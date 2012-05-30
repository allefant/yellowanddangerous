import array

class Blocks:

    def reset(self):
        self.static = []
        self.dynamic = []
        self.transparent = []
        self.rebuild_static_cache = True
        self.rebuild_dynamic_cache = True

    def block_pick(self, xp, yp, viewport):
        for block in self.static + self.dynamic:
            side = block.is_inside(xp, yp, viewport)
            if side:
                return side, block
        return 0, None

class BlockType:
    def __init__(self, xs, ys, zs):
        self.xs = xs
        self.ys = ys
        self.zs = zs
        self.dynamic = False
        self.lift = False
        self.transparent = False
        
class Block:
    tag = 0
    
    def __init__(self, blocks, x, y, z, block_type):
        self.blocks = blocks
        self.x, self.y, self.z = x, y, z
        self.block_type = block_type
        self.xs = block_type.xs
        self.ys = block_type.ys
        self.zs = block_type.zs
        self.r, self.g, self.b, self.a = 1, 1, 1, 1
        self.frame = 0
        self.dx = 0
        self.dy = 0
        self.dz = 0
        self.ground = False
        self.recursion_prevention = 0
        self.no_fall = False
     

    def add(self):
        self.bid = 1 + len(self.blocks.static) + len(self.blocks.dynamic)
        if self.block_type.dynamic:
            self.blocks.dynamic.append(self)
        elif self.block_type.transparent:
            self.blocks.transparent.append(self)
        else:
            self.blocks.static.append(self)

    def overlaps(self, other):
        return (other.x + other.xs > self.x and
            self.x + self.xs > other.x and
            other.y + other.ys > self.y and
            self.y + self.ys > other.y and
            other.z + other.zs > self.z and
            self.z + self.zs > other.z)

    def colliders(self):
        r = []
        for other in self.blocks.static + self.blocks.dynamic + self.blocks.transparent:
            if other is self: continue
            if self.overlaps(other): r.append(other)
        return r

    def move(self, dx, dy, dz):
        Block.tag += 1
        self.recursion_prevention = Block.tag
        return self.push(dx, dy, dz)

    def push(self, dx, dy, dz):
        
        ox = self.x
        oy = self.y
        oz = self.z
        self.x += dx
        self.y += dy
        self.z += dz

        cs = self.colliders()
        if cs:
            
            self.x = ox
            self.y = oy
            self.z = oz

            for c in cs:

                self.touch(c, dx, dy, dz)
                
                if self.y <= c.y + c.ys and self.y > c.y + c.ys - 1:
                    self.y = c.y + c.ys
                    continue

                if c.block_type.dynamic:
                    if c.recursion_prevention != Block.tag:
                        c.recursion_prevention = Block.tag
                        c.push(dx, dy, dz)

            return False
            
        else:
            self.blocks.rebuild_dynamic_cache = True
            return True

    def pull(self, dx, dy, dz):
       
        ox = self.x
        oy = self.y
        oz = self.z
        self.x += dx
        self.y += dy
        self.z += dz
        if self.colliders():
            self.x = ox
            self.y = oy
            self.z = oz
            return False

        self.blocks.rebuild_dynamic_cache = True
        return True

    def is_inside(self, xp, yp, viewport):
        """
        0 no
        1 top
        2 left
        3 right
        """

        x2 = self.x + self.xs
        y2 = self.y + self.ys
        z2 = self.z + self.zs
        
        v = (project(self.x, y2, self.z),
            project(self.x, y2, z2),
            project(x2, y2, z2),
            project(x2, y2, self.z),
            project(self.x, self.y, z2),
            project(x2, self.y, z2),
            project(x2, self.y, self.z),
            )

        #
        #      0
        #    /   \
        #  1       3
        #  | \   / |
        #  4   2   6
        #    \ | /
        #      5

        def is_left(i1, i2):
            ax = v[i2][0] - v[i1][0]
            ay = v[i2][1] - v[i1][1]
            bx = xp - v[i1][0]
            by = yp - v[i1][1]
            c = ax * by - ay * bx
            return c < 0
            
        if not is_left(0, 1): return 0
        if not is_left(1, 4): return 0
        if not is_left(4, 5): return 0
        if not is_left(5, 6): return 0
        if not is_left(6, 3): return 0
        if not is_left(3, 0): return 0
        if is_left(1, 2) and is_left(2, 3): return 1
        if is_left(2, 5): return 3
        return 2

    def get_bounding_rect(self, viewport):
        x1, _ = viewport.project(self.x, self.y, self.z + self.zs)
        x2, _ = viewport.project(self.x + self.xs, self.y, self.z)
        _, y1 = viewport.project(self.x, self.y + self.ys, self.z)
        _, y2 = viewport.project(self.x + self.xs, self.y, self.z + self.zs)
        return x1, y1, x2, y2

    def sort_order(self, other, viewport):
        if self is other: return 0
        e = 0.1

        slx, suy, srx, sdy = self.get_bounding_rect(viewport)
        olx, ouy, orx, ody = other.get_bounding_rect(viewport)

        # bounding box does not overlap -> don't care about order
        if slx >= orx: return 0
        if srx <= olx: return 0
        if suy >= ody: return 0
        if sdy <= ouy: return 0

        # Has to be drawn later if completely in front or above.
        if self.z + e >= other.z + other.zs: return 1
        if self.y + e >= other.y + other.ys: return 1
        if self.x + e >= other.x + other.xs: return 1
        
        # Has to be drawn earlier if completely behind or below.
        if other.z + e >= self.z + self.zs: return -1
        if other.y + e >= self.y + self.ys: return -1
        if other.x + e >= self.x + self.xs: return -1

        # Note: They overlap...

        if self.y > other.y: return 1
        #if self.z + self.zs >= other.z + other.zs: return 1
        #if self.y + self.ys >= other.y + other.ys: return 1
        #if self.x + self.xs >= other.x + other.xs: return 1

        return -1

    def tick(self):
        if not self.block_type.dynamic: return

        def sgn(a, x):
            if a <= 0: return 0
            if x < 0:
                if a >= 1: return -1
                return -a
            if x > 0:
                if a >= 1: return 1
                return a
            return 0
        
        if not self.no_fall: self.dy -= 1
        ax = abs(self.dx)
        ay = abs(self.dy)
        az = abs(self.dz)
        
        while ax > 0 or ay > 0 or az > 0:
            sx = sgn(ax, self.dx)
            sy = sgn(ay, self.dy)
            sz = sgn(az, self.dz)
            if sy:
                if not self.move(0, sy, 0):
                    self.dy = 0
                    if sy < 0: self.ground = True
                else:
                    self.ground = False
            if (sx or sz) and not self.move(sx, 0, sz):
                pass

            ax -= 1
            ay -= 1
            az -= 1

        self.dx *= 0.4
        self.dy *= 0.9
        self.dz *= 0.4

        if abs(self.dx) < 0.1: self.dx = 0
        if abs(self.dy) < 0.1: self.dy = 0
        if abs(self.dz) < 0.1: self.dz = 0

    def touch(self, c, dx, dy, dz):
        pass

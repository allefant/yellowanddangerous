import common
import isometric
import block_type
static import render
static import land.util2d

class Blocks:
    LandArray *fixed
    LandArray *dynamic
    LandArray *transparent
    LandArray *animated
    bool rebuild_static_cache
    bool rebuild_dynamic_cache

def blocks_list_destroy(LandArray **list):
    if *list:
        for Block *b in LandArray **list:
            b->block_type->destroy(b)
        land_array_destroy(*list)
        *list = None

def blocks_clear(Blocks *self):
    blocks_list_destroy(&self->fixed)
    blocks_list_destroy(&self->dynamic)
    blocks_list_destroy(&self->transparent)
    if self.animated:
        land_array_destroy(self.animated)

def blocks_reset(Blocks *self):
    blocks_clear(self)
    self->fixed = land_array_new()
    self->dynamic = land_array_new()
    self->transparent = land_array_new()
    self->animated = land_array_new()
    self->rebuild_static_cache = True
    self->rebuild_dynamic_cache = True

Blocks *def blocks_new():
    Blocks *b; land_alloc(b)
    return b

def blocks_destroy(Blocks *self):
    blocks_clear(self)
    land_free(self) 

def blocks_pick(Blocks *self, float xp, yp, Viewport *viewport) -> Block *:
    Block *best = None
    xp /= viewport.zoom
    yp /= viewport.zoom
    LandArray *arrays[] = {self.transparent, self.dynamic, self.fixed}
    for int i in range(3):
        LandArray *array = arrays[i]
        for Block *block in LandArray *array:
            int side = block_is_inside(block, xp, yp, viewport)
            if side:
                if best:
                    if block_sort_order(block, best, viewport) > 0:
                        best = block
                else:
                    best = block
  
    return best

static int tag = 0
class Block:
    BlockType *block_type

    Blocks *blocks
    float x, y, z
    float xs, ys, zs
    float r, g, b, a
    int frame
    float dx, dy, dz
    bool ground
    int recursion_prevention
    bool no_fall
    int bid

    bool pushed_something
    bool mover

    LandArray *cache
    
def block_init(Block *self, Blocks *blocks, float x, y, z, BlockType *block_type):
    self->blocks = blocks
    self->x = x
    self->y = y
    self->z = z
    self->block_type = block_type
    if block_type:
        self->xs = block_type->xs
        self->ys = block_type->ys
        self->zs = block_type->zs
    self->r = 1
    self->g = 1
    self->b = 1
    self->a = 1
    self->frame = 0
    self->dx = 0
    self->dy = 0
    self->dz = 0
    self->ground = False
    self->recursion_prevention = 0
    self->no_fall = False
    self->cache = land_array_new()

Block *def block_new(Blocks *blocks, float x, y, z, BlockType *block_type):
    Block *self = block_type.allocate()
    block_init(self, blocks, x, y, z, block_type)
    self->block_type->post_init(self)
    return self

def block_destroy(Block *self):
    land_array_destroy(self->cache)
    land_free(self)

def block_allocate() -> Block *:
    Block *self
    land_alloc(self)
    return self

def block_post_init(Block *self):
    return

def block_add(Block *self):
    self->bid = 1 + land_array_count(self->blocks->fixed) +\
        land_array_count(self->blocks->dynamic)
    if self.block_type and self->block_type->dynamic:
        land_array_add(self->blocks->dynamic, self)
    elif self.block_type and self->block_type->transparent:
        land_array_add(self->blocks->transparent, self)
    else:
        land_array_add(self->blocks->fixed, self)

    if self.block_type and self.block_type.animated:
        land_array_add(self.blocks.animated, self)

def block_change_type(Block *self, int d) -> Block *:
    int n = land_array_count(block_types)
    int btid = self.block_type.btid + d
    if btid >= n:
        btid -= n
    if btid < 0:
        btid += n
    BlockType *bt = land_array_get_nth(block_types, btid)
    Blocks *blocks = self.blocks
    float x = self.x
    float y = self.y
    float z = self.z
    block_del(self)
    self = block_new(blocks, x, y, z, bt)
    block_add(self)
    return self

def block_change_type_to(Block *self, char const *text) -> Block *:
    for BlockType *bt in LandArray *block_types:
        if land_equals(bt.name, text):
            return block_change_type(self, bt.btid - self.block_type.btid)
    return self

def block_del(Block *self):
    LandArray *array
    if self.block_type and self->block_type->dynamic:
        array = self->blocks->dynamic
    elif self.block_type and self->block_type->transparent:
        array = self->blocks->transparent
    else:
        array = self->blocks->fixed

    int i = land_array_find(array, self)
    if i < 0:
        return
    land_array_swap(array, i, -1)
    land_array_pop(array)

    self->blocks->rebuild_static_cache = True
    self->blocks->rebuild_dynamic_cache = True

    self->block_type->destroy(self)

bool def block_overlaps(Block *self, *other):
    if (other->x + other->xs > self->x and
        self->x + self->xs > other->x and
        other->y + other->ys > self->y and
        self->y + self->ys > other->y and
        other->z + other->zs > self->z and
        self->z + self->zs > other->z):

        if other.block_type == Render_RampLeft:
            #   __   b +y
            #  |  | /|
            #  |_0|/ |
            #     /  |
            #  +z/__0|-z
            #    a
            float az = other.z + other.zs
            float ay = other.y
            float bz = other.z
            float by = other.y + other.ys
            if land_cross2d(self.z - az, self.y - ay, bz - az, by - ay
                    ) > 0:
                return False
        if other.block_type == Render_RampRight:
            #   __   b +y
            #  |  | /|
            #  |_0|/ |
            #     /  |
            #  +x/__0|-x
            #    a
            float ax = other.x + other.xs
            float ay = other.y
            float bx = other.x
            float by = other.y + other.ys
            if land_cross2d(self.x - ax, self.y - ay, bx - ax, by - ay
                    ) > 0:
                return False
        return True
    return False

def block_center_overlaps(Block *super, *c) -> bool:
    float cx = super.x + super.xs / 2
    float cz = super.z + super.zs / 2
    if cx > c.x and cx < c.x + c.xs and cz > c.z and cz < c.z + c.zs:
        return True
    return False

LandArray *def block_colliders(Block *self):
    int n1, n2, n3
    LandArray *r = land_array_new()
    n1 = land_array_count(self->blocks->fixed)
    n2 = land_array_count(self->blocks->dynamic)
    n3 = land_array_count(self->blocks->transparent)
    for int i in range(n1 + n2 + n3):
        Block *other
        if i < n1: other = land_array_get_nth(self->blocks->fixed, i)
        elif i - n1 < n2: other = land_array_get_nth(self->blocks->dynamic, i - n1)
        elif i - n1 - n2 < n3: other = land_array_get_nth(self->blocks->transparent, i - n1 - n2)
        if other == self: continue
        if block_overlaps(self, other):
            land_array_add(r, other)
    return r

bool def block_move(Block *self, float dx, dy, dz):
    tag += 1
    self->recursion_prevention = tag
    self.mover = True
    bool r = block_push(self, dx, dy, dz)
    self.mover = False
    return r

def move_on_top(Block *self, float dx, dy, dz):
    float on_top_y = self.y
    self.y += 1
    LandArray *top = block_colliders(self)
    self.y = on_top_y
    for Block *c in LandArray *top:
        if c->block_type->dynamic and not c->block_type->fixed:
            if c->recursion_prevention != tag:
                c->recursion_prevention = tag
                block_push(c, dx, dy, dz)
    land_array_destroy(top)

def block_distance(Block *self, *other) -> float:
    float dx = self.x - other.x
    float dy = self.y - other.y
    float dz = self.z - other.z
    return sqrt(dx * dx + dy * dy + dz * dz)

bool def block_push(Block *self, float odx, ody, odz):
    bool r

    float ox = self->x
    float oy = self->y
    float oz = self->z

    bool first_after_push = True
    bool first_ramp_up = True
    int first_single_dir = 2

    label retry

    float dx = first_single_dir != 0 ? odx : 0
    float dy = ody
    float dz = first_single_dir != 1 ? odz : 0

    self->x += dx
    if self.y < 9000:
        self->y += dy
    self->z += dz

    if self.y < -9000:
        self.y = -9000

    LandArray *cs = block_colliders(self)

    if land_array_count(cs):

        bool retry_after_push = False
        
        self->x = ox
        self->y = oy
        self->z = oz

        for Block *c in LandArray *cs:

            self->block_type->touch(self, c, dx, dy, dz)

            # don't get stuck at the very top pixel
            if self->y <= c->y + c->ys and self->y > c->y + c->ys - 1:
                self->y = c->y + c->ys
                continue

            # doing this in general is too dangerous of getting stuck
            # re-align to pushed block
            if self->block_type == Render_Cart:
                if self->x + self->xs < c->x and self.x + self->xs > c->x - 1:
                    self.x = c->x - self->xs

                if self->z > c->z + c->zs and self.z < c->z + c->zs + 1:
                    self.z = c->z + c->zs

                if self->z + self->zs < c->z and self.z + self->zs > c->z - 1:
                    self.z = c->z - self->zs

                if self->x > c->x + c->xs and self.x < c->x + c->xs + 1:
                    self.x = c->x + c->xs

            # prevent "pushing" something that's actually on top
            if (dy > 0 or c->y < self->y + self->ys) and\
                    c->block_type->dynamic and not c->block_type->fixed:
                if c->recursion_prevention != tag:
                    c->recursion_prevention = tag
                    if block_push(c, dx, dy, dz):
                        #print("%d %s -> %s %f", tag, self->block_type->name, c->block_type->name, dy)
                        self.pushed_something = True
                        retry_after_push = True

        r = False
        land_array_destroy(cs)

        if first_after_push and retry_after_push:
            first_after_push = False
            goto retry
        elif first_ramp_up and dy == 0:
            first_ramp_up = False
            self.y += 1
            goto retry
        # only an active mover can do single directions, otherwise
        # pushing in xz will behave very weird
        elif self.mover and first_single_dir > 0:
            first_single_dir--
            goto retry
        
    else:
        if dx or dz:
            move_on_top(self, dx, dy, dz)
        
        self->blocks->rebuild_dynamic_cache = True
        r = True

        land_array_destroy(cs)
    return r

def block_recursion_tag -> int:
    tag += 1
    return tag

bool def block_pull(Block *self, float dx, dy, dz):
    bool first_ramp_up = True
    float ox = self->x
    float oy = self->y
    float oz = self->z
    label retry
    self->x += dx
    self->y += dy
    self->z += dz
    LandArray *cs = block_colliders(self)
    if land_array_count(cs):
        self->x = ox
        self->y = oy
        self->z = oz
        land_array_destroy(cs)

        if first_ramp_up:
            first_ramp_up = False
            self.y += 1
            goto retry
        
        return False

    land_array_destroy(cs)

    move_on_top(self, dx, dy, dz)

    self->blocks->rebuild_dynamic_cache = True
    return True

static bool def is_left(float *v, xp, yp, int i1, i2):
    float ax = v[i2 * 2 + 0] - v[i1 * 2 + 0]
    float ay = v[i2 * 2 + 1] - v[i1 * 2 + 1]
    float bx = xp - v[i1 * 2 + 0]
    float by = yp - v[i1 * 2 + 1]
    float c = ax * by - ay * bx
    return c < 0

int def block_is_inside(Block *self, float xp, yp, Viewport *viewport):
    """
    0 no
    1 top
    2 left
    3 right
    """

    float x2 = self->x + self->xs
    float y2 = self->y + self->ys
    float z2 = self->z + self->zs

    float v[14]
    project(viewport, self->x, y2, self->z, v + 0, v + 1)
    project(viewport, self->x, y2, z2, v + 2, v + 3)
    project(viewport, x2, y2, z2, v + 4, v + 5)
    project(viewport, x2, y2, self->z, v + 6, v + 7)
    project(viewport, self->x, self->y, z2, v + 8, v + 9)
    project(viewport, x2, self->y, z2, v + 10, v + 11)
    project(viewport, x2, self->y, self->z, v + 12, v + 13)

    #
    #      0
    #    /   .
    #  1       3
    #  | \   / |
    #  4   2   6
    #    \ | /
    #      5
        
    if not is_left(v, xp, yp, 0, 1): return 0
    if self.ys:
        if not is_left(v, xp, yp, 1, 4): return 0
    if not is_left(v, xp, yp, 4, 5): return 0
    if not is_left(v, xp, yp, 5, 6): return 0
    if self.ys:
        if not is_left(v, xp, yp, 6, 3): return 0
    if not is_left(v, xp, yp, 3, 0): return 0
    if is_left(v, xp, yp, 1, 2) and is_left(v, xp, yp, 2, 3): return 1
    if is_left(v, xp, yp, 2, 5): return 3
    return 2

def block_get_bounding_rect(Block *self, Viewport *viewport,
        float *x1, *y1, *x2, *y2):
    float _
    project(viewport, self->x, self->y, self->z + self->zs, x1, &_)
    project(viewport, self->x + self->xs, self->y, self->z, x2, &_)
    project(viewport, self->x, self->y + self->ys, self->z, &_, y1)
    project(viewport, self->x + self->xs, self->y, self->z + self->zs, &_, y2)
    

int def block_sort_order(Block *self, *other, Viewport *viewport):
    if self == other: return 0
    float e = 0.1

    float slx, suy, srx, sdy
    float olx, ouy, orx, ody

    block_get_bounding_rect(self, viewport, &slx, &suy, &srx, &sdy)
    block_get_bounding_rect(other, viewport, &olx, &ouy, &orx, &ody)

    # bounding box does not overlap -> don't care about order
    if slx >= orx: return 0
    if srx <= olx: return 0
    if suy >= ody: return 0
    if sdy <= ouy: return 0

    # Has to be drawn later if completely in front or above.
    if self->z + e >= other->z + other->zs: return 1
    if self->y + e >= other->y + other->ys: return 1
    if self->x + e >= other->x + other->xs: return 1
    
    # Has to be drawn earlier if completely behind or below.
    if other->z + e >= self->z + self->zs: return -1
    if other->y + e >= self->y + self->ys: return -1
    if other->x + e >= self->x + self->xs: return -1

    # Note: They overlap...

    if self->y > other->y: return 1
    #if self->z + self->zs >= other->z + other->zs: return 1
    #if self->y + self->ys >= other->y + other->ys: return 1
    #if self->x + self->xs >= other->x + other->xs: return 1

    return -1

static float def sgn(float a, x):
    if a <= 0: return 0
    if x < 0:
        if a >= 1: return -1
        return -a
    if x > 0:
        if a >= 1: return 1
        return a
    return 0

def block_tick(Block *self):
    if not self->block_type->animated: return

    if not self.no_fall and not self.block_type->fixed:
        self->dy -= sqrt(2)

    float ax = fabs(self->dx)
    float ay = fabs(self->dy)
    float az = fabs(self->dz)
    
    while ax > 0 or ay > 0 or az > 0:
        float sx = sgn(ax, self->dx)
        float sy = sgn(ay, self->dy)
        float sz = sgn(az, self->dz)
        if sy:
            if not block_move(self, 0, sy, 0):
                self->dy = 0
                if sy < 0:
                    self->ground = True
            else:
                self->ground = False
        if sx or sz:
            block_move(self, sx, 0, sz):

        ax -= 1
        ay -= 1
        az -= 1

    self->dx *= 0.4
    self->dy *= 0.9
    self->dz *= 0.4

    if fabs(self->dx) < 0.1: self->dx = 0
    if fabs(self->dy) < 0.1: self->dy = 0
    if fabs(self->dz) < 0.1: self->dz = 0

def block_touch(Block *self, *c, float dx, dy, dz):
    pass

def blocks_preload(Blocks *self) -> bool:
    int n1, n2, n3
    n1 = land_array_count(self->fixed)
    n2 = land_array_count(self->dynamic)
    n3 = land_array_count(self->transparent)
    for int i in range(n1 + n2 + n3):
        Block *other
        if i < n1: other = land_array_get_nth(self->fixed, i)
        elif i - n1 < n2: other = land_array_get_nth(self->dynamic, i - n1)
        elif i - n1 - n2 < n3: other = land_array_get_nth(self->transparent, i - n1 - n2)
        BlockType *bt = other.block_type
        if blocktype_preload(bt):
            return True
    return False

def blocks_shift(Blocks *self, int dx, dy, dz):
    int n1, n2, n3
    n1 = land_array_count(self->fixed)
    n2 = land_array_count(self->dynamic)
    n3 = land_array_count(self->transparent)
    for int i in range(n1 + n2 + n3):
        Block *other
        if i < n1: other = land_array_get_nth(self->fixed, i)
        elif i - n1 < n2: other = land_array_get_nth(self->dynamic, i - n1)
        elif i - n1 - n2 < n3: other = land_array_get_nth(self->transparent, i - n1 - n2)
        other.x += dx
        other.y += dy
        other.z += dz
    

import common
import isometric

class Blocks:
    LandArray *fixed
    LandArray *dynamic
    LandArray *transparent
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

def blocks_reset(Blocks *self):
    blocks_clear(self)
    self->fixed = land_array_new()
    self->dynamic = land_array_new()
    self->transparent = land_array_new()
    self->rebuild_static_cache = True
    self->rebuild_dynamic_cache = True

Blocks *def blocks_new():
    Blocks *b; land_alloc(b)
    return b

def blocks_destroy(Blocks *self):
    blocks_clear(self)
    land_free(self)

#def blocks_pick(Blocks *self, float xp, yp, Viewport *viewport):
#    for block in self->static + self->dynamic:
#        side = block_is_inside(xp, yp, viewport)
#        if side:
#            return side, block
#    return 0, None

class BlockType:
    float xs, ys, zs
    bool dynamic
    bool lift
    bool transparent
    LandArray *bitmaps
    float x, y, z

    void (*tick)(Block *)
    void (*touch)(Block *, Block *, float, float, float)
    void (*destroy)(Block *)

BlockType *def blocktype_new(float xs, ys, zs,
        void (*tick)(Block *),
        void (*touch)(Block *, Block *, float, float, float),
        void (*destroy)(Block *)):
    BlockType *self
    land_alloc(self)
    self->xs = xs
    self->ys = ys
    self->zs = zs
    self->dynamic = False
    self->lift = False
    self->transparent = False
    self->tick = tick
    self->touch = touch
    self->destroy = destroy
    return self

def blocktype_destroy(BlockType *self):
    for LandImage *pic in LandArray *self->bitmaps:
        land_image_destroy(pic)
    land_array_destroy(self->bitmaps)
    land_free(self)

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

    LandArray *cache
    
def block_init(Block *self, Blocks *blocks, float x, y, z, BlockType *block_type):
    self->blocks = blocks
    self->x = x
    self->y = y
    self->z = z
    self->block_type = block_type
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
    Block *self
    land_alloc(self)
    block_init(self, blocks, x, y, z, block_type)
    return self

def block_destroy(Block *self):
    land_array_destroy(self->cache)
    land_free(self)

def block_add(Block *self):
    self->bid = 1 + land_array_count(self->blocks->fixed) +\
        land_array_count(self->blocks->dynamic)
    if self->block_type->dynamic:
        land_array_add(self->blocks->dynamic, self)
    elif self->block_type->transparent:
        land_array_add(self->blocks->transparent, self)
    else:
        land_array_add(self->blocks->fixed, self)

bool def block_overlaps(Block *self, *other):
    return (other->x + other->xs > self->x and
        self->x + self->xs > other->x and
        other->y + other->ys > self->y and
        self->y + self->ys > other->y and
        other->z + other->zs > self->z and
        self->z + self->zs > other->z)

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
    return block_push(self, dx, dy, dz)

bool def block_push(Block *self, float dx, dy, dz):
    bool r

    float ox = self->x
    float oy = self->y
    float oz = self->z
    self->x += dx
    self->y += dy
    self->z += dz

    LandArray *cs = block_colliders(self)
    if land_array_count(cs):
        
        self->x = ox
        self->y = oy
        self->z = oz

        for Block *c in LandArray *cs:

            self->block_type->touch(self, c, dx, dy, dz)
            
            if self->y <= c->y + c->ys and self->y > c->y + c->ys - 1:
                self->y = c->y + c->ys
                continue

            if c->block_type->dynamic:
                if c->recursion_prevention != tag:
                    c->recursion_prevention = tag
                    block_push(c, dx, dy, dz)

        r = False
        
    else:
        self->blocks->rebuild_dynamic_cache = True
        r = True

    land_array_destroy(cs)
    return r

bool def block_pull(Block *self, float dx, dy, dz):
   
    float ox = self->x
    float oy = self->y
    float oz = self->z
    self->x += dx
    self->y += dy
    self->z += dz
    LandArray *cs = block_colliders(self)
    if land_array_count(cs):
        self->x = ox
        self->y = oy
        self->z = oz
        return False

    land_array_destroy(cs)

    self->blocks->rebuild_dynamic_cache = True
    return True

static bool def is_left(float *v, xp, yp, int i1, i2):
    float ax = v[i2 * 2 + 0] - v[i1 * 2 + 0]
    float ay = v[i2 * 2 + 1] - v[i1 * 2 + 1]
    float bx = xp - v[i1 * 2 + 0]
    float by = yp - v[i1 * 2 + 1]
    float c = ax * by - ay * bx
    return c < 0

bool def block_is_inside(Block *self, float xp, yp, Viewport *viewport):
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
    #    /   \
    #  1       3
    #  | \   / |
    #  4   2   6
    #    \ | /
    #      5

    
        
    if not is_left(v, xp, yp, 0, 1): return 0
    if not is_left(v, xp, yp, 1, 4): return 0
    if not is_left(v, xp, yp, 4, 5): return 0
    if not is_left(v, xp, yp, 5, 6): return 0
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
    if not self->block_type->dynamic: return

    if not self->no_fall: self->dy -= 1
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
                if sy < 0: self->ground = True
            else:
                self->ground = False
        if (sx or sz) and not block_move(self, sx, 0, sz):
            pass

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

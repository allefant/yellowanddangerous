import common
import block, render

class Platform:
    Block super
    int go_x, go_z
    bool moving

def platform_allocate -> Block *:
    Platform *self
    land_alloc(self)
    return &self.super

static def check(Block *super, int dx, dz) -> bool:
    float ox = super.x
    float oz = super.z
    super.x += dx
    super.z += dz
    LandArray *c = block_colliders(super)
    bool r = land_array_count(c) == 0
    land_array_destroy(c)
    super.x = ox
    super.z = oz
    return r

def platform_tick(Block *super):
    Platform *self = (void *)super

    if self.go_x == 0 and self.go_z == 0:
        if check(super, -1, 0):
            self.go_x = -1
        elif check(super, 0, -1):
            self.go_z = -1
        elif check(super, 1, 0):
            self.go_x = 1
        elif check(super, 0, 1):
            self.go_z = 1

    if game->lever_on or self.moving:
        super.dx += self.go_x * 2
        super.dz += self.go_z * 2
        self.moving = True

    block_tick(super)

def platform_touch (Block *super, Block *other, float dx, dy, dz):
    Platform *self = (void *)super
    self.moving = False
    self.go_x = 0
    self.go_z = 0
    game->lever_on = False
    if game->lever_right:
        game->lever_right->frame = 0
    if game->lever_left:
        game->lever_left->frame = 0

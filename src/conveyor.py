import common
import block, render

class Conveyor:
    Block super
    int direction
    bool on

def conveyor_allocate -> Block *:
    Conveyor *self
    land_alloc(self)
    return &self.super

def conveyor_tick(Block *super):
    Conveyor *self = (void *)super
    if not self.on:
        self.on = True
        LandArray *cs = block_colliders(super)
        self.direction = 1
        for Block *b in LandArray *cs:
            if b.block_type == Render_Waypoint:
                self.direction = -1
        land_array_destroy(cs)

    int t = game->ticks * self.direction
    super.frame = (t / 4) & 3

    float ys = super.ys
    super.ys += 4

    float ax = 0
    float az = 0
    if super.block_type == Render_ConveyorLeft:
        az = -1 * self.direction
    else:
        ax = 1 * self.direction
    
    LandArray *cs = block_colliders(super)
    for Block *b in LandArray *cs:
        b.dx += ax
        b.dz += az
    land_array_destroy(cs)

    super.ys = ys

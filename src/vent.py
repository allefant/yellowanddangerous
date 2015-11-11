import common
import block, render

class Vent:
    Block super
    bool on
    int offset
    float accum

def vent_allocate -> Block *:
    Vent *self
    land_alloc(self)
    return &self.super

def vent_tick(Block *super):
    Vent *self = (void *)super
    if not self.on:
        self.on = True
        self.offset = 300
        LandArray *cs = block_colliders(super)
        int n = 0
        for Block *b in LandArray *cs:
            if b.block_type == Render_Waypoint:
                self.offset = b.frame * 60
                n++
        land_array_destroy(cs)
    # t,offset = 0,0 0,300 300,0 0,540
    int t = game->ticks % 600
    t -= self.offset
    if t < -300:
        t += 600
    if t > 300:
        t -= 600
    # t = 0 -300 300 60
    t = abs(t)
    t -= 60
    if t < 0:
        t = 0
    if t > 100:
        t = 100
    # t = 0 100 100 45
    float speed = t / 100.0
    self.accum += speed
    if self.accum > 1:
        super.frame++
        self.accum -= 1

    if super.frame == 4:
        super.frame = 0

    float xs = super.xs
    float zs = super.zs
    float ax = 0
    float az = 0
    # offset a bit towards animation
    speed -= 0.1
    if speed < 0:
        speed = 0
    if super.block_type == Render_VentLeft:
        super.xs += 200
        ax = speed * 15
    if super.block_type == Render_VentRight:
        super.zs += 200
        az = speed * 15
    LandArray *cs = block_colliders(super)
    for Block *b in LandArray *cs:
        float s = 1 - (block_distance(b, super) - 64) / 225
        if s < 0:
            s = 0
        if s > 1:
            s = 1
        b.dx += ax * s
        b.dz += az * s
    land_array_destroy(cs)

    super.xs = xs
    super.zs = zs

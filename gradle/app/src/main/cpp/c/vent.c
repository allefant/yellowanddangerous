/* This file was generated by scramble.py. */
#line 1 "src/vent.py"
#include "vent.h"
#line 10
Block* vent_allocate(void) {
    Vent * self;
    land_alloc(self);
    return & self->super;
}
void vent_tick(Block * super) {
    Vent * self = (void *) super;
    if (! self->on) {
        self->on = 1;
        self->offset = 300;
        LandArray * cs = block_colliders(super);
        int n = 0;
        {
#line 22
            LandArrayIterator __iter0__ = LandArrayIterator_first(cs);
#line 22
            for (Block * b = LandArrayIterator_item(cs, &__iter0__); LandArrayIterator_next(cs, &__iter0__); b = LandArrayIterator_item(cs, &__iter0__)) {
                if (b->block_type == Render_Waypoint) {
                    self->offset = b->frame * 60;
                    n++;
                }
            }
        }
#line 26
        land_array_destroy(cs);
    }
    // t,offset = 0,0 0,300 300,0 0,540
#line 28
    int t = game->ticks % 600;
    t -= self->offset;
    if (t < - 300) {
        t += 600;
    }
#line 32
    if (t > 300) {
        t -= 600;
    }
    // t = 0 -300 300 60
#line 35
    t = abs(t);
    t -= 60;
    if (t < 0) {
        t = 0;
    }
#line 39
    if (t > 100) {
        t = 100;
    }
    // t = 0 100 100 45
#line 42
    float speed = t / 100.0;
    self->accum += speed;
    if (self->accum > 1) {
        super->frame++;
        self->accum -= 1;
    }
    if (super->frame == 4) {
        super->frame = 0;
    }
    float xs = super->xs;
    float zs = super->zs;
    float ax = 0;
    float az = 0;
    // offset a bit towards animation
    speed -= 0.1;
    if (speed < 0) {
        speed = 0;
    }
#line 59
    if (super->block_type == Render_VentLeft) {
        super->xs += 200;
        ax = speed * 15;
    }
#line 62
    if (super->block_type == Render_VentRight) {
        super->zs += 200;
        az = speed * 15;
    }
#line 65
    LandArray * cs = block_colliders(super);
    {
#line 66
        LandArrayIterator __iter0__ = LandArrayIterator_first(cs);
#line 66
        for (Block * b = LandArrayIterator_item(cs, &__iter0__); LandArrayIterator_next(cs, &__iter0__); b = LandArrayIterator_item(cs, &__iter0__)) {
            float s = 1 - (block_distance(b, super) - 64) / 225;
            if (s < 0) {
                s = 0;
            }
#line 70
            if (s > 1) {
                s = 1;
            }
#line 72
            b->dx += ax * s;
            b->dz += az * s;
        }
    }
#line 74
    land_array_destroy(cs);
#line 76
    super->xs = xs;
    super->zs = zs;
}
/* This file was generated by scramble.py. */
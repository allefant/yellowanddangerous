/* This file was generated by scramble.py. */
#line 1 "src/conveyor.py"
#include "conveyor.h"
#line 9
Block* conveyor_allocate(void) {
    Conveyor * self;
    land_alloc(self);
    return & self->super;
}
void conveyor_tick(Block * super) {
    Conveyor * self = (void *) super;
    if (! self->on) {
        self->on = 1;
        LandArray * cs = block_colliders(super);
        self->direction = 1;
        {
#line 20
            LandArrayIterator __iter0__ = LandArrayIterator_first(cs);
#line 20
            for (Block * b = LandArrayIterator_item(cs, &__iter0__); LandArrayIterator_next(cs, &__iter0__); b = LandArrayIterator_item(cs, &__iter0__)) {
                if (b->block_type == Render_Waypoint) {
                    self->direction = - 1;
                }
            }
        }
#line 23
        land_array_destroy(cs);
    }
    int t = game->ticks * self->direction;
    super->frame = (t / 4) & 3;
#line 28
    float ys = super->ys;
    super->ys += 4;
#line 31
    float ax = 0;
    float az = 0;
    if (super->block_type == Render_ConveyorLeft) {
        az = - 1 * self->direction;
    }
#line 34
    else {
#line 36
        ax = 1 * self->direction;
    }
    LandArray * cs = block_colliders(super);
    {
#line 39
        LandArrayIterator __iter0__ = LandArrayIterator_first(cs);
#line 39
        for (Block * b = LandArrayIterator_item(cs, &__iter0__); LandArrayIterator_next(cs, &__iter0__); b = LandArrayIterator_item(cs, &__iter0__)) {
            b->dx += ax;
            b->dz += az;
        }
    }
#line 42
    land_array_destroy(cs);
#line 44
    super->ys = ys;
}
/* This file was generated by scramble.py. */

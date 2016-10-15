/* This file was generated by scramble.py. */
#line 1 "src/gremlin.py"
#include "gremlin.h"
#line 8
Block* gremlin_allocate(void) {
    Gremlin * self;
    land_alloc(self);
    self->respect = 60;
    return & self->super;
}
void gremlin_tick(Block * super) {
    Gremlin * self = (void *) super;
    Block * p = (void *) game->player;
    if (self->respect) {
        self->respect--;
    }
#line 19
    else if (p) {
        float dx = p->x - super->x;
        float dz = p->z - super->z;
        if (game->ticks % 8 == 0) {
            super->frame++;
            if (super->frame == 4) {
                super->frame = 0;
            }
        }
#line 26
        super->frame &= 3;
        int a = (atan2(dx, - dz) + pi + pi / 4) * 2 / pi;
        super->frame += 4 * (a & 3);
        float d = sqrt(dx * dx + dz * dz);
        super->dx = 4 * dx / d;
        super->dz = 4 * dz / d;
    }
    if (super->pushed_something) {
        super->pushed_something = 0;
        super->dx *= 0.1;
        super->dz *= 0.1;
    }
    block_tick(super);
}
void gremlin_touch(Block * super, Block * c, float dx, float dy, float dz) {
    Gremlin * self = (void *) super;
    if (c->block_type == Render_Allefant || c->block_type == Render_Gremlin) {
        self->respect = 30;
        super->dx = c->dx;
        super->dz = c->dz;
    }
#line 46
    if (c->block_type == Render_Scientist) {
        if (! self->respect) {
            ((Player *) c)->dead = 1;
        }
    }
}
/* This file was generated by scramble.py. */
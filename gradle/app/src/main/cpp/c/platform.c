/* This file was generated by scramble.py. */
#line 1 "src/platform.py"
#include "platform.h"
#line 10
Block* platform_allocate(void) {
    Platform * self;
    land_alloc(self);
    return & self->super;
}
void platform_tick(Block * super) {
    Platform * self = (void *) super;
#line 18
    if (game->lever || self->moving) {
        if (! self->moving) {
            self->wait = 60;
            self->last_last_y = self->last_y = 9000;
            print("waiting 60, frame is %d", super->frame);
        }
#line 23
        if (self->wait > 0) {
            self->wait--;
        }
#line 24
        else {
#line 26
            if (super->frame == 0) {
#line 26
                super->dx += 2;
            }
#line 27
            if (super->frame == 1) {
#line 27
                super->dz -= 2;
            }
#line 28
            if (super->frame == 2) {
#line 28
                super->dx -= 2;
            }
#line 29
            if (super->frame == 3) {
#line 29
                super->dz += 2;
            }
#line 30
            if (super->frame == 4) {
#line 30
                super->dy = 1;
            }
#line 31
            if (super->frame == 5) {
#line 31
                super->dy = - 1;
            }
            self->last_last_y = self->last_y;
            self->last_y = super->y;
        }
        self->moving = 1;
    }
    block_tick(super);
    // hardcoded for now
#line 41
    if (super->dy > 0 && super->y > 336) {
        super->y = 336;
        stop(super);
    }
#line 44
    if (super->dy < 0 && super->y < - 48) {
        super->y = - 48;
        stop(super);
    }
}
#line 48
void platform_touch(Block * super, Block * other, float dx, float dy, float dz) {
    Platform * self = (void *) super;
#line 51
    if (dy) {
        // note: if multiple objects are on the platform we get here
        // for each one of them
        if (self->last_last_y != super->y) {
#line 54
            return ;
        }
    }
    stop(super);
}
void stop(Block * super) {
    Platform * self = (void *) super;
#line 62
    self->moving = 0;
    super->dx = 0;
    super->dy = 0;
    super->dz = 0;
    if (game->lever) {
        if (super->frame < 4) {
            super->frame += 2;
            super->frame &= 3;
        }
#line 69
        else {
#line 71
            super->frame++;
            if (super->frame == 6) {
                super->frame = 4;
            }
        }
#line 74
        game->lever->frame = 0;
        game->lever = NULL;
        print("game.lever is None, frame is %d", super->frame);
    }
}
/* This file was generated by scramble.py. */
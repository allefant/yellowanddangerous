/* This file was generated by scramble.py. */
#line 1 "src/eye.py"
#include "eye.h"
#line 4
void eye_tick(Block * super) {
    Block * p = (void *) game->player;
    if (p) {
        float dx = p->x - super->x;
        float dz = p->z - super->z;
        int f = (atan2(dx, dz) + pi) * 4 / pi;
        super->frame = (f + 1) & 7;
    }
    block_tick(super);
}
/* This file was generated by scramble.py. */

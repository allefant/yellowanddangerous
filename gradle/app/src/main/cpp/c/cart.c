/* This file was generated by scramble.py. */
#line 1 "src/cart.py"
#include "cart.h"
#line 4
void cart_tick(Block * super) {
    if (game->ticks % 8 == 0) {
        super->frame++;
        if (super->frame == 4) {
            super->frame = 0;
        }
    }
#line 9
    block_tick(super);
}
/* This file was generated by scramble.py. */

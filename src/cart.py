import block
import game

def cart_tick(Block *super):
    if game->ticks % 8 == 0:
        super.frame++
        if super.frame == 4:
            super.frame = 0
    block_tick(super)

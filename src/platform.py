import common
import block, render

class Platform:
    Block super
    bool moving
    int wait

def platform_allocate -> Block *:
    Platform *self
    land_alloc(self)
    return &self.super

def platform_tick(Block *super):
    Platform *self = (void *)super

    if game->lever or self.moving:
        if not self.moving:
            self.wait = 30
        if self.wait > 0:
            self.wait--
        else:
            if super.frame == 0: super.dx += 2
            if super.frame == 1: super.dz -= 2
            if super.frame == 2: super.dx -= 2
            if super.frame == 3: super.dz += 2
        self.moving = True

    block_tick(super)

def platform_touch (Block *super, Block *other, float dx, dy, dz):
    Platform *self = (void *)super
    self.moving = False
    if game->lever:
        super.frame += 2
        super.frame &= 3
        game->lever->frame = 0
        game->lever = None

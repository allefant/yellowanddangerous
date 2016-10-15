import common
import block, render

class Platform:
    Block super
    bool moving
    int wait
    float last_y, last_last_y

def platform_allocate -> Block *:
    Platform *self
    land_alloc(self)
    return &self.super

def platform_tick(Block *super):
    Platform *self = (void *)super

    if game->lever or self.moving:
        if not self.moving:
            self.wait = 60
            self.last_last_y = self.last_y = 9000
            print("waiting 60, frame is %d", super.frame)
        if self.wait > 0:
            self.wait--
        else:
            if super.frame == 0: super.dx += 2
            if super.frame == 1: super.dz -= 2
            if super.frame == 2: super.dx -= 2
            if super.frame == 3: super.dz += 2
            if super.frame == 4: super.dy = 1
            if super.frame == 5: super.dy = -1

            self.last_last_y = self.last_y
            self.last_y = super.y

        self.moving = True

    block_tick(super)

    # hardcoded for now
    if super.dy > 0 and super.y > 336:
        super.y = 336
        stop(super)
    if super.dy < 0 and super.y < -48:
        super.y = -48
        stop(super)

def platform_touch (Block *super, Block *other, float dx, dy, dz):
    Platform *self = (void *)super

    if dy:
        # note: if multiple objects are on the platform we get here
        # for each one of them
        if self.last_last_y != super.y:
            return
    
    stop(super)

def stop(Block *super):
    Platform *self = (void *)super
    
    self.moving = False
    super.dx = 0
    super.dy = 0
    super.dz = 0
    if game->lever:
        if super.frame < 4:
            super.frame += 2
            super.frame &= 3
        else:
            super.frame++
            if super.frame == 6:
                super.frame = 4
        game->lever->frame = 0
        game->lever = None
        print("game.lever is None, frame is %d", super.frame)

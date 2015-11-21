import block
import game

class Gremlin:
    Block super
    int respect

def gremlin_allocate -> Block *:
    Gremlin *self
    land_alloc(self)
    return &self.super

def gremlin_tick(Block *super):
    Gremlin *self = (void *)super
    Block *p = (void *)game->player
    if self.respect:
        self.respect--
    elif p:
        float dx = p.x - super.x
        float dz = p.z - super.z
        if game->ticks % 8 == 0:
            super.frame++
            if super.frame == 4:
                super.frame = 0
        super.frame &= 3
        int a = (atan2(dx, -dz) + pi + pi / 4) * 2 / pi
        super.frame += 4 * (a & 3)
        float d = sqrt(dx * dx + dz * dz)
        super.dx = 4 * dx / d
        super.dz = 4 * dz / d

    if super.pushed_something:
        super.pushed_something = False
        super.dx *= 0.1
        super.dz *= 0.1
    
    block_tick(super)

def gremlin_touch(Block *super, Block *c, float dx, dy, dz):
    Gremlin *self = (void *)super
    if c->block_type == Render_Allefant or c->block_type == Render_Gremlin:
        self.respect = 30
        super.dx = c.dx
        super.dz = c.dz
    if c->block_type == Render_Scientist:
        ((Player *)c)->dead = True

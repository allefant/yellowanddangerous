import common
import block, render

def testtube_touch(Block *super, Block *c, float dx, dy, dz):
    if dy < 0 and super.dy < -2:
        super.y = -9000
        sound(Render_glass, 1)

def testtube_tick(Block *super):
    super.dy += land_rnd(0, 0.5)
    block_tick(super)

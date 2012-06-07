import common
import block, render

class Cube:
    Block super

Cube *def cube_new(Blocks *blocks, float x, y, z, BlockType *kind):
    Cube *self
    land_alloc(self)
    block_init((void *)self, blocks, x, y, z, kind)
    return self

def cube_touch(Block *super, Block *c, float x, y, z):
    if y < 0 and c->block_type == Render_Plate:
        c->frame = 1

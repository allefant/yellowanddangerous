import common
import block, render

class Cube:
    Block super

Cube *def cube_new(Blocks *blocks, float x, y, z, BlockType *kind):
    Cube *self
    land_alloc(self)
    block_init((void *)self, blocks, x, y, z, kind)
    return self

def cube_touch(Block *super, Block *c, float dx, dy, dz):
    if dy < 0 and c->block_type == Render_Plate:
        float x = super.x + super.xs / 2
        float z = super.z + super.zs / 2
        if x >= c.x and z >= c.z and x <= c.x + c.xs and z <=  c.z + c.zs:
            c->frame = 1

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
        float x1 = c.x + c.xs / 3
        float z1 = c.z + c.zs / 3
        float x2 = c.x + c.xs - c.xs / 3
        float z2 = c.z + c.zs - c.zs / 3
        if super.x < x2 and super.z < z2 and\
                super.x + super.xs > x1 and super.z + super.zs > z1:
            c->frame = 1

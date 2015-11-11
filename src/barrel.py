import cube

def barrel_touch(Block *super, Block *c, float x, y, z):
    cube_touch(super, c, x, y, z)
    if y < 0:
        if c.block_type == Render_RampLeft:
            super.frame = 1
        elif c.block_type == Render_RampRight:
            super.frame = 2
        else:
            super.frame = 0

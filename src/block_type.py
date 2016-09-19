import common
import block
static import render

class BlockType:
    char *name
    float xs, ys, zs
    bool dynamic # in the dynamic list - must be set for any block that can move
    bool lift # can be lifted
    bool transparent # in the transparent list
    bool fixed # cannot be pushed/pulled
    bool invisible
    bool animated
    LandArray *bitmaps
    #float x, y, z
    int btid

    void (*tick)(Block *)
    void (*touch)(Block *, Block *, float, float, float)
    void (*destroy)(Block *)
    Block *(*allocate)(void)
    void (*post_init)(Block *)

global LandArray *block_types

BlockType *def blocktype_new(char const *name, float xs, ys, zs,
        void (*tick)(Block *),
        void (*touch)(Block *, Block *, float, float, float),
        void (*destroy)(Block *),
        Block *(*allocate)(void),
        void (*post_init)(Block *)):
    BlockType *self
    land_alloc(self)
    self->name = land_strdup(name)
    self->xs = xs
    self->ys = ys
    self->zs = zs
    self->dynamic = False
    self->lift = False
    self->transparent = False
    self->tick = tick
    self->touch = touch
    self->destroy = destroy
    self->allocate = allocate
    self->post_init = post_init
    return self

def blocktype_destroy(BlockType *self):
    if self.bitmaps:
        for LandImage *pic in LandArray *self->bitmaps:
            land_image_destroy(pic)
        land_array_destroy(self->bitmaps)
    land_free(self)

def blocktype_preload(BlockType *self) -> bool:
    for LandImage *pic in LandArray *self.bitmaps:
        if land_image_load_on_demand(pic):
            return True
    return False

def block_type_flowers -> BlockType**:
    return (BlockType *[8]) {None,
        Render_Gentian,
        Render_Edelweiss,
        Render_Orchid,
        Render_Hyacinth,
        Render_Sunflower,
        Render_Rose,
        Render_Belladonna}
   
def block_type_flower(BlockType *self) -> int:
    BlockType **flowers = block_type_flowers()
    for int i in range(1, 8):
        if self == flowers[i]:
            return i
    return 0

def block_flower(int i) -> BlockType *:
    BlockType **flowers = block_type_flowers()
    return flowers[i]

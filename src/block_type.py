import common
import block

class BlockType:
    char *name
    float xs, ys, zs
    bool dynamic
    bool lift
    bool transparent
    bool fixed
    bool invisible
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

def blocktype_preload(BlockType *self):
    for LandImage *pic in LandArray *self.bitmaps:
        land_image_load_on_demand(pic)
/* This file was generated by scramble.py. */
#line 1 "src/block.py"
#ifndef _BLOCK_
#define _BLOCK_
typedef struct Blocks Blocks;
typedef struct Block Block;
#line 1
#include "common.h"
#include "isometric.h"
#include "block_type.h"
#line 7
struct Blocks {
    LandArray * fixed;
    LandArray * dynamic;
    LandArray * transparent;
    LandArray * animated;
    bool rebuild_static_cache;
    bool rebuild_dynamic_cache;
};
void blocks_list_destroy(LandArray * (* list));
#line 22
void blocks_clear(Blocks * self);
#line 30
void blocks_reset(Blocks * self);
#line 39
Blocks* blocks_new(void);
#line 43
void blocks_destroy(Blocks * self);
#line 47
Block* blocks_pick(Blocks * self, float xp, float yp, Viewport * viewport);
#line 66
struct Block {
    BlockType * block_type;
#line 69
    Blocks * blocks;
    float x, y, z;
    float xs, ys, zs;
    float r, g, b, a;
    int frame;
    float dx, dy, dz;
    bool ground;
    int recursion_prevention;
    bool no_fall;
    int bid;
#line 80
    bool pushed_something;
    bool mover;
#line 83
    LandArray * cache;
};
void block_init(Block * self, Blocks * blocks, float x, float y, float z, BlockType * block_type);
#line 108
Block* block_new(Blocks * blocks, float x, float y, float z, BlockType * block_type);
#line 114
void block_destroy(Block * self);
#line 118
Block* block_allocate(void);
#line 123
void block_post_init(Block * self);
#line 126
void block_add(Block * self);
#line 139
Block* block_change_type(Block * self, int d);
#line 156
Block* block_change_type_to(Block * self, char const * text);
#line 162
void block_del(Block * self);
#line 182
bool block_overlaps(Block * self, Block * other);
#line 221
bool block_center_overlaps(Block * super, Block * c);
#line 228
LandArray* block_colliders(Block * self);
#line 244
bool block_move(Block * self, float dx, float dy, float dz);
#line 252
void move_on_top(Block * self, float dx, float dy, float dz);
#line 264
float block_distance(Block * self, Block * other);
#line 270
bool block_push(Block * self, float odx, float ody, float odz);
#line 365
int block_recursion_tag(void);
#line 369
bool block_pull(Block * self, float dx, float dy, float dz);
#line 407
int block_is_inside(Block * self, float xp, float yp, Viewport * viewport);
#line 450
void block_get_bounding_rect(Block * self, Viewport * viewport, float * x1, float * y1, float * x2, float * y2);
#line 458
int block_sort_order(Block * self, Block * other, Viewport * viewport);
#line 503
void block_tick(Block * self);
#line 539
void block_touch(Block * self, Block * c, float dx, float dy, float dz);
#line 542
bool blocks_preload(Blocks * self);
#line 557
void blocks_shift(Blocks * self, int dx, int dy, int dz);
#endif
/* This file was generated by scramble.py. */

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
#line 29
void blocks_reset(Blocks * self);
#line 38
Blocks* blocks_new(void);
#line 42
void blocks_destroy(Blocks * self);
#line 46
Block* blocks_pick(Blocks * self, float xp, float yp, Viewport * viewport);
#line 65
struct Block {
    BlockType * block_type;
#line 68
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
#line 79
    bool pushed_something;
    bool mover;
#line 82
    LandArray * cache;
};
void block_init(Block * self, Blocks * blocks, float x, float y, float z, BlockType * block_type);
#line 107
Block* block_new(Blocks * blocks, float x, float y, float z, BlockType * block_type);
#line 113
void block_destroy(Block * self);
#line 117
Block* block_allocate(void);
#line 122
void block_post_init(Block * self);
#line 125
void block_add(Block * self);
#line 138
Block* block_change_type(Block * self, int d);
#line 155
Block* block_change_type_to(Block * self, char const * text);
#line 161
void block_del(Block * self);
#line 181
bool block_overlaps(Block * self, Block * other);
#line 220
bool block_center_overlaps(Block * super, Block * c);
#line 227
LandArray* block_colliders(Block * self);
#line 243
bool block_move(Block * self, float dx, float dy, float dz);
#line 251
void move_on_top(Block * self, float dx, float dy, float dz);
#line 263
float block_distance(Block * self, Block * other);
#line 269
bool block_push(Block * self, float odx, float ody, float odz);
#line 364
int block_recursion_tag(void);
#line 368
bool block_pull(Block * self, float dx, float dy, float dz);
#line 406
int block_is_inside(Block * self, float xp, float yp, Viewport * viewport);
#line 449
void block_get_bounding_rect(Block * self, Viewport * viewport, float * x1, float * y1, float * x2, float * y2);
#line 457
int block_sort_order(Block * self, Block * other, Viewport * viewport);
#line 502
void block_tick(Block * self);
#line 538
void block_touch(Block * self, Block * c, float dx, float dy, float dz);
#line 541
bool blocks_preload(Blocks * self);
#line 556
void blocks_shift(Blocks * self, int dx, int dy, int dz);
#endif
/* This file was generated by scramble.py. */

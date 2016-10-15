/* This file was generated by scramble.py. */
#line 1 "src/block_type.py"
#ifndef _BLOCK_TYPE_
#define _BLOCK_TYPE_
typedef struct BlockType BlockType;
#line 1
#include "common.h"
#include "block.h"
#line 5
struct BlockType {
    char * name;
    float xs, ys, zs;
    bool dynamic /* in the dynamic list - must be set for any block that can move */;
    bool lift /* can be lifted */;
    bool transparent /* in the transparent list */;
    bool fixed /* cannot be pushed/pulled */;
    bool invisible;
    bool animated;
    LandArray * bitmaps;
#line 16
    int btid;
#line 18
    void(* tick)(Block *);
    void(* touch)(Block *, Block *, float, float, float);
    void(* destroy)(Block *);
    Block * (* allocate)(void);
    void(* post_init)(Block *);
};
extern LandArray * block_types;
#line 31
BlockType* blocktype_new(char const * name, float xs, float ys, float zs, void(* tick)(Block *), void(* touch)(Block *, Block *, float, float, float), void(* destroy)(Block *), Block * (* allocate)(void), void(* post_init)(Block *));
#line 48
void blocktype_destroy(BlockType * self);
#line 55
bool blocktype_preload(BlockType * self);
#line 71
int block_type_flower(BlockType * self);
#line 78
BlockType* block_flower(int i);
#endif
/* This file was generated by scramble.py. */
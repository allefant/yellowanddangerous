/* This file was generated by scramble.py. */
#line 1 "src/save.py"
#ifndef _SAVE_
#define _SAVE_
typedef struct SaveInfo SaveInfo;
#line 1
#include "common.h"
#line 27
struct SaveInfo {
    bool saved;
    bool exits [4];
    int n;
    float * xy;
};
#include "block.h"
#include "game.h"
#include "editor.h"
#line 41
void save_info(void);
#line 58
void load_info(void);
#line 107
void save_get_name(char const * base, int level, char const * suffix, char * out);
#line 113
void save_level(bool editing);
#line 173
void save_check(int level, SaveInfo * si);
#line 227
void load_level(bool editing);
#line 312
void save_load_from_offset(LandBuffer * f, int ox, int oy, int oz);
#line 358
void save_reset_room(int i);
#line 364
void save_new(void);
#endif
/* This file was generated by scramble.py. */

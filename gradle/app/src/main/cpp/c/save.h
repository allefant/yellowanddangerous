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
#line 43
void save_info(void);
#line 67
void load_info(void);
#line 130
void save_get_name(char const * base, int level, char const * suffix, char * out);
#line 136
void save_level(bool editing, bool at_entrance);
#line 199
void save_check(int level);
#line 255
void load_level(bool editing, bool at_entrance);
#line 355
void save_load_from_offset(LandBuffer * f, int ox, int oy, int oz, bool editing);
#line 401
void save_reset_room(int i);
#line 413
void save_new(void);
#line 424
bool save_is_saved(int i);
#line 427
int save_get_level_n(int i);
#line 430
float* save_get_level_xy(int i);
#endif
/* This file was generated by scramble.py. */

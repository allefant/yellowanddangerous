/* This file was generated by scramble.py. */
#line 1 "src/allefant.py"
#ifndef _ALLEFANT_
#define _ALLEFANT_
typedef struct Allefant Allefant;
#line 1
#include "common.h"
#include "block.h"
#line 2
#include "game.h"
#line 2
#include "player.h"
#line 4
struct Allefant {
    Block super;
    int step;
    int direction;
    int want_direction;
    int rotstep;
    int waypoint;
    int wait;
    float tx, tz;
    float ax, az;
    int travel;
};
Block* allefant_allocate(void);
#line 21
void allefant_init(Block * super);
#line 36
void find_waypoint(Block * super);
#line 48
void allefant_destroy(Block * super);
#line 52
void allefant_tick(Block * super);
#line 120
void allefant_touch(Block * super, Block * c, float dx, float dy, float dz);
#endif
/* This file was generated by scramble.py. */
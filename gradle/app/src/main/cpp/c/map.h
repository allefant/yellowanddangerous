/* This file was generated by scramble.py. */
#line 1 "src/map.py"
#ifndef _MAP_
#define _MAP_
typedef struct MapRender MapRender;
#line 1
#include "game.h"
#include "save.h"
#line 5
struct MapRender {
    int l;
    int current;
    int count;
    Block * flower [8];
    Block * test_tube;
};
#line 14
void map_render(void);
#endif
/* This file was generated by scramble.py. */

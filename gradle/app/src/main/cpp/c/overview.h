/* This file was generated by scramble.py. */
#line 1 "src/overview.py"
#ifndef _OVERVIEW_
#define _OVERVIEW_
typedef struct Overview Overview;
#line 1
#include "common.h"
#include "block.h"
#include "game.h"
#line 5
struct Overview {
    LandImage * screenshot [50];
    bool update [50];
    float mx, my;
    int selected;
#line 11
    int zoom;
    double zoomx, zoomy;
};
Overview* overview_new(void);
#line 24
void overview_update(Overview * self);
#line 32
void overview_tick(Overview * self);
#line 66
void overview_render_next(Overview * self);
#line 98
void overview_update_level(Overview * self, int level);
#line 101
void overview_destroy(Overview * self);
#line 106
void overview_render(Overview * self);
#line 143
void overview_click(Overview * self, float sx, float sy, int clicked, int released);
#line 164
void overview_swap_levels(Overview * self, int level1, int level2);
#endif
/* This file was generated by scramble.py. */

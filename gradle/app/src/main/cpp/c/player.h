/* This file was generated by scramble.py. */
#line 1 "src/player.py"
#ifndef _PLAYER_
#define _PLAYER_
typedef struct Player Player;
#line 1
#include "common.h"
#include "block.h"
#line 2
#include "game.h"
#line 2
#include "main.h"
#line 6
struct Player {
    Block super;
    LandArray * stack;
    int step;
    int direction;
    int want_direction;
    int rotstep;
    bool pull /* jump key pressed with no direction keys pressed */;
    bool reverse /* started moving in backwards direction */;
    bool pushing;
    bool dead;
#line 18
    bool lever;
    bool metal;
#line 21
    int accel;
};
Block* player_allocate(void);
#line 28
void player_init(Block * super);
#line 41
void player_destroy(Block * super);
#line 47
void player_try_pull(Player * self, float px, float pz);
#line 69
void player_grab(Player * self);
#line 97
void player_lift(Player * self);
#line 108
void player_tick(Block * super);
#line 295
void player_touch(Block * super, Block * c, float dx, float dy, float dz);
#line 369
void player_find_entrance(Block * super);
#endif
/* This file was generated by scramble.py. */

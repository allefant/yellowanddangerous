/* This file was generated by scramble.py. */
#line 1 "src/all.py"
#ifndef _ALL_
#define _ALL_
typedef struct All All;
#line 1
#include "common.h"
#line 3
struct All {
    int FPS;
    int w, h;
    LandFont * font;
    LandFont * medium;
    LandFont * big;
#line 11
    bool up, down, left, right, jump;
    float up_s, down_s, left_s, right_s;
#line 14
    int ftpos;
    double frame_times [60];
    float direct_speed_measure;
#line 18
    bool show_fps;
    bool show_help;
#line 21
    int cheatpos [10];
#line 23
    LandColor text;
#line 25
    bool title;
#line 27
    bool editor_enabled;
    bool editor;
    int text_input;
    int cursor;
#line 32
    LandColor tint;
#line 40
    int dpad;
    int music;
    int sound;
#line 44
    int fullscreen;
#line 46
    int load_after_redraw;
    bool find_entrance;
#line 49
    int time;
    bool overview;
    bool render_screenshot;
#line 53
    int code;
    bool godmode;
#line 56
    bool swipe;
    double swipex, swipey, swipet, swipej;
#line 59
    int resize_in_ticks;
    bool show_map;
    bool show_ad;
#line 63
    bool test;
};
#endif
/* This file was generated by scramble.py. */

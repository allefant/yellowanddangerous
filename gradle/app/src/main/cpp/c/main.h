/* This file was generated by scramble.py. */
#line 1 "src/main.py"
#ifndef _MAIN_
#define _MAIN_
#line 1
#include "common.h"
#include "render.h"
#line 2
#include "config.h"
#include "save.h"
#include "title.h"
#include "test.h"
#line 7
extern char * main_data_path;
#line 10
void main_switch_to_game(void);
#line 16
void main_switch_to_title(int com);
#line 21
void all_init(All * self);
#line 34
void sound(LandSound * s, float vol);
#line 38
void add_time(void);
#line 45
void get_fps(double * average, double * minmax);
#line 65
void redraw(void);
#line 111
void reload_fonts(void);
#line 142
void init(void);
#line 169
void done(void);
#line 174
void update(void);
#line 208
void runner_init(LandRunner * self);
#line 211
void runner_done(LandRunner * self);
#line 233
void runner_update(LandRunner * self);
#line 278
void runner_redraw(LandRunner * self);
#line 289
int my_main(void);
#endif
/* This file was generated by scramble.py. */

/* This file was generated by scramble.py. */
#line 1 "src/menu.py"
#ifndef _MENU_
#define _MENU_
typedef struct Menu Menu;
#line 1
#include "main.h"
#line 5
struct Menu {
    int menu [3];
    char items [16] [128] [32];
    int n [16];
    int hilite [3];
#line 11
    int pos;
    int sub_frame;
};
#define S(text) \
    strcpy(menu->items [menu->pos] [menu->n [menu->pos]++], text);
#define T \
    menu->pos++; \
    menu->n [menu->pos] = 0;
#line 20
Menu* menu_new(void);
#line 124
void menu_toggle(void);
#line 136
void menu_draw(Menu * menu);
#line 176
void menu_key(int k, bool shift);
#define ON(x, k) \
    if (land_equals(text, x)) { \
        menu_key(k, 0); \
    }
#define ON_SHIFT(x, k) \
    if (land_equals(text, x)) { \
        menu_key(k, 1); \
    }
#line 323
bool menu_tick(Menu * menu, float mx, float my, float click);
#endif
/* This file was generated by scramble.py. */
/* This file was generated by scramble.py. */
#line 1 "src/input.py"
#include "input.h"
static bool check_pause_button(LandFloat mx, LandFloat my);
static bool check_title_button(LandFloat mx, LandFloat my);
static bool check_menu(LandFloat mx, LandFloat my, bool clicked);
#line 9
static bool check_pause_button(LandFloat mx, LandFloat my) {
    All * a = global_a;
    double rr = land_display_width() / 8 * 0.8;
    if (a->dpad == 2 || a->dpad == 3) {
        rr *= 1.5;
    }
#line 14
    double ry = rr;
    double rx = land_display_width() - rr;
    if (mx > rx && my < ry && (a->dpad < 4 || ! a->swipe)) {
        return 1;
    }
#line 18
    return 0;
}
static bool check_title_button(LandFloat mx, LandFloat my) {
    All * a = global_a;
    if (! a->show_map) {
        return 0;
    }
#line 24
    double rr = land_display_width() / 8 * 0.8;
    if (a->dpad == 2 || a->dpad == 3) {
        rr *= 1.5;
    }
#line 27
    double ry = rr;
    double rx = land_display_width() - rr;
    if (mx > rx && my > ry && my < ry + rr && (a->dpad < 4 || ! a->swipe)) {
        return 1;
    }
#line 31
    return 0;
}
static bool check_menu(LandFloat mx, LandFloat my, bool clicked) {
    if (! game->menu_on) {
        return 0;
    }
#line 36
    return menu_tick(game->menu, mx, my, clicked);
}
void input_toggle_pause(void) {
    All * a = global_a;
    if (a->editor_enabled) {
        menu_toggle();
    }
#line 41
    else {
#line 43
        if (a->show_map) {
            a->show_map = 0;
        }
#line 44
        else {
#line 46
            a->show_map = 1;
        }
    }
}
#line 48
void input_tick(void) {
    All * a = global_a;
#line 51
    int count = 0;
    bool any = 0;
    for (int ti = 0; ti < 11; ti += 1) {
        double mx = land_touch_x(ti);
        double my = land_touch_y(ti);
#line 57
        bool holding = land_touch_down(ti);
        bool clicked = holding && land_touch_delta(ti);
        bool released = ! land_touch_down(ti) && land_touch_delta(ti);
#line 61
        if (! holding && ! released) {
            continue;
        }
        if (check_pause_button(mx, my)) {
            if (clicked) {
                input_toggle_pause();
            }
#line 66
            return ;
        }
#line 69
        if (check_title_button(mx, my)) {
            a->show_map = 0;
            main_switch_to_title(0);
#line 71
            return ;
        }
#line 74
        if (check_menu(mx, my, released)) {
            break;
        }
        if (a->overview) {
            overview_click(game->overview, mx, my, clicked, released);
            break;
        }
        if (a->editor) {
            editor_click(mx, my, clicked, released);
            break;
        }
        if (! land_touch_down(ti)) {
            continue;
        }
#line 87
        any = 1;
        count++;
#line 90
        double rr = land_display_width() / 8 * 0.8;
        if (a->dpad == 2 || a->dpad == 3) {
            rr *= 1.5;
        }
        double dx, dy;
#line 96
        if (a->dpad > 3) {
            double p = 0.97;
            if (a->dpad == 4 || (a->dpad == 5 && count == 1)) {
                dx = mx - a->swipex;
                dy = my - a->swipey;
                a->swipex = a->swipex * p + mx * (1 - p);
                a->swipey = a->swipey * p + my * (1 - p);
            }
            if (! a->swipe) {
                a->swipe = 1;
#line 107
                if (a->dpad == 4) {
                    if (land_get_time() < a->swipet + 0.25) {
                        // double tap
                        if (! a->swipej) {
                            a->swipej = 1;
                        }
#line 111
                        else {
                            // after heaving, just push
                            // (so can lift+push, not lift+jump)
#line 115
                            a->swipej = 0;
                        }
                    }
#line 115
                    else {
#line 117
                        a->swipex = mx;
                        a->swipey = my;
                        a->swipej = 0;
                        dx = 0;
                        dy = 0;
                    }
                }
#line 122
                else if (a->dpad == 5) {
                    a->swipex = mx;
                    a->swipey = my;
                    a->swipej = 0;
                    dx = 0;
                    dy = 0;
                }
                a->swipet = land_get_time();
            }
#line 129
            else {
#line 131
                if (a->dpad == 5) {
                    if (count == 1) {
                        a->swipej = 0;
                    }
#line 134
                    if (count > 1) {
                        a->swipej = 1;
                    }
                }
            }
#line 137
            if (a->swipej) {
                a->jump = 1;
            }
        }
#line 138
        else {
#line 140
            double rx = rr;
            if (a->dpad == 1 || a->dpad == 3) {
                rx = land_display_width() - rr;
            }
#line 143
            double ry = land_display_height() - rr;
            if (a->dpad == 1 || a->dpad == 3) {
                rx = land_display_width() - rr;
            }
#line 146
            dx = mx - rx;
            dy = my - ry;
        }
        // move control
        //                  c
        //                 b d
        //                a   e
        //               9     f
        //              8       0
        //               7     1
        //                6   2
        //                 5 3
        //                  4
#line 160
        bool move = 0;
        if (a->dpad == 4 || (a->dpad == 5 && count == 1)) {
            if (dx * dx + dy * dy > rr * rr / 256) {
                move = 1;
            }
        }
#line 164
        if (a->dpad < 4) {
            if ((fabs(dx) < rr && fabs(dy) < rr)) {
                if (dx * dx + dy * dy > rr * rr / 16) {
                    move = 1;
                }
            }
        }
#line 169
        if (move) {
            double ang = atan2(dy, dx);
            // we use 16 subdivisions, the main directions get 12
            // out of that and the diagonals 4
            ang += pi / 16;
            if (ang < 0) {
                ang += pi * 2;
            }
#line 176
            int i = ang * 8 / pi;
            if (i <= 3 || i >= 0xd) {
                a->right = 1;
            }
#line 179
            if (i >= 1 && i <= 7) {
                a->down = 1;
            }
#line 181
            if (i >= 5 && i <= 0xb) {
                a->left = 1;
            }
#line 183
            if (i >= 9) {
                a->up = 1;
            }
#line 185
            a->swipet = land_get_time();
        }
        // jump control
        if (a->dpad == 4 || a->dpad == 5) {
#line 188
            ;
        }
#line 188
        else {
#line 191
            double rx = land_display_width() - rr;
            double ry = land_display_height() - rr;
            if (a->dpad == 1 || a->dpad == 3) {
                rx = rr;
            }
#line 195
            dx = mx - rx;
            dy = my - ry;
            if (dx * dx + dy * dy < rr * rr) {
                a->jump = 1;
            }
        }
    }
#line 200
    if (! any) {
        if (a->dpad == 5) {
            a->swipej = 0;
        }
#line 203
        if (a->dpad == 4) {
            if (a->swipe) {
                a->swipet = land_get_time();
            }
        }
#line 206
        a->swipe = 0;
    }
}
/* This file was generated by scramble.py. */

import common
import main
import menu
import editor

type Game *game
type Editor *editor

static def check_pause_button(LandFloat mx, my) -> bool:
    All *a = global_a
    double rr = land_display_width() / 8 * 0.8
    if a.dpad == 2 or a.dpad == 3:
        rr *= 1.5
    double ry = rr
    double rx = land_display_width() - rr
    if mx > rx and my < ry and (a.dpad < 4 or not a.swipe):
        return True
    return False

static def check_title_button(LandFloat mx, my) -> bool:
    All *a = global_a
    if not a.show_map:
        return False
    double rr = land_display_width() / 8 * 0.8
    if a.dpad == 2 or a.dpad == 3:
        rr *= 1.5
    double ry = rr
    double rx = land_display_width() - rr
    if mx > rx and my > ry and my < ry + rr and (a.dpad < 4 or not a.swipe):
        return True
    return False

static def check_menu(LandFloat mx, my, bool clicked) -> bool:
    if not game.menu_on:
        return False
    return menu_tick(game.menu, mx, my, clicked)

def input_toggle_pause:
    All *a = global_a
    if a.editor_enabled:
        menu_toggle()
    else:
        if a.show_map:
            a.show_map = False
        else:
            a.show_map = True

def input_tick:
    All *a = global_a

    int count = 0
    bool any = False
    for int ti in range(11):
        double mx = land_touch_x(ti)
        double my = land_touch_y(ti)

        bool holding = land_touch_down(ti)
        bool clicked = holding and land_touch_delta(ti)
        bool released = not land_touch_down(ti) and land_touch_delta(ti)

        if not holding and not released:
            continue

        if check_pause_button(mx, my):
            if clicked:
                input_toggle_pause()
            return

        if check_title_button(mx, my):
            a.show_map = False
            main_switch_to_title(0)
            return

        if check_menu(mx, my, released):
            break

        if a.overview:
            overview_click(game.overview, mx, my, clicked, released)
            break

        if a.editor:
            editor_click(mx, my, clicked, released):
            break
        
        if not land_touch_down(ti):
            continue
        any = True
        count++

        double rr = land_display_width() / 8 * 0.8
        if a.dpad == 2 or a.dpad == 3:
            rr *= 1.5

        double dx, dy

        if a.dpad > 3:
            double p = 0.97
            if a.dpad == 4 or (a.dpad == 5 and count == 1):
                dx = mx - a.swipex
                dy = my - a.swipey
                a.swipex = a.swipex * p + mx * (1 - p)
                a.swipey = a.swipey * p + my * (1 - p)

            if not a.swipe:
                a.swipe = True
                
                if a.dpad == 4:
                    if land_get_time() < a.swipet + 0.25:
                        # double tap
                        if not a.swipej:
                            a.swipej = 1
                        else:
                            # after heaving, just push
                            # (so can lift+push, not lift+jump)
                            a.swipej = 0
                    else:
                        a.swipex = mx
                        a.swipey = my
                        a.swipej = 0
                        dx = 0
                        dy = 0
                elif a.dpad == 5:
                    a.swipex = mx
                    a.swipey = my
                    a.swipej = 0
                    dx = 0
                    dy = 0
                    
                a.swipet = land_get_time()
            else:
                if a.dpad == 5:
                    if count == 1:
                        a.swipej = 0
                    if count > 1:
                        a.swipej = 1
                    
            if a.swipej:
                a.jump = True
        else:
            double rx = rr
            if a.dpad == 1 or a.dpad == 3:
                rx = land_display_width() - rr
            double ry = land_display_height() - rr
            if a.dpad == 1 or a.dpad == 3:
                rx = land_display_width() - rr
            dx = mx - rx
            dy = my - ry

        # move control
        #                  c
        #                 b d
        #                a   e
        #               9     f
        #              8       0
        #               7     1
        #                6   2
        #                 5 3
        #                  4

        bool move = False
        if a.dpad == 4 or (a.dpad == 5 and count == 1):
            if dx * dx + dy * dy > rr * rr / 256:
                move = True
        if a.dpad < 4:
            if (fabs(dx) < rr and fabs(dy) < rr) :
                if dx * dx + dy * dy > rr * rr / 16:
                    move = True

        if move:
            double ang = atan2(dy, dx)
            # we use 16 subdivisions, the main directions get 12
            # out of that and the diagonals 4
            ang += pi / 16
            if ang < 0:
                ang += pi * 2
            int i = ang * 8 / pi
            if i <= 3 or i >= 0xd:
                a.right = True
            if i >= 1 and i <= 7:
                a.down = True
            if i >= 5 and i <= 0xb:
                a.left = True
            if i >= 9:
                a.up = True
            a.swipet = land_get_time()

        # jump control
        if a.dpad == 4 or a.dpad == 5:
            pass
        else:
            double rx = land_display_width() - rr
            double ry = land_display_height() - rr
            if a.dpad == 1 or a.dpad == 3:
                rx = rr
            dx = mx - rx
            dy = my - ry
            if dx * dx + dy * dy < rr * rr:
                a.jump = True

    if not any:
        if a.dpad == 5:
            a.swipej = False
        if a.dpad == 4:
            if a.swipe:
                a.swipet = land_get_time()
        a.swipe = False

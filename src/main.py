#!/usr/bin/env python3
import sys, os, glob
import random
from math import *
from ctypes import *

from land import *

import render, game, config, debug

data_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "..")).encode("utf8")

class Allegro:
    
    def __init__(self):
        self.FPS = 60

        self.display = None
        self.font = None

        self.ftpos = 0
        self.frame_times = [0.0] * self.FPS
        self.direct_speed_measure = self.FPS
        
        self.game = None
        
        self.mouse_down = False
        self.mx = 0
        self.my = 0
        
        self.show_fps = False
        self.running = False

    def sound(self, name, vol):
        land_sound_play(getattr(render.Render, name), vol, 0, 1)

def add_time():
    a.frame_times[a.ftpos] = land_get_time()
    a.ftpos += 1
    if a.ftpos >= a.FPS:
        a.ftpos = 0

def get_fps():
    prev = a.FPS - 1
    min_dt = 1
    max_dt = 1 / 1000000
    av = 0
    for i in range(a.FPS):
        if i != a.ftpos:
            dt = a.frame_times[i] - a.frame_times[prev]
            if dt < min_dt and dt > 0:
                min_dt = dt
            if dt > max_dt:
                max_dt = dt
            av += dt
        prev = i
    av /= a.FPS - 1
    average = ceil(1 / av)
    d = 1 / min_dt - 1 / max_dt
    minmax = floor(d / 2)
    return average, minmax

def redraw():
    w = land_display_width()
    h = land_display_height()
    fh = land_font_height(a.font)

    render.render(a.game)

    if a.show_fps:
        f1, f2 = get_fps()
        land_text_pos(w, 0)
        land_font_set(a.font)
        land_color(*a.text)
        land_print_right(b"%s", ("FPS: %4d +- %-4d" % (f1, f2)).encode("utf8"))
        land_print_right(b"%s", ("%4d / sec" % int(1.0 / a.direct_speed_measure)).encode("utf8"))

def init():
    land_display_title(b"Yellow and Dangerous")
    a.font = land_font_load(data_path + b"/data/Muli-Regular.ttf", 10)

    a.up = False
    a.down = False
    a.left = False
    a.right = False
    a.jump = False

    a.text = 0, 0, 0, 1

    a.game = game.Game()
    game.game = a.game
    game.game.a = a

    a.show_fps = False

    a.running = True

    a.cheatpos = 0

def update():
    if a.running:
        a.game.tick()

    config.check_controls(a)

def runner_init(self):
    init()

def runner_update(self):
    update()

    if land_closebutton():
        land_quit()

    def cheat(unichar):
        cheatcode = "iddqd"
        if unichar == cheatcode[a.cheatpos]:
            a.cheatpos += 1
            if a.cheatpos == len(cheatcode):
                a.game.level += 1
                a.cheatpos = 0
                a.game.reset()
        else:
            a.cheatpos = 0

    if not land_keybuffer_empty():
        k = c_int(0)
        u = c_int(0)
        land_keybuffer_next(byref(k), byref(u))
        k = k.value
        u = u.value
        cheat(chr(u))

        if k == LandKeyEscape:
            land_quit()
        elif k == LandKeyFunction + 1:
            a.show_fps = not a.show_fps
        elif k == LandKeyFunction + 2:
            debug.no_mask = not debug.no_mask
        elif k == LandKeyFunction + 3:
            debug.bounding_boxes = not debug.bounding_boxes
        elif k == ord(" "):
            pass
        elif k == LandKeyEnter:
            if not a.running:
                a.running = True
                a.game = game.Game()
                a.game.start_time = al_get_time()
        elif k == ord("r"):
            a.game.reset()
        elif k == ord("m"):
            land_stream_set_playing(render.Render.music,
                not land_stream_is_playing(render.Render.music))

    a.mouse_down = land_mouse_button(0)
    a.mx = land_mouse_x()
    a.my = land_mouse_y()

def runner_redraw(self):

    t = -land_get_time()
    add_time()
           
    redraw()

    t += land_get_time()
    a.direct_speed_measure  = t

def main():
    global a
    a = Allegro()
    game.a = a
    render.a = a
    
    w, h = 960, 600
    done = False
    need_redraw = True
    a.show_help = True

    land_init()
    land_set_display_parameters(w, h, LAND_OPENGL)
    game_runner = land_runner_new(b"Yellow and Dangerous",
        CFUNCTYPE(None, LP_LandRunner)(runner_init),
        None,
        CFUNCTYPE(None, LP_LandRunner)(runner_update),
        CFUNCTYPE(None, LP_LandRunner)(runner_redraw),
        None,
        None)
    a.w = w
    a.h = h

    land_runner_register(game_runner)
    land_set_initial_runner(game_runner)
    land_mainloop()

def start():
    land_use_main(main)

if __name__ == "__main_":
    start()

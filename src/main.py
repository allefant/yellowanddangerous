#!/usr/bin/env python3
import sys, os, glob
import random
from math import *
from ctypes import *

from allegro import *

import render, game, config, debug

data_path = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

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
        al_play_sample(getattr(render.Render, name), vol, 0, 1,
            ALLEGRO_PLAYMODE_ONCE, None)

def add_time():
    a.frame_times[a.ftpos] = al_get_time()
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
    w = al_get_display_width(a.display)
    h = al_get_display_height(a.display)
    fh = al_get_font_line_height(a.font)

    render.render(a.game)

    if a.show_fps:
        f1, f2 = get_fps()
        al_draw_textf(a.font, a.text, w, 0, ALLEGRO_ALIGN_RIGHT, "%s",
              ("FPS: %4d +- %-4d" % (f1, f2)).encode("utf8"))
        al_draw_textf(a.font, a.text, w, fh, ALLEGRO_ALIGN_RIGHT, "%s",
              ("%4d / sec" % int(1.0 / a.direct_speed_measure)).encode("utf8"))

def init():
    a.up = False
    a.down = False
    a.left = False
    a.right = False
    a.jump = False

    a.text = al_map_rgb_f(0, 0, 0)

    a.game = game.Game()
    game.game = a.game
    game.game.a = a

    a.show_fps = False

    a.running = True

def update():
    if a.running:
        a.game.tick()

def main():
    global a
    a = Allegro()
    game.a = a
    render.a = a
    
    w, h = 960, 600
    done = False
    need_redraw = True
    a.show_help = True

    al_install_system(ALLEGRO_VERSION_INT, None)
    al_set_exe_name(__file__)
    al_init_image_addon()
    al_init_font_addon()
    al_init_primitives_addon()
    al_install_audio()
    al_init_acodec_addon()
    al_init_ttf_addon()
    al_reserve_samples(16)

    #al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR)
    #al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST)
    #al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST)
    al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST)
    al_set_new_display_flags(ALLEGRO_OPENGL)
    a.display = al_create_display(w, h)
    al_set_window_title(a.display, "Yellow and Dangerous")
    a.w = w
    a.h = h

    al_install_keyboard()
    al_install_mouse()

    a.font = al_load_font(data_path + "/data/Muli-Regular.ttf", 10, 0)

    timer = al_create_timer(1.0 / a.FPS)

    queue = al_create_event_queue()
    al_register_event_source(queue, al_get_keyboard_event_source())
    al_register_event_source(queue, al_get_mouse_event_source())
    al_register_event_source(queue, al_get_timer_event_source(timer))
    al_register_event_source(queue, al_get_display_event_source(a.display))

    init()

    al_start_timer(timer)

    cheatpos = 0
    while not done:

        event = ALLEGRO_EVENT()

        if need_redraw and al_is_event_queue_empty(queue):
            t = -al_get_time()
            add_time()
            redraw()
            t += al_get_time()
            a.direct_speed_measure  = t
            al_flip_display()
            need_redraw = False

        al_wait_for_event(queue, byref(event))

        def cheat(event):
            nonlocal cheatpos
            cheatcode = "iddqd"
            if event.keyboard.unichar == ord(cheatcode[cheatpos]):
                cheatpos += 1
                if cheatpos == len(cheatcode):
                    a.game.level += 1
                    cheatpos = 0
                    a.game.reset()
            else:
                cheatpos = 0

        if event.type == ALLEGRO_EVENT_KEY_CHAR:
            cheat(event)
            if event.keyboard.keycode == ALLEGRO_KEY_ESCAPE:
                done = True
            elif event.keyboard.keycode == ALLEGRO_KEY_F1:
                a.show_fps = not a.show_fps
            elif event.keyboard.keycode == ALLEGRO_KEY_F2:
                debug.no_mask = not debug.no_mask
            elif event.keyboard.keycode == ALLEGRO_KEY_F3:
                debug.bounding_boxes = not debug.bounding_boxes
            elif event.keyboard.keycode == ALLEGRO_KEY_SPACE:
                pass
            elif event.keyboard.keycode == ALLEGRO_KEY_ENTER:
                if not a.running:
                    a.running = True
                    a.game = game.Game()
                    a.game.start_time = al_get_time()
            elif event.keyboard.keycode == ALLEGRO_KEY_R:
                a.game.reset()
            elif event.keyboard.keycode == ALLEGRO_KEY_M:
                al_set_audio_stream_playing(render.Render.music,
                    not al_get_audio_stream_playing(render.Render.music))

        elif event.type == ALLEGRO_EVENT_KEY_DOWN:
            config.check_controls(a, event, True)
            
        elif event.type == ALLEGRO_EVENT_KEY_UP:
            config.check_controls(a, event, False)
              
        elif event.type == ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = True

        elif event.type == ALLEGRO_EVENT_TIMER:
            update()
            need_redraw = True

        elif event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            a.mouse_down = True

        elif event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            a.mouse_down = False

        elif event.type == ALLEGRO_EVENT_MOUSE_AXES:
            a.mx = event.mouse.x
            a.my = event.mouse.y

    al_destroy_display(a.display)
    al_uninstall_system()

def start():
    al_main(main)

if __name__ == "__main_":
    start()

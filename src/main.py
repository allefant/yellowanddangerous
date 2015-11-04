import common
import render, config
import save

global char *main_data_path
    
def all_init(All *self):
    self->FPS = 60

    self->font = None

    self->ftpos = 0
    self->direct_speed_measure = self->FPS
    
    self->mouse_down = False
    self->mx = 0
    self->my = 0
    
    self->show_fps = False
    self->running = False

def sound(LandSound *s, float vol):
    land_sound_play(s, vol, 0, 1)

def add_time():
    All *a = global_a
    a->frame_times[a->ftpos] = land_get_time()
    a->ftpos += 1
    if a->ftpos >= a->FPS:
        a->ftpos = 0

def get_fps(double *average, *minmax):
    All *a = global_a
    int prev = a->FPS - 1
    double min_dt = 1
    double max_dt = 1 / 1000000.0
    double av = 0
    for int i in range(a->FPS):
        if i != a->ftpos:
            double dt = a->frame_times[i] - a->frame_times[prev]
            if dt < min_dt and dt > 0:
                min_dt = dt
            if dt > max_dt:
                max_dt = dt
            av += dt
        prev = i
    av /= (double)a->FPS - 1
    *average = ceil(1 / av)
    double d = 1 / min_dt - 1 / max_dt
    *minmax = floor(d / 2)

def redraw():
    All *a = global_a
    float w = land_display_width()
    #float h = land_display_height()
    #float fh = land_font_height(a->font)

    render(game)

    if a->show_fps:
        double f1, f2
        get_fps(&f1, &f2)
        land_text_pos(w, 0)
        land_font_set(a->font)
        land_color(a->text.r, a->text.g, a->text.b, a->text.a)
        land_print_right("FPS: %4d +- %-4d", (int)f1, (int)f2)
        land_print_right("%4d / sec", (int)(1.0 / a->direct_speed_measure))

def init():
    All *a = global_a
    all_init(a)
    land_display_title("Yellow and Dangerous")
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    land_buffer_cat(b, "/data/Muli-Regular.ttf")
    char *path = land_buffer_finish(b)
    a->font = land_font_load(path, 10)
    land_free(path)

    a->up = False
    a->down = False
    a->left = False
    a->right = False
    a->jump = False

    a->text = (LandColor){0, 0, 0, 1}

    config_controls_read()

    game = game_new()

    a->show_fps = False

    #a->running = True

    a->cheatpos = 0

def done():
    All *a = global_a
    game_del(game)
    land_font_destroy(a->font)

def update():
    All *a = global_a
    config_check_controls(a)

    if a->running:
        game_tick(game)

def runner_init(LandRunner *self):
    init()

def runner_done(LandRunner *self):
    done()

static def cheat(char unichar):
    All *a = global_a
    char const *cheatcode = "iddqd"
    if unichar == cheatcode[a->cheatpos]:
        a->cheatpos += 1
        if a->cheatpos == (int)strlen(cheatcode):
            game->level += 1
            a->cheatpos = 0
            game_reset(game)
    else:
        a->cheatpos = 0

def runner_update(LandRunner *self):
    All *a = global_a

    update()

    if land_closebutton():
        land_quit()

    if not land_keybuffer_empty():
        int k, u
        land_keybuffer_next(&k, &u)
        cheat(u)

        if k == LandKeyEscape:
            land_quit()
        elif k == LandKeyFunction + 1:
            a->show_fps = not a->show_fps
        elif k == LandKeyFunction + 2:
            save_level()
        elif k == LandKeyFunction + 3:
            load_level()
        elif k == LandKeyFunction + 5:
            debug_no_mask = not debug_no_mask
        elif k == LandKeyFunction + 6:
            debug_bounding_boxes = not debug_bounding_boxes
        elif k == ' ':
            pass
        elif k == LandKeyEnter:
            if not a->running:
                a->running = True
                game = game_new()
                game->start_time = land_get_time()
        elif k == 'r':
            game_reset(game)
            a.running = False
        elif k == 'q':
            game_reset(game)
            a.running = False
        elif k == 'e':
            game_reset(game)
            a.running = False
        #elif k == 'm':
        #    land_stream_set_playing(render_music,
        #        not land_stream_is_playing(render_music))

    a->mouse_down = land_mouse_button(0)
    a->mx = land_mouse_x()
    a->my = land_mouse_y()

def runner_redraw(LandRunner *self):
    All *a = global_a

    double t = -land_get_time()
    add_time()
           
    redraw()

    t += land_get_time()
    a->direct_speed_measure  = t

int def my_main():
    All *a
    land_alloc(a)
    
    int w = 960
    int h = 600
    a->show_help = True

    land_init()

    main_data_path = land_strdup(".")
    
    #land_set_display_parameters(w, h, LAND_OPENGL)
    *** "ifdef" ANDROID
    land_set_display_parameters(w, h, LAND_FULLSCREEN | LAND_DEPTH)
    *** "else"
    land_set_display_parameters(w, h, LAND_DEPTH | LAND_RESIZE)
    *** "endif"
    LandRunner *game_runner = land_runner_new("Yellow and Dangerous",
        runner_init,
        None,
        runner_update,
        runner_redraw,
        None,
        runner_done)
    a->w = w
    a->h = h

    land_runner_register(game_runner)
    land_set_initial_runner(game_runner)
    land_mainloop()

    land_free(main_data_path)
    land_free(a)

    return 0

land_use_main(my_main)


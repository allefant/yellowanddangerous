import common
import render, config
import save
import title
import test

global char *main_data_path
type Game *game

def main_switch_to_game:
    All *a = global_a
    a.title = False
    if not game.state:
        a.load_after_redraw = 1

def main_switch_to_title(int com):
    All *a = global_a
    a.title = True
    title_com(com)
    
def all_init(All *self):
    memset(self, 0, sizeof *self)
    self.title = True
    self->FPS = 60

    self->font = None

    self->ftpos = 0
    self->direct_speed_measure = self->FPS

    
    self->show_fps = False

def sound(LandSound *s, float vol):
    All *a = global_a
    land_sound_play(s, vol * a.sound / 6.0, 0, 1)

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

    if a.load_after_redraw:
        if not a.overview:
            render_loading_screen()
        if a.load_after_redraw == 1:
            a.load_after_redraw = 2
        elif a.load_after_redraw == 2:
            # wait for logic code to advance
            pass
        if a.load_after_redraw > 2:
            a.load_after_redraw++
            double t = land_get_time()
            while True:
                if not blocks_preload(game->blocks):
                    a.load_after_redraw = 0

                    if a.overview:
                        overview_render_next(game->overview)
                    break
                if land_get_time() > t + 0.01:
                    break

        if not a.overview:
            return
    
    float w = land_display_width()
    float h = land_display_height()
    #float fh = land_font_height(a->font)

    if a.title:
        title_render()
    else:
        render(game, w, h)

    if a->show_fps:
        double f1, f2
        get_fps(&f1, &f2)
        land_text_pos(w, 0)
        land_font_set(a->font)
        land_color(a->text.r, a->text.g, a->text.b, a->text.a)
        land_print_right("FPS: %4d +- %-4d", (int)f1, (int)f2)
        land_print_right("%4d / sec", (int)(1.0 / a->direct_speed_measure))

def reload_fonts:
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    #land_buffer_cat(b, "/data/Muli-Regular.ttf")
    land_buffer_cat(b, "/data/JosefinSans-Regular.ttf")
    char *path = land_buffer_finish(b)
    
    All *a = global_a
    float w = land_display_width()
    #float h = land_display_height()
    double s = w / 960

    if a.font:
        land_font_destroy(a.font)
    if a.medium:
        land_font_destroy(a.medium)
    if a.big:
        land_font_destroy(a.big)
    
    a.font = land_font_load(path, 10 * s)
    land_font_scale(a.font, 1.0 / s)
    a.medium = land_font_load(path, 24 * s)
    land_font_scale(a.medium, 1.0 / s)
    a.big = land_font_load(path, 60 * s)
    land_font_scale(a.big, 1.0 / s)

    land_font_set(a.medium)
    land_text_get_width("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")

    land_free(path)

def init():
    All *a = global_a
    all_init(a)
    land_display_title("Yellow and Dangerous")
    reload_fonts()

    a.up = False
    a.down = False
    a.left = False
    a.right = False
    a.jump = False

    a->text = (LandColor){0, 0, 0, 1}

    config_controls_read()

    title_init()

    game_setup(land_display_width(), land_display_height())

    render_setup()

    a->show_fps = False

    for int i in range(10):
        a->cheatpos[i] = 0

def done():
    All *a = global_a
    game_del(game)
    land_font_destroy(a->font)

def update():
    All *a = global_a

    if land_was_resized():
        viewport_update(game->viewport, land_display_width(),
            land_display_height())
        a.resize_in_ticks = 10

    if a.resize_in_ticks > 0:
        a.resize_in_ticks--
        if a.resize_in_ticks == 0:
            reload_fonts()

    if a.load_after_redraw:
        if a.load_after_redraw == 2:
            load_level(a.editor or game.record->is_replaying
                or game.record->is_recording, a.find_entrance)
            if a.find_entrance:
                a.find_entrance = False
                if game->player:
                    player_find_entrance(&game->player->super)
            if game and game.player:
                record_load(game.record, game.level, game.player->super.x,
                    game.player->super.y, game.player->super.z)
            a.load_after_redraw++
        return
    
    config_check_controls(a)

    if a.title:
        title_tick()
    else:
        game_tick(game)

def runner_init(LandRunner *self):
    init()

def runner_done(LandRunner *self):
    done()

static def cheat(char unichar):
    All *a = global_a
    char const *cheatcodes[] = {"iddqd", "idflower", "idkey"}
    for int i in range(3):
        if unichar == cheatcodes[i][a->cheatpos[i]]:
            a->cheatpos[i] += 1
            if a->cheatpos[i] == (int)strlen(cheatcodes[i]):
                a->cheatpos[i] = 0
                if i == 0:
                    a.godmode = not a.godmode
                if i == 1:
                    for int j in range(1, 8):
                        game.flower[j] = True
                        game.test_tube[j] = True
                if i == 2:
                    game.key = not game.key
        else:
            a->cheatpos[i] = 0

def runner_update(LandRunner *self):
    All *a = global_a

    update()

    if land_closebutton():
        save_level(False, False)
        land_quit()

    if land_switched_out():
        save_level(False, False)

    if land_was_halted():
        pass

    if not land_keybuffer_empty():
        int k, u
        land_keybuffer_next(&k, &u)
        cheat(u)

        if k == LandKeyEscape:
            save_level(False, False)
            land_quit()
        elif k == LandKeyFunction + 1:
            a->show_fps = not a->show_fps
        else:
            if a.text_input:
                if u == '|':
                    u = '\n'
                if u == 13:
                    u = 0
                if a.text_input == 1:
                    game->title[a.cursor++] = u
                elif a.text_input == 2:
                    game->hint[a.cursor++] = u
                if u == 0:
                    a.text_input = 0
            elif not a.title:
                if a.editor_enabled:
                    game_key(game, k)

        #elif k == 'm':
        #    land_stream_set_playing(render_music,
        #        not land_stream_is_playing(render_music))

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

    if land_argc > 1:
        if land_equals(land_argv[1], "test"):
            return test()
    
    #land_set_display_parameters(w, h, LAND_OPENGL)
    *** "ifdef" ANDROID
    land_set_display_parameters(0, 0, LAND_FULLSCREEN | LAND_DEPTH |
        LAND_LANDSCAPE)
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


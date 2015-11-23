import common
import main

static bool settings
static bool restart
static Block *block1
static Block *block2

def get_line(float y) -> int:
    float w = land_display_width()
    float h = land_display_height()
    double s = w / 960
    h /= s

    float by = (h - 64 * 5) / 2
    y /= s
    y -= by
    y /= 64

    return y

def title_com(int com):
    if com == 1:
        settings = True

def title_tick:
    float w = land_display_width()
    float h = land_display_height()
    double s = w / 960
    h /= s

    All *a = global_a

    if land_key_pressed(LandKeyEnter):
        main_switch_to_game()

    if land_key_pressed(LandKeyBack):
        if settings:
            settings = False
            save_info()
        elif restart:
            main_switch_to_game()
            restart = False
        else:
            load_info()
            main_switch_to_game()

    for int ti in range(11):
        if land_touch_down(ti) and land_touch_delta(ti):
            int i = get_line(land_touch_y(ti))
            if settings:
                if i == 0:
                    a.dpad++
                    if a.dpad == 4:
                        a.dpad = 0
                elif i == 2:
                    a.music = volget(land_touch_x(ti))
                    song_volume()
                elif i == 3:
                    a.sound = volget(land_touch_x(ti))
                    sound(Render_on, 1)
                elif i == 4:
                    settings = False
                    save_info()
            elif restart:
                if i == 3:
                    # start new game
                    save_new()
                    main_switch_to_game()
                    restart = False
                elif i == 4:
                    main_switch_to_game()
                    restart = False
            else:
                if i == 2:
                    # reset the current room
                    load_info()
                    save_reset_room(game->level)
                    main_switch_to_game()
                    if game->player:
                        player_find_entrance(&game->player->super)
                if i == 3:
                    restart = True
                if i == 0:
                    # load saved game
                    load_info()
                    main_switch_to_game()
                if i == 4:
                    load_info()
                    settings = True

static int volx = 0
static def drawvol(int v, float x, y):
    volx = x
    y += 16
    float s = 48
    for int i in range(7):
        float ix = x + i * s
        float iy = y
        land_color(1, 1, 1, 1)
        if i <= v:
            if v == 0:
                land_color(0, 0, 0, 1)
            land_filled_rectangle(ix, iy, ix + s * 0.8, iy + s)
        else:
            float cx = ix + s * 0.4
            float cy = iy + s * 0.5
            land_filled_circle(cx - 4, cy - 4, cx + 4, cy + 4)

static def volget(float mx) -> int:
    float w = land_display_width()
    double s = w / 960
    float sx = 48
    mx /= s
    int i = (mx - volx) / sx
    if i < 0: i = 0
    if i > 6: i = 6
    return i

def title_render:
    All *a = global_a
    float w = land_display_width()
    float h = land_display_height()
    double s = w / 960
    h /= s
    land_clear(1, 1, 1, 1)
    land_reset_transform()
    land_scale(s, s)

    land_font_set(a.big)
    float th = land_line_height()
    float yw = land_text_get_width("Yellow ")

    land_color(.9, .9, 0.7, 1)
    float tx = (960 - land_text_get_width("Yellow and Dangerous")) / 2
    land_filled_rectangle(tx + yw, 0, 960, h)

    for int i in range(5):
        float y = (h - 64 * 5) / 2 + i * 64 + (32 - th) / 2
        float x = tx
        land_text_pos(x + yw, y)
        land_color(0.5, 0, 0, 1)
        if i == 1:
            land_color(1, 0.9, 0, 1)
            land_text_pos(x, y)
            land_write("Yellow ")
            land_color(1, 1, 1, 1)
            if (land_get_ticks() / 60) % 14 >= 7:
                if land_get_ticks() % 8 >= 4:
                    land_color(1, 1, 0, 1)
            land_print("and Dangerous")
        if settings:
            if i == 0:
                if a.dpad == 0: land_print("DPad left")
                if a.dpad == 1: land_print("DPad right")
                if a.dpad == 2: land_print("DPad left big")
                if a.dpad == 3: land_print("DPad right big")
            elif i == 2:
                land_print("Music")
                drawvol(a.music, x + yw + 6 * 32, y)
            elif i == 3:
                land_print("Sound")
                drawvol(a.sound, x + yw + 6 * 32, y)
            elif i == 4:
                land_print("Back")
        elif restart:
            if i == 0:
                land_color(1, 0.75, 0.75, 1)
                land_print("Are you sure?")
            elif i == 3:
                land_print("Delete all saves")
            elif i == 4:
                land_print("Continue playing")
        else:
            if i == 0:
                land_print("Play")
            elif i == 2:
                land_print("Reset room")
            elif i == 3:
                land_print("New game")
            elif i == 4:
                land_print("Settings")

    land_font_set(a.font)
    
    if not block1:
        block1 = block_new(game->blocks, 120, 0, 720, Render_Gremlin)
    if not block2:
        block2 = block_new(game->blocks, -660, 0, -60, Render_Allefant)

    float speed = 60 * 7 / 2.0
    for int i in range(7):
        float ang = (land_get_ticks() + i * speed / 7) * 2 * pi / speed
        block1.y = 60 * fabs(sin(ang * 3.5))
        block1.x = 0 + cos(ang) * 120
        block1.z = 600 + sin(ang) * 120
        block1.frame = ((land_get_ticks() / 30 + i) % 4) * 4
        if ((land_get_ticks() / 60) % 14 >= 7) and i == 0:
            a.tint = land_color_hsv((land_get_ticks() * 4) % 360, .25, 1)
            a.tint.a = 0.5
            a.tint.r *= a.tint.a
            a.tint.g *= a.tint.a
            a.tint.b *= a.tint.a
        else:
            a.tint = land_color_premul(1, 1, 1, .2)
        render_block(block1, game->viewport)

    a.tint = land_color_premul(1, 1, 1, .2)

    block2.frame = 8 + ((16 * land_get_ticks() / 60) % 8)
    render_block(block2, game->viewport)

    a.tint.a = 0

    land_font_set(a.font)
    land_text_pos(w / s, h - land_line_height() * 2)
    int t = a.time / 60
    land_print_right("Playtime on this savegame: %02d:%02d:%02d",
        t / 3600, (t / 60) % 60, t % 60)
    land_print_right("Version 0.9")

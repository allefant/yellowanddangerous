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
    
def title_tick:
    float w = land_display_width()
    float h = land_display_height()
    double s = w / 960
    h /= s

    if land_key_pressed(LandKeyEnter):
        main_switch_to_game()

    for int ti in range(11):
        if land_touch_down(ti) and land_touch_delta(ti):
            int i = get_line(land_touch_y(ti))
            if settings:
                if i == 4:
                    settings = False
            elif restart:
                if i == 3:
                    # start new game
                    save_new()
                    game->level = game_starting_level
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
                    settings = True

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

    land_color(1, 1, 0.9, 1)
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
            land_color(1, 0.75, 0.75, 1)
            land_print("and Dangerous")
        if settings:
            if i == 2:
                land_print("Music")
            elif i == 3:
                land_print("Sound")
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
        block1 = block_new(game->blocks, 120, 0, 840, Render_Ginko)
    if not block2:
        block2 = block_new(game->blocks, -660, 0, 0, Render_Statue)
    render_block(block1, game->viewport)
    render_block(block2, game->viewport)

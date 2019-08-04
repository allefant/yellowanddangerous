import common
import main

class MenuScreenItem:
    str text
    LandArray *alternates
    int choice
    MenuScreen *target
    bool disabled

class MenuScreen:
    LandArray *items
    int selected
    str name
    MenuScreen *parent

str menu_text = """
Play
Reset Room
New Game
    -Are you sure?
    -
    Delete savegame!
    Continue Playing
Settings
    Controls
        Gamepad
        Left/Right
            -Configure H axis
            Left
            Right
            Done
        Up/Down
            -Configure V axis
            Up
            Down
            Done
        Jump/Pull
            -Configure buttons
            Jump/Pull
            Menu
            Done
        Back
    Audio
        -Volume
        Music
        Sound
        Back
    Video
        Fullscreen|Back to Windowed
        Back
    Back
"""

static MenuScreen *menu
static MenuScreen *menu_main
static Block *block1
static Block *block2
static int moment
static bool selected_blocking
static bool finding_input
static int finding_control
static int finding_progress

float ppx, ppy, ppw, pph;

def menu_screen_new -> MenuScreen*:
    MenuScreen *self; land_alloc(self)
    self.items = land_array_new()
    return self

def menu_screen_add(MenuScreen *self, str text) -> MenuScreenItem*:
    MenuScreenItem *item; land_alloc(item)
    if land_starts_with(text, "-"):
        item.disabled = True
        text++
    if land_contains(text, "|"):
        item.alternates = land_split(text, "|")
        text = land_array_get_nth(item.alternates, 0)
    if land_equals(text, "Controls"):
        if global_use_touch_input:
            text = "Touch"
        
    item.text = text
    land_array_add(self.items, item)
    return item

def menu_is(str x) -> bool:
    return land_equals(menu.name, x)

def menu_item_get -> MenuScreenItem*:
    if menu.selected >= land_array_count(menu.items): return None
    return land_array_get_nth(menu.items, menu.selected)

def menu_item_is(str x) -> bool:
    MenuScreenItem *item = menu_item_get()
    if not item:
        return False
    return land_equals(item.text, x)

def menu_screen_back:
    if menu_is("New Game"):
        main_switch_to_game()
    elif menu_is("Controls"):
        menu_goto("Settings")
    elif menu_is("Main"):
        main_switch_to_game()
    else:
        menu_goto("Main")
        save_info()

def menu_goto(str x):
    if land_equals(x, "Main"):
        menu = menu_main
        return
    for MenuScreenItem *item in LandArray *menu_main.items:
        if land_equals(item.text, x):
            menu = item.target
            return
    for MenuScreenItem *item in LandArray *menu.items:
        if land_equals(item.text, x):
            menu = item.target
            return
    print("Cannot goto menu %s", x)

def menu_goup:
    menu = menu.parent

def menu_select_next(int d):
    int n = land_array_count(menu.items)
    for int i in range(n):
        menu.selected += d
        if menu.selected == -1: menu.selected += n
        if menu.selected == n: menu.selected = 0
        MenuScreenItem *msi = land_array_get_nth(menu.items, menu.selected)
        if msi.disabled: continue
        break

def menu_sideways(int d):
    if menu_is("Audio"):
        if menu_item_is("Music"):
            music_volume(global_a.music + d)
        if menu_item_is("Sound"):
            sound_volume(global_a.sound + d)

def menu_select_position(int p):
    menu.selected = p

def _find_control(int c):
    finding_input = True
    finding_control = c
    finding_progress = 0

def menu_click(float x):
    All *a = global_a

    MenuScreenItem *item = menu_item_get()
    if item:
        if item.target:
            if menu_is("Controls"):
                menu = item.target
                menu_select_position(1)
                menu_click(0)
                return
                
            if menu_is("Main"):
                if menu_item_is("New Game"):
                    a.code = 0
                    a.godmode = False
            menu = item.target
            return
    if menu_is("Left/Right"):
        if menu_item_is("Left"): _find_control(ControlLeft)
        if menu_item_is("Right"): _find_control(ControlRight)
        if menu_item_is("Done"): menu_goup()
    elif menu_is("Up/Down"):
        if menu_item_is("Up"): _find_control(ControlUp)
        if menu_item_is("Down"): _find_control(ControlDown)
        if menu_item_is("Done"): menu_goup()
    elif menu_is("Jump/Pull"):
        if menu_item_is("Jump/Pull"): _find_control(ControlJump)
        if menu_item_is("Menu"): _find_control(ControlMenu)
        if menu_item_is("Done"): menu_goup()
    elif menu_is("Settings"):
        if menu_item_is("Touch"):
            a.dpad++
            if a.dpad == 6:
                a.dpad = 0
    elif menu_is("Audio"):
        if menu_item_is("Music"):
            music_volume(volget(x))
        elif menu_item_is("Sound"):
            sound_volume(volget(x))
    elif menu_is("Video"):
        if menu_item_is("Fullscreen"):
            land_display_toggle_fullscreen()
            a.fullscreen = (land_display_flags() & LAND_FULLSCREEN) != 0
            item.choice = a.fullscreen ? 1 : 0
    elif menu_is("New Game"):
        if menu_item_is("Delete savegame!"):
            # start new game
            save_new()
            main_switch_to_game()
        elif menu_item_is("Continue Playing"):
            main_switch_to_game()
    elif menu_is("Controls"):
        pass
    elif menu_is("Main"):
        if menu_item_is("Play"):
            if global_can_enable_editor and volget(x) > 0:
                a.editor_enabled = True
                a.editor = True
            else:
                a.editor_enabled = False
                
            # load saved game
            main_switch_to_game()
        elif menu_item_is("Reset Room"):
            # reset the current room
            save_reset_room(game->level)
            main_switch_to_game()
            if game->player:
                player_find_entrance(&game->player->super)

    if menu_item_is("Back"):
        menu_screen_back()

def _indentation(str x) -> int:
    int i = 0
    while x[i] == ' ':
        i++
    return i

def title_init:
    MenuScreen* menus[100]
    menus[0] = menu_main = menu_screen_new()
    menu_main.name = "Main"
    LandArray *rows = land_split_lines(menu_text)
    int prev_nested = 0
    MenuScreenItem *prev_item = None
    MenuScreen *prev_menu = None
    for str row_raw in rows:
        int nested = _indentation(row_raw)
        if nested > prev_nested:
            menus[nested] = menu_screen_new()
            menus[nested]->name = prev_item.text
            if not land_equals(prev_item.text, "Touch"):
                prev_item.target = menus[nested]
            menus[nested]->parent = prev_menu
        prev_nested = nested
        prev_menu = menus[nested]
        char *row = land_strdup(row_raw)
        land_strip(&row)
        if not row[0]: continue
        prev_item = menu_screen_add(menus[nested], row)
            
    land_array_destroy_with_strings(rows)

    menu = menu_main

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

# 0 = main, 1 = settings
def title_com(int com):
    if com == 1:
        menu_goto("Settings")
    else:
        menu_goto("Main")

def title_tick:
    float w = land_display_width()
    float h = land_display_height()
    double s = w / 960
    h /= s

    All *a = global_a

    if finding_input:
        int status = config_joystick_control(finding_control, finding_progress)
        if status == FoundButton:
            finding_input = False
        if status == FoundAxis:
            finding_progress++
        if status == FoundNothing: # wait until they stop using the input
            if finding_progress >= 10:
                finding_input = False
        if not finding_input:
            menu_select_next(1)
            menu_click(0) # either next control or done
        return

    if land_key_pressed(LandKeyBack) or controls.pressed[ControlMenu]:
        menu_screen_back()

    if selected_blocking:
        if not a.up and not a.down and not a.left and not a.right:
            selected_blocking = False
    elif a.up or a.down:
        menu_select_next(a.up ? -1 : 1)
        selected_blocking = True
    elif a.left or a.right:
        menu_sideways(a.left ? -1 : 1)
        selected_blocking = True

    for int ti in range(12):
        bool click = False
        int i = 0
        int i2 = 0
        float x = 0
        if ti < 11:
            if land_touch_down(ti) and land_touch_delta(ti):
                click = True
            i2 = get_line(land_touch_y(ti))
            i = i2
            if i > 0: i--
            x = land_touch_x(ti)
            
            if click:
                float y = land_touch_y(ti)
                land_log_message("%f %f %f %f %f %f", x, y, ppx, ppy, ppw, pph)
                if x > ppx and x < ppx + ppw and y > ppy and y < ppy + pph:
                    open_link("http://yellowdanger.com/privacy_policy.html")
                    return
        else:
            if controls.pressed[ControlJump]:
                i = menu.selected
                click = True
            
        if click:
            if i2 == 1:
                if menu_is("New Game"):
                    a.code++
                    if a.code == 7:
                        sound(Render_glass, 1)
                        a.godmode = True
            else:
                menu_select_position(i)
                menu_click(x)


static int volx = 0
static def drawvol(int v, float x, y):
    LandColor c = land_color_get()
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
    land_color_set(c)

def menu_screen_draw:
    All *a = global_a
    float w = land_display_width()
    float h = land_display_height()
    double s = w / 960
    h /= s
    land_font_set(a.big)
    float th = land_line_height()
    float yw = land_text_get_width("Yellow ")
    land_color(.9, .9, 0.7, 1)
    float tx = (960 - land_text_get_width("Yellow and Dangerous")) / 2
    
    int it = 0
    for MenuScreenItem *item in LandArray *menu.items:
        int it2 = it
        if it2 > 0:
            it2++
        float y = (h - 64 * 5) / 2 + it2 * 64 + (32 - th) / 2
        float x = tx
        bool draw = True
        land_text_pos(x + yw, y)
        land_color(0.5, 0, 0, 1)
        if it == menu.selected:
            land_color(0.9, 0.1, 0, 1)
            if finding_input:
                if (land_get_ticks() / 5) % 2 == 0:
                    land_color(1, 1, 1, 1)
        else:
            land_color(0.5, 0, 0, 1)

        if menu_is("Settings"):
            if it == 0:
                if global_use_touch_input:
                    if a.dpad == 0: land_print("DPad left")
                    if a.dpad == 1: land_print("DPad right")
                    if a.dpad == 2: land_print("DPad left big")
                    if a.dpad == 3: land_print("DPad right big")
                    if a.dpad == 4: land_print("double click swipe")
                    if a.dpad == 5: land_print("two finger swipe")
                    draw = False
        elif menu_is("Audio"):
            if it == 1:
                drawvol(a.music, volx, y)
            elif it == 2:
                drawvol(a.sound, volx, y)
        elif menu_is("New Game"):
            if it == 0:
                land_color(1, 0.75, 0.75, 1)
            elif it == 2:
                if it == menu.selected:
                    land_color(1, 0.4, 0.4, 1)
            elif it == 3:
                if it == menu.selected:
                    land_color(0, 0.5, 0, 1)

        if draw:
            if item.alternates:
                land_print(land_array_get_nth(item.alternates,
                    item.choice))
            else:
                land_print(item.text)

        if menu_is("Main"):
            if it == 0:
                if global_can_enable_editor:
                    land_text_pos(volx + 48, y)
                    land_print("Edit")

        int control = ControlNone
        if menu_is("Left/Right"):
            if it == 1: control = ControlLeft
            if it == 2: control = ControlRight
        if menu_is("Up/Down"):
            if it == 1: control = ControlUp
            if it == 2: control = ControlDown
        if menu_is("Jump/Pull"):
            if it == 1: control = ControlJump
            if it == 2: control = ControlMenu
        if menu_is("Controls"):
            if it == 1: control = ControlLeft
            if it == 2: control = ControlUp
            if it == 3: control = ControlJump
                
        if control:
            land_font_set(a.medium)
            land_text_pos(volx + 68, y)
            land_color(0, 0, 0, 0.33)
            land_print(control_name(control))
            land_font_set(a.big)
            
        it++

static def volget(float mx) -> int:
    float w = land_display_width()
    double s = w / 960
    float sx = 48
    mx /= s
    int i = (mx - volx) / sx
    return i

static def music_volume(int i):
    if i < 0: i = 0
    if i > 6: i = 6
    global_a.music = i
    song_volume()

static def sound_volume(int i):
    if i < 0: i = 0
    if i > 6: i = 6
    global_a.sound = i
    sound(Render_on, 1)

def align(float x, float s) -> float:
    return floor(x * s) / s

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

    if menu_is("Settings"):
        land_font_set(a.medium)
        land_color(0.5, 0, 0, 1)
        float nh = land_line_height()
        float y = (h - 64 * 5) / 2 + (32 - th) / 2
        float x = tx
        land_text_pos(x + yw, y - nh * 2)
        if global_use_touch_input:
            if a.dpad == 5:
                land_print("Jump: touch second finger")
                land_print("Pull/Lift: two finger swipe")
            elif a.dpad == 4:
                land_print("Jump: Move then double tap")
                land_print("Pull/Lift: Double tap then move")
            else:
                land_print("Jump: Hold move then jump")
                land_print("Pull/Lift: Hold jump then move")
        else:
            land_print("Jump: Press button while moving")
            land_print("Pull/Lift: Press button first then move")
        land_font_set(a.big)

    volx = tx + yw + 6 * 32

    if True:
        int i = 1
        float y = (h - 64 * 5) / 2 + i * 64 + (32 - th) / 2
        float x = tx
        land_color(1, 0.9, 0, 1)
        land_text_pos(x, y)
        land_write("Yellow ")
        land_color(1, 1, 1, 1)
        if (land_get_ticks() / 60) % 14 >= 7:
            if land_get_ticks() % 8 >= 4:
                land_color(1, 1, 0, 1)
        land_print("and Dangerous")

    menu_screen_draw()

    land_font_set(a.font)
    land_color(0, 0, 0, 1)
    
    if not block1:
        block1 = block_new(game->blocks, 120, 0, 720, Render_Gremlin)
    if not block2:
        block2 = block_new(game->blocks, -660, 0, -60, Render_Allefant)

    moment++
    if moment > 4:
        # wait a moment so Android gets a moment to recover and
        # won't crash :P
        draw_title_animation()

    a.tint.a = 0

    land_font_set(a.font)
    land_text_pos(w / s, h - land_line_height() * 6)
    int t = a.time / 60
    int f = 0
    for int i in range(8):
        if game->flower[i]:
            f++
    int tt = 0
    for int i in range(8):
        if game->test_tube[i]:
            tt++
    land_print_right("Flowers picked: %d/7", f)
    land_print_right("Test tubes: %d/7", tt)
    land_print_right("Car keys found: %s", game->key ? "yes" : "no")
    land_print_right("Died %d time%s.", game->deaths, game->deaths != 1 ? "s" : "")
    land_print_right("Playtime on this savegame: %02d:%02d:%02d",
        t / 3600, (t / 60) % 60, t % 60)
    land_print_right("Version %s", VERSION)

    land_font_set(a.medium)
    land_color(.3, 0.3, 1, 1)
    land_text_pos(4, h - 4 - land_line_height())
    land_print("Privacy Policy")
    ppx = land_text_x() * s
    ppy = land_text_y() * s
    ppw = land_text_width() * s
    pph = land_text_height() * s

static def draw_title_animation:
    All *a = global_a
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
        if not blocktype_preload(block1.block_type):
            render_block(block1, game->viewport)

    a.tint = land_color_premul(1, 1, 1, .2)

    block2.frame = 8 + ((16 * land_get_ticks() / 60) % 8)
    if not blocktype_preload(block2.block_type):
        render_block(block2, game->viewport)

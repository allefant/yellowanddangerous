import main
type Game *game

class Menu:
    int menu
    char items[16][16][32]
    int n[16]
    int hilite

    int pos

macro S(text):
    strcpy(menu->items[menu->pos][menu->n[menu->pos]++], text)

macro T(text):
    menu->pos++
    menu->n[menu->pos] = 0
    S(text)

def menu_new -> Menu*:
    Menu *menu
    land_alloc(menu)

    S("Mode")
    S("File")
    S("View")
    S("Level")
    S("Object")

    T("Title")
    S("Edit")
    S("Play")

    T("Save")
    S("Load")
    S("Clear")

    T("Bounds")
    S("Mask")
    S("Info")

    T("Overview")
    S("Intro")
    S("Move")
    S("Title")
    S("Hint")

    T("Move")
    S("Delete")
    S("Frame")
    S("Type")
    S("Align")
    S("Insert")

    return menu

def menu_toggle:
    if game.menu_on:
        game.menu_on = False
    else:
        game.menu_on = True
        Menu *menu = game.menu
        menu.hilite = -1
        menu.menu = 0

def menu_draw(Menu *menu):
    All *a = global_a
    float w = land_display_width()

    land_push_transform()
    land_scale(w / 960.0, w / 960.0)

    float mw = 120
    float mih = 30
    float border = 40
    
    float x0 = 960 - mw - border
    float y0 = 160
    land_font_set(a.medium)
    int n = menu.n[menu.menu]
    land_premul(1, 1, 1, 0.8)
    land_filled_rectangle(x0 - border, y0 - border,
        x0 + mw + border, y0 + n * mih + border)
    land_color(1, 1, 0, 1)
    land_thickness(8)
    land_rectangle(x0 - border, y0 - border,
        x0 + mw + border, y0 + n * mih + border)
    land_thickness(1)
    for int i in range(n):
        char *text = menu.items[menu.menu][i]
        float x = x0
        float y = y0 + i * mih
        if menu.hilite == i:
            land_color(1, 1, 0.5, 1)
            land_filled_rectangle(x, y, x + mw, y + mih)
        land_text_pos(x, y)
        land_color(0, 0, 0, 1)
        land_print("%s", text)
    land_pop_transform()

def menu_key(int k):
    All *a = global_a

    if k == LandKeyFunction + 2:
        if game.pristine:
            save_level(True)
    elif k == LandKeyFunction + 3:
        load_level(True)
        a.overview = False
        viewport_update(game.viewport)
        a.running = False
    elif k == LandKeyFunction + 4:
        blocks_reset(game.blocks)
        game.player = None
        game.player2 = None
    elif k == LandKeyFunction + 5:
        debug_no_mask = not debug_no_mask
    elif k == LandKeyFunction + 6:
        debug_bounding_boxes++
        debug_bounding_boxes %= 2
    elif k == LandKeyFunction + 7:
        a.editor = not a.editor
    elif k == LandKeyFunction + 8:
        if a.overview:
            overview_destroy(game.overview)
            game.overview = None
            a.overview = False
        else:
            game.overview = overview_new()
            a.overview = True
            a.running = False
    elif k == LandKeyFunction + 10:
        game.sequence = not game.sequence
    elif k == ' ':
        pass
    elif k == LandKeyEnter:
        if not a.running:
            a.running = True
    elif k == 'q' or k == 'e' or k == 'w' or k == 's':
        if k == 'q' or k == 'e' or not game.picked:
            int gox = 0, goz = 0
            if k == 'q': gox--
            if k == 'e': gox++
            if k == 'w': goz--
            if k == 's': goz++
            game.level = game_neighboring_level(game.level, gox, goz)
            load_level(True)
            a.running = False
    elif k == 'i':
        Block *p = game.picked
        if p:
            print("%.1f %.1f %.1f", p.x, p.y, p.z)
    elif k == 't':
        a.text_input = 1
        a.cursor = 0
    elif k == 'h':
        a.text_input = 2
        a.cursor = 0

    double s = 24
    double s2 = s * 2

    if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
        s2 = s

    if k == LandKeyInsert:
        Block *l = game.picked
        if l:
            game.picked = block_new(game.blocks, l.x, l.y, l.z,
                l.block_type)
        else:
            game.picked = block_new(game.blocks, -s, -s * 2, -s,
                Render_BlockBottom3)
        block_add(game.picked)

    Block *p = game.picked
    
    if not p:
        return

    if k == LandKeyLeft:
        p.x -= s2
        game_recalc()
    elif k == LandKeyRight:
        p.x += s2
        game_recalc()
    elif k == LandKeyUp:
        p.z -= s2
        game_recalc()
    elif k == LandKeyDown:
        p.z += s2
        game_recalc()
    elif k == 'w':
        p.y += s2
        game_recalc()
    elif k == 's':
        p.y -= s2
        game_recalc()
    elif k == 'x':
        if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
            p.y += p.ys
        else:
            p.y -= p.ys
    elif k == 'c':
        if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
            p.x = floor(p.x / s) * s
            p.y = floor(p.y / s) * s
            p.z = floor(p.z / s) * s
            p.x += (s - p.xs) / 2
            p.z += (s - p.zs) / 2
        else:
            p.x = floor(p.x / s + 0.1) * s
            p.y = floor(p.y / s + 0.1) * s
            p.z = floor(p.z / s + 0.1) * s
    elif k == 'a':
        game.picked = p = block_change_type(p, -1)
    elif k == 'd':
        game.picked = p = block_change_type(p, 1)
    elif k == 'f':
        p.frame++
        if p.frame >= land_array_count(p.block_type->bitmaps):
            p.frame = 0
    elif k == LandKeyDelete:
        block_del(p)
        game.picked = None

macro ON(x, k):
    if land_equals(text, x):
        menu_key(k)

def menu_tick(Menu *menu, float mx, my, click) -> bool:
    All *a = global_a
    float w = land_display_width()

    float mw = 120 * w / 960
    float mih = 30 * w / 960
    float border = 40 * w / 960
    float x0 = w - mw - border
    float y0 = 160 * w / 960
    int n = menu.n[menu.menu]

    menu.hilite = -1

    if mx < x0 - border:
        return False
    if mx > x0 + mw + border:
        return False
    if my < y0 - border:
        return False
    if my > y0 + n * mih + border:
        return False

    if mx < x0 or mx > x0 + mw:
        return True
    int i = floor((my - y0) / mih)
    if i < 0 or i >= n:
        return True
    char *text = menu.items[menu.menu][i]

    if click:
        if menu.menu > 0:
            game.menu_on = False
            menu.menu = 0
        
        if land_equals(text, "Mode"): menu.menu = 1
        if land_equals(text, "File"): menu.menu = 2
        if land_equals(text, "View"): menu.menu = 3
        if land_equals(text, "Level"): menu.menu = 4
        if land_equals(text, "Object"): menu.menu = 5

        if land_equals(text, "Title"):
           main_switch_to_title(0)

        if land_equals(text, "Play"):
            a.editor = False

        if land_equals(text, "Edit"):
            a.editor = True

        ON("Save", LandKeyFunction + 2)
        ON("Load", LandKeyFunction + 3)
        ON("Clear", LandKeyFunction + 4)

        ON("Bounds", LandKeyFunction + 6)
        ON("Mask", LandKeyFunction + 5)
        ON("Info", 'i')

        ON("Overview", LandKeyFunction + 8)
        ON("Intro", LandKeyFunction + 10)
        ON("Title", 't')
        ON("Hint", 'h')
      
        if land_equals(text, "Move"):
            if menu.menu == 4: # Level
                pass
            if menu.menu == 5: # Object
                pass
        ON("Delete", LandKeyDelete)
        ON("Frame", 'f')
        ON("Type", 'a')
        ON("Align", 'c')
        ON("Insert", LandKeyInsert)

    else:
        menu.hilite = i

    return True
    

    

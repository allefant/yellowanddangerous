import main
type Game *game
type Editor *editor

class Menu:
    int menu[3]
    char items[16][128][32]
    int n[16]
    int hilite[3]

    int pos
    int sub_frame

macro S(text):
    strcpy(menu->items[menu->pos][menu->n[menu->pos]++], text)
macro T:
    menu->pos++
    menu->n[menu->pos] = 0

def menu_new -> Menu*:
    Menu *menu
    land_alloc(menu)

    return menu

static macro categories_count 8

static def category(BlockType *bt) -> int:
    if land_starts_with(bt.name, "BlockBottom") or\
        land_starts_with(bt.name, "BlockSmall") or\
        land_starts_with(bt.name, "Ramp"):
        return 0
    if land_starts_with(bt.name, "Block") or\
        land_starts_with(bt.name, "Invisible") or\
        land_starts_with(bt.name, "Window"):
        return 1
    if block_type_flower(bt) or bt == Render_Key:
        return 2
    if bt == Render_Allefant or bt == Render_Gremlin or bt == Render_Scientist:
        return 3
    if land_starts_with(bt.name, "Lever") or\
        land_starts_with(bt.name, "Vent") or\
        land_starts_with(bt.name, "Plate") or\
        land_starts_with(bt.name, "Platform") or\
        land_starts_with(bt.name, "Waypoint") or\
        land_starts_with(bt.name, "Exit") or\
        land_starts_with(bt.name, "Conveyor"):
        return 4
    if bt.dynamic:
        return 5
    if land_starts_with(bt.name, "Tree") or\
            land_ends_with(bt.name, "Tree") or\
            bt == Render_Ginko or\
            bt == Render_Trunk:
        return 6
    return 7

static def category_name(int c) -> char const *:
    if c == 0: return "Floor"
    if c == 1: return "Wall"
    if c == 2: return "Item"
    if c == 3: return "Monster"
    if c == 4: return "Device"
    if c == 5: return "Moving"
    if c == 6: return "Plant"
    if c == 7: return "Decoration"
    return ""

static def menu_items(Menu *menu):
    All *a = global_a

    menu.pos = 0
    menu.n[0] = 0

    S("Mode")
    S("File")
    S("View")
    S("Level")
    S("Object")
    T
    S(a.editor ? "Play" : "Edit")
    S("Record")
    S("Replay")
    S("Godmode")
    S("Exit")
    T
    S("Save")
    S("Load")
    S("Clear")
    T
    S("Bounds")
    S("Mask")
    S("Info")
    T
    S("Overview")
    S("Intro")
    S("Title")
    S("Hint")
    S("Shift X+")
    S("Shift X-")
    S("Shift Y+")
    S("Shift Y-")
    S("Shift Z+")
    S("Shift Z-")
    T
    S("Insert")
    S("Type")
    S("Frame")
    S("Align")
    S("Delete")
    T
    for int i in range(categories_count):
        S(category_name(i))
    for int i in range(categories_count):
        T
        for BlockType *bt in LandArray *block_types:
            if category(bt) == i:
                S(bt.name)

    T
    S("0")
    S("1")
    menu.sub_frame = menu.pos

def menu_toggle:
    if game.menu_on:
        game.menu_on = False
    else:
        game.menu_on = True
        Menu *menu = game.menu
        menu_items(menu)
        menu.hilite[0] = -1
        menu.menu[0] = 0
        menu.menu[1] = -1
        menu.menu[2] = -1

def menu_draw(Menu *menu):
    All *a = global_a
    float w = land_display_width()

    land_push_transform()
    land_scale(w / 960.0, w / 960.0)

    float mw = 120
    float mih = 30
    float border = 40

    for int mi in range(3):
        int m = menu.menu[mi]
        if m == -1:
            break
        float x0 = 960 - (mw + border) * (1 + mi)
        float y0 = 160
        land_font_set(a.medium)
        int n = menu.n[m]
        land_premul(1, 1, 1, 0.8)
        land_filled_rectangle(x0 - border, y0 - border,
            x0 + mw + border, y0 + n * mih + border)
        land_color(1, 1, 0, 1)
        int t = 4
        land_thickness(t * 2)
        land_rectangle(x0 - border + t, y0 - border + t,
            x0 + mw + border - t, y0 + n * mih + border - t)
        land_thickness(1)
        for int i in range(n):
            char *text = menu.items[m][i]
            float x = x0
            float y = y0 + i * mih
            if menu.hilite[mi] == i:
                land_color(1, 1, 0.5, 1)
                land_filled_rectangle(x, y, x + mw, y + mih)
            land_text_pos(x, y)
            land_color(0, 0, 0, 1)
            land_print("%s", text)
    land_pop_transform()

def menu_key(int k, bool shift):
    All *a = global_a

    if k == LandKeyFunction + 2:
        if game.pristine:
            save_level(True, False)
    elif k == LandKeyFunction + 3:
        load_level(True, False)
        a.overview = False
        viewport_update(game.viewport, land_display_width(),
            land_display_height())
        a.editor = True
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
            a.overview = False
            game.level = game.overview->selected
            menu_key(LandKeyFunction + 3, False)
        else:
            overview_update(game.overview)
    elif k == LandKeyFunction + 10:
        game.sequence = not game.sequence
    elif k == ' ':
        pass
    elif k == LandKeyEnter:
        a.editor = not a.editor
    elif k == 'q' or k == 'e' or k == 'w' or k == 's':
        if k == 'q' or k == 'e' or not editor.picked:
            int gox = 0, goz = 0
            if k == 'q': gox--
            if k == 'e': gox++
            if k == 'w': goz--
            if k == 's': goz++
            game.level = game_neighboring_level(game.level, gox, goz)
            load_level(True, False)
            a.editor = True
    elif k == 'i':
        Block *p = editor.picked
        if p:
            print("F%d X%.1f Y%.1f Z%.1f %2d/%2d/%2d", p.frame,
                p.x, p.y, p.z,
                p.x // 24 + 22, p.y // 24 + 4, p.z // 24 + 22)
    elif k == 't':
        a.text_input = 1
        a.cursor = 0
    elif k == 'h':
        a.text_input = 2
        a.cursor = 0
    elif k == 'r':
        if shift:
            record_set_replaying(game.record)
        else:
            record_set_recording(game.record)
    elif k == 'g':
        a.godmode = not a.godmode

    if not editor.picked:
        if k == 'x':
            blocks_shift(game.blocks, shift ? 24 : -24, 0, 0)
        elif k == 'y':
            blocks_shift(game.blocks, 0, shift ? 24 : -24, 0)
        elif k == 'z':
            blocks_shift(game.blocks, 0, 0, shift ? 24 : -24)

    double s = 24
    double s2 = s * 2

    if shift:
        s2 = s

    if k == LandKeyInsert:
        Block *l = editor.picked
        if l:
            editor.picked = block_new(game.blocks, l.x, l.y, l.z,
                l.block_type)
        else:
            editor.picked = block_new(game.blocks, -s, -s * 2, -s,
                Render_BlockBottom3)
        block_add(editor.picked)

    Block *p = editor.picked
    
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
        if shift:
            p.y += p.ys
        else:
            p.y -= p.ys
    elif k == 'c':
        if shift:
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
        editor.picked = p = block_change_type(p, -1)
    elif k == 'd':
        editor.picked = p = block_change_type(p, 1)
    elif k == 'f':
        p.frame++
        if p.frame >= land_array_count(p.block_type->bitmaps):
            p.frame = 0
    elif k == LandKeyDelete:
        block_del(p)
        editor.picked = None

macro ON(x, k):
    if land_equals(text, x):
        menu_key(k, False)

macro ON_SHIFT(x, k):
    if land_equals(text, x):
        menu_key(k, True)

def menu_tick(Menu *menu, float mx, my, click) -> bool:
    All *a = global_a
    float w = land_display_width()

    float mw = 120 * w / 960
    float mih = 30 * w / 960
    float border = 40 * w / 960

    bool out = True
    char *text = None

    int selected = -1
    int mi
    for mi in range(3):
        float x0 = w - (mw + border) * (1 + mi)
        float y0 = 160 * w / 960

        if menu.menu[mi] == -1:
            break
        
        int n = menu.n[menu.menu[mi]]

        menu.hilite[mi] = -1

        if mx < x0 - border:
            continue
        if mx > x0 + mw + border:
            continue
        if my < y0 - border:
            continue
        if my > y0 + n * mih + border:
            continue

        out = False

        if mx < x0 or mx > x0 + mw:
            continue
        selected = floor((my - y0) / mih)
        if selected < 0 or selected >= n:
            continue

        text = menu.items[menu.menu[mi]][selected]
        break

    if out:
        return False

    if not text:
        return True

    if click:
        if menu.menu[mi] > 0:
            game.menu_on = False
            menu.menu[0] = 0
            menu.menu[1] = -1
        
        if land_equals(text, "Mode"): menu.menu[mi] = 1
        if land_equals(text, "File"): menu.menu[mi] = 2
        if land_equals(text, "View"): menu.menu[mi] = 3
        if land_equals(text, "Level"): menu.menu[mi] = 4
        if land_equals(text, "Object"): menu.menu[mi] = 5

        if land_equals(text, "Exit"):
           a.editor = False
           main_switch_to_title(0)

        if land_equals(text, "Play"):
            a.editor = False

        if land_equals(text, "Edit"):
            a.editor = True
        ON("Record", 'r')
        ON_SHIFT("Replay", 'r')
        ON("Godmode", 'g')

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
        ON_SHIFT("Shift X+", 'x')
        ON("Shift X-", 'x')
        ON_SHIFT("Shift Y+", 'y')
        ON("Shift Y-", 'y')
        ON_SHIFT("Shift Z+", 'z')
        ON("Shift Z-", 'z')
      
        ON("Delete", LandKeyDelete)

        if land_equals(text, "Frame"):
            menu.menu[0] = menu.sub_frame
            menu.menu[1] = -1
            game.menu_on = True

            Block *p = editor.picked
            if p:
                int n = land_array_count(p.block_type->bitmaps)
                if n > 10:
                    n = 10
                for int i in range(n):
                    sprintf(menu.items[menu.sub_frame][i], "Frame %d",
                        1 + i)
                menu.n[menu.sub_frame] = n

        if land_equals(text, "Type"):
            menu.menu[mi] = 6
            game.menu_on = True
        ON("Align", 'c')
        ON("Insert", LandKeyInsert)

        if land_starts_with(text, "Frame "):
            Block *p = editor.picked
            if p:
                p.frame = selected
                if p.frame >= land_array_count(p.block_type->bitmaps):
                    p.frame = 0

        for int c in range(categories_count):
            if land_equals(text, category_name(c)):
                menu.menu[0] = 6
                menu.menu[1] = 7 + c
                game.menu_on = True

    else:
        if mi == 1:
            if editor.picked:
                editor.picked  = block_change_type_to(editor.picked,
                    text)
                
        menu.hilite[mi] = selected

    return True
    

    

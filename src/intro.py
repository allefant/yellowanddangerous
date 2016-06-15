import game

global LandColor intro_tint
global LandColor intro_back
static Block *test_tube
static int ty
static int scrolly

static def find_test_tube:
    if test_tube:
        return
    for Block *b in LandArray *game->blocks->dynamic:
        if b.block_type == Render_TestTube:
            if b.frame == 5:
                if b.x < 0 and b.y > 0:
                    test_tube = b
                    return

static macro SN 100
static macro STARN 500
static class Smoke:
    bool active
    float x, y, z
    float sx, sy
    float dx, dy, dz
    float ax, ay, az
    float r, g, b, a
    bool two
static Smoke smokes[STARN]
static bool smoke

static def walls_down(bool final):
    for Block *b in LandArray *game->blocks->fixed:
        if b.block_type == Render_WallLeft or b.block_type == Render_WallRight:
           b.y -= land_rand(8, 12)
           if final:
               b.y = -9000
           game->blocks->rebuild_static_cache = True

static def move_car:
    for Block *b in LandArray *game->blocks->fixed:
        if b.block_type == Render_Car:
           b.dz += 0.1
           b.z += b.dz
           b.frame = 1
           game->blocks->rebuild_static_cache = True

def intro_sequence:
    if game->sequence == 1:
        intro()
    if game->sequence == 2:
        extro()

static def extro:
    Game *g = game
    int t = g.sequence_ticks++
    set_back_color(0, 0, 0)
    game->player->super.y = 9000
    if t < 60 * 5:
        move_car()
        set_tint_color(1, 1, 1)
        smokes[0].active = False
    else:
        fade_tint_color(0, 0, 0)
        scrolly++

        if not smokes[0].active:
            for int i in range(STARN):
                Smoke *s = smokes + i
                s.active = True
                s.x = land_rnd(-480, 480)
                s.y = land_rnd(-480, 480)
                s.z = land_rnd(-480, 480)
                s.two = land_rnd(0, 100) < 2
        else:
            for int i in range(STARN):
                Smoke *s = smokes + i
                s.z += 1
                if s.z > 480:
                    s.z -= 960

static macro set__color(X, r, g, b):
    LandColor *c = &intro_******X
    c.r = r
    c.g = g
    c.b = b
    c.a = 1

static macro fade__color(X, r, g, b, p):
    double q = 1 - p
    LandColor *c = &intro_******X
    c.r *= p
    c.r += q * r
    c.g *= p
    c.g += q * g
    c.b *= p
    c.b += q * b
    c.a = 1

static def set_back_color(float r, g, b):
    set__color(back, r, g, b)

static def fade_back_color(float r, g, b):
    fade__color(back, r, g, b, 0.95)

static def set_tint_color(float r, g, b):
    set__color(tint, r, g, b)

static def fade_tint_color(float r, g, b):
    fade__color(tint, r, g, b, 0.99)

static def intro:
    All *a = global_a
    Game *g = game

    a.right = 0
    a.left = 0
    a.down = 0
    a.up = 0
    a.jump = 0
    int t = g.sequence_ticks++
    if t == 1:
        smoke = False
        set_back_color(0, 0, 0)
        set_tint_color(1, 1, 1)
        test_tube = None
        find_test_tube()
        if not test_tube:
            g.sequence = 0
            return
    int w = 60 * 2.5
    if t < w:
        a.left = 1
        a.up = 1
        fade_tint_color(.8, .8, .8)
    elif t < w + 60 * 0.5:
        a.jump = 1
        ty = test_tube.y
    elif t < w + 60 * 1:
        a.jump = 1
        a.right = 1
        a.down = 1
        test_tube.x = g.player->super.x - 72
        test_tube.z = g.player->super.z
        test_tube.y = ty
    elif t < w + 60 * 5:
        if test_tube.y < -8000:
            if not smoke:
                setup_smoke()
        if t > w + 60 * 4:
            fade_tint_color(1, 0.8, 0.1)
    elif t < w + 60 * 6:
        fade_tint_color(1, 1, 1)
        walls_down(False)
    elif t < w + 60 * 7:
        fade_tint_color(1, 1, 1)
        fade_back_color(1, 1, 1)
        walls_down(False)
    else:
        walls_down(True)
        strcpy(g.title, "What happened to the walls?")
        g.sequence = 0

def intro_postprocess:
    if game->sequence == 1:
        postprocess1()
    if game->sequence == 2:
        postprocess2()

static def setup_smoke:
    if smoke:
        return
    smoke = True
    for int i in range(SN):
        Smoke *s = smokes + i
        s.active = True
        s.x = game->player->super.x - 72
        s.z = game->player->super.z
        s.y = 0
        s.sx = 0.1
        s.sy = 0.1
        float r = land_rnd(0, 2 * pi)
        s.ax = cos(r) * 0.015
        s.az = sin(r) * 0.015
        s.ay = -0.2
        s.dx = s.ax * land_rnd(-60, 60)
        s.dy = land_rnd(1, 5)
        s.dz = s.az * land_rnd(-60, 60)
        s.a = 0.3
        s.r = land_rnd(0.8, 1)
        s.g = land_rnd(0.5, 1)
        s.b = land_rnd(0, 0.4)

static def postprocess1:
    if smoke:
        for int i in range(SN):
            Smoke *s = smokes + i
            float a = s.a
            float r = s.r * a
            float g = s.g * a
            float b = s.b * a
            float sx, sy
            project(game->viewport, s.x, s.y, s.z, &sx, &sy)
            land_image_draw_scaled_tinted(Render_Smoke, sx, sy,
                s.sx, s.sy,
                r, g, b, a)
            s.x += s.dx
            s.y += s.dy
            if s.y < 0:
                s.y = 0
                s.dy = -s.dy
            s.z += s.dz
            s.sx += 0.01
            s.sy += 0.01
            s.dx += s.ax
            s.dy += s.ay
            s.dz += s.az
            s.a *= 0.99

static char const credits[] = """
Yellow and Dangerous


by

^Allefant


^Programming

Elias Pschernig

^Graphics

Elias Pschernig

^Level Design

Elias Pschernig

^Music

"Manic Polka" Kevin MacLeod (incompetech.com)
"Pixel Peeker Polka - slower" Kevin MacLeod (incompetech.com)
"Overcast" Kevin MacLeod (incompetech.com)
"Allefant Song" Elias Pschernig
"Katjusha"
"Dance of the Sugar Plum Fairy"

^Publishing

Rachel Morris



^Thanks to


Andrea Avers
_<3

Thomas Fjellstrom
_android port Allegro

Trent Gamblin
_Allegro library, inspiration

Pavel Sountsov
_Allegro library

Peter Wang
_Allegro library

Peter Hull
_OSX port Allegro

Shawn Hargreaves
_Allegro library

Eric Botcazou
_Allegro library

Jon Rafkind
_Allegro library

Milan Mimica
_Allegro library

Beoran
_Allegro library

Matthew Leverton
allegro.cc

Evert Gleebbeek
_Allegro library

Grzegorz Adam Hankiewicz
_Allegro library

Angelo Mottola
_Allegro library

Jonathan Seeley
_distracting me on IRC



Made with



^Allegro
Game Programming Library

^Blender
3D Modeler

^Gimp
Image Manipulator

^Geany
Code Editor

^Scramble
Pythonic C Compiler
"""
static LandArray *rows
static def postprocess2:
    int t = game->sequence_ticks
    All *a = global_a
    float w = land_display_width()
    float h = land_display_height()

    Viewport *v = game->viewport
    if smokes[0].active:
        # frames used in the title so always loaded
        LandImage *pic = land_array_get_nth(Render_Gremlin->bitmaps, 0)
        LandImage *pic2 = land_array_get_nth(Render_Allefant->bitmaps, 8)
        for int i in range(STARN):
            Smoke *s = smokes + i
            float pz = 480 - s.z
            float z = 16 / pz
            float angle = t * pi / 300
            float rx = s.x * cos(angle) + s.y * sin(angle)
            float ry = s.y * cos(angle) - s.x * sin(angle)
            float px = w / 2 / v.zoom + rx * z * 16
            float py = h / 2 / v.zoom + ry * z * 4
            px = px - 256 * z
            py = py - 256 * z
            land_image_draw_scaled(s.two ? pic2 : pic, px, py, z, z)

    if not rows:
        rows = land_text_splitlines(credits)

    land_color(1, 1, 1, 1)
    land_text_pos(480, 480 - scrolly)
    for char *row in LandArray *rows:
        if row[0] == '_':
            land_font_set(a.font)
            row++
        elif row[0] == '^':
            land_font_set(a.big)
            row++
 
        else:
            land_font_set(a.medium)
        land_print_center(row)

    if land_text_y_pos() < 0:
        scrolly = 0


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
    bool two
static Smoke smokes[STARN]

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
    intro_back.r = 0
    intro_back.g = 0
    intro_back.b = 0
    intro_back.a = 1
    game->player->super.y = 9000
    if t < 60 * 5:
        move_car()
        intro_tint.r = 1
        intro_tint.g = 1
        intro_tint.b = 1
        intro_tint.a = 1
        smokes[0].active = False
    else:
        intro_tint.r *= 0.99
        intro_tint.g *= 0.99
        intro_tint.b *= 0.99
        intro_tint.a = 1
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

static def intro:
    All *a = global_a
    Game *g = game

    intro_back.r = 0
    intro_back.g = 0
    intro_back.b = 0
    intro_back.a = 1

    a.right = 0
    a.left = 0
    a.down = 0
    a.up = 0
    a.jump = 0
    int t = g.sequence_ticks++
    if t == 1:
        test_tube = None
        find_test_tube()
        if not test_tube:
            g.sequence = 0
            return
        intro_tint.a = 1
        intro_tint.r = .8
        intro_tint.g = .8
        intro_tint.b = .8
    int w = 60 * 2.5
    if t < w:
        a.left = 1
        a.up = 1
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
        if test_tube.y < 0:
            pass
        elif test_tube.y < 1:
            test_tube.y = -1
            LandArray *c = block_colliders(test_tube)
            for Block *b in LandArray *c:
                b.frame = 1
            test_tube.y = -9000
            smokes[0].active = False
            sound(Render_glass, 1)
        float p = (w + 60 * 5 - t) / (60 * 4.0)
        intro_tint.a = 1
        intro_tint.r = .8 * p + (1 - p) * 1
        intro_tint.g = .8 * p + (1 - p) * 1
        intro_tint.b = .8 * p  + (1 - p) * 0
    elif t < w + 60 * 7:
        intro_tint.a = 1
        intro_tint.r *= 0.99
        intro_tint.g *= 0.99
        intro_tint.b *= 0.99
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

static def postprocess1
    int w = 60 * 2.5
    int t = game->sequence_ticks
    if t > w + 60 * 1.5:
        if not smokes[0].active:
            for int i in range(SN):
                Smoke *s = smokes + i
                s.active = True
                s.x = game->player->super.x - 72
                s.z = game->player->super.z
                s.y = 0
                s.sx = 0.2
                s.sy = 0.2
                float r = land_rnd(0, 2 * pi)
                s.dx = cos(r) * 2
                s.dz = sin(r) * 2
                s.dy = land_rnd(0, 0.2)
        float a = 0.1
        float r = 1 * a
        float g = 0.9 * a
        float b = 0.3 * a
        for int i in range(SN):
            Smoke *s = smokes + i
            float sx, sy
            project(game->viewport, s.x, s.y, s.z, &sx, &sy)
            land_image_draw_scaled_tinted(Render_Smoke, sx, sy,
                s.sx, s.sy,
                r, g, b, a)
            s.x += s.dx
            s.y += s.dy
            s.z += s.dz
            s.sx += 0.01
            s.sy += 0.01

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


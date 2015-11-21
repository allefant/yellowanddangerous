import game

global LandColor intro_tint
static Block *test_tube
static int ty
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
static class Smoke:
    bool active
    float x, y, z
    float sx, sy
    float dx, dy, dz
static Smoke smokes[SN]

static def walls_down(bool final):
    for Block *b in LandArray *game->blocks->fixed:
        if b.block_type == Render_WallLeft or b.block_type == Render_WallRight:
           b.y -= land_rand(8, 12)
           if final:
               b.y = -9000
           game->blocks->rebuild_static_cache = True

def intro_sequence:
    All *a = global_a
    Game *g = game

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
            g.sequence = False
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
        g.sequence = False

def intro_postprocess:
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

import common
import game, isometric, main, debug
import vent
import barrel
import platform
import eye
import cart
import gremlin
import intro

class Render:
    bool was_setup
    LandColor background_color
    LandStream *music
    char *path
    int song

Render r
global LandImage *Render_Smoke

#static int filter(char const *name, bool is_dir, void *data):
#    if is_dir: return 0
#    return 1

static def loadpic(char const *name) -> LandImage *:
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, r.path)
    land_buffer_cat(b, name)
    char *path = land_buffer_finish(b)
    LandImage *i = land_image_load(path)
    land_free(path)
    land_image_center(i)
    return i

static BlockType *def render_load(char const *name, float x, y, z,
        bool dynamic, lift, transparent, fixed, int frames):
    BlockType *bt = None
    float ss = 96
    bt = blocktype_new(name, ss * x, ss * y, ss * z,
        block_tick, block_touch, block_destroy, block_allocate,
        block_post_init)
    bt->dynamic = dynamic
    bt->lift = lift
    bt->transparent = transparent
    bt.fixed = fixed

    #LandArray *frames
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, r.path)
    land_buffer_cat(b, name)
    char *path = land_buffer_finish(b)
    # doesn't work on Android
    #frames = land_filelist(path, filter, LAND_FULL_PATH, None)

    #if not frames:
    #    print("Could not find %s%s", path, name)

    #land_array_sort_alphabetical(frames)

    #for char *s in LandArray *frames:
    for int fi in range(1, frames + 1)
        char s[1024]
        sprintf(s, "%s/%04d.png", path, fi)
        #LandImage *pic = land_image_load(s)
        LandImage *pic = land_image_new_deferred(s)
        pic.flags |= LAND_AUTOCROP
        if not pic: # or not (pic.flags & LAND_LOADED):
            print("Could not load %s", s)
            break
        else:
            if not bt.bitmaps:
                bt->bitmaps = land_array_new()
                #bt->x = -land_image_width(pic) / 4
                #bt->y = -land_image_height(pic) / 4
            land_array_add(bt->bitmaps, pic)
        #land_free(s)
    land_free(path)
    #land_array_destroy(frames)
    return bt

***scramble
defs = []
def load(name, x, y, z, dynamic = False, lift = False, transparent = False, fixed = False, frames = 1):
    defs.append((name, x, y, z, dynamic, lift, transparent, fixed, frames))
    parse("global BlockType *Render_" + name + "\n")

sdefs = []
def loads(name):
    vname = "Render_" + name.replace(" ", "_")
    sdefs.append((name, vname))
    parse("global LandSound *" + vname + "\n")

load("Block", 2, 2, 2)
load("BlockBottom", 2, 0.5, 2)
load("BlockLeft", 0.5, 2, 2)
load("BlockBottom2", 2, 1, 2)
load("BlockBottom3", 2, 0.5, 2)
load("BlockBottomLeft3", 2, 0.5, 1)
load("PlankRight", 1.9, 0.245, 0.5, dynamic = True, lift = True)
load("PlankLeft", 0.5, 0.245, 1.9, dynamic = True, lift = True)
load("BlockLeft2", 1, 2, 2)
load("BlockRight2", 2, 2, 1)
load("Scientist", 0.75, 1.8, 0.75, dynamic = True, frames = 64)
load("Cube2", 1, 1, 1)
load("Plate", 1, 0.1, 1, frames = 2)
load("Cube3", 0.667, 0.667, 0.667, dynamic = True, lift = True)
load("Barrel", .8, 1.2, .8, dynamic = True, frames = 3)
load("TreeBottom", 2, 2, 2)
load("TreeTop", 2, 2, 2)
load("Trunk", 0.2, 1.0, 0.2)
load("ExitLeft", 1, 0.25, 2, frames = 5)
load("ExitRight", 2, 0.25, 1, frames = 5)
load("Allefant", 1.3, 1.8, 1.3, dynamic = True, frames = 64)
load("BlockRight4", 2, 2, .5, transparent = True)
load("BlockLeft4", .5, 2, 2, transparent = True)
load("BlockSmall3", 1, 0.5, 1)
load("CherryTree", 3, 5, 3)
load("Waypoint", 0.5, 0, 0.5, frames = 10)
load("Crate", 0.95, 2, 0.95, dynamic = True)
load("BlockLeft3", 0.5, 1, 2)
load("BlockRight3", 2, 1, 0.5)
load("Plant", 0.5, 0.5, 0.5, dynamic = True, lift = True)
load("Platform", 2, 0.5, 2, dynamic = True, fixed = True)
load("LeverLeft", 0.5, 2, 1, frames = 2)
load("LeverRight", 1, 2, 0.5, frames = 2)
load("Statue", 2, 2, 2)
load("RampLeft", 1, 0.5, 2)
load("RampRight", 2, 0.5, 1)
load("VentLeft", 0.5, 2, 1, dynamic = True, fixed = True, frames = 4)
load("VentRight", 1, 2, 0.5, dynamic = True, fixed = True, frames = 4)
load("BlockSmall", 1, 0.5, 1)
load("BlockRight", 2, 2, .5)
load("BlockSmallLeft", 0.5, 1, 1)
load("BlockSmallRight", 1, 1, 0.5)
load("Gentian", 0.5, 0.5, 0.5)
load("Eye", 0.5, 0.5, 0.5, dynamic = True, lift = True, frames = 8)
load("Ginko", 2, 4, 2)
load("Edelweiss", .5, .5, .5)
load("Cart", 2, 1.25, 2, dynamic = True, frames = 4)
load("GrateBottom", 2, 0.25, 2)
load("GrateLeft", .25, 2, 2)
load("GrateRight", 2, 2, .25)
load("Gremlin", .5, .5, .5, dynamic = True, frames = 16)
load("InvisibleLeft", .25, 4, 2)
load("InvisibleRight", 2, 4, .25)
load("Orchid", .5, 1.25, .75)
load("Sunflower", 1, 2.5, 1)
load("Hyacinth", .5, 1, .5)
load("DeskLeft", 1, 1, 2)
load("WallLeft", .5, 3, 2)
load("WallRight", 2, 3, .5)
load("DeskRight", 2, 1, 1)
load("Floor", 2, .25, 2, frames = 2)
load("TestTube", .125, .5, .125, dynamic = True, lift = True, frames = 7)
load("Rose", .5, 1, .5)
load("Belladonna", .5, 1.5, .5)
load("BridgeRight", 2.5, 0.25, 0.5, dynamic = True, lift = True)
load("BridgeLeft", 0.5, 0.25, 2.5, dynamic = True, lift = True)
load("Car", 2, 2, 3, frames = 2)

loads("step")
loads("push")
loads("off")
loads("on")
loads("uhg")
loads("oh no")
loads("teleport")
loads("glass")
loads("metal")
loads("ignition")
***

static LandSound *def render_loads(char const *name):
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    land_buffer_cat(b, "/data/")
    land_buffer_cat(b, name)
    land_buffer_cat(b, ".ogg")
    char *fpath = land_buffer_finish(b)
    LandSound *s = land_sound_load(fpath)
    land_free(fpath)
    if not s:
        print("Could not load %s", fpath)
    return s

def render_loading_screen():
    land_clear(1, 1, 1, 1)
    land_clear_depth(1)
    land_reset_transform()
    float w = land_display_width()
    float h = land_display_height()
    land_text_pos(w / 2, h / 2 - 10)
    land_font_set(global_a->medium)
    land_color(0, 0, 0, 1)
    land_print_center("%s", "Loading! Please Wait!")

def render_setup():
    if r.was_setup: return
    r.was_setup = True

    land_render_state(LAND_ALPHA_TEST, True)
    land_render_state(LAND_ALPHA_FUNCTION, LAND_GREATER)
    land_render_state(LAND_ALPHA_VALUE, 0)

    r.background_color = (LandColor){1, 1, 1, 1}

    if r.path:
        land_free(r.path)
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    land_buffer_cat(b, "/data/yellowanddangerous/")
    r.path = land_buffer_finish(b)

    render_loading_screen()
    land_flip()

    r.music = land_stream_new(2048, 4, 22050, 16, 2)

    load_info()

    play_song()

    block_types = land_array_new()
***scramble
for name, x, y, z, dynamic, lift, transparent, fixed, frames in defs:
    parse('    Render_{} = render_load("{}", {}, {}, {}, {}, {}, {}, {}, {})\n'.format(
        name, name, x, y, z, dynamic, lift, transparent, fixed, frames))
    parse('    land_array_add(block_types, Render_{})\n'.format(name))

for name, vname in sdefs:
    parse('    {} = render_loads("{}")\n'.format(vname, name))
***

    int i = 0
    for BlockType *bt in LandArray *block_types:
        bt.btid = i++

    Render_InvisibleLeft->invisible = True
    Render_InvisibleRight->invisible = True

    Render_Scientist->tick = player_tick
    Render_Scientist->touch = player_touch
    Render_Scientist->destroy = player_destroy
    Render_Scientist->allocate = player_allocate
    Render_Scientist->post_init = player_init
    Render_Allefant->tick = allefant_tick
    Render_Allefant->touch = allefant_touch
    Render_Allefant->allocate = allefant_allocate
    Render_Allefant->post_init = allefant_init
    Render_Allefant->destroy = allefant_destroy
    Render_Cube3->touch = cube_touch
    Render_Barrel->touch = barrel_touch
    Render_VentLeft->tick = vent_tick
    Render_VentLeft->allocate = vent_allocate
    Render_VentRight->tick = vent_tick
    Render_VentRight->allocate = vent_allocate
    Render_Platform->allocate = platform_allocate
    Render_Platform->tick = platform_tick
    Render_Platform->touch = platform_touch
    Render_Eye->tick = eye_tick
    Render_Cart->tick = cart_tick
    Render_Gremlin->tick = gremlin_tick
    Render_Gremlin->touch = gremlin_touch
    Render_Gremlin->allocate = gremlin_allocate

    Render_Smoke = loadpic("../smoke.png")

def play_song:
    All *a = global_a
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    if r.song == 0:
        land_buffer_cat(b, "/data/katyusha.ogg")
    elif r.song == 1:
        land_buffer_cat(b, "/data/allefant.ogg")
    elif r.song == 2:
        land_buffer_cat(b, "/data/fairy.ogg")
    char *musicpath = land_buffer_finish(b)
    land_stream_music(r.music, musicpath)
    land_free(musicpath)
    land_stream_volume(r.music, a.music / 6.0)

    r.song++
    if r.song == 3:
        r.song = 0

def song_volume:
    All *a = global_a
    land_stream_volume(r.music, a.music / 6.0)

def render_teardown():
***scramble
for name, x, y, z, dynamic, lift, transparent, fixed, frames in defs:
    parse('    blocktype_destroy(Render_{})\n'.format(name))

for name, vname in sdefs:
    parse('    land_sound_destroy({})\n'.format(vname))
***

    land_stream_destroy(r.music)
    land_free(r.path)

static def draw_move_controls:
    All *a = global_a
    float w = land_display_width()
    float h = land_display_height()
    land_color(0.5, 0.4, 0, 0.5)
    float rr = w / 8 * 0.8

    if a.dpad == 2 or a.dpad == 3:
        rr *= 1.5
    float rx = rr
    float ry = h - rr

    if a.dpad == 4:
        if not a.swipe:
            return
        rx = a.swipex
        ry = a.swipey
    elif a.dpad == 1 or a.dpad == 3:
        rx = w - rr

    float xy[2 * 34]
    xy[0] = rx
    xy[1] = ry
    for int i in range(1, 34):
        double c = cos((i - 1.5) * pi / 16)
        double s = sin((i - 1.5) * pi / 16)
        float r2 = rr
        if i % 4 == 0 or i % 4 == 3:
            r2 *= 0.75
        xy[i * 2 + 0] = rx + c * r2
        xy[i * 2 + 1] = ry + s * r2
    land_filled_polygon(34, xy)

static def draw_jump_controls:
    All *a = global_a
    if a.dpad == 4:
        return
    land_color(0.5, 0.4, 0, 0.5)
    float w = land_display_width()
    float h = land_display_height()
    float rr = w / 8 * 0.8
    if a.dpad == 2 or a.dpad == 3:
        rr *= 1.5
    float rx = w - rr
    float ry = h - rr
    if a.dpad == 1 or a.dpad == 3:
        rx = rr
    rr *= 0.6
    land_filled_circle(rx - rr, ry - rr, rx + rr, ry + rr)

static def draw_pause_controls:
    land_color(0.5, 0.4, 0, 0.5)
    float w = land_display_width()
    float rr = w / 8 * 0.8
    
    land_filled_rectangle(w - rr, rr / 8,
        w - rr + rr * 3 / 8, rr * 7 / 8)
    land_filled_rectangle(w - rr + rr * 4 / 8, rr / 8,
        w - rr + rr * 7 / 8, rr * 7 / 8)

def render(Game *g):
    All *a = global_a
    float w = land_display_width()
    float h = land_display_height()
    float fh = land_font_height(a.medium)
    #float z = g.viewport->zoom

    land_clear_depth(1)

    if game->sequence:
        a.tint = intro_tint
        land_clear(0, 0, 0, 1)
    else:
        a.tint.a = 0
        land_clear(r.background_color.r, r.background_color.g,
            r.background_color.b, r.background_color.a)

    render_blocks(g->blocks, g->viewport)

    if game->sequence:
        intro_postprocess()

    land_reset_transform()

    if not game->sequence:
        draw_move_controls()
        draw_jump_controls()
        draw_pause_controls()

    land_color(0, 0, 0, 1)
    land_font_set(a.medium)

    if True:
        land_color(0, 0, 0, 1)
        land_text_pos(0, 0)
        land_print("%s", g->title)
        if a.editor:
            land_print("%d", g->level)

    if g->ticks < 300:
        
        land_text_pos(w * 3 / 4, fh)
        land_print_center("%s", "Yellow and Dangerous")
        land_print_center("%s", "by Allefant")

    if g->ticks > 600 or a.editor:
        float y = h - 3 * fh
        land_text_pos(0, y)
        land_print_wordwrap(w, h, "%s", g->hint)

def render_block(Block *self, Viewport *viewport):
    All *a = global_a
    BlockType *bt = self->block_type
    float x, y
    project(viewport,
        self->x + self->xs / 2,
        self->y + self->ys / 2,
        self->z + self->zs / 2,
        &x, &y)
    #x += bt->x
    #y += bt->y

    bool hide = bt.invisible
    if bt == Render_Waypoint:
        if not a.editor:
            hide = True

    if self.block_type->bitmaps and not hide:
        float cr = 1
        float cg = 1
        float cb = 1
        float ca = 1
        float scale = 24
        float height = floor(self.y / scale + 4)
        if height >= 0:
            cb -= height / 64.0
            cg -= height / 128.0
        else:
            cb += height / 64
            cr += height / 64
        if a.tint.a:
            cr = a.tint.r
            cg = a.tint.g
            cb = a.tint.b
            ca = a.tint.a
        LandImage *frame = land_array_get_nth(bt.bitmaps,
            self->frame)
        land_image_load_on_demand(frame)
        x -= land_image_width(frame) / 4
        y -= land_image_height(frame) / 4
        land_image_draw_scaled_tinted(frame, x, y, 0.5, 0.5,
                cr, cg, cb, ca)

    bool show_bounds = debug_bounding_boxes or self == game->picked
    bool show_misaligned = False
    bool show_ground = self == game->picked

    if a->editor:
        float s = 24

        if self.y < -s * 6:
            show_ground = True
            show_bounds = True
        
        float ix = self.x / s
        float iy = self.y / s
        float iz = self.z / s
        int xi = floor(ix)
        int yi = floor(iy)
        int zi = floor(iz)
        if xi != ix or yi != iy or zi != iz:
            show_bounds = True
            show_misaligned = True
        
    if show_bounds:
        float x2 = self->x + self->xs
        float y2 = self->y + self->ys
        float z2 = self->z + self->zs

        float v[22]
        project(viewport, self->x, y2, self->z, v + 0, v + 1)
        project(viewport, self->x, y2, z2, v + 2, v + 3)
        project(viewport, x2, y2, z2, v + 4, v + 5)
        project(viewport, x2, y2, self->z, v + 6, v + 7)
        project(viewport, self->x, self->y, z2, v + 8, v + 9)
        project(viewport, x2, self->y, z2, v + 10, v + 11)
        project(viewport, x2, self->y, self->z, v + 12, v + 13)

        #
        #      0
        #    /   . 
        #  1       3
        #  | \   / |
        #  4   2   6
        #    \ | /
        #      5

        if show_misaligned:
            land_color(0.75, 0, 0.75, 1)
            land_line(v[0], v[1], v[4], v[5])
            land_line(v[2], v[3], v[6], v[7])
        else:
            land_color(0, 0, 0, 1)

        land_line(v[0], v[1], v[2], v[3])
        land_line(v[2], v[3], v[8], v[9])
        land_line(v[8], v[9], v[10], v[11])
        land_line(v[10], v[11], v[12], v[13])
        land_line(v[12], v[13], v[6], v[7])
        land_line(v[6], v[7], v[0], v[1])

        if show_ground:
            project(viewport, self.x, 0, self.z, v + 14, v + 15)
            project(viewport, self.x, 0, z2, v + 16, v + 17)
            project(viewport, x2, 0, z2, v + 18, v + 19)
            project(viewport, x2, 0, self.z, v + 20, v + 21)
            land_color(1, 0, 0, 1)
            land_line(v[14], v[15], v[16], v[17])
            land_line(v[16], v[17], v[18], v[19])
            land_line(v[18], v[19], v[20], v[21])
            land_line(v[20], v[21], v[14], v[15])
            

def render_blocks(Blocks *blocks, Viewport *viewport):

    # Each block has a cache of other blocks which are drawn earlier but also
    # need to appear in front of the block. For static blocks this cache is
    # built only the first time they are drawn. Since all static blocks are
    # drawn before any dynamic blocks, that cache cannot possibly change after
    # all.
    # For dynamic blocks the cache has to be rebuilt whenever any of them moves
    # however.

    float z = viewport.zoom
    land_reset_transform()
    land_scale(z, z)

    int n1 = land_array_count(blocks->fixed)
    int n2 = land_array_count(blocks->dynamic)
    for int i in range(n1 + n2):
        Block *b
        if i < n1:
            b = land_array_get_nth(blocks->fixed, i)
        else:
            b = land_array_get_nth(blocks->dynamic, i - n1)
        bool need_mask = False

        # Need to rebuild the cache for this block?
        if (not b->block_type->dynamic and blocks->rebuild_static_cache) or\
            (b->block_type->dynamic and blocks->rebuild_dynamic_cache):

            land_array_clear(b->cache)

            int n = land_array_count(blocks->fixed)
            int m = n
            if b->block_type->dynamic:
                n += land_array_count(blocks->dynamic)

            for int j in range(n):
                Block *already
                if j < m:
                    already = land_array_get_nth(blocks->fixed, j)
                else:
                    already = land_array_get_nth(blocks->dynamic, j - m)
                if debug_no_mask: break
                if already == b: break
                if block_sort_order(already, b, viewport) == 1:
                    land_array_add(b->cache, already)

        for Block *already in LandArray *b->cache:
            if not debug_no_mask and not need_mask:
                need_mask = True

                # Unconditionally write into depth buffer only (to create
                # mask). The mask will have all blocks which have been
                # drawn already but are in front (and so should not be
                # overdrawn).

                land_render_state(LAND_DEPTH_TEST, True)
                land_render_state(LAND_DEPTH_FUNCTION, LAND_ALWAYS)
                land_render_state(LAND_WRITE_MASK, LAND_DEPTH_MASK)

                float x1, y1, x2, y2
                block_get_bounding_rect(b, viewport, &x1, &y1, &x2, &y2)
                x1 -= 30
                y1 -= 30
                x2 += 60
                y2 += 60
                land_clip((int)(x1 * z), (int)(y1 * z),
                    (int)(x2 * z) + 1, (int)(y2 * z) + 1)

            render_block(already, viewport)

        if not debug_no_mask and need_mask:
            # Write only color (no depth), but only where there is no mask.
            land_render_state(LAND_DEPTH_FUNCTION, LAND_LESS)
            land_render_state(LAND_WRITE_MASK, LAND_RGBA_MASK)

        #x1, y1, x2, y2 = b.get_bounding_rect(viewport)

        render_block(b, viewport)

        #if not debug->no_mask and need_mask:
        #    render_block(b, viewport)
        #c = al_map_rgb_f(1, 0, 0)
        #al_draw_line(x1 + 2, y1 + 2, x2 - 2, y1 + 2, c, 1)
        #al_draw_line(x1 + 2, y1 + 2, x1 + 2, y2 - 2, c, 1)

        if not debug_no_mask and need_mask:
            # Restore everything to how it was before this block was drawn.
            land_render_state(LAND_WRITE_MASK, LAND_DEPTH_MASK | LAND_RGBA_MASK)
            land_clear_depth(1)

            land_render_state(LAND_DEPTH_TEST, False)
            land_unclip()

    for Block *b in LandArray *blocks->transparent:
        render_block(b, viewport)

    blocks->rebuild_static_cache = False
    blocks->rebuild_dynamic_cache = False

import common
import game, isometric, main, debug

class Render:
    bool was_setup
    LandColor background_color
    LandFont *font
    LandStream *music
    char *path

Render r

#static int filter(char const *name, bool is_dir, void *data):
#    if is_dir: return 0
#    return 1

static BlockType *def render_load(char const *name, float x, y, z, bool dynamic, lift, transparent):
    BlockType *bt = None
    float ss = 96 / sqrt(2)
    bt = blocktype_new(ss * x, ss * y, ss * z,
        block_tick, block_touch, block_destroy)
    bt->dynamic = dynamic
    bt->lift = lift
    bt->transparent = transparent

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
    int fi = 1
    while True:
        char s[1024]
        sprintf(s, "%s/%04d.png", path, fi)
        fi++
        LandImage *pic = land_image_load(s)
        if not pic or not (pic.flags & LAND_LOADED):
            print("Could not load %s", s)
            break
        else:
            if not bt.bitmaps:
                bt->bitmaps = land_array_new()
                bt->x = -land_image_width(pic) / 4
                bt->y = -land_image_height(pic) / 4
            land_array_add(bt->bitmaps, pic)
        #land_free(s)
    land_free(path)
    #land_array_destroy(frames)
    return bt

***scramble
defs = []
def load(name, x, y, z, dynamic = False, lift = False, transparent = False):
    defs.append((name, x, y, z, dynamic, lift, transparent))
    parse("global BlockType *Render_" + name + "\n")

sdefs = []
def loads(name):
    vname = "Render_" + name.replace(" ", "_")
    sdefs.append((name, vname))
    parse("global LandSound *" + vname + "\n")

load("Block", 2, 2, 2)
load("BlockBottom", 2, 0.5, 2)
load("BlockLeft", 1, 2, 2)
load("BlockBottom2", 2, 1, 2)
load("BlockBottom3", 2, 1, 2)
load("BlockBottomLeft3", 2, 1, 1)
load("Bridge", 2, 0.25, 0.5, dynamic = True, lift = True)
load("Bridge2", 0.5, 0.25, 2, dynamic = True, lift = True)
load("BlockLeft2", 1, 2, 2)
load("BlockRight2", 2, 2, 1)
load("Scientist", 0.75, 1.8, 0.75, dynamic = True)
load("Cube2", 1, 1, 1)
load("Plate", 1, 0.1, 1)
load("Cube3", 0.667, 0.667, 0.667, dynamic = True, lift = True)
load("Barrel", 0.8, 1.2, 0.8, dynamic = True)
load("TreeBottom", 2, 2, 2)
load("TreeTop", 2, 1.5, 2)
load("Trunk", 0.2, 1.0, 0.2)
load("ExitLeft", 1, 0.2, 2)
load("ExitRight", 2, 0.2, 1)
load("Allefant", 1.3, 1.8, 1.3, dynamic = True)
load("BlockRight4", 2, 2, 1, transparent = True)
load("BlockLeft4", 1, 2, 2, transparent = True)
load("BlockSmall3", 1, 1, 1)
load("CherryTree", 2, 5, 2)
load("Waypoint", 1, 0, 1)

loads("step")
loads("push")
loads("off")
loads("on")
loads("uhg")
loads("oh no")
loads("teleport")
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

    b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    land_buffer_cat(b, "/data/Muli-Regular.ttf")
    char *fontpath = land_buffer_finish(b)
    r.font = land_font_load(fontpath, 24)
    land_free(fontpath)
    land_clear(1, 1, 1, 1)
    land_text_pos(480, 300)
    land_font_set(r.font)
    land_color(0, 0, 0, 1)
    land_print_center("%s", "Loading! Please Wait!")
    land_flip()

    r.music = land_stream_new(2048, 4, 48000, 16, 2)
    b = land_buffer_new()
    land_buffer_cat(b, main_data_path)
    land_buffer_cat(b, "/data/katyusha.ogg")
    char *musicpath = land_buffer_finish(b)
    land_stream_music(r.music, musicpath)
    land_free(musicpath)
    land_stream_volume(r.music, 0.75)

    block_types = land_array_new()
***scramble
for name, x, y, z, dynamic, lift, transparent in defs:
    parse('    Render_{} = render_load("{}", {}, {}, {}, {}, {}, {})\n'.format(
        name, name, x, y, z, dynamic, lift, transparent))
    parse('    land_array_add(block_types, Render_{})\n'.format(name))

for name, vname in sdefs:
    parse('    {} = render_loads("{}")\n'.format(vname, name))
***

    int i = 0
    for BlockType *bt in LandArray *block_types:
        bt.btid = i++

    Render_Scientist->tick = player_tick
    Render_Scientist->touch = player_touch
    Render_Scientist->destroy = player_destroy
    Render_Allefant->tick = allefant_tick
    Render_Allefant->touch = allefant_touch
    Render_Cube3->touch = cube_touch

def render_teardown():
***scramble
for name, x, y, z, dynamic, lift, transparent in defs:
    parse('    blocktype_destroy(Render_{})\n'.format(name))

for name, vname in sdefs:
    parse('    land_sound_destroy({})\n'.format(vname))
***

    land_font_destroy(r.font)
    land_stream_destroy(r.music)
    land_free(r.path)

def render(Game *g):
    float w = land_display_width()
    float h = land_display_height()
    float fh = land_font_height(r.font)
    #float z = g.viewport->zoom

    land_clear_depth(1)
    land_clear(r.background_color.r, r.background_color.g,
        r.background_color.b, r.background_color.a)

    render_blocks(g->blocks, g->viewport)

    land_reset_transform()

    land_color(0.5, 0.4, 0, 0.5)
    float rr = w / 8 * 0.8
    float rx = rr
    float ry = h - rr
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
    rx = w - rr
    rr *= 0.75
    land_filled_circle(rx - rr, ry - rr, rx + rr, ry + rr)

    land_color(0, 0, 0, 1)
    land_font_set(r.font)

    if g->level == g->levels:
        
        land_text_pos(0, 0)
        land_print("%s", "Congratulations! I'm surprised someone made it here :)")
    else:
        land_color(0, 0, 0, 1)
        land_text_pos(0, 0)
        land_print("Level %d/%d", g->level, g->levels)

    if g->ticks < 300:
        
        land_text_pos(w * 3 / 4, fh)
        land_print_center("%s", "Yellow and Dangerous")
        land_print_center("%s", "by Allefant")

    float y = h - 3 * fh
    land_text_pos(0, y)
    land_print_wordwrap(w, h, "%s", g->hint)
    
def render_block(Block *self, Viewport *viewport):
    BlockType *bt = self->block_type
    float x, y
    project(viewport,
        self->x + self->xs / 2,
        self->y + self->ys / 2,
        self->z + self->zs / 2,
        &x, &y)
    x += bt->x
    y += bt->y

    if self.block_type->bitmaps:
    
        land_image_draw_scaled(land_array_get_nth(
            self->block_type->bitmaps, self->frame), x, y, 0.5, 0.5)

    if debug_bounding_boxes or self == game->picked:
        float x2 = self->x + self->xs
        float y2 = self->y + self->ys
        float z2 = self->z + self->zs

        float v[14]
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

        land_color(0, 0, 0, 1)
        land_line(v[0], v[1], v[2], v[3])
        land_line(v[2], v[3], v[8], v[9])
        land_line(v[8], v[9], v[10], v[11])
        land_line(v[10], v[11], v[12], v[13])
        land_line(v[12], v[13], v[6], v[7])
        land_line(v[6], v[7], v[0], v[1])

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

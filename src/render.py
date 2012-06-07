import common
import game, isometric, main, debug

class Render:
    bool was_setup
    LandColor background_color
    LandFont *font
    LandStream *music
    char *path

Render r

static int filter(char const *name, bool is_dir, void *data):
    if is_dir: return 0
    return 1

static BlockType *def render_load(char const *name, float x, y, z, bool dynamic, lift, transparent):
    LandArray *frames
    LandBuffer *b = land_buffer_new()
    land_buffer_cat(b, r.path)
    land_buffer_cat(b, name)
    char *path = land_buffer_finish(b)
    frames = land_filelist(path, filter, LAND_FULL_PATH, None)
    land_free(path)

    if not frames:
        print("Could not find %s%s", path, name)
    BlockType *bt = None

    land_array_sort_alphabetical(frames)

    int n = land_array_count(frames)
    for int i in range(n):
        char *s = land_array_get_nth(frames, i)
        LandImage *pic = land_image_load(s)
        if not pic:
            print("Could not load %s", s)
        else:
            if not bt:
                float ss = 96 / sqrt(2)
                bt = blocktype_new(ss * x, ss * y, ss * z,
                    block_tick, block_touch)
                bt->dynamic = dynamic
                bt->lift = lift
                bt->transparent = transparent
                bt->bitmaps = land_array_new()
                bt->x = -land_image_width(pic) / 2
                bt->y = -land_image_height(pic) / 2
            land_array_add(bt->bitmaps, pic)
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

***scramble
for name, x, y, z, dynamic, lift, transparent in defs:
    parse('    Render_{} = render_load("{}", {}, {}, {}, {}, {}, {})\n'.format(
        name, name, x, y, z, dynamic, lift, transparent))

for name, vname in sdefs:
    parse('    {} = render_loads("{}")\n'.format(vname, name))
***

    Render_Scientist->tick = player_tick
    Render_Scientist->touch = player_touch
    Render_Allefant->tick = allefant_tick
    Render_Allefant->touch = allefant_touch
    Render_Cube3->touch = cube_touch

def render(Game *g):
    render_setup()

    float w = land_display_width()
    float h = land_display_height()
    float fh = land_font_height(r.font)

    land_clear_depth(1)
    land_clear(r.background_color.r, r.background_color.g,
        r.background_color.b, r.background_color.a)

    render_blocks(g->blocks, g->viewport)

    land_color(0, 0, 0, 1)
    land_font_set(r.font)

    if g->level == 13:
        
        land_text_pos(0, 0)
        land_print("%s", "Congratulations! I'm surprised someone made it here :)")
    else:
        land_color(0, 0, 0, 1)
        land_text_pos(0, 0)
        land_print("Level %d/12", g->level)

    if g->ticks < 300:
        
        land_text_pos(720, fh)
        land_print_center("%s", "Yellow and Dangerous")
        land_print_center("%s", "by Allefant")

    float y = 600 - 3 * fh
    land_text_pos(0, y)
    land_print_wordwrap(w, h, "%s", level_get_hint(g->level))
    
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
    land_image_draw(land_array_get_nth(self->block_type->bitmaps, self->frame), x, y)

    if debug_bounding_boxes:
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
        #    /   \
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
                land_clip((int)(x1), (int)(y1), (int)(x2) + 1, (int)(y2) + 1)

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

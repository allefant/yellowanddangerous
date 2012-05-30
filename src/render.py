import array, random, glob
from math import *
from allegro import *
import block, debug, main, level

class Render:
    was_setup = False
    @staticmethod
    def setup():
        if Render.was_setup: return
        Render.was_setup = True

        al_set_render_state(ALLEGRO_ALPHA_TEST, True)
        al_set_render_state(ALLEGRO_ALPHA_FUNCTION, ALLEGRO_RENDER_GREATER)
        al_set_render_state(ALLEGRO_ALPHA_TEST_VALUE, 0)
        
        Render.background_color = al_map_rgb_f(1, 1, 1)

        path = main.data_path + "/data/yellowanddangerous/"

        def load(name, x, y, z, dynamic = False, lift = False, transparent = False):
            frames = glob.glob(path + name + "/*.png")
            if not frames:
                print("Could not find " + path + name)
            bt = None
            for s in sorted(frames):
                pic = al_load_bitmap(s)
                if not pic:
                    print("Could not load " + s)
                else:
                    if not bt:
                        s = 96 / sqrt(2)
                        bt = block.BlockType(s * x, s * y, s * z)
                        bt.dynamic = dynamic
                        bt.lift = lift
                        bt.transparent = transparent
                        bt.bitmaps = []
                        bt.x = -al_get_bitmap_width(pic) / 2
                        bt.y = -al_get_bitmap_height(pic) / 2
                        setattr(Render, name, bt)
                    bt.bitmaps.append(pic)

        def loads(name):
            fpath = main.data_path + "/data/" + name + ".ogg"
            s = al_load_sample(fpath)
            if not s:
                print("Could not load " + fpath)
            else:
                setattr(Render, name.replace(" ", "_"), s)

        Render.font = al_load_font(main.data_path + "/data/Muli-Regular.ttf", 24, 0)
        al_clear_to_color(al_map_rgb_f(1, 1, 1))
        al_draw_textf(Render.font, al_map_rgb_f(0, 0, 0), 480, 300,
            ALLEGRO_ALIGN_CENTER,
            "%s", "Loading! Please Wait!".encode("utf8"))
        al_flip_display()

        Render.music = al_load_audio_stream(main.data_path + "/data/katyusha.ogg", 4, 2048)
        al_set_audio_stream_playmode(Render.music, ALLEGRO_PLAYMODE_LOOP)
        al_set_audio_stream_gain(Render.music, 0.75)
        al_attach_audio_stream_to_mixer(Render.music, al_get_default_mixer())

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
        load("Trunk", .2, 1.0, .2)
        load("ExitLeft", 1, 0.2, 2)
        load("ExitRight", 2, 0.2, 1)
        load("Trunk", .2, 1.0, .2)
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

r = Render

def render(g):
    r.setup()

    w = al_get_display_width(a.display)
    h = al_get_display_height(a.display)
    fh = al_get_font_line_height(r.font)

    al_clear_depth_buffer(1);
    al_clear_to_color(r.background_color)

    render_blocks(g.blocks, g.viewport)

    black = al_map_rgb(0, 0, 0)
    if g.level == 13:
        al_draw_textf(Render.font, black, 0, 0, 0, "%s",
            "Congratulations! I'm surprised someone made it here :)".encode("utf8"))
    else:
        al_draw_textf(Render.font, black, 0, 0, 0, "%s",
            "Level {}/12".format(g.level).encode("utf8"))

    if g.ticks < 300:
        al_draw_textf(Render.font, black, 720, fh, ALLEGRO_ALIGN_CENTER, "%s",
            "Yellow and Dangerous".encode("utf8"))
        al_draw_textf(Render.font, black, 720, fh + fh, ALLEGRO_ALIGN_CENTER, "%s",
            "by Allefant".encode("utf8"))

    y = 600 - 3 * fh
    for hint in getattr(level, "hint{}".format(g.level)).splitlines():
        al_draw_textf(Render.font, black, 0, y, 0, "%s",
            hint.encode("utf8"))
        y += fh
    
def render_block(self, viewport):
    bt = self.block_type
    x, y = viewport.project(
        self.x + self.xs / 2,
        self.y + self.ys / 2,
        self.z + self.zs / 2)
    x += bt.x
    y += bt.y
    al_draw_bitmap(self.block_type.bitmaps[self.frame], x, y, 0)

    if debug.bounding_boxes:
        x2 = self.x + self.xs
        y2 = self.y + self.ys
        z2 = self.z + self.zs

        project = viewport.project
        v = (project(self.x, y2, self.z),
            project(self.x, y2, z2),
            project(x2, y2, z2),
            project(x2, y2, self.z),
            project(self.x, self.y, z2),
            project(x2, self.y, z2),
            project(x2, self.y, self.z),
            )

        #
        #      0
        #    /   \
        #  1       3
        #  | \   / |
        #  4   2   6
        #    \ | /
        #      5

        c = al_map_rgb(0, 0, 0)
        al_draw_line(v[0][0], v[0][1], v[1][0], v[1][1], c, 1)
        al_draw_line(v[1][0], v[1][1], v[4][0], v[4][1], c, 1)
        al_draw_line(v[4][0], v[4][1], v[5][0], v[5][1], c, 1)
        al_draw_line(v[5][0], v[5][1], v[6][0], v[6][1], c, 1)
        al_draw_line(v[6][0], v[6][1], v[3][0], v[3][1], c, 1)
        al_draw_line(v[3][0], v[3][1], v[0][0], v[0][1], c, 1)

def render_blocks(blocks, viewport):

    for b in blocks.static + blocks.dynamic:
        need_mask = False

        if (not b.block_type.dynamic and blocks.rebuild_static_cache) or\
            (b.block_type.dynamic and blocks.rebuild_dynamic_cache):

            b.cache = []

            if b.block_type.dynamic:
                ablocks = blocks.static + blocks.dynamic
            else:
                ablocks = blocks.static
            
            for already in ablocks:
                if debug.no_mask: break
                if already is b: break
                if already.sort_order(b, viewport) == 1:
                    b.cache.append(already)

        for already in b.cache:
            if not debug.no_mask and not need_mask:
                need_mask = True

                # Unconditionally write into depth buffer only (to create
                # mask). The mask will have all blocks which have been
                # drawn already but are in front (and so should not be
                # overdrawn).

                al_set_render_state(ALLEGRO_DEPTH_TEST, True)
                al_set_render_state(ALLEGRO_DEPTH_FUNCTION, ALLEGRO_RENDER_ALWAYS)
                al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_DEPTH)

                x1, y1, x2, y2 = b.get_bounding_rect(viewport)
                x1 -= 30
                y1 -= 30
                x2 += 60
                y2 += 60
                al_set_clipping_rectangle(int(x1), int(y1), int(x2 - x1), int(y2 - y1))
                
            render_block(already, viewport)

        if not debug.no_mask and need_mask:
            # Write only color (no depth), but only where there is no mask.
            al_set_render_state(ALLEGRO_DEPTH_FUNCTION, ALLEGRO_RENDER_LESS)
            al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_RGBA)

        #x1, y1, x2, y2 = b.get_bounding_rect(viewport)

        render_block(b, viewport)

        #if not debug.no_mask and need_mask:
        #    render_block(b, viewport)
        #c = al_map_rgb_f(1, 0, 0)
        #al_draw_line(x1 + 2, y1 + 2, x2 - 2, y1 + 2, c, 1)
        #al_draw_line(x1 + 2, y1 + 2, x1 + 2, y2 - 2, c, 1)

        if not debug.no_mask and need_mask:
            # Restore everything to how it was before this block was drawn.
            al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_DEPTH | ALLEGRO_MASK_RGBA)
            al_clear_depth_buffer(1);

            al_set_render_state(ALLEGRO_DEPTH_TEST, False)
            al_reset_clipping_rectangle();

    for b in blocks.transparent:
        render_block(b, viewport)

    blocks.rebuild_static_cache = False
    blocks.rebuild_dynamic_cache = False

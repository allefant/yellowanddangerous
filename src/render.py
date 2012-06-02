import array, random, glob
from math import *
from land import *
import block, debug, main, level

class Render:
    was_setup = False
    @staticmethod
    def setup():
        if Render.was_setup: return
        Render.was_setup = True

        land_render_state(LAND_ALPHA_TEST, True)
        land_render_state(LAND_ALPHA_FUNCTION, LAND_GREATER)
        land_render_state(LAND_ALPHA_VALUE, 0)
        
        Render.background_color = 1, 1, 1, 1

        path = main.data_path + b"/data/yellowanddangerous/"

        def load(name, x, y, z, dynamic = False, lift = False, transparent = False):
            frames = glob.glob(path + (name + "/*.png").encode("utf8"))
            if not frames:
                print("Could not find " + path + name)
            bt = None
            for s in sorted(frames):
                pic = land_image_load(s)
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
                        bt.x = -land_image_width(pic) / 2
                        bt.y = -land_image_height(pic) / 2
                        setattr(Render, name, bt)
                    bt.bitmaps.append(pic)

        def loads(name):
            fpath = main.data_path + ("/data/" + name + ".ogg").encode("utf8")
            s = land_sound_load(fpath)
            if not s:
                print("Could not load " + fpath)
            else:
                setattr(Render, name.replace(" ", "_"), s)

        Render.font = land_font_load(main.data_path + b"/data/Muli-Regular.ttf", 24)
        land_clear(1, 1, 1, 1)
        land_text_pos(480, 300)
        land_font_set(Render.font)
        land_color(0, 0, 0, 1)
        land_print_center(b"%s", "Loading! Please Wait!".encode("utf8"))
        land_flip()

        Render.music = land_stream_new(2048, 4, 48000, 16, 2)
        land_stream_music(Render.music, main.data_path + b"/data/katyusha.ogg")
        land_stream_volume(Render.music, 0.75)

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

    w = land_display_width()
    h = land_display_height()
    fh = land_font_height(r.font)

    land_clear_depth(1)
    land_clear(*r.background_color)

    render_blocks(g.blocks, g.viewport)

    land_color(0, 0, 0, 1)
    land_font_set(Render.font)

    if g.level == 13:
        
        land_text_pos(0, 0)
        land_print(b"%s",
            "Congratulations! I'm surprised someone made it here :)".encode("utf8"))
    else:
        land_color(0, 0, 0, 1)
        land_text_pos(0, 0)
        land_print(b"%s",
            "Level {}/12".format(g.level).encode("utf8"))

    if g.ticks < 300:
        
        land_text_pos(720, fh)
        land_print_center(b"%s", "Yellow and Dangerous".encode("utf8"))
        land_print_center(b"%s", "by Allefant".encode("utf8"))

    y = 600 - 3 * fh
    for hint in getattr(level, "hint{}".format(g.level)).splitlines():
       
        land_text_pos(0, y)
        land_print(b"%s", hint.encode("utf8"))
        y += fh
    
def render_block(self, viewport):
    bt = self.block_type
    x, y = viewport.project(
        self.x + self.xs / 2,
        self.y + self.ys / 2,
        self.z + self.zs / 2)
    x += bt.x
    y += bt.y
    land_image_draw(self.block_type.bitmaps[self.frame], x, y)

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

        land_color(0, 0, 0, 1)
        land_line(v[0][0], v[0][1], v[1][0], v[1][1])
        land_line(v[1][0], v[1][1], v[4][0], v[4][1])
        land_line(v[4][0], v[4][1], v[5][0], v[5][1])
        land_line(v[5][0], v[5][1], v[6][0], v[6][1])
        land_line(v[6][0], v[6][1], v[3][0], v[3][1])
        land_line(v[3][0], v[3][1], v[0][0], v[0][1])

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

                land_render_state(LAND_DEPTH_TEST, True)
                land_render_state(LAND_DEPTH_FUNCTION, LAND_ALWAYS)
                land_render_state(LAND_WRITE_MASK, LAND_DEPTH_MASK)

                x1, y1, x2, y2 = b.get_bounding_rect(viewport)
                x1 -= 30
                y1 -= 30
                x2 += 60
                y2 += 60
                land_clip(int(x1), int(y1), int(x2) + 1, int(y2) + 1)
                
            render_block(already, viewport)

        if not debug.no_mask and need_mask:
            # Write only color (no depth), but only where there is no mask.
            land_render_state(LAND_DEPTH_FUNCTION, LAND_LESS)
            land_render_state(LAND_WRITE_MASK, LAND_RGBA_MASK)

        #x1, y1, x2, y2 = b.get_bounding_rect(viewport)

        render_block(b, viewport)

        #if not debug.no_mask and need_mask:
        #    render_block(b, viewport)
        #c = al_map_rgb_f(1, 0, 0)
        #al_draw_line(x1 + 2, y1 + 2, x2 - 2, y1 + 2, c, 1)
        #al_draw_line(x1 + 2, y1 + 2, x1 + 2, y2 - 2, c, 1)

        if not debug.no_mask and need_mask:
            # Restore everything to how it was before this block was drawn.
            land_render_state(LAND_WRITE_MASK, LAND_DEPTH_MASK | LAND_RGBA_MASK)
            land_clear_depth(1)

            land_render_state(LAND_DEPTH_TEST, False)
            land_unclip()

    for b in blocks.transparent:
        render_block(b, viewport)

    blocks.rebuild_static_cache = False
    blocks.rebuild_dynamic_cache = False

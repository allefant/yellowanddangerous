import common
import block
import game

type Game *game

class Overview:
    LandImage *screenshot[50]
    float mx, my

def overview_new -> Overview *:
    All *a = global_a
    Overview *self; land_alloc(self)

    a.overview = False
    game.sequence = True
    intro_tint = land_color_rgba(1, 1, 1, 1)
    intro_back = land_color_rgba(0, 0, 0, 0)
    a.render_screenshot = True
    
    for int i in range(1, 50):
        char name[1024]
        sprintf(name, "data/levels/level%02d.txt", i)
        LandBuffer *f = land_buffer_read_from_file(name)
        if f:
            Blocks *blocks = game.blocks
            blocks_reset(blocks)
            save_load_from_offset(f, 0, 0, 0)

            render(game)

            int w = land_display_width()
            int h = land_display_height()
            LandImage *s = land_image_new(w, h)
            land_image_grab(s, 0, 0)
            self.screenshot[i] = land_image_new(w / 4, h / 4)
            land_set_image_display(self.screenshot[i])
            land_image_draw_scaled(s, 0, 0, 0.25, 0.25)
            land_unset_image_display()
            land_image_destroy(s)
            land_image_center(self.screenshot[i])

    game.sequence = False
    a.render_screenshot = False
    
    return self

def overview_destroy(Overview *self):
    for int i in range(1, 50):
        land_image_destroy(self.screenshot[i])
    land_free(self)

def overview_render(Overview *self):
    float zoom = game.viewport->zoom
    land_reset_transform()
    land_scale(zoom, zoom)
    
    float w = 960
    for int i in range(1, 50):
        int x, z
        game_level_number_to_xz(i, &x, &z)
        float sx, sy
        project(game.viewport, (x - 3) * 128, 0, (z - 3) * 128, &sx, &sy)

        int j = i
        if i == game.swap_level:
            j = game.level
        elif i == game.level:
            if game.swap_level:
                j = game.swap_level
                sx = self.mx * 960 / w
                sy = self.my * 960 / w
        
        float iw = land_image_width(self.screenshot[j])
        land_image_draw_scaled(self.screenshot[j], sx, sy,
            w / 9 / iw, w / 9 / iw)

        if i == game.level:
            land_premul(1, 0, 0, 0.5)
           
            float s = w / 18
            float xy[8] = {sx, sy - s / 2, sx + s, sy, sx, sy + s / 2,
                sx - s, sy}
            land_filled_polygon(4, xy)

def overview_click(Overview *self, float sx, sy, int clicked, released):
    float x, y
    unproject(game.viewport, sx, sy, &x, &y)
    int ix = floor(x / 128 + 3.5)
    int iy = floor(y / 128 + 3.5)
    if ix >= 0 and iy >= 0 and ix < 7 and iy < 7:
        game.level = 1 + ix + iy * 7
        self.mx = sx
        self.my = sy
        if clicked:
            game.swap_level = game.level
        elif released:
            overview_swap_levels(self, game.level, game.swap_level)
    if released:
        game.swap_level = 0

def overview_swap_levels(Overview *self, int level1, level2):
    if not level1 or not level2:
        return
    if level1 == level2:
        return

    # 2 -> 0
    game.level = level2
    load_level(True)
    game.level = 0
    save_level(True)
    self.screenshot[0] = self.screenshot[level2]

    # 1 -> 2
    game.level = level1
    load_level(True)
    game.level = level2
    save_level(True)
    self.screenshot[level2] = self.screenshot[level1]

    # 0 -> 1
    game.level = 0
    load_level(True)
    game.level = level1
    save_level(True)
    self.screenshot[level1] = self.screenshot[0]
    

import common
import block
import game

type Game *game

class Overview:
    LandImage *screenshot[50]
    bool update[50]
    float mx, my
    int selected

    int zoom
    double zoomx, zoomy

def overview_new -> Overview *:
    Overview *self; land_alloc(self)

    self.zoom = 0

    for int i in range(1, 50):
        self.update[i] = True

    return self

def overview_update(Overview *self):
    All *a = global_a
    self.selected = game.level
    a.overview = True
    self.zoom = 0
    self.zoomx = 0
    self.zoomy = 0

def overview_tick(Overview *self):
    All *a = global_a
    for int i_ in range(49):
        int i = game.level + i_
        if i > 49:
            i -= 49
        if not self.update[i]:
            continue
        if self.screenshot[i]:
            land_image_destroy(self.screenshot[i])
            self.screenshot[i] = None
        self.update[i] = False
        game.level = i
        a.load_after_redraw = 1
        break

    int x, z
    game_level_number_to_xz(self.selected, &x, &z)
    float sx, sy
    project(game.viewport, (x - 3) * 128, 0, (z - 3) * 128, &sx, &sy)
    float zoom = game.viewport->zoom * pow(2, self.zoom / 10.0)
    float ax = sx * zoom + self.zoomx
    float ay = sy * zoom + self.zoomy
    
    game.overview->zoom += land_mouse_delta_z()
    if game.overview->zoom < 0:
        game.overview->zoom = 0
    if game.overview->zoom > 30:
        game.overview->zoom = 30

    zoom = game.viewport->zoom * pow(2, self.zoom / 10.0)
    self.zoomx = ax - sx * zoom
    self.zoomy = ay - sy * zoom

def overview_render_next(Overview *self):
    if self.screenshot[game.level]:
        return
    All *a = global_a

    game.sequence = True

    intro_tint = land_color_rgba(1, 1, 1, 1)
    intro_back = land_color_rgba(0, 0, 0, 0)
    a.render_screenshot = True

    int w = land_display_width()
    int h = land_display_height()
    self.screenshot[game.level] = land_image_new(w / 4, h / 4)
    land_set_image_display(self.screenshot[game.level])

    Viewport *backup = game.viewport
    Viewport ovp
    game.viewport = &ovp
    viewport_update(game.viewport, w / 4, h / 4)
    a.overview = False
    render(game, w / 4, h / 4)
    a.overview = True
    game.viewport = backup
    
    land_unset_image_display()

    land_image_center(self.screenshot[game.level])

    game.sequence = False
    a.render_screenshot = False

def overview_update_level(Overview *self, int level):
    self.update[level] = True

def overview_destroy(Overview *self):
    for int i in range(1, 50):
        land_image_destroy(self.screenshot[i])
    land_free(self)

def overview_render(Overview *self):
    land_clear(1, 1, 1, 1)
    float zoom = game.viewport->zoom * pow(2, self.zoom / 10.0)
    land_reset_transform()
    land_translate(self.zoomx, self.zoomy)
    land_scale(zoom, zoom)
    
    float w = 960
    for int i in range(1, 50):
        int x, z
        game_level_number_to_xz(i, &x, &z)
        float sx, sy
        project(game.viewport, (x - 3) * 128, 0, (z - 3) * 128, &sx, &sy)

        int j = i
        if i == game.swap_level:
            j = self.selected
        elif i == self.selected:
            if game.swap_level:
                j = game.swap_level
                sx = self.mx
                sy = self.my

        if self.screenshot[j]:
            float iw = land_image_width(self.screenshot[j])
            land_image_draw_scaled(self.screenshot[j], sx, sy,
                w / 9 / iw, w / 9 / iw)

        if i == self.selected:
            land_premul(1, 0, 0, 0.5)
           
            float s = w / 18
            sy += 5 # the floor is not centered, so add a slight offset
            float xy[8] = {sx, sy - s / 2, sx + s, sy, sx, sy + s / 2,
                sx - s, sy}
            land_filled_polygon(4, xy)

def overview_click(Overview *self, float sx, sy, int clicked, released):
    float x, y
    sx -= self.zoomx
    sy -= self.zoomy
    float zoom = game.viewport->zoom * pow(2, self.zoom / 10.0)
    sx /= zoom
    sy /= zoom
    unproject(game.viewport, sx, sy, 0, &x, &y)
    int ix = floor(x / 128 + 3.5)
    int iy = floor(y / 128 + 3.5)
    if ix >= 0 and iy >= 0 and ix < 7 and iy < 7:
        self.selected = 1 + ix + iy * 7
        self.mx = sx
        self.my = sy
        if clicked:
            game.swap_level = self.selected
        elif released:
            overview_swap_levels(self, self.selected, game.swap_level)
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
    

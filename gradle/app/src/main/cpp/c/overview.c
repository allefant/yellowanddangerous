/* This file was generated by scramble.py. */
#line 1 "src/overview.py"
#include "overview.h"
#line 14
Overview* overview_new(void) {
    Overview * self;
#line 15
    land_alloc(self);
#line 17
    self->zoom = 0;
#line 19
    for (int i = 1; i < 50; i += 1) {
        self->update [i] = 1;
    }
    return self;
}
void overview_update(Overview * self) {
    All * a = global_a;
    self->selected = game->level;
    a->overview = 1;
    self->zoom = 0;
    self->zoomx = 0;
    self->zoomy = 0;
}
void overview_tick(Overview * self) {
    All * a = global_a;
    for (int i_ = 0; i_ < 49; i_ += 1) {
        int i = game->level + i_;
        if (i > 49) {
            i -= 49;
        }
#line 38
        if (! self->update [i]) {
            continue;
        }
#line 40
        if (self->screenshot [i]) {
            land_image_destroy(self->screenshot [i]);
            self->screenshot [i] = NULL;
        }
#line 43
        self->update [i] = 0;
        game->level = i;
        a->load_after_redraw = 1;
        break;
    }
    int x, z;
    game_level_number_to_xz(self->selected, & x, & z);
    float sx, sy;
    project(game->viewport, (x - 3) * 128, 0, (z - 3) * 128, & sx, & sy);
    float zoom = game->viewport->zoom * pow(2, self->zoom / 10.0);
    float ax = sx * zoom + self->zoomx;
    float ay = sy * zoom + self->zoomy;
#line 56
    game->overview->zoom += land_mouse_delta_z();
    if (game->overview->zoom < 0) {
        game->overview->zoom = 0;
    }
#line 59
    if (game->overview->zoom > 30) {
        game->overview->zoom = 30;
    }
    zoom = game->viewport->zoom * pow(2, self->zoom / 10.0);
    self->zoomx = ax - sx * zoom;
    self->zoomy = ay - sy * zoom;
}
void overview_render_next(Overview * self) {
    if (self->screenshot [game->level]) {
#line 67
        return ;
    }
    All * a = global_a;
#line 71
    game->sequence = 1;
#line 73
    intro_tint = land_color_rgba(1, 1, 1, 1);
    intro_back = land_color_rgba(0, 0, 0, 0);
    a->render_screenshot = 1;
#line 77
    int w = land_display_width();
    int h = land_display_height();
    self->screenshot [game->level] = land_image_new(w / 4, h / 4);
    land_set_image_display(self->screenshot [game->level]);
#line 82
    Viewport * backup = game->viewport;
    Viewport ovp;
    game->viewport = & ovp;
    viewport_update(game->viewport, w / 4, h / 4);
    a->overview = 0;
    render(game, w / 4, h / 4);
    a->overview = 1;
    game->viewport = backup;
#line 91
    land_unset_image_display();
#line 93
    land_image_center(self->screenshot [game->level]);
#line 95
    game->sequence = 0;
    a->render_screenshot = 0;
}
void overview_update_level(Overview * self, int level) {
    self->update [level] = 1;
}
void overview_destroy(Overview * self) {
    for (int i = 1; i < 50; i += 1) {
        land_image_destroy(self->screenshot [i]);
    }
#line 104
    land_free(self);
}
void overview_render(Overview * self) {
    land_clear(1, 1, 1, 1);
    float zoom = game->viewport->zoom * pow(2, self->zoom / 10.0);
    land_reset_transform();
    land_translate(self->zoomx, self->zoomy);
    land_scale(zoom, zoom);
#line 113
    float w = 960;
    for (int i = 1; i < 50; i += 1) {
        int x, z;
        game_level_number_to_xz(i, & x, & z);
        float sx, sy;
        project(game->viewport, (x - 3) * 128, 0, (z - 3) * 128, & sx, & sy);
#line 120
        int j = i;
        if (i == game->swap_level) {
            j = self->selected;
        }
#line 123
        else if (i == self->selected) {
            if (game->swap_level) {
                j = game->swap_level;
                sx = self->mx;
                sy = self->my;
            }
        }
#line 129
        if (self->screenshot [j]) {
            float iw = land_image_width(self->screenshot [j]);
#line 132
            land_image_draw_scaled(self->screenshot [j], sx, sy, w / 9 / iw, w / 9 / iw);
        }
        if (i == self->selected) {
            land_premul(1, 0, 0, 0.5);
#line 137
            float s = w / 18;
            sy += 5 /* the floor is not centered, so add a slight offset */;
#line 140
            float xy [8] = {sx, sy - s / 2, sx + s, sy, sx, sy + s / 2, sx - s, sy};
            land_filled_polygon(4, xy);
        }
    }
}
#line 143
void overview_click(Overview * self, float sx, float sy, int clicked, int released) {
    float x, y;
    sx -= self->zoomx;
    sy -= self->zoomy;
    float zoom = game->viewport->zoom * pow(2, self->zoom / 10.0);
    sx /= zoom;
    sy /= zoom;
    unproject(game->viewport, sx, sy, 0, & x, & y);
    int ix = floor(x / 128 + 3.5);
    int iy = floor(y / 128 + 3.5);
    if (ix >= 0 && iy >= 0 && ix < 7 && iy < 7) {
        self->selected = 1 + ix + iy * 7;
        self->mx = sx;
        self->my = sy;
        if (clicked) {
            game->swap_level = self->selected;
        }
#line 159
        else if (released) {
            overview_swap_levels(self, self->selected, game->swap_level);
        }
    }
#line 161
    if (released) {
        game->swap_level = 0;
    }
}
#line 164
void overview_swap_levels(Overview * self, int level1, int level2) {
    if (! level1 || ! level2) {
#line 165
        return ;
    }
    if (level1 == level2) {
#line 167
        return ;
    }
    // 2 -> 0
#line 171
    game->level = level2;
    load_level(1, 0);
    game->level = 0;
    save_level(1, 0);
    self->screenshot [0] = self->screenshot [level2];
    // 1 -> 2
#line 178
    game->level = level1;
    load_level(1, 0);
    game->level = level2;
    save_level(1, 0);
    self->screenshot [level2] = self->screenshot [level1];
    // 0 -> 1
#line 185
    game->level = 0;
    load_level(1, 0);
    game->level = level1;
    save_level(1, 0);
    self->screenshot [level1] = self->screenshot [0];
}
/* This file was generated by scramble.py. */

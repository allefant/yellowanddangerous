/* This file was generated by scramble.py. */
#line 1 "src/game.py"
#include "game.h"
#line 53
Game * game;
int game_starting_level = 22;
#line 56
void game_setup(float w, float h) {
    Game * self;
#line 57
    land_alloc(self);
    self->viewport = viewport_new(w, h);
#line 60
    self->level = 0;
#line 62
    self->blocks = blocks_new();
#line 64
    self->menu = menu_new();
#line 66
    self->overview = overview_new();
#line 68
    self->record = record_new();
#line 70
    editor_new();
#line 72
    game = self;
}
void game_del(Game * self) {
    blocks_destroy(self->blocks);
    render_teardown();
    overview_destroy(game->overview);
    record_destroy(self->record);
    land_free(self->viewport);
    land_free(self->menu);
    land_free(self);
#line 83
    editor_del();
}
int game_neighboring_level(int level, int gox, int goz) {
    int row = (level - 1) / 7;
    int col = (level - 1) % 7;
    col += gox + 7;
    row += goz + 7;
    col %= 7;
    row %= 7;
    level = 1 + row * 7 + col;
    return level;
}
void game_level_number_to_xz(int level, int * x, int * z) {
    * z = (level - 1) / 7;
    * x = (level - 1) % 7;
}
void game_level_done(Game * self, int gox, int goz) {
    if (land_equals(self->state, "play")) {
        record_done(self->record);
        if (! global_a->test) {
            save_level(0);
        }
#line 104
        self->state = "done";
        self->state_tick = self->ticks;
        self->gox = gox;
        self->goz = goz;
        if (self->player) {
            self->ex = self->player->super.x;
            self->ez = self->player->super.z;
        }
#line 111
        self->level = game_neighboring_level(self->level, gox, goz);
        sound(Render_teleport, 1);
    }
}
#line 114
void game_recalc(void) {
    game->blocks->rebuild_static_cache = 1;
    game->blocks->rebuild_dynamic_cache = 1;
}
void game_key(Game * self, int k) {
    menu_key(k, land_key(LandKeyLeftShift) || land_key(LandKeyRightShift));
}
void game_tick(Game * self) {
    All * a = global_a;
#line 124
    if (land_equals(self->state, "done") || land_equals(self->state, "died")) {
        if (self->ticks > self->state_tick + 30) {
            a->load_after_redraw = 1;
            a->find_entrance = 1;
            play_song();
        }
    }
#line 130
    if (a->load_after_redraw) {
#line 130
        return ;
    }
#line 133
    input_tick();
#line 135
    if (a->overview) {
        overview_tick(game->overview);
#line 136
        return ;
    }
#line 139
    if (a->show_map) {
        if (land_key_pressed(LandKeyBack)) {
            a->show_map = 0;
        }
#line 141
        return ;
    }
#line 144
    int plates_count = 0;
    int plates_on_before = 0;
#line 147
    if (self->player) {
        if (land_equals(self->state, "play")) {
            if (self->player->dead || self->player->super.y < - 960) {
                sound(Render_oh_no, 1);
                self->state = "died";
                game->deaths++;
                record_done(self->record);
#line 156
                event("join_group group_id=died_x%.0f_y%.0f_z%.0f", self->player->super.x, self->player->super.y, self->player->super.z);
            }
        }
    }
#line 158
    {
#line 158
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->blocks->fixed);
#line 158
        for (Block * b = LandArrayIterator_item(self->blocks->fixed, &__iter0__); LandArrayIterator_next(self->blocks->fixed, &__iter0__); b = LandArrayIterator_item(self->blocks->fixed, &__iter0__)) {
            if (b->block_type == Render_Plate) {
                if (b->frame == 1) {
                    plates_on_before += 1;
                }
#line 162
                b->frame = 0;
                plates_count += 1;
            }
        }
    }
#line 165
    if (land_key_pressed(LandKeyBack)) {
        main_switch_to_title(0);
    }
    if (land_key_pressed(LandKeyMenu)) {
        main_switch_to_title(1);
    }
    if (game->sequence) {
        intro_sequence();
    }
    if (! a->editor) {
        record_tick(game->record);
        a->time++;
        {
#line 177
            LandArrayIterator __iter0__ = LandArrayIterator_first(self->blocks->animated);
#line 177
            for (Block * b = LandArrayIterator_item(self->blocks->animated, &__iter0__); LandArrayIterator_next(self->blocks->animated, &__iter0__); b = LandArrayIterator_item(self->blocks->animated, &__iter0__)) {
                b->block_type->tick(b);
            }
        }
#line 180
        int plates_on = 0;
        {
#line 181
            LandArrayIterator __iter0__ = LandArrayIterator_first(self->blocks->fixed);
#line 181
            for (Block * b = LandArrayIterator_item(self->blocks->fixed, &__iter0__); LandArrayIterator_next(self->blocks->fixed, &__iter0__); b = LandArrayIterator_item(self->blocks->fixed, &__iter0__)) {
                if (b->block_type == Render_Plate) {
                    if (b->frame == 1) {
                        plates_on += 1;
                    }
                }
#line 185
                else if (b->block_type == Render_ExitLeft || b->block_type == Render_ExitRight) {
                    if (b->frame == 1) {
                        b->frame = 0;
                    }
                }
            }
        }
#line 189
        if (plates_on > plates_on_before) {
            sound(Render_on, 1);
        }
        if (plates_on < plates_on_before) {
            sound(Render_off, 1);
        }
        if (plates_count == plates_on) {
            {
#line 196
                LandArrayIterator __iter0__ = LandArrayIterator_first(self->blocks->fixed);
#line 196
                for (Block * b = LandArrayIterator_item(self->blocks->fixed, &__iter0__); LandArrayIterator_next(self->blocks->fixed, &__iter0__); b = LandArrayIterator_item(self->blocks->fixed, &__iter0__)) {
                    if (b->block_type == Render_ExitLeft || b->block_type == Render_ExitRight) {
                        if (b->frame == 0) {
                            b->frame = 1;
                        }
                    }
                }
            }
        }
    }
#line 201
    self->ticks += 1;
}
/* This file was generated by scramble.py. */
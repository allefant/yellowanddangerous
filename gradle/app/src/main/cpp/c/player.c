/* This file was generated by scramble.py. */
#line 1 "src/player.py"
#include "player.h"
#line 21
Block* player_allocate(void) {
    Player * self;
    land_alloc(self);
    return & self->super;
}
void player_init(Block * super) {
    Player * self = (void *) super;
    self->step = 0;
    self->direction = 0;
    self->want_direction = 0;
    self->rotstep = 0;
    self->pull = 0;
    self->reverse = 0;
    self->stack = land_array_new();
    self->pushing = 0;
    self->dead = 0;
    game->player = self;
}
void player_destroy(Block * super) {
    game->player = NULL;
    Player * self = (void *) super;
    land_array_destroy(self->stack);
    block_destroy(super);
}
void player_try_pull(Player * self, float px, float pz) {
    float ox = self->super.x;
    float oz = self->super.z;
#line 49
    self->super.x -= px * 3 * sqrt(2);
    self->super.z -= pz * 3 * sqrt(2);
    LandArray * pulls = block_colliders((void *) self);
    self->super.x = ox;
    self->super.z = oz;
#line 55
    int tag = block_recursion_tag();
    {
#line 56
        LandArrayIterator __iter0__ = LandArrayIterator_first(pulls);
#line 56
        for (Block * p = LandArrayIterator_item(pulls, &__iter0__); LandArrayIterator_next(pulls, &__iter0__); p = LandArrayIterator_item(pulls, &__iter0__)) {
            if (! p->block_type->dynamic) {
#line 57
                continue;
            }
#line 58
            if (p->block_type->fixed) {
#line 58
                continue;
            }
#line 59
            p->recursion_prevention = tag;
            if (block_pull(p, px, 0, pz)) {
                self->super.dx = 0;
                self->super.dz = 0;
                self->pushing = 1;
            }
        }
    }
#line 65
    land_array_destroy(pulls);
}
void player_grab(Player * self) {
    float ox = self->super.x;
    float oz = self->super.z;
#line 71
    float px = sin((self->want_direction + 1) * pi / 4);
    float pz = cos((self->want_direction + 1) * pi / 4);
#line 74
    self->super.x += px * 3 * sqrt(2);
    self->super.z += pz * 3 * sqrt(2);
    LandArray * grabs = block_colliders(& self->super);
#line 78
    self->super.x = ox;
    self->super.z = oz;
#line 81
    land_array_clear(self->stack);
#line 83
    float max_y = - 9000;
    {
#line 84
        LandArrayIterator __iter0__ = LandArrayIterator_first(grabs);
#line 84
        for (Block * b = LandArrayIterator_item(grabs, &__iter0__); LandArrayIterator_next(grabs, &__iter0__); b = LandArrayIterator_item(grabs, &__iter0__)) {
            if (! b->block_type->lift) {
#line 85
                continue;
            }
#line 86
            if (b->y >= max_y) {
#line 86
                max_y = b->y;
            }
        }
    }
#line 88
    {
#line 88
        LandArrayIterator __iter0__ = LandArrayIterator_first(grabs);
#line 88
        for (Block * b = LandArrayIterator_item(grabs, &__iter0__); LandArrayIterator_next(grabs, &__iter0__); b = LandArrayIterator_item(grabs, &__iter0__)) {
            if (! b->block_type->lift) {
#line 89
                continue;
            }
#line 90
            if (b->y == max_y) {
                land_array_add(self->stack, b);
            }
        }
    }
#line 93
    land_array_destroy(grabs);
}
void player_lift(Player * self) {
    block_recursion_tag();
#line 98
    {
#line 98
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->stack);
#line 98
        for (Block * p = LandArrayIterator_item(self->stack, &__iter0__); LandArrayIterator_next(self->stack, &__iter0__); p = LandArrayIterator_item(self->stack, &__iter0__)) {
            // don't want to be able to walk under it
#line 101
            if (p->y + 1 < self->super.y + self->super.ys) {
                if (block_pull(p, 0, 1, 0)) {
                    p->no_fall = 1;
                    p->dy = 0;
                }
            }
        }
    }
}
#line 106
void player_tick(Block * super) {
#line 108
    Player * self = (void *) super;
#line 110
    All * a = global_a;
#line 112
    float x = 0;
    float z = 0;
    if (a->up) {
#line 114
        x -= 1;
#line 114
        z -= 1;
    }
#line 115
    if (a->down) {
#line 115
        x += 1;
#line 115
        z += 1;
    }
#line 116
    if (a->left) {
#line 116
        x -= 1;
#line 116
        z += 1;
    }
#line 117
    if (a->right) {
#line 117
        x += 1;
#line 117
        z -= 1;
    }
    bool push_animation = 0;
    // slow down jump stronger if only tapping
#line 122
    if (! a->jump && self->super.dy > 0) {
        self->super.dy *= 0.5;
    }
    float d = pow(x * x + z * z, 0.5);
    if (d > 0 && ! land_array_count(self->stack)) {
#line 128
        x /= d;
        z /= d;
        double angle = atan2(x, z) - pi / 4;
        angle = angle / (2 * pi);
        angle = (int)((angle - floor(angle)) * 8 + 0.5) & 7;
#line 134
        self->want_direction = angle;
#line 136
        if ((super->ground || (a->godmode && self->super.dy < 5)) && a->jump) {
            if (self->pull) {
                if (! self->reverse) {
                    player_grab(self);
                    if (land_array_count(self->stack)) {
                        x = z = 0;
                        self->super.dx = 0;
                        self->super.dz = 0;
                        self->pull = 0;
                    }
#line 144
                    else {
#line 146
                        self->reverse = 1;
                    }
                }
#line 148
                if (self->reverse) {
                    self->want_direction += 4;
                    self->want_direction &= 7;
                }
            }
#line 152
            else if (a->jump) {
                self->super.dy += 30;
                sound(Render_uhg, 1);
            }
        }
#line 156
        x *= 2.8;
        z *= 2.8;
#line 159
        super->dx += x;
        super->dz += z;
#line 162
        self->step += 1;
        self->step &= 31;
#line 165
        if (self->step == 9 || self->step == 25) {
            if (self->super.ground) {
                if (self->metal) {
#line 167
                    sound(Render_metal, 0.3);
                }
#line 167
                else {
                    sound(Render_step, 0.3);
                }
            }
        }
    }
#line 168
    else {
#line 171
        if (self->step != 8 && self->step != 24) {
            self->step += 1;
            self->step &= 31;
        }
#line 173
        else {
#line 175
            self->lever = 0;
        }
        if (super->ground && a->jump) {
            self->pull = 1;
        }
    }
#line 180
    if (self->pushing) {
        if (game->ticks % 8 == 1) {
            sound(Render_push, 0.3);
            self->pushing = 0;
        }
    }
#line 185
    if (self->want_direction != self->direction) {
        self->rotstep += 1;
        if (self->rotstep >= 4) {
            self->rotstep = 0;
            d = self->want_direction - self->direction;
#line 191
            if (d < - 4) {
#line 191
                d += 8;
            }
#line 192
            else if (d > 4) {
#line 192
                d -= 8;
            }
#line 193
            if (abs(d) == 4) {
#line 193
                self->direction += (land_rand(0, 1)) * 2 - 1;
            }
#line 194
            else if (d < 0) {
#line 194
                self->direction -= 1;
            }
#line 195
            else if (d > 0) {
#line 195
                self->direction += 1;
            }
#line 196
            self->direction &= 7;
        }
    }
#line 198
    super->frame = self->direction * 8 + self->step / 4;
#line 200
    float px = super->dx;
    float pz = super->dz;
#line 203
    if (super->pushed_something) {
        super->pushed_something = 0;
        super->dx *= 0.7;
        super->dz *= 0.7;
        push_animation = 1;
    }
    block_tick(super);
#line 211
    if (self->pull) {
        if (! a->jump) {
            self->pull = 0;
            self->reverse = 0;
        }
        if (px || pz) {
            player_try_pull(self, px, pz);
            push_animation = 1;
        }
    }
#line 220
    if (land_array_count(self->stack)) {
        if (! a->jump) {
            while (land_array_count(self->stack)) {
                Block * b = land_array_pop(self->stack);
                b->no_fall = 0;
            }
        }
#line 224
        else {
#line 226
            player_lift(self);
            push_animation = 1;
        }
    }
#line 229
    if (! super->ground && a->jump) {
        push_animation = 1;
    }
    if (push_animation) {
        super->frame += 64;
    }
}
#line 235
void player_touch(Block * super, Block * c, float dx, float dy, float dz) {
    All * a = global_a;
    Player * self = (void *) super;
    cube_touch(super, c, dx, dy, dz);
    if (c->block_type == Render_Gremlin) {
        Gremlin * gremlin = (void *) c;
        if (! gremlin->respect) {
            self->dead = 1;
        }
    }
#line 243
    int flower = 0;
    if (c->block_type == Render_Car) {
        if (game->key && game->sequence == 0) {
            LandArray * cs = block_colliders(c);
            int n = land_array_count(cs);
            land_array_destroy(cs);
            if (n == 0) {
                sound(Render_ignition, .5);
                game->sequence = 2;
                game->sequence_ticks = 0;
            }
        }
    }
#line 253
    if (c->block_type == Render_Gentian) {
        flower = 1;
    }
#line 255
    if (c->block_type == Render_Edelweiss) {
        flower = 2;
    }
#line 257
    if (c->block_type == Render_Orchid) {
        flower = 3;
    }
#line 259
    if (c->block_type == Render_Hyacinth) {
        flower = 4;
    }
#line 261
    if (c->block_type == Render_Sunflower) {
        flower = 5;
    }
#line 263
    if (c->block_type == Render_Rose) {
        flower = 6;
    }
#line 265
    if (c->block_type == Render_Belladonna) {
        flower = 7;
    }
#line 267
    if (c->block_type == Render_TestTube) {
        if (! game->test_tube [c->frame + 1]) {
            game->test_tube [c->frame + 1] = 1;
            sound(Render_on, 1);
            c->y = - 9000;
        }
    }
#line 272
    if (flower) {
        c->y = - 9000;
        game->flower [flower] = 1;
        sound(Render_pickup, 1);
    }
#line 276
    if (c->block_type == Render_Key) {
        c->y = - 9000;
        game->key = 1;
        sound(Render_pickup, 1);
    }
#line 280
    if (dy < 0) {
        bool always = a->godmode || game->record->wait_on_level;
        if (c->block_type == Render_ExitLeft && c->frame != 4) {
            if (c->frame == 1 || c->frame == 2 || always) {
                if (block_center_overlaps(super, c)) {
                    game_level_done(game, c->x > 0 ? 1 : - 1, 0);
                }
            }
        }
#line 286
        else if (c->block_type == Render_ExitRight && c->frame != 4) {
            if (c->frame == 1 || c->frame == 2 || always) {
                if (block_center_overlaps(super, c)) {
                    game_level_done(game, 0, c->z > 0 ? 1 : - 1);
                }
            }
        }
#line 290
        if (c->block_type == Render_GrateBottom || c->block_type == Render_Cart) {
            self->metal = 1;
        }
#line 291
        else {
#line 293
            self->metal = 0;
        }
    }
#line 294
    if (! self->lever) {
        if (dx < 0 && c->block_type == Render_LeverLeft) {
            if (c->frame == 0) {
                self->lever = 1;
                c->frame = 1;
                game->lever = c;
            }
        }
#line 300
        if (dz < 0 && c->block_type == Render_LeverRight) {
            if (c->frame == 0) {
                self->lever = 1;
                c->frame = 1;
                game->lever = c;
            }
        }
    }
#line 305
    if (dx != 0 || dz != 0) {
        if (c->block_type->dynamic) {
            self->pushing = 1;
        }
    }
}
#line 309
void player_find_entrance(Block * super) {
    int mind = 0;
    Block * e = NULL;
    {
#line 312
        LandArrayIterator __iter0__ = LandArrayIterator_first(super->blocks->fixed);
#line 312
        for (Block * b = LandArrayIterator_item(super->blocks->fixed, &__iter0__); LandArrayIterator_next(super->blocks->fixed, &__iter0__); b = LandArrayIterator_item(super->blocks->fixed, &__iter0__)) {
            if (game->gox && b->block_type == Render_ExitLeft) {
                if (game->gox * b->x < 0) {
                    int d = fabs(game->ez - b->z);
                    if (e == NULL || d < mind) {
                        mind = d;
                        e = b;
                    }
                }
            }
#line 319
            if (game->goz && b->block_type == Render_ExitRight) {
                if (game->goz * b->z < 0) {
                    int d = fabs(game->ex - b->x);
                    if (e == NULL || d < mind) {
                        mind = d;
                        e = b;
                    }
                }
            }
        }
    }
#line 325
    if (e) {
        super->x = e->x + e->xs / 2 + game->gox * (e->xs / 2 + super->xs / 2) - super->xs / 2;
        super->y = e->y + e->ys;
        super->z = e->z + e->zs / 2 + game->goz * (e->zs / 2 + super->zs / 2) - super->zs / 2;
        if (e->frame == 3) {
            e->frame = 2;
        }
    }
#line 332
    LandArray * a = block_colliders(super);
    {
#line 333
        LandArrayIterator __iter0__ = LandArrayIterator_first(a);
#line 333
        for (Block * c = LandArrayIterator_item(a, &__iter0__); LandArrayIterator_next(a, &__iter0__); c = LandArrayIterator_item(a, &__iter0__)) {
            if (super->y < c->y + c->ys) {
                super->y = c->y + c->ys;
            }
        }
    }
#line 337
    land_array_destroy(a);
}
/* This file was generated by scramble.py. */

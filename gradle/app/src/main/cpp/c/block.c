/* This file was generated by scramble.py. */
#line 1 "src/block.py"
#include "block.h"
#include "render.h"
#include "land/util2d.h"
static bool is_left(float * v, float xp, float yp, int i1, int i2);
static float sgn(float a, float x);
#line 15
void blocks_list_destroy(LandArray * (* list)) {
    if (* list) {
        {
#line 17
            LandArrayIterator __iter0__ = LandArrayIterator_first(* list);
#line 17
            for (Block * b = LandArrayIterator_item(* list, &__iter0__); LandArrayIterator_next(* list, &__iter0__); b = LandArrayIterator_item(* list, &__iter0__)) {
                b->block_type->destroy(b);
            }
        }
#line 19
        land_array_destroy(* list);
        * list = NULL;
    }
}
#line 22
void blocks_clear(Blocks * self) {
    blocks_list_destroy(& self->fixed);
    blocks_list_destroy(& self->dynamic);
    blocks_list_destroy(& self->transparent);
    if (self->animated) {
        land_array_destroy(self->animated);
        self->animated = NULL;
    }
}
#line 30
void blocks_reset(Blocks * self) {
    blocks_clear(self);
    self->fixed = land_array_new();
    self->dynamic = land_array_new();
    self->transparent = land_array_new();
    self->animated = land_array_new();
    self->rebuild_static_cache = 1;
    self->rebuild_dynamic_cache = 1;
}
Blocks* blocks_new(void) {
    Blocks * b;
#line 40
    land_alloc(b);
    return b;
}
void blocks_destroy(Blocks * self) {
    blocks_clear(self);
    land_free(self);
}
Block* blocks_pick(Blocks * self, float xp, float yp, Viewport * viewport) {
    Block * best = NULL;
    xp /= viewport->zoom;
    yp /= viewport->zoom;
    LandArray * arrays [] = {self->transparent, self->dynamic, self->fixed};
    for (int i = 0; i < 3; i += 1) {
        LandArray * array = arrays [i];
        {
#line 54
            LandArrayIterator __iter0__ = LandArrayIterator_first(array);
#line 54
            for (Block * block = LandArrayIterator_item(array, &__iter0__); LandArrayIterator_next(array, &__iter0__); block = LandArrayIterator_item(array, &__iter0__)) {
                int side = block_is_inside(block, xp, yp, viewport);
                if (side) {
                    if (best) {
                        if (block_sort_order(block, best, viewport) > 0) {
                            best = block;
                        }
                    }
#line 59
                    else {
#line 61
                        best = block;
                    }
                }
            }
        }
    }
#line 63
    return best;
}
static int tag = 0;
#line 85
void block_init(Block * self, Blocks * blocks, float x, float y, float z, BlockType * block_type) {
    self->blocks = blocks;
    self->x = x;
    self->y = y;
    self->z = z;
    self->block_type = block_type;
    if (block_type) {
        self->xs = block_type->xs;
        self->ys = block_type->ys;
        self->zs = block_type->zs;
    }
#line 95
    self->r = 1;
    self->g = 1;
    self->b = 1;
    self->a = 1;
    self->frame = 0;
    self->dx = 0;
    self->dy = 0;
    self->dz = 0;
    self->ground = 0;
    self->recursion_prevention = 0;
    self->no_fall = 0;
    self->cache = land_array_new();
}
Block* block_new(Blocks * blocks, float x, float y, float z, BlockType * block_type) {
    Block * self = block_type->allocate();
    block_init(self, blocks, x, y, z, block_type);
    self->block_type->post_init(self);
    return self;
}
void block_destroy(Block * self) {
    land_array_destroy(self->cache);
    land_free(self);
}
Block* block_allocate(void) {
    Block * self;
    land_alloc(self);
    return self;
}
void block_post_init(Block * self) {
#line 123
    return ;
}
#line 126
void block_add(Block * self) {
#line 128
    self->bid = 1 + land_array_count(self->blocks->fixed) + land_array_count(self->blocks->dynamic);
    if (self->block_type && self->block_type->dynamic) {
        land_array_add(self->blocks->dynamic, self);
    }
#line 131
    else if (self->block_type && self->block_type->transparent) {
        land_array_add(self->blocks->transparent, self);
    }
#line 132
    else {
#line 134
        land_array_add(self->blocks->fixed, self);
    }
    if (self->block_type && self->block_type->animated) {
        land_array_add(self->blocks->animated, self);
    }
}
#line 139
Block* block_change_type(Block * self, int d) {
    int n = land_array_count(block_types);
    int btid = self->block_type->btid + d;
    if (btid >= n) {
        btid -= n;
    }
#line 144
    if (btid < 0) {
        btid += n;
    }
#line 146
    BlockType * bt = land_array_get_nth(block_types, btid);
    Blocks * blocks = self->blocks;
    float x = self->x;
    float y = self->y;
    float z = self->z;
    block_del(self);
    self = block_new(blocks, x, y, z, bt);
    block_add(self);
    return self;
}
Block* block_change_type_to(Block * self, char const * text) {
    {
#line 157
        LandArrayIterator __iter0__ = LandArrayIterator_first(block_types);
#line 157
        for (BlockType * bt = LandArrayIterator_item(block_types, &__iter0__); LandArrayIterator_next(block_types, &__iter0__); bt = LandArrayIterator_item(block_types, &__iter0__)) {
            if (land_equals(bt->name, text)) {
                return block_change_type(self, bt->btid - self->block_type->btid);
            }
        }
    }
#line 160
    return self;
}
void block_del(Block * self) {
    LandArray * array;
    if (self->block_type && self->block_type->dynamic) {
        array = self->blocks->dynamic;
    }
#line 166
    else if (self->block_type && self->block_type->transparent) {
        array = self->blocks->transparent;
    }
#line 167
    else {
#line 169
        array = self->blocks->fixed;
    }
    int i = land_array_find(array, self);
    if (i < 0) {
#line 172
        return ;
    }
    land_array_swap(array, i, - 1);
    land_array_pop(array);
#line 177
    self->blocks->rebuild_static_cache = 1;
    self->blocks->rebuild_dynamic_cache = 1;
#line 180
    self->block_type->destroy(self);
}
bool block_overlaps(Block * self, Block * other) {
#line 188
    if ((other->x + other->xs > self->x && self->x + self->xs > other->x && other->y + other->ys > self->y && self->y + self->ys > other->y && other->z + other->zs > self->z && self->z + self->zs > other->z)) {
#line 190
        if (other->block_type == Render_RampLeft) {
            //   __   b +y
            //  |  | /|
            //  |_0|/ |
            //     /  |
            //  +z/__0|-z
            //    a
            float az = other->z + other->zs;
            float ay = other->y;
            float bz = other->z;
            float by = other->y + other->ys;
#line 202
            if (land_cross2d(self->z - az, self->y - ay, bz - az, by - ay) > 0) {
                return 0;
            }
        }
#line 204
        if (other->block_type == Render_RampRight) {
            //   __   b +y
            //  |  | /|
            //  |_0|/ |
            //     /  |
            //  +x/__0|-x
            //    a
            float ax = other->x + other->xs;
            float ay = other->y;
            float bx = other->x;
            float by = other->y + other->ys;
#line 216
            if (land_cross2d(self->x - ax, self->y - ay, bx - ax, by - ay) > 0) {
                return 0;
            }
        }
#line 218
        return 1;
    }
#line 219
    return 0;
}
bool block_center_overlaps(Block * super, Block * c) {
    float cx = super->x + super->xs / 2;
    float cz = super->z + super->zs / 2;
    if (cx > c->x && cx < c->x + c->xs && cz > c->z && cz < c->z + c->zs) {
        return 1;
    }
#line 226
    return 0;
}
LandArray* block_colliders(Block * self) {
    int n1, n2, n3;
    LandArray * r = land_array_new();
    n1 = land_array_count(self->blocks->fixed);
    n2 = land_array_count(self->blocks->dynamic);
    n3 = land_array_count(self->blocks->transparent);
    for (int i = 0; i < n1 + n2 + n3; i += 1) {
        Block * other;
        if (i < n1) {
#line 236
            other = land_array_get_nth(self->blocks->fixed, i);
        }
#line 237
        else if (i - n1 < n2) {
#line 237
            other = land_array_get_nth(self->blocks->dynamic, i - n1);
        }
#line 238
        else if (i - n1 - n2 < n3) {
#line 238
            other = land_array_get_nth(self->blocks->transparent, i - n1 - n2);
        }
#line 239
        if (other == self) {
#line 239
            continue;
        }
#line 240
        if (block_overlaps(self, other)) {
            land_array_add(r, other);
        }
    }
#line 242
    return r;
}
bool block_move(Block * self, float dx, float dy, float dz) {
    tag += 1;
    self->recursion_prevention = tag;
    self->mover = 1;
    bool r = block_push(self, dx, dy, dz);
    self->mover = 0;
    return r;
}
void move_on_top(Block * self, float dx, float dy, float dz) {
    float on_top_y = self->y;
    self->y += 1;
    LandArray * top = block_colliders(self);
    self->y = on_top_y;
    {
#line 257
        LandArrayIterator __iter0__ = LandArrayIterator_first(top);
#line 257
        for (Block * c = LandArrayIterator_item(top, &__iter0__); LandArrayIterator_next(top, &__iter0__); c = LandArrayIterator_item(top, &__iter0__)) {
            if (c->block_type->dynamic && ! c->block_type->fixed) {
                if (c->recursion_prevention != tag) {
                    c->recursion_prevention = tag;
                    block_push(c, dx, dy, dz);
                }
            }
        }
    }
#line 262
    land_array_destroy(top);
}
float block_distance(Block * self, Block * other) {
    float dx = self->x - other->x;
    float dy = self->y - other->y;
    float dz = self->z - other->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
bool block_push(Block * self, float odx, float ody, float odz) {
    bool r;
#line 273
    float ox = self->x;
    float oy = self->y;
    float oz = self->z;
#line 277
    bool first_after_push = 1;
    bool first_ramp_up = 1;
    int first_single_dir = 2;
#line 281
    retry:;
#line 283
    float dx = first_single_dir != 0 ? odx : 0;
    float dy = ody;
    float dz = first_single_dir != 1 ? odz : 0;
#line 287
    self->x += dx;
    if (self->y < 9000) {
        self->y += dy;
    }
#line 290
    self->z += dz;
#line 292
    if (self->y < - 9000) {
        self->y = - 9000;
    }
    LandArray * cs = block_colliders(self);
#line 297
    if (land_array_count(cs)) {
#line 299
        bool retry_after_push = 0;
#line 301
        self->x = ox;
        self->y = oy;
        self->z = oz;
#line 305
        {
#line 305
            LandArrayIterator __iter0__ = LandArrayIterator_first(cs);
#line 305
            for (Block * c = LandArrayIterator_item(cs, &__iter0__); LandArrayIterator_next(cs, &__iter0__); c = LandArrayIterator_item(cs, &__iter0__)) {
#line 307
                self->block_type->touch(self, c, dx, dy, dz);
                // don't get stuck at the very top pixel
#line 310
                if (self->y <= c->y + c->ys && self->y > c->y + c->ys - 1) {
                    self->y = c->y + c->ys;
                    continue;
                }
                // doing this in general is too dangerous of getting stuck
                // re-align to pushed block
                if (self->block_type == Render_Cart) {
                    if (self->x + self->xs < c->x && self->x + self->xs > c->x - 1) {
                        self->x = c->x - self->xs;
                    }
                    if (self->z > c->z + c->zs && self->z < c->z + c->zs + 1) {
                        self->z = c->z + c->zs;
                    }
                    if (self->z + self->zs < c->z && self->z + self->zs > c->z - 1) {
                        self->z = c->z - self->zs;
                    }
                    if (self->x > c->x + c->xs && self->x < c->x + c->xs + 1) {
                        self->x = c->x + c->xs;
                    }
                }
                // prevent "pushing" something that's actually on top
                if ((dy > 0 || c->y < self->y + self->ys) && c->block_type->dynamic && ! c->block_type->fixed) {
                    if (c->recursion_prevention != tag) {
                        c->recursion_prevention = tag;
                        if (block_push(c, dx, dy, dz)) {
                            //print("%d %s -> %s %f", tag, self->block_type->name, c->block_type->name, dy)
                            self->pushed_something = 1;
                            retry_after_push = 1;
                        }
                    }
                }
            }
        }
#line 339
        r = 0;
        land_array_destroy(cs);
#line 342
        if (first_after_push && retry_after_push) {
            first_after_push = 0;
            goto retry;
        }
#line 345
        else if (first_ramp_up && dy == 0) {
            first_ramp_up = 0;
            self->y += 1;
            goto retry;
        }
        // only an active mover can do single directions, otherwise
        // pushing in xz will behave very weird
#line 351
        else if (self->mover && first_single_dir > 0) {
            first_single_dir--;
            goto retry;
        }
    }
#line 353
    else {
#line 356
        if (dx || dz) {
            move_on_top(self, dx, dy, dz);
        }
        self->blocks->rebuild_dynamic_cache = 1;
        r = 1;
#line 362
        land_array_destroy(cs);
    }
#line 363
    return r;
}
int block_recursion_tag(void) {
    tag += 1;
    return tag;
}
bool block_pull(Block * self, float dx, float dy, float dz) {
    bool first_ramp_up = 1;
    float ox = self->x;
    float oy = self->y;
    float oz = self->z;
    retry:;
    self->x += dx;
    self->y += dy;
    self->z += dz;
    LandArray * cs = block_colliders(self);
    if (land_array_count(cs)) {
        self->x = ox;
        self->y = oy;
        self->z = oz;
        land_array_destroy(cs);
#line 385
        if (first_ramp_up) {
            first_ramp_up = 0;
            self->y += 1;
            goto retry;
        }
        return 0;
    }
    land_array_destroy(cs);
#line 394
    move_on_top(self, dx, dy, dz);
#line 396
    self->blocks->rebuild_dynamic_cache = 1;
    return 1;
}
static bool is_left(float * v, float xp, float yp, int i1, int i2) {
    float ax = v [i2 * 2 + 0] - v [i1 * 2 + 0];
    float ay = v [i2 * 2 + 1] - v [i1 * 2 + 1];
    float bx = xp - v [i1 * 2 + 0];
    float by = yp - v [i1 * 2 + 1];
    float c = ax * by - ay * bx;
    return c < 0;
}
int block_is_inside(Block * self, float xp, float yp, Viewport * viewport) {
    /* 0 no
     * 1 top
     * 2 left
     * 3 right
     */
#line 415
    float x2 = self->x + self->xs;
    float y2 = self->y + self->ys;
    float z2 = self->z + self->zs;
#line 419
    float v [14];
    project(viewport, self->x, y2, self->z, v + 0, v + 1);
    project(viewport, self->x, y2, z2, v + 2, v + 3);
    project(viewport, x2, y2, z2, v + 4, v + 5);
    project(viewport, x2, y2, self->z, v + 6, v + 7);
    project(viewport, self->x, self->y, z2, v + 8, v + 9);
    project(viewport, x2, self->y, z2, v + 10, v + 11);
    project(viewport, x2, self->y, self->z, v + 12, v + 13);
    //
    //      0
    //    /   .
    //  1       3
    //  | \   / |
    //  4   2   6
    //    \ | /
    //      5
#line 437
    if (! is_left(v, xp, yp, 0, 1)) {
#line 437
        return 0;
    }
#line 438
    if (self->ys) {
        if (! is_left(v, xp, yp, 1, 4)) {
#line 439
            return 0;
        }
    }
#line 440
    if (! is_left(v, xp, yp, 4, 5)) {
#line 440
        return 0;
    }
#line 441
    if (! is_left(v, xp, yp, 5, 6)) {
#line 441
        return 0;
    }
#line 442
    if (self->ys) {
        if (! is_left(v, xp, yp, 6, 3)) {
#line 443
            return 0;
        }
    }
#line 444
    if (! is_left(v, xp, yp, 3, 0)) {
#line 444
        return 0;
    }
#line 445
    if (is_left(v, xp, yp, 1, 2) && is_left(v, xp, yp, 2, 3)) {
#line 445
        return 1;
    }
#line 446
    if (is_left(v, xp, yp, 2, 5)) {
#line 446
        return 3;
    }
#line 447
    return 2;
}
#line 450
void block_get_bounding_rect(Block * self, Viewport * viewport, float * x1, float * y1, float * x2, float * y2) {
    float _;
    project(viewport, self->x, self->y, self->z + self->zs, x1, & _);
    project(viewport, self->x + self->xs, self->y, self->z, x2, & _);
    project(viewport, self->x, self->y + self->ys, self->z, & _, y1);
    project(viewport, self->x + self->xs, self->y, self->z + self->zs, & _, y2);
}
#line 458
int block_sort_order(Block * self, Block * other, Viewport * viewport) {
    if (self == other) {
#line 459
        return 0;
    }
#line 460
    float e = 0.1;
#line 462
    float slx, suy, srx, sdy;
    float olx, ouy, orx, ody;
#line 465
    block_get_bounding_rect(self, viewport, & slx, & suy, & srx, & sdy);
    block_get_bounding_rect(other, viewport, & olx, & ouy, & orx, & ody);
    // bounding box does not overlap -> don't care about order
#line 469
    if (slx >= orx) {
#line 469
        return 0;
    }
#line 470
    if (srx <= olx) {
#line 470
        return 0;
    }
#line 471
    if (suy >= ody) {
#line 471
        return 0;
    }
#line 472
    if (sdy <= ouy) {
#line 472
        return 0;
    }
    // Has to be drawn later if completely in front or above.
    if (self->z + e >= other->z + other->zs) {
#line 475
        return 1;
    }
#line 476
    if (self->y + e >= other->y + other->ys) {
#line 476
        return 1;
    }
#line 477
    if (self->x + e >= other->x + other->xs) {
#line 477
        return 1;
    }
    // Has to be drawn earlier if completely behind or below.
    if (other->z + e >= self->z + self->zs) {
#line 480
        return - 1;
    }
#line 481
    if (other->y + e >= self->y + self->ys) {
#line 481
        return - 1;
    }
#line 482
    if (other->x + e >= self->x + self->xs) {
#line 482
        return - 1;
    }
    // Note: They overlap...
#line 486
    if (self->y > other->y) {
#line 486
        return 1;
    }
    //if self->z + self->zs >= other->z + other->zs: return 1
    //if self->y + self->ys >= other->y + other->ys: return 1
    //if self->x + self->xs >= other->x + other->xs: return 1
    return - 1;
}
static float sgn(float a, float x) {
    if (a <= 0) {
#line 494
        return 0;
    }
#line 495
    if (x < 0) {
        if (a >= 1) {
#line 496
            return - 1;
        }
#line 497
        return - a;
    }
#line 498
    if (x > 0) {
        if (a >= 1) {
#line 499
            return 1;
        }
#line 500
        return a;
    }
#line 501
    return 0;
}
void block_tick(Block * self) {
    if (! self->block_type->animated) {
#line 504
        return ;
    }
    if (! self->no_fall && ! self->block_type->fixed) {
        self->dy -= sqrt(2);
    }
    float ax = fabs(self->dx);
    float ay = fabs(self->dy);
    float az = fabs(self->dz);
#line 513
    while (ax > 0 || ay > 0 || az > 0) {
        float sx = sgn(ax, self->dx);
        float sy = sgn(ay, self->dy);
        float sz = sgn(az, self->dz);
        if (sy) {
            if (! block_move(self, 0, sy, 0)) {
                self->dy = 0;
                if (sy < 0) {
                    self->ground = 1;
                }
            }
#line 521
            else {
#line 523
                self->ground = 0;
            }
        }
#line 524
        if (sx || sz) {
            block_move(self, sx, 0, sz);
        }
        ax -= 1;
        ay -= 1;
        az -= 1;
    }
    self->dx *= 0.4;
    self->dy *= 0.9;
    self->dz *= 0.4;
#line 535
    if (fabs(self->dx) < 0.1) {
#line 535
        self->dx = 0;
    }
#line 536
    if (fabs(self->dy) < 0.1) {
#line 536
        self->dy = 0;
    }
#line 537
    if (fabs(self->dz) < 0.1) {
#line 537
        self->dz = 0;
    }
}
#line 539
void block_touch(Block * self, Block * c, float dx, float dy, float dz) {
#line 539
    ;
}
#line 542
bool blocks_preload(Blocks * self) {
    int n1, n2, n3;
    n1 = land_array_count(self->fixed);
    n2 = land_array_count(self->dynamic);
    n3 = land_array_count(self->transparent);
    for (int i = 0; i < n1 + n2 + n3; i += 1) {
        Block * other;
        if (i < n1) {
#line 549
            other = land_array_get_nth(self->fixed, i);
        }
#line 550
        else if (i - n1 < n2) {
#line 550
            other = land_array_get_nth(self->dynamic, i - n1);
        }
#line 551
        else if (i - n1 - n2 < n3) {
#line 551
            other = land_array_get_nth(self->transparent, i - n1 - n2);
        }
#line 552
        BlockType * bt = other->block_type;
        if (blocktype_preload(bt)) {
            return 1;
        }
    }
#line 555
    return 0;
}
void blocks_shift(Blocks * self, int dx, int dy, int dz) {
    int n1, n2, n3;
    n1 = land_array_count(self->fixed);
    n2 = land_array_count(self->dynamic);
    n3 = land_array_count(self->transparent);
    for (int i = 0; i < n1 + n2 + n3; i += 1) {
        Block * other;
        if (i < n1) {
#line 564
            other = land_array_get_nth(self->fixed, i);
        }
#line 565
        else if (i - n1 < n2) {
#line 565
            other = land_array_get_nth(self->dynamic, i - n1);
        }
#line 566
        else if (i - n1 - n2 < n3) {
#line 566
            other = land_array_get_nth(self->transparent, i - n1 - n2);
        }
#line 567
        other->x += dx;
        other->y += dy;
        other->z += dz;
    }
}
/* This file was generated by scramble.py. */

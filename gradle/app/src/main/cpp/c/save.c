/* This file was generated by scramble.py. */
#line 1 "src/save.py"
#include "save.h"
static void add(SaveInfo * si, float x, float y, float z, float xs, float ys, float zs);
#line 3
    /* Savegame format:
     * a block in the center is at 22, 4, 22
     * positions are multipled by 24 to obtain in-game positions
     * An isometric block's origin is the bottom back corner, x then goes right
     * down, y goes up, z goes left down.
     * y
     * |
     * |
     * |
     * _-´ `-_
     * _-´       `-_
     * z               x
     * A block at 22/4/22 will end up at 0/0/0.
     * A block at 0/0/0 will end up at -528,-96,-528. (-22*24,-4*42,-22*24)
     * A level's floor typically is 40 x 40 in size.
     */
#line 41
static SaveInfo g_save_info [50];
#line 43
void save_info(void) {
    All * a = global_a;
    char * path = land_get_save_file("com.yellowdanger", "info.txt");
    LandFile * f = land_file_new(path, "w");
    land_file_print(f, "room %d", game->level);
    land_file_print(f, "dpad %d", a->dpad);
    land_file_print(f, "music %d", a->music);
    land_file_print(f, "sound %d", a->sound);
    land_file_print(f, "time %d", a->time);
    land_file_print(f, "key %d", game->key);
    land_file_print(f, "deaths %d", game->deaths);
    bool * fl = game->flower;
#line 56
    land_file_print(f, "flower %d %d %d %d %d %d %d", fl [1], fl [2], fl [3], fl [4], fl [5], fl [6], fl [7]);
    bool * tt = game->test_tube;
#line 59
    land_file_print(f, "testtube %d %d %d %d %d %d %d", tt [1], tt [2], tt [3], tt [4], tt [5], tt [6], tt [7]);
    land_file_destroy(f);
    land_free(path);
}
void load_info(void) {
    All * a = global_a;
    char * path = land_get_save_file("com.yellowdanger", "info.txt");
    game->level = game_starting_level;
    a->dpad = 0;
    a->music = 4;
    a->sound = 7;
    LandBuffer * f = land_buffer_read_from_file(path);
    if (f) {
        LandArray * rows = land_buffer_split(f, '\n');
        land_buffer_destroy(f);
        {
#line 74
            LandArrayIterator __iter0__ = LandArrayIterator_first(rows);
#line 74
            for (LandBuffer * rowb = LandArrayIterator_item(rows, &__iter0__); LandArrayIterator_next(rows, &__iter0__); rowb = LandArrayIterator_item(rows, &__iter0__)) {
                char * row = land_buffer_finish(rowb);
                if (land_starts_with(row, "room ")) {
                    sscanf(row, "room %d", & game->level);
                }
#line 78
                if (land_starts_with(row, "dpad ")) {
                    sscanf(row, "dpad %d", & a->dpad);
                }
#line 80
                if (land_starts_with(row, "music ")) {
                    sscanf(row, "music %d", & a->music);
                }
#line 82
                if (land_starts_with(row, "sound ")) {
                    sscanf(row, "sound %d", & a->sound);
                }
#line 84
                if (land_starts_with(row, "time ")) {
                    int t;
                    sscanf(row, "time %d", & t);
                    if (t > a->time) {
                        a->time = t;
                    }
                }
                // If a room is reloaded after dying or pausing,
                // we want to keep the current play time which
                // will always be higher.
                // If the game restarts however we want to use
                // the saved time.
#line 94
                if (land_starts_with(row, "key ")) {
                    int i;
                    sscanf(row, "key %d", & i);
                    if (i) {
#line 97
                        game->key = 1;
                    }
                }
#line 98
                if (land_starts_with(row, "deaths ")) {
                    sscanf(row, "deaths %d", & game->deaths);
                }
#line 100
                if (land_starts_with(row, "flower ")) {
                    int i [8];
                    i [0] = 0;
#line 104
                    sscanf(row, "flower %d %d %d %d %d %d %d", i + 1, i + 2, i + 3, i + 4, i + 5, i + 6, i + 7);
                    for (int j = 0; j < 8; j += 1) {
                        game->flower [j] = i [j];
                    }
                }
#line 107
                if (land_starts_with(row, "testtube ")) {
                    int i [8];
                    i [0] = 0;
#line 111
                    sscanf(row, "testtube %d %d %d %d %d %d %d", i + 1, i + 2, i + 3, i + 4, i + 5, i + 6, i + 7);
                    for (int j = 0; j < 8; j += 1) {
                        game->test_tube [j] = i [j];
                    }
                }
#line 114
                land_free(row);
            }
        }
#line 115
        land_array_destroy(rows);
    }
    land_free(path);
}
void save_get_name(char const * base, int level, char const * suffix, char * out) {
    sprintf(out, "%s%02d%s", base, level, suffix);
    char * path = land_get_save_file("com.yellowdanger", out);
    strcpy(out, path);
    land_free(path);
}
void save_level(bool editing) {
    char name [1024];
    if (editing) {
        sprintf(name, "data/levels/level%02d.txt", game->level);
        overview_update_level(game->overview, game->level);
    }
#line 129
    else {
#line 131
        save_get_name("save", game->level, ".txt", name);
        save_info();
    }
    Blocks * blocks = game->blocks;
    LandFile * f = land_file_new(name, "w");
    char * st = land_strdup(game->hint);
    land_replace_all(& st, "\n", "|");
    land_file_print(f, "hint %s", st);
    land_file_print(f, "title %s", game->title);
    land_free(st);
    float s = 24;
    int n = 0;
    LandArray * arrays [] = {blocks->transparent, blocks->dynamic, blocks->fixed};
    for (int i = 0; i < 3; i += 1) {
        LandArray * array = arrays [i];
        if (! array) {
            continue;
        }
#line 148
        {
#line 148
            LandArrayIterator __iter0__ = LandArrayIterator_first(array);
#line 148
            for (Block * block = LandArrayIterator_item(array, &__iter0__); LandArrayIterator_next(array, &__iter0__); block = LandArrayIterator_item(array, &__iter0__)) {
                float x = block->x / s + 22;
                float y = block->y / s + 4;
                float z = block->z / s + 22;
                int xi = floor(x);
                int yi = floor(y);
                int zi = floor(z);
#line 156
                land_file_print(f, "make %d %d %d %d", block->block_type->btid, xi, yi, zi);
                xi = x * 100 - xi * 100;
                yi = y * 100 - yi * 100;
                zi = z * 100 - zi * 100;
                if (xi || yi || zi) {
                    land_file_print(f, "move %d %d %d", xi, yi, zi);
                }
#line 162
                if (block->frame != 0) {
                    land_file_print(f, "frame %d", block->frame);
                }
#line 164
                n++;
            }
        }
    }
#line 166
    land_file_destroy(f);
#line 168
    print("save_level %s %d", name, n);
}
static void add(SaveInfo * si, float x, float y, float z, float xs, float ys, float zs) {
    float xy [14];
    float * p = xy;
    Viewport v = {0, 0, 1};
    project(& v, x + xs, y + ys, z, p + 0, p + 1);
#line 174
    p += 2;
    project(& v, x, y + ys, z, p + 0, p + 1);
#line 175
    p += 2;
    project(& v, x, y + ys, z + zs, p + 0, p + 1);
#line 176
    p += 2;
    project(& v, x, y, z + zs, p + 0, p + 1);
#line 177
    p += 2;
    project(& v, x + xs, y, z + zs, p + 0, p + 1);
#line 178
    p += 2;
    project(& v, x + xs, y, z, p + 0, p + 1);
#line 179
    p += 2;
    project(& v, x + xs, y + ys, z + zs, p + 0, p + 1);
#line 180
    p += 2;
    si->xy = land_realloc(si->xy, (si->n + 14) * sizeof (float));
    memcpy(si->xy + si->n, xy, sizeof (float) * 14);
    si->n += 14;
}
void save_check(int level) {
    char name [1024];
#line 188
    LandBuffer * f = NULL;
    SaveInfo * si = g_save_info + level;
#line 191
    if (level == game->level) {
        sprintf(name, "data/levels/level%02d.txt", level);
        f = land_buffer_read_from_file(name);
    }
    if (! f) {
        save_get_name("save", level, ".txt", name);
        f = land_buffer_read_from_file(name);
    }
    if (! f) {
#line 199
        return ;
    }
#line 202
    memset(si, 0, sizeof (* si));
#line 204
    si->saved = 1;
#line 206
    LandArray * rows = land_buffer_split(f, '\n');
    land_buffer_destroy(f);
#line 209
    {
#line 209
        LandArrayIterator __iter0__ = LandArrayIterator_first(rows);
#line 209
        for (LandBuffer * rowb = LandArrayIterator_item(rows, &__iter0__); LandArrayIterator_next(rows, &__iter0__); rowb = LandArrayIterator_item(rows, &__iter0__)) {
            char * row = land_buffer_finish(rowb);
            if (land_starts_with(row, "make ")) {
                int t, xi, yi, zi;
                sscanf(row, "make %d %d %d %d", & t, & xi, & yi, & zi);
#line 215
                BlockType * bt = land_array_get_nth(block_types, t);
#line 217
                float x = (xi - 22 - 3) * 24;
                float y = (yi - 4) * 24;
                float z = (zi - 22 - 3) * 24;
#line 221
                if (y < - 5000) {
                    continue;
                }
                if (bt == Render_Scientist) {
                    continue;
                }
                add(si, x, y, z, bt->xs, bt->ys, bt->zs);
#line 229
                if (bt == Render_ExitLeft) {
                    if (xi < 22) {
#line 230
                        si->exits [0] = 1;
                    }
#line 231
                    if (xi > 22) {
#line 231
                        si->exits [1] = 1;
                    }
                }
#line 232
                if (bt == Render_ExitRight) {
                    if (zi < 22) {
#line 233
                        si->exits [2] = 1;
                    }
#line 234
                    if (zi > 22) {
#line 234
                        si->exits [3] = 1;
                    }
                }
            }
#line 236
            land_free(row);
        }
    }
#line 238
    land_array_destroy(rows);
}
void load_level(bool editing) {
#line 242
    land_pause();
#line 244
    char name [1024];
    Game * self = game;
    self->pristine = 0;
#line 248
    print("Loading %d", game->level);
#line 250
    event("level_up level=%d", game->level);
#line 252
    LandBuffer * f = NULL;
    if (! editing) {
        save_get_name("save", game->level, ".txt", name);
        f = land_buffer_read_from_file(name);
    }
#line 256
    if (! f) {
        if (! editing) {
            print("    failed from %s", name);
        }
#line 259
        sprintf(name, "data/levels/level%02d.txt", game->level);
        f = land_buffer_read_from_file(name);
        self->pristine = 1;
    }
    self->player = NULL;
    self->state = "play";
    self->ticks = 0;
    self->state_tick = 0;
    self->waypoints_count = 0;
    editor->picked = NULL;
    self->lever = NULL;
    self->sequence = 0;
#line 272
    Blocks * blocks = game->blocks;
    blocks_reset(blocks);
#line 275
    if (! f) {
        printf("    failed from %s", name);
        land_unpause();
#line 277
        return ;
    }
#line 280
    save_load_from_offset(f, 0, 0, 0);
#line 282
    {
#line 282
        LandArrayIterator __iter0__ = LandArrayIterator_first(blocks->fixed);
#line 282
        for (Block * b = LandArrayIterator_item(blocks->fixed, &__iter0__); LandArrayIterator_next(blocks->fixed, &__iter0__); b = LandArrayIterator_item(blocks->fixed, &__iter0__)) {
#line 284
            if (b->block_type == Render_LeverLeft || b->block_type == Render_LeverRight) {
                if (b->frame == 1) {
                    self->lever = b;
                }
            }
#line 287
            if (b->block_type == Render_Waypoint) {
                self->waypoints [b->frame] [0] = b->x;
                self->waypoints [b->frame] [1] = b->y;
                self->waypoints [b->frame] [2] = b->z;
                if (b->frame >= self->waypoints_count) {
                    self->waypoints_count = b->frame + 1;
                }
            }
            // If a level is reloaded, and a flower is not picked (which
            // sets y to somewhere around -9000), it means we failed or
            // reset the level and so ought to get the flower again.
#line 296
            int flower = block_type_flower(b->block_type);
            if (flower) {
                if (b->y > - 8000) {
                    game->flower [flower] = 0;
                }
            }
        }
    }
#line 302
    bool visible = 1;
    for (int i = 1; i < 8; i += 1) {
        visible = visible && self->flower [i];
    }
#line 305
    if (self->key) {
        visible = 0;
    }
#line 307
    if (global_a->editor) {
        visible = 1;
    }
#line 309
    {
#line 309
        LandArrayIterator __iter0__ = LandArrayIterator_first(blocks->dynamic);
#line 309
        for (Block * b = LandArrayIterator_item(blocks->dynamic, &__iter0__); LandArrayIterator_next(blocks->dynamic, &__iter0__); b = LandArrayIterator_item(blocks->dynamic, &__iter0__)) {
            if (b->block_type == Render_Key) {
                if (b->y < 9000) {
                    if (! visible) {
                        b->y += 9000;
                    }
                }
#line 313
                else {
#line 315
                    if (visible) {
                        b->y -= 9000;
                    }
                }
            }
        }
    }
#line 318
    if (game->level == game_starting_level) {
        if (! editing && self->pristine) {
            game->sequence = 1;
            game->sequence_ticks = 0;
        }
    }
#line 323
    land_unpause();
}
void save_load_from_offset(LandBuffer * f, int ox, int oy, int oz) {
    All * all = global_a;
    LandArray * rows = land_buffer_split(f, '\n');
    land_buffer_destroy(f);
    float s = 24;
    int t, xi, yi, zi;
    Blocks * blocks = game->blocks;
    Block * block;
    {
#line 333
        LandArrayIterator __iter0__ = LandArrayIterator_first(rows);
#line 333
        for (LandBuffer * rowb = LandArrayIterator_item(rows, &__iter0__); LandArrayIterator_next(rows, &__iter0__); rowb = LandArrayIterator_item(rows, &__iter0__)) {
            char * row = land_buffer_finish(rowb);
            if (land_starts_with(row, "make ")) {
                sscanf(row, "make %d %d %d %d", & t, & xi, & yi, & zi);
#line 338
                float x = (ox + xi - 22) * s;
                float y = (oy + yi - 4) * s;
                float z = (oz + zi - 22) * s;
#line 342
                BlockType * bt = land_array_get_nth(block_types, t);
                //if bt == Render_ExitLeft or bt == Render_ExitRight:
                //    y -= 0.15 * s
#line 347
                block = block_new(blocks, x, y, z, bt);
#line 349
                block_add(block);
            }
#line 350
            if (land_starts_with(row, "move ")) {
                sscanf(row, "move %d %d %d", & xi, & yi, & zi);
                block->x += xi * s / 100.0;
                block->y += yi * s / 100.0;
                block->z += zi * s / 100.0;
            }
#line 355
            if (land_starts_with(row, "frame ")) {
                sscanf(row, "frame %d", & xi);
                block->frame = xi;
            }
#line 358
            if (land_starts_with(row, "hint ")) {
                char * st = land_strdup(row + 5);
                land_replace_all(& st, "|", "\n");
                if (all->dpad == 4 || all->dpad == 5) {
                    land_replace_all(& st, "the D-Pad", "anywhere");
                }
#line 363
                land_string_copy(game->hint, st, 1024);
                land_free(st);
            }
#line 365
            if (land_starts_with(row, "title ")) {
                land_string_copy(game->title, row + 6, 1024);
            }
            land_free(row);
        }
    }
#line 369
    land_array_destroy(rows);
}
void save_reset_room(int i) {
    char name [1024];
    save_get_name("save", i, ".txt", name);
    if (! land_file_remove(name)) {
        land_log_message("Cannot remove %s.", name);
    }
#line 376
    SaveInfo * si = g_save_info + i;
    si->saved = 0;
}
void save_new(void) {
    for (int i = 1; i < 50; i += 1) {
        save_reset_room(i);
    }
#line 382
    game->level = game_starting_level;
    game->deaths = 0;
    game->key = 0;
    for (int i = 0; i < 8; i += 1) {
        game->flower [i] = 0;
    }
#line 387
    global_a->time = 0;
    save_info();
}
bool save_is_saved(int i) {
    return g_save_info [i].saved;
}
int save_get_level_n(int i) {
    return g_save_info [i].n;
}
float* save_get_level_xy(int i) {
    return g_save_info [i].xy;
}
/* This file was generated by scramble.py. */

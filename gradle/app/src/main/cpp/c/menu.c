/* This file was generated by scramble.py. */
#line 1 "src/menu.py"
#include "menu.h"
static int category(BlockType * bt);
static char const* category_name(int c);
static void menu_items(Menu * menu);
#line 20
Menu* menu_new(void) {
    Menu * menu;
    land_alloc(menu);
#line 24
    return menu;
}
#define categories_count 8
#line 28
static int category(BlockType * bt) {
#line 31
    if (land_starts_with(bt->name, "BlockBottom") || land_starts_with(bt->name, "BlockSmall") || land_starts_with(bt->name, "Ramp")) {
        return 0;
    }
#line 35
    if (land_starts_with(bt->name, "Block") || land_starts_with(bt->name, "Invisible") || land_starts_with(bt->name, "Window")) {
        return 1;
    }
#line 37
    if (block_type_flower(bt) || bt == Render_Key) {
        return 2;
    }
#line 39
    if (bt == Render_Allefant || bt == Render_Gremlin || bt == Render_Scientist) {
        return 3;
    }
#line 47
    if (land_starts_with(bt->name, "Lever") || land_starts_with(bt->name, "Vent") || land_starts_with(bt->name, "Plate") || land_starts_with(bt->name, "Platform") || land_starts_with(bt->name, "Waypoint") || land_starts_with(bt->name, "Exit") || land_starts_with(bt->name, "Conveyor")) {
        return 4;
    }
#line 49
    if (bt->dynamic) {
        return 5;
    }
#line 54
    if (land_starts_with(bt->name, "Tree") || land_ends_with(bt->name, "Tree") || bt == Render_Ginko || bt == Render_Trunk) {
        return 6;
    }
#line 56
    return 7;
}
static char const* category_name(int c) {
    if (c == 0) {
#line 59
        return "Floor";
    }
#line 60
    if (c == 1) {
#line 60
        return "Wall";
    }
#line 61
    if (c == 2) {
#line 61
        return "Item";
    }
#line 62
    if (c == 3) {
#line 62
        return "Monster";
    }
#line 63
    if (c == 4) {
#line 63
        return "Device";
    }
#line 64
    if (c == 5) {
#line 64
        return "Moving";
    }
#line 65
    if (c == 6) {
#line 65
        return "Plant";
    }
#line 66
    if (c == 7) {
#line 66
        return "Decoration";
    }
#line 67
    return "";
}
static void menu_items(Menu * menu) {
    All * a = global_a;
#line 72
    menu->pos = 0;
    menu->n [0] = 0;
#line 75
    S("Mode");
    S("File");
    S("View");
    S("Level");
    S("Object");
    T;
    S(a->editor ? "Play" : "Edit");
    S("Record");
    S("Replay");
    S("Exit");
    T;
    S("Save");
    S("Load");
    S("Clear");
    T;
    S("Bounds");
    S("Mask");
    S("Info");
    T;
    S("Overview");
    S("Intro");
    S("Title");
    S("Hint");
    S("Shift X+");
    S("Shift X-");
    S("Shift Y+");
    S("Shift Y-");
    S("Shift Z+");
    S("Shift Z-");
    T;
    S("Insert");
    S("Type");
    S("Frame");
    S("Align");
    S("Delete");
    T;
    for (int i = 0; i < categories_count; i += 1) {
        S(category_name(i));
    }
#line 113
    for (int i = 0; i < categories_count; i += 1) {
        T;
        {
#line 115
            LandArrayIterator __iter0__ = LandArrayIterator_first(block_types);
#line 115
            for (BlockType * bt = LandArrayIterator_item(block_types, &__iter0__); LandArrayIterator_next(block_types, &__iter0__); bt = LandArrayIterator_item(block_types, &__iter0__)) {
                if (category(bt) == i) {
                    S(bt->name);
                }
            }
        }
    }
#line 119
    T;
    S("0");
    S("1");
    menu->sub_frame = menu->pos;
}
void menu_toggle(void) {
    if (game->menu_on) {
        game->menu_on = 0;
    }
#line 126
    else {
#line 128
        game->menu_on = 1;
        Menu * menu = game->menu;
        menu_items(menu);
        menu->hilite [0] = - 1;
        menu->menu [0] = 0;
        menu->menu [1] = - 1;
        menu->menu [2] = - 1;
    }
}
#line 136
void menu_draw(Menu * menu) {
    All * a = global_a;
    float w = land_display_width();
#line 140
    land_push_transform();
    land_scale(w / 960.0, w / 960.0);
#line 143
    float mw = 120;
    float mih = 30;
    float border = 40;
#line 147
    for (int mi = 0; mi < 3; mi += 1) {
        int m = menu->menu [mi];
        if (m == - 1) {
            break;
        }
#line 151
        float x0 = 960 - (mw + border) * (1 + mi);
        float y0 = 160;
        land_font_set(a->medium);
        int n = menu->n [m];
        land_premul(1, 1, 1, 0.8);
#line 157
        land_filled_rectangle(x0 - border, y0 - border, x0 + mw + border, y0 + n * mih + border);
        land_color(1, 1, 0, 1);
        int t = 4;
        land_thickness(t * 2);
#line 162
        land_rectangle(x0 - border + t, y0 - border + t, x0 + mw + border - t, y0 + n * mih + border - t);
        land_thickness(1);
        for (int i = 0; i < n; i += 1) {
            char * text = menu->items [m] [i];
            float x = x0;
            float y = y0 + i * mih;
            if (menu->hilite [mi] == i) {
                land_color(1, 1, 0.5, 1);
                land_filled_rectangle(x, y, x + mw, y + mih);
            }
#line 171
            land_text_pos(x, y);
            land_color(0, 0, 0, 1);
            land_print("%s", text);
        }
    }
#line 174
    land_pop_transform();
}
void menu_key(int k, bool shift) {
    All * a = global_a;
#line 179
    if (k == LandKeyFunction + 2) {
        if (game->pristine) {
            save_level(1);
        }
    }
#line 182
    else if (k == LandKeyFunction + 3) {
        load_level(1);
        a->overview = 0;
#line 186
        viewport_update(game->viewport, land_display_width(), land_display_height());
        a->editor = 1;
    }
#line 188
    else if (k == LandKeyFunction + 4) {
        blocks_reset(game->blocks);
        game->player = NULL;
        game->player2 = NULL;
    }
#line 192
    else if (k == LandKeyFunction + 5) {
        debug_no_mask = ! debug_no_mask;
    }
#line 194
    else if (k == LandKeyFunction + 6) {
        debug_bounding_boxes++;
        debug_bounding_boxes %= 2;
    }
#line 197
    else if (k == LandKeyFunction + 7) {
        a->editor = ! a->editor;
    }
#line 199
    else if (k == LandKeyFunction + 8) {
        if (a->overview) {
            a->overview = 0;
            game->level = game->overview->selected;
            menu_key(LandKeyFunction + 3, 0);
        }
#line 203
        else {
#line 205
            overview_update(game->overview);
        }
    }
#line 206
    else if (k == LandKeyFunction + 10) {
        game->sequence = ! game->sequence;
    }
#line 208
    else if (k == ' ') {
#line 208
        ;
    }
    else if (k == LandKeyEnter) {
        a->editor = ! a->editor;
    }
#line 212
    else if (k == 'q' || k == 'e' || k == 'w' || k == 's') {
        if (k == 'q' || k == 'e' || ! editor->picked) {
            int gox = 0, goz = 0;
            if (k == 'q') {
#line 215
                gox--;
            }
#line 216
            if (k == 'e') {
#line 216
                gox++;
            }
#line 217
            if (k == 'w') {
#line 217
                goz--;
            }
#line 218
            if (k == 's') {
#line 218
                goz++;
            }
#line 219
            game->level = game_neighboring_level(game->level, gox, goz);
            load_level(1);
            a->editor = 1;
        }
    }
#line 222
    else if (k == 'i') {
        Block * p = editor->picked;
        if (p) {
#line 227
            print("F%d X%.1f Y%.1f Z%.1f %2d/%2d/%2d", p->frame, p->x, p->y, p->z, (int)(p->x / 24) + 22, (int)(p->y / 24) + 4, (int)(p->z / 24) + 22);
        }
    }
#line 228
    else if (k == 't') {
        a->text_input = 1;
        a->cursor = 0;
    }
#line 231
    else if (k == 'h') {
        a->text_input = 2;
        a->cursor = 0;
    }
#line 234
    else if (k == 'r') {
        if (shift) {
            record_set_replaying(game->record);
        }
#line 236
        else {
#line 238
            record_set_recording(game->record);
        }
    }
#line 240
    if (! editor->picked) {
        if (k == 'x') {
            blocks_shift(game->blocks, shift ? 24 : - 24, 0, 0);
        }
#line 243
        else if (k == 'y') {
            blocks_shift(game->blocks, 0, shift ? 24 : - 24, 0);
        }
#line 245
        else if (k == 'z') {
            blocks_shift(game->blocks, 0, 0, shift ? 24 : - 24);
        }
    }
#line 248
    double s = 24;
    double s2 = s * 2;
#line 251
    if (shift) {
        s2 = s;
    }
    if (k == LandKeyInsert) {
        Block * l = editor->picked;
        if (l) {
#line 258
            editor->picked = block_new(game->blocks, l->x, l->y, l->z, l->block_type);
        }
#line 258
        else {
#line 261
            editor->picked = block_new(game->blocks, - s, - s * 2, - s, Render_BlockBottom3);
        }
#line 262
        block_add(editor->picked);
    }
    Block * p = editor->picked;
#line 266
    if (! p) {
#line 266
        return ;
    }
#line 269
    if (k == LandKeyLeft) {
        p->x -= s2;
        game_recalc();
    }
#line 272
    else if (k == LandKeyRight) {
        p->x += s2;
        game_recalc();
    }
#line 275
    else if (k == LandKeyUp) {
        p->z -= s2;
        game_recalc();
    }
#line 278
    else if (k == LandKeyDown) {
        p->z += s2;
        game_recalc();
    }
#line 281
    else if (k == 'w') {
        p->y += s2;
        game_recalc();
    }
#line 284
    else if (k == 's') {
        p->y -= s2;
        game_recalc();
    }
#line 287
    else if (k == 'x') {
        if (shift) {
            p->y += p->ys;
        }
#line 289
        else {
#line 291
            p->y -= p->ys;
        }
    }
#line 292
    else if (k == 'c') {
        if (shift) {
            p->x = floor(p->x / s) * s;
            p->y = floor(p->y / s) * s;
            p->z = floor(p->z / s) * s;
            p->x += (s - p->xs) / 2;
            p->z += (s - p->zs) / 2;
        }
#line 298
        else {
#line 300
            p->x = floor(p->x / s + 0.1) * s;
            p->y = floor(p->y / s + 0.1) * s;
            p->z = floor(p->z / s + 0.1) * s;
        }
    }
#line 303
    else if (k == 'a') {
        editor->picked = p = block_change_type(p, - 1);
    }
#line 305
    else if (k == 'd') {
        editor->picked = p = block_change_type(p, 1);
    }
#line 307
    else if (k == 'f') {
        p->frame++;
        if (p->frame >= land_array_count(p->block_type->bitmaps)) {
            p->frame = 0;
        }
    }
#line 311
    else if (k == LandKeyDelete) {
        block_del(p);
        editor->picked = NULL;
    }
}
#line 323
bool menu_tick(Menu * menu, float mx, float my, float click) {
    All * a = global_a;
    float w = land_display_width();
#line 327
    float mw = 120 * w / 960;
    float mih = 30 * w / 960;
    float border = 40 * w / 960;
#line 331
    bool out = 1;
    char * text = NULL;
#line 334
    int selected = - 1;
    int mi;
    for (mi = 0; mi < 3; mi += 1) {
        float x0 = w - (mw + border) * (1 + mi);
        float y0 = 160 * w / 960;
#line 340
        if (menu->menu [mi] == - 1) {
            break;
        }
        int n = menu->n [menu->menu [mi]];
#line 345
        menu->hilite [mi] = - 1;
#line 347
        if (mx < x0 - border) {
            continue;
        }
#line 349
        if (mx > x0 + mw + border) {
            continue;
        }
#line 351
        if (my < y0 - border) {
            continue;
        }
#line 353
        if (my > y0 + n * mih + border) {
            continue;
        }
        out = 0;
#line 358
        if (mx < x0 || mx > x0 + mw) {
            continue;
        }
#line 360
        selected = floor((my - y0) / mih);
        if (selected < 0 || selected >= n) {
            continue;
        }
        text = menu->items [menu->menu [mi]] [selected];
        break;
    }
    if (out) {
        return 0;
    }
    if (! text) {
        return 1;
    }
    if (click) {
        if (menu->menu [mi] > 0) {
            game->menu_on = 0;
            menu->menu [0] = 0;
            menu->menu [1] = - 1;
        }
        if (land_equals(text, "Mode")) {
#line 379
            menu->menu [mi] = 1;
        }
#line 380
        if (land_equals(text, "File")) {
#line 380
            menu->menu [mi] = 2;
        }
#line 381
        if (land_equals(text, "View")) {
#line 381
            menu->menu [mi] = 3;
        }
#line 382
        if (land_equals(text, "Level")) {
#line 382
            menu->menu [mi] = 4;
        }
#line 383
        if (land_equals(text, "Object")) {
#line 383
            menu->menu [mi] = 5;
        }
        if (land_equals(text, "Exit")) {
            a->editor = 0;
            main_switch_to_title(0);
        }
        if (land_equals(text, "Play")) {
            a->editor = 0;
        }
        if (land_equals(text, "Edit")) {
            a->editor = 1;
        }
#line 394
        ON("Record", 'r');
        ON_SHIFT("Replay", 'r');
#line 397
        ON("Save", LandKeyFunction + 2);
        ON("Load", LandKeyFunction + 3);
        ON("Clear", LandKeyFunction + 4);
#line 401
        ON("Bounds", LandKeyFunction + 6);
        ON("Mask", LandKeyFunction + 5);
        ON("Info", 'i');
#line 405
        ON("Overview", LandKeyFunction + 8);
        ON("Intro", LandKeyFunction + 10);
        ON("Title", 't');
        ON("Hint", 'h');
        ON_SHIFT("Shift X+", 'x');
        ON("Shift X-", 'x');
        ON_SHIFT("Shift Y+", 'y');
        ON("Shift Y-", 'y');
        ON_SHIFT("Shift Z+", 'z');
        ON("Shift Z-", 'z');
#line 416
        ON("Delete", LandKeyDelete);
#line 418
        if (land_equals(text, "Frame")) {
            menu->menu [0] = menu->sub_frame;
            menu->menu [1] = - 1;
            game->menu_on = 1;
#line 423
            Block * p = editor->picked;
            if (p) {
                int n = land_array_count(p->block_type->bitmaps);
                if (n > 10) {
                    n = 10;
                }
#line 428
                for (int i = 0; i < n; i += 1) {
#line 430
                    sprintf(menu->items [menu->sub_frame] [i], "Frame %d", 1 + i);
                }
#line 431
                menu->n [menu->sub_frame] = n;
            }
        }
#line 433
        if (land_equals(text, "Type")) {
            menu->menu [mi] = 6;
            game->menu_on = 1;
        }
#line 436
        ON("Align", 'c');
        ON("Insert", LandKeyInsert);
#line 439
        if (land_starts_with(text, "Frame ")) {
            Block * p = editor->picked;
            if (p) {
                p->frame = selected;
                if (p->frame >= land_array_count(p->block_type->bitmaps)) {
                    p->frame = 0;
                }
            }
        }
#line 446
        for (int c = 0; c < categories_count; c += 1) {
            if (land_equals(text, category_name(c))) {
                menu->menu [0] = 6;
                menu->menu [1] = 7 + c;
                game->menu_on = 1;
            }
        }
    }
#line 450
    else {
#line 453
        if (mi == 1) {
            if (editor->picked) {
#line 456
                editor->picked = block_change_type_to(editor->picked, text);
            }
        }
#line 458
        menu->hilite [mi] = selected;
    }
    return 1;
}
/* This file was generated by scramble.py. */
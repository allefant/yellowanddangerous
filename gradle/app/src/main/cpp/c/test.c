/* This file was generated by scramble.py. */
#line 1 "src/test.py"
#include "test.h"
#line 5
bool test(void) {
    global_a->test = 1;
    render_setup_path();
    render_load_blocktypes();
    game_setup(1920, 1080);
#line 11
    char result [50];
    int minduration [50];
    memset(result, ' ', sizeof result);
    memset(minduration, 0, sizeof minduration);
#line 16
    int ok = 0, n = 0;
    LandArray * tests = land_filelist("recordings", NULL, LAND_RELATIVE_PATH, NULL);
#line 19
    {
#line 19
        LandArrayIterator __iter0__ = LandArrayIterator_first(tests);
#line 19
        for (char * line = LandArrayIterator_item(tests, &__iter0__); LandArrayIterator_next(tests, &__iter0__); line = LandArrayIterator_item(tests, &__iter0__)) {
            if (land_equals(line, "")) {
                continue;
            }
#line 22
            int level, x, y, z;
            sscanf(line, "recordings/record%02d_%04d%04d%04d.gz", & level, & x, & y, & z);
            int tick = 0;
            if (test_level(level, x, y, z, & tick)) {
                ok++;
                if (result [level] == ' ') {
                    result [level] = 'K';
                }
            }
#line 28
            else {
#line 30
                result [level] = 'F';
            }
#line 31
            minduration [level] = tick;
            n++;
        }
    }
#line 34
    land_array_destroy_with_strings(tests);
#line 36
    for (int i = 0; i < 7; i += 1) {
        printf("%2d | ", 1 + i * 7);
        for (int j = 0; j < 7; j += 1) {
            int k = 1 + j + 7 * i;
            int d = minduration [k] / 360;
            if (d > 99) {
#line 41
                d = 99;
            }
#line 42
            char const * col = color_bash(result [k] == 'F' ? "red" : "green");
            char const * end = color_bash("");
            printf("%s%c%s %d.%d | ", col, result [k], end, d / 10, d % 10);
        }
#line 45
        printf("\n");
    }
    print("%d / %d successful", ok, n);
    return n == ok;
}
bool test_level(int level, int x, int y, int z, int * tick) {
    x = x - 22 * 24;
    y = y - 4 * 24;
    z = z - 22 * 24;
    game->level = level;
    load_level(1, 1);
    record_set_replaying(game->record);
    record_load(game->record, game->level, x, y, z);
    if (game->record->wait_on_level) {
        game->state = "no recording";
    }
#line 60
    Block * b = & game->player->super;
    b->x = x;
    b->y = y;
    b->z = z;
#line 65
    * tick = 0;
    while (* tick < 60 * 60 * 100) {
        // cap at 10 minutes
#line 67
        game_tick(game);
        if (! land_equals(game->state, "play")) {
            break;
        }
        //All *a = global_a
        //print("%d %d/%d/%d/%d/%d %f %f %f", tick,
        //    a.left, a.right, a.up, a.down, a.jump,
        //    b.x, b.y, b.z)
#line 74
        (* tick)++;
    }
#line 75
    print("%s at tick %d", game->state, * tick);
    if (land_equals(game->state, "done")) {
        print("%sOK%s", color_bash("green"), color_bash(""));
        return 1;
    }
#line 79
    print("%sFAIL%s", color_bash("red"), color_bash(""));
    return 0;
}
/* This file was generated by scramble.py. */

import common

"""
Savegame format:
a block in the center is at 22, 4, 22
positions are multipled by 24 to obtain in-game positions

An isometric block's origin is the bottom back corner, x then goes right
down, y goes up, z goes left down.

        y
        
        |
        |
        |
     _-´ `-_
  _-´       `-_
z               x

A block at 22/4/22 will end up at 0/0/0.
A block at 0/0/0 will end up at -528,-96,-528. (-22*24,-4*42,-22*24)

A level's floor typically is 40 x 40 in size.

"""

global class SaveInfo:
    bool saved
    bool exits[4]
    int n
    float *xy

import block
import game
import editor

type Game *game
type Editor *editor
type All *global_a

static SaveInfo g_save_info[50]

def save_info:
    All *a = global_a
    char *path = land_get_save_file("com.yellowdanger", "info.txt")
    LandFile *f = land_file_new(path, "w")
    land_file_print(f, "room %d", game.level)
    land_file_print(f, "dpad %d", a.dpad)
    land_file_print(f, "music %d", a.music)
    land_file_print(f, "sound %d", a.sound)
    land_file_print(f, "time %d", a.time)
    land_file_print(f, "key %d", game.key)
    land_file_print(f, "deaths %d", game.deaths)
    bool *fl = game.flower
    land_file_print(f, "flower %d %d %d %d %d %d %d",
        fl[1], fl[2], fl[3], fl[4], fl[5], fl[6], fl[7])
    bool *tt = game.test_tube
    land_file_print(f, "testtube %d %d %d %d %d %d %d",
        tt[1], tt[2], tt[3], tt[4], tt[5], tt[6], tt[7])
    land_file_destroy(f)
    land_free(path)

def load_info:
    All *a = global_a
    char *path = land_get_save_file("com.yellowdanger", "info.txt")
    game.level = game_starting_level
    a.dpad = 0
    a.music = 4
    a.sound = 7
    LandBuffer *f = land_buffer_read_from_file(path)
    if f:
        LandArray *rows = land_buffer_split(f, '\n')
        land_buffer_destroy(f)
        for LandBuffer *rowb in LandArray *rows:
            char *row = land_buffer_finish(rowb)
            if land_starts_with(row, "room "):
                sscanf(row, "room %d", &game.level)
            if land_starts_with(row, "dpad "):
                sscanf(row, "dpad %d", &a->dpad)
            if land_starts_with(row, "music "):
                sscanf(row, "music %d", &a->music)
            if land_starts_with(row, "sound "):
                sscanf(row, "sound %d", &a->sound)
            if land_starts_with(row, "time "):
                int t
                sscanf(row, "time %d", &t)
                if t > a.time:
                    a.time = t
                    # If a room is reloaded after dying or pausing,
                    # we want to keep the current play time which
                    # will always be higher.
                    # If the game restarts however we want to use
                    # the saved time.
            if land_starts_with(row, "key "):
                int i
                sscanf(row, "key %d", &i)
                if i: game.key = True
            if land_starts_with(row, "deaths "):
                sscanf(row, "deaths %d", &game.deaths)
            if land_starts_with(row, "flower "):
                int i[8]
                i[0] = 0
                sscanf(row, "flower %d %d %d %d %d %d %d", i + 1,
                    i + 2, i + 3, i + 4, i + 5, i + 6, i + 7)
                for int j in range(8):
                    game.flower[j] = i[j]
            if land_starts_with(row, "testtube "):
                int i[8]
                i[0] = 0
                sscanf(row, "testtube %d %d %d %d %d %d %d", i + 1,
                    i + 2, i + 3, i + 4, i + 5, i + 6, i + 7)
                for int j in range(8):
                    game.test_tube[j] = i[j]
            land_free(row)
        land_array_destroy(rows)
        
    land_free(path)

def save_get_name(char const *base, int level, char const *suffix, char *out):
    sprintf(out, "%s%02d%s", base, level, suffix)
    char *path = land_get_save_file("com.yellowdanger", out)
    strcpy(out, path)
    land_free(path)

def save_level(bool editing):
    char name[1024]
    if editing:
        sprintf(name, "data/levels/level%02d.txt", game.level)
        overview_update_level(game.overview, game.level)
    else:
        save_get_name("save", game.level, ".txt", name)
        save_info()
        
    Blocks *blocks = game.blocks
    LandFile *f = land_file_new(name, "w")
    char *st = land_strdup(game.hint)
    land_replace_all(&st, "\n", "|")
    land_file_print(f, "hint %s", st)
    land_file_print(f, "title %s", game.title)
    land_free(st)
    float s = 24
    int n = 0
    LandArray *arrays[] = {blocks.transparent, blocks.dynamic, blocks.fixed}
    for int i in range(3):
        LandArray *array = arrays[i]
        if not array:
            continue
        for Block *block in LandArray *array:
            float x = block.x / s + 22
            float y = block.y / s + 4
            float z = block.z / s + 22
            int xi = floor(x)
            int yi = floor(y)
            int zi = floor(z)
            land_file_print(f, "make %d %d %d %d", block.block_type->btid,
                xi, yi, zi)
            xi = x * 100 - xi * 100
            yi = y * 100 - yi * 100
            zi = z * 100 - zi * 100
            if xi or yi or zi:
                land_file_print(f, "move %d %d %d", xi, yi, zi)
            if block.frame != 0:
                land_file_print(f, "frame %d", block.frame)
            n++
            
    land_file_destroy(f)

    print("save_level %s %d", name, n)

static def add(SaveInfo *si, float x, y, z, xs, ys, zs):
    float xy[14]
    float *p = xy
    Viewport v = {0, 0, 1}
    project(&v, x + xs, y + ys, z, p + 0, p + 1); p += 2
    project(&v, x, y + ys, z, p + 0, p + 1); p += 2
    project(&v, x, y + ys, z + zs, p + 0, p + 1); p += 2
    project(&v, x, y, z + zs, p + 0, p + 1); p += 2
    project(&v, x + xs, y, z + zs, p + 0, p + 1); p += 2
    project(&v, x + xs, y, z, p + 0, p + 1); p += 2
    project(&v, x + xs, y + ys, z + zs, p + 0, p + 1); p += 2
    si.xy = land_realloc(si.xy, (si.n + 14) * sizeof(float))
    memcpy(si.xy + si.n, xy, sizeof(float) * 14)
    si.n += 14

def save_check(int level):
    char name[1024]

    LandBuffer *f = None
    SaveInfo *si = g_save_info + level

    if level == game.level:
        sprintf(name, "data/levels/level%02d.txt", level)
        f = land_buffer_read_from_file(name)

    if not f:
        save_get_name("save", level, ".txt", name)
        f = land_buffer_read_from_file(name)

    if not f:
        return

    memset(si, 0, sizeof *si)
   
    si.saved = True

    LandArray *rows = land_buffer_split(f, '\n')
    land_buffer_destroy(f)
   
    for LandBuffer *rowb in LandArray *rows:
        char *row = land_buffer_finish(rowb)
        if land_starts_with(row, "make "):
            int t, xi, yi, zi
            sscanf(row, "make %d %d %d %d", &t, &xi, &yi, &zi)

            BlockType *bt = land_array_get_nth(block_types, t)

            float x = (xi - 22 - 3) * 24
            float y = (yi - 4) * 24
            float z = (zi - 22 - 3) * 24

            if y < -5000:
                continue

            if bt == Render_Scientist:
                continue

            add(si, x, y, z, bt.xs, bt.ys, bt.zs)

            if bt == Render_ExitLeft:
                if xi < 22: si.exits[0] = True
                if xi > 22: si.exits[1] = True
            if bt == Render_ExitRight:
                if zi < 22: si.exits[2] = True
                if zi > 22: si.exits[3] = True
           
        land_free(row)
    
    land_array_destroy(rows)

def load_level(bool editing):

    land_pause()

    char name[1024]
    Game *self = game
    self.pristine = False

    print("Loading %d", game.level)

    event("level_up level=%d", game.level)

    LandBuffer *f = None
    if not editing:
        save_get_name("save", game.level, ".txt", name)
        f = land_buffer_read_from_file(name)
    if not f:
        if not editing:
            print("    failed from %s", name)
        sprintf(name, "data/levels/level%02d.txt", game.level)
        f = land_buffer_read_from_file(name)
        self.pristine = True

    self.player = None
    self.state = "play"
    self.ticks = 0
    self.state_tick = 0
    self.waypoints_count = 0
    editor.picked = None
    self.lever = None
    self.sequence = 0

    Blocks *blocks = game.blocks
    blocks_reset(blocks)

    if not f:
        printf("    failed from %s", name)
        land_unpause()
        return

    save_load_from_offset(f, 0, 0, 0)

    for Block *b in LandArray *blocks.fixed:
        if b.block_type == Render_LeverLeft or\
                b.block_type == Render_LeverRight:
            if b.frame == 1:
                self.lever = b
        if b.block_type == Render_Waypoint:
            self.waypoints[b.frame][0] = b.x
            self.waypoints[b.frame][1] = b.y
            self.waypoints[b.frame][2] = b.z
            if b.frame >= self.waypoints_count:
                self.waypoints_count = b.frame + 1
        # If a level is reloaded, and a flower is not picked (which
        # sets y to somewhere around -9000), it means we failed or
        # reset the level and so ought to get the flower again.
        int flower = block_type_flower(b.block_type)
        if flower:
            if b.y > -8000:
                game.flower[flower] = False
                

    bool visible = True
    for int i in range(1, 8):
        visible = visible and self.flower[i]
    if self.key:
        visible = False
    if global_a.editor:
        visible = True
    for Block *b in LandArray *blocks.dynamic:
        if b.block_type == Render_Key:
            if b.y < 9000:
                if not visible:
                    b.y += 9000
            else:
                if visible:
                    b.y -= 9000

    if game.level == game_starting_level:
        if not editing and self.pristine:
            game.sequence = 1
            game.sequence_ticks = 0

    land_unpause()

def save_load_from_offset(LandBuffer *f, int ox, oy, oz):
    All *all = global_a
    LandArray *rows = land_buffer_split(f, '\n')
    land_buffer_destroy(f)
    float s = 24
    int t, xi, yi, zi
    Blocks *blocks = game.blocks
    Block *block
    for LandBuffer *rowb in LandArray *rows:
        char *row = land_buffer_finish(rowb)
        if land_starts_with(row, "make "):
            sscanf(row, "make %d %d %d %d", &t, &xi, &yi, &zi)

            float x = (ox + xi - 22) * s
            float y = (oy + yi - 4) * s
            float z = (oz + zi - 22) * s

            BlockType *bt = land_array_get_nth(block_types, t)

            #if bt == Render_ExitLeft or bt == Render_ExitRight:
            #    y -= 0.15 * s

            block = block_new(blocks, x, y, z, bt)

            block_add(block)
        if land_starts_with(row, "move "):
            sscanf(row, "move %d %d %d", &xi, &yi, &zi)
            block.x += xi * s / 100.0
            block.y += yi * s / 100.0
            block.z += zi * s / 100.0
        if land_starts_with(row, "frame "):
            sscanf(row, "frame %d", &xi)
            block.frame = xi
        if land_starts_with(row, "hint "):
            char *st = land_strdup(row + 5)
            land_replace_all(&st, "|", "\n")
            if all.dpad == 4 or all.dpad == 5:
                land_replace_all(&st, "the D-Pad", "anywhere")
            land_string_copy(game.hint, st, 1024)
            land_free(st)
        if land_starts_with(row, "title "):
            land_string_copy(game.title, row + 6, 1024)

        land_free(row)
    land_array_destroy(rows)

def save_reset_room(int i):
    char name[1024]
    save_get_name("save", i, ".txt", name)
    if not land_file_remove(name):
        land_log_message("Cannot remove %s.", name)
    SaveInfo *si = g_save_info + i
    si.saved = False

def save_new:
    for int i in range(1, 50):
        save_reset_room(i)
    game.level = game_starting_level
    game.deaths = 0
    game.key = False
    for int i in range(8):
        game.flower[i] = False
    global_a->time = 0
    save_info()

def save_is_saved(int i) -> bool:
    return g_save_info[i].saved

def save_get_level_n(int i) -> int:
    return g_save_info[i].n

def save_get_level_xy(int i) -> float *:
    return g_save_info[i].xy 

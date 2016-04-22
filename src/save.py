import block
import game

type Game *game

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
            land_free(row)
        land_array_destroy(rows)
        
    land_free(path)

def save_level(bool editor):
    char name[1024]
    if editor:
        sprintf(name, "data/levels/level%02d.txt", game.level)
    else:
        sprintf(name, "save%02d.txt", game.level)
        char *path = land_get_save_file("com.yellowdanger", name)
        strcpy(name, path)
        land_free(path)
        save_info()
        
    Blocks *blocks = game.blocks
    LandFile *f = land_file_new(name, "w")
    char *st = land_strdup(game.hint)
    land_replace_all(&st, "\n", "|")
    land_file_print(f, "hint %s", st)
    land_file_print(f, "title %s", game.title)
    land_free(st)
    float s = 24
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
            
    land_file_destroy(f)
    
def load_level(bool editor):

    land_pause()

    char name[1024]
    Game *self = game
    self.pristine = False

    LandBuffer *f = None
    if not editor:
        sprintf(name, "save%02d.txt", game.level)
        char *path = land_get_save_file("com.yellowdanger", name)
        strcpy(name, path)
        land_free(path)
        f = land_buffer_read_from_file(name)
    if not f:
        sprintf(name, "data/levels/level%02d.txt", game.level)
        f = land_buffer_read_from_file(name)
        self.pristine = True

    self.player = None
    self.state = "play"
    self.ticks = 0
    self.state_tick = 0
    self.waypoints_count = 0
    self.picked = None
    self.lever_left = 0
    self.lever_right = 0
    self.lever_on = False
    self.sequence = 0

    Blocks *blocks = game.blocks
    blocks_reset(blocks)

    if not f:
        land_unpause()
        return

    save_load_from_offset(f, 0, 0, 0)

    BlockType *flowers[8] = {None,
        Render_Gentian,
        Render_Edelweiss,
        Render_Orchid,
        Render_Hyacinth,
        Render_Sunflower,
        Render_Rose,
        Render_Belladonna}

    for Block *b in LandArray *blocks.fixed:
        if b.block_type == Render_Waypoint:
            self.waypoints[b.frame][0] = b.x
            self.waypoints[b.frame][1] = b.y
            self.waypoints[b.frame][2] = b.z
            if b.frame >= self.waypoints_count:
                self.waypoints_count = b.frame + 1
        # If a level is reloaded, and a flower is not picked (which
        # sets y to somewhere around -9000), it means we failed or
        # reset the level and so ought to get the flower again.
        for int i in range(1, 8):
            if b.block_type == flowers[i]:
                if b.y > -8000:
                    game.flower[i] = False
                

    bool visible = True
    for int i in range(1, 8):
        visible = visible and self.flower[i]
    if self.key:
        visible = False
    if global_a->editor:
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
    sprintf(name, "save%02d.txt", i)
    char *path = land_get_save_file("com.yellowdanger", name)
    if not land_file_remove(path):
        land_log_message("Cannot remove %s.", path)
    land_free(path)

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


import block
import game

def save_info:
    if game->level == 0:
        return
    char *path = land_get_save_file("com.yellowdanger", "info.txt")
    LandFile *f = land_file_new(path, "w")
    land_file_print(f, "room %d", game->level)
    land_file_destroy(f)
    land_free(path)

def load_info:
    char *path = land_get_save_file("com.yellowdanger", "info.txt")
    LandBuffer *f = land_buffer_read_from_file(path)
    if f:
        LandArray *rows = land_buffer_split(f, '\n')
        land_buffer_destroy(f)
        for LandBuffer *rowb in LandArray *rows:
            char *row = land_buffer_finish(rowb)
            if land_starts_with(row, "room "):
                sscanf(row, "room %d", &game->level)
            land_free(row)
        land_array_destroy(rows)
        
    land_free(path)

def save_level(bool editor):
    if game->level == 0:
        return
    char name[1024]
    if editor:
        sprintf(name, "data/levels/level%02d.txt", game->level)
    else:
        sprintf(name, "save%02d.txt", game->level)
        char *path = land_get_save_file("com.yellowdanger", name)
        strcpy(name, path)
        land_free(path)
        save_info()
        
    Blocks *blocks = game->blocks
    LandFile *f = land_file_new(name, "w")
    char *st = land_strdup(game->hint)
    land_replace_all(&st, "\n", "|")
    land_file_print(f, "hint %s", st)
    land_free(st)
    float s = 24
    LandArray *arrays[] = {blocks.transparent, blocks.dynamic, blocks.fixed}
    for int i in range(3):
        LandArray *array = arrays[i]
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
    char name[1024]
    Game *self = game
    self.pristine = False

    LandBuffer *f = None
    if not editor:
        sprintf(name, "save%02d.txt", game->level)
        char *path = land_get_save_file("com.yellowdanger", name)
        strcpy(name, path)
        land_free(path)
        f = land_buffer_read_from_file(name)
    if not f:
        sprintf(name, "data/levels/level%02d.txt", game->level)
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

    Blocks *blocks = game->blocks
    blocks_reset(blocks)

    if not f:
        return

    LandArray *rows = land_buffer_split(f, '\n')
    land_buffer_destroy(f)
    float s = 24
    int t, xi, yi, zi
    Block *block
    for LandBuffer *rowb in LandArray *rows:
        char *row = land_buffer_finish(rowb)
        if land_starts_with(row, "make "):
            sscanf(row, "make %d %d %d %d", &t, &xi, &yi, &zi)

            float x = (xi - 22) * s
            float y = (yi - 4) * s
            float z = (zi - 22) * s

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
            land_string_copy(game->hint, st, 1024)
            land_free(st)

        land_free(row)
    land_array_destroy(rows)

    for Block *b in LandArray *blocks.fixed:
        if b.block_type == Render_Waypoint:
            self.waypoints[b.frame][0] = b.x
            self.waypoints[b.frame][1] = b.y
            self.waypoints[b.frame][2] = b.z
            if b.frame >= self.waypoints_count:
                self.waypoints_count = b.frame + 1

def save_reset_room(int i):
    char name[1024]
    sprintf(name, "save%02d.txt", i)
    char *path = land_get_save_file("com.yellowdanger", name)
    if not land_file_remove(path):
        print("Cannot remove %s.", path)
    land_free(path)

def save_new:
    for int i in range(1, 50):
        save_reset_room(i)
    char *path = land_get_save_file("com.yellowdanger", "info.txt")
    land_file_remove(path)
    land_free(path)

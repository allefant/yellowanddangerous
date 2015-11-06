import block
import game

def save_level:
    char name[1024]
    sprintf(name, "data/levels/level%02d.txt", game->level)
    Blocks *blocks = game->blocks
    LandFile *f = land_file_new(name, "w")
    char *st = land_strdup(game->hint)
    land_replace_all(&st, "\n", "|")
    land_file_print(f, "hint %s", st)
    land_free(st)
    float s = 24 / sqrt(2)
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
    
def load_level:
    char name[1024]
    sprintf(name, "data/levels/level%02d.txt", game->level)

    Game *self = game
    self.player = None
    self.state = "play"
    self.ticks = 0
    self.state_tick = 0
    self.waypoints_count = 0
    self.picked = None
    self.lever_left = 0
    self.lever_right = 0
    self.lever_dir = 1

    Blocks *blocks = game->blocks
    blocks_reset(blocks)

    LandBuffer *f = land_buffer_read_from_file(name)
    LandArray *rows = land_buffer_split(f, '\n')
    land_buffer_destroy(f)
    float s = 24 / sqrt(2)
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

def save_count:
    char name[1024]
    game->levels = 0
    while True:
        sprintf(name, "data/levels/level%02d.txt", game->levels + 1)
        FILE *f = fopen(name, "r")
        if not f:
            break
        fclose(f)
        game->levels++

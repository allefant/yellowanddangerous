import common
import block, isometric, level, render, player, cube, allefant, level

class Game:
    int level, levels
    Blocks *blocks
    float waypoints[10][3]
    int waypoints_count
    Viewport *viewport
    char const *state
    int ticks
    int state_tick
    Player *player
    Allefant *player2

    Block *picked

    double start_time

    char hint[1024]

global Game *game

  
Game *def game_new():
    Game *self; land_alloc(self)
    self->viewport = viewport_new()

    self->level = level_start

    render_setup()

    self->blocks = blocks_new()

    game_reset(self)

    return self

def game_del(Game *self):
    blocks_destroy(self->blocks)
    render_teardown()
    land_free(self->viewport)
    land_free(self)

def game_reset(Game *self):
    self.player = None
    self->state = "play"
    self->ticks = 0
    self->state_tick = 0
    self->waypoints_count = 0
    game_read_level(self, level_get_data(), self->level)

def game_read_level(Game *self, char const *rooms, int level):
    level--

    blocks_reset(self->blocks)
    
    float e = 0
    float s = 96 / sqrt(2)
    float S = -4.25

    int data[12 * 12 * 6]
    memset(data, 0, sizeof data)

    int rowpos = 0
    int rows = 0
    bool empty = True
    char const *hint
    char const *row = rooms
    while *row:
        int c = land_utf8_char_const(&row)
        if c == '\n':
            rowpos = 0
            if not empty:
                rows++
            empty = True
            if rows == 13 * level + 12:
                hint = row
            continue
        else:
            rowpos++
            empty = False
        self.levels = rows / 13
        if rows / 13 == level:
            int levelrow = rows - level * 13
            if rowpos - 1 < 12 * 6 and levelrow < 12:
                data[levelrow * 12 * 6 + rowpos - 1] = c

    for int y in range(6):
        for int z in range(12):
            for int x in range(12):
                int c = data[z * 12 * 6 + x + 12 * y]

                float rx = x - 1
                float ry = max(0, y - 1)
                float rz = z - 1
                float xp = (rx + S) * s
                float yp = ry * (s + e)
                float zp = (rz + S) * s
              
                game_make_block(self, c, xp, yp, zp)

    char const *end = strchr(hint, '\n')
    char *r = land_substring(hint, 0, end - hint)
    land_replace_all(&r, "|", "\n")
    strcpy(self.hint, r)
    land_free(r)

static Block *def make(Game *self, float xp, yp, zp, BlockType *t):
    Block *b
    if t and t->dynamic:
        b = block_new(self->blocks, xp + 0.1, yp, zp + 0.1, t)
    else:
        b = block_new(self->blocks, xp, yp, zp, t)

    block_add(b)
    return b
            
def game_make_block(Game *self, int c, float xp, yp, zp):
    char s[10];
    s[land_utf8_encode(c, s)] = 0
    Block *b
    if c == '_':
        b = make(self, xp, yp, zp, Render_BlockBottom2)
        b->y -= b->ys
    if c == '-':
        b = make(self, xp, yp, zp, Render_BlockBottom3)
        b->y -= b->ys
    if c == '~':
        b = make(self, xp, yp, zp, Render_BlockBottomLeft3)
        b->y -= b->ys
    if c == '*':
        make(self, xp, yp, zp, Render_Cube2)
    if c == '+':
        b = make(self, xp, yp, zp, Render_Cube2)
        b->y -= b->ys
    if c == '#':
        make(self, xp, yp, zp, Render_Block)
    if c == ':':
        b = make(self, xp, yp, zp, Render_BlockBottom)
        b->y -= b->ys
    if c == '\'':
        b = make(self, xp, yp, zp, Render_BlockSmall3)
        b->y -= b->ys
    if c == '/':
        make(self, xp, yp, zp, Render_BlockLeft2)
    if c == '|':
        make(self, xp, yp, zp, Render_BlockRight2)
    #if c == ']':
    #    make(self, xp, yp, zp, Render_BlockRight)
    if c == '[':
        make(self, xp, yp, zp, Render_BlockLeft)
    if c == '}':
        make(self, xp, yp, zp, Render_BlockRight4)
    if c == '{':
        make(self, xp, yp, zp, Render_BlockLeft4)
    if c == 'S':
        self->player = player_new(self->blocks, xp, yp, zp, Render_Scientist)
        block_add(&self->player->super)
    if c == L'♥':
        b = (void *)cube_new(self->blocks, xp, yp, zp, Render_Cube3)
        block_add(b)
    if c == '=':
        make(self, xp, yp, zp, Render_Bridge)
    if c == '$':
        make(self, xp, yp, zp, Render_Bridge2)
    if c == 'x':
        b = make(self, xp, yp, zp, Render_Plate)
        b->y -= b->ys
    if c == 'O':
        make(self, xp, yp, zp, Render_Barrel)
    if c == 'T':
        make(self, xp, yp, zp, Render_TreeBottom)
    if c == 't':
        make(self, xp, yp, zp, Render_TreeTop)
    if c == 'C':
        make(self, xp, yp, zp, Render_CherryTree)
    if c == '!':
        make(self, xp, yp, zp, Render_Trunk)
    if c == 'e':
        b = make(self, xp, yp, zp, Render_ExitLeft)
        b->y -= b->ys
    if c == L'ə':
        b = make(self, xp, yp, zp, Render_ExitRight)
        b->y -= b->ys
    if c == 'A':
        self->player2 = allefant_new(self->blocks, xp, yp, zp, Render_Allefant)
        self->waypoints[0][0] = xp
        self->waypoints[0][1] = yp
        self->waypoints[0][2] = zp
        block_add(&self->player2->super)
        self->waypoints_count = max(self->waypoints_count, 1)
    if c >= '1' and c <= '9':
        int i = c - '0';
        self->waypoints[i][0] = xp
        self->waypoints[i][1] = yp
        self->waypoints[i][2] = zp
        self->waypoints_count = max(self->waypoints_count, i + 1)

def game_level_done(Game *self):
    if strcmp(self->state, "play") == 0:
        self->state = "done"
        self->state_tick = self->ticks
        sound(Render_teleport, 1)

def game_tick(Game *self):

    if strcmp(self->state, "done") == 0 or  strcmp(self->state, "died") == 0:
        if self->ticks > self->state_tick + 30:
            if strcmp(self->state, "done") == 0: self->level += 1
            game_reset(self)

    if land_was_resized():
        viewport_update(self.viewport)

    for int ti in range(11):
        if not land_touch_down(ti):
            continue
        All *a = global_a

        double rr = land_display_width() / 8 * 0.8
        double rx = rr
        double ry = land_display_height() - rr
        double mx = land_touch_x(ti)
        double my = land_touch_y(ti)
        double dx = mx - rx
        double dy = my - ry

        if dx * dx + dy * dy < rr * rr:
            if dx * dx + dy * dy > rr * rr / 16:
                double ang = atan2(dy, dx)
                ang += pi / 8
                if ang < 0:
                    ang += pi * 2
                int i = ang * 4 / pi
                if i == 0 or i == 1 or i == 7:
                    a.right = True
                if i == 1 or i == 2 or i == 3:
                    a.down = True
                if i == 3 or i == 4 or i == 5:
                    a.left = True
                if i == 5 or i == 6 or i == 7:
                    a.up = True

        rx = land_display_width() - rr
        dx = mx - rx
        dy = my - ry
        if dx * dx + dy * dy < rr * rr:
            a.jump = True

    int plates_count = 0
    int plates_on_before = 0

    if land_mouse_button(0) and land_mouse_delta_button(0):
        float mx = land_mouse_x()
        float my = land_mouse_y()
        game.picked = blocks_pick(game.blocks, mx, my, game.viewport)
        if not game.picked:
            game.blocks.rebuild_static_cache = True
            game.blocks.rebuild_dynamic_cache = True

    if self->player:

        if strcmp(self->state, "play") == 0:
            if self->player->dead or self->player->super.y < -960:
                sound(Render_oh_no, 1)
                self->state = "died"

    for Block *b in LandArray *self->blocks->fixed:
        if b->block_type == Render_Plate:
            if b->frame == 1:
                plates_on_before += 1
            b->frame = 0
            plates_count += 1

    float s = 96 / sqrt(2)

    if land_key_pressed(LandKeyInsert):
        game.picked = block_new(self.blocks, -0.25 * s, -s, -0.25 * s, Render_BlockBottom3)
        block_add(game.picked)

    if game.picked:
        Block *p = game.picked

        if land_key_pressed(LandKeyLeft):
            p.x -= s
        if land_key_pressed(LandKeyRight):
            p.x += s
        if land_key_pressed(LandKeyUp):
            p.z -= s
        if land_key_pressed(LandKeyDown):
            p.z += s
        if land_key_pressed('w'):
            p.y += s / 2
        if land_key_pressed('s'):
            p.y -= s / 2
        if land_key_pressed('a'):
            block_change_type(p, -1)
        if land_key_pressed('d'):
            block_change_type(p, 1)
        if land_key_pressed(LandKeyDelete):
            block_del(p)
            block_destroy(p)
    else:
        for Block *b in LandArray *self->blocks->dynamic:
            b->block_type->tick(b)

    int plates_on = 0
    for Block *b in LandArray *self->blocks->fixed:
        if b->block_type == Render_Plate:
            if b->frame == 1:
                plates_on += 1
        elif b->block_type == Render_ExitLeft or b->block_type == Render_ExitRight:
            b->frame = 0

    if plates_on > plates_on_before:
        sound(Render_on, 1)

    if plates_on < plates_on_before:
        sound(Render_off, 1)

    if plates_count == plates_on:
        for Block *b in LandArray *self->blocks->fixed:
            if b->block_type == Render_ExitLeft or b->block_type == Render_ExitRight:
                b->frame = 1

    self->ticks += 1

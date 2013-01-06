import common
import block, isometric, level, render, player, cube, allefant, level

class Game:
    int level
    Blocks *blocks
    float waypoints[10][3]
    int waypoints_count
    Viewport *viewport
    char const *state
    int ticks
    int state_tick
    Player *player
    Allefant *player2

    double start_time

global Game *game
    
Game *def game_new():
    Game *self; land_alloc(self)
    self->viewport = viewport_new(land_display_width() / 2,
        land_display_height() / 2)

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
    self->state = "play"
    self->ticks = 0
    self->state_tick = 0
    self->waypoints_count = 0
    game_read_level(self, level_get_data(self->level))

def game_read_level(Game *self, char const *level):
    blocks_reset(self->blocks)
    
    float e = 0
    float s = 96 / sqrt(2)
    float S = -4.25

    int data[12 * 12 * 6]

    int pos = 0
    int rowpos = 0
    char const *row = level + 1
    while *row:
        int c = land_utf8_char_const(&row)
        if rowpos < 12 * 6:
            data[pos++] = c
        if c == '\n':
            rowpos = 0
        else:
            rowpos++

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

static Block *def make(Game *self, float xp, yp, zp, BlockType *t):
    Block *b
    if t->dynamic:
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

    int plates_count = 0
    int plates_on_before = 0

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

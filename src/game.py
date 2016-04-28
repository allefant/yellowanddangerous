import common
import block, isometric, level, render, player, cube, allefant, level
import save
import intro
import input
import menu
import overview
import editor

type Editor *editor

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

    Block *lever

    double start_time

    char hint[1024]
    char title[1024]
    bool pristine

    int gox, goz
    int ex, ez

    int swap_level

    int sequence
    int sequence_ticks

    bool flower[8]
    bool key

    int deaths

    Menu *menu
    bool menu_on

    Overview *overview

global Game *game
global int game_starting_level = 22
  
Game *def game_new():
    Game *self; land_alloc(self)
    self.viewport = viewport_new()

    self.level = 0

    self.blocks = blocks_new()

    self.menu = menu_new()

    self.overview = overview_new()

    editor_new()

    return self

def game_del(Game *self):
    blocks_destroy(self->blocks)
    render_teardown()
    overview_destroy(game.overview)
    land_free(self.viewport)
    land_free(self.menu)
    land_free(self)

    editor_del()

def game_neighboring_level(int level, gox, goz) -> int:
    int row = (level - 1) / 7
    int col = (level - 1) % 7
    col += gox + 7
    row += goz + 7
    col %= 7
    row %= 7
    level = 1 + row * 7 + col
    return level

def game_level_number_to_xz(int level, *x, *z):
    *z = (level - 1) / 7
    *x = (level - 1) % 7
    
def game_level_done(Game *self, int gox, goz):
    if land_equals(self->state, "play") :
        self->state = "done"
        self->state_tick = self->ticks
        save_level(False)
        self->gox = gox
        self->goz = goz
        if self->player:
            self->ex = self->player->super.x
            self->ez = self->player->super.z
        self->level = game_neighboring_level(self.level, gox, goz)
        sound(Render_teleport, 1)

def game_recalc:
    game.blocks.rebuild_static_cache = True
    game.blocks.rebuild_dynamic_cache = True

def game_key(Game *self, int k):
    if not global_editor_enabled:
        return
    
    menu_key(k)

def game_tick(Game *self):
    All *a = global_a

    if land_equals(self->state, "done") or land_equals(self->state, "died"):
        if self->ticks > self->state_tick + 30:
            a.load_after_redraw = 1
            a.find_entrance = True
            play_song()

    if a.load_after_redraw:
        return

    input_tick()

    if a.overview:
        overview_tick(game.overview)
        return
    
    int plates_count = 0
    int plates_on_before = 0

    if self->player:

        if strcmp(self->state, "play") == 0:
            if self->player->dead or self->player->super.y < -960:
                sound(Render_oh_no, 1)
                self->state = "died"
                game->deaths++

    for Block *b in LandArray *self->blocks->fixed:
        if b->block_type == Render_Plate:
            if b->frame == 1:
                plates_on_before += 1
            b->frame = 0
            plates_count += 1

    if land_key_pressed(LandKeyBack):
        main_switch_to_title(0)

    if land_key_pressed(LandKeyMenu):
        main_switch_to_title(1)

    if game.sequence:
        intro_sequence()

    if not a.editor:
        a.time++
        for Block *b in LandArray *self->blocks->dynamic:
            b->block_type->tick(b)

        int plates_on = 0
        for Block *b in LandArray *self->blocks->fixed:
            if b->block_type == Render_Plate:
                if b->frame == 1:
                    plates_on += 1
            elif b->block_type == Render_ExitLeft or b->block_type == Render_ExitRight:
                if b.frame == 1:
                    b.frame = 0

        if plates_on > plates_on_before:
            sound(Render_on, 1)

        if plates_on < plates_on_before:
            sound(Render_off, 1)

        if plates_count == plates_on:
            for Block *b in LandArray *self->blocks->fixed:
                if b->block_type == Render_ExitLeft or b->block_type == Render_ExitRight:
                    if b.frame == 0:
                        b.frame = 1

    self->ticks += 1

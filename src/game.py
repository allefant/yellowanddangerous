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

    Block *lever_left
    Block *lever_right
    bool lever_on
    bool platform_moving
    int lever_dir

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

    return self

def game_del(Game *self):
    blocks_destroy(self->blocks)
    render_teardown()
    land_free(self->viewport)
    land_free(self)

def game_reset:
    if game.level > game.levels:
        game.level = 1
    if game.level < 1:
        game.level = game.levels
    load_level()

def game_level_done(Game *self):
    if strcmp(self->state, "play") == 0:
        self->state = "done"
        self->state_tick = self->ticks
        sound(Render_teleport, 1)

static def recalc:
    game.blocks.rebuild_static_cache = True
    game.blocks.rebuild_dynamic_cache = True

def game_tick(Game *self):
    All *a = global_a

    if strcmp(self->state, "done") == 0 or  strcmp(self->state, "died") == 0:
        if self->ticks > self->state_tick + 30:
            if strcmp(self->state, "done") == 0: self->level += 1
            game_reset()

    if land_was_resized():
        viewport_update(self.viewport)

    for int ti in range(11):
        if not land_touch_down(ti):
            continue

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
        Block *l = game.picked
        if l:
            game.picked = block_new(self.blocks, l.x, l.y, l.z,
                l.block_type)
        else:
            game.picked = block_new(self.blocks, -0.25 * s, -s / 2, -0.25 * s,
                Render_BlockBottom3)
        block_add(game.picked)

    if game.picked:
        Block *p = game.picked

        if land_key_pressed(LandKeyLeft):
            p.x -= s / 2
            recalc()
        if land_key_pressed(LandKeyRight):
            p.x += s / 2
            recalc()
        if land_key_pressed(LandKeyUp):
            p.z -= s / 2
            recalc()
        if land_key_pressed(LandKeyDown):
            p.z += s / 2
            recalc()
        if land_key_pressed('w'):
            p.y += s / 2
            recalc()
        if land_key_pressed('s'):
            p.y -= s / 2
            recalc()
        if land_key_pressed('x'):
            if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
                p.y += p.ys
            else:
                p.y -= p.ys
        if land_key_pressed('c'):
            if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
                p.x = floor(p.x / s + 0.25) * s - s / 4
                p.y = 0
                p.z = floor(p.z / s + 0.25) * s - s / 4
                p.x += (s - p.xs) / 2
                p.z += (s - p.zs) / 2
            else:
                p.x = floor(p.x / s + 0.25) * s - s / 4
                p.y = 0
                p.z = floor(p.z / s + 0.25) * s - s / 4
        if land_key_pressed('a'):
            game.picked = p = block_change_type(p, -1)
        if land_key_pressed('d'):
            game.picked = p = block_change_type(p, 1)
        if land_key_pressed('f'):
            p.frame++
            if p.frame >= land_array_count(p.block_type->bitmaps):
                p.frame = 0
        if land_key_pressed(LandKeyDelete):
            block_del(p)
            game.picked = None
        

    if a.running and not game.picked:
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

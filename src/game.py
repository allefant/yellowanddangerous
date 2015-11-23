import common
import block, isometric, level, render, player, cube, allefant, level
import save
import intro

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

    Block *lever_left
    Block *lever_right
    bool lever_on

    Block *picked

    double start_time

    char hint[1024]
    char title[1024]
    bool pristine

    int gox, goz
    int ex, ez

    int swap_level

    bool sequence
    int sequence_ticks

global Game *game
global int game_starting_level = 22
  
Game *def game_new():
    Game *self; land_alloc(self)
    self->viewport = viewport_new()

    self->level = 0

    render_setup()

    self->blocks = blocks_new()

    return self

def game_del(Game *self):
    blocks_destroy(self->blocks)
    render_teardown()
    land_free(self->viewport)
    land_free(self)

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
        self->level += gox + goz * 7
        sound(Render_teleport, 1)

static def recalc:
    game.blocks.rebuild_static_cache = True
    game.blocks.rebuild_dynamic_cache = True

def game_key(Game *self, int k):
    All *a = global_a
    if k == LandKeyFunction + 2:
        if game->pristine:
            save_level(True)
    elif k == LandKeyFunction + 3:
        load_level(True)
        a.overview = False
        viewport_update(game->viewport)
        a.running = False
    elif k == LandKeyFunction + 4:
        blocks_reset(game->blocks)
        game->player = None
        game->player2 = None
    elif k == LandKeyFunction + 5:
        debug_no_mask = not debug_no_mask
    elif k == LandKeyFunction + 6:
        debug_bounding_boxes++
        debug_bounding_boxes %= 2
    elif k == LandKeyFunction + 7:
        a.editor = not a.editor
    elif k == LandKeyFunction + 8:
        load_all()
        a.overview = True
        viewport_update(game->viewport)
        a.running = False
    elif k == LandKeyFunction + 10:
        game->sequence = not game->sequence
    elif k == ' ':
        pass
    elif k == LandKeyEnter:
        if not a->running:
            a->running = True
    elif k == 'q' or k == 'e' or k == 'w' or k == 's':
        if k == 'q' or k == 'e' or not game->picked:
            if k == 'q': game->level -= 1
            if k == 'e': game->level += 1
            if k == 'w': game->level -= 7
            if k == 's': game->level += 7
            if game->level < 1:
                game->level += 49
            if game->level > 49:
                game->level -= 49
            load_level(True)
            a.running = False
    elif k == 'i':
        Block *p = game->picked
        if p:
            print("%.1f %.1f %.1f", p.x, p.y, p.z)
    elif k == 't':
        a.text_input = 1
        a.cursor = 0
    elif k == 'h':
        a.text_input = 2
        a.cursor = 0
    elif k >= '0' and k <= '9':
        int d = k - '0'
        game->level *= 10
        game->level %= 100
        game->level += d
    elif k == 'c':
        game->swap_level = game->level
    elif k == 'v':
        if game->swap_level:
            int level1 = game->swap_level
            game->swap_level = 0
            int level2 = game->level

            # 2 -> 0
            load_level(True)
            game->level = 0
            save_level(True)

            # 1 -> 2
            game->level = level1
            load_level(True)
            game->level = level2
            save_level(True)

            # 0 -> 1
            game->level = 0
            load_level(True)
            game->level = level1
            save_level(True)

def game_tick(Game *self):
    All *a = global_a

    if land_equals(self->state, "done") or land_equals(self->state, "died"):
        if self->ticks > self->state_tick + 30:
            a.load_after_redraw = 1
            a.find_entrance = True
            play_song()

    if a.load_after_redraw:
        return

    for int ti in range(11):
        if not land_touch_down(ti):
            continue

        double rr = land_display_width() / 8 * 0.8
        if a.dpad == 2 or a.dpad == 3:
            rr *= 1.5
        double rx = rr
        if a.dpad == 1 or a.dpad == 3:
            rx = land_display_width() - rr
        double ry = land_display_height() - rr
        double mx = land_touch_x(ti)
        double my = land_touch_y(ti)
        double dx = mx - rx
        double dy = my - ry

        # move control
        #                  c
        #                 b d
        #                a   e
        #               9     f
        #              8       0
        #               7     1
        #                6   2
        #                 5 3
        #                  4
           
        if dx * dx + dy * dy < rr * rr:
            if dx * dx + dy * dy > rr * rr / 16:
                double ang = atan2(dy, dx)
                # we use 16 subdivisions, the main directions get 12
                # out of that and the diagonals 4
                ang += pi / 16
                if ang < 0:
                    ang += pi * 2
                int i = ang * 8 / pi
                if i <= 3 or i >= 0xd:
                    a.right = True
                if i >= 1 and i <= 7:
                    a.down = True
                if i >= 5 and i <= 0xb:
                    a.left = True
                if i >= 9:
                    a.up = True

        # jump control
        rx = land_display_width() - rr
        if a.dpad == 1 or a.dpad == 3:
            rx = rr
        dx = mx - rx
        dy = my - ry
        if dx * dx + dy * dy < rr * rr:
            a.jump = True

        # pause control
        rx = land_display_width() - rr
        ry = rr
        if mx > rx and my < ry:
            main_switch_to_title(0)

    int plates_count = 0
    int plates_on_before = 0

    if land_mouse_button(0) and land_mouse_delta_button(0):
        float mx = land_mouse_x()
        float my = land_mouse_y()
        game.picked = blocks_pick(game.blocks, mx, my, game.viewport)
        #if game.picked:
        #    print("%f %f %f", game.picked->x, game.picked->y, game.picked->z)   

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

    double s = 24

    if land_key_pressed(LandKeyBack):
        main_switch_to_title(0)

    if land_key_pressed(LandKeyMenu):
        main_switch_to_title(1)

    if land_key_pressed(LandKeyInsert):
        Block *l = game.picked
        if l:
            game.picked = block_new(self.blocks, l.x, l.y, l.z,
                l.block_type)
        else:
            game.picked = block_new(self.blocks, -s, -s * 2, -s,
                Render_BlockBottom3)
        block_add(game.picked)

    if game.sequence and a.running:
        intro_sequence()

    if game.picked:
        Block *p = game.picked

        double s2 = s * 2
        if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
            s2 = s

        if land_key_pressed(LandKeyLeft):
            p.x -= s2
            recalc()
        if land_key_pressed(LandKeyRight):
            p.x += s2
            recalc()
        if land_key_pressed(LandKeyUp):
            p.z -= s2
            recalc()
        if land_key_pressed(LandKeyDown):
            p.z += s2
            recalc()
        if land_key_pressed('w'):
            p.y += s2
            recalc()
        if land_key_pressed('s'):
            p.y -= s2
            recalc()
        if land_key_pressed('x'):
            if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
                p.y += p.ys
            else:
                p.y -= p.ys
        if land_key_pressed('c'):
            if land_key(LandKeyLeftShift) or land_key(LandKeyRightShift):
                p.x = floor(p.x / s) * s
                p.y = floor(p.y / s) * s
                p.z = floor(p.z / s) * s
                p.x += (s - p.xs) / 2
                p.z += (s - p.zs) / 2
            else:
                p.x = floor(p.x / s + 0.1) * s
                p.y = floor(p.y / s + 0.1) * s
                p.z = floor(p.z / s + 0.1) * s
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

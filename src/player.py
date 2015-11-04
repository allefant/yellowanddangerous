import common
import block, game, main

class Player:
    Block super
    LandArray *stack
    int step 
    int direction
    int want_direction
    int rotstep
    bool pull # jump key pressed with no direction keys pressed
    bool reverse # started moving in backwards direction
    bool pushing
    bool dead

Player *def player_new(Blocks *blocks, float x, y, z, BlockType *kind):
    Player *self
    land_alloc(self)
    block_init((void *)self, blocks, x, y, z, kind)
    self->step = 0
    self->direction = 0
    self->want_direction = 0
    self->rotstep = 0
    self->pull = False
    self->reverse = False
    self->stack = land_array_new()
    self->pushing = False
    self->dead = False
    return self

def player_destroy(Block *super):
    Player *self = (void *)super
    land_array_destroy(self->stack)
    block_destroy(super)

def player_try_pull(Player *self, float px, pz):
    float ox = self->super.x
    float oz = self->super.z
    
    self->super.x -= px * 3
    self->super.z -= pz * 3
    LandArray *pulls = block_colliders((void *)self)
    self->super.x = ox
    self->super.z = oz

    for Block *p in LandArray *pulls:
        if not p->block_type->dynamic: continue
        if block_pull(p, px, 0, pz):
            self->super.dx = 0
            self->super.dz = 0
            self->pushing = True

    land_array_destroy(pulls)

def player_grab(Player *self):
    float ox = self->super.x
    float oz = self->super.z

    float px = sin((self->want_direction + 1) * pi / 4)
    float pz = cos((self->want_direction + 1) * pi / 4)

    self->super.x += px * 3
    self->super.z += pz * 3
    LandArray *grabs = block_colliders(&self->super)

    self->super.x = ox
    self->super.z = oz

    land_array_clear(self->stack)

    float max_y = 0
    for Block *b in LandArray *grabs:
        if not b->block_type->lift: continue
        if b->y >= max_y: max_y = b->y

    for Block *b in LandArray *grabs:
        if not b->block_type->lift: continue
        if b->y == max_y:
            land_array_add(self->stack, b)

def player_lift(Player *self):

    for Block *p in LandArray *self->stack:

        # don't want to be able to walk under it
        if p->y + 1 < self->super.y + self->super.ys:
            if block_pull(p, 0, 1, 0):
                p->no_fall = True
                p->dy = 0

def player_tick(Block *super):
    Player *self = (void *)super

    All *a = global_a

    float x = 0
    float z = 0
    if a->up: x -= 1; z -= 1
    if a->down: x += 1; z += 1
    if a->left: x -= 1; z += 1
    if a->right: x += 1; z -= 1

    float d = pow(x * x + z * z, 0.5)
    if d > 0 and not land_array_count(self->stack):

        x /= d
        z /= d
        double angle = atan2(x, z) - pi / 4
        angle = angle / (2 * pi)
        angle = (int)((angle - floor(angle)) * 8 + 0.5) & 7

        self->want_direction = angle

        if super->ground and a->jump:
            if self->pull:
                if not self->reverse:
                    player_grab(self)
                    if land_array_count(self->stack):
                        x = z = 0
                        self->super.dx = 0
                        self->super.dz = 0
                        self->pull = False
                    else:
                        self->reverse = True

                if self->reverse:
                    self->want_direction += 4
                    self->want_direction &= 7
                    
            elif a->jump:
                self->super.dy += 20
                sound(Render_uhg, 1)

        x *= 2
        z *= 2

        super->dx += x
        super->dz += z

        self->step += 1
        self->step &= 31

        if self->step == 9 or self->step == 25:
            if self->super.ground: sound(Render_step, 0.3)

    else:
        if self->step != 8 and self->step != 24:
            self->step += 1
            self->step &= 31

        if super->ground and a->jump:
            self->pull = True

    if self->pushing:
        if game->ticks % 8 == 1:
            sound(Render_push, 0.3)
            self->pushing = False

    if self->want_direction != self->direction:
        self->rotstep += 1
        if self->rotstep >= 4:
            self->rotstep = 0
            d = self->want_direction - self->direction

            if d < -4: d += 8
            elif d > 4: d -= 8
            if abs(d) == 4: self->direction += (land_rand(0, 1)) * 2 - 1
            elif d < 0: self->direction -= 1
            elif d > 0: self->direction += 1
            self->direction &= 7
    
    super->frame = self->direction * 8 + self->step / 4

    float px = super->dx
    float pz = super->dz
    block_tick(super)

    if self->pull:
        if not a->jump:
            self->pull = False
            self->reverse = False

        if px or pz:
            player_try_pull(self, px, pz)

    if land_array_count(self->stack):
        if not a->jump:
            while land_array_count(self->stack):
                Block *b = land_array_pop(self->stack)
                b->no_fall = False
        else:
            player_lift(self)

def player_touch(Block *super, Block *c, float dx, dy, dz):
    Player *self = (void *)super
    if dy < 0:
        if c->block_type == Render_Plate:
            c->frame = 1
        elif c->block_type == Render_ExitLeft or c->block_type == Render_ExitRight:
            if c->frame == 1:
                game_level_done(game)
    if dx != 0 or dz != 0:
        if c->block_type->dynamic:
            self->pushing = True

import common
import block, game, main

type Game *game

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

    bool lever
    bool metal

def player_allocate -> Block *:
    Player *self
    land_alloc(self)
    return &self.super

def player_init(Block *super):
    Player *self = (void *)super
    self->step = 0
    self->direction = 0
    self->want_direction = 0
    self->rotstep = 0
    self->pull = False
    self->reverse = False
    self->stack = land_array_new()
    self->pushing = False
    self->dead = False
    game->player = self

def player_destroy(Block *super):
    game->player = None
    Player *self = (void *)super
    land_array_destroy(self->stack)
    block_destroy(super)

def player_try_pull(Player *self, float px, pz):
    float ox = self->super.x
    float oz = self->super.z
    
    self->super.x -= px * 3 * sqrt(2)
    self->super.z -= pz * 3 * sqrt(2)
    LandArray *pulls = block_colliders((void *)self)
    self->super.x = ox
    self->super.z = oz

    int tag = block_recursion_tag()
    for Block *p in LandArray *pulls:
        if not p->block_type->dynamic: continue
        if p->block_type->fixed: continue
        p.recursion_prevention = tag
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

    self->super.x += px * 3 * sqrt(2)
    self->super.z += pz * 3 * sqrt(2)
    LandArray *grabs = block_colliders(&self->super)

    self->super.x = ox
    self->super.z = oz

    land_array_clear(self->stack)

    float max_y = -9000
    for Block *b in LandArray *grabs:
        if not b->block_type->lift: continue
        if b->y >= max_y: max_y = b->y

    for Block *b in LandArray *grabs:
        if not b->block_type->lift: continue
        if b->y == max_y:
            land_array_add(self->stack, b)

    land_array_destroy(grabs)

def player_lift(Player *self):
    block_recursion_tag()

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

    # slow down jump stronger if only tapping
    if not a.jump and self->super.dy > 0:
        self->super.dy *= 0.5

    float d = pow(x * x + z * z, 0.5)
    if d > 0 and not land_array_count(self->stack):

        x /= d
        z /= d
        double angle = atan2(x, z) - pi / 4
        angle = angle / (2 * pi)
        angle = (int)((angle - floor(angle)) * 8 + 0.5) & 7

        self->want_direction = angle

        if (super->ground or (a.godmode and self->super.dy < 5)) and a->jump:
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
                self->super.dy += 30
                sound(Render_uhg, 1)

        x *= 2.8
        z *= 2.8

        super->dx += x
        super->dz += z

        self->step += 1
        self->step &= 31

        if self->step == 9 or self->step == 25:
            if self->super.ground:
                if self.metal: sound(Render_metal, 0.3)
                else: sound(Render_step, 0.3)

    else:
        if self->step != 8 and self->step != 24:
            self->step += 1
            self->step &= 31
        else:
            self.lever = False

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

    if super.pushed_something:
        super.pushed_something = False
        super.dx *= 0.7
        super.dz *= 0.7

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
    All *a = global_a
    Player *self = (void *)super
    cube_touch(super, c, dx, dy, dz)
    if c->block_type == Render_Gremlin:
        Gremlin *gremlin = (void *)c
        if not gremlin.respect:
            self.dead = True
    int flower = 0
    if c->block_type == Render_Car:
        if game->key and game->sequence == 0:
            LandArray *cs = block_colliders(c)
            int n = land_array_count(cs)
            land_array_destroy(cs)
            if n == 0:
                sound(Render_ignition, .5)
                game->sequence = 2
                game->sequence_ticks = 0
    if c->block_type == Render_Gentian:
        flower = 1
    if c->block_type == Render_Edelweiss:
        flower = 2
    if c->block_type == Render_Orchid:
        flower = 3
    if c->block_type == Render_Hyacinth:
        flower = 4
    if c->block_type == Render_Sunflower:
        flower = 5
    if c->block_type == Render_Rose:
        flower = 6
    if c->block_type == Render_Belladonna:
        flower = 7
    if flower:
        c->y = -9000
        game.flower[flower] = True
        sound(Render_pickup, 1)
    if c->block_type == Render_Key:
        c->y = -9000
        game->key = True
        sound(Render_pickup, 1)
    if dy < 0:
        if c->block_type == Render_ExitLeft and c.frame != 4:
            if c.frame == 1 or c.frame == 2 or a.godmode:
                game_level_done(game, c.x > 0 ? 1 : -1, 0)
        elif c->block_type == Render_ExitRight and c.frame != 4:
            if c.frame == 1 or c.frame == 2 or a.godmode:
                game_level_done(game, 0, c.z > 0 ? 1 : -1)
        if c.block_type == Render_GrateBottom or c.block_type == Render_Cart:
            self.metal = True
        else:
            self.metal = False
    if not self.lever:
        if dx < 0 and c.block_type == Render_LeverLeft:
            if c.frame == 0:
                self.lever = True
                c.frame = 1
                game->lever = c
        if dz < 0 and c.block_type == Render_LeverRight:
            if c.frame == 0:
                self.lever = True
                c.frame = 1
                game->lever = c
    if dx != 0 or dz != 0:
        if c->block_type->dynamic:
            self->pushing = True

def player_find_entrance(Block *super):
    int mind = 0
    Block *e = None
    for Block *b in LandArray *super->blocks->fixed:
        if game->gox and b->block_type == Render_ExitLeft:
            if game->gox * b->x < 0:
                int d = fabs(game->ez - b->z)
                if e == None or d < mind:
                    mind = d
                    e = b
        if game->goz and b->block_type == Render_ExitRight:
            if game->goz * b->z < 0:
                int d = fabs(game->ex - b->x)
                if e == None or d < mind:
                    mind = d
                    e = b
    if e:
        super.x = e.x + e.xs / 2 + game->gox * (e.xs / 2 + super.xs / 2) - super.xs / 2
        super.y = e.y + e.ys
        super.z = e.z + e.zs / 2 + game->goz * (e.zs / 2 + super.zs / 2) - super.zs / 2
        if e.frame == 3:
            e.frame = 2

    LandArray *a = block_colliders(super)
    for Block *c in LandArray *a:
        if super.y < c.y + c.ys:
            super.y = c.y + c.ys
            
    land_array_destroy(a)

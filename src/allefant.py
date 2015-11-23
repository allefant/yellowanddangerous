import common
import block, game, player

class Allefant:
    Block super
    int step
    int direction
    int want_direction
    int rotstep
    int waypoint
    int wait
    float tx, tz
    float ax, az
    int travel

def allefant_allocate -> Block *:
    Allefant *self
    land_alloc(self)
    return &self.super

def allefant_init(Block *super):
    Allefant *self = (void *)super
    self->step = 0
    self->direction = 0
    self->want_direction = 0
    self->rotstep = 0
    self->waypoint = 1
    self->wait = 60 * 2
    self->tx = super.x
    self->tz = super.y
    self->ax = 0
    self->az = 0
    self->travel = 0
    game->player2 = self

def allefant_onload(Block *super):
    Allefant *self = (void *)super
    float mind = -1
    for int i in range(game->waypoints_count):
        float x = game->waypoints[i][0] - super.x
        float z = game->waypoints[i][2] - super.z
        float d = x * x + z * z
        if mind < 0 or d < mind:
            mind = d
            self.waypoint = i

def allefant_destroy(Block *super):
    game->player2 = None
    block_destroy(super)

def allefant_tick(Block *super):
    Allefant *self = (void *)super
    float speed = 1.4

    if self->wait > 0:
        if self->step != 8 and self->step != 24:
            self->step += 1
            self->step &= 31
        self->wait -= 1

        if self->wait == 0:
            if self->waypoint >= game->waypoints_count:
                self->waypoint = 0

            self->tx = game->waypoints[self->waypoint][0]
            self->tz = game->waypoints[self->waypoint][2]
            self->waypoint += 1
            self->travel = 0
                
    else:

        float x = self->tx - super->x
        float z = self->tz - super->z
        float d = pow(x * x + z * z, 0.5)
        if d > 3:
            self->ax = x / d
            self->az = z / d
            
            float angle = atan2(self->ax, self->az) - pi / 4
            angle = angle / (2 * pi)
            angle = (int)((angle - floor(angle)) * 8 + 0.5) & 7
            self->want_direction = angle

            if self->travel <= 0:
                self->travel = d / speed
        else:
            self->wait = 60 * 2

        super->dx += self->ax * speed
        super->dz += self->az * speed

        self->step += 1
        self->step &= 31

        self->travel -= 1

        if self->travel <= 0:
            self->wait = 60 * 4

    if self->want_direction != self->direction:
        self->rotstep += 1
        if self->rotstep >= 4:
            self->rotstep = 0
            int d = self->want_direction - self->direction

            if d < -4: d += 8
            elif d > 4: d -= 8
            if abs(d) == 4: self->direction += (land_rand(0, 1)) * 2 - 1
            elif d < 0: self->direction -= 1
            elif d > 0: self->direction += 1
            self->direction &= 7

    super->frame = self->direction * 8 + self->step / 4
    block_tick((void *)self)

def allefant_touch(Block *super, Block *c, float dx, dy, dz):
    if dy < 0:
        if c->block_type == Render_Plate:
            c->frame = 1
    if c->block_type == Render_Scientist:
        # we can ride on top
        if c->y < super.y + super.ys - 1:
            ((Player *)c)->dead = True

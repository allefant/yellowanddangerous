import random
from block import *
import game
from math import *
import render

class Player(Block):
    def __init__(self, blocks, x, y, z, kind):
        super().__init__(blocks, x, y, z, kind)
        self.step = 0
        self.direction = 0
        self.want_direction = 0
        self.rotstep = 0
        self.pull = False # jump key pressed with no direction keys pressed
        self.reverse = False # started moving in backwards direction
        self.stack = []
        self.pushing = False
        self.dead = False

    def try_pull(self, px, pz):
        ox = self.x
        oz = self.z
        
        self.x -= px * 3
        self.z -= pz * 3
        pulls = self.colliders()
        self.x = ox
        self.z = oz

        for p in pulls:
            if not p.block_type.dynamic: continue
            if p.pull(px, 0, pz):
                self.dx = 0
                self.dz = 0
                self.pushing = True

    def grab(self):
        ox = self.x
        oz = self.z

        px = sin((self.want_direction + 1) * pi / 4)
        pz = cos((self.want_direction + 1) * pi / 4)

        self.x += px * 3
        self.z += pz * 3
        grabs = self.colliders()

        self.x = ox
        self.z = oz

        dynamic = [x for x in grabs if x.block_type.lift]
        if dynamic:
            return [max(dynamic, key = lambda x: x.y)]
        return []

    def lift(self):
        for p in self.stack:
            # don't want to be able to walk under it
            if p.y + 1 < self.y + self.ys:
                if p.pull(0, 1, 0):
                    p.no_fall = True
                    p.dy = 0

    def tick(self):

        a = game.game.a

        x = 0
        z = 0
        if a.up: x -= 1; z -= 1
        if a.down: x += 1; z += 1
        if a.left: x -= 1; z += 1
        if a.right: x += 1; z -= 1

        d = (x * x + z * z) ** 0.5
        if d > 0 and not self.stack:

            x /= d
            z /= d
            angle = atan2(x, z) - pi / 4
            angle = angle / (2 * pi)
            angle = int((angle - floor(angle)) * 8 + 0.5) & 7

            self.want_direction = angle

            if self.ground and a.jump:
                if self.pull:
                    if not self.reverse:
                        self.stack = self.grab()
                        if self.stack:
                            x = z = 0
                            self.dx = 0
                            self.dz = 0
                            self.pull = False
                        else:
                            self.reverse = True

                    if self.reverse:
                        self.want_direction += 4
                        self.want_direction &= 7
                        
                elif a.jump:
                    self.dy += 20
                    a.sound("uhg", 1)
            
            x *= 2
            z *= 2

            self.dx += x
            self.dz += z

            self.step += 1
            self.step &= 31

            if self.step == 9 or self.step == 25:
                if self.ground: a.sound("step", 0.3)

        else:
            if self.step != 8 and self.step != 24:
                self.step += 1
                self.step &= 31

            if self.ground and a.jump:
                self.pull = True

        if self.pushing:
            if a.game.ticks % 8 == 1:
                a.sound("push", 0.3)
                self.pushing = False

        if self.want_direction != self.direction:
            self.rotstep += 1
            if self.rotstep >= 4:
                self.rotstep = 0
                d = self.want_direction - self.direction

                if d < -4: d += 8
                elif d > 4: d -= 8
                if abs(d) == 4: self.direction += (random.randint(0, 1)) * 2 - 1
                elif d < 0: self.direction -= 1
                elif d > 0: self.direction += 1
                self.direction &= 7
        
        self.frame = self.direction * 8 + self.step // 4

        px = self.dx
        pz = self.dz
        super().tick()

        if self.pull:
            if not a.jump:
                self.pull = False
                self.reverse = False

            if px or pz:
                self.try_pull(px, pz)

        if self.stack:
            if not a.jump:
                while self.stack:
                    b = self.stack.pop()
                    b.no_fall = False
            else:
                self.lift()

    def touch(self, c, dx, dy, dz):
        r = render.Render
        if dy < 0:
            if c.block_type is r.Plate:
                c.frame = 1
            elif c.block_type in [r.ExitLeft, r.ExitRight]:
                if c.frame == 1:
                    game.game.level_done()
        if dx != 0 or dz != 0:
            if c.block_type.dynamic:
                self.pushing = True

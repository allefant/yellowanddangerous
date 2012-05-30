import random
from block import *
import game, render
from math import *

class Allefant(Block):
    def __init__(self, blocks, x, y, z, kind):
        super().__init__(blocks, x, y, z, kind)
        self.step = 0
        self.direction = 0
        self.want_direction = 0
        self.rotstep = 0
        self.waypoint = 1
        self.wait = 60 * 2
        self.tx, self.tz = x, z
        self.ax = 0
        self.az = 0
        self.travel = 0

    def tick(self):

        if self.wait > 0:
            if self.step != 8 and self.step != 24:
                self.step += 1
                self.step &= 31
            self.wait -= 1

            if self.wait == 0:
                if self.waypoint not in game.game.waypoints:
                    self.waypoint = 0
                if self.waypoint in game.game.waypoints:
                    self.tx, _, self.tz = game.game.waypoints[self.waypoint]
                    self.waypoint += 1
                    self.travel = 0
                    
        else:

            x = self.tx - self.x
            z = self.tz - self.z
            d = (x * x + z * z) ** 0.5
            if d > 1:
                self.ax = x / d
                self.az = z / d
                
                angle = atan2(self.ax, self.az) - pi / 4
                angle = angle / (2 * pi)
                angle = int((angle - floor(angle)) * 8 + 0.5) & 7
                self.want_direction = angle

                if self.travel == 0:
                    self.travel = d
            else:
                self.wait = 60 * 2

            self.dx += self.ax
            self.dz += self.az

            self.step += 1
            self.step &= 31

            self.travel -= 1

            if self.travel < 0:
                self.wait = 60 * 4

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
        super().tick()

    def touch(self, c, dx, dy, dz):
        r = render.Render
        if dy < 0:
            if c.block_type is r.Plate:
                c.frame = 1
        if c.block_type is r.Scientist:
            c.dead = True

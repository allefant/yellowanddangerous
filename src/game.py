import random, array
from math import *
import main
from land import *
import block
from isometric import *
import render
import level, cube
from player import *
from allefant import *

class Game:
    def __init__(self):
        self.viewport = Viewport(land_display_width() / 2,
            land_display_height() / 2)

        self.level = level.start

        render.Render.setup()

        self.blocks = block.Blocks()

        self.reset()

    def reset(self):
        self.state = "play"
        self.ticks = 0
        self.state_tick = 0
        self.waypoints = {}
        self.read_level(getattr(level, "room{}".format(self.level)))

    def read_level(self, level):
        self.blocks.reset()
        
        e = 0
        s = 96 / sqrt(2)
        S = -4.25

        rows = level.splitlines()[1:]
        for y in range(6):
            for z in range(12):
                for x in range(12):
                    c = rows[z][x + 12 * y]

                    rx = x - 1
                    ry = max(0, y - 1)
                    rz = z - 1
                    xp = (rx + S) * s
                    yp = ry * (s + e)
                    zp = (rz + S) * s
                  
                    self.make_block(c, xp, yp, zp)
                
    def make_block(self, c, xp, yp, zp):
        r = render.Render

        def make(t):
            if t.dynamic:
                b = Block(self.blocks, xp + 0.1, yp, zp + 0.1, t)
            else:
                b = Block(self.blocks, xp, yp, zp, t)
            return b

        if c == "_":
            b = make(r.BlockBottom2)
            b.y -= b.ys
            b.add()
        if c == "-":
            b = make(r.BlockBottom3)
            b.y -= b.ys
            b.add()
        if c == "~":
            b = make(r.BlockBottomLeft3)
            b.y -= b.ys
            b.add()
        if c == "*":
            make(r.Cube2).add()
        if c == "+":
            b = make(r.Cube2)
            b.y -= b.ys
            b.add()
        if c == "#":
            make(r.Block).add()
        if c == ":":
            b = make(r.BlockBottom)
            b.y -= b.ys
            b.add()
        if c == "'":
            b = make(r.BlockSmall3)
            b.y -= b.ys
            b.add()
        if c == "/":
            make(r.BlockLeft2).add()
        if c == "\\":
            make(r.BlockRight2).add()
        if c == "]":
            make(r.BlockRight).add()
        if c == "[":
            make(r.BlockLeft).add()
        if c == "}":
            make(r.BlockRight4).add()
        if c == "{":
            make(r.BlockLeft4).add()
        if c == 'S':
            self.player = Player(self.blocks, xp, yp, zp, r.Scientist)
            self.player.add()
        if c == '♥':
            cube.Cube(self.blocks, xp, yp, zp, r.Cube3).add()
        if c == "=":
            make(r.Bridge).add()
        if c == "$":
            make(r.Bridge2).add()
        if c == 'x':
            b = make(r.Plate)
            b.y -= b.ys
            b.add()
        if c == 'O':
            make(r.Barrel).add()
        if c == 'T':
            make(r.TreeBottom).add()
        if c == 't':
            make(r.TreeTop).add()
        if c == '!':
            make(r.Trunk).add()
        if c == 'e':
            b = make(r.ExitLeft)
            b.y -= b.ys
            b.add()
        if c == 'ə':
            b = make(r.ExitRight)
            b.y -= b.ys
            b.add()
        if c == 'A':
            self.player2 = Allefant(self.blocks, xp, yp, zp, r.Allefant)
            self.player2.add()
            self.waypoints[0] = xp, yp, zp
        if c in "123456789":
            self.waypoints[int(c)] = xp, yp, zp

    def was_a_stupid_idea(self):
        e = 0.1
        s = 96 / sqrt(2)
        S = -4.25

        j = 0
        height = 0
        for row in level.room1.splitlines():
            x = S * s
            i = 0
            for i, c in enumerate(row):

                i2 = (i - 21)
                j2 = (j - 6)
                x = i2 / 4 + j2 / 2
                y = 0
                z = j2 / 2 - i2 / 4
                
                if x - floor(x) > 0.1 or z - floor(z) > 0.1:
                    if height == 0: continue
                    if c in " _\\/": continue
                    rx = round((x - floor(x)) * 4)
                    rz = round((z - floor(z)) * 4)
                    x = floor(x)
                    z = floor(z)
                    if rx == 1 and rz == 3:
                        y += 2
                    if rx == 2 and rz == 2:
                        y += 1
                    if rx == 3 and rz == 1:
                        y += 3

                if x < 0:
                    z -= x
                    y += -x - 1
                    x = 0

                if z < 0:
                    x -= z
                    y += -z - 1
                    z = 0

                xp = (x + S) * s
                yp = y * (s - e)
                zp = (z + S) * s
              
                self.make_block(c, xp, yp, zp)
                

            j += 1
            if j == 28:
                j = 6
                height += 1

        #block.blocks_static.sort(key = lambda b: -b.y)

    def level_done(self):
        if self.state == "play":
            self.state = "done"
            self.state_tick = self.ticks
            self.a.sound("teleport", 1)

    def tick(self):
        r = render.Render

        if self.state in ["done", "died"]:
            if self.ticks > self.state_tick + 30:
                if self.state == "done": self.level += 1
                self.reset()

        plates_count = 0
        plates_on_before = 0

        if hasattr(self, "player"):

            if self.state == "play":
                if self.player.dead or self.player.y < -960:
                    self.a.sound("oh_no", 1)
                    self.state = "died"


        for b in self.blocks.static:
            if b.block_type == r.Plate:
                if b.frame == 1:
                    plates_on_before += 1
                b.frame = 0
                plates_count += 1
            
        for b in self.blocks.dynamic:
            b.tick()

        plates_on = 0
        for b in self.blocks.static:
            if b.block_type == r.Plate:
                if b.frame == 1:
                    plates_on += 1
            elif b.block_type in [r.ExitLeft, r.ExitRight]:
                b.frame = 0

        if plates_on > plates_on_before:
            a.sound("on", 1)

        if plates_on < plates_on_before:
            a.sound("off", 1)

        if plates_count == plates_on:
            for b in self.blocks.static:
                if b.block_type in [r.ExitLeft, r.ExitRight]:
                    b.frame = 1

        self.ticks += 1

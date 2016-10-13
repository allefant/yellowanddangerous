#!/usr/bin/env python3
import os, sys
import colors
path = lambda x: "data/levels/level{:02}.txt".format(1 + x)

class Exit:
    def __init__(self, level, t, x, y, z):
        level.exits.append(self)
        self.t = t
        self.x = int(x)
        self.y = int(y)
        self.z = int(z)
        # 0 = locked
        # 1 = open
        # 2 = open from this side
        # 3 = open from other side
        # 4 = shut permanently
        self.frame = 0
        self.side = None

        if t == 18 and self.x == 45:
            self.side = "right"
        if t == 18 and self.x == 1:
            self.side = "left"
        if t == 19 and self.z == 45:
            self.side = "down"
        if t == 19 and self.z == 1:
            self.side = "up"

    def framestring(self):
        if self.frame == 0:
            return colors.bash("back black") + "    " + colors.bash("end")
        if self.frame == 1:
            return colors.bash("back black") + colors.bash("bright yellow") + "EXIT" + colors.bash("end")
        if self.frame == 2:
            return colors.bash("back bright yellow") + "    " + colors.bash("end")
        if self.frame == 3:
            return colors.bash("back yellow") + "    " + colors.bash("end")
        return colors.bash("back red") + colors.bash("bright red") + "EXIT" + colors.bash("end")

    def typestring(self):
        if self.t == 18:
            return "_.-´"
        if self.t == 19:
            return "`-._"
        return "++++"

levels = {}
class Level:
    size = 40
    
    @staticmethod
    def num(x, y):
        return x + y * 7

    @staticmethod
    def x(i):
        return i % 7

    @staticmethod
    def y(i):
        return i // 7

    def __init__(self, i):
        levels[i] = self
        self.i = i
        self.exits = []

    def right(self):
        return self.num((self.x(self.i) + 1) % 7, self.y(self.i))

    def left(self):
        return self.num((self.x(self.i) - 1 + 7) % 7, self.y(self.i))

    def up(self):
        return self.num(self.x(self.i), (self.y(self.i) - 1 + 7) % 7)

    def down(self):
        return self.num(self.x(self.i), (self.y(self.i) + 1) % 7)

def check_exit(i, f):
    rows = open(f).read().splitlines()
    l = Level(i)

    e = None
    for row in rows:
        if row.startswith("make 18"):
            e = Exit(l, 18, *row[7:].split())
        elif row.startswith("make 19"):
            e = Exit(l, 19, *row[7:].split())
        elif e:
            if row.startswith("frame"):
                e.frame = int(row[6:])
            elif row.startswith("make"):
                e = None

def find_exits():
    for i in range(49):
        if os.path.exists(path(i)):
            check_exit(i, path(i))

def main():
    find_exits()

    for i in range(49):
        l = levels[i]
        for e in levels[i].exits:
            if e.frame == 4:
                continue
            info =   "%2d %s %s %d/%d/%d" % (1 + i, e.typestring(), e.framestring(), e.x, e.y, e.z)
            if e.t == 18 and e.x == 45:
                x = levels[l.right()]
                for e2 in x.exits:
                    if e2.z == e.z and e2.y == e.y and e2.x == 1:
                        print(colors.bash("green"), "+", colors.bash("end"), info)
                        break
                else:
                    print(colors.bash("back red"), "-", colors.bash("end"), info)
            elif e.t == 18 and e.x == 1:
                x = levels[l.left()]
                for e2 in x.exits:
                    if e2.z == e.z and e2.y == e.y and e2.x == 45:
                        print(colors.bash("green"), "+", colors.bash("end"), info)
                        break
                else:
                    print(colors.bash("back red"), "-", colors.bash("end"), info)
            elif e.t == 19 and e.z == 45:
                x = levels[l.down()]
                for e2 in x.exits:
                    if e2.x == e.x and e2.y == e.y and e2.z == 1:
                        print(colors.bash("green"), "+", colors.bash("end"), info)
                        break
                else:
                    print(colors.bash("back red"), "-", colors.bash("end"), info)
            elif e.t == 19 and e.z == 1:
                x = levels[l.up()]
                for e2 in x.exits:
                    if e2.x == e.x and e2.y == e.y and e2.z == 45:
                        print(colors.bash("green"), "+", colors.bash("end"), info)
                        break
                else:
                    print(colors.bash("back red"), "-", colors.bash("end"), info)
            else:
                print(colors.bash("yellow"), "?", colors.bash("end"), info)
    
if __name__ == "__main__":
    main()

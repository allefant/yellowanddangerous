#!/usr/bin/env python3
import os, sys
import colors
import check_exits

class Path:
    pass

def main():
    check_exits.find_exits()

    p = Path()

    steps = []

    def add(neighbor):
        if (neighbor, p.current, p.prev) in p.cannot:
            return
        p.poss.add((neighbor, p.current))

    def cannot(goto = [], ifin = 0, comefrom = []):
        for g in goto:
            for cf in comefrom:
                p.cannot.add((g, ifin, cf))

    levels = check_exits.levels
    p.poss = set()
    p.already = set()
    p.cannot = set()
    p.poss.add((22, 0))
    cannot(goto = [35, 41], ifin = 34, comefrom = [27, 33])
    cannot(goto = [40, 46], ifin = 39, comefrom = [32, 38])
    cannot(goto = [2, 4], ifin = 3, comefrom = [45])
    while True:
        p.poss = p.poss.difference(p.already)
        if not p.poss:
            break
        steps.append((set(p.poss), set(p.already)))
        p.already = p.already.union(p.poss)
        old = p.poss.copy()
        p.poss = set()
        for li, lprev in old:
            p.prev = lprev
            p.current = li
            l = levels[li - 1]
            for e in l.exits:
                if e.side == "right":
                    if e.frame in [0, 1, 2]:
                        add(1 + l.right())
                if e.side == "left":
                    if e.frame in [0, 1, 2]:
                        add(1 + l.left())
                if e.side == "up":
                    if e.frame in [0, 1, 2]:
                        add(1 + l.up())
                if e.side == "down":
                    if e.frame in [0, 1, 2]:
                        add(1 + l.down())

    for s, a in steps:
        draw_map(s, a)

def draw_map(current, a):
    a = {x[0] for x in a}
    s = {x[0] for x in current}
    p = {x[1] for x in current}
    for i in range(7):
        for j in range(7):
            lev = 1 + j + i * 7
            if lev in s:
                c = "X"
            elif lev in p:
                c = "x"
            elif lev in a:
                c = "."
            else:
                c = " "
            print(c, end = "")
        print()
    print("-------")

if __name__ == "__main__":
    main()

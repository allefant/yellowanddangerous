#!/usr/bin/env python3
import os, sys
path = lambda x: "data/levels/level{:02}.txt".format(x)

def align(f):
    rows = open(f).read().splitlines()
    rows2 = []
    watch = False
    for row in rows:
        if row.startswith("make 12"):
            watch = True
        elif watch and row.startswith("move"):
            print("misaligned:", f, row)
            continue
        rows2.append(row)
    out = open(f, "w")
    for row in rows2:
        out.write(row + "\n")

for i in range(50):
    if os.path.exists(path(i)):
        align(path(i))


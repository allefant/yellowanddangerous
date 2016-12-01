#!/usr/bin/env python3
import os, sys
path = lambda x: "data/levels/level{:02}.txt".format(x)

def align(f):
    rows = open(f).read().splitlines()
    rows2 = []
    make = ""
    watch = False
    for row in rows:
        if row.startswith("make "):
            watch = True
            make = row
        elif watch and row.startswith("move"):
            print("misaligned:", f, make, row)
            continue
        rows2.append(row)
    out = open(f, "w")
    for row in rows2:
        out.write(row + "\n")

for i in range(50):
    if os.path.exists(path(i)):
        align(path(i))


#!/usr/bin/env python3
import os, sys
path = lambda x: "data/levels/level{:02}.txt".format(x)

def move(a, b):
    print(a, "->", b)
    os.rename(a, b)

if sys.argv[1] == "rotatez":
    for i in range(1, 8):
        if os.path.exists(path(i)):
            move(path(i), path(i + 14))

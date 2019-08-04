#!/usr/bin/env python3
import glob
import PIL.Image as pim
import os
path = "data/yellowanddangerous"
ini = open(path + "/offsets.ini", "w")
for pic in glob.glob(path + "/*/*.png"):
    im = pim.open(pic)
    name = pic[len(path) + 1:]
    w, h = im.size
    x = w / 2
    y = h / 2
    l, t, r, b = im.getbbox()
    x -= l
    y -= t
    im = im.crop((l, t, r, b))
    im.save(pic)
    ini.write("[" + name + "]\n")
    ini.write("x = " + str(x) + "\n")
    ini.write("y = " + str(y) + "\n")

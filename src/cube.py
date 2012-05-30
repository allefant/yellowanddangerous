import random
from block import *
import game, render
from math import *

class Cube(Block):
    def __init__(self, blocks, x, y, z, kind):
        super().__init__(blocks, x, y, z, kind)

    def touch(self, c, x, y, z):
        if y < 0 and c.block_type is render.Render.Plate:
            c.frame = 1

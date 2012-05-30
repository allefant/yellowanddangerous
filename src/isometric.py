from math import *

class Viewport:

    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def project(self, x, y, z):
        s = 1 / sqrt(2)
        t = sqrt(3)
        sx = self.x + x * s - z * s
        sy = self.y + (x * s - y * t + z * s) * 0.5
        return sx, sy

    def unproject_xz(sx, sy):
        s = sqrt(2)

        sx -= self.x
        sy -= self.y

        z = (sy - sx * 0.5) * s
        x = (sx * 0.5 + sy) * s

        return x, z

    def unproject_xy(sx, sy):
        s = sqrt(2)
        t = 1 / sqrt(3)

        sx -= self.x
        sy -= self.y

        x = sx * s
        y = sx * t - 2 * sy * t

        return x, y

    def unproject_xy(sx, sy):
        s = sqrt(2)
        t = 1 / sqrt(3)

        sx -= self.x
        sy -= self.y

        y = sx * t - 2 * sy * t
        z = -sx * s

        return y, z



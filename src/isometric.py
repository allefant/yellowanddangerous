import common

#
#       
#              0
#            __--__
#    +Z __--      --__ +X
#          --__  __--
#              --
#       
#

class Viewport:
    float x, y
    float zoom

Viewport *def viewport_new(float w, h):
    Viewport *self
    land_alloc(self)
    viewport_update(self, w, h)
    return self

def viewport_update(Viewport *self, float w, h):
    self.zoom = w / 960
    self->x = w / 2 / self.zoom
    self->y = h / 2 / self.zoom

def project(Viewport *self, float x, y, z, *sx, *sy):
    float s = 1 / 2.0
    float t = sqrt(3) / sqrt(2)
    *sx = self.x + x * s - z * s
    *sy = self.y + (x * s - y * t + z * s) * 0.5

def unproject(Viewport *self, float sx, sy, y, *x, *z):
    float s = 1 / 2.0
    float t = sqrt(3) / sqrt(2)

    *x = ((sx - self.x) / 2.0 + sy - self.y + y * t / 2.0) / s
    *z = ((sx - self.x) / -2.0 + (sy - self.y) + y * t / 2.0) / s

def unproject_y(Viewport *self, float sy, x, z, *y):
    float s = 1 / 2.0
    float t = sqrt(3) / sqrt(2)
    *y = ((sy - self.y) * 2 - x * s - z * s) / -t

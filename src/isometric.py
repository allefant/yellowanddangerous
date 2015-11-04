import common

class Viewport:
    float x, y
    float zoom

Viewport *def viewport_new:
    Viewport *self
    land_alloc(self)
    viewport_update(self)
    return self

def viewport_update(Viewport *self):
    float w = land_display_width()
    float h = land_display_height()
    self.zoom = w / 960
    self->x = w / 2 / self.zoom
    self->y = h / 2 / self.zoom

def project(Viewport *self, float x, y, z, *sx, *sy):
    float s = 1 / sqrt(2)
    float t = sqrt(3)
    *sx = self->x + x * s - z * s
    *sy = self->y + (x * s - y * t + z * s) * 0.5

def unproject_xz(Viewport *self, float sx, sy, *x, *z):
    float s = sqrt(2)

    sx -= self->x
    sy -= self->y

    *z = (sy - sx * 0.5) * s
    *x = (sx * 0.5 + sy) * s

def unproject_xy(Viewport *self, float sx, sy, *x, *y):
    float s = sqrt(2)
    float t = 1 / sqrt(3)

    sx -= self->x
    sy -= self->y

    *x = sx * s
    *y = sx * t - 2 * sy * t

def unproject_yz(Viewport *self, float sx, sy, *y, *z):
    float s = sqrt(2)
    float t = 1 / sqrt(3)

    sx -= self->x
    sy -= self->y

    *y = sx * t - 2 * sy * t
    *z = -sx * s



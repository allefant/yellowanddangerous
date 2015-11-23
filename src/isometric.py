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

    if global_a->overview:
        self.zoom /= 8

def project(Viewport *self, float x, y, z, *sx, *sy):
    float s = 1 / 2.0
    float t = sqrt(3) / sqrt(2)
    *sx = self->x + x * s - z * s
    *sy = self->y + (x * s - y * t + z * s) * 0.5



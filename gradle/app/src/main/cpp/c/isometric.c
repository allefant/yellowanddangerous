/* This file was generated by scramble.py. */
#line 1 "src/isometric.py"
#include "isometric.h"
//
//
//              0
//            __--__
//    +Z __--      --__ +X
//          --__  __--
//              --
//
//
#line 17
Viewport* viewport_new(float w, float h) {
    Viewport * self;
    land_alloc(self);
    viewport_update(self, w, h);
    return self;
}
void viewport_update(Viewport * self, float w, float h) {
    self->zoom = w / 960;
    self->x = w / 2 / self->zoom;
    self->y = h / 2 / self->zoom;
}
void project(Viewport * self, float x, float y, float z, float * sx, float * sy) {
    float s = 1 / 2.0;
    float t = sqrt(3) / sqrt(2);
    * sx = self->x + x * s - z * s;
    * sy = self->y + (x * s - y * t + z * s) * 0.5;
}
void unproject(Viewport * self, float sx, float sy, float y, float * x, float * z) {
    float s = 1 / 2.0;
    float t = sqrt(3) / sqrt(2);
#line 38
    * x = ((sx - self->x) / 2.0 + sy - self->y + y * t / 2.0) / s;
    * z = ((sx - self->x) / (- 2.0) + (sy - self->y) + y * t / 2.0) / s;
}
void unproject_y(Viewport * self, float sy, float x, float z, float * y) {
    float s = 1 / 2.0;
    float t = sqrt(3) / sqrt(2);
    * y = ((sy - self->y) * 2 - x * s - z * s) / (- t);
}
/* This file was generated by scramble.py. */
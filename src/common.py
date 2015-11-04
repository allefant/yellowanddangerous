import land.land

class All:
    int FPS
    int w, h
    LandFont *font
    bool up, down, left, right, jump

    int ftpos
    double frame_times[60]
    float direct_speed_measure
        
    bool mouse_down
    int mx, my

    bool show_fps, running
    bool show_help

    int cheatpos

    LandColor text

def print(char const *str, ...):
    va_list args
    va_start(args, str)
    vprintf(str, args)
    va_end(args)
    printf("\n")

macro pi LAND_PI

static All a
global All *global_a = &a

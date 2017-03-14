import land.land
import all

def print(char const *s, ...):
    va_list args
    va_start(args, s)
    vprintf(s, args)
    va_end(args)
    printf("\n")

macro pi LAND_PI

static All a
global All *global_a = &a

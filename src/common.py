import land.land
import all


def print(char const *str, ...):
    va_list args
    va_start(args, str)
    vprintf(str, args)
    va_end(args)
    printf("\n")

macro pi LAND_PI

static All a
global All *global_a = &a

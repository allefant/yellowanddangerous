/* This file was generated by scramble.py. */
#line 1 "src/common.py"
#include "common.h"
#line 4
void print(char const * s, ...) {
    va_list args;
    va_start(args, s);
    vprintf(s, args);
    va_end(args);
    printf("\n");
}
#line 13
static All a;
All * global_a = & a;
/* This file was generated by scramble.py. */

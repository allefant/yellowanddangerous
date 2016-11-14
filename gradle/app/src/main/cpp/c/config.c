/* This file was generated by scramble.py. */
#line 1 "src/config.py"
#include "config.h"
#line 3
char const * VERSION = "1.16";
bool global_can_enable_editor = 1;
#line 17
Controls controls;
#line 19
void config_controls_read(void) {
    controls.c [ControlLeft] [0] = LandKeyLeft;
    controls.c [ControlLeft] [1] = 'a';
    controls.c [ControlRight] [0] = LandKeyRight;
    controls.c [ControlRight] [1] = 'd';
    controls.c [ControlUp] [0] = LandKeyUp;
    controls.c [ControlUp] [1] = 'w';
    controls.c [ControlDown] [0] = LandKeyDown;
    controls.c [ControlDown] [1] = 's';
    controls.c [ControlJump] [0] = LandKeyLeftControl;
    controls.c [ControlJump] [1] = LandKeyRightControl;
}
void config_check_controls(All * a) {
    for (int j = 0; j < ControlCount; j += 1) {
        controls.down [j] = 0;
        for (int i = 0; i < 3; i += 1) {
            if (land_key(controls.c [j] [i])) {
#line 35
                controls.down [j] = 1;
            }
        }
    }
#line 36
    a->left = controls.down [ControlLeft];
    a->right = controls.down [ControlRight];
    a->up = controls.down [ControlUp];
    a->down = controls.down [ControlDown];
    a->jump = controls.down [ControlJump];
}
/* This file was generated by scramble.py. */

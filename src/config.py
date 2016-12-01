import common

global char const *VERSION = "1.23"
global bool global_can_enable_editor = True

enum:
    ControlLeft
    ControlRight
    ControlUp
    ControlDown
    ControlJump
    ControlCount

class Controls:
    int c[ControlCount][3]
    bool down[ControlCount]
Controls controls

def config_controls_read():
    controls.c[ControlLeft][0] = LandKeyLeft
    controls.c[ControlLeft][1] = 'a'
    controls.c[ControlRight][0] = LandKeyRight
    controls.c[ControlRight][1] = 'd'
    controls.c[ControlUp][0] = LandKeyUp
    controls.c[ControlUp][1] = 'w'
    controls.c[ControlDown][0] = LandKeyDown
    controls.c[ControlDown][1] = 's'
    controls.c[ControlJump][0] = LandKeyLeftControl
    controls.c[ControlJump][1] = LandKeyRightControl

def config_check_controls(All *a):
    for int j in range(ControlCount):
        controls.down[j] = False
        for int i in range(3):
            if land_key(controls.c[j][i]): controls.down[j] = True
    a.left = controls.down[ControlLeft]
    a.right = controls.down[ControlRight]
    a.up = controls.down[ControlUp]
    a.down = controls.down[ControlDown]
    a.jump = controls.down[ControlJump]

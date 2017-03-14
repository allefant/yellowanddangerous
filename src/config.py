import common

global char const *VERSION = "1.23"
global bool global_can_enable_editor = False
global bool global_use_touch_input = False

enum:
    FoundNothing
    FoundButton
    FoundAxis

enum:
    ControlNone
    ControlLeft
    ControlRight
    ControlUp
    ControlDown
    ControlJump
    ControlMenu
    ControlUnused
    ControlCount

class Controls:
    int c[ControlCount][3]
    int down[ControlCount]
    int pressed[ControlCount]
    int axis[ControlCount][2] # number, inverted
    int button[ControlCount]
global Controls controls

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
    controls.c[ControlJump][2] = LandKeyEnter
    controls.c[ControlMenu][0] = LandKeyBackspace

def config_check_controls(All *a):
    for int j in range(ControlCount):
        controls.pressed[j] = not controls.down[j]
        controls.down[j] = False
        for int i in range(3):
            if land_key(controls.c[j][i]): controls.down[j] = True
        float threshold = controls.axis[j][1] / 100.0
        if land_joystick_axis(controls.axis[j][0]) * threshold > threshold * threshold:
            controls.down[j] = True
        if land_joystick_button(controls.button[j]):
            controls.down[j] = True
        if not controls.down[j]:
            controls.pressed[j] = False
    a.left = controls.down[ControlLeft]
    a.right = controls.down[ControlRight]
    a.up = controls.down[ControlUp]
    a.down = controls.down[ControlDown]
    a.jump = controls.down[ControlJump]

def config_joystick_control(int control, int progress) -> int:
    if progress == 0:
        controls.axis[control][0] = 0
        controls.axis[control][1] = 0
        controls.button[control] = 0

    int an = land_joystick_axis_count()
    for int ai in range(1, an):
        float a = land_joystick_axis(ai)
        float d = land_joystick_delta_axis(ai)
        if fabs(a) > 0.2 and (fabs(d) > 0 or ai == controls.axis[control][0]):
            if fabs(a * 25) > fabs(controls.axis[control][1]):
                controls.axis[control][0] = ai
                controls.axis[control][1] = a * 25
            return FoundAxis
    int bn = land_joystick_button_count()
    for int bi in range(1, bn):
        if land_joystick_button_pressed(bi):
            controls.button[control] = bi
            # initialize state for the new control
            controls.down[control] = True
            controls.pressed[control] = 0
            return FoundButton
    return FoundNothing
        
def config_print_controls(LandFile *f):
    for int j in range(ControlCount):
        land_file_print(f, "control %d 0 %d %d", j,
            controls.axis[j][0], controls.axis[j][1])
        land_file_print(f, "control %d 1 %d 0", j,
            controls.button[j])

def config_read_controls(str row):
    if land_starts_with(row, "control "):
        int a, b, c, d
        sscanf(row, "control %d %d %d %d", &a, &b, &c, &d)
        if b == 0:
            controls.axis[a][0] = c
            controls.axis[a][1] = d
        elif b == 1:
            controls.button[a] = c

def control_name(int c) -> str:
    if controls.button[c]: return land_joystick_button_name(controls.button[c])
    if controls.axis[c][0]: return land_joystick_axis_name(controls.axis[c][0])
    return "none"

import common

global char const *VERSION = "1.26"
global bool global_can_enable_editor = False
global bool global_use_touch_input = True

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
    int c[ControlCount][3] # key alt-key alt-key-2
    int down[ControlCount]
    float strength[ControlCount]
    int pressed[ControlCount]
    int axis[ControlCount][3] # number, threshold (+/-)
    float detection[LandJoystickAxesCount]
    float zero[LandJoystickAxesCount]
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

    int an = land_joystick_axis_count()
    for int ai in range(1, an):
        str axis = land_joystick_axis_name(ai)
        if land_equals("Stick 1 X", axis) or\
                land_equals("Left Thumbstick X", axis):
            controls.axis[ControlLeft][0] = ai
            controls.axis[ControlLeft][1] = -25
            controls.axis[ControlRight][0] = ai
            controls.axis[ControlRight][1] = 25
        if land_equals("Stick 1 Y", axis) or\
                land_equals("Left Thumbstick Y", axis):
            controls.axis[ControlUp][0] = ai
            controls.axis[ControlUp][1] = -25
            controls.axis[ControlDown][0] = ai
            controls.axis[ControlDown][1] = 25
    int bn = land_joystick_button_count()
    for int bi in range(1, bn):
        str button = land_joystick_button_name(bi)
        if land_equals("B1", button):
            controls.button[ControlJump] = bi
        if land_equals("B4", button):
            controls.button[ControlMenu] = bi
        if land_equals("A", button):
            controls.button[ControlJump] = bi
        if land_equals("Y", button):
            controls.button[ControlMenu] = bi

def config_check_controls(All *a):
    for int j in range(ControlCount):
        controls.pressed[j] = not controls.down[j]
        controls.down[j] = False
        controls.strength[j] = 0
        for int i in range(3):
            if land_key(controls.c[j][i]):
                controls.down[j] = True
                controls.strength[j] = 1
        float threshold = controls.axis[j][1] / 100.0
        if land_joystick_axis(controls.axis[j][0]) * threshold > threshold * threshold:
            controls.down[j] = True
            controls.strength[j] = fabs(land_joystick_axis(controls.axis[j][0]))
        if land_joystick_button(controls.button[j]):
            controls.down[j] = True
            controls.strength[j] = 1
        if not controls.down[j]:
            controls.pressed[j] = False
    a.left = controls.down[ControlLeft]
    a.right = controls.down[ControlRight]
    a.up = controls.down[ControlUp]
    a.down = controls.down[ControlDown]
    a.jump = controls.down[ControlJump]
    a.left_s = controls.strength[ControlLeft]
    a.right_s = controls.strength[ControlRight]
    a.up_s = controls.strength[ControlUp]
    a.down_s = controls.strength[ControlDown]

def config_joystick_control(int control, int progress) -> int:
    int an = land_joystick_axis_count()
     
    if progress == 0:
        controls.axis[control][0] = 0
        controls.axis[control][1] = 0
        for int ai in range(1, an):
            controls.detection[ai] = 0
            controls.zero[ai] = land_joystick_axis(ai)
        controls.button[control] = 0

    for int ai in range(1, an):
        float a = land_joystick_axis(ai)
        float d = land_joystick_delta_axis(ai)
        controls.detection[ai] += fabs(d)
        if fabs(a) > 0.2 and\
                (progress == 0 or controls.detection[ai] > 0.5) and\
                (fabs(d) > 0 or ai == controls.axis[control][0]):
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

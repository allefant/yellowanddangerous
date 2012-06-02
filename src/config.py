from land import *
class Controls: pass
controls = Controls()
controls.left = [LandKeyLeft, ord("a")]
controls.right = [LandKeyRight, ord("d")]
controls.up = [LandKeyUp, ord("w")]
controls.down = [LandKeyDown, ord("s")]
controls.jump = [LandKeyLeftControl, LandKeyRightControl]

def check_controls(a):
    for c in controls.__dict__:
        down = False
        for k in getattr(controls, c):
            if land_key(k): down = True
        setattr(a, c, down)

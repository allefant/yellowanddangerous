from allegro import *
class Controls: pass
controls = Controls()
controls.left = [ALLEGRO_KEY_LEFT, ALLEGRO_KEY_A]
controls.right = [ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_D]
controls.up = [ALLEGRO_KEY_UP, ALLEGRO_KEY_W]
controls.down = [ALLEGRO_KEY_DOWN, ALLEGRO_KEY_S]
controls.jump = [ALLEGRO_KEY_LCTRL, ALLEGRO_KEY_RCTRL]

def check_controls(a, event, down):
    for c in controls.__dict__:
        if event.keyboard.keycode in getattr(controls, c):
            setattr(a, c, down)

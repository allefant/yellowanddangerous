import common
import block
import game

class Editor:
    LandFloat mx, my
    float ox, oy, oz
    Block *picked

global Editor *editor

def editor_new:
    land_alloc(editor)

def editor_del:
    land_free(editor)
    editor = None

def editor_click(LandFloat mx, my, bool clicked, released) -> bool:

    if clicked:
        Block *p = blocks_pick(game.blocks, mx, my, game.viewport)
        if not p:
            editor.picked = None
            return False
        editor.mx = mx
        editor.my = my
        editor.ox = p.x
        editor.oy = p.y
        editor.oz = p.z
        editor.picked = p
        return True
    else:
        if editor.picked:

            LandFloat dx = mx - editor.mx
            LandFloat dy = my - editor.my

            dx /= game.viewport->zoom
            dy /= game.viewport->zoom

            float ang = (atan2(dy * 2, dx) + pi) * 8 / 2 / pi
            float r = sqrt(dx * dx + dy * dy)
            if r < 12:
                return True

            dx += dx * -12 / r
            dy += dy * -12 / r

            Block *p = editor.picked

            p.x = editor.ox
            p.y = editor.oy
            p.z = editor.oz

            float s = 24
            #       2 
            #    1     3
            #  0    *    4  
            #    7     5
            #       6
            if fabs(ang - 2) < 0.5 or fabs(ang - 6) < 0.5:
                float ox, oy, y
                project(game.viewport, p.x, p.y, p.z, &ox, &oy)
                unproject_y(game.viewport, oy + dy, p.x, p.z, &y)
                
                p.y = floor(y / s + 0.1) * s
            elif ang < 0.5 or ang > 7.5 or fabs(ang - 4) < 0.5:
                pass
            else:
                float ox, oy, x, z
                project(game.viewport, p.x, p.y, p.z, &ox, &oy)
                unproject(game.viewport, ox + dx, oy + dy, p.y, &x, &z)

                if fabs(x - p.x) > fabs(z - p.z):
                    p.x = floor(x / s + 0.1) * s
                else:
                    p.z = floor(z / s + 0.1) * s
            game_recalc()
            
            return True
    if released:
        return True
    return False

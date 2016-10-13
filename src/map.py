import game
import save
type Game *game

class MapRender:
    int l
    SaveInfo si[50]
    int current
    int count

    Block *flower[8]

static MapRender mr

def map_render:
    All *a = global_a
    float zoom = game.viewport->zoom
    land_reset_transform()
    land_scale(zoom, zoom)

    if mr.current != game.level:
        mr.current = game.level
        mr.l = mr.current
        mr.count = 0
    else:
        mr.l++
        if mr.l == 50:
            mr.l = 1

    float w = 960
    int i = game.level # want to draw it last
    for int i2 in range(1, 50):
        int x, z
        i++
        if i > 49:
            i = 1
        if i == mr.l and mr.count < 49:
            save_check(i, mr.si + i)
            mr.count++
            
        game_level_number_to_xz(i, &x, &z)
        float sx, sy
        # a level is 960
        float ls = 960.0 / 7 # level scale
        project(game.viewport, (x - 3) * ls, 0, (z - 3) * ls, &sx, &sy)
       
        land_color(0.5, 0.5, 0.5, 1)
        float s = w / 14
        float xy[8] = {sx, sy - s / 2, sx + s, sy, sx, sy + s / 2,
            sx - s, sy}
        land_filled_polygon(4, xy)

        if not mr.si[i].saved and i != game.level:
            continue

        #land_color(0, 0, 0, 1)
        #land_polygon(4, xy)

        #int dx[4] = {-1, 1, 0, 0}
        #int dz[4] = {0, 0, -1, 1}
        #for int j in range(4):
            #if mr.si[i].exits[j]:
                #s = w / 72

                #float ex, ey
                #project(game.viewport, (x - 3 + dx[j] * 0.5) * ls, 0,
                    #(z - 3 + dz[j] * 0.5) * ls, &ex, &ey)
                #float xy3[8] = {ex, ey - s / 2, ex + s, ey, ex, ey + s / 2,
                    #ex - s, ey}

                #if game.level == i:
                    #float c = (land_get_ticks() / 15) % 2
                    #land_premul(1, c, c, 1)
                #else:
                    #land_premul(1, 1, 1, 1)
                #land_filled_polygon(4, xy3)

                #land_color(0, 0, 0, 1)
                #if dx[j] != 0:
                    #land_line(xy3[0], xy3[1], xy3[2], xy3[3])
                    #land_line(xy3[4], xy3[5], xy3[6], xy3[7])
                #else:
                    #land_line(xy3[2], xy3[3], xy3[4], xy3[5])
                    #land_line(xy3[6], xy3[7], xy3[0], xy3[1])

        
        land_push_transform()
        land_translate(sx, sy)
        land_scale(1.0 / 9, 1.0 / 9)
        for int bi in range(0, mr.si[i].n, 14):
            
            float *bxy = mr.si[i].xy + bi

            if game.level == i:
                float c = (land_get_ticks() / 15) % 2
                land_premul(1, c, c, 1)
            else:
                land_premul(1, 1, 1, 1)
           
            land_filled_polygon(6, bxy)
            #land_color(0, 0, 0, 1)
            #land_polygon(6, bxy)

        land_pop_transform()


    float x, y
    project(game->viewport,
        0,
        0,
        900,
        &x, &y)
    land_text_pos(x, y)
    land_color(0, 0, 0, 1)
    if game.key:
        land_print("car keys found")
    else:
        land_print("no car keys")

    for int fi in range(1, 8):
        if not mr.flower[fi]:
            mr.flower[fi] = block_new(game->blocks, 0, 0, 0,
                block_flower(fi))
        mr.flower[fi]->x = -240 + fi * 72
        mr.flower[fi]->z = 720 #- fi * 60
        LandColor tint = a.tint
        if not game->flower[fi]:
            float c = (1 + sin(pi * 2 * land_get_ticks() / 60.0)) / 2
            a.tint.r = 0
            a.tint.g = 0
            a.tint.b = 0
            a.tint.a = 0.02 + 0.2 * c
        render_block_scaled(mr.flower[fi], game->viewport, .333)
       
        a.tint = tint

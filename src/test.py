import game
type Game *game
type All *global_a

def test -> bool:
    global_a.test = True
    render_setup_path()
    render_load_blocktypes()
    game_setup(1920, 1080)

    char result[50]
    int minduration[50]
    memset(result, ' ', sizeof result)
    memset(minduration, 0, sizeof minduration)

    int ok = 0, n = 0
    LandArray *tests = land_filelist("recordings", None, LAND_RELATIVE_PATH, None)

    for char *line in LandArray *tests:
        if land_equals(line, ""):
            continue
        int level, x, y, z
        sscanf(line, "recordings/record%02d_%04d%04d%04d.gz", &level, &x, &y, &z)
        int tick = 0
        if test_level(level, x, y, z, &tick):
            ok++
            if result[level] == ' ':
                result[level] = 'K'
        else:
            result[level] = 'F'
        minduration[level] = tick
        n++

    land_array_destroy_with_strings(tests)

    for int i in range(7):
        printf("%2d | ", 1 + i * 7)
        for int j in range(7):
            int k = 1 + j + 7 * i
            int d = minduration[k] / 360
            if d > 99: d = 99
            char const *col = color_bash(result[k] == 'F' ? "red" : "green")
            char const *end = color_bash("")
            printf("%s%c%s %d.%d | ", col, result[k], end, d / 10, d % 10)
        printf("\n")
        
    print("%d / %d successful", ok, n)
    return n == ok

def test_level(int level, x, y, z, int *tick) -> bool
    x = x - 22 * 24
    y = y - 4 * 24
    z = z - 22 * 24
    game.level = level
    load_level(True, True)
    record_set_replaying(game.record)
    record_load(game.record, game.level, x, y, z)
    if game.record->wait_on_level:
        game.state = "no recording"
    Block *b = &game.player->super
    b.x = x
    b.y = y
    b.z = z
    
    *tick = 0
    while *tick < 60 * 60 * 100: # cap at 10 minutes
        game_tick(game)
        if not land_equals(game.state, "play"):
            break
        #All *a = global_a
        #print("%d %d/%d/%d/%d/%d %f %f %f", tick,
        #    a.left, a.right, a.up, a.down, a.jump,
        #    b.x, b.y, b.z)
        (*tick)++
    print("%s at tick %d", game.state, *tick)
    if land_equals(game.state, "done"):
        print("%sOK%s", color_bash("green"), color_bash(""))
        return True
    print("%sFAIL%s", color_bash("red"), color_bash(""))
    return False

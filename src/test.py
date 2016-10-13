import game
type Game *game
type All *global_a

char const *tests = """
record01_091203550756.gz
record02_100800960660.gz
record03_012000960660.gz
record04_056400961008.gz
record05_037200961008.gz
record06_100801920180.gz
record07_075604081008.gz
record08_056400961008.gz
record09_100800960564.gz
record10_056402881008.gz
record11_100800960564.gz
record12_094800961008.gz
record13_012000960948.gz
record14_012000960948.gz
record15_037200961008.gz
record16_012000960564.gz
record17_056402881008.gz
record18_056400960120.gz
record19_100801440756.gz
record20_100801440564.gz
record21_056400961008.gz
record22_037200960120.gz
record23_012000960564.gz
record24_012000960564.gz
record25_012000960564.gz
record26_012000960564.gz
record27_012000960564.gz
record28_066002881008.gz
record29_100800960756.gz
record30_100800960228.gz
record31_066002881008.gz
record32_100800960468.gz
record33_100801920468.gz
record34_075600960120.gz
record35_085204801008.gz
record36_027600960120.gz
record37_012000960708.gz
record38_100800720180.gz
record39_037200720120.gz
record40_094804801008.gz
record41_012004800756.gz
record42_080404801008.gz
record43_075600960120.gz
record44_070800960120.gz
record45_012000960948.gz
record46_012000960564.gz
record47_012004800564.gz
record48_056400960120.gz
record49_012000960948.gz
"""

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
    LandArray *lines = land_split_lines(tests)
    for char *line in LandArray *lines:
        if land_equals(line, ""):
            continue
        int level, x, y, z
        sscanf(line, "record%02d_%04d%04d%04d.gz", &level, &x, &y, &z)
        int tick = 0
        if test_level(level, x, y, z, &tick):
            ok++
            if result[level] == ' ':
                result[level] = 'K'
        else:
            result[level] = 'F'
        minduration[level] = tick
        n++

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
    load_level(True)
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

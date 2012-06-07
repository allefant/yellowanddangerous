global int level_start = 1

static char const *room1 = """
.           .           .           .           .           .           .
 - - - - -  .           .           .           .           .           .
.           .           .     ♥     .           .           .           .
 -       -  .           .           .           .           .           .
.           .           .           .           .           .           .
 -       - e.           .           .           .           .           .
.  ~ ~ x    .      S    .           .           .           .           .
 -       -  .           .           .           .           .           .
.           .           .           .           .           .           .
 - - - - -  .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint1 = "Cursor keys\nor WASD to move\nR to restart."

static char const *room2 = """
.           .           .           .    ə      .           .           .
.           .           .           .    _      .           .           .
.           .           .           .           .           .           .
.    _      .    |      .           .           .           .           .
.           .           .           .           .           .           .
.    _      .           .           .           .           .           .
.           .           .           .           .           .           .
.    _      .     S     .           .           .           .           .
.           .     ♥     .           .           .           .           .
.    _      .     ♥     .     ♥     .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint2 = "While moving, press\ncontrol to jump\nR to restart."

static char const *room3 = """
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
._ _ _ _ _  .| | | | |  .           .| | | | |  .           .    | | |  .
.           .OOO        e         + .  /      + .         + .    | | |+ .
._ _ _ _ _{ .OOO        .      S    .         { .           .    | | |  .
.} } } } }  .           .           .} } } } }  .           .| | | | |  .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint3 = "To pull, press jump\nthen move backwards."

static char const *room4 = """
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
. ~    - _  .           .           .           .           .           .
. ~         .           .      S    .           .           .       =   .
.ə     - _  .           .           .           .       =   .       =   .
.           .           .           .       =   .       =   .       =   .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint4 = "Lab repairs."

static char const *room5 = """
.           .           .           .           .           .           .
.- - - -    .       ♥   . ♥         .           .           .           .
.           .        t  .           .           .           .           .
.- x~ x-    .           .           .           .           .           .
e  ~ ~   ~  .           .           .           .           .           .
.- '~ '- '' .           .         S .           .           .           .
.  x~ x     .        t  .           .           .           .           .
.- - - -    .           .           .           .           .           .
.           .           . ♥     ♥   .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint5 = "Now what."

static char const *room6 = """
.  ə        .           .           .           .           .           .
.  _ _ _    .     ***   .           .           .           .           .
.           .     * *   .      x    .           .           .           .
.  _ _ _    .     ***   .           .           .           .           .
.           .           .  _        .  ♥        .           .           .
.  _ _ _ -  .           .           .  ♥        .           .           .
.           .         S .           .           .           .           .
.  _ _ _    .           .           .           .           .           .
.           .     ***   .           .           .           .           .
.  _ _ _    .     * *   .      x    .           .           .           .
.           .     ***   .           .           .           .           .
.  ə        .           .           .           .           .           .
"""
static char const *hint6 = "To lift, stand still,\nthen press jump key,\nthen push."

static char const *room7 = """
.           .           .           .           .           .           .
.      x    .           .           .           .           .           .
.~ ~ ~ ~ ~  .         S .           .           .           .           .
.  '        .           .           .           .           .           .
.  '        .           .           .           .           .           .
.~ ~ ~ ~ ə .1        A .           .           .           .           .
.      '    .           .           .           .           .           .
.      '    .           .           .           .           .           .
.~ ~ ~ ~ ~  .           .           .           .           .           .
.  '        .           .  ♥        .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint7 = "Yellow and Dangerous.\n\nA mere figment of your imagination?"

static char const *room8 = """
.    ə      .           .           .           .           .           .
.- - - - -  .           .           .           .        t  .           .
.           . !!!!  !!! . !       ! . !       ! .           .           .
.- - - x'-  . !A      ! .           .           .           .           .
.      ~    . !       ! .       ♥   .       ♥   .           .           .
e- - - x'-  .     S   ! .           .           .           .           .
.      ~    .         ! .           .           .           .           .
.- - - x'-  . !1 = 2= ! .           .           .           .           .
.      ~    . !       ! .           .           .           .           .
.- - - - -  . !       ! .           .           .t          .           .
.           . !!!!!!!!! . !       ! . !       ! .           .           .
.           .           .           .           .           .           .
"""
static char const *hint8 = "Yellow and...\nhelpful?"

static char const *room9 = """
.           .           .           .           .           .           .
. +_ _ _ +x ./6      75 .           .           .           .           .
. +      ++ .           .           .           .           .         x .
._ _ _ _ _  ./ | | |    .           . x    |    .           .        ++ .
.           .  A  S  ♥♥ .        ♥♥ .        ♥♥ .+          .           .
e_ _ _ _ ++ .        8  .           .           .+          .           .
.        +x .      3  4 .           .           .+          .           .
._ _   _ _  ./          .           .           .+          .           .
.           .           .           .           .+          .           .
._ ++_ ++_  ./          .           ./       T  .           .           .
.  +x  +x   .  1   2  ! .         ! .           .           . x         .
.           .           .           .           .           .           . 
"""
static char const *hint9 = "\nYellow and Annoying!"

static char const *room10 = """
.           .           .           .           .           .           .
.           .  ß'ß'ß'ß' .  '        .           .           .           .
.           .         ' .  ß      ♥ .    ' '    .           .           .
.           .  ß      x .  '        .           .           .           .
.           .  'ß'      .           .           .           .           .
.           .    ß      .           .           .           .           .
.           .    'ß'    .           .           .  s      x .  's's'    .
.           .      ß    .           .           .  '      ' .  s   s  ♥ .
.           .     ß'    .    ß'ß    .    'ß     .  s     s' .      's's .
.           .           .           .  s ß      .  '        .           .
.S          .'          . '         .  'ß'      .  s        .           .
.           .           .    ' 'ə   .           .           .           .
"""
static char const *hint10 = "Which way is up?"

static char const *room11 = """
.           .           .           .           .           .           .
.      _ _  .      # #  .           .      #    .           .           .
.           .           .           .           .           .           .
.      _ _  .           .           .      #    .           .           .
.          x.           .           .           .           .           .
.           .           .           .      #    .           .           .
.           .           .           .           .           .           .
._ _ _      .#          .           .# # # #    .           .           .
.           .   ♥♥♥     .   ♥♥♥     .           .           .           .
._ _S_ e    .#          .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
static char const *hint11 = "Seriously?"

static char const *room12 = """
.           .           .           .           .           .           .
.    -   -  .           .           .    T   T  .           .           .
.           .     !   ! .     !   ! .           .           .           .
.           .           .           .           .           .         $ .
.           .           .           .           .           .           .
.-   -   - x.           .           .T   T   T  .           .     ♥     .
.           . !   !   ! . !   !   ! .           .           .    ♥      .
.           .           .           .           .           .         $ .
.        ə  .           .           .           .           .           .
.-   -  e- e.           .           .T   T   T  .           .           .
.           . !   !   ! . !   !   ! .           .           .  =   =  S .
.    x   ə  .           .           .           .           .           .
"""
static char const *hint12 = "Finally at the top!\n(Of the trees.)"

static char const *room13 = """
.ə e ə e    .           .           .           .           .           .
ə e ə e ə e .           .           .           .           .           .
.e ə e ə e  .           .           .           .           .           .
ə ə e ə e ə .           .           .           .           .           .
.ə e ə e.ə5e.      6    .     O   O .           .           .           .
ə e ə e ə e..           .   O       .           .           .           .
.e ə e ə e ə.     87    .      ♥    .           .           .           .
ə ə e xxe ə . A   9.    .     ..  O .           .           .           .
.ə e ə3e ə4e.           .     ♥     .           .           .           .
ə e ə e ə e .           .        O  .           .           .           .
. 1ə e2ə.e  .           . O         .           .           .           .
  ə e........           .           .           .           .           .
"""
static char const *hint13 = "Thanks a lot for playing!\nThanks Richard for Pyweek!\nMaking this was great fun :)"

static char const *room0 = """
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""

static char const *hint0 = ""

char const *def level_get_data(int i):
***scramble
levels = "    char const *data[] = {"
for i in range(14):
    levels += "room" + str(i) + ", "
levels += "}\n"
parse(levels)
***
    return data[i]

char const *def level_get_hint(int i):
***scramble
hints = "    char const *hints[] = {"
for i in range(14):
    hints += "hint" + str(i) + ", "
hints += "}\n"
parse(hints)
***
    return hints[i]

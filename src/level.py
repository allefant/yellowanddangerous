start = 1

room1 = r"""
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
hint1 = "Cursor keys\nor WASD to move\nR to restart."

room2 = r"""
.           .           .           .    ə      .           .           .
.           .           .           .    _      .           .           .
.           .           .           .           .           .           .
.    _      .    \      .           .           .           .           .
.           .           .           .           .           .           .
.    _      .           .           .           .           .           .
.           .           .           .           .           .           .
.    _      .     S     .           .           .           .           .
.           .     ♥     .           .           .           .           .
.    _      .     ♥     .     ♥     .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
hint2 = "While moving, press\ncontrol to jump\nR to restart."

room3 = r"""
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
._ _ _ _ _  .\ \ \ \ \  .           .\ \ \ \ \  .           .    \ \ \  .
.           .OOO        e         + .  /      + .         + .    \ \ \+ .
._ _ _ _ _{ .OOO        .      S    .         { .           .    \ \ \  .
.} } } } }  .           .           .} } } } }  .           .\ \ \ \ \  .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
.           .           .           .           .           .           .
"""
hint3 = "To pull, press jump\nthen move backwards."

room4 = r"""
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
hint4 = "Lab repairs."

room5 = r"""
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
hint5 = "Now what."

room6 = r"""
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
hint6 = "To lift, stand still,\nthen press jump key,\nthen push."

room7 = r"""
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
hint7 = "Yellow and Dangerous.\n\nA mere figment of your imagination?"

room8 = r"""
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
hint8 = "Yellow and...\nhelpful?"

room9 = r"""
.           .           .           .           .           .           .
. +_ _ _ +x ./6      75 .           .           .           .           .
. +      ++ .           .           .           .           .         x .
._ _ _ _ _  ./ \ \ \    .           . x    \    .           .        ++ .
.           .  A  S  ♥♥ .        ♥♥ .        ♥♥ .+          .           .
e_ _ _ _ ++ .        8  .           .           .+          .           .
.        +x .      3  4 .           .           .+          .           .
._ _   _ _  ./          .           .           .+          .           .
.           .           .           .           .+          .           .
._ ++_ ++_  ./          .           ./       T  .           .           .
.  +x  +x   .  1   2  ! .         ! .           .           . x         .
.           .           .           .           .           .           . 
"""
hint9 = "\nYellow and Annoying!"

room10 = r"""
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
hint10 = "Which way is up?"

room11 = r"""
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
hint11 = "Seriously?"

room12 = r"""
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
hint12 = "Finally at the top!\n(Of the trees.)"

room13 = r"""
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
hint13 = "Thanks a lot for playing!\nThanks Richard for Pyweek!\nMaking this was great fun :)"

room0 = r"""
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

this_was_a_stupid_idea = """
 
                     _
           _       _| |_       _
         _| |    _| |_| |_    | |_
       _| |_|  _| |_|/|_| |_  |_| |_
     _| |_| |_| |_| |_| |_| |_| |_| |_
   _| |_|/|_| |_|/|_/.\_|\|_| |_|\|_| |_
  | |_| |_| |_| |_/ \_/ \_| |_| |_| |_| |
  |_|/|_| |_| |_/.\_/ \_/.\_|\|_| |_|\|_|
  | |_| |_| |_/ \_/ \_/ \_/ \_| |_| |_| |
  |_| |_|/|_/.\_/ \_/.\_/ \_/.\_|\|_| |_|
  | |_| |_/ \_/ \_/ \_/ \_/ \_/ \_| |_| |
  |_|/|_/.\_/ \_/.\_/ \_/.\_/ \_/.\_|\|_|
  | |_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_| |
  |_/.\_/ \_/.\_/ \_/.\_/ \_/.\_/ \_/.\_|
  / \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \
  \_/ \_/.\_/ \_/ \_/ \_/.\_/ \_/.\_/ \_/ 
    \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
      \_/ \_/.\_/ \_/.\_/ \_/.\_/ \_/ 
        \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
          \_/ \_/.\_/ \_/.\_/ \_/ 
            \_/ \_/ \_/ \_/ \_/ 
              \_/ \_/.\_/ \_/ 
                \_/ \_/ \_/ 
                  \_/ \_/ 
                    \_/ 

                     _
                   _/ \_
                 _/ \_/ \_
               _/ \_/ \_/ \_
             _/ \_/ \_/ \_/ \_
           _/ \_/ \_/ \_/ \_/ \_
         _/ \_/ \_/ \_/ \_/ \_/ \_
       _/ \_/ \_/ \_/ \_/ \_/ \_/ \_
     _/ \_/ \_/ \_/ \_/ \_/♥\_/ \_/ \_
   _/ \_/ \_/ \_/ \_/S\_/ ♥♥♥ \_/ \_/ \_
  / \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \
  \_/ \_/ \_/ \_/ \_/ \_/ \_/♥\_/ \_/ \_/ 
    \_/ \_/ \_/ \_/ \_/ \_/ ♥♥♥ \_/ \_/ 
      \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
        \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
          \_/ \_/ \_/ \_/ \_/ \_/ 
            \_/ \_/ \_/ \_/ \_/ 
              \_/ \_/!\_/ \_/ 
                \_/ \Tt \_/ 
                  \_/ \_/ 
                    \_/ 
"""

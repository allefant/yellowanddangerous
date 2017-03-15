import common

class All:
    int FPS
    int w, h
    LandFont *font
    LandFont *medium
    LandFont *big

    # controls
    bool up, down, left, right, jump

    int ftpos
    double frame_times[60]
    float direct_speed_measure

    bool show_fps
    bool show_help

    int cheatpos[10]

    LandColor text

    bool title

    bool editor_enabled
    bool editor
    int text_input
    int cursor

    LandColor tint

    # 0 dpad left
    # 1 dpad right
    # 2 dpad left big
    # 3 dpad right big
    # 4 on screen, double tap jump
    # 5 on screen, two-finger jump
    int dpad
    int music
    int sound

    int fullscreen

    int load_after_redraw
    bool find_entrance

    int time
    bool overview
    bool render_screenshot

    int code
    bool godmode

    bool swipe
    double swipex, swipey, swipet, swipej

    int resize_in_ticks
    bool show_map
    bool show_ad

    bool test

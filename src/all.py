import common

class All:
    int FPS
    int w, h
    LandFont *font
    LandFont *medium
    LandFont *big
    bool up, down, left, right, jump

    int ftpos
    double frame_times[60]
    float direct_speed_measure
        
    bool mouse_down
    int mx, my

    bool show_fps, running
    bool show_help

    int cheatpos

    LandColor text

    bool title

    bool editor
    int text_input
    int cursor

    LandColor tint

    int dpad
    int music
    int sound

    int load_after_redraw
    bool find_entrance

    int time
    bool overview

    int code
    bool godmode

    bool swipe
    double swipex, swipey, swipet, swipej

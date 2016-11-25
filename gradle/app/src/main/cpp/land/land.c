#include "land.h"
#define _scramble_min(x, y) ((y) < (x) ? (y) : (x))
#define _scramble_max(x, y) ((y) > (x) ? (y) : (x))
typedef enum State State;
typedef struct LagSimulator LagSimulator;
typedef enum LandWidgetThemeFlags LandWidgetThemeFlags;
typedef enum COLUMN_TYPE COLUMN_TYPE;
typedef struct LandSoundPlatform LandSoundPlatform;
typedef struct LandStreamPlatform LandStreamPlatform;
typedef struct PlatformThread PlatformThread;
typedef struct PlatformLock PlatformLock;
typedef struct LandFontPlatform LandFontPlatform;
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
static int replacement_main(int argc, char * (* argv));
static int platform_keycode(int ak);
static int cb_free(void * data, void * _);
static int alphacomp(void const * a, void const * b);
#include <allegro5/allegro_color.h>
#include <ctype.h>
#include <string.h>
static char const* bash_mode(char const * x, char const * mode);
static bool get_data(LandHash * self, LandHashIterator * i, void * (* data));
static unsigned int hash_function(LandHash * self, char const * thekey);
static LandHashEntry* land_hash_get_entry(LandHash * self, char const * thekey);
#include <allegro5/allegro5.h>
static void add_files(char const * rel, LandArray * (* array), ALLEGRO_FS_ENTRY * entry, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data);
static void init_genrand(LandRandom * r, unsigned long s);
static unsigned long genrand_int32(LandRandom * r);
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
static void* _get(LandIniSection * s, char const * key);
static void _add(LandIniSection * s, char const * key, void * val);
static void _del(LandIniSection * s);
static LandIniSection* _new(void);
static bool is_whitespace(char c);
#include <assert.h>
#include <string.h>
static LandImage* _load(char const * filename, bool mem);
static void _load2(LandImage * self);
static int callback(const char * filename, int attrib, void * param);
static int compar(void const * a, void const * b);
static int filter(char const * name, bool is_dir, void * data);
static void defcb(LandImage * image, void * p);
#include <math.h>
static void get_bounding_box(float l, float t, float r, float b, float angle, float * bl, float * bt, float * br, float * bb);
static LandPixelMask* pixelmask_create_flip(LandImage * image, int n, int threshold, bool flipped);
static LandPixelMask* pixelmask_create(LandImage * image, int n, int threshold);
static void pixelmask_destroy(LandPixelMask * mask);
static int mask_get_rotation_frame(LandPixelMask * mask, float angle, bool flipped);
static int pixelmask_part_collision(SinglePixelMask * mask, int x, int y, SinglePixelMask * mask_, int x_, int y_, int w, int h);
static int pixelmask_collision(SinglePixelMask * mask, int x, int y, int w, int h, SinglePixelMask * mask_, int x_, int y_, int w_, int h_);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_opengl.h>
static void _platform_load(LandImage * super);
#include <sys/time.h>
static void land_exit(void);
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
static void ERR(char const * format, ...);
static void update_lookup_grid(LandWidget * self);
static LandWidget* lookup_box_in_grid(LandWidget * self, int col, int row);
static int row_min_height(LandWidget * self, int row);
static int column_min_width(LandWidget * self, int col);
static int is_column_expanding(LandWidget * self, int col);
static int is_row_expanding(LandWidget * self, int row);
static int expanding_columns(LandWidget * self);
static int expanding_rows(LandWidget * self);
static int min_height(LandWidget * self);
static int min_width(LandWidget * self);
static int adjust_resize_width(LandWidget * self, int dx);
static int adjust_resize_height(LandWidget * self, int dx);
static void gul_box_bottom_up(LandWidget * self);
static void gul_box_top_down(LandWidget * self);
static void gul_box_fit_children(LandWidget * self);
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
static void shader_setup(LandGLSLShader * self, char const * name, char const * vertex_glsl, char const * fragment_glsl);
static void shader_cleanup(LandGLSLShader * self);
static void test(char const * name, int want, int got);
static void sphere_point(LandArray * vertices, LandFloat i, LandFloat j);
static void add_quad(LandArray * polygons, LandVector a, LandVector b, LandVector c, LandVector d, void * shared);
static void add_tri(LandArray * polygons, LandVector a, LandVector b, LandVector c, void * shared);
static void torus_point(LandArray * vertices, LandFloat i, LandFloat j, LandFloat r);
#include <setjmp.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
static int nonblocking(LandNet * self);
static void split_address(char const * address, char * (* host), int * port);
static void _get_address(struct sockaddr_in sock_addr, char * address);
static void land_net_poll_accept(LandNet * self);
static void land_net_poll_connect(LandNet * self);
static LagSimulator* lag_simulator_new(double delay, double jitter);
static void lag_simulator_add(LandNet * net, char const * packet, int size);
static int _create_datagram_socket(LandNet * self);
static int _send_datagram(LandNet * self, char const * address, char const * packet, int size);
static void land_net_poll_recv(LandNet * self);
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
static int read32(FILE * f);
static int star_match(char const * pattern, char const * name);
static inline int centered_offset(int size1, int size2);
static inline void _masked_non_stretched_blit(LandImage * s, int sx, int sy, int w, int h, int dx, int dy, int _, int __);
static inline void _masked_stretched_blit(LandImage * s, int sx, int sy, int w, int h, int dx, int dy, int dw, int dh);
static inline void blit_column(LandWidgetThemeElement * pat, int bx, int bw, int x, int y, int w, int h, int skip_middle);
static void draw_bitmap(LandWidgetThemeElement * pat, int x, int y, int w, int h, int skip_middle);
static void read_int_arg(int argc, LandArray * argv, int * a, int * val);
static LandWidgetThemeElement* find_element(LandList * list, char const * name);
static void _theme_recurse(LandWidget * self, LandWidgetTheme * theme);
static void _layout_recurse(LandWidget * self, LandWidgetTheme * theme);
#include <math.h>
#include <assert.h>
static void land_tilegrid_draw_cell(LandGrid * self, LandView * view, int cell_x, int cell_y, float pixel_x, float pixel_y);
static void view_x_to_cell_and_pixel_x(LandGrid * self, float view_x, int * cell_x, float * pixel_x);
static void view_y_to_cell_and_pixel_y(LandGrid * self, float view_y, int * cell_y, float * pixel_y);
#include <stdio.h>
static int _wordwrap_helper(char const * text, int w, int h, void(* cb)(int a, int b, void * data), void * data);
static void _print_wordwrap_cb(int a, int b, void * data);
static void land_wordwrap_text_cb(int a, int b, void * data);
#include <math.h>
#include <allegro5/allegro_audio.h>
static bool get_params(int channels, int bits, int * chan_conf, int * depth);
#include <allegro5/allegro5.h>
static void* proc(void * data);
static void* aproc(ALLEGRO_THREAD * thread, void * arg);
static void land_widget_really_destroy(LandWidget * self);
static int collision_code(LandVector * v, LandCSGAABB * b);
static bool polygon_intersects_aabb(LandCSGPolygon * polygon, LandCSGAABB * box);
static LandArray* clone_vertices(LandCSG * csg, LandArray * vertices);
static void remove_vertices(LandArray * vertices, bool is_pooled);
static void csg_vertex_flip(LandCSGVertex * self);
static LandCSGVertex* csg_vertex_interpolate(LandCSG * csg, LandCSGVertex * self, LandCSGVertex * other, LandFloat t);
static LandCSGPlane csg_plane(LandVector normal, LandFloat w);
static LandCSGPlane csg_plane_from_points(LandVector a, LandVector b, LandVector c);
static LandCSGPolygon* land_csg_polygon_new_pool(LandMemoryPool * pool, LandArray * vertices, void * shared);
static void csg_plane_split_polygon(LandCSG * csg, LandCSGPlane * self, LandCSGPolygon * polygon, LandArray * coplanar_front, LandArray * coplanar_back, LandArray * front, LandArray * back);
static void csg_polygon_flip(LandCSGPolygon * self);
static LandArray* clone_polygons(LandCSG * csg, LandArray * polygons);
static void clear_polygons(LandArray * polygons);
static void csg_node_destroy(LandCSGNode * self);
static void csg_node_invert(LandCSGNode * self);
static void csg_node_clip_polygons(LandCSG * csg, LandCSGNode * self, LandArray * polygons);
static void csg_node_clip_to(LandCSG * csg, LandCSGNode * self, LandCSGNode * bsp);
static LandArray* csg_node_all_polygons(LandCSG * csg, LandCSGNode * self);
static void csg_add_polygons_from_node(LandCSG * csg, LandCSGNode * node);
static void csg_add_polygons(LandCSG * csg, LandArray * polygons);
static void csg_node_build(LandCSG * csg, LandCSGNode * self, LandArray * polygons);
static LandCSGNode* csg_node_new(LandCSG * csg, LandArray * polygons);
static void csg_split_on_bounding_box(LandCSG const * self, LandCSGAABB * box, LandArray * (* inside), LandArray * (* outside));
static void dummy(LandSprite * self, LandView * view);
static void dummy_image(LandSprite * self, LandView * view);
static void dummy_animation(LandSprite * self, LandView * view);
static void get_grid_extents(LandSprite * self, LandGrid * grid, int * tl, int * tt, int * tr, int * tb);
static int is_left(float ax, float ay, float bx, float by);
static int is_in_triangle(float x, float y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y);
static void grid_place(LandSprite * self, LandSpritesGrid * grid);
static void grid_unplace(LandSprite * self, LandSpritesGrid * grid);
static void get_cell_at(LandGrid * self, LandView * view, float view_x, float view_y, float * cell_x, float * cell_y);
#include <math.h>
#include <stdbool.h>
static LandGrid* new(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells);
static void view_to_cell(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y);
static void view_to_cell_wrap(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y);
static void cell_to_view(LandGrid * self, float cell_x, float cell_y, float * view_x, float * view_y);
static int find_offset(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y, float * pixel_x, float * pixel_y);
static void find_offset_wrap(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y, float * pixel_x, float * pixel_y);
static void placeholder(LandGrid * self, LandView * view, int cell_x, int cell_y, float x, float y);
static int _linedelcb(void * item, void * data);
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <assert.h>
#include <math.h>
static void check_blending_and_transform(void);
static void uncheck_blending(void);
static void transfer_mouse_focus(LandWidget * base, LandWidget * child);
static void transfer_keyboard_focus(LandWidget * base);
static int get_x_offset(LandWidget * base);
static void scroll_vertical_cb(LandWidget * self, int set, int * _scramble_min, int * _scramble_max, int * range, int * pos);
static void scroll_horizontal_cb(LandWidget * self, int set, int * _scramble_min, int * _scramble_max, int * range, int * pos);
static int get_size(LandWidget * super);
static void clicked(LandWidget * button);
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
static void land_widget_vbox_renumber(LandWidget * base);
static int scrolling_update_layout(LandWidget * widget);
static void cb_clicked(LandWidget * widget);
static void land_widget_hbox_renumber(LandWidget * base);
static void menubutton_clicked(LandWidget * base);
static void menuitem_clicked(LandWidget * base);
static int is_in_menu(LandWidget * self, LandWidget * other);
static int is_related(LandWidget * self, LandWidget * other);
static void updated(LandWidget * base);
static void spinning(LandWidget * widget, float amount);
#ifdef ANDROID
#include "allegro5/allegro_android.h"
#endif
#ifdef __EMSCRIPTEN__
#include < emscripten.h>
#endif
static bool redraw;
static LandDisplayPlatform * d;
static ALLEGRO_EVENT_QUEUE * queue;
static ALLEGRO_TIMER * timer;
static void(* global_cb)(void);
static int replacement_main(int argc, char * (* argv)) {
    global_cb();
    return 0;
}
void platform_without_main(void(* cb)(void)) {
    global_cb = cb;
    al_run_main(0, NULL, replacement_main);
}
double platform_get_time(void) {
    return al_current_time();
}
void platform_halt(void) {
    platform_sound_halt();
}
void platform_resume(void) {
    platform_sound_resume();
}
void platform_init(void) {
    land_log_message("Compiled against Allegro %s.\n", ALLEGRO_VERSION_STR);
    if (! al_init()) {
        land_log_message("Allegro initialization failed.\n");
        land_exception("Error in allegro_init.");
    }
    #ifdef ANDROID
    al_android_set_apk_file_interface();
    #endif
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
}
#define _UnkKey(x) LandKeyUnknown3 + x + 0, LandKeyUnknown3 + x + 1, LandKeyUnknown3 + x + 2, LandKeyUnknown3 + x + 3, LandKeyUnknown3 + x + 4, LandKeyUnknown3 + x + 5, LandKeyUnknown3 + x + 6, LandKeyUnknown3 + x + 7, LandKeyUnknown3 + x + 8, LandKeyUnknown3 + x + 9
static int keyboard_conversion_table [ALLEGRO_KEY_MAX] = {LandKeyNone, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', LandKeyPad + 0, LandKeyPad + 1, LandKeyPad + 2, LandKeyPad + 3, LandKeyPad + 4, LandKeyPad + 5, LandKeyPad + 6, LandKeyPad + 7, LandKeyPad + 8, LandKeyPad + 9, LandKeyFunction + 1, LandKeyFunction + 2, LandKeyFunction + 3, LandKeyFunction + 4, LandKeyFunction + 5, LandKeyFunction + 6, LandKeyFunction + 7, LandKeyFunction + 8, LandKeyFunction + 9, LandKeyFunction + 10, LandKeyFunction + 11, LandKeyFunction + 12, LandKeyEscape, '~', '-', '=', LandKeyBackspace, LandKeyTab, '[', ']', LandKeyEnter, ';', '\'', '\\', LandKeyUnknown + 0, ',', '.', '/', ' ', LandKeyInsert, LandKeyDelete, LandKeyHome, LandKeyEnd, LandKeyPageUp, LandKeyPageDown, LandKeyLeft, LandKeyRight, LandKeyUp, LandKeyDown, LandKeyPadSlash, LandKeyPadStar, LandKeyPadMinus, LandKeyPadPlus, LandKeyPadDelete, LandKeyPadEnter, LandKeyPrint, LandKeyPause, LandKeyUnknown + 1, LandKeyUnknown + 2, LandKeyUnknown + 3, LandKeyUnknown + 4, LandKeyUnknown + 5, '@', '^', ':', LandKeyUnknown + 6, LandKeyUnknown + 7, LandKeyUnknown + 8, LandKeyUnknown + 9, LandKeyUnknown + 10, LandKeyBack, LandKeyUnknown + 12, LandKeyUnknown2 + 0, LandKeyUnknown2 + 1, LandKeyUnknown2 + 2, LandKeyUnknown2 + 3, LandKeyUnknown2 + 4, LandKeyUnknown2 + 5, LandKeyUnknown3 + 0, LandKeyUnknown3 + 1, LandKeyUnknown3 + 2, LandKeyUnknown3 + 3, LandKeyUnknown3 + 4, LandKeyUnknown3 + 5, _UnkKey(6), _UnkKey(16), _UnkKey(26), _UnkKey(36), _UnkKey(46), _UnkKey(56), _UnkKey(66), _UnkKey(76), _UnkKey(86), LandKeyUnknown3 + 96, LandKeyUnknown3 + 97, LandKeyUnknown3 + 98, LandKeyUnknown3 + 99, LandKeyLeftShift, LandKeyRightShift, LandKeyLeftControl, LandKeyRightControl, LandKeyLeftAlt, LandKeyRightAlt, LandKeyLeftWin, LandKeyRightWin, LandKeyMenu, LandKeyScrollLock, LandKeyNumLock, LandKeyCapsLock};
char const* platform_key_name(int lk) {
    int ak = 0;
    for (int i = 0; i < ALLEGRO_KEY_MAX; i++) {
        if (keyboard_conversion_table [i] == lk) {
            ak = i;
            break;
        }
    }
    char const * s = al_keycode_to_name(ak);
    return s;
}
static int platform_keycode(int ak) {
    return keyboard_conversion_table [ak];
}
void platform_hide_mouse_cursor(void) {
    LandDisplayPlatform * d = (void *) _land_active_display;
    al_hide_mouse_cursor(d->a5);
}
void platform_show_mouse_cursor(void) {
    LandDisplayPlatform * d = (void *) _land_active_display;
    al_show_mouse_cursor(d->a5);
}
void platform_mouse_set_pos(float x, float y) {
    LandDisplayPlatform * d = (void *) _land_active_display;
    al_set_mouse_xy(d->a5, x, y);
}
void platform_pause(void) {
    if (timer) {
        al_stop_timer(timer);
    }
}
void platform_unpause(void) {
    if (timer) {
        al_resume_timer(timer);
    }
}
void platform_mainloop(LandParameters * parameters) {
    d = (void *) _land_active_display;
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / parameters->fps);
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    if (al_install_touch_input()) {
        al_register_event_source(queue, al_get_touch_input_event_source());
    }
    al_register_event_source(queue, al_get_display_event_source(d->a5));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    ALLEGRO_MOUSE_STATE s;
    al_get_mouse_state(& s);
    land_mouse_move_event(s.x, s.y, s.z);
    redraw = 0;
    #ifdef __EMSCRIPTEN__
    _land_synchronized = 1;
    emscripten_set_main_loop(platform_frame, 0, true);
    #else
    while (! _land_quit) {
        platform_frame();
    }
    #endif
}
void platform_frame(void) {
    if (! _land_quit) {
        if (redraw && (_land_synchronized || al_event_queue_is_empty(queue))) {
            if (! _land_halted) {
                land_draw();
            }
            redraw = 0;
        }
        while (1) {
            ALLEGRO_EVENT event;
            #ifdef __EMSCRIPTEN__
            if (! al_get_next_event(queue, & event)) {
                break;
            }
            #else
            al_wait_for_event(queue, & event);
            #endif
            switch (event.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                    land_closebutton_event();
                    break;
                }
                case ALLEGRO_EVENT_TIMER: {
                    if (_land_was_halted && _land_halted) {
                        al_stop_timer(timer);
                    }
                    else {
                        land_tick();
                        _land_frames++;
                        redraw = 1;
                    }
                    break;
                }
                case ALLEGRO_EVENT_KEY_DOWN: {
                    int lk = platform_keycode(event.keyboard.keycode);
                    land_key_press_event(lk);
                    break;
                }
                case ALLEGRO_EVENT_KEY_CHAR: {
                    int lk = platform_keycode(event.keyboard.keycode);
                    land_keyboard_add_char(lk, event.keyboard.unichar);
                    break;
                }
                case ALLEGRO_EVENT_KEY_UP: {
                    int lk = platform_keycode(event.keyboard.keycode);
                    land_key_release_event(lk);
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_AXES: {
                    land_mouse_move_event(event.mouse.x, event.mouse.y, event.mouse.z);
                    if (land_mouse_b() & 1) {
                        land_touch_event(event.mouse.x, event.mouse.y, 10, 0);
                    }
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                    land_mouse_button_down_event(event.mouse.button - 1);
                    land_touch_event(land_mouse_x(), land_mouse_y(), 10, 1);
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                    land_mouse_button_up_event(event.mouse.button - 1);
                    land_touch_event(land_mouse_x(), land_mouse_y(), 10, - 1);
                    break;
                }
                case ALLEGRO_EVENT_TOUCH_BEGIN: {
                    land_touch_event(event.touch.x, event.touch.y, event.touch.id, 1);
                    break;
                }
                case ALLEGRO_EVENT_TOUCH_END: {
                    land_touch_event(event.touch.x, event.touch.y, event.touch.id, - 1);
                    break;
                }
                case ALLEGRO_EVENT_TOUCH_MOVE: {
                    land_touch_event(event.touch.x, event.touch.y, event.touch.id, 0);
                    break;
                }
                case ALLEGRO_EVENT_DISPLAY_RESIZE: {
                    al_acknowledge_resize((ALLEGRO_DISPLAY *) event.any.source);
                    land_resize_event(event.display.width, event.display.height);
                    break;
                }
                case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT: {
                    land_switch_out_event();
                    break;
                }
                case ALLEGRO_EVENT_DISPLAY_HALT_DRAWING: {
                    land_halt();
                    al_acknowledge_drawing_halt(d->a5);
                    break;
                }
                case ALLEGRO_EVENT_DISPLAY_SWITCH_IN: {
                    break;
                }
                case ALLEGRO_EVENT_DISPLAY_RESUME_DRAWING: {
                    land_resume();
                    al_acknowledge_drawing_resume(d->a5);
                    al_start_timer(timer);
                    break;
                }
            }
            #ifdef __EMSCRIPTEN__
            continue;
            #endif
            break;
        }
    }
}
char* platform_get_app_settings_file(char const * appname) {
    al_set_org_name("");
    al_set_app_name(appname);
    ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_USER_SETTINGS_PATH);
    const char * str = al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP);
    if (! al_filename_exists(str)) {
        land_log_message("Creating new settings path %s.\n", str);
        al_make_directory(str);
    }
    al_set_path_filename(path, "settings.cfg");
    str = al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP);
    land_log_message("Using settings file %s.\n", str);
    char * dup = land_strdup(str);
    al_destroy_path(path);
    return dup;
}
void platform_wait(double seconds) {
    al_rest(seconds);
}
#undef _UnkKey
#ifdef LAND_MEMLOG
#undef land_array_new
#undef land_array_destroy
#undef land_array_add
#undef land_array_clear
#undef land_array_merge
#undef land_array_concat
#undef land_array_copy
LandArray* land_array_new_memlog(char const * f, int l) {
    LandArray * array = land_array_new();
    land_memory_add(array, "array", 1, f, l);
    return array;
}
void land_array_destroy_memlog(LandArray * self, char const * f, int l) {
    land_memory_remove(self, "array", 1, f, l);
    land_array_destroy(self);
}
void land_array_add_memlog(LandArray * self, void * data, char const * f, int l) {
    land_array_add(self, data);
    land_memory_remove(self, "array", 1, f, l);
    land_memory_add(self, "array", self->size, f, l);
}
LandArray* land_array_copy_memlog(LandArray const * self, char const * f, int l) {
    LandArray * copy = land_array_copy(self);
    land_memory_add(copy, "array", copy->size, f, l);
    return copy;
}
void land_array_concat_memlog(LandArray * self, LandArray const * other, char const * f, int l) {
    land_array_concat(self, other);
    land_memory_remove(self, "array", 1, f, l);
    land_memory_add(self, "array", self->size, f, l);
}
void land_array_merge_memlog(LandArray * self, LandArray * other, char const * f, int l) {
    land_array_merge(self, other);
    land_memory_remove(self, "array", 1, f, l);
    land_memory_add(self, "array", self->size, f, l);
    land_memory_remove(other, "array", 1, f, l);
}
void land_array_clear_memlog(LandArray * self, char const * f, int l) {
    land_array_clear(self);
    land_memory_remove(self, "array", 1, f, l);
    land_memory_add(self, "array", self->size, f, l);
}
#endif
LandArrayIterator LandArrayIterator_first(LandArray * a) {
    LandArrayIterator i = {0};
    return i;
}
void* LandArrayIterator_item(LandArray * a, LandArrayIterator * i) {
    return i->i < a->count ? a->data [i->i] : NULL;
}
bool LandArrayIterator_next(LandArray * a, LandArrayIterator * i) {
    i->i++;
    return i->i <= a->count;
}
LandArray* land_array_new(void) {
    /* Create a new empty array.
     */
    LandArray * self;
    land_alloc(self);
    return self;
}
void land_array_add(LandArray * self, void * data) {
    /* Add data to an array.
     */
    int i = self->count++;
    if (self->count > self->size) {
        if (self->size == 0) {
            self->size = 1;
        }
        else {
            self->size *= 2;
        }
        self->data = land_realloc(self->data, self->size * sizeof (* self->data));
    }
    self->data [i] = data;
}
void land_array_reserve(LandArray * self, int n) {
    /* Allocate n empty (None) entries for the array. Removes any contents
     * of the array if it already has any data added to it.
     */
    self->count = self->size = n;
    self->data = land_realloc(self->data, self->size * sizeof (* self->data));
    memset(self->data, 0, self->count * sizeof (* self->data));
}
void* land_array_pop(LandArray * self) {
    /* Remove the last element in the array and return it. Only the last element
     * in an array can be removed. To remove another element, you could replace
     * it with the last (land_array_replace_nth) and remove the last with this
     * function.
     */
    if (self->count == 0) {
        return NULL;
    }
    int i = --self->count;
    return self->data [i];
}
void land_array_add_data(LandArray * (* array), void * data) {
    /* *deprecated*
     * Use land_array_add in new code, as this function might be removed in a
     * future version.
     * Given a pointer to a (possibly NULL valued) array pointer, create a new node
     * with the given data, and add to the (possibly modified) array.
     */
    LandArray * self = * array;
    if (! self) {
        #if LAND_MEMLOG
        self = land_array_new_memlog(__FILE__, __LINE__);
        #else
        self = land_array_new();
        #endif
        * array = self;
    }
    land_array_add(self, data);
}
int land_array_find(LandArray * self, void * data) {
    /* Searches the array for the given data. If they are contained, return the
     * first index i so that land_array_get_nth(array, i) == data. If the data
     * cannot be found, -1 is returned.
     */
    for (int i = 0; i < self->count; i++) {
        if (self->data [i] == data) {
            return i;
        }
    }
    return - 1;
}
void* land_array_get_nth(LandArray const * array, int i) {
    if (i < 0) {
        i += array->count;
    }
    return array->data [i];
}
bool land_array_is_empty(LandArray const * array) {
    return array->count == 0;
}
void* land_array_replace_nth(LandArray * array, int i, void * data) {
    /* Replace the array entry at the given index, and return the previous
     * contents.
     */
    if (i >= array->count) {
        return NULL;
    }
    void * old = array->data [i];
    array->data [i] = data;
    return old;
}
void land_array_destroy(LandArray * self) {
    /* Destroys an array. This does not destroy any of the data put into it - loop
     * through the array before and destroy the data if there are no other
     * references to them.
     */
    if (self->data) {
        land_free(self->data);
    }
    land_free(self);
}
static int cb_free(void * data, void * _) {
    land_free(data);
    return 0;
}
void land_array_destroy_with_strings(LandArray * self) {
    /* Like [land_array_destroy] but also calls land_free on every
     * element.
     */
    land_array_for_each(self, cb_free, NULL);
    land_array_destroy(self);
}
void land_array_sort(LandArray * self, int(* cmpfnc)(void const * a, void const * b)) {
    /* Sorts the entries in the array. The given callback function gets passed
     * two direct pointers to two array elements, and expects a return value
     * determining the order:
     * < 0: a is before b
     * = 0: order is arbitrary
     * > 0: a is after b
     */
    qsort(self->data, self->count, sizeof (void *), cmpfnc);
}
static int alphacomp(void const * a, void const * b) {
    char const * const * as = a;
    char const * const * bs = b;
    int r = strcmp(* as, * bs);
    return r;
}
void land_array_sort_alphabetical(LandArray * self) {
    /* Expects all array members to be strings and sorts alphabetically.
     */
    land_array_sort(self, alphacomp);
}
int land_array_count(LandArray const * self) {
    if (! self) {
        return 0;
    }
    return self->count;
}
int land_array_for_each(LandArray * self, int(* cb)(void * item, void * data), void * data) {
    /* Call the given callback for each array element. If the callback returns
     * anything but 0, the iteration is stopped. The return value is the number
     * of times the callback was called. The data argument simply is passed as-is
     * to the callback.
     */
    if (! self) {
        return 0;
    }
    int i;
    for (i = 0; i < self->count; i++) {
        if (cb(self->data [i], data)) {
            break;
        }
    }
    return i;
}
void land_array_clear(LandArray * self) {
    /* Clear all elements in the array.
     */
    self->count = 0;
}
void land_array_concat(LandArray * self, LandArray const * other) {
    int new_count = self->count + other->count;
    self->size = new_count;
    self->data = land_realloc(self->data, self->size * sizeof (* self->data));
    memcpy(self->data + self->count, other->data, other->count * sizeof (* other->data));
    self->count = self->size;
}
void land_array_merge(LandArray * self, LandArray * other) {
    land_array_concat(self, other);
    land_array_destroy(other);
}
LandArray* land_array_copy(LandArray const * self) {
    LandArray * copy = land_array_new();
    land_array_concat(copy, self);
    return copy;
}
void land_array_swap(LandArray * self, int a, int b) {
    if (a < 0) {
        a += self->count;
    }
    if (b < 0) {
        b += self->count;
    }
    void * temp = self->data [a];
    self->data [a] = self->data [b];
    self->data [b] = temp;
}
void land_array_move_behind(LandArray * self, int a, int b) {
    /* Move item at position a so it is behind b. If b is 0 then a is moved to
     * the beginning. If b is n then a is moved to the end.
     */
    void * temp = self->data [a];
    if (a < b) {
        for (int i = a; i < b - 1; i++) {
            self->data [i] = self->data [i + 1];
        }
        self->data [b - 1] = temp;
    }
    else {
        for (int i = a; i > b; i--) {
            self->data [i] = self->data [i - 1];
        }
        self->data [b] = temp;
    }
}
void land_array_reverse(LandArray * self) {
    for (int i = 0; i < self->count / 2; i += 1) {
        land_array_swap(self, i, self->count - 1 - i);
    }
}
int land_widget_layout_freeze(LandWidget * self) {
    int nl = self->no_layout;
    self->no_layout = 1;
    return ! nl;
}
int land_widget_layout_unfreeze(LandWidget * self) {
    int nl = self->no_layout;
    self->no_layout = 0;
    return nl;
}
void land_widget_layout_set_grid(LandWidget * self, int columns, int rows) {
    self->box.rows = rows;
    self->box.cols = columns;
    land_widget_layout(self);
}
void land_widget_layout_disable(LandWidget * self) {
    self->box.flags |= GUL_NO_LAYOUT;
}
void land_widget_layout_enable(LandWidget * self) {
    self->box.flags &= ~ GUL_NO_LAYOUT;
}
void land_widget_layout_set_grid_position(LandWidget * self, int column, int row) {
    self->box.col = column;
    self->box.row = row;
    if (self->parent) {
        land_widget_layout(self->parent);
    }
}
void land_widget_layout_set_grid_extra(LandWidget * self, int columns, int rows) {
    self->box.extra_cols = columns;
    self->box.extra_rows = rows;
    if (self->parent) {
        land_widget_layout(self->parent);
    }
}
void land_widget_layout_set_minimum_size(LandWidget * self, int w, int h) {
    self->box.min_width = w;
    self->box.min_height = h;
    self->box.current_min_width = w;
    self->box.current_min_height = h;
}
void land_widget_layout_set_maximum_size(LandWidget * self, int w, int h) {
    self->box.max_width = w;
    self->box.max_height = h;
}
void land_widget_layout_set_shrinking(LandWidget * self, int x, int y) {
    if (x) {
        self->box.flags |= GUL_SHRINK_X;
    }
    if (y) {
        self->box.flags |= GUL_SHRINK_Y;
    }
    if (self->parent && ! self->parent->no_layout) {
        land_widget_layout(self);
    }
}
void land_widget_layout_set_expanding(LandWidget * self, int x, int y) {
    if (x) {
        self->box.flags &= ~ GUL_SHRINK_X;
    }
    if (y) {
        self->box.flags &= ~ GUL_SHRINK_Y;
    }
    if (self->parent) {
        land_widget_layout(self);
    }
}
void land_widget_layout(LandWidget * self) {
    if (! self->no_layout) {
        _land_gul_layout_updated(self);
    }
}
void land_widget_layout_initialize(LandWidget * self, int x, int y, int w, int h) {
    _land_gul_box_initialize(& self->box);
    self->box.x = x;
    self->box.y = y;
    self->box.w = w;
    self->box.h = h;
}
LandColor platform_color_hsv(float hue, float sat, float val) {
    LandColor c;
    al_color_hsv_to_rgb(hue, sat, val, & c.r, & c.g, & c.b);
    c.a = 1;
    return c;
}
LandColor platform_color_name(char const * name) {
    LandColor c;
    al_color_name_to_rgb(name, & c.r, & c.g, & c.b);
    c.a = 1;
    return c;
}
void land_map_draw(LandMap * self, LandView * view) {
    /* Render the map using the given ''view''.
     */
    LandLayer * layer = self->first_layer;
    while (layer) {
        land_layer_draw(layer, view);
        layer = layer->next_in_map;
    }
}
void land_map_add_layer(LandMap * map, LandLayer * layer) {
    /* Add another layer to the map, on top of any existing layers.
     */
    if (map->first_layer) {
        LandLayer * l = map->first_layer;
        while (l->next_in_map) {
            l = l->next_in_map;
        }
        l->next_in_map = layer;
    }
    else {
        map->first_layer = layer;
    }
}
LandLayer* land_map_base_layer(LandMap * map) {
    /* Returns the base layer of the map.
     */
    return map->first_layer;
}
LandLayer* land_map_find_layer(LandMap * map, char const * name) {
    for (LandLayer * l = map->first_layer; l; l = l->next_in_map) {
        if (! strcmp(name, l->name)) {
            return l;
        }
    }
    return NULL;
}
LandMap* land_map_new(void) {
    /* Create a new map. This is not called directly normally, as you likely want
     * to use one of the convenience function to already create layers of the
     * right type along with it.
     */
    LandMap * self;
    land_alloc(self);
    return self;
}
void land_map_del(LandMap * self) {
    /* Destroy a map. This also destroys its layers.
     */
    if (self->first_layer) {
        LandLayer * l = self->first_layer;
        while (l) {
            LandLayer * next = l->next_in_map;
            land_layer_del(l);
            l = next;
        }
    }
    land_free(self);
}
void land_map_destroy(LandMap * self) {
    /* Same as land_map_del.
     */
    land_map_del(self);
}
static int key_state [LandKeysCount];
static int key_pressed [LandKeysCount];
static int keybuffer_keycode [256];
static int keybuffer_unicode [256];
static int keybuffer_first;
static int keybuffer_last;
void land_key_press_event(int k) {
    if (! key_state [k]) {
        key_pressed [k]++;
        key_state [k] = 1;
    }
}
void land_key_release_event(int k) {
    key_state [k] = 0;
}
void land_keyboard_init(void) {
    ;
}
int land_key(int k) {
    return key_state [k];
}
int land_key_pressed(int k) {
    return key_pressed [k];
}
void land_keyboard_tick(void) {
    int i;
    for (i = 0; i < LandKeysCount; i++) {
        key_pressed [i] = 0;
    }
    keybuffer_first = 0;
    keybuffer_last = 0;
}
void land_keyboard_add_char(int keycode, int unicode) {
    if (keybuffer_last == 256) {
        return ;
    }
    keybuffer_keycode [keybuffer_last] = keycode;
    keybuffer_unicode [keybuffer_last] = unicode;
    keybuffer_last++;
}
bool land_keybuffer_empty(void) {
    return keybuffer_last == keybuffer_first;
}
void land_keybuffer_next(int * k, int * u) {
    if (keybuffer_first < keybuffer_last) {
        * k = keybuffer_keycode [keybuffer_first];
        * u = keybuffer_unicode [keybuffer_first];
        keybuffer_first++;
    }
}
char const* land_key_name(int k) {
    return platform_key_name(k);
}
LandView* land_view_new(int x, int y, int w, int h) {
    /* Specify the view rectangle on the screen.
     */
    LandView * self;
    land_alloc(self);
    self->x = x;
    self->y = y;
    self->w = w;
    self->h = h;
    self->scale_x = 1;
    self->scale_y = 1;
    self->r = 1;
    self->g = 1;
    self->b = 1;
    self->a = 1;
    return self;
}
void land_view_destroy(LandView * self) {
    land_free(self);
}
void land_view_scroll(LandView * self, float dx, float dy) {
    /* Scroll the view by the given amount of screen pixels.
     */
    self->scroll_x += dx;
    self->scroll_y += dy;
}
void land_view_scroll_to(LandView * self, float x, float y) {
    self->scroll_x = x;
    self->scroll_y = y;
}
void land_view_scale(LandView * self, float sx, float sy) {
    float cx = self->scroll_x + (self->w / 2 / self->scale_x);
    float cy = self->scroll_y + (self->h / 2 / self->scale_y);
    self->scale_x *= sx;
    self->scale_y *= sy;
    self->scroll_x = cx - (self->w / 2 / self->scale_x);
    self->scroll_y = cy - (self->h / 2 / self->scale_y);
}
void land_view_zoom(LandView * self, float zx, float zy) {
    land_view_scale(self, zx / self->scale_x, zy / self->scale_y);
}
void land_view_scroll_center(LandView * self, float x, float y) {
    /* Given two absolute map coordinates, make them the center of the view.
     */
    self->scroll_x = x - self->w / 2;
    self->scroll_y = y - self->h / 2;
}
void land_view_scroll_center_on_screen(LandView * self, float x, float y) {
    /* Given an on-screen position, make it the new center of the view.
     */
    x -= self->x;
    y -= self->y;
    x += self->scroll_x;
    y += self->scroll_y;
    land_view_scroll_center(self, x, y);
}
void land_view_ensure_visible(LandView * self, float x, float y, float bx, float by) {
    /* Given an absolute map position, scroll the view so it is not within bx/by
     * pixels to the view's border.
     */
    if (x - self->scroll_x < bx) {
        self->scroll_x = x - bx;
    }
    if (x - self->scroll_x > self->w - bx) {
        self->scroll_x = x - self->w + bx;
    }
    if (y - self->scroll_y < by) {
        self->scroll_y = y - by;
    }
    if (y - self->scroll_y > self->h - by) {
        self->scroll_y = y - self->h + by;
    }
}
void land_view_ensure_visible_on_screen(LandView * self, float x, float y, float bx, float by) {
    /* land_view_ensure_visible, but the given position is in screen coordinates.
     */
    x -= self->x;
    y -= self->y;
    x += self->scroll_x;
    y += self->scroll_y;
    land_view_ensure_visible(self, x, y, bx, by);
}
void land_view_ensure_inside_grid(LandView * self, LandGrid * grid) {
    /* For a non-wrapped grid, move the view so it lies within the grid.
     * For a wrapped grid, where the view always is inside the grid, this function
     * only normalizes the scroll position to lie within the "first quadrant".
     */
    if (grid->wrap) {
        float cx, cy, sx, sy;
        land_grid_get_cell_at(grid, self, self->x, self->y, & cx, & cy);
        self->scroll_x = 0;
        self->scroll_y = 0;
        land_grid_get_cell_position(grid, self, cx, cy, & sx, & sy);
        self->scroll_x = sx - self->x;
        self->scroll_y = sy - self->y;
    }
    else {
        int w = grid->x_cells * grid->cell_w;
        int h = grid->y_cells * grid->cell_h;
        if (self->scroll_x < 0) {
            self->scroll_x = 0;
        }
        if (self->scroll_y < 0) {
            self->scroll_y = 0;
        }
        if (self->scroll_x > w - self->w) {
            self->scroll_x = w - self->w;
        }
        if (self->scroll_y > h - self->h) {
            self->scroll_y = h - self->h;
        }
    }
}
void land_view_clip(LandView * self) {
    land_clip(self->x, self->y, self->x + self->w, self->y + self->h);
}
void land_view_to_world(LandView * self, float vx, float vy, float * wx, float * wy) {
    * wx = self->scroll_x + (vx - self->x) / self->scale_x;
    * wy = self->scroll_y + (vy - self->y) / self->scale_y;
}
static LandHash * cache;
LandColor land_color_hsv(float hue, float sat, float val) {
    return platform_color_hsv(hue, sat, val);
}
LandColor land_color_rgba(float r, float g, float b, float a) {
    LandColor c = {r, g, b, a};
    return c;
}
LandColor land_color_premul(float r, float g, float b, float a) {
    LandColor c = {r * a, g * a, b * a, a};
    return c;
}
static int hexval(char c) {
    c = tolower(c);
    if (c >= '0' && c <= '9') {
        return (c - '0');
    }
    if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a');
    }
    return 0;
}
LandColor land_color_name(char const * name) {
    if (name && name [0] == '#') {
        LandColor c;
        c.r = (hexval(name [1]) * 16 + hexval(name [2])) / 255.0;
        c.g = (hexval(name [3]) * 16 + hexval(name [4])) / 255.0;
        c.b = (hexval(name [5]) * 16 + hexval(name [6])) / 255.0;
        c.a = 1;
        return c;
    }
    return platform_color_name(name);
}
LandColor land_color_lerp(LandColor a, LandColor b, float t) {
    return land_color_rgba(a.r + t * (b.r - a.r), a.g + t * (b.g - a.g), a.b + t * (b.b - a.b), a.a + t * (b.a - a.a));
}
char const* color_bash(char const * x) {
    /* bash("bright red")
     * bash("back white")
     * bash("bold blue back bright green")
     * bash("end")
     * Note: The return value remains property of the color module and is
     * not to be freed.
     */
    return bash_mode(x, "3");
}
#define CAT(X, Y1, Y2) \
    if (land_equals(c, X)) { \
        land_concatenate_with_separator(& m, Y1, ";"); \
        land_concatenate(& m, Y2); \
    }
static char const* bash_mode(char const * x, char const * mode) {
    if (cache == NULL) {
        cache = land_hash_new();
    }
    char * cached = land_hash_get(cache, x);
    if (cached) {
        return cached;
    }
    char const * back = strstr(x, "back");
    if (back) {
        if (back == x) {
            return bash_mode(x + 4, "4");
        }
        char * x2 = land_substring(x, 0, back - x);
        char const * fg = bash_mode(x2, "3");
        char const * bg = bash_mode(back, "4");
        char * r = land_strdup(fg);
        land_concatenate(& r, bg);
        land_free(x2);
        land_hash_insert(cache, x, r);
        return r;
    }
    char * m = land_strdup("");
    LandArray * a = land_split(x, ' ');
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(a);
        for (char * c = LandArrayIterator_item(a, &__iter0__); LandArrayIterator_next(a, &__iter0__); c = LandArrayIterator_item(a, &__iter0__)) {
            if (land_equals(c, "bright")) {
                if (land_equals(mode, "3")) {
                    mode = "9";
                }
                else {
                    mode = "10";
                }
            }
            CAT("bold", "", "1");
            CAT("black", mode, "0");
            CAT("red", mode, "1");
            CAT("green", mode, "2");
            CAT("yellow", mode, "3");
            CAT("blue", mode, "4");
            CAT("magenta", mode, "5");
            CAT("cyan", mode, "6");
            CAT("white", mode, "7");
        }
    }
    land_array_destroy_with_strings(a);
    land_prepend(& m, "\x1b[");
    land_concatenate(& m, "m");
    land_hash_insert(cache, x, m);
    return m;
}
#undef CAT
static bool get_data(LandHash * self, LandHashIterator * i, void * (* data)) {
    if (! self->entries) {
        return 0;
    }
    while (i->i < self->size) {
        if (self->entries [i->i]) {
            if (i->j < self->entries [i->i] [0].n) {
                if (data) {
                    * data = self->entries [i->i] [i->j].data;
                }
                return 1;
            }
            i->j = 0;
        }
        i->i++;
    }
    return 0;
}
LandHashIterator LandHashIterator_first(LandHash * self) {
    LandHashIterator i = {0, 0};
    return i;
}
void* LandHashIterator_item(LandHash * self, LandHashIterator * i) {
    void * data = NULL;
    get_data(self, i, & data);
    return data;
}
bool LandHashIterator_next(LandHash * self, LandHashIterator * i) {
    if (get_data(self, i, NULL)) {
        i->j++;
        return 1;
    }
    return 0;
}
#ifdef LAND_MEMLOG
#undef land_hash_new
#undef land_hash_destroy
LandHash* land_hash_new_memlog(char const * f, int l) {
    LandHash * hash = land_hash_new();
    land_memory_add(hash, "hash", 1, f, l);
    return hash;
}
void land_hash_destroy_memlog(LandHash * self, char const * f, int l) {
    land_hash_destroy(self);
    land_memory_remove(self, "hash", 1, f, l);
}
#endif
static unsigned int hash_function(LandHash * self, char const * thekey) {
    int i;
    unsigned int hash = 5381;
    for (i = 0; thekey [i]; i++) {
        unsigned char c = thekey [i];
        hash = hash * 33 + c;
    }
    return hash & (self->size - 1);
}
LandHash* land_hash_new(void) {
    /* """Create a new LandHash."""
     */
    LandHash * self;
    land_alloc(self);
    self->hash_function = hash_function;
    return self;
}
void land_hash_clear(LandHash * self) {
    /* Clears the hash. Referenced data are not touched though.
     */
    for (int i = 0; i < self->size; i += 1) {
        LandHashEntry * entry = self->entries [i];
        if (entry) {
            int j;
            for (j = 0; j < entry->n; j++) {
                land_free(entry [j].thekey);
            }
            land_free(entry);
        }
    }
    if (self->entries) {
        land_free(self->entries);
        self->entries = NULL;
    }
}
void land_hash_destroy(LandHash * self) {
    /* Destroy a LandHash. The data inside the hash are not freed (just
     * everything else, like key names and internal data structures).
     */
    if (! self) {
        return ;
    }
    land_hash_clear(self);
    land_free(self);
}
void* land_hash_insert(LandHash * self, char const * thekey, void * data) {
    /* """Insert data into a LandHash.
     * A LandHash simply is a mapping of keys to data pointers - it will never
     * touch the passed data in any way. E.g. you need to make sure to delete any
     * pointers you add to a hash. A copy of the passed key is made so you need
     * not keep it around.
     * If the key already exists, there will be two entries with the same key
     * from now on, and it is undefined behavior which one will get returned when
     * querying for the key."""
     */
    assert(thekey);
    int i;
    if ((self->count + 1) * 2 > self->size) {
        int oldsize = self->size;
        LandHashEntry * (* oldentries) = self->entries;
        if (! self->size) {
            self->bits = 1;
        }
        else {
            self->bits++;
        }
        self->size = 1 << self->bits;
        self->entries = land_calloc(self->size * sizeof (* self->entries));
        self->count = 0;
        for (i = 0; i < oldsize; i++) {
            LandHashEntry * entry = oldentries [i];
            if (entry) {
                int j;
                for (j = 0; j < entry [0].n; j++) {
                    land_hash_insert(self, entry [j].thekey, entry [j].data);
                    land_free(entry [j].thekey);
                }
                land_free(entry);
            }
        }
        if (oldentries) {
            land_free(oldentries);
        }
    }
    i = self->hash_function(self, thekey);
    LandHashEntry * entry = self->entries [i];
    int n = entry ? entry->n + 1 : 1;
    self->entries [i] = land_realloc(entry, n * sizeof (* entry));
    self->entries [i] [n - 1].thekey = land_strdup(thekey);
    self->entries [i] [n - 1].data = data;
    self->entries [i] [0].n = n;
    self->count++;
    return data;
}
void* land_hash_remove(LandHash * self, char const * thekey) {
    /* """Remove the first entry found with the key, and return the associated
     * data.
     * The returned pointer might need to be destroyed after you remove it from
     * the hash, if it has no more use.
     */
    if (! self->size) {
        return NULL;
    }
    int i = self->hash_function(self, thekey);
    if (! self->entries [i]) {
        return NULL;
    }
    int n = self->entries [i] [0].n;
    int j;
    for (j = 0; j < n; j++) {
        if (! strcmp(self->entries [i] [j].thekey, thekey)) {
            void * data = self->entries [i] [j].data;
            land_free(self->entries [i] [j].thekey);
            if (n > 1) {
                self->entries [i] [j] = self->entries [i] [n - 1];
                self->entries [i] = land_realloc(self->entries [i], (n - 1) * sizeof (* self->entries [i]));
                self->entries [i] [0].n = n - 1;
            }
            else {
                land_free(self->entries [i]);
                self->entries [i] = NULL;
            }
            self->count--;
            return data;
        }
    }
    return NULL;
}
static LandHashEntry* land_hash_get_entry(LandHash * self, char const * thekey) {
    if (! self->size) {
        return NULL;
    }
    int i = self->hash_function(self, thekey);
    if (! self->entries [i]) {
        return NULL;
    }
    int j;
    for (j = 0; j < self->entries [i] [0].n; j++) {
        if (! strcmp(self->entries [i] [j].thekey, thekey)) {
            return & self->entries [i] [j];
        }
    }
    return NULL;
}
void* land_hash_replace(LandHash * self, char const * thekey, void * data) {
    /* If an association to the given key exists, replace it with the given data,
     * and return the old data.
     * Else, do the same as land_hash_insert, and return None.
     */
    LandHashEntry * entry = land_hash_get_entry(self, thekey);
    if (entry) {
        void * old = entry->data;
        entry->data = data;
        return old;
    }
    land_hash_insert(self, thekey, data);
    return NULL;
}
void* land_hash_get(LandHash * self, char const * thekey) {
    /* """Return the data associated with a hash key. If the key exists multiple
     * times, it can be not relied on a certain one being returned. It might always
     * be the same, but it might not be - this is especially true if other entries
     * are added which could lead to a re-hashing when it gets too full.
     * If the key is not found, None is returned.
     */
    LandHashEntry * entry = land_hash_get_entry(self, thekey);
    if (entry) {
        return entry->data;
    }
    return NULL;
}
int land_hash_has(LandHash * self, char const * thekey) {
    LandHashEntry * entry = land_hash_get_entry(self, thekey);
    if (entry) {
        return 1;
    }
    return 0;
}
LandArray* land_hash_keys(LandHash * hash, bool alloc) {
    /* """Return an array containing all the keys in the hash.
     * If alloc is true, each key is allocated and must be freed. A
     * convenient way is to use land_array_destroy_with_strings.
     * Otherwise the strings are direct pointers into the hash - so you
     * must not modify or free them, and they will get invalid if the hash
     * is modifed (even just by adding/removing an unrelated key).
     * You are responsible for destroying the array with land_array_destroy
     * when you are done using it.
     */
    LandArray * array = land_array_new();
    int i;
    for (i = 0; i < hash->size; i++) {
        if (hash->entries [i]) {
            int n = hash->entries [i]->n;
            int j;
            for (j = 0; j < n; j++) {
                char * key = hash->entries [i] [j].thekey;
                if (alloc) {
                    key = land_strdup(key);
                }
                land_array_add_data(& array, key);
            }
        }
    }
    return array;
}
LandArray* land_hash_data(LandHash * hash) {
    /* """Return an array with all the data pointers in the hash. If you want to
     * destroy a hash including all its data, this may be a convenient way to
     * do it:
     * LandArray *data = land_hash_data(hash)
     * for int i = 0 while i < land_array_count(data) with i++:
     * void *entry = land_array_get_nth(data, i)
     * land_free(entry)
     * land_array_destroy(data)
     * land_hash_destroy(hash)
     */
    LandArray * array = land_array_new();
    int i;
    for (i = 0; i < hash->size; i++) {
        if (hash->entries [i]) {
            int n = hash->entries [i]->n;
            int j;
            for (j = 0; j < n; j++) {
                land_array_add_data(& array, hash->entries [i] [j].data);
            }
        }
    }
    return array;
}
void land_hash_print_stats(LandHash * hash) {
    /* """This is an internal function for debugging purposes, which will print
     * out statistics about the hash to the console.
     */
    int i;
    int u = 0;
    int c = 0;
    int l = 0;
    for (i = 0; i < hash->size; i++) {
        if (hash->entries [i]) {
            int n = hash->entries [i]->n;
            if (n > 1) {
                c += n;
            }
            if (n > l) {
                l = n;
            }
            u++;
        }
    }
    printf("hash stats: %d/%d[%d%%] full, %d/%d[%d%%] used, %d/%d[%d%%] colliding, longest chain is %d.\n", hash->count, hash->size, hash->size ? 100 * hash->count / hash->size : 0, u, hash->size, hash->size ? 100 * u / hash->size : 0, c, hash->count, hash->count ? 100 * c / hash->count : 0, l);
}
void* platform_fopen(char const * filename, char const * mode) {
    #ifdef ANDROID
    land_log_message("open %s", filename);
    if (land_starts_with(filename, "/")) {
        al_set_standard_file_interface();
        ALLEGRO_FILE * f = al_fopen(filename, mode);
        al_android_set_apk_file_interface();
        return f;
    }
    #endif
    ALLEGRO_FILE * f = al_fopen(filename, mode);
    return f;
}
void platform_fclose(void * f) {
    al_fclose(f);
}
int platform_fread(void * f, char * buffer, int bytes) {
    return al_fread(f, buffer, bytes);
}
int platform_fwrite(void * f, char const * buffer, int bytes) {
    return al_fwrite(f, buffer, bytes);
}
void platform_ungetc(void * f, int c) {
    al_fungetc(f, c);
}
int platform_fgetc(void * f) {
    return al_fgetc(f);
}
bool platform_feof(void * f) {
    return al_feof(f);
}
void platform_fseek(void * f, int n) {
    al_fseek(f, n, ALLEGRO_SEEK_CUR);
}
static void add_files(char const * rel, LandArray * (* array), ALLEGRO_FS_ENTRY * entry, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data) {
    if (! al_open_directory(entry)) {
        land_log_message("Cannot open directory (%d).\n", al_get_fs_entry_mode(entry) & ALLEGRO_FILEMODE_ISDIR);
        return ;
    }
    while (true) {
        ALLEGRO_FS_ENTRY * next = al_read_directory(entry);
        if (! next) {
            break;
        }
        ALLEGRO_PATH * path = al_create_path(al_get_fs_entry_name(next));
        char const * name = al_get_path_filename(path);
        if (! name [0]) {
            name = al_get_path_component(path, - 1);
        }
        if (strcmp(name, ".") && strcmp(name, "..")) {
            bool is_dir = al_get_fs_entry_mode(next) & ALLEGRO_FILEMODE_ISDIR;
            char rel2 [strlen(rel) + strlen("/") + strlen(name) + 1];
            strcpy(rel2, rel);
            strcat(rel2, "/");
            strcat(rel2, name);
            char const * fpath;
            if (flags & LAND_FULL_PATH) {
                fpath = al_path_cstr(path, '/');
            }
            else if (flags & LAND_RELATIVE_PATH) {
                fpath = rel2;
            }
            else {
                fpath = name;
            }
            int f = 3;
            if (filter) {
                f = filter(fpath, is_dir, data);
            }
            if (f & 1) {
                if (! (* array)) {
                    * array = land_array_new();
                }
                land_array_add(* array, land_strdup(fpath));
            }
            if ((f & 2) && is_dir) {
                add_files(rel2, array, next, filter, flags, data);
            }
        }
        al_destroy_fs_entry(next);
        al_destroy_path(path);
    }
    al_close_directory(entry);
}
LandArray* platform_filelist(char const * dir, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data) {
    land_log_message("platform_filelist %s\n", dir);
    ALLEGRO_FS_ENTRY * entry = al_create_fs_entry(dir);
    LandArray * array = NULL;
    add_files(dir, & array, entry, filter, flags, data);
    al_destroy_fs_entry(entry);
    return array;
}
bool platform_is_dir(char const * path) {
    ALLEGRO_FS_ENTRY * fse = al_create_fs_entry(path);
    bool r = al_get_fs_entry_mode(fse) & ALLEGRO_FILEMODE_ISDIR;
    al_destroy_fs_entry(fse);
    return r;
}
bool platform_file_exists(char const * path) {
    return al_filename_exists(path);
}
char* platform_get_save_file(char const * appname, char const * name) {
    al_set_org_name("");
    al_set_app_name(appname);
    ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_USER_SETTINGS_PATH);
    const char * str = al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP);
    if (! al_filename_exists(str)) {
        land_log_message("Creating new settings path %s.\n", str);
        al_make_directory(str);
    }
    al_set_path_filename(path, name);
    str = al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP);
    land_log_message("Using save file %s.\n", str);
    char * dup = land_strdup(str);
    al_destroy_path(path);
    return dup;
}
char* platform_get_current_directory(void) {
    char * d = al_get_current_directory();
    char * dup = land_strdup(d);
    al_free(d);
    return dup;
}
char* platform_get_data_path(void) {
    ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    char * dup = land_strdup(al_path_cstr(path, '/'));
    al_destroy_path(path);
    return dup;
}
bool platform_remove_file(char const * path) {
    return al_remove_filename(path);
}
    /* ![Land!](logo.png)
     * ## the name
     * It has no special meaning, it's just that in computer games, you make
     * virtual worlds or lands - and that inspired it as use as name for this.
     * The only limits of this land should be your imagination, not programming
     * language obstacles. But if you insist, it could also be a recursive
     * acronym for "Land All New Design".
     * ## history
     * Well, I really started working on this version only some days ago. But I
     * made a library called "land", with the very same goals, about 10-20 years
     * ago. I actually recovered some files of that, but they require a program
     * called TASM to work. I actually found a copy of that, and tried to
     * compile it in dosbox, but still, it wouldn't work. Not that the result
     * would have been interesting for anyone but me :)
     * ## what it is
     * Land is, currently, just a simple framework to assist in creating games,
     * which will work under Windows, Linux and OSX. As well as some others,
     * basically everything Allegro/SDL/OpenGL can get to run (currently only
     * Allegro). It doesn't do a lot, just handle a basic game loop for you.
     * Some may not want this, since it takes control away. But for beginners,
     * it may make things somewhat simpler. And especially, and that's the only
     * thing I care about, for me.
     * ## features/limitations
     * - Written in C, preprocessed by a Python-like syntax.
     * - Automated build process using scons.
     * - Load images as single files, from directories, from .zip files, from
     * fixed-grid/transparent/color-keyed sheets.
     * - Free-form multi-layer tilemaps. The layers use no fixed tile-layout,
     * you can place there what and where you want. (Of course this includes
     * classic tiles.)
     * - Pixel-perfect collision between tilemap-sprite and sprite-sprite,
     * efficient for 1000ds of objects and huge maps. (The algorithm is to
     * first check a grid-cash for proximity, then do a bounding-box check,
     * then pixel-perfect with pre-generated bit-masks.)
     * - Parallax scrolling with arbitrary amount of layers. Define some of the
     * tilemap layers to be parallax layers - scrolling is handled by Land.
     * ## source code
     * Normally, the split into .c/.cpp and .h files is not a problem, either you
     * work out the API first in he .h and then implement, or write first the
     * implementation then derive the .h. But in two cases it is very bad: Designing
     * a new library, and maintaining a library. In the former, it means you need
     * to make every interface change at multiple locations. In the latter case it
     * means, you end up with en entangled mess of headers all over the place.
     * Therefore, in Land, I ended up using preprocessed files from which .c and .h
     * files are auto-generated. That way, the source always stays clean and
     * managable. Looking at the changes of the build process would show how hard it
     * was to end up at the current system (but a lot of that happened before the code
     * was stable enough to move to SVN).
     * ## inheritance and polymorphism
     * What does the technical inplementation of Land look like, given it is
     * implemented in C? Well, polymorphism is done by using VTables, similar to e.g.
     * the Allegro drivers. Inheritance is done by manual aggregation (along with
     * VTables).
     * For example, let's say, you want to use a tilemap, but have your own drawing
     * function called for each tile. Simple create a LandGridInterface object,
     * replace the ->draw_cell method with your own, and replace the ->vt member of your
     * LandGrid object with your own LandGridInterface.
     * TODO: Maybe a macro, something like:
     * LandGridInterface *my_grid_vtable =
     * land_override(land_grid_vtable_normal, cell_draw, my_cell_draw);
     * ## user data
     * Instead of inheriting your own types, it is much easier to simply attach data to
     * land types. For example:
     * int index = land_attach_data(sprite, "mydata", mydata);
     * or
     * int index = land_attach_data(sprite, NULL, mydata);
     * In both cases, you can retrieve the data with:
     * mydata = land_retrieve_data(sprite, index);
     * In the first case, also with:
     * mydata = land_retrieve_named_data(sprite, "mydata")
     * ## containers
     * LandList - a doubly linked list of items. Fast insertion and deletion of
     * items.
     * LandArray - a dynamically growing array. The number of used and allocated
     * elements can differ, so can allocate items in advance, or not de-allocate
     * items in case more are added shortly.
     * LandQueue - like an array but the items are always kept sorted. Useful
     * for something like a priority queue or if you want to (heap-)sort some
     * other container.
     * LandHash - a mapping of strings to the data. Useful if there are many strings
     * to look up, in which case this is faster than looping through a list/array.
     * ## maps, layers, tiles, sprites..
     * One question still is.. what to do about maximum sprite size? Two brute force
     * approaches:
     * - render as much overlap cells that the biggest sprite would be catched
     * This leaves the solution very high-level.. simply draw a bigger area.
     * Drawback is possibly drawing more than necessary most of the time.
     * - add a sprite to every cell it covers.. this is somewhat more complicated,
     * but can have other advantages as well, like easy collision detection
     * Another solution would be to have a maximum size of the cell size in each
     * layer - then simply can group large sprites into a layer with a big enough
     * cell size. This also would deal with collision detection - a sprite simply can
     * never be outside of its cell and the adjacent ones.
     * ## graphics primitives
     * You can directly use all of Allegro's API, as well as OpenGL. Additionally, with
     * the time, Land got it's own graphics primitives:
     * land_color(r, g, b) Sets the color
     * land_transparency(a) Sets transparency
     * land_thickness(t) Sets thickness of lines/pixels/rectangles
     * land_line(x, y, x_, y_) Like the one in Allegro
     * land_move_to(x, y) Sets the cursor position
     * land_line_to(x, y) Draws from the current position towards x/y, but not on x/y
     * itself, and sets the cursor to x/y.
     * land_line_end(x, y) Like land_line_to, but doesn't change the cursor, and also
     * draws on x/y.
     * land_pixel(x, y) Draws a single pixel.
     * land_clip(x, y, w, h)
     * How can you draw not to the screen, but into an image?
     * land_target(image)
     * So far, the state maintained by a LandDisplay thus is:
     * - color_r, color_g, color_b, color_a
     * - thickness
     * - font
     * - text_x, text_y
     * - target
     * - clip_x, clip_y, clip_w, clip_h
     * ## The land song
     * + lalalala-land
     * + Land is "Land All New Design"
     * + so new so shiny so well designed
     * + lalalala-land
     * + Land in sight!
     * + lalalala-land
     * + lalalalalala-land
     * + lal-land
     * (this chapter is all the progress I made when I tried to work on it drunk)
     */
static char const * _version = "1.0.0";
char const* land_version(void) {
    return _version;
}
static LandArray * exit_functions;
static int _exitcode;
void land_without_main(void(* cb)(void)) {
    platform_without_main(cb);
}
void land_set_exitcode(int code) {
    _exitcode = code;
}
int land_get_exitcode(void) {
    return _exitcode;
}
void land_exit_function(void(* function)(void)) {
    land_array_add_data(& exit_functions, function);
}
void land_exit_functions(void) {
    int i, n = land_array_count(exit_functions);
    for (i = n - 1; i >= 0; i--) {
        void(* function)(void) = land_array_get_nth(exit_functions, i);
        function();
    }
    land_array_destroy(exit_functions);
}
void land_wait(double seconds) {
    platform_wait(seconds);
}
int land_argc;
char * (* land_argv);
LandRunner * shortcut_runner;
#define N LAND_RANDOM_N
#define M 397
#define MATRIX_A 0x9908b0dfUL
#define UPPER_MASK 0x80000000UL
#define LOWER_MASK 0x7fffffffUL
static LandRandom default_state = {.mti = N + 1};
static void init_genrand(LandRandom * r, unsigned long s) {
    r->mt [0] = s & 0xffffffffUL;
    for (r->mti = 1; r->mti < N; r->mti++) {
        r->mt [r->mti] = (1812433253UL * (r->mt [r->mti - 1] ^ (r->mt [r->mti - 1] >> 30)) + r->mti);
        r->mt [r->mti] &= 0xffffffffUL;
    }
}
static unsigned long genrand_int32(LandRandom * r) {
    unsigned long y;
    static const unsigned long mag01 [2] = {0x0UL, MATRIX_A};
    if (r->mti >= N) {
        int kk;
        if (r->mti == N + 1) {
            init_genrand(r, 5489UL);
        }
        for (kk = 0; kk < N - M; kk++) {
            y = (r->mt [kk] & UPPER_MASK) | (r->mt [kk + 1] & LOWER_MASK);
            r->mt [kk] = r->mt [kk + M] ^ (y >> 1) ^ mag01 [y & 0x1UL];
        }
        for (; kk < N - 1; kk++) {
            y = (r->mt [kk] & UPPER_MASK) | (r->mt [kk + 1] & LOWER_MASK);
            r->mt [kk] = r->mt [kk + (M - N)] ^ (y >> 1) ^ mag01 [y & 0x1UL];
        }
        y = (r->mt [N - 1] & UPPER_MASK) | (r->mt [0] & LOWER_MASK);
        r->mt [N - 1] = r->mt [M - 1] ^ (y >> 1) ^ mag01 [y & 0x1UL];
        r->mti = 0;
    }
    y = r->mt [r->mti++];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);
    return y;
}
#define MAX_NUMBER 4294967295U
void land_seed(int seed) {
    init_genrand(& default_state, seed);
}
double land_rnd(double rmin, double rmax) {
    /* Random value in the half-open interval [min, max[, that is min is inclusive
     * but max is exclusive.
     */
    if (rmin >= rmax) {
        return rmin;
    }
    return rmin + ((double) genrand_int32(& default_state) / MAX_NUMBER) * (rmax - rmin);
}
int land_rand(int rmin, int rmax) {
    if (rmin >= rmax) {
        return rmin;
    }
    int64_t d = rmax;
    d++;
    d -= rmin;
    return rmin + genrand_int32(& default_state) % d;
}
LandRandom* land_random_new(int seed) {
    LandRandom * self;
    land_alloc(self);
    init_genrand(self, seed);
    return self;
}
void land_random_del(LandRandom * self) {
    land_free(self);
}
int land_random(LandRandom * r, int rmin, int rmax) {
    if (rmin >= rmax) {
        return rmin;
    }
    int64_t d = rmax;
    d++;
    d -= rmin;
    return rmin + genrand_int32(r) % d;
}
#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK
#undef MAX_NUMBER
static void* _get(LandIniSection * s, char const * key) {
    LandIniEntry * e = land_hash_get(s->lookup, key);
    if (e) {
        return e->val;
    }
    return NULL;
}
static void _add(LandIniSection * s, char const * key, void * val) {
    LandIniEntry * e = land_hash_get(s->lookup, key);
    if (e) {
        land_free(e->val);
        e->val = val;
        return ;
    }
    e = land_calloc(sizeof (* e));
    e->key = land_strdup(key);
    e->val = val;
    land_array_add(s->entries, e);
    land_hash_insert(s->lookup, key, e);
}
static void _del(LandIniSection * s) {
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(s->entries);
        for (LandIniEntry * e = LandArrayIterator_item(s->entries, &__iter0__); LandArrayIterator_next(s->entries, &__iter0__); e = LandArrayIterator_item(s->entries, &__iter0__)) {
            land_free(e->key);
            if (e->val) {
                land_free(e->val);
            }
            land_free(e);
        }
    }
    land_array_destroy(s->entries);
    land_hash_destroy(s->lookup);
    land_free(s);
}
static LandIniSection* _new(void) {
    LandIniSection * s = land_calloc(sizeof (* s));
    s->lookup = land_hash_new();
    s->entries = land_array_new();
    return s;
}
void land_ini_set_string(LandIniFile * ini, char const * section, char const * key, char const * val) {
    LandIniSection * s = _get(ini->sections, section);
    if (! s) {
        s = _new();
        _add(ini->sections, section, s);
    }
    _add(s, key, val ? land_strdup(val) : NULL);
}
void land_ini_set_int(LandIniFile * ini, char const * section, char const * key, int val) {
    char temp [100];
    snprintf(temp, sizeof temp, "%d", val);
    land_ini_set_string(ini, section, key, temp);
}
char const* land_ini_get_string(LandIniFile * ini, char const * section, char const * key, char const * de) {
    LandIniSection * s = _get(ini->sections, section);
    if (! s) {
        return de;
    }
    char * v = _get(s, key);
    if (v) {
        return v;
    }
    return de;
}
int land_ini_get_int(LandIniFile * ini, char const * section, char const * key, int de) {
    char const * s = land_ini_get_string(ini, section, key, NULL);
    if (s == NULL) {
        return de;
    }
    return strtol(s, NULL, 0);
}
int land_ini_get_number_of_entries(LandIniFile * ini, char const * section) {
    LandIniSection * s = ini->sections;
    if (! s) {
        return 0;
    }
    if (section) {
        s = _get(s, section);
        if (! s) {
            return 0;
        }
    }
    return land_array_count(s->entries);
}
char const* land_ini_get_nth_entry(LandIniFile * ini, char const * section, int i) {
    /* Get the n-th entry of an ini section. If section is None get the
     * n-th section instead.
     */
    LandIniSection * s = ini->sections;
    if (section) {
        s = _get(s, section);
    }
    LandIniEntry * e = land_array_get_nth(s->entries, i);
    return e->key;
}
static bool is_whitespace(char c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return true;
    }
    return false;
}
#define addc(var, len) \
    var [len] = c; \
    if (len < (int) sizeof (var) - 1) { \
        len++; \
    } \
    var [len] = '\0';
enum State {
    OUTSIDE,
    SECTION,
    KEY,
    EQUALS,
    VALUE,
    COMMENT
};
LandIniFile* land_ini_read(char const * filename) {
    char section_name [1024] = "", key_name [1024] = "", value [1024] = "";
    int slen = 0, klen = 0, vlen = 0;
    State state = OUTSIDE;
    LandIniFile * ini = land_calloc(sizeof (* ini));
    ini->filename = land_strdup(filename);
    ini->sections = _new();
    LandFile * f = land_file_new(filename, "rb");
    if (! f) {
        return ini;
    }
    int done = 0;
    while (! done) {
        int c = land_file_getc(f);
        if (c == EOF) {
            done = 1;
            c = '\n';
        }
        if (c == '\r') {
            continue;
        }
        if (state == OUTSIDE) {
            if (c == '[') {
                slen = 0;
                state = SECTION;
            }
            else if (c == '#') {
                state = COMMENT;
            }
            else if (! is_whitespace(c)) {
                klen = 0;
                addc(key_name, klen);
                state = KEY;
            }
        }
        else if (state == SECTION) {
            if (c == ']' || c == '\n') {
                state = OUTSIDE;
            }
            else {
                addc(section_name, slen);
            }
        }
        else if (state == KEY) {
            if (c == '\n') {
                state = OUTSIDE;
            }
            else if (c == '=') {
                state = EQUALS;
            }
            else if (! is_whitespace(c)) {
                addc(key_name, klen);
            }
        }
        else if (state == EQUALS) {
            if (c == '\n') {
                value [0] = 0;
                goto got_value;
            }
            if (c == '\n' || ! is_whitespace(c)) {
                state = VALUE;
                vlen = 0;
                addc(value, vlen);
            }
        }
        else if (state == VALUE) {
            if (c == '\n') {
                got_value:;
                land_ini_set_string(ini, section_name, key_name, value);
                state = OUTSIDE;
            }
            else {
                addc(value, vlen);
            }
        }
        else if (state == COMMENT) {
            if (c == '\n') {
                state = OUTSIDE;
            }
        }
    }
    land_file_destroy(f);
    return ini;
}
LandIniFile* land_ini_new(char const * filename) {
    LandIniFile * ini = land_calloc(sizeof (* ini));
    ini->filename = land_strdup(filename);
    ini->sections = _new();
    return ini;
}
void land_ini_destroy(LandIniFile * ini) {
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(ini->sections->entries);
        for (LandIniEntry * e = LandArrayIterator_item(ini->sections->entries, &__iter0__); LandArrayIterator_next(ini->sections->entries, &__iter0__); e = LandArrayIterator_item(ini->sections->entries, &__iter0__)) {
            LandIniSection * s = e->val;
            _del(s);
            e->val = NULL;
        }
    }
    _del(ini->sections);
    land_free(ini->filename);
    land_free(ini);
}
void land_ini_writeback(LandIniFile * ini) {
    FILE * f = fopen(ini->filename, "wb");
    if (! f) {
        return ;
    }
    LandIniSection * ss = ini->sections;
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(ss->entries);
        for (LandIniEntry * es = LandArrayIterator_item(ss->entries, &__iter0__); LandArrayIterator_next(ss->entries, &__iter0__); es = LandArrayIterator_item(ss->entries, &__iter0__)) {
            LandIniSection * s = es->val;
            char * name = es->key;
            if (name && name [0]) {
                fprintf(f, "[%s]\n", name);
            }
            {
                LandArrayIterator __iter1__ = LandArrayIterator_first(s->entries);
                for (LandIniEntry * e = LandArrayIterator_item(s->entries, &__iter1__); LandArrayIterator_next(s->entries, &__iter1__); e = LandArrayIterator_item(s->entries, &__iter1__)) {
                    if (e->val) {
                        fprintf(f, "%s = %s\n", e->key, (char *) e->val);
                    }
                }
            }
        }
    }
    fclose(f);
}
LandIniFile* land_ini_app_settings(char const * appname) {
    char * name = platform_get_app_settings_file(appname);
    LandIniFile * ini = land_ini_read(name);
    land_free(name);
    return ini;
}
#undef addc
static char * prefix;
LandFile* land_file_new(char const * path, char const * mode) {
    char * path2;
    if (mode [0] == 'r') {
        path2 = land_path_with_prefix(path);
    }
    else {
        path2 = land_strdup(path);
    }
    void * f = platform_fopen(path2, mode);
    if (! f) {
        land_log_message("Opening file %s (%s) failed.", path2, mode);
        land_free(path2);
        return NULL;
    }
    LandFile * self;
    land_alloc(self);
    self->path = path2;
    self->f = f;
    return self;
}
void land_file_destroy(LandFile * self) {
    platform_fclose(self->f);
    land_free(self->path);
    land_free(self);
}
int land_file_read(LandFile * self, char * buffer, int bytes) {
    return platform_fread(self->f, buffer, bytes);
}
int land_file_write(LandFile * self, char const * buffer, int bytes) {
    return platform_fwrite(self->f, buffer, bytes);
}
void land_file_print(LandFile * self, char const * f, ...) {
    char s [1024];
    va_list args;
    va_start(args, f);
    vsnprintf(s, sizeof s, f, args);
    strcat(s, "\n");
    va_end(args);
    land_file_write(self, s, strlen(s));
}
void land_file_printnn(LandFile * self, char const * f, ...) {
    char s [1024];
    va_list args;
    va_start(args, f);
    vsnprintf(s, sizeof s, f, args);
    va_end(args);
    land_file_write(self, s, strlen(s));
}
int land_file_fputs(LandFile * self, char const * string) {
    int n = strlen(string);
    return land_file_write(self, string, n);
}
int land_file_getc(LandFile * self) {
    return platform_fgetc(self->f);
}
void land_file_ungetc(LandFile * self, int c) {
    platform_ungetc(self->f, c);
}
bool land_file_eof(LandFile * self) {
    return platform_feof(self->f) != 0;
}
void land_file_skip(LandFile * self, int n) {
    platform_fseek(self->f, n);
}
uint32_t land_file_get32le(LandFile * self) {
    uint32_t a = platform_fgetc(self->f);
    uint32_t b = platform_fgetc(self->f);
    uint32_t c = platform_fgetc(self->f);
    uint32_t d = platform_fgetc(self->f);
    return a | (b << 8) | (c << 16) | (d << 24);
}
uint16_t land_file_get16le(LandFile * self) {
    uint16_t a = platform_fgetc(self->f);
    uint16_t b = platform_fgetc(self->f);
    return a | (b << 8);
}
uint32_t land_file_get32be(LandFile * self) {
    uint32_t a = platform_fgetc(self->f);
    uint32_t b = platform_fgetc(self->f);
    uint32_t c = platform_fgetc(self->f);
    uint32_t d = platform_fgetc(self->f);
    return d | (c << 8) | (b << 16) | (a << 24);
}
uint16_t land_file_get16be(LandFile * self) {
    uint16_t a = platform_fgetc(self->f);
    uint16_t b = platform_fgetc(self->f);
    return b | (a << 8);
}
bool land_file_is_dir(char const * name) {
    return platform_is_dir(name);
}
bool land_file_exists(char const * name) {
    return platform_file_exists(name);
}
char* land_get_save_file(char const * appname, char const * name) {
    /* The returned string is owned by the caller and needs to be freed with
     * land_free.
     */
    return platform_get_save_file(appname, name);
}
char* land_get_current_directory(void) {
    return platform_get_current_directory();
}
char* land_get_data_path(void) {
    return platform_get_data_path();
}
char* land_path_with_prefix(char const * name) {
    int n = strlen(name);
    if (prefix) {
        n += strlen(prefix);
    }
    n++;
    char * r = land_malloc(n);
    if (prefix) {
        strcpy(r, prefix);
        strcat(r, name);
    }
    else {
        strcpy(r, name);
    }
    return r;
}
void land_set_prefix(char const * path) {
    if (! path) {
        land_free(prefix);
        land_log_message("Prefix unset.\n");
    }
    else {
        prefix = land_realloc(prefix, strlen(path) + 1);
        strcpy(prefix, path);
        land_log_message("Prefix set to %s.\n", prefix);
    }
}
void land_find_data_prefix(char const * path) {
    char s [3 * 10 + 1] = "";
    for (int i = 0; i < 10; i += 1) {
        land_set_prefix(s);
        char * p = land_path_with_prefix(path);
        if (land_file_is_dir(p)) {
            land_set_prefix(p);
            land_free(p);
            return ;
        }
        strcat(s, "../");
    }
    land_set_prefix(path);
}
char* land_replace_filename(char const * path, char const * name) {
    char * slash = strrchr(path, '/');
    int n = 0;
    if (slash) {
        n = slash - path;
    }
    char * result = land_malloc(n + strlen("/") + strlen(name) + 1);
    strncpy(result, path, n);
    result [n] = 0;
    strcat(result, "/");
    strcat(result, name);
    return result;
}
bool land_file_remove(char const * path) {
    return platform_remove_file(path);
}
#define LOG_COLOR_STATS 0
extern LandDataFile * _land_datafile;
static void(* _cb)(char const * path, LandImage * image);
static int bitmap_count, bitmap_memory;
void land_image_set_callback(void(* cb)(char const * path, LandImage * image)) {
    _cb = cb;
}
static LandImage* _load(char const * filename, bool mem) {
    LandImage * self;
    char * path = land_path_with_prefix(filename);
    land_log_message("land_image_load %s..", path);
    self = platform_image_load(path, mem);
    land_free(path);
    bitmap_count++;
    _load2(self);
    return self;
}
static void _load2(LandImage * self) {
    if (self->flags & LAND_LOADED) {
        int w = land_image_width(self);
        int h = land_image_height(self);
        land_log_message_nostamp("success (%d x %d)\n", w, h);
        if (self->flags & LAND_IMAGE_CENTER) {
            land_image_center(self);
        }
        if (self->flags & LAND_AUTOCROP) {
            land_image_auto_crop(self);
        }
        if (! (self->flags & LAND_IMAGE_MEMORY)) {
            land_image_prepare(self);
        }
        land_log_message("prepared l=%.0f, t=%.0f, r=%.0f, b=%.0f\n", self->l, self->t, self->r, self->b);
        #ifdef LOG_COLOR_STATS
        float red = 0, green = 0, blue = 0, alpha = 0;
        int n = 1;
        n = land_image_color_stats(self, & red, & green, & blue, & alpha);
        land_log_message(" (%.2f|%.2f|%.2f|%.2f).\n", red / n, green / n, blue / n, alpha / n);
        #endif
        bitmap_memory += w * h * 4;
        land_log_message(" %d bitmaps (%.1fMB).\n", bitmap_count, bitmap_memory / 1024.0 / 1024.0);
    }
    else {
        land_log_message_nostamp("failure\n");
    }
    if (_cb) {
        _cb(self->filename, self);
    }
}
LandImage* land_image_load(char const * filename) {
    return _load(filename, 0);
}
LandImage* land_image_load_memory(char const * filename) {
    return _load(filename, 1);
}
LandImage* land_image_new_deferred(char const * filename) {
    LandImage * self = land_image_new(0, 0);
    self->filename = land_path_with_prefix(filename);
    return self;
}
bool land_image_load_on_demand(LandImage * self) {
    if (self->flags & LAND_LOADED) {
        return 0;
    }
    if (self->flags & LAND_FAILED) {
        return 0;
    }
    land_log_message("land_image_load_on_demand %s..", self->filename);
    platform_image_load_on_demand(self);
    _load2(self);
    return 1;
}
LandImage* land_image_memory_new(int w, int h) {
    /* Creates a new image. If w or h are 0, the image will have no contents at
     * all (this can be useful if the contents are to be added later).
     * The image will always be a simple memory rectangle of pixels, with no
     * driver specific optimizations.
     */
    assert(0);
    return NULL;
}
LandImage* land_image_new(int w, int h) {
    /* Creates a new image. If w and h are 0, the image will have no contents at
     * all (this can be useful if the contents are to be added later).
     */
    LandImage * self = land_display_new_image();
    self->width = w;
    self->height = h;
    if (w || h) {
        platform_image_empty(self);
    }
    bitmap_count++;
    bitmap_memory += w * h * 4;
    return self;
}
LandImage* land_image_create(int w, int h) {
    /* Like land_image_new, but clears the image to all 0 initially.
     */
    LandImage * self = land_display_new_image();
    self->width = w;
    self->height = h;
    platform_image_empty(self);
    bitmap_count++;
    bitmap_memory += w * h * 4;
    return self;
}
void land_image_del(LandImage * self) {
    if (! self) {
        return ;
    }
    if (! (self->flags & LAND_SUBIMAGE)) {
        land_image_destroy_pixelmasks(self);
        if (self->name) {
            land_free(self->name);
        }
        if (self->filename && self->filename != self->name) {
            land_free(self->filename);
        }
        bitmap_count--;
        bitmap_memory -= self->width * self->height * 4;
    }
    land_display_del_image(self);
}
void land_image_destroy(LandImage * self) {
    land_image_del(self);
}
void land_image_crop(LandImage * self, int x, int y, int w, int h) {
    /* Crops an image to the specified rectangle. All image contents outside the
     * rectangle will be lost. You can also use this to make an image larger, in
     * which case the additional borders are filled with transparency. The offset
     * need not lie within the image.
     */
    if (self->width == w && self->height == h && x == 0 && y == 0) {
        return ;
    }
    platform_image_crop(self, x, y, w, h);
}
void land_image_auto_crop(LandImage * self) {
    /* This will optimize an image by cropping away any completely transparent
     * borders it may have.
     */
    int w = land_image_width(self);
    int h = land_image_height(self);
    unsigned char * rgba = land_malloc(w * h * 4);
    land_image_get_rgba_data(self, rgba);
    int mini = w;
    int maxi = - 1;
    int minj = h;
    int maxj = - 1;
    for (int j = 0; j < h; j++) {
        uint32_t * row = (void *)(rgba + j * w * 4);
        for (int i = 0; i < w; i++) {
            if (row [i] & 0xff000000) {
                if (i < mini) {
                    mini = i;
                }
                if (i > maxi) {
                    maxi = i;
                }
                if (j < minj) {
                    minj = j;
                }
                if (j > maxj) {
                    maxj = j;
                }
            }
        }
    }
    land_free(rgba);
    if (maxi == - 1) {
        mini = maxi = minj = maxj = 0;
    }
    self->l = mini;
    self->t = minj;
    self->r = w - 1 - maxi;
    self->b = h - 1 - maxj;
}
LandImage* land_image_new_from(LandImage * copy, int x, int y, int w, int h) {
    /* Create a new image, copying pixel data from a rectangle in an existing
     * image.
     */
    land_log_message("land_image_new_from %s..", copy->name);
    LandImage * self = land_image_new(w, h);
    land_set_image_display(self);
    land_blend(LAND_BLEND_SOLID);
    land_image_draw_partial(copy, copy->x, copy->y, x, y, w, h);
    land_unset_image_display();
    land_log_message_nostamp("success (%d x %d)\n", w, h);
    #ifdef LOG_COLOR_STATS
    float red, green, blue, alpha;
    int n;
    n = land_image_color_stats(self, & red, & green, & blue, & alpha);
    land_log_message(" (%.2f|%.2f|%.2f|%.2f).\n", red / n, green / n, blue / n, alpha / n);
    #endif
    land_log_message(" %d bitmaps (%.1fMB).\n", bitmap_count, bitmap_memory / 1024.0 / 1024.0);
    return self;
}
int land_image_color_stats(LandImage * self, float * red, float * green, float * blue, float * alpha) {
    /* Returns the number of pixels in the image, and the average red, green, blue
     * and alpha component.
     */
    int n = 0;
    int w = land_image_width(self);
    int h = land_image_height(self);
    * red = 0;
    * green = 0;
    * blue = 0;
    * alpha = 0;
    unsigned char * rgba = land_malloc(w * h * 4);
    land_image_get_rgba_data(self, rgba);
    int p = 0;
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            * red += rgba [p++] * 1.0 / 255.0;
            * green += rgba [p++] * 1.0 / 255.0;
            * blue += rgba [p++] * 1.0 / 255.0;
            * alpha += rgba [p++] * 1.0 / 255.0;
            n++;
        }
    }
    land_free(rgba);
    return n;
}
void land_image_color_replace(LandImage * self, int r255, int g255, int b255, int a255, int _r255, int _g255, int _b255, int _a255) {
    /* Replaces a color with another.
     */
    assert(0);
}
void land_image_colorkey(LandImage * self, int r255, int g255, int b255) {
    /* Replaces all pixels in the image matching the given RGB triplet (in 0..255
     * format) with full transparency.
     */
    assert(0);
}
void land_image_colorkey_hack(LandImage * self, int allegro_color) {
    /* Like land_image_colorkey, but even more hackish, you directly specify
     * the color in Allegro's format. The only use for this is if you load
     * paletted pictures and want to colorkey by index.
     */
    assert(0);
}
void land_image_colorize(LandImage * self, LandImage * colormask) {
    /* Colorizes the part of the image specified by the mask with the current
     * color. The mask uses (1, 0, 1) for transparent, and the intensity is
     * otherwise used as intensity of the replacement color.
     */
    assert(0);
}
void land_image_colorize_replace(LandImage * self, int n, int * rgb) {
    /* This takes a list of colors and replaces all colors in the image
     * corresponding to one of them with the current color.
     * The colors use integer 0..255 format, since exact comparison with
     * the usual floating point colors would be difficult otherwise. The
     * array ''rgb'' should have 3 * n integers, consisting of consecutive
     * R, G, B triplets to replace.
     * The first rgb triplet has a special meaning - it determines the image color
     * which is mapped to the current color. All matching colors with a larger
     * rgb sum then are mapped to a color between the first color and pure weight,
     * depending on their rgb sum. All colors with a smaller rgb sum are mapped
     * to a range from total black to the first color.
     */
    int w = land_image_width(self);
    int h = land_image_height(self);
    unsigned char rgba [w * h * 4];
    land_image_get_rgba_data(self, rgba);
    unsigned char * p = rgba;
    float fr, fg, fb, fa;
    land_get_color(& fr, & fg, & fb, & fa);
    int red = fr * 255;
    int green = fg * 255;
    int blue = fb * 255;
    int base_red = rgb [0];
    int base_green = rgb [1];
    int base_blue = rgb [2];
    int base_sum = base_red + base_green + base_blue;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int r = * (p + 0);
            int g = * (p + 1);
            int b = * (p + 2);
            for (int i = 0; i < n; i++) {
                if (rgb [i * 3 + 0] == r && rgb [i * 3 + 1] == g && rgb [i * 3 + 2] == b) {
                    int sum = r + g + b;
                    int nr, ng, nb;
                    if (sum <= base_sum) {
                        nr = red * sum / base_sum;
                        ng = green * sum / base_sum;
                        nb = blue * sum / base_sum;
                    }
                    else {
                        int isum = 255 * 3 - sum;
                        int ibase_sum = 255 * 3 - base_sum;
                        nr = 255 - (255 - red) * isum / ibase_sum;
                        ng = 255 - (255 - green) * isum / ibase_sum;
                        nb = 255 - (255 - blue) * isum / ibase_sum;
                    }
                    * (p + 0) = nr;
                    * (p + 1) = ng;
                    * (p + 2) = nb;
                }
            }
            p += 4;
        }
    }
    land_image_set_rgba_data(self, rgba);
    land_image_prepare(self);
}
LandImage* land_image_split_mask_from_colors(LandImage * self, int n_rgb, int * rgb) {
    /* Takes the same parameters as land_image_colorize_replace - but instead of
     * recoloring the image itself, creates a separate image of the same size,
     * which is transparent except where mask colors have been found in the
     * given image. Here, it is colored in graylevels with the intensity
     * corresponding to the mask colors. In the original image, all mask colors
     * are replaced by transparency.
     * The use of this function is to always draw the mask over the original
     * image, but tint the white mask to other colors.
     */
    assert(0);
}
void land_image_prepare(LandImage * self) {
    /* This is used to convert image data into a device dependent format, which
     * is used to display the image (instead of the raw R/G/B/A values). Usually
     * this is not needed, but it can be useful for certain optimizations, where
     * the automatic synchronization is circumvented.
     */
    platform_image_prepare(self);
}
static int callback(const char * filename, int attrib, void * param) {
    LandArray * (* filenames) = param;
    land_array_add_data(filenames, land_strdup(filename));
    return 0;
}
static int compar(void const * a, void const * b) {
    char * an = * (char * *) a;
    char * bn = * (char * *) b;
    return strcmp(an, bn);
}
static int filter(char const * name, bool is_dir, void * data) {
    char const * pattern = data;
    if (is_dir) {
        return 2;
    }
    if (land_fnmatch(pattern, name)) {
        return 1;
    }
    return 0;
}
LandArray* land_load_images_cb(char const * pattern, void(* cb)(LandImage * image, void * data), void * data) {
    /* Load all images matching the file name pattern, and create an array
     * referencing them all, in alphabetic filename order. The callback function
     * is called on each image along the way.
     */
    LandBuffer * dirbuf = land_buffer_new();
    int j = 0;
    for (int i = 0; pattern [i]; i++) {
        if (pattern [i] == '/' || pattern [i] == '\\') {
            land_buffer_add(dirbuf, pattern + j, i - j);
            j = i;
        }
        if (pattern [i] == '?' || pattern [i] == '*') {
            break;
        }
    }
    char * dir = land_buffer_finish(dirbuf);
    LandArray * filenames = NULL;
    int count = 0;
    if (_land_datafile) {
        count = land_datafile_for_each_entry(_land_datafile, pattern, callback, & filenames);
    }
    if (! count) {
        filenames = land_filelist(dir, filter, LAND_RELATIVE_PATH, (void *) pattern);
        if (filenames) {
            count = filenames->count;
        }
        else {
            land_log_message("No files at all match %s.\n", pattern);
        }
    }
    land_free(dir);
    if (! filenames) {
        return NULL;
    }
    qsort(filenames->data, count, sizeof (void *), compar);
    LandArray * array = NULL;
    int i;
    for (i = 0; i < filenames->count; i++) {
        char * filename = land_array_get_nth(filenames, i);
        LandImage * image = land_image_load(filename);
        land_free(filename);
        if (image) {
            if (cb) {
                cb(image, data);
            }
            land_array_add_data(& array, image);
        }
    }
    land_array_destroy(filenames);
    return array;
}
static void defcb(LandImage * image, void * p) {
    int * data = p;
    if (data [0]) {
        land_image_center(image);
    }
    if (data [1]) {
        land_image_auto_crop(image);
    }
}
LandArray* land_load_images(char const * pattern, int center, int auto_crop) {
    /* Load all images matching the file name pattern, and create an array
     * referencing them all.
     */
    int data [2] = {center, auto_crop};
    return land_load_images_cb(pattern, defcb, data);
}
LandImage* land_image_sub(LandImage * parent, float x, float y, float w, float h) {
    LandImage * self = platform_image_sub(parent, x, y, w, h);
    return self;
}
LandArray* land_image_load_sheet(char const * filename, int offset_x, int offset_y, int grid_w, int grid_h, int x_gap, int y_gap, int x_count, int y_count, int auto_crop) {
    LandArray * array = NULL;
    LandImage * sheet = land_image_load(filename);
    if (! sheet) {
        return NULL;
    }
    int x, y, i, j;
    for (j = 0; j < y_count; j++) {
        for (i = 0; i < x_count; i++) {
            x = offset_x + i * (grid_w + x_gap);
            y = offset_y + j * (grid_h + y_gap);
            LandImage * sub = land_image_sub(sheet, x, y, grid_w, grid_h);
            if (auto_crop) {
                land_image_auto_crop(sub);
            }
            land_array_add_data(& array, sub);
        }
    }
    if (_cb) {
        _cb(filename, sheet);
    }
    return array;
}
LandArray* land_image_load_split_sheet(char const * filename, int offset_x, int offset_y, int grid_w, int grid_h, int x_gap, int y_gap, int x_count, int y_count, int auto_crop) {
    LandArray * array = NULL;
    LandImage * sheet = land_image_load_memory(filename);
    if (! sheet) {
        return NULL;
    }
    int x, y, i, j;
    for (j = 0; j < y_count; j++) {
        for (i = 0; i < x_count; i++) {
            x = offset_x + i * (grid_w + x_gap);
            y = offset_y + j * (grid_h + y_gap);
            LandImage * sub = land_image_new_from(sheet, x, y, grid_w, grid_h);
            land_array_add_data(& array, sub);
        }
    }
    land_image_del(sheet);
    return array;
}
void land_image_draw_scaled_rotated_tinted_flipped(LandImage * self, float x, float y, float sx, float sy, float angle, float r, float g, float b, float alpha, int flip) {
    platform_image_draw_scaled_rotated_tinted_flipped(self, x, y, sx, sy, angle, r, g, b, alpha, flip);
}
void land_image_draw_scaled_rotated_tinted(LandImage * self, float x, float y, float sx, float sy, float angle, float r, float g, float b, float alpha) {
    land_image_draw_scaled_rotated_tinted_flipped(self, x, y, sx, sy, angle, r, g, b, alpha, 0);
}
void land_image_draw_scaled_rotated(LandImage * self, float x, float y, float sx, float sy, float angle) {
    land_image_draw_scaled_rotated_tinted(self, x, y, sx, sy, angle, 1, 1, 1, 1);
}
void land_image_draw_scaled(LandImage * self, float x, float y, float sx, float sy) {
    land_image_draw_scaled_rotated_tinted(self, x, y, sx, sy, 0, 1, 1, 1, 1);
}
void land_image_draw_rotated(LandImage * self, float x, float y, float a) {
    land_image_draw_scaled_rotated_tinted(self, x, y, 1, 1, a, 1, 1, 1, 1);
}
void land_image_draw_rotated_flipped(LandImage * self, float x, float y, float a) {
    land_image_draw_scaled_rotated_tinted_flipped(self, x, y, 1, 1, a, 1, 1, 1, 1, 1);
}
void land_image_draw_rotated_tinted(LandImage * self, float x, float y, float a, float r, float g, float b, float alpha) {
    land_image_draw_scaled_rotated_tinted(self, x, y, 1, 1, a, r, g, b, alpha);
}
void land_image_draw_scaled_tinted(LandImage * self, float x, float y, float sx, float sy, float r, float g, float b, float alpha) {
    land_image_draw_scaled_rotated_tinted(self, x, y, sx, sy, 0, r, g, b, alpha);
}
void land_image_draw(LandImage * self, float x, float y) {
    land_image_draw_scaled_rotated_tinted(self, x, y, 1, 1, 0, 1, 1, 1, 1);
}
void land_image_draw_flipped(LandImage * self, float x, float y) {
    land_image_draw_scaled_rotated_tinted_flipped(self, x, y, 1, 1, 0, 1, 1, 1, 1, 1);
}
void land_image_draw_tinted(LandImage * self, float x, float y, float r, float g, float b, float alpha) {
    land_image_draw_scaled_rotated_tinted(self, x, y, 1, 1, 0, r, g, b, alpha);
}
void land_image_grab(LandImage * self, int x, int y) {
    platform_image_grab_into(self, x, y, 0, 0, self->width, self->height);
}
void land_image_grab_into(LandImage * self, float x, float y, float tx, float ty, float tw, float th) {
    platform_image_grab_into(self, x, y, tx, ty, tw, th);
}
void land_image_offset(LandImage * self, int x, int y) {
    self->x = x;
    self->y = y;
}
void land_image_memory_draw(LandImage * self, float x, float y) {
    assert(0);
}
void land_image_center(LandImage * self) {
    self->x = 0.5 * self->width;
    self->y = 0.5 * self->height;
    self->flags |= LAND_IMAGE_WAS_CENTERED;
}
void land_image_init(void) {
    ;
}
void land_image_exit(void) {
    ;
}
void land_image_clip(LandImage * self, float x, float y, float x_, float y_) {
    self->l = x;
    self->t = y;
    self->r = self->width - x_;
    self->b = self->height - y_;
}
void land_image_unclip(LandImage * self) {
    self->l = 0;
    self->t = 0;
    self->r = 0;
    self->b = 0;
}
void land_image_draw_partial(LandImage * self, float x, float y, float sx, float sy, float sw, float sh) {
    float l = self->l;
    float t = self->t;
    float r = self->r;
    float b = self->b;
    land_image_clip(self, sx, sy, sx + sw, sy + sh);
    land_image_draw(self, x - sx, y - sy);
    self->l = l;
    self->t = t;
    self->r = r;
    self->b = b;
}
int land_image_height(LandImage * self) {
    return self->height;
}
int land_image_width(LandImage * self) {
    return self->width;
}
void land_image_get_rgba_data(LandImage * self, unsigned char * rgba) {
    platform_image_get_rgba_data(self, rgba);
}
void land_image_set_rgba_data(LandImage * self, unsigned char const * rgba) {
    /* Copies the rgba data, overwriting the image contents. Since data are copied
     * rgba can be safely deleted after returning from the function.
     */
    platform_image_set_rgba_data(self, rgba);
}
void land_image_save(LandImage * self, char const * filename) {
    platform_image_save(self, filename);
}
int land_image_opengl_texture(LandImage * self) {
    return platform_image_opengl_texture(self);
}
void land_image_flip(LandImage * self) {
    int w = land_image_width(self);
    int h = land_image_height(self);
    unsigned char * rgba = land_malloc(w * h * 4);
    land_image_get_rgba_data(self, rgba);
    for (int j = 0; j < h; j++) {
        uint32_t * row = (void *)(rgba + j * w * 4);
        for (int i = 0; i < w / 2; i++) {
            uint32_t temp = row [i];
            row [i] = row [w - 1 - i];
            row [w - 1 - i] = temp;
        }
    }
    land_image_set_rgba_data(self, rgba);
    land_free(rgba);
}
LandImage* land_image_clone(LandImage * self) {
    int w = land_image_width(self);
    int h = land_image_height(self);
    LandImage * clone = land_image_new(w, h);
    unsigned char * rgba = land_malloc(w * h * 4);
    land_image_get_rgba_data(self, rgba);
    land_image_set_rgba_data(clone, rgba);
    land_free(rgba);
    clone->x = self->x;
    clone->y = self->y;
    return clone;
}
void land_image_fade_to_color(LandImage * self) {
    int w = land_image_width(self);
    int h = land_image_height(self);
    unsigned char * rgba = land_malloc(w * h * 4);
    land_image_get_rgba_data(self, rgba);
    float fr, fg, fb, fa;
    land_get_color(& fr, & fg, & fb, & fa);
    int red = fr * 255;
    int green = fg * 255;
    int blue = fb * 255;
    int alpha = fa * 255;
    for (int j = 0; j < h; j++) {
        unsigned char * row = rgba + j * w * 4;
        for (int i = 0; i < w; i++) {
            int a = row [i * 4 + 3];
            if (! a) {
                continue;
            }
            int ar = row [i * 4 + 0];
            int ag = row [i * 4 + 1];
            int ab = row [i * 4 + 2];
            row [i * 4 + 0] = (red * alpha * a + ar * (255 - alpha) * 255) / (255 * 255);
            row [i * 4 + 1] = (green * alpha * a + ag * (255 - alpha) * 255) / (255 * 255);
            row [i * 4 + 2] = (blue * alpha * a + ab * (255 - alpha) * 255) / (255 * 255);
        }
    }
    land_image_set_rgba_data(self, rgba);
    land_free(rgba);
}
LandImage* land_image_from_xpm(char const * (* xpm)) {
    int w, h, palette_size, pixel_size;
    sscanf(xpm [0], "%d %d %d %d", & w, & h, & palette_size, & pixel_size);
    LandColor palette [65536];
    for (int i = 0; i < palette_size; i += 1) {
        char const * entry = xpm [1 + i];
        int p = 0;
        for (int j = 0; j < pixel_size; j += 1) {
            p *= 256;
            p += (unsigned char) entry [j];
        }
        palette [p] = land_color_name(entry + pixel_size + 3);
    }
    LandImage * self = land_image_new(w, h);
    unsigned char * rgba = land_malloc(w * h * 4);
    for (int y = 0; y < h; y += 1) {
        for (int x = 0; x < w; x += 1) {
            char const * pos = xpm [1 + palette_size + y] + x * pixel_size;
            int p = 0;
            for (int j = 0; j < pixel_size; j += 1) {
                p *= 256;
                p += (unsigned char) pos [j];
            }
            LandColor c = palette [p];
            rgba [y * w * 4 + x * 4 + 0] = c.r * 255;
            rgba [y * w * 4 + x * 4 + 1] = c.g * 255;
            rgba [y * w * 4 + x * 4 + 2] = c.b * 255;
            rgba [y * w * 4 + x * 4 + 3] = c.a * 255;
        }
    }
    land_image_set_rgba_data(self, rgba);
    land_free(rgba);
    return self;
}
#undef LOG_COLOR_STATS
#define BB(x1, y1, x2, y2, x3, y3, x4, y4) \
    * bl = x1 * cos(angle) + y1 * sin(angle); \
    * bt = y2 * cos(angle) - x2 * sin(angle); \
    * br = x3 * cos(angle) + y3 * sin(angle); \
    * bb = y4 * cos(angle) - x4 * sin(angle);
static void get_bounding_box(float l, float t, float r, float b, float angle, float * bl, float * bt, float * br, float * bb) {
    if (angle < LAND_PI / 2) {
        BB(l, t, r, t, r, b, l, b);
    }
    else if (angle < LAND_PI) {
        BB(r, t, r, b, l, b, l, t);
    }
    else if (angle < 3 * LAND_PI / 2) {
        BB(r, b, l, b, l, t, r, t);
    }
    else {
        BB(l, b, l, t, r, t, r, b);
    }
}
#ifdef DEBUG_MASK
static void printout_mask(SinglePixelMask * mask) {
    int i;
    int mask_w = mask->w;
    for (i = 0; i < mask->h; i++) {
        int j;
        for (j = 0; j < mask_w; j++) {
            int m = mask->data [mask_w * i + j];
            int b;
            for (b = 0; b < 32; b++) {
                printf("%c", m & (1 << b) ? '1' : '0');
            }
        }
        printf("\n");
    }
    printf("---\n");
}
#endif
static LandPixelMask* pixelmask_create_flip(LandImage * image, int n, int threshold, bool flipped) {
    LandPixelMask * mask;
    int j;
    int angle_count = n;
    if (flipped) {
        n *= 2;
    }
    mask = land_malloc(sizeof (* mask) + sizeof (SinglePixelMask *) * n);
    mask->n = n;
    mask->flipped = flipped;
    int bmpw = land_image_width(image) - image->l - image->r;
    int bmph = land_image_height(image) - image->t - image->b;
    mask->w = bmpw;
    mask->h = bmph;
    mask->x = image->l;
    mask->y = image->t;
    for (j = 0; j < n; j++) {
        int j2 = j;
        if (j2 >= angle_count) {
            j2 -= angle_count;
        }
        float angle = j2 * LAND_PI * 2 / angle_count;
        float w, h;
        if (angle < LAND_PI / 2) {
            w = bmpw * cos(angle) + bmph * sin(angle);
            h = bmph * cos(angle) + bmpw * sin(angle);
        }
        else if (angle < LAND_PI) {
            w = bmpw * (- cos(angle)) + bmph * sin(angle);
            h = bmph * (- cos(angle)) + bmpw * sin(angle);
        }
        else if (angle < 3 * LAND_PI / 2) {
            w = bmpw * (- cos(angle)) + bmph * (- sin(angle));
            h = bmph * (- cos(angle)) + bmpw * (- sin(angle));
        }
        else {
            w = bmpw * cos(angle) + bmph * (- sin(angle));
            h = bmph * cos(angle) + bmpw * (- sin(angle));
        }
        int tw = ceil(w);
        int th = ceil(h);
        LandImage * temp = land_image_create(tw, th);
        land_set_image_display(temp);
        float backup_x = image->x;
        float backup_y = image->y;
        image->x = image->l + 0.5 * bmpw;
        image->y = image->t + 0.5 * bmph;
        if (flipped && j >= n / 2) {
            land_image_draw_rotated_flipped(image, w / 2.0, h / 2.0, angle);
        }
        else {
            land_image_draw_rotated(image, w / 2.0, h / 2.0, angle);
        }
        image->x = backup_x;
        image->y = backup_y;
        land_unset_image_display();
        int mask_w = 1 + (tw + 31) / 32;
        mask->rotation [j] = land_malloc(sizeof (* mask->rotation [j]) + mask_w * th * sizeof (uint32_t));
        mask->rotation [j]->w = mask_w;
        mask->rotation [j]->h = th;
        unsigned char rgba [tw * th * 4];
        land_image_get_rgba_data(temp, rgba);
        land_image_destroy(temp);
        for (int y = 0; y < th; y++) {
            int x;
            for (x = 0; x < tw; x += 32) {
                int bits = 0;
                for (int i = 0; i < 32 && x + i < tw; i++) {
                    if (rgba [y * tw * 4 + (x + i) * 4 + 3] >= threshold) {
                        bits += 1 << i;
                    }
                }
                mask->rotation [j]->data [y * mask_w + x / 32] = bits;
            }
            mask->rotation [j]->data [y * mask_w + x / 32] = 0;
        }
        #ifdef DEBUG_MASK
        printout_mask(mask->rotation [j]);
        #endif
    }
    return mask;
}
static LandPixelMask* pixelmask_create(LandImage * image, int n, int threshold) {
    bool flipped = n < 0;
    if (flipped) {
        n = - n;
    }
    return pixelmask_create_flip(image, n, threshold, flipped);
}
static void pixelmask_destroy(LandPixelMask * mask) {
    int j;
    for (j = 0; j < mask->n; j++) {
        land_free(mask->rotation [j]);
    }
    land_free(mask);
}
static int mask_get_rotation_frame(LandPixelMask * mask, float angle, bool flipped) {
    int n = mask->n;
    if (mask->flipped) {
        n /= 2;
    }
    float r = n * angle / (2 * LAND_PI);
    if (r > 0) {
        r += 0.5;
    }
    else {
        r -= 0.5;
    }
    int i = (int)(r) % n;
    if (i < 0) {
        i += n;
    }
    if (mask->flipped && flipped) {
        i += mask->n / 2;
    }
    return i;
}
void land_image_debug_pixelmask(LandImage * self, float x, float y, float angle, bool flipped) {
    int i;
    int k = mask_get_rotation_frame(self->mask, angle, flipped);
    int mask_w = self->mask->rotation [k]->w;
    int w = land_image_width(self) - self->l - self->r;
    int h = land_image_height(self) - self->t - self->b;
    float ml, mt, mr, mb;
    get_bounding_box(self->l - self->x, self->t - self->y, w - self->x + self->l, h - self->y + self->t, k * 2.0 * LAND_PI / self->mask->n, & ml, & mt, & mr, & mb);
    land_color(1, 0, 0, 1);
    land_rectangle(x + ml, y + mt, x + mr, y + mb);
    land_color(0, 1, 0, 1);
    for (i = 0; i < self->mask->rotation [k]->h; i++) {
        int j;
        for (j = 0; j < mask_w; j++) {
            int m = self->mask->rotation [k]->data [mask_w * i + j];
            int b;
            for (b = 0; b < 32; b++) {
                if (m & (1 << b)) {
                    land_plot(x + ml + j * 32 + b, y + mt + i);
                }
            }
        }
    }
}
static int pixelmask_part_collision(SinglePixelMask * mask, int x, int y, SinglePixelMask * mask_, int x_, int y_, int w, int h) {
    int mask_w = mask->w;
    int mask_w_ = mask_->w;
    unsigned int * li = mask->data + mask_w * y;
    unsigned int * li_ = mask_->data + mask_w_ * y_;
    unsigned int bit = x & 31;
    unsigned int bit_ = x_ & 31;
    int j;
    for (j = 0; j < h; j++) {
        int lw;
        int i = x >> 5;
        int i_ = x_ >> 5;
        for (lw = w; lw > 0; lw -= 32) {
            unsigned int m, m_;
            if (bit == 0) {
                m = li [i];
            }
            else {
                m = (li [i] >> bit) + (li [i + 1] << (32 - bit));
            }
            if (bit_ == 0) {
                m_ = li_ [i_];
            }
            else {
                m_ = (li_ [i_] >> bit_) + (li_ [i_ + 1] << (32 - bit_));
            }
            if (m & m_) {
                return 1;
            }
            i++;
            i_++;
        }
        li += mask_w;
        li_ += mask_w_;
    }
    return 0;
}
static int pixelmask_collision(SinglePixelMask * mask, int x, int y, int w, int h, SinglePixelMask * mask_, int x_, int y_, int w_, int h_) {
    if (x >= x_ + w_ || x_ >= x + w || y >= y_ + h_ || y_ >= y + h) {
        return 0;
    }
    if (x <= x_) {
        if (y <= y_) {
            return pixelmask_part_collision(mask, x_ - x, y_ - y, mask_, 0, 0, _scramble_min(x + w - x_, w_), _scramble_min(y + h - y_, h_));
        }
        else {
            return pixelmask_part_collision(mask, x_ - x, 0, mask_, 0, y - y_, _scramble_min(x + w - x_, w_), _scramble_min(y_ + h_ - y, h));
        }
    }
    else {
        if (y <= y_) {
            return pixelmask_part_collision(mask, 0, y_ - y, mask_, x - x_, 0, _scramble_min(x_ + w_ - x, w), _scramble_min(y + h - y_, h_));
        }
        else {
            return pixelmask_part_collision(mask, 0, 0, mask_, x - x_, y - y_, _scramble_min(x_ + w_ - x, w), _scramble_min(y_ + h_ - y, h));
        }
    }
}
void land_image_create_pixelmasks(LandImage * self, int n, int threshold) {
    self->mask = pixelmask_create(self, n, threshold);
}
void land_image_destroy_pixelmasks(LandImage * self) {
    if (self->mask) {
        pixelmask_destroy(self->mask);
    }
}
int land_image_overlaps(LandImage * self, float x, float y, float angle, float flipped, LandImage * other, float x_, float y_, float angle_, float flipped_) {
    if (! self->mask) {
        return 0;
    }
    if (! other->mask) {
        return 0;
    }
    int w = self->mask->w;
    int h = self->mask->h;
    int w_ = other->mask->w;
    int h_ = other->mask->h;
    int i = mask_get_rotation_frame(self->mask, angle, flipped);
    int i_ = mask_get_rotation_frame(other->mask, angle_, flipped_);
    int mx = self->mask->x - self->x;
    int my = self->mask->y - self->y;
    int mx_ = other->mask->x - other->x;
    int my_ = other->mask->y - other->y;
    float ml, mt, mr, mb, ml_, mt_, mr_, mb_;
    get_bounding_box(mx, my, mx + w, my + h, i * 2.0 * LAND_PI / self->mask->n, & ml, & mt, & mr, & mb);
    get_bounding_box(mx_, my_, mx_ + w_, my_ + h_, i_ * 2.0 * LAND_PI / other->mask->n, & ml_, & mt_, & mr_, & mb_);
    return pixelmask_collision(self->mask->rotation [i], x + ml, y + mt, mr - ml, mb - mt, other->mask->rotation [i_], x_ + ml_, y_ + mt_, mr_ - ml_, mb_ - mt_);
}
#undef BB
LandWidgetInterface * land_widget_box_interface;
void land_widget_box_draw(LandWidget * self) {
    land_widget_theme_draw(self);
}
LandWidget* land_widget_box_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidget * self = land_widget_base_new(parent, x, y, w, h);
    land_widget_box_interface_initialize();
    self->vt = land_widget_box_interface;
    land_widget_theme_initialize(self);
    land_call_method(parent, update, (parent));
    return self;
}
void land_widget_box_interface_initialize(void) {
    if (land_widget_box_interface) {
        return ;
    }
    land_widget_box_interface = land_widget_copy_interface(land_widget_base_interface, "box");
    land_widget_box_interface->id = LAND_WIDGET_ID_BASE;
    land_widget_box_interface->draw = land_widget_box_draw;
}
#ifndef LAND_NO_COMPRESS
#endif
#ifdef LAND_MEMLOG
#undef land_buffer_new
#undef land_buffer_destroy
#undef land_buffer_finish
#undef land_buffer_read_from_file
#undef land_buffer_split
LandBuffer* land_buffer_new_memlog(char const * f, int l) {
    LandBuffer * self = land_buffer_new();
    land_memory_add(self, "buffer", 1, f, l);
    return self;
}
void land_buffer_destroy_memlog(LandBuffer * self, char const * f, int l) {
    land_memory_remove(self, "buffer", 1, f, l);
    land_buffer_destroy(self);
}
char* land_buffer_finish_memlog(LandBuffer * self, char const * f, int l) {
    land_memory_remove(self, "buffer", 1, f, l);
    char * s = land_buffer_finish(self);
    land_memory_remove(s, "", 1, f, l);
    land_memory_add(s, "", strlen(s), f, l);
    return s;
}
LandBuffer* land_buffer_read_from_file_memlog(char const * filename, char const * f, int l) {
    LandBuffer * self = land_buffer_read_from_file(filename);
    land_memory_add(self, "buffer", 1, f, l);
    return self;
}
LandArray* land_buffer_split_memlog(LandBuffer const * self, char delim, char const * f, int line) {
    LandArray * a = land_array_new_memlog(f, line);
    int start = 0;
    for (int i = 0; i < self->n; i++) {
        if (self->buffer [i] == delim) {
            LandBuffer * l = land_buffer_new_memlog(f, line);
            land_buffer_add(l, self->buffer + start, i - start);
            land_array_add_memlog(a, l, f, line);
            start = i + 1;
        }
    }
    LandBuffer * l = land_buffer_new_memlog(f, line);
    land_buffer_add(l, self->buffer + start, self->n - start);
    land_array_add_memlog(a, l, f, line);
    return a;
}
#endif
LandBuffer* land_buffer_new(void) {
    LandBuffer * self;
    land_alloc(self);
    return self;
}
LandBuffer* land_buffer_copy(LandBuffer * other) {
    LandBuffer * self;
    land_alloc(self);
    land_buffer_add(self, other->buffer, other->n);
    return self;
}
LandBuffer* land_buffer_extract(LandBuffer * other, int x, int n) {
    LandBuffer * self = land_buffer_new();
    if (n > 0) {
        land_buffer_add(self, other->buffer + x, n);
    }
    return self;
}
LandBuffer* land_buffer_copy_from(LandBuffer * other, int x) {
    LandBuffer * self = land_buffer_new();
    land_buffer_add(self, other->buffer + x, other->n - x);
    return self;
}
void land_buffer_destroy(LandBuffer * self) {
    if (self->buffer) {
        land_free(self->buffer);
    }
    land_free(self);
}
void land_buffer_insert(LandBuffer * self, int pos, char const * buffer, int n) {
    self->n += n;
    if (self->n > self->size) {
        if (! self->size) {
            self->size = 1;
        }
        while (self->size < self->n) {
            self->size *= 2;
        }
        self->buffer = land_realloc(self->buffer, self->size);
    }
    memmove(self->buffer + pos + n, self->buffer + pos, self->n - n - pos);
    memcpy(self->buffer + pos, buffer, n);
}
void land_buffer_cut(LandBuffer * self, int pos, int n) {
    memmove(self->buffer + pos, self->buffer + pos + n, self->n - pos - n);
    self->n -= n;
}
void land_buffer_shorten_left(LandBuffer * self, int n) {
    land_buffer_cut(self, 0, n);
}
void land_buffer_add(LandBuffer * self, char const * b, int n) {
    land_buffer_insert(self, self->n, b, n);
}
void land_buffer_addv(LandBuffer * self, char const * format, va_list args) {
    va_list args2;
    va_copy(args2, args);
    int n = vsnprintf(NULL, 0, format, args2);
    va_end(args2);
    if (n < 0) {
        n = 1023;
    }
    char s [n + 1];
    vsnprintf(s, n + 1, format, args);
    land_buffer_add(self, s, n);
}
void land_buffer_addf(LandBuffer * self, char const * format, ...) {
    va_list args;
    va_start(args, format);
    land_buffer_addv(self, format, args);
    va_end(args);
}
void land_buffer_addl(LandBuffer * self, char const * format, ...) {
    va_list args;
    va_start(args, format);
    land_buffer_addv(self, format, args);
    va_end(args);
    land_buffer_add_char(self, '\n');
}
void land_buffer_add_uint32_t(LandBuffer * self, uint32_t i) {
    land_buffer_add_char(self, i & 255);
    land_buffer_add_char(self, (i >> 8) & 255);
    land_buffer_add_char(self, (i >> 16) & 255);
    land_buffer_add_char(self, (i >> 24) & 255);
}
uint32_t land_buffer_get_uint32_t(LandBuffer * self, int pos) {
    uint8_t * uc = (uint8_t *) self->buffer + pos;
    uint32_t u = * (uc++);
    u += * (uc++) << 8;
    u += * (uc++) << 16;
    u += * (uc++) << 24;
    return u;
}
uint16_t land_buffer_get_uint16_t(LandBuffer * self, int pos) {
    uint8_t * uc = (uint8_t *) self->buffer + pos;
    uint16_t u = * (uc++);
    u += * (uc++) << 8;
    return u;
}
uint8_t land_buffer_get_byte(LandBuffer * self, int pos) {
    uint8_t * uc = (uint8_t *) self->buffer + pos;
    return * uc;
}
void land_buffer_add_float(LandBuffer * self, float f) {
    uint32_t * i = (void *) & f;
    land_buffer_add_uint32_t(self, * i);
}
void land_buffer_add_char(LandBuffer * self, char c) {
    land_buffer_add(self, & c, 1);
}
void land_buffer_cat(LandBuffer * self, char const * string) {
    /* Appends a zero-terminated string (without the 0 byte) to the buffer.
     */
    land_buffer_add(self, string, strlen(string));
}
void land_buffer_clear(LandBuffer * self) {
    /* Clears the buffer (but keeps any memory allocation for speedy refilling).
     */
    self->n = 0;
}
void land_buffer_crop(LandBuffer * self) {
    /* Make the buffer use up only the minimum required amount of memory.
     */
    self->buffer = land_realloc(self->buffer, self->n);
    self->size = self->n;
}
char* land_buffer_finish(LandBuffer * self) {
    /* Destroys the buffer, but returns a C-string constructed from it by appending
     * a 0 character. You may not access the pointer you pass to this function
     * anymore after it returns. Also, you have to make sure it does not already
     * contain any 0 characters. When no longer needed, you should free the string
     * with land_free.
     */
    char c [] = "";
    land_buffer_add(self, c, 1);
    char * s = self->buffer;
    self->buffer = NULL;
    land_buffer_destroy(self);
    return s;
}
void land_buffer_println(LandBuffer * self) {
    printf("%.*s\n", self->n, self->buffer);
}
LandArray* land_buffer_split(LandBuffer const * self, char delim) {
    /* Creates an array of buffers. If there are n occurences of character delim
     * in the buffer, the array contains n + 1 entries. No buffer in the array
     * contains the delim character.
     */
    LandArray * a = land_array_new();
    int start = 0;
    for (int i = 0; i < self->n; i++) {
        if (self->buffer [i] == delim) {
            LandBuffer * l = land_buffer_new();
            land_buffer_add(l, self->buffer + start, i - start);
            land_array_add(a, l);
            start = i + 1;
        }
    }
    LandBuffer * l = land_buffer_new();
    land_buffer_add(l, self->buffer + start, self->n - start);
    land_array_add(a, l);
    return a;
}
void land_buffer_strip_right(LandBuffer * self, char const * what) {
    if (self->n == 0) {
        return ;
    }
    int away = 0;
    char * p = self->buffer + self->n;
    while (p > self->buffer) {
        int c = land_utf8_char_back(& p);
        char const * q = what;
        while (1) {
            int d = land_utf8_char_const(& q);
            if (! d) {
                goto done;
            }
            if (c == d) {
                away++;
                break;
            }
        }
    }
    done:;
    self->n -= away;
}
void land_buffer_strip_left(LandBuffer * self, char const * what) {
    if (self->n == 0) {
        return ;
    }
    int away = 0;
    char * p = self->buffer;
    while (1) {
        again:;
        int c = land_utf8_char(& p);
        if (! c) {
            break;
        }
        char const * q = what;
        while (1) {
            int d = land_utf8_char_const(& q);
            if (! d) {
                break;
            }
            if (c == d) {
                away++;
                goto again;
            }
        }
        break;
    }
    self->n -= away;
    memmove(self->buffer, self->buffer + away, self->n);
}
void land_buffer_strip(LandBuffer * self, char const * what) {
    land_buffer_strip_right(self, what);
    land_buffer_strip_left(self, what);
}
bool land_buffer_is(LandBuffer * self, char const * what) {
    int n = strlen(what);
    if (n != self->n) {
        return 0;
    }
    return memcmp(self->buffer, what, self->n) == 0;
}
void land_buffer_remove_if_start(LandBuffer * self, char const * what) {
    if (memcmp(self->buffer, what, strlen(what)) == 0) {
        land_buffer_shorten_left(self, strlen(what));
    }
}
void land_buffer_remove_if_end(LandBuffer * self, char const * what) {
    if (memcmp(self->buffer + self->n - strlen(what), what, strlen(what)) == 0) {
        land_buffer_shorten(self, strlen(what));
    }
}
int land_buffer_rfind(LandBuffer * self, char c) {
    if (self->n == 0) {
        return - 1;
    }
    for (int i = self->n - 1; i >= 0; i--) {
        if (self->buffer [i] == c) {
            return i;
        }
    }
    return - 1;
}
int land_buffer_find(LandBuffer const * self, int offset, char const * what) {
    int n = strlen(what);
    for (int i = offset; i < self->n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (self->buffer [i + j] != what [j]) {
                goto mismatch;
            }
        }
        return i;
        mismatch:;
    }
    return - 1;
}
int land_buffer_replace(LandBuffer * self, int offset, char const * wat, char const * wit) {
    int x = land_buffer_find(self, offset, wat);
    if (x < 0) {
        return x;
    }
    land_buffer_cut(self, x, strlen(wat));
    land_buffer_insert(self, x, wit, strlen(wit));
    return x + strlen(wit);
}
int land_buffer_replace_all(LandBuffer * self, char const * wat, char const * wit) {
    int x = 0;
    int count = 0;
    while (1) {
        x = land_buffer_replace(self, x, wat, wit);
        if (x < 0) {
            break;
        }
        count++;
    }
    return count;
}
void land_buffer_set_length(LandBuffer * self, int n) {
    self->n = n;
}
void land_buffer_shorten(LandBuffer * self, int n) {
    self->n -= n;
}
LandBuffer* land_buffer_read_from_file(char const * filename) {
    /* Read a buffer from the given file. If the file cannot be read, return None.
     */
    LandFile * pf = land_file_new(filename, "r");
    if (! pf) {
        return NULL;
    }
    LandBuffer * self = land_buffer_new();
    while (1) {
        char kb [16384];
        size_t n = land_file_read(pf, kb, 16384);
        land_buffer_add(self, kb, n);
        if (n < 16384) {
            break;
        }
    }
    land_file_destroy(pf);
    return self;
}
bool land_buffer_write_to_file(LandBuffer * self, char const * filename) {
    LandFile * pf = land_file_new(filename, "w");
    if (! pf) {
        return 0;
    }
    int written = land_file_write(pf, self->buffer, self->n);
    land_file_destroy(pf);
    return written == self->n;
}
#ifndef LAND_NO_COMPRESS
void land_buffer_compress(LandBuffer * self) {
    uLongf destlen = self->n * 1.1 + 12;
    Bytef * dest = land_malloc(destlen);
    compress(dest, & destlen, (void *) self->buffer, self->n);
    dest = land_realloc(dest, destlen);
    land_free(self->buffer);
    self->buffer = (void *) dest;
    self->size = self->n = destlen;
}
void land_buffer_decompress(LandBuffer * self) {
    z_stream z;
    z.zalloc = Z_NULL;
    z.zfree = Z_NULL;
    z.opaque = Z_NULL;
    z.next_in = (void *) self->buffer;
    z.avail_in = self->n;
    int err = inflateInit2(& z, 15 | 32);
    if (err != Z_OK) {
        return ;
    }
    LandBuffer * temp = land_buffer_new();
    char * out = malloc(8192);
    while (1) {
        z.avail_out = 8192;
        z.next_out = (void *) out;
        err = inflate(& z, Z_NO_FLUSH);
        if (err < 0) {
            goto break2;
        }
        land_buffer_add(temp, out, 8192 - z.avail_out);
        if (z.avail_out > 0) {
            break;
        }
    }
    break2:;
    land_free(out);
    land_free(self->buffer);
    self->buffer = temp->buffer;
    self->n = temp->n;
    temp->buffer = NULL;
    land_buffer_destroy(temp);
}
#endif
int land_buffer_compare(LandBuffer * self, LandBuffer * other) {
    if (self->n < other->n) {
        return - 1;
    }
    if (self->n > other->n) {
        return 1;
    }
    return memcmp(self->buffer, other->buffer, self->n);
}
static LandDisplay * global_previous_display;
static LandDisplayPlatform global_image_display;
static ALLEGRO_BITMAP * previous;
#define SELF LandImagePlatform * self = (void *) super
LandImage* platform_new_image(void) {
    LandImagePlatform * self;
    land_alloc(self);
    return (void *) self;
}
void platform_del_image(LandImage * super) {
    SELF;
    if (self->a5) {
        al_destroy_bitmap(self->a5);
    }
    land_free(self);
}
void platform_image_empty(LandImage * super) {
    SELF;
    if (! self->a5) {
        self->a5 = al_create_bitmap(super->width, super->height);
    }
    int f = al_get_bitmap_format(self->a5);
    ALLEGRO_LOCKED_REGION * lock = al_lock_bitmap(self->a5, f, ALLEGRO_LOCK_WRITEONLY);
    int rowbytes = al_get_pixel_size(f) * super->width;
    for (int i = 0; i < super->height; i++) {
        memset(lock->data + lock->pitch * i, 0, rowbytes);
    }
    al_unlock_bitmap(self->a5);
}
LandImage* platform_image_load(char const * filename, bool mem) {
    LandImage * super = land_display_new_image();
    super->filename = land_strdup(filename);
    if (mem) {
        super->flags |= LAND_IMAGE_MEMORY;
    }
    _platform_load(super);
    return super;
}
static void _platform_load(LandImage * super) {
    super->name = land_strdup(super->filename);
    ALLEGRO_STATE state;
    if (super->flags & LAND_IMAGE_MEMORY) {
        al_store_state(& state, ALLEGRO_STATE_NEW_BITMAP_PARAMETERS);
        al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
    }
    #ifdef ANDROID
    land_log_message("open %s", super->filename);
    #endif
    ALLEGRO_BITMAP * bmp;
    if (strchr(super->filename, '.')) {
        bmp = al_load_bitmap(super->filename);
    }
    else {
        bmp = al_load_bitmap(super->filename);
    }
    if (bmp) {
        LandImagePlatform * self = (void *) super;
        self->a5 = bmp;
        super->width = al_get_bitmap_width(bmp);
        super->height = al_get_bitmap_height(bmp);
        super->flags |= LAND_LOADED;
    }
    else {
        super->flags |= LAND_FAILED;
    }
    if (super->flags & LAND_IMAGE_MEMORY) {
        al_restore_state(& state);
        super->flags |= LAND_FAILED;
    }
}
void platform_image_load_on_demand(LandImage * super) {
    LandImagePlatform * self = (void *) super;
    if (self->a5) {
        return ;
    }
    _platform_load(super);
}
LandImage* platform_image_sub(LandImage * parent, float x, float y, float w, float h) {
    LandImage * super = land_display_new_image();
    super->flags |= LAND_SUBIMAGE;
    super->filename = parent->filename;
    super->name = parent->name;
    LandImagePlatform * self = (void *) super;
    LandImagePlatform * parentself = (void *) parent;
    self->a5 = al_create_sub_bitmap(parentself->a5, x, y, w, h);
    super->width = al_get_bitmap_width(self->a5);
    super->height = al_get_bitmap_height(self->a5);
    return super;
}
void platform_image_save(LandImage * super, char const * filename) {
    LandImagePlatform * self = (void *) super;
    al_save_bitmap(filename, self->a5);
}
void platform_image_prepare(LandImage * super) {
    land_log_message("platform_image_prepare\n");
}
void platform_image_draw_scaled_rotated_tinted_flipped(LandImage * super, float x, float y, float sx, float sy, float angle, float r, float g, float b, float alpha, int flip) {
    SELF;
    LandDisplay * d = _land_active_display;
    ALLEGRO_STATE state;
    land_a5_display_check_transform();
    bool restore = 0;
    if (d->blend) {
        if (d->blend & LAND_BLEND_SOLID) {
            al_store_state(& state, ALLEGRO_STATE_BLENDER);
            al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
            restore = 1;
        }
        if (d->blend & LAND_BLEND_ADD) {
            al_store_state(& state, ALLEGRO_STATE_BLENDER);
            al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_ONE);
            restore = 1;
        }
    }
    int flags = 0;
    if (flip == 1 || flip == 3) {
        flags |= ALLEGRO_FLIP_HORIZONTAL;
    }
    if (flip == 2 || flip == 3) {
        flags |= ALLEGRO_FLIP_VERTICAL;
    }
    ALLEGRO_COLOR tint = al_map_rgba_f(r, g, b, alpha);
    al_draw_tinted_scaled_rotated_bitmap_region(self->a5, super->l, super->t, super->width - super->l - super->r, super->height - super->t - super->b, tint, super->x - super->l, super->y - super->t, x, y, sx, sy, - angle, flags);
    if (restore) {
        al_restore_state(& state);
    }
}
void platform_set_image_display(LandImage * super) {
    SELF;
    global_previous_display = _land_active_display;
    LandDisplayPlatform * prev = (void *) global_previous_display;
    LandDisplay * d = (void *) & global_image_display;
    _land_active_display = d;
    global_image_display.a5 = prev->a5;
    global_image_display.c = al_map_rgb_f(1, 1, 1);
    d->w = super->width;
    d->h = super->height;
    d->flags = 0;
    d->color_r = 1;
    d->color_g = 1;
    d->color_b = 1;
    d->color_a = 1;
    d->blend = 0;
    d->clip_off = 0;
    d->clip_x1 = 0;
    d->clip_y1 = 0;
    d->clip_x2 = super->width;
    d->clip_y2 = super->height;
    previous = al_get_target_bitmap();
    al_set_target_bitmap(self->a5);
}
void platform_unset_image_display(void) {
    _land_active_display = global_previous_display;
    al_set_target_bitmap(previous);
}
void platform_image_grab_into(LandImage * super, float x, float y, float tx, float ty, float tw, float th) {
    SELF;
    ALLEGRO_STATE state;
    al_store_state(& state, ALLEGRO_STATE_TARGET_BITMAP);
    ALLEGRO_BITMAP * from = al_get_target_bitmap();
    al_set_target_bitmap(self->a5);
    al_draw_bitmap_region(from, x, y, tw, th, tx, ty, 0);
    al_restore_state(& state);
}
void platform_image_get_rgba_data(LandImage * super, unsigned char * rgba) {
    SELF;
    int w = super->width;
    int h = super->height;
    unsigned char * p = rgba;
    ALLEGRO_LOCKED_REGION * lock;
    lock = al_lock_bitmap(self->a5, ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE, ALLEGRO_LOCK_READONLY);
    unsigned char * p2 = lock->data;
    for (int y = 0; y < h; y++) {
        unsigned char * p3 = p2;
        for (int x = 0; x < w; x++) {
            unsigned char r, g, b, a;
            r = * (p3++);
            g = * (p3++);
            b = * (p3++);
            a = * (p3++);
            * (p++) = r;
            * (p++) = g;
            * (p++) = b;
            * (p++) = a;
        }
        p2 += lock->pitch;
    }
    al_unlock_bitmap(self->a5);
}
void platform_image_set_rgba_data(LandImage * super, unsigned char const * rgba) {
    SELF;
    int w = super->width;
    int h = super->height;
    unsigned char const * p = rgba;
    ALLEGRO_LOCKED_REGION * lock;
    lock = al_lock_bitmap(self->a5, ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE, ALLEGRO_LOCK_WRITEONLY);
    unsigned char * p2 = lock->data;
    for (int y = 0; y < h; y++) {
        unsigned char * p3 = p2;
        for (int x = 0; x < w; x++) {
            int r, g, b, a;
            r = * (p++);
            g = * (p++);
            b = * (p++);
            a = * (p++);
            * (p3++) = r;
            * (p3++) = g;
            * (p3++) = b;
            * (p3++) = a;
        }
        p2 += lock->pitch;
    }
    al_unlock_bitmap(self->a5);
}
int platform_image_opengl_texture(LandImage * super) {
    SELF;
    return al_get_opengl_texture(self->a5);
}
void platform_image_crop(LandImage * super, int x, int y, int w, int h) {
    SELF;
    ALLEGRO_STATE state;
    if (x == 0 && y == 0 && w == super->width && h == super->height) {
        return ;
    }
    al_store_state(& state, ALLEGRO_STATE_TARGET_BITMAP | ALLEGRO_STATE_BLENDER);
    ALLEGRO_BITMAP * cropped = al_create_bitmap(w, h);
    al_set_target_bitmap(cropped);
    al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
    if (self->a5) {
        al_draw_bitmap(self->a5, - x, - y, 0);
        al_destroy_bitmap(self->a5);
    }
    self->a5 = cropped;
    al_restore_state(& state);
    super->width = w;
    super->height = h;
}
#undef SELF
LandCSGAABB land_csg_aabb_infinite(void) {
    LandCSGAABB a;
    a.x1 = - INFINITY;
    a.x2 = + INFINITY;
    a.y1 = - INFINITY;
    a.y2 = + INFINITY;
    a.z1 = - INFINITY;
    a.z2 = + INFINITY;
    return a;
}
LandCSGAABB land_csg_aabb_empty(void) {
    LandCSGAABB a;
    a.x1 = + INFINITY;
    a.x2 = - INFINITY;
    a.y1 = + INFINITY;
    a.y2 = - INFINITY;
    a.z1 = + INFINITY;
    a.z2 = - INFINITY;
    return a;
}
void land_csg_aabb_update(LandCSGAABB * self, LandArray * polygons) {
    * self = land_csg_aabb_empty();
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(polygons, &__iter0__); LandArrayIterator_next(polygons, &__iter0__); p = LandArrayIterator_item(polygons, &__iter0__)) {
            {
                LandArrayIterator __iter1__ = LandArrayIterator_first(p->vertices);
                for (LandCSGVertex * v = LandArrayIterator_item(p->vertices, &__iter1__); LandArrayIterator_next(p->vertices, &__iter1__); v = LandArrayIterator_item(p->vertices, &__iter1__)) {
                    if (v->pos.x < self->x1) {
                        self->x1 = v->pos.x;
                    }
                    if (v->pos.x > self->x2) {
                        self->x2 = v->pos.x;
                    }
                    if (v->pos.y < self->y1) {
                        self->y1 = v->pos.y;
                    }
                    if (v->pos.y > self->y2) {
                        self->y2 = v->pos.y;
                    }
                    if (v->pos.z < self->z1) {
                        self->z1 = v->pos.z;
                    }
                    if (v->pos.z > self->z2) {
                        self->z2 = v->pos.z;
                    }
                }
            }
        }
    }
}
LandCSGAABB land_csg_aabb_intersect(LandCSGAABB a, LandCSGAABB b) {
    LandCSGAABB c = a;
    if (b.x1 > c.x1) {
        c.x1 = b.x1;
    }
    if (b.x2 < c.x2) {
        c.x2 = b.x2;
    }
    if (b.y1 > c.y1) {
        c.y1 = b.y1;
    }
    if (b.y2 < c.y2) {
        c.y2 = b.y2;
    }
    if (b.z1 > c.z1) {
        c.z1 = b.z1;
    }
    if (b.z2 < c.z2) {
        c.z2 = b.z2;
    }
    return c;
}
LandProtobuf* land_protobuf_load(char const * filename) {
    LandBuffer * b = land_buffer_read_from_file(filename);
    if (! b) {
        return NULL;
    }
    LandProtobuf * pbuf;
    land_alloc(pbuf);
    pbuf->data = b;
    pbuf->end = b->n;
    return pbuf;
}
static uint64_t varint(LandProtobuf * self) {
    uint64_t x = 0;
    int s = 0;
    while (1) {
        uint8_t c = self->data->buffer [self->pos++];
        x += (c & 127) << s;
        s += 7;
        if (c & 128) {
            continue;
        }
        return x;
    }
}
int land_protobuf_next(LandProtobuf * self, uint64_t * size) {
    if (self->pos >= self->end) {
        return 0;
    }
    int x = varint(self);
    int kind = x & 3;
    if (kind == 2) {
        * size = varint(self);
    }
    return x >> 3;
}
void land_protobuf_sub_start(LandProtobuf * self, uint64_t * size) {
    uint64_t end = self->end;
    self->end = self->pos + * size;
    * size = end;
}
void land_protobuf_sub_end(LandProtobuf * self, uint64_t end) {
    self->pos = self->end;
    self->end = end;
}
#define R(T) \
    T x = * (T *)(self->data->buffer + self->pos); \
    self->pos += sizeof (T); \
    return x;
double land_protobuf_double(LandProtobuf * self) {
    double x;
    void * p = & x;
    memcpy(p, self->data->buffer + self->pos, 8);
    self->pos += 8;
    return x;
}
float land_protobuf_float(LandProtobuf * self) {
    float x;
    void * p = & x;
    memcpy(p, self->data->buffer + self->pos, 4);
    self->pos += 4;
    return x;
}
uint32_t land_protobuf_fixed32(LandProtobuf * self) {
    R(uint32_t);
}
int32_t land_protobuf_sfixed32(LandProtobuf * self) {
    R(int32_t);
}
char* land_protobuf_string(LandProtobuf * self, int size) {
    self->pos += size;
    return self->data->buffer + self->pos - size;
}
void land_protobuf_destroy(LandProtobuf * self) {
    land_buffer_del(self->data);
    land_free(self);
}
#undef R
static bool land_active;
bool _land_quit;
static LandParameters * parameters;
bool _land_halted;
bool _land_was_halted;
static bool x_clicked;
int _land_frames;
bool _land_synchronized;
static bool _maximize_fps;
static void land_exit(void) {
    if (! land_active) {
        return ;
    }
    land_active = 0;
    land_free(parameters);
    land_log_message("land_exit\n");
}
void land_halt(void) {
    platform_halt();
    _land_halted = 1;
}
void land_resume(void) {
    platform_resume();
    _land_halted = 0;
}
bool land_was_halted(void) {
    return _land_halted;
}
void land_init(void) {
    /* """Initialize Land. This must be called before anything else."""
     */
    if (land_active) {
        return ;
    }
    land_active = 1;
    land_log_message("land_init\n");
    land_alloc(parameters);
    parameters->w = 640;
    parameters->h = 480;
    parameters->fps = 60;
    atexit(land_exit);
    if (! land_exception_handler) {
        land_exception_handler_set(land_default_exception_handler);
    }
    int seed = time(NULL);
    land_seed(seed);
    land_log_message("Random seed is %d.\n", seed);
    char cd [1024];
    if (! getcwd(cd, sizeof cd)) {
        sprintf(cd, "<none>");
    }
    land_log_message("Current path: %s\n", cd);
    platform_init();
}
void land_tick(void) {
    land_display_tick();
    land_runner_tick_active();
    land_mouse_tick();
    land_keyboard_tick();
    x_clicked = 0;
    _land_was_halted = _land_halted;
}
void land_draw(void) {
    land_runner_draw_active();
    land_flip();
}
void land_quit(void) {
    /* Quit the Land application. Call it when you want the program to
     * exit.
     */
    _land_quit = 1;
}
void land_closebutton_event(void) {
    x_clicked = 1;
}
int land_closebutton(void) {
    /* """Check if the closebutton has been clicked.
     * * Returns: True if yes, else False.
     */
    return x_clicked;
}
void land_set_fps(int f) {
    /* """Set the frequency in Hz at which Land should tick. Default is 60."""
     */
    land_log_message("land_set_frequency %d\n", f);
    parameters->fps = f;
}
void land_set_display_parameters(int w, int h, int flags) {
    /* """Set the display parameters to use initially.
     * * w, h Width and height in pixel.
     * * flags, a combination of:
     * ** LAND_WINDOWED
     * ** LAND_FULLSCREEN
     * ** LAND_OPENGL
     * ** LAND_CLOSE_LINES
     */
    parameters->w = w;
    parameters->h = h;
    parameters->flags = flags;
}
void land_set_initial_runner(LandRunner * runner) {
    /* """Set the initial runner."""
     */
    parameters->start = runner;
}
double land_get_fps(void) {
    /* """Return the current frequency."""
     */
    return parameters->fps;
}
int land_get_ticks(void) {
    /* """Return the number of ticks Land has executed."""
     */
    return _land_frames;
}
double land_get_time(void) {
    /* """Get the time in seconds since Land has started."""
     */
    return platform_get_time();
}
void land_pause(void) {
    /* """Stop time. The tick function of the current runner will not be
     * called any longer and [land_get_ticks] will not advance until the
     * next call to [land_unpause].
     */
    platform_pause();
}
void land_unpause(void) {
    platform_unpause();
}
int land_get_flags(void) {
    return parameters->flags;
}
void land_set_synchronized(bool onoff) {
    _land_synchronized = onoff;
}
void land_maximize_fps(bool onoff) {
    _maximize_fps = onoff;
}
void land_mainloop(void) {
    /* """Run Land. This function will use all the parameters set before to
     * initialize everything, then run the initial runner. It will return when
     * you call land_quit() inside the tick function of the active runner.
     */
    land_log_message("land_mainloop\n");
    land_exit_function(land_exit);
    land_display_init();
    land_font_init();
    land_image_init();
    land_grid_init();
    LandDisplay * display = land_display_new(parameters->w, parameters->h, parameters->flags);
    land_log_message("About to create the main window.\n");
    land_display_set();
    land_log_message("Video initialized.\n");
    land_sound_init();
    land_log_message("Audio initialized.\n");
    land_mouse_init();
    land_log_message("Mouse initialized.\n");
    land_keyboard_init();
    land_log_message("Keyboard initialized.\n");
    land_runner_switch_active(parameters->start);
    land_log_message("Commencing operations.\n");
    platform_mainloop(parameters);
    land_runner_switch_active(NULL);
    land_runner_destroy_all();
    land_display_destroy(display);
    land_sound_exit();
    land_grid_exit();
    land_font_exit();
    land_image_exit();
    land_display_exit();
    land_exit_functions();
    land_log_message("exit\n");
}
static int gul_debug;
#define D(_) if(gul_debug) _
static void ERR(char const * format, ...) {
    va_list args;
    va_start(args, format);
    char str [1024];
    vsnprintf(str, sizeof str, format, args);
    strcat(str, "\n");
    land_log_message(str);
    va_end(args);
}
void _land_gul_box_initialize(LandLayoutBox * self) {
    memset(self, 0, sizeof (* self));
}
void _land_gul_box_deinitialize(LandLayoutBox * self) {
    if (self->lookup_grid) {
        land_free(self->lookup_grid);
        self->lookup_grid = NULL;
    }
}
static void update_lookup_grid(LandWidget * self) {
    if (self->box.lookup_grid) {
        land_free(self->box.lookup_grid);
    }
    self->box.lookup_grid = NULL;
    if (self->box.flags & (GUL_NO_LAYOUT | GUL_HIDDEN)) {
        return ;
    }
    if (land_widget_is(self, LAND_WIDGET_ID_CONTAINER)) {
        LandWidgetContainer * container = LAND_WIDGET_CONTAINER(self);
        if (! container->children) {
            return ;
        }
        if (self->box.cols * self->box.rows == 0) {
            return ;
        }
        self->box.lookup_grid = land_calloc(self->box.cols * self->box.rows * sizeof (* self->box.lookup_grid));
        LandListItem * li = container->children->first;
        for (; li; li = li->next) {
            LandWidget * c = li->data;
            int i, j;
            if (c->box.flags & GUL_HIDDEN) {
                continue;
            }
            for (i = c->box.col; i <= c->box.col + c->box.extra_cols; i++) {
                for (j = c->box.row; j <= c->box.row + c->box.extra_rows; j++) {
                    self->box.lookup_grid [i + j * self->box.cols] = c;
                }
            }
        }
    }
}
static LandWidget* lookup_box_in_grid(LandWidget * self, int col, int row) {
    if (! self->box.lookup_grid) {
        update_lookup_grid(self);
    }
    if (! self->box.lookup_grid) {
        return NULL;
    }
    assert(col < self->box.cols && row < self->box.rows);
    return self->box.lookup_grid [row * self->box.cols + col];
}
static int row_min_height(LandWidget * self, int row) {
    int i;
    int v = 0;
    for (i = 0; i < self->box.cols; i++) {
        LandWidget * c = lookup_box_in_grid(self, i, row);
        if (c && c->box.current_min_height > v) {
            v = c->box.current_min_height;
        }
    }
    return v;
}
static int column_min_width(LandWidget * self, int col) {
    int i;
    int v = 0;
    for (i = 0; i < self->box.rows; i++) {
        LandWidget * c = lookup_box_in_grid(self, col, i);
        if (c && c->box.current_min_width > v) {
            v = c->box.current_min_width;
        }
    }
    return v;
}
static int is_column_expanding(LandWidget * self, int col) {
    int i;
    for (i = 0; i < self->box.rows; i++) {
        LandWidget * c = lookup_box_in_grid(self, col, i);
        if (c && c->box.col == col && ! (c->box.flags & GUL_SHRINK_X)) {
            return 1;
        }
    }
    return 0;
}
static int is_row_expanding(LandWidget * self, int row) {
    int i;
    for (i = 0; i < self->box.cols; i++) {
        LandWidget * c = lookup_box_in_grid(self, i, row);
        if (c && c->box.row == row && ! (c->box.flags & GUL_SHRINK_Y)) {
            return 1;
        }
    }
    return 0;
}
static int expanding_columns(LandWidget * self) {
    int i;
    int v = 0;
    for (i = 0; i < self->box.cols; i++) {
        if (is_column_expanding(self, i)) {
            v++;
        }
    }
    return v;
}
static int expanding_rows(LandWidget * self) {
    int i;
    int v = 0;
    for (i = 0; i < self->box.rows; i++) {
        if (is_row_expanding(self, i)) {
            v++;
        }
    }
    return v;
}
static int min_height(LandWidget * self) {
    int i;
    int v = 0;
    for (i = 0; i < self->box.rows; i++) {
        v += row_min_height(self, i);
    }
    if (self->element) {
        v += self->element->vgap * (i - 1) + self->element->it + self->element->ib;
    }
    return v;
}
static int min_width(LandWidget * self) {
    int i;
    int v = 0;
    for (i = 0; i < self->box.cols; i++) {
        v += column_min_width(self, i);
    }
    if (self->element) {
        v += self->element->hgap * (i - 1) + self->element->il + self->element->ir;
    }
    return v;
}
static int adjust_resize_width(LandWidget * self, int dx) {
    int i;
    for (i = 0; i < self->box.cols; i++) {
        int j;
        for (j = 0; j < self->box.rows; j++) {
            LandWidget * c = lookup_box_in_grid(self, i, j);
            if (c && c->box.flags & GUL_RESIZE) {
                c->box.current_min_width += dx;
                return 1;
            }
        }
    }
    return 0;
}
static int adjust_resize_height(LandWidget * self, int dx) {
    int j;
    for (j = 0; j < self->box.rows; j++) {
        int i;
        for (i = 0; i < self->box.cols; i++) {
            LandWidget * c = lookup_box_in_grid(self, i, j);
            if (c && c->box.flags & GUL_RESIZE) {
                c->box.current_min_height += dx;
                return 1;
            }
        }
    }
    return 0;
}
static void gul_box_bottom_up(LandWidget * self) {
    if (self->box.flags & GUL_HIDDEN) {
        self->box.current_min_width = 0;
        self->box.current_min_height = 0;
        return ;
    }
    if (! (self->box.flags & GUL_NO_LAYOUT)) {
        if (land_widget_is(self, LAND_WIDGET_ID_CONTAINER)) {
            LandWidgetContainer * container = LAND_WIDGET_CONTAINER(self);
            if (container->children) {
                LandListItem * i = container->children->first;
                for (; i; i = i->next) {
                    LandWidget * c = i->data;
                    gul_box_bottom_up(LAND_WIDGET(c));
                }
                self->box.current_min_width = _scramble_max(self->box.min_width, min_width(self));
                self->box.current_min_height = _scramble_max(self->box.min_height, min_height(self));
                return ;
            }
        }
    }
    self->box.current_min_width = self->box.min_width;
    self->box.current_min_height = self->box.min_height;
}
static void gul_box_top_down(LandWidget * self) {
    /* Recursively fit in all child widgets into the given widget.
     */
    if (self->box.flags & (GUL_HIDDEN | GUL_NO_LAYOUT)) {
        return ;
    }
    D(printf("Box (%s[%p]): %d[%d] x %d[%d] at %d/%d\n", self->vt->name, self, self->box.w, self->box.cols, self->box.h, self->box.rows, self->box.x, self->box.y));
    if (self->box.cols == 0 || self->box.rows == 0) {
        D(printf("    empty.\n"));
        return ;
    }
    int minw = min_width(self);
    int minh = min_height(self);
    if (self->box.max_width && minw > self->box.max_width) {
        if (! adjust_resize_width(self, self->box.max_width - minw)) {
            ERR("Fatal: Minimum width of children (%d) ""exceeds available space (%d).", minw, self->box.max_width);
        }
    }
    if (self->box.max_height && minh > self->box.max_height) {
        if (! adjust_resize_height(self, self->box.max_height - minh)) {
            ERR("Fatal: Minimum height of children (%d) ""exceeds available space (%d).", minh, self->box.max_height);
        }
    }
    LandWidgetThemeElement * element = self->element;
    int available_width = self->box.w - minw;
    int available_height = self->box.h - minh;
    int want_width = expanding_columns(self);
    int want_height = expanding_rows(self);
    D(printf("    Children: %d (%d exp) x %d (%d exp)\n", self->box.cols, want_width, self->box.rows, want_height));
    D(printf("              %d x %d min\n", minw, minh));
    int i, j;
    int x = self->box.x;
    if (self->element) {
        x += element->il;
    }
    int share = 0;
    if (want_width) {
        share = available_width / want_width;
    }
    available_width -= share * want_width;
    D(printf("    Columns:"));
    int hgap = self->element ? element->hgap : 0;
    for (i = 0; i < self->box.cols; i++) {
        int cw = column_min_width(self, i);
        int cx = x;
        if (is_column_expanding(self, i)) {
            cw += share;
            if (available_width) {
                cw += 1;
                available_width -= 1;
            }
            D(printf(" <->%d", cw));
        }
        else {
            D(printf(" [-]%d", cw));
        }
        x += cw + hgap;
        for (j = 0; j < self->box.rows; j++) {
            LandWidget * c = lookup_box_in_grid(self, i, j);
            if (c && c->box.row == j) {
                if (c->box.col == i) {
                    c->box.w = cw;
                    land_widget_move(c, cx - c->box.x, 0);
                }
                else {
                    c->box.w += cw + hgap;
                }
            }
        }
    }
    D(printf("\n"));
    D(printf("    Rows:"));
    int y = self->box.y;
    if (self->element) {
        y += element->it;
    }
    share = 0;
    if (want_height) {
        share = available_height / want_height;
    }
    available_height -= share * want_height;
    int vgap = self->element ? element->vgap : 0;
    for (j = 0; j < self->box.rows; j++) {
        int ch = row_min_height(self, j);
        int cy = y;
        if ((is_row_expanding(self, j))) {
            ch += share;
            if (available_height) {
                ch += 1;
                available_height -= 1;
            }
            D(printf(" <->%d", ch));
        }
        else {
            D(printf(" [-]%d", ch));
        }
        y += ch;
        y += vgap;
        for (i = 0; i < self->box.cols; i++) {
            LandWidget * c = lookup_box_in_grid(self, i, j);
            if (c && c->box.col == i) {
                if (c->box.row == j) {
                    c->box.h = ch;
                    land_widget_move(c, 0, cy - c->box.y);
                }
                else {
                    c->box.h += ch + vgap;
                }
            }
        }
    }
    D(printf("\n"));
    if (land_widget_is(self, LAND_WIDGET_ID_CONTAINER)) {
        LandWidgetContainer * container = LAND_WIDGET_CONTAINER(self);
        if (container->children) {
            LandListItem * li = container->children->first;
            for (; li; li = li->next) {
                LandWidget * c = li->data;
                if (c->box.w != c->box.ow || c->box.h != c->box.oh) {
                    land_call_method(c, layout_changing, (c));
                }
                gul_box_top_down(c);
                if (c->box.w != c->box.ow || c->box.h != c->box.oh) {
                    land_call_method(c, layout_changed, (c));
                    c->box.ow = c->box.w;
                    c->box.oh = c->box.h;
                }
                if (c->layout_hack) {
                    c->layout_hack = 0;
                    gul_box_top_down(c);
                }
            }
        }
    }
}
static void gul_box_fit_children(LandWidget * self) {
    D(printf("gul_box_fit_children %s[%p]\n", self->vt->name, self));
    gul_box_bottom_up(self);
    self->box.w = self->box.current_min_width;
    self->box.h = self->box.current_min_height;
    land_call_method(self, layout_changing, (self));
    gul_box_top_down(self);
    land_call_method(self, layout_changed, (self));
}
void _land_gul_layout_updated(LandWidget * self) {
    /* This is used if the size of a widget may have changed and therefore its own
     * as well as its parent's layout needs updating.
     */
    D(printf("gul_layout_updated %s[%p]\n", self->vt->name, self));
    update_lookup_grid(self);
    if (self->parent && ! (self->parent->box.flags & GUL_NO_LAYOUT)) {
        if (self->no_layout_notify == 0) {
            self->no_layout_notify = 1;
            _land_gul_layout_updated(self->parent);
            self->no_layout_notify = 0;
        }
    }
    else {
        gul_box_fit_children(self);
    }
}
void _land_gul_layout_updated_during_layout(LandWidget * self) {
    /* FIXME: What the hell is this? Can't we do it the proper way?
     * If widgets are added or removed in the middle of a layout algorithm run,
     * this function should be called from within the layout_changed event.
     */
    update_lookup_grid(self);
    gul_box_bottom_up(self);
}
#undef D
static LandList * runners;
static LandRunner * active_runner;
void land_runner_register(LandRunner * self) {
    land_log_message("land_runner_register \"%s\"\n", self->name);
    land_add_list_data(& runners, self);
}
void land_runner_initialize(LandRunner * self, char const * name, void(* init)(LandRunner * self), void(* enter)(LandRunner * self), void(* tick)(LandRunner * self), void(* draw)(LandRunner * self), void(* leave)(LandRunner * self), void(* destroy)(LandRunner * self)) {
    self->name = land_strdup(name);
    self->init = init;
    self->enter = enter;
    self->tick = tick;
    self->draw = draw;
    self->leave = leave;
    self->destroy = destroy;
}
LandRunner* land_runner_new(char const * name, void(* init)(LandRunner * self), void(* enter)(LandRunner * self), void(* tick)(LandRunner * self), void(* draw)(LandRunner * self), void(* leave)(LandRunner * self), void(* destroy)(LandRunner * self)) {
    LandRunner * self;
    land_alloc(self);
    self->allocated = 1;
    land_runner_initialize(self, name, init, enter, tick, draw, leave, destroy);
    return self;
}
void land_runner_switch_active(LandRunner * self) {
    land_runner_leave_active();
    active_runner = self;
    if (active_runner && ! active_runner->inited) {
        active_runner->inited = 1;
        if (active_runner->init) {
            active_runner->init(active_runner);
        }
    }
    land_runner_enter_active();
}
void land_runner_enter_active(void) {
    LandRunner * self = active_runner;
    if (self && self->enter) {
        self->enter(self);
    }
}
void land_runner_tick_active(void) {
    LandRunner * self = active_runner;
    if (self && self->tick) {
        self->tick(self);
    }
}
void land_runner_draw_active(void) {
    LandRunner * self = active_runner;
    if (self && self->draw) {
        self->draw(self);
    }
}
void land_runner_leave_active(void) {
    LandRunner * self = active_runner;
    if (self && self->leave) {
        self->leave(self);
    }
}
void land_runner_destroy_all(void) {
    land_log_message("land_runner_destroy_all\n");
    LandListItem * i;
    if (! runners) {
        return ;
    }
    for (i = runners->first; i; i = i->next) {
        LandRunner * self = (LandRunner *) i->data;
        if (self->destroy) {
            self->destroy(self);
        }
        land_log_message("destroyed %s\n", self->name);
        land_free(self->name);
        if (self->allocated) {
            land_free(self);
        }
    }
    land_list_destroy(runners);
}
#ifdef LAND_HAVE_EXECINFO_h
#endif
#ifdef LAND_MEMLOG
static char const * LOGFILE = "memlog.log";
static LandLock * lock;
#define MAX_BLOCKS 1024 * 1024
static int installed = 0;
static bool installing;
static struct LandMemBlockInfo not_freed [MAX_BLOCKS];
static int _num = 0;
static int _size = 0;
static int _maxnum = 0;
static int _maxsize = 0;
static void done(void) {
    int n;
    installing = 1;
    land_thread_delete_lock(lock);
    FILE * lf = fopen(LOGFILE, "a");
    fprintf(lf, "Memory statistics:\n");
    fprintf(lf, "Maximum number of simultanously allocated blocks: %d\n", _maxnum);
    fprintf(lf, "Maximum number of simultanously allocated elements: %d\n", _maxsize);
    fprintf(lf, "Memory leaks: %d\n", _num);
    for (n = 0; n < _num; n++) {
        fprintf(lf, "%s: %d: %d elements [%s] not freed: %p\n", not_freed [n].file, not_freed [n].line, not_freed [n].size, not_freed [n].id, not_freed [n].ptr);
        fflush(lf);
        backtrace_symbols_fd(not_freed [n].trace, not_freed [n].trace_depth, fileno(lf));
        if (! strcmp(not_freed [n].id, "")) {
            fprintf(lf, "    first bytes: [");
            for (int i = 0; i < 16; i++) {
                if (i >= not_freed [n].size) {
                    break;
                }
                int c = * ((unsigned char *)(not_freed [n].ptr) + i);
                if (c >= 32 && c <= 127) {
                    fprintf(lf, "%c", c);
                }
                else {
                    fprintf(lf, "«%d»", c);
                }
            }
            fprintf(lf, "]\n");
        }
    }
    fclose(lf);
}
static void install(void) {
    installed++;
    if (installed == 1) {
        installing = 1;
        lock = land_thread_new_lock();
        installing = 0;
        atexit(done);
        FILE * lf = fopen(LOGFILE, "w");
        fprintf(lf, "Land MemLog\n");
        fclose(lf);
    }
}
void land_memory_add(void * ptr, char const * id, int size, const char * f, int l) {
    if (installing) {
        return ;
    }
    if (! installed) {
        install();
    }
    land_thread_lock(lock);
    if (! ptr) {
        if (size) {
            FILE * lf = fopen(LOGFILE, "a");
            fprintf(lf, "%s: %d: allocation of %d elements [%s] failed\n", f, l, size, id);
            fclose(lf);
        }
        goto ret;
    }
    if (_num >= MAX_BLOCKS) {
        FILE * lf = fopen(LOGFILE, "a");
        fprintf(lf, "memlog block number exceeded\n");
        fclose(lf);
        goto ret;
    }
    not_freed [_num].ptr = ptr;
    not_freed [_num].file = f;
    not_freed [_num].line = l;
    not_freed [_num].id = id;
    not_freed [_num].size = size;
    not_freed [_num].trace_depth = backtrace(not_freed [_num].trace, LAND_MEMBLOCK_INFO_MAX_STACK);
    _num++;
    _size += size;
    if (_num > _maxnum) {
        _maxnum = _num;
    }
    if (_size > _maxsize) {
        _maxsize = _size;
    }
    #ifdef LOGALL
    FILE * lf = fopen(LOGFILE, "a");
    fprintf(lf, "%s: %d: allocated: %d elements [%s] at %p\n", f, l, size, id, ptr);
    fclose(lf);
    #endif
    ret:;
    land_thread_unlock(lock);
}
void land_memory_remove(void * ptr, char const * id, int re, const char * f, int l) {
    if (installing) {
        return ;
    }
    int n;
    if (! installed) {
        install();
    }
    land_thread_lock(lock);
    if (! ptr) {
        if (re) {
            #ifdef LOGALL
            FILE * lf = fopen(LOGFILE, "a");
            fprintf(lf, "%s: %d: reallocated: %p [%s]\n", f, l, ptr, id);
            fclose(lf);
            #endif
            goto ret;
        }
        FILE * lf = fopen(LOGFILE, "a");
        fprintf(lf, "%s: %d: freed 0 pointer [%s]\n", f, l, id);
        fclose(lf);
        abort();
        goto ret;
    }
    for (n = 0; n < _num; n++) {
        if (not_freed [n].ptr == ptr) {
            #ifdef LOGALL
            FILE * lf = fopen(LOGFILE, "a");
            fprintf(lf, "%s: %d: freed: %d elements [%s] at %p\n", f, l, not_freed [n].size, id, ptr);
            fclose(lf);
            #endif
            _size -= not_freed [n].size;
            not_freed [n] = not_freed [_num - 1];
            _num--;
            goto ret;
        }
    }
    FILE * lf = fopen(LOGFILE, "a");
    fprintf(lf, "%s: %d: double freed or never allocated: %p [%s]\n", f, l, ptr, id);
    fclose(lf);
    abort();
    ret:;
    land_thread_unlock(lock);
}
void* land_malloc_memlog(int size, char const * f, int l) {
    void * ptr = malloc(size);
    land_memory_add(ptr, "", size, f, l);
    return ptr;
}
void* land_calloc_memlog(int size, char const * f, int l) {
    void * ptr = calloc(1, size);
    land_memory_add(ptr, "", size, f, l);
    return ptr;
}
void* land_realloc_memlog(void * ptr, int size, char const * f, int l) {
    void * p = realloc(ptr, size);
    land_memory_remove(ptr, "", 1, f, l);
    land_memory_add(p, "", size, f, l);
    return p;
}
char* land_strdup_memlog(char const * str, char const * f, int l) {
    void * p = strdup(str);
    land_memory_add(p, "", strlen(p), f, l);
    return p;
}
void land_free_memlog(void * ptr, char const * f, int l) {
    land_memory_remove(ptr, "", 0, f, l);
    free(ptr);
}
#else
void* land_malloc(int size) {
    return malloc(size);
}
void* land_calloc(int size) {
    return calloc(1, size);
}
void* land_realloc(void * ptr, int size) {
    return realloc(ptr, size);
}
char* land_strdup(char const * str) {
    return strdup(str);
}
void land_free(void * ptr) {
    free(ptr);
}
#endif
#undef MAX_BLOCKS
    /* Simple helper object for maintaining a vertex/fragment shader combination
     * with GLSL.
     */
static void shader_setup(LandGLSLShader * self, char const * name, char const * vertex_glsl, char const * fragment_glsl) {
    if (vertex_glsl) {
        self->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(self->vertex_shader, 1, & vertex_glsl, NULL);
        glCompileShader(self->vertex_shader);
        GLint success;
        glGetShaderiv(self->vertex_shader, GL_COMPILE_STATUS, & success);
        if (1) {
            int size;
            glGetShaderiv(self->vertex_shader, GL_INFO_LOG_LENGTH, & size);
            char error [size];
            glGetShaderInfoLog(self->vertex_shader, size, & size, error);
            if (size) {
                land_log_message("%s: Vertex Shader %s:\n%s\n", name, success ? "Warning" : "Error", error);
            }
        }
    }
    if (fragment_glsl) {
        self->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(self->fragment_shader, 1, & fragment_glsl, NULL);
        glCompileShader(self->fragment_shader);
        GLint success;
        glGetShaderiv(self->fragment_shader, GL_COMPILE_STATUS, & success);
        if (1) {
            int size;
            glGetShaderiv(self->fragment_shader, GL_INFO_LOG_LENGTH, & size);
            char error [size];
            glGetShaderInfoLog(self->fragment_shader, size, & size, error);
            if (size) {
                land_log_message("%s: Fragment Shader %s:\n%s\n", name, success ? "Warning" : "Error", error);
            }
        }
    }
    if (! self->program_object) {
        self->program_object = glCreateProgram();
    }
    if (self->fragment_shader) {
        glAttachShader(self->program_object, self->fragment_shader);
    }
    if (self->vertex_shader) {
        glAttachShader(self->program_object, self->vertex_shader);
    }
    if (self->fragment_shader && self->vertex_shader) {
        glLinkProgram(self->program_object);
        GLint success;
        glGetProgramiv(self->program_object, GL_LINK_STATUS, & success);
        if (1) {
            int size;
            glGetProgramiv(self->program_object, GL_INFO_LOG_LENGTH, & size);
            char error [size];
            glGetProgramInfoLog(self->program_object, size, & size, error);
            if (size) {
                land_log_message("%s: Shader Link Error:\n%s\n", name, error);
            }
        }
    }
}
static void shader_cleanup(LandGLSLShader * self) {
    if (self->program_object) {
        glDeleteProgram(self->program_object);
        glDeleteShader(self->vertex_shader);
        glDeleteShader(self->fragment_shader);
    }
}
LandGLSLShader* land_glsl_shader_new(char const * name, char const * vertex_glsl, char const * fragment_glsl) {
    LandGLSLShader * self;
    land_alloc(self);
    shader_setup(self, name, vertex_glsl, fragment_glsl);
    return self;
}
LandGLSLShader* land_glsl_shader_new_empty(char const * name) {
    LandGLSLShader * self;
    land_alloc(self);
    shader_setup(self, name, NULL, NULL);
    return self;
}
void land_glsl_shader_set_shaders(LandGLSLShader * self, char const * vertex_glsl, char const * fragment_glsl) {
    shader_setup(self, NULL, vertex_glsl, fragment_glsl);
}
void land_glsl_shader_destroy(LandGLSLShader * self) {
    shader_cleanup(self);
    land_free(self);
}
char* land_read_text(char const * filename) {
    FILE * pf = fopen(filename, "rb");
    if (! pf) {
        return NULL;
    }
    int s = 1;
    char * buf = land_malloc(s);
    int n = 0;
    while (1) {
        int c = fgetc(pf);
        if (c <= 0) {
            break;
        }
        buf [n] = c;
        n++;
        if (n >= s) {
            s *= 2;
            buf = land_realloc(buf, s);
        }
    }
    fclose(pf);
    buf [n] = 0;
    n++;
    buf = land_realloc(buf, n);
    return buf;
}
int land_utf8_char(char * (* pos)) {
    /* Return the unicode value at the given pointer position, and advance the
     * pointer to the start of the next code point.
     */
    unsigned char * upos = (unsigned char *) * pos;
    int remain;
    int c = * upos++;
    if (c < 128) {
        * pos = (char *) upos;
        return c;
    }
    if (c < 194) {
        return 0;
    }
    if (c < 224) {
        c &= 31;
        remain = 1;
    }
    else if (c < 240) {
        c &= 15;
        remain = 2;
    }
    else if (c < 245) {
        c &= 7;
        remain = 3;
    }
    else {
        return 0;
    }
    while (remain--) {
        int d = * upos++;
        c = (c << 6) | (d & 63);
    }
    * pos = (char *) upos;
    return c;
}
int land_utf8_char_back(char * (* pos)) {
    /* Adjust the pointer back to the previous code point and return its value.
     */
    unsigned char * upos = (unsigned char *) * pos;
    while (((* (--upos) & 0xc0) == 0x80)) {
    }
    * pos = (char *) upos;
    int c = land_utf8_char((char * *) & upos);
    return c;
}
int land_utf8_char_const(char const * (* pos)) {
    char * (* p) = (char * *) pos;
    return land_utf8_char(p);
}
int land_utf8_encode(int c, char * s) {
    uint32_t uc = c;
    if (uc <= 0x7f) {
        if (s) {
            s [0] = uc;
        }
        return 1;
    }
    if (uc <= 0x7ff) {
        if (s) {
            s [0] = 0xC0 | ((uc >> 6) & 0x1F);
            s [1] = 0x80 | (uc & 0x3F);
        }
        return 2;
    }
    if (uc <= 0xffff) {
        if (s) {
            s [0] = 0xE0 | ((uc >> 12) & 0x0F);
            s [1] = 0x80 | ((uc >> 6) & 0x3F);
            s [2] = 0x80 | (uc & 0x3F);
        }
        return 3;
    }
    if (uc <= 0x10ffff) {
        if (s) {
            s [0] = 0xF0 | ((uc >> 18) & 0x07);
            s [1] = 0x80 | ((uc >> 12) & 0x3F);
            s [2] = 0x80 | ((uc >> 6) & 0x3F);
            s [3] = 0x80 | (uc & 0x3F);
        }
        return 4;
    }
    return 0;
}
char* land_utf8_realloc_insert(char * s, int pos, int c) {
    /* (abc, 3, d) -> abcd
     */
    int len = strlen(s);
    int clen = land_utf8_encode(c, NULL);
    s = land_realloc(s, len + clen + 1);
    char * p = s;
    for (int i = 0; i < pos; i++) {
        land_utf8_char(& p);
    }
    memmove(p + clen, p, len + 1 - (p - s));
    land_utf8_encode(c, p);
    return s;
}
char* land_utf8_realloc_remove(char * s, int pos) {
    /* (abc, 1) -> ac
     */
    int len = strlen(s);
    char * p = s;
    for (int i = 0; i < pos; i++) {
        land_utf8_char(& p);
    }
    char * p2 = p;
    land_utf8_char(& p2);
    memmove(p, p2, len - (p2 - s) + 1);
    s = land_realloc(s, len - (p2 - p) + 1);
    return s;
}
int land_utf8_count(char const * s) {
    int n = 0;
    while (land_utf8_char_const(& s)) {
        n++;
    }
    return n;
}
void land_utf8_copy(char * target, int size, char const * source) {
    int i = 0;
    char const * ptr = source;
    char const * prev = source;
    while (land_utf8_char_const(& ptr)) {
        int s = ptr - prev;
        if (i + s < size) {
            memcpy(target + i, prev, s);
            i += s;
        }
        else {
            break;
        }
        prev = ptr;
    }
    target [i] = 0;
}
bool land_fnmatch(char const * pattern, char const * name) {
    int i = 0, j = 0;
    while (1) {
        switch (pattern [i]) {
            case 0: {
                return name [j] == 0;
            }
            case '?': {
                if (name [j] == 0) {
                    return 0;
                }
                break;
            }
            case '*': {
                while (pattern [i] == '*') {
                    i++;
                }
                if (pattern [i] == 0) {
                    return 1;
                }
                while (name [j] != 0) {
                    if (land_fnmatch(pattern + i, name + j)) {
                        return 1;
                    }
                    j++;
                }
                return false;
            }
            default: {
                if (pattern [i] != name [j]) {
                    return 0;
                }
            }
        }
        i++;
        j++;
    }
}
char* land_string_copy(char * target, char const * source, int size) {
    /* size is the size of target in bytes (including the terminating 0)
     * Returns target.
     */
    strncpy(target, source, size - 1);
    target [size - 1] = 0;
    return target;
}
bool land_equals(char const * s, char const * s2) {
    return strcmp(s, s2) == 0;
}
bool land_ends_with(char const * s, char const * end) {
    size_t n = strlen(end);
    if (strlen(end) > n) {
        return 0;
    }
    return strncmp(s + strlen(s) - n, end, n) == 0;
}
bool land_starts_with(char const * s, char const * start) {
    size_t n = strlen(start);
    if (strlen(start) > n) {
        return 0;
    }
    return strncmp(s, start, n) == 0;
}
void land_concatenate(char * (* s), char const * cat) {
    int sn = strlen(* s);
    int n = sn + strlen(cat) + 1;
    char * re = land_realloc(* s, n);
    memmove(re + sn, cat, strlen(cat));
    re [n - 1] = 0;
    * s = re;
}
void land_concatenate_with_separator(char * (* s), char const * cat, char const * sep) {
    if (! (* s) || land_equals(* s, "")) {
        land_concatenate(s, cat);
    }
    else {
        land_concatenate(s, sep);
        land_concatenate(s, cat);
    }
}
void land_prepend(char * (* s), char const * pre) {
    int n = strlen(* s) + strlen(pre) + 1;
    char * re = land_realloc(* s, n);
    memmove(re + strlen(pre), re, strlen(* s));
    memmove(re, pre, strlen(pre));
    re [n - 1] = 0;
    * s = re;
}
int land_replace(char * (* s), int off, char const * wat, char const * wit) {
    char * r = strstr(* s + off, wat);
    if (! r) {
        return strlen(* s);
    }
    int pn = r - * s;
    int sn = strlen(* s);
    int n = sn + strlen(wit) - strlen(wat) + 1;
    char * re = land_malloc(n);
    memmove(re, * s, r - * s);
    memmove(re + pn, wit, strlen(wit));
    memmove(re + pn + strlen(wit), r + strlen(wat), sn - pn - strlen(wat));
    re [n - 1] = 0;
    land_free(* s);
    * s = re;
    return pn + strlen(wit);
}
int land_replace_all(char * (* s), char const * wat, char const * wit) {
    int off = 0;
    int c = 0;
    while (1) {
        off = land_replace(s, off, wat, wit);
        if (! (* s) [off]) {
            return c;
        }
        c++;
    }
}
char* land_substring(char const * s, int a, int b) {
    if (a < 0) {
        a += strlen(s);
    }
    if (b < 0) {
        b += strlen(s);
    }
    char * r = land_malloc(b - a + 1);
    memmove(r, s + a, b - a);
    r [b - a] = 0;
    return r;
}
LandArray* land_filelist(char const * dir, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data) {
    /* Returns an array of files in the given directory. Before a file is added,
     * the filter function is called, with the name about to be added and an
     * indication whether it is a filename or a directory.
     * If flags is LAND_FULL_PATH files are returned as a full path, if
     * LAND_RELATIVE_PATH relative to dir, otherwise as
     * only the filename.
     * The return value of the filter decides what is done with the name:
     * 0 - Discard it.
     * 1 - Append it to the returned list.
     * 2 - If it is a directory, recurse into it.
     * 3 - Like 1 and 2 combined.
     */
    return platform_filelist(dir, filter, flags, data);
}
LandArray* land_split_path_name_ext(char const * filename) {
    /* Returns a LandArray with three elements, for example:
     * data/blah/tree.png -> ["data/blah", "tree", "png"]
     * test.txt -> [None, "test", "txt"]
     * /etc/passwd -> ["/etc", "passwd", None]
     * The return value can most conveniently be freed like this:
     * a = land_split_path_name_ext(filename)
     * ...
     * land_array_destroy_with_strings(a)
     */
    LandArray * a = land_array_new();
    char * path = land_strdup(filename);
    char * name;
    char * ext;
    char * slash = strrchr(path, '/');
    if (slash) {
        * slash = 0;
        name = land_strdup(slash + 1);
    }
    else {
        name = path;
        path = NULL;
    }
    char * dot = strrchr(name, '.');
    if (dot) {
        * dot = 0;
        ext = land_strdup(dot + 1);
    }
    else {
        ext = NULL;
    }
    land_array_add(a, path);
    land_array_add(a, name);
    land_array_add(a, ext);
    return a;
}
LandArray* land_split(char const * text, char c) {
    /* Returns an array of strings which you should destroy with
     * land_array_destroy_with_strings
     */
    LandArray * split = land_array_new();
    LandBuffer * buf = land_buffer_new();
    land_buffer_cat(buf, text);
    LandArray * lines = land_buffer_split(buf, c);
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(lines);
        for (LandBuffer * line = LandArrayIterator_item(lines, &__iter0__); LandArrayIterator_next(lines, &__iter0__); line = LandArrayIterator_item(lines, &__iter0__)) {
            char * x = land_buffer_finish(line);
            land_array_add(split, x);
        }
    }
    land_array_destroy(lines);
    land_buffer_destroy(buf);
    return split;
}
LandArray* land_split_lines(char const * text) {
    return land_split(text, '\n');
}
static void test(char const * name, int want, int got) {
    if (want == got) {
        printf("OK   %s\n", name);
    }
    else {
        printf("FAIL %s (want %d but got %d)\n", name, want, got);
    }
}
void csg_test_shapes(void) {
    LandCSG * cube = csg_cube(NULL);
    test("cube", 6, cube->polygons->count);
    land_csg_destroy(cube);
    LandCSG * sphere = csg_sphere(3, 3, NULL);
    test("sphere", 6, sphere->polygons->count);
    land_csg_destroy(sphere);
    LandCSG * sphere2 = csg_sphere(3, 4, NULL);
    test("sphere2", 9, sphere2->polygons->count);
    land_csg_destroy(sphere2);
    LandCSG * sphere3 = csg_sphere(4, 3, NULL);
    test("sphere3", 8, sphere3->polygons->count);
    land_csg_destroy(sphere3);
    LandCSG * cylinder = csg_cylinder(3, NULL);
    test("cylinder", 9, cylinder->polygons->count);
    land_csg_destroy(cylinder);
    LandCSG * cylinder2 = csg_cylinder(4, NULL);
    test("cylinder2", 12, cylinder2->polygons->count);
    land_csg_destroy(cylinder2);
}
void csg_test_union(void) {
    LandCSG * cubeA = csg_cube(NULL);
    LandCSG * cubeB = csg_cube(NULL);
    land_csg_transform(cubeB, land_4x4_matrix_translate(4, 0, 0));
    LandCSG * AB = land_csg_union(cubeA, cubeB);
    test("AB", 12, AB->polygons->count);
    LandCSG * cubeC = csg_cube(NULL);
    land_csg_transform(cubeC, land_4x4_matrix_translate(2, 0, 0));
    LandCSG * AC = land_csg_union(cubeA, cubeC);
    test("AC", 10, AC->polygons->count);
    LandCSG * ABC1 = land_csg_union(AB, cubeC);
    test("ABC1", 14, ABC1->polygons->count);
    LandCSG * ABC2 = land_csg_union(cubeB, AC);
    test("ABC2", 14, ABC2->polygons->count);
    land_csg_destroy(cubeA);
    land_csg_destroy(cubeB);
    land_csg_destroy(cubeC);
    land_csg_destroy(AB);
    land_csg_destroy(AC);
    land_csg_destroy(ABC1);
    land_csg_destroy(ABC2);
}
void csg_test_subtract(void) {
    LandCSG * cubeA = csg_cube(NULL);
    LandCSG * cubeB = csg_cube(NULL);
    land_csg_transform(cubeB, land_4x4_matrix_translate(1, 0, 0));
    LandCSG * A_B = land_csg_subtract(cubeA, cubeB);
    test("A-B", 6, A_B->polygons->count);
    LandCSG * cubeBi = land_csg_inverse(cubeB);
    test("Bi", 6, cubeBi->polygons->count);
    LandCSG * ABi = land_csg_union(cubeA, cubeBi);
    test("ABi", 6, ABi->polygons->count);
    land_csg_destroy(cubeA);
    land_csg_destroy(cubeB);
    land_csg_destroy(A_B);
    land_csg_destroy(cubeBi);
    land_csg_destroy(ABi);
}
void csg_test_intersect(void) {
    LandCSG * cubeA = csg_cube(NULL);
    LandCSG * cubeB = csg_cube(NULL);
    land_csg_transform(cubeB, land_4x4_matrix_translate(1, 0, 0));
    LandCSG * A_B = land_csg_intersect(cubeA, cubeB);
    test("A/B", 6, A_B->polygons->count);
    land_csg_destroy(cubeA);
    land_csg_destroy(cubeB);
    land_csg_destroy(A_B);
}
void csg_test(void) {
    csg_test_shapes();
    csg_test_union();
    csg_test_subtract();
    csg_test_intersect();
}
#define pi LAND_PI
static void sphere_point(LandArray * vertices, LandFloat i, LandFloat j) {
    LandFloat theta = 2 * pi * i;
    LandFloat phi = pi * j;
    LandVector normal = land_vector(cos(theta) * sin(phi), cos(phi), sin(theta) * sin(phi));
    LandVector pos = normal;
    land_array_add(vertices, land_csg_vertex_new(pos, normal));
}
LandCSG* csg_sphere(int slices, int rings, void * shared) {
    /* Make a sphere with radius 1.0.
     * It fits within a cube from -1/-1/-1 to 1/1/1.
     * rings determines how many parts the latitude is divided into, a
     * value of 3 means just south pole, equator and north pole.
     * slices determins how many parts the longitude is divided into,
     * a value of 3 means 0-meridian, +120° and -120°.
     */
    if (slices < 3) {
        return NULL;
    }
    if (rings < 3) {
        return NULL;
    }
    LandArray * polygons = land_array_new();
    for (int i = 0; i < slices; i += 1) {
        for (int j = 0; j < rings - 1; j += 1) {
            LandArray * vertices = land_array_new();
            sphere_point(vertices, 1.0 * i / slices, 1.0 * j / (rings - 1));
            if (j > 0) {
                sphere_point(vertices, 1.0 * (i + 1) / slices, 1.0 * j / (rings - 1));
            }
            if (j < rings - 2) {
                sphere_point(vertices, 1.0 * (i + 1) / slices, 1.0 * (j + 1) / (rings - 1));
            }
            sphere_point(vertices, 1.0 * i / slices, 1.0 * (j + 1) / (rings - 1));
            land_array_add(polygons, land_csg_polygon_new(vertices, shared));
        }
    }
    return land_csg_new_from_polygons(polygons);
}
LandCSG* csg_cylinder(int slices, void * shared) {
    return csg_cylinder_open(slices, 0, shared);
}
LandCSG* csg_cylinder_open(int slices, bool opened, void * shared) {
    /* Make a cylinder along the z-axis with radius 1.0 and height 2.0.
     * It fits within a cube from -1/-1/-1 to 1/1/1.
     */
    if (slices < 3) {
        return NULL;
    }
    LandVector up = land_vector(0, 0, 1);
    LandVector down = land_vector(0, 0, - 1);
    LandArray * polygons = land_array_new();
    for (int i = 0; i < slices; i += 1) {
        LandCSGVertex * start = land_csg_vertex_new(down, down);
        LandCSGVertex * end = land_csg_vertex_new(up, up);
        LandFloat angle0 = i * 2 * pi / slices;
        LandFloat angle1 = (i + 1) * 2 * pi / slices;
        LandFloat c0 = cos(angle0), s0 = sin(angle0);
        LandFloat c1 = cos(angle1), s1 = sin(angle1);
        LandVector side0 = land_vector(c0, - s0, 0);
        LandVector side1 = land_vector(c1, - s1, 0);
        LandVector v0d = land_vector(c0, - s0, - 1);
        LandVector v1d = land_vector(c1, - s1, - 1);
        LandVector v0u = land_vector(c0, - s0, 1);
        LandVector v1u = land_vector(c1, - s1, 1);
        LandArray * vertices;
        if (! opened) {
            vertices = land_array_new();
            land_array_add(vertices, start);
            land_array_add(vertices, land_csg_vertex_new(v0d, down));
            land_array_add(vertices, land_csg_vertex_new(v1d, down));
            land_array_add(polygons, land_csg_polygon_new(vertices, shared));
        }
        vertices = land_array_new();
        land_array_add(vertices, land_csg_vertex_new(v1d, side1));
        land_array_add(vertices, land_csg_vertex_new(v0d, side0));
        land_array_add(vertices, land_csg_vertex_new(v0u, side0));
        land_array_add(vertices, land_csg_vertex_new(v1u, side1));
        land_array_add(polygons, land_csg_polygon_new(vertices, shared));
        if (! opened) {
            vertices = land_array_new();
            land_array_add(vertices, end);
            land_array_add(vertices, land_csg_vertex_new(v1u, up));
            land_array_add(vertices, land_csg_vertex_new(v0u, up));
            land_array_add(polygons, land_csg_polygon_new(vertices, shared));
        }
    }
    return land_csg_new_from_polygons(polygons);
}
LandCSG* csg_cone(int slices, void * shared) {
    /* Make a cone along the z-axis with radius 1.0 and height 2.0.
     * The top of the cone is at 0/0/1.
     * It fits within a cube from -1/-1/-1 to 1/1/1.
     */
    if (slices < 3) {
        return NULL;
    }
    LandVector down = land_vector(0, 0, - 1);
    LandVector up = land_vector(0, 0, 1);
    LandArray * polygons = land_array_new();
    for (int i = 0; i < slices; i += 1) {
        LandCSGVertex * start = land_csg_vertex_new(down, down);
        LandFloat angle0 = i * 2 * pi / slices;
        LandFloat angle1 = (i + 1) * 2 * pi / slices;
        LandFloat c0 = cos(angle0), s0 = sin(angle0);
        LandFloat c1 = cos(angle1), s1 = sin(angle1);
        LandVector side0 = land_vector_normalize(land_vector(c0, - s0, 0.5));
        LandVector side1 = land_vector_normalize(land_vector(c1, - s1, 0.5));
        LandVector v0d = land_vector(c0, - s0, - 1);
        LandVector v1d = land_vector(c1, - s1, - 1);
        LandArray * vertices;
        vertices = land_array_new();
        land_array_add(vertices, start);
        land_array_add(vertices, land_csg_vertex_new(v0d, down));
        land_array_add(vertices, land_csg_vertex_new(v1d, down));
        land_array_add(polygons, land_csg_polygon_new(vertices, shared));
        vertices = land_array_new();
        land_array_add(vertices, land_csg_vertex_new(up, up));
        land_array_add(vertices, land_csg_vertex_new(v1d, side1));
        land_array_add(vertices, land_csg_vertex_new(v0d, side0));
        land_array_add(polygons, land_csg_polygon_new(vertices, shared));
    }
    return land_csg_new_from_polygons(polygons);
}
LandCSG* csg_prism(int slices, void * shared) {
    return NULL;
}
static void add_quad(LandArray * polygons, LandVector a, LandVector b, LandVector c, LandVector d, void * shared) {
    LandArray * vertices = land_array_new();
    LandVector ab = land_vector_sub(b, a);
    LandVector bc = land_vector_sub(c, b);
    LandVector normal = land_vector_normalize(land_vector_cross(ab, bc));
    land_array_add(vertices, land_csg_vertex_new(a, normal));
    land_array_add(vertices, land_csg_vertex_new(b, normal));
    land_array_add(vertices, land_csg_vertex_new(c, normal));
    land_array_add(vertices, land_csg_vertex_new(d, normal));
    land_array_add(polygons, land_csg_polygon_new(vertices, shared));
}
static void add_tri(LandArray * polygons, LandVector a, LandVector b, LandVector c, void * shared) {
    LandArray * vertices = land_array_new();
    LandVector ab = land_vector_sub(b, a);
    LandVector bc = land_vector_sub(c, b);
    LandVector normal = land_vector_normalize(land_vector_cross(ab, bc));
    land_array_add(vertices, land_csg_vertex_new(a, normal));
    land_array_add(vertices, land_csg_vertex_new(b, normal));
    land_array_add(vertices, land_csg_vertex_new(c, normal));
    land_array_add(polygons, land_csg_polygon_new(vertices, shared));
}
LandCSG* csg_pyramid(void * shared) {
    /* Make a 4-sided pyramid with a side-length of 1 and a height of 2.
     * The top is at 0/0/1.
     * It fits within a cube from -1/-1/-1 to 1/1/1.
     */
    LandArray * polygons = land_array_new();
    LandVector a = land_vector(- 1, - 1, - 1);
    LandVector b = land_vector(1, - 1, - 1);
    LandVector c = land_vector(1, 1, - 1);
    LandVector d = land_vector(- 1, 1, - 1);
    LandVector e = land_vector(0, 0, 1);
    add_quad(polygons, a, d, c, b, shared);
    add_tri(polygons, a, b, e, shared);
    add_tri(polygons, b, c, e, shared);
    add_tri(polygons, c, d, e, shared);
    add_tri(polygons, d, a, e, shared);
    return land_csg_new_from_polygons(polygons);
}
LandCSG* csg_tetrahedron(void * shared) {
    /* Make a tetrahedron.
     */
    LandArray * polygons = land_array_new();
    LandFloat s = 1 / sqrt(2);
    LandVector a = land_vector(- 1, 0, - s);
    LandVector b = land_vector(1, 0, - s);
    LandVector c = land_vector(0, - 1, s);
    LandVector d = land_vector(0, 1, s);
    add_tri(polygons, a, d, b, shared);
    add_tri(polygons, d, c, b, shared);
    add_tri(polygons, c, d, a, shared);
    add_tri(polygons, c, a, b, shared);
    return land_csg_new_from_polygons(polygons);
}
LandCSG* csg_cube(void * shared) {
    /* Make a cube from -1/-1/-1 to 1/1/1.
     */
    LandArray * polygons = land_array_new();
    LandVector a = land_vector(- 1, - 1, - 1);
    LandVector b = land_vector(1, - 1, - 1);
    LandVector c = land_vector(1, 1, - 1);
    LandVector d = land_vector(- 1, 1, - 1);
    LandVector e = land_vector(- 1, - 1, 1);
    LandVector f = land_vector(1, - 1, 1);
    LandVector g = land_vector(1, 1, 1);
    LandVector h = land_vector(- 1, 1, 1);
    add_quad(polygons, a, d, c, b, shared);
    add_quad(polygons, e, f, g, h, shared);
    add_quad(polygons, h, g, c, d, shared);
    add_quad(polygons, g, f, b, c, shared);
    add_quad(polygons, f, e, a, b, shared);
    add_quad(polygons, e, h, d, a, shared);
    return land_csg_new_from_polygons(polygons);
}
LandCSG* csg_block(int x, int y, int z, bool outside, void * shared) {
    bool all = ! outside;
    LandArray * polygons = land_array_new();
    LandFloat xs = 1.0 / x;
    LandFloat ys = 1.0 / y;
    LandFloat zs = 1.0 / z;
    for (int i = 0; i < x; i += 1) {
        for (int j = 0; j < y; j += 1) {
            for (int k = 0; k < z; k += 1) {
                LandFloat xp = - 1 + xs + i * xs * 2;
                LandFloat yp = - 1 + ys + j * ys * 2;
                LandFloat zp = - 1 + zs + k * zs * 2;
                LandVector a = land_vector(xp + xs * (- 1), yp + ys * (- 1), zp + zs * (- 1));
                LandVector b = land_vector(xp + xs * 1, yp + ys * (- 1), zp + zs * (- 1));
                LandVector c = land_vector(xp + xs * 1, yp + ys * 1, zp + zs * (- 1));
                LandVector d = land_vector(xp + xs * (- 1), yp + ys * 1, zp + zs * (- 1));
                LandVector e = land_vector(xp + xs * (- 1), yp + ys * (- 1), zp + zs * 1);
                LandVector f = land_vector(xp + xs * 1, yp + ys * (- 1), zp + zs * 1);
                LandVector g = land_vector(xp + xs * 1, yp + ys * 1, zp + zs * 1);
                LandVector h = land_vector(xp + xs * (- 1), yp + ys * 1, zp + zs * 1);
                if (all || k == 0) {
                    add_quad(polygons, a, d, c, b, shared);
                }
                if (all || k == z - 1) {
                    add_quad(polygons, e, f, g, h, shared);
                }
                if (all || j == y - 1) {
                    add_quad(polygons, h, g, c, d, shared);
                }
                if (all || i == x - 1) {
                    add_quad(polygons, g, f, b, c, shared);
                }
                if (all || j == 0) {
                    add_quad(polygons, f, e, a, b, shared);
                }
                if (all || i == 0) {
                    add_quad(polygons, e, h, d, a, shared);
                }
            }
        }
    }
    return land_csg_new_from_polygons(polygons);
}
static void torus_point(LandArray * vertices, LandFloat i, LandFloat j, LandFloat r) {
    LandFloat theta = 2 * pi * i;
    LandFloat phi = 2 * pi * j;
    LandFloat cx = cos(theta);
    LandFloat cy = sin(theta);
    LandVector pos = land_vector(cx + cx * r * cos(phi), cy + cy * cos(phi) * r, sin(phi) * r);
    LandVector normal = land_vector(cx * cos(phi), cy * cos(phi), sin(phi));
    land_array_add(vertices, land_csg_vertex_new(pos, normal));
}
LandCSG* csg_torus(int slices, int segments, LandFloat diameter, void * shared) {
    /* slices is the longitude subdivisions, or how many "disks" the torus
     * is cut into along its outer circle
     * segments is the "latitude" subdivisions, i.e. how many segments each
     * individual disk has
     * diameter is the size of the tube and must be greater than 0 (thin)
     * and less than 1 (thick).
     * The torus has radius of 1 around the origin and lies in the
     * X/Y plane. The outer radius therefore is 1 + diameter / 2.
     */
    LandArray * polygons = land_array_new();
    for (int i = 0; i < slices; i += 1) {
        for (int j = 0; j < segments; j += 1) {
            LandArray * vertices = land_array_new();
            torus_point(vertices, 1.0 * i / slices, 1.0 * j / segments, diameter / 2);
            torus_point(vertices, 1.0 * (i + 1) / slices, 1.0 * j / segments, diameter / 2);
            torus_point(vertices, 1.0 * (i + 1) / slices, 1.0 * (j + 1) / segments, diameter / 2);
            torus_point(vertices, 1.0 * i / slices, 1.0 * (j + 1) / segments, diameter / 2);
            land_array_add(polygons, land_csg_polygon_new(vertices, shared));
        }
    }
    return land_csg_new_from_polygons(polygons);
}
#undef pi
void land_layer_draw(LandLayer * self, LandView * view) {
    if (self->hidden) {
        return ;
    }
    LandView v = * view;
    v.scroll_x += self->view_x - self->x;
    v.scroll_y += self->view_y - self->y;
    v.scroll_x *= self->scrolling_x / self->scale_x;
    v.scroll_y *= self->scrolling_y / self->scale_y;
    v.scale_x *= self->scale_x;
    v.scale_y *= self->scale_y;
    v.x += self->view_x;
    v.y += self->view_y;
    v.w += self->view_w;
    v.h += self->view_h;
    v.r *= self->r;
    v.g *= self->g;
    v.b *= self->b;
    v.a *= self->a;
    if (self->grid) {
        land_grid_draw(self->grid, & v);
    }
}
void land_layer_draw_grid(LandLayer * self, LandView * view) {
    /* Draws a debug grid using the layer's cell size.
     */
    LandGrid * grid = self->grid;
    LandView v = * view;
    v.scroll_x += self->view_x - self->x;
    v.scroll_y += self->view_y - self->y;
    v.scroll_x *= self->scrolling_x;
    v.scroll_y *= self->scrolling_y;
    v.scale_x *= self->scale_x;
    v.scale_y *= self->scale_y;
    v.x += self->view_x;
    v.y += self->view_y;
    v.w += self->view_w;
    v.h += self->view_h;
    view = & v;
    land_color(0, 0, 1, 0.5);
    float cx = view->scroll_x / grid->cell_w;
    float cy = view->scroll_y / grid->cell_h;
    float ox = floor(cx) - cx;
    float oy = floor(cy) - cy;
    float sx = grid->cell_w * view->scale_x;
    float sy = grid->cell_h * view->scale_y;
    float min_x = view->x + ox * sx + 0.5;
    float min_y = view->y + oy * sy + 0.5;
    if (cx < 0) {
        min_x -= floor(cx) * sx;
    }
    if (cy < 0) {
        min_y -= floor(cy) * sy;
    }
    float max_x = view->x + sx * (grid->x_cells - cx) + 1;
    float max_y = view->y + sy * (grid->y_cells - cy) + 1;
    float vy1 = view->y;
    float vy2 = view->y + view->h;
    if (vy1 < min_y) {
        vy1 = min_y;
    }
    if (vy2 > max_y) {
        vy2 = max_y;
    }
    float vx1 = view->x;
    float vx2 = view->x + view->w;
    if (vx1 < min_x) {
        vx1 = min_x;
    }
    if (vx2 > max_x) {
        vx2 = max_x;
    }
    for (float x = min_x; x < view->x + view->w; x += sx) {
        if (x > max_x) {
            break;
        }
        land_line(x, vy1, x, vy2);
    }
    for (float y = min_y; y < view->y + view->h; y += sy) {
        if (y > max_y) {
            break;
        }
        land_line(vx1, y, vx2, y);
    }
}
void land_layer_set_name(LandLayer * self, char const * name) {
    if (self->name) {
        land_free(self->name);
    }
    self->name = land_strdup(name);
}
void land_layer_del(LandLayer * self) {
    land_grid_del(self->grid);
    if (self->name) {
        land_free(self->name);
    }
    land_free(self);
}
LandLayer* land_layer_new_with_grid(LandGrid * grid) {
    LandLayer * self;
    land_alloc(self);
    self->scrolling_x = 1;
    self->scrolling_y = 1;
    self->scale_x = 1;
    self->scale_y = 1;
    self->grid = grid;
    self->r = 1;
    self->g = 1;
    self->b = 1;
    self->a = 1;
    return self;
}
LandLayer* land_layer_new(void) {
    return land_layer_new_with_grid(NULL);
}
void land_layer_set_scroll_speed(LandLayer * self, float x, float y) {
    self->scrolling_x = x;
    self->scrolling_y = y;
}
void land_layer_set_scale(LandLayer * self, float x, float y) {
    self->scale_x = x;
    self->scale_y = y;
}
void land_layer_set_position(LandLayer * self, float x, float y) {
    self->x = x;
    self->y = y;
}
void land_layer_set_grid(LandLayer * self, LandGrid * grid) {
    self->grid = grid;
}
void land_layer_hide(LandLayer * self) {
    self->hidden = true;
}
void land_layer_unhide(LandLayer * self) {
    self->hidden = false;
}
LandMemoryPool* land_pool_new_initial(int initial) {
    LandMemoryPool * self;
    land_alloc(self);
    self->allocated = initial;
    self->memory = land_calloc(self->allocated);
    self->prev = self;
    return self;
}
LandMemoryPool* land_pool_new(void) {
    return land_pool_new_initial(1024);
}
void land_pool_destroy(LandMemoryPool * self) {
    LandMemoryPool * last = self->prev;
    while (1) {
        LandMemoryPool * prev = last->prev;
        land_free(last->memory);
        land_free(last);
        if (last == self) {
            break;
        }
        last = prev;
    }
}
void* land_pool_alloc(LandMemoryPool * self, int size) {
    LandMemoryPool * last = self->prev;
    while (last->used + size > last->allocated) {
        LandMemoryPool * another = land_pool_new_initial(last->allocated * 2);
        another->prev = last;
        self->prev = another;
        last = another;
    }
    void * p = last->memory + last->used;
    last->used += size;
    return p;
}
#ifdef LAND_MEMLOG
#undef land_list_new
#undef land_list_destroy
#undef land_add_list_data
LandList* land_list_new_memlog(char const * f, int l) {
    LandList * list = land_list_new();
    land_memory_add(list, "list", 1, f, l);
    return list;
}
void land_list_destroy_memlog(LandList * self, char const * f, int l) {
    land_memory_remove(self, "list", 1, f, l);
    land_list_destroy(self);
}
void land_add_list_data_memlog(LandList * (* list), void * data, char const * f, int l) {
    if (* list) {
        land_memory_remove(* list, "list", 1, f, l);
        land_add_list_data(list, data);
        land_memory_add(* list, "list", 1, f, l);
    }
    else {
        * list = land_list_new_memlog(f, l);
        land_add_list_data(list, data);
    }
}
#endif
LandListIterator LandListIterator_first(LandList * a) {
    LandListIterator i = {a->first};
    return i;
}
void* LandListIterator_item(LandList * a, LandListIterator * i) {
    return i->i ? i->i->data : NULL;
}
bool LandListIterator_next(LandList * a, LandListIterator * i) {
    if (i->i) {
        i->i = i->i->next;
        return 1;
    }
    return 0;
}
LandList* land_list_new(void) {
    LandList * self;
    land_alloc(self);
    return self;
}
void land_list_clear(LandList * list) {
    LandListItem * item = list->first;
    while (item) {
        LandListItem * next = item->next;
        land_listitem_destroy(item);
        item = next;
    }
    list->first = NULL;
    list->last = NULL;
    list->count = 0;
}
void land_list_destroy(LandList * list) {
    land_list_clear(list);
    land_free(list);
}
LandListItem* land_listitem_new(void * data) {
    LandListItem * self;
    land_alloc(self);
    self->data = data;
    return self;
}
void land_listitem_destroy(LandListItem * self) {
    land_free(self);
}
void land_list_insert_item(LandList * list, LandListItem * item) {
    item->next = NULL;
    item->prev = list->last;
    if (list->last) {
        list->last->next = item;
    }
    else {
        list->first = item;
    }
    list->last = item;
    list->count++;
}
void land_list_insert_item_before(LandList * list, LandListItem * insert, LandListItem * before) {
    if (before) {
        insert->next = before;
        insert->prev = before->prev;
        if (before->prev) {
            before->prev->next = insert;
        }
        else {
            list->first = insert;
        }
        before->prev = insert;
        list->count++;
    }
    else {
        land_list_insert_item(list, insert);
    }
}
void land_list_remove_item(LandList * list, LandListItem * item) {
    if (item->prev) {
        item->prev->next = item->next;
    }
    else {
        list->first = item->next;
    }
    if (item->next) {
        item->next->prev = item->prev;
    }
    else {
        list->last = item->prev;
    }
    list->count--;
}
void land_add_list_data(LandList * (* list), void * data) {
    LandListItem * item = land_listitem_new(data);
    if (! (* list)) {
        * list = land_list_new();
    }
    land_list_insert_item(* list, item);
}
void land_remove_list_data(LandList * (* list), void * data) {
    LandListItem * item = (* list)->first;
    while (item) {
        LandListItem * next = item->next;
        if (item->data == data) {
            land_list_remove_item(* list, item);
            land_listitem_destroy(item);
            return ;
        }
        item = next;
    }
}
static jmp_buf exception;
static char exception_string [1024];
int(* land_exception_handler)(char const * str);
static int init = 1;
int land_default_exception_handler(char const * str) {
    fprintf(stderr, "%s\n", str);
    return 1;
}
void land_exception_handler_init(void) {
    again:;
    if (setjmp(exception)) {
        int r = land_exception_handler(exception_string);
        if (! r) {
            goto again;
        }
        abort();
    }
}
void land_exception_handler_set(int(* handler)(char const * str)) {
    if (init) {
        land_exception_handler_init();
        init = 0;
    }
    land_exception_handler = handler;
}
void land_exception(char const * format, ...) {
    va_list args;
    va_start(args, format);
    vsnprintf(exception_string, 1024, format, args);
    va_end(args);
    fprintf(stderr, "%s", exception_string);
    int r = land_exception_handler(exception_string);
    if (r) {
        abort();
    }
}
#ifndef LAND_NO_NET
#ifdef WINDOWS
#include < winsock2.h>
#include < ws2tcpip>
#define SHUT_RDWR SD_BOTH
#else
#endif
#define D(_) _
#ifdef WINDOWS
static void cleanup(void) {
    WSACleanup();
}
static void sockerror(char const * name) {
    int err = WSAGetLastError();
    char const * what = "unknown";
    switch (err) {
        case WSAEINTR: {
            what = "WSAEINTR";
            break;
        }
        case WSAEBADF: {
            what = "WSAEBADF";
            break;
        }
        case WSAEACCES: {
            what = "WSAEACCES";
            break;
        }
        case WSAEFAULT: {
            what = "WSAEFAULT";
            break;
        }
        case WSAEINVAL: {
            what = "WSAEINVAL";
            break;
        }
        case WSAEMFILE: {
            what = "WSAEMFILE";
            break;
        }
        case WSAEWOULDBLOCK: {
            what = "WSAEWOULDBLOCK";
            break;
        }
        case WSAEINPROGRESS: {
            what = "WSAEINPROGRESS";
            break;
        }
        case WSAEALREADY: {
            what = "WSAEALREADY";
            break;
        }
        case WSAENOTSOCK: {
            what = "WSAENOTSOCK";
            break;
        }
    }
    fprintf(stderr, "%s: %s [%d]\n", name, what, err);
}
#else
#define closesocket close
#define sockerror perror
#endif
static int nonblocking(LandNet * self) {
    int r;
    #if defined(WINDOWS)
    u_long a = 1;
    r = ioctlsocket(self->sock, FIONBIO, & a);
    #else
    int a = 1;
    r = ioctl(self->sock, FIONBIO, & a);
    #endif
    if (r) {
        sockerror("ioctl");
        closesocket(self->sock);
        return - 1;
    }
    return 0;
}
static void split_address(char const * address, char * (* host), int * port) {
    char * colon = strrchr(address, ':');
    if (colon) {
        * host = land_calloc(colon - address + 1);
        strncpy(* host, address, colon - address);
        (* host) [colon - address] = '\0';
        * port = atoi(colon + 1);
    }
    else {
        * host = land_strdup(address);
        * port = 0;
    }
}
static void _get_address(struct sockaddr_in sock_addr, char * address) {
    if (sock_addr.sin_addr.s_addr == INADDR_ANY) {
        sprintf(address, "*.*.*.*");
    }
    else {
        char * ip = (char *) & sock_addr.sin_addr.s_addr;
        sprintf(address, "%d.%d.%d.%d", (unsigned char) ip [0], (unsigned char) ip [1], (unsigned char) ip [2], (unsigned char) ip [3]);
    }
    sprintf(address + strlen(address), ":%d", ntohs(sock_addr.sin_port));
}
char* land_net_get_address(LandNet * self, int remote) {
    /* Return either the local or remote address of the connection.
     */
    int s;
    static char address [256];
    struct sockaddr_in sock_addr;
    socklen_t addrlength = sizeof sock_addr;
    s = (remote ? getpeername : getsockname)(self->sock, (struct sockaddr *) & sock_addr, & addrlength);
    if (s == 0) {
        _get_address(sock_addr, address);
    }
    else {
        sprintf(address, "?:?");
    }
    return address;
}
LandNet* land_net_new(void) {
    LandNet * self;
    land_alloc(self);
    static int once = 1;
    if (once) {
        #ifdef WINDOWS
        WORD wVersionRequested;
        WSADATA wsaData;
        int err;
        wVersionRequested = MAKEWORD(1, 0);
        err = WSAStartup(wVersionRequested, & wsaData);
        if (err != 0) {
            return NULL;
        }
        land_exit_function(cleanup);
        #else
        struct sigaction sa;
        sigset_t mask;
        sigemptyset(& mask);
        sa.sa_handler = SIG_IGN;
        sa.sa_mask = mask;
        sa.sa_flags = 0;
        sigaction(SIGPIPE, & sa, NULL);
        #endif
        once = 0;
    }
    if ((self->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        sockerror("socket");
        return self;
    }
    nonblocking(self);
    return self;
}
void land_net_listen(LandNet * self, char const * address) {
    int r;
    struct sockaddr_in sock_address;
    char * host;
    int port;
    if (self->state != LAND_NET_INVALID) {
        return ;
    }
    self->local_address = land_strdup(address);
    split_address(address, & host, & port);
    struct hostent * hostinfo;
    if (! (hostinfo = gethostbyname(host))) {
        sockerror("gethostbyname");
        land_free(host);
        return ;
    }
    #ifdef WINDOWS
    char a = 1;
    #else
    int a = 1;
    #endif
    setsockopt(self->sock, IPPROTO_TCP, SO_REUSEADDR, & a, sizeof (a));
    sock_address.sin_family = AF_INET;
    sock_address.sin_addr = * (struct in_addr *) hostinfo->h_addr;
    sock_address.sin_port = htons(port);
    r = bind(self->sock, (struct sockaddr *) & sock_address, sizeof sock_address);
    if (r < 0) {
        sockerror("bind");
        land_free(host);
        return ;
    }
    r = listen(self->sock, SOMAXCONN);
    if (r < 0) {
        sockerror("listen");
        land_free(host);
        return ;
    }
    self->state = LAND_NET_LISTENING;
    D(land_log_message("Listening on host %s port %d (%s).\n", host, port, land_net_get_address(self, 0)));
    land_free(host);
}
static void land_net_poll_accept(LandNet * self) {
    int r;
    struct sockaddr_in address;
    socklen_t address_length = sizeof address;
    if (self->accepted) {
        return ;
    }
    r = accept(self->sock, (struct sockaddr *) & address, & address_length);
    if (r < 0) {
        #if defined(LINUX)
        if (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN) {
            return ;
        }
        #elif defined(WINDOWS)
        if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK) {
            return ;
        }
        #endif
        sockerror("accept");
        return ;
    }
    self->accepted = land_calloc(sizeof (* self->accepted));
    self->accepted->sock = r;
    nonblocking(self->accepted);
    self->accepted->state = LAND_NET_OK;
    D(land_log_message("Accepted connection (%s ->", land_net_get_address(self->accepted, 0)));
    D(land_log_message_nostamp(" %s).\n", land_net_get_address(self->accepted, 1)));
}
LandNet* land_net_accept(LandNet * self) {
    if (self->state == LAND_NET_LISTENING && self->accepted) {
        LandNet * accepted = self->accepted;
        self->accepted = NULL;
        return accepted;
    }
    return NULL;
}
void land_net_connect(LandNet * self, char const * address) {
    struct sockaddr_in sock_address;
    char * host;
    int port;
    struct hostent * hostinfo;
    if (self->state != LAND_NET_INVALID) {
        return ;
    }
    self->remote_address = land_strdup(address);
    split_address(address, & host, & port);
    if (! (hostinfo = gethostbyname(host))) {
        sockerror("gethostbyname");
        land_free(host);
        return ;
    }
    sock_address.sin_family = AF_INET;
    sock_address.sin_addr = * (struct in_addr *) hostinfo->h_addr;
    sock_address.sin_port = htons(port);
    if (connect(self->sock, (struct sockaddr *) & sock_address, sizeof sock_address)) {
        bool err;
        #if defined(WINDOWS)
        err = WSAGetLastError() != WSAEINPROGRESS && WSAGetLastError() != WSAEWOULDBLOCK;
        #else
        err = errno != EINPROGRESS;
        #endif
        if (err) {
            sockerror("connect");
            closesocket(self->sock);
            land_free(host);
            return ;
        }
    }
    self->state = LAND_NET_CONNECTING;
    D(land_log_message("Connecting to host %s port %d (from %s).\n", host, port, land_net_get_address(self, 0)));
    land_free(host);
}
static void land_net_poll_connect(LandNet * self) {
    int r;
    struct timeval tv;
    fd_set ds;
    FD_ZERO(& ds);
    FD_SET((unsigned) self->sock, & ds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    r = select(FD_SETSIZE, NULL, & ds, NULL, & tv);
    if (r > 0) {
        #ifdef WINDOWS
        char a;
        int as = sizeof a;
        #else
        socklen_t a, as = sizeof a;
        #endif
        if (getsockopt(self->sock, SOL_SOCKET, SO_ERROR, & a, & as) == 0) {
            if (a != 0) {
                errno = a;
                self->state = LAND_NET_INVALID;
                sockerror("select(connect)");
                return ;
            }
        }
        self->state = LAND_NET_OK;
        D(land_log_message("Connected (%s ->", land_net_get_address(self, 0)));
        D(land_log_message_nostamp(" %s).\n", land_net_get_address(self, 1)));
        return ;
    }
    bool err;
    #if defined WINDOWS
    err = WSAGetLastError() != WSAEINTR;
    #else
    err = r < 0 && errno != EINTR;
    #endif
    if (err) {
        sockerror("select");
        closesocket(self->sock);
        return ;
    }
}
#ifdef DEBUG_BYTES
static void debug_packet(char const * buffer, int size) {
    land_log_message("Sent %d bytes: ", size);
    int i;
    for (i = 0; i < size; i++) {
        int c = (unsigned char) buffer [i];
        land_log_message_nostamp("%d[%c],", c, c >= 32 && c <= 127 ? c : '.');
    }
    land_log_message_nostamp("\n");
}
#endif
struct LagSimulator {
    int ringpos;
    int ringpos2;
    char packets [256 * 256];
    int size [256];
    double t [256];
    double delay;
    double jitter;
};
static LagSimulator* lag_simulator_new(double delay, double jitter) {
    LagSimulator * self;
    land_alloc(self);
    self->delay = delay;
    self->jitter = jitter;
    return self;
}
static void lag_simulator_add(LandNet * net, char const * packet, int size) {
    LagSimulator * self = net->lag_simulator;
    double t = land_get_time();
    if (packet) {
        memcpy(self->packets + self->ringpos * 256, packet, size);
        self->size [self->ringpos] = size;
        self->t [self->ringpos] = t + land_rnd(- self->jitter, self->jitter);
        self->ringpos++;
        if (self->ringpos == 256) {
            self->ringpos = 0;
        }
    }
    while (self->ringpos2 != self->ringpos) {
        int i = self->ringpos2;
        if (t >= self->t [i] + self->delay) {
            self->ringpos2++;
            if (self->ringpos2 == 256) {
                self->ringpos2 = 0;
            }
            net->lag_simulator = NULL;
            packet = self->packets + i * 256;
            size = self->size [i];
            land_net_send(net, packet, size);
            net->lag_simulator = self;
        }
        else {
            break;
        }
    }
}
void land_net_lag_simulator(LandNet * self, double delay, double jitter) {
    self->lag_simulator = lag_simulator_new(delay, jitter);
}
void land_net_limit_receive_rate(LandNet * self, int rate) {
    self->max_rate = rate;
}
static int _create_datagram_socket(LandNet * self) {
    if (! self->sockd) {
        int r;
        r = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (r >= 0) {
            self->sockd = r;
        }
        else {
            return 1;
        }
        #if defined(WINDOWS)
        u_long b = 1;
        r = ioctlsocket(self->sockd, FIONBIO, & b);
        #else
        int b = 1;
        r = ioctl(self->sockd, FIONBIO, & b);
        #endif
        if (r < 0) {
            sockerror("ioctl");
        }
        #ifdef WINDOWS
        char a = 1;
        #else
        int a = 1;
        #endif
        r = setsockopt(self->sockd, SOL_SOCKET, SO_BROADCAST, & a, sizeof (a));
        if (r < 0) {
            sockerror("setsockopt");
        }
    }
    return 0;
}
static int _send_datagram(LandNet * self, char const * address, char const * packet, int size) {
    char * host;
    int port;
    split_address(address, & host, & port);
    struct hostent * hostinfo = gethostbyname(host);
    if (! hostinfo) {
        land_free(host);
        return 0;
    }
    struct sockaddr_in sock_address;
    sock_address.sin_family = AF_INET;
    sock_address.sin_addr = * (struct in_addr *) hostinfo->h_addr;
    sock_address.sin_port = htons(port);
    int r = sendto(self->sockd, packet, size, 0, (struct sockaddr *) & sock_address, sizeof sock_address);
    land_free(host);
    return r;
}
int land_net_send_datagram(LandNet * self, char const * address, char const * packet, int size) {
    /* [experimental]
     * This is to directly send a datagram to some address. This is an experimental
     * feature and for now, you should use land_net_send when possible.
     */
    _create_datagram_socket(self);
    return _send_datagram(self, address, packet, size);
}
int land_net_recv_datagram(LandNet * self, int port, char * (* address), char * packet, int size) {
    /* [experimental]
     * Receives a datagram. Returns the number of received bytes (less than or
     * equal to size), or 0 if there's no datagram to be received. If address is
     * not None and the return value is > 0, it will point to a static buffer
     * containing the source address. (If you need that address for anything,
     * copy it to your own buffer immediately.)
     */
    _create_datagram_socket(self);
    if (port) {
        struct sockaddr_in laddr;
        laddr.sin_family = AF_INET;
        laddr.sin_port = htons(port);
        laddr.sin_addr.s_addr = INADDR_ANY;
        bind(self->sockd, (struct sockaddr *) & laddr, sizeof laddr);
    }
    struct sockaddr_in sock_address;
    socklen_t addrsize = sizeof sock_address;
    int r = recvfrom(self->sockd, packet, size, 0, (struct sockaddr *) & sock_address, & addrsize);
    if (r > 0) {
        if (address) {
            static char static_address [256];
            _get_address(sock_address, static_address);
            * address = static_address;
        }
        return r;
    }
    return 0;
}
void land_net_send(LandNet * self, char const * buffer, size_t size) {
    size_t bytes = 0;
    int r = 0;
    if (self->state != LAND_NET_OK) {
        return ;
    }
    if (self->lag_simulator) {
        lag_simulator_add(self, buffer, size);
        return ;
    }
    while (1) {
        r = send(self->sock, buffer + bytes, size - bytes, 0);
        if (r < 0) {
            #if defined WINDOWS
            if (WSAGetLastError() == WSAEINTR || WSAGetLastError() == WSAEWOULDBLOCK) {
                r = 0;
            }
            else {
                sockerror("send");
                return ;
            }
            #else
            if (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN) {
                r = 0;
            }
            else {
                sockerror("send");
                return ;
            }
            #endif
        }
        bytes += r;
        if (bytes < size) {
            continue;
        }
        break;
    }
    #ifdef DEBUG_BYTES
    debug_packet(buffer, size);
    #endif
}
void land_net_buffer(LandNet * self, char * buffer, size_t size) {
    /* Assign a networking buffer to use. This buffer keeps being owned by you,
     * Land will never delete it on its own.
     */
    self->buffer = buffer;
    self->size = size;
    self->full = 0;
}
void land_net_flush(LandNet * self, size_t size) {
    if (size == 0) {
        self->full = 0;
    }
    else {
        if (self->full >= size) {
            memmove(self->buffer, self->buffer + size, self->full - size);
        }
        self->full -= size;
    }
}
static void land_net_poll_recv(LandNet * self) {
    int r;
    if (self->size == 0 || self->full == self->size) {
        return ;
    }
    int _scramble_max = self->size - self->full;
    if (self->max_rate) {
        double t = land_get_time();
        double dt = t - self->timestamp;
        if (dt > 1) {
            dt = 1;
        }
        if (_scramble_max > self->max_rate * dt) {
            _scramble_max = self->max_rate * dt;
        }
        self->timestamp = t;
        if (_scramble_max == 0) {
            return ;
        }
    }
    r = recv(self->sock, self->buffer + self->full, _scramble_max, 0);
    if (r < 0) {
        #if defined WINDOWS
        bool err = WSAGetLastError() != WSAEINTR && WSAGetLastError() != WSAEWOULDBLOCK;
        #else
        bool err = errno != EINTR && errno != EWOULDBLOCK && errno != EAGAIN;
        #endif
        if (err) {
            sockerror("recv");
            return ;
        }
        return ;
    }
    if (r == 0) {
        self->state = LAND_NET_INVALID;
    }
    self->full += r;
    #ifdef DEBUG_BYTES
    land_log_message("Received %d bytes: ", r);
    int i;
    for (i = 0; i < r; i++) {
        int c = (unsigned char) self->buffer [self->full - r + i];
        land_log_message_nostamp("%d[%c],", c, c >= 32 && c <= 128 ? c : '.');
    }
    land_log_message_nostamp("\n");
    #endif
}
void land_net_disconnect(LandNet * self) {
    if (self->state == LAND_NET_INVALID) {
        return ;
    }
    if (shutdown(self->sock, SHUT_RDWR)) {
        sockerror("shutdown");
        return ;
    }
    self->state = LAND_NET_INVALID;
}
void land_net_del(LandNet * self) {
    /* Deletes a connection. Make sure to reclaim any buffers you have assigned
     * to it first.
     */
    land_net_disconnect(self);
    if (closesocket(self->sock)) {
        sockerror("close");
    }
    if (self->local_address) {
        land_free(self->local_address);
    }
    if (self->remote_address) {
        land_free(self->remote_address);
    }
    land_free(self);
}
void land_net_poll(LandNet * self) {
    switch ((self->state)) {
        case LAND_NET_INVALID: {
            break;
        }
        case LAND_NET_LISTENING: {
            land_net_poll_accept(self);
            break;
        }
        case LAND_NET_CONNECTING: {
            land_net_poll_connect(self);
            break;
        }
        case LAND_NET_OK: {
            if (self->lag_simulator) {
                lag_simulator_add(self, NULL, 0);
            }
            land_net_poll_recv(self);
            break;
        }
    }
}
#endif
#undef SHUT_RDWR
#undef D
#undef closesocket
#undef sockerror
LandQueue* land_queue_new(int(* cmp_cb)(void * data1, void * data2)) {
    /* Create a new queue, with the given comparison function for its elements.
     */
    LandQueue * self;
    land_alloc(self);
    self->array.data = NULL;
    self->cmp_cb = cmp_cb;
    return self;
}
void land_queue_del(LandQueue * q) {
    /* Delete the queue. This will not touch the elements that might have been
     * added since its creation.
     */
    land_free(q->array.data);
    land_free(q);
}
void land_queue_destroy(LandQueue * q) {
    land_queue_del(q);
}
void land_queue_add(LandQueue * q, void * data) {
    /* Add an element to the queue.
     */
    int i = q->array.count;
    land_array_add(& q->array, data);
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (q->cmp_cb(q->array.data [parent], q->array.data [i]) <= 0) {
            break;
        }
        void * temp = q->array.data [parent];
        q->array.data [parent] = q->array.data [i];
        q->array.data [i] = temp;
        i = parent;
    }
}
void* land_queue_pop(LandQueue * q) {
    /* Return and remove the smallest element in the queue.
     */
    if (q->array.count == 0) {
        return NULL;
    }
    void * data = q->array.data [0];
    q->array.data [0] = q->array.data [q->array.count - 1];
    land_array_pop(& q->array);
    int i = 0;
    while (1) {
        int child1 = i * 2 + 1;
        int child2 = i * 2 + 2;
        if ((child1 >= q->array.count || q->cmp_cb(q->array.data [child1], q->array.data [i]) >= 0) && (child2 >= q->array.count || q->cmp_cb(q->array.data [child2], q->array.data [i]) >= 0)) {
            break;
        }
        if (child2 >= q->array.count || (child1 < q->array.count && q->cmp_cb(q->array.data [child1], q->array.data [child2]) < 0)) {
            void * temp = q->array.data [i];
            q->array.data [i] = q->array.data [child1];
            q->array.data [child1] = temp;
            i = child1;
        }
        else {
            void * temp = q->array.data [i];
            q->array.data [i] = q->array.data [child2];
            q->array.data [child2] = temp;
            i = child2;
        }
    }
    return data;
}
LandArray* land_queue_sort(LandQueue * q) {
    /* Return an array referencing the same data as the queue. The array will be
     * sorted from smallest to largest element. The queue will be destroyed in
     * the process. So you should set the parameter you passed to this function to
     * None after it returns.
     */
    LandArray * a = land_array_new();
    while (1) {
        void * data = land_queue_pop(q);
        if (! data) {
            break;
        }
        land_array_add(a, data);
    }
    land_queue_del(q);
    return a;
}
int land_queue_for_each(LandQueue * self, int(* cb)(void * item, void * data), void * data) {
    /* Like land_array_for_each. The callback will not be called in any particular
     * order, especially it will *not* be sorted. (The first call will be the
     * smallest element, but the subsequent order is random.)
     */
    return land_array_for_each(& self->array, cb, data);
}
int land_queue_count(LandQueue * self) {
    return self->array.count;
}
void land_queue_clear(LandQueue * self) {
    land_array_clear(& self->array);
}
static int active;
LandSound* land_sound_load(char const * filename) {
    LandSound * sound = platform_sound_load(filename);
    return sound;
}
LandSound* land_sound_new(int samples, float frequency, int bits, int channels) {
    LandSound * sound = platform_sound_new(samples, frequency, bits, channels);
    return sound;
}
void* land_sound_sample_pointer(LandSound * self) {
    return platform_sound_sample_pointer(self);
}
int land_sound_length(LandSound * self) {
    return platform_sound_length(self);
}
double land_sound_seconds(LandSound * self) {
    return platform_sound_seconds(self);
}
void land_sound_play(LandSound * s, float volume, float pan, float frequency) {
    if (! s) {
        return ;
    }
    platform_sound_play(s, volume, pan, frequency, false);
}
void land_sound_loop(LandSound * s, float volume, float pan, float frequency) {
    if (! s) {
        return ;
    }
    platform_sound_play(s, volume, pan, frequency, true);
}
void land_sound_stop(LandSound * s) {
    if (! s) {
        return ;
    }
    platform_sound_stop(s);
}
void land_sound_destroy(LandSound * s) {
    if (! s) {
        return ;
    }
    platform_sound_destroy(s);
}
void land_sound_init(void) {
    platform_sound_init();
    active = 1;
}
void land_sound_exit(void) {
    platform_sound_exit();
    active = 0;
}
LandStream* land_stream_new(int samples, int fragments, float frequency, int bits, int channels) {
    return platform_stream_new(samples, fragments, frequency, bits, channels);
}
void land_stream_destroy(LandStream * self) {
    platform_stream_destroy(self);
}
void* land_stream_buffer(LandStream * self) {
    return platform_stream_buffer(self);
}
void land_stream_fill(LandStream * self) {
    platform_stream_fill(self);
}
void land_stream_music(LandStream * self, char const * filename) {
    self->filename = land_strdup(filename);
    platform_stream_music(self, filename);
}
void land_stream_volume(LandStream * self, float volume) {
    platform_stream_volume(self, volume);
}
bool land_stream_is_playing(LandStream * self) {
    return platform_stream_is_playing(self);
}
void land_stream_set_playing(LandStream * self, bool onoff) {
    platform_stream_set_playing(self, onoff);
}
LandAnimation* land_animation_new(LandArray * frames) {
    /* Ownership of the frames array is transferred to the animation - destroying
     * the animation later will destroy the array.
     */
    LandAnimation * self;
    land_alloc(self);
    self->fps = 10;
    self->frames = frames;
    return self;
}
void land_animation_destroy(LandAnimation * self) {
    int i;
    if (self->frames) {
        for (i = 0; i < self->frames->count; i++) {
            land_image_destroy(land_array_get_nth(self->frames, i));
        }
        land_array_destroy(self->frames);
    }
    land_free(self);
}
LandImage* land_animation_get_frame(LandAnimation * self, int i) {
    return land_array_get_nth(self->frames, i);
}
int land_animation_length(LandAnimation * self) {
    if (self->frames) {
        return land_array_count(self->frames);
    }
    return 0;
}
void land_animation_add_frame(LandAnimation * self, LandImage * frame) {
    if (! self->frames) {
        self->frames = land_array_new();
    }
    land_array_add(self->frames, frame);
}
LandAnimation* land_animation_load_cb(char const * pattern, void(* cb)(LandImage * image, void * data), void * data) {
    /* Create a new animation from all files matching the pattern, sorted
     * alphabetically. The callback function, if present, is called on each
     * frame.
     */
    LandArray * pics = land_load_images_cb(pattern, cb, data);
    if (! pics) {
        land_log_message("Could not locate: %s\n", pattern);
        return NULL;
    }
    return land_animation_new(pics);
}
void land_animation_draw_frame(LandAnimation * self, int i, float x, float y) {
    LandImage * frame = land_animation_get_frame(self, i);
    land_image_draw(frame, x, y);
}
void land_animation_draw_frame_rotated(LandAnimation * self, int i, float x, float y, float angle) {
    LandImage * frame = land_animation_get_frame(self, i);
    land_image_draw_rotated(frame, x, y, angle);
}
void land_animation_draw_frame_scaled_rotated(LandAnimation * self, int i, float x, float y, float xs, float ys, float angle) {
    LandImage * frame = land_animation_get_frame(self, i);
    land_image_draw_scaled_rotated(frame, x, y, xs, ys, angle);
}
#ifdef ANDROID
#include "android/log.h"
#endif
static char * logname = NULL;
void land_log_overwrite(char const * name) {
    FILE * f;
    if (logname) {
        land_free(logname);
    }
    logname = land_strdup(name);
    f = fopen(logname, "w");
    if (f) {
        fclose(f);
    }
}
void land_log_set(char const * name) {
    if (logname) {
        land_free(logname);
    }
    logname = land_strdup(name);
}
void land_log_del(void) {
    if (logname) {
        land_free(logname);
    }
    logname = NULL;
}
void land_log_new(char const * base, int unique) {
    static int once = 0;
    if (logname) {
        land_free(logname);
    }
    logname = land_malloc(strlen(base) + 10);
    if (! once) {
        atexit(land_log_del);
        once++;
    }
    #ifdef ANDROID
    sprintf(logname, "%s.log", base);
    __android_log_print(ANDROID_LOG_INFO, "land", "%s", "******* new log *******\n");
    #else
    FILE * f;
    int i = 0;
    if (unique) {
        while (1) {
            sprintf(logname, "%s%04d.log", base, i);
            f = fopen(logname, "r");
            if (f) {
                fclose(f);
            }
            i++;
            if (! f) {
                break;
            }
        }
    }
    else {
        sprintf(logname, "%s.log", base);
    }
    f = fopen(logname, "w");
    if (f) {
        fprintf(f, "******* new log *******\n");
        fclose(f);
    }
    #endif
}
void land_log_message_nostamp(char const * format, ...) {
    if (! logname) {
        land_log_new("land", 0);
    }
    va_list va_args;
    va_start(va_args, format);
    #ifdef ANDROID
    char s [16382];
    vsprintf(s, format, va_args);
    __android_log_print(ANDROID_LOG_INFO, "land", "%s", s);
    #else
    FILE * logfile = fopen(logname, "a");
    vfprintf(logfile, format, va_args);
    fclose(logfile);
    #endif
    va_end(va_args);
}
void land_log_message(char const * format, ...) {
    if (! logname) {
        land_log_new("land", 0);
    }
    va_list va_args;
    va_start(va_args, format);
    #ifdef ANDROID
    char s [16382];
    vsprintf(s, format, va_args);
    __android_log_print(ANDROID_LOG_INFO, "land", "%s", s);
    #else
    struct timeval tv;
    #ifdef WINDOWS
    tv.tv_usec = 0;
    #else
    gettimeofday(& tv, NULL);
    #endif
    time_t t;
    struct tm tm;
    time(& t);
    tm = * gmtime(& t);
    FILE * logfile = fopen(logname, "a");
    fprintf(logfile, "%04d/%02d/%02d %02d:%02d:%02d.%06ld ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tv.tv_usec);
    vfprintf(logfile, format, va_args);
    fclose(logfile);
    #endif
    va_end(va_args);
}
LandDataFile * _land_datafile;
static int read32(FILE * f) {
    unsigned int u = fgetc(f);
    u += fgetc(f) << 8;
    u += fgetc(f) << 16;
    u += fgetc(f) << 24;
    return u;
}
LandDataFile* land_read_datafile(FILE * file) {
    LandDataFile * self;
    land_alloc(self);
    self->file = file;
    int count = read32(self->file);
    int i;
    char name [1024];
    land_log_message("Data listing:\n");
    for (i = 0; i < count; i++) {
        int s = 0;
        while (s < 1024) {
            int c = fgetc(self->file);
            name [s++] = c;
            if (c == '\0') {
                break;
            }
        }
        LandDataEntry * entry;
        land_alloc(entry);
        entry->name = land_strdup(name);
        entry->offset = read32(self->file);
        entry->size = read32(self->file);
        land_array_add_data(& self->entries, entry);
        land_log_message(" %8d %8d %s\n", entry->offset, entry->size, entry->name);
    }
    return self;
}
LandDataFile* land_open_datafile(char const * filename) {
    FILE * file = fopen(filename, "rb");
    if (! file) {
        return NULL;
    }
    return land_read_datafile(file);
}
LandDataFile* land_open_appended_datafile(char const * filename, char const * marker) {
    FILE * file = fopen(filename, "rb");
    if (! file) {
        return NULL;
    }
    fseek(file, - 4, SEEK_END);
    int size = read32(file);
    land_log_message("Embedded data size: %d\n", size);
    fseek(file, - size - strlen(marker), SEEK_END);
    int i;
    for (i = 0; i < (int) strlen(marker); i++) {
        if (fgetc(file) != marker [i]) {
            fclose(file);
            return NULL;
        }
    }
    int offset = ftell(file);
    LandDataFile * data = land_read_datafile(file);
    for (i = 0; i < data->entries->count; i++) {
        LandDataEntry * entry = land_array_get_nth(data->entries, i);
        entry->offset += offset;
    }
    return data;
}
void* land_datafile_read_entry(LandDataFile * self, char const * filename, int * size) {
    int i;
    for (i = 0; i < self->entries->count; i++) {
        LandDataEntry * entry = land_array_get_nth(self->entries, i);
        if (! strcmp(entry->name, filename)) {
            fseek(self->file, entry->offset, 0);
            unsigned char * buffer = land_calloc(entry->size);
            int r = fread(buffer, entry->size, 1, self->file);
            entry->size = r;
            if (size) {
                * size = entry->size;
            }
            return buffer;
        }
    }
    return NULL;
}
static int star_match(char const * pattern, char const * name) {
    int i = 0;
    int j = 0;
    while (1) {
        char c = pattern [i];
        char d = name [j];
        if (c == '*') {
            int k;
            if (pattern [i + 1] == '\0') {
                return 1;
            }
            for (k = j; k < (int) strlen(name); k++) {
                int r = star_match(pattern + i + 1, name + k);
                if (r) {
                    return r;
                }
            }
            return 0;
        }
        else if (c == '?') {
            ;
        }
        else if (c != d) {
            return 0;
        }
        if (c == '\0') {
            return 1;
        }
        i++;
        j++;
    }
}
int land_datafile_for_each_entry(LandDataFile * self, char const * pattern, int(* callback)(const char * filename, int attrib, void * param), void * param) {
    int i;
    int n = 0;
    for (i = 0; i < self->entries->count; i++) {
        LandDataEntry * entry = land_array_get_nth(self->entries, i);
        if (star_match(pattern, entry->name)) {
            if (callback(entry->name, 0, param)) {
                break;
            }
            n++;
        }
    }
    return n;
}
void land_set_datafile(LandDataFile * datafile) {
    _land_datafile = datafile;
}
LandDataFile* land_get_datafile(void) {
    return _land_datafile;
}
float land_norm2d(float x, float y) {
    return sqrt(x * x + y * y);
}
float land_dot2d(float ax, float ay, float bx, float by) {
    /* Given two vectors ax/ay and bx/by, returns the dot product.
     * If the result is 0, the two vectors are orthogonal. If the result is
     * > 0, they point into the same general direction. If the result is < 0,
     * they point into opposite directions.
     * This can be geometrically interpreted as "how far one vector goes along the
     * direction of the other vector".
     * For example, if we have two vectors a = (4, -3) and b = (4, 0). Then:
     * |a| = 5
     * |b| = 4
     * a.b = 16
     * cos = a.b / |a| / |b| = 0.8 (36.87°)
     * length of a projected onto b: a.b / |b| = 4
     * length of b projected onto a: a.b / |a| = 3.2
     */
    return ax * bx + ay * by;
}
float land_cross2d(float ax, float ay, float bx, float by) {
    /* Given two vectors ax/ay and bx/by, returns the cross product.
     * If the result is 0, the two vectors are parallel. If the result
     * is > 0, b points more to the left than a (if y goes up). If the
     * result is < 0, b points more to the right than a (if y goes up).
     * Geometrically, this is "how far away does one vector go from the other".
     * For example, if we have two vectors a = (4, -3) and b = (4, 0). Then:
     * |a| = 5
     * |b| = 4
     * axb = 4 * 0 - -3 * 4 = 12
     * sin = axb / |a| / |b| = 0.6 (36.87°)
     * distance of a from b: axb / |b| = 3
     * distance of b from a: axb / |a| = 2.4
     */
    return ax * by - ay * bx;
}
void land_ortho2d(float ax, float ay, float * bx, float * by) {
    /* Returns a vector orthogonal to ax/ay. More specifically, returns a
     * vector rotated 90 degree to the right (with y axis going down).
     */
    * bx = - ay;
    * by = ax;
}
bool land_line_line_collision2d(float l1x1, float l1y1, float l1x2, float l1y2, float l2x1, float l2y1, float l2x2, float l2y2) {
    /* Checks if two line segments collide.
     */
    float ax = l1x2 - l1x1;
    float ay = l1y2 - l1y1;
    float bx = l2x2 - l2x1;
    float by = l2y2 - l2y1;
    float cx = l2x1 - l1x1;
    float cy = l2y1 - l1y1;
    float ab = land_cross2d(ax, ay, bx, by);
    float ca = land_cross2d(cx, cy, ax, ay);
    float cb = land_cross2d(cx, cy, bx, by);
    if (ab == 0) {
        return 0;
    }
    if (ab < 0) {
        if (ca > 0 || cb > 0) {
            return 0;
        }
        if (ca < ab || cb < ab) {
            return 0;
        }
    }
    else {
        if (ca < 0 || cb < 0) {
            return 0;
        }
        if (ca > ab || cb > ab) {
            return 0;
        }
    }
    return 1;
}
enum LandWidgetThemeFlags {
    TILE_H=0,
    TILE_V=0,
    STRETCH_H=1,
    STRETCH_V=2,
    CENTER_H=4,
    CENTER_V=8,
    ALIGN_H=16,
    ALIGN_V=32
};
static LandWidgetTheme * default_theme;
LandWidgetTheme* land_widget_theme_default(void) {
    return default_theme;
}
void land_widget_theme_set_default(LandWidgetTheme * self) {
    default_theme = self;
}
static inline int centered_offset(int size1, int size2) {
    int center1, center2, o;
    if (! size1 || ! size2) {
        return 0;
    }
    center1 = size1 / 2;
    center2 = size2 / 2;
    o = (center1 - center2) % size2;
    if (o > 0) {
        o -= size2;
    }
    return o;
}
static inline void _masked_non_stretched_blit(LandImage * s, int sx, int sy, int w, int h, int dx, int dy, int _, int __) {
    land_image_clip(s, sx, sy, sx + w, sy + h);
    land_image_draw(s, dx - sx, dy - sy);
}
static inline void _masked_stretched_blit(LandImage * s, int sx, int sy, int w, int h, int dx, int dy, int dw, int dh) {
    land_image_clip(s, sx, sy, sx + w, sy + h);
    land_image_draw_scaled(s, dx - sx, dy - sy, (float) dw / w, (float) dh / h);
}
enum COLUMN_TYPE {
    COLUMN_CENTER=1,
    COLUMN_STRETCH,
    COLUMN_LEFT,
    COLUMN_MIDDLE,
    COLUMN_RIGHT
};
static inline void blit_column(LandWidgetThemeElement * pat, int bx, int bw, int x, int y, int w, int h, int skip_middle) {
    int oy;
    int j;
    int bh = land_image_height(pat->bmp);
    int bm = bh - pat->bt - pat->bb;
    void(* bfunc)(LandImage *, int, int, int, int, int, int, int, int);
    bfunc = _masked_non_stretched_blit;
    if (bm < 1) {
        return ;
    }
    if (pat->flags & ALIGN_V) {
        oy = (y / bm) * bm - y;
    }
    else {
        oy = centered_offset(h, bm);
    }
    if (w != bw) {
        bfunc = _masked_stretched_blit;
    }
    if (pat->flags & CENTER_V) {
        bfunc(pat->bmp, bx, 0, bw, land_image_height(pat->bmp), x, y + h / 2 - land_image_height(pat->bmp) / 2, w, land_image_height(pat->bmp));
    }
    else if (pat->flags & STRETCH_V) {
        _masked_stretched_blit(pat->bmp, bx, 0, bw, land_image_height(pat->bmp), x, y, w, h);
    }
    else {
        int bt = pat->bt;
        int bb = pat->bb;
        if (bt + bb > h) {
            bt = h / 2;
            bb = h - bt;
        }
        if (bt && y + bt >= _land_active_display->clip_y1) {
            land_clip_push();
            land_clip_intersect(0, y, land_display_width(), _scramble_min(y + h, y + bt));
            bfunc(pat->bmp, bx, 0, bw, bt, x, y, w, bt);
            land_clip_pop();
        }
        if (h - pat->bt - pat->bb > 0 && ! skip_middle) {
            land_clip_push();
            land_clip_intersect(0, _scramble_min(y + h, y + pat->bt), land_display_width(), _scramble_max(y, y + h - pat->bb));
            int start = _scramble_max(0, (_land_active_display->clip_y1 - (y + oy)) / bm);
            start = y + oy + start * bm;
            int end = _scramble_min(_land_active_display->clip_y2, y + h);
            for (j = start; j < end; j += bm) {
                bfunc(pat->bmp, bx, pat->bt, bw, bm, x, j, w, bm);
            }
            land_clip_pop();
        }
        if (bb && y + h - bb < _land_active_display->clip_y2) {
            land_clip_push();
            land_clip_intersect(0, _scramble_max(y, y + h - bb), land_display_width(), y + h);
            bfunc(pat->bmp, bx, land_image_height(pat->bmp) - bb, bw, bb, x, y + h - bb, w, bb);
            land_clip_pop();
        }
    }
}
static void draw_bitmap(LandWidgetThemeElement * pat, int x, int y, int w, int h, int skip_middle) {
    int i;
    int bw = land_image_width(pat->bmp);
    int bm = bw - pat->bl - pat->br;
    if (w < 1 || h < 1 || bm < 1) {
        return ;
    }
    land_clip_push();
    land_clip_intersect(x, y, x + w, y + h);
    if (pat->flags & CENTER_H) {
        blit_column(pat, 0, bw, x + w / 2 - bw / 2, y, bw, h, 0);
    }
    else if (pat->flags & STRETCH_H) {
        blit_column(pat, 0, bw, x, y, w, h, 0);
    }
    else {
        int ox;
        if (pat->flags & ALIGN_H) {
            ox = (x / bm) * bm - x;
        }
        else {
            ox = centered_offset(w, bm);
        }
        int bl = pat->bl;
        int br = pat->br;
        if (bl + br > w) {
            bl = w / 2;
            br = w - bl;
        }
        if (bl && x + bl >= _land_active_display->clip_x1) {
            land_clip_push();
            land_clip_intersect(x, 0, _scramble_min(x + w, x + bl), land_display_height());
            blit_column(pat, 0, bl, x, y, bl, h, 0);
            land_clip_pop();
        }
        if (w - pat->bl - pat->br > 0) {
            land_clip_push();
            land_clip_intersect(_scramble_min(x + w, x + pat->bl), 0, _scramble_max(x, x + w - pat->br), land_display_height());
            int start = _scramble_max(0, (_land_active_display->clip_x1 - (x + ox)) / bm);
            start = x + ox + start * bm;
            int end = _scramble_min(_land_active_display->clip_x2, x + w - pat->br);
            for (i = start; i < end; i += bm) {
                blit_column(pat, pat->bl, bm, i, y, bm, h, skip_middle);
            }
            land_clip_pop();
        }
        if (br && x + w - br < _land_active_display->clip_x2) {
            land_clip_push();
            land_clip_intersect(_scramble_max(x, x + w - br), 0, x + w, land_display_height());
            blit_column(pat, bw - br, br, x + w - br, y, br, h, 0);
            land_clip_pop();
        }
    }
    land_clip_pop();
}
static void read_int_arg(int argc, LandArray * argv, int * a, int * val) {
    (* a)++;
    if (* a < argc) {
        LandBuffer * buf = land_array_get_nth(argv, * a);
        char * arg = land_buffer_finish(buf);
        * val = strtoul(arg, NULL, 0);
        land_free(arg);
    }
}
LandWidgetThemeElement* land_widget_theme_element_new(struct LandWidgetTheme * theme, char const * name, char const * argline) {
    LandWidgetThemeElement * self;
    land_alloc(self);
    self->name = land_strdup(name);
    self->a = 1;
    self->minw = 4;
    self->minh = 4;
    self->font = land_font_current();
    self->theme = theme;
    LandBuffer * argbuf = land_buffer_new();
    land_buffer_cat(argbuf, argline);
    land_buffer_strip(argbuf, " ");
    LandArray * argv = land_buffer_split(argbuf, ' ');
    land_buffer_del(argbuf);
    int argc = land_array_count(argv);
    LandImage * img = NULL;
    if (argc) {
        char iname [2048];
        LandBuffer * buf = land_array_get_nth(argv, 0);
        char * arg = land_buffer_finish(buf);
        snprintf(iname, sizeof iname, "%s%s%s", theme->prefix, arg, theme->suffix);
        land_free(arg);
        img = land_image_load(iname);
        if (img) {
            for (int a = 1; a < argc; a++) {
                buf = land_array_get_nth(argv, a);
                arg = land_buffer_finish(buf);
                if (! strcmp(arg, "cut")) {
                    int cx = 0, cy = 0, cw = 0, ch = 0;
                    read_int_arg(argc, argv, & a, & cx);
                    read_int_arg(argc, argv, & a, & cy);
                    read_int_arg(argc, argv, & a, & cw);
                    read_int_arg(argc, argv, & a, & ch);
                    if (cw <= 0) {
                        cw += land_image_width(img);
                    }
                    if (ch <= 0) {
                        ch += land_image_height(img);
                    }
                    self->bmp = land_image_new_from(img, cx, cy, cw, ch);
                }
                else if (! strcmp(arg, "halign")) {
                    self->flags |= ALIGN_H;
                }
                else if ((! strcmp(arg, "valign"))) {
                    self->flags |= ALIGN_V;
                }
                else if ((! strcmp(arg, "min"))) {
                    read_int_arg(argc, argv, & a, & self->minw);
                    read_int_arg(argc, argv, & a, & self->minh);
                }
                else if ((! strcmp(arg, "border"))) {
                    read_int_arg(argc, argv, & a, & self->bl);
                    read_int_arg(argc, argv, & a, & self->bt);
                    read_int_arg(argc, argv, & a, & self->br);
                    read_int_arg(argc, argv, & a, & self->bb);
                    self->il = self->bl;
                    self->it = self->bt;
                    self->ir = self->br;
                    self->ib = self->bb;
                }
                else if ((! strcmp(arg, "inner"))) {
                    read_int_arg(argc, argv, & a, & self->il);
                    read_int_arg(argc, argv, & a, & self->it);
                    read_int_arg(argc, argv, & a, & self->ir);
                    read_int_arg(argc, argv, & a, & self->ib);
                }
                else if (! strcmp(arg, "gap")) {
                    read_int_arg(argc, argv, & a, & self->hgap);
                    read_int_arg(argc, argv, & a, & self->vgap);
                }
                else if (! strcmp(arg, "color")) {
                    int c = 0;
                    read_int_arg(argc, argv, & a, & c);
                    self->a = (c & 255) / 255.0;
                    c >>= 8;
                    self->b = (c & 255) / 255.0;
                    c >>= 8;
                    self->g = (c & 255) / 255.0;
                    c >>= 8;
                    self->r = (c & 255) / 255.0;
                    c >>= 8;
                }
                else if ((! strcmp(arg, "transparent"))) {
                    self->transparent = 1;
                }
                land_free(arg);
            }
            if (! self->bmp) {
                self->bmp = land_image_new_from(img, 0, 0, land_image_width(img), land_image_height(img));
            }
            land_log_message("element %s: %d x %d, %d/%d/%d/%d %.1f/%.1f/%.1f/%.1f\n", name, land_image_width(self->bmp), land_image_height(self->bmp), self->bl, self->bt, self->br, self->bb, self->r, self->g, self->b, self->a);
        }
        else {
            land_log_message("element: Error: %s not found!\n", name);
        }
    }
    land_array_destroy(argv);
    if (img) {
        land_image_destroy(img);
    }
    return self;
}
LandWidgetTheme* land_widget_theme_new(char const * filename) {
    LandWidgetTheme * self;
    land_alloc(self);
    LandIniFile * config = land_ini_read(filename);
    LandBuffer * prefix = land_buffer_new();
    land_buffer_cat(prefix, filename);
    int slash = land_buffer_rfind(prefix, '/');
    if (slash >= 0) {
        land_buffer_set_length(prefix, slash + 1);
    }
    else {
        land_buffer_set_length(prefix, 0);
    }
    land_buffer_cat(prefix, land_ini_get_string(config, "agup.cfg", "prefix", ""));
    self->name = land_strdup(land_ini_get_string(config, "agup.cfg", "name", ""));
    self->prefix = land_buffer_finish(prefix);
    self->suffix = land_strdup(land_ini_get_string(config, "agup.cfg", "suffix", ""));
    int n = land_ini_get_number_of_entries(config, "agup.cfg/elements");
    for (int i = 0; i < n; i++) {
        char const * v = land_ini_get_nth_entry(config, "agup.cfg/elements", i);
        char const * k = land_ini_get_string(config, "agup.cfg/elements", v, "");
        LandWidgetThemeElement * elem = land_widget_theme_element_new(self, v, k);
        land_add_list_data(& self->elements, elem);
    }
    land_ini_destroy(config);
    return self;
}
void land_widget_theme_destroy(LandWidgetTheme * self) {
    LandListItem * item;
    for (item = self->elements->first; item; item = item->next) {
        LandWidgetThemeElement * elem = item->data;
        land_free(elem->name);
        land_image_destroy(elem->bmp);
        land_free(elem);
    }
    land_list_destroy(self->elements);
    land_free(self->name);
    land_free(self->prefix);
    land_free(self->suffix);
    land_free(self);
}
static LandWidgetThemeElement* find_element(LandList * list, char const * name) {
    if (! list) {
        return NULL;
    }
    LandListItem * item = list->first;
    while (item) {
        LandWidgetThemeElement * elem = item->data;
        if (! strcmp(elem->name, name)) {
            return elem;
        }
        item = item->next;
    }
    return NULL;
}
LandWidgetThemeElement* land_widget_theme_find_element(LandWidgetTheme * theme, LandWidget * widget) {
    if (! theme) {
        return NULL;
    }
    LandWidgetThemeElement * element;
    element = find_element(theme->elements, widget->vt->name);
    if (! element) {
        element = find_element(theme->elements, "base");
    }
    if (! element) {
        land_alloc(element);
        element->name = land_strdup("");
        element->theme = theme;
    }
    if (! element->selected) {
        char name [1024];
        strncpy(name, widget->vt->name, sizeof name);
        strncat(name, ".selected", sizeof name - strlen(name) - 1);
        element->selected = find_element(theme->elements, name);
        if (! element->selected) {
            strncpy(name, element->name, sizeof name);
            strncat(name, ".selected", sizeof name - strlen(name) - 1);
            element->selected = find_element(theme->elements, name);
        }
        if (! element->selected) {
            element->selected = element;
        }
    }
    if (! element->disabled) {
        char name [1024];
        strncpy(name, widget->vt->name, sizeof name);
        strncat(name, ".disabled", sizeof name - strlen(name) - 1);
        element->disabled = find_element(theme->elements, name);
        if (! element->disabled) {
            element->disabled = element;
        }
    }
    return element;
}
LandWidgetThemeElement* land_widget_theme_element(LandWidget * self) {
    if (self->selected) {
        return self->element->selected;
    }
    if (self->disabled) {
        return self->element->disabled;
    }
    return self->element;
}
void land_widget_theme_draw(LandWidget * self) {
    LandWidgetThemeElement * element = land_widget_theme_element(self);
    if (! element) {
        return ;
    }
    if (self->no_decoration) {
        return ;
    }
    if (element->transparent) {
        return ;
    }
    draw_bitmap(element, self->box.x, self->box.y, self->box.w, self->box.h, self->only_border);
}
void land_widget_theme_color(LandWidget * self) {
    LandWidgetThemeElement * element = land_widget_theme_element(self);
    if (! element) {
        return ;
    }
    land_color(element->r, element->g, element->b, element->a);
}
void land_widget_theme_font(LandWidget * self) {
    LandWidgetThemeElement * element = land_widget_theme_element(self);
    if (! element) {
        return ;
    }
    land_font_set(element->font);
}
void land_widget_theme_set_minimum_size_for_contents(LandWidget * self, int w, int h) {
    LandWidgetThemeElement * element = land_widget_theme_element(self);
    if (! element) {
        return ;
    }
    self->inner_w = w;
    self->inner_h = h;
    w += element->il + element->ir;
    h += element->it + element->ib;
    if (element->minw > w) {
        w = element->minw;
    }
    if (element->minh > h) {
        h = element->minh;
    }
    if (self->outer_w > w) {
        w = self->outer_w;
    }
    if (self->outer_h > h) {
        h = self->outer_h;
    }
    land_widget_layout_set_minimum_size(self, w, h);
}
void land_widget_theme_set_minimum_size_for_text(LandWidget * self, char const * text) {
    LandWidgetThemeElement * element = land_widget_theme_element(self);
    if (! element) {
        return ;
    }
    land_font_set(element->font);
    int w = land_text_get_width(text);
    int h = land_font_height(land_font_current());
    land_widget_theme_set_minimum_size_for_contents(self, w, h);
}
void land_widget_theme_set_minimum_size_for_image(LandWidget * self, LandImage * image) {
    LandWidgetThemeElement * element = land_widget_theme_element(self);
    if (! element) {
        return ;
    }
    int w = land_image_width(image);
    int h = land_image_height(image);
    land_widget_theme_set_minimum_size_for_contents(self, w, h);
}
void land_widget_theme_initialize(LandWidget * self) {
    /* Initialize theming of an item. Must only called once at item creation,
     * as it also calculates the minimum size.
     */
    if (! self->element) {
        return ;
    }
    self->element = land_widget_theme_find_element(self->element->theme, self);
    self->outer_w = self->box.min_width;
    self->outer_h = self->box.min_height;
    land_widget_theme_set_minimum_size_for_contents(self, 0, 0);
}
void land_widget_theme_update(LandWidget * self) {
    /* Adjust the widget's theme to its class (widgets all start off as "base"
     * otherwise).
     */
    if (! self->element) {
        return ;
    }
    self->element = land_widget_theme_find_element(self->element->theme, self);
    land_widget_theme_set_minimum_size_for_contents(self, self->inner_w, self->inner_h);
}
static void _theme_recurse(LandWidget * self, LandWidgetTheme * theme) {
    if (! self->element) {
        return ;
    }
    self->element = land_widget_theme_find_element(theme, self);
    land_widget_theme_set_minimum_size_for_contents(self, self->inner_w, self->inner_h);
    if (land_widget_is(self, LAND_WIDGET_ID_CONTAINER)) {
        LandWidgetContainer * c = (void *) self;
        LandListItem * i = c->children ? c->children->first : NULL;
        while (i) {
            LandWidget * w = i->data;
            _theme_recurse(w, theme);
            i = i->next;
        }
    }
}
static void _layout_recurse(LandWidget * self, LandWidgetTheme * theme) {
    if (land_widget_is(self, LAND_WIDGET_ID_CONTAINER)) {
        LandWidgetContainer * c = (void *) self;
        LandListItem * i = c->children ? c->children->first : NULL;
        while (i) {
            LandWidget * w = i->data;
            _layout_recurse(w, theme);
            i = i->next;
        }
        if (self->parent && (self->parent->box.flags & GUL_NO_LAYOUT)) {
            land_widget_layout(self);
        }
    }
}
void land_widget_theme_apply(LandWidget * self, LandWidgetTheme * theme) {
    /* Applies the given theme to the widget and all its children.
     */
    _theme_recurse(self, theme);
    _layout_recurse(self, theme);
    land_widget_layout(self);
}
    /* The art of programming tilemaps
     * = Types of tilemaps =
     * == The classic fixed-cell grid-map ==
     * This is the simplest form of a tilemap. Just define a grid and store a tile-id
     * in each cell.
     * == Optimized fixed-cell map ==
     * There are various ways to optimize the simple tilemap to consume less memory.
     * For example, quad-trees or similar techniques. A quad-tree can optimize away
     * large empty areas, and makes it easy to have different-sized tiles as long as
     * bigger ones have double the dimensions of smaller ones.
     * == Layers ==
     * Simply have multiple layers, one on top of another. This can have many uses,
     * for example different tile-sizes and parallax scrolling.
     * == Non-rectangle ==
     * Popular types of tiles don't use a fixed rectangular grid, but use hexagon or
     * isometric maps. We'll deal with both of them.
     * = The basics =
     * == Drawing ==
     * Assume, we have a fixed cell map. The x and y position of a tile can
     * be calculated like this:
     * * pixel_x = tile_x * cell_width
     * * pixel_y = tile_y * cell_height
     * If the map data are stored as an array, and each map position just
     * stores a tile number, we  can retriece it like this:
     * * tile_numer = array[tile_y * map_width + tile_x]
     * So now, we have all we need. We can draw the tile to its position.
     * Doing this for all tiles in the map, we can draw the complete map.
     * == Picking ==
     * Something which is not obvious to do at first, but will be useful soon, is how
     * to pick tiles out of a map. Thinking about it, it is quite simple to
     * do. It is, in a sense, the opposite of drawing.
     * We have a (pixel) position, and want to know which tile lies under it.
     * * tile_x = pixel_x / cell_width
     * * tile_y = pixel_y / cell_height
     * == Collision ==
     * Since we know how to pick a tile from a position, we can easily do
     * collision detection now.
     * = Non-rectangular maps =
     * == Isometric (diamond layout) ==
     * == Hexagon (diamond layout) ==
     * == Isometric (row or column shifted layout) ==
     * == Hexagon (row or coumn shifted layout) ==
     */
void land_grid_draw(LandGrid * self, LandView * view) {
    self->vt->draw(self, view);
}
void land_grid_get_cell_at(LandGrid * self, LandView * view, float view_x, float view_y, float * cell_x, float * cell_y) {
    /* Given a view position, return the corresponding cell position.
     * For a wrapped grid, the returned position will always be normalized to
     * lie within the grid, even if the passed position or the view's scroll
     * position are outside.
     */
    self->vt->get_cell_at(self, view, view_x, view_y, cell_x, cell_y);
}
void land_grid_get_cell_position(LandGrid * self, LandView * view, float cell_x, float cell_y, float * view_x, float * view_y) {
    /* Given a cell position, return the corresponding view position, in pixels.
     * For a wrapped grid, the returned position will first be normalized to
     * lie within the grid, and then related to the view position. Try normalizing
     * the view's scroll position first (land_view_ensure_inside_grid) so it lies
     * within the grid, if you experience unexpected offsets.
     */
    self->vt->get_cell_position(self, view, cell_x, cell_y, view_x, view_y);
}
void land_grid_initialize(LandGrid * self, int cell_w, int cell_h, int x_cells, int y_cells) {
    self->x_cells = x_cells;
    self->y_cells = y_cells;
    self->cell_w = cell_w;
    self->cell_h = cell_h;
}
void land_grid_init(void) {
    land_log_message("land_grid_init\n");
    land_tilemap_init();
    land_isometric_init();
    land_sprites_init();
}
void land_grid_exit(void) {
    land_log_message("land_grid_exit\n");
    land_tilemap_exit();
    land_isometric_exit();
    land_sprites_exit();
}
void land_grid_del(LandGrid * self) {
    land_call_method(self, del, (self));
}
void land_thread_run(void(* cb)(void * data), void * data) {
    platform_thread_run(cb, data);
}
LandThread* land_thread_new(void(* cb)(void * data), void * data) {
    return platform_thread_new(cb, data);
}
void land_thread_destroy(LandThread * t) {
    platform_thread_destroy(t);
}
LandLock* land_thread_new_lock(void) {
    return platform_thread_new_lock();
}
void land_thread_delete_lock(LandLock * l) {
    return platform_thread_delete_lock(l);
}
void land_thread_lock(LandLock * l) {
    platform_thread_lock(l);
}
void land_thread_unlock(LandLock * l) {
    platform_thread_unlock(l);
}
    /* translation matrix to translate by xt/yt/zt
     * T = 1 0 0 xt
     * 0 1 0 yt
     * 0 0 1 zt
     * 0 0 0 1
     * rotation matrix into coordinate system given by 3 vectors
     * x=xx/yx/zx, y=xy/yy/zy, z=xz/yz/zz
     * R = xx xy xz 0
     * yx yy yz 0
     * zx zy zz 0
     * 0  0  0  1
     * scaling matrix to scale by xs/ys/zs
     * S = xs 0  0  0
     * 0  ys 0  0
     * 0  0  zs 0
     * 0  0  0  1
     * inv(T) = 1 0 0 -xt
     * 0 1 0 -yt
     * 0 0 1 -zt
     * 0 0 0 1
     * inv(R) = xx yx zx 0
     * xy yy zy 0
     * xz yz zz 0
     * 0  0  0  1
     * T x = x + xt
     * y = y + yt
     * z = z + zt
     * 1 = 1
     * R x = xx x + xy y + xz z
     * y = yx x + yy y + yz z
     * z = zx x + zy y + zz z
     * 1 = 1
     * rotate first then translate
     * T R = xx xy xz xt
     * yx yy yz yt
     * zx zy zz zt
     * 0  0  0  1
     * T R x = xx x + xy y + xz z + xt
     * y   yx x + yy y + yz z + yt
     * z   zx x + zy y + zz z + zt
     * 1   1
     * translate first then rotate
     * R T = xx xy xz xx xt + xy yt + xz zt
     * yx yy yz yx xt + yy yt + yz zt
     * zx zy zz zx xt + zy yt + zz zt
     * 0  0  0  1
     * scale first then translate
     * T S = 1 0 0 xt   xs 0  0  0   xs 0  0  xt
     * 0 1 0 yt * 0  ys 0  0 = 0  ys 0  yt
     * 0 0 1 zt   0  0  zs 0   0  0  zs zt
     * 0 0 0 1    0  0  0  1   0  0  0  1
     * T S x = xs * x + xt
     * y   ys * y + yt
     * z   zs * z + zt
     * 1   1
     * translate first then scale
     * S T = xs 0  0  0   1 0 0 xt   xs 0  0  xs*xt
     * 0  ys 0  0 * 0 1 0 yt = 0  ys 0  ys*yt
     * 0  0  zs 0   0 0 1 zt   0  0  zs zs*zt
     * 0  0  0  1   0 0 0 1    0  0  0  1
     * S T x = xs * x + xs * xt
     * y   ys * y + ys * yt
     * z   zs * z + zs * zt
     * 1   1
     * translate first then arbitrary affine matrix
     * A T = A0 A1 A2 A3   1 0 0 xt    A0 A1 A2 A0*xt+A1*yt+A2*zt+A3
     * A4 A5 A6 A7 * 0 1 0 yt =  A4 A5 A6 A4*xt+A5*yt+A7*zt+A7
     * A8 A9 Aa Ab   0 0 1 zt    A8 A9 Aa A8*xt+A9*yt+Aa*zt+Ab
     * 0  0  0  1    0 0 0 1     0  0  0  1
     * scale first then arbitrary affine matrix
     * A S = A0 A1 A2 A3   xs 0  0  0   A0*xs A1*ys A2*zs A3
     * A4 A5 A6 A7 * 0  ys 0  0 = A4*xs A5*ys A6*zs A7
     * A8 A9 Aa Ab   0  0  zs 0   A8*xs A9*ys Aa*zs Ab
     * 0  0  0  1    0  0  0  1   0     0     0     1
     * rotate by an angle around vector 0/0/1
     * Ra = +cos -sin 0 0
     * +sin +cos 0 0
     * 0    0    1 0
     * 0    0    0 1
     * same but arbitrary affine matrix afterwards
     * A Ra = A0*c+A1*s -A0*s+A1*c A2 A3
     * A4*c+A5*s -A4*s+A5*c A6 A7
     * A8*c+A9*s -A8*s+A9*c Aa Ab
     * 0         0          0  1
     */
#define SQRT sqrt
#define COS cos
#define SIN sin
LandVector land_vector(LandFloat x, LandFloat y, LandFloat z) {
    LandVector v = {x, y, z};
    return v;
}
LandVector land_vector_from_array(LandFloat * a) {
    LandVector v = {a [0], a [1], a [2]};
    return v;
}
void land_vector_iadd(LandVector * v, LandVector w) {
    v->x += w.x;
    v->y += w.y;
    v->z += w.z;
}
void land_vector_isub(LandVector * v, LandVector w) {
    v->x -= w.x;
    v->y -= w.y;
    v->z -= w.z;
}
void land_vector_imul(LandVector * v, LandFloat s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}
void land_vector_idiv(LandVector * v, LandFloat s) {
    v->x /= s;
    v->y /= s;
    v->z /= s;
}
LandVector land_vector_neg(LandVector v) {
    LandVector r = {- v.x, - v.y, - v.z};
    return r;
}
LandVector land_vector_mul(LandVector v, LandFloat s) {
    LandVector r = {v.x * s, v.y * s, v.z * s};
    return r;
}
LandVector land_vector_div(LandVector v, LandFloat s) {
    LandVector r = {v.x / s, v.y / s, v.z / s};
    return r;
}
LandVector land_vector_add(LandVector v, LandVector w) {
    LandVector r = {v.x + w.x, v.y + w.y, v.z + w.z};
    return r;
}
LandVector land_vector_sub(LandVector v, LandVector w) {
    LandVector r = {v.x - w.x, v.y - w.y, v.z - w.z};
    return r;
}
LandVector land_vector_lerp(LandVector v, LandVector w, LandFloat t) {
    return land_vector_add(v, land_vector_mul(land_vector_sub(w, v), t));
}
LandFloat land_vector_dot(LandVector v, LandVector w) {
    /* The dot product is a number. The number corresponds to the cosine
     * between the two vectors times their lengths. So the angle between the
     * vectors would be: angle = acos(v . w / (|v| * |w|)). If the dot product
     * is 0, the two vectors conversely are orthogonal. The sign can be used to
     * determine which side of a plane a point is on.
     */
    return v.x * w.x + v.y * w.y + v.z * w.z;
}
LandVector land_vector_cross(LandVector v, LandVector w) {
    /* The cross product results in a vector orthogonal to both v and w. The
     * length of the resulting vector corresponds to the sine of the angle
     * between the two vectors and their lengths. So the angle between the
     * vectors would be: angle = asin(|v x w| / (|v| * |w|)). If the cross
     * product is the 0 vector, the two input vectors are parallel.
     */
    LandVector r = {v.y * w.z - w.y * v.z, v.z * w.x - w.z * v.x, v.x * w.y - w.x * v.y};
    return r;
}
LandFloat land_vector_norm(LandVector v) {
    /* Return the norm of the vector.
     */
    return SQRT(land_vector_dot(v, v));
}
LandVector land_vector_normalize(LandVector v) {
    /* Return a normalized version of the vector.
     */
    return land_vector_div(v, land_vector_norm(v));
}
LandQuaternion land_vector_quatmul(LandVector v, LandQuaternion q) {
    /* Multiply the vector with a quaternion. The result is a quaternion. For
     * example if your vector is a rotation, the resulting quaternion will be a
     * quaternion who rotates whatever it did plus this additional rotation.
     */
    LandQuaternion r = {- v.x * q.x - v.y * q.y - v.z * q.z, v.x * q.w + v.y * q.z - v.z * q.y, v.y * q.w + v.z * q.x - v.x * q.z, v.z * q.w + v.x * q.y - v.y * q.x};
    return r;
}
LandVector land_vector_transform(LandVector v, LandVector p, LandVector r, LandVector u, LandVector b) {
    /* Return a new vector obtained by transforming this vector by a coordinate
     * system with the given origin and given right/up/back vectors. This is
     * used if the vector is in world coordinates, and you want to transform it
     * to camera coordinates, where p/r/u/b define camera position and
     * orientation.
     */
    LandVector w = land_vector_sub(v, p);
    LandVector a = {land_vector_dot(w, r), land_vector_dot(w, u), land_vector_dot(w, b)};
    return a;
}
LandVector land_vector_matmul(LandVector v, Land4x4Matrix * m) {
    LandFloat x = m->v [0] * v.x + m->v [1] * v.y + m->v [2] * v.z + m->v [3];
    LandFloat y = m->v [4] * v.x + m->v [5] * v.y + m->v [6] * v.z + m->v [7];
    LandFloat z = m->v [8] * v.x + m->v [9] * v.y + m->v [10] * v.z + m->v [11];
    return land_vector(x, y, z);
}
LandVector land_vector_backtransform(LandVector v, LandVector p, LandVector r, LandVector u, LandVector b) {
    /* Do the inverse of transform, i.e. you can use it to transform from
     * camera back to world coordinates.
     */
    LandVector x = land_vector_mul(r, v.x);
    LandVector y = land_vector_mul(u, v.y);
    LandVector z = land_vector_mul(b, v.z);
    LandVector a = p;
    land_vector_iadd(& a, x);
    land_vector_iadd(& a, y);
    land_vector_iadd(& a, z);
    return a;
}
LandVector land_vector_rotate(LandVector v, LandVector a, double angle) {
    /* Rotate the vector around axis a by angle in counter clockwise direction.
     * If this vector is a point in world space, then the axis of rotation is
     * defined by the origin and the a vector.
     */
    LandFloat c = COS(angle);
    LandFloat s = SIN(angle);
    LandVector r = land_vector_mul(a, a.x * (1 - c));
    LandVector u = land_vector_mul(a, a.y * (1 - c));
    LandVector b = land_vector_mul(a, a.z * (1 - c));
    r.x += c;
    r.y += a.z * s;
    r.z -= a.y * s;
    u.x -= a.z * s;
    u.y += c;
    u.z += a.x * s;
    b.x += a.y * s;
    b.y -= a.x * s;
    b.z += c;
    LandFloat x = land_vector_dot(v, r);
    LandFloat y = land_vector_dot(v, u);
    LandFloat z = land_vector_dot(v, b);
    LandVector ret = {x, y, z};
    return ret;
}
LandVector land_vector_reflect(LandVector v, LandVector n) {
    /* Given the normal of a plane, reflect the vector off the plane. If the
     * vector is a point in 3D space, and the plane goes through the origin,
     * the result is a point reflected by the plane.
     */
    LandFloat d = land_vector_dot(v, n);
    LandVector r = n;
    land_vector_imul(& r, - 2 * d);
    land_vector_iadd(& r, v);
    return r;
}
LandQuaternion land_quaternion(LandFloat w, LandFloat x, LandFloat y, LandFloat z) {
    LandQuaternion q = {w, x, y, z};
    return q;
}
LandQuaternion land_quaternion_from_array(LandFloat * f) {
    LandQuaternion q = {f [0], f [1], f [2], f [3]};
    return q;
}
void land_quaternion_to_array(LandQuaternion * q, LandFloat * f) {
    f [0] = q->w;
    f [1] = q->x;
    f [2] = q->y;
    f [3] = q->z;
}
void land_quaternion_iadd(LandQuaternion * q, LandQuaternion p) {
    q->w += p.w;
    q->x += p.x;
    q->y += p.y;
    q->z += p.z;
}
void land_quaternion_imul(LandQuaternion * q, LandFloat s) {
    q->w *= s;
    q->x *= s;
    q->y *= s;
    q->z *= s;
}
LandQuaternion land_quaternion_combine(LandQuaternion qa, LandQuaternion qb) {
    LandVector qav = {qa.x, qa.y, qa.z};
    LandVector qbv = {qb.x, qb.y, qb.z};
    LandVector va = land_vector_cross(qav, qbv);
    LandVector vb = land_vector_mul(qav, qb.w);
    LandVector vc = land_vector_mul(qbv, qa.w);
    land_vector_iadd(& va, vb);
    LandVector qrv = land_vector_add(va, vc);
    double w = land_vector_dot(qav, qbv);
    LandQuaternion qr = {qrv.x, qrv.y, qrv.z, w};
    land_quaternion_normalize(& qr);
    return qr;
}
void land_quaternion_vectors(LandQuaternion q, LandVector * r, LandVector * u, LandVector * b) {
    /* Output three orientation vectors for the quaternion. That is, if the
     * quaternion is used as a 3D orientation, return right/up/back vectors
     * representing the same orientation.
     */
    LandFloat ww = q.w * q.w;
    LandFloat xx = q.x * q.x;
    LandFloat yy = q.y * q.y;
    LandFloat zz = q.z * q.z;
    LandFloat wx = q.w * q.x * 2;
    LandFloat wy = q.w * q.y * 2;
    LandFloat wz = q.w * q.z * 2;
    LandFloat xy = q.x * q.y * 2;
    LandFloat xz = q.x * q.z * 2;
    LandFloat yz = q.y * q.z * 2;
    r->x = ww + xx - yy - zz;
    u->x = xy - wz;
    b->x = xz + wy;
    r->y = xy + wz;
    u->y = ww - xx + yy - zz;
    b->y = yz - wx;
    r->z = xz - wy;
    u->z = yz + wx;
    b->z = ww - xx - yy + zz;
}
Land4x4Matrix land_quaternion_4x4_matrix(LandQuaternion q) {
    LandVector r, u, b;
    land_quaternion_vectors(q, & r, & u, & b);
    Land4x4Matrix m;
    m.v [0] = r.x;
    m.v [1] = u.x;
    m.v [2] = b.x;
    m.v [3] = 0;
    m.v [4] = r.y;
    m.v [5] = u.y;
    m.v [6] = b.y;
    m.v [7] = 0;
    m.v [8] = r.z;
    m.v [9] = u.z;
    m.v [10] = b.z;
    m.v [11] = 0;
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_mul(Land4x4Matrix a, Land4x4Matrix b) {
    /* This multiplies two matrices:
     * result = a b
     * When used with 3D transformations, the result has the same effect as first
     * applying b, then a.
     * In words, result[row,column] = a[row,...] * b[...,column].
     */
    Land4x4Matrix m;
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 4; j += 1) {
            LandFloat x = 0;
            for (int k = 0; k < 4; k += 1) {
                x += a.v [i * 4 + k] * b.v [k * 4 + j];
            }
            m.v [i * 4 + j] = x;
        }
    }
    return m;
}
Land4x4Matrix land_4x4_matrix_scale(LandFloat x, LandFloat y, LandFloat z) {
    Land4x4Matrix m;
    m.v [0] = x;
    m.v [1] = 0;
    m.v [2] = 0;
    m.v [3] = 0;
    m.v [4] = 0;
    m.v [5] = y;
    m.v [6] = 0;
    m.v [7] = 0;
    m.v [8] = 0;
    m.v [9] = 0;
    m.v [10] = z;
    m.v [11] = 0;
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_rotate(LandFloat x, LandFloat y, LandFloat z, LandFloat angle) {
    Land4x4Matrix m;
    double s = sin(angle);
    double c = cos(angle);
    double cc = 1 - c;
    m.v [0] = (cc * x * x) + c;
    m.v [4] = (cc * x * y) + (z * s);
    m.v [8] = (cc * x * z) - (y * s);
    m.v [12] = 0;
    m.v [1] = (cc * x * y) - (z * s);
    m.v [5] = (cc * y * y) + c;
    m.v [9] = (cc * z * y) + (x * s);
    m.v [13] = 0;
    m.v [2] = (cc * x * z) + (y * s);
    m.v [6] = (cc * y * z) - (x * s);
    m.v [10] = (cc * z * z) + c;
    m.v [14] = 0;
    m.v [3] = 0;
    m.v [7] = 0;
    m.v [11] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_identity(void) {
    Land4x4Matrix m;
    m.v [0] = 1;
    m.v [1] = 0;
    m.v [2] = 0;
    m.v [3] = 0;
    m.v [4] = 0;
    m.v [5] = 1;
    m.v [6] = 0;
    m.v [7] = 0;
    m.v [8] = 0;
    m.v [9] = 0;
    m.v [10] = 1;
    m.v [11] = 0;
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_translate(LandFloat x, LandFloat y, LandFloat z) {
    /* T = 1 0 0 xt
     * 0 1 0 yt
     * 0 0 1 zt
     * 0 0 0 1
     */
    Land4x4Matrix m;
    m.v [0] = 1;
    m.v [1] = 0;
    m.v [2] = 0;
    m.v [3] = x;
    m.v [4] = 0;
    m.v [5] = 1;
    m.v [6] = 0;
    m.v [7] = y;
    m.v [8] = 0;
    m.v [9] = 0;
    m.v [10] = 1;
    m.v [11] = z;
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_perspective(LandFloat left, LandFloat bottom, LandFloat nearz, LandFloat right, LandFloat top, LandFloat farz) {
    Land4x4Matrix m;
    LandFloat w = right - left;
    LandFloat h = top - bottom;
    LandFloat depth = farz - nearz;
    LandFloat cx = (right + left) / 2;
    LandFloat cy = (bottom + top) / 2;
    LandFloat cz = (farz + nearz) / 2;
    m.v [0] = 2 * nearz / w;
    m.v [1] = 0;
    m.v [2] = 2 * cx / w;
    m.v [3] = 0;
    m.v [4] = 0;
    m.v [5] = 2 * nearz / h;
    m.v [6] = 0;
    m.v [7] = 2 * cy / h;
    m.v [8] = 0;
    m.v [9] = 0;
    m.v [10] = - 2 * cz / depth;
    m.v [11] = farz * nearz * (- 2 / depth);
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = - 1;
    m.v [15] = 0;
    return m;
}
Land4x4Matrix land_4x4_matrix_orthographic(LandFloat left, LandFloat top, LandFloat nearz, LandFloat right, LandFloat bottom, LandFloat farz) {
    /* Orthographic means no projection so this would be just an identity matrix.
     * But as convenience this scales and translates to fit into the
     * left/top/right/bottom rectangle and also scales depth.
     * The point at (left, top, near) will end up at (-1, -1, -1) and the point
     * at (right, bottom, far) will end up at (1, 1, 1).
     * O = S(2/w, 2/h, 2/d) T(-cx, -cy, -cz)
     * O = 2/w 0   0   2/w*-cx
     * 0   2/h 0   2/h*-cy
     * 0   0   2/d 2/d*-cz
     * 0   0   0   1
     * O x = 2/w*(x-cx)
     * y   2/h*(y-cy)
     * z   2/d*(z-cz)
     * 1   1
     * inv(O) = inv(T) inv(S) = w/2 0   0   cx
     * 0   h/2 0   cy
     * 0   0   d/2 cz
     * 0   0   0   1
     * O inv(O) = 1 0 0 0
     * 0 1 0 0
     * 0 0 1 0
     * 0 0 0 1
     */
    Land4x4Matrix m;
    LandFloat w = right - left;
    LandFloat h = bottom - top;
    LandFloat depth = farz - nearz;
    LandFloat cx = (right + left) / 2;
    LandFloat cy = (bottom + top) / 2;
    LandFloat cz = (farz + nearz) / 2;
    m.v [0] = 2 / w;
    m.v [1] = 0;
    m.v [2] = 0;
    m.v [3] = 2 / w * (- cx);
    m.v [4] = 0;
    m.v [5] = 2 / h;
    m.v [6] = 0;
    m.v [7] = 2 / h * (- cy);
    m.v [8] = 0;
    m.v [9] = 0;
    m.v [10] = 2 / depth;
    m.v [11] = 2 / depth * (- cz);
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_from_vectors(LandVector * p, LandVector * r, LandVector * u, LandVector * b) {
    Land4x4Matrix m;
    m.v [0] = r->x;
    m.v [1] = u->x;
    m.v [2] = b->x;
    m.v [3] = p->x;
    m.v [4] = r->y;
    m.v [5] = u->y;
    m.v [6] = b->y;
    m.v [7] = p->y;
    m.v [8] = r->z;
    m.v [9] = u->z;
    m.v [10] = b->z;
    m.v [11] = p->z;
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
Land4x4Matrix land_4x4_matrix_inverse_from_vectors(LandVector * p, LandVector * r, LandVector * u, LandVector * b) {
    Land4x4Matrix m;
    m.v [0] = r->x;
    m.v [1] = r->y;
    m.v [2] = r->z;
    m.v [3] = r->x * (- p->x) + r->y * (- p->y) + r->z * (- p->z);
    m.v [4] = u->x;
    m.v [5] = u->y;
    m.v [6] = u->z;
    m.v [7] = u->x * (- p->x) + u->y * (- p->y) + u->z * (- p->z);
    m.v [8] = b->x;
    m.v [9] = b->y;
    m.v [10] = b->z;
    m.v [11] = b->x * (- p->x) + b->y * (- p->y) + b->z * (- p->z);
    m.v [12] = 0;
    m.v [13] = 0;
    m.v [14] = 0;
    m.v [15] = 1;
    return m;
}
void land_quaternion_normalize(LandQuaternion * q) {
    /* Normalize the quaternion. This may be useful to prevent deteriorating
     * the quaternion if it is used for a long time, due to floating point
     * inaccuracies.
     */
    LandFloat n = SQRT(q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
    q->w /= n;
    q->x /= n;
    q->y /= n;
    q->z /= n;
}
LandQuaternion land_quaternion_slerp(LandQuaternion qa, LandQuaternion qb, double t) {
    /* Given two quaternions, interpolate a quaternion in between. If t is 0
     * this will return qa, if t is 1 it will return qb.
     * The rotation will be along the shortest path (not necessarily the shorter
     * direction though) and the rotation angle will linearly correspond to t.
     */
    LandQuaternion q;
    double c = qa.w * qb.w + qa.x * qb.x + qa.y * qb.y + qa.z * qb.z;
    if (c < 0) {
        c = - c;
        qb.w = - qb.w;
        qb.x = - qb.x;
        qb.y = - qb.y;
        qb.z = - qb.z;
    }
    double theta = acos(c);
    double s = sin(theta);
    double fs = sin((1 - t) * theta) / s;
    double ts = sin(t * theta) / s;
    q.w = qa.w * fs + qb.w * ts;
    q.x = qa.x * fs + qb.x * ts;
    q.y = qa.y * fs + qb.y * ts;
    q.z = qa.z * fs + qb.z * ts;
    return q;
}
LandBuffer* land_4x4_matrix_to_string(Land4x4Matrix * m) {
    LandBuffer * b = land_buffer_new();
    for (int i = 0; i < 16; i += 1) {
        land_buffer_addf(b, "%-5.2f%s", m->v [i], i % 4 == 3 ? "\n" : " ");
    }
    return b;
}
#undef SQRT
#undef COS
#undef SIN
static int mx, my, mz, mb;
static int omx, omy, omz, omb;
static int buttons [5], obuttons [5], clicks [5];
static float tx [11], ty [11], tb [11], otb [11];
void land_mouse_init(void) {
    land_show_mouse_cursor();
}
void land_mouse_tick(void) {
    omx = mx;
    omy = my;
    omz = mz;
    omb = mb;
    for (int i = 0; i < 5; i++) {
        obuttons [i] = buttons [i];
        if (buttons [i] == 2) {
            buttons [i] = 0;
        }
        clicks [i] = 0;
    }
    for (int i = 0; i < 11; i += 1) {
        otb [i] = tb [i];
    }
}
void land_mouse_move_event(int x, int y, int z) {
    mx = x;
    my = y;
    mz = z;
}
void land_touch_event(float x, float y, int n, int d) {
    if (n > 10) {
        return ;
    }
    tx [n] = x;
    ty [n] = y;
    if (d == 1) {
        tb [n] = 1;
    }
    if (d == - 1) {
        tb [n] = 0;
    }
}
float land_touch_x(int n) {
    if (n > 10) {
        return 0;
    }
    return tx [n];
}
float land_touch_y(int n) {
    if (n > 10) {
        return 0;
    }
    return ty [n];
}
bool land_touch_down(int n) {
    if (n > 10) {
        return 0;
    }
    return tb [n];
}
bool land_touch_delta(int n) {
    if (n > 10) {
        return 0;
    }
    return otb [n] != tb [n];
}
void land_mouse_button_down_event(int b) {
    mb |= 1 << b;
    if (! (buttons [b] & 1)) {
        clicks [b]++;
    }
    buttons [b] |= 1 + 2;
}
void land_mouse_button_up_event(int b) {
    mb &= ~ (1 << b);
    buttons [b] &= ~ 1;
}
int land_mouse_x(void) {
    /* """Return the mouse X coordinate for the current tick."""
     */
    return mx;
}
int land_mouse_y(void) {
    /* """Return the mouse Y coordinate for the current tick."""
     */
    return my;
}
int land_mouse_z(void) {
    /* """Return the mouse wheel coordinate for the current tick."""
     */
    return mz;
}
int land_mouse_b(void) {
    /* """Short for land_mouse_button."""
     */
    return mb;
}
int land_mouse_button(int i) {
    /* """Return the mouse button state for the current tick."""
     */
    return buttons [i] & 1;
}
int land_mouse_delta_x(void) {
    return mx - omx;
}
int land_mouse_delta_y(void) {
    return my - omy;
}
int land_mouse_delta_z(void) {
    return mz - omz;
}
int land_mouse_delta_b(void) {
    return mb ^ omb;
}
int land_mouse_delta_button(int i) {
    return (buttons [i] & 1) ^ (obuttons [i] & 1);
}
int land_mouse_button_clicked(int i) {
    return clicks [i];
}
void land_mouse_set_pos(int x, int y) {
    platform_mouse_set_pos(x, y);
    mx = x;
    my = y;
}
bool land_hide_mouse_cursor(void) {
    platform_hide_mouse_cursor();
    return true;
}
bool land_show_mouse_cursor(void) {
    platform_show_mouse_cursor();
    return true;
}
static LandGridInterface * land_grid_vtable_tilegrid;
LandGrid* land_tilegrid_new(int cell_w, int cell_h, int x_cells, int y_cells) {
    LandTileGrid * self;
    land_alloc(self);
    land_grid_initialize(& self->super, cell_w, cell_h, x_cells, y_cells);
    self->super.vt = land_grid_vtable_tilegrid;
    self->tiles = land_calloc(x_cells * y_cells * sizeof (* self->tiles));
    return & self->super;
}
void land_tilegrid_del(LandGrid * self) {
    land_free(LAND_TILE_GRID (self)->tiles);
    land_free(self);
}
void land_tilegrid_place(LandGrid * super, int cell_x, int cell_y, LandImage * image) {
    if (cell_x < 0 || cell_y < 0 || cell_x >= super->x_cells || cell_y >= super->y_cells) {
        return ;
    }
    LandTileGrid * self = LAND_TILE_GRID(super);
    self->tiles [cell_y * super->x_cells + cell_x] = image;
}
static void land_tilegrid_draw_cell(LandGrid * self, LandView * view, int cell_x, int cell_y, float pixel_x, float pixel_y) {
    LandImage * image = LAND_TILE_GRID (self)->tiles [cell_y * self->x_cells + cell_x];
    if (image) {
        land_image_draw_scaled(image, pixel_x, pixel_y, view->scale_x, view->scale_y);
    }
}
static void view_x_to_cell_and_pixel_x(LandGrid * self, float view_x, int * cell_x, float * pixel_x) {
    if (view_x < 0) {
        * cell_x = 0;
        * pixel_x = - view_x;
    }
    else {
        * cell_x = (unsigned int) view_x / self->cell_w;
        * pixel_x = * cell_x * self->cell_w - view_x;
    }
}
static void view_y_to_cell_and_pixel_y(LandGrid * self, float view_y, int * cell_y, float * pixel_y) {
    if (view_y < 0) {
        * cell_y = 0;
        * pixel_y = - view_y;
    }
    else {
        * cell_y = (unsigned int) view_y / self->cell_h;
        * pixel_y = * cell_y * self->cell_h - view_y;
    }
}
void land_grid_draw_normal(LandGrid * self, LandView * view) {
    int cell_x, cell_y;
    float pixel_x, pixel_y;
    float view_x = view->scroll_x;
    float view_y = view->scroll_y;
    view_y_to_cell_and_pixel_y(self, view_y, & cell_y, & pixel_y);
    pixel_y *= view->scale_y;
    pixel_y += view->y;
    for (; pixel_y < view->y + view->h; cell_y++, pixel_y += self->cell_h * view->scale_y) {
        if (cell_y >= self->y_cells) {
            break;
        }
        view_x_to_cell_and_pixel_x(self, view_x, & cell_x, & pixel_x);
        pixel_x *= view->scale_x;
        pixel_x += view->x;
        for (; pixel_x < view->x + view->w; cell_x++, pixel_x += self->cell_w * view->scale_x) {
            if (cell_x >= self->x_cells) {
                break;
            }
            self->vt->draw_cell(self, view, cell_x, cell_y, pixel_x, pixel_y);
        }
    }
}
void land_tilemap_init(void) {
    land_log_message("land_tilemap_init\n");
    land_alloc(land_grid_vtable_tilegrid);
    land_grid_vtable_tilegrid->draw = land_grid_draw_normal;
    land_grid_vtable_tilegrid->draw_cell = land_tilegrid_draw_cell;
    land_grid_vtable_tilegrid->del = land_tilegrid_del;
}
void land_tilemap_exit(void) {
    land_log_message("land_tilemap_exit\n");
    land_free(land_grid_vtable_tilegrid);
}
static LandFontState * land_font_state;
static int active;
void land_font_init(void) {
    if (active) {
        return ;
    }
    land_log_message("land_font_init\n");
    land_alloc(land_font_state);
    platform_font_init();
    active = 1;
}
void land_font_exit(void) {
    if (! active) {
        return ;
    }
    land_free(land_font_state);
    platform_font_exit();
    active = 0;
}
int land_font_active(void) {
    return active;
}
LandFont* land_font_load(char const * filename, float size) {
    /* Load the given font file, with the given size. The size usually is the pixel
     * height of a line in the font. But some fonts, e.g. bitmap fonts, will
     * ignore it. The font also us made the current font if successfully loaded.
     */
    char * path = land_path_with_prefix(filename);
    LandFont * self = platform_font_load(path, size);
    land_free(path);
    land_font_state->font = self;
    return self;
}
void land_font_destroy(LandFont * self) {
    platform_font_destroy(self);
}
LandFont* land_font_new(void) {
    LandFont * f = platform_font_new();
    return f;
}
void land_font_scale(LandFont * f, double scaling) {
    f->xscaling = f->yscaling = scaling;
}
void land_font_yscale(LandFont * f, double scaling) {
    f->yscaling = scaling;
}
void land_font_set(LandFont * self) {
    land_font_state->font = self;
}
void land_text_pos(float x, float y) {
    land_font_state->x_pos = x;
    land_font_state->y_pos = y;
}
void land_text_set_width(float w) {
    land_font_state->adjust_width = w;
}
float land_text_x_pos(void) {
    return land_font_state->x_pos;
}
float land_text_y_pos(void) {
    return land_font_state->y_pos;
}
float land_text_x(void) {
    return land_font_state->x;
}
float land_text_y(void) {
    return land_font_state->y;
}
float land_text_width(void) {
    return land_font_state->w;
}
float land_text_height(void) {
    return land_font_state->h;
}
int land_text_state(void) {
    return land_font_state->off;
}
float land_font_height(LandFont * self) {
    return self->size * land_font_current ()->yscaling;
}
LandFont* land_font_current(void) {
    return land_font_state->font;
}
float land_line_height(void) {
    return land_font_height(land_font_current());
}
void land_text_off(void) {
    land_font_state->off = 1;
}
void land_text_on(void) {
    land_font_state->off = 0;
}
void land_print_string(char const * str, int newline, int alignment) {
    platform_font_print(land_font_state, str, alignment);
    if (newline) {
        land_font_state->y_pos = land_font_state->y + land_font_state->h;
    }
    else {
        land_font_state->x_pos = land_font_state->x + land_font_state->w;
    }
}
float land_text_get_width(char const * str) {
    int onoff = land_font_state->off;
    land_font_state->off = 1;
    platform_font_print(land_font_state, str, 0);
    land_font_state->off = onoff;
    return land_font_state->w;
}
int land_text_get_char_offset(char const * str, int nth) {
    char * u = land_strdup(str);
    char * p = u;
    for (int i = 0; i < nth; i++) {
        land_utf8_char(& p);
    }
    * p = 0;
    int x = land_text_get_width(u);
    land_free(u);
    return x;
}
int land_text_get_char_index(char const * str, int x) {
    if (x < 0) {
        return 0;
    }
    int l = 0;
    char * p = (char *) str;
    while (land_utf8_char(& p)) {
        l++;
    }
    for (int i = 0; i <= l; i++) {
        if (land_text_get_char_offset(str, i) > x) {
            return i - 1;
        }
    }
    return l;
}
void land_print(char const * text, ...) {
    VPRINT;
    land_print_string(s, 1, 0);
}
void land_print_right(char const * text, ...) {
    VPRINT;
    land_print_string(s, 1, 1);
}
void land_print_center(char const * text, ...) {
    VPRINT;
    land_print_string(s, 1, 2);
}
void land_write(char const * text, ...) {
    VPRINT;
    land_print_string(s, 0, 0);
}
void land_write_right(char const * text, ...) {
    VPRINT;
    land_print_string(s, 0, 1);
}
void land_write_center(char const * text, ...) {
    VPRINT;
    land_print_string(s, 0, 2);
}
void land_printv(char const * text, va_list args) {
    va_list args2;
    va_copy(args2, args);
    int n = vsnprintf(NULL, 0, text, args2);
    va_end(args2);
    if (n < 0) {
        n = 1023;
    }
    char s [n + 1];
    vsnprintf(s, n + 1, text, args);
    land_print_string(s, 1, 0);
}
static int _wordwrap_helper(char const * text, int w, int h, void(* cb)(int a, int b, void * data), void * data) {
    int y = land_text_y_pos();
    float fh = land_font_state->font->size;
    char const * line_start_p = text;
    land_font_state->adjust_width = w;
    while (1) {
        if (h > 0 && land_text_y_pos() >= y + h) {
            break;
        }
        float width_of_line = 0;
        int word_end_glyphs = 0;
        char const * word_end_p = line_start_p;
        char const * prev_word_end_p = line_start_p;
        char const * ptr;
        int c;
        while (1) {
            bool inside_leading_whitespace = 1;
            ptr = word_end_p;
            int glyphs = word_end_glyphs;
            while (1) {
                c = land_utf8_char_const(& ptr);
                if (c == 0) {
                    break;
                }
                if (c == '\n') {
                    break;
                }
                if (c == ' ') {
                    if (! inside_leading_whitespace) {
                        break;
                    }
                }
                else {
                    inside_leading_whitespace = 0;
                }
                if (inside_leading_whitespace && word_end_glyphs == 0) {
                    line_start_p = ptr;
                }
                else {
                    glyphs++;
                    word_end_p = ptr;
                }
            }
            int x = land_text_get_char_offset(line_start_p, glyphs);
            if (x > w) {
                if (word_end_glyphs == 0) {
                    word_end_glyphs = glyphs;
                    width_of_line = x;
                }
                else {
                    c = ' ';
                    ptr = word_end_p = prev_word_end_p;
                }
                break;
            }
            width_of_line = x;
            word_end_glyphs = glyphs;
            prev_word_end_p = word_end_p;
            if (c == 0 || c == '\n') {
                break;
            }
        }
        if (width_of_line > land_font_state->wordwrap_width) {
            land_font_state->wordwrap_width = width_of_line;
        }
        land_font_state->wordwrap_height += fh;
        if (word_end_p < line_start_p) {
            cb(line_start_p - text, line_start_p - text, data);
        }
        else {
            cb(line_start_p - text, word_end_p - text, data);
        }
        line_start_p = ptr;
        if (c == 0) {
            break;
        }
    }
    return line_start_p - text;
}
static void _print_wordwrap_cb(int a, int b, void * data) {
    void * (* p) = data;
    char * text = p [0];
    int * alignment = p [1];
    char s [b - a + 1];
    strncpy(s, text + a, b - a + 1);
    s [b - a] = 0;
    land_print_string(s, 1, * alignment);
}
int land_print_string_wordwrap(char const * text, int w, int h, int alignment) {
    /* Print text inside, and starts a new line whenever the text goes over the
     * given width, wrapping at whitespace. If a single word is bigger than w, it
     * will be printed in its own line and exceed w. If h is 0, the whole text is
     * printed. Otherwise, only as many lines as fit into h pixels are printed.
     * The return value is the offset into text in bytes of one past the last
     * printed character.
     */
    void * data [] = {(void *) text, & alignment};
    return _wordwrap_helper(text, w, h, _print_wordwrap_cb, data);
}
int land_print_wordwrap(int w, int h, char const * text, ...) {
    VPRINT;
    return land_print_string_wordwrap(s, w, h, 0);
}
int land_print_wordwrap_right(int w, int h, char const * text, ...) {
    VPRINT;
    return land_print_string_wordwrap(s, w, h, 1);
}
int land_print_wordwrap_center(int w, int h, char const * text, ...) {
    VPRINT;
    return land_print_string_wordwrap(s, w, h, 2);
}
static void land_wordwrap_text_cb(int a, int b, void * data) {
    void * (* p) = data;
    char * text = p [0];
    LandArray * lines = p [1];
    char * s = land_malloc(b - a + 1);
    strncpy(s, text + a, b - a + 1);
    s [b - a] = 0;
    land_array_add(lines, s);
}
LandArray* land_wordwrap_text(int w, int h, char const * str) {
    /* Splits the given string into multiple lines no longer than w pixels. The
     * returned array will have a newly allocated string for each line. You are
     * responsible for freeing those strings again.
     * The calculations will use the current font. Note that for large texts, this
     * can take a while, so you should do calculations on demand and only for the
     * visible text.
     * You can call land_wordwrap_extents after this functions to get the
     * dimensions of a box which will be able to hold all the text.
     */
    LandArray * lines = land_array_new();
    land_font_state->wordwrap_width = 0;
    land_font_state->wordwrap_height = 0;
    if (str) {
        void * data [] = {(void *) str, lines};
        _wordwrap_helper(str, w, h, land_wordwrap_text_cb, data);
    }
    return lines;
}
void land_text_destroy_lines(LandArray * lines) {
    if (! lines) {
        return ;
    }
    int n = land_array_count(lines);
    for (int i = 0; i < n; i++) {
        char * s = land_array_get_nth(lines, i);
        land_free(s);
    }
    land_array_destroy(lines);
}
LandArray* land_text_splitlines(char const * str) {
    /* Splits the text into lines, and updates the wordwrap extents.
     */
    land_font_state->wordwrap_width = 0;
    LandArray * lines = land_array_new();
    while (1) {
        char const * p = strchr(str, '\n');
        if (! p) {
            p = str + strlen(str);
        }
        char * s = land_malloc(p - str + 1);
        strncpy(s, str, p - str);
        s [p - str] = 0;
        int w = land_text_get_width(s);
        if (w > land_font_state->wordwrap_width) {
            land_font_state->wordwrap_width = w;
        }
        land_array_add(lines, s);
        if (p [0] == 0) {
            break;
        }
        str = p + 1;
    }
    land_font_state->wordwrap_height = land_font_state->font->size * land_array_count(lines);
    return lines;
}
void land_wordwrap_extents(float * w, float * h) {
    if (w) {
        * w = land_font_state->wordwrap_width;
    }
    if (h) {
        * h = land_font_state->wordwrap_height;
    }
}
void land_print_lines(LandArray * lines, int alignment) {
    /* Given an array of lines, print the visible ones.
     */
    float cl, ct, cr, cb;
    land_get_clip(& cl, & ct, & cr, & cb);
    float fh = land_font_state->font->size;
    float ty = land_text_y_pos();
    int first = (ct - ty) / fh;
    int last = (cb - ty) / fh;
    int n = land_array_count(lines);
    if (first < 0) {
        first = 0;
    }
    if (last > n - 1) {
        last = n - 1;
    }
    land_font_state->y_pos += fh * first;
    for (int i = first; i <= last; i++) {
        char * s = land_array_get_nth(lines, i);
        land_print_string(s, 1, alignment);
    }
}
LandFont* land_font_from_image(LandImage * image, int n_ranges, int * ranges) {
    LandFont * self = platform_font_from_image(image, n_ranges, ranges);
    land_font_state->font = self;
    return self;
}
    /* Drawing Primitives in Land
     * # Positions
     * The most basic information drawing primitives need is, where on the target
     * should they be drawn. There are several ways:
     * Relative screen coordinates. For example, 0/0 is the upper left screen edge, 1/1
     * the lower right screen edge. A rectangle from 0.1/0.1 to 0.9/0.9 would span 80%
     * of the width and the height of the screen, and leave a 10% border all around.
     * Obviously, using such coordinates is most useful if you don't want to care at
     * all about the actual resolution used.
     * Pixel coordinates. A coordinate is given in pixels. So, if you draw a line from
     * 1/1 to 2/2, the pixels at 1/1 and at 2/2 would be lit. This is what Land
     * originally used in its first incarnation, a very long time ago. This has some
     * disadvantages. Besides positions relying on the current resolution, it is also
     * impossible to specify sub-pixel behavior, for example when anti-aliasing is
     * switched on.
     * Subpixel coordinates. This is what Land uses by default, but you can easily
     * change it. It is a mixture of the two modes above. You give coordinates in pixel
     * positions (so positions depend on the resolution), but each integer position is
     * the upper left corner of a pixel, not the pixel as a whole, as in the method
     * before. To get the behavior of the previous method, you would do two things:
     * 1. For rectangles, draw them with their full width.
     * 2. For images, don't do anything.
     * To make clear why, let's compare a rectangle and an image. The rectangle is
     * drawn at pixel 0/0 with the pixel method, and 10x10
     * pixels big. So the pixels that are lit are from 0/0 to 9/9, inclusive. Doing the
     * same with the subpixel method, we would draw a rectangle from 0/0 to 10/10.
     * But what just happened? The rectangle of lit pixels before was 10x10 pixels big,
     * from pixel 0 to pixel 9 inclusive. The new subpixel rectangle also is 10x10
     * pixels big. Just now there is no more inclusive/exclusive pixels, the rectangle
     * coordinates are independent now.
     * The problem is, that what we really want with subpixel coordinates is not just
     * an outline anymore, but a frame which is one pixel thick. Its outer rectangle
     * would actually start at 0/0, and end at 10/10. Its inner rectangle would start
     * at 1/1 and end at 9/9. Drawing a single rectangle from 0.5/0.5 to 9.5/9.5 just
     * works, because we assumed a line-thickness of 1.
     * But with images, there is no line thickness. So if we draw an image which is
     * 10x10 pixels big, and we draw it to 0/0, it will exactly fit the same rectangle.
     * Would we draw it to 0.5/0.5, that just would be wrong.
     * Now, to make things easier, you don't have to use sub-pixel coordinates if you
     * absolutely don't want to. Call:
     * land_use_screen_positions()
     * to use the method which maps the screen to 0/0..1/1,
     * or
     * land_use_pixel_positions()
     * to use pixel positions. That is, Land will always lit the exact pixel you
     * specify, and also draw images correctly to full-pixel positions. In fact, this
     * mode just maps the coordinates like described above, so you still can use
     * non-integer positions (but there really is no reason to not use one of the other
     * two positioning modes then) and enable e.g. anti-aliasing.
     * # Primitives
     * ## line
     * This draws a line from the first point to the second point.
     * ## rectangle
     * This draws a rectangle from the first point to the second point.
     * ## filled_rectangle
     * Like rectangle, but filled.
     * ## circle/ellipse/oval
     * This draws a circle, inscribed into the given rectangle. The alternate names
     * "ellipse" and "oval" for this function actually fit better.
     * ## filled_circle
     * Like circle, but filled.
     */
static int resize_event_counter;
static int was_resized;
static int switch_out_event_counter;
static int was_switched_out;
static LandList * _previous;
LandDisplay * _land_active_display;
LandDisplay* land_display_new(int w, int h, int flags) {
    LandDisplay * self = platform_display_new();
    self->w = w;
    self->h = h;
    self->flags = flags;
    self->clip_x1 = 0;
    self->clip_y1 = 0;
    self->clip_x2 = w;
    self->clip_y2 = h;
    self->clip_off = 0;
    land_display_select(self);
    land_reset_transform();
    return self;
}
void land_display_destroy(LandDisplay * self) {
    if (self == _land_active_display) {
        land_display_unselect();
    }
    if (self->clip_stack_depth) {
        land_log_message("Error: non-empty clip stack in display.\n");
    }
    platform_display_del(self);
    land_free(self);
}
void land_display_del(LandDisplay * self) {
    land_display_destroy(self);
}
double land_scale_to_fit(float w, float h, int how) {
    float dw = land_display_width();
    float dh = land_display_height();
    float sx, sy;
    float ox = 0, oy = 0;
    int back = how >> 8;
    how &= 255;
    if (how == 0) {
        how = 2;
        if (w * dh / dw < h) {
            how = 3;
        }
    }
    if (how == 1) {
        how = 2;
        if (w * h / dw < dh) {
            how = 3;
        }
    }
    if (how == 4) {
        how = 6;
        if (w * dh / dw < h) {
            how = 7;
        }
    }
    if (how == 2 || how == 6) {
        sx = sy = dw / w;
        if (how == 2) {
            oy = (dh - h * sy) / 2;
        }
    }
    else if (how == 3 || how == 7) {
        sx = sy = dh / h;
        if (how == 3) {
            ox = (dw - w * sx) / 2;
        }
    }
    else {
        sx = dw / w;
        sy = dh / h;
    }
    land_reset_transform();
    if (back) {
        land_scale(1 / sx, 1 / sy);
        land_translate(- ox, - oy);
    }
    else {
        land_translate(ox, oy);
        land_scale(sx, sy);
    }
    return sx;
}
LandFloat land_get_left(void) {
    LandFloat * m = _land_active_display->matrix;
    return - m [3] / m [0];
}
LandFloat land_get_x_scale(void) {
    LandFloat * m = _land_active_display->matrix;
    return m [0];
}
void land_set_image_display(LandImage * image) {
    /* Change the display of the current thread to an internal display which draws
     * to the specified image. This cannot be nested.
     */
    platform_set_image_display(image);
}
void land_unset_image_display(void) {
    /* Restore the display to what it was before the call to
     * land_set_image_display.
     */
    platform_unset_image_display();
}
void land_display_set(void) {
    /* Make the active display of the current thread the active one. This may
     * involve creating a new window. There is usually no need to call this
     * function directly, as it will be called internally.
     */
    platform_display_set();
    platform_display_color();
    platform_display_clip();
}
LandDisplay* land_display_get(void) {
    /* Retrieve a handle to the currently active display of the calling thread.
     */
    return _land_active_display;
}
void land_display_unset(void) {
    /* Make the current display invalid. Usually there is no need for this.
     */
    _land_active_display = NULL;
}
void land_display_init(void) {
    land_log_message("land_display_init\n");
    _previous = land_list_new();
    platform_display_init();
}
void land_display_exit(void) {
    land_log_message("land_display_exit\n");
    land_list_destroy(_previous);
    platform_display_exit();
}
double land_display_time_flip_speed(double howlong) {
    /* This function is dangerous! It will completely halt Land for the passed
     * time in seconds.
     * The function will try to determine how long flipping of the display takes.
     * This can be used to see if the refresh rate is honored (usually because
     * vsync is enabled).
     */
    land_flip();
    double t = land_get_time();
    double t2;
    int i = 0;
    while ((t2 = land_get_time()) < t + howlong) {
        land_flip();
        i += 1;
    }
    return i / (t2 - t);
}
void land_display_toggle_fullscreen(void) {
    /* Toggle the current thread's display between windowed and fullscreen
     * mode, if possible.
     */
    LandDisplay * d = _land_active_display;
    d->flags ^= LAND_FULLSCREEN;
    if (d->flags & LAND_FULLSCREEN) {
        d->flags &= ~ LAND_WINDOWED;
    }
    else {
        d->flags |= LAND_WINDOWED;
    }
    land_display_set();
}
void land_clear(float r, float g, float b, float a) {
    /* Clear the current thread's display to the specified color. Always set
     * '''a''' to 1, or you may get a transparent background.
     */
    LandDisplay * d = _land_active_display;
    platform_display_clear(d, r, g, b, a);
}
void land_clear_depth(float z) {
    LandDisplay * d = _land_active_display;
    platform_display_clear_depth(d, z);
}
void land_color(float r, float g, float b, float a) {
    /* Change the color of the current thread's active display. This is the color
     * which will be used for subsequent graphics commands.
     */
    LandDisplay * d = _land_active_display;
    d->color_r = r;
    d->color_g = g;
    d->color_b = b;
    d->color_a = a;
    platform_display_color();
}
void land_premul(float r, float g, float b, float a) {
    land_color_set(land_color_premul(r, g, b, a));
}
void land_color_set(LandColor c) {
    land_color(c.r, c.g, c.b, c.a);
}
void land_thickness(float t) {
    LandDisplay * d = _land_active_display;
    d->thickness = t;
}
void land_get_color(float * r, float * g, float * b, float * a) {
    /* Retrieve the current color.
     */
    LandDisplay * d = _land_active_display;
    * r = d->color_r;
    * g = d->color_g;
    * b = d->color_b;
    * a = d->color_a;
}
int land_blend(int state) {
    LandDisplay * d = _land_active_display;
    int prev = d->blend;
    d->blend = state;
    return prev;
}
void land_clip(float x, float y, float x_, float y_) {
    LandDisplay * d = _land_active_display;
    d->clip_x1 = x;
    d->clip_y1 = y;
    d->clip_x2 = x_;
    d->clip_y2 = y_;
    platform_display_clip();
}
void land_clip_intersect(float x, float y, float x_, float y_) {
    LandDisplay * d = _land_active_display;
    d->clip_x1 = _scramble_max(d->clip_x1, x);
    d->clip_y1 = _scramble_max(d->clip_y1, y);
    d->clip_x2 = _scramble_min(d->clip_x2, x_);
    d->clip_y2 = _scramble_min(d->clip_y2, y_);
    platform_display_clip();
}
void land_clip_push(void) {
    LandDisplay * d = _land_active_display;
    if (d->clip_stack_depth > LAND_MAX_CLIP_DEPTH) {
        return ;
    }
    int * clip = d->clip_stack + d->clip_stack_depth * 5;
    clip [0] = d->clip_x1;
    clip [1] = d->clip_y1;
    clip [2] = d->clip_x2;
    clip [3] = d->clip_y2;
    clip [4] = d->clip_off;
    d->clip_stack_depth++;
}
void land_clip_pop(void) {
    LandDisplay * d = _land_active_display;
    if (d->clip_stack_depth < 1) {
        return ;
    }
    d->clip_stack_depth--;
    int * clip = d->clip_stack + d->clip_stack_depth * 5;
    d->clip_x1 = clip [0];
    d->clip_y1 = clip [1];
    d->clip_x2 = clip [2];
    d->clip_y2 = clip [3];
    d->clip_off = clip [4];
    platform_display_clip();
}
void land_clip_on(void) {
    LandDisplay * d = _land_active_display;
    d->clip_off = 0;
    platform_display_clip();
}
void land_clip_off(void) {
    LandDisplay * d = _land_active_display;
    d->clip_off = 1;
    platform_display_clip();
}
void land_unclip(void) {
    LandDisplay * d = _land_active_display;
    d->clip_x1 = 0;
    d->clip_y1 = 0;
    d->clip_x2 = land_display_width();
    d->clip_y2 = land_display_height();
    platform_display_clip();
}
int land_get_clip(float * cx1, float * cy1, float * cx2, float * cy2) {
    LandDisplay * d = _land_active_display;
    * cx1 = d->clip_x1;
    * cy1 = d->clip_y1;
    * cx2 = d->clip_x2;
    * cy2 = d->clip_y2;
    return ! d->clip_off;
}
void land_flip(void) {
    platform_display_flip();
}
void land_rectangle(float x, float y, float x_, float y_) {
    platform_rectangle(x, y, x_, y_);
}
void land_filled_rectangle(float x, float y, float x_, float y_) {
    platform_filled_rectangle(x, y, x_, y_);
}
void land_filled_circle(float x, float y, float x_, float y_) {
    platform_filled_circle(x, y, x_, y_);
}
void land_circle(float x, float y, float x_, float y_) {
    platform_circle(x, y, x_, y_);
}
void land_arc(float x, float y, float x_, float y_, float a, float a_) {
    platform_arc(x, y, x_, y_, a, a_);
}
void land_line(float x, float y, float x_, float y_) {
    platform_line(x, y, x_, y_);
}
void land_move_to(float x, float y) {
    LandDisplay * d = _land_active_display;
    d->cursor_x = x;
    d->cursor_y = y;
}
void land_line_to(float x, float y) {
    LandDisplay * d = _land_active_display;
    land_line(d->cursor_x, d->cursor_y, x, y);
    d->cursor_x = x;
    d->cursor_y = y;
}
void land_ribbon(int n, float * xy) {
    platform_ribbon(n, xy);
}
void land_ribbon_loop(int n, float * xy) {
    platform_ribbon_loop(n, xy);
}
void land_filled_ribbon(int n, float * xy) {
    platform_filled_ribbon(n, xy);
}
void land_polygon(int n, float * xy) {
    platform_polygon(n, xy);
}
void land_filled_polygon(int n, float * xy) {
    platform_filled_polygon(n, xy);
}
void land_filled_triangle(float x0, float y0, float x1, float y1, float x2, float y2) {
    float xy [6] = {x0, y0, x1, y1, x2, y2};
    platform_filled_polygon(3, xy);
}
void land_3d_triangles(int n, LandFloat * xyzrgb) {
    platform_3d_triangles(n, xyzrgb);
}
void land_textured_polygon(LandImage * image, int n, float * xy, float * uv) {
    platform_textured_polygon(image, n, xy, uv);
}
void land_filled_polygon_with_holes(int n, float * xy, int * holes) {
    platform_filled_polygon_with_holes(n, xy, holes);
}
void land_filled_colored_polygon(int n, float * xy, float * rgba) {
    platform_filled_colored_polygon(n, xy, rgba);
}
void land_plot(float x, float y) {
    platform_plot(x, y);
}
void land_pick_color(float x, float y) {
    platform_pick_color(x, y);
}
int land_display_width(void) {
    LandDisplay * self = _land_active_display;
    return self->w;
}
int land_display_height(void) {
    LandDisplay * self = _land_active_display;
    return self->h;
}
void land_display_resize(int w, int h) {
    /* Resize the current display to the given dimensions.
     */
    LandDisplay * d = _land_active_display;
    d->w = w;
    d->h = h;
    platform_display_resize(w, h);
}
void land_display_move(int x, int y) {
    platform_display_move(x, y);
}
void land_display_desktop_size(int * w, int * h) {
    platform_display_desktop_size(w, h);
}
void land_display_title(char const * title) {
    platform_display_title(title);
}
int land_display_flags(void) {
    LandDisplay * self = _land_active_display;
    return self->flags;
}
LandImage* land_display_new_image(void) {
    LandImage * image = platform_new_image();
    return image;
}
void land_display_del_image(LandImage * image) {
    return platform_del_image(image);
}
void land_display_select(LandDisplay * display) {
    if (_land_active_display) {
        land_add_list_data(& _previous, _land_active_display);
    }
    _land_active_display = display;
}
void land_display_unselect(void) {
    if (_previous && _previous->count) {
        LandListItem * last = _previous->last;
        _land_active_display = last->data;
        land_list_remove_item(_previous, last);
        land_listitem_destroy(last);
    }
    else {
        _land_active_display = NULL;
    }
}
void land_screenshot(char const * filename) {
    int w = land_display_width();
    int h = land_display_height();
    LandImage * screenshot = land_image_new(w, h);
    land_image_grab(screenshot, 0, 0);
    land_image_save(screenshot, filename);
    land_image_destroy(screenshot);
}
void land_screenshot_autoname(char const * name) {
    LandBuffer * b = land_buffer_new();
    time_t t = time(NULL);
    land_buffer_cat(b, name);
    land_buffer_cat(b, "_");
    land_buffer_cat(b, ctime(& t));
    land_buffer_strip(b, " \n");
    land_buffer_cat(b, ".jpg");
    char * path = land_buffer_finish(b);
    land_screenshot(path);
    land_free(path);
}
void land_resize_event(int w, int h) {
    resize_event_counter++;
    _land_active_display->w = w;
    _land_active_display->h = h;
    _land_active_display->clip_x2 = w;
    _land_active_display->clip_y2 = h;
}
void land_switch_out_event(void) {
    switch_out_event_counter++;
}
int land_switched_out(void) {
    return was_switched_out;
}
int land_was_resized(void) {
    return was_resized;
}
void land_display_tick(void) {
    was_resized = resize_event_counter;
    resize_event_counter = 0;
    was_switched_out = switch_out_event_counter;
    switch_out_event_counter = 0;
}
void land_rotate(LandFloat angle) {
    /* Pre-rotate the current transformation.
     */
    LandFloat * m = _land_active_display->matrix;
    LandFloat c = cosf(angle);
    LandFloat s = sinf(angle);
    LandFloat x, y;
    x = m [0];
    y = m [1];
    m [0] = x * (+ c) + y * (+ s);
    m [1] = x * (- s) + y * (+ c);
    x = m [4];
    y = m [5];
    m [4] = x * (+ c) + y * (+ s);
    m [5] = x * (- s) + y * (+ c);
    _land_active_display->matrix_modified = 1;
}
void land_scale(LandFloat x, LandFloat y) {
    /* Pre-scale the current transformation.
     */
    LandFloat * m = _land_active_display->matrix;
    m [0] *= x;
    m [1] *= y;
    m [4] *= x;
    m [5] *= y;
    _land_active_display->matrix_modified = 1;
}
void land_translate(LandFloat x, LandFloat y) {
    /* Pre-translate the current transformation. That is, any transformations in
     * effect prior to this call will be applied afterwards. And transformations
     * after this call until before the next drawing command will be applied
     * before.
     */
    LandFloat * m = _land_active_display->matrix;
    m [3] += x * m [0] + y * m [1];
    m [7] += x * m [4] + y * m [5];
    _land_active_display->matrix_modified = 1;
}
void land_z(LandFloat z) {
    LandFloat * m = _land_active_display->matrix;
    m [3] += z * m [2];
    m [7] += z * m [6];
    m [11] += z * m [10];
    _land_active_display->matrix_modified = 1;
}
void land_push_transform(void) {
    if (_land_active_display->matrix_stack_depth < 16) {
        int i = _land_active_display->matrix_stack_depth++;
        memcpy(_land_active_display->matrix_stack [i], _land_active_display->matrix, sizeof _land_active_display->matrix);
    }
}
void land_pop_transform(void) {
    if (_land_active_display->matrix_stack_depth > 0) {
        int i = --_land_active_display->matrix_stack_depth;
        memcpy(_land_active_display->matrix, _land_active_display->matrix_stack [i], sizeof _land_active_display->matrix);
        _land_active_display->matrix_modified = 1;
    }
}
void land_reset_transform(void) {
    LandFloat * m = _land_active_display->matrix;
    LandFloat i [16]={1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,};
    memcpy(m, i, sizeof i);
    _land_active_display->matrix_modified = 1;
}
void land_transform(LandFloat * x, LandFloat * y, LandFloat * z) {
    Land4x4Matrix m;
    memcpy(m.v, _land_active_display->matrix, sizeof m.v);
    LandVector v = land_vector_matmul(land_vector(* x, * y, * z), & m);
    * x = v.x;
    * y = v.y;
    * z = v.z;
}
void land_display_transform_4x4(Land4x4Matrix * matrix) {
    LandFloat * m = _land_active_display->matrix;
    for (int i = 0; i < 16; i += 1) {
        m [i] = matrix->v [i];
    }
    _land_active_display->matrix_modified = 1;
}
void land_render_state(int state, int value) {
    platform_render_state(state, value);
}
void land_display_set_default_shaders(void) {
    /* When using custom shaders, use this to restore the shader expected by the
     * builtin functions.
     */
    platform_set_default_shaders();
}
struct LandSoundPlatform {
    LandSound super;
    ALLEGRO_SAMPLE * a5;
    ALLEGRO_SAMPLE_ID last_playing;
    void * buffer;
};
struct LandStreamPlatform {
    LandStream super;
    ALLEGRO_AUDIO_STREAM * a5;
    void * fragment;
};
static LandArray * streaming;
static bool get_params(int channels, int bits, int * chan_conf, int * depth) {
    if (channels == 1) {
        * chan_conf = ALLEGRO_CHANNEL_CONF_1;
    }
    else if (channels == 2) {
        * chan_conf = ALLEGRO_CHANNEL_CONF_2;
    }
    else {
        return 0;
    }
    if (bits == 8) {
        * depth = ALLEGRO_AUDIO_DEPTH_INT8;
    }
    else if (bits == 16) {
        * depth = ALLEGRO_AUDIO_DEPTH_INT16;
    }
    else {
        return 0;
    }
    return 1;
}
LandSound* platform_sound_load(char const * filename) {
    LandSoundPlatform * self;
    land_alloc(self);
    self->a5 = al_load_sample(filename);
    self->super.filename = land_strdup(filename);
    return (void *) self;
}
LandSound* platform_sound_new(int samples, float frequency, int bits, int channels) {
    LandSoundPlatform * self;
    land_alloc(self);
    int chan_conf = 0, depth = 0;
    get_params(channels, bits, & chan_conf, & depth);
    int sample_size = al_get_channel_count(chan_conf) * al_get_audio_depth_size(depth);
    int bytes = samples * sample_size;
    self->buffer = land_malloc(bytes);
    self->a5 = al_create_sample(self->buffer, samples, frequency, depth, chan_conf, 0);
    return (void *) self;
}
void* platform_sound_sample_pointer(LandSound * super) {
    LandSoundPlatform * self = (void *) super;
    return al_get_sample_data(self->a5);
}
int platform_sound_length(LandSound * super) {
    LandSoundPlatform * self = (void *) super;
    return al_get_sample_length(self->a5);
}
double platform_sound_seconds(LandSound * super) {
    LandSoundPlatform * self = (void *) super;
    double x = al_get_sample_length(self->a5);
    x /= al_get_sample_frequency(self->a5);
    return x;
}
void platform_sound_play(LandSound * s, float volume, float pan, float frequency, bool loop) {
    LandSoundPlatform * self = (void *) s;
    al_play_sample(self->a5, volume, pan, frequency, loop ? ALLEGRO_PLAYMODE_LOOP : ALLEGRO_PLAYMODE_ONCE, & self->last_playing);
}
void platform_sound_stop(LandSound * s) {
    LandSoundPlatform * self = (void *) s;
    al_stop_sample(& self->last_playing);
}
void platform_sound_destroy(LandSound * s) {
    LandSoundPlatform * self = (void *) s;
    al_destroy_sample(self->a5);
    if (self->buffer) {
        land_free(self->buffer);
    }
    land_free(s->filename);
    land_free(s);
}
void platform_sound_init(void) {
    al_init_acodec_addon();
    al_install_audio();
    al_reserve_samples(8);
}
void platform_sound_exit(void) {
    ;
}
void platform_sound_resume(void) {
    al_restore_default_mixer();
    ALLEGRO_MIXER * mix = al_get_default_mixer();
    if (mix) {
        al_set_mixer_playing(mix, 1);
    }
}
void platform_sound_halt(void) {
    ALLEGRO_MIXER * mix = al_get_default_mixer();
    if (mix) {
        al_set_mixer_playing(al_get_default_mixer(), 0);
    }
    al_set_default_voice(NULL);
}
LandStream* platform_stream_new(int samples, int fragments, float frequency, int bits, int channels) {
    LandStreamPlatform * self;
    land_alloc(self);
    LandStream * super = (void *) self;
    int chan_conf = 0, depth = 0;
    get_params(channels, bits, & chan_conf, & depth);
    super->fragments = fragments;
    super->samples = samples;
    super->sample_size = al_get_channel_count(chan_conf) * al_get_audio_depth_size(depth);
    self->a5 = al_create_audio_stream(fragments, samples, frequency, depth, chan_conf);
    al_attach_audio_stream_to_mixer(self->a5, al_get_default_mixer());
    if (! streaming) {
        streaming = land_array_new();
    }
    land_array_add(streaming, self);
    return super;
}
void platform_stream_destroy(LandStream * super) {
    int i = land_array_find(streaming, super);
    if (i >= 0) {
        land_array_swap(streaming, i, - 1);
        land_array_pop(streaming);
    }
    LandStreamPlatform * self = (void *) super;
    al_destroy_audio_stream(self->a5);
    land_free(super);
}
void* platform_stream_buffer(LandStream * super) {
    LandStreamPlatform * self = (void *) super;
    if (al_get_available_audio_stream_fragments(self->a5) == 0) {
        return NULL;
    }
    self->fragment = al_get_audio_stream_fragment(self->a5);
    return self->fragment;
}
void platform_stream_fill(LandStream * super) {
    LandStreamPlatform * self = (void *) super;
    al_set_audio_stream_fragment(self->a5, self->fragment);
}
void platform_stream_music(LandStream * super, char const * filename) {
    LandStreamPlatform * self = (void *) super;
    al_destroy_audio_stream(self->a5);
    self->a5 = al_load_audio_stream(filename, super->fragments, super->samples);
    al_attach_audio_stream_to_mixer(self->a5, al_get_default_mixer());
    al_set_audio_stream_playmode(self->a5, ALLEGRO_PLAYMODE_LOOP);
}
void platform_stream_volume(LandStream * super, float volume) {
    LandStreamPlatform * self = (void *) super;
    al_set_audio_stream_gain(self->a5, volume);
}
bool platform_stream_is_playing(LandStream * super) {
    LandStreamPlatform * self = (void *) super;
    return al_get_audio_stream_playing(self->a5);
}
void platform_stream_set_playing(LandStream * super, bool onoff) {
    LandStreamPlatform * self = (void *) super;
    al_set_audio_stream_playing(self->a5, onoff);
}
struct PlatformThread {
    LandThread super;
    ALLEGRO_THREAD * a5;
};
struct PlatformLock {
    ALLEGRO_MUTEX * a5;
};
static void* proc(void * data) {
    LandThread * t = data;
    t->cb(t->data);
    land_free(t);
    return NULL;
}
void platform_thread_run(void(* cb)(void *), void * data) {
    LandThread * t;
    land_alloc(t);
    t->cb = cb;
    t->data = data;
    al_run_detached_thread(proc, t);
}
static void* aproc(ALLEGRO_THREAD * thread, void * arg) {
    LandThread * t = arg;
    t->cb(t->data);
    return NULL;
}
LandThread* platform_thread_new(void(* cb)(void * data), void * data) {
    PlatformThread * t;
    land_alloc(t);
    t->super.cb = cb;
    t->super.data = data;
    t->a5 = al_create_thread(aproc, t);
    al_start_thread(t->a5);
    return & t->super;
}
void platform_thread_destroy(LandThread * self) {
    PlatformThread * t = (void *) self;
    al_destroy_thread(t->a5);
    land_free(self);
}
LandLock* platform_thread_new_lock(void) {
    PlatformLock * l;
    land_alloc(l);
    l->a5 = al_create_mutex();
    return (void *) l;
}
void platform_thread_delete_lock(LandLock * lock) {
    PlatformLock * l = (void *) lock;
    al_destroy_mutex(l->a5);
    land_free(l);
}
void platform_thread_lock(LandLock * lock) {
    PlatformLock * l = (void *) lock;
    al_lock_mutex(l->a5);
}
void platform_thread_unlock(LandLock * lock) {
    PlatformLock * l = (void *) lock;
    al_unlock_mutex(l->a5);
}
void land_bind_vbo(GLuint * vbo, void * data, int n, int draw) {
    if (* vbo) {
        glBindBuffer(GL_ARRAY_BUFFER, * vbo);
        if (glGetError() == GL_INVALID_OPERATION) {
            * vbo = 0;
        }
    }
    if (! (* vbo)) {
        glGenBuffers(1, vbo);
        glBindBuffer(GL_ARRAY_BUFFER, * vbo);
        glBufferData(GL_ARRAY_BUFFER, n, data, draw);
    }
}
char const* land_opengl_error(void) {
    GLenum e = glGetError();
    if (e == GL_NO_ERROR) {
        return "GL_NO_ERROR";
    }
    if (e == GL_INVALID_ENUM) {
        return "GL_INVALID_ENUM";
    }
    if (e == GL_INVALID_VALUE) {
        return "GL_INVALID_VALUE";
    }
    if (e == GL_INVALID_OPERATION) {
        return "GL_INVALID_OPERATION";
    }
    if (e == GL_INVALID_FRAMEBUFFER_OPERATION) {
        return "GL_INVALID_FRAMEBUFFER_OPERATION";
    }
    if (e == GL_OUT_OF_MEMORY) {
        return "GL_OUT_OF_MEMORY";
    }
    return "unknown";
}
void land_4x4_matrix_to_gl_float(Land4x4Matrix m, GLfloat * gl) {
    gl [0x0] = m.v [0x0];
    gl [0x1] = m.v [0x4];
    gl [0x2] = m.v [0x8];
    gl [0x3] = m.v [0xc];
    gl [0x4] = m.v [0x1];
    gl [0x5] = m.v [0x5];
    gl [0x6] = m.v [0x9];
    gl [0x7] = m.v [0xd];
    gl [0x8] = m.v [0x2];
    gl [0x9] = m.v [0x6];
    gl [0xa] = m.v [0xa];
    gl [0xb] = m.v [0xe];
    gl [0xc] = m.v [0x3];
    gl [0xd] = m.v [0x7];
    gl [0xe] = m.v [0xb];
    gl [0xf] = m.v [0xf];
}
    /* Simple themeable widgets to use for in-game user interface elements.
     * This module implements a simple graphical user interface on top of Land.
     * = Some Features =
     * * Simple. This is intended to be used in-game, so no advanced features.
     * * A widget is basically a box. It can contain other boxes, to which mouse and
     * keyboard input is dispatched.
     * * Themeable, either with custom drawing, or bitmap themes.
     * = Mouse Focus =
     * Mouse focus is given to the window under the mouse, if the left button is not
     * being held. Else the focused window retains focus as long as the left mouse
     * button is being held pressed, even if the mouse leaves the window.
     * = Keyboard Focus =
     * Keyboard focus is only given to widgets requesting it. A focused window retains
     * keyboard focus, unless focus is transferred to another window.
     * A widget will normally ask for keyboard focus being transferred to it, when
     * the mouse is clicked over it, or when the TAB key is pressed and it is the
     * next in the widget cycle. This cycle is constructed by walking all widgets in
     * order, starting with the parent, then the children, recursively.
     * = Layout =
     * About using the auto layout:
     * * Each widget has an outer box, which is how much space it takes up inside
     * its parent.
     * * Additionally, it has an inner box, which is the space available to
     * children. The inner box is 6 values: il, it, ir, ib, hgap, vgap. The first
     * 4 are for a border all around the widget, the last 2 are gaps between
     * multiple children.
     * * The space between outer and inner box is usually filled with some kind of
     * border by the themeing.
     * * The layout allows layers, so child windows can share the same space.
     * * By default, container widgets try to fill up as much space as they can, so
     * if you place e.g. a VBox onto the desktop, it fills it up completely when
     * using auto layout. Non-container widgets on the other hand usually try to
     * be as small as possible, e.g. a button will try to fit around the text/image
     * inside it. You can of course change for each widget how it behaves.
     * = Themeing =
     * Each widget has a pointer to a theme. On creation, a widget inherits this
     * theme from its parent. So usually is is enough to set a theme for the
     * desktop, then all widgets spawned from it will inherit the theme. And it's
     * also easy to have per-widget themes, either for a single widget, or for a
     * window or menu. In the latter case, simply set the theme before creating
     * children.
     * Themes are built from bitmaps. This keeps them very simple, and should be
     * enough in most cases. And of course, if you absolutely don't want to, you
     * don't have to use themes. Simply override the draw method of all widgets
     * which you want to draw yourself.
     * = Polymorphism =
     * The widgets are organized in a class hierarchy. To use polymorphism, you need
     * to convert pointers to one class to pointers to a base or specialized class.
     * This is done using land_widget_check, which will use the widgets vtable to
     * assert that the conversion is possible and generate a runtime error
     * otherwise.
     * = Reference counting =
     * The widgets use reference counting to handle deletion. This is a cheap way
     * out of dealing with stale references/dangling pointers. A GUI without either reference counting
     * or garbage collection is possible, it just needs some more design work. In
     * our case here, following a KISS principle, we do simple naive reference counting,
     * and leave the user to deal with possible problems like circular references.
     * In the normal case, it works like this: You create a widget, and have to
     * pass along a parent widget to the constructor. Now, the parent will hold a
     * reference to the new widget. There is no reference from the child to the
     * parent, despite the parent field referencing the parent. This is done to
     * avoid complications with cyclic references. If your own widgets contain
     * cyclic references in another way, you should understand how the reference
     * counting works.
     * The first consequence of the above is, you always should manually reference the
     * top level window, since it has no parent it is referenced by.
     * The apparent problem is the possible dangling pointer of a child to its
     * parent. But it should be save, since whenever the parent is deleted, it will
     * delete all its children anyway.
     * = An example =
     * desktop = desktop_new()
     * reference(desktop)
     * child = window_new(desktop)
     * unreference(desktop)
     * This does what is expected. The only reference to desktop is removed manually,
     * therefore it gets destroyed. The destructor will detach all children. The only
     * child in this case will therefore drop its reference count to zero, and get
     * destroyed as well.
     * desktop = desktop_new()
     * reference(desktop)
     * child = window_new(desktop)
     * reference(child)
     * unreference(desktop)
     * Here, a reference is kept to child. Maybe it is the window with keyboard
     * focus, and the focus handler holds a reference to it. So, when the desktop
     * is destroyed, first all childs are detached again. This means, the parent
     * member of child is set to NULL, and its reference is decreased. Since there
     * is still the manual reference, nothing else will be done. The desktop itself
     * however is destroyed. Also note that any other childs without a reference
     * would be destroyed correctly, and it also would work recursively down for
     * their childs. Only the child window stays, and the focus handler won't
     * crash.
     * unreference(child)
     * If the focus handler is done, the reference of child will now drop to zero,
     * and it is destroyed as well.
     * Now, about cyclic references, just either don't use them, or else take care
     * to resolve them before dropping the last reference into the cycle. As an
     * example, you make a watchdog window, which somehow watches another window.
     * So, you play good, and along with storing a reference to that other window,
     * you increase the reference count of the other window, just so you never get
     * a dangling pointer. In your destructor, you release the reference again, so
     * everything seems to work out. But consider this:
     * desktop = new_widget(NULL)
     * reference(desktop)
     * watchdog = new_widget(desktop)
     * watchdog_watch(desktop)
     * unreference(desktop)
     * Yikes. Now you see the problem. Although nobody holds a reference to watchdog,
     * and we remove the only real reference to desktop, neither of them gets deleted.
     * Worse, neither of them can ever be deleted again, since the only reference to
     * either is from each other.
     * Simple rule here would be: The watchdog only ever should watch a sibling or
     * unrelated widget, never a parent. Of course, in practice, widgets could get
     * reparented and whatever, so things like this need watching out for. And there
     * are many other cases. Also, you never have to use the reference counting. You
     * just need to understand that Land provides no way to directly and forcefully
     * delete one of its widgets, and why it is like that.
     */
LandWidgetInterface * land_widget_base_interface;
static LandArray * land_widget_interfaces;
int land_widget_is(LandWidget const * self, int id) {
    /* Return true if the widget has the given type (or one derived from it).
     */
    int i;
    for (i = 0; i < 7; i++) {
        int digit = id & (0xf << (i * 4));
        if (! digit) {
            break;
        }
        if ((self->vt->id & (0xf << (i * 4))) != digit) {
            return 0;
        }
    }
    return 1;
}
void* land_widget_check(void const * ptr, int id, char const * file, int linenum) {
    LandWidget const * widget = ptr;
    if (land_widget_is(widget, id)) {
        return (void *) ptr;
    }
    land_exception("%s: %d: Widget cannot be converted.", file, linenum);
    return NULL;
}
char const* land_widget_info_string(LandWidget * w) {
    static char str [1024];
    if (! w) {
        strcpy(str, "none");
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_MENU)) {
        LandWidgetContainer * c = (void *) w;
        int n = 0;
        if (c->children) {
            n = c->children->count;
        }
        sprintf(str, "menu (%d items)", n);
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_MENUBAR)) {
        LandWidgetContainer * c = (void *) w;
        int n = 0;
        if (c->children) {
            n = c->children->count;
        }
        sprintf(str, "menubar (%d items)", n);
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_MENUITEM)) {
        LandWidgetButton * b = (void *) w;
        sprintf(str, "menuitem %s", b->text);
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_MENUBUTTON)) {
        LandWidgetButton * b = (void *) w;
        sprintf(str, "menubutton %s", b->text);
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_BUTTON)) {
        LandWidgetButton * b = (void *) w;
        sprintf(str, "button %s", b->text);
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_CHECKBOX)) {
        sprintf(str, "checkbox");
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_BOOK)) {
        sprintf(str, "book");
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_SCROLLING)) {
        sprintf(str, "scrolling");
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_SCROLLBAR)) {
        sprintf(str, "scrollbar");
    }
    else if (land_widget_is(w, LAND_WIDGET_ID_BOOKPAGE)) {
        sprintf(str, "bookpage");
    }
    else {
        sprintf(str, "unknown");
    }
    return str;
}
void land_widget_set_property(LandWidget * self, char const * property, void * data, void(* destroy)(void * data)) {
    if (! self->properties) {
        self->properties = land_hash_new();
    }
    LandWidgetProperty * prop;
    land_alloc(prop);
    prop->data = data;
    prop->destroy = destroy;
    land_hash_insert(self->properties, property, prop);
}
void land_widget_del_property(LandWidget * self, char const * property) {
    if (! self->properties) {
        return ;
    }
    LandWidgetProperty * prop = land_hash_remove(self->properties, property);
    if (prop->destroy) {
        prop->destroy(prop);
    }
}
void* land_widget_get_property(LandWidget * self, char const * property) {
    if (! self->properties) {
        return NULL;
    }
    LandWidgetProperty * prop = land_hash_get(self->properties, property);
    if (prop) {
        return prop->data;
    }
    return NULL;
}
void land_widget_remove_all_properties(LandWidget * self) {
    LandHash * hash = self->properties;
    if (! hash) {
        return ;
    }
    int i;
    for (i = 0; i < hash->size; i++) {
        if (hash->entries [i]) {
            int j;
            for (j = 0; j < hash->entries [i]->n; j++) {
                LandWidgetProperty * prop = hash->entries [i] [j].data;
                if (prop->destroy) {
                    prop->destroy(prop->data);
                }
                land_free(prop);
            }
        }
    }
    land_hash_destroy(self->properties);
    self->properties = NULL;
}
void land_widget_base_initialize(LandWidget * self, LandWidget * parent, int x, int y, int w, int h) {
    land_widget_base_interface_initialize();
    land_widget_layout_initialize(self, x, y, w, h);
    self->vt = land_widget_base_interface;
    land_widget_layout_set_minimum_size(self, w, h);
    if (parent) {
        if (parent->element) {
            self->element = land_widget_theme_find_element(parent->element->theme, self);
        }
        land_call_method(parent, add, (parent, self));
    }
    else {
        self->element = land_widget_theme_find_element(land_widget_theme_default(), self);
    }
}
LandWidget* land_widget_base_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidget * self;
    land_alloc(self);
    land_widget_base_initialize(self, parent, x, y, w, h);
    return self;
}
void land_widget_remove(LandWidget * self) {
    /* """Remove a widget from its parent."""
     */
    if (! self->parent) {
        return ;
    }
    land_call_method(self->parent, remove, (self->parent, self));
}
void land_widget_interfaces_destroy_all(void) {
    int n = land_array_count(land_widget_interfaces);
    land_log_message("land_widget_interfaces_destroy_all (%d)\n", n);
    int i;
    for (i = 0; i < n; i++) {
        LandWidgetInterface * f = land_array_get_nth(land_widget_interfaces, i);
        land_free(f->name);
        land_free(f);
    }
    land_array_destroy(land_widget_interfaces);
}
void land_widget_interface_register(LandWidgetInterface * vt) {
    /* """Register a new widget interface with Land.
     * The interface is then owned by Land, and you should not try to free the
     * passed pointer. Land will automatically free it when you call land_quit().
     */
    if (! land_widget_interfaces) {
        land_log_message("land_widget_interfaces\n");
        land_exit_function(land_widget_interfaces_destroy_all);
    }
    land_array_add_data(& land_widget_interfaces, vt);
}
LandWidgetInterface* land_widget_copy_interface(LandWidgetInterface * basevt, char const * name) {
    LandWidgetInterface * vt;
    land_alloc(vt);
    memcpy(vt, basevt, sizeof (* vt));
    vt->name = land_strdup(name);
    land_widget_interface_register(vt);
    return vt;
}
void land_widget_create_interface(LandWidget * widget, char const * name) {
    widget->vt = land_widget_copy_interface(widget->vt, name);
    land_widget_theme_update(widget);
}
void land_widget_base_destroy(LandWidget * self) {
    land_widget_remove_all_properties(self);
    _land_gul_box_deinitialize(& self->box);
    land_free(self);
}
static void land_widget_really_destroy(LandWidget * self) {
    if (self->vt->destroy) {
        self->vt->destroy(self);
    }
    else {
        land_log_message("*** widget without destructor?\n");
        land_widget_base_destroy(self);
    }
}
void land_widget_unreference(LandWidget * self) {
    self->reference--;
    if (self->reference <= 0) {
        land_widget_really_destroy(self);
    }
}
void land_widget_reference(LandWidget * self) {
    self->reference++;
}
void land_widget_base_mouse_enter(LandWidget * self, LandWidget * focus) {
    ;
}
void land_widget_base_mouse_leave(LandWidget * self, LandWidget * focus) {
    ;
}
void land_widget_base_move(LandWidget * self, float dx, float dy) {
    ;
}
void land_widget_move(LandWidget * self, float dx, float dy) {
    /* Moves the widget.
     */
    self->box.x += dx;
    self->box.y += dy;
    land_call_method(self, move, (self, dx, dy));
}
void land_widget_center(LandWidget * self) {
    int dw = land_display_width();
    int dh = land_display_height();
    int x = self->box.x;
    int y = self->box.y;
    int w = self->box.w;
    int h = self->box.h;
    land_widget_move(self, (dw - w) / 2 - x, (dh - h) / 2 - y);
}
void land_widget_base_size(LandWidget * self, float dx, float dy) {
    ;
}
void land_widget_size(LandWidget * self, float dx, float dy) {
    /* Resizes a widget.
     */
    self->box.w += dx;
    self->box.h += dy;
    land_call_method(self, size, (self, dx, dy));
}
void land_widget_resize(LandWidget * self, float dx, float dy) {
    /* Changes the minimum size of the widget to its current size modified by the
     * given offset.
     */
    self->box.min_width = self->box.w + dx;
    self->box.min_height = self->box.h + dy;
    land_widget_size(self, dx, dy);
}
void land_widget_set_size(LandWidget * self, float w, float h) {
    land_widget_resize(self, w - self->box.w, h - self->box.h);
}
void land_widget_retain_mouse_focus(LandWidget * self) {
    /* Called inside mouse_leave, will keep the mouse focus, and no other widget
     * can get highlighted.
     */
    self->got_mouse = 1;
}
void land_widget_refuse_mouse_focus(LandWidget * self) {
    /* Called inside mouse_enter, inhibits highlighting of the widget.
     */
    self->got_mouse = 0;
}
void land_widget_request_keyboard_focus(LandWidget * self) {
    /* Called in mouse_tick (or elsewhere), will cause the widget to receive the
     * keyboard focus.
     */
    self->want_focus = 1;
}
void land_widget_retain_keyboard_focus(LandWidget * self) {
    /* Called in keyboard_leave to keep the focus. Doesn't usually make sense.
     */
    self->got_keyboard = 1;
}
void land_widget_tick(LandWidget * self) {
    /* Call this regularly on your desktop widget. It's the base function which is
     * needed in any widgets application to handle input to the widgets. The other
     * important function is land_widget_draw, which handles display of widgets.
     */
    land_call_method(self, tick, (self));
}
void land_widget_draw(LandWidget * self) {
    /* Draw a widget on its current position. Call this on your desktop widget to
     * display all of your widgets. This function and land_widget_tick are the two
     * functions you should call on your desktop widget in each widgets using
     * application.
     */
    if (self->hidden) {
        return ;
    }
    int pop = 0;
    if (! self->dont_clip) {
        land_clip_push();
        land_clip_on();
        land_clip_intersect(self->box.x, self->box.y, self->box.x + self->box.w, self->box.y + self->box.h);
        pop = 1;
    }
    land_call_method(self, draw, (self));
    if (pop) {
        land_clip_pop();
    }
}
void land_widget_hide(LandWidget * self) {
    /* Hide the widget. It will not be displayed anymore, and also not take up any
     * more space.
     */
    if (self->hidden) {
        return ;
    }
    self->hidden = 1;
    self->box.flags |= GUL_HIDDEN;
    if (self->parent) {
        land_widget_layout(self->parent);
    }
}
void land_widget_unhide(LandWidget * self) {
    /* Unhide the widget.
     */
    if (! self->hidden) {
        return ;
    }
    self->hidden = 0;
    self->box.flags &= ~ GUL_HIDDEN;
    if (self->parent) {
        land_widget_layout(self->parent);
    }
}
void land_widget_outer(LandWidget * self, float * x, float * y, float * w, float * h) {
    * x = self->box.x;
    * y = self->box.y;
    * w = self->box.w;
    * h = self->box.h;
}
void land_widget_inner(LandWidget * self, float * x, float * y, float * w, float * h) {
    * x = self->box.x;
    * y = self->box.y;
    * w = self->box.w;
    * h = self->box.h;
    if (self->element) {
        * x += self->element->il;
        * y += self->element->it;
        * w -= self->element->ir + self->element->ir;
        * h -= self->element->ib + self->element->ib;
    }
}
void land_widget_inner_extents(LandWidget * self, float * l, float * t, float * r, float * b) {
    * l = self->box.x;
    * t = self->box.y;
    * r = self->box.x + self->box.w;
    * b = self->box.y + self->box.h;
    if (self->element) {
        * l += self->element->il;
        * t += self->element->it;
        * r -= self->element->ir;
        * b -= self->element->ib;
    }
}
void land_widget_base_interface_initialize(void) {
    if (land_widget_base_interface) {
        return ;
    }
    land_alloc(land_widget_base_interface);
    land_widget_interface_register(land_widget_base_interface);
    land_widget_base_interface->id = LAND_WIDGET_ID_BASE;
    land_widget_base_interface->name = land_strdup("base");
    land_widget_base_interface->size = land_widget_base_size;
    land_widget_base_interface->destroy = land_widget_base_destroy;
}
void land_widget_debug(LandWidget * w, int indentation) {
    for (int i = 0; i < indentation; i += 1) {
        printf("  ");
    }
    printf("%s %d %d %d %d\n", land_widget_info_string(w), w->box.x, w->box.y, w->box.w, w->box.h);
    if (land_widget_is(w, LAND_WIDGET_ID_CONTAINER)) {
        LandWidgetContainer * c = LAND_WIDGET_CONTAINER(w);
        if (c->children) {
            {
                LandListIterator __iter0__ = LandListIterator_first(c->children);
                for (LandWidget * child = LandListIterator_item(c->children, &__iter0__); LandListIterator_next(c->children, &__iter0__); child = LandListIterator_item(c->children, &__iter0__)) {
                    land_widget_debug(child, indentation + 1);
                }
            }
        }
    }
}
static const int COPLANAR = 0;
static const int FRONT = 1;
static const int BACK = 2;
static const int SPANNING = 3;
LandCSGVertex* land_csg_vertex_new(LandVector pos, LandVector normal) {
    LandCSGVertex * self;
    land_alloc(self);
    self->pos = pos;
    self->normal = normal;
    return self;
}
void land_csg_vertex_destroy(LandCSGVertex * self) {
    land_free(self);
}
LandCSGVertex* land_csg_vertex_new_pool(LandMemoryPool * pool) {
    LandCSGVertex * self = land_pool_alloc(pool, sizeof (* self));
    return self;
}
LandCSGVertex* csg_vertex_clone(LandCSG * csg, LandCSGVertex * self, bool pool) {
    LandCSGVertex * v;
    if (pool) {
        v = land_csg_vertex_new_pool(csg->pool);
    }
    else {
        land_alloc(v);
    }
    v->pos = self->pos;
    v->normal = self->normal;
    v->rgba = self->rgba;
    return v;
}
static int collision_code(LandVector * v, LandCSGAABB * b) {
    int c = 0;
    if (v->x < b->x1) {
        c |= 1;
    }
    if (v->x > b->x2) {
        c |= 2;
    }
    if (v->y < b->y1) {
        c |= 4;
    }
    if (v->y > b->y2) {
        c |= 8;
    }
    if (v->z < b->z1) {
        c |= 16;
    }
    if (v->z > b->z2) {
        c |= 32;
    }
    return c;
}
static bool polygon_intersects_aabb(LandCSGPolygon * polygon, LandCSGAABB * box) {
    int a = 0, b = 0;
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(polygon->vertices);
        for (LandCSGVertex * v = LandArrayIterator_item(polygon->vertices, &__iter0__); LandArrayIterator_next(polygon->vertices, &__iter0__); v = LandArrayIterator_item(polygon->vertices, &__iter0__)) {
            int c = collision_code(& v->pos, box);
            if (c == 0) {
                return 1;
            }
            a |= c;
            b |= ~ c;
        }
    }
    if (((a ^ b) & 63) != 0) {
        return 0;
    }
    return 1;
}
static LandArray* clone_vertices(LandCSG * csg, LandArray * vertices) {
    LandArray * clone = land_array_copy(vertices);
    int n = land_array_count(clone);
    for (int i = 0; i < n; i += 1) {
        clone->data [i] = csg_vertex_clone(csg, clone->data [i], 1);
    }
    return clone;
}
static void remove_vertices(LandArray * vertices, bool is_pooled) {
    if (! is_pooled) {
        for (int i = 0; i < vertices->count; i += 1) {
            land_csg_vertex_destroy(vertices->data [i]);
        }
    }
    land_array_destroy(vertices);
}
static void csg_vertex_flip(LandCSGVertex * self) {
    self->normal = land_vector_mul(self->normal, - 1);
}
static LandCSGVertex* csg_vertex_interpolate(LandCSG * csg, LandCSGVertex * self, LandCSGVertex * other, LandFloat t) {
    LandCSGVertex * v = land_csg_vertex_new_pool(csg->pool);
    v->pos = land_vector_lerp(self->pos, other->pos, t);
    v->normal = land_vector_lerp(self->normal, other->normal, t);
    v->rgba = land_color_lerp(self->rgba, other->rgba, t);
    return v;
}
static LandCSGPlane csg_plane(LandVector normal, LandFloat w) {
    LandCSGPlane self;
    self.normal = normal;
    self.w = w;
    return self;
}
static const LandFloat LandCSGPlaneEPSILON = 0.00001;
static LandCSGPlane csg_plane_from_points(LandVector a, LandVector b, LandVector c) {
    LandVector ac = land_vector_sub(c, a);
    LandVector ab = land_vector_sub(b, a);
    LandVector n = land_vector_cross(ab, ac);
    n = land_vector_normalize(n);
    return csg_plane(n, land_vector_dot(n, a));
}
void land_csg_polygon_init(LandCSGPolygon * self, LandArray * vertices, void * shared) {
    self->vertices = vertices;
    self->shared = shared;
    LandCSGVertex * v0 = land_array_get_nth(vertices, 0);
    LandCSGVertex * v1 = land_array_get_nth(vertices, 1);
    LandCSGVertex * v2 = land_array_get_nth(vertices, 2);
    self->plane = csg_plane_from_points(v0->pos, v1->pos, v2->pos);
}
LandCSGPolygon* land_csg_polygon_new(LandArray * vertices, void * shared) {
    LandCSGPolygon * self;
    land_alloc(self);
    land_csg_polygon_init(self, vertices, shared);
    return self;
}
static LandCSGPolygon* land_csg_polygon_new_pool(LandMemoryPool * pool, LandArray * vertices, void * shared) {
    LandCSGPolygon * p = land_pool_alloc(pool, sizeof (* p));
    p->is_pooled = 1;
    land_csg_polygon_init(p, vertices, shared);
    return p;
}
void csg_plane_flip(LandCSGPlane * self) {
    self->normal = land_vector_mul(self->normal, - 1);
    self->w *= - 1;
}
static void csg_plane_split_polygon(LandCSG * csg, LandCSGPlane * self, LandCSGPolygon * polygon, LandArray * coplanar_front, LandArray * coplanar_back, LandArray * front, LandArray * back) {
    int polygon_type = 0;
    int n = land_array_count(polygon->vertices);
    int i = 0;
    int types [n];
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(polygon->vertices);
        for (LandCSGVertex * v = LandArrayIterator_item(polygon->vertices, &__iter0__); LandArrayIterator_next(polygon->vertices, &__iter0__); v = LandArrayIterator_item(polygon->vertices, &__iter0__)) {
            LandFloat dot = land_vector_dot(self->normal, v->pos) - self->w;
            int t = (dot < - LandCSGPlaneEPSILON ? BACK : dot > LandCSGPlaneEPSILON ? FRONT : COPLANAR);
            polygon_type |= t;
            types [i++] = t;
        }
    }
    assert(i == n);
    if (polygon_type == COPLANAR) {
        if (land_vector_dot(self->normal, polygon->plane.normal) > 0) {
            land_array_add(coplanar_front, polygon);
        }
        else {
            land_array_add(coplanar_back, polygon);
        }
    }
    else if (polygon_type == FRONT) {
        land_array_add(front, polygon);
    }
    else if (polygon_type == BACK) {
        land_array_add(back, polygon);
    }
    else if (polygon_type == SPANNING) {
        LandArray * f = land_array_new();
        LandArray * b = land_array_new();
        for (i = 0; i < n; i += 1) {
            int j = (i + 1) % n;
            int ti = types [i];
            int tj = types [j];
            LandCSGVertex * vi = land_array_get_nth(polygon->vertices, i);
            LandCSGVertex * vj = land_array_get_nth(polygon->vertices, j);
            if (ti == FRONT) {
                land_array_add(f, csg_vertex_clone(csg, vi, 1));
            }
            else if (ti == BACK) {
                land_array_add(b, csg_vertex_clone(csg, vi, 1));
            }
            else if (ti == COPLANAR) {
                land_array_add(f, csg_vertex_clone(csg, vi, 1));
                land_array_add(b, csg_vertex_clone(csg, vi, 1));
            }
            if ((ti | tj) == SPANNING) {
                LandFloat t = self->w - land_vector_dot(self->normal, vi->pos);
                t /= land_vector_dot(self->normal, land_vector_sub(vj->pos, vi->pos));
                LandCSGVertex * v = csg_vertex_interpolate(csg, vi, vj, t);
                land_array_add(f, v);
                land_array_add(b, csg_vertex_clone(csg, v, 1));
            }
        }
        if (land_array_count(f) >= 3) {
            LandCSGPolygon * add = land_csg_polygon_new_pool(csg->pool, f, polygon->shared);
            land_array_add(front, add);
        }
        else {
            remove_vertices(f, true);
        }
        if (land_array_count(b) >= 3) {
            LandCSGPolygon * add = land_csg_polygon_new_pool(csg->pool, b, polygon->shared);
            land_array_add(back, add);
        }
        else {
            remove_vertices(b, true);
        }
        land_csg_polygon_destroy(polygon);
    }
}
void land_csg_polygon_destroy(LandCSGPolygon * self) {
    if (self->is_pooled) {
        land_array_destroy(self->vertices);
    }
    else {
        remove_vertices(self->vertices, false);
        land_free(self);
    }
}
LandCSGPolygon* land_csg_polygon_clone(LandCSG * csg, LandCSGPolygon const * self) {
    LandCSGPolygon * clone = land_csg_polygon_new_pool(csg->pool, clone_vertices(csg, self->vertices), self->shared);
    return clone;
}
static void csg_polygon_flip(LandCSGPolygon * self) {
    land_array_reverse(self->vertices);
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->vertices);
        for (LandCSGVertex * v = LandArrayIterator_item(self->vertices, &__iter0__); LandArrayIterator_next(self->vertices, &__iter0__); v = LandArrayIterator_item(self->vertices, &__iter0__)) {
            csg_vertex_flip(v);
        }
    }
    csg_plane_flip(& self->plane);
}
static LandArray* clone_polygons(LandCSG * csg, LandArray * polygons) {
    LandArray * clone = land_array_copy(polygons);
    int n = land_array_count(clone);
    for (int i = 0; i < n; i += 1) {
        clone->data [i] = land_csg_polygon_clone(csg, clone->data [i]);
    }
    return clone;
}
static void clear_polygons(LandArray * polygons) {
    for (int i = 0; i < polygons->count; i += 1) {
        land_csg_polygon_destroy(polygons->data [i]);
    }
    land_array_clear(polygons);
}
static void csg_node_destroy(LandCSGNode * self) {
    if (self->front) {
        csg_node_destroy(self->front);
    }
    if (self->back) {
        csg_node_destroy(self->back);
    }
    clear_polygons(self->polygons);
    land_array_destroy(self->polygons);
    land_free(self);
}
static void csg_node_invert(LandCSGNode * self) {
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(self->polygons, &__iter0__); LandArrayIterator_next(self->polygons, &__iter0__); p = LandArrayIterator_item(self->polygons, &__iter0__)) {
            csg_polygon_flip(p);
        }
    }
    csg_plane_flip(& self->plane);
    if (self->front) {
        csg_node_invert(self->front);
    }
    if (self->back) {
        csg_node_invert(self->back);
    }
    LandCSGNode * temp = self->front;
    self->front = self->back;
    self->back = temp;
}
static void csg_node_clip_polygons(LandCSG * csg, LandCSGNode * self, LandArray * polygons) {
    if (! self->plane.normal.z && ! self->plane.normal.y && ! self->plane.normal.x) {
        return ;
    }
    LandArray * front = land_array_new();
    LandArray * back = land_array_new();
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(polygons, &__iter0__); LandArrayIterator_next(polygons, &__iter0__); p = LandArrayIterator_item(polygons, &__iter0__)) {
            csg_plane_split_polygon(csg, & self->plane, p, front, back, front, back);
        }
    }
    land_array_clear(polygons);
    if (self->front) {
        csg_node_clip_polygons(csg, self->front, front);
    }
    if (self->back) {
        csg_node_clip_polygons(csg, self->back, back);
    }
    else {
        clear_polygons(back);
    }
    land_array_concat(polygons, front);
    land_array_concat(polygons, back);
    land_array_destroy(front);
    land_array_destroy(back);
}
static void csg_node_clip_to(LandCSG * csg, LandCSGNode * self, LandCSGNode * bsp) {
    csg_node_clip_polygons(csg, bsp, self->polygons);
    if (self->front) {
        csg_node_clip_to(csg, self->front, bsp);
    }
    if (self->back) {
        csg_node_clip_to(csg, self->back, bsp);
    }
}
static LandArray* csg_node_all_polygons(LandCSG * csg, LandCSGNode * self) {
    LandArray * polygons = clone_polygons(csg, self->polygons);
    if (self->front) {
        land_array_merge(polygons, csg_node_all_polygons(csg, self->front));
    }
    if (self->back) {
        land_array_merge(polygons, csg_node_all_polygons(csg, self->back));
    }
    return polygons;
}
static void csg_add_polygons_from_node(LandCSG * csg, LandCSGNode * node) {
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(node->polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(node->polygons, &__iter0__); LandArrayIterator_next(node->polygons, &__iter0__); p = LandArrayIterator_item(node->polygons, &__iter0__)) {
            land_array_add(csg->polygons, land_csg_polygon_clone(csg, p));
        }
    }
    if (node->front) {
        csg_add_polygons_from_node(csg, node->front);
    }
    if (node->back) {
        csg_add_polygons_from_node(csg, node->back);
    }
}
static void csg_add_polygons(LandCSG * csg, LandArray * polygons) {
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(polygons, &__iter0__); LandArrayIterator_next(polygons, &__iter0__); p = LandArrayIterator_item(polygons, &__iter0__)) {
            land_array_add(csg->polygons, land_csg_polygon_clone(csg, p));
        }
    }
}
static void csg_node_build(LandCSG * csg, LandCSGNode * self, LandArray * polygons) {
    if (! land_array_count(polygons)) {
        land_array_destroy(polygons);
        return ;
    }
    if (! self->plane.normal.z && ! self->plane.normal.y && ! self->plane.normal.x) {
        LandCSGPolygon * p0 = land_array_get_nth(polygons, 0);
        self->plane = p0->plane;
    }
    LandArray * front = land_array_new();
    LandArray * back = land_array_new();
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(polygons, &__iter0__); LandArrayIterator_next(polygons, &__iter0__); p = LandArrayIterator_item(polygons, &__iter0__)) {
            csg_plane_split_polygon(csg, & self->plane, p, self->polygons, self->polygons, front, back);
        }
    }
    land_array_destroy(polygons);
    if (land_array_count(front)) {
        if (! self->front) {
            self->front = csg_node_new(csg, NULL);
        }
        csg_node_build(csg, self->front, front);
    }
    else {
        land_array_destroy(front);
    }
    if (land_array_count(back)) {
        if (! self->back) {
            self->back = csg_node_new(csg, NULL);
        }
        csg_node_build(csg, self->back, back);
    }
    else {
        land_array_destroy(back);
    }
}
static LandCSGNode* csg_node_new(LandCSG * csg, LandArray * polygons) {
    LandCSGNode * self;
    land_alloc(self);
    self->polygons = land_array_new();
    if (polygons) {
        csg_node_build(csg, self, polygons);
    }
    return self;
}
void land_csg_transform(LandCSG * self, Land4x4Matrix matrix) {
    Land4x4Matrix matrix2 = * (& matrix);
    matrix2.v [3] = 0;
    matrix2.v [7] = 0;
    matrix2.v [11] = 0;
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(self->polygons, &__iter0__); LandArrayIterator_next(self->polygons, &__iter0__); p = LandArrayIterator_item(self->polygons, &__iter0__)) {
            {
                LandArrayIterator __iter1__ = LandArrayIterator_first(p->vertices);
                for (LandCSGVertex * v = LandArrayIterator_item(p->vertices, &__iter1__); LandArrayIterator_next(p->vertices, &__iter1__); v = LandArrayIterator_item(p->vertices, &__iter1__)) {
                    v->pos = land_vector_matmul(v->pos, & matrix);
                    v->normal = land_vector_normalize(land_vector_matmul(v->normal, & matrix2));
                }
            }
        }
    }
}
void land_csg_destroy(LandCSG * self) {
    clear_polygons(self->polygons);
    land_array_destroy(self->polygons);
    land_pool_destroy(self->pool);
    land_free(self);
}
void land_csg_triangles(LandCSG * self) {
    LandArray * triangles = NULL;
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(self->polygons, &__iter0__); LandArrayIterator_next(self->polygons, &__iter0__); p = LandArrayIterator_item(self->polygons, &__iter0__)) {
            int n = land_array_count(p->vertices);
            if (n == 3) {
                continue;
            }
            if (! triangles) {
                triangles = land_array_new();
            }
            LandCSGVertex * a = land_array_get_nth(p->vertices, 0);
            LandCSGVertex * b = land_array_get_nth(p->vertices, 2);
            for (int i = 3; i < n; i += 1) {
                LandCSGVertex * c = land_array_get_nth(p->vertices, i);
                LandArray * v = land_array_new();
                land_array_add(v, csg_vertex_clone(self, a, p->is_pooled));
                land_array_add(v, csg_vertex_clone(self, b, p->is_pooled));
                land_array_add(v, c);
                LandCSGPolygon * triangle;
                if (p->is_pooled) {
                    triangle = land_csg_polygon_new_pool(self->pool, v, p->shared);
                }
                else {
                    triangle = land_csg_polygon_new(v, p->shared);
                }
                land_array_add(triangles, triangle);
                b = c;
            }
            p->vertices->count = 3;
        }
    }
    if (triangles) {
        land_array_merge(self->polygons, triangles);
    }
}
LandCSG* land_csg_new(void) {
    LandCSG * self;
    land_alloc(self);
    self->pool = land_pool_new();
    return self;
}
LandCSG* land_csg_new_from_polygons(LandArray * polygons) {
    LandCSG * self = land_csg_new();
    self->polygons = polygons;
    return self;
}
LandCSG* land_csg_clone(LandCSG * self) {
    LandCSG * csg = land_csg_new();
    csg->polygons = clone_polygons(csg, self->polygons);
    return csg;
}
static void csg_split_on_bounding_box(LandCSG const * self, LandCSGAABB * box, LandArray * (* inside), LandArray * (* outside)) {
    /* Keep every polygon intersecting the bounding box, return the removed ones.
     * TODO: we could use a cached BSP for an extra fast bounding box check,
     * as soon as we see that the bounding box is on one side of a BSP node we
     * can ignore the other side completely.
     */
    * inside = land_array_new();
    * outside = land_array_new();
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(self->polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(self->polygons, &__iter0__); LandArrayIterator_next(self->polygons, &__iter0__); p = LandArrayIterator_item(self->polygons, &__iter0__)) {
            if (polygon_intersects_aabb(p, box)) {
                land_array_add(* inside, p);
            }
            else {
                land_array_add(* outside, p);
            }
        }
    }
}
LandCSG* land_csg_union(LandCSG * csg_a, LandCSG * csg_b) {
    LandCSG * c = land_csg_new();
    land_csg_aabb_update(& csg_a->bbox, csg_a->polygons);
    land_csg_aabb_update(& csg_b->bbox, csg_b->polygons);
    LandCSGAABB box = land_csg_aabb_intersect(csg_a->bbox, csg_b->bbox);
    LandArray * a_out, * a_in, * b_out, * b_in;
    csg_split_on_bounding_box(csg_a, & box, & a_in, & a_out);
    csg_split_on_bounding_box(csg_b, & box, & b_in, & b_out);
    LandCSGNode * a = csg_node_new(c, clone_polygons(c, a_in));
    LandCSGNode * b = csg_node_new(c, clone_polygons(c, b_in));
    csg_node_clip_to(c, a, b);
    csg_node_clip_to(c, b, a);
    if (1) {
        csg_node_invert(b);
        csg_node_clip_to(c, b, a);
        csg_node_invert(b);
    }
    c->polygons = land_array_new();
    csg_add_polygons_from_node(c, a);
    csg_add_polygons_from_node(c, b);
    csg_add_polygons(c, a_out);
    csg_add_polygons(c, b_out);
    land_array_destroy(a_in);
    land_array_destroy(a_out);
    land_array_destroy(b_in);
    land_array_destroy(b_out);
    csg_node_destroy(a);
    csg_node_destroy(b);
    return c;
}
LandCSG* land_csg_subtract(LandCSG * self, LandCSG * csg) {
    LandCSG * c = land_csg_new();
    LandCSGNode * a = csg_node_new(c, clone_polygons(c, self->polygons));
    LandCSGNode * b = csg_node_new(c, clone_polygons(c, csg->polygons));
    csg_node_invert(a);
    csg_node_clip_to(c, a, b);
    csg_node_clip_to(c, b, a);
    csg_node_invert(b);
    csg_node_clip_to(c, b, a);
    csg_node_invert(b);
    csg_node_build(c, a, csg_node_all_polygons(c, b));
    csg_node_invert(a);
    c->polygons = csg_node_all_polygons(c, a);
    csg_node_destroy(a);
    csg_node_destroy(b);
    return c;
}
LandCSG* land_csg_intersect(LandCSG * self, LandCSG * csg) {
    LandCSG * c = land_csg_new();
    LandCSGNode * a = csg_node_new(c, clone_polygons(c, self->polygons));
    LandCSGNode * b = csg_node_new(c, clone_polygons(c, csg->polygons));
    csg_node_invert(a);
    csg_node_clip_to(c, b, a);
    csg_node_invert(b);
    csg_node_clip_to(c, a, b);
    csg_node_clip_to(c, b, a);
    csg_node_build(c, a, csg_node_all_polygons(c, b));
    csg_node_invert(a);
    c->polygons = csg_node_all_polygons(c, a);
    csg_node_destroy(a);
    csg_node_destroy(b);
    return c;
}
LandCSG* land_csg_inverse(LandCSG * self) {
    LandCSG * csg = land_csg_clone(self);
    {
        LandArrayIterator __iter0__ = LandArrayIterator_first(csg->polygons);
        for (LandCSGPolygon * p = LandArrayIterator_item(csg->polygons, &__iter0__); LandArrayIterator_next(csg->polygons, &__iter0__); p = LandArrayIterator_item(csg->polygons, &__iter0__)) {
            csg_polygon_flip(p);
        }
    }
    return csg;
}
static LandGridInterface * land_grid_vtable_sprites;
LandGrid* land_sprites_grid_new(int cell_w, int cell_h, int x_cells, int y_cells) {
    LandSpritesGrid * self;
    land_alloc(self);
    land_grid_initialize(& self->super, cell_w, cell_h, x_cells, y_cells);
    self->super.vt = land_grid_vtable_sprites;
    self->sprites = land_calloc(x_cells * y_cells * sizeof (* self->sprites));
    return & self->super;
}
void land_sprites_grid_resize(LandGrid * super, int cell_w, int cell_h, int x_cells, int y_cells) {
    LandSpritesGrid * self = (void *) super;
    land_sprites_grid_clear(super);
    land_free(self->sprites);
    self->sprites = land_calloc(x_cells * y_cells * sizeof (* self->sprites));
    super->x_cells = x_cells;
    super->y_cells = y_cells;
    super->cell_w = cell_w;
    super->cell_h = cell_h;
}
void land_sprites_grid_clear(LandGrid * super) {
    /* Removes all sprites from a grid, but does not destroy them.
     */
    LandSpritesGrid * self = LAND_SPRITES_GRID(super);
    int j;
    for (j = 0; j < super->x_cells * super->y_cells; j++) {
        if (self->sprites [j]) {
            land_list_destroy(self->sprites [j]);
            self->sprites [j] = NULL;
        }
    }
}
void land_sprites_grid_del(LandGrid * super) {
    /* Deletes a sprites grid. The sprites themselves are not destroyed.
     */
    land_sprites_grid_clear(super);
    LandSpritesGrid * self = LAND_SPRITES_GRID(super);
    land_free(self->sprites);
    land_free(self);
}
static void dummy(LandSprite * self, LandView * view) {
    float x = (self->x - view->scroll_x) * view->scale_x + view->x;
    float y = (self->y - view->scroll_y) * view->scale_y + view->y;
    land_color(1, 0, 0, 1);
    land_rectangle(x, y, x + self->type->w * view->scale_x, y + self->type->h * view->scale_y);
}
static void dummy_image(LandSprite * self, LandView * view) {
    LandSpriteTypeImage * image = LAND_SPRITE_TYPE_IMAGE(self->type);
    float x = (self->x - view->scroll_x) * view->scale_x + view->x;
    float y = (self->y - view->scroll_y) * view->scale_y + view->y;
    land_image_draw_scaled_rotated_tinted_flipped(image->image, x, y, view->scale_x, view->scale_y, self->angle, view->r, view->g, view->b, view->a, self->flipped);
    #ifdef DEBUG_MASK
    if (image->image->mask) {
        land_image_debug_pixelmask(image->image, x, y, self->angle, self->flipped);
    }
    #endif
}
static void dummy_animation(LandSprite * self, LandView * view) {
    LandSpriteTypeAnimation * animation = (LandSpriteTypeAnimation *) self->type;
    LandSpriteAnimated * animated = (LandSpriteAnimated *) self;
    float x = (self->x - view->scroll_x) * view->scale_x + view->x;
    float y = (self->y - view->scroll_y) * view->scale_y + view->y;
    LandImage * image;
    if (animation->animation) {
        image = land_animation_get_frame(animation->animation, animated->frame);
    }
    else {
        image = animation->super.image;
    }
    land_image_draw_scaled_rotated_tinted(image, x, y, animated->sx * view->scale_x, animated->sy * view->scale_y, self->angle, animated->r * view->r, animated->g * view->g, animated->b * view->b, animated->a * view->b);
    #ifdef DEBUG_MASK
    if (animation->super.image->mask) {
        land_image_debug_pixelmask(animation->super.image, x, y, self->angle, self->flipped);
    }
    #endif
}
void land_sprite_initialize(LandSprite * self, LandSpriteType * type) {
    self->type = type;
    if (self->type->initialize) {
        self->type->initialize(self);
    }
}
LandSprite* land_sprite_new(LandSpriteType * type) {
    if (! strcmp(type->name, "animation")) {
        return land_sprite_animated_new(type);
    }
    LandSprite * self;
    land_alloc(self);
    land_sprite_initialize(self, type);
    return self;
}
LandSprite* land_sprite_with_image_new(LandSpriteType * type, LandImage * image) {
    LandSpriteWithImage * self;
    land_alloc(self);
    land_sprite_initialize(LAND_SPRITE(self), type);
    self->image = image;
    return LAND_SPRITE(self);
}
void land_sprite_image_destroy(LandSprite * self) {
    ;
}
void land_sprite_image_initialize(LandSprite * super) {
    ;
}
void land_sprite_animated_initialize(LandSprite * super) {
    LandSpriteAnimated * self = (void *) super;
    self->sx = 1;
    self->sy = 1;
    self->r = 1;
    self->g = 1;
    self->b = 1;
    self->a = 1;
}
LandSprite* land_sprite_animated_new(LandSpriteType * type) {
    LandSpriteAnimated * self;
    land_alloc(self);
    land_sprite_initialize(LAND_SPRITE(self), type);
    return LAND_SPRITE(self);
}
void land_sprite_animated_destroy(LandSprite * sprite) {
    ;
}
void land_sprite_del(LandSprite * self) {
    /* Destroys a sprite. This will not remove its reference from a grid in case it
     * is inside one - so only use this if you know what you are doing.
     */
    if (self->type->destroy) {
        self->type->destroy(self);
    }
    land_free(self);
}
void land_sprite_destroy(LandSprite * self) {
    /* """Same as land_sprite_del."""
     */
    land_sprite_del(self);
}
void land_sprite_show(LandSprite * self, LandGrid * grid) {
    if (self->shown) {
        return ;
    }
    land_sprite_place_into_grid(self, grid, self->x, self->y);
}
void land_sprite_hide(LandSprite * self, LandGrid * grid) {
    if (! self->shown) {
        return ;
    }
    land_sprite_remove_from_grid(self, grid);
}
int land_sprite_overlap_pixelperfect(LandSprite * self, LandSprite * other) {
    /* Given two sprites who have a type LandSpriteTypeImage, do a pixel overlap
     * test, and return 0 if they don't overlap.
     */
    return land_image_overlaps(LAND_SPRITE_TYPE_IMAGE (self->type)->image, self->x, self->y, self->angle, self->flipped, LAND_SPRITE_TYPE_IMAGE (other->type)->image, other->x, other->y, other->angle, other->flipped);
}
void land_sprite_grid_ysorted(LandGrid * self) {
    LandSpritesGrid * sg = (void *) self;
    sg->ysorted = 1;
}
static void get_grid_extents(LandSprite * self, LandGrid * grid, int * tl, int * tt, int * tr, int * tb) {
    float l = self->x - self->type->x;
    float t = self->y - self->type->y;
    float r = self->x - self->type->x + self->type->w;
    float b = self->y - self->type->y + self->type->h;
    * tl = l / grid->cell_w;
    * tt = t / grid->cell_h;
    * tr = r / grid->cell_w;
    * tb = b / grid->cell_h;
    if (* tl < 0) {
        * tl = 0;
    }
    if (* tt < 0) {
        * tt = 0;
    }
    if (* tr >= grid->x_cells) {
        * tr = grid->x_cells - 1;
    }
    if (* tb >= grid->y_cells) {
        * tb = grid->y_cells - 1;
    }
}
LandArray* land_sprites_grid_get_all(LandGrid * sprites_grid) {
    LandArray * a = land_array_new();
    LandSpritesGrid * grid = LAND_SPRITES_GRID(sprites_grid);
    grid->tag++;
    for (int ty = 0; ty < sprites_grid->y_cells; ty++) {
        for (int tx = 0; tx < sprites_grid->x_cells; tx++) {
            LandList * list = grid->sprites [ty * grid->super.x_cells + tx];
            if (list) {
                LandListItem * item = list->first;
                while (item) {
                    LandSprite * sprite = item->data;
                    if (sprite->tag != grid->tag) {
                        sprite->tag = grid->tag;
                        land_array_add(a, sprite);
                    }
                    item = item->next;
                }
            }
        }
    }
    return a;
}
LandList* land_sprites_grid_overlap(LandSprite * self, LandGrid * sprites_grid) {
    /* Return a list of all sprites overlapping the sprite in the given grid.
     * The sprite itself is not returned.
     * Note that this only works if all sprites in the grid have compatible
     * overlapping, e.g. if the sprite does a pixel-overlap test, then all other
     * sprites must have a pixel mask, or if it does a bounding circle test, then
     * all other sprites must have a bounding circle, and so on.
     */
    LandSpritesGrid * grid = LAND_SPRITES_GRID(sprites_grid);
    LandList * retlist = NULL;
    int tl, tt, tr, tb;
    get_grid_extents(self, sprites_grid, & tl, & tt, & tr, & tb);
    grid->tag++;
    for (int ty = tt; ty <= tb; ty++) {
        for (int tx = tl; tx <= tr; tx++) {
            LandList * list = grid->sprites [ty * grid->super.x_cells + tx];
            if (list) {
                LandListItem * item = list->first;
                while (item) {
                    LandSprite * other = item->data;
                    if (other != self && other->tag != grid->tag) {
                        other->tag = grid->tag;
                        if (self->type->overlap(self, other)) {
                            land_add_list_data(& retlist, other);
                        }
                    }
                    item = item->next;
                }
            }
        }
    }
    return retlist;
}
LandList* land_sprites_grid_get_circle(LandGrid * sprites_grid, float x, float y, float radius) {
    /* Return a list of all sprites in the grid, whose position is inside the given
     * circle (in pixels). The size of the sprite is currently ignored, only its
     * point position is used.
     */
    LandSpritesGrid * grid = LAND_SPRITES_GRID(sprites_grid);
    LandList * retlist = NULL;
    float l = x - radius;
    float t = y - radius;
    float r = x + radius;
    float b = y + radius;
    int tl = l / grid->super.cell_w;
    int tt = t / grid->super.cell_h;
    int tr = r / grid->super.cell_w;
    int tb = b / grid->super.cell_h;
    int tx, ty;
    if (tl < 0) {
        tl = 0;
    }
    if (tt < 0) {
        tt = 0;
    }
    if (tr >= grid->super.x_cells) {
        tr = grid->super.x_cells - 1;
    }
    if (tb >= grid->super.y_cells) {
        tb = grid->super.y_cells - 1;
    }
    grid->tag++;
    for (ty = tt; ty <= tb; ty++) {
        for (tx = tl; tx <= tr; tx++) {
            LandList * list = grid->sprites [ty * grid->super.x_cells + tx];
            if (list) {
                LandListItem * item = list->first;
                while (item) {
                    LandSprite * other = item->data;
                    if (other->tag != grid->tag) {
                        other->tag = grid->tag;
                        float dx = other->x - x;
                        float dy = other->y - y;
                        if (dx + dx + dy * dy < radius * radius) {
                            land_add_list_data(& retlist, other);
                        }
                    }
                    item = item->next;
                }
            }
        }
    }
    return retlist;
}
LandList* land_sprites_grid_get_rectangle(LandGrid * sprites_grid, float l, float t, float r, float b) {
    /* Return a list of all sprites in the given rectangle. All the sprites who
     * are in one of the grid cells overlapped by the rectangle are returned.
     */
    LandSpritesGrid * grid = LAND_SPRITES_GRID(sprites_grid);
    LandList * retlist = NULL;
    int tl = l / grid->super.cell_w;
    int tt = t / grid->super.cell_h;
    int tr = r / grid->super.cell_w;
    int tb = b / grid->super.cell_h;
    int tx, ty;
    if (tl < 0) {
        tl = 0;
    }
    if (tt < 0) {
        tt = 0;
    }
    if (tr >= grid->super.x_cells) {
        tr = grid->super.x_cells - 1;
    }
    if (tb >= grid->super.y_cells) {
        tb = grid->super.y_cells - 1;
    }
    grid->tag++;
    for (ty = tt; ty <= tb; ty++) {
        for (tx = tl; tx <= tr; tx++) {
            LandList * list = grid->sprites [ty * grid->super.x_cells + tx];
            if (list) {
                LandListItem * item = list->first;
                while (item) {
                    LandSprite * other = item->data;
                    if (other->tag != grid->tag) {
                        other->tag = grid->tag;
                        land_add_list_data(& retlist, other);
                    }
                    item = item->next;
                }
            }
        }
    }
    return retlist;
}
LandList* land_sprites_grid_get_in_cell(LandGrid * grid, int cx, int cy) {
    LandList * retlist = NULL;
    LandSpritesGrid * sgrid = LAND_SPRITES_GRID(grid);
    if (cx < 0 || cy < 0 || cx >= grid->x_cells || cy >= grid->y_cells) {
        return NULL;
    }
    LandList * list = sgrid->sprites [cy * grid->x_cells + cx];
    if (list) {
        LandListItem * item = list->first;
        while (item) {
            LandSprite * s = item->data;
            int sx = s->x / grid->cell_w;
            int sy = s->y / grid->cell_h;
            if (sx == cx && sy == cy) {
                land_add_list_data(& retlist, s);
            }
            item = item->next;
        }
    }
    return retlist;
}
static int is_left(float ax, float ay, float bx, float by) {
    return ax * by - ay * bx < 0;
}
static int is_in_triangle(float x, float y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) {
    if (is_left(x - p1x, y - p1y, p2x - p1x, p2y - p1y) && is_left(x - p2x, y - p2y, p3x - p2x, p3y - p2y) && is_left(x - p3x, y - p3y, p1x - p3x, p1y - p3y)) {
        return 1;
    }
    return 0;
}
LandList* land_sprites_get_triangle(LandGrid * sprites_grid, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) {
    /* Return a list of all sprites in the given triangle. This only considers
     * center positions, the size/shape of sprites is completely ignored.
     */
    LandSpritesGrid * grid = LAND_SPRITES_GRID(sprites_grid);
    int l = p1x, t = p1y, r = p1y, b = p1y;
    if (p2x < l) {
        l = p2x;
    }
    if (p3x < l) {
        l = p3x;
    }
    if (p2x > r) {
        r = p2x;
    }
    if (p3x > r) {
        r = p3x;
    }
    if (p2y < t) {
        t = p2y;
    }
    if (p3y < t) {
        t = p3y;
    }
    if (p2y > b) {
        b = p2y;
    }
    if (p3y > b) {
        b = p3y;
    }
    int tl = l / grid->super.cell_w;
    int tt = t / grid->super.cell_h;
    int tr = r / grid->super.cell_w;
    int tb = b / grid->super.cell_h;
    if (tl < 0) {
        tl = 0;
    }
    if (tt < 0) {
        tt = 0;
    }
    if (tr >= grid->super.x_cells) {
        tr = grid->super.x_cells - 1;
    }
    if (tb >= grid->super.y_cells) {
        tb = grid->super.y_cells - 1;
    }
    LandList * retlist = NULL;
    grid->tag++;
    for (int ty = tt; ty <= tb; ty++) {
        for (int tx = tl; tx <= tr; tx++) {
            LandList * list = grid->sprites [ty * grid->super.x_cells + tx];
            if (! list) {
                continue;
            }
            LandListItem * item = list->first;
            while (item) {
                LandSprite * other = item->data;
                if (other->tag != grid->tag) {
                    other->tag = grid->tag;
                    if (is_in_triangle(other->x, other->y, p1x, p1y, p2x, p2y, p3x, p3y)) {
                        land_add_list_data(& retlist, other);
                    }
                }
                item = item->next;
            }
        }
    }
    return retlist;
}
LandList* land_sprites_grid_get_in_view(LandGrid * sprites_grid, LandView * view, float l, float t, float r, float b) {
    l += view->scroll_x + view->x;
    t += view->scroll_y + view->y;
    r += view->scroll_x + view->x + view->w;
    b += view->scroll_y + view->y + view->h;
    return land_sprites_grid_get_rectangle(sprites_grid, l, t, r, b);
}
static void grid_place(LandSprite * self, LandSpritesGrid * grid) {
    /* Place a sprite into a grid.
     * Note: This *must not* be called more than once for a sprite.
     * Note: The sprite *must not* change position or dimension after calling this.
     * Note: Use grid_unplace to undo the effect of this function.
     */
    int tl, tt, tr, tb;
    get_grid_extents(self, & grid->super, & tl, & tt, & tr, & tb);
    self->shown = 1;
    for (int ty = tt; ty <= tb; ty++) {
        for (int tx = tl; tx <= tr; tx++) {
            if (grid->ysorted) {
                LandList * list = grid->sprites [ty * grid->super.x_cells + tx];
                if (! list) {
                    list = land_list_new();
                    grid->sprites [ty * grid->super.x_cells + tx] = list;
                }
                LandListItem * item = land_listitem_new(self);
                LandListItem * i = list->first;
                while (i) {
                    LandSprite * ls = i->data;
                    if (ls->y > self->y) {
                        land_list_insert_item_before(list, item, i);
                        goto done;
                    }
                    if (ls->y == self->y) {
                        if (ls->x > self->x) {
                            land_list_insert_item_before(list, item, i);
                            goto done;
                        }
                    }
                    i = i->next;
                }
                land_list_insert_item(list, item);
                done:;
            }
            else {
                land_add_list_data(& grid->sprites [ty * grid->super.x_cells + tx], self);
            }
        }
    }
}
static void grid_unplace(LandSprite * self, LandSpritesGrid * grid) {
    /* Remove a sprite from a grid.
     */
    int tl, tt, tr, tb;
    get_grid_extents(self, & grid->super, & tl, & tt, & tr, & tb);
    for (int ty = tt; ty <= tb; ty++) {
        for (int tx = tl; tx <= tr; tx++) {
            land_remove_list_data(& grid->sprites [ty * grid->super.x_cells + tx], self);
        }
    }
    self->shown = 0;
}
void land_sprite_remove_from_grid(LandSprite * self, LandGrid * grid) {
    /* Remove a sprite from a grid.
     */
    grid_unplace(self, LAND_SPRITES_GRID(grid));
}
void land_sprite_place_into_grid(LandSprite * self, LandGrid * grid, float x, float y) {
    /* Place a sprite into a grid.
     */
    self->x = x;
    self->y = y;
    grid_place(self, (LandSpritesGrid *) grid);
}
void land_sprite_move(LandSprite * self, LandGrid * grid, float x, float y) {
    /* Move a sprite by the given amount of pixels
     */
    grid_unplace(self, (LandSpritesGrid *) grid);
    self->x += x;
    if (self->x < 0) {
        self->x = 0;
    }
    if (self->x >= grid->cell_w * grid->x_cells) {
        self->x = grid->cell_w * grid->x_cells - 1;
    }
    self->y += y;
    if (self->y < 0) {
        self->y = 0;
    }
    if (self->y >= grid->cell_h * grid->y_cells) {
        self->y = grid->cell_h * grid->y_cells - 1;
    }
    grid_place(self, (LandSpritesGrid *) grid);
}
void land_sprite_move_to(LandSprite * self, LandGrid * grid, float x, float y) {
    /* Move a sprite to the given position in pixels.
     */
    land_sprite_move(self, grid, x - self->x, y - self->y);
}
void land_sprites_grid_draw_cell(LandSpritesGrid * self, LandView * view, int cell_x, int cell_y, float pixel_x, float pixel_y) {
    LandList * list = self->sprites [cell_y * self->super.x_cells + cell_x];
    if (list) {
        LandListItem * item = list->first;
        while (item) {
            LandSprite * sprite = item->data;
            if (sprite->tag != self->tag) {
                sprite->type->draw(sprite, view);
                sprite->tag = self->tag;
            }
            item = item->next;
        }
    }
}
void land_sprites_grid_draw(LandGrid * super, LandView * view) {
    LandSpritesGrid * self = (void *) super;
    self->tag++;
    land_grid_draw_normal(super, view);
}
static void get_cell_at(LandGrid * self, LandView * view, float view_x, float view_y, float * cell_x, float * cell_y) {
    float x = view->scroll_x + (view_x - view->x) / view->scale_x;
    float y = view->scroll_y + (view_y - view->y) / view->scale_y;
    * cell_x = x / self->cell_w;
    * cell_y = y / self->cell_h;
}
void land_sprites_init(void) {
    land_log_message("land_sprites_init\n");
    land_alloc(land_grid_vtable_sprites);
    land_grid_vtable_sprites->draw = land_sprites_grid_draw;
    land_grid_vtable_sprites->draw_cell = (void *) land_sprites_grid_draw_cell;
    land_grid_vtable_sprites->del = land_sprites_grid_del;
    land_grid_vtable_sprites->get_cell_at = get_cell_at;
}
void land_sprites_exit(void) {
    land_log_message("land_sprites_exit\n");
    land_free(land_grid_vtable_sprites);
}
LandSpriteType* land_spritetype_new(void) {
    LandSpriteType * self;
    land_alloc(self);
    self->draw = dummy;
    return self;
}
void land_spritetype_destroy(LandSpriteType * self) {
    if (self->destroy_type) {
        self->destroy_type(self);
    }
    land_free(self->name);
    land_free(self);
}
LandSpriteTypeWithImage* land_spritetype_with_image_new(void) {
    return NULL;
}
void land_spritetype_image_initialize(LandSpriteType * super, LandImage * image, bool mask, int n) {
    LandSpriteTypeImage * self = (void *) super;
    super->draw = dummy_image;
    super->overlap = land_sprite_overlap_pixelperfect;
    super->destroy = land_sprite_image_destroy;
    super->initialize = land_sprite_image_initialize;
    if (image) {
        super->x = image->x - image->l;
        super->y = image->y - image->t;
        super->w = land_image_width(image) - image->l - image->r;
        super->h = land_image_height(image) - image->t - image->b;
    }
    else {
        super->x = super->y = super->w = super->h = 0;
    }
    self->image = image;
    LAND_SPRITE_TYPE (self)->name = land_strdup("image");
    if (image && mask && ! image->mask) {
        land_image_create_pixelmasks(image, n, 128);
    }
}
LandSpriteType* land_spritetype_image_new(LandImage * image, bool mask, int n) {
    LandSpriteTypeImage * self;
    land_alloc(self);
    land_spritetype_image_initialize((void *) self, image, mask, n);
    return LAND_SPRITE_TYPE(self);
}
void land_spritetype_animation_initialize(LandSpriteType * super, LandAnimation * animation, LandImage * image, bool mask, int n) {
    LandSpriteTypeAnimation * self = (void *) super;
    if (! image && animation) {
        image = land_animation_get_frame(animation, 0);
    }
    land_spritetype_image_initialize((void *) self, image, 0, 0);
    if (image && mask) {
        land_image_create_pixelmasks(image, n, 128);
    }
    super->draw = dummy_animation;
    super->destroy = land_sprite_animated_destroy;
    super->destroy_type = land_spritetype_animation_destroy;
    super->initialize = land_sprite_animated_initialize;
    self->animation = animation;
    land_free(super->name);
    super->name = land_strdup("animation");
}
LandSpriteType* land_spritetype_animation_new(LandAnimation * animation, LandImage * image, bool mask, int n) {
    /* Create a new animation sprite type with the given animation. The
     * image is used for collision detection. If no image is given, the
     * first frame of the animation is used instead.
     * If a mask is request n is the number of rotations. A negative n
     * means two variants are made for each rotation (one flipped
     * horizontally).
     */
    LandSpriteTypeAnimation * self;
    land_alloc(self);
    land_spritetype_animation_initialize((void *) self, animation, image, mask, n);
    return LAND_SPRITE_TYPE(self);
}
void land_spritetype_animation_destroy(LandSpriteType * base) {
    LandSpriteTypeAnimation * self = LAND_SPRITE_TYPE_ANIMATION(base);
    if (self->animation) {
        land_animation_destroy(self->animation);
    }
}
LandGridInterface * land_grid_vtable_isometric;
LandGridInterface * land_grid_vtable_isometric_wrap;
static LandGrid* new(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells) {
    LandGridIsometric * self;
    land_alloc(self);
    land_grid_initialize(& self->super, cell_w1 + cell_w2, cell_h1 + cell_h2, x_cells, y_cells);
    self->cell_w1 = cell_w1;
    self->cell_h1 = cell_h1;
    self->cell_w2 = cell_w2;
    self->cell_h2 = cell_h2;
    return & self->super;
}
LandGrid* land_isometric_new(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells) {
    LandGrid * self = new(cell_w1, cell_h1, cell_w2, cell_h2, x_cells, y_cells);
    self->vt = land_grid_vtable_isometric;
    return self;
}
LandGrid* land_isometric_wrap_new(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells) {
    LandGrid * self = new(cell_w1, cell_h1, cell_w2, cell_h2, x_cells, y_cells);
    self->vt = land_grid_vtable_isometric_wrap;
    self->wrap = true;
    return self;
}
LandGrid* land_isometric_custom_grid(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells, bool wrap, void(* draw_cell)(LandGrid * self, LandView * view, int cell_x, int cell_y, float x, float y)) {
    LandGrid * self = new(cell_w1, cell_h1, cell_w2, cell_h2, x_cells, y_cells);
    land_alloc(self->vt);
    self->vt->draw = wrap ? land_grid_draw_isometric_wrap : land_grid_draw_isometric;
    self->vt->get_cell_at = wrap ? land_grid_pixel_to_cell_isometric_wrap : land_grid_pixel_to_cell_isometric;
    self->vt->draw_cell = draw_cell;
    self->vt->get_cell_position = wrap ? land_grid_cell_to_pixel_isometric_wrap : land_grid_cell_to_pixel_isometric;
    self->wrap = wrap;
    return self;
}
void land_grid_pixel_to_cell_isometric(LandGrid * self, LandView * view, float mx, float my, float * partial_x, float * partial_y) {
    /* Returns the grid position in cells below the specified pixel position in
     * the given view.
     */
    LandGridIsometric * iso = (void *) self;
    float x = view->scroll_x + mx - view->x;
    float y = view->scroll_y + my - view->y;
    float a = iso->cell_w1 * iso->cell_h2 + iso->cell_w2 * iso->cell_h1;
    * partial_x = (x * iso->cell_h1 + y * iso->cell_w1) / a;
    * partial_y = (y * iso->cell_w2 - x * iso->cell_h2) / a;
}
void land_grid_cell_to_pixel_isometric(LandGrid * self, LandView * view, float cell_x, float cell_y, float * view_x, float * view_y) {
    /* Given a cell position, return the position of the cell's origin in
     * on-screen coordinates, using the current view.
     */
    LandGridIsometric * iso = (void *) self;
    float mx = cell_x * iso->cell_w2 - cell_y * iso->cell_w1;
    float my = cell_x * iso->cell_h2 + cell_y * iso->cell_h1;
    mx = view->x + mx - view->scroll_x;
    my = view->y + my - view->scroll_y;
    * view_x = mx;
    * view_y = my;
}
void land_grid_cell_to_pixel_isometric_wrap(LandGrid * self, LandView * view, float cell_x, float cell_y, float * view_x, float * view_y) {
    /* Given a cell position, return the position of the cell's origin in
     * on-screen coordinates, using the current view.
     */
    LandGridIsometric * iso = (void *) self;
    cell_x = cell_x - floorf(cell_x / self->x_cells) * self->x_cells;
    cell_y = cell_y - floorf(cell_y / self->y_cells) * self->y_cells;
    float mx = cell_x * iso->cell_w2 - cell_y * iso->cell_w1;
    float my = cell_x * iso->cell_h2 + cell_y * iso->cell_h1;
    mx = view->x + mx - view->scroll_x;
    my = view->y + my - view->scroll_y;
    * view_x = mx;
    * view_y = my;
}
void land_grid_pixel_to_cell_isometric_wrap(LandGrid * self, LandView * view, float mx, float my, float * partial_x, float * partial_y) {
    float x, y;
    land_grid_pixel_to_cell_isometric(self, view, mx, my, & x, & y);
    * partial_x = x - floorf(x / self->x_cells) * self->x_cells;
    * partial_y = y - floorf(y / self->y_cells) * self->y_cells;
}
static void view_to_cell(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y) {
    LandGridIsometric * iso = (void *) self;
    float x = view_x;
    float y = view_y;
    float a = iso->cell_w1 * iso->cell_h2 + iso->cell_w2 * iso->cell_h1;
    * cell_x = floor((x * iso->cell_h1 + y * iso->cell_w1) / a);
    * cell_y = floor((y * iso->cell_w2 - x * iso->cell_h2) / a);
}
static void view_to_cell_wrap(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y) {
    int cx, cy;
    view_to_cell(self, view_x, view_y, & cx, & cy);
    cx %= self->x_cells;
    cy %= self->y_cells;
    if (cx < 0) {
        cx += self->x_cells;
    }
    if (cy < 0) {
        cy += self->y_cells;
    }
    * cell_x = cx;
    * cell_y = cy;
}
static void cell_to_view(LandGrid * self, float cell_x, float cell_y, float * view_x, float * view_y) {
    LandGridIsometric * iso = (void *) self;
    * view_x = cell_x * iso->cell_w2 - cell_y * iso->cell_w1;
    * view_y = cell_x * iso->cell_h2 + cell_y * iso->cell_h1;
}
static int find_offset(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y, float * pixel_x, float * pixel_y) {
    LandGridIsometric * iso = (void *) self;
    float h1 = iso->cell_h1;
    float w2 = iso->cell_w2;
    float h2 = iso->cell_h2;
    float right_x = w2 * self->x_cells;
    float right_y = h2 * self->x_cells;
    float left_y = h1 * self->y_cells;
    float bottom_y = right_y + left_y;
    view_to_cell(self, view_x, view_y, cell_x, cell_y);
    if (view_y >= bottom_y) {
        return 0;
    }
    else if (view_x >= right_x) {
        return 0;
    }
    else if (view_x < 0 && view_y < 0) {
        * cell_x = 0;
        * cell_y = 0;
    }
    else if (* cell_x < 0 && view_x < 0 && view_y < left_y) {
        * cell_x = 0;
        * cell_y = view_y / h1;
    }
    else if (* cell_y >= self->y_cells) {
        * cell_x = (view_y - left_y) / h2;
        * cell_y = self->y_cells - 1;
    }
    else if (* cell_y < 0) {
        * cell_x = view_x / w2;
        * cell_y = 0;
    }
    else if (* cell_x >= self->x_cells) {
        return 0;
    }
    cell_to_view(self, * cell_x, * cell_y, pixel_x, pixel_y);
    * pixel_x -= view_x;
    * pixel_y -= view_y;
    return 1;
}
static void find_offset_wrap(LandGrid * self, float view_x, float view_y, int * cell_x, int * cell_y, float * pixel_x, float * pixel_y) {
    float vw = (self->x_cells * self->cell_w) / 2;
    float vh = (self->y_cells * self->cell_h) / 2;
    float x, y;
    view_to_cell_wrap(self, view_x, view_y, cell_x, cell_y);
    cell_to_view(self, * cell_x, * cell_y, & x, & y);
    x -= view_x;
    y -= view_y;
    * pixel_x = x - (1 + floorf(x / vw - 0.5)) * vw;
    * pixel_y = y - (1 + floorf(y / vh - 0.5)) * vh;
}
static void placeholder(LandGrid * self, LandView * view, int cell_x, int cell_y, float x, float y) {
    int x_, y_;
    int w = self->cell_w / 2;
    int h = self->cell_h / 2;
    land_color(255, 0, 0, 1);
    x_ = x + w;
    y_ = y + h;
    land_line(x, y, x_, y_);
    x = x_;
    y = y_;
    x_ = x - w;
    y_ = y + h;
    land_line(x, y, x_, y_);
    x = x_;
    y = y_;
    x_ = x - w;
    y_ = y - h;
    land_line(x, y, x_, y_);
    x = x_;
    y = y_;
    x_ = x + w;
    y_ = y - h;
    land_line(x, y, x_, y_);
}
void land_grid_draw_isometric(LandGrid * self, LandView * view) {
    LandGridIsometric * iso = (void *) self;
    float w1 = iso->cell_w1;
    float h1 = iso->cell_h1;
    float w2 = iso->cell_w2;
    float h2 = iso->cell_h2;
    int cell_x, cell_y;
    float pixel_x, pixel_y;
    float view_x = view->scroll_x;
    float view_y = view->scroll_y;
    if (! find_offset(self, view_x, view_y, & cell_x, & cell_y, & pixel_x, & pixel_y)) {
        return ;
    }
    pixel_x += view->x;
    pixel_y += view->y;
    float h = h1;
    if (h2 < h) {
        h = h2;
    }
    float upper_y = view->y;
    int row = 0;
    while (1) {
        float line_pixel_x = pixel_x;
        float line_pixel_y = pixel_y;
        int line_cell_x = cell_x;
        int line_cell_y = cell_y;
        while (1) {
            while (pixel_y + h2 > upper_y && cell_y > 0) {
                pixel_x += w1;
                pixel_y -= h1;
                cell_y--;
            }
            if (pixel_x - w1 >= view->x + view->w) {
                break;
            }
            if (pixel_y + h1 + h2 - upper_y <= h) {
                if (pixel_y >= view->y + view->h) {
                    return ;
                }
                self->vt->draw_cell(self, view, cell_x, cell_y, pixel_x, pixel_y);
            }
            pixel_x += w2;
            pixel_y += h2;
            cell_x++;
            if (cell_x >= self->x_cells) {
                break;
            }
        }
        cell_x = line_cell_x;
        cell_y = line_cell_y;
        pixel_x = line_pixel_x;
        pixel_y = line_pixel_y;
        upper_y += h;
        row++;
        if (pixel_y + h1 + h2 <= upper_y) {
            if (pixel_x + w2 - w1 > view->x && cell_y < self->y_cells - 1) {
                pixel_x -= w1;
                pixel_y += h1;
                cell_y++;
            }
            else {
                if (cell_x >= self->x_cells - 1) {
                    break;
                }
                pixel_x += w2;
                pixel_y += h2;
                cell_x++;
            }
        }
    }
}
void land_grid_draw_isometric_wrap(LandGrid * self, LandView * view) {
    float w = self->cell_w / 2;
    float h = self->cell_h / 2;
    int cell_x, cell_y;
    float pixel_x, pixel_y;
    float view_x = view->scroll_x;
    float view_y = view->scroll_y;
    find_offset_wrap(self, view_x, view_y, & cell_x, & cell_y, & pixel_x, & pixel_y);
    if (pixel_y > - h) {
        cell_y--;
        if (cell_y < 0) {
            cell_y += self->y_cells;
        }
        pixel_x += w;
        pixel_y -= h;
    }
    pixel_x += view->x;
    pixel_y += view->y;
    while (pixel_y < view->y + view->h) {
        float line_pixel_x = pixel_x;
        float line_pixel_y = pixel_y;
        int line_cell_x = cell_x;
        int line_cell_y = cell_y;
        while (pixel_x - w < view->x + view->w) {
            self->vt->draw_cell(self, view, cell_x, cell_y, pixel_x, pixel_y);
            pixel_x += w;
            pixel_y += h;
            cell_x++;
            if (cell_x >= self->x_cells) {
                cell_x -= self->x_cells;
            }
            pixel_x += w;
            pixel_y -= h;
            cell_y--;
            if (cell_y < 0) {
                cell_y += self->y_cells;
            }
        }
        cell_x = line_cell_x;
        cell_y = line_cell_y;
        pixel_x = line_pixel_x;
        pixel_y = line_pixel_y;
        if (pixel_x > view->x) {
            pixel_x -= w;
            pixel_y += h;
            cell_y++;
            if (cell_y >= self->y_cells) {
                cell_y -= self->y_cells;
            }
        }
        else {
            pixel_x += w;
            pixel_y += h;
            cell_x++;
            if (cell_x >= self->x_cells) {
                cell_x -= self->x_cells;
            }
        }
    }
}
void land_isometric_init(void) {
    land_log_message("land_isometric_init\n");
    land_alloc(land_grid_vtable_isometric);
    land_grid_vtable_isometric->draw = land_grid_draw_isometric;
    land_grid_vtable_isometric->draw_cell = placeholder;
    land_grid_vtable_isometric->get_cell_at = land_grid_pixel_to_cell_isometric;
    land_grid_vtable_isometric->get_cell_position = land_grid_cell_to_pixel_isometric;
    land_alloc(land_grid_vtable_isometric_wrap);
    land_grid_vtable_isometric_wrap->draw = land_grid_draw_isometric_wrap;
    land_grid_vtable_isometric_wrap->draw_cell = placeholder;
    land_grid_vtable_isometric_wrap->get_cell_at = land_grid_pixel_to_cell_isometric_wrap;
    land_grid_vtable_isometric_wrap->get_cell_position = land_grid_cell_to_pixel_isometric_wrap;
}
void land_isometric_exit(void) {
    land_free(land_grid_vtable_isometric);
    land_free(land_grid_vtable_isometric_wrap);
}
LandWidgetInterface * land_widget_button_interface;
void land_widget_button_draw(LandWidget * base) {
    LandWidgetButton * self = LAND_WIDGET_BUTTON(base);
    land_widget_box_draw(base);
    if (! base->dont_clip) {
        float l, t, r, b;
        land_widget_inner_extents(base, & l, & t, & r, & b);
        land_clip_push();
        land_clip_intersect(l, t, r, b);
    }
    if (self->image) {
        int w = land_image_width(self->image);
        int h = land_image_height(self->image);
        float x = base->box.x + base->element->il;
        switch (self->xalign) {
            case 1: {
                x = base->box.x + base->box.w - base->element->ir - w;
                break;
            }
            case 2: {
                x = base->box.x + (base->box.w - base->element->il - base->element->ir - w) * 0.5;
                break;
            }
        }
        float y = base->box.y + base->element->it;
        switch (self->yalign) {
            case 1: {
                y = base->box.y + base->box.h - base->element->ib - h;
                break;
            }
            case 2: {
                y = base->box.y + (base->box.h - base->element->it - base->element->ib - h) * 0.5;
                break;
            }
        }
        x += self->xshift;
        y += self->yshift;
        land_image_draw(self->image, x + self->image->x, y + self->image->y);
    }
    if (self->animation) {
        float fps = self->animation->fps;
        int i = (int)(land_get_time() * fps) % self->animation->frames->count;
        LandImage * image = land_animation_get_frame(self->animation, i);
        int w = land_image_width(image);
        int h = land_image_height(image);
        float x = base->box.x + base->element->il;
        switch (self->xalign) {
            case 1: {
                x = base->box.x + base->box.w - base->element->ir - w;
                break;
            }
            case 2: {
                x = base->box.x + (base->box.w - base->element->il - base->element->ir - w) * 0.5;
                break;
            }
        }
        float y = base->box.y + base->element->it;
        switch (self->yalign) {
            case 1: {
                y = base->box.y + base->box.h - base->element->ib - h;
                break;
            }
            case 2: {
                y = base->box.y + (base->box.h - base->element->it - base->element->ib - h) * 0.5;
                break;
            }
        }
        x += self->xshift;
        y += self->yshift;
        land_image_draw(image, x + image->x, y + image->y);
    }
    if (self->text) {
        int x, y = base->box.y + base->element->it;
        land_widget_theme_color(base);
        land_widget_theme_font(base);
        int th = land_font_height(land_font_current());
        switch (self->yalign) {
            case 1: {
                y = base->box.y + base->box.h - base->element->ib - th;
                break;
            }
            case 2: {
                y = base->box.y + (base->box.h - base->element->it + base->element->ib - th) / 2;
                break;
            }
        }
        y += self->yshift;
        switch (self->xalign) {
            case 0: {
                x = base->box.x + base->element->il;
                x += self->xshift;
                land_text_pos(x, y);
                if (self->multiline) {
                    land_print_lines(self->lines, 0);
                }
                else {
                    land_print("%s", self->text);
                }
                break;
            }
            case 1: {
                x = base->box.x + base->box.w - base->element->ir;
                x += self->xshift;
                land_text_pos(x, y);
                if (self->multiline) {
                    land_print_lines(self->lines, 1);
                }
                else {
                    land_print_right("%s", self->text);
                }
                break;
            }
            case 2: {
                x = base->box.x + (base->box.w - base->element->il + base->element->ir) / 2;
                x += self->xshift;
                land_text_pos(x, y);
                if (self->multiline) {
                    land_print_lines(self->lines, 2);
                }
                else {
                    land_print_center("%s", self->text);
                }
                break;
            }
        }
    }
    if (! base->dont_clip) {
        land_clip_pop();
    }
}
void land_widget_button_size(LandWidget * base, float dx, float dy) {
    if (! (dx || dy)) {
        return ;
    }
    LandWidgetButton * button = LAND_WIDGET_BUTTON(base);
    land_widget_button_multiline(base, button->multiline);
}
void land_widget_button_mouse_tick(LandWidget * base) {
    LandWidgetButton * button = LAND_WIDGET_BUTTON(base);
    if (button->clicked) {
        if (land_mouse_delta_b() & 1) {
            if (land_mouse_b() & 1) {
                button->clicked(base);
            }
        }
    }
    if (button->rclicked) {
        if (land_mouse_delta_b() & 2) {
            if (land_mouse_b() & 2) {
                button->rclicked(base);
            }
        }
    }
}
void land_widget_button_initialize(LandWidget * base, LandWidget * parent, char const * text, LandImage * image, void(* clicked)(LandWidget * self), int x, int y, int w, int h) {
    land_widget_base_initialize(base, parent, x, y, w, h);
    land_widget_button_interface_initialize();
    base->vt = land_widget_button_interface;
    land_widget_theme_initialize(base);
    LandWidgetButton * self = LAND_WIDGET_BUTTON(base);
    if (text) {
        self->text = land_strdup(text);
        land_widget_theme_set_minimum_size_for_text(base, text);
        w = _scramble_max(w, base->box.min_width);
        h = _scramble_max(h, base->box.min_height);
        land_widget_layout_set_minimum_size(base, w, h);
    }
    if (image) {
        self->image = image;
        land_widget_theme_set_minimum_size_for_image(base, image);
    }
    self->clicked = clicked;
    if (parent) {
        land_widget_layout(parent);
    }
}
LandWidget* land_widget_button_new(LandWidget * parent, char const * text, void(* clicked)(LandWidget * self), int x, int y, int w, int h) {
    LandWidgetButton * button;
    land_alloc(button);
    LandWidget * self = (LandWidget *) button;
    land_widget_button_initialize(self, parent, text, NULL, clicked, x, y, w, h);
    return self;
}
LandWidget* land_widget_button_new_with_image(LandWidget * parent, char const * text, LandImage * image, void(* clicked)(LandWidget * self), int x, int y, int w, int h) {
    LandWidgetButton * button;
    land_alloc(button);
    LandWidget * self = (LandWidget *) button;
    land_widget_button_initialize(self, parent, text, image, clicked, x, y, w, h);
    return self;
}
LandWidget* land_widget_button_new_with_animation(LandWidget * parent, char const * text, LandAnimation * animation, void(* clicked)(LandWidget * self), int x, int y, int w, int h) {
    LandWidgetButton * button;
    land_alloc(button);
    LandWidget * self = (LandWidget *) button;
    land_widget_button_initialize(self, parent, text, NULL, clicked, x, y, w, h);
    button->animation = animation;
    return self;
}
LandWidget* land_widget_text_initialize(LandWidget * self, LandWidget * parent, char const * text, int multiline, int x, int y, int w, int h) {
    land_widget_button_initialize(self, parent, multiline ? NULL : text, NULL, NULL, x, y, w, h);
    self->no_decoration = 1;
    land_widget_theme_initialize(self);
    if (multiline) {
        land_widget_button_multiline(self, multiline);
        land_widget_button_set_text(self, text);
    }
    else {
        land_widget_layout(parent);
    }
    return self;
}
LandWidget* land_widget_text_new(LandWidget * parent, char const * text, int multiline, int x, int y, int w, int h) {
    LandWidgetButton * button;
    land_alloc(button);
    LandWidget * self = (LandWidget *) button;
    land_widget_text_initialize(self, parent, text, multiline, x, y, w, h);
    return self;
}
static int _linedelcb(void * item, void * data) {
    land_free(item);
    return 0;
}
void land_widget_button_replace_text(LandWidget * base, char const * text) {
    /* Same as set_text but does not trigger any layout updates.
     */
    LandWidgetButton * button = LAND_WIDGET_BUTTON(base);
    if (button->text) {
        land_free(button->text);
    }
    button->text = NULL;
    if (text) {
        button->text = land_strdup(text);
    }
}
void land_widget_button_set_text(LandWidget * base, char const * text) {
    land_widget_button_replace_text(base, text);
    land_widget_button_layout_text(base);
}
void land_widget_button_layout_text(LandWidget * base) {
    LandWidgetButton * button = LAND_WIDGET_BUTTON(base);
    if (button->text) {
        if (button->multiline) {
            land_widget_button_multiline(base, button->multiline);
        }
        else {
            land_widget_theme_set_minimum_size_for_text(base, button->text);
        }
    }
    if (base->parent) {
        land_widget_layout(base->parent);
    }
}
void land_widget_button_append_row(LandWidget * base, char const * text) {
    LandWidgetButton * button = LAND_WIDGET_BUTTON(base);
    char * newt = button->text;
    if (! newt) {
        newt = land_strdup("");
    }
    if (newt [0] != 0) {
        land_concatenate(& newt, "\n");
    }
    land_concatenate(& newt, text);
    button->text = newt;
    land_widget_button_layout_text(base);
}
void land_widget_button_multiline(LandWidget * self, int style) {
    /* If style is 0, the text of this widget is a single line. No newline
     * characters are allowed.
     * If style is 1, the text can have multiple lines.
     * If style is 2, the text can have multiple lines, and long lines are
     * word wrapped.
     */
    LandWidgetButton * button = LAND_WIDGET_BUTTON(self);
    button->multiline = style;
    if (button->lines) {
        land_array_for_each(button->lines, _linedelcb, NULL);
        land_array_destroy(button->lines);
        button->lines = NULL;
    }
    if (style && button->text) {
        float x, y, w, h;
        land_widget_theme_font(self);
        land_widget_inner(self, & x, & y, & w, & h);
        if (style == 1) {
            button->lines = land_text_splitlines(button->text);
        }
        else {
            button->lines = land_wordwrap_text(w, 0, button->text);
        }
        float ww, wh;
        land_wordwrap_extents(& ww, & wh);
        if (ww - w > 0.1) {
            land_array_for_each(button->lines, _linedelcb, NULL);
            land_array_destroy(button->lines);
            button->lines = land_wordwrap_text(ww, 0, button->text);
            land_wordwrap_extents(& ww, & wh);
        }
        land_widget_theme_set_minimum_size_for_contents(self, ww, wh);
    }
}
void land_widget_button_align(LandWidget * self, int x, int y) {
    /* 0 = left/top
     * 1 = right/bottom
     * 2 = center
     */
    LandWidgetButton * button = LAND_WIDGET_BUTTON(self);
    button->xalign = x;
    button->yalign = y;
}
void land_widget_button_shift(LandWidget * self, int x, int y) {
    LandWidgetButton * button = LAND_WIDGET_BUTTON(self);
    button->xshift = x;
    button->yshift = y;
}
void land_widget_button_interface_initialize(void) {
    if (land_widget_button_interface) {
        return ;
    }
    land_widget_button_interface = land_widget_copy_interface(land_widget_base_interface, "button");
    land_widget_button_interface->id |= LAND_WIDGET_ID_BUTTON;
    land_widget_button_interface->destroy = land_widget_button_destroy;
    land_widget_button_interface->draw = land_widget_button_draw;
    land_widget_button_interface->mouse_tick = land_widget_button_mouse_tick;
    land_widget_button_interface->size = land_widget_button_size;
}
void land_widget_button_destroy(LandWidget * base) {
    LandWidgetButton * button = LAND_WIDGET_BUTTON(base);
    if (button->text) {
        land_free(button->text);
    }
    if (button->lines) {
        land_array_for_each(button->lines, _linedelcb, NULL);
        land_array_destroy(button->lines);
    }
    land_widget_base_destroy(base);
}
void platform_display_init(void) {
    ;
}
void platform_display_exit(void) {
    ;
}
LandDisplay* platform_display_new(void) {
    LandDisplayPlatform * self;
    land_alloc(self);
    return & self->super;
}
void platform_display_del(LandDisplay * super) {
    LandDisplayPlatform * self = (void *) super;
    al_destroy_display(self->a5);
}
#define SELF \
    LandDisplayPlatform * self = (void *) _land_active_display; \
    LandDisplay * super = & self->super; \
    (void) super;
void platform_display_desktop_size(int * w, int * h) {
    ALLEGRO_MONITOR_INFO info;
    al_get_monitor_info(0, & info);
    * w = info.x2 - info.x1;
    * h = info.y2 - info.y1;
}
void platform_display_title(char const * title) {
    SELF;
    al_set_window_title(self->a5, title);
}
void platform_display_move(int x, int y) {
    SELF;
    al_set_window_position(self->a5, x, y);
}
void platform_display_resize(int w, int h) {
    SELF;
    al_resize_display(self->a5, w, h);
}
void land_a5_display_check_transform(void) {
    LandDisplayPlatform * self = (void *) _land_active_display;
    LandDisplay * super = & self->super;
    if (super->matrix_modified) {
        self->transform.m [0] [0] = super->matrix [0];
        self->transform.m [1] [0] = super->matrix [1];
        self->transform.m [2] [0] = super->matrix [2];
        self->transform.m [3] [0] = super->matrix [3];
        self->transform.m [0] [1] = super->matrix [4];
        self->transform.m [1] [1] = super->matrix [5];
        self->transform.m [2] [1] = super->matrix [6];
        self->transform.m [3] [1] = super->matrix [7];
        self->transform.m [0] [2] = super->matrix [8];
        self->transform.m [1] [2] = super->matrix [9];
        self->transform.m [2] [2] = super->matrix [10];
        self->transform.m [3] [2] = super->matrix [11];
        self->transform.m [0] [3] = super->matrix [12];
        self->transform.m [1] [3] = super->matrix [13];
        self->transform.m [2] [3] = super->matrix [14];
        self->transform.m [3] [3] = super->matrix [15];
        al_use_transform(& self->transform);
        super->matrix_modified = 0;
    }
}
static void check_blending_and_transform(void) {
    SELF;
    land_a5_display_check_transform();
    if (super->blend) {
        al_store_state(& self->blend_state, ALLEGRO_STATE_BLENDER);
        if (super->blend & LAND_BLEND_SOLID) {
            al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
        }
        else if (super->blend & LAND_BLEND_ADD) {
            al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_ONE);
        }
    }
}
static void uncheck_blending(void) {
    SELF;
    if (super->blend) {
        al_restore_state(& self->blend_state);
    }
}
void platform_display_set(void) {
    SELF;
    int f = 0;
    if (self->a5) {
        return ;
    }
    if (super->flags & LAND_FULLSCREEN) {
        f |= ALLEGRO_FULLSCREEN_WINDOW;
    }
    if (super->flags & LAND_RESIZE) {
        f |= ALLEGRO_RESIZABLE;
    }
    if (super->flags & LAND_OPENGL) {
        f |= ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE;
    }
    if (super->flags & LAND_MULTISAMPLE) {
        al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
        al_set_new_display_option(ALLEGRO_SAMPLES, 4, ALLEGRO_SUGGEST);
    }
    if (super->flags & LAND_DEPTH) {
        al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 16, ALLEGRO_SUGGEST);
    }
    if (super->flags & LAND_LANDSCAPE) {
        al_set_new_display_option(ALLEGRO_SUPPORTED_ORIENTATIONS, ALLEGRO_DISPLAY_ORIENTATION_LANDSCAPE, ALLEGRO_SUGGEST);
    }
    if (super->flags & LAND_ANTIALIAS) {
        al_set_new_bitmap_flags(ALLEGRO_MAG_LINEAR | ALLEGRO_MIN_LINEAR);
    }
    ALLEGRO_MONITOR_INFO info;
    al_get_monitor_info(0, & info);
    land_log_message("Monitor resolution: %d %d %d %d\n", info.x1, info.y1, info.x2, info.y2);
    int monw = info.x2 - info.x1;
    int monh = info.y2 - info.y1;
    if (super->flags & LAND_RESIZE) {
        if (super->w > monw) {
            super->w = monw;
        }
        if (super->h > monh) {
            super->h = monh;
        }
    }
    if (super->w == monw && super->h == monh) {
        f |= ALLEGRO_FULLSCREEN_WINDOW;
    }
    if (super->w == 0) {
        super->w = monw;
        super->clip_x2 = super->w;
    }
    if (super->h == 0) {
        super->h = monh;
        super->clip_y2 = super->h;
    }
    #ifdef ANDROID
    #endif
    if (f) {
        al_set_new_display_flags(f);
    }
    al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 16, ALLEGRO_SUGGEST);
    land_log_message("Calling al_create_display(%d, %d).\n", super->w, super->h);
    self->a5 = al_create_display(super->w, super->h);
    if (self->a5) {
        land_log_message("    Success!\n");
    }
    else {
        land_log_message("    Failed activating Allegro display.\n");
    }
    if (super->flags & LAND_FULLSCREEN) {
        super->w = al_get_display_width(self->a5);
        super->h = al_get_display_height(self->a5);
        super->clip_x2 = super->w;
        super->clip_y2 = super->h;
        land_log_message("Using actual size of %dx%d.\n", super->w, super->h);
    }
    if (f & ALLEGRO_PROGRAMMABLE_PIPELINE) {
        land_display_set_default_shaders();
    }
}
void platform_display_color(void) {
    SELF;
    self->c = al_map_rgba_f(super->color_r, super->color_g, super->color_b, super->color_a);
}
void platform_display_clip(void) {
    SELF;
    al_set_clipping_rectangle(super->clip_x1, super->clip_y1, super->clip_x2 - super->clip_x1, super->clip_y2 - super->clip_y1);
}
void platform_display_clear(LandDisplay * self, float r, float g, float b, float a) {
    al_clear_to_color(al_map_rgba_f(r, g, b, a));
}
void platform_display_clear_depth(LandDisplay * self, float z) {
    al_clear_depth_buffer(z);
}
void platform_display_flip(void) {
    al_flip_display();
}
void platform_rectangle(float x, float y, float x_, float y_) {
    SELF;
    check_blending_and_transform();
    al_draw_rectangle(x, y, x_, y_, self->c, self->super.thickness);
    uncheck_blending();
}
void platform_filled_rectangle(float x, float y, float x_, float y_) {
    SELF;
    check_blending_and_transform();
    al_draw_filled_rectangle(x, y, x_, y_, self->c);
    uncheck_blending();
}
void platform_filled_circle(float x, float y, float x_, float y_) {
    SELF;
    float cx = (x + x_) * 0.5;
    float cy = (y + y_) * 0.5;
    float rx = (x_ - x) * 0.5;
    float ry = (y_ - y) * 0.5;
    check_blending_and_transform();
    al_draw_filled_ellipse(cx, cy, rx, ry, self->c);
    uncheck_blending();
}
void platform_circle(float x, float y, float x_, float y_) {
    SELF;
    float cx = (x + x_) * 0.5;
    float cy = (y + y_) * 0.5;
    float rx = (x_ - x) * 0.5;
    float ry = (y_ - y) * 0.5;
    check_blending_and_transform();
    al_draw_ellipse(cx, cy, rx, ry, self->c, self->super.thickness);
    uncheck_blending();
}
void platform_arc(float x, float y, float x_, float y_, float a, float a_) {
    SELF;
    float cx = (x + x_) * 0.5;
    float cy = (y + y_) * 0.5;
    float rx = (x_ - x) * 0.5;
    check_blending_and_transform();
    al_draw_arc(cx, cy, rx, a, (a_ - a), self->c, self->super.thickness);
    uncheck_blending();
}
void platform_ribbon(int n, float * xy) {
    SELF;
    check_blending_and_transform();
    for (int i = 0; i < n - 1; i++) {
        float xy8 [8];
        xy8 [2] = xy [i * 2 + 0];
        xy8 [3] = xy [i * 2 + 1];
        xy8 [0] = xy [i * 2 + 0];
        xy8 [1] = xy [i * 2 + 1];
        xy8 [6] = xy [i * 2 + 2];
        xy8 [7] = xy [i * 2 + 3];
        xy8 [4] = xy [i * 2 + 2];
        xy8 [5] = xy [i * 2 + 3];
        float ex = xy8 [0] - xy8 [6];
        float ey = xy8 [1] - xy8 [7];
        float e = sqrt(ex * ex + ey * ey);
        e *= 0.33;
        if (i > 0) {
            float dx = xy [i * 2 + 2] - xy [(i - 1) * 2 + 0];
            float dy = xy [i * 2 + 3] - xy [(i - 1) * 2 + 1];
            float d = sqrt(dx * dx + dy * dy);
            xy8 [2] += e * dx / d;
            xy8 [3] += e * dy / d;
        }
        if (i < n - 2) {
            float dx = xy [i * 2 + 0] - xy [i * 2 + 4];
            float dy = xy [i * 2 + 1] - xy [i * 2 + 5];
            float d = sqrt(dx * dx + dy * dy);
            xy8 [4] += e * dx / d;
            xy8 [5] += e * dy / d;
        }
        al_draw_spline(xy8, self->c, self->super.thickness);
    }
    uncheck_blending();
}
void platform_ribbon_loop(int n, float * xy) {
    SELF;
    check_blending_and_transform();
    for (int i = 0; i < n; i++) {
        float xy8 [8];
        xy8 [2] = xy [i * 2 + 0];
        xy8 [3] = xy [i * 2 + 1];
        int i_n = (i + 1) % n;
        xy8 [0] = xy [i * 2 + 0];
        xy8 [1] = xy [i * 2 + 1];
        xy8 [6] = xy [i_n * 2 + 0];
        xy8 [7] = xy [i_n * 2 + 1];
        xy8 [4] = xy [i_n * 2 + 0];
        xy8 [5] = xy [i_n * 2 + 1];
        float ex = xy8 [0] - xy8 [6];
        float ey = xy8 [1] - xy8 [7];
        float e = sqrt(ex * ex + ey * ey);
        e *= 0.33;
        if (true) {
            int i_p = (i + n - 1) % n;
            float dx = xy [i_n * 2 + 0] - xy [i_p * 2 + 0];
            float dy = xy [i_n * 2 + 1] - xy [i_p * 2 + 1];
            float d = sqrt(dx * dx + dy * dy);
            xy8 [2] += e * dx / d;
            xy8 [3] += e * dy / d;
        }
        if (true) {
            int i_nn = (i_n + 1) % n;
            float dx = xy [i * 2 + 0] - xy [i_nn * 2 + 0];
            float dy = xy [i * 2 + 1] - xy [i_nn * 2 + 1];
            float d = sqrt(dx * dx + dy * dy);
            xy8 [4] += e * dx / d;
            xy8 [5] += e * dy / d;
        }
        al_draw_spline(xy8, self->c, self->super.thickness);
    }
    uncheck_blending();
}
void platform_filled_ribbon(int n, float * xy) {
    SELF;
    check_blending_and_transform();
    int q = 8;
    int points = n * (q - 1);
    float v [points * 2];
    for (int i = 0; i < n; i++) {
        float xy8 [8];
        xy8 [2] = xy [i * 2 + 0];
        xy8 [3] = xy [i * 2 + 1];
        int i_n = (i + 1) % n;
        xy8 [0] = xy [i * 2 + 0];
        xy8 [1] = xy [i * 2 + 1];
        xy8 [6] = xy [i_n * 2 + 0];
        xy8 [7] = xy [i_n * 2 + 1];
        xy8 [4] = xy [i_n * 2 + 0];
        xy8 [5] = xy [i_n * 2 + 1];
        float ex = xy8 [0] - xy8 [6];
        float ey = xy8 [1] - xy8 [7];
        float e = sqrt(ex * ex + ey * ey);
        e *= 0.33;
        if (true) {
            int i_p = (i + n - 1) % n;
            float dx = xy [i_n * 2 + 0] - xy [i_p * 2 + 0];
            float dy = xy [i_n * 2 + 1] - xy [i_p * 2 + 1];
            float d = sqrt(dx * dx + dy * dy);
            xy8 [2] += e * dx / d;
            xy8 [3] += e * dy / d;
        }
        if (true) {
            int i_nn = (i_n + 1) % n;
            float dx = xy [i * 2 + 0] - xy [i_nn * 2 + 0];
            float dy = xy [i * 2 + 1] - xy [i_nn * 2 + 1];
            float d = sqrt(dx * dx + dy * dy);
            xy8 [4] += e * dx / d;
            xy8 [5] += e * dy / d;
        }
        al_calculate_spline(v + (i * (q - 1)) * 2, 2 * sizeof (float), xy8, 0, q);
    }
    int holes [2] = {points, 0};
    platform_filled_polygon_with_holes(points, v, holes);
    uncheck_blending();
}
void platform_line(float x, float y, float x_, float y_) {
    SELF;
    check_blending_and_transform();
    al_draw_line(x, y, x_, y_, self->c, self->super.thickness);
    uncheck_blending();
}
void platform_polygon(int n, float * xy) {
    SELF;
    ALLEGRO_VERTEX v [n];
    memset(v, 0, n * sizeof (ALLEGRO_VERTEX));
    int j = 0;
    for (int i = 0; i < n; i++) {
        v [i].x = xy [j++];
        v [i].y = xy [j++];
        v [i].color = self->c;
    }
    check_blending_and_transform();
    al_draw_prim(v, NULL, NULL, 0, n, ALLEGRO_PRIM_LINE_LOOP);
    uncheck_blending();
}
void platform_filled_polygon(int n, float * xy) {
    SELF;
    ALLEGRO_VERTEX v [n];
    memset(v, 0, n * sizeof (ALLEGRO_VERTEX));
    int j = 0;
    for (int i = 0; i < n; i++) {
        v [i].x = xy [j++];
        v [i].y = xy [j++];
        v [i].color = self->c;
    }
    check_blending_and_transform();
    al_draw_prim(v, NULL, NULL, 0, n, ALLEGRO_PRIM_TRIANGLE_FAN);
    uncheck_blending();
}
void platform_textured_colored_polygon(LandImage * image, int n, float * xy, float * uv, float * rgba) {
    SELF;
    LandImagePlatform * pim = (void *) image;
    ALLEGRO_VERTEX v [n];
    memset(v, 0, n * sizeof (ALLEGRO_VERTEX));
    int j = 0;
    int k = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        v [i].x = xy [j++];
        v [i].y = xy [j++];
        if (uv) {
            v [i].u = uv [k++];
            v [i].v = uv [k++];
        }
        else {
            v [i].u = 0;
            v [i].v = 0;
        }
        if (rgba) {
            v [i].color.r = rgba [l++];
            v [i].color.g = rgba [l++];
            v [i].color.b = rgba [l++];
            v [i].color.a = rgba [l++];
        }
        else {
            v [i].color = self->c;
        }
    }
    check_blending_and_transform();
    al_draw_prim(v, NULL, pim ? pim->a5 : NULL, 0, n, ALLEGRO_PRIM_TRIANGLE_FAN);
    uncheck_blending();
}
void platform_textured_polygon(LandImage * image, int n, float * xy, float * uv) {
    platform_textured_colored_polygon(image, n, xy, uv, NULL);
}
void platform_filled_colored_polygon(int n, float * xy, float * rgba) {
    platform_textured_colored_polygon(NULL, n, xy, NULL, rgba);
}
void platform_filled_polygon_with_holes(int n, float * xy, int * holes) {
    SELF;
    check_blending_and_transform();
    al_draw_filled_polygon_with_holes(xy, holes, self->c);
    uncheck_blending();
}
void platform_3d_triangles(int n, LandFloat * xyzrgb) {
    ALLEGRO_VERTEX v [n];
    for (int i = 0; i < n; i += 1) {
        LandFloat * f = xyzrgb + i * 6;
        v [i].x = f [0];
        v [i].y = f [1];
        v [i].z = f [2];
        v [i].u = 0;
        v [i].v = 0;
        v [i].color.r = f [3];
        v [i].color.g = f [4];
        v [i].color.b = f [5];
        v [i].color.a = 1;
    }
    check_blending_and_transform();
    al_draw_prim(v, NULL, NULL, 0, n, ALLEGRO_PRIM_TRIANGLE_LIST);
    uncheck_blending();
}
void platform_plot(float x, float y) {
    SELF;
    check_blending_and_transform();
    al_draw_pixel(x, y, self->c);
    uncheck_blending();
}
void platform_pick_color(float x, float y) {
    SELF;
    float32_t r, g, b, a;
    self->c = al_get_pixel(al_get_target_bitmap(), x, y);
    al_unmap_rgba_f(self->c, & r, & g, & b, & a);
    super->color_r = r;
    super->color_g = g;
    super->color_b = b;
    super->color_a = a;
}
static int a5state [] = {ALLEGRO_ALPHA_TEST, ALLEGRO_ALPHA_FUNCTION, ALLEGRO_ALPHA_TEST_VALUE, ALLEGRO_WRITE_MASK, ALLEGRO_DEPTH_TEST, ALLEGRO_DEPTH_FUNCTION};
static int a5func [] = {ALLEGRO_RENDER_NEVER, ALLEGRO_RENDER_ALWAYS, ALLEGRO_RENDER_LESS, ALLEGRO_RENDER_EQUAL, ALLEGRO_RENDER_LESS_EQUAL, ALLEGRO_RENDER_GREATER, ALLEGRO_RENDER_NOT_EQUAL, ALLEGRO_RENDER_GREATER_EQUAL};
void platform_render_state(int state, int value) {
    int value2 = value;
    if (state == LAND_ALPHA_FUNCTION || state == LAND_DEPTH_FUNCTION) {
        value2 = a5func [value];
    }
    else if (state == LAND_WRITE_MASK) {
        value2 = 0;
        if (value & LAND_RED_MASK) {
            value2 |= ALLEGRO_MASK_RED;
        }
        if (value & LAND_GREEN_MASK) {
            value2 |= ALLEGRO_MASK_GREEN;
        }
        if (value & LAND_BLUE_MASK) {
            value2 |= ALLEGRO_MASK_BLUE;
        }
        if (value & LAND_ALPHA_MASK) {
            value2 |= ALLEGRO_MASK_ALPHA;
        }
        if (value & LAND_DEPTH_MASK) {
            value2 |= ALLEGRO_MASK_DEPTH;
        }
    }
    al_set_render_state(a5state [state], value2);
}
void platform_set_default_shaders(void) {
    SELF;
    if (! self->default_shader) {
        ALLEGRO_SHADER * shader;
        shader = al_create_shader(ALLEGRO_SHADER_GLSL);
        al_attach_shader_source(shader, ALLEGRO_VERTEX_SHADER, al_get_default_shader_source(ALLEGRO_SHADER_AUTO, ALLEGRO_VERTEX_SHADER));
        al_attach_shader_source(shader, ALLEGRO_PIXEL_SHADER, al_get_default_shader_source(ALLEGRO_SHADER_AUTO, ALLEGRO_PIXEL_SHADER));
        al_build_shader(shader);
        self->default_shader = shader;
    }
    al_use_shader(self->default_shader);
}
#undef SELF
static LandWidgetInterface * land_widget_mover_interface;
void land_widget_mover_mouse_tick(LandWidget * super) {
    LandWidgetMover * self = LAND_WIDGET_MOVER(super);
    if ((land_mouse_delta_b())) {
        if (land_mouse_b() & 1) {
            self->target->send_to_top = 1;
            self->dragged = 1;
        }
        else {
            self->dragged = 0;
        }
    }
    if ((land_mouse_b() & 1) && self->dragged) {
        land_widget_move(self->target, land_mouse_delta_x(), land_mouse_delta_y());
    }
}
LandWidget* land_widget_mover_new(LandWidget * parent, char const * text, int x, int y, int w, int h) {
    /* """Create a new mover widget.
     * By default, the widget will stretch in the horizontal and shrink in the
     * vertical direction.
     */
    LandWidgetMover * self;
    land_widget_mover_interface_initialize();
    land_alloc(self);
    LandWidget * base = (LandWidget *) self;
    land_widget_button_initialize(base, parent, text, NULL, NULL, x, y, w, h);
    base->vt = land_widget_mover_interface;
    land_widget_layout_set_shrinking(base, 0, 1);
    land_widget_theme_initialize(base);
    if (parent) {
        land_widget_layout(parent);
    }
    self->target = parent;
    self->dragged = 0;
    return base;
}
void land_widget_mover_set_target(LandWidget * self, LandWidget * target) {
    LAND_WIDGET_MOVER (self)->target = target;
}
void land_widget_mover_interface_initialize(void) {
    if (land_widget_mover_interface) {
        return ;
    }
    land_widget_button_interface_initialize();
    land_widget_mover_interface = land_widget_copy_interface(land_widget_button_interface, "mover");
    land_widget_mover_interface->mouse_tick = land_widget_mover_mouse_tick;
}
LandWidgetInterface * land_widget_container_interface;
void land_widget_container_destroy(LandWidget * base) {
    /* """Destroy the container and all its children."""
     */
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(base);
    if (self->mouse) {
        land_widget_unreference(self->mouse);
    }
    if (self->children) {
        LandListItem * item = self->children->first;
        while (item) {
            LandListItem * next = item->next;
            LandWidget * child = item->data;
            child->parent = NULL;
            land_widget_unreference(child);
            item = next;
        }
        land_list_destroy(self->children);
    }
    land_widget_base_destroy(base);
}
void land_widget_container_mouse_enter(LandWidget * super) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    LandWidget * child = land_widget_container_get_child_at_pos(super, land_mouse_x(), land_mouse_y());
    if (child) {
        land_widget_reference(child);
        child->got_mouse = 1;
        land_call_method(child, mouse_enter, (child));
        self->mouse = child;
    }
}
void land_widget_container_mouse_leave(LandWidget * super) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (self->mouse) {
        self->mouse->got_mouse = 0;
        land_call_method(self->mouse, mouse_leave, (self->mouse));
        if (self->mouse->got_mouse) {
            super->got_mouse = 1;
        }
        else {
            land_widget_unreference(self->mouse);
            self->mouse = NULL;
        }
    }
}
void land_widget_container_keyboard_enter(LandWidget * super) {
    /* """ Give keyboard focus to the container, and to children who requested
     * focus."""
     */
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (self->children) {
        LandListItem * item, * next;
        item = self->children->first;
        for (; item; item = next) {
            next = item->next;
            LandWidget * child = item->data;
            if (child->want_focus) {
                child->want_focus = 0;
                child->got_keyboard = 1;
                land_call_method(child, keyboard_enter, (child));
                self->keyboard = child;
                land_widget_reference(self->keyboard);
                break;
            }
        }
    }
}
void land_widget_container_keyboard_leave(LandWidget * super) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (self->keyboard) {
        self->keyboard->got_keyboard = 0;
        land_call_method(self->keyboard, keyboard_leave, (self->keyboard));
        if (self->keyboard->got_keyboard) {
            super->got_keyboard = 1;
            return ;
        }
        land_widget_unreference(self->keyboard);
        self->keyboard = NULL;
    }
}
LandListItem* land_widget_container_child_item(LandWidget * super, LandWidget * child) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (! self->children) {
        return NULL;
    }
    LandListItem * item = self->children->first;
    while (item) {
        if (item->data == child) {
            return item;
        }
        item = item->next;
    }
    return NULL;
}
void land_widget_container_to_top(LandWidget * super, LandWidget * child) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    LandListItem * item = land_widget_container_child_item(super, child);
    land_list_remove_item(self->children, item);
    land_list_insert_item(self->children, item);
}
void land_widget_container_draw(LandWidget * base) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(base);
    land_widget_theme_draw(base);
    if (! self->children) {
        return ;
    }
    if (! base->dont_clip) {
        float l, t, r, b;
        land_widget_inner_extents(base, & l, & t, & r, & b);
        land_clip_push();
        land_clip_intersect(l, t, r, b);
    }
    float cl, ct, cr, cb;
    land_get_clip(& cl, & ct, & cr, & cb);
    LandListItem * item = self->children->first;
    for (; item; item = item->next) {
        LandWidget * child = item->data;
        if (child->hidden) {
            continue;
        }
        if (! base->dont_clip && ! child->no_clip_check) {
            if ((child->box.x <= cr && child->box.x + child->box.w >= cl && child->box.y <= cb && child->box.y + child->box.h >= ct)) {
                land_widget_draw(child);
            }
        }
        else {
            land_widget_draw(child);
        }
    }
    if (! base->dont_clip) {
        land_clip_pop();
    }
}
void land_widget_container_move(LandWidget * super, float dx, float dy) {
    /* Move all children of the container when the container itself is moved.
     */
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (! self->children) {
        return ;
    }
    LandListItem * item = self->children->first;
    while (item) {
        LandWidget * child = item->data;
        land_widget_move(child, dx, dy);
        item = item->next;
    }
}
void land_widget_container_size(LandWidget * super, float dx, float dy) {
    if (dx || dy) {
        land_widget_layout(super);
    }
}
LandWidget* land_widget_container_get_descendant_at_pos(LandWidget * super, int x, int y) {
    /* Returns a descendant under a specific (absolute) position, or else the
     * widget itself.
     */
    LandWidget * child = land_widget_container_get_child_at_pos(super, x, y);
    if (child) {
        if (land_widget_is(child, LAND_WIDGET_ID_CONTAINER)) {
            return land_widget_container_get_descendant_at_pos(child, x, y);
        }
        return child;
    }
    return super;
}
LandWidget* land_widget_container_get_child_at_pos(LandWidget * super, int x, int y) {
    /* Returns the direct child under a specific (absolute) position.
     */
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (! self->children) {
        return NULL;
    }
    LandListItem * item = self->children->last;
    for (; item; item = item->prev) {
        LandWidget * child = item->data;
        if (child->hidden) {
            continue;
        }
        if ((x >= child->box.x && y >= child->box.y && x < child->box.x + child->box.w && y < child->box.y + child->box.h)) {
            return child;
        }
    }
    return NULL;
}
static void transfer_mouse_focus(LandWidget * base, LandWidget * child) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(base);
    if (child) {
        land_widget_reference(child);
    }
    if (self->mouse) {
        self->mouse->got_mouse = 0;
        land_call_method(self->mouse, mouse_leave, (self->mouse));
        if (self->mouse->got_mouse) {
            if (child) {
                land_widget_unreference(child);
            }
            return ;
        }
        land_widget_unreference(self->mouse);
        self->mouse = NULL;
    }
    if (child) {
        self->mouse = child;
        land_call_method(self->mouse, mouse_enter, (self->mouse));
    }
}
static void transfer_keyboard_focus(LandWidget * base) {
    base->got_keyboard = 0;
    land_widget_container_keyboard_leave(base);
    if (base->got_keyboard) {
        return ;
    }
    base->want_focus = 0;
    base->got_keyboard = 1;
    land_widget_container_keyboard_enter(base);
}
void land_widget_container_mouse_tick(LandWidget * super) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (self->mouse) {
        land_call_method(self->mouse, mouse_tick, (self->mouse));
    }
    LandWidget * mouse = land_widget_container_get_child_at_pos(super, land_mouse_x(), land_mouse_y());
    if (mouse != self->mouse && ! (land_mouse_b() & 1)) {
        transfer_mouse_focus(super, mouse);
    }
    if (self->children) {
        LandListItem * item, * next, * last;
        item = self->children->first;
        last = self->children->last;
        for (; item; item = next) {
            next = item->next;
            LandWidget * child = item->data;
            if (child->want_focus) {
                super->want_focus = 1;
            }
            if (child->send_to_top) {
                land_widget_container_to_top(super, child);
                child->send_to_top = 0;
            }
            if (item == last) {
                break;
            }
        }
    }
}
void land_widget_container_set_mouse_focus(LandWidget * super, LandWidget * mouse) {
    /* Only suceeds if the currently focused window agrees.
     */
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (mouse != self->mouse) {
        transfer_mouse_focus(super, mouse);
    }
}
void land_widget_container_keyboard_tick(LandWidget * super) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    if (super->want_focus) {
        transfer_keyboard_focus(super);
    }
    if (self->keyboard) {
        land_call_method(self->keyboard, keyboard_tick, (self->keyboard));
    }
}
void land_widget_container_tick(LandWidget * super) {
    land_widget_reference(super);
    land_call_method(super, mouse_tick, (super));
    land_call_method(super, keyboard_tick, (super));
    land_widget_unreference(super);
}
void land_widget_container_add(LandWidget * super, LandWidget * add) {
    LandWidgetContainer * self = LAND_WIDGET_CONTAINER(super);
    land_add_list_data(& self->children, add);
    land_widget_reference(add);
    add->parent = super;
}
void land_widget_container_remove(LandWidget * base, LandWidget * rem) {
    assert(rem->parent == base);
    rem->parent = NULL;
    land_remove_list_data(& LAND_WIDGET_CONTAINER (base)->children, rem);
    land_widget_unreference(rem);
}
void land_widget_container_remove_all(LandWidget * base) {
    while (1) {
        LandWidget * child = land_widget_container_child(base);
        if (! child) {
            break;
        }
        land_widget_container_remove(base, child);
    }
}
void land_widget_container_update(LandWidget * widget) {
    /* The update method is called after the add method. We simply defer it to
     * our children.
     */
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    if (! container->children) {
        return ;
    }
    LandListItem * item = container->children->first;
    while (item) {
        LandWidget * child = item->data;
        land_call_method(child, update, (child));
        item = item->next;
    }
}
LandWidget* land_widget_container_child(LandWidget * super) {
    /* Return the first child of the container or None.
     */
    LandWidgetContainer * self = (LandWidgetContainer *) super;
    LandList * l = self->children;
    if (l) {
        LandListItem * first = l->first;
        if (first) {
            return first->data;
        }
    }
    return NULL;
}
int land_widget_container_is_empty(LandWidget * super) {
    LandWidgetContainer * self = (LandWidgetContainer *) super;
    return ! self->children || self->children->count == 0;
}
void land_widget_container_initialize(LandWidget * super, LandWidget * parent, int x, int y, int w, int h) {
    land_widget_container_interface_initialize();
    LandWidgetContainer * self = (LandWidgetContainer *) super;
    land_widget_base_initialize(super, parent, x, y, w, h);
    super->vt = land_widget_container_interface;
    self->children = NULL;
    land_widget_layout_disable(super);
    land_widget_theme_initialize(super);
}
LandWidget* land_widget_container_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetContainer * self;
    land_alloc(self);
    land_widget_container_initialize(& self->super, parent, x, y, w, h);
    return & self->super;
}
void land_widget_container_interface_initialize(void) {
    if (land_widget_container_interface) {
        return ;
    }
    land_alloc(land_widget_container_interface);
    land_widget_interface_register(land_widget_container_interface);
    land_widget_container_interface->id = LAND_WIDGET_ID_BASE | LAND_WIDGET_ID_CONTAINER;
    land_widget_container_interface->name = land_strdup("container");
    land_widget_container_interface->destroy = land_widget_container_destroy;
    land_widget_container_interface->draw = land_widget_container_draw;
    land_widget_container_interface->tick = land_widget_container_tick;
    land_widget_container_interface->add = land_widget_container_add;
    land_widget_container_interface->remove = land_widget_container_remove;
    land_widget_container_interface->move = land_widget_container_move;
    land_widget_container_interface->size = land_widget_container_size;
    land_widget_container_interface->update = land_widget_container_update;
    land_widget_container_interface->mouse_tick = land_widget_container_mouse_tick;
    land_widget_container_interface->mouse_enter = land_widget_container_mouse_enter;
    land_widget_container_interface->mouse_leave = land_widget_container_mouse_leave;
    land_widget_container_interface->keyboard_tick = land_widget_container_keyboard_tick;
    land_widget_container_interface->keyboard_enter = land_widget_container_keyboard_enter;
    land_widget_container_interface->keyboard_leave = land_widget_container_keyboard_leave;
}
static LandWidgetInterface * land_widget_sizer_interface [8];
void land_widget_sizer_draw(LandWidget * widget) {
    land_widget_theme_draw(widget);
}
void land_widget_sizer_mouse_tick(LandWidget * super) {
    LandWidgetSizer * self = LAND_WIDGET_SIZER(super);
    if ((land_mouse_delta_b())) {
        if ((land_mouse_b() & 1)) {
            self->dragged = 1;
            self->drag_x = land_mouse_x() - self->target->box.x;
            self->drag_y = land_mouse_y() - self->target->box.y;
        }
        else {
            self->dragged = 0;
        }
    }
    if (((land_mouse_b() & 1) && self->dragged)) {
        float mx = 0, my = 0, sx = 0, sy = 0;
        float dx = land_mouse_x() - self->target->box.x - self->drag_x;
        float dy = land_mouse_y() - self->target->box.y - self->drag_y;
        if (self->position == 0) {
            sy = - dy;
            my = 1;
        }
        else if (self->position == 1) {
            sx = dx;
            sy = - dy;
            my = 1;
        }
        else if (self->position == 2) {
            sx = dx;
        }
        else if (self->position == 3) {
            sx = dx;
            sy = dy;
        }
        else if (self->position == 4) {
            sy = dy;
        }
        else if (self->position == 5) {
            sx = - dx;
            sy = dy;
            mx = 1;
        }
        else if (self->position == 6) {
            sx = - dx;
            mx = 1;
        }
        else if (self->position == 7) {
            sx = - dx;
            sy = - dy;
            mx = 1;
            my = 1;
        }
        float pw = self->target->box.w;
        float ph = self->target->box.h;
        self->target->box.flags |= GUL_RESIZE;
        land_widget_resize(self->target, sx, sy);
        sx = self->target->box.w - pw;
        sy = self->target->box.h - ph;
        land_widget_move(self->target, mx * (- sx), my * (- sy));
        self->drag_x += sx - mx * sx;
        self->drag_y += sy - my * sy;
        self->target->box.flags &= ~ GUL_RESIZE;
    }
}
LandWidget* land_widget_sizer_new(LandWidget * parent, int position, int x, int y, int w, int h) {
    /* Create a new sizer widget. By default it will use its parent as target,
     * and shrink depending on the position parameter.
     */
    LandWidgetSizer * self;
    land_widget_sizer_interface_initialize();
    land_alloc(self);
    LandWidget * super = & self->super;
    land_widget_base_initialize(super, parent, x, y, w, h);
    super->vt = land_widget_sizer_interface [position];
    if (position == 0 || position == 4) {
        land_widget_layout_set_shrinking(super, 0, 1);
    }
    if (position == 2 || position == 6) {
        land_widget_layout_set_shrinking(super, 1, 0);
    }
    else {
        land_widget_layout_set_shrinking(super, 1, 1);
    }
    land_widget_theme_initialize(super);
    if (parent) {
        land_widget_layout(parent);
    }
    self->target = parent;
    self->position = position;
    self->dragged = 0;
    return super;
}
void land_widget_sizer_set_target(LandWidget * self, LandWidget * target) {
    /* This does not set any references, as it is assumed the sizer is a descendant
     * of the target anyway.
     */
    LAND_WIDGET_SIZER (self)->target = target;
}
void land_widget_sizer_interface_initialize(void) {
    if (land_widget_sizer_interface [0]) {
        return ;
    }
    char const * dir [8] = {"t", "rt", "r", "rb", "b", "lb", "l", "lt"};
    for (int i = 0; i < 8; i++) {
        char str [256];
        snprintf(str, sizeof str, "sizer.%s", dir [i]);
        land_widget_sizer_interface [i] = land_widget_copy_interface(land_widget_base_interface, str);
        land_widget_sizer_interface [i]->draw = land_widget_sizer_draw;
        land_widget_sizer_interface [i]->mouse_tick = land_widget_sizer_mouse_tick;
    }
}
static double land_widget_cursor_blink_rate = 2;
static LandWidgetInterface * land_widget_edit_interface;
static int get_x_offset(LandWidget * base) {
    int x = base->box.x + base->element->il;
    LandWidgetEdit * self = LAND_WIDGET_EDIT(base);
    if (self->align_right) {
        int w = land_text_get_width(self->text);
        x = base->box.x + base->box.w - base->element->r - w - 0.5;
    }
    return x;
}
void land_widget_edit_draw(LandWidget * base) {
    LandWidgetEdit * self = LAND_WIDGET_EDIT(base);
    if (! base->no_decoration) {
        land_widget_box_draw(base);
    }
    if (! base->dont_clip) {
        int l = base->box.x + base->element->il;
        int t = base->box.y + base->element->it;
        int r = base->box.x + base->box.w - base->element->r;
        int b = base->box.y + base->box.h - base->element->ib;
        land_clip_push();
        land_clip_intersect(l, t, r, b);
    }
    if (self->text) {
        int x = get_x_offset(base);
        int y = base->box.y + base->box.h - base->element->ib;
        y -= land_font_height(land_font_current());
        land_widget_theme_color(base);
        land_text_pos(x, y);
        land_print(self->text);
        if (base->got_keyboard) {
            double pos = land_get_time() * land_widget_cursor_blink_rate;
            pos -= floor(pos);
            if (pos < 0.5) {
                int cx = land_text_get_char_offset(self->text, self->cursor);
                land_line(x + cx + 0.5, y, x + cx + 0.5, base->box.y + base->box.h - base->element->ib);
            }
        }
    }
    if (! base->dont_clip) {
        land_clip_pop();
    }
}
void land_widget_edit_mouse_tick(LandWidget * base) {
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(base);
    if (land_mouse_delta_b() & 1) {
        if (land_mouse_b() & 1) {
            base->want_focus = 1;
            int x = land_mouse_x() - get_x_offset(base);
            edit->cursor = land_text_get_char_index(edit->text, x);
        }
    }
}
#define M if(edit->modified) edit->modified(base)
void land_widget_edit_keyboard_tick(LandWidget * base) {
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(base);
    while (! land_keybuffer_empty()) {
        int k, u;
        land_keybuffer_next(& k, & u);
        edit->last_key = k;
        edit->last_char = u;
        if (u > 31 && u != 127) {
            edit->text = land_utf8_realloc_insert(edit->text, edit->cursor, u);
            edit->cursor++;
            M;
        }
        else {
            char * pos = edit->text;
            int l = 0;
            while (land_utf8_char(& pos)) {
                l++;
            }
            if (k == LandKeyLeft) {
                edit->cursor--;
                if (edit->cursor < 0) {
                    edit->cursor = 0;
                }
            }
            else if (k == LandKeyRight) {
                edit->cursor++;
                if (edit->cursor > l) {
                    edit->cursor = l;
                }
            }
            else if (k == LandKeyDelete) {
                if (edit->cursor < l) {
                    edit->text = land_utf8_realloc_remove(edit->text, edit->cursor);
                    M;
                }
            }
            else if (k == LandKeyBackspace) {
                if (edit->cursor > 0) {
                    edit->cursor--;
                    edit->text = land_utf8_realloc_remove(edit->text, edit->cursor);
                    M;
                }
            }
            else if (k == LandKeyHome) {
                edit->cursor = 0;
            }
            else if (k == LandKeyEnd) {
                edit->cursor = l;
            }
            else if (k == LandKeyEnter) {
                land_widget_container_keyboard_leave(base->parent);
            }
        }
    }
}
void land_widget_edit_destroy(LandWidget * base) {
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(base);
    if (edit->text) {
        land_free(edit->text);
    }
    land_widget_base_destroy(base);
}
void land_widget_edit_initialize(LandWidget * base, LandWidget * parent, char const * text, void(* modified)(LandWidget * self), int x, int y, int w, int h) {
    land_widget_base_initialize(base, parent, x, y, w, h);
    land_widget_edit_interface_initialize();
    base->vt = land_widget_edit_interface;
    LandWidgetEdit * self = LAND_WIDGET_EDIT(base);
    if (text) {
        self->text = land_strdup(text);
        land_widget_theme_set_minimum_size_for_text(base, text);
        if (base->box.min_width < w) {
            base->box.min_width = w;
        }
    }
    self->modified = modified;
}
LandWidget* land_widget_edit_new(LandWidget * parent, char const * text, void(* modified)(LandWidget * self), int x, int y, int w, int h) {
    LandWidgetEdit * edit;
    land_alloc(edit);
    LandWidget * self = (LandWidget *) edit;
    land_widget_edit_initialize(self, parent, text, modified, x, y, w, h);
    land_widget_theme_initialize(self);
    land_widget_layout(parent);
    return self;
}
void land_widget_edit_set_text(LandWidget * base, char const * text) {
    /* Changes the text of the edit widget to a copy of the given string. The
     * string itself is not touched nor referenced - if you allocated it, you
     * can immediately free it after this function returns.
     */
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(base);
    land_free(edit->text);
    edit->text = land_strdup(text);
    land_widget_theme_set_minimum_size_for_text(base, text);
    if (edit->cursor > land_utf8_count(text)) {
        edit->cursor = land_utf8_count(text);
    }
}
void land_widget_edit_align_right(LandWidget * base, bool yes) {
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(base);
    edit->align_right = yes;
}
char const* land_widget_edit_get_text(LandWidget * base) {
    /* Note: Points directly to the widget's text, only valid as long
     * as the widget is alive.
     */
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(base);
    return edit->text;
}
void land_widget_edit_interface_initialize(void) {
    if (land_widget_edit_interface) {
        return ;
    }
    land_widget_edit_interface = land_widget_copy_interface(land_widget_base_interface, "edit");
    land_widget_edit_interface->id |= LAND_WIDGET_ID_EDIT;
    land_widget_edit_interface->destroy = land_widget_edit_destroy;
    land_widget_edit_interface->draw = land_widget_edit_draw;
    land_widget_edit_interface->mouse_tick = land_widget_edit_mouse_tick;
    land_widget_edit_interface->keyboard_tick = land_widget_edit_keyboard_tick;
}
#undef M
LandWidgetInterface * land_widget_panel_interface;
void land_widget_panel_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetPanel * self = (LandWidgetPanel *) base;
    land_widget_panel_interface_initialize();
    LandWidgetContainer * super = & self->super;
    land_widget_container_initialize(& super->super, parent, x, y, w, h);
    base->vt = land_widget_panel_interface;
    land_widget_layout_enable(base);
    land_widget_theme_initialize(base);
}
LandWidget* land_widget_panel_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetPanel * self;
    land_alloc(self);
    land_widget_panel_initialize((LandWidget *) self, parent, x, y, w, h);
    return LAND_WIDGET(self);
}
void land_widget_panel_add(LandWidget * base, LandWidget * add) {
    land_widget_container_add(base, add);
    int f = land_widget_layout_freeze(base);
    land_widget_layout_set_grid_position(add, 0, 0);
    land_widget_layout_set_grid(base, 1, 1);
    if (f) {
        land_widget_layout_unfreeze(base);
    }
    land_widget_layout(base);
}
void land_widget_panel_interface_initialize(void) {
    if (land_widget_panel_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_panel_interface = land_widget_copy_interface(land_widget_container_interface, "panel");
    land_widget_panel_interface->id |= LAND_WIDGET_ID_PANEL;
    land_widget_panel_interface->add = land_widget_panel_add;
}
LandWidgetInterface * land_widget_scrollbar_vertical_interface;
LandWidgetInterface * land_widget_scrollbar_horizontal_interface;
static void scroll_vertical_cb(LandWidget * self, int set, int * _scramble_min, int * _scramble_max, int * range, int * pos) {
    /* If set is not 0, then the target window is scrolled according to the
     * scrollbar position.
     * If set is 0, then the min/max/range/pos parameters are updated.
     */
    LandWidgetScrollbar * bar = LAND_WIDGET_SCROLLBAR(self);
    LandWidget * target = bar->target;
    if (target) {
        LandWidget * viewport = target->parent;
        if (set) {
            int ty = viewport->box.y + viewport->element->it;
            if (target->box.y > ty) {
                ty = target->box.y;
            }
            ty -= * pos;
            land_widget_move(target, 0, ty - target->box.y);
        }
        else {
            * _scramble_min = 0;
            * _scramble_max = target->box.h - 1;
            * range = viewport->box.h - viewport->element->it - viewport->element->ib;
            * pos = viewport->box.y + viewport->element->it - target->box.y;
            if (* pos < * _scramble_min) {
                * _scramble_min = * pos;
            }
            if (* pos + * range - 1 > * _scramble_max) {
                * _scramble_max = * pos + * range - 1;
            }
        }
    }
    else {
        if (! set) {
            * _scramble_min = 0;
            * _scramble_max = 0;
            * range = 0;
            * pos = 0;
        }
    }
}
static void scroll_horizontal_cb(LandWidget * self, int set, int * _scramble_min, int * _scramble_max, int * range, int * pos) {
    LandWidgetScrollbar * bar = LAND_WIDGET_SCROLLBAR(self);
    LandWidget * target = bar->target;
    if (target) {
        LandWidget * viewport = target->parent;
        if (set) {
            int tx = viewport->box.x + viewport->element->il;
            if (target->box.x > tx) {
                tx = target->box.x;
            }
            tx -= * pos;
            land_widget_move(target, tx - target->box.x, 0);
        }
        else {
            * _scramble_min = 0;
            * _scramble_max = target->box.w - 1;
            * range = viewport->box.w - viewport->element->il - viewport->element->ir;
            * pos = viewport->box.x + viewport->element->il - target->box.x;
            if (* pos < * _scramble_min) {
                * _scramble_min = * pos;
            }
            if (* pos + * range - 1 > * _scramble_max) {
                * _scramble_max = * pos + * range - 1;
            }
        }
    }
    else {
        if (! set) {
            * _scramble_min = 0;
            * _scramble_max = 0;
            * range = 0;
            * pos = 0;
        }
    }
}
static int get_size(LandWidget * super) {
    LandWidgetScrollbar * self = LAND_WIDGET_SCROLLBAR(super);
    if (self->vertical) {
        return super->box.h;
    }
    else {
        return super->box.w;
    }
}
void land_widget_scrollbar_update(LandWidget * super, int set) {
    /* If set is not 0, then the target is updated from the scrollbar. Else the
     * scrollbar adjusts to the target's scrolled position.
     */
    LandWidgetScrollbar * self = LAND_WIDGET_SCROLLBAR(super);
    int minval, maxval, val, valrange;
    int minpos, maxpos, pos, posrange, minlen;
    self->callback(super, 0, & minval, & maxval, & valrange, & val);
    if (self->vertical) {
        minpos = super->parent->box.y + super->parent->element->it;
        maxpos = super->parent->box.y + super->parent->box.h - super->parent->element->ib - 1;
        pos = super->box.y;
        posrange = super->box.h;
        minlen = super->element->minh;
    }
    else {
        minpos = super->parent->box.x + super->parent->element->il;
        maxpos = super->parent->box.x + super->parent->box.w - super->parent->element->ir - 1;
        pos = super->box.x;
        posrange = super->box.w;
        minlen = super->element->minw;
    }
    if (set) {
        maxpos -= posrange - 1;
        maxval -= valrange - 1;
        if (maxpos <= minpos) {
            return ;
        }
        else {
            int rounded = maxpos - minpos - 1;
            val = (minval + (pos - minpos) * (maxval - minval) + rounded) / (maxpos - minpos);
        }
        self->callback(super, 1, & minval, & maxval, & valrange, & val);
    }
    else {
        if (maxval > minval) {
            posrange = (1 + maxpos - minpos) * valrange / (1 + maxval - minval);
        }
        else {
            posrange = 0;
        }
        if (posrange < minlen) {
            posrange = minlen;
        }
        maxpos -= posrange - 1;
        maxval -= valrange - 1;
        if (maxval == minval) {
            pos = minpos;
        }
        else {
            pos = minpos + (val - minval) * (maxpos - minpos) / (maxval - minval);
        }
        int dx = 0, dy = 0, dw = 0, dh = 0;
        if (self->vertical) {
            dw = super->parent->box.w - (super->parent->element->ir + super->parent->element->il) - super->box.w;
            dh = posrange - super->box.h;
            dx = super->parent->box.x + super->parent->element->il - super->box.x;
            dy = pos - super->box.y;
        }
        else {
            dw = posrange - super->box.w;
            dh = super->parent->box.h - (super->parent->element->ib + super->parent->element->it) - super->box.h;
            dx = pos - super->box.x;
            dy = super->parent->box.y + super->parent->element->it - super->box.y;
        }
        land_widget_move(super, dx, dy);
        land_widget_size(super, dw, dh);
    }
}
void land_widget_scrollbar_draw(LandWidget * self) {
    land_widget_theme_draw(self);
}
void land_widget_scrollbar_mouse_tick(LandWidget * super) {
    LandWidgetScrollbar * self = LAND_WIDGET_SCROLLBAR(super);
    if (land_mouse_delta_b()) {
        if (land_mouse_b() & 1) {
            self->drag_x = land_mouse_x() - super->box.x;
            self->drag_y = land_mouse_y() - super->box.y;
            self->dragged = 1;
        }
        else {
            self->dragged = 0;
        }
    }
    if ((land_mouse_b() & 1) && self->dragged) {
        int newx = land_mouse_x() - self->drag_x;
        int newy = land_mouse_y() - self->drag_y;
        int l = super->parent->box.x + super->parent->element->il;
        int t = super->parent->box.y + super->parent->element->it;
        int r = super->parent->box.x + super->parent->box.w - super->box.w - super->parent->element->ir;
        int b = super->parent->box.y + super->parent->box.h - super->box.h - super->parent->element->ib;
        if (newx > r) {
            newx = r;
        }
        if (newy > b) {
            newy = b;
        }
        if (newx < l) {
            newx = l;
        }
        if (newy < t) {
            newy = t;
        }
        int dx = newx - super->box.x;
        int dy = newy - super->box.y;
        land_widget_move(super, dx, dy);
        int old_size = get_size(super);
        land_widget_scrollbar_update(super, 1);
        land_widget_scrollbar_update(super, 0);
        int new_size = get_size(super);
        if (new_size > old_size) {
            if (self->vertical && dy > 0) {
                self->drag_y += new_size - old_size;
            }
            if (! self->vertical && dx > 0) {
                self->drag_x += new_size - old_size;
            }
        }
    }
}
LandWidget* land_widget_scrollbar_new(LandWidget * parent, LandWidget * target, int vertical, int x, int y, int w, int h) {
    LandWidgetScrollbar * self;
    land_widget_scrollbar_interface_initialize();
    land_alloc(self);
    LandWidget * super = & self->super;
    land_widget_base_initialize(super, parent, x, y, w, h);
    self->target = target;
    self->vertical = vertical;
    if (vertical) {
        self->callback = scroll_vertical_cb;
        super->vt = land_widget_scrollbar_vertical_interface;
    }
    else {
        self->callback = scroll_horizontal_cb;
        super->vt = land_widget_scrollbar_horizontal_interface;
    }
    land_widget_theme_initialize(super);
    return super;
}
void land_widget_scrollbar_interface_initialize(void) {
    if (! land_widget_scrollbar_vertical_interface) {
        LandWidgetInterface * i = land_widget_copy_interface(land_widget_base_interface, "scrollbar.vertical");
        i->id = LAND_WIDGET_ID_SCROLLBAR;
        i->draw = land_widget_scrollbar_draw;
        i->move = land_widget_base_move;
        i->mouse_tick = land_widget_scrollbar_mouse_tick;
        land_widget_scrollbar_vertical_interface = i;
    }
    if (! land_widget_scrollbar_horizontal_interface) {
        LandWidgetInterface * i = land_widget_copy_interface(land_widget_base_interface, "scrollbar.horizontal");
        i->id = LAND_WIDGET_ID_SCROLLBAR;
        i->draw = land_widget_scrollbar_draw;
        i->move = land_widget_base_move;
        i->mouse_tick = land_widget_scrollbar_mouse_tick;
        land_widget_scrollbar_horizontal_interface = i;
    }
}
static LandWidgetInterface * land_widget_book_interface;
static LandWidgetInterface * land_widget_tab_interface;
static LandWidgetInterface * land_widget_tab_l_interface;
static LandWidgetInterface * land_widget_tab_m_interface;
static LandWidgetInterface * land_widget_tab_r_interface;
static LandWidgetInterface * land_widget_tabbar_interface;
static LandWidgetInterface * land_widget_bookpage_interface;
static LandWidgetInterface * land_widget_bookpage_tabless_interface;
void land_widget_book_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h) {
    land_widget_book_interface_initialize();
    land_widget_container_initialize(base, parent, x, y, w, h);
    land_widget_layout_enable(base);
    LandWidget * page = land_widget_hbox_new(base, 0, 0, 10, 10);
    page->vt = land_widget_bookpage_interface;
    land_widget_theme_initialize(page);
    LandWidget * tabbar = land_widget_hbox_new(base, 0, 0, 10, 10);
    tabbar->dont_clip = 1;
    tabbar->vt = land_widget_tabbar_interface;
    land_widget_theme_initialize(tabbar);
    land_widget_layout_set_grid(base, 1, 2);
    land_widget_layout_set_grid_position(tabbar, 0, 0);
    land_widget_layout_set_grid_position(page, 0, 1);
    land_widget_layout_set_shrinking(tabbar, 0, 1);
    base->vt = land_widget_book_interface;
    land_widget_theme_initialize(base);
    land_call_method(parent, update, (parent));
}
void land_widget_book_show_page(LandWidget * self, LandWidget * page) {
    /* Change the visible page of the notebook. If ''page'' is None or not a
     * child of the notebook, then an empty tab will be shown.
     */
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(self);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandWidgetContainer * tabbar = LAND_WIDGET_CONTAINER(book->children->first->next->data);
    LandListItem * panelitem = panel->children->first;
    LandListItem * tabitem = tabbar->children->first;
    while (panelitem) {
        land_widget_hide(panelitem->data);
        LAND_WIDGET (tabitem->data)->selected = 0;
        panelitem = panelitem->next;
        tabitem = tabitem->next;
    }
    panelitem = panel->children->first;
    tabitem = tabbar->children->first;
    while (panelitem) {
        LandWidget * tab = LAND_WIDGET(tabitem->data);
        if (panelitem->data == page) {
            LandWidget * tabpanel = LAND_WIDGET(panelitem->data);
            land_widget_unhide(tabpanel);
            land_call_method(tab, update, (tabpanel));
            tab->selected = 1;
        }
        if (tabitem == tabbar->children->first) {
            if (tabitem->next) {
                tab->vt = land_widget_tab_l_interface;
            }
            else {
                tab->vt = land_widget_tab_interface;
            }
        }
        else if (tabitem->next) {
            tab->vt = land_widget_tab_m_interface;
        }
        else {
            tab->vt = land_widget_tab_r_interface;
        }
        land_widget_theme_update(tab);
        panelitem = panelitem->next;
        tabitem = tabitem->next;
    }
    land_widget_layout(LAND_WIDGET(book));
}
void land_widget_book_remove_page(LandWidget * widget, LandWidget * rem) {
    /* """Remove a widget from the book."""
     */
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(widget);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandWidgetContainer * tabbar = LAND_WIDGET_CONTAINER(book->children->first->next->data);
    LandListItem * panelitem = panel->children->first;
    LandListItem * tabitem = tabbar->children->first;
    while (panelitem) {
        if (panelitem->data == rem) {
            LandWidget * tab = tabitem->data;
            land_widget_remove(rem);
            land_widget_remove(tab);
            break;
        }
        panelitem = panelitem->next;
        tabitem = tabitem->next;
    }
    land_widget_book_show_page(widget, land_widget_book_get_current_page(widget));
}
static void clicked(LandWidget * button) {
    LandWidgetContainer * hbox = LAND_WIDGET_CONTAINER(button->parent);
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(button->parent->parent);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandListItem * panelitem = panel->children->first;
    LandListItem * item = hbox->children->first;
    while (item) {
        if (item->data == button) {
            land_widget_book_show_page(button->parent->parent, panelitem->data);
            break;
        }
        item = item->next;
        panelitem = panelitem->next;
    }
}
void land_widget_book_add(LandWidget * widget, LandWidget * add) {
    /* Add a new item to the notebook. This will not make it visible yet, use
     * [land_widget_book_show_page] for that.
     */
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandWidget * tabbar = container->children->first->next->data;
    LandWidget * panel = LAND_WIDGET(container->children->first->data);
    LandWidget * tab = land_widget_button_new(tabbar, "", clicked, 0, 0, 10, 10);
    tab->vt = land_widget_tab_interface;
    land_widget_theme_initialize(tab);
    land_widget_container_add(panel, add);
    land_widget_hide(add);
    land_widget_layout_set_grid(panel, 1, 1);
    land_widget_layout_set_grid_position(add, 0, 0);
}
void land_widget_book_pagename(LandWidget * widget, char const * name) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandWidgetContainer * hbox = LAND_WIDGET_CONTAINER(container->children->first->next->data);
    LandWidget * button = hbox->children->last->data;
    land_widget_button_set_text(button, name);
}
LandWidget* land_widget_book_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetBook * self;
    land_alloc(self);
    land_widget_book_initialize((LandWidget *) self, parent, x, y, w, h);
    return LAND_WIDGET(self);
}
LandWidget* land_widget_book_get_tabbar(LandWidget * widget) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandWidget * tabbar = container->children->first->next->data;
    return tabbar;
}
void land_widget_book_hide_tabbar(LandWidget * widget) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandWidget * tabbar = land_widget_book_get_tabbar(widget);
    LandWidget * panel = LAND_WIDGET(container->children->first->data);
    land_widget_hide(tabbar);
    panel->vt = land_widget_bookpage_tabless_interface;
    land_widget_theme_update(panel);
}
void land_widget_book_interface_initialize(void) {
    if (land_widget_book_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_book_interface = land_widget_copy_interface(land_widget_container_interface, "book");
    land_widget_book_interface->id |= LAND_WIDGET_ID_BOOK;
    land_widget_book_interface->add = land_widget_book_add;
    land_widget_button_interface_initialize();
    land_widget_tab_interface = land_widget_copy_interface(land_widget_button_interface, "tab");
    land_widget_tab_interface->id |= LAND_WIDGET_ID_TAB;
    land_widget_tab_l_interface = land_widget_copy_interface(land_widget_tab_interface, "tab.l");
    land_widget_tab_m_interface = land_widget_copy_interface(land_widget_tab_interface, "tab.m");
    land_widget_tab_r_interface = land_widget_copy_interface(land_widget_tab_interface, "tab.r");
    land_widget_hbox_interface_initialize();
    land_widget_tabbar_interface = land_widget_copy_interface(land_widget_hbox_interface, "tabbar");
    land_widget_tabbar_interface->id |= LAND_WIDGET_ID_TABBAR;
    land_widget_bookpage_interface = land_widget_copy_interface(land_widget_hbox_interface, "bookpage");
    land_widget_bookpage_interface->id |= LAND_WIDGET_ID_BOOKPAGE;
    land_widget_bookpage_tabless_interface = land_widget_copy_interface(land_widget_bookpage_interface, "bookpage.tabless");
}
LandWidget* land_widget_book_get_current_page(LandWidget * self) {
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(self);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandListItem * panelitem = panel->children->first;
    while (panelitem) {
        LandWidget * page = LAND_WIDGET(panelitem->data);
        if (! page->hidden) {
            return page;
        }
        panelitem = panelitem->next;
    }
    return NULL;
}
int land_widget_book_get_page_n(LandWidget * self, LandWidget * page) {
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(self);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandListItem * panelitem = panel->children->first;
    int i = 0;
    while (panelitem) {
        LandWidget * page_ = LAND_WIDGET(panelitem->data);
        if (page_ == page) {
            return i;
        }
        panelitem = panelitem->next;
        i++;
    }
    return - 1;
}
LandWidget* land_widget_book_get_last_page(LandWidget * self) {
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(self);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandListItem * panelitem = panel->children->last;
    if (panelitem) {
        return LAND_WIDGET(panelitem->data);
    }
    return NULL;
}
LandWidget* land_widget_book_get_nth_page(LandWidget * self, int n) {
    LandWidgetContainer * book = LAND_WIDGET_CONTAINER(self);
    LandWidgetContainer * panel = LAND_WIDGET_CONTAINER(book->children->first->data);
    LandListItem * panelitem = panel->children->first;
    int i = 0;
    while (panelitem) {
        LandWidget * page = LAND_WIDGET(panelitem->data);
        if (i == n) {
            return page;
        }
        panelitem = panelitem->next;
        i++;
    }
    return NULL;
}
void land_widget_book_show_nth(LandWidget * self, int n) {
    LandWidget * page = land_widget_book_get_nth_page(self, n);
    if (page) {
        land_widget_book_show_page(self, page);
    }
}
struct LandFontPlatform {
    LandFont super;
    ALLEGRO_FONT * a5;
};
void platform_font_init(void) {
    al_init_font_addon();
    al_init_ttf_addon();
}
void platform_font_exit(void) {
    ;
}
LandFont* platform_font_load(char const * filename, float size) {
    land_log_message("Loading font %s..", filename);
    LandFontPlatform * self;
    land_alloc(self);
    self->a5 = al_load_font(filename, size, 0);
    land_log_message_nostamp("%s.\n", self->a5 ? "success" : "failure");
    LandFont * super = (void *) self;
    if (self->a5) {
        super->size = al_get_font_line_height(self->a5);
    }
    super->xscaling = 1.0;
    super->yscaling = 1.0;
    return super;
}
LandFont* platform_font_from_image(LandImage * image, int n_ranges, int * ranges) {
    LandFontPlatform * self;
    LandImagePlatform * i = (void *) image;
    land_alloc(self);
    self->a5 = al_grab_font_from_bitmap(i->a5, n_ranges, ranges);
    LandFont * super = (void *) self;
    if (self->a5) {
        super->size = al_get_font_line_height(self->a5);
    }
    super->xscaling = 1.0;
    super->yscaling = 1.0;
    return super;
}
void platform_font_print(LandFontState * lfs, char const * str, int alignment) {
    LandFont * super = lfs->font;
    LandFontPlatform * self = (void *) super;
    if (! self->a5) {
        return ;
    }
    double xscaling = super->xscaling;
    double yscaling = super->yscaling;
    float x = lfs->x = lfs->x_pos;
    float y = lfs->y = lfs->y_pos;
    lfs->w = al_get_text_width(self->a5, str) * xscaling;
    lfs->h = al_get_font_line_height(self->a5) * yscaling;
    if (lfs->off) {
        return ;
    }
    if (xscaling != 1 || yscaling != 1) {
        land_push_transform();
        land_translate(x, y);
        land_scale(xscaling, yscaling);
        land_translate(- x, - y);
    }
    ALLEGRO_STATE state;
    al_store_state(& state, ALLEGRO_STATE_BLENDER);
    LandDisplay * d = _land_active_display;
    al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
    land_a5_display_check_transform();
    ALLEGRO_COLOR c = al_map_rgba_f(d->color_r, d->color_g, d->color_b, d->color_a);
    int a = ALLEGRO_ALIGN_INTEGER;
    if (alignment == LandAlignAdjust) {
        al_draw_justified_text(self->a5, c, x, x + lfs->adjust_width, y, lfs->adjust_width * 0.5, a | ALLEGRO_ALIGN_CENTRE, str);
    }
    else if (alignment == LandAlignCenter) {
        al_draw_text(self->a5, c, x, y, a | ALLEGRO_ALIGN_CENTRE, str);
    }
    else if (alignment == LandAlignRight) {
        al_draw_text(self->a5, c, x, y, a | ALLEGRO_ALIGN_RIGHT, str);
        lfs->x -= lfs->w;
    }
    else {
        al_draw_text(self->a5, c, x, y, a, str);
    }
    al_restore_state(& state);
    if (xscaling != 1 || yscaling != 1) {
        land_pop_transform();
    }
}
LandFont* platform_font_new(void) {
    return NULL;
}
void platform_font_destroy(LandFont * super) {
    LandFontPlatform * self = (void *) super;
    al_destroy_font(self->a5);
    land_free(self);
}
LandWidgetInterface * land_widget_board_interface;
void land_widget_board_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetBoard * self = (LandWidgetBoard *) base;
    land_widget_board_interface_initialize();
    LandWidgetContainer * super = & self->super;
    land_widget_container_initialize(& super->super, parent, x, y, w, h);
    base->vt = land_widget_board_interface;
    land_widget_theme_initialize(base);
}
LandWidget* land_widget_board_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetBoard * self;
    land_alloc(self);
    land_widget_board_initialize((LandWidget *) self, parent, x, y, w, h);
    return LAND_WIDGET(self);
}
void land_widget_board_add(LandWidget * base, LandWidget * add) {
    land_widget_container_add(base, add);
}
void land_widget_board_interface_initialize(void) {
    land_widget_container_interface_initialize();
    land_widget_board_interface = land_widget_copy_interface(land_widget_container_interface, "board");
    land_widget_board_interface->id |= LAND_WIDGET_ID_BOARD;
    land_widget_board_interface->add = land_widget_board_add;
}
LandWidgetInterface * land_widget_vbox_interface;
void land_widget_vbox_disable_updates(LandWidget * base) {
    /* Call this before adding *many* items to the vbox, then call
     * land_widget_vbox_update when done. This can speed things up, since there is
     * no need to calculate intermediate layouts for each single added item.
     */
    LAND_WIDGET_VBOX (base)->disable_updates = 1;
}
void land_widget_vbox_do_update(LandWidget * base) {
    /* Update the vbox, after updates have previously been disabled with
     * land_widget_vbox_disable_updates.
     */
    LAND_WIDGET_VBOX (base)->disable_updates = 0;
    land_widget_layout(base);
}
void land_widget_vbox_update(LandWidget * base) {
    /* This is called when a child is done adding itself. It's the earliest time
     * we can calculate the layout.
     * FIXME: the layout also is calculated in the add method, but that's wrong
     */
    land_widget_container_update(base);
    if (! LAND_WIDGET_VBOX (base)->disable_updates) {
        land_widget_layout(base);
    }
}
static void land_widget_vbox_renumber(LandWidget * base) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(base);
    LandWidgetVBox * vbox = LAND_WIDGET_VBOX(base);
    if (container->children) {
        int x = 0, y = 0;
        LandListItem * item = container->children->first;
        while (item) {
            LandWidget * child = item->data;
            land_widget_layout_set_grid_position(child, x, y);
            x++;
            if (x == vbox->columns) {
                x = 0;
                y++;
            }
            item = item->next;
        }
    }
    if (! vbox->disable_updates) {
        land_widget_vbox_do_update(base);
    }
}
void land_widget_vbox_add(LandWidget * base, LandWidget * add) {
    /* Add a widget to the vbox. It will be put to the end, going left to right
     * in columns and top to bottom in rows.
     */
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(base);
    LandWidgetVBox * vbox = LAND_WIDGET_VBOX(base);
    land_widget_container_add(base, add);
    int n = container->children->count;
    int rows = (n + vbox->columns - 1) / vbox->columns;
    int row = rows - 1;
    int column = n - row * vbox->columns - 1;
    int layout = land_widget_layout_freeze(base);
    land_widget_layout_set_grid_position(add, column, row);
    land_widget_layout_set_grid(base, vbox->columns, rows);
    if (layout) {
        land_widget_layout_unfreeze(base);
    }
    if (! vbox->disable_updates) {
        land_widget_vbox_do_update(base);
    }
}
void land_widget_vbox_remove(LandWidget * base, LandWidget * rem) {
    /* """Remove a widget from the vbox."""
     */
    int layout = land_widget_layout_freeze(base);
    land_widget_container_remove(base, rem);
    if (layout) {
        land_widget_layout_unfreeze(base);
    }
    land_widget_vbox_renumber(base);
}
void land_widget_vbox_set_columns(LandWidget * base, int n) {
    /* """Specify the number of columns for the vbox. By default, it is 1."""
     */
    LAND_WIDGET_VBOX (base)->columns = n;
}
void land_widget_vbox_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h) {
    /* """Initialize the given vbox widget."""
     */
    land_widget_vbox_interface_initialize();
    LandWidgetVBox * self = (LandWidgetVBox *) base;
    land_widget_container_initialize(base, parent, x, y, w, h);
    base->vt = land_widget_vbox_interface;
    land_widget_layout_enable(base);
    self->columns = 1;
    land_widget_theme_initialize(base);
}
LandWidget* land_widget_vbox_new(LandWidget * parent, int x, int y, int w, int h) {
    /* """Create a new vbox widget."""
     */
    LandWidgetVBox * self;
    land_alloc(self);
    LandWidget * widget = (LandWidget *) self;
    land_widget_vbox_initialize(widget, parent, x, y, w, h);
    return widget;
}
void land_widget_vbox_interface_initialize(void) {
    if (land_widget_vbox_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_vbox_interface = land_widget_copy_interface(land_widget_container_interface, "vbox");
    land_widget_vbox_interface->id |= LAND_WIDGET_ID_VBOX;
    land_widget_vbox_interface->add = land_widget_vbox_add;
    land_widget_vbox_interface->update = land_widget_vbox_update;
    land_widget_vbox_interface->remove = land_widget_vbox_remove;
}
LandWidgetInterface * land_widget_scrolling_interface;
static LandWidgetInterface * land_widget_scrolling_contents_container_interface;
static LandWidgetInterface * land_widget_scrolling_vertical_container_interface;
static LandWidgetInterface * land_widget_scrolling_horizontal_container_interface;
LandWidget* land_widget_scrolling_get_container(LandWidget * base) {
    LandList * children = LAND_WIDGET_CONTAINER (base)->children;
    LandWidget * w = children->first->data;
    return w;
}
LandWidget* land_widget_scrolling_get_vertical(LandWidget * base) {
    LandList * children = LAND_WIDGET_CONTAINER (base)->children;
    LandWidget * w = children->first->next->data;
    return w;
}
LandWidget* land_widget_scrolling_get_horizontal(LandWidget * base) {
    LandList * children = LAND_WIDGET_CONTAINER (base)->children;
    LandWidget * w = children->first->next->next->data;
    return w;
}
LandWidget* land_widget_scrolling_get_empty(LandWidget * base) {
    LandList * children = LAND_WIDGET_CONTAINER (base)->children;
    LandWidget * w = children->first->next->next->next->data;
    return w;
}
void land_widget_scrolling_move(LandWidget * widget, float dx, float dy) {
    land_widget_container_move(widget, dx, dy);
}
void land_widget_scrolling_autohide(LandWidget * widget, int hori, int vert, int empty) {
    /* Set hori/vert to 1 if the horizontal/vertical scrollbar should be auto
     * hidden. Set empty to 1 if the empty should be auto hidden, and set empty to
     * 2 if the empty should be hidden as soon as one bar is hidden.
     */
    LandWidgetScrolling * self = LAND_WIDGET_SCROLLING(widget);
    self->autohide = hori + 2 * vert + 4 * empty;
    land_widget_scrolling_update(widget);
}
int land_widget_scrolling_autobars(LandWidget * widget) {
    /* Returns 0 if nothing changed or 1 if something changed.
     */
    LandWidgetScrolling * self = LAND_WIDGET_SCROLLING(widget);
    if ((self->autohide & 3) == 0) {
        return 0;
    }
    LandWidget * container = land_widget_scrolling_get_container(widget);
    LandWidget * empty = land_widget_scrolling_get_empty(widget);
    LandWidget * vbox = land_widget_scrolling_get_vertical(widget);
    LandWidget * hbox = land_widget_scrolling_get_horizontal(widget);
    int f = land_widget_layout_freeze(widget);
    int before = 0;
    if (! vbox->hidden || ! hbox->hidden || ! empty->hidden) {
        if (! vbox->hidden) {
            before += 1;
            land_widget_hide(vbox);
        }
        if (! hbox->hidden) {
            before += 2;
            land_widget_hide(hbox);
        }
        if (! empty->hidden) {
            before += 4;
            land_widget_hide(empty);
        }
        land_widget_layout_set_grid_extra(container, 1, 1);
        land_widget_layout_set_grid_extra(hbox, 0, 0);
        land_widget_layout_set_grid_extra(vbox, 0, 0);
        if (f) {
            land_widget_layout_unfreeze(widget);
        }
        land_widget_layout(widget);
        f = land_widget_layout_freeze(widget);
    }
    LandWidget * vslider = land_widget_container_child(vbox);
    LandWidget * hslider = land_widget_container_child(hbox);
    int xa, xb, xr, xp;
    int ya, yb, yr, yp;
    LAND_WIDGET_SCROLLBAR (hslider)->callback(hslider, 0, & xa, & xb, & xr, & xp);
    LAND_WIDGET_SCROLLBAR (vslider)->callback(vslider, 0, & ya, & yb, & yr, & yp);
    int needh = self->autohide & 1 ? 0 : 1, needv = self->autohide & 2 ? 0 : 1;
    if (xp > xa || 1 + xb - xa > xr) {
        needh = 1;
    }
    if (yp > ya || 1 + yb - ya > yr) {
        needv = 1;
    }
    int neede = 1;
    if (self->autohide & 4) {
        if (! needh && ! needv) {
            neede = 0;
        }
    }
    if (self->autohide & 8) {
        if (! needh || ! needv) {
            neede = 0;
        }
    }
    if (! needh && ! needv && ! neede) {
        goto done;
    }
    if (! needh && ! needv) {
        land_widget_unhide(empty);
        land_widget_layout_set_grid_extra(container, 0, 0);
        goto done;
    }
    if (needh && needv) {
        land_widget_unhide(hbox);
        land_widget_unhide(vbox);
        land_widget_unhide(empty);
        land_widget_layout_set_grid_extra(container, 0, 0);
        goto done;
    }
    if (needh) {
        land_widget_unhide(hbox);
        if (neede) {
            land_widget_unhide(empty);
        }
        else {
            land_widget_layout_set_grid_extra(hbox, 1, 0);
        }
        land_widget_layout_set_grid_extra(container, 1, 0);
        if (f) {
            land_widget_layout_unfreeze(widget);
        }
        land_widget_layout(widget);
        LAND_WIDGET_SCROLLBAR (vslider)->callback(vslider, 0, & ya, & yb, & yr, & yp);
        needv = yp > ya || 1 + yb - ya > yr;
        f = land_widget_layout_freeze(widget);
        if (needv) {
            land_widget_unhide(vbox);
            land_widget_unhide(empty);
            land_widget_layout_set_grid_extra(hbox, 0, 0);
            land_widget_layout_set_grid_extra(container, 0, 0);
        }
        else {
            goto done;
        }
    }
    else {
        land_widget_unhide(vbox);
        if (neede) {
            land_widget_unhide(empty);
        }
        else {
            land_widget_layout_set_grid_extra(vbox, 0, 1);
        }
        land_widget_layout_set_grid_extra(container, 0, 1);
        if (f) {
            land_widget_layout_unfreeze(widget);
        }
        land_widget_layout(widget);
        LAND_WIDGET_SCROLLBAR (hslider)->callback(hslider, 0, & xa, & xb, & xr, & xp);
        needh = xp > xa || 1 + xb - xa > xr;
        f = land_widget_layout_freeze(widget);
        if (needh) {
            land_widget_unhide(hbox);
            land_widget_unhide(empty);
            land_widget_layout_set_grid_extra(vbox, 0, 0);
            land_widget_layout_set_grid_extra(container, 0, 0);
        }
        else {
            goto done;
        }
    }
    done:;
    if (f) {
        land_widget_layout_unfreeze(widget);
    }
    land_widget_layout(widget);
    int after = 0;
    if (! vbox->hidden) {
        after += 1;
    }
    if (! hbox->hidden) {
        after += 2;
    }
    if (! empty->hidden) {
        after += 4;
    }
    if (after == before) {
        return 0;
    }
    return 1;
}
static int scrolling_update_layout(LandWidget * widget) {
    /* Update the scrolling window after it was resized or scrolled. Returns 1
     * if any bars were hidden or unhidden.
     */
    int r = land_widget_scrolling_autobars(widget);
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandListItem * item = container->children->first;
    item = item->next;
    LandWidget * right = LAND_WIDGET(item->data);
    LandListItem * item2 = LAND_WIDGET_CONTAINER (right)->children->first;
    LandWidgetScrollbar * rightbar = LAND_WIDGET_SCROLLBAR(item2->data);
    land_widget_scrollbar_update(LAND_WIDGET(rightbar), 0);
    item = item->next;
    LandWidget * bottom = LAND_WIDGET(item->data);
    LandListItem * item3 = LAND_WIDGET_CONTAINER (bottom)->children->first;
    LandWidgetScrollbar * bottombar = LAND_WIDGET_SCROLLBAR(item3->data);
    land_widget_scrollbar_update(LAND_WIDGET(bottombar), 0);
    return r;
}
void land_widget_scrolling_update(LandWidget * widget) {
    scrolling_update_layout(widget);
}
void land_widget_scrolling_size(LandWidget * widget, float dx, float dy) {
    if (! (dx || dy)) {
        return ;
    }
    land_widget_scrolling_update(widget);
}
void land_widget_scrolling_get_scroll_position(LandWidget * base, float * x, float * y) {
    LandWidget * contents = LAND_WIDGET_CONTAINER (base)->children->first->data;
    LandList * children = LAND_WIDGET_CONTAINER (contents)->children;
    if (! children) {
        * x = 0;
        * y = 0;
        return ;
    }
    LandWidget * child = children->first->data;
    * x = child->box.x - contents->box.x - contents->element->il;
    * y = child->box.y - contents->box.y - contents->element->it;
}
void land_widget_scrolling_get_scroll_extents(LandWidget * base, float * x, float * y) {
    /* Determines the "scrollable area", that is how much overlap there is in
     * horizontal and vertical direction.
     */
    LandWidget * contents = LAND_WIDGET_CONTAINER (base)->children->first->data;
    LandList * children = LAND_WIDGET_CONTAINER (contents)->children;
    if (! children) {
        * x = 0;
        * y = 0;
        return ;
    }
    LandWidget * child = children->first->data;
    * x = child->box.w - contents->box.w + contents->element->il + contents->element->ir;
    * y = child->box.h - contents->box.h + contents->element->it + contents->element->ib;
    if (* x < 0) {
        * x = 0;
    }
    if (* y < 0) {
        * y = 0;
    }
}
void land_widget_scrolling_get_view(LandWidget * base, float * l, float * t, float * r, float * b) {
    /* Determine pixel coordinates of the viewable area.
     */
    LandWidget * contents = land_widget_scrolling_get_container(base);
    land_widget_inner_extents(contents, l, t, r, b);
}
void land_widget_scrolling_scrollto(LandWidget * base, float x, float y) {
    LandWidget * contents = LAND_WIDGET_CONTAINER (base)->children->first->data;
    LandList * children = LAND_WIDGET_CONTAINER (contents)->children;
    if (! children) {
        return ;
    }
    LandWidget * child = children->first->data;
    land_widget_move(child, contents->box.x + contents->element->il + x - child->box.x, contents->box.y + contents->element->it + y - child->box.y);
    land_widget_scrolling_update(base);
}
void land_widget_scrolling_scroll(LandWidget * base, float dx, float dy) {
    float x, y;
    land_widget_scrolling_get_scroll_position(base, & x, & y);
    land_widget_scrolling_scrollto(base, x + dx, y + dy);
}
void land_widget_scrolling_limit(LandWidget * base) {
    float x, y, w, h;
    land_widget_scrolling_get_scroll_position(base, & x, & y);
    land_widget_scrolling_get_scroll_extents(base, & w, & h);
    if (y < - h) {
        land_widget_scrolling_scrollto(base, x, - h);
    }
    if (y > 0) {
        land_widget_scrolling_scrollto(base, x, 0);
    }
}
void land_widget_scrolling_mouse_tick(LandWidget * base) {
    LandWidgetScrolling * self = LAND_WIDGET_SCROLLING(base);
    if (land_mouse_delta_z() && self->scrollwheel) {
        if (! (self->scrollwheel & 2)) {
            float w, h;
            land_widget_scrolling_get_scroll_extents(base, & w, & h);
            if (h <= 0) {
                return ;
            }
        }
        int dy = land_mouse_delta_z() * land_font_height(base->element->font);
        land_widget_scrolling_scroll(base, 0, dy);
        if (! (self->scrollwheel & 2)) {
            land_widget_scrolling_limit(base);
        }
    }
    land_widget_container_mouse_tick(base);
}
void land_widget_scrolling_tick(LandWidget * super) {
    ;
}
void land_widget_scrolling_add(LandWidget * widget, LandWidget * add) {
    /* Add a widget to the scrolling widget. The child widget can be bigger than
     * the parent, and scrollbars will appear to allow scrolling around.
     */
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandListItem * item = container->children->first;
    LandWidget * contents = LAND_WIDGET(item->data);
    land_widget_container_add(contents, add);
    add->box.x = contents->box.x + contents->element->il;
    add->box.y = contents->box.y + contents->element->it;
    item = item->next;
    LandWidgetContainer * right = LAND_WIDGET_CONTAINER(item->data);
    LandListItem * item2 = right->children->first;
    LandWidgetScrollbar * rightbar = LAND_WIDGET_SCROLLBAR(item2->data);
    rightbar->target = add;
    item = item->next;
    LandWidgetContainer * bottom = LAND_WIDGET_CONTAINER(item->data);
    item2 = bottom->children->first;
    LandWidgetScrollbar * bottombar = LAND_WIDGET_SCROLLBAR(item2->data);
    bottombar->target = add;
}
LandWidget* land_widget_scrolling_get_child(LandWidget * base) {
    /* Return the child window of the scrolling window. Usually, a scrolling
     * window has exactly one child window, which is controlled by the scrollbars.
     * That window is returned.
     */
    LandWidget * contents = LAND_WIDGET_CONTAINER (base)->children->first->data;
    LandList * children = LAND_WIDGET_CONTAINER (contents)->children;
    return children ? children->first->data : NULL;
}
void land_widget_scrolling_remove_child(LandWidget * base) {
    /* Detach the window managed inside the scrolled window. If there are no
     * other references to it, it will be destroyed.
     */
    LandList * list = LAND_WIDGET_CONTAINER (base)->children;
    LandWidget * contents = list->first->data;
    LandList * children = LAND_WIDGET_CONTAINER (contents)->children;
    LandWidget * child = children ? children->first->data : NULL;
    if (child) {
        land_widget_container_remove(contents, child);
    }
    LandWidgetContainer * c;
    c = LAND_WIDGET_CONTAINER(list->first->next->data);
    LAND_WIDGET_SCROLLBAR (c->children->first->data)->target = NULL;
    c = LAND_WIDGET_CONTAINER(list->first->next->next->data);
    LAND_WIDGET_SCROLLBAR (c->children->first->data)->target = NULL;
}
void land_widget_scrolling_initialize(LandWidget * widget, LandWidget * parent, int x, int y, int w, int h) {
    land_widget_scrolling_interface_initialize();
    land_widget_container_initialize(widget, parent, x, y, w, h);
    land_widget_layout_enable(widget);
    widget->vt = land_widget_container_interface;
    LandWidgetScrolling * scrolling = (void *) widget;
    scrolling->scrollwheel = 1;
    LandWidget * contents = land_widget_container_new(widget, 0, 0, 0, 0);
    contents->vt = land_widget_scrolling_contents_container_interface;
    land_widget_theme_initialize(contents);
    LandWidget * right = land_widget_container_new(widget, 0, 0, 0, 0);
    right->vt = land_widget_scrolling_vertical_container_interface;
    land_widget_theme_initialize(right);
    land_widget_scrollbar_new(right, NULL, 1, right->element->il, right->element->it, 0, 0);
    LandWidget * bottom = land_widget_container_new(widget, 0, 0, 0, 0);
    bottom->vt = land_widget_scrolling_horizontal_container_interface;
    land_widget_theme_initialize(bottom);
    land_widget_scrollbar_new(bottom, NULL, 0, bottom->element->il, bottom->element->it, 0, 0);
    land_widget_layout_set_grid(widget, 2, 2);
    land_widget_layout_set_grid_position(contents, 0, 0);
    land_widget_layout_set_grid_position(right, 1, 0);
    land_widget_layout_set_shrinking(right, 1, 0);
    land_widget_layout_set_grid_position(bottom, 0, 1);
    land_widget_layout_set_shrinking(bottom, 0, 1);
    LandWidget * empty = land_widget_vbox_new(widget, 0, 0, 0, 0);
    land_widget_layout_set_grid_position(empty, 1, 1);
    land_widget_layout_set_shrinking(empty, 1, 1);
    widget->vt = land_widget_scrolling_interface;
    land_widget_theme_initialize(widget);
    land_widget_layout(widget);
}
void land_widget_scrolling_wheel(LandWidget * widget, int wheel) {
    /* 0: no wheel scrolling
     * 1: wheel scrolling [default]
     * 2: unlimited scrolling
     */
    LandWidgetScrolling * self = LAND_WIDGET_SCROLLING(widget);
    self->scrollwheel = wheel;
}
LandWidget* land_widget_scrolling_new(LandWidget * parent, int x, int y, int w, int h) {
    /* Creates a new Scrolling widget. You can add a child widget to it, and it
     * will automatically display scrollbars and translate mouse coordinates.
     * By default, the widget will expand in all directions.
     */
    LandWidgetScrolling * self;
    land_alloc(self);
    LandWidget * widget = (LandWidget *) self;
    land_widget_scrolling_initialize(widget, parent, x, y, w, h);
    return widget;
}
void land_widget_scrolling_layout_changed(LandWidget * widget) {
    if (widget->box.w != widget->box.ow || widget->box.h != widget->box.oh) {
        int r = scrolling_update_layout(widget);
        if (r) {
            _land_gul_layout_updated_during_layout(widget);
            widget->layout_hack = 1;
        }
    }
}
void land_widget_scrolling_layout_changing(LandWidget * widget) {
    ;
}
void land_widget_scrolling_interface_initialize(void) {
    if (land_widget_scrolling_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_scrolling_interface = land_widget_copy_interface(land_widget_container_interface, "scrolling");
    land_widget_scrolling_interface->id |= LAND_WIDGET_ID_SCROLLING;
    land_widget_scrolling_interface->tick = land_widget_scrolling_tick;
    land_widget_scrolling_interface->add = land_widget_scrolling_add;
    land_widget_scrolling_interface->update = land_widget_scrolling_update;
    land_widget_scrolling_interface->move = land_widget_scrolling_move;
    land_widget_scrolling_interface->size = land_widget_scrolling_size;
    land_widget_scrolling_interface->layout_changed = land_widget_scrolling_layout_changed;
    land_widget_scrolling_interface->layout_changing = land_widget_scrolling_layout_changing;
    land_widget_scrolling_interface->mouse_tick = land_widget_scrolling_mouse_tick;
    land_widget_scrolling_contents_container_interface = land_widget_copy_interface(land_widget_container_interface, "scrolling.contents.container");
    land_widget_scrolling_vertical_container_interface = land_widget_copy_interface(land_widget_container_interface, "scrolling.vertical.container");
    land_widget_scrolling_horizontal_container_interface = land_widget_copy_interface(land_widget_container_interface, "scrolling.horizontal.container");
}
LandWidgetInterface * land_widget_checkbox_interface;
LandWidgetInterface * land_widget_checkbox_button_interface;
LandWidgetInterface * land_widget_checkbox_description_interface;
static void cb_clicked(LandWidget * widget) {
    LandWidgetCheckBox * cb = LAND_WIDGET_CHECKBOX(widget->parent);
    if (widget->selected) {
        widget->selected = 0;
        land_widget_button_replace_text(widget, cb->checkbox_unselected);
    }
    else {
        widget->selected = 1;
        land_widget_button_replace_text(widget, cb->checkbox_selected);
    }
}
void land_widget_checkbox_initialize(LandWidget * base, LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, int x, int y, int w, int h) {
    LandWidgetCheckBox * self = (void *) base;
    self->checkbox_selected = land_strdup(checkbox_selected);
    self->checkbox_unselected = land_strdup(checkbox_unselected);
    land_widget_checkbox_interface_initialize();
    land_widget_container_initialize(base, parent, x, y, w, h);
    base->vt = land_widget_checkbox_interface;
    LandWidget * checkbox = land_widget_button_new(base, checkbox_selected, cb_clicked, 0, 0, 8, 8);
    checkbox->vt = land_widget_checkbox_button_interface;
    land_widget_theme_initialize(checkbox);
    land_widget_layout_set_shrinking(checkbox, 1, 0);
    LandWidget * description = land_widget_text_new(base, text, 0, 0, 0, 8, 8);
    description->vt = land_widget_checkbox_description_interface;
    land_widget_theme_initialize(description);
    land_widget_layout_set_grid(base, 2, 1);
    land_widget_layout_set_grid_position(checkbox, 0, 0);
    land_widget_layout_set_grid_position(description, 1, 0);
    land_widget_theme_initialize(base);
    land_widget_layout_enable(base);
    land_widget_layout(base);
    land_widget_button_replace_text(checkbox, checkbox_unselected);
}
LandWidget* land_widget_checkbox_new(LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, int x, int y, int w, int h) {
    LandWidgetCheckBox * self;
    land_alloc(self);
    land_widget_checkbox_initialize((LandWidget *) self, parent, checkbox_selected, checkbox_unselected, text, x, y, w, h);
    return (LandWidget *) self;
}
bool land_widget_checkbox_is_checked(LandWidget * self) {
    return land_widget_container_child (self)->selected;
}
void land_widget_checkbox_interface_initialize(void) {
    if (land_widget_checkbox_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_checkbox_interface = land_widget_copy_interface(land_widget_container_interface, "checkbox");
    land_widget_checkbox_interface->id |= LAND_WIDGET_ID_CHECKBOX;
    land_widget_checkbox_interface->destroy = land_widget_checkbox_destroy;
    land_widget_button_interface_initialize();
    land_widget_checkbox_button_interface = land_widget_copy_interface(land_widget_button_interface, "checkbox.box");
    land_widget_checkbox_description_interface = land_widget_copy_interface(land_widget_button_interface, "checkbox.description");
}
void land_widget_checkbox_destroy(LandWidget * base) {
    LandWidgetCheckBox * self = LAND_WIDGET_CHECKBOX(base);
    if (self->checkbox_selected) {
        land_free(self->checkbox_selected);
    }
    if (self->checkbox_unselected) {
        land_free(self->checkbox_unselected);
    }
    land_widget_container_destroy(base);
}
static LandWidgetInterface * land_widget_slider_interface;
static LandWidgetInterface * land_widget_handle_horizontal_interface;
LandWidget* land_widget_handle_new(LandWidget * parent, float minval, float maxval, bool vertical, void(* update)(LandWidget *), int x, int y, int w, int h) {
    LandWidgetHandle * self;
    land_alloc(self);
    LandWidget * super = (void *) self;
    land_widget_handle_interface_initialize();
    land_widget_base_initialize(super, parent, x, y, w, h);
    super->vt = land_widget_handle_horizontal_interface;
    land_widget_theme_initialize(super);
    self->vertical = vertical;
    self->minval = minval;
    self->maxval = maxval;
    self->update = update;
    self->value = minval;
    super->no_clip_check = 1;
    self->super.box.w = self->super.box.min_width;
    self->super.box.h = self->super.box.min_height;
    return super;
}
LandWidget* land_widget_slider_new(LandWidget * parent, float minval, float maxval, bool vertical, void(* update)(LandWidget *), int x, int y, int w, int h) {
    /* vertical - whether the slider is vertical
     */
    LandWidgetSlider * self;
    land_widget_slider_interface_initialize();
    land_alloc(self);
    LandWidget * super = (void *) self;
    land_widget_container_initialize(super, parent, x, y, w, h);
    super->vt = land_widget_slider_interface;
    land_widget_theme_initialize(super);
    LandWidget * handle = land_widget_handle_new(super, minval, maxval, vertical, update, x + super->element->il, y + super->element->it, 0, 0);
    land_widget_layout_set_minimum_size(super, handle->box.min_width + super->element->il + super->element->it, handle->box.min_height + super->element->il + super->element->it);
    return super;
}
void land_widget_slider_size(LandWidget * widget, float dx, float dy) {
    if (! (dx || dy)) {
        return ;
    }
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(widget);
    LandListItem * item = container->children->first;
    LandWidget * handle = LAND_WIDGET(item->data);
    land_widget_handle_update(handle, 0);
}
void land_widget_handle_update(LandWidget * super, int set) {
    /* Either set the value from the slider position, or else update the slider
     * position from the value.
     */
    LandWidgetHandle * self = LAND_WIDGET_HANDLE(super);
    float minpos, maxpos;
    float n, i;
    n = self->maxval - self->minval;
    i = self->value - self->minval;
    minpos = super->parent->box.x + super->parent->element->il;
    maxpos = super->parent->box.x + super->parent->box.w - super->parent->element->ir;
    maxpos -= super->box.w;
    if (set) {
        self->value = self->minval + (super->box.x - minpos) * n / (maxpos - minpos);
        if (self->update) {
            self->update(super);
        }
    }
    else {
        super->box.x = minpos + i * (maxpos - minpos) / n;
        super->box.y = super->parent->box.y + super->parent->element->it;
    }
}
void land_widget_handle_draw(LandWidget * super) {
    land_widget_handle_update(super, 0);
    land_widget_theme_draw(super);
}
void land_widget_handle_mouse_tick(LandWidget * super) {
    LandWidgetHandle * self = LAND_WIDGET_HANDLE(super);
    if (land_mouse_delta_b()) {
        if (land_mouse_b() & 1) {
            self->drag_x = land_mouse_x() - super->box.x;
            self->drag_y = land_mouse_y() - super->box.y;
            self->dragged = 1;
        }
        else {
            self->dragged = 0;
        }
    }
    if ((land_mouse_b() & 1) && self->dragged) {
        int newx = land_mouse_x() - self->drag_x;
        int newy = land_mouse_y() - self->drag_y;
        int l = super->parent->box.x + super->parent->element->il;
        int t = super->parent->box.y + super->parent->element->it;
        int r = super->parent->box.x + super->parent->box.w - super->box.w - super->parent->element->ir;
        int b = super->parent->box.y + super->parent->box.h - super->box.h - super->parent->element->ib;
        if (newx > r) {
            newx = r;
        }
        if (newy > b) {
            newy = b;
        }
        if (newx < l) {
            newx = l;
        }
        if (newy < t) {
            newy = t;
        }
        newy = t;
        int dx = newx - super->box.x;
        int dy = newy - super->box.y;
        land_widget_move(super, dx, dy);
        land_widget_handle_update(super, 1);
    }
}
void land_widget_slider_set_value(LandWidget * super, float value) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(super);
    LandListItem * item = container->children->first;
    LandWidgetHandle * handle = LAND_WIDGET_HANDLE(item->data);
    handle->value = value;
    land_widget_handle_update(LAND_WIDGET(handle), 0);
}
float land_widget_slider_get_value(LandWidget * super) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(super);
    LandListItem * item = container->children->first;
    LandWidgetHandle * handle = LAND_WIDGET_HANDLE(item->data);
    return handle->value;
}
void land_widget_slider_interface_initialize(void) {
    if (land_widget_slider_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_slider_interface = land_widget_copy_interface(land_widget_container_interface, "slider.horizontal");
    land_widget_slider_interface->id |= LAND_WIDGET_ID_SLIDER;
    land_widget_slider_interface->size = land_widget_slider_size;
}
void land_widget_handle_interface_initialize(void) {
    if (land_widget_handle_horizontal_interface) {
        return ;
    }
    land_widget_base_interface_initialize();
    land_widget_handle_horizontal_interface = land_widget_copy_interface(land_widget_base_interface, "handle.horizontal");
    land_widget_handle_horizontal_interface->id |= LAND_WIDGET_ID_HANDLE;
    land_widget_handle_horizontal_interface->draw = land_widget_handle_draw;
    land_widget_handle_horizontal_interface->mouse_tick = land_widget_handle_mouse_tick;
}
LandWidgetInterface * land_widget_hbox_interface;
void land_widget_hbox_disable_updates(LandWidget * base) {
    LAND_WIDGET_HBOX (base)->disable_updates = 1;
}
void land_widget_hbox_do_update(LandWidget * base) {
    LAND_WIDGET_HBOX (base)->disable_updates = 0;
    land_widget_layout(base);
}
void land_widget_hbox_update(LandWidget * base) {
    land_widget_container_update(base);
    if (! LAND_WIDGET_HBOX (base)->disable_updates) {
        land_widget_layout(base);
    }
}
static void land_widget_hbox_renumber(LandWidget * base) {
    int layout = land_widget_layout_freeze(base);
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(base);
    LandWidgetHBox * hbox = LAND_WIDGET_HBOX(base);
    if (container->children) {
        int x = 0, y = 0;
        LandListItem * item = container->children->first;
        while (item) {
            LandWidget * child = item->data;
            land_widget_layout_set_grid_position(child, x, y);
            y++;
            if (y == hbox->rows) {
                x++;
                y = 0;
            }
            item = item->next;
        }
    }
    if (layout) {
        land_widget_layout_unfreeze(base);
    }
    if (! hbox->disable_updates) {
        land_widget_hbox_do_update(base);
    }
}
void land_widget_hbox_add(LandWidget * base, LandWidget * add) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(base);
    LandWidgetHBox * hbox = LAND_WIDGET_HBOX(base);
    land_widget_container_add(base, add);
    int n = container->children->count;
    int columns = (n + hbox->rows - 1) / hbox->rows;
    int column = columns - 1;
    int row = n - column * hbox->rows - 1;
    int f = land_widget_layout_freeze(base);
    land_widget_layout_set_grid_position(add, column, row);
    land_widget_layout_set_grid(base, columns, hbox->rows);
    if (f) {
        land_widget_layout_unfreeze(base);
    }
    if (! hbox->disable_updates) {
        land_widget_hbox_do_update(base);
    }
}
void land_widget_hbox_remove(LandWidget * base, LandWidget * rem) {
    int layout = land_widget_layout_freeze(base);
    land_widget_container_remove(base, rem);
    if (layout) {
        land_widget_layout_unfreeze(base);
    }
    land_widget_hbox_renumber(base);
}
void land_widget_hbox_set_rows(LandWidget * base, int n) {
    LAND_WIDGET_HBOX (base)->rows = n;
}
void land_widget_hbox_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h) {
    land_widget_hbox_interface_initialize();
    LandWidgetHBox * self = (LandWidgetHBox *) base;
    land_widget_container_initialize(base, parent, x, y, w, h);
    base->vt = land_widget_hbox_interface;
    land_widget_layout_enable(base);
    self->rows = 1;
    land_widget_theme_initialize(base);
}
LandWidget* land_widget_hbox_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetHBox * self;
    land_alloc(self);
    LandWidget * widget = (LandWidget *) self;
    land_widget_hbox_initialize(widget, parent, x, y, w, h);
    return widget;
}
void land_widget_hbox_interface_initialize(void) {
    if (land_widget_hbox_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_hbox_interface = land_widget_copy_interface(land_widget_container_interface, "hbox");
    land_widget_hbox_interface->id |= LAND_WIDGET_ID_HBOX;
    land_widget_hbox_interface->add = land_widget_hbox_add;
    land_widget_hbox_interface->remove = land_widget_hbox_remove;
    land_widget_hbox_interface->update = land_widget_hbox_update;
}
static LandWidgetInterface * land_widget_menu_interface;
static LandWidgetInterface * land_widget_menubutton_interface;
static LandWidgetInterface * land_widget_menubar_interface;
static LandWidgetInterface * land_widget_menuitem_interface;
LandWidget* land_widget_menubar_new(LandWidget * parent, float x, float y, float w, float h) {
    /* Create a new menubar. That is, a menu which is layout horizontally instead
     * of vertically. By default, a menubar will expand horizontally, and shrink
     * vertically.
     */
    LandWidget * base = land_widget_menu_new(parent, x, y, w, h);
    base->vt = land_widget_menubar_interface;
    land_widget_theme_initialize(base);
    land_widget_layout_set_shrinking(base, 1, 1);
    return base;
}
LandWidget* land_widget_menu_new(LandWidget * parent, float x, float y, float w, float h) {
    /* Create a new menu, with menu items layout out vertically.
     */
    land_widget_menu_interface_initialize();
    LandWidgetMenu * self;
    land_alloc(self);
    LandWidget * base = (LandWidget *) self;
    land_widget_container_initialize(base, parent, x, y, w, h);
    base->vt = land_widget_menu_interface;
    land_widget_layout_enable(base);
    land_widget_theme_initialize(base);
    return base;
}
void land_widget_menu_hide_sub(LandWidget * base) {
    /* Hide the given menu and all its sub-menus.
     */
    LandWidgetMenu * menu = LAND_WIDGET_MENU(base);
    if (menu->submenu) {
        land_widget_menu_hide_sub(menu->submenu);
        menu->submenu = NULL;
    }
    land_widget_hide(base);
}
void land_widget_menu_hide_complete(LandWidget * base) {
    /* Hide the complete menu the given one is part of.
     */
    while (1) {
        LandWidgetMenu * menu = LAND_WIDGET_MENU(base);
        if (! menu->menubutton) {
            break;
        }
        LandWidgetMenuButton * button = LAND_WIDGET_MENUBUTTON(menu->menubutton);
        if (button->menu) {
            base = button->menu;
        }
        else {
            break;
        }
    }
    if (((base->vt->id & LAND_WIDGET_ID_MENUBAR) == LAND_WIDGET_ID_MENUBAR)) {
        LandWidgetMenu * menu = LAND_WIDGET_MENU(base);
        base = menu->submenu;
        if (! base) {
            return ;
        }
        menu->submenu = NULL;
    }
    land_widget_menu_hide_sub(base);
}
static void menubutton_clicked(LandWidget * base) {
    LandWidgetMenuButton * self = LAND_WIDGET_MENUBUTTON(base);
    if (self->below) {
        land_widget_move(self->submenu, base->box.x - self->submenu->box.x, base->box.y + base->box.h - self->submenu->box.y);
    }
    else {
        land_widget_move(self->submenu, base->box.x + base->box.w - self->submenu->box.x, base->box.y - self->submenu->box.y);
    }
    if ((self->menu && (self->menu->vt->id & LAND_WIDGET_ID_MENU) == LAND_WIDGET_ID_MENU)) {
        LandWidgetMenu * menu = LAND_WIDGET_MENU(self->menu);
        if (menu->submenu) {
            land_widget_menu_hide_sub(menu->submenu);
        }
        menu->submenu = self->submenu;
    }
    self->submenu->send_to_top = 1;
    land_widget_unhide(self->submenu);
    land_widget_layout(self->submenu);
}
static void menuitem_clicked(LandWidget * base) {
    LandWidgetMenuItem * self = LAND_WIDGET_MENUITEM(base);
    if (self->menu && land_widget_is(self->menu, LAND_WIDGET_ID_MENU)) {
        land_widget_menu_hide_complete(self->menu);
    }
    if (self->callback) {
        self->callback(LAND_WIDGET(self));
    }
}
LandWidget* land_widget_menubutton_new(LandWidget * parent, char const * name, LandWidget * submenu, float x, float y, float w, float h) {
    /* Create a submenu, i.e. a button in a menu to open another menu when clicked.
     */
    land_widget_menubutton_interface_initialize();
    LandWidgetMenuButton * self;
    land_alloc(self);
    land_widget_reference(submenu);
    self->submenu = submenu;
    self->menu = parent;
    if (((parent->vt->id & LAND_WIDGET_ID_MENUBAR) == LAND_WIDGET_ID_MENUBAR)) {
        self->below = 1;
    }
    LandWidget * base = (void *) self;
    land_widget_button_initialize(base, parent, name, NULL, menubutton_clicked, x, y, w, h);
    LAND_WIDGET_MENU (submenu)->menubutton = base;
    base->vt = land_widget_menubutton_interface;
    land_widget_theme_initialize(base);
    return base;
}
void land_widget_menubutton_destroy(LandWidget * self) {
    LandWidgetMenuButton * menubutton = LAND_WIDGET_MENUBUTTON(self);
    if (menubutton->submenu) {
        LandWidgetMenu * menu = LAND_WIDGET_MENU(menubutton->submenu);
        menu->menubutton = NULL;
        land_widget_unreference(menubutton->submenu);
    }
    land_widget_button_destroy(self);
}
void land_widget_menu_add(LandWidget * base, LandWidget * item) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(base);
    land_widget_container_add(base, item);
    int n = container->children->count;
    land_widget_layout_freeze(base);
    land_widget_layout_set_grid(base, 1, n);
    land_widget_layout_set_grid_position(item, 0, n - 1);
    land_widget_layout_set_shrinking(item, 1, 1);
    land_widget_layout_unfreeze(base);
}
void land_widget_menubar_add(LandWidget * base, LandWidget * item) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(base);
    land_widget_container_add(base, item);
    int n = container->children->count;
    land_widget_layout_freeze(base);
    land_widget_layout_set_grid(base, n, 1);
    land_widget_layout_set_grid_position(item, n - 1, 0);
    land_widget_layout_set_shrinking(item, 1, 1);
    land_widget_layout_unfreeze(base);
}
LandWidget* land_widget_menuitem_new(LandWidget * parent, char const * name, void(* callback)(LandWidget * widget)) {
    /* Create a new menu item, i.e. en entry which can be clicked to execute the
     * given callback.
     */
    int tw = land_text_get_width(name);
    int th = land_font_height(land_font_current());
    LandWidgetMenuItem * menuitem;
    land_alloc(menuitem);
    land_widget_menubutton_interface_initialize();
    menuitem->menu = parent;
    menuitem->callback = callback;
    land_widget_button_initialize((LandWidget *) menuitem, parent, name, NULL, menuitem_clicked, 0, 0, 10, 10);
    LandWidget * self = LAND_WIDGET(menuitem);
    self->vt = land_widget_menuitem_interface;
    land_widget_theme_initialize(self);
    land_widget_layout_set_minimum_size(self, self->element->il + self->element->ir + tw, self->element->it + self->element->ib + th);
    land_widget_layout(parent);
    return self;
}
LandWidget* land_widget_submenuitem_new(LandWidget * parent, char const * name, LandWidget * submenu) {
    int tw = land_text_get_width(name);
    int th = land_font_height(land_font_current());
    LandWidget * button = land_widget_menubutton_new(parent, name, submenu, 0, 0, 0, 0);
    LAND_WIDGET_MENU (submenu)->menubutton = button;
    land_widget_theme_initialize(button);
    land_widget_layout_set_minimum_size(button, button->element->il + button->element->ir + tw, button->element->it + button->element->ib + th);
    land_widget_layout(parent);
    return button;
}
LandWidget* land_widget_menu_spacer_new(LandWidget * parent) {
    LandWidget * button = land_widget_box_new(parent, 0, 0, 0, 0);
    land_widget_theme_initialize(button);
    land_widget_layout(parent);
    return button;
}
LandWidget* land_widget_menu_find(LandWidget * super, int n, char const * names []) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(super);
    LandList * l = container->children;
    if (l) {
        LandListItem * listitem = l->first;
        while (listitem) {
            if (land_widget_is(listitem->data, LAND_WIDGET_ID_BUTTON)) {
                LandWidgetButton * button = listitem->data;
                if (! strcmp(button->text, names [0])) {
                    if (n <= 1) {
                        return (void *) button;
                    }
                    if (land_widget_is(listitem->data, LAND_WIDGET_ID_MENUBUTTON)) {
                        LandWidgetMenuButton * mb = listitem->data;
                        return land_widget_menu_find(mb->submenu, n - 1, names + 1);
                    }
                }
            }
            listitem = listitem->next;
        }
    }
    return NULL;
}
void land_widget_menu_mouse_enter(LandWidget * self) {
    ;
}
static int is_in_menu(LandWidget * self, LandWidget * other) {
    /* Check if the given menu has other as an ancestor.
     */
    while (self) {
        if (self == other) {
            return 1;
        }
        LandWidgetMenu * menu = LAND_WIDGET_MENU(self);
        LandWidget * buttonwidget = menu->menubutton;
        if (! buttonwidget) {
            break;
        }
        LandWidgetMenuButton * button = LAND_WIDGET_MENUBUTTON(buttonwidget);
        self = button->menu;
    }
    return 0;
}
static int is_related(LandWidget * self, LandWidget * other) {
    /* Check if other is a menu item or menu button related to this menu.
     */
    if (land_widget_is(other, LAND_WIDGET_ID_MENUITEM)) {
        LandWidgetMenuItem * othermenuitem = LAND_WIDGET_MENUITEM(other);
        LandWidget * othermenuwidget = othermenuitem->menu;
        while (othermenuwidget) {
            if (is_in_menu(self, othermenuwidget)) {
                return 1;
            }
            LandWidgetMenu * othermenu = LAND_WIDGET_MENU(othermenuwidget);
            LandWidget * otherbuttonwidget = othermenu->menubutton;
            if (! otherbuttonwidget) {
                break;
            }
            LandWidgetMenuButton * othermenubutton = LAND_WIDGET_MENUBUTTON(otherbuttonwidget);
            othermenuwidget = othermenubutton->menu;
        }
    }
    else if (land_widget_is(other, LAND_WIDGET_ID_MENUBUTTON)) {
        while (other) {
            LandWidgetMenuButton * otherbutton = LAND_WIDGET_MENUBUTTON(other);
            LandWidget * othermenuwidget = otherbutton->menu;
            if (! othermenuwidget) {
                break;
            }
            if (is_in_menu(self, othermenuwidget)) {
                return 1;
            }
            LandWidgetMenu * othermenu = LAND_WIDGET_MENU(othermenuwidget);
            other = othermenu->menubutton;
        }
    }
    return 0;
}
void land_widget_menu_mouse_leave(LandWidget * self) {
    if (self->hidden) {
        return ;
    }
    LandWidget * up = self;
    while (up->parent) {
        up = up->parent;
    }
    LandWidget * target = land_widget_container_get_descendant_at_pos(up, land_mouse_x(), land_mouse_y());
    if (is_related(self, target)) {
        return ;
    }
    land_widget_retain_mouse_focus(self);
}
void land_widget_menubutton_mouse_enter(LandWidget * self) {
    menubutton_clicked(self);
}
void land_widget_menubutton_mouse_leave(LandWidget * self) {
    ;
}
void land_widget_menubar_mouse_leave(LandWidget * self) {
    return ;
}
void land_widget_menu_mouse_tick(LandWidget * self) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(self);
    land_widget_container_mouse_tick(self);
    if ((! container->mouse && land_mouse_delta_b() && land_mouse_b())) {
        land_widget_menu_hide_complete(self);
        return ;
    }
}
void land_widget_menu_interface_initialize(void) {
    if (land_widget_menu_interface) {
        return ;
    }
    land_widget_container_interface_initialize();
    land_widget_menu_interface = land_widget_copy_interface(land_widget_container_interface, "menu");
    land_widget_menu_interface->id |= LAND_WIDGET_ID_MENU;
    land_widget_menu_interface->add = land_widget_menu_add;
    land_widget_menu_interface->mouse_enter = land_widget_menu_mouse_enter;
    land_widget_menu_interface->mouse_leave = land_widget_menu_mouse_leave;
    land_widget_menu_interface->mouse_tick = land_widget_menu_mouse_tick;
    land_widget_menubar_interface = land_widget_copy_interface(land_widget_menu_interface, "menubar");
    land_widget_menubar_interface->id |= LAND_WIDGET_ID_MENUBAR;
    land_widget_menubar_interface->add = land_widget_menubar_add;
    land_widget_menubar_interface->mouse_leave = land_widget_menubar_mouse_leave;
}
void land_widget_menubutton_interface_initialize(void) {
    if (land_widget_menubutton_interface) {
        return ;
    }
    land_widget_button_interface_initialize();
    land_widget_menubutton_interface = land_widget_copy_interface(land_widget_button_interface, "menubutton");
    land_widget_menubutton_interface->id |= LAND_WIDGET_ID_MENUBUTTON;
    land_widget_menubutton_interface->mouse_enter = land_widget_menubutton_mouse_enter;
    land_widget_menubutton_interface->mouse_leave = land_widget_menubutton_mouse_leave;
    land_widget_menubutton_interface->destroy = land_widget_menubutton_destroy;
    land_widget_menuitem_interface = land_widget_copy_interface(land_widget_button_interface, "menuitem");
    land_widget_menuitem_interface->id |= LAND_WIDGET_ID_MENUITEM;
}
static LandWidgetInterface * land_widget_list_interface;
static LandWidgetInterface * land_widget_listitem_interface;
void land_widget_list_disable_updates(LandWidget * base) {
    land_widget_vbox_disable_updates(base);
}
void land_widget_list_update(LandWidget * base) {
    land_widget_vbox_update(base);
}
void land_widget_list_set_columns(LandWidget * base, int n) {
    land_widget_vbox_set_columns(base, n);
}
void land_widget_list_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h) {
    land_widget_list_interface_initialize();
    land_widget_vbox_initialize(base, parent, x, y, w, h);
    base->vt = land_widget_list_interface;
    land_widget_theme_initialize(base);
    land_call_method(parent, update, (parent));
}
LandWidget* land_widget_list_new(LandWidget * parent, int x, int y, int w, int h) {
    LandWidgetList * self;
    land_alloc(self);
    LandWidget * widget = (LandWidget *) self;
    land_widget_list_initialize(widget, parent, x, y, w, h);
    return widget;
}
LandWidget* land_widget_listitem_new(LandWidget * parent, char const * text, void(* clicked)(LandWidget * self), int x, int y, int w, int h) {
    LandWidget * self = land_widget_button_new(parent, text, clicked, x, y, w, h);
    land_widget_listitem_interface_initialize();
    self->vt = land_widget_listitem_interface;
    land_widget_theme_initialize(self);
    land_widget_layout(parent);
    return self;
}
void land_widget_list_interface_initialize(void) {
    if (land_widget_list_interface) {
        return ;
    }
    land_widget_vbox_interface_initialize();
    land_widget_list_interface = land_widget_copy_interface(land_widget_vbox_interface, "list");
    land_widget_list_interface->id |= LAND_WIDGET_ID_LIST;
}
void land_widget_listitem_interface_initialize(void) {
    if (land_widget_listitem_interface) {
        return ;
    }
    land_widget_button_interface_initialize();
    land_widget_listitem_interface = land_widget_copy_interface(land_widget_button_interface, "listitem");
    land_widget_listitem_interface->id |= LAND_WIDGET_ID_LISTITEM;
}
LandArray* land_widget_list_get_selected_items(LandWidget * self) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(self);
    LandArray * array = land_array_new();
    LandListItem * item;
    for (item = container->children->first; item; item = item->next) {
        LandWidget * child = item->data;
        if (child->selected) {
            land_array_add_data(& array, child);
        }
    }
    return array;
}
void land_widget_list_clear_selection(LandWidget * self) {
    LandWidgetContainer * container = LAND_WIDGET_CONTAINER(self);
    LandListItem * item;
    for (item = container->children->first; item; item = item->next) {
        LandWidget * child = item->data;
        if (child->selected) {
            child->selected = 0;
        }
    }
}
LandWidgetInterface * land_widget_scrolling_text_interface;
void land_widget_scrolling_text_initialize(LandWidget * base, LandWidget * parent, char const * text, int wordwrap, int x, int y, int w, int h) {
    land_widget_scrolling_initialize(base, parent, x, y, w, h);
    land_widget_scrolling_text_interface_initialize();
    base->vt = land_widget_scrolling_text_interface;
    land_widget_theme_initialize(base);
    LandWidget * container = land_widget_scrolling_get_container(base);
    float cx, cy, cw, ch;
    land_widget_inner(container, & cx, & cy, & cw, & ch);
    land_widget_text_new(base, text, wordwrap, cx, cy, cw, ch);
}
LandWidget* land_widget_scrolling_text_new(LandWidget * parent, char const * text, int wordwrap, int x, int y, int w, int h) {
    LandWidgetScrollingText * self;
    land_alloc(self);
    LandWidget * widget = (LandWidget *) self;
    land_widget_scrolling_text_initialize(widget, parent, text, wordwrap, x, y, w, h);
    return widget;
}
void land_widget_scrolling_text_size(LandWidget * widget, float dx, float dy) {
    if (! (dx || dy)) {
        return ;
    }
    LandWidget * container = land_widget_scrolling_get_container(widget);
    float cx, cy, cw, ch;
    land_widget_layout(widget);
    land_widget_inner(container, & cx, & cy, & cw, & ch);
    LandWidget * button = land_widget_container_child(container);
    land_widget_size(button, cw - button->box.w, ch - button->box.h);
    land_widget_scrolling_size(widget, dx, dy);
}
void land_widget_scrolling_text_interface_initialize(void) {
    if (land_widget_scrolling_text_interface) {
        return ;
    }
    land_widget_scrolling_interface_initialize();
    land_widget_scrolling_text_interface = land_widget_copy_interface(land_widget_scrolling_interface, "scrolling");
    land_widget_scrolling_text_interface->id |= LAND_WIDGET_ID_SCROLLING_TEXT;
    land_widget_scrolling_text_interface->size = land_widget_scrolling_text_size;
}
static LandWidgetInterface * land_widget_spin_interface;
static LandWidgetInterface * land_widget_spinbutton_interface;
static LandImage * image_up;
static LandImage * image_down;
LandWidget* land_widget_spin_get_edit(LandWidget * spin) {
    LandListItem * item = LAND_WIDGET_CONTAINER (spin)->children->first;
    LandWidget * edit = item->data;
    return edit;
}
static void updated(LandWidget * base) {
    LandListItem * item = LAND_WIDGET_CONTAINER (base)->children->first;
    LandWidgetEdit * edit = LAND_WIDGET_EDIT(item->data);
    if (edit->modified) {
        edit->modified(LAND_WIDGET(edit));
    }
}
LandWidget* land_widget_spinbutton_new(LandWidget * parent, LandImage * image, void(* clicked)(LandWidget * self), int x, int y, int w, int h) {
    LandWidgetSpinButton * spinbutton;
    land_alloc(spinbutton);
    LandWidget * self = (LandWidget *) spinbutton;
    land_widget_button_initialize(self, parent, NULL, image, clicked, x, y, w, h);
    land_widget_spinbutton_interface_initialize();
    self->vt = land_widget_spinbutton_interface;
    land_widget_theme_initialize(self);
    land_widget_theme_set_minimum_size_for_image(self, image);
    return self;
}
void land_widget_spin_initialize(LandWidget * base, LandWidget * parent, float val, float _scramble_min, float _scramble_max, float step, void(* modified)(LandWidget * self), int x, int y, int w, int h) {
    land_widget_spin_interface_initialize();
    land_widget_hbox_initialize(base, parent, x, y, w, h);
    base->vt = land_widget_spin_interface;
    LandWidgetSpin * spin = LAND_WIDGET_SPIN(base);
    spin->_scramble_min = _scramble_min;
    spin->_scramble_max = _scramble_max;
    spin->step = step;
    LandWidget * edit = land_widget_edit_new(base, "", modified, 0, 0, 1, 1);
    land_widget_edit_align_right(edit, true);
    LandWidget * spinner = land_widget_vbox_new(base, 0, 0, 1, 1);
    LandWidgetSpinButton * buttonup = LAND_WIDGET_SPINBUTTON(land_widget_spinbutton_new(spinner, image_up, NULL, 0, 0, 1, 1));
    buttonup->initial_delay = 0.25;
    buttonup->rate = 0.1;
    buttonup->spin = base;
    buttonup->dir = 1;
    LandWidgetSpinButton * buttondown = LAND_WIDGET_SPINBUTTON(land_widget_spinbutton_new(spinner, image_down, NULL, 0, 0, 1, 1));
    buttondown->initial_delay = 0.25;
    buttondown->rate = 0.1;
    buttondown->spin = base;
    buttondown->dir = - 1;
    land_widget_layout_set_shrinking(LAND_WIDGET(buttonup), 1, 0);
    land_widget_layout_set_shrinking(LAND_WIDGET(buttondown), 1, 0);
    land_widget_layout_set_shrinking(spinner, 1, 0);
    land_widget_layout_set_expanding(edit, 1, 0);
    land_widget_spin_set_value(base, val);
    land_widget_layout_set_expanding(base, 1, 0);
    land_widget_theme_initialize(base);
    if (parent) {
        land_widget_layout(parent);
    }
}
LandWidget* land_widget_spin_new(LandWidget * parent, float val, float _scramble_min, float _scramble_max, float step, void(* modified)(LandWidget * self), int x, int y, int w, int h) {
    LandWidgetSpin * spin;
    land_alloc(spin);
    LandWidget * self = (LandWidget *) spin;
    land_widget_spin_initialize(self, parent, val, _scramble_min, _scramble_max, step, modified, x, y, w, h);
    return self;
}
void land_widget_spin_set_value(LandWidget * base, float val) {
    LandWidgetSpin * spin = LAND_WIDGET_SPIN(base);
    if (spin->wrap) {
        if (val < spin->_scramble_min) {
            val += spin->_scramble_max - spin->_scramble_min;
        }
        if (val > spin->_scramble_max) {
            val -= spin->_scramble_max - spin->_scramble_min;
        }
    }
    else {
        if (val < spin->_scramble_min && spin->_scramble_min < spin->_scramble_max) {
            val = spin->_scramble_min;
        }
        if (val > spin->_scramble_max && spin->_scramble_max > spin->_scramble_min) {
            val = spin->_scramble_max;
        }
    }
    LandListItem * item = LAND_WIDGET_CONTAINER (base)->children->first;
    LandWidget * edit = LAND_WIDGET(item->data);
    char text [256];
    char format [256];
    if (spin->step > 0 && spin->step < 1) {
        snprintf(format, sizeof format, "%%.%df", (int)(0.9 - log10(spin->step)));
    }
    else {
        strcpy(format, "%.0f");
    }
    snprintf(text, sizeof text, format, val);
    land_widget_edit_set_text(edit, text);
}
void land_widget_spin_set_minimum_text(LandWidget * base, char const * text) {
    LandListItem * item = LAND_WIDGET_CONTAINER (base)->children->first;
    LandWidget * edit = LAND_WIDGET(item->data);
    land_widget_theme_set_minimum_size_for_text(edit, text);
}
float land_widget_spin_get_value(LandWidget * base) {
    LandWidgetSpin * spin = LAND_WIDGET_SPIN(base);
    LandListItem * item = LAND_WIDGET_CONTAINER (base)->children->first;
    LandWidget * edit = LAND_WIDGET(item->data);
    char const * text = land_widget_edit_get_text(edit);
    float val = strtod(text, NULL);
    if (val < spin->_scramble_min && spin->_scramble_min < spin->_scramble_max) {
        val = spin->_scramble_min;
    }
    if (val > spin->_scramble_max && spin->_scramble_max > spin->_scramble_min) {
        val = spin->_scramble_max;
    }
    return val;
}
static void spinning(LandWidget * widget, float amount) {
    LandWidget * super = widget->parent->parent;
    float val = land_widget_spin_get_value(super);
    LandWidgetSpin * spin = LAND_WIDGET_SPIN(super);
    val += amount;
    land_widget_spin_set_value(LAND_WIDGET(spin), val);
    updated(super);
}
void land_widget_spinbutton_mouse_tick(LandWidget * base) {
    LandWidgetSpinButton * spinbutton = LAND_WIDGET_SPINBUTTON(base);
    LandWidgetSpin * spin = LAND_WIDGET_SPIN(spinbutton->spin);
    if ((land_mouse_delta_b() & 1)) {
        if ((land_mouse_b() & 1)) {
            spinbutton->seconds = land_get_time();
            spinbutton->delay = spinbutton->initial_delay;
            spinbutton->count = 0;
            spinbutton->step = spin->step * spinbutton->dir;
            spinning(base, spinbutton->step);
        }
    }
    else {
        if ((land_mouse_b() & 1)) {
            double seconds = land_get_time();
            if (seconds > spinbutton->seconds + spinbutton->delay) {
                spinbutton->seconds = seconds;
                spinbutton->delay = spinbutton->rate;
                spinbutton->count++;
                if (spinbutton->count >= 20) {
                    spinbutton->step *= 10;
                    spinbutton->count = 0;
                }
                spinning(base, spinbutton->step);
            }
        }
    }
}
void land_widget_spinbutton_interface_initialize(void) {
    if (land_widget_spinbutton_interface) {
        return ;
    }
    land_widget_button_interface_initialize();
    land_widget_spinbutton_interface = land_widget_copy_interface(land_widget_button_interface, "spinbutton");
    land_widget_spinbutton_interface->id |= LAND_WIDGET_ID_SPINBUTTON;
    land_widget_spinbutton_interface->mouse_tick = land_widget_spinbutton_mouse_tick;
}
void land_widget_spin_interface_initialize(void) {
    if (land_widget_spin_interface) {
        return ;
    }
    land_widget_hbox_interface_initialize();
    land_widget_spin_interface = land_widget_copy_interface(land_widget_hbox_interface, "spin");
    land_widget_spin_interface->id |= LAND_WIDGET_ID_SPIN;
    image_up = land_image_create(2, 2);
    image_down = land_image_create(2, 2);
}

#ifndef _LAND_
#define _LAND_
typedef struct LandLayer LandLayer;
typedef struct LandSound LandSound;
typedef struct LandStream LandStream;
typedef struct LandFile LandFile;
typedef struct LandDataEntry LandDataEntry;
typedef struct LandDataFile LandDataFile;
typedef struct LandRandom LandRandom;
typedef struct LandHashEntry LandHashEntry;
typedef struct LandHash LandHash;
typedef struct LandHashIterator LandHashIterator;
typedef struct LandBuffer LandBuffer;
typedef struct LandBufferAsFile LandBufferAsFile;
typedef struct LandGLSLShader LandGLSLShader;
typedef struct LandPixelMask LandPixelMask;
typedef struct SinglePixelMask SinglePixelMask;
typedef struct LandIniEntry LandIniEntry;
typedef struct LandIniSection LandIniSection;
typedef struct LandIniFile LandIniFile;
typedef enum LandNetState LandNetState;
typedef struct LandNet LandNet;
typedef struct LandDisplay LandDisplay;
typedef struct LandProtobuf LandProtobuf;
typedef struct LandMap LandMap;
typedef struct LandLayoutBox LandLayoutBox;
typedef struct LandFont LandFont;
typedef struct LandFontState LandFontState;
typedef struct LandParameters LandParameters;
typedef struct LandView LandView;
typedef struct LandGridInterface LandGridInterface;
typedef struct LandGrid LandGrid;
typedef struct LandMemoryPool LandMemoryPool;
typedef struct LandWidgetThemeElement LandWidgetThemeElement;
typedef struct LandWidgetTheme LandWidgetTheme;
typedef struct LandArray LandArray;
typedef struct LandArrayIterator LandArrayIterator;
typedef enum LandKeyboardKeys LandKeyboardKeys;
typedef struct LandRunner LandRunner;
typedef struct LandMemBlockInfo LandMemBlockInfo;
typedef struct LandColor LandColor;
typedef struct LandCSGAABB LandCSGAABB;
typedef struct LandListItem LandListItem;
typedef struct LandList LandList;
typedef struct LandListIterator LandListIterator;
typedef struct LandThread LandThread;
typedef struct LandLock LandLock;
typedef struct LandImage LandImage;
typedef struct LandSubImage LandSubImage;
typedef struct LandTileGrid LandTileGrid;
typedef struct LandAnimation LandAnimation;
typedef struct LandVector LandVector;
typedef struct Land4x4Matrix Land4x4Matrix;
typedef struct LandQuaternion LandQuaternion;
typedef struct LandQueue LandQueue;
typedef struct LandDisplayPlatform LandDisplayPlatform;
typedef struct LandImagePlatform LandImagePlatform;
typedef struct LandGridIsometric LandGridIsometric;
typedef struct LandSpriteType LandSpriteType;
typedef struct LandSpriteTypeWithImage LandSpriteTypeWithImage;
typedef struct LandSpriteTypeImage LandSpriteTypeImage;
typedef struct LandSpriteTypeAnimation LandSpriteTypeAnimation;
typedef struct LandSprite LandSprite;
typedef struct LandSpriteWithImage LandSpriteWithImage;
typedef struct LandSpriteAnimated LandSpriteAnimated;
typedef struct LandSpritesGrid LandSpritesGrid;
typedef struct LandWidgetInterface LandWidgetInterface;
typedef struct LandWidget LandWidget;
typedef struct LandWidgetProperty LandWidgetProperty;
typedef struct LandWidgetEdit LandWidgetEdit;
typedef struct LandWidgetSizer LandWidgetSizer;
typedef struct LandWidgetContainer LandWidgetContainer;
typedef struct LandCSG LandCSG;
typedef struct LandCSGVertex LandCSGVertex;
typedef struct LandCSGPlane LandCSGPlane;
typedef struct LandCSGPolygon LandCSGPolygon;
typedef struct LandCSGNode LandCSGNode;
typedef struct LandWidgetSlider LandWidgetSlider;
typedef struct LandWidgetHandle LandWidgetHandle;
typedef struct LandWidgetPanel LandWidgetPanel;
typedef struct LandWidgetBook LandWidgetBook;
typedef struct LandWidgetVBox LandWidgetVBox;
typedef struct LandWidgetBoard LandWidgetBoard;
typedef struct LandWidgetScrollbar LandWidgetScrollbar;
typedef struct LandWidgetHBox LandWidgetHBox;
typedef struct LandWidgetScrolling LandWidgetScrolling;
typedef struct LandWidgetButton LandWidgetButton;
typedef struct LandWidgetScrollingText LandWidgetScrollingText;
typedef struct LandWidgetMenu LandWidgetMenu;
typedef struct LandWidgetMenuButton LandWidgetMenuButton;
typedef struct LandWidgetMenuItem LandWidgetMenuItem;
typedef struct LandWidgetCheckBox LandWidgetCheckBox;
typedef struct LandWidgetList LandWidgetList;
typedef struct LandWidgetSpin LandWidgetSpin;
typedef struct LandWidgetSpinButton LandWidgetSpinButton;
typedef struct LandWidgetMover LandWidgetMover;
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
typedef float float32_t;
typedef double LandFloat;
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>
void land_bind_vbo(GLuint * vbo, void * data, int n, int draw);
char const* land_opengl_error(void);
void land_4x4_matrix_to_gl_float(Land4x4Matrix m, GLfloat * gl);
#include <stdbool.h>
#include <math.h>
struct LandLayer {
    float x, y;
    float scrolling_x, scrolling_y;
    float scale_x, scale_y;
    float view_x, view_y, view_w, view_h;
    float r, g, b, a;
    char * name;
    LandGrid * grid;
    LandSprite * first_active;
    LandLayer * next_in_map;
    bool hidden;
};
void land_layer_draw(LandLayer * self, LandView * view);
void land_layer_draw_grid(LandLayer * self, LandView * view);
void land_layer_set_name(LandLayer * self, char const * name);
void land_layer_del(LandLayer * self);
LandLayer* land_layer_new_with_grid(LandGrid * grid);
LandLayer* land_layer_new(void);
void land_layer_set_scroll_speed(LandLayer * self, float x, float y);
void land_layer_set_scale(LandLayer * self, float x, float y);
void land_layer_set_position(LandLayer * self, float x, float y);
void land_layer_set_grid(LandLayer * self, LandGrid * grid);
void land_layer_hide(LandLayer * self);
void land_layer_unhide(LandLayer * self);
float land_norm2d(float x, float y);
float land_dot2d(float ax, float ay, float bx, float by);
float land_cross2d(float ax, float ay, float bx, float by);
void land_ortho2d(float ax, float ay, float * bx, float * by);
bool land_line_line_collision2d(float l1x1, float l1y1, float l1x2, float l1y2, float l2x1, float l2y1, float l2x2, float l2y2);
LandColor platform_color_hsv(float hue, float sat, float val);
LandColor platform_color_name(char const * name);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#define y1 libc_y1
#define yn libc_yn
#include <math.h>
#undef y1
#undef yn
#define land_use_main(m) \
    int main(int argc, char * (* argv)) { \
        land_argc = argc; \
        land_argv = argv; \
        m(); \
        land_log_message("Return code is %d.\n", land_get_exitcode()); \
        return land_get_exitcode(); \
    }
#define land_begin_shortcut(w, h, hz, flags, init, enter, tick, draw, leave, destroy) \
    int main(int argc, char * (* argv)) { \
        land_argc = argc; \
        land_argv = argv; \
        land_init(); \
        shortcut_runner = land_runner_new("shortcut", (void *) init, (void *) enter, (void *) tick, (void *) draw, (void *) leave, (void *) destroy); \
        land_runner_register(shortcut_runner); \
        land_set_display_parameters(w, h, flags); \
        land_set_initial_runner(shortcut_runner); \
        land_set_fps(hz); \
        land_mainloop(); \
        land_log_message("Return code is %d.\n", land_get_exitcode()); \
        return land_get_exitcode(); \
    }
void land_without_main(void(* cb)(void));
void land_set_exitcode(int code);
int land_get_exitcode(void);
void land_exit_function(void(* function)(void));
void land_exit_functions(void);
void land_wait(double seconds);
extern int land_argc;
extern char * (* land_argv);
extern LandRunner * shortcut_runner;
#include <stdbool.h>
struct LandSound {
    char * filename;
    char * name;
};
struct LandStream {
    int samples;
    int sample_size;
    int fragments;
    float frequency;
    char const * filename;
};
LandSound* land_sound_load(char const * filename);
LandSound* land_sound_new(int samples, float frequency, int bits, int channels);
void* land_sound_sample_pointer(LandSound * self);
int land_sound_length(LandSound * self);
double land_sound_seconds(LandSound * self);
void land_sound_play(LandSound * s, float volume, float pan, float frequency);
void land_sound_loop(LandSound * s, float volume, float pan, float frequency);
void land_sound_stop(LandSound * s);
void land_sound_destroy(LandSound * s);
void land_sound_init(void);
void land_sound_exit(void);
LandStream* land_stream_new(int samples, int fragments, float frequency, int bits, int channels);
void land_stream_destroy(LandStream * self);
void* land_stream_buffer(LandStream * self);
void land_stream_fill(LandStream * self);
void land_stream_music(LandStream * self, char const * filename);
void land_stream_volume(LandStream * self, float volume);
bool land_stream_is_playing(LandStream * self);
void land_stream_set_playing(LandStream * self, bool onoff);
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
enum {
    LAND_FULL_PATH=1,
    LAND_RELATIVE_PATH=2
};
struct LandFile {
    char * path;
    void * f;
};
LandFile* land_file_new(char const * path, char const * mode);
void land_file_destroy(LandFile * self);
int land_file_read(LandFile * self, char * buffer, int bytes);
int land_file_write(LandFile * self, char const * buffer, int bytes);
void land_file_print(LandFile * self, char const * f, ...);
void land_file_printnn(LandFile * self, char const * f, ...);
int land_file_fputs(LandFile * self, char const * string);
int land_file_getc(LandFile * self);
void land_file_ungetc(LandFile * self, int c);
bool land_file_eof(LandFile * self);
void land_file_skip(LandFile * self, int n);
uint32_t land_file_get32le(LandFile * self);
uint16_t land_file_get16le(LandFile * self);
uint32_t land_file_get32be(LandFile * self);
uint16_t land_file_get16be(LandFile * self);
bool land_file_is_dir(char const * name);
bool land_file_exists(char const * name);
char* land_get_save_file(char const * appname, char const * name);
char* land_get_current_directory(void);
char* land_get_data_path(void);
char* land_path_with_prefix(char const * name);
void land_set_prefix(char const * path);
void land_find_data_prefix(char const * path);
char* land_replace_filename(char const * path, char const * name);
bool land_file_remove(char const * path);
#include <stdio.h>
struct LandDataEntry {
    char * name;
    int offset;
    int size;
};
struct LandDataFile {
    LandArray * entries;
    FILE * file;
};
extern LandDataFile * _land_datafile;
LandDataFile* land_read_datafile(FILE * file);
LandDataFile* land_open_datafile(char const * filename);
LandDataFile* land_open_appended_datafile(char const * filename, char const * marker);
void* land_datafile_read_entry(LandDataFile * self, char const * filename, int * size);
int land_datafile_for_each_entry(LandDataFile * self, char const * pattern, int(* callback)(const char * filename, int attrib, void * param), void * param);
void land_set_datafile(LandDataFile * datafile);
LandDataFile* land_get_datafile(void);
#include <stdint.h>
enum {
    LAND_RANDOM_N=624
};
struct LandRandom {
    uint32_t mt [LAND_RANDOM_N];
    uint32_t mti;
};
void land_seed(int seed);
double land_rnd(double rmin, double rmax);
int land_rand(int rmin, int rmax);
LandRandom* land_random_new(int seed);
void land_random_del(LandRandom * self);
int land_random(LandRandom * r, int rmin, int rmax);
#define land_method(_returntype, _name, _params) _returntype(* _name) _params
#define land_call_method(self, method, params) if(self->vt->method) self->vt->method params
#include <stdbool.h>
#define LAND_PI 3.1415926535897931
char* land_read_text(char const * filename);
int land_utf8_char(char * (* pos));
int land_utf8_char_back(char * (* pos));
int land_utf8_char_const(char const * (* pos));
int land_utf8_encode(int c, char * s);
char* land_utf8_realloc_insert(char * s, int pos, int c);
char* land_utf8_realloc_remove(char * s, int pos);
int land_utf8_count(char const * s);
void land_utf8_copy(char * target, int size, char const * source);
bool land_fnmatch(char const * pattern, char const * name);
char* land_string_copy(char * target, char const * source, int size);
bool land_equals(char const * s, char const * s2);
bool land_ends_with(char const * s, char const * end);
bool land_starts_with(char const * s, char const * start);
void land_concatenate(char * (* s), char const * cat);
void land_concatenate_with_separator(char * (* s), char const * cat, char const * sep);
void land_prepend(char * (* s), char const * pre);
int land_replace(char * (* s), int off, char const * wat, char const * wit);
int land_replace_all(char * (* s), char const * wat, char const * wit);
char* land_substring(char const * s, int a, int b);
LandArray* land_filelist(char const * dir, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data);
LandArray* land_split_path_name_ext(char const * filename);
LandArray* land_split(char const * text, char c);
LandArray* land_split_lines(char const * text);
#include <stdbool.h>
void land_mouse_init(void);
void land_mouse_tick(void);
void land_mouse_move_event(int x, int y, int z);
void land_touch_event(float x, float y, int n, int d);
float land_touch_x(int n);
float land_touch_y(int n);
bool land_touch_down(int n);
bool land_touch_delta(int n);
void land_mouse_button_down_event(int b);
void land_mouse_button_up_event(int b);
int land_mouse_x(void);
int land_mouse_y(void);
int land_mouse_z(void);
int land_mouse_b(void);
int land_mouse_button(int i);
int land_mouse_delta_x(void);
int land_mouse_delta_y(void);
int land_mouse_delta_z(void);
int land_mouse_delta_b(void);
int land_mouse_delta_button(int i);
int land_mouse_button_clicked(int i);
void land_mouse_set_pos(int x, int y);
bool land_hide_mouse_cursor(void);
bool land_show_mouse_cursor(void);
int land_widget_layout_freeze(LandWidget * self);
int land_widget_layout_unfreeze(LandWidget * self);
void land_widget_layout_set_grid(LandWidget * self, int columns, int rows);
void land_widget_layout_disable(LandWidget * self);
void land_widget_layout_enable(LandWidget * self);
void land_widget_layout_set_grid_position(LandWidget * self, int column, int row);
void land_widget_layout_set_grid_extra(LandWidget * self, int columns, int rows);
void land_widget_layout_set_minimum_size(LandWidget * self, int w, int h);
void land_widget_layout_set_maximum_size(LandWidget * self, int w, int h);
void land_widget_layout_set_shrinking(LandWidget * self, int x, int y);
void land_widget_layout_set_expanding(LandWidget * self, int x, int y);
void land_widget_layout(LandWidget * self);
void land_widget_layout_initialize(LandWidget * self, int x, int y, int w, int h);
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
LandSound* platform_sound_load(char const * filename);
LandSound* platform_sound_new(int samples, float frequency, int bits, int channels);
void* platform_sound_sample_pointer(LandSound * super);
int platform_sound_length(LandSound * super);
double platform_sound_seconds(LandSound * super);
void platform_sound_play(LandSound * s, float volume, float pan, float frequency, bool loop);
void platform_sound_stop(LandSound * s);
void platform_sound_destroy(LandSound * s);
void platform_sound_init(void);
void platform_sound_exit(void);
void platform_sound_resume(void);
void platform_sound_halt(void);
LandStream* platform_stream_new(int samples, int fragments, float frequency, int bits, int channels);
void platform_stream_destroy(LandStream * super);
void* platform_stream_buffer(LandStream * super);
void platform_stream_fill(LandStream * super);
void platform_stream_music(LandStream * super, char const * filename);
void platform_stream_volume(LandStream * super, float volume);
bool platform_stream_is_playing(LandStream * super);
void platform_stream_set_playing(LandStream * super, bool onoff);
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
struct LandHashEntry {
    char * thekey;
    void * data;
    int n;
};
struct LandHash {
    int count;
    int size;
    int bits;
    unsigned int(* hash_function)(LandHash * self, char const * thekey);
    LandHashEntry * (* entries);
};
struct LandHashIterator {
    int i, j;
};
LandHashIterator LandHashIterator_first(LandHash * self);
void* LandHashIterator_item(LandHash * self, LandHashIterator * i);
bool LandHashIterator_next(LandHash * self, LandHashIterator * i);
LandHash* land_hash_new_memlog(char const * f, int l);
void land_hash_destroy_memlog(LandHash * self, char const * f, int l);
LandHash* land_hash_new(void);
void land_hash_clear(LandHash * self);
void land_hash_destroy(LandHash * self);
void* land_hash_insert(LandHash * self, char const * thekey, void * data);
void* land_hash_remove(LandHash * self, char const * thekey);
void* land_hash_replace(LandHash * self, char const * thekey, void * data);
void* land_hash_get(LandHash * self, char const * thekey);
int land_hash_has(LandHash * self, char const * thekey);
LandArray* land_hash_keys(LandHash * hash, bool alloc);
LandArray* land_hash_data(LandHash * hash);
void land_hash_print_stats(LandHash * hash);
#ifdef LAND_MEMLOG
#define land_hash_new() land_hash_new_memlog(__FILE__, __LINE__)
#define land_hash_destroy(x) land_hash_destroy_memlog(x, __FILE__, __LINE__)
#endif
struct LandBuffer {
    int size;
    int n;
    char * buffer;
};
struct LandBufferAsFile {
    LandBuffer * landbuffer;
    int pos;
    int ungetc;
};
LandBuffer* land_buffer_new_memlog(char const * f, int l);
void land_buffer_destroy_memlog(LandBuffer * self, char const * f, int l);
char* land_buffer_finish_memlog(LandBuffer * self, char const * f, int l);
LandBuffer* land_buffer_read_from_file_memlog(char const * filename, char const * f, int l);
LandArray* land_buffer_split_memlog(LandBuffer const * self, char delim, char const * f, int line);
LandBuffer* land_buffer_new(void);
LandBuffer* land_buffer_copy(LandBuffer * other);
LandBuffer* land_buffer_extract(LandBuffer * other, int x, int n);
LandBuffer* land_buffer_copy_from(LandBuffer * other, int x);
#define land_buffer_del land_buffer_destroy
void land_buffer_destroy(LandBuffer * self);
void land_buffer_insert(LandBuffer * self, int pos, char const * buffer, int n);
void land_buffer_cut(LandBuffer * self, int pos, int n);
void land_buffer_shorten_left(LandBuffer * self, int n);
void land_buffer_add(LandBuffer * self, char const * b, int n);
void land_buffer_addv(LandBuffer * self, char const * format, va_list args);
void land_buffer_addf(LandBuffer * self, char const * format, ...);
void land_buffer_addl(LandBuffer * self, char const * format, ...);
void land_buffer_add_uint32_t(LandBuffer * self, uint32_t i);
uint32_t land_buffer_get_uint32_t(LandBuffer * self, int pos);
uint16_t land_buffer_get_uint16_t(LandBuffer * self, int pos);
uint8_t land_buffer_get_byte(LandBuffer * self, int pos);
void land_buffer_add_float(LandBuffer * self, float f);
void land_buffer_add_char(LandBuffer * self, char c);
void land_buffer_cat(LandBuffer * self, char const * string);
void land_buffer_clear(LandBuffer * self);
void land_buffer_crop(LandBuffer * self);
char* land_buffer_finish(LandBuffer * self);
void land_buffer_println(LandBuffer * self);
LandArray* land_buffer_split(LandBuffer const * self, char delim);
void land_buffer_strip_right(LandBuffer * self, char const * what);
void land_buffer_strip_left(LandBuffer * self, char const * what);
void land_buffer_strip(LandBuffer * self, char const * what);
bool land_buffer_is(LandBuffer * self, char const * what);
void land_buffer_remove_if_start(LandBuffer * self, char const * what);
void land_buffer_remove_if_end(LandBuffer * self, char const * what);
int land_buffer_rfind(LandBuffer * self, char c);
int land_buffer_find(LandBuffer const * self, int offset, char const * what);
int land_buffer_replace(LandBuffer * self, int offset, char const * wat, char const * wit);
int land_buffer_replace_all(LandBuffer * self, char const * wat, char const * wit);
void land_buffer_set_length(LandBuffer * self, int n);
void land_buffer_shorten(LandBuffer * self, int n);
LandBuffer* land_buffer_read_from_file(char const * filename);
bool land_buffer_write_to_file(LandBuffer * self, char const * filename);
void land_buffer_compress(LandBuffer * self);
void land_buffer_decompress(LandBuffer * self);
int land_buffer_compare(LandBuffer * self, LandBuffer * other);
#ifdef LAND_MEMLOG
#define land_buffer_new() land_buffer_new_memlog(__FILE__, __LINE__)
#define land_buffer_destroy(x) land_buffer_destroy_memlog(x, __FILE__, __LINE__)
#define land_buffer_finish(x) land_buffer_finish_memlog(x, __FILE__, __LINE__)
#define land_buffer_read_from_file(x) land_buffer_read_from_file_memlog(x, __FILE__, __LINE__)
#define land_buffer_split(x, y) land_buffer_split_memlog(x, y, __FILE__, __LINE__)
#endif
struct LandGLSLShader {
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program_object;
};
LandGLSLShader* land_glsl_shader_new(char const * name, char const * vertex_glsl, char const * fragment_glsl);
LandGLSLShader* land_glsl_shader_new_empty(char const * name);
void land_glsl_shader_set_shaders(LandGLSLShader * self, char const * vertex_glsl, char const * fragment_glsl);
void land_glsl_shader_destroy(LandGLSLShader * self);
void platform_without_main(void(* cb)(void));
double platform_get_time(void);
void platform_halt(void);
void platform_resume(void);
void platform_init(void);
char const* platform_key_name(int lk);
void platform_hide_mouse_cursor(void);
void platform_show_mouse_cursor(void);
void platform_mouse_set_pos(float x, float y);
void platform_pause(void);
void platform_unpause(void);
void platform_mainloop(LandParameters * parameters);
void platform_frame(void);
char* platform_get_app_settings_file(char const * appname);
void platform_wait(double seconds);
#include <stdio.h>
#include <stdint.h>
struct LandPixelMask {
    int w, h, x, y;
    int n;
    bool flipped;
    SinglePixelMask * rotation [0];
};
struct SinglePixelMask {
    int w, h;
    uint32_t data [0];
};
void land_image_debug_pixelmask(LandImage * self, float x, float y, float angle, bool flipped);
void land_image_create_pixelmasks(LandImage * self, int n, int threshold);
void land_image_destroy_pixelmasks(LandImage * self);
int land_image_overlaps(LandImage * self, float x, float y, float angle, float flipped, LandImage * other, float x_, float y_, float angle_, float flipped_);
struct LandIniEntry {
    char * key;
    void * val;
};
struct LandIniSection {
    LandArray * entries;
    LandHash * lookup;
};
struct LandIniFile {
    char * filename;
    LandIniSection * sections;
};
void land_ini_set_string(LandIniFile * ini, char const * section, char const * key, char const * val);
void land_ini_set_int(LandIniFile * ini, char const * section, char const * key, int val);
char const* land_ini_get_string(LandIniFile * ini, char const * section, char const * key, char const * de);
int land_ini_get_int(LandIniFile * ini, char const * section, char const * key, int de);
int land_ini_get_number_of_entries(LandIniFile * ini, char const * section);
char const* land_ini_get_nth_entry(LandIniFile * ini, char const * section, int i);
LandIniFile* land_ini_read(char const * filename);
LandIniFile* land_ini_new(char const * filename);
void land_ini_destroy(LandIniFile * ini);
void land_ini_writeback(LandIniFile * ini);
LandIniFile* land_ini_app_settings(char const * appname);
extern LandWidgetInterface * land_widget_box_interface;
void land_widget_box_draw(LandWidget * self);
LandWidget* land_widget_box_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_box_interface_initialize(void);
#include <unistd.h>
#include <stdbool.h>
enum LandNetState {
    LAND_NET_INVALID,
    LAND_NET_LISTENING,
    LAND_NET_CONNECTING,
    LAND_NET_OK
};
struct LandNet {
    int sock;
    int sockd;
    LandNetState state;
    char * local_address;
    char * remote_address;
    LandNet * accepted;
    char * buffer;
    size_t size;
    size_t full;
    double timestamp;
    int rate_control;
    int max_rate;
    void * lag_simulator;
};
char* land_net_get_address(LandNet * self, int remote);
LandNet* land_net_new(void);
void land_net_listen(LandNet * self, char const * address);
LandNet* land_net_accept(LandNet * self);
void land_net_connect(LandNet * self, char const * address);
void land_net_lag_simulator(LandNet * self, double delay, double jitter);
void land_net_limit_receive_rate(LandNet * self, int rate);
int land_net_send_datagram(LandNet * self, char const * address, char const * packet, int size);
int land_net_recv_datagram(LandNet * self, int port, char * (* address), char * packet, int size);
void land_net_send(LandNet * self, char const * buffer, size_t size);
void land_net_buffer(LandNet * self, char * buffer, size_t size);
void land_net_flush(LandNet * self, size_t size);
void land_net_disconnect(LandNet * self);
void land_net_del(LandNet * self);
void land_net_poll(LandNet * self);
#include <stdlib.h>
enum {
    LAND_WINDOWED=1,
    LAND_FULLSCREEN=2,
    LAND_OPENGL=4,
    LAND_CLOSE_LINES=8,
    LAND_ANTIALIAS=16,
    LAND_STENCIL=32,
    LAND_RESIZE=64,
    LAND_MULTISAMPLE=128,
    LAND_DEPTH=256,
    LAND_LANDSCAPE=512
};
enum {
    LAND_BLEND_SOLID=1,
    LAND_BLEND_ADD=2,
    LAND_BLEND_TINT=4
};
enum {
    LAND_MAX_CLIP_DEPTH=64
};
enum {
    LAND_NEVER,
    LAND_ALWAYS,
    LAND_LESS,
    LAND_EQUAL,
    LAND_LESS_EQUAL,
    LAND_GREATER,
    LAND_NOT_EQUAL,
    LAND_GREATER_EQUAL
};
enum {
    LAND_ALPHA_TEST,
    LAND_ALPHA_FUNCTION,
    LAND_ALPHA_VALUE,
    LAND_WRITE_MASK,
    LAND_DEPTH_TEST,
    LAND_DEPTH_FUNCTION
};
enum {
    LAND_RED_MASK=1,
    LAND_GREEN_MASK=2,
    LAND_BLUE_MASK=4,
    LAND_ALPHA_MASK=8,
    LAND_DEPTH_MASK=16,
    LAND_RGB_MASK=7,
    LAND_RGBA_MASK=15
};
struct LandDisplay {
    int w, h, flags;
    float color_r, color_g, color_b, color_a;
    int blend;
    float thickness;
    float cursor_x, cursor_y;
    int clip_off;
    float clip_x1, clip_y1, clip_x2, clip_y2;
    int clip_stack_depth;
    int clip_stack [LAND_MAX_CLIP_DEPTH * 5];
    LandFloat matrix [16];
    LandFloat matrix_stack [16] [16];
    int matrix_stack_depth;
    bool matrix_modified;
};
extern LandDisplay * _land_active_display;
LandDisplay* land_display_new(int w, int h, int flags);
void land_display_destroy(LandDisplay * self);
void land_display_del(LandDisplay * self);
void land_scale_to_fit(float w, float h, int how);
void land_set_image_display(LandImage * image);
void land_unset_image_display(void);
void land_display_set(void);
LandDisplay* land_display_get(void);
void land_display_unset(void);
void land_display_init(void);
void land_display_exit(void);
double land_display_time_flip_speed(double howlong);
void land_display_toggle_fullscreen(void);
void land_clear(float r, float g, float b, float a);
void land_clear_depth(float z);
void land_color(float r, float g, float b, float a);
void land_premul(float r, float g, float b, float a);
void land_color_set(LandColor c);
void land_thickness(float t);
void land_get_color(float * r, float * g, float * b, float * a);
int land_blend(int state);
void land_clip(float x, float y, float x_, float y_);
void land_clip_intersect(float x, float y, float x_, float y_);
void land_clip_push(void);
void land_clip_pop(void);
void land_clip_on(void);
void land_clip_off(void);
void land_unclip(void);
int land_get_clip(float * cx1, float * cy1, float * cx2, float * cy2);
void land_flip(void);
void land_rectangle(float x, float y, float x_, float y_);
void land_filled_rectangle(float x, float y, float x_, float y_);
void land_filled_circle(float x, float y, float x_, float y_);
void land_circle(float x, float y, float x_, float y_);
void land_arc(float x, float y, float x_, float y_, float a, float a_);
void land_line(float x, float y, float x_, float y_);
void land_move_to(float x, float y);
void land_line_to(float x, float y);
void land_ribbon(int n, float * xy);
void land_ribbon_loop(int n, float * xy);
void land_filled_ribbon(int n, float * xy);
void land_polygon(int n, float * xy);
void land_filled_polygon(int n, float * xy);
void land_filled_triangle(float x0, float y0, float x1, float y1, float x2, float y2);
void land_3d_triangles(int n, LandFloat * xyzrgb);
void land_textured_polygon(LandImage * image, int n, float * xy, float * uv);
void land_filled_polygon_with_holes(int n, float * xy, int * holes);
void land_filled_colored_polygon(int n, float * xy, float * rgba);
void land_plot(float x, float y);
void land_pick_color(float x, float y);
int land_display_width(void);
int land_display_height(void);
void land_display_resize(int w, int h);
void land_display_move(int x, int y);
void land_display_desktop_size(int * w, int * h);
void land_display_title(char const * title);
int land_display_flags(void);
LandImage* land_display_new_image(void);
void land_display_del_image(LandImage * image);
void land_display_select(LandDisplay * display);
void land_display_unselect(void);
void land_screenshot(char const * filename);
void land_screenshot_autoname(char const * name);
void land_resize_event(int w, int h);
int land_was_resized(void);
void land_display_tick(void);
void land_rotate(LandFloat angle);
void land_scale(LandFloat x, LandFloat y);
void land_translate(LandFloat x, LandFloat y);
void land_z(LandFloat z);
void land_push_transform(void);
void land_pop_transform(void);
void land_reset_transform(void);
void land_transform(LandFloat * x, LandFloat * y, LandFloat * z);
void land_display_transform_4x4(Land4x4Matrix * matrix);
void land_render_state(int state, int value);
void land_display_set_default_shaders(void);
LandCSG* csg_sphere(int slices, int rings, void * shared);
LandCSG* csg_cylinder(int slices, void * shared);
LandCSG* csg_cylinder_open(int slices, bool opened, void * shared);
LandCSG* csg_cone(int slices, void * shared);
LandCSG* csg_prism(int slices, void * shared);
LandCSG* csg_pyramid(void * shared);
LandCSG* csg_tetrahedron(void * shared);
LandCSG* csg_cube(void * shared);
LandCSG* csg_block(int x, int y, int z, bool outside, void * shared);
LandCSG* csg_torus(int slices, int segments, LandFloat diameter, void * shared);
struct LandProtobuf {
    LandBuffer * data;
    uint64_t pos;
    uint64_t end;
};
LandProtobuf* land_protobuf_load(char const * filename);
int land_protobuf_next(LandProtobuf * self, uint64_t * size);
void land_protobuf_sub_start(LandProtobuf * self, uint64_t * size);
void land_protobuf_sub_end(LandProtobuf * self, uint64_t end);
double land_protobuf_double(LandProtobuf * self);
float land_protobuf_float(LandProtobuf * self);
uint32_t land_protobuf_fixed32(LandProtobuf * self);
int32_t land_protobuf_sfixed32(LandProtobuf * self);
char* land_protobuf_string(LandProtobuf * self, int size);
void land_protobuf_destroy(LandProtobuf * self);
struct LandMap {
    LandLayer * first_layer;
    LandLayer * main_layer;
};
void land_map_draw(LandMap * self, LandView * view);
void land_map_add_layer(LandMap * map, LandLayer * layer);
LandLayer* land_map_base_layer(LandMap * map);
LandLayer* land_map_find_layer(LandMap * map, char const * name);
LandMap* land_map_new(void);
void land_map_del(LandMap * self);
void land_map_destroy(LandMap * self);
void csg_test_shapes(void);
void csg_test_union(void);
void csg_test_subtract(void);
void csg_test_intersect(void);
void csg_test(void);
#define GUL_SHRINK_X 1
#define GUL_CENTER_X 2
#define GUL_RIGHT 4
#define GUL_EQUAL_X 8
#define GUL_LEAVE_X 16
#define GUL_SHRINK_Y (1 * 256)
#define GUL_CENTER_Y (2 * 256)
#define GUL_BOTTOM (4 * 256)
#define GUL_EQUAL_Y (8 * 256)
#define GUL_LEAVE_Y (16 * 256)
#define GUL_HIDDEN (1 * 65536)
#define GUL_NO_LAYOUT (2 * 65536)
#define GUL_RESIZE (4 * 65536)
struct LandLayoutBox {
    int x, y, w, h;
    int ow, oh;
    struct LandWidget * (* lookup_grid);
    int cols, rows;
    int col, row;
    int extra_cols;
    int extra_rows;
    int min_width;
    int min_height;
    int max_width;
    int max_height;
    int current_min_width;
    int current_min_height;
    int flags;
};
void _land_gul_box_initialize(LandLayoutBox * self);
void _land_gul_box_deinitialize(LandLayoutBox * self);
void _land_gul_layout_updated(LandWidget * self);
void _land_gul_layout_updated_during_layout(LandWidget * self);
extern int(* land_exception_handler)(char const * str);
int land_default_exception_handler(char const * str);
void land_exception_handler_init(void);
void land_exception_handler_set(int(* handler)(char const * str));
void land_exception(char const * format, ...);
#include <assert.h>
struct LandFont {
    int size;
    double xscaling;
    double yscaling;
};
struct LandFontState {
    float x_pos, y_pos;
    float adjust_width;
    LandFont * font;
    float x, y, w, h;
    bool off;
    float wordwrap_width, wordwrap_height;
};
enum {
    LandAlignLeft,
    LandAlignRight,
    LandAlignCenter,
    LandAlignAdjust
};
void land_font_init(void);
void land_font_exit(void);
int land_font_active(void);
LandFont* land_font_load(char const * filename, float size);
void land_font_destroy(LandFont * self);
LandFont* land_font_new(void);
void land_font_scale(LandFont * f, double scaling);
void land_font_yscale(LandFont * f, double scaling);
void land_font_set(LandFont * self);
void land_text_pos(float x, float y);
void land_text_set_width(float w);
float land_text_x_pos(void);
float land_text_y_pos(void);
float land_text_x(void);
float land_text_y(void);
float land_text_width(void);
float land_text_height(void);
int land_text_state(void);
float land_font_height(LandFont * self);
LandFont* land_font_current(void);
float land_line_height(void);
void land_text_off(void);
void land_text_on(void);
void land_print_string(char const * str, int newline, int alignment);
float land_text_get_width(char const * str);
int land_text_get_char_offset(char const * str, int nth);
int land_text_get_char_index(char const * str, int x);
#define VPRINT \
    va_list args; \
    va_start(args, text); \
    int n = vsnprintf(NULL, 0, text, args); \
    va_end(args); \
    if (n < 0) { \
        n = 1023; \
    } \
    char s [n + 1]; \
    va_start(args, text); \
    vsnprintf(s, n + 1, text, args); \
    va_end(args);
void land_print(char const * text, ...);
void land_print_right(char const * text, ...);
void land_print_center(char const * text, ...);
void land_write(char const * text, ...);
void land_write_right(char const * text, ...);
void land_write_center(char const * text, ...);
void land_printv(char const * text, va_list args);
int land_print_string_wordwrap(char const * text, int w, int h, int alignment);
int land_print_wordwrap(int w, int h, char const * text, ...);
int land_print_wordwrap_right(int w, int h, char const * text, ...);
int land_print_wordwrap_center(int w, int h, char const * text, ...);
LandArray* land_wordwrap_text(int w, int h, char const * str);
void land_text_destroy_lines(LandArray * lines);
LandArray* land_text_splitlines(char const * str);
void land_wordwrap_extents(float * w, float * h);
void land_print_lines(LandArray * lines, int alignment);
LandFont* land_font_from_image(LandImage * image, int n_ranges, int * ranges);
struct LandParameters {
    int w, h;
    int fps;
    int flags;
    LandRunner * start;
};
extern bool _land_quit;
extern bool _land_halted;
extern bool _land_was_halted;
extern int _land_frames;
extern bool _land_synchronized;
void land_halt(void);
void land_resume(void);
bool land_was_halted(void);
void land_init(void);
void land_tick(void);
void land_draw(void);
void land_quit(void);
void land_closebutton_event(void);
int land_closebutton(void);
void land_set_fps(int f);
void land_set_display_parameters(int w, int h, int flags);
void land_set_initial_runner(LandRunner * runner);
double land_get_fps(void);
int land_get_ticks(void);
double land_get_time(void);
void land_pause(void);
void land_unpause(void);
int land_get_flags(void);
void land_set_synchronized(bool onoff);
void land_maximize_fps(bool onoff);
void land_mainloop(void);
struct LandView {
    float scroll_x, scroll_y;
    float scale_x, scale_y;
    int x, y, w, h;
    float r, g, b, a;
};
LandView* land_view_new(int x, int y, int w, int h);
void land_view_destroy(LandView * self);
void land_view_scroll(LandView * self, float dx, float dy);
void land_view_scroll_to(LandView * self, float x, float y);
void land_view_scale(LandView * self, float sx, float sy);
void land_view_zoom(LandView * self, float zx, float zy);
void land_view_scroll_center(LandView * self, float x, float y);
void land_view_scroll_center_on_screen(LandView * self, float x, float y);
void land_view_ensure_visible(LandView * self, float x, float y, float bx, float by);
void land_view_ensure_visible_on_screen(LandView * self, float x, float y, float bx, float by);
void land_view_ensure_inside_grid(LandView * self, LandGrid * grid);
void land_view_clip(LandView * self);
void land_view_to_world(LandView * self, float vx, float vy, float * wx, float * wy);
#include <stdbool.h>
void* platform_fopen(char const * filename, char const * mode);
void platform_fclose(void * f);
int platform_fread(void * f, char * buffer, int bytes);
int platform_fwrite(void * f, char const * buffer, int bytes);
void platform_ungetc(void * f, int c);
int platform_fgetc(void * f);
bool platform_feof(void * f);
void platform_fseek(void * f, int n);
LandArray* platform_filelist(char const * dir, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data);
bool platform_is_dir(char const * path);
bool platform_file_exists(char const * path);
char* platform_get_save_file(char const * appname, char const * name);
char* platform_get_current_directory(void);
char* platform_get_data_path(void);
bool platform_remove_file(char const * path);
#include <stdbool.h>
struct LandGridInterface {
    void(* draw)(LandGrid * self, LandView * view);
    void(* draw_cell)(LandGrid * self, LandView * view, int cell_x, int cell_y, float pixel_x, float pixel_y);
    void(* get_cell_at)(LandGrid * self, LandView * view, float pixel_x, float pixel_y, float * cell_x, float * cell_y);
    void(* get_cell_position)(LandGrid * self, LandView * view, float cell_x, float cell_y, float * pixel_x, float * pixel_y);
    void(* del)(LandGrid * self);
};
struct LandGrid {
    LandGridInterface * vt;
    int x_cells, y_cells;
    int cell_w, cell_h;
    float scale_x, scale_y;
    bool wrap;
};
void land_grid_draw(LandGrid * self, LandView * view);
void land_grid_get_cell_at(LandGrid * self, LandView * view, float view_x, float view_y, float * cell_x, float * cell_y);
void land_grid_get_cell_position(LandGrid * self, LandView * view, float cell_x, float cell_y, float * view_x, float * view_y);
void land_grid_initialize(LandGrid * self, int cell_w, int cell_h, int x_cells, int y_cells);
void land_grid_init(void);
void land_grid_exit(void);
void land_grid_del(LandGrid * self);
struct LandMemoryPool {
    LandMemoryPool * prev;
    int allocated;
    int used;
    void * memory;
};
LandMemoryPool* land_pool_new_initial(int initial);
LandMemoryPool* land_pool_new(void);
void land_pool_destroy(LandMemoryPool * self);
void* land_pool_alloc(LandMemoryPool * self, int size);
struct LandWidgetThemeElement {
    char * name;
    LandImage * bmp;
    int flags;
    int bl, bt, br, bb;
    int minw, minh;
    LandWidget * anchor;
    int ox, oy;
    float r, g, b, a;
    LandFont * font;
    bool transparent;
    int il, it, ir, ib;
    int hgap, vgap;
    LandWidgetThemeElement * selected;
    LandWidgetThemeElement * disabled;
    LandWidgetTheme * theme;
};
struct LandWidgetTheme {
    char * name;
    char * prefix;
    char * suffix;
    LandList * elements;
};
LandWidgetTheme* land_widget_theme_default(void);
void land_widget_theme_set_default(LandWidgetTheme * self);
LandWidgetThemeElement* land_widget_theme_element_new(struct LandWidgetTheme * theme, char const * name, char const * argline);
LandWidgetTheme* land_widget_theme_new(char const * filename);
void land_widget_theme_destroy(LandWidgetTheme * self);
LandWidgetThemeElement* land_widget_theme_find_element(LandWidgetTheme * theme, LandWidget * widget);
LandWidgetThemeElement* land_widget_theme_element(LandWidget * self);
void land_widget_theme_draw(LandWidget * self);
void land_widget_theme_color(LandWidget * self);
void land_widget_theme_font(LandWidget * self);
void land_widget_theme_set_minimum_size_for_contents(LandWidget * self, int w, int h);
void land_widget_theme_set_minimum_size_for_text(LandWidget * self, char const * text);
void land_widget_theme_set_minimum_size_for_image(LandWidget * self, LandImage * image);
void land_widget_theme_initialize(LandWidget * self);
void land_widget_theme_update(LandWidget * self);
void land_widget_theme_apply(LandWidget * self, LandWidgetTheme * theme);
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
struct LandArray {
    int count;
    int size;
    void * (* data);
};
struct LandArrayIterator {
    int i;
};
LandArray* land_array_new_memlog(char const * f, int l);
void land_array_destroy_memlog(LandArray * self, char const * f, int l);
void land_array_add_memlog(LandArray * self, void * data, char const * f, int l);
LandArray* land_array_copy_memlog(LandArray const * self, char const * f, int l);
void land_array_concat_memlog(LandArray * self, LandArray const * other, char const * f, int l);
void land_array_merge_memlog(LandArray * self, LandArray * other, char const * f, int l);
void land_array_clear_memlog(LandArray * self, char const * f, int l);
LandArrayIterator LandArrayIterator_first(LandArray * a);
void* LandArrayIterator_item(LandArray * a, LandArrayIterator * i);
bool LandArrayIterator_next(LandArray * a, LandArrayIterator * i);
LandArray* land_array_new(void);
void land_array_add(LandArray * self, void * data);
void land_array_reserve(LandArray * self, int n);
void* land_array_pop(LandArray * self);
void land_array_add_data(LandArray * (* array), void * data);
int land_array_find(LandArray * self, void * data);
void* land_array_get_nth(LandArray const * array, int i);
bool land_array_is_empty(LandArray const * array);
void* land_array_replace_nth(LandArray * array, int i, void * data);
void land_array_destroy(LandArray * self);
void land_array_destroy_with_strings(LandArray * self);
void land_array_sort(LandArray * self, int(* cmpfnc)(void const * a, void const * b));
void land_array_sort_alphabetical(LandArray * self);
int land_array_count(LandArray const * self);
int land_array_for_each(LandArray * self, int(* cb)(void * item, void * data), void * data);
void land_array_clear(LandArray * self);
void land_array_concat(LandArray * self, LandArray const * other);
void land_array_merge(LandArray * self, LandArray * other);
LandArray* land_array_copy(LandArray const * self);
void land_array_swap(LandArray * self, int a, int b);
void land_array_move_behind(LandArray * self, int a, int b);
void land_array_reverse(LandArray * self);
#ifdef LAND_MEMLOG
#define land_array_new() land_array_new_memlog(__FILE__, __LINE__)
#define land_array_destroy(x) land_array_destroy_memlog(x, __FILE__, __LINE__)
#define land_array_add(x, y) land_array_add_memlog(x, y, __FILE__, __LINE__)
#define land_array_copy(x) land_array_copy_memlog(x, __FILE__, __LINE__)
#define land_array_merge(x, y) land_array_merge_memlog(x, y, __FILE__, __LINE__)
#define land_array_concat(x, y) land_array_concat_memlog(x, y, __FILE__, __LINE__)
#define land_array_clear(x) land_array_clear_memlog(x, __FILE__, __LINE__)
#endif
#include <stdbool.h>
enum LandKeyboardKeys {
    LandKeyNone=0,
    LandKeyInsert=1,
    LandKeyDelete=2,
    LandKeyHome=3,
    LandKeyEnd=4,
    LandKeyPageUp=5,
    LandKeyPageDown=6,
    LandKeyPadSlash=7,
    LandKeyBackspace=8,
    LandKeyTab=9,
    LandKeyPadStar=10,
    LandKeyPadMinus=11,
    LandKeyPadPlus=12,
    LandKeyEnter=13,
    LandKeyUnknown=14,
    LandKeyBack=25,
    LandKeyEscape=27,
    LandKeyPadDelete=28,
    LandKeyPadEnter=29,
    LandKeyLeftWin=30,
    LandKeyRightWin=31,
    LandKeyUnknown2=33,
    LandKeyLeftShift='(',
    LandKeyRightShift=')',
    LandKeyScrollLock='*',
    LandKeyNumLock='+',
    LandKeyNumber='0',
    LandKeyLeftAlt='<',
    LandKeyRightAlt='>',
    LandKeyMenu='?',
    LandKeyFunction='@',
    LandKeyPad='M',
    LandKeyLeft='W',
    LandKeyRight='X',
    LandKeyUp='Y',
    LandKeyDown='Z',
    LandKeyCapsLock='_',
    LandKeyPrint='`',
    LandKeyLetter='a',
    LandKeyLeftControl='{',
    LandKeyPause='|',
    LandKeyRightControl='}',
    LandKeyUnknown3=127,
    LandKeysCount=228
};
void land_key_press_event(int k);
void land_key_release_event(int k);
void land_keyboard_init(void);
int land_key(int k);
int land_key_pressed(int k);
void land_keyboard_tick(void);
void land_keyboard_add_char(int keycode, int unicode);
bool land_keybuffer_empty(void);
void land_keybuffer_next(int * k, int * u);
char const* land_key_name(int k);
struct LandRunner {
    char * name;
    int inited;
    bool allocated;
    void(* init)(LandRunner * self);
    void(* enter)(LandRunner * self);
    void(* tick)(LandRunner * self);
    void(* draw)(LandRunner * self);
    void(* leave)(LandRunner * self);
    void(* destroy)(LandRunner * self);
};
void land_runner_register(LandRunner * self);
void land_runner_initialize(LandRunner * self, char const * name, void(* init)(LandRunner * self), void(* enter)(LandRunner * self), void(* tick)(LandRunner * self), void(* draw)(LandRunner * self), void(* leave)(LandRunner * self), void(* destroy)(LandRunner * self));
LandRunner* land_runner_new(char const * name, void(* init)(LandRunner * self), void(* enter)(LandRunner * self), void(* tick)(LandRunner * self), void(* draw)(LandRunner * self), void(* leave)(LandRunner * self), void(* destroy)(LandRunner * self));
void land_runner_switch_active(LandRunner * self);
void land_runner_enter_active(void);
void land_runner_tick_active(void);
void land_runner_draw_active(void);
void land_runner_leave_active(void);
void land_runner_destroy_all(void);
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define land_alloc(self) self = land_calloc(sizeof (* self))
enum {
    LAND_MEMBLOCK_INFO_MAX_STACK=32
};
struct LandMemBlockInfo {
    void * ptr;
    char const * id;
    const char * file;
    int line;
    int size;
    int trace_depth;
    void * trace [LAND_MEMBLOCK_INFO_MAX_STACK];
};
void land_memory_add(void * ptr, char const * id, int size, const char * f, int l);
void land_memory_remove(void * ptr, char const * id, int re, const char * f, int l);
void* land_malloc_memlog(int size, char const * f, int l);
void* land_calloc_memlog(int size, char const * f, int l);
void* land_realloc_memlog(void * ptr, int size, char const * f, int l);
char* land_strdup_memlog(char const * str, char const * f, int l);
void land_free_memlog(void * ptr, char const * f, int l);
void* land_malloc(int size);
void* land_calloc(int size);
void* land_realloc(void * ptr, int size);
char* land_strdup(char const * str);
void land_free(void * ptr);
#ifdef LAND_MEMLOG
#define land_malloc(x) land_malloc_memlog(x, __FILE__, __LINE__)
#define land_calloc(x) land_calloc_memlog(x, __FILE__, __LINE__)
#define land_free(x) land_free_memlog(x, __FILE__, __LINE__)
#define land_realloc(x, y) land_realloc_memlog(x, y, __FILE__, __LINE__)
#define land_strdup(x) land_strdup_memlog(x, __FILE__, __LINE__)
#endif
struct LandColor {
    float r, g, b, a;
};
LandColor land_color_hsv(float hue, float sat, float val);
LandColor land_color_rgba(float r, float g, float b, float a);
LandColor land_color_premul(float r, float g, float b, float a);
LandColor land_color_name(char const * name);
LandColor land_color_lerp(LandColor a, LandColor b, float t);
char const* color_bash(char const * x);
struct LandCSGAABB {
    double x1, y1, z1, x2, y2, z2;
};
LandCSGAABB land_csg_aabb_infinite(void);
LandCSGAABB land_csg_aabb_empty(void);
void land_csg_aabb_update(LandCSGAABB * self, LandArray * polygons);
LandCSGAABB land_csg_aabb_intersect(LandCSGAABB a, LandCSGAABB b);
void land_log_overwrite(char const * name);
void land_log_set(char const * name);
void land_log_del(void);
void land_log_new(char const * base, int unique);
void land_log_message_nostamp(char const * format, ...);
void land_log_message(char const * format, ...);
struct LandListItem {
    void * data;
    LandListItem * next, * prev;
};
struct LandList {
    int count;
    LandListItem * first, * last;
};
struct LandListIterator {
    LandListItem * i;
};
LandList* land_list_new_memlog(char const * f, int l);
void land_list_destroy_memlog(LandList * self, char const * f, int l);
void land_add_list_data_memlog(LandList * (* list), void * data, char const * f, int l);
LandListIterator LandListIterator_first(LandList * a);
void* LandListIterator_item(LandList * a, LandListIterator * i);
bool LandListIterator_next(LandList * a, LandListIterator * i);
LandList* land_list_new(void);
void land_list_clear(LandList * list);
void land_list_destroy(LandList * list);
LandListItem* land_listitem_new(void * data);
void land_listitem_destroy(LandListItem * self);
void land_list_insert_item(LandList * list, LandListItem * item);
void land_list_insert_item_before(LandList * list, LandListItem * insert, LandListItem * before);
void land_list_remove_item(LandList * list, LandListItem * item);
void land_add_list_data(LandList * (* list), void * data);
void land_remove_list_data(LandList * (* list), void * data);
#ifdef LAND_MEMLOG
#define land_list_new() land_list_new_memlog(__FILE__, __LINE__)
#define land_list_destroy(x) land_list_destroy_memlog(x, __FILE__, __LINE__)
#define land_add_list_data(x, y) land_add_list_data_memlog(x, y, __FILE__, __LINE__)
#endif
struct LandThread {
    void * data;
    void(* cb)(void * data);
};
struct LandLock {
    void * lock;
};
void land_thread_run(void(* cb)(void * data), void * data);
LandThread* land_thread_new(void(* cb)(void * data), void * data);
void land_thread_destroy(LandThread * t);
LandLock* land_thread_new_lock(void);
void land_thread_delete_lock(LandLock * l);
void land_thread_lock(LandLock * l);
void land_thread_unlock(LandLock * l);
#define LAND_SUBIMAGE 1
#define LAND_LOADED 2
#define LAND_IMAGE_WAS_CENTERED 4
#define LAND_IMAGE_MEMORY 8
#define LAND_AUTOCROP 16
#define LAND_FAILED 32
#define LAND_IMAGE_CENTER 64
struct LandImage {
    char * filename;
    char * name;
    int flags;
    LandPixelMask * mask;
    int width, height;
    float x, y;
    float l, t, r, b;
};
struct LandSubImage {
    LandImage super;
    LandImage * parent;
    float x, y, w, h;
};
void land_image_set_callback(void(* cb)(char const * path, LandImage * image));
LandImage* land_image_load(char const * filename);
LandImage* land_image_load_memory(char const * filename);
LandImage* land_image_new_deferred(char const * filename);
bool land_image_load_on_demand(LandImage * self);
LandImage* land_image_memory_new(int w, int h);
LandImage* land_image_new(int w, int h);
LandImage* land_image_create(int w, int h);
void land_image_del(LandImage * self);
void land_image_destroy(LandImage * self);
void land_image_crop(LandImage * self, int x, int y, int w, int h);
void land_image_auto_crop(LandImage * self);
LandImage* land_image_new_from(LandImage * copy, int x, int y, int w, int h);
int land_image_color_stats(LandImage * self, float * red, float * green, float * blue, float * alpha);
void land_image_color_replace(LandImage * self, int r255, int g255, int b255, int a255, int _r255, int _g255, int _b255, int _a255);
void land_image_colorkey(LandImage * self, int r255, int g255, int b255);
void land_image_colorkey_hack(LandImage * self, int allegro_color);
void land_image_colorize(LandImage * self, LandImage * colormask);
void land_image_colorize_replace(LandImage * self, int n, int * rgb);
LandImage* land_image_split_mask_from_colors(LandImage * self, int n_rgb, int * rgb);
void land_image_prepare(LandImage * self);
LandArray* land_load_images_cb(char const * pattern, void(* cb)(LandImage * image, void * data), void * data);
LandArray* land_load_images(char const * pattern, int center, int auto_crop);
LandImage* land_image_sub(LandImage * parent, float x, float y, float w, float h);
LandArray* land_image_load_sheet(char const * filename, int offset_x, int offset_y, int grid_w, int grid_h, int x_gap, int y_gap, int x_count, int y_count, int auto_crop);
LandArray* land_image_load_split_sheet(char const * filename, int offset_x, int offset_y, int grid_w, int grid_h, int x_gap, int y_gap, int x_count, int y_count, int auto_crop);
void land_image_draw_scaled_rotated_tinted_flipped(LandImage * self, float x, float y, float sx, float sy, float angle, float r, float g, float b, float alpha, int flip);
void land_image_draw_scaled_rotated_tinted(LandImage * self, float x, float y, float sx, float sy, float angle, float r, float g, float b, float alpha);
void land_image_draw_scaled_rotated(LandImage * self, float x, float y, float sx, float sy, float angle);
void land_image_draw_scaled(LandImage * self, float x, float y, float sx, float sy);
void land_image_draw_rotated(LandImage * self, float x, float y, float a);
void land_image_draw_rotated_flipped(LandImage * self, float x, float y, float a);
void land_image_draw_rotated_tinted(LandImage * self, float x, float y, float a, float r, float g, float b, float alpha);
void land_image_draw_scaled_tinted(LandImage * self, float x, float y, float sx, float sy, float r, float g, float b, float alpha);
void land_image_draw(LandImage * self, float x, float y);
void land_image_draw_flipped(LandImage * self, float x, float y);
void land_image_draw_tinted(LandImage * self, float x, float y, float r, float g, float b, float alpha);
void land_image_grab(LandImage * self, int x, int y);
void land_image_grab_into(LandImage * self, float x, float y, float tx, float ty, float tw, float th);
void land_image_offset(LandImage * self, int x, int y);
void land_image_memory_draw(LandImage * self, float x, float y);
void land_image_center(LandImage * self);
void land_image_init(void);
void land_image_exit(void);
void land_image_clip(LandImage * self, float x, float y, float x_, float y_);
void land_image_unclip(LandImage * self);
void land_image_draw_partial(LandImage * self, float x, float y, float sx, float sy, float sw, float sh);
int land_image_height(LandImage * self);
int land_image_width(LandImage * self);
void land_image_get_rgba_data(LandImage * self, unsigned char * rgba);
void land_image_set_rgba_data(LandImage * self, unsigned char const * rgba);
void land_image_save(LandImage * self, char const * filename);
int land_image_opengl_texture(LandImage * self);
void land_image_flip(LandImage * self);
LandImage* land_image_clone(LandImage * self);
void land_image_fade_to_color(LandImage * self);
LandImage* land_image_from_xpm(char const * (* xpm));
struct LandTileGrid {
    LandGrid super;
    LandImage * (* tiles);
};
#define LAND_TILE_GRID(_) ((LandTileGrid *)(_))
LandGrid* land_tilegrid_new(int cell_w, int cell_h, int x_cells, int y_cells);
void land_tilegrid_del(LandGrid * self);
void land_tilegrid_place(LandGrid * super, int cell_x, int cell_y, LandImage * image);
void land_grid_draw_normal(LandGrid * self, LandView * view);
void land_tilemap_init(void);
void land_tilemap_exit(void);
struct LandAnimation {
    float fps;
    LandArray * frames;
};
LandAnimation* land_animation_new(LandArray * frames);
void land_animation_destroy(LandAnimation * self);
LandImage* land_animation_get_frame(LandAnimation * self, int i);
int land_animation_length(LandAnimation * self);
void land_animation_add_frame(LandAnimation * self, LandImage * frame);
LandAnimation* land_animation_load_cb(char const * pattern, void(* cb)(LandImage * image, void * data), void * data);
void land_animation_draw_frame(LandAnimation * self, int i, float x, float y);
void land_animation_draw_frame_rotated(LandAnimation * self, int i, float x, float y, float angle);
void land_animation_draw_frame_scaled_rotated(LandAnimation * self, int i, float x, float y, float xs, float ys, float angle);
struct LandVector {
    LandFloat x, y, z;
};
struct Land4x4Matrix {
    LandFloat v [16];
};
struct LandQuaternion {
    LandFloat w, x, y, z;
};
LandVector land_vector(LandFloat x, LandFloat y, LandFloat z);
LandVector land_vector_from_array(LandFloat * a);
void land_vector_iadd(LandVector * v, LandVector w);
void land_vector_isub(LandVector * v, LandVector w);
void land_vector_imul(LandVector * v, LandFloat s);
void land_vector_idiv(LandVector * v, LandFloat s);
LandVector land_vector_neg(LandVector v);
LandVector land_vector_mul(LandVector v, LandFloat s);
LandVector land_vector_div(LandVector v, LandFloat s);
LandVector land_vector_add(LandVector v, LandVector w);
LandVector land_vector_sub(LandVector v, LandVector w);
LandVector land_vector_lerp(LandVector v, LandVector w, LandFloat t);
LandFloat land_vector_dot(LandVector v, LandVector w);
LandVector land_vector_cross(LandVector v, LandVector w);
LandFloat land_vector_norm(LandVector v);
LandVector land_vector_normalize(LandVector v);
LandQuaternion land_vector_quatmul(LandVector v, LandQuaternion q);
LandVector land_vector_transform(LandVector v, LandVector p, LandVector r, LandVector u, LandVector b);
LandVector land_vector_matmul(LandVector v, Land4x4Matrix * m);
LandVector land_vector_backtransform(LandVector v, LandVector p, LandVector r, LandVector u, LandVector b);
LandVector land_vector_rotate(LandVector v, LandVector a, double angle);
LandVector land_vector_reflect(LandVector v, LandVector n);
LandQuaternion land_quaternion(LandFloat w, LandFloat x, LandFloat y, LandFloat z);
LandQuaternion land_quaternion_from_array(LandFloat * f);
void land_quaternion_to_array(LandQuaternion * q, LandFloat * f);
void land_quaternion_iadd(LandQuaternion * q, LandQuaternion p);
void land_quaternion_imul(LandQuaternion * q, LandFloat s);
LandQuaternion land_quaternion_combine(LandQuaternion qa, LandQuaternion qb);
void land_quaternion_vectors(LandQuaternion q, LandVector * r, LandVector * u, LandVector * b);
Land4x4Matrix land_quaternion_4x4_matrix(LandQuaternion q);
Land4x4Matrix land_4x4_matrix_mul(Land4x4Matrix a, Land4x4Matrix b);
Land4x4Matrix land_4x4_matrix_scale(LandFloat x, LandFloat y, LandFloat z);
Land4x4Matrix land_4x4_matrix_rotate(LandFloat x, LandFloat y, LandFloat z, LandFloat angle);
Land4x4Matrix land_4x4_matrix_identity(void);
Land4x4Matrix land_4x4_matrix_translate(LandFloat x, LandFloat y, LandFloat z);
Land4x4Matrix land_4x4_matrix_perspective(LandFloat left, LandFloat bottom, LandFloat nearz, LandFloat right, LandFloat top, LandFloat farz);
Land4x4Matrix land_4x4_matrix_orthographic(LandFloat left, LandFloat top, LandFloat nearz, LandFloat right, LandFloat bottom, LandFloat farz);
Land4x4Matrix land_4x4_matrix_from_vectors(LandVector * p, LandVector * r, LandVector * u, LandVector * b);
Land4x4Matrix land_4x4_matrix_inverse_from_vectors(LandVector * p, LandVector * r, LandVector * u, LandVector * b);
void land_quaternion_normalize(LandQuaternion * q);
LandQuaternion land_quaternion_slerp(LandQuaternion qa, LandQuaternion qb, double t);
LandBuffer* land_4x4_matrix_to_string(Land4x4Matrix * m);
struct LandQueue {
    LandArray array;
    int(* cmp_cb)(void * data1, void * data2);
};
LandQueue* land_queue_new(int(* cmp_cb)(void * data1, void * data2));
void land_queue_del(LandQueue * q);
void land_queue_destroy(LandQueue * q);
void land_queue_add(LandQueue * q, void * data);
void* land_queue_pop(LandQueue * q);
LandArray* land_queue_sort(LandQueue * q);
int land_queue_for_each(LandQueue * self, int(* cb)(void * item, void * data), void * data);
int land_queue_count(LandQueue * self);
void land_queue_clear(LandQueue * self);
struct LandDisplayPlatform {
    LandDisplay super;
    ALLEGRO_DISPLAY * a5;
    ALLEGRO_COLOR c;
    ALLEGRO_STATE blend_state;
    ALLEGRO_TRANSFORM transform;
    ALLEGRO_SHADER * default_shader;
};
void platform_display_init(void);
void platform_display_exit(void);
LandDisplay* platform_display_new(void);
void platform_display_del(LandDisplay * super);
void platform_display_desktop_size(int * w, int * h);
void platform_display_title(char const * title);
void platform_display_move(int x, int y);
void platform_display_resize(int w, int h);
void land_a5_display_check_transform(void);
void platform_display_set(void);
void platform_display_color(void);
void platform_display_clip(void);
void platform_display_clear(LandDisplay * self, float r, float g, float b, float a);
void platform_display_clear_depth(LandDisplay * self, float z);
void platform_display_flip(void);
void platform_rectangle(float x, float y, float x_, float y_);
void platform_filled_rectangle(float x, float y, float x_, float y_);
void platform_filled_circle(float x, float y, float x_, float y_);
void platform_circle(float x, float y, float x_, float y_);
void platform_arc(float x, float y, float x_, float y_, float a, float a_);
void platform_ribbon(int n, float * xy);
void platform_ribbon_loop(int n, float * xy);
void platform_filled_ribbon(int n, float * xy);
void platform_line(float x, float y, float x_, float y_);
void platform_polygon(int n, float * xy);
void platform_filled_polygon(int n, float * xy);
void platform_textured_colored_polygon(LandImage * image, int n, float * xy, float * uv, float * rgba);
void platform_textured_polygon(LandImage * image, int n, float * xy, float * uv);
void platform_filled_colored_polygon(int n, float * xy, float * rgba);
void platform_filled_polygon_with_holes(int n, float * xy, int * holes);
void platform_3d_triangles(int n, LandFloat * xyzrgb);
void platform_plot(float x, float y);
void platform_pick_color(float x, float y);
void platform_render_state(int state, int value);
void platform_set_default_shaders(void);
struct LandImagePlatform {
    LandImage super;
    ALLEGRO_BITMAP * a5;
};
LandImage* platform_new_image(void);
void platform_del_image(LandImage * super);
void platform_image_empty(LandImage * super);
LandImage* platform_image_load(char const * filename, bool mem);
void platform_image_load_on_demand(LandImage * super);
LandImage* platform_image_sub(LandImage * parent, float x, float y, float w, float h);
void platform_image_save(LandImage * super, char const * filename);
void platform_image_prepare(LandImage * super);
void platform_image_draw_scaled_rotated_tinted_flipped(LandImage * super, float x, float y, float sx, float sy, float angle, float r, float g, float b, float alpha, int flip);
void platform_set_image_display(LandImage * super);
void platform_unset_image_display(void);
void platform_image_grab_into(LandImage * super, float x, float y, float tx, float ty, float tw, float th);
void platform_image_get_rgba_data(LandImage * super, unsigned char * rgba);
void platform_image_set_rgba_data(LandImage * super, unsigned char const * rgba);
int platform_image_opengl_texture(LandImage * super);
void platform_image_crop(LandImage * super, int x, int y, int w, int h);
struct LandGridIsometric {
    LandGrid super;
    float cell_w1, cell_h1;
    float cell_w2, cell_h2;
};
extern LandGridInterface * land_grid_vtable_isometric;
extern LandGridInterface * land_grid_vtable_isometric_wrap;
LandGrid* land_isometric_new(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells);
LandGrid* land_isometric_wrap_new(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells);
LandGrid* land_isometric_custom_grid(float cell_w1, float cell_h1, float cell_w2, float cell_h2, int x_cells, int y_cells, bool wrap, void(* draw_cell)(LandGrid * self, LandView * view, int cell_x, int cell_y, float x, float y));
void land_grid_pixel_to_cell_isometric(LandGrid * self, LandView * view, float mx, float my, float * partial_x, float * partial_y);
void land_grid_cell_to_pixel_isometric(LandGrid * self, LandView * view, float cell_x, float cell_y, float * view_x, float * view_y);
void land_grid_cell_to_pixel_isometric_wrap(LandGrid * self, LandView * view, float cell_x, float cell_y, float * view_x, float * view_y);
void land_grid_pixel_to_cell_isometric_wrap(LandGrid * self, LandView * view, float mx, float my, float * partial_x, float * partial_y);
void land_grid_draw_isometric(LandGrid * self, LandView * view);
void land_grid_draw_isometric_wrap(LandGrid * self, LandView * view);
void land_isometric_init(void);
void land_isometric_exit(void);
void platform_thread_run(void(* cb)(void *), void * data);
LandThread* platform_thread_new(void(* cb)(void * data), void * data);
void platform_thread_destroy(LandThread * self);
LandLock* platform_thread_new_lock(void);
void platform_thread_delete_lock(LandLock * lock);
void platform_thread_lock(LandLock * lock);
void platform_thread_unlock(LandLock * lock);
void platform_font_init(void);
void platform_font_exit(void);
LandFont* platform_font_load(char const * filename, float size);
LandFont* platform_font_from_image(LandImage * image, int n_ranges, int * ranges);
void platform_font_print(LandFontState * lfs, char const * str, int alignment);
LandFont* platform_font_new(void);
void platform_font_destroy(LandFont * super);
#define LAND_SPRITE(_) ((LandSprite *)(_))
#define LAND_SPRITE_ANIMATED(_) ((LandSpriteAnimated *)(_))
#define LAND_SPRITE_TYPE(_) ((LandSpriteType *)(_))
#define LAND_SPRITE_TYPE_IMAGE(_) ((LandSpriteTypeImage *)(_))
#define LAND_SPRITE_TYPE_ANIMATION(_) ((LandSpriteTypeAnimation *)(_))
#define LAND_SPRITES_GRID(x) ((LandSpritesGrid *)(x))
struct LandSpriteType {
    float x, y;
    float w, h;
    void(* draw)(LandSprite * self, LandView * view);
    int(* overlap)(LandSprite * self, LandSprite * other);
    void(* initialize)(LandSprite * self);
    void(* destroy)(LandSprite * self);
    void(* destroy_type)(LandSpriteType * self);
    char * name;
};
struct LandSpriteTypeWithImage {
    LandSpriteType super;
};
struct LandSpriteTypeImage {
    LandSpriteType super;
    LandImage * image;
};
struct LandSpriteTypeAnimation {
    LandSpriteTypeImage super;
    LandAnimation * animation;
};
struct LandSprite {
    float x, y, angle;
    LandSpriteType * type;
    int tag;
    bool shown;
    bool flipped;
};
struct LandSpriteWithImage {
    LandSprite super;
    LandImage * image;
};
struct LandSpriteAnimated {
    LandSprite super;
    int frame;
    float sx, sy;
    float r, g, b, a;
};
struct LandSpritesGrid {
    LandGrid super;
    LandList * (* sprites);
    int ysorted;
    int tag;
};
LandGrid* land_sprites_grid_new(int cell_w, int cell_h, int x_cells, int y_cells);
void land_sprites_grid_resize(LandGrid * super, int cell_w, int cell_h, int x_cells, int y_cells);
void land_sprites_grid_clear(LandGrid * super);
void land_sprites_grid_del(LandGrid * super);
void land_sprite_initialize(LandSprite * self, LandSpriteType * type);
LandSprite* land_sprite_new(LandSpriteType * type);
LandSprite* land_sprite_with_image_new(LandSpriteType * type, LandImage * image);
void land_sprite_image_destroy(LandSprite * self);
void land_sprite_image_initialize(LandSprite * super);
void land_sprite_animated_initialize(LandSprite * super);
LandSprite* land_sprite_animated_new(LandSpriteType * type);
void land_sprite_animated_destroy(LandSprite * sprite);
void land_sprite_del(LandSprite * self);
void land_sprite_destroy(LandSprite * self);
void land_sprite_show(LandSprite * self, LandGrid * grid);
void land_sprite_hide(LandSprite * self, LandGrid * grid);
int land_sprite_overlap_pixelperfect(LandSprite * self, LandSprite * other);
void land_sprite_grid_ysorted(LandGrid * self);
LandArray* land_sprites_grid_get_all(LandGrid * sprites_grid);
LandList* land_sprites_grid_overlap(LandSprite * self, LandGrid * sprites_grid);
LandList* land_sprites_grid_get_circle(LandGrid * sprites_grid, float x, float y, float radius);
LandList* land_sprites_grid_get_rectangle(LandGrid * sprites_grid, float l, float t, float r, float b);
LandList* land_sprites_grid_get_in_cell(LandGrid * grid, int cx, int cy);
LandList* land_sprites_get_triangle(LandGrid * sprites_grid, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y);
LandList* land_sprites_grid_get_in_view(LandGrid * sprites_grid, LandView * view, float l, float t, float r, float b);
void land_sprite_remove_from_grid(LandSprite * self, LandGrid * grid);
void land_sprite_place_into_grid(LandSprite * self, LandGrid * grid, float x, float y);
void land_sprite_move(LandSprite * self, LandGrid * grid, float x, float y);
void land_sprite_move_to(LandSprite * self, LandGrid * grid, float x, float y);
void land_sprites_grid_draw_cell(LandSpritesGrid * self, LandView * view, int cell_x, int cell_y, float pixel_x, float pixel_y);
void land_sprites_grid_draw(LandGrid * super, LandView * view);
void land_sprites_init(void);
void land_sprites_exit(void);
LandSpriteType* land_spritetype_new(void);
void land_spritetype_destroy(LandSpriteType * self);
LandSpriteTypeWithImage* land_spritetype_with_image_new(void);
void land_spritetype_image_initialize(LandSpriteType * super, LandImage * image, bool mask, int n);
LandSpriteType* land_spritetype_image_new(LandImage * image, bool mask, int n);
void land_spritetype_animation_initialize(LandSpriteType * super, LandAnimation * animation, LandImage * image, bool mask, int n);
LandSpriteType* land_spritetype_animation_new(LandAnimation * animation, LandImage * image, bool mask, int n);
void land_spritetype_animation_destroy(LandSpriteType * base);
#define LAND_WIDGET_ID_BASE 0x00000001
#define LAND_WIDGET_ID_CONTAINER 0x00000011
#define LAND_WIDGET_ID_SCROLLING 0x00000111
#define LAND_WIDGET_ID_SCROLLING_TEXT 0x00001111
#define LAND_WIDGET_ID_VBOX 0x00000211
#define LAND_WIDGET_ID_LIST 0x00001211
#define LAND_WIDGET_ID_HBOX 0x00000311
#define LAND_WIDGET_ID_TABBAR 0x00001311
#define LAND_WIDGET_ID_SPIN 0x00002311
#define LAND_WIDGET_ID_BOOKPAGE 0x00003311
#define LAND_WIDGET_ID_PANEL 0x00000411
#define LAND_WIDGET_ID_BOARD 0x00000511
#define LAND_WIDGET_ID_MENU 0x00000611
#define LAND_WIDGET_ID_MENUBAR 0x00001611
#define LAND_WIDGET_ID_BOOK 0x00000711
#define LAND_WIDGET_ID_SLIDER 0x00000811
#define LAND_WIDGET_ID_CHECKBOX 0x00000911
#define LAND_WIDGET_ID_BUTTON 0x00000021
#define LAND_WIDGET_ID_MENUBUTTON 0x00000121
#define LAND_WIDGET_ID_MENUITEM 0x00000221
#define LAND_WIDGET_ID_LISTITEM 0x00000321
#define LAND_WIDGET_ID_TAB 0x00000421
#define LAND_WIDGET_ID_SPINBUTTON 0x00000521
#define LAND_WIDGET_ID_SCROLLBAR 0x00000031
#define LAND_WIDGET_ID_EDIT 0x00000041
#define LAND_WIDGET_ID_HANDLE 0x00000051
#define LAND_WIDGET_ID_USER 0x80000000
struct LandWidgetInterface {
    int id;
    char * name;
    void(* init)(LandWidget * self);
    void(* enter)(LandWidget * self);
    void(* tick)(LandWidget * self);
    void(* mouse_enter)(LandWidget * self);
    void(* mouse_tick)(LandWidget * self);
    void(* mouse_leave)(LandWidget * self);
    void(* keyboard_enter)(LandWidget * self);
    void(* keyboard_tick)(LandWidget * self);
    void(* keyboard_leave)(LandWidget * self);
    void(* add)(LandWidget * self, LandWidget * add);
    void(* update)(LandWidget * self);
    void(* remove)(LandWidget * self, LandWidget * rem);
    void(* layout_changing)(LandWidget * self);
    void(* layout_changed)(LandWidget * self);
    void(* move)(LandWidget * self, float dx, float dy);
    void(* size)(LandWidget * self, float dx, float dy);
    void(* get_inner_size)(LandWidget * self, float * w, float * h);
    void(* draw)(LandWidget * self);
    void(* leave)(LandWidget * self);
    void(* destroy)(LandWidget * self);
};
struct LandWidget {
    LandWidgetInterface * vt;
    LandWidget * parent;
    LandLayoutBox box;
    unsigned int got_mouse : 1;
    unsigned int got_keyboard : 1;
    unsigned int send_to_top : 1;
    unsigned int want_focus : 1;
    unsigned int dont_clip : 1;
    unsigned int no_clip_check : 1;
    unsigned int no_decoration : 1;
    unsigned int only_border : 1;
    unsigned int hidden : 1;
    unsigned int no_layout : 1;
    unsigned int no_layout_notify : 1;
    unsigned int layout_hack : 1;
    unsigned int selected : 1;
    unsigned int highlighted : 1;
    unsigned int disabled : 1;
    int reference;
    LandHash * properties;
    struct LandWidgetThemeElement * element;
    int inner_w, inner_h;
    int outer_w, outer_h;
};
struct LandWidgetProperty {
    void(* destroy)(void * data);
    void * data;
};
#define LAND_WIDGET(widget) ((LandWidget *) land_widget_check(widget, LAND_WIDGET_ID_BASE, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_base_interface;
int land_widget_is(LandWidget const * self, int id);
void* land_widget_check(void const * ptr, int id, char const * file, int linenum);
char const* land_widget_info_string(LandWidget * w);
void land_widget_set_property(LandWidget * self, char const * property, void * data, void(* destroy)(void * data));
void land_widget_del_property(LandWidget * self, char const * property);
void* land_widget_get_property(LandWidget * self, char const * property);
void land_widget_remove_all_properties(LandWidget * self);
void land_widget_base_initialize(LandWidget * self, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_base_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_remove(LandWidget * self);
void land_widget_interfaces_destroy_all(void);
void land_widget_interface_register(LandWidgetInterface * vt);
LandWidgetInterface* land_widget_copy_interface(LandWidgetInterface * basevt, char const * name);
void land_widget_create_interface(LandWidget * widget, char const * name);
void land_widget_base_destroy(LandWidget * self);
void land_widget_unreference(LandWidget * self);
void land_widget_reference(LandWidget * self);
void land_widget_base_mouse_enter(LandWidget * self, LandWidget * focus);
void land_widget_base_mouse_leave(LandWidget * self, LandWidget * focus);
void land_widget_base_move(LandWidget * self, float dx, float dy);
void land_widget_move(LandWidget * self, float dx, float dy);
void land_widget_center(LandWidget * self);
void land_widget_base_size(LandWidget * self, float dx, float dy);
void land_widget_size(LandWidget * self, float dx, float dy);
void land_widget_resize(LandWidget * self, float dx, float dy);
void land_widget_set_size(LandWidget * self, float w, float h);
void land_widget_retain_mouse_focus(LandWidget * self);
void land_widget_refuse_mouse_focus(LandWidget * self);
void land_widget_request_keyboard_focus(LandWidget * self);
void land_widget_retain_keyboard_focus(LandWidget * self);
void land_widget_tick(LandWidget * self);
void land_widget_draw(LandWidget * self);
void land_widget_hide(LandWidget * self);
void land_widget_unhide(LandWidget * self);
void land_widget_outer(LandWidget * self, float * x, float * y, float * w, float * h);
void land_widget_inner(LandWidget * self, float * x, float * y, float * w, float * h);
void land_widget_inner_extents(LandWidget * self, float * l, float * t, float * r, float * b);
void land_widget_base_interface_initialize(void);
void land_widget_debug(LandWidget * w, int indentation);
#include <stdbool.h>
struct LandWidgetEdit {
    LandWidget super;
    char * text;
    int scroll;
    int cursor;
    int last_key;
    int last_char;
    bool align_right;
    void(* modified)(LandWidget * self);
};
#define LAND_WIDGET_EDIT(widget) ((LandWidgetEdit *) land_widget_check(widget, LAND_WIDGET_ID_EDIT, __FILE__, __LINE__))
void land_widget_edit_draw(LandWidget * base);
void land_widget_edit_mouse_tick(LandWidget * base);
void land_widget_edit_keyboard_tick(LandWidget * base);
void land_widget_edit_destroy(LandWidget * base);
void land_widget_edit_initialize(LandWidget * base, LandWidget * parent, char const * text, void(* modified)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_edit_new(LandWidget * parent, char const * text, void(* modified)(LandWidget * self), int x, int y, int w, int h);
void land_widget_edit_set_text(LandWidget * base, char const * text);
void land_widget_edit_align_right(LandWidget * base, bool yes);
char const* land_widget_edit_get_text(LandWidget * base);
void land_widget_edit_interface_initialize(void);
struct LandWidgetSizer {
    LandWidget super;
    int position;
    LandWidget * target;
    int dragged;
    int drag_x, drag_y;
};
#define LAND_WIDGET_SIZER(widget) ((LandWidgetSizer *) widget)
void land_widget_sizer_draw(LandWidget * widget);
void land_widget_sizer_mouse_tick(LandWidget * super);
LandWidget* land_widget_sizer_new(LandWidget * parent, int position, int x, int y, int w, int h);
void land_widget_sizer_set_target(LandWidget * self, LandWidget * target);
void land_widget_sizer_interface_initialize(void);
struct LandWidgetContainer {
    LandWidget super;
    LandList * children;
    LandWidget * mouse;
    LandWidget * keyboard;
};
#define LAND_WIDGET_CONTAINER(widget) ((LandWidgetContainer *) land_widget_check(widget, LAND_WIDGET_ID_CONTAINER, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_container_interface;
void land_widget_container_destroy(LandWidget * base);
void land_widget_container_mouse_enter(LandWidget * super);
void land_widget_container_mouse_leave(LandWidget * super);
void land_widget_container_keyboard_enter(LandWidget * super);
void land_widget_container_keyboard_leave(LandWidget * super);
LandListItem* land_widget_container_child_item(LandWidget * super, LandWidget * child);
void land_widget_container_to_top(LandWidget * super, LandWidget * child);
void land_widget_container_draw(LandWidget * base);
void land_widget_container_move(LandWidget * super, float dx, float dy);
void land_widget_container_size(LandWidget * super, float dx, float dy);
LandWidget* land_widget_container_get_descendant_at_pos(LandWidget * super, int x, int y);
LandWidget* land_widget_container_get_child_at_pos(LandWidget * super, int x, int y);
void land_widget_container_mouse_tick(LandWidget * super);
void land_widget_container_set_mouse_focus(LandWidget * super, LandWidget * mouse);
void land_widget_container_keyboard_tick(LandWidget * super);
void land_widget_container_tick(LandWidget * super);
void land_widget_container_add(LandWidget * super, LandWidget * add);
void land_widget_container_remove(LandWidget * base, LandWidget * rem);
void land_widget_container_remove_all(LandWidget * base);
void land_widget_container_update(LandWidget * widget);
LandWidget* land_widget_container_child(LandWidget * super);
int land_widget_container_is_empty(LandWidget * super);
void land_widget_container_initialize(LandWidget * super, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_container_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_container_interface_initialize(void);
struct LandCSG {
    LandArray * polygons;
    LandMemoryPool * pool;
    LandCSGAABB bbox;
};
struct LandCSGVertex {
    LandVector pos;
    LandVector normal;
    LandColor rgba;
};
struct LandCSGPlane {
    LandVector normal;
    LandFloat w;
};
struct LandCSGPolygon {
    LandArray * vertices;
    void * shared;
    LandCSGPlane plane;
    bool is_pooled;
};
struct LandCSGNode {
    LandCSGPlane plane;
    LandCSGNode * front;
    LandCSGNode * back;
    LandArray * polygons;
};
LandCSGVertex* land_csg_vertex_new(LandVector pos, LandVector normal);
void land_csg_vertex_destroy(LandCSGVertex * self);
LandCSGVertex* land_csg_vertex_new_pool(LandMemoryPool * pool);
LandCSGVertex* csg_vertex_clone(LandCSG * csg, LandCSGVertex * self, bool pool);
void land_csg_polygon_init(LandCSGPolygon * self, LandArray * vertices, void * shared);
LandCSGPolygon* land_csg_polygon_new(LandArray * vertices, void * shared);
void csg_plane_flip(LandCSGPlane * self);
void land_csg_polygon_destroy(LandCSGPolygon * self);
LandCSGPolygon* land_csg_polygon_clone(LandCSG * csg, LandCSGPolygon const * self);
void land_csg_transform(LandCSG * self, Land4x4Matrix matrix);
void land_csg_destroy(LandCSG * self);
void land_csg_triangles(LandCSG * self);
LandCSG* land_csg_new(void);
LandCSG* land_csg_new_from_polygons(LandArray * polygons);
LandCSG* land_csg_clone(LandCSG * self);
LandCSG* land_csg_union(LandCSG * csg_a, LandCSG * csg_b);
LandCSG* land_csg_subtract(LandCSG * self, LandCSG * csg);
LandCSG* land_csg_intersect(LandCSG * self, LandCSG * csg);
LandCSG* land_csg_inverse(LandCSG * self);
struct LandWidgetSlider {
    LandWidgetContainer super;
};
struct LandWidgetHandle {
    LandWidget super;
    bool vertical;
    float minval, maxval, value;
    void(* update)(LandWidget *);
    int dragged;
    int drag_x, drag_y;
};
#define LAND_WIDGET_SLIDER(widget) ((LandWidgetSlider *) land_widget_check(widget, LAND_WIDGET_ID_SLIDER, __FILE__, __LINE__))
#define LAND_WIDGET_HANDLE(widget) ((LandWidgetHandle *) land_widget_check(widget, LAND_WIDGET_ID_HANDLE, __FILE__, __LINE__))
LandWidget* land_widget_handle_new(LandWidget * parent, float minval, float maxval, bool vertical, void(* update)(LandWidget *), int x, int y, int w, int h);
LandWidget* land_widget_slider_new(LandWidget * parent, float minval, float maxval, bool vertical, void(* update)(LandWidget *), int x, int y, int w, int h);
void land_widget_slider_size(LandWidget * widget, float dx, float dy);
void land_widget_handle_update(LandWidget * super, int set);
void land_widget_handle_draw(LandWidget * super);
void land_widget_handle_mouse_tick(LandWidget * super);
void land_widget_slider_set_value(LandWidget * super, float value);
float land_widget_slider_get_value(LandWidget * super);
void land_widget_slider_interface_initialize(void);
void land_widget_handle_interface_initialize(void);
struct LandWidgetPanel {
    LandWidgetContainer super;
};
#define LAND_WIDGET_PANEL(widget) ((LandWidgetPanel *) land_widget_check(widget, LAND_WIDGET_ID_PANEL, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_panel_interface;
void land_widget_panel_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_panel_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_panel_add(LandWidget * base, LandWidget * add);
void land_widget_panel_interface_initialize(void);
struct LandWidgetBook {
    LandWidgetContainer super;
    LandList * pages;
};
#define LAND_WIDGET_BOOK(widget) ((LandWidgetBook *) land_widget_check(widget, LAND_WIDGET_ID_BOOK, __FILE__, __LINE__))
void land_widget_book_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
void land_widget_book_show_page(LandWidget * self, LandWidget * page);
void land_widget_book_remove_page(LandWidget * widget, LandWidget * rem);
void land_widget_book_add(LandWidget * widget, LandWidget * add);
void land_widget_book_pagename(LandWidget * widget, char const * name);
LandWidget* land_widget_book_new(LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_book_get_tabbar(LandWidget * widget);
void land_widget_book_hide_tabbar(LandWidget * widget);
void land_widget_book_interface_initialize(void);
LandWidget* land_widget_book_get_current_page(LandWidget * self);
int land_widget_book_get_page_n(LandWidget * self, LandWidget * page);
LandWidget* land_widget_book_get_last_page(LandWidget * self);
LandWidget* land_widget_book_get_nth_page(LandWidget * self, int n);
void land_widget_book_show_nth(LandWidget * self, int n);
struct LandWidgetVBox {
    LandWidgetContainer super;
    int columns;
    bool disable_updates;
};
#define LAND_WIDGET_VBOX(widget) ((LandWidgetVBox *) land_widget_check(widget, LAND_WIDGET_ID_VBOX, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_vbox_interface;
void land_widget_vbox_disable_updates(LandWidget * base);
void land_widget_vbox_do_update(LandWidget * base);
void land_widget_vbox_update(LandWidget * base);
void land_widget_vbox_add(LandWidget * base, LandWidget * add);
void land_widget_vbox_remove(LandWidget * base, LandWidget * rem);
void land_widget_vbox_set_columns(LandWidget * base, int n);
void land_widget_vbox_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_vbox_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_vbox_interface_initialize(void);
struct LandWidgetBoard {
    LandWidgetContainer super;
};
#define LAND_WIDGET_BOARD(widget) ((LandWidgetBoard *) land_widget_check(widget, LAND_WIDGET_ID_BOARD, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_board_interface;
void land_widget_board_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_board_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_board_add(LandWidget * base, LandWidget * add);
void land_widget_board_interface_initialize(void);
struct LandWidgetScrollbar {
    LandWidget super;
    LandWidget * target;
    int dragged;
    int drag_x, drag_y;
    bool vertical;
    void(* callback)(LandWidget * self, int set, int * _scramble_min, int * _scramble_max, int * range, int * pos);
};
#define LAND_WIDGET_SCROLLBAR(widget) ((LandWidgetScrollbar *) land_widget_check(widget, LAND_WIDGET_ID_SCROLLBAR, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_scrollbar_vertical_interface;
extern LandWidgetInterface * land_widget_scrollbar_horizontal_interface;
void land_widget_scrollbar_update(LandWidget * super, int set);
void land_widget_scrollbar_draw(LandWidget * self);
void land_widget_scrollbar_mouse_tick(LandWidget * super);
LandWidget* land_widget_scrollbar_new(LandWidget * parent, LandWidget * target, int vertical, int x, int y, int w, int h);
void land_widget_scrollbar_interface_initialize(void);
struct LandWidgetHBox {
    LandWidgetContainer super;
    int rows;
    bool disable_updates;
};
#define LAND_WIDGET_HBOX(widget) ((LandWidgetHBox *) land_widget_check(widget, LAND_WIDGET_ID_HBOX, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_hbox_interface;
void land_widget_hbox_disable_updates(LandWidget * base);
void land_widget_hbox_do_update(LandWidget * base);
void land_widget_hbox_update(LandWidget * base);
void land_widget_hbox_add(LandWidget * base, LandWidget * add);
void land_widget_hbox_remove(LandWidget * base, LandWidget * rem);
void land_widget_hbox_set_rows(LandWidget * base, int n);
void land_widget_hbox_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_hbox_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_hbox_interface_initialize(void);
struct LandWidgetScrolling {
    LandWidgetContainer super;
    unsigned int autohide;
    unsigned int scrollwheel;
};
#define LAND_WIDGET_SCROLLING(widget) ((LandWidgetScrolling *) land_widget_check(widget, LAND_WIDGET_ID_SCROLLING, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_scrolling_interface;
LandWidget* land_widget_scrolling_get_container(LandWidget * base);
LandWidget* land_widget_scrolling_get_vertical(LandWidget * base);
LandWidget* land_widget_scrolling_get_horizontal(LandWidget * base);
LandWidget* land_widget_scrolling_get_empty(LandWidget * base);
void land_widget_scrolling_move(LandWidget * widget, float dx, float dy);
void land_widget_scrolling_autohide(LandWidget * widget, int hori, int vert, int empty);
int land_widget_scrolling_autobars(LandWidget * widget);
void land_widget_scrolling_update(LandWidget * widget);
void land_widget_scrolling_size(LandWidget * widget, float dx, float dy);
void land_widget_scrolling_get_scroll_position(LandWidget * base, float * x, float * y);
void land_widget_scrolling_get_scroll_extents(LandWidget * base, float * x, float * y);
void land_widget_scrolling_get_view(LandWidget * base, float * l, float * t, float * r, float * b);
void land_widget_scrolling_scrollto(LandWidget * base, float x, float y);
void land_widget_scrolling_scroll(LandWidget * base, float dx, float dy);
void land_widget_scrolling_limit(LandWidget * base);
void land_widget_scrolling_mouse_tick(LandWidget * base);
void land_widget_scrolling_tick(LandWidget * super);
void land_widget_scrolling_add(LandWidget * widget, LandWidget * add);
LandWidget* land_widget_scrolling_get_child(LandWidget * base);
void land_widget_scrolling_remove_child(LandWidget * base);
void land_widget_scrolling_initialize(LandWidget * widget, LandWidget * parent, int x, int y, int w, int h);
void land_widget_scrolling_wheel(LandWidget * widget, int wheel);
LandWidget* land_widget_scrolling_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_scrolling_layout_changed(LandWidget * widget);
void land_widget_scrolling_layout_changing(LandWidget * widget);
void land_widget_scrolling_interface_initialize(void);
struct LandWidgetButton {
    LandWidget super;
    unsigned int xalign;
    unsigned int yalign;
    int xshift;
    int yshift;
    int multiline;
    LandAnimation * animation;
    LandImage * image;
    char * text;
    LandArray * lines;
    void(* clicked)(LandWidget * self);
    void(* rclicked)(LandWidget * self);
};
#define LAND_WIDGET_BUTTON(widget) ((LandWidgetButton *) land_widget_check(widget, LAND_WIDGET_ID_BUTTON, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_button_interface;
void land_widget_button_draw(LandWidget * base);
void land_widget_button_size(LandWidget * base, float dx, float dy);
void land_widget_button_mouse_tick(LandWidget * base);
void land_widget_button_initialize(LandWidget * base, LandWidget * parent, char const * text, LandImage * image, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_button_new(LandWidget * parent, char const * text, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_button_new_with_image(LandWidget * parent, char const * text, LandImage * image, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_button_new_with_animation(LandWidget * parent, char const * text, LandAnimation * animation, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_text_initialize(LandWidget * self, LandWidget * parent, char const * text, int multiline, int x, int y, int w, int h);
LandWidget* land_widget_text_new(LandWidget * parent, char const * text, int multiline, int x, int y, int w, int h);
void land_widget_button_replace_text(LandWidget * base, char const * text);
void land_widget_button_set_text(LandWidget * base, char const * text);
void land_widget_button_layout_text(LandWidget * base);
void land_widget_button_append_row(LandWidget * base, char const * text);
void land_widget_button_multiline(LandWidget * self, int style);
void land_widget_button_align(LandWidget * self, int x, int y);
void land_widget_button_shift(LandWidget * self, int x, int y);
void land_widget_button_interface_initialize(void);
void land_widget_button_destroy(LandWidget * base);
struct LandWidgetScrollingText {
    LandWidgetScrolling super;
};
extern LandWidgetInterface * land_widget_scrolling_text_interface;
void land_widget_scrolling_text_initialize(LandWidget * base, LandWidget * parent, char const * text, int wordwrap, int x, int y, int w, int h);
LandWidget* land_widget_scrolling_text_new(LandWidget * parent, char const * text, int wordwrap, int x, int y, int w, int h);
void land_widget_scrolling_text_size(LandWidget * widget, float dx, float dy);
void land_widget_scrolling_text_interface_initialize(void);
struct LandWidgetMenu {
    LandWidgetContainer super;
    LandWidget * menubutton;
    LandWidget * submenu;
};
struct LandWidgetMenuButton {
    LandWidgetButton super;
    LandWidget * menu;
    LandWidget * submenu;
    bool below;
};
struct LandWidgetMenuItem {
    LandWidgetButton super;
    void(* callback)(LandWidget * self);
    LandWidget * menu;
};
#define LAND_WIDGET_MENU(widget) ((LandWidgetMenu *) land_widget_check(widget, LAND_WIDGET_ID_MENU, __FILE__, __LINE__))
#define LAND_WIDGET_MENUBUTTON(widget) ((LandWidgetMenuButton *) land_widget_check(widget, LAND_WIDGET_ID_MENUBUTTON, __FILE__, __LINE__))
#define LAND_WIDGET_MENUITEM(widget) ((LandWidgetMenuItem *) land_widget_check(widget, LAND_WIDGET_ID_MENUITEM, __FILE__, __LINE__))
LandWidget* land_widget_menubar_new(LandWidget * parent, float x, float y, float w, float h);
LandWidget* land_widget_menu_new(LandWidget * parent, float x, float y, float w, float h);
void land_widget_menu_hide_sub(LandWidget * base);
void land_widget_menu_hide_complete(LandWidget * base);
LandWidget* land_widget_menubutton_new(LandWidget * parent, char const * name, LandWidget * submenu, float x, float y, float w, float h);
void land_widget_menubutton_destroy(LandWidget * self);
void land_widget_menu_add(LandWidget * base, LandWidget * item);
void land_widget_menubar_add(LandWidget * base, LandWidget * item);
LandWidget* land_widget_menuitem_new(LandWidget * parent, char const * name, void(* callback)(LandWidget * widget));
LandWidget* land_widget_submenuitem_new(LandWidget * parent, char const * name, LandWidget * submenu);
LandWidget* land_widget_menu_spacer_new(LandWidget * parent);
LandWidget* land_widget_menu_find(LandWidget * super, int n, char const * names []);
void land_widget_menu_mouse_enter(LandWidget * self);
void land_widget_menu_mouse_leave(LandWidget * self);
void land_widget_menubutton_mouse_enter(LandWidget * self);
void land_widget_menubutton_mouse_leave(LandWidget * self);
void land_widget_menubar_mouse_leave(LandWidget * self);
void land_widget_menu_mouse_tick(LandWidget * self);
void land_widget_menu_interface_initialize(void);
void land_widget_menubutton_interface_initialize(void);
struct LandWidgetCheckBox {
    LandWidgetContainer super;
    char * checkbox_selected;
    char * checkbox_unselected;
};
extern LandWidgetInterface * land_widget_checkbox_interface;
extern LandWidgetInterface * land_widget_checkbox_button_interface;
extern LandWidgetInterface * land_widget_checkbox_description_interface;
#define LAND_WIDGET_CHECKBOX(widget) ((LandWidgetCheckBox *) land_widget_check(widget, LAND_WIDGET_ID_CHECKBOX, __FILE__, __LINE__))
void land_widget_checkbox_initialize(LandWidget * base, LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, int x, int y, int w, int h);
LandWidget* land_widget_checkbox_new(LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, int x, int y, int w, int h);
bool land_widget_checkbox_is_checked(LandWidget * self);
void land_widget_checkbox_interface_initialize(void);
void land_widget_checkbox_destroy(LandWidget * base);
struct LandWidgetList {
    LandWidgetVBox super;
    bool multi_select;
};
#define LAND_WIDGET_LIST(widget) ((LandWidgetList *) land_widget_check(widget, LAND_WIDGET_ID_LIST, __FILE__, __LINE__))
void land_widget_list_disable_updates(LandWidget * base);
void land_widget_list_update(LandWidget * base);
void land_widget_list_set_columns(LandWidget * base, int n);
void land_widget_list_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_list_new(LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_listitem_new(LandWidget * parent, char const * text, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
void land_widget_list_interface_initialize(void);
void land_widget_listitem_interface_initialize(void);
LandArray* land_widget_list_get_selected_items(LandWidget * self);
void land_widget_list_clear_selection(LandWidget * self);
struct LandWidgetSpin {
    LandWidgetHBox super;
    double _scramble_min, _scramble_max, step;
    bool wrap;
};
struct LandWidgetSpinButton {
    LandWidgetButton button;
    LandWidget * spin;
    double initial_delay;
    double rate;
    double dir;
    double seconds;
    double delay;
    int count;
    double step;
};
#define LAND_WIDGET_SPIN(widget) ((LandWidgetSpin *) land_widget_check(widget, LAND_WIDGET_ID_SPIN, __FILE__, __LINE__))
#define LAND_WIDGET_SPINBUTTON(widget) ((LandWidgetSpinButton *) land_widget_check(widget, LAND_WIDGET_ID_SPINBUTTON, __FILE__, __LINE__))
LandWidget* land_widget_spin_get_edit(LandWidget * spin);
LandWidget* land_widget_spinbutton_new(LandWidget * parent, LandImage * image, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
void land_widget_spin_initialize(LandWidget * base, LandWidget * parent, float val, float _scramble_min, float _scramble_max, float step, void(* modified)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_spin_new(LandWidget * parent, float val, float _scramble_min, float _scramble_max, float step, void(* modified)(LandWidget * self), int x, int y, int w, int h);
void land_widget_spin_set_value(LandWidget * base, float val);
void land_widget_spin_set_minimum_text(LandWidget * base, char const * text);
float land_widget_spin_get_value(LandWidget * base);
void land_widget_spinbutton_mouse_tick(LandWidget * base);
void land_widget_spinbutton_interface_initialize(void);
void land_widget_spin_interface_initialize(void);
struct LandWidgetMover {
    LandWidgetButton super;
    LandWidget * target;
    int dragged;
};
#define LAND_WIDGET_MOVER(widget) ((LandWidgetMover *) widget)
void land_widget_mover_mouse_tick(LandWidget * super);
LandWidget* land_widget_mover_new(LandWidget * parent, char const * text, int x, int y, int w, int h);
void land_widget_mover_set_target(LandWidget * self, LandWidget * target);
void land_widget_mover_interface_initialize(void);
#endif

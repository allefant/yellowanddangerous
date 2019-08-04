#define ALLEGRO_UNSTABLE
#ifndef _LAND_
#define _LAND_
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_acodec.h>
#if defined ( ANDROID )
#include <allegro5/allegro_android.h>
#endif
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#if ! defined ( ANDROID )
#include <allegro5/allegro_native_dialog.h>
#endif
#include <allegro5/allegro_opengl.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#if ! defined ( WINDOWS )
#include <arpa/inet.h>
#endif
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#if ! defined ( WINDOWS )
#include <netdb.h>
#endif
#include <setjmp.h>
#if ! defined ( WINDOWS )
#include <signal.h>
#endif
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if ! defined ( WINDOWS )
#include <sys/ioctl.h>
#endif
#if ! defined ( WINDOWS )
#include <sys/socket.h>
#endif
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#if defined WINDOWS
#include <ws2tcpip.h>
#endif
#if defined LAND_USE_EXTERNAL_YAML
#include <yaml.h>
#endif
#if ! defined ( LAND_NO_COMPRESS )
#include <zlib.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include <math.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h>
typedef struct LandBuffer LandBuffer;
typedef struct LandBufferAsFile LandBufferAsFile;
typedef struct LandHashEntry LandHashEntry;
typedef struct LandHash LandHash;
typedef struct LandHashIterator LandHashIterator;
typedef struct LandListItem LandListItem;
typedef struct LandList LandList;
typedef struct LandListIterator LandListIterator;
typedef float float32_t;
typedef double LandFloat;
typedef char const*str;
typedef struct LandGLSLShader LandGLSLShader;
typedef struct LandFile LandFile;
typedef struct LandPixelMask LandPixelMask;
typedef struct SinglePixelMask SinglePixelMask;
typedef struct LandRunner LandRunner;
typedef struct LandShader LandShader;
typedef struct LandTriangles LandTriangles;
typedef struct LandFont LandFont;
typedef struct LandFontState LandFontState;
typedef struct LandPlasma LandPlasma;
typedef struct LandRandom LandRandom;
typedef char const*str;
typedef struct LandImage LandImage;
typedef struct LandSubImage LandSubImage;
typedef void(VoidFunction)(void);
typedef struct LandPerlin LandPerlin;
typedef enum LandPerlinLerp LandPerlinLerp;
typedef struct LandSound LandSound;
typedef struct LandStream LandStream;
typedef struct LandView LandView;
typedef struct LandOctree LandOctree;
typedef enum LandNoiseType LandNoiseType;
typedef struct LandNoiseI2 LandNoiseI2;
typedef struct LandNoiseF2 LandNoiseF2;
typedef struct LandNoise LandNoise;
typedef enum LandYamlEntryType LandYamlEntryType;
typedef struct LandYamlEntry LandYamlEntry;
typedef struct LandYaml LandYaml;
typedef struct LandThread LandThread;
typedef struct LandLock LandLock;
typedef struct LandParameters LandParameters;
typedef struct LandMemoryPool LandMemoryPool;
typedef struct LandDataEntry LandDataEntry;
typedef struct LandDataFile LandDataFile;
typedef struct LandWidgetThemeElement LandWidgetThemeElement;
typedef struct LandWidgetTheme LandWidgetTheme;
typedef struct LandMemBlockInfo LandMemBlockInfo;
typedef enum LandKeyboardKeys LandKeyboardKeys;
typedef struct LandProtobuf LandProtobuf;
typedef struct LandVertexWithNormal LandVertexWithNormal;
typedef struct LandVertexAllegro LandVertexAllegro;
typedef struct LandCSGAABB LandCSGAABB;
typedef struct LandLayoutBox LandLayoutBox;
typedef struct LandColor LandColor;
typedef struct LandShaderPlatform LandShaderPlatform;
typedef struct LandLayer LandLayer;
typedef struct LandAnimation LandAnimation;
typedef struct LandGridInterface LandGridInterface;
typedef struct LandGrid LandGrid;
typedef struct LandAtlas LandAtlas;
typedef struct LandVoronoi LandVoronoi;
typedef struct LandImagePlatform LandImagePlatform;
typedef enum LandYamlFlags LandYamlFlags;
typedef struct YamlParser YamlParser;
typedef struct LandArray LandArray;
typedef struct LandArrayIterator LandArrayIterator;
typedef struct LandIniEntry LandIniEntry;
typedef struct LandIniSection LandIniSection;
typedef struct LandIniFile LandIniFile;
typedef enum LandNetState LandNetState;
typedef struct LandNet LandNet;
typedef struct LandDisplay LandDisplay;
typedef struct LandSpriteType LandSpriteType;
typedef struct LandSpriteTypeWithImage LandSpriteTypeWithImage;
typedef struct LandSpriteTypeImage LandSpriteTypeImage;
typedef struct LandSpriteTypeAnimation LandSpriteTypeAnimation;
typedef struct LandSprite LandSprite;
typedef struct LandSpriteWithImage LandSpriteWithImage;
typedef struct LandSpriteAnimated LandSpriteAnimated;
typedef struct LandSpritesGrid LandSpritesGrid;
typedef struct LandMap LandMap;
typedef struct LandVector LandVector;
typedef struct Land4x4Matrix Land4x4Matrix;
typedef struct LandQuaternion LandQuaternion;
typedef struct LandCSG LandCSG;
typedef struct LandCSGVertex LandCSGVertex;
typedef struct LandCSGPlane LandCSGPlane;
typedef struct LandCSGPolygon LandCSGPolygon;
typedef struct LandCSGNode LandCSGNode;
typedef struct LandGridIsometric LandGridIsometric;
typedef struct LandWidgetInterface LandWidgetInterface;
typedef struct LandWidget LandWidget;
typedef struct LandWidgetProperty LandWidgetProperty;
typedef struct LandQueue LandQueue;
typedef struct LandWidgetScrollbar LandWidgetScrollbar;
typedef struct LandTileGrid LandTileGrid;
typedef struct LandWidgetButton LandWidgetButton;
typedef struct LandDisplayPlatform LandDisplayPlatform;
typedef struct LandWidgetContainer LandWidgetContainer;
typedef struct LandWidgetMover LandWidgetMover;
typedef struct LandWidgetEdit LandWidgetEdit;
typedef struct LandWidgetPanel LandWidgetPanel;
typedef struct LandWidgetBoard LandWidgetBoard;
typedef struct LandWidgetVBox LandWidgetVBox;
typedef struct LandWidgetSizer LandWidgetSizer;
typedef struct LandWidgetScrolling LandWidgetScrolling;
typedef struct LandWidgetBook LandWidgetBook;
typedef struct LandWidgetSlider LandWidgetSlider;
typedef struct LandWidgetHandle LandWidgetHandle;
typedef struct LandWidgetScrollingText LandWidgetScrollingText;
typedef struct LandWidgetHBox LandWidgetHBox;
typedef struct LandWidgetMenu LandWidgetMenu;
typedef struct LandWidgetMenuButton LandWidgetMenuButton;
typedef struct LandWidgetMenuItem LandWidgetMenuItem;
typedef struct LandWidgetCheckBox LandWidgetCheckBox;
typedef struct LandWidgetList LandWidgetList;
typedef struct LandWidgetSpin LandWidgetSpin;
typedef struct LandWidgetSpinButton LandWidgetSpinButton;
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
void land_buffer_grow(LandBuffer * self, int n);
void land_buffer_insert(LandBuffer * self, int pos, char const * buffer, int n);
void land_buffer_move(LandBuffer * self, int from_pos, int to_pos, int n);
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
bool land_buffer_empty(LandBuffer * self);
LandArray* land_buffer_split(LandBuffer const * self, str delim);
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
int land_hash_count(LandHash * self);
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
LandFloat land_constrain(LandFloat * v, LandFloat v_min, LandFloat v_max);
float land_constrainf(float v, float v_min, float v_max);
int land_mod(int x, int d);
int land_div(int x, int d);
struct LandGLSLShader {
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program_object;
    char * name;
};
LandGLSLShader* land_glsl_shader_new(char const * name, char const * vertex_glsl, char const * fragment_glsl);
LandGLSLShader* land_glsl_shader_new_empty(char const * name);
void land_glsl_shader_set_shaders(LandGLSLShader * self, char const * vertex_glsl, char const * fragment_glsl);
void land_glsl_shader_destroy(LandGLSLShader * self);
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
void land_file_putc(LandFile * self, int x);
void land_file_ungetc(LandFile * self, int c);
bool land_file_eof(LandFile * self);
void land_file_skip(LandFile * self, int n);
uint32_t land_file_get32le(LandFile * self);
void land_file_put32le(LandFile * self, uint32_t x);
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
int64_t land_file_time(char const * path);
char* land_user_data_path(char const * app, char const * path);
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
struct LandShader {
    char * name;
};
extern char const * land_sample_vertex_shader;
extern char const * land_sample_fragment_shader;
LandShader* land_shader_new(char const * name, char const * vertex_glsl, char const * fragment_glsl);
void land_shader_destroy(LandShader * self);
struct LandTriangles {
    int n;
    int size;
    bool has_normals;
    LandBuffer * buf;
    LandImage * image;
    void * platform;
};
LandTriangles* land_triangles_new(void);
LandTriangles* land_triangles_new_with_normals(void);
void land_triangles_add_csg(LandTriangles * self, LandCSG * csg);
void land_triangles_destroy(LandTriangles * self);
void land_triangles_clear(LandTriangles * self);
void land_triangles_texture(LandTriangles * self, LandImage * texture);
void land_add_vertex(LandTriangles * self, float x, float y, float z, float u, float v, float r, float g, float b, float a);
void land_set_vertex_normal(LandTriangles * self, float x, float y, float z);
void land_set_vertex_index(LandTriangles * self, float i);
void land_duplicate_vertex(LandTriangles * self, int i);
void land_update_vertex(LandTriangles * self, int i, float x, float y, float z, float u, float v, float r, float g, float b, float a);
void land_triangles_draw(LandTriangles * self);
void* land_triangles_get_vertex(LandTriangles * self, int i);
float land_norm2d(float x, float y);
float land_dot2d(float ax, float ay, float bx, float by);
float land_cross2d(float ax, float ay, float bx, float by);
void land_ortho2d(float ax, float ay, float * bx, float * by);
bool land_line_line_collision2d(LandFloat l1x1, LandFloat l1y1, LandFloat l1x2, LandFloat l1y2, LandFloat l2x1, LandFloat l2y1, LandFloat l2x2, LandFloat l2y2);
bool circle_circle_collision2d(LandFloat c1x1, LandFloat c1y1, LandFloat c1r, LandFloat c2x1, LandFloat c2y1, LandFloat c2r);
bool land_line_circle_collision2d(LandFloat lx1, LandFloat ly1, LandFloat lx2, LandFloat ly2, LandFloat cx1, LandFloat cy1, LandFloat cr);
void land_log_overwrite(char const * name);
void land_log_set(char const * name);
void land_log_del(void);
void land_log_new(char const * base, int unique);
void land_log_message_nostamp(char const * format, ...);
void land_log_message(char const * format, ...);
struct LandFont {
    int size;
    double xscaling;
    double yscaling;
    int flags;
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
    LandAlignRight=1,
    LandAlignCenter=2,
    LandAlignAdjust=4,
    LandAlignMiddle=8,
    LandAlignBottom=16
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
void land_print_middle(char const * text, ...);
void land_write(char const * text, ...);
void land_write_right(char const * text, ...);
void land_write_center(char const * text, ...);
void land_write_middle(char const * text, ...);
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
void land_print_multiline(char const * text, ...);
struct LandPlasma {
    int w, h;
    float * cache;
    float power_modifier;
    float amplitude;
    LandRandom * rndgen;
};
LandPlasma* land_plasma_new(LandRandom * rndgen, int w, int h, float power_modifier, float amplitude);
void land_plasma_generate(LandPlasma * self);
void land_plasma_del(LandPlasma * self);
float land_plasma_at(LandPlasma * self, int x, int y);
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
double land_random_f(LandRandom * r, double rmin, double rmax);
void land_shuffle(int * a, int n);
#define land_method(_returntype, _name, _params) _returntype(* _name) _params
#define land_call_method(self, method, params) if(self->vt->method) self->vt->method params
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
void land_appendv(char * (* s), str format, va_list args);
void land_append(char * (* s), str format, ...);
void land_concatenate_with_separator(char * (* s), char const * cat, char const * sep);
void land_prepend(char * (* s), char const * pre);
int land_replace(char * (* s), int off, char const * wat, char const * wit);
bool land_contains(str hay, str needle);
int land_find(str hay, str needle);
int land_find_from_back(str hay, str needle);
int land_replace_all(char * (* s), char const * wat, char const * wit);
char* land_lowercase_copy(str s);
void land_shorten(char * (* s), int start, int end);
char* land_substring(char const * s, int a, int b);
void land_strip(char * (* s));
LandArray* land_filelist(char const * dir, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data);
LandArray* land_split_path_name_ext(char const * filename);
LandArray* land_split(char const * text, str c);
bool land_split_two(str text, str sep, char * (* a), char * (* b));
LandArray* land_split_lines(char const * text);
LandColor platform_color_hsv(float hue, float sat, float val);
LandColor platform_color_name(char const * name);
void platform_popup(str title, str text);
#define LAND_SUBIMAGE 1
#define LAND_LOADED 2
#define LAND_IMAGE_WAS_CENTERED 4
#define LAND_IMAGE_MEMORY 8
#define LAND_AUTOCROP 16
#define LAND_FAILED 32
#define LAND_IMAGE_CENTER 64
#define LAND_IMAGE_DEPTH 128
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
bool land_image_was_loaded(LandImage * self);
LandImage* land_image_load_memory(char const * filename);
LandImage* land_image_new_deferred(char const * filename);
bool land_image_load_on_demand(LandImage * self);
bool land_image_exists(LandImage * self);
LandImage* land_image_memory_new(int w, int h);
LandImage* land_image_new_flags(int w, int h, int flags);
LandImage* land_image_new(int w, int h);
LandImage* land_image_create(int w, int h);
void land_image_del(LandImage * self);
void land_image_destroy(LandImage * self);
void land_image_crop(LandImage * self, int x, int y, int w, int h);
void land_image_auto_crop(LandImage * self);
#define LandImageFit 1
void land_image_resize(LandImage * self, int new_w, int new_h, int flags);
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
void land_image_write_callback(LandImage * self, void(* cb)(int x, int y, unsigned char * rgba, void * user), void * user);
void land_image_read_write_callback(LandImage * self, void(* cb)(int x, int y, unsigned char * rgba, void * user), void * user);
void land_image_read_backup_write_callback(LandImage * self, void(* cb)(int x, int y, int w, int h, unsigned char * rgba_in, unsigned char * rgba_out, void * user), void * user);
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
#define y1 libc_y1
#define yn libc_yn
#undef y1
#undef yn
char const* land_version(void);
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
void land_callbacks(VoidFunction * init, VoidFunction * tick, VoidFunction * draw, VoidFunction * done);
extern int land_argc;
extern char * (* land_argv);
extern LandRunner * shortcut_runner;
struct LandPerlin {
    LandNoiseF2 * xy;
    int w;
    int h;
    float(* lerp)(float a, float b, float p);
};
enum LandPerlinLerp {
    LandPerlinLerpNone,
    LandPerlinLerpLinear,
    LandPerlinLerpCosine,
    LandPerlinLerpSmoothStep,
    LandPerlinLerpSmootherStep,
    LandPerlinLerpSmoothestStep
};
LandPerlin* land_perlin_create(LandRandom * seed, int w, int h);
void land_perlin_set_lerp_callback(LandPerlin * self, float(* lerp)(float a, float b, float p));
void land_perlin_set_lerp(LandPerlin * self, LandPerlinLerp lerp);
void land_perlin_destroy(LandPerlin * self);
float land_perlin_at(LandPerlin * self, float x, float y);
void land_perlin_displace(LandPerlin * self, float x, float y, float * xd, float * yd);
struct LandSound {
    char * filename;
    char * name;
};
struct LandStream {
    int samples;
    int sample_size;
    int fragments;
    float frequency;
    char * filename;
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
void land_stream_music_once(LandStream * self, char const * filename);
void land_stream_volume(LandStream * self, float volume);
bool land_stream_is_playing(LandStream * self);
void land_stream_set_playing(LandStream * self, bool onoff);
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
void land_world_to_view(LandView * self, float wx, float wy, float * vx, float * vy);
struct LandOctree {
    LandArray * (* data);
    int xs, ys, zs;
    int xo, yo, zo;
    int cx, cy, cz;
};
LandOctree* land_octree_new(int xs, int ys, int zs, int xo, int yo, int zo, int cx, int cy, int cz);
LandOctree* land_octree_new_from_aabb(LandCSGAABB * aabb, int count);
void land_octree_del(LandOctree * self);
int between(int x, int a, int b);
void land_octree_insert(LandOctree * self, LandFloat x, LandFloat y, LandFloat z, void * data);
LandArray* land_octree_get(LandOctree * self, LandFloat x, LandFloat y, LandFloat z);
void land_octree_callback_in_cube(LandOctree * self, LandFloat x1, LandFloat y1, LandFloat z1, LandFloat x2, LandFloat y2, LandFloat z2, void(* callback)(LandArray * array, void * data), void * data);
enum LandNoiseType {
    LandNoiseNone,
    LandNoiseWhite,
    LandNoisePerlin,
    LandNoiseVoronoi,
    LandNoisePlasma,
    LandNoiseWaves,
    LandNoiseValue
};
struct LandNoiseI2 {
    int x, y;
};
struct LandNoiseF2 {
    float x, y;
};
struct LandNoise {
    LandNoiseType t;
    LandArray * noise;
    int w, h;
    int count;
    int levels;
    LandRandom * seed;
    bool use_external_seed;
    float randomness;
    float power_modifier;
    float amplitude;
    int lerp;
    bool warp;
    float warp_x, warp_y, warp_sx, warp_sy;
    bool blur;
    float blur_size;
    float minval, maxval;
    bool wrap;
    float z_scale, z_offset, z_ease;
    float * cache;
};
LandNoise* land_noise_new(LandNoiseType t, int seed);
void land_noise_set_random(LandNoise * self, LandRandom * random);
void land_noise_set_size(LandNoise * self, int w, int h);
void land_noise_set_lerp(LandNoise * self, LandPerlinLerp lerp);
void land_noise_set_count(LandNoise * self, int n);
void land_noise_set_levels(LandNoise * self, int n);
void land_noise_set_amplitude(LandNoise * self, float amplitude);
void land_noise_set_power_modifier(LandNoise * self, float power_modifier);
void land_noise_set_randomness(LandNoise * self, float randomness);
void land_noise_set_minmax(LandNoise * self, float minval, float maxval);
void land_noise_set_warp(LandNoise * self, LandNoise * warp, float x, float y, float sx, float sy);
void land_noise_set_blur(LandNoise * self, LandNoise * blur, int size);
void land_noise_set_wrap(LandNoise * self, bool wrap);
void land_noise_prepare(LandNoise * self);
void land_noise_callback(LandNoise * self, float(* cb)(float x));
void land_noise_destroy(LandNoise * self);
float land_noise_at(LandNoise * self, float x, float y);
float land_noise_at_raw(LandNoise * self, float x, float y);
void land_noise_z_transform(LandNoise * self, float scale, float offset);
void land_noise_z_ease(LandNoise * self, float x);
enum LandYamlEntryType {
    YamlScalar,
    YamlSequence,
    YamlMapping
};
struct LandYamlEntry {
    int type;
    char * scalar;
    LandArray * sequence;
    LandHash * mapping;
};
struct LandYaml {
    char * filename;
    LandYamlEntry * root;
    char * key;
    LandYamlEntry * parent;
    LandArray * parents;
    bool expect_key;
};
LandHash* land_yaml_get_mapping(LandYamlEntry * self);
LandHash* land_yaml_get_if_mapping(LandYamlEntry * self);
LandArray* land_yaml_get_sequence(LandYamlEntry * self);
LandArray* land_yaml_get_if_sequence(LandYamlEntry * self);
char const* land_yaml_get_scalar(LandYamlEntry * self);
char const* land_yaml_get_if_scalar(LandYamlEntry * self);
int land_yaml_get_scalar_int(LandYamlEntry * self);
double land_yaml_get_scalar_double(LandYamlEntry * self);
char const* land_yaml_get_scalar_nth(LandArray * s, int i);
double land_yaml_get_scalar_nth_double(LandArray * s, int i);
LandYamlEntry* land_yaml_get_entry(LandYamlEntry * self, char const * name);
char const* land_yaml_get_entry_scalar(LandYamlEntry * self, char const * name);
int land_yaml_get_entry_int(LandYamlEntry * self, char const * name);
double land_yaml_get_entry_double(LandYamlEntry * self, char const * name);
LandYamlEntry* land_yaml_get_nth(LandYamlEntry * self, int i);
int land_yaml_get_nth_int(LandYamlEntry * self, int i);
double land_yaml_get_nth_double(LandYamlEntry * self, int i);
char const* land_yaml_get_nth_scalar(LandYamlEntry * self, int i);
LandArray* land_yaml_get_entry_sequence(LandYamlEntry * self, char const * name);
LandYaml* land_yaml_new(char const * filename);
void land_yaml_add_mapping(LandYaml * yaml);
void land_yaml_done(LandYaml * yaml);
void land_yaml_add_sequence(LandYaml * yaml);
void land_yaml_add_scalar(LandYaml * yaml, char const * v);
void land_yaml_add_scalar_v(LandYaml * yaml, char const * v, va_list args);
void land_yaml_add_scalar_f(LandYaml * yaml, char const * v, ...);
void land_yaml_destroy(LandYaml * self);
void land_yaml_dump(LandYaml * self);
void land_yaml_rename(LandYaml * self, str filename);
void* platform_fopen(char const * filename, char const * mode);
void platform_fclose(void * f);
int platform_fread(void * f, char * buffer, int bytes);
int platform_fwrite(void * f, char const * buffer, int bytes);
void platform_ungetc(void * f, int c);
int platform_fgetc(void * f);
void platform_fputc(void * f, int c);
bool platform_feof(void * f);
void platform_fseek(void * f, int n);
LandArray* platform_filelist(char const * dir, int(* filter)(char const *, bool is_dir, void * data), int flags, void * data);
bool platform_is_dir(char const * path);
bool platform_file_exists(char const * path);
char* platform_get_save_file(char const * appname, char const * name);
char* platform_get_app_settings_file(char const * appname);
char* platform_get_app_data_file(char const * appname, char const * filename);
char* platform_get_current_directory(void);
char* platform_get_data_path(void);
bool platform_remove_file(char const * path);
void land_android_apk_filesystem(bool onoff);
int64_t platform_file_time(char const * path);
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
struct LandParameters {
    int w, h;
    int fps;
    int flags;
    int skip;
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
void land_skip_render(int skip);
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
void land_mainloop_prepare(void);
void land_mainloop(void);
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
struct LandDataEntry {
    char * name;
    int offset;
    int size;
};
struct LandDataFile {
    LandArray * entries;
    FILE * file;
};
extern LandDataFile * land_datafile;
LandDataFile* land_read_datafile(FILE * file);
LandDataFile* land_open_datafile(char const * filename);
LandDataFile* land_open_appended_datafile(char const * filename, char const * marker);
void* land_datafile_read_entry(LandDataFile * self, char const * filename, int * size);
int land_datafile_for_each_entry(LandDataFile * self, char const * pattern, int(* callback)(const char * filename, int attrib, void * param), void * param);
void land_set_datafile(LandDataFile * datafile);
LandDataFile* land_get_datafile(void);
void a5_joystick_create_mapping(void);
int a5_joystick_axis_to_land(ALLEGRO_JOYSTICK * allegro, int s, int a);
int a5_joystick_button_to_land(ALLEGRO_JOYSTICK * allegro, int b);
int platform_joystick_axis_count(void);
int platform_joystick_button_count(void);
str platform_joystick_button_name(int b);
str platform_joystick_axis_name(int a);
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
void land_widget_theme_change_font(LandWidgetTheme * theme);
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
char* land_strdup_memlog(char const * s, char const * f, int l);
void land_free_memlog(void * ptr, char const * f, int l);
void* land_malloc(int size);
void* land_calloc(int size);
void* land_realloc(void * ptr, int size);
char* land_strdup(char const * s);
void land_free(void * ptr);
#ifdef LAND_MEMLOG
#define land_malloc(x) land_malloc_memlog(x, __FILE__, __LINE__)
#define land_calloc(x) land_calloc_memlog(x, __FILE__, __LINE__)
#define land_free(x) land_free_memlog(x, __FILE__, __LINE__)
#define land_realloc(x, y) land_realloc_memlog(x, y, __FILE__, __LINE__)
#define land_strdup(x) land_strdup_memlog(x, __FILE__, __LINE__)
#endif
void platform_font_init(void);
void platform_font_exit(void);
LandFont* platform_font_load(char const * filename, float size);
LandFont* platform_font_from_image(LandImage * image, int n_ranges, int * ranges);
void platform_font_print(LandFontState * lfs, char const * str, int alignment);
LandFont* platform_font_new(void);
void platform_font_destroy(LandFont * super);
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
    LandKeysCount=228,
    LandKeyF5=LandKeyFunction+5
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
int land_key_get_pressed(int first);
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
struct LandVertexWithNormal {
    float x, y, z;
    float nx, ny, nz;
    float r, g, b, a;
    float i;
};
struct LandVertexAllegro {
    float x, y, z;
    float u, v;
    float r, g, b, a;
};
void platform_update_vertex_with_normals(LandTriangles * t, int i, float x, float y, float z, float tu, float tv, float r, float g, float b, float a);
void platform_update_vertex_allegro(LandTriangles * t, int i, float x, float y, float z, float tu, float tv, float r, float g, float b, float a);
void platform_update_vertex(LandTriangles * t, int i, float x, float y, float z, float tu, float tv, float r, float g, float b, float a);
void platform_set_vertex_normal(LandTriangles * t, float x, float y, float z);
void platform_set_vertex_index(LandTriangles * t, float i);
void platform_triangles_init(LandTriangles * self);
void platform_triangles_deinit(LandTriangles * self);
void platform_triangles_draw(LandTriangles * t);
struct LandCSGAABB {
    double x1, y1, z1, x2, y2, z2;
};
LandCSGAABB land_csg_aabb_infinite(void);
LandCSGAABB land_csg_aabb_empty(void);
void land_csg_aabb_update(LandCSGAABB * self, LandArray * polygons);
LandCSGAABB land_csg_aabb_intersect(LandCSGAABB a, LandCSGAABB b);
#define GUL_SHRINK_X 1
#define GUL_CENTER_X 2
#define GUL_RIGHT 4
#define GUL_EQUAL_X 8
#define GUL_SHRINK_Y (16)
#define GUL_CENTER_Y (32)
#define GUL_BOTTOM (64)
#define GUL_EQUAL_Y (128)
#define GUL_HIDDEN (256)
#define GUL_NO_LAYOUT (512)
#define GUL_STEADFAST (1024)
#define GUL_RESIZE (2048)
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
void land_internal_land_gul_box_initialize(LandLayoutBox * self);
void land_internal_land_gul_box_deinitialize(LandLayoutBox * self);
void land_internal_gul_layout_updated(LandWidget * self);
void land_internal_gul_layout_updated_during_layout(LandWidget * self);
struct LandColor {
    float r, g, b, a;
};
LandColor land_color_hsv(float hue, float sat, float val);
LandColor land_color_rgba(float r, float g, float b, float a);
double srgba_gamma_to_linear(double x);
double srgba_linear_to_gamma(double x);
LandColor land_color_xyz(double x, double y, double z);
void land_color_to_xyz(LandColor c, double * x, double * y, double * z);
void land_color_to_cielab(LandColor c, double * L, double * a, double * b);
LandColor land_color_cielab(double L, double a, double b);
LandColor land_color_lch(double l, double c, double h);
LandColor land_color_xyy(double x, double y, double Y);
void land_color_to_xyy(LandColor c, double * x, double * y, double * Y);
double land_color_distance_cie94(LandColor color, LandColor other);
double land_color_distance_cie94_lab(double l1, double a1, double b1, double l2, double a2, double b2);
double land_color_distance_ciede2000(LandColor color, LandColor other);
double land_color_distance_ciede2000_lab(double l1, double a1, double b1, double l2, double a2, double b2);
void test_ciede2000(void);
LandColor land_color_premul(float r, float g, float b, float a);
LandColor land_color_name(char const * name);
void land_color_to_html(LandColor c, char html [8]);
LandColor land_color_int(int i);
int land_color_to_int(LandColor c);
LandColor land_color_lerp(LandColor a, LandColor b, float t);
char const* land_color_bash(char const * x);
extern int(* land_exception_handler)(char const * str);
int land_default_exception_handler(char const * str);
void land_exception_handler_init(void);
void land_exception_handler_set(int(* handler)(char const * str));
void land_exception(char const * format, ...);
void land_popup(str title, str message);
struct LandShaderPlatform {
    LandShader super;
    ALLEGRO_SHADER * a5;
};
LandShader* platform_shader_new(char const * name, char const * vertex_glsl, char const * fragment_glsl);
void platform_shader_destroy(LandShader * super);
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
void land_animation_mirror(LandAnimation * self);
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
extern LandWidgetInterface * land_widget_box_interface;
void land_widget_box_draw(LandWidget * self);
LandWidget* land_widget_box_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_box_interface_initialize(void);
struct LandAtlas {
    LandArray * sheets;
    LandHash * sprites;
    char * filename;
};
LandAtlas* land_atlas_new(char const * filename);
void land_atlas_destroy(LandAtlas * self);
void land_atlas_load_all(LandAtlas * self);
LandImage* land_atlas_image_create(LandAtlas * self, char const * filename);
struct LandVoronoi {
    int * map;
    float * distance;
    int n;
    LandNoiseI2 * xy;
    int w;
    int h;
    float max_distance;
};
LandVoronoi* land_voronoi_new(LandRandom * seed, int w, int h, int n);
LandVoronoi* land_voronoi_create(LandRandom * seed, int w, int h, int n, float randomness);
void land_voronoi_calculate_distance(LandVoronoi * self);
void land_voronoi_distort_with_perlin(LandVoronoi * self, LandRandom * seed, float randomness);
void land_voronoi_destroy(LandVoronoi * self);
float land_voronoi_at(LandVoronoi * self, int x, int y);
struct LandImagePlatform {
    LandImage super;
    ALLEGRO_BITMAP * a5;
};
LandImage* platform_new_image(void);
void platform_del_image(LandImage * super);
void platform_image_empty(LandImage * super);
LandImage* platform_image_load(char const * filename, bool mem);
bool platform_image_exists(LandImage * super);
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
void platform_image_merge(LandImage * super, LandImage * replacement_image);
#define LandJoystickButtonsCount 100
#define LandJoystickAxesCount 100
void land_joystick_button_down_event(int button);
void land_joystick_button_up_event(int button);
void land_joystick_axis_event(int a, float x);
void land_joystick_tick(void);
int land_joystick_button(int button);
int land_joystick_button_pressed(int button);
float land_joystick_axis(int a);
float land_joystick_delta_axis(int a);
str land_joystick_button_name(int b);
str land_joystick_axis_name(int a);
int land_joystick_button_count(void);
int land_joystick_axis_count(void);
int land_joystick_find_axis(str name);
int land_joystick_find_button(str name);
void land_joystick_debug(void);
void csg_test_shapes(void);
void csg_test_union(void);
void csg_test_subtract(void);
void csg_test_intersect(void);
void csg_test(void);
#ifndef LAND_USE_EXTERNAL_YAML
enum LandYamlFlags {
    LandYamlPretty=1
};
struct YamlParser {
    LandFile * file;
    int line_length;
    int flags;
    int indent;
    bool cannot_break;
};
LandYaml* land_yaml_load(char const * filename);
void land_yaml_save_flags(LandYaml * yaml, int flags);
void land_yaml_save(LandYaml * yaml);
#endif
struct LandArray {
    int count;
    int size;
    void * (* data);
};
struct LandArrayIterator {
    int i;
};
LandArrayIterator LandArrayIterator_first(LandArray * a);
void* LandArrayIterator_item(LandArray * a, LandArrayIterator * i);
bool LandArrayIterator_next(LandArray * a, LandArrayIterator * i);
int LandArray__len__(LandArray * a);
LandArray* land_array_new(void);
void land_array_add(LandArray * self, void * data);
void land_array_reserve(LandArray * self, int n);
void* land_array_pop(LandArray * self);
void* land_array_remove(LandArray * self, int i);
void land_array_add_data(LandArray * (* array), void * data);
int land_array_find(LandArray * self, void * data);
void* land_array_get_nth(LandArray const * array, int i);
void* land_array_get(LandArray const * array, int i);
bool land_array_is_empty(LandArray const * array);
void* land_array_replace_nth(LandArray * array, int i, void * data);
void* land_array_replace_or_resize(LandArray * array, int i, void * data);
void* land_array_get_last(LandArray * array);
void land_array_destroy(LandArray * self);
void land_array_destroy_with_strings(LandArray * self);
void land_array_destroy_with_free(LandArray * self);
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
LandArray* land_array_new_memlog(char const * f, int l);
void land_array_destroy_memlog(LandArray * self, char const * f, int l);
void land_array_add_memlog(LandArray * self, void * data, char const * f, int l);
LandArray* land_array_copy_memlog(LandArray const * self, char const * f, int l);
void land_array_concat_memlog(LandArray * self, LandArray const * other, char const * f, int l);
void land_array_merge_memlog(LandArray * self, LandArray * other, char const * f, int l);
void land_array_clear_memlog(LandArray * self, char const * f, int l);
#ifdef LAND_MEMLOG
#define land_array_new() land_array_new_memlog(__FILE__, __LINE__)
#define land_array_destroy(x) land_array_destroy_memlog(x, __FILE__, __LINE__)
#define land_array_add(x, y) land_array_add_memlog(x, y, __FILE__, __LINE__)
#define land_array_copy(x) land_array_copy_memlog(x, __FILE__, __LINE__)
#define land_array_merge(x, y) land_array_merge_memlog(x, y, __FILE__, __LINE__)
#define land_array_concat(x, y) land_array_concat_memlog(x, y, __FILE__, __LINE__)
#define land_array_clear(x) land_array_clear_memlog(x, __FILE__, __LINE__)
#endif
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
LandYaml* land_yaml_load_xml(str filename);
void land_yaml_save_xml(LandYaml * yaml);
void land_yaml_xml_tag(LandYaml * yaml, str name);
void land_yaml_xml_tag_with_content(LandYaml * yaml, str name, str content);
void land_yaml_xml_content(LandYaml * yaml, str content);
void land_yaml_xml_attribute(LandYaml * yaml, str key, str value);
void land_yaml_xml_end(LandYaml * yaml);
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
void platform_wait(double seconds);
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
double land_scale_to_fit_into(float w, float h, float l, float t, float r, float b, int how);
void land_get_scaled_dimensions(float * x, float * y, float * w, float * h);
double land_scale_to_fit(float w, float h, int how);
LandFloat land_get_left(void);
LandFloat land_get_x_scale(void);
LandFloat land_get_top(void);
LandFloat land_get_y_scale(void);
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
LandColor land_color_get(void);
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
void land_textured_colored_polygon(LandImage * image, int n, float * xy, float * uv, float * rgba);
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
void land_display_icon(LandImage * icon);
int land_display_flags(void);
LandImage* land_display_new_image(void);
void land_display_del_image(LandImage * image);
void land_display_select(LandDisplay * display);
void land_display_unselect(void);
void land_screenshot(char const * filename);
void land_screenshot_autoname(char const * name);
void land_resize_event(int w, int h);
void land_switch_out_event(void);
int land_switched_out(void);
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
void land_projection(Land4x4Matrix m);
void land_reset_projection(void);
void land_display_transform_4x4(Land4x4Matrix * matrix);
void land_render_state(int state, int value);
void land_display_set_default_shaders(void);
int land_display_dpi(void);
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
LandVector land_vector_add4(LandVector v, LandVector w, LandVector a, LandVector b);
LandVector land_vector_add8(LandVector v, LandVector w, LandVector a, LandVector b, LandVector c, LandVector d, LandVector e, LandVector f);
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
Land4x4Matrix land_4x4_matrix_skew(LandFloat xy, LandFloat xz, LandFloat yx, LandFloat yz, LandFloat zx, LandFloat zy);
Land4x4Matrix land_4x4_matrix_rotate(LandFloat x, LandFloat y, LandFloat z, LandFloat angle);
Land4x4Matrix land_4x4_matrix_identity(void);
Land4x4Matrix land_4x4_matrix_translate(LandFloat x, LandFloat y, LandFloat z);
Land4x4Matrix land_4x4_matrix_perspective(LandFloat left, LandFloat bottom, LandFloat nearz, LandFloat right, LandFloat top, LandFloat farz);
Land4x4Matrix land_4x4_matrix_orthographic(LandFloat left, LandFloat top, LandFloat nearz, LandFloat right, LandFloat bottom, LandFloat farz);
Land4x4Matrix land_4x4_matrix_from_vectors(LandVector * p, LandVector * r, LandVector * u, LandVector * b);
Land4x4Matrix land_4x4_matrix_inverse_from_vectors(LandVector * p, LandVector * r, LandVector * u, LandVector * b);
LandVector land_4x4_matrix_get_right(Land4x4Matrix * m);
LandVector land_4x4_matrix_get_up(Land4x4Matrix * m);
LandVector land_4x4_matrix_get_back(Land4x4Matrix * m);
LandVector land_4x4_matrix_get_position(Land4x4Matrix * m);
void land_quaternion_normalize(LandQuaternion * q);
LandQuaternion land_quaternion_slerp(LandQuaternion qa, LandQuaternion qb, double t);
LandBuffer* land_4x4_matrix_to_string(Land4x4Matrix * m);
LandCSG* csg_sphere(int slices, int rings, void * shared);
LandCSG* csg_tetrasphere(int divisions, void * shared);
LandCSG* land_csg_icosphere(int divisions, void * shared);
LandCSG* csg_cylinder(int slices, void * shared);
LandCSG* csg_cut_cone_open(int slices, bool opened, float top_radius, void * shared);
LandCSG* csg_cylinder_open(int slices, bool opened, void * shared);
LandCSG* csg_cone(int slices, void * shared);
LandCSG* csg_pyramid(void * shared);
LandCSG* csg_cut_pyramid_open(bool opened, LandFloat top_x, LandFloat top_y, void * shared);
LandCSG* csg_tetrahedron(void * shared);
LandCSG* csg_cube(void * shared);
LandCSG* csg_block2(int x, int y, int z, bool outside, void * shared);
LandCSG* csg_block(int x, int y, int z, bool outside, void * shared);
LandCSG* csg_grid(int x, int y, void * shared);
LandCSG* csg_prism(int n, void * shared);
LandCSG* csg_trapezoid(LandFloat x1, LandFloat x2, void * shared);
LandCSG* csg_extrude_triangle(LandVector a, LandVector b, LandFloat d, void * shared);
LandCSG* csg_irregular_tetrahedron(LandVector a, LandVector b, LandVector c, LandVector d, void * shared);
LandCSG* csg_torus(int slices, int segments, LandFloat diameter, void * shared);
void land_csg_polygon_recalculate_normal(LandCSGPolygon * p);
void land_csg_recalculate_smooth_normals(LandCSG * csg);
LandCSG* land_csg_voxelize(LandCSG * csg, double radius);
void platform_thread_run(void(* cb)(void *), void * data);
LandThread* platform_thread_new(void(* cb)(void * data), void * data);
void platform_thread_destroy(LandThread * self);
LandLock* platform_thread_new_lock(void);
void platform_thread_delete_lock(LandLock * lock);
void platform_thread_lock(LandLock * lock);
void platform_thread_unlock(LandLock * lock);
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
void platform_stream_music(LandStream * super, char const * filename, bool looping);
void platform_stream_volume(LandStream * super, float volume);
bool platform_stream_is_playing(LandStream * super);
void platform_stream_set_playing(LandStream * super, bool onoff);
struct LandCSG {
    LandArray * polygons;
    LandMemoryPool * pool;
    LandCSGAABB bbox;
    LandOctree * octree;
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
LandCSGPlane land_csg_plane_from_points(LandVector a, LandVector b, LandVector c);
void land_csg_polygon_init(LandCSGPolygon * self, LandArray * vertices, void * shared);
LandCSGPolygon* land_csg_polygon_new(LandArray * vertices, void * shared);
void csg_plane_flip(LandCSGPlane * self);
void land_csg_polygon_destroy(LandCSGPolygon * self);
LandCSGPolygon* land_csg_polygon_clone(LandCSG * csg, LandCSGPolygon const * self);
void land_csg_polygon_flip(LandCSGPolygon * self);
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
void land_csg_polygon_paint(LandCSGPolygon * self, float r, float g, float b, float a);
void land_csg_paint_all(LandCSG * self, float r, float g, float b, float a);
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
void land_grid_isometric_placeholder(LandGrid * self, LandView * view, int cell_x, int cell_y, float x, float y);
void land_grid_draw_isometric(LandGrid * self, LandView * view);
void land_grid_draw_isometric_wrap(LandGrid * self, LandView * view);
void land_isometric_init(void);
void land_isometric_exit(void);
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
void land_widget_move_to(LandWidget * self, float x, float y);
void land_widget_center(LandWidget * self);
void land_widget_base_size(LandWidget * self, float dx, float dy);
void land_widget_size(LandWidget * self, float dx, float dy);
void land_widget_resize(LandWidget * self, float dx, float dy);
void land_widget_set_size_permanent(LandWidget * self, float w, float h);
void land_widget_set_size(LandWidget * self, float w, float h);
void land_widget_set_height(LandWidget * self, float h);
void land_widget_retain_mouse_focus(LandWidget * self);
void land_widget_refuse_mouse_focus(LandWidget * self);
void land_widget_request_keyboard_focus(LandWidget * self);
void land_widget_retain_keyboard_focus(LandWidget * self);
void land_widget_tick(LandWidget * self);
void land_widget_draw(LandWidget * self);
void land_widget_hide(LandWidget * self);
void land_widget_unhide(LandWidget * self);
void land_widget_set_hidden(LandWidget * self, bool hidden);
bool land_widget_is_hidden(LandWidget * self);
void land_widget_outer(LandWidget * self, float * x, float * y, float * w, float * h);
void land_widget_inner(LandWidget * self, float * x, float * y, float * w, float * h);
void land_widget_inner_extents(LandWidget * self, float * l, float * t, float * r, float * b);
void land_widget_get_inner_size(LandWidget * self, float * w, float * h);
void land_widget_base_interface_initialize(void);
void land_widget_debug(LandWidget * w, int indentation);
void land_widget_keyboard_leave(LandWidget * self);
void land_widget_keyboard_focus(LandWidget * self);
void land_bind_vbo(GLuint * vbo, void * data, int n, int draw);
void land_unbind_vbo(GLuint vbo);
char const* land_opengl_error(void);
void land_4x4_matrix_to_gl_float(Land4x4Matrix m, GLfloat * gl);
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
struct LandWidgetScrollbar {
    LandWidget super;
    LandWidget * target;
    int dragged;
    int drag_x, drag_y;
    bool vertical;
    void(* callback)(LandWidget * self, bool update_target, int * _scramble_min, int * _scramble_max, int * range, int * pos);
};
#define LAND_WIDGET_SCROLLBAR(widget) ((LandWidgetScrollbar *) land_widget_check(widget, LAND_WIDGET_ID_SCROLLBAR, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_scrollbar_vertical_interface;
extern LandWidgetInterface * land_widget_scrollbar_horizontal_interface;
void land_widget_scrollbar_update(LandWidget * handle, bool update_target);
void land_widget_scrollbar_draw(LandWidget * self);
void land_widget_scrollbar_mouse_tick(LandWidget * handle);
LandWidget* land_widget_scrollbar_new(LandWidget * parent, LandWidget * target, int vertical, int x, int y, int w, int h);
void land_widget_scrollbar_interface_initialize(void);
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
struct LandWidgetButton {
    LandWidget super;
    unsigned int xalign;
    unsigned int yalign;
    int xshift;
    int yshift;
    float scale_x, scale_y;
    int multiline;
    LandAnimation * animation;
    LandImage * image;
    bool want_image_destroyed;
    char * text;
    LandArray * lines;
    void(* clicked)(LandWidget * self);
    void(* rclicked)(LandWidget * self);
    void(* dynamic_text_cb)(LandWidget * self);
};
#define LAND_WIDGET_BUTTON(widget) ((LandWidgetButton *) land_widget_check(widget, LAND_WIDGET_ID_BUTTON, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_button_interface;
void land_widget_button_draw(LandWidget * base);
void land_widget_button_size(LandWidget * base, float dx, float dy);
void land_widget_button_mouse_tick(LandWidget * base);
void land_widget_button_initialize(LandWidget * base, LandWidget * parent, char const * text, LandImage * image, bool destroy, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_button_new(LandWidget * parent, char const * text, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_button_new_with_image(LandWidget * parent, char const * text, LandImage * image, bool destroy, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
void land_widget_button_image_scale(LandWidget * base, float xs, float ys);
LandWidget* land_widget_button_new_with_animation(LandWidget * parent, char const * text, LandAnimation * animation, void(* clicked)(LandWidget * self), int x, int y, int w, int h);
LandWidget* land_widget_text_initialize(LandWidget * self, LandWidget * parent, char const * text, int multiline, int x, int y, int w, int h);
LandWidget* land_widget_text_new(LandWidget * parent, char const * text, int multiline, int x, int y, int w, int h);
void land_widget_button_replace_text(LandWidget * base, char const * text);
void land_widget_button_set_text(LandWidget * base, char const * text);
str land_widget_button_get_text(LandWidget * base);
void land_widget_button_layout_text(LandWidget * base);
void land_widget_button_append_row(LandWidget * base, char const * text);
void land_widget_button_multiline(LandWidget * self, int style);
void land_widget_button_align(LandWidget * self, int x, int y);
void land_widget_button_shift(LandWidget * self, int x, int y);
void land_widget_button_interface_initialize(void);
void land_widget_button_destroy(LandWidget * base);
void land_widget_button_set_minimum_text(LandWidget * base, char const * text);
void land_widget_button_set_dynamic_text_callback(LandWidget * self, void(* cb)(LandWidget *));
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
void platform_display_icon(LandImage * icon);
void platform_display_move(int x, int y);
void platform_display_resize(int w, int h);
void land_a5_display_check_transform(void);
void platform_check_blending_and_transform(void);
void platform_uncheck_blending(void);
void check_blending_and_transform(void);
void uncheck_blending(void);
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
void platform_reset_projection(void);
void platform_projection(Land4x4Matrix m);
int platform_get_dpi(void);
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
LandWidget* land_widget_container_get_keyboard_focus(LandWidget * super);
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
LandWidget* land_widget_container_child_i(LandWidget * super, int i);
int land_widget_container_is_empty(LandWidget * super);
void land_widget_container_initialize(LandWidget * super, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_container_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_container_interface_initialize(void);
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
struct LandWidgetPanel {
    LandWidgetContainer super;
};
#define LAND_WIDGET_PANEL(widget) ((LandWidgetPanel *) land_widget_check(widget, LAND_WIDGET_ID_PANEL, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_panel_interface;
void land_widget_panel_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_panel_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_panel_add(LandWidget * base, LandWidget * add);
void land_widget_panel_interface_initialize(void);
struct LandWidgetBoard {
    LandWidgetContainer super;
};
#define LAND_WIDGET_BOARD(widget) ((LandWidgetBoard *) land_widget_check(widget, LAND_WIDGET_ID_BOARD, __FILE__, __LINE__))
extern LandWidgetInterface * land_widget_board_interface;
void land_widget_board_initialize(LandWidget * base, LandWidget * parent, int x, int y, int w, int h);
LandWidget* land_widget_board_new(LandWidget * parent, int x, int y, int w, int h);
void land_widget_board_add(LandWidget * base, LandWidget * add);
void land_widget_board_size(LandWidget * super, float dx, float dy);
void land_widget_board_update(LandWidget * widget);
void land_widget_board_interface_initialize(void);
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
bool land_widget_scrolling_need_vertical_bar(LandWidget * widget);
void land_widget_scrolling_update(LandWidget * widget);
void land_widget_scrolling_size(LandWidget * widget, float dx, float dy);
void land_widget_scrolling_get_scroll_position(LandWidget * base, float * x, float * y);
void land_widget_scrolling_get_scrollable_area(LandWidget * base, float * x, float * y);
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
struct LandWidgetScrollingText {
    LandWidgetScrolling super;
};
extern LandWidgetInterface * land_widget_scrolling_text_interface;
void land_widget_scrolling_text_initialize(LandWidget * base, LandWidget * parent, char const * text, int wordwrap, int x, int y, int w, int h);
LandWidget* land_widget_scrolling_text_new(LandWidget * parent, char const * text, int wordwrap, int x, int y, int w, int h);
void land_widget_scrolling_text_size(LandWidget * widget, float dx, float dy);
void land_widget_scrolling_text_interface_initialize(void);
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
    bool * value;
};
extern LandWidgetInterface * land_widget_checkbox_interface;
extern LandWidgetInterface * land_widget_checkbox_button_interface;
extern LandWidgetInterface * land_widget_checkbox_description_interface;
#define LAND_WIDGET_CHECKBOX(widget) ((LandWidgetCheckBox *) land_widget_check(widget, LAND_WIDGET_ID_CHECKBOX, __FILE__, __LINE__))
void land_widget_checkbox_initialize(LandWidget * base, LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, bool * b, int x, int y, int w, int h);
LandWidget* land_widget_checkbox_new(LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, int x, int y, int w, int h);
LandWidget* land_widget_checkbox_new_boolean(LandWidget * parent, char const * checkbox_selected, char const * checkbox_unselected, char const * text, bool * b, int x, int y, int w, int h);
bool land_widget_checkbox_is_checked(LandWidget * self);
void land_widget_checkbox_set(LandWidget * base, bool checked);
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
#endif

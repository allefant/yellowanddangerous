/* This file was generated by scramble.py. */
#line 1 "src/render.py"
#ifndef _RENDER_
#define _RENDER_
typedef struct Render Render;
#line 1
#include "common.h"
#include "game.h"
#line 2
#include "isometric.h"
#line 2
#include "main.h"
#line 2
#include "debug.h"
#include "vent.h"
#include "barrel.h"
#include "platform.h"
#include "eye.h"
#include "cart.h"
#include "gremlin.h"
#include "intro.h"
#include "testtube.h"
#include "menu.h"
#include "map.h"
#include "conveyor.h"
#line 18
struct Render {
    bool was_setup;
    LandColor background_color;
    LandStream * music;
    char * path;
    int song;
    LandIniFile * offsets;
};
#line 27
extern LandImage * Render_Smoke;
#line 95
extern BlockType * Render_Block;
#line 95
extern BlockType * Render_BlockBottom;
#line 95
extern BlockType * Render_BlockLeft;
#line 95
extern BlockType * Render_BlockBottom2;
#line 95
extern BlockType * Render_BlockBottom3;
#line 95
extern BlockType * Render_BlockBottomLeft3;
#line 95
extern BlockType * Render_PlankRight;
#line 95
extern BlockType * Render_PlankLeft;
#line 95
extern BlockType * Render_BlockLeft2;
#line 95
extern BlockType * Render_BlockRight2;
#line 95
extern BlockType * Render_Scientist;
#line 95
extern BlockType * Render_Cube2;
#line 95
extern BlockType * Render_Plate;
#line 95
extern BlockType * Render_Cube3;
#line 95
extern BlockType * Render_Barrel;
#line 95
extern BlockType * Render_TreeBottom;
#line 95
extern BlockType * Render_TreeTop;
#line 95
extern BlockType * Render_Trunk;
#line 95
extern BlockType * Render_ExitLeft;
#line 95
extern BlockType * Render_ExitRight;
#line 95
extern BlockType * Render_Allefant;
#line 95
extern BlockType * Render_WindowRight;
#line 95
extern BlockType * Render_WindowLeft;
#line 95
extern BlockType * Render_BlockSmall3;
#line 95
extern BlockType * Render_CherryTree;
#line 95
extern BlockType * Render_Waypoint;
#line 95
extern BlockType * Render_Crate;
#line 95
extern BlockType * Render_BlockLeft3;
#line 95
extern BlockType * Render_BlockRight3;
#line 95
extern BlockType * Render_Plant;
#line 95
extern BlockType * Render_Platform;
#line 95
extern BlockType * Render_LeverLeft;
#line 95
extern BlockType * Render_LeverRight;
#line 95
extern BlockType * Render_Statue;
#line 95
extern BlockType * Render_RampLeft;
#line 95
extern BlockType * Render_RampRight;
#line 95
extern BlockType * Render_VentLeft;
#line 95
extern BlockType * Render_VentRight;
#line 95
extern BlockType * Render_BlockSmall;
#line 95
extern BlockType * Render_BlockRight;
#line 95
extern BlockType * Render_BlockSmallLeft;
#line 95
extern BlockType * Render_BlockSmallRight;
#line 95
extern BlockType * Render_Gentian;
#line 95
extern BlockType * Render_Eye;
#line 95
extern BlockType * Render_Ginko;
#line 95
extern BlockType * Render_Edelweiss;
#line 95
extern BlockType * Render_Cart;
#line 95
extern BlockType * Render_GrateBottom;
#line 95
extern BlockType * Render_GrateLeft;
#line 95
extern BlockType * Render_GrateRight;
#line 95
extern BlockType * Render_Gremlin;
#line 95
extern BlockType * Render_InvisibleLeft;
#line 95
extern BlockType * Render_InvisibleRight;
#line 95
extern BlockType * Render_Orchid;
#line 95
extern BlockType * Render_Sunflower;
#line 95
extern BlockType * Render_Hyacinth;
#line 95
extern BlockType * Render_DeskLeft;
#line 95
extern BlockType * Render_WallLeft;
#line 95
extern BlockType * Render_WallRight;
#line 95
extern BlockType * Render_DeskRight;
#line 95
extern BlockType * Render_Floor;
#line 95
extern BlockType * Render_TestTube;
#line 95
extern BlockType * Render_Rose;
#line 95
extern BlockType * Render_Belladonna;
#line 95
extern BlockType * Render_BridgeRight;
#line 95
extern BlockType * Render_BridgeLeft;
#line 95
extern BlockType * Render_Car;
#line 95
extern BlockType * Render_Key;
#line 95
extern BlockType * Render_BlockBottomRight3;
#line 95
extern BlockType * Render_ConveyorLeft;
#line 95
extern BlockType * Render_ConveyorRight;
#line 95
extern LandSound * Render_step;
#line 95
extern LandSound * Render_push;
#line 95
extern LandSound * Render_off;
#line 95
extern LandSound * Render_on;
#line 95
extern LandSound * Render_uhg;
#line 95
extern LandSound * Render_oh_no;
#line 95
extern LandSound * Render_teleport;
#line 95
extern LandSound * Render_glass;
#line 95
extern LandSound * Render_metal;
#line 95
extern LandSound * Render_ignition;
#line 95
extern LandSound * Render_pickup;
#line 207
void render_loading_screen(void);
#line 219
void render_ad_screen(void);
#line 231
void render_setup(void);
#line 264
LandImage* render_load_icon(void);
#line 268
void render_setup_path(void);
#line 276
void render_load_blocktypes(void);
#line 329
void play_song(void);
#line 358
void song_volume(void);
#line 362
void render_teardown(void);
#line 444
void render(Game * g, float w, float h);
#line 543
void render_block_scaled(Block * self, Viewport * viewport, double scaled);
#line 657
void render_block(Block * self, Viewport * viewport);
#line 660
void render_blocks(Blocks * blocks, Viewport * viewport);
#endif
/* This file was generated by scramble.py. */

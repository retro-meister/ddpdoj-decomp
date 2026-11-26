/* Tables of the player panel. */
#include "common.h"

extern u8 D_0025F7B0[];
extern u8 D_0025F7F0[];
extern u8 D_0025F830[];
extern u8 D_0025F870[];
extern u8 D_0025F8B0[];
extern u8 D_0025F8F0[];
extern u8 D_0025F930[];
extern u8 D_0025F970[];
extern u16 player_panel_palettes[4][16];
#ifdef DDPDOJ_PC
#include "pc_player_palette.h"
extern u16 D_0025F5F0[];
#define SHIP_GROUP(...) { __VA_ARGS__ },
struct PcPlayerPaletteTable stage_palettes_load_value = {
    { D_0025F5F0, D_0025F5F0, D_0025F5F0, D_0025F5F0, D_0025F5F0 },
    { 0, 0, 0, 0, 0, 0 },
    { { 0, 2, 4, 9 }, { 1, 3, 4, 10 } },
    {
#else
#define SHIP_GROUP(...) __VA_ARGS__,
extern u8 D_0028D988[];

struct D0025f620Record { void *p0; void *p1; void *p2; void *p3; void *p4; u16 w5[14]; void *p6; void *p7; void *p8; void *p9; void *p10; void *p11; void *p12; void *p13; void *p14; void *p15; void *p16; void *p17; void *p18; void *p19; void *p20; void *p21; };
extern struct D0025f620Record stage_palettes_load_value;

struct D0025f620Record stage_palettes_load_value = {
    D_0028D988,
    D_0028D988,
    D_0028D988,
    D_0028D988,
    D_0028D988,
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0004, 0x0009, 0x0001, 0x0003, 0x0004, 0x000A },
#endif
    SHIP_GROUP(D_0025F7B0, D_0025F8B0, D_0025F930, player_panel_palettes[0])
    SHIP_GROUP(D_0025F7F0, D_0025F8F0, D_0025F970, player_panel_palettes[2])
    SHIP_GROUP(D_0025F830, D_0025F8B0, D_0025F930, player_panel_palettes[1])
    SHIP_GROUP(D_0025F870, D_0025F8F0, D_0025F970, player_panel_palettes[3])
#ifdef DDPDOJ_PC
    },
#endif
};
#undef SHIP_GROUP

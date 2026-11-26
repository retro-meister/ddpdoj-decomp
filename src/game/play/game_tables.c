/* Tables of the game task. */
#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_enemy_animation.h"
#endif

extern u8 D_0024F3D8[];
extern u8 D_0024F400[];
extern u8 D_0024F420[];
extern u8 D_0024F450[];
extern u8 D_0024F470[];
extern u8 D_0024F490[];
extern u8 D_0024F4C0[];
extern u8 D_0024F4D0[];
extern u8 D_0024F4E0[];
extern u8 D_0024F4F0[];
extern u8 D_0024F500[];
extern u8 D_0024F510[];
extern u8 D_0028C0E0[];
extern u8 D_0028C0E4[];
void entity_draw_layer1();
void entity_draw_layer2();
void entity_draw_layer3();
void entity_draw_layer4();
void entity_draw_layer5();

#ifdef DEATH_LABEL
extern u16 D_0024F3A8[8];
#else
extern u16 D_0024F3A8[7];
#endif
#ifdef DDPDOJ_PC
struct D0024f3c0Record {
    void (*draw[6])(void);
    u16 frames[164];
    u8 *definitions[8];
    u16 reserved[4];
    u8 *sprites[6];
    u16 tail[8];
};
#define ANIMATION_POINTERS(...) { __VA_ARGS__ }
#else
struct D0024f3c0Record { void *p0; void *p1; void *p2; void *p3; void *p4; void *p5; u16 w6[164]; void *p7; void *p8; void *p9; void *p10; void *p11; void *p12; void *p13; void *p14; u16 w15[4]; void *p16; void *p17; void *p18; void *p19; void *p20; void *p21; u16 w22[8]; };
#define ANIMATION_POINTERS(...) __VA_ARGS__
#endif
extern struct D0024f3c0Record enemy_anims_update_value;

#ifdef DEATH_LABEL
u16 D_0024F3A8[8] = {
    0x0002, 0x0003, 0x0004, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};
#else
u16 D_0024F3A8[7] = {
    0x0002, 0x0003, 0x0004, 0x0000, 0x0001, 0x0000, 0x0000,
};
#endif

struct D0024f3c0Record enemy_anims_update_value = {
    ANIMATION_POINTERS(
        entity_draw_layer2,
        entity_draw_layer1,
        entity_draw_layer2,
        entity_draw_layer3,
        entity_draw_layer4,
        entity_draw_layer5
    ),
    { 0x8000, 0xFC00, 0xFE00, 0x0410, 0x001E, 0x00B4, 0x000C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x13DB, 0x0000, 0x13DA, 0x0000, 0x13D9, 0x0000, 0x13D8, 0x8004, 0xFA00, 0xFD00, 0x0618, 0x001E, 0x00B4, 0x000C, 0x0000, 0x0000, 0x13D3, 0x0000, 0x13D2, 0x0000, 0x13D1, 0x0000, 0x13D0, 0x8008, 0xF800, 0xFB00, 0x0828, 0x001E, 0x00B4, 0x001C, 0x0000, 0x0000, 0x13C7, 0x0000, 0x13C6, 0x0000, 0x13C5, 0x0000, 0x13C4, 0x0000, 0x13C3, 0x0000, 0x13C2, 0x0000, 0x13C1, 0x0000, 0x13C0, 0x800C, 0xFC00, 0xFE00, 0x0410, 0x001E, 0x00B4, 0x000C, 0x0000, 0x0000, 0x13DF, 0x0000, 0x13DE, 0x0000, 0x13DD, 0x0000, 0x13DC, 0x8010, 0xFA00, 0xFC00, 0x0620, 0x001E, 0x00B4, 0x000C, 0x0000, 0x0000, 0x13D7, 0x0000, 0x13D6, 0x0000, 0x13D5, 0x0000, 0x13D4, 0x8014, 0xF800, 0xFA00, 0x0830, 0x001E, 0x00B4, 0x001C, 0x0000, 0x0000, 0x13CF, 0x0000, 0x13CE, 0x0000, 0x13CD, 0x0000, 0x13CC, 0x0000, 0x13CB, 0x0000, 0x13CA, 0x0000, 0x13C9, 0x0000, 0x13C8, 0x8128, 0xFC00, 0xFE00, 0x0410, 0x001E, 0x00B4, 0x000C, 0x0000, 0x812C, 0xFA00, 0xFD00, 0x0618, 0x001E, 0x00B4, 0x000C, 0x0000, 0x8130, 0xF800, 0xFB00, 0x0828, 0x001E, 0x00B4, 0x001C, 0x0000, 0x8134, 0xFC00, 0xFE00, 0x0410, 0x001E, 0x00B4, 0x000C, 0x0000, 0x8138, 0xFA00, 0xFC00, 0x0620, 0x001E, 0x00B4, 0x000C, 0x0000, 0x813C, 0xF800, 0xFA00, 0x0830, 0x001E, 0x00B4, 0x001C, 0x0000 },
    ANIMATION_POINTERS(
        D_0024F3D8,
        D_0024F400,
        D_0024F420,
        D_0024F450,
        D_0024F470,
        D_0024F490,
        D_0028C0E0,
        D_0028C0E4
    ),
    { 0x0000, 0x0000, 0x0000, 0x0000 },
    ANIMATION_POINTERS(
        D_0024F4C0,
        D_0024F4D0,
        D_0024F4E0,
        D_0024F4F0,
        D_0024F500,
        D_0024F510
    ),
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};


#ifdef DDPDOJ_PC
#include "pc_data_alias.h"
#include <stddef.h>

u8 *pc_enemy_animation_definition(u16 offset)
{
    unsigned index = offset / 4;
    if (offset % 4 || index >= sizeof(enemy_anims_update_value.definitions) / sizeof(u8 *)) {
        pc_arcade_address_invalid(offset);
    }
    return enemy_anims_update_value.definitions[index];
}

void (*pc_enemy_animation_draw(u16 offset))(void)
{
    unsigned index = offset / 4;
    if (offset % 4 || index >= sizeof(enemy_anims_update_value.draw) / sizeof(enemy_anims_update_value.draw[0])) {
        pc_arcade_address_invalid(offset);
    }
    return enemy_anims_update_value.draw[index];
}

/* The 16-bit frame records keep their original layout after the six callbacks. */
_Static_assert(offsetof(struct D0024f3c0Record, frames) == 0x30, "Desktop animation frame offset");
PC_DATA_ALIAS(D_0024F3D8, enemy_anims_update_value, 0x30);
PC_DATA_ALIAS(D_0024F3F0, enemy_anims_update_value, 0x48);
PC_DATA_ALIAS(D_0024F400, enemy_anims_update_value, 0x58);
PC_DATA_ALIAS(D_0024F410, enemy_anims_update_value, 0x68);
PC_DATA_ALIAS(D_0024F420, enemy_anims_update_value, 0x78);
PC_DATA_ALIAS(D_0024F430, enemy_anims_update_value, 0x88);
PC_DATA_ALIAS(D_0024F450, enemy_anims_update_value, 0xa8);
PC_DATA_ALIAS(D_0024F460, enemy_anims_update_value, 0xb8);
PC_DATA_ALIAS(D_0024F470, enemy_anims_update_value, 0xc8);
PC_DATA_ALIAS(D_0024F480, enemy_anims_update_value, 0xd8);
PC_DATA_ALIAS(D_0024F490, enemy_anims_update_value, 0xe8);
PC_DATA_ALIAS(D_0024F4A0, enemy_anims_update_value, 0xf8);
PC_DATA_ALIAS(D_0024F4C0, enemy_anims_update_value, 0x118);
PC_DATA_ALIAS(D_0024F4D0, enemy_anims_update_value, 0x128);
PC_DATA_ALIAS(D_0024F4E0, enemy_anims_update_value, 0x138);
PC_DATA_ALIAS(D_0024F4F0, enemy_anims_update_value, 0x148);
PC_DATA_ALIAS(D_0024F500, enemy_anims_update_value, 0x158);
PC_DATA_ALIAS(D_0024F510, enemy_anims_update_value, 0x168);
#endif

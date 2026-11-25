/* Data of the stage clear colors unit, still to be merged into it. */
#include "common.h"

extern u8 D_002620F0[];
extern u8 D_00262130[];
extern u8 D_00262170[];
extern u8 D_002621B0[];
extern u8 D_002621F0[];
extern u8 D_002BB430[];
extern u8 D_002BB438[];
extern u8 D_002BB440[];
extern u8 D_002BB448[];
extern u8 D_002BB450[];

struct D0026b210Record { u16 w0[16]; void *p1; void *p2; void *p3; void *p4; void *p5; u16 w6[8]; void *p7; u16 w8[2]; void *p9; u16 w10[2]; void *p11; u16 w12[2]; void *p13; u16 w14[2]; void *p15; u16 w16[20]; };
extern struct D0026b210Record D_0026B210;

struct D0026b210Record D_0026B210 = {
    { 0x0100, 0x0302, 0x0004, 0x0201, 0x0403, 0x0100, 0x0302, 0x0004, 0x0201, 0x0403, 0x0100, 0x0302, 0x0004, 0x0201, 0x0403, 0x0100 },
    D_002BB430,
    D_002BB438,
    D_002BB440,
    D_002BB448,
    D_002BB450,
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x14B5, 0x0000 },
    D_002620F0,
    { 0x14B6, 0x0000 },
    D_00262130,
    { 0x14B7, 0x0000 },
    D_00262170,
    { 0x14B8, 0x0000 },
    D_002621B0,
    { 0x14B9, 0x0000 },
    D_002621F0,
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0x8000, 0x9000, 0x9000, 0xA000, 0xA000, 0xB000, 0xB000, 0xC000, 0xC000, 0xD000, 0xD000, 0xE000, 0xE000, 0xF000, 0xF000 },
};

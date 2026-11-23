#include "common.h"

typedef struct {
    u32 DX : 12;
    u32 DY : 11;
    u32 MAGH : 4;
    u32 MAGV : 2;
    u32 p0 : 3;
    u32 DW : 12;
    u32 DH : 11;
    u32 p1 : 9;
} DisplayReg;

extern s32 D_0028EA54;
extern DisplayReg D_0057C7F8[];
extern DisplayReg D_0057C820[];

void func_0021B570(s32 x, s32 y) {
    s32 dx;
    s32 dy;
    s32 base_x;
    s32 base_y;

    switch (D_0028EA54) {
    case 0x180:
        base_x = 0x21E;
        base_y = 0x32;
        break;
    case 0x1C0:
        base_x = 0x21C;
        x = (s8)(x * 4);
        base_y = 0x19;
        break;
    case 0x200:
        base_x = 0x256;
        base_y = 0x32;
        break;
    case 0x280:
        base_x = 0x27C;
        x = (s8)(x * 4);
        base_y = 0x19;
        break;
    }
    dy = base_y + (s8)y;
    dx = base_x + (s8)(x * 2);
    D_0057C7F8[0].DX = dx;
    D_0057C7F8[0].DY = dy;
    D_0057C820[0].DX = dx;
    D_0057C820[0].DY = dy;
}

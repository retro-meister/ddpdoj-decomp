#include "common.h"

void func_001713F0(s32 id);

void func_001CA450(void) {
    func_001713F0(0xB);
}

s32 func_00124320();
s32 func_00124B20();
s32 func_00124E10();
s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
s32 func_001CA720();
s32 func_001CBBD0();
s32 func_001CBC10();
extern u8 D_002554B0[];
extern u8 D_0025FBB0[];
extern u8 D_0025FBF0[];
extern u8 D_0025FC30[];
extern u8 D_0025FC70[];
extern u8 D_0025FCF0[];
extern u8 D_0026C030[];
extern u8 D_0026C0C0[];
extern u8 D_0026C270[];
extern u8 D_0026C630[];
extern u8 D_0026C820[];
extern u8 D_0026C920[];
extern u8 D_0028DB18[];
extern s16 D_0028E3A8;
extern s16 D_0028E5B0_as_s16;
extern u8 *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E855;
extern u16 D_0028E910;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CA460(void) {
    reg_a0 = (u8 *)D_0026C920;
    func_0014E370();
    reg_a0 = (u8 *)D_0028DB18;
    reg_d0.h[0] = 2;
    func_0014E300();
    reg_tmp.w = 0x9C001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = D_0029C068[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
    reg_a0 = (u8 *)D_0026C820;
    reg_a1 = (u8 *)D_0026C0C0;
    reg_a2 = (u8 *)D_0026C270;
    reg_a3 = (u8 *)D_0026C030;
    reg_a4 = (u8 *)D_0026C630;
    D_0028E3A8 = 0;
    func_00124320();
    func_00124E10();
    reg_d0.w = 0;
    func_00124B20();
    reg_d0.h[0] = 0x10;
    reg_a0 = (u8 *)D_0025FBB0;
    func_001A3020();
    reg_d0.h[0] = 0x11;
    reg_a0 = (u8 *)D_0025FBF0;
    func_001A3020();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_0025FC30;
    func_001A3020();
    reg_d0.h[0] = 0x17;
    reg_a0 = (u8 *)D_0025FC70;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_0025FCF0;
    func_001A3020();
    reg_d0.h[0] = 0x16;
    reg_a0 = (u8 *)D_002554B0;
    func_001A3020();
    D_0028E5B0_as_s16 = 1;
    D_0028E855 |= 1;
    D_0028E624 = 0x322;
    reg_a0 = reg_a5 + 0x16;
    D_0028E855 |= 4;
    D_0028E620 = (u8 *)(reg_a0);
    func_001CA720();
    func_001CBBD0();
    func_001CBC10();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (D_0028E910 != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
}

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001CA730();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s8 D_0028E408;
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001CA640(void) {
    func_001CA730();
    func_00124590();
    if (D_0028E408 != 0) {
        func_002035A0();
        func_0014E290();
        return;
    }
    reg_a0_as_s32 = reg_a6_as_s32;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x20;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x40;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x60;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x80;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xA0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xC0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xE0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x100;
    func_0014D220();
}

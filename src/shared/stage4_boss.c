#include "common.h"
#include "entity.h"

void func_001713F0(s32);

void func_001E7A10(void) {
    func_001713F0(0xC);
}

s32 func_00124320();
s32 func_00124B20();
s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
s32 func_001E7C50();
s32 func_001E8700();
s32 func_001E8720();
s32 func_0020ED10();
extern u8 D_002554B0[];
extern u8 D_0025FE70[];
extern u8 D_0025FEB0[];
extern u8 D_0026EAF0[];
extern u8 D_0026EB50[];
extern u8 D_0026EDD0[];
extern u8 D_0026F200[];
extern u8 D_0026F3F0[];
extern u8 D_0026F4D0[];
extern u8 D_0028DC88[];
extern s16 D_0028E5B0_as_s16;
extern u8 *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern s16 D_0028E864_as_s16;
extern s16 D_0028E870_as_s16;
extern s16 D_0028E874_as_s16;
extern s16 D_0028E878_as_s16;
extern s16 D_0028E87C_as_s16;
extern u16 D_0028E910;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];

void func_001E7A20(void) {
    reg_a0 = (u8 *)D_0026F4D0;
    func_0014E370();
    reg_a0 = (u8 *)D_0028DC88;
    reg_d0.h[0] = 3;
    func_0014E300();
    reg_tmp.w = 0xC8001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_a0 = (u8 *)D_0026F3F0;
    reg_a1 = (u8 *)D_0026EB50;
    reg_a2 = (u8 *)D_0026EDD0;
    reg_a3 = (u8 *)D_0026EAF0;
    reg_a4 = (u8 *)D_0026F200;
    func_00124320();
    reg_d0.w = 0;
    func_00124B20();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_0025FE70;
    func_001A3020();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_0025FEB0;
    func_001A3020();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_002554B0;
    func_001A3020();
    D_0028E5B0_as_s16 = 1;
    func_0020ED10();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (D_0028E910 != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
    D_0028E855 |= 1;
    D_0028E855 |= 4;
    D_0028E624 = 0x500;
    D_0028E864_as_s16 = 0;
    D_0028E87C_as_s16 = 0;
    D_0028E878_as_s16 = 0;
    D_0028E854 |= 1;
    reg_a0 = reg_a5;
    D_0028E874_as_s16 = 0;
    D_0028E870_as_s16 = 0;
    reg_a0 += 0x16;
    D_0028E620 = (u8 *)(reg_a0);
    func_001E7C50();
    func_001E8700();
    func_001E8720();
}

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001E7C60();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001E7BB0(void) {
    func_00124590();
    if (cond_flag != 0) {
        func_002035A0();
        func_0014E290();
        return;
    }
    func_001E7C60();
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
}

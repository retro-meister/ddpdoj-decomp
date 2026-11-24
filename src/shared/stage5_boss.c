#include "common.h"

extern void func_001713F0(s32);

void func_001F4B50(void) {
    func_001713F0(MAIN_OR_DEATH_LABEL(0xF, 18));
}

s32 func_00124320();
s32 func_00124B20();
s32 func_00124DC0();
s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
s32 func_001F5750();
extern u8 D_0025FF70[];
extern u8 D_0025FFB0[];
extern u8 D_0025FFF0[];
extern u8 D_00260030[];
extern u8 D_00260070[];
extern u8 D_002600B0[];
extern u8 D_002600F0[];
extern u8 D_00260130[];
extern u8 D_00260170[];
extern u8 D_00264090[];
extern u8 D_002640D0[];
extern u8 D_002645B0[];
extern u8 D_00264820[];
extern u8 D_00264B00[];
extern u8 D_00264EE0[];
extern u8 D_00264F40[];
extern u8 D_00264F50[];
extern u32 D_0028D9C8;
extern u8 D_0028E290;
extern u16 D_0028E2E8;
extern u16 D_0028E910;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F4B60(void) {
    reg_a0 = D_00264F50;
    func_0014E370();
    reg_a0 = D_00264F40;
    reg_d0.h[0] = ((u32) D_0028D9C8 >> 1) - 1;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00264EE0;
    reg_a1 = D_002640D0;
    reg_a2 = D_00264820;
    reg_a3 = D_00264090;
    reg_a4 = D_00264B00;
    D_0028E2E8 = D_0028E910;
    if (D_0028E290 == 2) {
        D_0028E2E8 = 1;
    }
    if (D_0028E2E8 == 0) {
        reg_a1 = D_002645B0;
    }
    func_00124320();
    reg_d0.w = 0;
    func_00124DC0();
    reg_d0.w = 1;
    func_00124DC0();
    reg_d0.w = 2;
    func_00124DC0();
    reg_d0.w = 5;
    func_00124DC0();
    reg_d0.w = 4;
    func_00124DC0();
    reg_d0.w = 3;
    func_00124DC0();
    reg_d0.w = 8;
    func_00124DC0();
    reg_d0.w = 7;
    func_00124DC0();
    reg_d0.w = 6;
    func_00124DC0();
    reg_d0.w = 9;
    func_00124DC0();
    reg_d0.w = 0;
    func_00124B20();
    reg_d0.h[0] = 0x10;
    reg_a0 = D_0025FF70;
    func_001A3020();
    reg_d0.h[0] = 0x11;
    reg_a0 = D_0025FFB0;
    func_001A3020();
    reg_d0.h[0] = 0x12;
    reg_a0 = D_0025FFF0;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0 = D_00260030;
    func_001A3020();
    reg_d0.h[0] = 0x14;
    reg_a0 = D_00260070;
    func_001A3020();
    reg_d0.h[0] = 0x15;
    reg_a0 = D_002600B0;
    func_001A3020();
    reg_d0.h[0] = 0x16;
    reg_a0 = D_002600F0;
    func_001A3020();
    reg_d0.h[0] = 0x17;
    reg_a0 = D_00260130;
    func_001A3020();
    reg_d0.h[0] = 0xF;
    reg_a0 = D_00260170;
    func_001A3020();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    D_0029976C_as_s16_a[0] = 1;
    func_001F5750();
}

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001F4EB0();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s8 D_0028E408;
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001F4DB0(void) {
    func_001F4EB0();
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
    reg_a0_as_s32 = reg_a6_as_s32 + 0x1A0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x140;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x160;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x180;
    func_0014D220();
#ifdef DEATH_LABEL
    reg_a0_as_s32 = reg_a6_as_s32 + 0x200;
    func_0014D220();
#endif
}

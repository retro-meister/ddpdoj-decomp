#include "common.h"

void func_001713F0(s32 id);

void func_001BB630(void) {
    func_001713F0(8);
}

s32 func_00124320();
s32 func_00124B20();
s32 func_00124DC0();
s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
s32 func_001BB8D0();
s32 func_001BC390();
s32 func_001BC400();
extern u8 D_002554B0[];
extern u8 D_0025FA70[];
extern u8 D_0025FAB0[];
extern u8 D_0025FAF0[];
extern u8 D_0025FB70[];
extern u8 D_0026DB20[];
extern u8 D_0026DFF0[];
extern u8 D_0026E190[];
extern u8 D_0026E860[];
extern u8 D_0026E8E0[];
extern u8 D_0026E9E0[];
extern u8 D_0026E9F0[];
extern s32 D_0028DC90;
extern s16 D_0028E5B0_as_s16;
extern u8 *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u16 D_0028E910;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern u16 D_0029C068[];

void func_001BB640(void) {
    s32 t;

    reg_a0 = (u8 *)D_0026E9F0;
    func_0014E370();
    reg_a0 = (u8 *)D_0026E9E0;
    t = (s32) D_0028DC90 >> 1;
    if (D_0028DC90 < 0) {
        t = (s32) (D_0028DC90 + 1) >> 1;
    }
    reg_d0.h[0] = t - 1;
    func_0014E300();
    reg_tmp.w = 0x97FFFE00;
    *(u16 *)(reg_a6 + 2) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = D_0029C068[0];
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
    reg_a0 = (u8 *)D_0026E8E0;
    reg_a1 = (u8 *)D_0026DFF0;
    reg_a2 = (u8 *)D_0026E190;
    reg_a3 = (u8 *)D_0026DB20;
    reg_a4 = (u8 *)D_0026E860;
    func_00124320();
    reg_d0.w = 6;
    func_00124DC0();
    reg_d0.w = 0;
    func_00124B20();
    reg_d0.h[0] = 0x15;
    reg_a0 = (u8 *)D_0025FA70;
    func_001A3020();
    reg_d0.h[0] = 0x16;
    reg_a0 = (u8 *)D_0025FAB0;
    func_001A3020();
    reg_d0.h[0] = 0x17;
    reg_a0 = (u8 *)D_0025FAF0;
    func_001A3020();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_002554B0;
    func_001A3020();
    reg_d0.h[0] = 0x11;
    reg_a0 = (u8 *)D_0025FB70;
    func_001A3020();
    D_0028E5B0_as_s16 = 1;
    D_0028E855 |= 1;
    D_0028E855 |= 4;
    D_0028E624 = 0x1A0;
    D_0028E854 |= 1;
    reg_a0 = reg_a5;
    reg_a0 += 0x16;
    D_0028E620 = (u8 *)(reg_a0);
    func_001BB8D0();
    func_001BC390();
    func_001BC400();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (D_0028E910 != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
}

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001BB8E0();                            /* extern */
s32 func_002016D0();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001BB830(void) {
    u16 temp_v0;

    func_001BB8E0();
    temp_v0 = *(u16 *)(reg_a5 + 0x24);
    if (temp_v0 != 0) {
        *(u16 *)(reg_a5 + 0x24) = (u16) (temp_v0 - 1);
        func_002016D0();
    }
    func_00124590();
    if (cond_flag != 0) {
        func_002035A0();
        func_0014E290();
        return;
    }
    reg_a0_as_s32 = reg_a6_as_s32;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x20;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x60;
    func_0014D220();
}

#include "common.h"

void func_001713F0(s32 id);

void func_001D3C90(void) {
    func_001713F0(9);
}

s32 func_00124320();
s32 func_00124B20();
s32 func_00124DC0();
s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
s32 func_001D45D0();
extern u8 D_002554B0[];
extern u8 D_0025FD30[];
extern u8 D_0025FD70[];
extern u8 D_0025FDB0[];
extern u8 D_0025FDF0[];
extern u8 D_0025FE30[];
extern u8 D_0026CAE0[];
extern u8 D_0026CBF0[];
extern u8 D_0026D2F0[];
extern u8 D_0026D7C0[];
extern u8 D_0026D9E0[];
extern u8 D_0026DA00[];
extern u8 D_0028DC18[];
extern s16 D_0028E5B0_as_s16;
extern u8 *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u16 D_0028E910;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];

void func_001D3CA0(void) {
    reg_a0 = (u8 *)D_0026DA00;
    func_0014E370();
    reg_a0 = (u8 *)D_0028DC18;
    reg_d0.h[0] = 2;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    *(u16 *)(reg_a6 + 2) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)D_0026D9E0;
    reg_a1 = (u8 *)D_0026CBF0;
    reg_a2 = (u8 *)D_0026D2F0;
    reg_a3 = (u8 *)D_0026CAE0;
    reg_a4 = (u8 *)D_0026D7C0;
    func_00124320();
    reg_d0.w = 9;
    func_00124DC0();
    reg_d0.w = 0;
    func_00124B20();
    reg_d0.h[0] = 0x10;
    reg_a0 = (u8 *)D_0025FD30;
    func_001A3020();
    reg_d0.h[0] = 0x11;
    reg_a0 = (u8 *)D_0025FD70;
    func_001A3020();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_0025FDB0;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_0025FDF0;
    func_001A3020();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_0025FE30;
    func_001A3020();
    reg_d0.h[0] = 0xA;
    reg_a0 = (u8 *)D_002554B0;
    func_001A3020();
    D_0028E5B0_as_s16 = 1;
    D_0028E855 |= 1;
    D_0028E624 = 0x4A0;
    D_0028E855 |= 4;
    D_0028E854 |= 1;
    reg_a0 = reg_a5 + 0x16;
    D_0028E620 = (u8 *)(reg_a0);
    func_001D45D0();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (D_0028E910 != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
}

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001D3F00();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001D3E60(void) {
    func_001D3F00();
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
    reg_a0_as_s32 = reg_a6_as_s32 + 0x40;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xC0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xE0;
    func_0014D220();
}

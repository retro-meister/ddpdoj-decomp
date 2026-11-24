#include "common.h"

extern s16 D_0028E1A4_as_s16;
extern s16 D_0028E1A8_as_s16;
extern s16 D_0028E1AC_as_s16;
extern s16 D_0028E1B0_as_s16;
extern s16 D_0028E1B4_as_s16;
extern s16 D_0028E1B8_as_s16;

void func_0016A6F0(void) {
    D_0028E1B8_as_s16 = 0;
    D_0028E1B4_as_s16 = 0;
    D_0028E1B0_as_s16 = 0;
    D_0028E1AC_as_s16 = 0;
    D_0028E1A8_as_s16 = 0;
    D_0028E1A4_as_s16 = 0;
}

s32 func_00236F40();
s32 death_func_00136980();
extern u16 D_0028E1AC;
extern u16 D_0028E1B8;
extern u16 g_arcade_input_port_as_u16_a[];
extern u8 g_paused;

void func_0016A710(void) {
    u32 t;
    u32 t2;

    if (g_paused != 0) return;
    reg_a0 = (u8 *)g_arcade_input_port_as_u16_a;
    reg_d0.h[0] = *(u16 *)reg_a0;
    t = reg_d0.h[0];
    reg_d1.h[0] = t;
    reg_d1.h[0] = (s32) reg_d1.h[0] >> 8;
    if (t & 1) {
        reg_d0.h[0] = (s32) t >> 1;
        reg_d0.h[0] |= 0x8000;
    } else {
        reg_d0.h[0] = (s32) t >> 1;
    }
    t2 = reg_d1.h[0];
    if (t2 & 1) {
        reg_d1.h[0] = (s32) (t2 & 0xFFFF) >> 1;
        reg_d1.h[0] |= 0x8000;
    } else {
        reg_d1.h[0] = (s32) (t2 & 0xFFFF) >> 1;
    }
    reg_d0.h[0] = ~reg_d0.sh[0];
    reg_d1.h[0] = ~reg_d1.sh[0];
#ifdef DEATH_LABEL
    death_func_00136980();
#endif
    func_00236F40();
    D_0028E1B8 = reg_d0.h[0];
    D_0028E1AC = reg_d1.h[0];
}

extern u16 D_0028E1A4;
extern u16 D_0028E1A8;
extern u16 D_0028E1B0;
extern u16 D_0028E1B4;

void func_0016A7F0(void) {
    s32 sd0 = reg_d0.w;
    s32 sd1 = reg_d1.w;
    s32 sd2 = reg_d2.w;
    s32 sd3 = reg_d3.w;
    s32 sd4 = reg_d4.w;
    s32 sd5 = reg_d5.w;
    s32 sd6 = reg_d6.w;
    s32 sd7 = reg_d7.w;

    reg_d0.h[0] = D_0028E1B8;
    reg_d1.h[0] = D_0028E1AC;
    reg_d2.h[0] = D_0028E1B0;
    reg_d3.h[0] = D_0028E1A4;
    reg_d2.h[0] = ~reg_d2.h[0];
    reg_d3.h[0] = ~reg_d3.h[0];
    D_0028E1B0 = reg_d0.h[0];
    D_0028E1A4 = reg_d1.h[0];
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d3.h[0] &= reg_d1.h[0];
    D_0028E1B4 = reg_d2.h[0];
    D_0028E1A8 = reg_d3.h[0];
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
}

void func_0016A8B0(void) {
    *(u16 *)&reg_d0 = D_0028E1B8;
}

void func_0016A8C0(void) {
    *(u16 *)&reg_d0 = D_0028E1AC;
}

void func_0016A8D0(void) {
    *(u16 *)&reg_d0 = D_0028E1B4;
}

void func_0016A8E0(void) {
    *(u16 *)&reg_d0 = D_0028E1A8;
}

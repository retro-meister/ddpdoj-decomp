#include "common.h"
extern s8 D_0028E368;
extern s8 D_0028ED7C;
extern s8 D_0028DF84;
extern u8 *reg_a5;
extern void func_00206D70(void);
extern void func_002071C0(void);
extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern s32 func_0022B2F0(void);
extern void func_002376F0(void);
extern u8 D_0028ED58;
extern u8 D_0028ED68;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;

static void func_00238910(void)
{
    u32 saved_d0;
    u32 saved_d1;
    u32 saved_d2;
    u32 saved_d3;
    u32 saved_d4;
    u32 saved_d5;
    u32 saved_d6;
    u32 saved_d7;

    D_0028ED7C = 2;

    saved_d0 = reg_d0.w;
    saved_d1 = reg_d1.w;
    saved_d2 = reg_d2.w;
    saved_d3 = reg_d3.w;
    saved_d4 = reg_d4.w;
    saved_d5 = reg_d5.w;
    saved_d6 = reg_d6.w;
    saved_d7 = reg_d7.w;

    D_0028DF84 = 0;
    D_0028E368 = 0;
    reg_a5[3] = 1;
    *(u16 *)(reg_a5 + 0xC) = 0;

    reg_d0.w = saved_d0;
    reg_d1.w = saved_d1;
    reg_d2.w = saved_d2;
    reg_d3.w = saved_d3;
    reg_d4.w = saved_d4;
    reg_d5.w = saved_d5;
    reg_d6.w = saved_d6;
    reg_d7.w = saved_d7;
}

void func_00238980(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 step;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    step = *(u16 *)(reg_a5 + 12);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00238910();
        return;
    }
    switch (step) {
    case 0:
        if (D_0028ED58 != 0) {
            D_0028ED68 = 0;
            func_002376F0();
            return;
        }
        if (func_0022B2F0() != 0) {
            if (D_0028ED68 != 0) {
                step++;
            } else {
                func_002376F0();
                return;
            }
        }
        break;
    default:
        func_00215DB0(0, 0, 0x1C2, 0xE0, 0x50, step * 8, 0xFF, 0xFF, 0xFF);
        step++;
        break;
    case 16:
        func_00215DB0(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        D_0028E368 = 1;
        D_0028ED7C = 2;
        func_00206D70();
        reg_d0.h[0] = 20;
        func_002071C0();
        *(u8 *)(reg_a0 + 5) = 3;
        return;
    }
    *(u16 *)(reg_a5 + 12) = step;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}

#include "common.h"

extern void func_0015BA20(void);
extern void func_0015BD00(void);
extern void func_002071C0(void);
extern void stage_load_step(void);
extern void func_00225630(void);
extern void func_002256B0(void);
extern void func_00227120(void);
extern void func_002271D0(void);
extern void func_00237330(void);
extern u8 D_0028E350;
extern s16 D_0028E3FC;
extern u16 D_0028E91C;
extern u8 g_cd_async_state_as_u8;
extern u8 g_cd_async_busy_as_u8;
extern s8 D_0028EC20;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00237470(void) {
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
    step = *(u16 *)(reg_a5 + 8);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00237330();
        return;
    }
    switch (step) {
    default:
        step++;
        break;
    case 0:
        g_cd_async_busy_as_u8 = 1;
        D_0028E350 = 0;
        g_cd_async_state_as_u8 = 0;
        func_00225630();
        D_0028E91C = 0;
        step++;
        break;
    case 1:
        stage_load_step();
        if (D_0028E3FC == D_0028E91C) {
            func_002256B0();
            step++;
        }
        break;
    case 2:
        step++;
        func_0015BA20();
        func_0015BD00();
        if (D_0028EC20 != 0) {
            func_002271D0();
        } else {
            func_00227120();
        }
        break;
    case 4:
        reg_d0.h[0] = 8;
        func_002071C0();
        *(u16 *)(reg_a0 + 4) = 15;
        *(u8 *)(reg_a5 + 3) = 2;
        break;
    }
    *(u16 *)(reg_a5 + 8) = step;
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

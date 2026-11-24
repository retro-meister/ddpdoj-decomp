#include "common.h"

extern s8 D_0028E408;

s32 func_00131440();
s32 func_00135110();
s32 func_001719A0();
s32 func_001719B0();
s32 func_001719D0();
s32 func_0018D190();
s32 func_0022C450();
extern u8 D_0028E298;
extern u8 D_0028E2C4;
extern u8 D_0028E2C8;
extern u8 D_0028E2D4;
extern u8 D_0028E2E4;
extern u8 D_0028E370;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u16 D_0028E59C;
extern u16 D_0028E910;
extern u8 D_00684C88[];
extern u16 D_00684C8A[];
extern u16 D_00684C8C[];
extern u8 D_00684C8E[];
extern u8 D_00684C90[];
extern u16 D_00684C94[];
#ifdef DEATH_LABEL
s32 fade_reset();
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u16 death_D_00290DB8_as_u16;
extern u16 death_D_00290DB4_as_u16;
extern u16 D_0028E614;
extern u16 D_0028E610;
#endif
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_0022C1F0(void) {
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
    func_001719D0();
    switch (D_00684C94[0]) {                           /* irregular */
    default:
        D_00684C94[0] += 1;
        break;
    case 0:
        func_001719A0();
        D_00684C94[0] += 1;
        break;
#ifdef DEATH_LABEL
    case 2:
        fade_reset();
        D_00684C94[0] += 1;
        break;
#endif
    case 16:
        D_0028E2C8 = 1;
        D_0028E2E4 = 0;
        D_0028E2D4 = 0xFF;
        D_0028E2C4 = 0;
        D_0028E38C = D_00684C88[0];
        D_0028E388 = D_00684C90[0];
        D_0028E384 = D_00684C8E[0];
        func_0022C450(D_00684C88[0]);
        D_0028E298 = 1;
#ifdef DEATH_LABEL
        if (death_D_00290DC0 != 0) {
            death_D_00290DBC = 1;
            D_0028E614 = death_D_00290DB8_as_u16;
            D_0028E610 = death_D_00290DB4_as_u16;
        }
#endif
        D_00684C94[0] += 1;
        break;
#ifdef DEATH_LABEL
    case 17:
        death_D_00290DBC = 0;
        D_00684C94[0] += 1;
        break;
#endif
    case MAIN_OR_DEATH_LABEL(17, 18):
        if (D_0028E59C == 0) {
            D_00684C94[0] += 1;
        }
        break;
    case MAIN_OR_DEATH_LABEL(18, 19):
        func_00131440();
        if (D_0028E370 != 0) {
            D_0028E298 = 0;
            D_00684C94[0] += 1;
            D_0028E910 = D_00684C8A[0];
            func_00135110();
#ifdef DEATH_LABEL
            fade_reset();
#endif
            if (D_00684C8C[0] == 0) {
                func_0018D190();
            }
        }
        break;
    case MAIN_OR_DEATH_LABEL(19, 20):
        func_001719B0();
        if (D_0028E408 == 0) {
            (*(s8 *)((u8 *)(reg_a5) + (3))) = 2;
        }
        break;
    }
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

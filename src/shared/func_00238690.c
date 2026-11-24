#include "common.h"

extern void func_00131440(void);
extern void func_00135100(void);
extern void func_00135110(void);
extern void func_001719A0(void);
extern void func_001719B0(void);
extern void func_001719D0(void);
extern void func_0018D190(void);
extern void func_00236DF0(void);
extern void func_00238520(void);
extern s8 D_0028E408;
extern s8 D_0028E298;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 D_0028E2C8;
extern u8 D_0028E2D4;
extern u8 D_0028E2E4;
extern u8 D_0028E370;
extern u8 D_0028E38C;
extern u16 D_0028E59C;
extern u16 D_0028E910;
extern s8 D_0028ED5C;
extern u8 D_006E5BEA[];
extern u16 D_006E5BEC[];
extern u16 D_006E5BEE[];
extern u8 D_006E5BF8[];
extern u8 D_006E5BFA[];
extern u16 D_006E5BFE[];
extern u8 D_006E5C00[];
extern u8 D_006E5C04[];
extern u8 D_006E5C0A[];
extern u8 D_006E5C0C[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00238690(void) {
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
    step = *(u16 *)(reg_a5 + 4);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00238520();
        return;
    }
    func_001719D0();
    switch (step) {
    default:
        step++;
        break;
    case 0:
        func_001719A0();
        step++;
        break;
    case 16:
        D_0028E38C = D_006E5BEA[0];
        D_0028E2E4 = D_006E5C04[0];
        D_0028E2C8 = D_006E5BF8[0];
        D_0028E2C4 = D_006E5BFA[0];
        D_0028E2D4 = D_006E5C00[0];
        D_0028E2B0 = D_006E5C0A[0];
        D_0028E2AC = D_006E5BFE[0];
        D_0028E2A8 = D_006E5C0C[0];
        func_00236DF0();
        func_00135100();
        step++;
        D_0028E298 = 1;
        break;
    case 17:
        if (D_0028E59C == 0) {
            D_0028ED5C = 0;
            step++;
        }
        break;
    case 18:
        func_00131440();
        if (D_0028E370 != 0) {
            D_0028E298 = 0;
            step++;
            D_0028E910 = D_006E5BEC[0];
            func_00135110();
            if (D_006E5BEE[0] == 0) {
                func_0018D190();
            }
        }
        break;
    case 19:
        func_001719B0();
        if (D_0028E408 == 0) {
            *(u8 *)(reg_a5 + 3) = 2;
        }
        break;
    }
    *(u16 *)(reg_a5 + 4) = step;
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

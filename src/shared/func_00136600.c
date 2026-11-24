#include "common.h"

s32 func_00136400();
s32 func_001AEF50();
extern u16 D_0028E3C0;
extern u16 D_0028E91C;
extern u16 D_0028E92C;
extern u16 D_0028E930;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u16 D_0028E93C;
extern u16 D_0028E940;
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00136600(void) {
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
    u8 *save_a6;
    s32 var_v0;
    u32 temp_a2;

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
    save_a6 = reg_a6;
    if (D_0028E93C != 0) {
        temp_a2 = reg_d0.h[0];
        D_0028E99C = -1;
        D_0028E998 = -1;
        D_0028E938 = temp_a2;
        D_0028E93C = 0;
        D_0028E930 = reg_d1.h[0];
        D_0028E934 = reg_d2.h[0];
        D_0028E92C = reg_d3.h[0];
        D_0028E940 = reg_d4.h[0];
        reg_d0.h[0] = D_0028E938;
        reg_d1.h[0] = D_0028E934;
        reg_d2.h[0] = D_0028E930;
        reg_d3.h[0] = D_0028E92C;
        func_001AEF50();
        var_v0 = D_0028ED80 == 1;
        reg_d7.w = 0;
        if (var_v0 == 0) {
            var_v0 = D_0028ED7C == 2;
        }
        if (((var_v0 != 0) || (D_0028E3C0 != 0)) && (D_0028E91C == 0)) {
            reg_d7.h[0] = 0x38;
        }
        reg_d6.h[0] = D_0028E940;
        func_00136400();
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
    reg_a6 = save_a6;
}

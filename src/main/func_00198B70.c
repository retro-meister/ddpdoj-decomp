#include "common.h"

s32 func_00197F60();
s32 func_001980A0();
s32 func_00198C40();
s32 func_00198D90();
extern u8 *reg_a5;

void func_00198B70(void) {
    u8 temp_a0;

    temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (3)));
    if (temp_a0 == 0) {
        func_00197F60(temp_a0, reg_a5);
        return;
    }
    if (temp_a0 == 2) {
        func_001980A0(temp_a0, reg_a5);
        return;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (4)));
    if (reg_d0.b[0] == 0) {
        func_001980A0(reg_d0.b[0], reg_a5);
        return;
    }
    if (reg_d0.b[0] == 3) {
        func_00198C40(reg_d0.b[0], reg_a5);
        reg_d0.w = 3;
        func_00198D90();
        return;
    }
    if (reg_d0.w & 1) {
        func_00198C40(reg_d0.w, reg_a5);
        return;
    }
    if (reg_d0.w & 2) {
        func_00198D90(reg_d0.w, reg_a5);
    }
}

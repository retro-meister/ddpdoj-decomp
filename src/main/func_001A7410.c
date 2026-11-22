#include "common.h"


extern s8 D_0028E408;

s32 func_0016A8B0();
s32 func_0016A8C0();
extern u16 D_0028E648;
extern s8 D_0028EC24;
extern u8 D_0028ED7C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
void func_001A7410(void) {
    u32 temp_s0;
    u32 temp_v1;

    reg_d0.h[0] = D_0028E648;
    reg_d0.h[0] -= 1;
    if ((s16) reg_d0.h[0] < 0) {
        D_0028E408 = 0;
        return;
    }
    reg_d0.w = 0;
    if (D_0029F260[0] < 0) {
        func_0016A8B0();
        if ((D_0028ED7C == 2) && (D_0028EC24 == 1)) {
            func_0016A8C0();
        }
    }
    if (D_0029F1F0[0] < 0) {
        temp_s0 = reg_d0.h[0];
        func_0016A8C0();
        if ((D_0028ED7C == 2) && (D_0028EC24 == 0)) {
            func_0016A8B0();
        }
        reg_d0.h[0] |= temp_s0 & 0xFFFF;
    }
    temp_v1 = reg_d0.b[0] & 0x70;
    reg_d0.b[0] = temp_v1;
    if (!(temp_v1 & 0xFF)) {
        D_0028E408 = 0;
        return;
    }
    reg_d7.h[0] = D_0028E648;
    D_0028E408 = 1;
    D_0028E648 = 0;
    reg_d7.w -= 1;
}

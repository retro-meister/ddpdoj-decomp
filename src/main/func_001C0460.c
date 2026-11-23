#include "common.h"

s32 func_00128930();
extern u16 D_0028E910;

void func_001C0460(void) {
    reg_d5.b[0] = 2;
    if (D_0028E910 != 0) {
        reg_d5.b[0] = 3;
    }
    reg_d0.w = 0xFFFC0007;
    reg_d1.b[0] -= reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    func_00128930();
    reg_d0.w = 0xFFFD0007;
    reg_d1.b[0] += reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    func_00128930();
    reg_d0.w = 0xFFFE0007;
    reg_d1.b[0] += reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    func_00128930();
    if (D_0028E910 != 0) {
        reg_d0.w = 0xFFFF0007;
        reg_d1.b[0] += reg_d5.b[0];
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
            reg_d0.w += 0x80000;
        }
        func_00128930();
        reg_d0.w = 7;
        reg_d1.b[0] += reg_d5.b[0];
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
            reg_d0.w += 0x80000;
        }
        func_00128930();
    }
}

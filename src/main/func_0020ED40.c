#include "common.h"

s32 func_0018DD40();
s32 func_001A35A0();
s32 func_00206520();
s32 func_0020ED20();
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0020ED40(void) {
    reg_d0.w = 0;
    func_00206520();
    reg_d0.w = 1;
    func_00206520();
    if (D_0028E910 == 0) {
        func_0018DD40();
    }
    (*(s16 *)((u8 *)(reg_a6) + (0x32))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x5A))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x5E))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x60))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0))) = 7;
    func_0020ED20();
    func_001A35A0();
    if (reg_d7.h[0] != 0) {
        reg_a0 = (u8 *)(reg_a6 + 0x70);
    } else {
        reg_a0 = (u8 *)(reg_a6 - 0x70);
    }
    if ((D_0028E910 != 0) || ((*(u8 *)((u8 *)(reg_a0) + (1))) == 0)) {
        func_0020ED20();
        reg_d0.h[0] += 1;
        reg_d0.h[0] &= 1;
        func_001A35A0();
    }
}

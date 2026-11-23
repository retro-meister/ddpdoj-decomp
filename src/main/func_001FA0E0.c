#include "common.h"

s32 func_002011A0();
extern u16 D_0028E3F0;
extern u16 D_0028E910;
extern u8 *reg_a6;

void func_001FA0E0(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x4E))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x4A))) = 0x258;
    (*(s16 *)((u8 *)(reg_a6) + (0x48))) = 0x202;
    reg_d0.w = 3;
    if (D_0028E910 != 0) {
        reg_d0.w = 2;
    }
    if (!(D_0028E3F0 & 2)) {
        (*(u8 *)((u8 *)(reg_a6) + (0x49))) += reg_d0.b[0];
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x48))) += reg_d0.b[0];
    func_002011A0();
    reg_d0.b[0] -= 0x20;
    (*(u8 *)((u8 *)(reg_a6) + (0x4D))) = (u8) reg_d0.b[0];
}

#include "common.h"


extern s8 D_0028E408;

s32 func_0013E760();
s32 func_0013E790();
s32 func_0016BFD0();
s32 func_0016C0B0();
s32 func_0016C0C0();
s32 func_0016C2A0();
s32 func_0018D9B0();
extern u8 D_0026AE40[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016BF00(void) {
    u32 temp_v0;

    if (!(reg_d1.w & 0x2000)) {
        (*(u8 *)((u8 *)(reg_a6) + (1))) |= 0x20;
        func_0016C0B0();
        (*(s16 *)((u8 *)(reg_a6) + (0xC))) = 0x202;
        (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0;
    }
    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        func_0018D9B0();
        if (reg_d1.w & 0x1000) {
            func_0013E760();
        } else {
            func_0013E790();
        }
        reg_a0 = D_0026AE40;
        func_0016C2A0();
        return;
    }
    func_0016C0C0();
    if (D_0028E408 == 0) {
        func_0016BFD0();
    }
}

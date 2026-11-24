#include "common.h"

s32 func_001D36C0();
s32 func_002010A0();
s32 func_00201C60();
s32 func_002024C0();
extern Reg32 D_0028E484;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D3A20(void) {
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3600) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.b[0] >= 0x5200) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    if ((s32) reg_d1.h[0] >= 0x6600) {
        if ((s32) reg_d1.h[0] < 0x6A00) {
            func_001D36C0();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    func_001D36C0();
}

#include "common.h"

s32 func_00158ED0();
s32 func_002026F0();
extern s8 D_0028E408;
extern u8 *reg_a6;

void func_00158E10() {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002026F0();
    if (D_0028E408 == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x2E))) = (u8) reg_d1.b[0];
        reg_d1.b[0] -= 0x30;
        (*(u8 *)((u8 *)(reg_a6) + (0x30))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002026F0();
        (*(u8 *)((u8 *)(reg_a6) + (0x2F))) = (u8) reg_d1.b[0];
        reg_d1.b[0] += 0x30;
        (*(u8 *)((u8 *)(reg_a6) + (0x31))) = (u8) reg_d1.b[0];
        (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 2;
        (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x16;
        func_00158ED0();
    }
}

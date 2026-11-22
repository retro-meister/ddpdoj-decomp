#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001A17C0(void) {
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
    if ((*(u8 *)((u8 *)(reg_a4) + (0x39))) != reg_d0.b[0]) {
        (*(u8 *)((u8 *)(reg_a6) + (0x4A))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a6) + (0x4A))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x1B))) -= 1;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
            reg_d0.h[0] -= 2;
            reg_d0.h[0] >>= 1;
            reg_d0.h[0] += 4;
            (*(u8 *)((u8 *)(reg_a6) + (0x4A))) = (u8) reg_d0.b[0];
        }
    }
}

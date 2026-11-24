#include "common.h"

extern s8 D_0028E408;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00202D00(void) {
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] -= reg_d2.h[0];
    if (((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    D_0028E408 = 0;
}

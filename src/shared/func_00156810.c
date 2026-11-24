#include "common.h"

extern s16 D_0028E88C_as_s16;
extern s16 D_0028E890_as_s16;
extern s16 D_0028E894_as_s16;
extern u8 *reg_a5;

void func_00156810(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x3A)));
    if (reg_d0.h[0] == 0x48) {
        D_0028E894_as_s16 = 0;
    }
    if (reg_d0.h[0] == 0x8D) {
        D_0028E890_as_s16 = 0;
    }
    if (reg_d0.h[0] == 0xAC) {
        D_0028E88C_as_s16 = 0;
    }
}

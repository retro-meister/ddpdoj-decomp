#include "common.h"

extern u16 D_0028E910;
extern u8 *reg_a4;

void func_001B5CD0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (2))) = 6;
    (*(u16 *)((u8 *)(reg_a4) + (0x14))) = 0xFFFA;
    if (D_0028E910 != 0) {
        (*(s8 *)((u8 *)(reg_a4) + (2))) = 3;
        (*(u16 *)((u8 *)(reg_a4) + (0x14))) = 0xFFFB;
    }
}

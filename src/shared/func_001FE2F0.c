#include "common.h"

extern u16 D_0028E910;
extern u8 *reg_a6;

void func_001FE2F0(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x66))) = 1;
    (*(s16 *)((u8 *)(reg_a6) + (0x6C))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x6E))) = 0x1818;
    if (D_0028E910 != 0) {
        (*(s16 *)((u8 *)(reg_a6) + (0x6E))) = 0x404;
    }
}

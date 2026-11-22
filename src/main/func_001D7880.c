#include "common.h"

extern u8 *reg_a6;

void func_001D7880(void) {
    (*(u16 *)((u8 *)(reg_a6) + (0xC6))) += 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xC6))) >= 0x18) {
        (*(u16 *)((u8 *)(reg_a6) + (0xC6))) = 0U;
    }
}

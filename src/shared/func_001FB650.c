#include "common.h"

extern u8 *reg_a6;

void func_001FB650(void) {
    if ((*(u16 *)((u8 *)(reg_a6) + (0x68))) == 0) {
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0xC40;
        if ((*(s16 *)((u8 *)(reg_a6) + (4))) < 0x1C01) {
            (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0xCC0;
        }
    }
    if ((*(s16 *)((u8 *)(reg_a6) + (4))) >= 0x5400) {
        (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
    }
    if ((*(s16 *)((u8 *)(reg_a6) + (4))) < -0x1BFF) {
        (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
    }
}

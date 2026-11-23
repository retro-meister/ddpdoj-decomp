#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D7C20(s32 id) {
    *(u16 *)(reg_a4 + 4) = 0;
    *(u16 *)(reg_a4 + 6) = 1;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) = 0;
    reg_tmp.w = id;
    (*(u8 *)(reg_a6 + reg_tmp.h[0] + ((reg_tmp.h[0] & 1) ? -1 : 1)))++;
}

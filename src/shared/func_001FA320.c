#include "common.h"

s32 func_00201710(void *);
extern s8 D_0028E408;
extern u8 *reg_a6;

void func_001FA320(void) {
    if (((*(u8 *)((u8 *)(reg_a6) + (0x7E))) != 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x67))) == 0)) {
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        func_00201710(reg_a6);
        (*(u16 *)((u8 *)(reg_a6) + (0x70))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x70))) == 0) {
            (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
        }
    }
    D_0028E408 = 0;
}

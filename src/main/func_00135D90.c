#include "common.h"

s32 func_00207600();                            /* extern */
extern u16 D_0028E4AA;
extern u16 D_0028E850;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00135D90(void) {
    D_0028E850 += 1;
    D_0028E4AA = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    func_00207600();
    (*(s8 *)((u8 *)(reg_a0) + (3))) = 3;
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}

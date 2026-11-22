#include "common.h"

s32 func_001DF350();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E4520(void) {
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0x8080;
    reg_a6 += 0x40;
    func_001DF350();
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a6 = (void *) reg_tmp.w;
    (*(u8 *)((u8 *)(reg_a6) + (0x5C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
}

#include "common.h"

s32 func_002011A0();
extern u8 *reg_a6;

void func_001F9ED0(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x2A))) = 0x258;
    (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 0x104;
    func_002011A0();
    reg_d0.h[0] &= 0x1F;
    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = 0x40U;
    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x2C))) = 0U;
    reg_d7.h[0] = 0x3B;
    do {
        (*(u8 *)((u8 *)(reg_a6) + (0x2C))) += 1;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) += reg_d0.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

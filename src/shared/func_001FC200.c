#include "common.h"

s32 func_0014E370();
extern u16 D_00265F70[];
extern u16 D_00265F80[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FC200(void) {
    reg_a0 = (u8 *)(D_00265F80);
    func_0014E370();
    reg_a0 = (u8 *)(D_00265F70);
    reg_d0.h[0] = 7;
    reg_a1 = (u8 *)(reg_a5 + 0x1C);
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x1C))) |= 0x40;
    }
}

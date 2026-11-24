#include "common.h"

s32 func_001C9C50();
s32 func_002021F0(void *);
extern u8 D_0026C860[];
extern u8 *reg_a0;
extern u16 *reg_a4;
extern u8 *reg_a6;

void func_001C9BC0(void) {
    *reg_a4 = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 4;
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0(reg_a6);
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_001C9C50();
}

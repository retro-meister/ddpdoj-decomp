#include "common.h"

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u8 D_00260870[];
extern u8 D_00265870[];
extern u8 D_00265890[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F8710(void) {
    u16 temp_a0;
    u32 temp_a2;

    reg_a0 = D_00265890;
    func_0014E370();
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    temp_a2 = reg_d0.w;
    reg_d0.w = temp_a2 + 0x02000000;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    (*(u16 *)((u8 *)(reg_a5) + (0x32))) = temp_a0;
    reg_a0 = D_00265870;
    reg_d0.w = 0xE;
    func_0014E300();
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x2801) {
        func_0014E290();
        return;
    }
    reg_d0.h[0] = 0x15;
    reg_a0 = D_00260870;
    func_001A3020();
}

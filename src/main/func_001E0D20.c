#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_002010A0();
s32 func_002011A0();
extern u8 D_00263A30[];
extern u8 D_00263EF0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E0D20(void) {
    u16 temp_a1;

    reg_a0 = D_00263A30;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = temp_a1;
    reg_a0 = D_00263EF0;
    reg_d0.w = 7;
    func_0014E300();
    func_002010A0();
    reg_tmp.h[0] = (u16) (s8) reg_d0.b[0];
    reg_d0.h[0] = reg_tmp.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] * 8;
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += reg_d0.h[0];
    func_002011A0();
    if ((s8) reg_d0.b[0] < 0) {
        (*(s8 *)((u8 *)(reg_a6) + (0x1D))) = 0x40;
        (*(u16 *)((u8 *)(reg_a5) + (0x1C))) *= 0xFFFF;
    }
}

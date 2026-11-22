#include "common.h"

s32 func_00201160();
s32 func_002011A0();
s32 func_00201230();
extern u16 D_00264570[];
extern u32 D_0028D9FC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001ED410(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264570);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9FC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_00201160();
    reg_d0.b[0] += 0x60;
    (*(u8 *)((u8 *)(reg_a4) + (0xF))) = (u8) reg_d0.b[0];
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0xE))) *= -1;
    }
    func_00201230();
    reg_d0.w = (u32) (s16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x1C))) = (u16) reg_d0.h[0];
    reg_d0.h[0] += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) = (u16) reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1EE)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
}

#include "common.h"

s32 func_00201F70(u8, void *);                  /* extern */
extern u16 D_0028E8A0;
extern u8 *reg_a6;

void func_00201F20(void) {
    u8 temp_a0;

    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.w = 0;
    temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] = temp_a0;
    if (D_0028E8A0 != 0) {
        reg_d3.w = 0;
        reg_d2.w = 0;
        return;
    }
    func_00201F70(temp_a0, reg_a6);
}

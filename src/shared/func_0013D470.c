#include "common.h"

s32 func_0019DB50();
extern u16 D_0028E4A2;
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_0013D470(void) {
    u16 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a0) + (1)));
    (*(u8 *)((u8 *)(reg_a0) + (1))) -= 1;
    if (((s32) reg_tmp.b[0] <= 0) && ((*(u8 *)((u8 *)(reg_a0) + (1))) = (u8) (*(u8 *)((u8 *)(reg_a0) + (0))), reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0))), reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2))), reg_tmp.w += 1, (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1], (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0], (reg_tmp.w == 0xC3A))) {
        (*(u8 *)((u8 *)(reg_a0) + (1))) = 0x10U;
    } else {
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
        if (reg_tmp.w == 0xC41) {
            reg_tmp.w = 0xC36;
            (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
        }
    }
    D_0028E4A2 = (*(u16 *)((u8 *)(reg_a1) + (0)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a1) + (2)));
    reg_d2.h[0] = temp_a0;
    reg_d3.h[0] = 0x270;
    reg_d4.h[0] = 9;
    func_0019DB50();
}

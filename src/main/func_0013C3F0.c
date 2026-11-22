#include "common.h"

s32 func_0013C300();
s32 func_0013C350();
s32 func_0013C4B0();
extern s8 D_0028E408;
extern u8 D_0029C0C0[];
extern u8 *reg_a0;

void func_0013C3F0(void) {
    u16 temp_a0;
    reg_d7.w = 2;
    reg_a0 = D_0029C0C0;
    do {
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        if ((s16) reg_tmp.h[0] < 0) {
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0x2C)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x2E)));
            func_0013C4B0();
            temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            if ((temp_a0 != 0) && (temp_a0 == 1)) {
                reg_d0.w = (u32) reg_a0;
                func_0013C350();
                if (D_0028E408 == 0) {
                    reg_d0.w = (u32) reg_a0;
                    func_0013C300();
                }
            }
        }
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

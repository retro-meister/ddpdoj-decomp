#include "common.h"

s32 func_001A34C0();                            /* extern */
s32 func_001A3560();                            /* extern */
s32 func_001A35A0();                            /* extern */
extern u8 D_0028E390;
extern s8 D_0028E39C;
extern u16 D_0028E910;
extern u8 *reg_a4;

void func_001A3630(void) {
    u8 *temp_s0;

    if (D_0028E39C >= 9) {
        func_001A3560();
        return;
    }
    if (D_0028E390 == 1) {
        func_001A3560();
        return;
    }
    if (D_0028E910 != 0) {
        func_001A35A0();
        return;
    }
    temp_s0 = reg_a4;
    func_001A34C0();
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) != 0xC) {
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 1;
        (*(u16 *)((u8 *)(reg_a4) + (2))) = 0xCU;
    }
    reg_a4 = temp_s0;
}

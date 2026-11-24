#include "common.h"

s32 func_00124B20();
s32 func_00124C70();
s32 func_00125060(void *);
s32 func_001D36C0();
s32 func_00201C60();
extern s8 D_0028E408;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D3810(void) {
    u8 temp_v1;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
    (*(u8 *)((u8 *)(reg_a4) + (1))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0)));
        temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
        if (temp_v1 != 4) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (temp_v1 - 1);
            goto block_5;
        }
        reg_d0.w = 7;
        func_00125060(reg_a6 + 0x1B);
        if (D_0028E408 == 0) {
            reg_d0.w = 0;
            func_00124C70();
            reg_d0.w = 2;
            func_00124B20();
            func_001D36C0();
            return;
        }
        goto block_5;
    }
block_5:
    func_00201C60();
    func_001D36C0();
}

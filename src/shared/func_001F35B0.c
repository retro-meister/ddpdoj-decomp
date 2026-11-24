#include "common.h"

s32 func_001251C0();
s32 func_001F5630();
extern u16 D_0028E89C;
extern u8 *reg_a4;

void func_001F35B0() {
    u16 temp_a0;
    u16 temp_v1;

    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_a0 - 1);
            if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
                reg_d0.w = 4;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (4)));
        if (temp_v1 != 0) {
            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (temp_v1 - 1);
            if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
                func_001F5630();
            }
        }
    }
}

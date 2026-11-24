#include "common.h"

s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u8 *reg_a4;

void func_001BA310() {
    u8 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 1) {
        reg_d0.w = 0;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                reg_d0.w = 0;
                func_001251C0();
            }
        }
    }
}

#include "common.h"

s32 func_00124B20(void *);                      /* extern */
s32 func_00125060();                            /* extern */
s32 func_00125250(void *);                      /* extern */
extern s8 D_0028E408;
extern u8 *reg_a4;

void func_001D3340(void) {
    u16 temp_v1;
    u8 *temp_a0;

    temp_a0 = reg_a4 + 2;
    temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_v1 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
            reg_d0.w = 2;
            func_00124B20(temp_a0);
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    } else {
        reg_d0.w = 8;
        func_00125250(temp_a0);
        if (D_0028E408 == 0) {
            reg_d0.w = 5;
            func_00125060();
            if (D_0028E408 == 0) {
                (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
            }
        }
    }
}

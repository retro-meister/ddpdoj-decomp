#include "common.h"

s32 func_0014E370();                            /* extern */
extern s32 D_002583E0[];
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a5;

void func_00157D90(void) {
    reg_a0_as_s32_p = D_002583E0;
    func_0014E370();
    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 6;
}

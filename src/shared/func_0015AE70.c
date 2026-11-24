#include "common.h"

extern s16 D_0028E874_as_s16;
extern u8 *reg_a5;

void func_0015AE70(void) {
    D_0028E874_as_s16 = 0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x17)));
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x16)));
        D_0028E874_as_s16 = 1;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
            (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 0x10U;
        }
    }
}

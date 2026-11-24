#include "common.h"

s32 func_0020E290();
extern s16 D_0028E098_as_s16;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_0020E230() {
    D_0028E098_as_s16 = 0;
    reg_a2 = reg_a1;
    if ((*(s16 *)((u8 *)(reg_a1) + (0))) < 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a1) + (1)));
        (*(u8 *)((u8 *)(reg_a1) + (1))) |= 2;
        if (reg_tmp.b[0] & 2) {
            func_0020E290();
        }
    }
}

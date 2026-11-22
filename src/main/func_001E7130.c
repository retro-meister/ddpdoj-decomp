#include "common.h"

s32 func_00124F50();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E7130() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (6))) -= 4;
        if ((*(u16 *)((u8 *)(reg_a6) + (6))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            reg_d0.w = 2;
            func_00124F50();
        }
    }
}

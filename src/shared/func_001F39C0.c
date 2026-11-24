#include "common.h"

s32 func_00124510();
extern u8 *reg_a4;

void func_001F39C0() {
    (*(u16 *)((u8 *)(reg_a4) + (2))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
        func_00124510();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}

#include "common.h"

s32 func_001BF730();
s32 func_002011D0();
extern u8 *reg_a4;

void func_001BF6C0(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 5;
    (*(s8 *)((u8 *)(reg_a4) + (8))) = 0;
    (*(u8 *)((u8 *)(reg_a4) + (9))) = 1U;
    func_002011D0();
    if (reg_d0.h[0] != 0) {
        func_001BF730();
        return;
    }
    (*(u8 *)((u8 *)(reg_a4) + (9))) *= -1;
    func_001BF730();
}

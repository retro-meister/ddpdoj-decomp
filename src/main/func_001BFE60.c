#include "common.h"

s32 func_001BFEC0();
s32 func_002010A0();
extern u8 *reg_a4;

void func_001BFE60() {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 1;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x1010;
    func_002010A0();
    reg_d0.b[0] += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    func_001BFEC0();
}

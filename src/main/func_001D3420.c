#include "common.h"

s32 func_00124F50();
s32 func_001251C0();
s32 func_001D4550();
extern u8 *reg_a4;

void func_001D3420() {
    (*(u16 *)((u8 *)(reg_a4) + (2))) -= 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a4) + (2))) < 0) {
        reg_d0.w = 2;
        func_00124F50();
        reg_d0.w = 1;
        func_001251C0();
        reg_d0.w = 2;
        func_001251C0();
        func_001D4550();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}

#include "common.h"

s32 func_0018D580();
s32 func_001D5040();
extern u8 D_00263470[];
extern u16 D_0028E4A2;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001D5150() {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x2F))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
        reg_a1 = D_00263470;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        func_001D5040();
        func_0018D580();
    }
}

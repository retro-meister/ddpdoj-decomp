#include "common.h"

s32 func_0018D4B0();
s32 func_0018D4D0();
extern s32 D_0028EAC0;
extern s8 D_0028EAC8;
extern s8 D_0028EACC;
extern s8 D_0028EB04;
extern s8 D_0028EC24;
extern u8 D_0057CC60[];
extern u8 D_0057CC70[];
void func_00225B90(void) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;

    temp_a1 = D_0028EC24 * 4;
    temp_a0 = *(u32 *)(D_0057CC70 + temp_a1);
    if (temp_a0 & 0x40) {
        D_0028EAC0 = 2;
        D_0028EB04 = 2;
        D_0028EAC8 = 2;
        D_0028EACC += 1;
        func_0018D4B0();
        return;
    }
    if (temp_a0 & 0x20) {
        D_0028EAC0 = 2;
        func_0018D4B0();
        if (D_0028EAC8 == 3) {
            D_0028EACC = 0x40;
            return;
        }
        D_0028EB04 = 2;
        D_0028EACC += 1;
        return;
    }
    temp_a0_2 = *(u32 *)(D_0057CC60 + temp_a1);
    if (temp_a0_2 & 0x1000) {
        func_0018D4D0();
        D_0028EAC8 -= 1;
        if (0 >= D_0028EAC8) {
            D_0028EAC8 = 2;
        }
    } else if (temp_a0_2 & 0x4000) {
        func_0018D4D0();
        D_0028EAC8 += 1;
        if (D_0028EAC8 >= 3) {
            D_0028EAC8 = 1;
        }
    }
}

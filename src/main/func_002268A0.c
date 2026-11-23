#include "common.h"

s32 func_0018D4B0();
s32 func_0018D4D0();
s32 func_002263F0();
extern u8 D_0028EC34;
extern s8 D_0028EC3C;
extern s8 D_0028EC40;
extern u8 D_0057CC60[];
extern u8 D_0057CC70[];
extern u8 D_006A0E50[];
void func_002268A0(void) {
    s32 temp_a0;
    s32 temp_a0_3;
    u16 temp_a0_2;

    temp_a0 = *(u32 *)(D_0057CC70 + (D_0028EC34 * 4));
    if (temp_a0 & 0x40) {
        func_0018D4B0();
        func_002263F0();
    } else if (temp_a0 & 0x20) {
        temp_a0_2 = *(u16 *)(D_006A0E50 + (D_0028EC40 << 0xA));
        if ((temp_a0_2 != 0) && (temp_a0_2 != 3)) {
            D_0028EC3C = 6;
            func_0018D4B0();
        }
    }
    temp_a0_3 = *(u32 *)(D_0057CC60 + (D_0028EC34 * 4));
    if (temp_a0_3 & 0x1000) {
        func_0018D4D0();
        D_0028EC40 -= 1;
        if (0 > D_0028EC40) {
            D_0028EC40 = 9;
        }
    } else if (temp_a0_3 & 0x4000) {
        func_0018D4D0();
        D_0028EC40 += 1;
        if (D_0028EC40 >= 0xA) {
            D_0028EC40 = 0;
        }
    }
}

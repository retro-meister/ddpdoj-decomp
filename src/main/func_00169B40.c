#include "common.h"

s32 func_00168BA0(u8);                          /* extern */
s32 func_0018DA30();                            /* extern */
extern u8 D_0028E1E6[];
extern u8 D_0028E39C;
extern s8 D_0028EB88;
extern s32 D_0057CC78[];

void func_00169B40(void) {
    if (D_0057CC78[0] & 0x800) {
        if (D_0028E39C == 0x12) {
            D_0028EB88 = 0;
            reg_d0.h[0] = 0xF;
            func_00168BA0(D_0028E39C);
            func_0018DA30();
            return;
        }
        if (D_0028E1E6[0] != 0) {
            D_0028EB88 = 0;
            reg_d0.h[0] = 0xF;
            func_00168BA0(D_0028E39C);
        }
    }
}

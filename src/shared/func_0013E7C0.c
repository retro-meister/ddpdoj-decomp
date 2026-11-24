#include "common.h"

s32 func_0013E8E0();
s32 func_0013F9A0();
extern s16 D_0028E014;
extern s16 D_0028E024;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern u16 D_0028E074;
extern s32 D_0029CD94[];
extern s16 D_0029F260[];
extern u8 D_0029F261[];
void func_0013E7C0(void) {
    u16 temp_a0;

    if (D_0029F260[0] < 0) {
        func_0013F9A0();
        D_0028E024 = 0;
        D_0028E014 = 0;
        if (!(D_0029F261[0] & 0x40) && (D_0029CD94[0] != 0)) {
            temp_a0 = D_0028E074;
            if (temp_a0 != 8) {
                D_0028E074 = temp_a0 + 4;
                func_0013E8E0(temp_a0);
                D_0028E068 -= 1;
                D_0028E06C = D_0028E068;
            }
        }
    }
}

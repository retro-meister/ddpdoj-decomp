#include "common.h"

extern s16 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern s16 D_0029F260[];
extern u8 D_0029F261[];

void func_00203400(void) {
    reg_d0.w = 0;
    if ((D_0029F260[0] < 0) && !(D_0029F261[0] & 1)) {
        reg_d0.w = 0x10;
    }
    if ((D_0029F1F0[0] < 0) && !(D_0029F1F1[0] & 1)) {
        reg_d0.h[0] += 8;
    }
}

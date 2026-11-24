#include "common.h"

extern Reg32 D_0028E484;
extern u16 D_0029C068[];
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_00203060(void) {
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x9000;
    D_0028E484.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += (s16) D_0029C068[0];
    D_0028E484.h[0] = reg_d0.h[0];
    D_0028E484.w += reg_tmp.w;
    if (D_0028E484.h[1] == 0) {
        reg_tmp.w = 0;
        reg_tmp.h[0] = 0x8000;
        D_0028E484.w = 0;
        reg_d0.h[1] += 0x800;
        D_0028E484.h[0] = reg_d0.h[1];
        D_0028E484.w += reg_tmp.w;
    }
    D_0028E408 = 0;
    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
    }
}

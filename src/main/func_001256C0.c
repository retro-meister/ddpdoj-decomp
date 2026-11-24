#include "common.h"

extern s8 D_0028E408;
extern Reg32 D_0028E484;
extern u16 D_0029C068[];
extern u8 *reg_a6;

void func_001256C0(void) {
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += D_0029C068[0];
    D_0028E484.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] == 0) {
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7800;
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.sw;
        reg_d0.h[0] += 0x7800;
    }
    D_0028E408 = 0;
    switch (reg_tmp.h[1]) {
    case 0:
        break;
    default:
        D_0028E408 = 1;
    }
}

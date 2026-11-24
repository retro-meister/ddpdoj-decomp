#include "common.h"


s32 func_001AC340();
s32 func_001AC370();
extern s16 D_0028E000;
extern s16 D_0028E004;
extern u16 D_0028E6E0;
extern u16 D_0028E6E4;
extern u16 D_0029CEA0[];
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u8 *reg_a0;

void func_00122B20(void) {
    reg_d0.w = 0;
    if (D_0028E6E4 != 0) {
        func_001AC340();
    }
    if (D_0028E6E0 != 0) {
        func_001AC370();
    }
    reg_d7.w = 0x2C;
    D_0028E004 = 0;
    D_0028E000 = 0;
    reg_a0 = (u8 *)(D_0029CEA0);
    reg_d0.w = 0;
    D_0029F260[0] &= 0xBF;
    D_0029F1F0[0] &= 0xBF;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

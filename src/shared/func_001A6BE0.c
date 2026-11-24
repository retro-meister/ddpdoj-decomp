#include "common.h"

extern u32 D_0028E484;
extern u16 D_0028E4A6;
extern s16 D_0028E8C0;
extern void func_001A53D0(void);
extern void func_001A8520(void);

void func_001A6BE0(void) {
    if (D_0028E8C0 >= 0) {
        u32 savedRegister;
        u16 savedLow;

        reg_d1.h[0] = 0x5BC0;
        savedRegister = reg_d1.w;
        savedLow = reg_d1.h[0];
        reg_d1.h[0] = 0x2800;
        reg_d2.w = 0xE63;
        reg_d3.h[0] = 0x840;
        reg_d4.h[0] = 9;
        D_0028E484 = savedRegister;
        D_0028E4A6 = savedLow;
        reg_d1.h[0] -= reg_d6.h[0];
        func_001A53D0();
        reg_d7.w = 0;
        func_001A8520();
    }
}

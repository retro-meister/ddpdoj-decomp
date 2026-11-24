#include "common.h"

void func_001286D0(void);
void func_00128710(void);
void func_00128830(void);
extern u8 *D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00128760(void) {
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = D_0028E484.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        func_001286D0();
        return;
    }
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        func_00128710();
        return;
    }
    func_00128830();
}

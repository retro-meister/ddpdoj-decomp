#include "common.h"

void func_001257E0(void);
void func_00201E20(void);
void func_00202760(void);
extern u16 D_0028E3E0;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00125C80(void) {
    if (*(u8 *)(reg_a6 + 0x1F) == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        func_00202760();
        *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
        reg_d0.w = 0x40;
        func_00201E20();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        *(u8 *)(reg_a6 + 0x1F) = 1;
    }
    reg_d0.h[0] = D_0028E3E0;
    if ((reg_d0.b[0] &= *(u8 *)(reg_a6 + 0x1B)) == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(s16 *)reg_a0 >= 0) {
            func_001257E0();
            return;
        }
        func_00202760();
        if (*(u8 *)(reg_a6 + 0x1A) != reg_d1.b[0]) {
            *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
            reg_d0.w = 0x40;
            func_00201E20();
            *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
            *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        }
    }
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d3.h[0];
}

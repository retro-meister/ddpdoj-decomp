#include "common.h"

s32 func_00125310();
s32 func_00202A80();
s32 death_func_0021B180(void);
void death_func_0021B2E0(void);
extern u16 D_00262A50[];
extern u16 D_0028E88C;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_0021BA40(void) {
    D_0028E88C = 0;
    func_00202A80();
    if ((s32) reg_d0.h[0] < 0x2000) {
        D_0028E88C = 1;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] != 0) {
        return;
    }
    *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 7);
    reg_a1 = (u8 *) D_00262A50;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x10);
    death_func_0021B2E0();
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x11);
    *(u8 *)(reg_a4 + 0x10) += reg_d0.b[0];
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    *(s8 *)(reg_a6 + 0x11) = ~*(s8 *)(reg_a6 + 0x11);
    if ((s32) *(u8 *)(reg_a6 + 0x10) < 0x81) {
        *(u8 *)(reg_a6 + 0x10) += 0xA;
    }
    if ((s32) *(u16 *)(reg_a6 + 0x12) < 2) {
        *(u16 *)(reg_a6 + 0x12) += 1;
    }
    if ((s32) *(u16 *)(reg_a6 + 0x14) < 3) {
        *(u16 *)(reg_a6 + 0x14) += 1;
    }
    if (death_func_0021B180()) {
        reg_d0.w = 0x10;
    } else {
        reg_d0.w = 0x11;
    }
    func_00125310();
}

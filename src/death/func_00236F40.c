#include "common.h"

void func_00131440(void);
extern u8 *D_0028E7FC;
extern u16 D_0028E800;
extern u16 D_0028E804;
extern u16 D_0028E80C;
extern u8 death_D_00291195;
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00236F40(void) {
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    reg_d6.h[0] = reg_d0.h[0];
    reg_d0.h[0] &= 0xFF;
    reg_d6.h[0] &= 0xFF00;
    if (D_0028E80C != 0) {
        reg_d7.h[0] = D_0028E800;
        if (reg_d7.h[0] == 0x800) {
            reg_d0.h[0] = 0;
        } else if (D_0028E80C == 1) {
            D_0028E80C = 2;
            func_00131440();
            reg_d0.b[0] = 0;
        } else {
            reg_d0.b[0] = death_D_00291195;
            D_0028E804 -= 1;
            if (!(0 < (s16) D_0028E804)) {
                reg_a0 = D_0028E7FC;
                reg_a0 += D_0028E800;
                reg_d7.w = 0;
                reg_d7.b[0] = *(s8 *)reg_a0;
                D_0028E804 = reg_d7.h[0];
                reg_d0.b[0] = *(s8 *)(reg_a0 + 1);
                D_0028E800 += 2;
                death_D_00291195 = reg_d0.b[0];
            }
        }
    }
    reg_d0.h[0] |= reg_d6.h[0];
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
}

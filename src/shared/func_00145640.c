#include "common.h"

s32 func_0019D400();
s32 func_0019D430();
extern u16 D_0028C610_as_u16_a[];
extern u16 D_0028C638[];
extern u16 D_0028C868[];
extern u16 D_0028E3E4;
extern u16 D_0028E3EC;
extern u16 D_0028E484_as_u16;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00145640(void) {
    u16 save_a;
    u16 save_c;

    save_a = *(u16 *) (reg_a6 + 0xA);
    save_c = *(u16 *) (reg_a6 + 0xC);
    reg_a0 = (u8 *) D_0028C610_as_u16_a;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x58);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = 0;
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    func_0019D400();
    *(u16 *) (reg_a6 + 0xA) = save_a;
    *(u16 *) (reg_a6 + 0xC) = save_c;
    if (D_0028E3EC == 0) {
        return;
    }
    reg_d4.h[0] = 0x1A;
    reg_d7.h[0] = *(u16 *) (reg_a6 + 0x58);
    reg_d7.h[0] *= 2;
    reg_d6.h[0] = 0;
    reg_a0 = (u8 *) D_0028C638;
    reg_a1 = (u8 *) D_0028C868;
    reg_tmp.h[1] = (reg_d7.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d7.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d7.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d6.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d6.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d6.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = (D_0028E3E4 / 2) * 4;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[1] = (reg_d7.h[0]) ? *(u16 *) (reg_a1 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d7.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d7.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *) (reg_a6 + 2);
    reg_d3.h[0] = 0;
    reg_d1.h[0] -= reg_d3.h[0];
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484_as_u16;
    reg_d1.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *) (reg_a6 + 4);
    reg_d3.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = (D_0028E3E4 / 2) * 4;
    func_0019D430();
}

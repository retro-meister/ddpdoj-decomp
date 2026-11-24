#include "common.h"

typedef void (*Fn)();

s32 func_00126ED0();
extern u8 D_00269530[];
extern u8 D_00269550[];
extern u8 D_002695E0[];
extern u8 D_0028DE80;
extern u32 D_0028DE90;
extern u32 D_0028DE94;
extern Reg32 D_0028E484;
extern u16 D_0028E988;
extern u16 D_0029C068[];
extern u16 D_0029C06C[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a6;

void func_00126F10(void) {
    u8 *save_a1;

    reg_a3 = D_002695E0;
    D_0028E988 += 1;
    reg_a3 = *(u8 **) (D_002695E0 + (reg_d0.h[0] & ~3));
    *(u16 *) reg_a0 = reg_d0.h[0];
    *(u16 *) reg_a0 |= 0x8000;
    reg_a0 += 2;
    D_0028DE94 = reg_d1.w;
    D_0028E484.h[1] = *(u16 *) (reg_a6 + 2);
    D_0028E484.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += D_0028E484.w;
    reg_d1.h[0] += D_0029C06C[0];
    *(u16 *) reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xAC00;
    reg_d1.h[0] += 0xE00;
    reg_d1.h[0] += D_0029C068[0];
    D_0028E484.w = 0;
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += 0xAC00;
    if (D_0028E484.h[1] != 0) {
        func_00126ED0();
        return;
    }
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x6000;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    D_0028E484.w = 0;
    reg_d1.h[0] += 0x800;
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x6000;
    D_0028E484.w += (s32) reg_tmp.w;
    if (D_0028E484.h[1] != 0) {
        func_00126ED0();
        return;
    }
    reg_d1.w = D_0028DE94;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a0 += 2;
    reg_a0 -= 0x1E;
    save_a1 = reg_a1;
    reg_a1 = D_00269530;
    reg_a1 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 0x28) = *(u16 *) (reg_a1 + 2);
    *(u16 *) (reg_a0 + 0x2A) = *(u16 *) (reg_a1 + 0);
    ((Fn) *(u32 *) (D_00269550 + (reg_d0.h[0] & ~3)))();
    reg_a1 = save_a1;
    reg_d7.w = D_0028DE90;
    reg_a0 = *(u8 **) (&D_0028DE80 + 0xC);
}

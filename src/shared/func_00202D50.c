#include "common.h"

extern u8 D_00267030[];
extern u8 D_00267050[];
extern u8 D_00267070[];
extern u8 D_00267090[];
extern Reg32 D_0028E484;
extern u16 D_0028E910;
extern u16 D_0028E914;
extern u8 *reg_a0;
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_00202D50(void) {
    u8 *save_a0;
    u32 save_d0;
    u32 save_d1;

    save_d1 = reg_d1.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = D_0028E914;
    reg_a0 = (u8 *)D_00267030;
    if (D_0028E910 == 0) goto next_1;
    reg_a0 = (u8 *)D_00267070;
next_1:
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_tmp.w = 0;
    D_0028E484.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
    if (D_0028E484.h[1] != 0) goto next_3;
    reg_d0.h[0] = D_0028E914;
    reg_a0 = (u8 *)D_00267050;
    if (D_0028E910 == 0) goto next_2;
    reg_a0 = (u8 *)D_00267090;
next_2:
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w = 0;
    D_0028E484.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
next_3:
    D_0028E408 = 0;
    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
}

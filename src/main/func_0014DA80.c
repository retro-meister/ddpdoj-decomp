#include "common.h"


typedef void (*Fn)();

extern s16 D_0028E7D8;
extern s16 D_0028E7DC;
extern s16 D_0028E7E0;
extern u16 D_0028E7E4;
extern u16 D_0028E7E8;
extern u16 D_0028E7EC;
extern u16 D_0029C06C[];
extern u8 D_002BE0C0[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014DA80(void) {
    u32 temp_s0;

    reg_a5 = D_002BE0C0;
    D_0028E7EC = 0;
    D_0028E7E8 = 0;
    reg_d6.h[0] = 0x39;
    D_0028E7E4 = 0;
    do {
        if ((*(u16 *)((u8 *)(reg_a5) + (0))) != 0) {
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
            reg_d0.h[0] = D_0029C06C[0];
            reg_a6 = (u8 *)reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x4C)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x4E)));
            reg_a1 = (u8 *)reg_tmp.w;
            jtbl_0028E3F4 = reg_a1;
            temp_s0 = reg_d6.w;
            ((Fn)jtbl_0028E3F4)();
            reg_d6.w = temp_s0;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
            reg_d0.h[0] += 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0))) < 0) {
                D_0028E7EC += 1;
                reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xC)));
                if (((s8) reg_d2.b[0] >= 0) && !(reg_d2.w & 0x20)) {
                    D_0028E7E8 += reg_d0.h[0];
                } else {
                    D_0028E7E4 += reg_d0.h[0];
                }
            }
        }
        reg_a5 += 0x50;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    D_0028E7E0 = 0;
    D_0028E7DC = 0;
    D_0028E7D8 = 0;
}

#include "common.h"

void func_00140280(u8 *, s32 *);
s32 func_0019D360();
extern u8 D_0028C610[];
extern u16 D_0028C618[];
extern u16 D_0028C620[];
extern u16 D_0028DFC0;
extern u16 D_0028E064;
extern u16 D_0028E06C;
extern u8 D_0028E370;
extern u16 D_0028E3B4;
extern u16 D_0028E3EC;
extern u16 D_0028E484_as_u16;
extern u8 D_0028E718_as_u8;
extern u8 D_0028E71C_as_u8;
extern u8 D_0028E855;
extern u16 D_0028E908;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 D_0028EC4C;
extern s32 D_0029CD84[];
extern s32 D_0029CD94[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00141B50(void) {
    u8 *p0;
    s32 *p1;
    u16 idx;

    reg_a0 = (u8 *)D_0028C610;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4E)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028C618;
    reg_d1.w = 0;
    reg_d1.h[0] *= 4;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((D_0028DFC0 == 0) && (D_0028E3EC == 0) && (D_0028E910 == 0) && (D_0028E91C != 2)) {
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484_as_u16 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484_as_u16 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        reg_d1.w += 0xFE00FE00;
        reg_a0 = (u8 *)D_0028C620;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
        reg_d0.h[0] *= 2;
        idx = reg_d0.h[0];
        reg_tmp.h[1] = (idx != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)idx & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((idx & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((idx & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4E)));
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        func_0019D360();
    }
    if ((D_0028E370 != 0) && (D_0028EC4C == 0) && (D_0028E3B4 == 0) && !(D_0028E855 & 1) && (D_0028E908 == 0) && !((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40)) {
        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
            if (D_0028E06C == 0) {
                p0 = &D_0028E71C_as_u8;
                p1 = (s32 *)(p0 - 0x34);
                *p1 = D_0029CD94[0];
                func_00140280(p0, p1);
                if (D_0028E910 != 0) {
                    func_00140280(p0, p1);
                }
                return;
            }
        } else if (D_0028E064 == 0) {
            p0 = &D_0028E718_as_u8;
            p1 = (s32 *)(p0 - 0x30);
            *p1 = D_0029CD84[0];
            func_00140280(p0, p1);
            if (D_0028E910 != 0) {
                func_00140280(p0, p1);
            }
        }
    }
    return;
}

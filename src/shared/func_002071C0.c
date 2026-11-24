#include "common.h"

extern u8 D_002678A0[];
extern u32 D_0028E0C4;
extern u16 D_0028E0D0;
extern u8 D_002A1130[];
extern u8 D_002A1770[];
extern u8 *reg_a0;

void func_002071C0(void) {
    u32 save_d1;
    u32 save_d2;
    s32 t1;

    save_d2 = reg_d2.w;
    reg_d2.h[0] = D_0028E0D0;
    save_d1 = reg_d1.w;
    if ((s16) reg_d2.h[0] < 0x640) {
        reg_d1.h[0] = reg_d0.h[0];
        reg_a0 = (u8 *)D_002678A0;
        reg_d1.h[0] *= 8;
        t1 = reg_d1.h[0] + 4;
        reg_d1.h[0] = (t1 != 0) ? *(u16 *)(reg_a0 + ((s16) t1 & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)D_002A1130;
        reg_a0 += reg_d2.h[0] & 0xFFFF;
        reg_d0.h[0] |= 0x8000;
        *(u16 *)(reg_a0 + 0) = reg_d0.h[0];
        *(s16 *)(reg_a0 + 2) = 0;
        *(u16 *)(reg_a0 + 0x4A) = reg_d1.h[0];
        D_0028E0D0 += 0x50;
        D_0028E0C4 += 1;
        reg_d0.w = D_0028E0C4;
        *(u16 *)(reg_a0 + 0x4C) = reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x4E) = reg_d0.h[0];
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        return;
    }
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_002A1770;
}

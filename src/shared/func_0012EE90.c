#include "common.h"

s32 func_0012E3D0();
extern u16 D_0028E3F0;
extern Reg32 D_0028E484;
extern u8 *reg_a6;

void func_0012EE90(void) {
    func_0012E3D0();
    reg_tmp.w = 0x19D;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] &= 3;
    do {
        reg_tmp.w = 1;
        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
        D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
        D_0028E484.w = (s32) ((s32) D_0028E484.w + reg_tmp.w);
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) D_0028E484.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = D_0028E484.h[0];
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_tmp.w = 0x1B;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x30))) = 0x20;
}

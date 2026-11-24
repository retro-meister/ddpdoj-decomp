#include "common.h"

s32 func_0014E370();
extern u8 D_0024ED80[];
extern u16 D_0024EEB0[];
extern u8 D_0026E760[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014F440(void) {
    reg_a0 = D_0026E760;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x24)));
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x26)));
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d0.h[0] += 0x20;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) reg_d0.h[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x21)));
    (*(s8 *)((u8 *)(reg_a5) + (0x28))) = 0;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a0 = D_0024ED80;
    reg_a1 = (u8 *)(D_0024EEB0);
    reg_d1.h[0] = (u16) reg_d1.b[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 2);
    reg_d1.h[0] &= 0x3E;
    reg_a1 += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a0 += reg_d1.h[0];
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_d0.h[0];
    reg_d0.w += 3;
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 2U;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 0;
}

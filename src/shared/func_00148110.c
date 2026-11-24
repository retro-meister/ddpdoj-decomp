#include "common.h"

extern u16 D_002576C0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00148110(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0))) = 0x8000U;
    reg_a0 += 2;
    reg_d1.h[0] += 0x200;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d1.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_a0 += 2;
    reg_a0 += 0xA;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
    reg_d3.h[0] *= 4;
    if ((*(u8 *)((u8 *)(reg_a5) + (0))) & 1) {
        reg_d3.h[0] += 0x78;
    } else if ((*(u16 *)((u8 *)(reg_a5) + (0x5A))) != 2) {
        reg_d3.h[0] += 0x50;
    } else if ((*(u16 *)((u8 *)(reg_a5) + (0x58))) != 0) {
        reg_d3.h[0] += 0x28;
    }
    reg_a1 = (u8 *)(D_002576C0);
    reg_a1 += reg_d3.h[0];
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d0.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d0.h[0];
    (*(u8 *)((u8 *)(reg_a0) + (4))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
}

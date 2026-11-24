#include "common.h"


extern u16 D_0026A2B0[];
extern u16 D_0026A300[];
extern u8 D_0028E290;
extern u8 D_0028E2C8;
extern s16 D_0028E7D4_as_s16;
extern u16 D_0028E914;
extern u8 D_0028ED80;
extern u8 D_002BF330[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_0014D4A0(void) {
    reg_a4 = D_002BF330;
    reg_a0 = (u8 *)(D_0026A2B0);
    reg_d0.h[0] = D_0028E914;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        reg_a0 = (u8 *)(D_0026A300);
    }
    reg_a0 += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
    D_0028E7D4_as_s16 = 0;
}

#include "common.h"

extern u16 D_0025B160[];
extern u32 D_0028E484;
extern u16 D_0028E91C;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
extern s16 D_0029F260[];
extern u16 D_0029F262[];
extern u16 D_0029F264[];
extern u8 *reg_a0;
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_0016D290(void) {
    reg_d0.h[0] = 0x7FFF;
    if (D_0029F260[0] < 0) {
        reg_d2.h[0] = D_0029F262[0];
        reg_d3.h[0] = D_0029F264[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d0.h[0]) < 0) {
            reg_d0.h[0] *= 0xFFFF;
        }
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] >>= 2;
        reg_d1.h[0] -= reg_d3.h[0];
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d1.h[0]) < 0) {
            reg_d1.h[0] *= 0xFFFF;
        }
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            D_0028E484 = reg_d1.w;
            reg_d1.w = reg_d0.w;
            reg_d0.w = D_0028E484;
        }
        reg_d1.h[0] >>= 1;
        reg_d0.h[0] += reg_d1.h[0];
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0x7FFF;
    if (D_0029F1F0[0] < 0) {
        reg_d2.h[0] = D_0029F1F2[0];
        reg_d3.h[0] = D_0029F1F4[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d0.h[0]) < 0) {
            reg_d0.h[0] *= 0xFFFF;
        }
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] >>= 2;
        reg_d1.h[0] -= reg_d3.h[0];
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d1.h[0]) < 0) {
            reg_d1.h[0] *= 0xFFFF;
        }
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            D_0028E484 = reg_d1.w;
            reg_d1.w = reg_d0.w;
            reg_d0.w = D_0028E484;
        }
        reg_d1.h[0] >>= 1;
        reg_d0.h[0] += reg_d1.h[0];
    }
    if ((s32) reg_d0.h[0] > (s32) reg_d4.h[0]) {
        reg_d0.h[0] = reg_d4.h[0];
    }
    reg_a0 = (u8 *)(D_0025B160);
    reg_d4.h[0] = D_0028E91C;
    reg_d4.h[0] += reg_d4.h[0];
    reg_a0 += reg_d4.h[0];
    reg_d4.h[0] = *(u16 *)reg_a0;
    if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}

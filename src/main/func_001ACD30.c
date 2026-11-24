#include "common.h"

extern s8 D_0028E408;

void func_001ACF80(void);
extern u8 *D_0028E4F0;
extern u8 *D_0028E4F4;
extern u8 *D_0028E4F8;
extern u8 *D_0028E4FC;
extern u8 *D_0028E500;
extern u8 *D_0028E504;
extern u8 *D_0028E508;
extern u32 D_0028E50C;
extern u32 D_0028E510;
extern u32 D_0028E514;
extern u32 D_0028E518;
extern u32 D_0028E51C;
extern u32 D_0028E520;
extern u32 D_0028E524;
extern u32 D_0028E528;
extern u16 D_0028E738;
extern u16 D_0028E73C;
extern u32 D_0028E740;
extern u32 D_0028E744;
extern u16 D_0028E758;
extern u16 D_0028E75C;
extern u32 D_0028E764;
extern u32 D_0028E768;
extern u16 D_0028E90C;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001ACD30(void) {
    *(u16 *)(reg_a4 + 0) = D_0028E910;
    *(u16 *)(reg_a4 + 2) = D_0028E91C;
    if (D_0028E90C != 0) {
        *(u16 *)(reg_a4 + 0) = 1;
        *(u16 *)(reg_a4 + 2) = 5;
    }
    *(u16 *)(reg_a4 + 4) = reg_d0.h[0];
    *(u16 *)(reg_a4 + 6) = reg_d1.h[0];
    *(u16 *)(reg_a4 + 8) = reg_d2.h[0];
    *(u16 *)(reg_a4 + 0xA) = reg_d3.h[0];
    func_001ACF80();
    if (D_0028E408 != 0) {
        goto block_50;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_a4 = (u8 *)reg_tmp.w;
    *(u32 *)(reg_a4 + 0) = reg_d6.w;
    if (reg_d6.w == 0xFF) {
        reg_d0.h[0] = D_0028E75C;
        if ((s32) D_0028E73C > (s32) reg_d0.h[0]) {
            goto block_51;
        }
        D_0028E73C = reg_d0.h[0];
        reg_d0.w = D_0028E768;
        if ((u32) D_0028E744 > (u32) reg_d0.w) {
            goto block_51;
        }
        D_0028E744 = reg_d0.w;
    } else {
        reg_d0.h[0] = D_0028E758;
        if ((s32) D_0028E738 > (s32) reg_d0.h[0]) {
            goto block_51;
        }
        D_0028E738 = reg_d0.h[0];
        reg_d0.w = D_0028E764;
        if ((u32) D_0028E740 > (u32) reg_d0.w) {
            goto block_51;
        }
        D_0028E740 = reg_d0.w;
    }
block_51:
    D_0028E408 = 0;
    reg_d0.w = D_0028E528;
    reg_d1.w = D_0028E524;
    reg_d2.w = D_0028E520;
    reg_d3.w = D_0028E51C;
    reg_d4.w = D_0028E518;
    reg_d5.w = D_0028E514;
    reg_d6.w = D_0028E510;
    reg_d7.w = D_0028E50C;
    reg_a0 = (u8 *)D_0028E508;
    reg_a1 = (u8 *)D_0028E504;
    reg_a2 = (u8 *)D_0028E500;
    reg_a3 = (u8 *)D_0028E4FC;
    reg_a4 = (u8 *)D_0028E4F8;
    reg_a5 = (u8 *)D_0028E4F4;
    reg_a6 = (u8 *)D_0028E4F0;
    return;
block_50:
    D_0028E408 = 1;
    reg_d0.w = D_0028E528;
    reg_d1.w = D_0028E524;
    reg_d2.w = D_0028E520;
    reg_d3.w = D_0028E51C;
    reg_d4.w = D_0028E518;
    reg_d5.w = D_0028E514;
    reg_d6.w = D_0028E510;
    reg_d7.w = D_0028E50C;
    reg_a0 = (u8 *)D_0028E508;
    reg_a1 = (u8 *)D_0028E504;
    reg_a2 = (u8 *)D_0028E500;
    reg_a3 = (u8 *)D_0028E4FC;
    reg_a4 = (u8 *)D_0028E4F8;
    reg_a5 = (u8 *)D_0028E4F4;
    reg_a6 = (u8 *)D_0028E4F0;
}

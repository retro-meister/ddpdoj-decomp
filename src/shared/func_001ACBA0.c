#include "common.h"

s32 func_001ACD30();
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
extern u16 D_0028E614;
extern u16 D_0028E750;
extern u16 D_0028E75C;
extern u32 D_0028E768;
extern u16 D_0028E930;
extern u16 D_0028E938;
extern u8 D_002BB420[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001ACBA0(void) {
    D_0028E528 = reg_d0.w;
    D_0028E524 = reg_d1.w;
    D_0028E520 = reg_d2.w;
    D_0028E51C = reg_d3.w;
    D_0028E518 = reg_d4.w;
    D_0028E514 = reg_d5.w;
    D_0028E510 = reg_d6.w;
    D_0028E50C = reg_d7.w;
    D_0028E508 = reg_a0;
    D_0028E504 = reg_a1;
    D_0028E500 = reg_a2;
    D_0028E4FC = reg_a3;
    D_0028E4F8 = reg_a4;
    D_0028E4F4 = reg_a5;
    D_0028E4F0 = reg_a6;
    reg_a4 = (u8 *)D_002BB420;
    reg_d6.w = 0xFF;
    reg_d7.w = D_0028E768;
    reg_d5.h[0] = D_0028E75C;
    reg_d0.h[0] = D_0028E938;
    reg_d1.h[0] = D_0028E930;
    reg_d2.h[0] = D_0028E614;
    reg_d3.h[0] = D_0028E750;
    func_001ACD30();
}

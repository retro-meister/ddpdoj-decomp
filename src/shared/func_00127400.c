#include "common.h"

extern s8 D_0028E408;

s32 func_002011D0();
s32 func_00201270();
s32 func_00201D10();
extern void *D_0028E44C;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00127400(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d3;
    u8 *temp_a1;

    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += reg_d0.b[0];
    save_d0 = reg_d0.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    func_002011D0();
    reg_d0.h[0] += 1;
    reg_d1.h[0] = reg_d0.h[0];
    func_00201270();
    reg_d0.b[0] -= reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) += reg_d0.b[0];
    temp_a1 = (u8 *)(reg_a0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1) + (0x1B)));
    reg_d1.w = 0x3F;
    reg_d0.h[0] = (u16) reg_d0.b[0];
    reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a1) + (0x1A)));
    reg_a0 = reg_a6;
    D_0028E44C = temp_a1;
    reg_a6 = temp_a1;
    func_00201D10();
    D_0028E44C = (void *)reg_a0;
    reg_a0 = reg_a6;
    reg_a6 = (u8 *)D_0028E44C;
    (*(u16 *)((u8 *)(reg_a0) + (0x20))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x22))) = (u16) reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    D_0028E408 = 0;
    reg_d1.w = reg_d7.w;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
}

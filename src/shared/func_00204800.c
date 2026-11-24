#include "common.h"

extern s8 D_0028E408;

s32 func_0019C790();
s32 func_001A3520();
s32 func_00206510();
s32 func_00206520();
extern u8 D_00251F70[];
extern u8 D_00251F80[];
extern u8 D_0028DF0C;
extern u8 D_0028E304;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00204800(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u32 save_d0;
    u32 save_d7;
    u16 temp_a0;
    u8 *temp_s5;

    reg_a0 = (u8 *)D_00251F70;
    if (reg_d7.h[0] != 0) {
        reg_a0 = (u8 *)D_00251F80;
    }
    if ((D_0028E304 != 0) || (D_0028DF0C != 0) || (reg_d0.h[0] = reg_d7.h[0], reg_d0.h[0] += 1, reg_d0.h[0] &= 1, func_001A3520(), (reg_d0.h[0] == 4)) || (temp_s5 = reg_a6, ((*(u8 *)((u8 *)(temp_s5) + (1))) != 0))) {
        reg_d0.h[0] = reg_d7.h[0];
        reg_d0.h[0] += 1;
        reg_d0.h[0] &= 1;
        func_00206520();
        return;
    }
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    reg_d0.w = 0;
    func_00206510();
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = temp_s5;
    if (D_0028E408 == 0) {
        save_d0 = reg_d0.w;
        reg_d0.h[0] = reg_d7.h[0];
        reg_d0.h[0] += 1;
        reg_d0.h[0] &= 1;
        func_00206520();
        reg_d0.w = save_d0;
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_a0 += 2;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_a0 += 2;
        reg_tmp.w = reg_d1.w;
        reg_a0 += reg_d0.h[0];
        reg_d1.h[1] = reg_tmp.h[0];
        reg_d1.h[0] = reg_tmp.h[1];
        reg_d1.h[0] += 0x7FFF + 0x7A01;
        reg_tmp.w = reg_d1.w;
        reg_d1.h[1] = reg_tmp.h[0];
        reg_d1.h[0] = reg_tmp.h[1];
        reg_d1.h[0] += 0x7FFF + 0x6C01;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d2.h[0] = temp_a0;
        reg_d3.h[0] = 0x6A0;
        reg_d4.h[0] = 0xB;
        func_0019C790();
    }
}

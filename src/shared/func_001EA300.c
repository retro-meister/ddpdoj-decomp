#include "common.h"

s32 func_00125310();
s32 func_00129280();
s32 func_00171400();
s32 func_001EA0E0();
s32 func_001EA1A0();
s32 func_002010A0();
s32 func_00201100();
s32 func_002027A0();
extern u8 D_00264160[];
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001EA300(void) {
    s16 *temp_a0;
    s16 *var_a1;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v0_2;

    if (D_0028E89C != 0) {
        func_001EA1A0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (s16 *)(reg_a4);
        (*(u8 *)((u8 *)(var_a1) + (3))) = (u8) (*(u8 *)((u8 *)(var_a1) + (9)));
        (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 1;
        if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                D_0028E44C = (s16 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(D_0028E44C);
            }
            temp_a0 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                var_a1 = (s16 *)(reg_a1);
                if (0 > *var_a1) {
                    reg_a0 = (u8 *)(var_a1);
                    D_0028E44C = (s16 *)(temp_a0);
                    reg_a1 = (u8 *)(temp_a0);
                    goto block_9;
                }
            } else {
block_9:
                reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
                reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
                reg_d7.h[0] = reg_d2.h[0];
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                func_002027A0();
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_2;
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d5.h[0] += 0x7FFF + 0x7601;
                if ((s32) reg_d5.h[0] <= (s32) reg_d7.h[0]) {
                    reg_d0.w += 0x100000;
                    func_00201100();
                    reg_d5.b[0] = (u8) ((s8) reg_d5.b[0] >> 1);
                    reg_d1.b[0] += reg_d5.b[0];
                    func_00129280();
                    reg_d0.w += 0x40000;
                    func_00129280();
                    reg_d0.w += 0x40000;
                }
                func_00129280();
                func_00171400();
                goto block_12;
            }
        } else {
block_12:
            reg_a3 = (u8 *)D_00264160;
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x70;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xC0;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x7C;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x14)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB8;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x14)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x98;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x17)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB0;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x17)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x90;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x16)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x40;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x16)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBA)));
            func_001EA0E0();
            reg_d1.h[0] = 0x84;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x19)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x48;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x19)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDA)));
            func_001EA0E0();
            reg_d1.h[0] = 0x68;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x50;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
        }
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
        (*(u8 *)((u8 *)(reg_a6) + (0x3A))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x5A))) -= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x7A))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x9A))) -= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xBA))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xDA))) -= reg_d0.b[0];
        reg_d0.h[0] = 0x3F;
        (*(u8 *)((u8 *)(reg_a6) + (0x3A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x5A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x7A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x9A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xBA))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xDA))) &= reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_002010A0();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
            reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
                (*(s8 *)((u8 *)(reg_a6) + (0x13D))) = (s8) ~(*(s8 *)((u8 *)(reg_a6) + (0x13D)));
                temp_v0 = (*(u16 *)((u8 *)(reg_a6) + (0x1D2)));
                if ((s32) temp_v0 < 4) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1D2))) = (u16) (temp_v0 + 1);
                }
                temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1D4)));
                if ((s32) temp_v0_2 < 4) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1D4))) = (u16) (temp_v0_2 + 1);
                }
                (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
                reg_d0.w = 2;
                func_00125310();
            }
        }
    }
}

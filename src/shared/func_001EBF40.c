#include "common.h"

s32 func_00125310();
s32 func_00171400();
s32 func_001EBD30();
s32 func_001EBE90();
s32 func_002027A0();
extern u8 D_002643E0[];
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

void func_001EBF40(void) {
    s16 *temp_a0;
    u16 temp_a0_2;
    u16 temp_v0_2;
    u8 temp_v0;
    u8 temp_v1;
    u8 *var_a1;

    if (D_0028E89C != 0) {
        func_001EBE90();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (unsigned char *)((*(u8 *)((u8 *)(reg_a4) + (9))));
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (unsigned char)var_a1;
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            var_a1 = (unsigned char *)reg_a1;
            if (0 > (s64)*(s16 *)var_a1) {
                reg_a0 = (u8 *) var_a1;
                D_0028E44C = (s16 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_002027A0();
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d2.h[0] = temp_a0_2;
            reg_d7.h[0] = reg_d1.h[0];
            reg_a3 = (u8 *)D_002643E0;
            reg_d4.w = 0;
            reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_a3 += reg_d4.h[0];
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_a3 += reg_d4.h[0];
            func_001EBD30();
            reg_d1.h[0] = reg_d7.h[0];
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            func_001EBD30();
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            (*(u16 *)((u8 *)(reg_a4) + (0x12))) -= 0x10;
            if ((s32) reg_tmp.h[0] < 0x10) {
                (*(u16 *)((u8 *)(reg_a4) + (0x12))) = 0x40U;
            }
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_00171400();
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (4)));
            if ((s32) temp_v1 < 0x3B) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1 + 0xF);
            }
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 2;
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) += 1;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1EB)));
                if ((s32) temp_v0 < 0x10) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1EB))) = (u8) (temp_v0 + 8);
                }
                temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1EC)));
                if ((s32) temp_v0_2 < 0xB) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1EC))) = (u16) (temp_v0_2 + 2);
                }
                reg_d0.w = 7;
                func_00125310();
            }
        }
    }
}

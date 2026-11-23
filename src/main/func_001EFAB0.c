#include "common.h"

s32 func_00125310();
s32 func_00171400();
s32 func_001EF990();
s32 func_00201270();
s32 func_002027A0();
extern u16 D_002647C0[];
extern s16 *D_0028E44C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001EFAB0(void) {
    s16 *temp_a0_2;
    s8 temp_a0_5;
    s8 temp_a0_6;
    u16 temp_a0_4;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_v0_2;
    u32 temp_s0;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v0_3;
    u8 temp_v1;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (9)));
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (4)));
        if (temp_a0 == reg_d0.b[0]) {
            func_00201270();
            (*(u8 *)((u8 *)(reg_a4) + (0x15))) = (u8) reg_d0.b[0];
        }
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        temp_a0_2 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0_2) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                D_0028E44C = (s16 *)(temp_a0_2);
                reg_a1 = (u8 *)(temp_a0_2);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a3 = (u8 *)(D_002647C0);
            temp_a1 = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d4.h[0] = temp_a1;
            reg_a3 += reg_d4.h[0];
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0xD00;
            func_002027A0();
            temp_s0 = reg_d1.w;
            reg_d2.h[0] = reg_d6.h[0];
            reg_d3.h[0] = reg_d7.h[0];
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0x7FFF + 0x7301;
            func_002027A0();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d2.h[0] = temp_a1_2;
            temp_a0_4 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = temp_a0_4;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_5 = (s8) reg_d4.b[0];
            reg_d5.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            reg_d4.b[0] = (u8) (temp_a0_5 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            reg_d4.w = 0;
            reg_d6.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            func_001EF990();
            reg_d1.w = temp_s0;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_6 = (s8) reg_d4.b[0];
            reg_d5.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            reg_d4.b[0] = (u8) (temp_a0_6 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            func_001EF990();
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0x30U;
            }
        }
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 1;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_00171400();
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (4)));
            if ((s32) temp_v1 < 0x1E) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1 + 0xF);
            }
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) += 4;
            (*(u16 *)((u8 *)(reg_a4) + (0x12))) += 1;
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
                temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1D7)));
                if ((s32) temp_v0 < 2) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1D7))) = (u8) (temp_v0 + 1);
                }
                temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x13E)));
                if ((s32) temp_v0_2 < 6) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x13E))) = (u16) (temp_v0_2 + 1);
                }
                temp_v0_3 = (*(u8 *)((u8 *)(reg_a6) + (0x1D6)));
                if ((s32) temp_v0_3 < 0x10) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1D6))) = (u8) (temp_v0_3 + 4);
                }
                reg_d0.w = 3;
                func_00125310();
            }
        }
    }
}

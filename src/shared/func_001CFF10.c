#include "common.h"

s32 func_00125310();
s32 func_00129280();
s32 func_00171400();
s32 func_002027A0();
extern s16 *D_0028E448;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CFF10(void) {
    s16 *temp_a0;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u8 temp_v0_2;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (9)));
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        switch ((*(u8 *)((u8 *)(reg_a5) + (2)))) { case 0: break; default:
            D_0028E448 = (s16 *)(reg_a1);
            reg_a1 = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(D_0028E448);
        }
        if ((*(s16 *)((u8 *)(reg_a0) + (0))) >= 0) {
            temp_a0 = (s16 *)(reg_a1);
            if (*temp_a0 < 0) {
                reg_a1 = (u8 *)(reg_a0);
                D_0028E448 = (s16 *)(temp_a0);
                reg_a0 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.h[0] += 0x7FFF + 0x6201;
            func_002027A0();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d3.w = 0xE2000000;
            reg_d4.w = (u32) reg_a6;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
            reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a4) + (4)));
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            func_00129280();
        }
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        switch (reg_tmp.h[0]) {
        case 0:
            func_00171400();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            (*(u16 *)((u8 *)(reg_a4) + (6))) += reg_d0.h[0];
            if ((s32) (*(u16 *)((u8 *)(reg_a4) + (6))) > 0xC) {
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 0xCU;
            }
            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (6)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
            if (reg_tmp.b[0] == 0) {
                temp_v0 = (*(u16 *)((u8 *)(reg_a6) + (0x126)));
                if ((s32) temp_v0 < 6) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x126))) = (u16) (temp_v0 + 3);
                }
                temp_v0_2 = (*(u8 *)((u8 *)(reg_a6) + (0x12A)));
                if ((s32) temp_v0_2 < 0x20) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x12A))) = (u8) (temp_v0_2 + 8);
                }
                temp_v0_3 = (*(u16 *)((u8 *)(reg_a6) + (0x10C)));
                if ((s32) temp_v0_3 < 0xF) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x10C))) = (u16) (temp_v0_3 + 3);
                }
                temp_v0_4 = (*(u16 *)((u8 *)(reg_a6) + (0x10E)));
                if ((s32) temp_v0_4 < 6) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x10E))) = (u16) (temp_v0_4 + 2);
                    (*(u16 *)((u8 *)(reg_a6) + (0x110))) += 4;
                }
                reg_d0.w = 6;
                func_00125310();
                reg_d0.w = 7;
                func_00125310();
            }
            break;
        }
    }
}

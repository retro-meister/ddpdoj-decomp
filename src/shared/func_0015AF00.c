#include "common.h"

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00201160();
extern u16 D_002589A0[];
extern u16 D_002589B0[];
extern u16 D_002589D0[];
extern u16 D_0025B610_as_u16_a[];
extern u16 D_0028E88C;
extern u16 D_0028E890;
extern u16 D_0028E894;
extern u16 D_0028E8A8;
extern u16 D_0028E8C8;
extern u16 D_0028E8DC;
extern u16 D_0028E918;
extern s8 enemy_move_end_requested;
void func_0019BF00();
void func_0019C4B0();
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015AF00(void) {
    s16 temp_v1_2;
    u16 *temp_a2;
    u16 temp_a3;
    reg_a0 = (u8 *)(D_002589D0);
    func_0014E370();
    reg_a0 = (u8 *)(D_002589B0);
    reg_d0.w = 0xF;
    func_0014E300();
    reg_d0.h[0] = D_0028E8DC;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= reg_d0.b[0];
    func_00201160();
    reg_d0.b[0] >>= 1;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) += reg_d0.b[0];
    reg_d0.h[0] = D_0028E8C8;
    reg_d0.h[0] >>= 4;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_a6 = (u8 *)reg_tmp.w;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025B610_as_u16_a);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_002589A0);
        reg_d0.h[0] = D_0028E918;
        temp_a3 = reg_d0.h[0];
        reg_a0 += temp_a3;
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x35))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x34))) = *(s8 *)reg_a0;
        reg_tmp.w = (u32) (void *)func_0019BF00;
        temp_a2 = (u16 *)(reg_a0 + 1);
        reg_a0 = (u8 *)(temp_a2);
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32) (void *)func_0019C4B0;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) = (u16) reg_tmp.h[0];
        reg_d0.h[0] = D_0028E8A8;
        if ((s16) reg_d0.h[0] >= 0xAC) {
            if (((*(s16 *)((u8 *)(reg_a6) + (2))) < 0x6400) && (D_0028E88C == 0)) {
                func_0014E290();
            }
        } else if ((s16) reg_d0.h[0] >= 0x8D) {
            temp_v1_2 = (*(s16 *)((u8 *)(reg_a6) + (2)));
            if ((temp_v1_2 > -0x3C00) && (temp_v1_2 < 0x6400) && (D_0028E890 == 0)) {
                func_0014E290();
            }
        } else if (((s16) reg_d0.h[0] >= 0x48) && (D_0028E894 == 0)) {
            func_0014E290();
        }
    }
}

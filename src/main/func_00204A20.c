#include "common.h"

s32 func_0019C5B0();
s32 func_00205320();
extern u8 D_00251F90[];
extern u8 D_00251FB0[];
extern u8 D_00251FD0[];
extern u8 D_00251FF0[];
extern u16 D_0028E3F0;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_00204A20(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u8 temp_a0;

    reg_a0 = D_00251FB0;
    reg_a1 = D_00251FF0;
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
    reg_d6.h[0] *= 0xFFFF;
    if (reg_d7.h[0] != 0) {
        reg_a0 = D_00251F90;
        reg_a1 = D_00251FD0;
        reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
    }
    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0;
    if ((*(u8 *)((u8 *)(reg_a6) + (0))) == 1) {
        if ((*(u16 *)((u8 *)(reg_a6) + (2))) != 0) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
            if ((*(u16 *)((u8 *)(reg_a1) + (0))) == reg_d0.h[0]) {
                (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
            } else {
                reg_a2 = reg_a6 + 0x10;
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                func_00205320();
            }
            goto block_11;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x10))) = 0x60;
        (*(s16 *)((u8 *)(reg_a6) + (0x12))) = 0xC00;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (4)));
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (6)));
            (*(u16 *)((u8 *)(reg_a6) + (0x14))) += reg_d1.h[0];
block_11:
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
            reg_d1.h[0] += 0xE600 & 0xFFFF;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
            reg_d1.h[0] += 0x7FFF + 0x6601;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.h[0] = 0x1AD0;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0xA)));
            func_0019C5B0();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
            reg_d1.h[0] += 0x7FFF + 0x7A01;
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0x12)));
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
            reg_d1.h[0] += 0x7FFF + 0x7001;
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0x14)));
            reg_d2.w = 3;
            reg_d2.h[0] &= D_0028E3F0;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0x14)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x16)));
            reg_d2.w += reg_tmp.w;
            reg_d3.h[0] = 0x680;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0xE)));
            func_0019C5B0();
        }
        if ((*(u16 *)((u8 *)(reg_a6) + (2))) == 0) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
            if ((*(u16 *)((u8 *)(reg_a1) + (0))) == reg_d0.h[0]) {
                (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
            } else {
                reg_a2 = reg_a6 + 0xA;
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                func_00205320();
            }
            goto block_20;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 0x60;
        (*(s16 *)((u8 *)(reg_a6) + (0xC))) = 0xC00;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (4)));
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (6)));
            (*(u16 *)((u8 *)(reg_a6) + (0xE))) += reg_d1.h[0];
block_20:
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
            reg_d1.h[0] += 0xE600 & 0xFFFF;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
            reg_d1.h[0] += 0x7FFF + 0x6601;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (6)));
            reg_d3.h[0] = 0x1AD0;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0xC)));
            func_0019C5B0();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
            reg_d1.h[0] += 0x7FFF + 0x7C01;
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0x16)));
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
            reg_d1.h[0] += 0x7FFF + 0x7001;
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0x18)));
            reg_d2.w = 3;
            reg_d2.h[0] &= D_0028E3F0;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0x18)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x1A)));
            reg_d2.w += reg_tmp.w;
            reg_d3.h[0] = 0x480;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0x10)));
            func_0019C5B0();
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0)));
    if ((temp_a0 == 4) || (temp_a0 == 7)) {
        if ((*(u16 *)((u8 *)(reg_a6) + (4))) == 2) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a1) + (0)));
            if (temp_a0_2 == reg_d0.h[0]) {
                (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
            } else {
                reg_a2 = reg_a6 + 0x22;
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                func_00205320();
            }
            goto block_31;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x22))) = 0x60;
        (*(s16 *)((u8 *)(reg_a6) + (0x24))) = 0xC00;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (4)));
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (6)));
            (*(u16 *)((u8 *)(reg_a6) + (0x26))) += reg_d1.h[0];
block_31:
            if (D_0028E910 == 0) {
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
                reg_d1.h[0] += 0xE600 & 0xFFFF;
                reg_d1.h[0] += reg_d6.h[0];
                reg_tmp.w = reg_d1.w;
                reg_d1.h[1] = reg_tmp.h[0];
                reg_d1.h[0] = reg_tmp.h[1];
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                reg_d1.h[0] += 0x7FFF + 0x6601;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (8)));
                temp_a0_3 = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
                reg_d2.h[0] = temp_a0_3;
                reg_d3.h[0] = 0x1AD0;
                reg_d4.h[0] = 0x1B;
                func_0019C5B0();
            }
        }
        if ((*(u16 *)((u8 *)(reg_a6) + (4))) == 1) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
            temp_a0_4 = (*(u16 *)((u8 *)(reg_a1) + (0)));
            if (temp_a0_4 == reg_d0.h[0]) {
                (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
            } else {
                reg_a2 = reg_a6 + 0x1C;
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                func_00205320();
            }
            goto block_41;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x1C))) = 0x60;
        (*(s16 *)((u8 *)(reg_a6) + (0x1E))) = 0xC00;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (4)));
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (6)));
            (*(u16 *)((u8 *)(reg_a6) + (0x20))) += reg_d1.h[0];
block_41:
            if (D_0028E910 == 0) {
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
                reg_d1.h[0] += 0xE600 & 0xFFFF;
                reg_d1.h[0] += reg_d6.h[0];
                reg_tmp.w = reg_d1.w;
                reg_d1.h[1] = reg_tmp.h[0];
                reg_d1.h[0] = reg_tmp.h[1];
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
                reg_d1.h[0] += 0x7FFF + 0x6601;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
                temp_a0_5 = (*(u16 *)((u8 *)(reg_a0) + (0xE)));
                reg_d2.h[0] = temp_a0_5;
                reg_d3.h[0] = 0x1AD0;
                reg_d4.h[0] = 0x19;
                func_0019C5B0();
            }
        }
        if ((*(u16 *)((u8 *)(reg_a6) + (4))) == 0) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
            temp_a0_6 = (*(u16 *)((u8 *)(reg_a1) + (0)));
            if (temp_a0_6 == reg_d0.h[0]) {
                (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
            } else {
                reg_a2 = reg_a6 + 0x16;
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                func_00205320();
            }
            goto block_51;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x16))) = 0x60;
        (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0xC00;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (4)));
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (6)));
            (*(u16 *)((u8 *)(reg_a6) + (0x1A))) += reg_d1.h[0];
block_51:
            if (D_0028E910 == 0) {
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (8)));
                reg_d1.h[0] += 0xE600 & 0xFFFF;
                reg_d1.h[0] += reg_d6.h[0];
                reg_tmp.w = reg_d1.w;
                reg_d1.h[1] = reg_tmp.h[0];
                reg_d1.h[0] = reg_tmp.h[1];
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d1.h[0] += 0x7FFF + 0x6601;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0x10)));
                temp_a0_7 = (*(u16 *)((u8 *)(reg_a0) + (0x12)));
                reg_d2.h[0] = temp_a0_7;
                reg_d3.h[0] = 0x1AD0;
                reg_d4.h[0] = 0x18;
                func_0019C5B0();
            }
        }
    }
}

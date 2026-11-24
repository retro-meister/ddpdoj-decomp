#include "common.h"

s32 func_00125EC0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00170A60();
s32 func_00170D00();
s32 func_0018D580();
s32 func_001A9000();
s32 func_001A91A0();
extern Reg32 D_0028E484;
extern u16 D_0028E8B8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C60C0(void) {
    u8 *t1;

    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x6800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x6800;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                func_0014E290();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
    }
next_1:
    if (*(s8 *)reg_a6 < 0) goto next_2;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    if ((s32) *(u16 *)(reg_a6 + 0x18) >= 0x380) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    }
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x18);
    if ((s16) reg_d2.h[0] < 0) goto next_3;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
next_4:
    func_00170A60();
    reg_a0 = reg_a6;
    func_0014D220();
    return;
next_3:
    func_0018D580();
    reg_d0.w = 0x15;
    func_001A91A0();
    *(u16 *)reg_a6 = 0x8080;
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x19);
    reg_d0.h[0] = 0x85;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x26) = 0xC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE80;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.w = 0xD;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 2;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(u16 *)(reg_a0 + 0x28) = 0xFF00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 1;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    t1 = (u8 *)((void *)1);
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xEE00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 0;
    goto next_4;
next_2:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x16);
    *(u8 *)(reg_a5 + 0x16) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_d0.w = 0xC;
    reg_d1.w = 0xFAC0FA40;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    func_00125EC0();
    func_0014E290();
}

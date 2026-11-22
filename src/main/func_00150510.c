#include "common.h"


extern s8 D_0028E408;

s32 func_0013A780();
s32 func_0014E290();
s32 func_0018D540();
s32 func_001A9000();
s32 func_001A91A0();
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00150510(u32 arg0) {
    u8 temp_a0;
    u8 temp_a1;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2A)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = arg0;
            func_001A91A0();
            reg_d0.w = 2;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            reg_d0.b[0] += 8;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] *= 4;
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            func_0018D540();
            func_0014E290();
            D_0028E408 = 1;
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
block_4:
    D_0028E408 = 0;
}

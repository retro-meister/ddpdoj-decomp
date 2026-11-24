#include "common.h"

s32 func_001389D0();
s32 func_0013B8B0();
s32 func_0014D220();
s32 func_0014E290();
s32 func_001A9000();
s32 func_001FABA0();
s32 func_001FAC60();
s32 func_001FACB0();
s32 func_001FAD00();
s32 func_001FAD30();
s32 func_001FB6C0();
s32 func_001FB700();
s32 func_001FBE90();
extern u8 D_00265F60[];
extern u16 D_0028E890;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FA6F0(void) {
    u16 temp_v0;
    u16 temp_v0_2;

    if (D_0028E8A0 == 0) {
        if ((*(u8 *)((u8 *)(reg_a6) + (0xBF))) != 0) {
            D_0028E890 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
            func_0014E290();
            return;
        }
        if (((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0xBE))) == 0) && (D_0028E8A8 == 0xE0)) {
            (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
            func_001FB6C0();
            reg_d0.w = 4;
            func_001FAD00();
        }
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x21)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x41)));
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0xAE))) = (u16) reg_d1.h[0];
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x41))) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d0.b[0] ^= 0xD;
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3C)));
            reg_d0.b[0] ^= 0xD;
            (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5C)));
            reg_d0.b[0] ^= 0xD;
            (*(u8 *)((u8 *)(reg_a6) + (0x5C))) = (u8) reg_d0.b[0];
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x18)));
            reg_d3.w = 0x7FFF;
            reg_d3.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x38)));
            if ((s32) reg_d2.w < (s32) reg_d3.w) {
                reg_d2.w = reg_d3.w;
            }
            reg_d3.w = 0x7FFF;
            reg_d3.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x58)));
            if ((s32) reg_d2.w < (s32) reg_d3.w) {
                reg_d2.w = reg_d3.w;
            }
            reg_d0.h[0] = 0x7FFF;
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x58))) = (u16) reg_d0.h[0];
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
                reg_tmp.w -= reg_d2.w;
                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_tmp.h[0];
                if ((s32) reg_tmp.w < 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
                    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
                    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0x8000;
                    func_001FB6C0();
                    reg_d0.w = 3;
                    func_001FAD00();
                    (*(u8 *)((u8 *)(reg_a6) + (0xBE))) = 1U;
                    reg_d0.h[0] = 0x20;
                    reg_d1.h[0] = 0x20;
                    D_0028E890 = 0;
                    func_001389D0();
                    reg_a0 = (u8 *)D_00265F60;
                    func_0013B8B0();
                    goto block_15;
                }
            }
        } else {
block_15:
            reg_d0.w = 0x12;
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x5C))) = (u8) reg_d0.b[0];
        }
        func_001FBE90();
        func_001FAD30();
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_tmp.w += 0xF6FFF800;
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_d0.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_tmp.w += 0xF7000800;
        (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_tmp.h[0];
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
        (*(u16 *)((u8 *)(reg_a6) + (0x42))) += reg_d1.h[0];
        func_001FB700();
        temp_v0 = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
        if (temp_v0 != 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x26))) = (u16) (temp_v0 - 0x40);
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x26)))) {
                (*(u16 *)((u8 *)(reg_a6) + (0x26))) = 0U;
            }
        }
        temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
        if (temp_v0_2 != 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x46))) = (u16) (temp_v0_2 - 0x40);
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x46)))) {
                (*(u16 *)((u8 *)(reg_a6) + (0x46))) = 0U;
            }
        }
        goto block_22;
    }
block_22:
    func_001FABA0();
    func_001FAC60();
    func_001FACB0();
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x40;
    func_0014D220();
}

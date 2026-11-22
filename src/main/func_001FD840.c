#include "common.h"

s32 func_0014E290();
s32 func_001389D0();
s32 func_0013B8B0();
s32 func_0014D220();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001FDAB0();
s32 func_001FDC10();
s32 func_001FDC80();
s32 func_001FDCF0();
s32 func_001FDD60();
s32 func_001FDDD0();
s32 func_001FDE00();
s32 func_001FE120();
s32 func_001FE330();
s32 func_001FF0B0();
extern u8 D_00266330[];
extern u16 D_0028E884;
extern u16 D_0028E888;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FD840() {
    if (D_0028E8A0 == 0) {
        if ((*(u8 *)((u8 *)(reg_a6) + (0x9F))) != 0) {
            D_0028E888 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
            func_0014E290();
            return;
        }
        if (((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) == 0) && (D_0028E8A8 == 0x1F0)) {
            (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
            (*(u16 *)((u8 *)(reg_a5) + (0x20))) = 1U;
            reg_d0.w = 7;
            func_001FDDD0();
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x8E))) = (u16) reg_d1.h[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d0.b[0] ^= 0xD;
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x18)));
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                reg_tmp.w -= reg_d0.w;
                (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) reg_tmp.h[0];
            }
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFFU;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                func_001A91A0();
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
                (*(u8 *)((u8 *)(reg_a6) + (0x9E))) = 1U;
                reg_d0.h[0] = 0x20;
                reg_d1.h[0] = 0x20;
                D_0028E888 = 0;
                D_0028E884 = 0;
                func_001389D0();
                reg_d0.w = 6;
                func_001FDDD0();
                reg_a0 = D_00266330;
                func_0013B8B0();
                goto block_12;
            }
        } else {
block_12:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = 0x12U;
        }
        func_001FF0B0();
        if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) == 0) {
            func_001FDE00();
            if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                func_001FE120();
                func_001FE330();
            }
        }
        goto block_16;
    }
block_16:
    reg_a0 = reg_a6;
    func_0014D220();
    func_001FDCF0();
    func_001FDD60();
    func_001FDC10();
    func_001FDC80();
    func_001FDAB0();
}

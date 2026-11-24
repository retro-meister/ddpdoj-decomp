#include "common.h"

s32 func_00129280();
s32 func_00129370();
s32 func_0014D220();
s32 func_0014E290();
s32 func_00153650();
s32 func_00156690();
s32 func_00156810();
s32 func_0018D580();
s32 func_0019C6D0();
s32 func_0019C730();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201B80();
s32 func_00201E20();
extern u8 D_00258150[];
extern u8 D_00258190[];
extern u8 D_002581D0[];
extern u16 D_0028E904;
extern u16 D_0029CEA0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00156860(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_a0_8;
    u32 temp_a0_9;

    if ((*(s16 *)((u8 *)(reg_a6) + (2))) < -0x2200) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_00156810();
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201B80();
    if ((*(s16 *)((u8 *)(reg_a5) + (0x3E))) >= 0) {
        (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFF;
        reg_d0.h[0] = 1;
        if (D_0029CEA0[0] != 0) {
            reg_d0.h[0] = 2;
        }
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x3E)));
        (*(u16 *)((u8 *)(reg_a5) + (0x3E))) -= reg_d0.h[0];
        if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) {
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x1C00;
        }
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x1A))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = 0x632;
            func_001A91A0();
            func_00156810();
            reg_a1 = (u8 *)D_002581D0;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d3.h[0] = 0xC;
            func_00153650();
            func_0018D580();
            func_0014E290();
            return;
        }
        goto block_13;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x1A))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
block_13:
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) += 1;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x39)));
    (*(u8 *)((u8 *)(reg_a5) + (0x16))) += reg_d0.b[0];
    reg_d7.h[0] = 0x40;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    func_00201E20();
    temp_a0_2 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_2;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (u16) reg_d3.h[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0x40;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    func_00201E20();
    temp_a0_3 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_3;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) reg_d3.h[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0x80;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    func_00201E20();
    temp_a0_4 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_4;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x32))) = (u16) reg_d3.h[0];
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xC0;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    func_00201E20();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    (*(u16 *)((u8 *)(reg_a5) + (0x34))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x36))) = (u16) reg_d3.h[0];
    if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
            (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
            reg_d0.h[0] = 4;
            if ((s32) D_0028E904 >= 0xC0) {
                reg_d0.h[0] = 3;
                if ((s32) D_0028E904 >= 0xE0) {
                    reg_d0.h[0] = 2;
                }
            }
            (*(u8 *)((u8 *)(reg_a5) + (0x24))) = (u8) reg_d0.b[0];
            goto block_19;
        }
    } else {
block_19:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
        (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
            if ((*(s16 *)((u8 *)(reg_a6) + (2))) > 0x1800) {
                reg_d1.w = 0;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d5.h[0] = 0x40;
                reg_d4.w = 0;
                if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x39))) < 0) {
                    reg_d5.h[0] *= 0xFFFF;
                }
                reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                func_00129280();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                func_00129370();
                reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                func_00129280();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                func_00129370();
                reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x30)));
                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                func_00129280();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                func_00129370();
                reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x34)));
                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x36)));
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                func_00129280();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                func_00129370();
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
            }
        }
    }
    (*(u16 *)((u8 *)(reg_a5) + (0x3C))) += 4;
    (*(u16 *)((u8 *)(reg_a5) + (0x3C))) &= 0x3C;
    reg_a0 = (u8 *)D_00258150;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x3C)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0_5 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0_5;
    reg_d1.w += 0xDE00EB00;
    reg_d3.h[0] = 0x22A8;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    func_0019C6D0();
    reg_a0 = (u8 *)D_00258190;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0_6 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_tmp.h[0] = temp_a0_6;
    reg_d4.w = 0;
    reg_d1.w += reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    reg_d3.h[0] = 0x418;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    func_0019C730();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
    temp_a0_7 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w = temp_a0_7 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    func_0019C730();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x30)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
    temp_a0_8 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w = temp_a0_8 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    func_0019C730();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x34)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x36)));
    temp_a0_9 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w = temp_a0_9 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    func_0019C730();
    reg_a0 = reg_a6;
    func_0014D220();
}

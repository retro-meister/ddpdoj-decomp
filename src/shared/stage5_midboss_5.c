#include "common.h"
#include "entity.h"

void func_001FDAB0(void);
void func_001FDBD0(void);
void func_001FDC10(void);
void func_001FDC80(void);
void func_001FDCF0(void);
void func_001FDD60(void);
void func_001FDDD0(void);
void func_001FDE00(void);
void func_001FDED0(void);
void func_001FDFC0(void);
void func_001FE0F0(void);
void func_001FE100(void);
void func_001FE120(void);
void func_001FE2E0(void);
void func_001FE2F0(void);
void func_001FE330(void);
void func_001FE6D0(void);
void func_001FEA90(void);
void func_001FEF40(void);
void func_001FEF70(void);
void func_001FF000(void);
void func_001FF0B0(void);
void func_001FFA50(void);
void func_00200420(void);
void func_002004E0(void);

s32 func_00128930();
extern u16 D_00259970[];
extern u16 D_0028E910;
extern u32 reg_a4_as_u32;

void func_001FC8E0(void) {
    u16 temp_a0;
    u16 var_v0_11;
    u16 var_v0_13;
    u16 var_v0_15;
    u16 var_v0_17;
    u16 var_v0_19;
    u16 var_v0_21;
    u16 var_v0_23;
    u16 var_v0_3;
    u16 var_v0_5;
    u16 var_v0_7;
    u16 var_v0_9;
    u32 temp_s0;
    u32 temp_s0_10;
    u32 temp_s0_11;
    u32 temp_s0_2;
    u32 temp_s0_3;
    u32 temp_s0_4;
    u32 temp_s0_5;
    u32 temp_s0_6;
    u32 temp_s0_7;
    u32 temp_s0_8;
    u32 temp_s0_9;

    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_a4_as_u32 = reg_tmp.w;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        reg_d6.b[0] = 0xFD;
        reg_d1.b[0] = 0x1B;
        reg_d7.w = 0;
        if (D_0028E910 != 0) {
            reg_d7.b[0] = 1;
            reg_d1.b[0] = 0x1E;
        }
    } else {
        reg_d6.b[0] = 3;
        reg_d1.b[0] = 0x25;
        reg_d7.w = 0;
        if (D_0028E910 != 0) {
            reg_d7.b[0] = 0xFF;
            reg_d1.b[0] = 0x22;
        }
    }
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a4_as_u32) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a4_as_u32) + (4)));
    reg_d2.h[0] = temp_a0;
    reg_a0 = (u8 *)(D_00259970);
    reg_d4.w = 0;
    reg_d3.w = 0;
    if (D_0028E910 != 0) {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        var_v0_3 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        temp_s0 = reg_d1.w;
        reg_d3.h[0] = var_v0_3;
        reg_d0.w = 0x4000B;
        func_00128930();
        reg_d0.w -= 0x40000;
        reg_d1.b[0] += reg_d7.b[0];
        func_00128930();
        reg_d1.w = temp_s0;
        reg_d1.b[0] += reg_d6.b[0];
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_5 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_2 = reg_d1.w;
    reg_d3.h[0] = var_v0_5;
    reg_d0.w = 0x8000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_2;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_7 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_3 = reg_d1.w;
    reg_d3.h[0] = var_v0_7;
    reg_d0.w = 0xC000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_3;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_9 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_4 = reg_d1.w;
    reg_d3.h[0] = var_v0_9;
    reg_d0.w = 0x10000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_4;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_11 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_5 = reg_d1.w;
    reg_d3.h[0] = var_v0_11;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_5;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_13 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_6 = reg_d1.w;
    reg_d3.h[0] = var_v0_13;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_6;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_15 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_7 = reg_d1.w;
    reg_d3.h[0] = var_v0_15;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_7;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_17 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_8 = reg_d1.w;
    reg_d3.h[0] = var_v0_17;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_8;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_19 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_9 = reg_d1.w;
    reg_d3.h[0] = var_v0_19;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_9;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_21 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_10 = reg_d1.w;
    reg_d3.h[0] = var_v0_21;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_10;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_23 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_11 = reg_d1.w;
    reg_d3.h[0] = var_v0_23;
    reg_d0.w = 0x14000B;
    func_00128930();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    func_00128930();
    reg_d1.w = temp_s0_11;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d0.w = 0x14000B;
    func_00128930();
}

void func_001FE990();
void func_001FEE40();

void func_001FD750(void) {
    void func_001713F0(s32);
    func_001713F0(4);
}

s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u8 D_00260470[];
extern u8 D_002604B0[];
extern u8 D_002604F0[];
extern u8 D_002661C8[];
extern u8 D_002661E0[];
extern s16 D_0028E884_as_s16;
extern s16 D_0028E888_as_s16;
extern s16 D_00299768[];
extern u16 D_0029C068[];

void func_001FD760(void) {
    reg_a0 = (u8 *)D_002661E0;
    func_0014E370();
    reg_a0 = (u8 *)D_002661C8;
    reg_d0.h[0] = 5;
    func_0014E300();
    reg_tmp.w = 0xF4001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = D_0029C068[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    D_00299768[0] = 1;
    D_0028E888_as_s16 = 1;
    D_0028E884_as_s16 = 1;
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_00260470;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_002604B0;
    func_001A3020();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_002604F0;
    func_001A3020();
}

s32 func_001389D0();
s32 func_0013B8B0();
s32 func_0014D220();
s32 func_001A9000();
s32 func_001A91A0();
extern u8 D_00266330[];
extern u16 D_0028E884;
extern u16 D_0028E888;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;

void func_001FD840() {
    s32 func_0014E290();
    if (D_0028E8A0 == 0) {
        if (*(u8 *)(reg_a6 + 0x9F) != 0) {
            D_0028E888 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
            func_0014E290();
            return;
        }
        if ((*(u8 *)(reg_a5 + 0x17) == 0) && (*(u8 *)(reg_a6 + 0x9E) == 0) && (D_0028E8A8 == 0x1F0)) {
            *(u8 *)(reg_a5 + 0x17) = 1U;
            *(u16 *)(reg_a5 + 0x20) = 1U;
            reg_d0.w = 7;
            func_001FDDD0();
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            *(u16 *)(reg_a6 + 0x8E) = (u16) reg_d1.h[0];
            func_001A9000();
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
            reg_d0.b[0] ^= 0xD;
            *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
            if (*(u8 *)(reg_a5 + 0x17) == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                reg_tmp.w -= reg_d0.w;
                *(u16 *)(reg_a5 + 0x1A) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a5 + 0x1C) = (u16) reg_tmp.h[0];
            }
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                func_001A91A0();
                ENTITY(reg_a6)->flags.h = 0x8000;
                *(u8 *)(reg_a6 + 0x9E) = 1U;
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
            *(u8 *)(reg_a6 + 0x1C) = 0x12U;
        }
        func_001FF0B0();
        if (*(u8 *)(reg_a6 + 0x9E) == 0) {
            func_001FDE00();
            if (*(u16 *)(reg_a5 + 0x20) == 0) {
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


void func_001FDAB0(void) {
    reg_d2.w = 0x1E92;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF7000000;
    reg_d1.w += 0xF600F900;
    reg_d3.h[0] = 0xA38;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_001FDBD0();
    reg_d2.w = 0x1E91;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x1E);
    reg_d1.w += 0x0C800000;
    reg_d1.w += 0xF200EF00;
    reg_d3.h[0] = 0xE88;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_001FDBD0();
    reg_d2.w = 0x1E90;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF200E600;
    reg_d3.h[0] = 0xED0;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_001FDBD0();
}

s32 func_0019C470();                            /* extern */
s32 func_0019C530();                            /* extern */

void func_001FDBD0(void) {
    if (*(u8 *)(reg_a5 + 0x16) == 0) {
        func_0019C470();
        return;
    }
    func_0019C530();
}


void func_001FDC10(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w += 0xFC3FEC80U;
    reg_d1.h[0] += *(u16 *)(object + 0x48);
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x5C];
    func_001FDBD0();
}

void func_001FDC80(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w += 0xFC401380U;
    reg_d1.h[0] -= *(u16 *)(object + 0x4A);
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x0608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x5C];
    func_001FDBD0();
}

extern void *reg_a6_as_void_p;

void func_001FDCF0(void)
{
    u8 *object;

    reg_d2.w = 0x1E93;
    object = reg_a6_as_void_p;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.h[1] += *(u16 *)(object + 0x68);
    reg_d1.w += 0xF47FFC00u;
    reg_d4.w = 0;
    reg_d1.w += 0xF600FE00u;
    reg_d3.h[0] = 0xA10;
    *(u8 *)&reg_d4 = object[0x7C];
    func_001FDBD0();
}

void func_001FDD60(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E93;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.h[1] += *(u16 *)(object + 0x6A);
    reg_d1.w += 0xF4800400U;
    reg_d1.w += 0xF600FE00U;
    reg_d3.h[0] = 0x0A10;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x7C];
    func_001FDBD0();
}

void func_001FDDD0(void) {
    if (((u16 *)reg_a6_as_void_p)[0x26 / 2] != reg_d0.h[0]) {
        ((u16 *)reg_a6_as_void_p)[0x26 / 2] = (u16) reg_d0.h[0];
        ((u16 *)reg_a6_as_void_p)[0x28 / 2] = 0;
    }
}

s32 func_00201C60();

void func_001FDE00(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    switch (reg_d0.h[0]) {
    case 0:
        func_001FDED0();
        break;
    case 1:
        func_001FDFC0();
        break;
    case 2:
        func_001FE6D0();
        break;
    case 3:
        func_001FE990();
        break;
    case 4:
        func_001FEA90();
        break;
    case 5:
        func_001FEE40();
        break;
    case 6:
        func_001FEF40();
        break;
    case 7:
        func_001FEF70();
        break;
    }
    func_00201C60();
}

void func_001FDED0(void) {
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        ENTITY(reg_a6)->move.sh = 0x1600;
        *(s16 *)(reg_a6 + 0x34) = 0x202;
        *(u16 *)(reg_a6 + 0x28) = 1U;
    }
    if ((*(u16 *)(reg_a6 + 0x28) == 1) && (ENTITY(reg_a6)->y.sh >= 0x2000)) {
        *(u16 *)(reg_a6 + 0x28) = 2U;
    }
    if (*(u16 *)(reg_a6 + 0x28) == 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x35);
        *(u8 *)(reg_a6 + 0x35) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a6 + 0x35) = *(u8 *)(reg_a6 + 0x34);
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                *(s8 *)(reg_a5 + 0x16) = 1;
                ENTITY(reg_a6)->flags.h = 0xA001;
                reg_d0.w = 1;
                func_001FDDD0();
            }
        }
    }
}

extern u8 D_0028DA58;

void func_001FDFC0() {
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        *(u16 *)(reg_a6 + 0x28) = 1U;
        ENTITY(reg_a6)->move.sb.speed = 4;
        *(u16 *)(reg_a6 + 0x2A) = 0U;
        *(u16 *)(reg_a6 + 0x30) = 0x12CU;
        func_001FE100();
        func_001FE2F0();
    }
    reg_a0 = &D_0028DA58;
    reg_a0 += *(u16 *)(reg_a6 + 0x2A);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_001FF000();
    if (cond_flag == 0) {
        *(u16 *)(reg_a6 + 0x2A) += 4;
        *(u16 *)(reg_a6 + 0x2A) &= 7;
    }
    *(u16 *)(reg_a6 + 0x30) -= 1;
    if (*(u16 *)(reg_a6 + 0x30) == 0) {
        reg_d0.w = 2;
        if (*(u16 *)(reg_a5 + 0x18) != 0) {
            reg_d0.w = 4;
        }
        func_001FDDD0();
        *(u16 *)(reg_a5 + 0x18) += 1;
        *(u16 *)(reg_a5 + 0x18) &= 1;
        func_001FE0F0();
        func_001FE2E0();
    }
}

void func_001FE0F0(void) {
    *(s16 *)(reg_a6 + 0x46) = 0;
}

typedef struct FuncFe100Obj {
    u8 pad_00[0x46];
    s16 unk46;
    u8 pad_48[0x4];
    s16 unk4C;
} FuncFe100Obj;

extern FuncFe100Obj *reg_a6_as_FuncFe100Obj_p;

void func_001FE100(void) {
    reg_a6_as_FuncFe100Obj_p->unk46 = 1;
    reg_a6_as_FuncFe100Obj_p->unk4C = 0;
}

s32 func_0014E030();
extern u16 D_0028E3F0;

void func_001FE120(void) {
    u16 temp_v1;
    u16 temp_v1_2;

    if (*(u16 *)(reg_a6 + 0x46) != 0) {
        if (*(u16 *)(reg_a6 + 0x4C) == 1) {
            *(u16 *)(reg_a6 + 0x48) = 0xA00U;
            *(u16 *)(reg_a6 + 0x4A) = 0xA00U;
            *(u16 *)(reg_a6 + 0x4C) = 0U;
        }
        if (*(u16 *)(reg_a6 + 0x4C) == 0) {
            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x48);
            reg_d0.h[0] += *(u16 *)(reg_a6 + 0x4A);
            if (reg_d0.h[0] == 0) {
                reg_d0.w = 0;
                reg_d0.h[0] &= D_0028E3F0;
                if (reg_d0.h[0] == 0) {
                    *(u16 *)(reg_a6 + 0x4C) = 1U;
                    reg_d0.w = 0x4E;
                    func_0014E030();
                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.w += 0xFC3FEC80;
                    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                    *(u16 *)(reg_a0 + 0x1A) = 0xFA00;
                    reg_d0.w = 0x4E;
                    func_0014E030();
                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.w += 0xFC401380;
                    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                    *(s16 *)(reg_a0 + 0x1A) = 0x600;
                }
            }
        }
    }
    temp_v1 = *(u16 *)(reg_a6 + 0x48);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a6 + 0x48) = (u16) (temp_v1 - 0x100);
        if ((s16) *(u16 *)(reg_a6 + 0x48) <= 0) {
            *(u16 *)(reg_a6 + 0x48) = 0U;
        }
    }
    temp_v1_2 = *(u16 *)(reg_a6 + 0x4A);
    if (temp_v1_2 != 0) {
        *(u16 *)(reg_a6 + 0x4A) = (u16) (temp_v1_2 - 0x100);
        if ((s16) *(u16 *)(reg_a6 + 0x4A) <= 0) {
            *(u16 *)(reg_a6 + 0x4A) = 0U;
        }
    }
}

void func_001FE2E0(void) {
    *(u16 *)(reg_a6 + 0x66) = 0;
}


void func_001FE2F0(void) {
    *(s16 *)(reg_a6 + 0x66) = 1;
    *(s16 *)(reg_a6 + 0x6C) = 0;
    *(s16 *)(reg_a6 + 0x6E) = 0x1818;
    if (D_0028E910 != 0) {
        *(s16 *)(reg_a6 + 0x6E) = 0x404;
    }
}

s32 func_00128970();
s32 func_002011A0();
extern u8 D_00259870_as_u8_a[];
extern u16 D_0028E3DC;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern s16 D_0029F260[];
extern u16 D_0029F262[];

void func_001FE330(void) {
    u16 t1;
    u16 t2;
    if (*(u16 *)(reg_a6 + 0x66) != 0) {
        if (*(u16 *)(reg_a6 + 0x6C) == 1) {
            *(u16 *)(reg_a6 + 0x68) = 0x800U;
            *(u16 *)(reg_a6 + 0x6C) = 0U;
        }
        if (*(u16 *)(reg_a6 + 0x6C) == 2) {
            *(u16 *)(reg_a6 + 0x6A) = 0x800U;
            *(u16 *)(reg_a6 + 0x6C) = 0U;
        }
        if (*(u16 *)(reg_a6 + 0x6C) == 0) {
            if (D_0028E3DC == 0) {
                reg_d0.w = 0;
                if (D_0029F260[0] < 0) {
                    reg_d0.h[0] = D_0029F262[0];
                }
                reg_d1.w = 0;
                if (D_0029F1F0[0] < 0) {
                    reg_d1.h[0] = D_0029F1F2[0];
                }
                if ((s32) reg_d0.h[0] <= (s32) reg_d1.h[0]) {
                    reg_d0.h[0] = reg_d1.h[0];
                }
                reg_d1.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] -= 0x400;
                if ((s32) reg_d1.h[0] <= (s32) reg_d0.h[0]) {
                    reg_d7.h[0] = 0x24;
                    reg_d0.w = 0x10007;
                    reg_d1.h[0] = 0x2E;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a0 = (u8 *)D_00259870_as_u8_a;
                    reg_d5.w = 0;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] &= 0x3F;
                        reg_d3.h[0] *= 4;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        func_00128970();
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3F;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                }
            }
            reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x6F);
            *(u8 *)(reg_a6 + 0x6F) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a6 + 0x6F) = (u8) *(u8 *)(reg_a6 + 0x6E);
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x68);
                reg_d0.h[0] += *(u16 *)(reg_a6 + 0x6A);
                if (reg_d0.h[0] == 0) {
                    func_002011A0();
                    reg_d0.h[0] &= 1;
                    if (reg_d0.h[0] == 0) {
                        reg_d0.w = 0x50;
                        func_0014E030();
                        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w += 0xF47FFC00;
                        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                        *(u16 *)(reg_a6 + 0x6C) = 1;
                    } else {
                        reg_d0.w = 0x50;
                        func_0014E030();
                        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w += 0xF4800400;
                        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                        *(u16 *)(reg_a6 + 0x6C) = 2;
                    }
                }
            }
        }
    }
    t1 = *(u16 *)(reg_a6 + 0x68);
    if (t1 != 0) {
        *(u16 *)(reg_a6 + 0x68) = (u16) (t1 - 0x80);
        if ((s16) *(u16 *)(reg_a6 + 0x68) <= 0) {
            *(u16 *)(reg_a6 + 0x68) = 0U;
        }
    }
    t2 = *(u16 *)(reg_a6 + 0x6A);
    if (t2 != 0) {
        *(u16 *)(reg_a6 + 0x6A) = (u16) (t2 - 0x80);
        if ((s16) *(u16 *)(reg_a6 + 0x6A) <= 0) {
            *(u16 *)(reg_a6 + 0x6A) = 0U;
        }
    }
}

extern u8 D_00266270[];

void func_001FE6D0(void) {
    u16 temp_a0;
    u32 temp_a1;
    u32 temp_a1_2;

    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        *(u16 *)(reg_a6 + 0x28) = 1U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
        *(u8 *)(reg_a6 + 0x2B) = 0U;
        *(u8 *)(reg_a6 + 0x2A) = 0U;
        *(u8 *)(reg_a6 + 0x35) = 0x10U;
    }
    temp_a0 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x2800;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            *(u16 *)(reg_a6 + 0x28) = 2U;
        }
    }
    if (*(u16 *)(reg_a6 + 0x28) == 2) {
        *(u16 *)(reg_a5 + 0x1E) += 0x40;
        if ((s16) *(u16 *)(reg_a5 + 0x1E) >= 0x600) {
            *(u16 *)(reg_a5 + 0x1E) = 0x600U;
            *(u16 *)(reg_a6 + 0x28) = 3U;
        }
    }
    if (*(u16 *)(reg_a6 + 0x28) == 3) {
        reg_d1.w = 1;
        reg_d1.h[0] &= D_0028E3F0;
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x35);
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = 0x52;
            func_0014E030();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C7FF600;
            temp_a1 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a1 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            *(u8 *)(reg_a0 + 0x1B) = (u8) *(u8 *)(reg_a6 + 0x2B);
            *(u8 *)(reg_a6 + 0x2B) += 4;
            *(u8 *)(reg_a6 + 0x2B) &= 0x3F;
            reg_d0.w = 0x52;
            func_0014E030();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C800A00;
            temp_a1_2 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a1_2 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            *(u8 *)(reg_a0 + 0x1B) = (u8) *(u8 *)(reg_a6 + 0x2A);
            *(u8 *)(reg_a6 + 0x2A) -= 4;
            *(u8 *)(reg_a6 + 0x2A) &= 0x3F;
            *(u8 *)(reg_a6 + 0x35) -= 1;
            if (*(u8 *)(reg_a6 + 0x35) == 0) {
                reg_d0.w = 3;
                func_001FDDD0();
            }
        }
    }
}

void func_001FE990(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        var_a1 = 0xF0;
        *(u16 *)(reg_a6 + 0x28) = 1U;
        *(u16 *)(reg_a6 + 0x30) = 0xF0U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
    }
    temp_v1 = *(u16 *)(reg_a5 + 0x1E);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a5 + 0x1E) = (u16) (temp_v1 - 0x40);
        if ((s16) *(u16 *)(reg_a5 + 0x1E) <= 0) {
            *(u16 *)(reg_a5 + 0x1E) = 0U;
        }
    }
    temp_a0 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            *(u16 *)(reg_a6 + 0x28) = 2U;
        }
    }
    temp_a0_2 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0_2 == 2) {
        *(u16 *)(reg_a6 + 0x30) -= 1;
        if (*(u16 *)(reg_a6 + 0x30) == 0) {
            reg_d0.w = 1;
            func_001FDDD0();
        }
    }
}

void func_001FEA90(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u32 temp_a2;
    u8 temp_a1;

    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        *(u16 *)(reg_a6 + 0x28) = 1U;
        ENTITY(reg_a6)->move.sb.speed = 8;
        *(u8 *)(reg_a6 + 0x2B) = 0U;
    }
    temp_a0 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x3200;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 4;
            *(u16 *)(reg_a6 + 0x28) = 2U;
            *(u8 *)(reg_a6 + 0x2B) = 1U;
        }
    }
    temp_a0_2 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0_2 == 2) {
        reg_d2.h[0] = 0x3600;
        reg_d3.h[0] = 0x2A00;
        func_001FF000();
        if (cond_flag == 0) {
            *(u16 *)(reg_a6 + 0x28) = 3U;
            *(u8 *)(reg_a6 + 0x2B) = 1U;
        }
    }
    temp_a0_3 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0_3 == 3) {
        reg_d2.h[0] = 0x3600;
        reg_d3.h[0] = 0xE00;
        func_001FF000();
        if (cond_flag == 0) {
            reg_d0.w = 5;
            func_001FDDD0();
        }
    }
    if ((*(u8 *)(reg_a6 + 0x2B) == 1) && ((temp_a0_4 = *(u16 *)(reg_a5 + 0x1E), (temp_a0_4 == 0x600)) || (*(u16 *)(reg_a5 + 0x1E) = (u16) (temp_a0_4 + 0x40), (((s16) *(u16 *)(reg_a5 + 0x1E) < 0x600) == 0)))) {
        *(u16 *)(reg_a5 + 0x1E) = 0x600U;
        *(u8 *)(reg_a6 + 0x2B) = 2U;
        *(u8 *)(reg_a6 + 0x2A) = 8U;
        *(u8 *)(reg_a6 + 0x35) = 0U;
    }
    if (*(u8 *)(reg_a6 + 0x2B) == 2) {
        reg_d1.h[0] = D_0028E3F0;
        reg_d1.b[0] &= 7;
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x2A);
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = 0x58;
            func_0014E030();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C7FF600;
            temp_a2 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a2 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            reg_d1.w = 4;
            temp_a1 = *(u8 *)(reg_a6 + 0x35);
            reg_d1.b[0] -= temp_a1;
            reg_d1.b[0] &= 0x3F;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d1.b[0];
            *(u8 *)(reg_a6 + 0x35) += 1;
            *(u8 *)(reg_a6 + 0x35) &= 7;
            reg_d0.w = 0x58;
            func_0014E030();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C800A00;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w += reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            reg_d1.w = 4;
            reg_d1.b[0] -= *(u8 *)(reg_a6 + 0x35);
            reg_d1.b[0] &= 0x3F;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d1.b[0];
            *(u8 *)(reg_a6 + 0x35) += 1;
            *(u8 *)(reg_a6 + 0x35) &= 7;
            *(u8 *)(reg_a6 + 0x2A) -= 1;
            if (*(u8 *)(reg_a6 + 0x2A) == 0) {
                *(u8 *)(reg_a6 + 0x2B) = 0U;
            }
        }
    }
}

void func_001FEE40(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        var_a1 = 0x40;
        *(u16 *)(reg_a6 + 0x28) = 1U;
        *(u16 *)(reg_a6 + 0x30) = 0x40U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
    }
    temp_v1 = *(u16 *)(reg_a5 + 0x1E);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a5 + 0x1E) = (u16) (temp_v1 - 0x40);
        if ((s16) *(u16 *)(reg_a5 + 0x1E) <= 0) {
            *(u16 *)(reg_a5 + 0x1E) = 0U;
        }
    }
    temp_a0 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            *(u16 *)(reg_a6 + 0x28) = 2U;
        }
    }
    temp_a0_2 = *(u16 *)(reg_a6 + 0x28);
    if (temp_a0_2 == 2) {
        *(u16 *)(reg_a6 + 0x30) -= 1;
        if (*(u16 *)(reg_a6 + 0x30) == 0) {
            reg_d0.w = 1;
            func_001FDDD0();
        }
    }
}

void func_001FEF40(void) {
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        *(u16 *)(reg_a6 + 0x28) = 1;
        ENTITY(reg_a6)->move.h = 0x420;
    }
}

void func_001FEF70(void) {
    u8 temp_v1;

    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        *(u16 *)(reg_a6 + 0x28) = 1U;
        ENTITY(reg_a6)->move.sb.dir = 0;
    }
    temp_v1 = ENTITY(reg_a6)->move.b.speed;
    if (temp_v1 != 8) {
        ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 + 1);
        if ((s8) ENTITY(reg_a6)->move.b.speed >= 8) {
            ENTITY(reg_a6)->move.b.speed = 8U;
        }
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x67FF) {
        *(s8 *)(reg_a6 + 0x9F) = 1;
    }
}

s32 func_002021D0();                            /* extern */
s32 func_002024F0();                            /* extern */
s32 func_00202B50();                            /* extern */

void func_001FF000(void) {
    reg_d0.h[0] = D_0029C068[0];
    reg_d3.h[0] -= reg_d0.h[0];
    func_00202B50();
    if (((s16) reg_d0.h[0] >= 0x200) || (ENTITY(reg_a6)->move.sb.speed = 8, (((s16) reg_d0.h[0] < 0x100) == 0)) || (ENTITY(reg_a6)->move.sb.speed = 6, (((s16) reg_d0.h[0] < 0x40) == 0))) {
        func_002021D0();
        func_002024F0();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 func_0013A780();
s32 func_0013AB50();
s32 func_0018D500();
s32 func_0018D5C0();
s32 func_001D5040();
s32 func_002010A0();
s32 func_00201710();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_00266290[];
extern u16 D_002662E0[];

void func_001FF0B0(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;

    if (*(u8 *)(reg_a6 + 0x9E) != 0) {
        ENTITY(reg_a6)->y.h -= 0x40;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x8E);
        func_00201710();
        temp_a0 = *(u8 *)(reg_a6 + 0x87);
        if (temp_a0 == 2) {
            *(s8 *)(reg_a6 + 0x9F) = 1;
            goto block_set;
        }
        if (temp_a0 == 1) {
            *(u8 *)(reg_a6 + 0x89) -= 1;
            if (*(u8 *)(reg_a6 + 0x89) == 0) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(D_002662E0);
                func_001D5040();
                func_002010A0();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0x40;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_2 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_2;
                reg_d2.w += 0xF8000800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                func_0013AB50();
                func_002010A0();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0xC0;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_3 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_3;
                reg_d2.w += 0x01FFF800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                func_0013AB50();
                func_0018D5C0();
                *(u8 *)(reg_a6 + 0x89) = 0x10U;
                *(u8 *)(reg_a6 + 0x87) = 2U;
                vibration_start_pad1(0xB4, 0x3C, 0x10);
                vibration_start_pad2(0xB4, 0x3C);
            }
        }
        if (*(u8 *)(reg_a6 + 0x87) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x89);
            *(u8 *)(reg_a6 + 0x89) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a6 + 0x89) = (u8) *(u8 *)(reg_a6 + 0x88);
                func_0018D500();
                reg_a1 = (u8 *)(D_00266290);
                reg_a1 += *(u16 *)(reg_a6 + 0x8A);
                reg_d1.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
                *(s16 *)(reg_a0 + 0x1E) = 0x10;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] *= 4;
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a6 + 0x8A) += 0xC;
                if (*(u16 *)(reg_a6 + 0x8A) == 0x48) {
                    *(u16 *)(reg_a6 + 0x8A) = 0U;
                    *(u16 *)(reg_a6 + 0x8C) -= 1;
                    if (*(u16 *)(reg_a6 + 0x8C) == 0) {
                        *(u16 *)(reg_a6 + 0x88) = 0x1006;
                        *(u8 *)(reg_a6 + 0x87) = 1U;
                    }
                }
            }
        }
        goto block_11;
    }
block_11:
    cond_flag = 0;
    return;
block_set:
    cond_flag = 1;
}

void func_001FF420(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

extern u8 D_00266340[];
extern u8 D_0028DA38;

void func_001FF430() {
    u16 temp_a1;

    reg_a0 = D_00266340;
    func_0014E370();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA38;
    reg_d0.h[0] = 1;
    func_0014E300();
}

s32 func_0019C4F0();
s32 func_00201D10();
extern u8 D_0028E2E4;

void func_001FF490(void) {
    s32 func_0014E290();
    if (D_0028E2E4 != 0) goto block_end;
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00201D10();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto block_disp;
    reg_d0.w = 0x4F;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x4F;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x16) += 0xA00;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a0 + 0x18) += reg_d0.h[0];
block_end:
    func_0014E290();
    return;
block_disp:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_d2.w = 0x1E94;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FF00;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_0019C4F0();
}

void func_001FF600(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

extern u8 D_00266360[];
extern u8 D_0028DA40;

void func_001FF610() {
    u16 temp_a1;

    reg_a0 = D_00266360;
    func_0014E370();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA40;
    reg_d0.h[0] = 2;
    func_0014E300();
}

s32 func_0019C7F0();
s32 func_0019D710();
s32 func_00203060();
extern u8 D_00266380[];
extern u16 D_0028E3E4;

void func_001FF670(void) {
    s32 func_0014E290();
    u8 *t1;
    u16 t2;
    u8 t3;

    if (D_0028E2E4 != 0) goto block_end1;
    {
        if (D_0028E884 == 0) {
            func_001FFA50();
            return;
        }
        func_00203060();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
block_end1:
            func_0014E290();
            return;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00201D10();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                t1 = (u8 *)1;
                *(u8 *)(reg_a5 + 0x16) = 1U;
                ENTITY(reg_a6)->move.b.dir = 0x20U;
            }
        } else {
            ENTITY(reg_a6)->move.b.speed += 1;
            if (D_0028E910 != 0) {
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x18) += 4;
            if ((s16) *(u16 *)(reg_a5 + 0x18) >= 0x2C) {
                *(u16 *)(reg_a5 + 0x18) = 0x14U;
            }
        }
        reg_a0 = reg_a6;
        func_0014D220();
        reg_a0 = (u8 *)D_00266380;
        reg_a0 += *(u16 *)(reg_a5 + 0x18);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = t2;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        t3 = *(u8 *)(reg_a6 + 0x1C);
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (D_0028E3E4 != 0) {
            func_0019D710();
        } else {
            func_0019C7F0();
        }
    }
}

void func_001FF8B0(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

extern u8 D_002663C0[];
extern u8 D_0028DA48;

void func_001FF8C0() {
    u16 temp_a1;

    reg_a0 = D_002663C0;
    func_0014E370();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA48;
    reg_d0.h[0] = 1;
    func_0014E300();
}

void func_001FF920(void) {
    s32 func_0014E290();
    if (D_0028E2E4 != 0) goto block_1;
    if (D_0028E884 == 0) {
        func_001FFA50();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00201D10();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_1;
    reg_d0.w = 0x51;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
block_1:
    func_0014E290();
    return;
next_1:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_d2.w = 0x1E93;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF600FE00;
    reg_d3.h[0] = 0xA10;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_0019C4F0();
}

s32 func_0013A780();                            /* extern */

void func_001FFA50(void) {
    s32 func_0014E290(u16);
    u16 temp_a0;

    reg_d0.h[0] = 4;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = temp_a0;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    func_0014E290(temp_a0);
}

void func_001FFAA0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

extern u8 D_002663E0[];
extern u8 D_0028DA50;

void func_001FFAB0() {
    u16 temp_a1;

    reg_a0 = D_002663E0;
    func_0014E370();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA50;
    reg_d0.h[0] = 2;
    func_0014E300();
}

extern u8 D_00266400[];

void func_001FFB10(void) {
    s32 func_0014E290();
    u8 *t1;
    u16 t2;
    u8 t3;
    u8 t4;
    u8 t5;

    if (D_0028E2E4 != 0) goto block_end1;
    {
        func_00203060();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
block_end1:
            func_0014E290();
            return;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00201D10();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                t1 = (u8 *)0x20;
                *(u8 *)(reg_a5 + 0x16) = 1U;
                ENTITY(reg_a6)->move.b.dir = 0x20U;
                ENTITY(reg_a6)->flags.h = 0x8001;
            }
        } else if (D_0028E910 == 0) {
            t1 = (u8 *)(reg_a6 + 0x1B);
            t5 = ENTITY(reg_a6)->move.b.speed;
            if (t5 != 0x1C) {
                ENTITY(reg_a6)->move.b.speed = (u8) (t5 + 1);
            }
        } else {
            t4 = ENTITY(reg_a6)->move.b.speed;
            if ((s32) t4 < 0x3C) {
                ENTITY(reg_a6)->move.b.speed = (u8) (t4 + 4);
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x18) += 4;
            if ((s32) *(u16 *)(reg_a5 + 0x18) >= 0x38) {
                *(u16 *)(reg_a5 + 0x18) = 0x28U;
            }
        }
        reg_a0 = reg_a6;
        func_0014D220();
        reg_a0 = (u8 *)D_00266400;
        reg_a0 += *(u16 *)(reg_a5 + 0x18);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = t2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        t3 = *(u8 *)(reg_a6 + 0x1C);
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (D_0028E3E4 != 0) {
            func_0019D710();
        } else {
            func_0019C7F0();
        }
    }
}

void func_001FFD60(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

extern u8 D_00266440[];
extern u8 D_00266460[];

void func_001FFD70() {
    u8 temp_a1;

    reg_a0 = D_00266460;
    func_0014E370();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a1 = *(u8 *)(reg_a5 + 0x1B);
    ENTITY(reg_a6)->move.b.dir = temp_a1;
    reg_a0 = D_00266440;
    reg_d0.h[0] = 8;
    func_0014E300();
}

s32 func_0018D560();
s32 func_00202490();
s32 func_00202500();

void func_001FFDE0(void) {
    s32 func_0014E290();
    u8 t;
    u8 c;

    func_00201C60();
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if (*(u16 *)(reg_a5 + 0x1C) == 0) goto block_1;
    if (D_0028E888 == 0) goto block_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_1;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_2;
block_1:
    reg_d0.h[0] = 0x14;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    func_0018D560();
    func_0014E290();
    return;
next_1:
    *(u8 *)(reg_a6 + 0x1C) = 0x13;
next_2:
    t = *(u8 *)(reg_a5 + 0x18);
    if (!(t & 8)) goto next_7;
    if (t & 0x80) goto next_6;
    if (!(0 > ENTITY(reg_a6)->x.sh)) goto next_3;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_3:
    if (ENTITY(reg_a6)->x.sh <= 0x3800) goto next_4;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_4:
    if (!(ENTITY(reg_a6)->y.sh < 0x3200)) goto next_6;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_6:
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 8) goto next_7;
    *(u8 *)(reg_a5 + 0x18) = 4;
    *(s8 *)(reg_a5 + 0x16) = 0;
next_7:
    if (!(*(u8 *)(reg_a5 + 0x18) & 1)) goto next_8;
    *(s8 *)(reg_a5 + 0x16) = 1;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto next_8;
    *(u16 *)(reg_a5 + 0x1A) += 4;
    if ((s16) *(u16 *)(reg_a5 + 0x1A) < 0xC) goto next_8;
    *(u8 *)(reg_a5 + 0x18) &= 0xFE;
    *(u8 *)(reg_a5 + 0x18) |= 2;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(u16 *)(reg_a5 + 0x1E) = 8;
next_8:
    if (!(*(u8 *)(reg_a5 + 0x18) & 2)) goto next_11;
    *(s8 *)(reg_a5 + 0x16) = 1;
    if (*(u16 *)(reg_a5 + 0x1E) == 0) goto next_10;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto next_11;
    *(u16 *)(reg_a5 + 0x1E) -= 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 8) goto next_9;
    *(u16 *)(reg_a5 + 0x1A) = 0;
next_9:
    *(u16 *)(reg_a5 + 0x1A) += 4;
    goto next_11;
next_10:
    *(u8 *)(reg_a5 + 0x18) &= 0xFD;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(s8 *)(reg_a5 + 0x16) = 0;
next_11:
    if (!(*(u8 *)(reg_a5 + 0x18) & 4)) goto next_14;
    reg_d6.w = 0;
    reg_d7.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00202490();
    if (cond_flag != 0) goto next_12;
    reg_d6.w = 1;
    reg_d7.b[0] -= reg_d1.b[0];
    if (reg_d7.b[0] == 0) goto next_12;
    goto next_14;
next_12:
    if (reg_d6.b[0] != 0) goto next_13;
    *(u8 *)(reg_a5 + 0x21) = 1;
next_13:
    *(u8 *)(reg_a5 + 0x18) = 0x10;
    *(u16 *)(reg_a5 + 0x22) = 4;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
next_14:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x10)) goto next_17;
    c = *(u8 *)(reg_a5 + 0x25);
    if (c == 0) goto next_15;
    *(u8 *)(reg_a5 + 0x25) = c - 1;
    goto next_17;
next_15:
    if (*(u16 *)(reg_a5 + 0x22) == 0) goto next_16;
    if (*(u8 *)(reg_a5 + 0x21) != 0) goto block_2;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.b[0] &= 7;
    if (reg_d0.b[0] != 0) goto next_17;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.w = 0x80007;
    reg_d3.w = 0;
    reg_d1.b[0] += 1;
    func_00128970();
    reg_d1.b[0] -= 2;
    func_00128970();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.w = 0x30;
    func_00201D10();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
block_2:
    *(u16 *)(reg_a5 + 0x22) -= 1;
    goto next_17;
next_16:
    *(u8 *)(reg_a5 + 0x18) = 0x20;
    func_002010A0();
    *(u8 *)(reg_a5 + 0x27) = ENTITY(reg_a6)->move.b.dir;
    *(u8 *)(reg_a5 + 0x27) += reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x27) &= 0x3F;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
    *(u8 *)(reg_a5 + 0x21) = 0;
next_17:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x20)) goto next_19;
    c = *(u8 *)(reg_a5 + 0x25);
    if (c == 0) goto next_18;
    *(u8 *)(reg_a5 + 0x25) = c - 1;
    goto next_19;
next_18:
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x27);
    func_00202500();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    reg_d1.b[0] -= *(u8 *)(reg_a5 + 0x27);
    if (reg_d1.b[0] != 0) goto next_19;
    *(u8 *)(reg_a5 + 0x18) = 0x40;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
next_19:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x40)) goto next_20;
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if (*(u8 *)(reg_a5 + 0x25) != 0) goto next_20;
    *(u8 *)(reg_a5 + 0x18) = 9;
    ENTITY(reg_a6)->move.b.speed = 0x20;
    func_002011A0();
    reg_d0.b[0] &= 7;
    ENTITY(reg_a6)->move.b.speed += reg_d0.b[0];
next_20:
    func_00200420();
    func_002004E0();
    reg_a0 = reg_a6;
    func_0014D220();
}

s32 func_0019C570();
extern u8 D_00266480[];

void func_00200420(void) {
    u16 temp_a0;

    if (*(u8 *)(reg_a5 + 0x16) == 0) {
        reg_a0 = (u8 *)D_00266480;
        reg_d0.w = 0xE;
        reg_d0.b[0] &= ENTITY(reg_a6)->move.b.dir;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
        func_0019C570();
    }
}

extern u8 D_002664A0[];

void func_002004E0(void) {
    u16 temp_a0;

    if (*(u8 *)(reg_a5 + 0x16) != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_002664A0;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] *= 8;
        reg_a0 += reg_d1.h[0];
        reg_a1 = reg_a0;
        reg_a0 += *(u16 *)(reg_a5 + 0x1A);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 0xE);
        reg_d4.w += reg_tmp.w;
        func_0019C570();
    }
}

void func_002005D0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_00202180();
extern u8 D_002666A0[];
extern u8 D_002666B0[];

void func_002005E0() {
    u8 temp_a1;

    reg_a0 = D_002666B0;
    func_0014E370();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a1 = *(u8 *)(reg_a5 + 0x1B);
    ENTITY(reg_a6)->move.b.dir = temp_a1;
    reg_a0 = D_002666A0;
    reg_d0.h[0] = 7;
    func_0014E300();
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00201D10();
    *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x20) = (u16) reg_d3.h[0];
    *(u8 *)(reg_a5 + 0x1D) = 0x20U;
    func_00202180();
    if (cond_flag == 0) {
        *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d1.b[0];
    }
}

s32 func_002009C0();

void func_002006B0(void) {
    s32 func_0014E290();
    if (ENTITY(reg_a6)->y.sh > -0x400) goto next_1;
    func_0014E290();
    return;
next_1:
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.w += reg_d0.w;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    *(u16 *)(reg_a5 + 0x1E) -= 2;
    if (D_0028E888 == 0) goto block_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_2;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_3;
block_1:
    reg_d0.h[0] = 0x14;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    func_0018D560();
    func_0014E290();
    return;
next_2:
    *(u8 *)(reg_a6 + 0x1C) = 0x13;
next_3:
    reg_d0.w = 3;
    reg_d0.h[0] &= D_0028E3F0;
    if (reg_d0.h[0] != 0) goto next_4;
    *(u16 *)(reg_a5 + 0x1A) += 4;
    *(u16 *)(reg_a5 + 0x1A) &= 0x1F;
next_4:
    if (*(u16 *)(reg_a5 + 0x24) == 0) goto next_5;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_5;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    *(u8 *)(reg_a5 + 0x1D) += 3;
    *(u8 *)(reg_a5 + 0x1D) &= 0x3F;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d0.w = 0xFFFC0007;
    reg_d4.w = 0;
    reg_d3.w = 0;
    func_002009C0();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    func_002009C0();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    func_002009C0();
    *(u16 *)(reg_a5 + 0x24) -= 1;
next_5:
    reg_a0 = (u8 *)D_00266480;
    reg_a0 += *(u16 *)(reg_a5 + 0x1A);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_0019C570();
    reg_a0 = reg_a6;
    func_0014D220();
}

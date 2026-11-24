#include "common.h"

void func_001BC930(void);
void func_001BDD40(void);
void func_001BDEE0(void);
void func_001BDFC0(void);

s32 func_00129410();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001BC4B0(void) {

    reg_d0.w = 0x50003;
    reg_d7.w = 3;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += 0x12000000;
        if (!((*(u8 *)((u8 *)(reg_a6) + (0xC))) & 1)) {
            func_00129410();
        }
        reg_d1.h[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 func_00129370();

void func_001BC5D0(void) {

    reg_d0.w = 0x50004;
    reg_d7.w = 3;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += 0x27000000;
        if ((*(u8 *)((u8 *)(reg_a6) + (0xC))) & 1) {
            func_00129370();
        }
        reg_d1.h[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 func_0013A780();
s32 func_0018D5C0();
extern u8 D_00262680[];
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001BC6F0(arg1)
    u16 arg1;
{
    s16 var_a0;
    u16 temp_a1;
    u16 var_a1;

    var_a1 = arg1;
    var_a0 = 0x70;
    (*(s8 *)((u8 *)(reg_a5) + (0x16))) = 0x70;
    reg_d7.w = 7;
    reg_a4 = reg_a6 + 0x20;
    do {
        if ((*(u16 *)((u8 *)(reg_a4) + (0))) == 0x8000) {
            reg_d0.w = 0xC;
            func_0013A780();
            var_a0 = 2;
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (2)));
            var_a1 = (*(u16 *)((u8 *)(reg_a4) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = var_a1;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        }
        (*(s8 *)((u8 *)(reg_a4) + (8))) = 1;
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    func_0018D5C0();
    reg_a4 = (u8 *)D_00262680;
loop_5:
    temp_a1 = (*(u16 *)((u8 *)(reg_a4) + (0)));
    reg_d1.h[0] = temp_a1;
    reg_a4 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_a4 += 2;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_a4 += 2;
        (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_a4 += 2;
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
        goto loop_5;
    }
}


void func_001BC8B0(void) {
    reg_d5.w = 0;
    reg_d7.w = 7;
    reg_d6.w = 0;
    reg_a0 = reg_a6 + 0x20;
    do {
        *(u8 *)(reg_a0 + 0x1A) = reg_d6.b[0];
        *(u8 *)(reg_a0 + 0x28) = reg_d5.b[0];
        reg_d6.b[0] += 0x20;
        reg_d5.b[0] += 8;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    func_001BC930();
}

s32 func_002011D0();
s32 func_00201270();

void func_001BC930(void) {
    func_00201270();
    reg_tmp.h[0] = (u16) (s8) reg_d0.b[0];
    reg_d0.h[0] = reg_tmp.h[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.h[0] += 0x14;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = 0;
    func_00201270();
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a5) + (0x1C))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a5) + (0x18))) = 0;
    func_002011D0();
    if (reg_d0.h[0] != 0) {
        (*(s8 *)((u8 *)(reg_a5) + (0x18))) = 1;
    }
    func_00201270();
    reg_d0.b[0] *= 4;
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
}

s32 func_00201E20();
extern u16 D_0028E470;
extern u32 D_0028E47C_as_u32;
extern u32 D_0028E480_as_u32;

#define W(o) (*(u16 *)(reg_a4 + (o)))
#define SW(o) (*(s16 *)(reg_a4 + (o)))
#define SW6(o) (*(s16 *)(reg_a6 + (o)))

void func_001BCA10(void) {
    if (reg_a5[0x1F] != 0) goto block_main;
    reg_d0.b[0] = reg_a5[0x1B];
    if (reg_d0.b[0] == 0) goto next_1;
    if (reg_a5[0x1A] == reg_d0.b[0]) goto next_1;
#ifdef DEATH_LABEL
    reg_a5[0x1D] -= 1;
    if ((s8) reg_a5[0x1D] >= 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_a5[0x1A] += 1;
    goto block_main;
next_1:
    if (reg_a5[0x19] != 0) goto next_3;
    reg_a5[0x1D] -= 1;
    if ((s8) reg_a5[0x1D] >= 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_a5[0x1A] -= 1;
    if ((s8) reg_a5[0x1A] > 0) goto block_main;
    if ((s8) reg_a5[0x20] >= 0) goto next_2;
#else
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if (reg_tmp.sb[0] > 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_a5[0x1A] += 1;
    goto block_main;
next_1:
    if (reg_a5[0x19] != 0) goto next_3;
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if (reg_tmp.sb[0] > 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_tmp.b[0] = reg_a5[0x1A];
    reg_a5[0x1A] -= 1;
    if (reg_tmp.sb[0] >= 2) goto block_main;
    if ((s8) reg_a5[0x20] <= 0) goto next_2;
#endif
    reg_a5[0x1F] = 1;
    func_002011D0();
    reg_d0.b[0] += 1;
    reg_d6.b[0] = reg_d0.b[0];
    reg_a4 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_a4[9] = 1;
        reg_a4[0x29] = reg_d6.b[0];
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
next_2:
    func_001BC930();
    goto block_main;
next_3:
    reg_a5[0x19] -= 1;
    if (reg_a5[0x19] != 0) goto block_main;
    reg_a5[0x1B] = 0;
    *(u16 *)(reg_a5 + 0x1C) = 0x404;
block_main:
    reg_d5.w = 0;
    reg_d5.b[0] = reg_a5[0x1A];
    if (reg_a5[0x18] == 0) goto next_4;
    reg_d5.h[0] *= 0xFFFF;
next_4:
    reg_a4 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_d0.h[0] = 0x70;
        reg_d1.w = 0;
        reg_d1.b[0] = reg_a4[0x1A];
        func_00201E20();
        reg_d6.h[1] = *(u16 *)(reg_a6 + 2);
        reg_d6.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d6.w += 0x02000000;
        W(2) = reg_d6.h[1];
        W(4) = reg_d6.h[0];
        reg_d1.h[0] = reg_d2.h[0];
        reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
        reg_d3.h[0] = reg_d3.sh[0] * 4;
        reg_d2.h[0] = reg_d2.sh[0] + reg_d1.sh[0];
        SW(2) += reg_d2.sh[0];
        SW(4) += reg_d3.sh[0];
        reg_d6.w = 0;
        reg_d6.b[0] = reg_a4[0x1B];
        D_0028E470 = (u16) reg_d6.sb[0];
        reg_d6.h[0] = D_0028E470;
        reg_d6.h[0] = reg_d6.sh[0] + reg_d5.sh[0];
        if ((s16) reg_d6.h[0] >= 0) {
            reg_d4.w = 1;
        } else {
            reg_d4.w = -1;
            reg_d6.h[0] *= 0xFFFF;
        }
loop_6:
        reg_d0.h[0] = 0x70;
        reg_d1.h[0] = reg_d4.h[0];
        reg_d1.b[0] += reg_a4[0x1A];
        reg_d1.h[0] = reg_d1.b[0];
        func_00201E20();
        reg_d1.h[0] = reg_d2.h[0];
        reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
        reg_d3.h[0] = reg_d3.sh[0] * 4;
        reg_d2.h[0] = reg_d2.sh[0] + reg_d1.sh[0];
        reg_d2.h[0] = reg_d2.sh[0] + SW6(2);
        reg_d2.h[0] = reg_d2.sh[0] + 0x200;
        reg_d3.h[0] = reg_d3.sh[0] + SW6(4);
        reg_d2.h[0] = reg_d2.sh[0] - SW(2);
        reg_d3.h[0] = reg_d3.sh[0] - SW(4);
        reg_d2.h[0] = reg_d2.sh[0] >> 4;
        reg_d3.h[0] = reg_d3.sh[0] >> 4;
        D_0028E480_as_u32 = (s16) reg_d2.h[0];
        reg_d2.w = D_0028E480_as_u32;
        D_0028E47C_as_u32 = (s16) reg_d3.h[0];
        reg_d3.w = D_0028E47C_as_u32;
#ifdef DEATH_LABEL
        reg_d2.h[0] = reg_d2.sh[0] * reg_d6.sh[0];
        reg_d3.h[0] = reg_d3.sh[0] * reg_d6.sh[0];
#else
        reg_d2.h[0] = reg_d2.h[0] * reg_d6.h[0];
        reg_d3.h[0] = (s16) reg_d3.h[0] * reg_d6.h[0];
#endif
        SW(2) += reg_d2.sh[0];
        SW(4) += reg_d3.sh[0];
        if (reg_d6.sh[0] < 0x10) goto next_7;
#ifdef DEATH_LABEL
        reg_a4[0x1A] += reg_d4.b[0];
#else
        reg_a4[0x1A] = (s8) reg_a4[0x1A] + reg_d4.sb[0];
#endif
        reg_d6.h[0] -= 0x10;
        if (reg_d6.h[0] != 0) goto loop_6;
next_7:
        if (reg_d4.sh[0] >= 0) goto next_8;
        reg_d6.h[0] *= 0xFFFF;
next_8:
        reg_a4[0x1B] = reg_d6.b[0];
        reg_tmp.b[0] = reg_a4[0x2F];
        reg_a4[0x2F] -= 1;
        if ((s32) reg_tmp.b[0] > 0) goto next_9;
        reg_a4[0x2F] = reg_a4[0x2E];
        W(0x30) += 4;
        W(0x30) &= 0x7F;
next_9:
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


void func_001BCF20(void) {
    void func_001713F0(s32);
    func_001713F0(0x10);
}

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_002601B0[];
extern u8 D_002601F0[];
extern u8 D_00260230[];
extern u8 D_00262700[];
extern u8 D_00262720[];
extern s16 D_0028E890_as_s16;
extern s16 D_0028E894_as_s16;
extern s8 enemy_move_end_requested;

void func_001BCF30() {
    reg_a0 = D_00262720;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00262700;
    reg_d0.h[0] = 9;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 0xA40;
        func_001BC8B0();
        func_001BCA10();
        D_0028E890_as_s16 = 0;
        D_0028E894_as_s16 = 1;
        reg_d0.h[0] = 0x10;
        reg_a0 = D_002601B0;
        func_001A3020();
        reg_d0.h[0] = 0x11;
        reg_a0 = D_002601F0;
        func_001A3020();
        reg_d0.h[0] = 0xF;
        reg_a0 = D_00260230;
        func_001A3020();
    }
}

s32 func_001293C0();
s32 func_001368E0();
s32 func_001389D0();
s32 func_0013B2E0();
s32 func_0014D220();
s32 func_0014E030();
s32 func_0014E290();
s32 func_0018D4E0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201800();
s32 func_00201B80();
s32 func_002026F0();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00259970_as_u8_a[];
extern u8 D_00262B50[];
extern u8 D_0028E310;
extern s8 D_0028E408;
extern u16 D_0028E890;
extern u16 D_0028E894;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;

void func_001BD010(void) {
    u16 temp_v1;
    u8 temp_a0;
    u32 temp_a0_2;
    u8 temp_a1;
    u8 temp_v0_2;
    u8 temp_v0_5;
    u8 *var_a0;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) {
        func_00201B80();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
        func_00201800();
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) -= 1;
        temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
        if (temp_a0 != 0) {
            if (temp_a0 >= 0x48) goto block_tail;
            if (temp_a0 == 48) {
            D_0028E894 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
                return;
            }
        } else {
            func_0014E290();
        }
        return;
    } else {
        if (D_0028E8A8 == 0xD8) {
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) = 1U;
        }
        if (D_0028E8A8 == 0xF8) {
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) = 0xFFU;
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x3500U;
            }
            if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x26)));
                if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x20))) < 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFFU;
                }
                goto block_18;
            }
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
                D_0028E890 = 1;
                reg_d0.w = 0x1C;
                func_0014E030();
                (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d1.h[0];
                reg_d0.w = 0x353;
                func_001A91A0();
                func_001BC6F0();
                vibration_start_pad1(0xB4, 0x50);
                vibration_start_pad2(0xB4, 0x50);
                D_0028E310 = MAIN_OR_DEATH_LABEL(0x54, 0x5A);
                reg_a0 = D_00262B50;
                func_0013B2E0();
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                func_00201800();
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8080;
                goto block_18;
            }
        } else {
block_18:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        reg_d7.w = 7;
        reg_a4 = reg_a6 + 0x20;
        do {
            var_a0 = (u8 *)(reg_a4);
            reg_d0.h[0] = (*(u16 *)((u8 *)(var_a0) + (0)));
            if (reg_d0.h[0] != 0x8000) {
                if ((*(u8 *)((u8 *)(var_a0) + (8))) == 0) {
                    reg_d1.w = 0x5C;
                    reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
                    if (reg_d1.b[0] != 0) {
                        reg_d0.b[0] = 0xA3;
                        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
                        func_001A9000();
                        var_a0 = (u8 *)(reg_a4);
                        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
                        reg_d2.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1E)));
                        reg_d0.b[0] ^= reg_d2.b[0];
                        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
                        if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                            (*(s16 *)((u8 *)(reg_a4) + (0x18))) = 0x400;
                        }
                        if ((*(s16 *)((u8 *)(reg_a4) + (0x18))) < 0) {
                            reg_d0.w = 0x26;
                            func_001A91A0();
block_27:
                            func_0018D4E0();
                            reg_d0.h[0] = 0x85;
                            func_0013A780();
                            var_a0 = (u8 *)((void *)1);
                            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (2)));
                            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (4)));
                            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
                            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
                            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                            (*(u16 *)((u8 *)(reg_a4) + (0))) = 0x8000U;
                        }
                    } else {
                        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(var_a0) + (0x1F)));
                    }
                } else {
                    goto block_27;
                }
            }
            reg_a4 += 0x40;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) {
            if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
            }
            goto block_35;
        }
        if ((*(s16 *)((u8 *)(reg_a6) + (2))) < -0x23FF) {
            D_0028E894 = 0;
            func_0014E290();
            return;
        }
block_35:
        func_001368E0();
        if (D_0028E8A0 == 0) {
            func_00201B80();
            func_001BCA10();
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                (*(u16 *)((u8 *)(reg_a5) + (0x24))) += 4;
                if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x24))) >= 0x14) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 0U;
                }
            }
            temp_v0_2 = (*(u8 *)((u8 *)(reg_a6) + (0xD)));
            if (temp_v0_2 == 0) {
                if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x20))) > 0) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (7)));
                    (*(u8 *)((u8 *)(reg_a6) + (7))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (6)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 1U;
                        (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 2;
#ifndef DEATH_LABEL
                        (*(u8 *)((u8 *)(reg_a6) + (0xB))) = 0U;
                        (*(u8 *)((u8 *)(reg_a6) + (0xA))) = 2;
#endif
                    }
                }
            } else if ((temp_v0_2 & 0xFF) == 1) {
                if (((*(u16 *)((u8 *)(reg_a6) + (8))) != 0) || ((*(u8 *)((u8 *)(reg_a5) + (0x1F))) == 0)) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xB)));
                    (*(u8 *)((u8 *)(reg_a6) + (0xB))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0xB))) = (*(u8 *)((u8 *)(reg_a6) + (0xA)));
                        (*(u16 *)((u8 *)(reg_a6) + (8))) += 4;
                        if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0x7C) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 2U;
                            (*(u8 *)((u8 *)(reg_a6) + (0xC))) = 2U;
                            (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 2;
                        }
                        goto block_50;
                    }
                }
            } else {
block_50:
                if ((*(u8 *)((u8 *)(reg_a6) + (0xD))) == 2) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xF)));
                    (*(u8 *)((u8 *)(reg_a6) + (0xF))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0xF))) = (*(u8 *)((u8 *)(reg_a6) + (0xE)));
                        temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        if ((s32) temp_v1 >= 0x1000) {
                            reg_d0.h[0] = temp_v1;
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x2700;
                            func_002026F0();
                            if (D_0028E408 == 0) {
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d4.w = 0;
                                reg_d6.h[0] = reg_d1.h[0];
                                if ((*(u8 *)((u8 *)(reg_a6) + (0xC))) & 1) {
                                    reg_d0.w = 0x30003;
                                    reg_d1.h[0] -= 0xC;
                                    reg_d3.w = 0x27000000;
                                    reg_d7.w = 6;
                                    do {
                                        func_00129410();
                                        reg_d1.h[0] += 4;
                                    } while ((s16)(--reg_d7.h[0]) >= 0);
                                }
                                reg_d1.h[0] = reg_d6.h[0];
                                reg_a0 = D_00259970_as_u8_a;
                                reg_d1.h[0] -= 0x56;
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                                func_001BC5D0();
                                func_001BC4B0();
                            }
                        }
                        (*(u8 *)((u8 *)(reg_a6) + (0xC))) -= 1;
                        if ((*(u8 *)((u8 *)(reg_a6) + (0xC))) == 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 3U;
                            (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 0x1001;
#ifndef DEATH_LABEL
                            (*(u8 *)((u8 *)(reg_a6) + (0xB))) = 0x10U;
                            (*(u8 *)((u8 *)(reg_a6) + (0xA))) = 1;
#endif
                            goto block_60;
                        }
                    }
                } else {
block_60:
                    if ((*(u8 *)((u8 *)(reg_a6) + (0xD))) == 3) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xB)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xB))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xB))) = (*(u8 *)((u8 *)(reg_a6) + (0xA)));
                            (*(u16 *)((u8 *)(reg_a6) + (8))) -= 4;
                            if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0) {
                                (*(u8 *)((u8 *)(reg_a6) + (0xD))) = 0U;
                            }
                        }
                    }
                }
            }
            if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x20))) > 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) += 1;
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) &= 7;
                reg_d7.w = 7;
                reg_a4 = reg_a6 + 0x20;
                do {
                    if ((*(u16 *)((u8 *)(reg_a4) + (0))) != 0x8000) {
                        temp_v0_5 = (*(u8 *)((u8 *)(reg_a4) + (9)));
                        if (temp_v0_5 == 0) {
                            if ((*(u8 *)((u8 *)(reg_a4) + (0x2B))) == 0) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
                                (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                                    (*(u8 *)((u8 *)(reg_a4) + (0x2B))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x2A)));
                                    goto block_71;
                                }
                            } else {
block_71:
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x2D)));
                                (*(u8 *)((u8 *)(reg_a4) + (0x2D))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x2C)));
                                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                                    reg_d1.h[0] = reg_d7.h[0];
                                    reg_d1.h[0] &= 3;
                                    reg_d0.h[0] &= 3;
                                    if (reg_d0.h[0] == reg_d1.h[0]) {
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
#ifdef DEATH_LABEL
                                        if (((reg_d1.sb[0] < -0x20) || (0 < reg_d1.sb[0])) && ((reg_d1.sb[0] > 0x20) || (0 > reg_d1.sb[0]))) {
#else
                                        if (((s32) reg_d1.b[0] < 0xE1) && ((s32) reg_d1.b[0] > 0x20)) {
#endif
                                            reg_d3.w = 0x02000000;
                                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                            reg_d0.w = 0xFFFE0007;
                                            func_001293C0();
                                            (*(u8 *)((u8 *)(reg_a4) + (0x2B))) -= 1;
                                        }
                                    }
                                }
                            }
                        } else if ((temp_v0_5 & 0xFF) == 1) {
                            if ((*(u16 *)((u8 *)(reg_a6) + (8))) == 0) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
                                (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                                    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 4;
                                    if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0x1C) {
                                        (*(u8 *)((u8 *)(reg_a4) + (9))) = 2U;
                                        (*(s16 *)((u8 *)(reg_a4) + (0x26))) = 1;
                                        (*(u8 *)((u8 *)(reg_a4) + (0x29))) = 8U;
                                        goto block_81;
                                    }
                                }
                            }
                        } else {
block_81:
                            if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 2) {
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x27)));
                                (*(u8 *)((u8 *)(reg_a4) + (0x27))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a4) + (0x27))) = (*(u8 *)((u8 *)(reg_a4) + (0x26)));
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
#ifdef DEATH_LABEL
                                    if (((reg_tmp.sb[0] < -0x18) || (0 < reg_tmp.sb[0])) && ((reg_tmp.sb[0] > 0x18) || (0 > reg_tmp.sb[0]))) {
#else
                                    if (((s32) reg_tmp.b[0] < 0xE9) && ((s32) reg_tmp.b[0] > 0x18)) {
#endif
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x29)));
                                        reg_d1.b[0] *= 4;
                                        temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
                                        temp_a1 = reg_d1.b[0];
                                        reg_d1.b[0] = temp_a1 + temp_a0_2;
                                        reg_d3.w = 0x02000000;
                                        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                        reg_d0.w = 0x20007;
                                        func_001293C0();
                                        (*(u8 *)((u8 *)(reg_a4) + (0x28))) += 2;
                                    }
                                    (*(u8 *)((u8 *)(reg_a4) + (0x29))) -= 1;
                                    if ((*(u8 *)((u8 *)(reg_a4) + (0x29))) == 0) {
                                        (*(u8 *)((u8 *)(reg_a4) + (9))) = 3U;
                                        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0x20U;
                                        goto block_88;
                                    }
                                }
                            } else {
block_88:
                                if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 3) {
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
                                    (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                                        (*(u16 *)((u8 *)(reg_a4) + (0xA))) -= 4;
                                        if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0) {
                                            (*(u8 *)((u8 *)(reg_a4) + (9))) = 0U;
                                            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0x10U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    reg_a4 += 0x40;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d6.w = 0;
                reg_d7.w = 7;
                reg_a4 = reg_a6 + 0x20;
                do {
                    if (((*(u16 *)((u8 *)(reg_a4) + (0))) != 0x8000) && ((*(u8 *)((u8 *)(reg_a4) + (9))) != 0)) {
                        reg_d6.w = 1;
                    }
                    reg_a4 += 0x40;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                if (reg_d6.h[0] == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = 0U;
                }
            }
        }
block_tail:
        func_001BDFC0();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
            func_001BDD40();
            func_001BDEE0();
        }
        reg_a0 = reg_a6;
        func_0014D220();
        reg_a0 = reg_a6 + 0x20;
        func_0014D220();
        reg_a0 = reg_a6 + 0x40;
        func_0014D220();
        reg_a0 = reg_a6 + 0x60;
        func_0014D220();
        reg_a0 = reg_a6 + 0x80;
        func_0014D220();
        reg_a0 = reg_a6 + 0xA0;
        func_0014D220();
        reg_a0 = reg_a6 + 0xC0;
        func_0014D220();
        reg_a0 = reg_a6 + 0xE0;
        func_0014D220();
        reg_a0 = reg_a6 + 0x100;
        func_0014D220();
        reg_a0 = reg_a6 + 0x120;
        func_0014D220();
        reg_a0 = reg_a6 + 0x140;
        func_0014D220();
        reg_a0 = reg_a6 + 0x160;
        func_0014D220();
        reg_a0 = reg_a6 + 0x180;
        func_0014D220();
        reg_a0 = reg_a6 + 0x1A0;
        func_0014D220();
        reg_a0 = reg_a6 + 0x1C0;
        func_0014D220();
        reg_a0 = reg_a6 + 0x1E0;
        func_0014D220();
    }
}

s32 func_0019C730();
extern u8 D_00262910[];
extern u8 D_00262930[];
extern u8 *reg_a1;

void func_001BDD40(void) {
    u16 temp_a0;
    u16 temp_a1;
    reg_a0 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        if (reg_d0.h[0] != 0x8000) {
            reg_a1 = (u8 *)D_00262930;
            reg_a1 += (*(u16 *)((u8 *)(reg_a0) + (0x30)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d1.h[0] = temp_a0;
            reg_d1.w += 0xFA00FC00;
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x1C)));
            func_0019C730();
            reg_a1 = (u8 *)D_00262910;
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d2.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d1.h[0] = temp_a1;
            reg_d1.w += 0xFC00FC00;
            reg_d3.h[0] = 0x420;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x1C)));
            func_0019C730();
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_0019C530(void);
extern u16 D_002629B0[];

void func_001BDEE0(void) {
    reg_a0 = (u8 *)D_002629B0;
    reg_d2.h[0] = *(u16 *)(reg_a6 + 8);
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[1] += 0x1600;
    reg_d1.h[0] += 0x7FFF + 0x7401;
    reg_d1.h[1] += 0x7FFF + 0x6601;
    reg_d3.h[0] = 0x1A60;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    func_0019C530();
}

extern u32 D_00262A30[];
extern void func_0019C530(void);

void func_001BDFC0(void) {
    reg_a0 = (u8 *)D_00262A30;
    reg_a0 += *(u16 *)(reg_a5 + 0x24);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xDC00E600U;
    reg_d3.h[0] = 0x24D0;
    reg_d4.h[0] = 0x11;
    func_0019C530();
}

void func_001BE030(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
extern s32 D_00262C20[];
extern s32 D_0028D990;
extern s32 *reg_a0_as_s32_p;

void func_001BE040(void) {
    reg_a0_as_s32_p = D_00262C20;
    func_0014E370();
    reg_d0.w = 0;
    reg_a0_as_s32_p = &D_0028D990;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
}

extern u32 D_00251720[];
extern u16 D_0028E3C0;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u32 D_002B6D50_as_u32_a[];
extern u32 D_002B6DF4[];
extern u32 D_002B6E0C[];
extern u8 *D_0028E484_as_u8_p;

void func_001BE0A0(void) {
    s32 flag;
    u32 *dst;
    u32 *src;
    u32 cnt;
    u32 cnt2;

    if (D_0028E8A8 == 0x105) {
        func_0014E290();
        return;
    }
    src = D_00251720;
    reg_a0 = (u8 *)(D_002B6E0C);
    reg_tmp.w = 0xBC;
    flag = D_0028ED80 == 1;
    if (flag == 0) {
        flag = D_0028ED7C == 2;
    }
    if ((flag != 0) || (D_0028E3C0 != 0)) {
        reg_a0 = (u8 *)(D_002B6DF4);
        reg_tmp.w = 0xA4;
    }
    reg_d6.w = 0x16;
loop_1:
    dst = (u32 *)(reg_a0);
    reg_d7.w = 8;
loop_2:
    reg_d4.w = *src;
    src += 1;
    reg_d4.h[1] += 0x800;
    *dst = reg_d4.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    dst += 64;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) {
        goto loop_2;
    }
    D_0028E484_as_u8_p = (u8 *)D_002B6D50_as_u32_a;
    reg_tmp.w += 4;
    reg_tmp.w = (u32) reg_tmp.b[0];
    D_0028E484_as_u8_p += reg_tmp.w;
    reg_a0 = (u8 *)(D_0028E484_as_u8_p);
    cnt2 = reg_d6.h[0] - 1;
    reg_d6.h[0] = cnt2;
    if (((s64) ((s64) (u16) cnt2 << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

#include "common.h"
#include "entity.h"

void func_0019E980(void);

extern u16 D_0028E154;
extern u8 D_002A45B0[];

void func_0019D740(void) {
    u8 *base;
    s32 step;

    base = D_002A45B0;
    reg_a0 = base;
    step = D_0028E154;
    reg_a0 += step;
    D_0028E154 = step + 0xC;
}


void func_0019D770(void) {
    s32 func_0019B6E0();
    func_0019D740();
    func_0019B6E0();
}

s32 func_0019BB40();                            /* extern */
extern s32 reg_a0_as_s32;

void func_0019D7A0(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019D740();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}

extern u16 D_0028E150;
extern u8 D_002A4430[];

void func_0019D7E0(void) {
    u32 counter;

    reg_a0 = D_002A4430;
    counter = D_0028E150;
    reg_a0 += counter;
    D_0028E150 = counter + 0xC;
}


void func_0019D810(void) {
    func_0019D7E0();
    func_0019BB40();
}

void func_0019D840(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019D7E0();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}

extern u16 D_0028E148;
extern u8 D_002A3CB0[];

void func_0019D880(void) {
    u32 temp;

    reg_a0 = D_002A3CB0;
    temp = D_0028E148;
    reg_a0 += temp;
    D_0028E148 = temp + 0xC;
}


void func_0019D8B0(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019D880();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}

extern u16 D_0028E128;
extern u8 D_002A3C80[];
void func_0019D8F0(void) {
    u8 *base;
    s32 step;

    base = D_002A3C80;
    reg_a0 = base;
    step = D_0028E128;
    reg_a0 += step;
    D_0028E128 = step + 0xC;
}


void func_0019D920(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019D8F0();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}

extern u16 D_0028E144;
extern u8 D_002A3F70[];
void func_0019D960(void) {
    s32 step; reg_a0 = D_002A3F70; step = D_0028E144; reg_a0 += step; D_0028E144 = step + 0xC;
}


void func_0019D990(void) {
    s32 func_0019B6E0();
    func_0019D960();
    func_0019B6E0();
}

extern s32 reg_a1_as_s32;


void func_0019D9C0(void)
{
    extern void func_0019B6E0(void);
    s32 saved_a0;
    s32 saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = reg_a0_as_s32;
    saved_a1 = reg_a1_as_s32;
    func_0019D960();
    func_0019B6E0();
    reg_d0.w = saved_d0;
    reg_a0_as_s32 = saved_a0;
    reg_a1_as_s32 = saved_a1;
}

void func_0019DA10(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019D960();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}

extern u16 D_0028E140;
extern u8 D_002A3EF0[];

void func_0019DA50(void) {
    u32 offset;
    u8 *cursor;

    reg_a0 = D_002A3EF0;
    offset = D_0028E140;
    cursor = reg_a0;
    reg_a0 = cursor + offset;
    D_0028E140 = offset + 0xC;
}


void func_0019DA80(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019DA50();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}

extern u16 D_0028E134;
extern u8 D_002A3DD0[];

void func_0019DAC0(void) {
    u32 offset;

    reg_a0 = D_002A3DD0;
    offset = D_0028E134;
    reg_a0 += offset;
    D_0028E134 = offset + 0xC;
}


void func_0019DAF0(void) {
    func_0019DAC0();
    func_0019BB40();
}

extern u16 D_0028E130;
extern u8 D_002A3DB0[];

void func_0019DB20(void) {
    u8 *base;
    s32 step;

    base = D_002A3DB0;
    reg_a0 = base;
    step = D_0028E130;
    reg_a0 += step;
    D_0028E130 = step + 0xC;
}


void func_0019DB50(void) {
    func_0019DB20();
    func_0019BB40();
}

extern u16 D_0028E12C;
extern u8 D_002A3D30[];

void func_0019DB80(void) {
    u32 temp;

    reg_a0 = D_002A3D30;
    temp = D_0028E12C;
    reg_a0 += temp;
    D_0028E12C = temp + 0xC;
}


void func_0019DBB0(void) {
    func_0019DB80();
    func_0019BB40();
}

void func_0019DBE0(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32;
    temp_s1 = reg_d0.w;
    func_0019DB80();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0_as_s32 = temp_s0;
}


void func_0019DC20(void) {
    *(u16 *)(reg_a6 + 0x52) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x52) < 0) {
        *(u16 *)(reg_a6 + 0x52) = 8U;
    }
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x52);
}

void func_0019DC60(void) {
    *(u16 *)(reg_a6 + 0x52) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x52) < 0) {
        *(u16 *)(reg_a6 + 0x52) = 8U;
    }
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x52);
}

void func_0019DCA0(void) {
    *(u16 *)(reg_a6 + 0x52) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x52) < 0) {
        *(u16 *)(reg_a6 + 0x52) = 8U;
    }
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x52);
}

void func_0019DCE0(void) {
    *(u16 *)(reg_a6 + 0x54) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x54) < 0) {
        *(u16 *)(reg_a6 + 0x54) = 8U;
    }
    reg_d7.h[0] = *(u16 *)(reg_a6 + 0x54);
}


void func_0019DD20(void) {
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += *(u16 *) reg_a1;
    reg_a1 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[0] += *(u16 *) reg_a1;
    reg_a1 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a5 = (u8 *) reg_tmp.w;
    reg_d0.w = 0;
    *(u16 *) reg_a0 = (reg_d6.h[0]) ? *(u16 *) (reg_a5 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a5;
    reg_a0 += 2;
    *(u16 *) reg_a0 = ((u16) reg_d6.h[0] + 2) ? *(u16 *) (reg_a5 + ((s16) ((u16) reg_d6.h[0] + 2) & ~1)) : *(u16 *) reg_a5;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *) (reg_a0 - 2) = *(u8 *) (reg_a4 + 0x57);
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) (reg_a4 + 0x5A);
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) (reg_a4 + 0x20);
    reg_a0 += 2;
}

s32 func_0019C000();
extern u8 D_0025ECF0[];
extern u8 D_0025ED80[];
extern u8 D_0028D960;
extern u16 D_0028E07C[];
extern u16 D_0028E07E[];
extern u16 D_0028E084[];
extern u16 D_0028E086[];
extern u16 D_0028E928;
extern u8 D_0029E390[];
extern u8 D_0029EA50[];

void func_0019E130(void) {
    u8 *save_a3;
    u8 *save_a5;
    u8 *save_a6;
    u8 *push_a6;
    u32 save_d6;
    u32 save_d7;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = D_0028E084[0];
    reg_tmp.h[0] = D_0028E086[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = D_0028E07C[0];
    reg_tmp.h[0] = D_0028E07E[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x150;
    if (*(u16 *)(reg_a4 + 0x58) == 0) goto next_1;
    reg_d0.h[0] = 0x150;
next_1:
    reg_a3 = reg_a0;
    reg_a3 += reg_d0.h[0];
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!(*(u8 *)reg_a4 & 1)) goto next_2;
    reg_d0.h[0] += 4;
    reg_a1 = &D_0028D960;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
next_2:
    if (D_0028E928 != 0) goto next_3;
    if ((s32)reg_d4.h[0] <= 4) goto next_3;
    reg_d4.w = 4;
next_3:
    reg_d5.h[0] = reg_d4.h[0];
    reg_a1 = (u8 *)D_0025ECF0;
    reg_a2 = (u8 *)D_0025ED80;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x20);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    func_0019DC20();
    func_0019DCE0();
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto next_4;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
next_4:
    push_a6 = reg_a6;
    func_0019DD20();
    reg_a6 = reg_a0 - 0x2C;
    func_0019C000();
    reg_a6 = push_a6;
next_5:
    reg_a0 = reg_a3;
    reg_a6 += 0x20;
loop_1:
    if (*(s16 *)reg_a0 >= 0) goto next_6;
    reg_a0 += 0x30;
    if ((s16)(reg_d5.h[0] -= 1) >= 0) goto loop_1;
    goto next_7;
next_6:
    reg_a1 = reg_a2;
    func_0019DD20();
    reg_a6 = reg_a0 - 0x2C;
    func_0019C000();
next_7:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u8 D_0025EE10[];

void func_0019E5B0(void) {
    u8 *save_a3;
    u8 *save_a5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = D_0028E084[0];
    reg_tmp.h[0] = D_0028E086[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = D_0028E07C[0];
    reg_tmp.h[0] = D_0028E07E[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x450;
    if (*(u16 *)(reg_a4 + 0x58) == 0) goto next_1;
    reg_d0.h[0] = 0x450;
next_1:
    reg_a3 = reg_a0;
    reg_a3 += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
    reg_d0.b[0] += 0x10;
    reg_d0.b[0] &= 0x3F;
    if ((s32)reg_d0.b[0] >= 0x20) goto next_2;
    reg_atmp = reg_a0;
    reg_a0 = reg_a3;
    reg_a3 = (u8 *)reg_atmp;
next_2:
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d4.h[0] += 2;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!(*(u8 *)reg_a4 & 1)) goto next_3;
    reg_a1 = &D_0028D960;
    reg_d0.h[0] += 4;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d4.h[0] += 2;
next_3:
    if (D_0028E928 != 0) goto next_4;
    if ((s32)reg_d4.h[0] <= 4) goto next_4;
    reg_d4.w = 4;
next_4:
    reg_d5.h[0] = reg_d4.h[0];
    reg_a1 = (u8 *)D_0025EE10;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x20);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto loop_1;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
loop_1:
    if (*(s16 *)reg_a3 >= 0) goto next_6;
    reg_a3 += 0x30;
    if ((s16)(reg_d5.h[0] -= 1) >= 0) goto loop_1;
    goto next_5;
next_6:
    func_0019DC60();
    func_0019DCE0();
    func_0019E980();
    reg_a0 = reg_a3;
    func_0019DC60();
    func_0019DCE0();
    reg_a6 += 0x20;
    func_0019E980();
next_5:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

void func_0019E980(void) {
    u8 *save_a1;
    u8 *save_a6;

    save_a1 = reg_a1;
    save_a6 = reg_a6;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.w = 0;
    reg_d0.w = 0;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
    reg_d0.h[0] &= 0x3E;
    if ((reg_d0.h[0] != 0) && ((s32)reg_d0.b[0] > 0x20)) {
        reg_d0.b[0] *= -1;
        reg_d3.h[0] = 0xFFFF;
        reg_d0.h[0] &= 0x3E;
    }
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if ((s8)reg_d3.b[0] < 0) {
        reg_d1.h[0] *= 0xFFFF;
    }
    *(u16 *)reg_a0 = *(u16 *)(reg_a6 + 4);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.w = 0;
    reg_a5 = (u8 *)reg_tmp.w;
    *(u16 *)reg_a0 = (reg_d6.h[0] != 0) ? *(u16 *)(reg_a5 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a5;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)(reg_a5 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a5;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *)(reg_a0 - 2) = *(u8 *)(reg_a4 + 0x57);
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 0x5A);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 0x20);
    reg_a0 += 2;
    if ((s8)reg_d3.b[0] < 0) {
        *(u8 *)(reg_a0 - 0x12) *= -1;
        *(u8 *)(reg_a0 - 0xF) |= 0x40;
    }
    reg_a6 = reg_a0 - 0x2C;
    func_0019C000();
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_a1 = save_a1;
    reg_a6 = save_a6;
}

s32 func_0019F270();
extern u8 D_0025EEA0[];

void func_0019EF20(void) {
    u32 save_d6;
    u32 save_d7;
    u8 *save_a3;
    u8 *save_a5;
    u8 *save_a6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = D_0028E084[0];
    reg_tmp.h[0] = D_0028E086[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = D_0028E07C[0];
    reg_tmp.h[0] = D_0028E07E[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x150;
    if (*(u16 *)(reg_a4 + 0x58) == 0) goto next_1;
    reg_d0.h[0] = 0x150;
next_1:
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!(*(u8 *)reg_a4 & 1)) goto next_2;
    reg_d0.h[0] += 4;
    reg_a1 = &D_0028D960;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
next_2:
    if (D_0028E928 != 0) goto next_3;
    if ((s32)reg_d4.h[0] <= 4) goto next_3;
    reg_d4.w = 4;
next_3:
    reg_d4.h[0] *= 2;
    reg_d4.h[0] += 1;
    reg_a1 = (u8 *)D_0025EEA0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x20);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    func_0019DCA0();
    func_0019DCE0();
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto next_4;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
next_4:
    reg_a3 = reg_a0;
loop_1:
    reg_a0 += 0x30;
    if (*(s16 *)reg_a0 >= 0) goto next_6;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_1;
    goto next_5;
next_6:
    func_0019F270();
next_5:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

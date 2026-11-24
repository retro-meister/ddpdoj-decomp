#include "common.h"

void func_001C9950(void);
void func_001C9C50(void);
void func_001C9DB0(void);
void func_001C9EE0(void);
void func_001CA090(void);
void func_001CA1F0(void);
void func_001CA370(void);

extern u8 *reg_a6;

void func_001C9750(void) {
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) -= 0x1800;
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) += 0x300;
    (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x42))) -= 0x11C0;
    (*(u16 *)((u8 *)(reg_a6) + (0x44))) += 0x6C0;
    (*(u16 *)((u8 *)(reg_a6) + (0x62))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x64))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x62))) -= 0x11C0;
    (*(u16 *)((u8 *)(reg_a6) + (0x64))) -= 0x6C0;
    (*(u16 *)((u8 *)(reg_a6) + (0x82))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x84))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x82))) -= 0x40;
    (*(u16 *)((u8 *)(reg_a6) + (0x84))) += 0xCC0;
    (*(u16 *)((u8 *)(reg_a6) + (0xA2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xA4))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xA2))) -= 0x40;
    (*(u16 *)((u8 *)(reg_a6) + (0xA4))) -= 0xCC0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC4))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xC2))) += 0x540;
    (*(u16 *)((u8 *)(reg_a6) + (0xC4))) += 0x1480;
    (*(u16 *)((u8 *)(reg_a6) + (0xE2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xE4))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xE2))) += 0x540;
    (*(u16 *)((u8 *)(reg_a6) + (0xE4))) -= 0x1480;
    (*(u16 *)((u8 *)(reg_a6) + (0x102))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x104))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x102))) -= 0x300;
}

extern u8 *reg_a4;

void func_001C9920(void) {
    reg_a4[3] = 0;
    *(u16 *)(reg_a4 + 4) = 0x1C0;
    *(u16 *)(reg_a4 + 6) = 0;
    *(u16 *)(reg_a4 + 8) = 0;
    func_001C9950();
}

s32 func_00124B20();
s32 func_00124D70();
s32 func_0013B2E0();
s32 func_001A3020();
s32 func_001CBBF0();
s32 func_00201B80();
extern u8 D_0025FCB0[];
extern u8 D_0026C8C0[];
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u8 *reg_a0;

void func_001C9950(void) {
    func_00201B80();
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0x10) {
            reg_d0.h[0] = 0xD;
            reg_a0 = (u8 *)D_0025FCB0;
            func_001A3020();
        }
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) != 0) {
            func_001C9750();
            return;
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        D_0028E854 |= 1;
        func_001C9750();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (6))) != 0x100) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u16 *)((u8 *)(reg_a4) + (6))) += 3;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (6))) >= 0x100) {
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 0x100U;
            }
        }
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x6200) {
        func_001C9750();
        return;
    }
    D_0028E855 |= 0x10;
    D_0028E855 |= 2;
    reg_d0.w = 3;
    func_00124B20();
    func_001CBBF0();
    func_00124D70();
    reg_a0 = (u8 *)D_0026C8C0;
    func_0013B2E0();
    func_001C9750();
}


void func_001C9AF0(void) {
    *(u16 *)(reg_a6 + 2) -= 0x10;
    func_001C9750();
}

s32 func_00201160();
extern u16 *reg_a4_as_u16_p;

void func_001C9B10(void) {
    func_00201160();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *reg_a4_as_u16_p = reg_d0.h[0];
}

void func_001C9B60(void)
{
    reg_d0.b[0] = reg_a4[3];
    reg_d1.b[0] = reg_a6[0x1B];

    if (reg_d0.b[0] != reg_d1.b[0]) {
        if ((s8)reg_d0.b[0] >= (s8)reg_d1.b[0]) {
            reg_d1.b[0]++;
        } else {
            reg_d1.b[0]--;
        }
    }

    reg_a6[0x1B] = reg_d1.b[0];
}

extern u8 D_0026C860[];

void func_001C9BC0(void) {
    s32 func_002021F0(void *);
    *reg_a4_as_u16_p = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 4;
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0(reg_a6);
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_001C9C50();
}

s32 func_002011D0();
s32 func_00201C60();
s32 func_00202500();
s32 func_00202B50();

void func_001C9C50() {
    s32 func_002021F0();
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_00201C60();
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        *reg_a4_as_u16_p += 4;
        *reg_a4_as_u16_p &= 0x3F;
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 4U;
        func_002011D0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= reg_d0.b[0];
    }
    func_001C9750();
}


void func_001C9D70(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 2;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x404;
    reg_tmp.w = 0x5C001C00;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_tmp.h[0];
    func_001C9DB0();
}

s32 func_00124D90();
s32 func_001CBBE0();

void func_001C9DB0(void) {
    s32 func_002021F0();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] >>= 8;
    (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 5;
        func_00124D90();
        func_001CBBE0();
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        func_001C9B60();
    }
    func_00201C60();
    func_001C9750();
}


void func_001C9EA0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x101;
    reg_tmp.w = 0x5C001C00;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_tmp.h[0];
    func_001C9EE0();
}

void func_001C9EE0(void) {
    s32 func_002021F0();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] >>= 7;
    (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 5;
        func_00124D90();
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        func_001C9B60();
    }
    func_00201C60();
    func_001C9750();
}

s32 func_00125310();
s32 func_002012F0();

void func_001C9FC0(void) {
    u16 temp_a0;

    reg_d0.w = 2;
    func_00125310();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 2;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] = temp_a0;
    (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    func_001CA090();
}

void func_001CA090() {
    s32 func_002021F0();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
    (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
        func_001C9B60();
    }
    func_00201C60();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (4)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
        (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    }
    func_001C9750();
}


void func_001CA1D0(void) {
    reg_a4[3] = 0;
    reg_a4[2] = 0;
    *(s16 *)(reg_a4 + 4) = 0x404;
    func_001CA1F0();
}

void func_001CA1F0(void) {
    s32 func_002021F0();
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) == 0) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002021F0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        func_00202B50();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d1.h[0] >>= 7;
        if ((s16)(reg_d1.b[0]) < 3) {
            reg_d1.w = 2;
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d1.b[0];
        if ((s16) reg_d0.h[0] < 0x201) {
            (*(u8 *)((u8 *)(reg_a4) + (2))) = 1U;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x101;
        }
    }
    if (((*(u8 *)((u8 *)(reg_a4) + (2))) == 1) && ((*(s8 *)((u8 *)(reg_a6) + (0x1B))) < 3)) {
        (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 2;
        reg_d0.w = 5;
        func_00124D90();
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        func_001C9B60();
    }
    func_00201C60();
    func_001C9750();
}

extern s16 *reg_a4_as_s16_p;


void func_001CA350(void) {
    *reg_a4_as_s16_p = 0;
    reg_a6[0x1B] = 8;
    func_001CA370();
}

extern u8 D_0026C8A0[];

void func_001CA370(void) {
    s32 func_002021F0(void *);
    reg_a0 = D_0026C8A0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0(reg_a6);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_00201C60();
    reg_a0 = D_0026C8A0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x201) {
        func_001C9B10();
    }
    func_001C9750();
}

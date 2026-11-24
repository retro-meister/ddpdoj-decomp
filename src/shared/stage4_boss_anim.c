#include "common.h"

void func_001D7320(void);
void func_001D73A0(void);
void func_001D7420(void);
void func_001D74B0(void);
void func_001D7540(void);
void func_001D75D0(void);
void func_001D7660(void);
void func_001D76F0(void);
void func_001D7780(void);
void func_001D77F0(void);

extern s16 *reg_a4_as_s16_p;

void func_001D71C0(void) {
    *reg_a4_as_s16_p = 0;
}

s32 func_00124DC0();                            /* extern */
s32 func_00124F00();                            /* extern */

void func_001D71D0(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x106))) = 0;
    reg_d0.w = 0;
    func_00124F00();
    reg_d0.w = 6;
    func_00124DC0();
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x202;
}

s32 func_00124DC0();
s32 func_00124F00();
s32 func_001E8710();
s32 func_001E8730();

void func_001D7210() {
    u16 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x106))) += 4;
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x106)));
        if (temp_a0 == 0x3C) {
            (*(u16 *)((u8 *)(reg_a6) + (0x106))) = 0U;
            reg_d0.w = 6;
            func_00124F00();
            reg_d0.w = 9;
            func_00124DC0();
            reg_d0.w = 7;
            func_00124DC0();
            reg_d0.w = 8;
            func_00124DC0();
            (*(s16 *)((u8 *)(reg_a6) + (0x30))) = 0xC00;
            (*(s16 *)((u8 *)(reg_a6) + (0x32))) = 0xD80;
            (*(s16 *)((u8 *)(reg_a6) + (0x34))) = 0x900;
            (*(s16 *)((u8 *)(reg_a6) + (0x36))) = 0x900;
            reg_d0.h[0] = 0x80;
            func_001E8730();
            reg_d0.h[0] = 0xA0;
            func_001E8730();
            func_001E8710();
            func_001D71C0();
        }
    }
}


void func_001D7310(void) {
    reg_a4_as_s16_p[1] = 0x202;
    func_001D7320();
}

void func_001D7320() {
    u16 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x66))) += 4;
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
        if (temp_a0 == 0x1C) {
            func_001D71C0();
        }
    }
}

extern u16 *reg_a4_as_u16_p;

void func_001D7390(void) {
    reg_a4_as_u16_p[1] = 0x202;
    func_001D73A0();
}

void func_001D73A0() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x66))) -= 4;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x66))) == 0) {
            func_001D71C0();
        }
    }
}


void func_001D7410(void) {
    reg_a4_as_u16_p[1] = 1;
    func_001D7420();
}

void func_001D7420() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x106))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x106))) >= 0x3C) {
            (*(u16 *)((u8 *)(reg_a6) + (0x106))) = 0x3CU;
            func_001D71C0();
        }
    }
}


void func_001D74A0(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D74B0();
}


void func_001D74B0(void)
{
    s32 remainingIsPositive;

    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;

    if ((s32)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        *(u16 *)(reg_a6 + 0x106) -= 4;

        remainingIsPositive = 0 < *(s16 *)(reg_a6 + 0x106);
        if (remainingIsPositive == 0) {
            *(u16 *)(reg_a6 + 0x106) = 0;
            func_001D71C0();
        }
    }
}


void func_001D7530(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D7540();
}

void func_001D7540() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x88))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x88))) >= 0x20) {
            (*(u16 *)((u8 *)(reg_a6) + (0x88))) = 0x20U;
            func_001D71C0();
        }
    }
}


void func_001D75C0(void) {
    reg_a4_as_s16_p[1] = 1;
    func_001D75D0();
}

void func_001D75D0(void)
{
    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3]--;

    if ((s32)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        *(u16 *)(reg_a6 + 0x88) -= 4;

        if (0 < *(s16 *)(reg_a6 + 0x88)) {
            return;
        }

        *(u16 *)(reg_a6 + 0x88) = 0;
        func_001D71C0();
    }
}


void func_001D7650(void) {
    reg_a4_as_s16_p[1] = 1;
    func_001D7660();
}

void func_001D7660() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0xA8))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xA8))) >= 0x20) {
            (*(u16 *)((u8 *)(reg_a6) + (0xA8))) = 0x20U;
            func_001D71C0();
        }
    }
}


void func_001D76E0(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    func_001D76F0();
}

void func_001D76F0(void)
{
    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        s16 *remaining;

        reg_a4[3] = reg_a4[2];
        *(u16 *)(reg_a6 + 0xA8) -= 4;
        remaining = (s16 *)(reg_a6 + 0xA8);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        func_001D71C0();
    }
}


void func_001D7770(void) {
    func_001D7780();
}

s32 func_00202140();                            /* extern */
s32 func_00202500();                            /* extern */

void func_001D7780(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
    func_00202140();
    if (cond_flag == 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x11A)));
        func_00202500();
        (*(u8 *)((u8 *)(reg_a6) + (0x11A))) = (u8) reg_d1.b[0];
    }
}


void func_001D77E0(void) {
    func_001D77F0();
}

void func_001D77F0(void) {
    (*(u16 *)((u8 *)(reg_a6) + (0x26))) += 4;
    (*(u16 *)((u8 *)(reg_a6) + (0x26))) &= 0x1F;
    (*(u16 *)((u8 *)(reg_a6) + (0x46))) += 4;
    (*(u16 *)((u8 *)(reg_a6) + (0x46))) &= 0x1F;
    (*(u16 *)((u8 *)(reg_a6) + (0x86))) += 4;
    (*(u16 *)((u8 *)(reg_a6) + (0x86))) &= 0x1F;
    (*(u16 *)((u8 *)(reg_a6) + (0xA6))) += 4;
    (*(u16 *)((u8 *)(reg_a6) + (0xA6))) &= 0x1F;
}

#include "common.h"

void func_0011D600(void);
void func_0011D6F0(void);
void func_0011D7E0(void);
void func_0011D900(void);
void func_0011DA20(void);
void func_0011DB40(void);

s32 func_00171330(s32 *);
s32 func_001713A0();
s32 func_00201B80();
extern u8 D_0028E290;
extern u8 D_0028E2C8;
extern u8 D_0028ED80;
extern void func_0019C4F0();

void func_0011D510(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        func_001713A0();
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    if ((s16) reg_d0.h[0] < -0x13FF) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4F0);
}


void func_0011D5A0(void) {
    reg_tmp.w = 0x1BF8;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2EE0;
    reg_tmp.w = (u32) (u32)func_0011D600;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x13;
}

void func_0011D600(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        func_001713A0();
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    if ((s16) reg_d0.h[0] < -0x5C00) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4F0);
}


void func_0011D690(void) {
    reg_tmp.w = 0x1BA0;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1F20;
    reg_tmp.w = (u32) (u32)func_0011D6F0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x11;
}

extern void func_0019C4B0();

void func_0011D6F0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        func_001713A0();
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    if ((s16) reg_d0.h[0] < -0x3C00) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4B0);
}


void func_0011D780(void) {
    reg_tmp.w = 0x1BA3;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2050;
    reg_tmp.w = (u32) (u32)func_0011D7E0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x12;
}

void func_0011D7E0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    if ((s16) reg_d0.h[0] < -0x4000) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4F0);
}

void func_0011D840(void) {
    reg_tmp.w = 0x1BA3;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2050;
    reg_tmp.w = (u32) (u32)func_0011D7E0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0xC) = 0x52;
}


void func_0011D8A0(void) {
    reg_tmp.w = 0x1BA4;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2A50;
    reg_tmp.w = (u32) (u32)func_0011D900;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x12;
}

void func_0011D900(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    if ((s16) reg_d0.h[0] < -0x5400) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4F0);
}

void func_0011D960(void) {
    reg_tmp.w = 0x1BA4;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2A50;
    reg_tmp.w = (u32) (u32)func_0011D900;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0xC) = 0x52;
}


void func_0011D9C0(void) {
    reg_tmp.w = 0x1BF9;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1220;
    reg_tmp.w = (u32) (u32)func_0011DA20;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x15;
}

void func_0011DA20(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        func_001713A0();
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    if ((s16) reg_d0.h[0] < -0x2400) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4F0);
}


void func_0011DAB0(void) {
    reg_tmp.w = (u32) (u32)func_0011DB40;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 6) = 0xF8;
    reg_tmp.w = 0x1BB7;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0x1BC7;
    *(u16 *)(reg_a6 + 0x14) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x16) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x19) = 2;
    *(s8 *)(reg_a6 + 0x18) = 2;
}

s32 func_0019C530();
s32 func_0019C730();
extern u16 D_002524E0[];
extern u8 D_0028E2C0;
extern u16 D_0028E8A8;

void func_0011DB40(void) {
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a3;

    if ((s32) D_0028E8A8 >= 0x22F) {
        func_001713A0();
        return;
    }
    func_00201B80();
    if (((s32) D_0028E8A8 >= 0x1F4) && (0 <= (s64)*(s16 *)(reg_a6 + 6))) {
        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x19);
        *(u8 *)(reg_a6 + 0x19) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a6 + 0x19) = (u8) *(u8 *)(reg_a6 + 0x18);
            reg_d0.h[0] = *(u16 *)(reg_a6 + 6);
            reg_a0 = (u8 *)(D_002524E0);
            reg_a0 += reg_d0.h[0];
            *(u16 *)(reg_a6 + 0x10) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a6 + 0x12) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a6 + 0x14) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a6 + 0x16) = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a6 + 6) -= 8;
        }
    }
    if (((s32) D_0028E8A8 < 0x21A) && ((reg_d1.h[1] = *(u16 *)(reg_a6 + 2), reg_d1.h[0] = *(u16 *)(reg_a6 + 4), temp_a3 = reg_d1.w, reg_d1.w = temp_a3 + 0xFE00DC00, reg_d2.h[1] = *(u16 *)(reg_a6 + 0x10), temp_a2 = *(u16 *)(reg_a6 + 0x12), reg_d2.h[0] = temp_a2, reg_d3.h[0] = 0x2720, reg_d4.h[0] = 0x15, (D_0028ED80 == 0)) || (D_0028E2C8 == 0) || (D_0028E2C0 == 0)) && ((D_0028E290 != 2) || (D_0028E2C0 == 0))) {
        func_0019C730();
    }
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += 0x4C00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFE00DC00;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x14);
    temp_a2_2 = *(u16 *)(reg_a6 + 0x16);
    reg_d2.h[0] = temp_a2_2;
    reg_d3.h[0] = 0x2320;
    reg_d4.h[0] = 0x15;
    if (((D_0028ED80 == 0) || (D_0028E2C8 == 0) || (D_0028E2C0 == 0)) && ((D_0028E290 != 2) || (D_0028E2C0 == 0))) {
        func_0019C530();
    }
}

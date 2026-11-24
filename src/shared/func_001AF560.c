#include "common.h"

typedef void (*Fn)(void);

extern s8 D_0028E408;

void func_0012FBD0(void);
void func_001301B0(void);
void func_00131610(void);
void func_001353E0(void);
void func_001A3020(void);
void func_001A3560(void);
void func_001A35A0(void);
void func_001A3630(void);
void func_001AF1A0(void);
void func_001AF210(void);
void func_001AF3A0(void);
void func_001AF460(void);
void func_001AF8F0(void);
void func_001AFCC0(void);
void func_001B00D0(void);
void func_001B0100(void);
extern u8 D_002623B0[];
extern u8 D_0028E304;
extern u16 D_0028E314;
extern u16 D_0028E318;
extern u16 D_0028E3C0;
extern u16 D_0028E910;
extern u8 D_0028ED58;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AF560(void) {
    u8 state;
    u8 seq;

    state = *(u8 *)(reg_a5 + 3);
    if (state == 0) {
        func_001AF3A0();
        return;
    }
    if (state == 2) {
        func_001AF460();
        return;
    }
    func_00131610();
    if (D_0028E408 != 0) {
        goto block_50;
    }
    if (*(u8 *)(reg_a5 + 0xD) != 0) {
        goto block_51;
    }
    if (D_0028E910 != 0) {
        goto block_50;
    }
    if (D_0028E304 != 0) {
        goto block_50;
    }
    if (D_0028ED80 == 1) {
        goto block_50;
    }
#ifdef DEATH_LABEL
    if ((D_0028ED7C == 2) && (D_0028ED58 == 0)) {
        goto block_50;
    }
#else
    if ((D_0028E3C0 == 0) && (D_0028ED7C == 2) && (D_0028ED58 == 0)) {
        goto block_50;
    }
#endif
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 == 0) {
            goto block_50;
        }
    } else {
        if (D_0028E314 == 0) {
            goto block_50;
        }
    }
    func_001301B0();
    if (reg_d0.h[0] != 0) {
        goto next_1;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3630();
    goto block_51;
next_1:
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3560();
    goto block_51;
block_50:
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A35A0();
    return;
block_51:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_a4 = (u8 *)reg_tmp.w;
    if (*(u8 *)(reg_a5 + 0xD) != 0) {
        goto block_52;
    }
    if (D_0028E910 != 0) {
        goto block_52;
    }
    if (D_0028E3C0 != 0) {
        goto block_52;
    }
    if (D_0028ED80 == 1) {
        goto block_52;
    }
#ifdef DEATH_LABEL
    if ((D_0028ED7C == 2) && (D_0028ED58 == 0)) {
        goto block_50;
    }
#else
    if ((D_0028E3C0 == 0) && (D_0028ED7C == 2) && (D_0028ED58 == 0)) {
        goto block_50;
    }
#endif
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 == 0) {
            goto block_52;
        }
    } else {
        if (D_0028E314 == 0) {
            goto block_52;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = reg_a0;
    ((Fn)jtbl_0028E3F4)();
    if (!(reg_d0.w & 0x8000)) {
        goto block_52;
    }
    func_00131610();
    if (D_0028E408 != 0) {
        goto block_52;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = reg_a0;
    ((Fn)jtbl_0028E3F4)();
    if (D_0028E408 != 0) {
        goto block_52;
    }
    func_001AF1A0();
    func_001AF210();
    *(u8 *)(reg_a5 + 0xD) = 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3560();
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
#ifdef DEATH_LABEL
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 != 0) {
            D_0028E318 -= 1;
        }
    } else {
        if (D_0028E314 != 0) {
            D_0028E314 -= 1;
        }
    }
#endif
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
    reg_a0 = (u8 *)D_002623B0;
    func_001A3020();
    func_0012FBD0();
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    reg_d1.h[0] = 7;
    func_001353E0();
    func_001B0100();
block_52:
    seq = *(u8 *)(reg_a5 + 0xD);
    if (seq == 1) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A3560();
        func_001AF8F0();
        if (D_0028E408 != 0) {
            *(u8 *)(reg_a5 + 0xD) = 2;
            *(s8 *)(reg_a5 + 0xC) = 1;
        }
        return;
    }
    if (seq == 2) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A3560();
        func_001AFCC0();
        return;
    }
    func_001B00D0();
}

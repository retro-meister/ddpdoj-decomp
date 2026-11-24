#include "common.h"

s32 func_00138A40();
s32 func_00138A50();
s32 func_001391B0();
s32 func_001394A0();
s32 func_00225670();
extern u16 D_0028E128;
extern u16 D_0028E12C;
extern u16 D_0028E130;
extern u16 D_0028E134;
extern u16 D_0028E138;
extern u16 D_0028E13C;
extern u16 D_0028E140;
extern u16 D_0028E144;
extern u16 D_0028E148;
extern u16 D_0028E14C;
extern u16 D_0028E150;
extern u16 D_0028E154;
extern u16 D_0028E158;
extern u16 D_0028E15C;
extern u16 D_0028E160;
extern u16 D_0028E164;
extern u16 D_0028E168;
extern u16 D_0028E16C;
extern u16 D_0028E170;
extern u16 D_0028E174;
extern u16 D_0028E178;
extern u16 D_0028E17C;
extern u16 D_0028E180;
extern u16 D_0028E184;
extern u16 D_0028E188;
extern u16 D_0028E190;
extern u16 D_0028E194;
extern u16 D_0028E198;
extern u16 D_0028E19C;
extern u16 D_0028E1A0;
extern u8 D_0028E290;
extern u8 D_0028E2C0;
extern u8 D_0028E2C8;
extern u8 D_0028E350;
extern u8 D_0028E370;
extern u16 D_0028E3C0;
extern s16 D_0028E3FC;
extern u16 D_0028E8A8;
extern u16 D_0028E91C;
extern u8 g_cd_async_state;
extern u8 g_cd_async_busy;
extern u8 D_0028EC58;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u8 *reg_a5;

void func_00138DA0(void) {
    u16 save_22;
    u16 save_21;
    u16 save_20;
    u16 save_19;
    u16 save_18;
    u16 save_17;
    u16 save_16;
    u16 save_15;
    u16 save_14;
    u16 save_13;
    u16 save_12;
    u16 save_11;
    u16 save_10;
    u16 save_09;
    u16 save_08;
    u16 save_07;
    u16 save_06;
    u16 save_05;
    u16 save_04;
    u16 save_03;
    u16 save_02;
    u16 save_01;
    u16 save_00;
    s32 more;
    s32 done;
    u16 save_23;
    u16 save_29;
    u16 save_28;
    u16 save_27;
    u16 save_24;
    u16 save_25;
    u16 save_26;
    u8 t;
    u8 *p;

    D_0028E2C0 = 0;
    t = *(u8 *) (reg_a5 + 2);
    p = reg_a5 + 2;
    if (t & 8) {
        func_001391B0();
        return;
    }
    if (t & 1) {
        *p = t | 1;
        goto next_3;
    }
    *p = t | 1;
    func_00138A50();
    if (D_0028ED80 != 0) {
        goto next_1;
    }
#ifndef DEATH_LABEL
    if (D_0028E3C0 != 0) {
        goto next_2;
    }
#endif
    if (D_0028ED7C != 2) {
        goto next_2;
    }
next_1:
    if (D_0028E3FC != D_0028E91C) {
        func_00225670();
    }
next_2:
    D_0028E350 = 0;
    g_cd_async_busy = 1;
    g_cd_async_state = 0;
    D_0028E370 = 0;
    D_0028EC58 = 0;
    return;
next_3:
    t = *(u8 *) (reg_a5 + 2);
    p = reg_a5 + 2;
    if (!(t & 2)) {
        func_001394A0();
        return;
    }
    *p = t | 8;
    if (D_0028ED80 == 0) {
        goto next_4;
    }
    if (D_0028E2C8 != 0) {
        goto next_5;
    }
next_4:
    if (D_0028E290 != 2) {
        return;
    }
next_5:
    more = 1;
    done = 0;
    save_23 = D_0028E140;
    save_29 = D_0028E13C;
    save_28 = D_0028E138;
    save_27 = D_0028E134;
    save_24 = D_0028E130;
    save_22 = D_0028E1A0;
    save_25 = D_0028E12C;
    save_26 = D_0028E128;
    D_0028E2C0 = 1;
    save_21 = D_0028E19C;
    save_20 = D_0028E198;
    save_19 = D_0028E194;
    save_18 = D_0028E178;
    save_17 = D_0028E190;
    save_16 = D_0028E174;
    save_15 = D_0028E17C;
    save_14 = D_0028E188;
    save_13 = D_0028E184;
    save_12 = D_0028E180;
    save_11 = D_0028E170;
    save_10 = D_0028E16C;
    save_09 = D_0028E168;
    save_08 = D_0028E164;
    save_07 = D_0028E160;
    save_06 = D_0028E15C;
    save_05 = D_0028E158;
    save_04 = D_0028E154;
    save_03 = D_0028E150;
    save_02 = D_0028E14C;
    save_01 = D_0028E148;
    save_00 = D_0028E144;
loop_6:
    func_001391B0();
    if (done == 0 && D_0028E91C == 2 && D_0028E8A8 == 0xE4 && *(u16 *) (reg_a5 + 8) == 1) {
        func_00138A40();
        done = 1;
    }
    if (D_0028E91C == 4 && D_0028E8A8 == 0x319) {
        more = 0;
    }
    if (D_0028E91C == 3 && D_0028E8A8 == MAIN_OR_DEATH_LABEL(0x2C5, 0x2C6)) {
        more = 0;
    }
    if (D_0028E91C == 2 && D_0028E8A8 == MAIN_OR_DEATH_LABEL(0x19A, 0x199)) {
        more = 0;
    }
    if (D_0028E91C == 1 && D_0028E8A8 == MAIN_OR_DEATH_LABEL(0x1D5, 0x1D6)) {
        more = 0;
    }
    if (D_0028E91C == 0 && D_0028E8A8 == 0x1CF) {
        more = 0;
    }
    if (more != 0) {
        goto loop_6;
    }
    D_0028E140 = save_23;
    D_0028E13C = save_29;
    D_0028E138 = save_28;
    D_0028E134 = save_27;
    D_0028E130 = save_24;
    D_0028E1A0 = save_22;
    D_0028E12C = save_25;
    D_0028E128 = save_26;
    D_0028E19C = save_21;
    D_0028E198 = save_20;
    D_0028E194 = save_19;
    D_0028E178 = save_18;
    D_0028E190 = save_17;
    D_0028E174 = save_16;
    D_0028E17C = save_15;
    D_0028E188 = save_14;
    D_0028E184 = save_13;
    D_0028E180 = save_12;
    D_0028E170 = save_11;
    D_0028E16C = save_10;
    D_0028E168 = save_09;
    D_0028E164 = save_08;
    D_0028E160 = save_07;
    D_0028E15C = save_06;
    D_0028E158 = save_05;
    D_0028E154 = save_04;
    D_0028E150 = save_03;
    D_0028E14C = save_02;
    D_0028E148 = save_01;
    D_0028E144 = save_00;
}

#include "common.h"
#include "entity.h"

void func_001F1540();
void func_001F1680();
void func_001F1E20();
void func_001F1FE0(void);
void func_001F2640();
void func_001F28A0();
void func_001F3010(void);
void func_001F3060(void);
void func_001F30F0(void);
void func_001F3190();
void func_001F3240(void);
void func_001F32D0(void);
void func_001F33D0(void);
void func_001F34A0(void);
void func_001F35B0(void);
void func_001F3650(void);
void func_001F3700(void);
void func_001F37A0(void);
void func_001F3860();
void func_001F3950(void);
void func_001F39C0(void);

s32 func_00124F50();                            /* extern */
s32 func_0020ED10();                            /* extern */
extern u16 D_0028E2E8;

#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void func_001F14C0(void) {
    s32 func_00124D90();
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 0;
#endif
    reg_d0.w = 0;
    func_00124F50();
    reg_d0.w = 1;
    func_00124F50();
    reg_d0.w = 0;
    func_00124D90();
    func_0020ED10();
    *(s16 *)(reg_a4 + 2) = 0x260;
    *(s16 *)(reg_a4 + 4) = 0x160;
    if (D_0028E2E8 == 0) {
        func_001F1540(0x260);
        return;
    }
    *(s16 *)(reg_a4 + 4) = 0;
    func_001F1540(0x260);
}

s32 func_00124B20();
s32 func_0013B2E0();
s32 func_001F5640();
extern u8 D_00264EA0[];
extern s16 D_0028E5B0_as_s16;
extern u8 *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern s16 D_0028E908_as_s16;

void func_001F1540() {
    u16 temp_v1;
    u16 var_a1;

    temp_v1 = *(u16 *)(reg_a4 + 4);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_tmp.w = 0x69000;
            D_0028E855 |= 1;
            D_0028E855 |= 4;
            D_0028E854 |= 1;
            *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
            var_a1 = reg_tmp.h[0];
            *(u16 *)(reg_a5 + 0x18) = var_a1;
            D_0028E624 = 0x780;
            reg_a0 = reg_a5 + 0x16;
            D_0028E620 = (u8 *)(reg_a0);
        }
    }
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        D_0028E5B0_as_s16 = 1;
        if (D_0028E2E8 == 0) {
            D_0028E855 |= 2;
            D_0028E855 |= 0x10;
        } else {
            D_0028E908_as_s16 = 1;
        }
        func_001F5640();
        reg_a0 = (u8 *)D_00264EA0;
        func_0013B2E0();
        reg_d0.w = 6;
        func_00124B20();
        *(s16 *)reg_a4 = 0;
    }
}

extern void *reg_a4_as_void_p;

void func_001F1660(void) {
    ((u16 *)reg_a4_as_void_p)[1] = 0xC0;
    ((u16 *)reg_a4_as_void_p)[2] = 0x303;
    func_001F1680(0xC0);
}

typedef void (*Fn)();

extern u8 D_00264C30[];
s32 func_00124E80();
s32 func_001389D0();
s32 func_00139EB0();
s32 func_0013A780();
s32 func_0018D500();
s32 func_0018D520();
s32 func_0018D5C0();
s32 func_0018D660();
s32 func_001E1F30();
s32 func_002011A0();
s32 func_00201270();
s32 func_002012F0();
s32 func_00211550();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_00264BB0[];
extern u16 D_00264C10[];
extern u8 D_0028E310;
extern void (*jtbl_0028E3F4)();

void func_001F1680() {
    s16 t1;
    s16 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        func_00139EB0();
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        t6 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = t6;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(u16 *)(reg_a0 + 0x28) = 0x600U;
        *(s16 *)(reg_a0 + 0x1A) = 0x658;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xC00U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x6A8;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x400U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA88;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 6;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x600U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA78;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 4;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF600U;
        *(u16 *)(reg_a0 + 0x28) = 0xA00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA70;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 0xA;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x588;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xE000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x4A0;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xD800U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0x460;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        t1 = (s16) ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.sh;
        ENTITY(reg_a6)->y.h += 0x7FFF + 0x7401;
        ENTITY(reg_a6)->x.h += 0x7FFF + 0x7101;
        func_001E1F30();
        ENTITY(reg_a6)->x.h += 0x1E00;
        func_001E1F30();
        ENTITY(reg_a6)->y.h = t1;
        ENTITY(reg_a6)->x.h = t2;
        reg_a0 = (u8 *)D_00264C30;
        func_0013B2E0();
        if (D_0028E2E8 == 0) {
            func_0018D660();
            func_00124E80();
            reg_d7.w = 0x14;
            reg_a3 = (u8 *)(D_00264BB0);
            do {
                reg_d1.h[0] = 0;
                reg_d2.h[1] = *(u16 *)reg_a3;
                reg_a3 += 2;
                t3 = *(u16 *)reg_a3;
                reg_d2.h[0] = t3;
                reg_a3 += 2;
                reg_d0.w = 0xC;
                func_00211550();
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d0.w = 0x14;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
            return;
        }
        vibration_start_pad1(0xC8, 0x50);
        vibration_start_pad2(0xC8, 0x50);
        D_0028E310 = 0x50;
        func_0018D5C0();
        reg_d0.h[0] = 0x10;
        reg_d1.h[0] = 0x10;
        func_001389D0();
        reg_d0.w = 2;
        func_00124B20();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto block_rts;
    }
    *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
    reg_a0 = (u8 *)func_0018D500;
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        reg_a0 = (u8 *)func_0018D520;
    }
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    func_002011A0();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *)(D_00264C10);
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    t5 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = t5;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
    func_002011A0();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    func_002012F0();
    t4 = reg_d0.h[0];
    reg_d1.h[0] = t4;
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] = t4 + reg_d1.h[0];
    reg_d0.h[0] += 0x7FFF + 0x7801;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
}

extern s16 *reg_a4_as_s16_p;
extern s16 *reg_a5_as_s16_p;

#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void func_001F1DF0(void) {
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 1;
#endif
    reg_a4_as_s16_p[1] = 1;
    reg_a4_as_s16_p[2] = 0x80;
    reg_a5_as_s16_p[13] = 0x6270;
    func_001F1E20(0x80, 1);
}

s32 func_00124DC0();
s32 func_00124F00();
s32 func_001F5630();
s32 func_001F56F0();
s32 func_001F57C0();
s32 func_0020ED10();

void func_001F1E20() {
    s32 func_00124D90();
    u16 temp_v1;
    u8 *temp_a0;

    temp_v1 = *(u16 *)(reg_a4 + 2);
    temp_a0 = reg_a4 + 2;
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0;
            func_00124F00();
            reg_d0.w = 1;
            func_00124F00();
            reg_d0.w = 9;
            func_00124F00();
            reg_d0.w = 2;
            func_00124F00();
            reg_d0.w = 5;
            func_00124F00();
            reg_d0.w = 4;
            func_00124F00();
            reg_d0.w = 3;
            func_00124F00();
            reg_d0.w = 8;
            func_00124F00();
            reg_d0.w = 7;
            func_00124F00();
            reg_d0.w = 6;
            func_00124F00();
            reg_d0.w = 0xB;
            func_00124DC0();
            reg_d0.w = 0xC;
            func_00124DC0();
            reg_d0.w = 0xD;
            func_00124DC0();
            reg_d0.w = 0xF;
            func_00124DC0();
            reg_d0.w = 1;
            func_00124D90();
            *(s8 *)(reg_a6 + 0x10F) = 1;
            *(s16 *)(reg_a6 + 0x172) = 0;
            reg_tmp.w = 0x23000;
            *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
            func_001F5630();
            func_001F56F0();
            func_001F57C0();
            func_0020ED10();
        }
    } else {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 0xA;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F1FA0(void) {
    s32 func_00124D90(s32, s32);
    *(s16 *)(reg_a4 + 2) = 0xC0;
    *(s16 *)(reg_a4 + 4) = 0x303;
    reg_d0.w = 3;
    func_00124D90(0x303, 0xC0);
    func_001F1FE0();
}

extern u8 D_00264D00[];

void func_001F1FE0(void) {
    u16 temp_a1;
    u16 temp_a3;
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        func_0018D5C0();
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a3 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a3;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(u16 *)(reg_a0 + 0x28) = 0x600U;
        *(s16 *)(reg_a0 + 0x1A) = 0x658;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xC00U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x6A8;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x400U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA88;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 6;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x600U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA78;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 4;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF600U;
        *(u16 *)(reg_a0 + 0x28) = 0xA00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA70;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 0xA;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x588;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xE000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x4A0;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0xD;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xD800U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0x460;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        vibration_start_pad1(0xC8, 0x50, 0x460, 0x400);
        vibration_start_pad2(0xC8, 0x50);
        reg_a0 = (u8 *)D_00264D00;
        func_0013B2E0();
        reg_d0.h[0] = 0x200;
        reg_d1.h[0] = 0x200;
        func_001389D0();
        reg_d0.w = 4;
        func_00124B20();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto block_rts;
    }
    {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_a0 = (u8 *)func_0018D500;
        func_002011A0();
        if (0 > reg_d0.sb[0]) {
            reg_a0 = (u8 *)func_0018D520;
        }
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        func_002011A0();
        reg_d0.h[0] &= 7;
        reg_a1 = (u8 *)(D_00264C10);
        reg_d0.h[0] += reg_d0.h[0];
        switch (reg_d0.h[0]) { case 0: goto block_zero; }
        temp_a3 = *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1));
        goto block_join;
block_zero:
        temp_a3 = *(u16 *)reg_a1;
block_join:
        reg_d0.h[0] = temp_a3;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a1;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x800;
        func_00201270();
        reg_d0.b[0] += 3;
        *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
        func_002011A0();
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
        func_002012F0();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0xF800;
        *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
    }
}

typedef struct WorkRegA4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;
extern s16 D_0028E88C_as_s16;


#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void func_001F2620(void) {
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 2;
#endif
    reg_a4_as_WorkRegA4_p->unk2 = 1;
    reg_a4_as_WorkRegA4_p->unk4 = 0x80;
    D_0028E88C_as_s16 = 0;
    func_001F2640(1);
}

s32 func_00124D70();
s32 func_00124F50();
s32 func_0018D350();
s32 func_001F5730();
extern void *D_0028E620_as_void_p;
extern u16 D_0028E908;
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];

#ifdef DEATH_LABEL
extern u16 death_D_0068FFB2[];
extern u16 death_D_0068FFB4[];
extern u16 death_D_006901B2[];
extern u16 death_D_006901B4[];
#endif

void func_001F2640() {
    s32 func_00124D90();
    u16 t1;
    u8 *t2;

    t1 = *(u16 *)(reg_a4 + 2);
    t2 = (u8 *)(reg_a4 + 2);
    if (t1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (t1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            D_0028E855 |= 2;
            reg_d0.w = 0xB;
            D_0028E855 |= 0x10;
            func_00124F00();
            reg_d0.w = 0xC;
            func_00124F00();
            reg_d0.w = 0xD;
            func_00124F00();
            reg_d0.w = 0xF;
            func_00124F00();
            reg_d0.w = 0x10;
            func_00124DC0();
            reg_d0.w = 6;
            func_00124F50();
            reg_d0.w = 7;
            func_00124F50();
            reg_d0.w = 3;
            func_00124D70();
            reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
            func_00124D90();
#ifdef DEATH_LABEL
            death_D_006901B2[0] = death_D_0068FFB2[0];
            death_D_006901B4[0] = death_D_0068FFB4[0];
#endif
            *(s8 *)(reg_a6 + 0x10F) = 2;
            D_0028E908 = 0xFFFF;
            reg_d0.w = 0x4D000;
            *(u16 *)(reg_a5 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a5 + 0x18) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a5 + 0x1C) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d0.h[0];
            D_0028E624 = 0x580;
            reg_a0 = (u8 *)(reg_a5 + 0x16);
            D_0028E620_as_void_p = (void *)reg_a0;
            D_0028E855 |= 1;
            D_0028E855 |= 4;
            D_0028E854 |= 1;
            func_001F5630();
            func_001F5730();
            func_001F57C0();
            D_00299768_as_u16_a[0] = 1;
            D_0029976A_as_u16_a[0] = 1;
            D_0029976C[0] = 1;
            D_0029976E[0] = 1;
            func_0020ED10();
            func_0018D350();
        }
    } else {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0xF, 21);
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}

s32 func_0013B8B0();                            /* extern */
s32 func_001A3020();                            /* extern */
extern s32 D_002554B0_as_s32_a[];
extern s32 D_00264E80[];
extern s32 *reg_a0_as_s32_p;

void func_001F2810(void) {
    reg_d0.h[0] = 0xE;
    reg_a0_as_s32_p = D_002554B0_as_s32_a;
    func_001A3020();
    reg_a0_as_s32_p = D_00264E80;
    func_0013B8B0();
    *(s16 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x101;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 0xA) = 1;
    *(s8 *)(reg_a4 + 0xD) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x2020;
    *(s16 *)(reg_a4 + 0x12) = 0;
    func_001F28A0(1, 0x101);
}

extern u8 D_00264E10[];

s32 func_00124510();
s32 func_00125410();
s32 func_00125440();
s32 func_0013AAB0();
s32 func_0018D560();
s32 func_002010A0();
extern u16 D_00264D80[];

/* Death Label runs each emitter twice, once per boss body. */
#ifdef DEATH_LABEL
#define BOSS_X x
#define BOSS_Y y
#else
#define BOSS_X (ENTITY(reg_a6)->y.h)
#define BOSS_Y (ENTITY(reg_a6)->x.h)
#endif

void func_001F28A0() {
#ifdef DEATH_LABEL
    s32 i;
    u16 y;
    u16 x;

#endif
    if (*(u16 *)(reg_a4 + 2) != 4) goto block_3;
    *(u16 *)(reg_a4 + 4) -= 1;
    if (*(u16 *)(reg_a4 + 4) != 0) goto block_rts_2;
    func_00124510();
    *(u16 *)(reg_a4 + 0) = 0;
block_rts_2:
    return;
block_3:
    if (*(u16 *)(reg_a4 + 2) != 3) goto block_2;
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_d6.w = 0;
    reg_a1 = (u8 *)D_00264D80;
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if ((s16)reg_d0.h[0] == -1) goto block_3_end;
    func_0013A780();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u8 *)(reg_a0 + 0x1D) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = BOSS_X;
    *(u16 *)(reg_a0 + 4) = BOSS_Y;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    func_002010A0();
    reg_d0.b[0] += 4;
    reg_d0.b[0] += *(u8 *)(reg_a4 + 0xD);
    *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
    func_002011A0();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x18) = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_1;
block_3_end:
#ifdef DEATH_LABEL
        x = *(u16 *)(reg_a6 + 0x202);
        y = *(u16 *)(reg_a6 + 0x204);
    }
#endif
    *(u16 *)(reg_a4 + 4) = 0x80;
    *(u16 *)(reg_a4 + 2) = 4;
    func_0018D660();
    return;
block_2:
    if (*(u16 *)(reg_a4 + 2) != 2) goto block_1;
    func_00125440();
    if (cond_flag != 0) goto block_1;
    reg_a0 = (u8 *)D_00264E10;
    func_0013B2E0();
    func_00124E80();
    *(u16 *)(reg_a4 + 0xA) = 1;
    *(u16 *)(reg_a4 + 2) = 3;
    return;
block_1:
    if (*(u16 *)(reg_a4 + 2) != 1) goto block_0;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
    *(u8 *)(reg_a4 + 0x11) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    *(u8 *)(reg_a4 + 0x11) = *(u8 *)(reg_a4 + 0x10);
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    func_002011A0();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d2.h[1] = BOSS_X;
    reg_d2.h[0] = BOSS_Y;
    func_002012F0();
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 2;
    reg_d2.h[0] += reg_d0.h[0];
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    func_002012F0();
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 1;
    reg_d2.h[0] += reg_d0.h[0];
    reg_d2.h[0] -= 0x1000;
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    reg_d3.h[0] = 8;
    reg_d0.h[0] = 0;
    func_0013AAB0();
#ifdef DEATH_LABEL
        x = *(u16 *)(reg_a6 + 0x202);
        y = *(u16 *)(reg_a6 + 0x204);
    }
#endif
    switch (*(u8 *)(reg_a4 + 6)) { case 2: goto next_1; }
    func_0018D560();
next_1:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
    *(u8 *)(reg_a4 + 0xF) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    *(u8 *)(reg_a4 + 0xF) = *(u8 *)(reg_a4 + 0xE);
    if (*(u8 *)(reg_a4 + 6) == 2) goto next_2;
    *(u8 *)(reg_a4 + 6) -= 1;
    *(u8 *)(reg_a4 + 0xD) += 1;
next_2:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_0;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    if (*(u8 *)(reg_a4 + 6) == 2) goto next_3;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x12);
    *(u8 *)(reg_a4 + 0x12) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_3;
    *(u8 *)(reg_a4 + 0x12) = 4;
    func_0018D520();
next_3:
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_a1 = (u8 *)D_00264D80;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_0013A780();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u8 *)(reg_a0 + 0x1D) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = BOSS_X;
    *(u16 *)(reg_a0 + 4) = BOSS_Y;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 2;
    reg_d0.b[0] += 2;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
    reg_d1.b[0] = (s8)reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
    func_002011A0();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
#ifdef DEATH_LABEL
        x = *(u16 *)(reg_a6 + 0x202);
        y = *(u16 *)(reg_a6 + 0x204);
    }
#endif
    *(u16 *)(reg_a4 + 8) += 8;
    if (*(u16 *)(reg_a4 + 8) != 0x80) goto block_0;
    *(u16 *)(reg_a4 + 8) = 0;
    if (*(u8 *)(reg_a4 + 6) != 2) goto block_0;
    reg_d0.h[0] = 0xE;
    func_00125410();
    *(u16 *)(reg_a4 + 2) = 2;
    return;
block_0:
    if (*(u16 *)(reg_a4 + 2) != 0) return;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    if (*(u8 *)(reg_a4 + 0x13) & 1) {
        *(u8 *)(reg_a4 + 0x13) &= 0xFE;
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x13) |= 1;
    reg_a0 = (u8 *)func_0018D500;
    func_002011A0();
    if (!(0 > reg_d0.sb[0])) goto next_5;
    reg_a0 = (u8 *)func_0018D520;
next_5:
    jtbl_0028E3F4 = (Fn)reg_a0;
    jtbl_0028E3F4();
next_4:
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_a1 = (u8 *)D_00264D80;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_0013A780();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u8 *)(reg_a0 + 0x1D) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = BOSS_X;
    *(u16 *)(reg_a0 + 4) = BOSS_Y;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
#ifdef DEATH_LABEL
        x = *(u16 *)(reg_a6 + 0x202);
        y = *(u16 *)(reg_a6 + 0x204);
    }
#endif
    *(u16 *)(reg_a4 + 8) += 8;
    if ((s32)*(u16 *)(reg_a4 + 8) < 0x80) return;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) != 0) return;
    *(u16 *)(reg_a4 + 6) = 0x2010;
    *(u16 *)(reg_a4 + 0xE) = 0x1111;
    *(u16 *)(reg_a4 + 2) = 1;
block_rts:
    return;
}

s32 func_001251C0();                            /* extern */

void func_001F2FE0(void) {
    reg_d0.w = 2;
    func_00124F50();
    reg_d0.w = 0;
    func_001251C0();
    func_001F3010();
}

s32 func_00124B20();                            /* extern */
s32 func_00125250();                            /* extern */

void func_001F3010(void) {
    reg_d0.w = 0;
    func_00125250();
    if (cond_flag == 0) {
        reg_d0.w = 7;
        func_00124B20();
        *reg_a4_as_s16_p = 0;
    }
}

extern u16 *reg_a4_as_u16_p;


void func_001F3050(void) {
    reg_a4_as_u16_p[1] = 0x60;
    func_001F3060();
}

s32 func_001251C0();
s32 func_00125250();
extern u16 D_0028E89C;

void func_001F3060() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 1;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 1;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F30E0(void) {
    reg_a4_as_s16_p[1] = 0x60;
    func_001F30F0();
}

void func_001F30F0() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 2;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 2;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 9;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F3170(void) {
    ((s16 *)reg_a4_as_void_p)[1] = 0x60;
    ((s16 *)reg_a4_as_void_p)[2] = 0x40;
    func_001F3190(0x60);
}

void func_001F3190() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 3;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 3;
        func_00125250();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 6;
                func_00124B20();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void func_001F3230(void) {
    reg_a4_as_u16_p[1] = 1;
    func_001F3240();
}

void func_001F3240() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 5;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 5;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F32C0(void) {
    reg_a4_as_s16_p[1] = 0x40;
    func_001F32D0();
}

void func_001F32D0() {
    s32 func_00124D90();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 6;
                func_001251C0();
                reg_d0.w = 0xE;
                func_00124F00();
                *(s16 *)(reg_a6 + 0x172) = 0;
                reg_d0.w = 5;
                func_00124D90();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 6;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xE;
            func_00124DC0();
            *(s16 *)(reg_a6 + 0x172) = 0x1000;
            reg_d0.w = 0xC;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F3390(void) {
    s32 func_00124D90(s32);
    *(s16 *)(reg_a4 + 2) = 0x50;
    reg_d0.w = 6;
    func_00124D90(0x50);
    func_001F33D0();
}

void func_001F33D0() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 7;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 7;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xD;
            func_00124B20();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F3450(void) {
    s32 func_00124D90(s32, s32);
    *(s16 *)(reg_a4 + 2) = 0x60;
    *(s16 *)(reg_a4 + 4) = 0x40;
    reg_d0.w = 7;
    func_00124D90(0x40, 0x60);
    ENTITY(reg_a6)->move.sb.speed = 0xC;
    func_001F34A0();
}

void func_001F34A0() {
    s32 func_00124D90();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 8;
                func_001251C0();
                ENTITY(reg_a6)->move.sb.speed = 4;
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 8;
        func_00125250();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 0xA;
                func_00124B20();
                reg_d0.w = 2;
                func_00124D90();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void func_001F3560(void) {
    *(s16 *)(reg_a4 + 2) = 0x40;
    *(s16 *)(reg_a4 + 4) = 1;
    *(s8 *)(reg_a6 + 0x3F) = 0;
    *(s8 *)(reg_a6 + 0x5F) = 0;
    *(s8 *)(reg_a6 + 0x7F) = 0;
    *(s8 *)(reg_a6 + 0x9F) = 0;
    *(s8 *)(reg_a6 + 0xBF) = 0;
    *(s8 *)(reg_a6 + 0xDF) = 0;
    func_001F35B0();
}

void func_001F35B0() {
    u16 temp_a0;
    u16 temp_v1;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 4;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
            if (*(u16 *)(reg_a4 + 4) == 0) {
                func_001F5630();
            }
        }
    }
}


void func_001F3640(void) {
    *(s16 *)(reg_a4 + 2) = 0x60;
    func_001F3650();
}

void func_001F3650() {
    s32 func_00124D90();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 9;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 9;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0x11;
            func_00124B20();
            reg_d0.w = MAIN_OR_DEATH_LABEL(9, 14);
            func_00124D90();
            ENTITY(reg_a6)->move.sb.speed = 0xC;
#ifdef DEATH_LABEL
            *(s8 *)(reg_a6 + 0x21B) = 0xC;
#endif
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F36F0(void) {
    *(s16 *)(reg_a4 + 2) = 0x60;
    func_001F3700();
}

void func_001F3700() {
    s32 func_00124D90();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 0xA;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xA;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xF;
            func_00124B20();
            reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
            func_00124D90();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F3790(void) {
    reg_a4_as_u16_p[1] = 0x60;
    func_001F37A0();
}

void func_001F37A0() {
    s32 func_00124D90();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 0xB;
                func_001251C0();
                ENTITY(reg_a6)->move.sb.speed = 4;
#ifdef DEATH_LABEL
                *(s8 *)(reg_a6 + 0x21B) = 4;
#endif
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xB;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0x10;
            func_00124B20();
            reg_d0.w = MAIN_OR_DEATH_LABEL(8, 0xD);
            func_00124D90();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001F3840(void) {
    ((s16 *)reg_a4_as_void_p)[1] = 0x60;
    ((s16 *)reg_a4_as_void_p)[2] = 0x40;
    func_001F3860(0x60);
}

void func_001F3860() {
    s32 func_00124D90();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 0xC;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xC;
        func_00125250();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 0xF;
                func_00124B20();
                reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
                func_00124D90();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void func_001F3910(void) {
    s32 func_00124D90(s32);
    *(s16 *)(reg_a4 + 2) = 0x60;
    reg_d0.w = MAIN_OR_DEATH_LABEL(0xB, 0x10);
    func_00124D90(0x60);
    func_001F3950();
}

void func_001F3950() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if ((temp_a0 != 0) && (D_0028E89C == 0)) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0xD;
            func_001251C0();
            func_001F5630();
        }
    }
}


void func_001F39B0(void) {
    reg_a4_as_s16_p[1] = 0x80;
    func_001F39C0();
}

void func_001F39C0() {
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        func_00124510();
        *(s16 *)reg_a4 = 0;
    }
}

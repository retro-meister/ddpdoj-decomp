#include "common.h"

void func_001C7D10(void);
void func_001C7DA0();
void func_001C7F70();
void func_001C87E0();
void func_001C8CB0();
void func_001C91D0();
void func_001C9570(void);
void func_001C9640(void);
void func_001C9740(void);

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */

void func_001C7CB0(void) {
    reg_d0.w = 0;
    func_00124D90();
    reg_d0.w = 0;
    func_00124F50();
    reg_d0.w = 2;
    func_00124F50();
    reg_d0.w = 0xB;
    func_00124F50();
    reg_d0.w = 0xC;
    func_00124F50();
    reg_d0.w = 0xD;
    func_00124F50();
    func_001C7D10();
}

extern u16 *reg_a4_as_u16_p;

void func_001C7D10(void) {
    *reg_a4_as_u16_p = 0;
}

s32 func_00124D90();                            /* extern */
s32 func_001CBBD0();                            /* extern */
s32 func_001CBC70();                            /* extern */
s32 func_001CBCA0();                            /* extern */

void func_001C7D20(void) {
    reg_d0.w = 3;
    func_00124D90();
    reg_d0.h[0] = 0x100;
    func_001CBCA0();
    reg_d0.h[0] = 0;
    func_001CBC70();
    reg_d0.h[0] = 0x20;
    func_001CBC70();
    func_001CBBD0();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x10;
    *(s16 *)(reg_a4 + 6) = 4;
    *(s16 *)(reg_a4 + 8) = 0;
    func_001C7DA0(0x10);
}

typedef void (*Fn)();

extern u8 D_0026C6C0[];
s32 func_00124B20();
s32 func_00124F00();
s32 func_001CBA00();
extern u8 D_0026C680[];
extern void (*jtbl_0028E3F4)();

void func_001C7DA0() {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_a1 = D_0026C680;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
        func_001CBA00();
        *(u8 *)(reg_a4 + 3) = 1U;
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_a0 = D_0026C6C0;
            reg_a0 += *(u16 *)(reg_a4 + 0x14);
            reg_a0 = *(u8 **)reg_a0;
            jtbl_0028E3F4 = (Fn)(reg_a0);
            jtbl_0028E3F4();
            *(u16 *)(reg_a4 + 0x14) += 4;
            *(u16 *)(reg_a4 + 8) &= 0x1F;
        }
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 2;
            func_00124F00();
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 4;
            func_00124B20();
        }
    }
}

s32 func_00124D90();                            /* extern */
s32 func_0013B8B0();                            /* extern */
extern s32 D_0026C7B0[];
extern s32 *reg_a0_as_s32_p;

void func_001C7EE0(void) {
    reg_d0.w = 1;
    func_00124D90();
    reg_a0_as_s32_p = D_0026C7B0;
    func_0013B8B0();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 6) = 0x101;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 0xA) = 1;
    *(s8 *)(reg_a4 + 0xD) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x2020;
    *(s16 *)(reg_a4 + 0x12) = 4;
    *(s16 *)(reg_a4 + 0x14) = 0;
    func_001C7F70(0x2020, 1, 0x101);
}

extern u8 D_0026C790[];

s32 func_00124510();
s32 func_00124E80();
s32 func_00125410();
s32 func_00125440();
s32 func_0013A780();
s32 func_0013AAB0();
s32 func_0013B2E0();
s32 func_0018D560();
s32 func_0018D660();
s32 func_002010A0();
s32 func_002011A0();
s32 func_002012F0();
extern u16 D_0026C6E0[];

void func_001C7F70() {
    u16 *t1;
    u16 *t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;
    u8 *v1;

    v1 = (u8 *)(reg_a4);
    t7 = (*(u8 *)((u8 *)(v1) + (3)));
    if (t7 == 4) {
        (*(u16 *)((u8 *)(v1) + (4))) -= 1;
        if (*(u16 *)(reg_a4 + 4) != 0) {
            goto block_rts;
        }
        func_00124510();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    } else {
        if (t7 == 3) {
            reg_d6.w = 0;
            reg_a1 = (u8 *)(D_0026C6E0);
loop_6:
            t3 = *(u16 *)reg_a1;
            reg_d0.h[0] = t3;
            reg_a1 += 2;
            if (reg_d0.h[0] != 0xFFFF) {
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                t1 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t1);
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
                t4 = *(u16 *)(reg_a6 + 4);
                *(u16 *)(reg_a0 + 4) = t4;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                func_002010A0();
                reg_d0.b[0] += 4;
                reg_d0.b[0] += *(u8 *)(reg_a4 + 0xD);
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                func_002011A0();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x18) = (u16) reg_d6.h[0];
                reg_d6.h[0] += 1;
                reg_a1 += 2;
                goto loop_6;
            }
            reg_d0.h[0] = 0x1E;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            t6 = *(u16 *)(reg_a6 + 4);
            *(u16 *)(reg_a0 + 4) = t6;
            reg_tmp.w = 0xF4000000;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
            *(s16 *)(reg_a0 + 0x1E) = 4;
            func_0018D660();
            v1 = (u8 *)((void *)0x80);
            *(u16 *)(reg_a4 + 4) = 0x80U;
            *(u8 *)(reg_a4 + 3) = 4U;
        }
        t9 = *(u8 *)(reg_a4 + 3);
        if (t9 == 2) {
            func_00125440();
            if (cond_flag == 0) {
                reg_a0 = (u8 *)D_0026C790;
                func_0013B2E0();
                func_00124E80();
                *(u8 *)(reg_a4 + 3) = 3U;
                *(u16 *)(reg_a4 + 0xA) = 1U;
            }
        }
        t10 = *(u8 *)(reg_a4 + 3);
        if (t10 == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
            *(u8 *)(reg_a4 + 0x11) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
                func_002011A0();
                reg_d1.b[0] = reg_d0.b[0];
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                func_002012F0();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
                reg_d2.h[0] += reg_d0.h[0];
                reg_tmp2.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = reg_tmp2.h[1];
                func_002012F0();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
                reg_d2.h[0] += reg_d0.h[0];
                reg_d2.h[0] -= 0x1000;
                reg_tmp2.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = reg_tmp2.h[1];
                reg_d3.h[0] = 8;
                reg_d0.h[0] = 0;
                func_0013AAB0();
                func_0018D560();
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
            *(u8 *)(reg_a4 + 0xF) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xF) = (u8) *(u8 *)(reg_a4 + 0xE);
                t11 = *(u8 *)(reg_a4 + 6);
                if (t11 != 2) {
                    *(u8 *)(reg_a4 + 6) = (u8) (t11 - 1);
                    *(u8 *)(reg_a4 + 0xD) += 1;
                }
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
                *(u8 *)(reg_a4 + 0x13) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                    reg_a0 = (u8 *)D_0026C6C0;
                    reg_a0 += *(u16 *)(reg_a4 + 0x14);
                    reg_a0 = *(u8 **)reg_a0;
                    jtbl_0028E3F4 = (Fn)(reg_a0);
                    jtbl_0028E3F4();
                    *(u16 *)(reg_a4 + 0x14) += 4;
                    *(u16 *)(reg_a4 + 0x14) &= 0x1F;
                }
                reg_a1 = (u8 *)(D_0026C6E0);
                reg_a1 += *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                t2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t2);
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
                t5 = *(u16 *)(reg_a6 + 4);
                *(u16 *)(reg_a0 + 4) = t5;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                func_002010A0();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d0.b[0] += 2;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
                reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 1);
                reg_d0.b[0] += reg_d1.b[0];
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                func_002011A0();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a4 + 8) += 0xA;
                if (*(u16 *)(reg_a4 + 8) == 0xA0) {
                    *(u16 *)(reg_a4 + 8) = 0U;
                    t8 = *(u8 *)(reg_a4 + 6);
                    if (t8 == 2) {
                        reg_d0.h[0] = 0x16;
                        func_00125410();
                        *(u8 *)(reg_a4 + 3) = 2U;
                    }
                }
            }
        }
        if (*(u8 *)(reg_a4 + 3) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
            *(u8 *)(reg_a4 + 0x13) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                reg_a0 = (u8 *)D_0026C6C0;
                reg_a0 += *(u16 *)(reg_a4 + 0x14);
                reg_a0 = *(u8 **)reg_a0;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
                *(u16 *)(reg_a4 + 0x14) += 4;
                *(u16 *)(reg_a4 + 0x14) &= 0x1F;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_a1 = (u8 *)(D_0026C6E0);
                reg_a1 += *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
                *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
                *(s16 *)(reg_a0 + 0x1E) = 8;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                *(u16 *)(reg_a4 + 8) += 0xA;
                if ((s16) *(u16 *)(reg_a4 + 8) >= 0xA0) {
                    *(u16 *)(reg_a4 + 8) = 0U;
                    *(u16 *)(reg_a4 + 0xA) -= 1;
                    if (*(u16 *)(reg_a4 + 0xA) == 0) {
                        *(u16 *)(reg_a4 + 6) = 0x2010;
                        *(u16 *)(reg_a4 + 0xE) = 0x1111;
                        *(u8 *)(reg_a4 + 3) = 1U;
                        *(u16 *)(reg_a4 + 0x12) = 0x101;
                        *(u16 *)(reg_a4 + 0x14) = 0U;
                    }
                }
            }
        }
    }
}

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */

void func_001C8780(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    reg_d0.w = 2;
    func_00124D90();
    reg_d0.w = 3;
    func_00124F50();
    *(s16 *)(reg_a4 + 4) = 0x40;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 0xA) = 2;
    func_001C87E0(0x40);
}

s32 func_00125120();
s32 func_001251C0();
s32 func_00125250();
s32 func_001CBBE0();
s32 func_00201160();
extern u16 D_0026C800[];
extern u16 D_0028E910;

void func_001C87E0() {
    u16 temp_v1;
    u16 temp_v1_2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1_3;
    u8 *temp_a1;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        temp_a1 = (u8 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
            if (*(u16 *)(reg_a4 + 4) == 0) {
                func_001CBBE0();
                if (D_0028E910 != 0) {
                    reg_d0.w = 0xD;
                    func_00125120();
                }
                reg_d0.w = 6;
                func_001251C0();
                *(u16 *)(reg_a0 + 4) = 0xA0U;
            }
        } else {
            reg_d0.w = 6;
            func_00125250();
            if (cond_flag == 0) {
                *(u8 *)(reg_a4 + 3) = 2U;
            }
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        reg_d0.w = 6;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 7;
            func_00125250();
            if (cond_flag == 0) {
                reg_d0.w = 8;
                func_00125250();
                if (cond_flag == 0) {
                    reg_d0.w = 9;
                    func_00125250();
                    if (cond_flag == 0) {
                        do {
                            func_00201160();
                            reg_d0.h[0] &= 3;
                        } while (*(u16 *)(reg_a4 + 6) == reg_d0.h[0]);
                        *(u16 *)(reg_a4 + 6) = (u16) reg_d0.h[0];
                        reg_a1 = (u8 *)(D_0026C800);
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_a1 += reg_d0.h[0];
                        reg_d0.h[0] = *(u16 *)reg_a1;
                        reg_a1 += 2;
                        func_001251C0();
                        *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)reg_a1;
                        reg_a1 += 2;
                        *(u16 *)(reg_a4 + 8) += 1;
                        if (*(u16 *)(reg_a4 + 8) == 3) {
                            *(u16 *)(reg_a4 + 8) = 0U;
                            *(u8 *)(reg_a4 + 3) = 3U;
                            *(u16 *)(reg_a4 + 4) = 0x40U;
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 3) {
        reg_d0.w = 6;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 7;
            func_00125250();
            if (cond_flag == 0) {
                reg_d0.w = 8;
                func_00125250();
                if (cond_flag == 0) {
                    reg_d0.w = 9;
                    func_00125250();
                    if (cond_flag == 0) {
                        temp_v1_2 = *(u16 *)(reg_a4 + 4);
                        if (temp_v1_2 != 0) {
                            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1_2 - 1);
                            if (*(u16 *)(reg_a4 + 4) == 0) {
                                *(s16 *)(reg_a4 + 0xC) = 0x20;
                                *(u16 *)(reg_a4 + 0xE) = 0x4040U;
                                *(u16 *)(reg_a4 + 0x10) = 4U;
                            }
                        } else {
                            reg_d0.w = 0xB;
                            func_00125250();
                            if (cond_flag == 0) {
                                reg_d0.w = 0xB;
                                func_001251C0();
                                *(u16 *)(reg_a0 + 0xC) = (u16) *(u16 *)(reg_a4 + 0xE);
                                temp_v1_3 = *(u8 *)(reg_a4 + 0xF);
                                if (temp_v1_3 != 0x10) {
                                    *(u8 *)(reg_a4 + 0xF) = (u8) (temp_v1_3 - 8);
                                    if ((s8) *(u8 *)(reg_a4 + 0xF) < 0x11) {
                                        *(u8 *)(reg_a4 + 0xF) = 0x10U;
                                    }
                                }
                                *(u16 *)(reg_a4 + 0x10) -= 1;
                                if (*(u16 *)(reg_a4 + 0x10) == 0) {
                                    *(u8 *)(reg_a4 + 3) = 2U;
                                } else {
                                    goto block_31;
                                }
                            } else {
block_31:
                                reg_d0.w = 0xA;
                                func_00125250();
                                if (cond_flag == 0) {
                                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
                                    *(u8 *)(reg_a4 + 0xD) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a4 + 0xD) = *(u8 *)(reg_a4 + 0xC);
                                        reg_d0.w = 0xA;
                                        func_001251C0();
                                        func_00201160();
                                        reg_d0.h[0] &= 3;
                                        reg_d0.h[0] += *(u16 *)(reg_a4 + 0xA);
                                        *(u16 *)(reg_a0 + 4) = (u16) reg_d0.h[0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 4) {
        reg_d0.w = 0xA;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            func_00125250();
            if (cond_flag == 0) {
                *(u8 *)(reg_a4 + 3) = 0U;
                *(u16 *)(reg_a4 + 4) = 0x40U;
            }
        }
    }
}


void func_001C8C10(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 0x60;
    *(s16 *)(reg_a4 + 6) = 0x6060;
    *(s16 *)(reg_a4 + 8) = 0x1E;
    *(s8 *)(reg_a4 + 0xB) = 1;
    *(s16 *)(reg_a4 + 0x10) = 0x3040;
    *(s16 *)(reg_a4 + 0x12) = 0x20;
    *(s16 *)(reg_a4 + 0xC) = 0x303;
    *(s16 *)(reg_a4 + 0x16) = 0x2024;
    *(s16 *)(reg_a4 + 0x1A) = 0x303;
    *(s8 *)(reg_a4 + 0x15) = 0;
    *(s8 *)(reg_a4 + 0x14) = 0;
    *(s8 *)(reg_a4 + 0x19) = 2;
    *(s8 *)(reg_a4 + 0x18) = 2;
    func_001C8CB0();
}

s32 func_00124F50();
s32 func_00125060();

void func_001C8CB0(arg1)
    s32 arg1;
{
    s32 var_a1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_a0_8;

    var_a1 = arg1;
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 2;
            func_00125120();
            reg_d0.w = 6;
            func_00124F50();
            var_a1 = 2;
            *(u8 *)(reg_a4 + 3) = 2U;
            *(u8 *)(reg_a4 + 2) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 2);
    if (temp_a0 == 1) {
        reg_d0.w = 1;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xE;
            func_00125250();
            if (cond_flag == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x17);
                *(u8 *)(reg_a4 + 0x17) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x17) = (u8) *(u8 *)(reg_a4 + 0x16);
                    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
                    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
                    if ((s32) reg_tmp.w < 0x7700) {
                        *(u8 *)(reg_a4 + 0x17) = 8U;
                    }
                    reg_d0.w = 0xE;
                    func_001251C0();
                    *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)(reg_a4 + 0x18);
                    *(u16 *)(reg_a0 + 8) = 0xFFFB;
                    *(s16 *)(reg_a0 + 0x16) = 4;
                    *(s16 *)(reg_a0 + 0x18) = 5;
                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x1B);
                    *(u8 *)(reg_a4 + 0x1B) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a4 + 0x1B) = (u8) *(u8 *)(reg_a4 + 0x1A);
                        *(u16 *)(reg_a0 + 8) = 0xFFFA;
                        *(s16 *)(reg_a0 + 0x16) = 0xB;
                        *(s16 *)(reg_a0 + 0x18) = 0xC;
                        *(s8 *)(reg_a0 + 7) = 4;
                        *(u8 *)(reg_a4 + 2) = 2U;
                    }
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 2);
    if (temp_a0_2 == 2) {
        reg_d0.w = 1;
        func_00125250();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_d0.w = 1;
                func_001251C0();
                *(u8 *)(reg_a0 + 5) = (u8) *(u8 *)(reg_a4 + 0xB);
                *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)(reg_a4 + 8);
                *(u8 *)(reg_a4 + 0xB) = (u8) -(s8) *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a4 + 2) = 1U;
                *(u16 *)(reg_a4 + 8) += 1;
                if ((s16) *(u16 *)(reg_a4 + 8) >= 0x28) {
                    *(u16 *)(reg_a4 + 8) = 0x28U;
                }
            }
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 2) {
        reg_d0.w = 0xA;
        func_00125060();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            func_00125250();
            if (cond_flag == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
                *(u8 *)(reg_a4 + 0x11) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
                    *(u8 *)(reg_a4 + 3) = 3U;
                    *(u16 *)(reg_a4 + 4) = 0x20U;
                    temp_a0_4 = *(u8 *)(reg_a4 + 0x15);
                    if (temp_a0_4 != 4) {
                        *(u8 *)(reg_a4 + 0x15) = (u8) (temp_a0_4 + 1);
                    }
                }
            }
        }
    }
    temp_a0_5 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_5 == 3) {
        reg_d0.w = 0xC;
        func_00125250();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 9;
                func_00124F50();
                *(u8 *)(reg_a4 + 3) = 4U;
            }
        }
    }
    temp_a0_6 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_6 == 4) {
        reg_d0.w = 9;
        func_00125060();
        if (cond_flag == 0) {
            reg_d0.w = 0xD;
            func_00125250();
            if (cond_flag == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
                *(u8 *)(reg_a4 + 0x13) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                    reg_d0.w = 0xD;
                    func_001251C0();
                    *(u16 *)(reg_a0 + 6) = 4U;
                    *(u8 *)(reg_a4 + 0xD) -= 1;
                    if (*(u8 *)(reg_a4 + 0xD) == 0) {
                        *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
                        *(u8 *)(reg_a4 + 0x12) -= 4;
                        if ((s8) *(u8 *)(reg_a4 + 0x12) < 0x11) {
                            *(u8 *)(reg_a4 + 0x12) = 0x10U;
                        }
                        *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                        *(u8 *)(reg_a4 + 3) = 5U;
                    }
                }
            }
        }
    }
    temp_a0_7 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_7 == 5) {
        reg_d0.w = 0xD;
        func_00125250();
        if (cond_flag == 0) {
            reg_d0.w = 0xA;
            func_00124F50();
            *(u8 *)(reg_a4 + 3) = 2U;
            temp_a0_8 = *(u8 *)(reg_a4 + 0x14);
            if (temp_a0_8 != 4) {
                *(u8 *)(reg_a4 + 0x14) = (u8) (temp_a0_8 + 1);
            }
        }
    }
}


void func_001C91A0(void) {
    reg_a4[3] = 0;
    *(s16 *)(reg_a4 + 4) = 0x60;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 8) = 8;
    func_001C91D0(0x60);
}

s32 func_00202140();
s32 func_00202500();
extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];

void func_001C91D0() {
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u8 temp_a0_3;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            temp_a1 = *(u16 *)(reg_a6 + 4);
            reg_d1.h[0] = temp_a1;
            reg_d0.h[0] += D_0026C250[0];
            reg_d1.h[0] += D_0026C252[0];
            func_00202140();
            *(u8 *)(reg_a4 + 0xB) = (u8) reg_d1.b[0];
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            temp_a1_2 = *(u16 *)(reg_a6 + 4);
            reg_d1.h[0] = temp_a1_2;
            reg_d0.h[0] += D_0026C260[0];
            reg_d1.h[0] += D_0026C262[0];
            func_00202140();
            *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 1) {
        reg_d0.w = 8;
        func_00125060();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_d0.w = 8;
                func_00124F50();
                reg_d7.w = 1;
                do {
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                    temp_a1_3 = *(u16 *)(reg_a6 + 4);
                    reg_d1.h[0] = temp_a1_3;
                    reg_d0.h[0] += D_0026C250[0];
                    reg_d1.h[0] += D_0026C252[0];
                    func_00202140();
                    reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
                    func_00202500();
                    *(u8 *)(reg_a4 + 0xB) = (u8) reg_d1.b[0];
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                    temp_a1_4 = *(u16 *)(reg_a6 + 4);
                    reg_d1.h[0] = temp_a1_4;
                    reg_d0.h[0] += D_0026C260[0];
                    reg_d1.h[0] += D_0026C262[0];
                    func_00202140();
                    reg_d0.b[0] = *(u8 *)(reg_a4 + 0xA);
                    func_00202500();
                    *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.w = 0xD;
                func_001251C0();
                *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a4 + 0xA);
                *(u16 *)(reg_a4 + 8) -= 1;
                if (*(u16 *)(reg_a4 + 8) == 0) {
                    *(s16 *)reg_a4 = 0;
                    reg_d0.w = 4;
                    func_00124B20();
                }
            }
        }
    }
}

s32 func_00124D90();                            /* extern */

void func_001C9440(void) {
    reg_d0.w = 4;
    func_00124D90();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x20;
}

s32 func_00124D80();

void func_001C9480() {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 5) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 3;
            func_00124B20();
        }
    }
}

extern u8 D_0026C810[];

void func_001C9510(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 4) = 0x20;
    reg_tmp.w = (u32) D_0026C810;
    *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a4 + 0xC) = 1;
    func_001C9570();
}


void func_001C9570(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if ((temp_a0 == 1) && (func_00124D80(temp_a0), (reg_d0.h[0] == 5))) {
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 8);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
        reg_a1 = (u8 *)(reg_tmp.w);
        temp_a0_2 = *(u16 *)(reg_a4 + 6);
        reg_a1 += temp_a0_2;
        if (*(s16 *)reg_a1 != -1) {
            func_001C9640();
            return;
        }
        reg_d0.w = 4;
        func_00124B20();
        *(s16 *)reg_a4 = 0;
    }
}

s32 func_00124D90();
s32 func_00171400();

void func_001C9640(void) {
    reg_d0.w = 6;
    func_00124D90();
    *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)(reg_a1 + 2);
    *(u16 *)(reg_a4 + 6) += 4;
    func_00171400();
    if (*(u8 *)(reg_a4 + 2) != 0) {
        reg_d0.w = 2;
        func_001251C0();
        *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)(reg_a4 + 0xC);
        *(u16 *)(reg_a4 + 0xC) *= 0xFFFF;
    }
    *(u8 *)(reg_a4 + 2) = 1U;
}

s32 func_00124F50(s32, s32, s32);   /* extern */
s32 func_001251C0();                            /* extern */

void func_001C96E0(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x10;
    *(s16 *)(reg_a4 + 6) = 0x200A;
    *(s16 *)(reg_a4 + 0xC) = 0x101;
    reg_d0.w = 0xA;
    func_00124F50(0x101, 0x200A, 0x10);
    reg_d0.w = 0xF;
    func_001251C0();
    func_001C9740();
}

void func_001C9740(void) {
}

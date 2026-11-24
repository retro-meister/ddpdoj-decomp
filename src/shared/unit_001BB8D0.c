#include "common.h"

void func_001BC160(void);
void func_001BC230(void);
void func_001BC2E0(void);
void func_001BC430(void);
void func_001BC440(void);

void func_001BB8D0(void) {

}

extern s8 D_0028E408;

s32 func_00124B20();
s32 func_00124BB0();
s32 func_0016A9B0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002016D0();
extern u8 D_0028E290;
extern s32 D_0028E638;
extern u16 D_0028E8B8;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BB8E0(void) {
    s32 func_00203400();
    u32 hp;
    u8 *v1;
    u8 *v2;
    u8 *v3;
    u8 *v4;

    v2 = (u8 *)(reg_a6);
    if ((*(u16 *)((u8 *)(v2) + (0xE6))) == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(v2) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(v2) + (1))) &= reg_d0.b[0];
            *(u16 *)(reg_a6 + 0xEA) = (u16) reg_d1.h[0];
            func_001A9000();
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
            if (reg_d0.b[0] == 0x19) {
                *(u8 *)(reg_a6 + 0x1C) = 0x13U;
                *(u8 *)(reg_a6 + 0xBC) = 0x16U;
            }
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
            reg_d0.b[0] ^= 0xC;
            *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBC);
            reg_d0.b[0] ^= 9;
            *(u8 *)(reg_a6 + 0xBC) = (u8) reg_d0.b[0];
            v1 = (u8 *)(reg_a6);
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= *(u16 *)(reg_a6 + 0x18);
            hp = *(u16 *)(reg_a6 + 0x18);
            if (*(u16 *)(reg_a6 + 0xE8) == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
                if (D_0028E290 == 2) {
                    if ((s32) hp > 0x7FFF) {
                        reg_tmp.w += hp - 0x7FFF;
                        if (reg_tmp.w >= 0x16C00) {
                            reg_tmp.w = 0x16C00;
                        }
                    } else {
                        reg_tmp.w -= reg_d2.w;
                    }
                } else {
                    reg_tmp.w -= reg_d2.w;
                }
                *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
                *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
            }
            reg_d0.h[0] = 0x7FFF;
            *(u16 *)(reg_a6 + 0x18) = (u16) reg_d0.h[0];
        } else {
            (*(u8 *)((u8 *)(v2) + (0x1C))) = 0x13U;
            *(u8 *)(reg_a6 + 0xBC) = 0x16U;
            v1 = (u8 *)(reg_a5);
            reg_d2.w = 0x6D33;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(v1) + (0x16)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(v1) + (0x18)));
            if (((u32) reg_tmp.w <= (u32) reg_d2.w) && (D_0028E8B8 == 0)) {
                *(u8 *)(reg_a6 + 0x1C) = 0x19U;
                *(u8 *)(reg_a6 + 0xBC) = 0x19U;
            }
        }
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
        if ((s32) reg_tmp.w < 0) {
            func_00203400();
            if (reg_d0.h[0] == 0) {
                reg_tmp.w = 0x200;
                *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
                goto next_1;
            }
            D_0028E638 = 0x30000;
            func_001BC160();
            return;
        }
next_1:
        if (*(u16 *)(reg_a6 + 0x20) != 0x8000) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x21);
            v3 = (u8 *)(reg_a6 + 0x21);
            if (reg_d1.b[0] != 0) {
                reg_d0.b[0] = 0xA3;
                *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
                *(u16 *)(reg_a6 + 0xEA) = (u16) reg_d1.h[0];
                func_001A9000();
                reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3C);
                if (reg_d0.b[0] == 0x19) {
                    *(u8 *)(reg_a6 + 0x3C) = 0x15U;
                }
                reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3C);
                reg_d0.b[0] ^= 0xA;
                *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
                reg_d2.w = 0x7FFF;
                reg_d2.h[0] -= *(u16 *)(reg_a6 + 0x38);
                hp = *(u16 *)(reg_a6 + 0x38);
                if (*(u16 *)(reg_a6 + 0xE8) == 0) {
                    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                    if (D_0028E290 == 2) {
                        if ((s32) hp > 0x7FFF) {
                            reg_tmp.w += hp - 0x7FFF;
                            if (reg_tmp.w >= 0x9000) {
                                reg_tmp.w = 0x9000;
                            }
                        } else {
                            reg_tmp.w -= reg_d2.w;
                        }
                    } else {
                        reg_tmp.w -= reg_d2.w;
                    }
                    *(u16 *)(reg_a5 + 0x1A) = reg_tmp.h[1];
                    *(u16 *)(reg_a5 + 0x1C) = reg_tmp.h[0];
                }
                reg_d0.h[0] = 0x7FFF;
                *(u16 *)(reg_a6 + 0x38) = (u16) reg_d0.h[0];
            } else {
                *(u8 *)(reg_a6 + 0x3C) = 0x15U;
                reg_d2.w = 0x2B33;
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                if (((u32) reg_tmp.w <= (u32) reg_d2.w) && (D_0028E8B8 == 0)) {
                    *(u8 *)(reg_a6 + 0x3C) = 0x19U;
                }
            }
            if (*(u8 *)(reg_a6 + 0x7E) == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                if ((s32) reg_tmp.w < 0) {
                    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xEA);
                    reg_d0.w = 0x1000;
                    func_001A91A0();
                    reg_d0.w = 0xC;
                    if (!(reg_d1.w & 0x10)) {
                        reg_d0.w = 0x14;
                    }
                    reg_a6 += 0x20;
                    func_0016A9B0();
                    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
                    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
                    reg_a6 = (void *) reg_tmp.w;
                    func_002016D0();
                    *(s16 *)(reg_a5 + 0x24) = 0x6E;
                    if (*(u16 *)(reg_a6 + 0x114) != 0) {
                        reg_a6 += 0x60;
                        func_0016A9B0();
                        reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
                        reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
                        reg_a6 = (void *) reg_tmp.w;
                    }
                    goto next_2;
                }
                goto next_3;
            }
next_2:
            func_001BC230();
            return;
        }
next_3:
        if (*(u16 *)(reg_a6 + 0x60) != 0x8000) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x61);
            v4 = (u8 *)(reg_a6 + 0x61);
            if (reg_d1.b[0] != 0) {
                reg_d0.b[0] = 0xA3;
                *(u8 *)(reg_a6 + 0x61) &= reg_d0.b[0];
                *(u16 *)(reg_a6 + 0xEA) = (u16) reg_d1.h[0];
                func_001A9000();
                reg_d0.b[0] = *(u8 *)(reg_a6 + 0x7C);
                if (reg_d0.b[0] == 0x19) {
                    *(u8 *)(reg_a6 + 0x7C) = 0x15U;
                }
                reg_d0.b[0] = *(u8 *)(reg_a6 + 0x7C);
                reg_d0.b[0] ^= 0xA;
                *(u8 *)(reg_a6 + 0x7C) = (u8) reg_d0.b[0];
                reg_d2.w = 0x7FFF;
                reg_d2.h[0] -= *(u16 *)(reg_a6 + 0x78);
                hp = *(u16 *)(reg_a6 + 0x78);
                if (*(u16 *)(reg_a6 + 0xE8) == 0) {
                    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1E);
                    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x20);
                    if (D_0028E290 == 2) {
                        if ((s32) hp > 0x7FFF) {
                            reg_tmp.w += hp - 0x7FFF;
                            if (reg_tmp.w >= 0x9000) {
                                reg_tmp.w = 0x9000;
                            }
                        } else {
                            reg_tmp.w -= reg_d2.w;
                        }
                    } else {
                        reg_tmp.w -= reg_d2.w;
                    }
                    *(u16 *)(reg_a5 + 0x1E) = reg_tmp.h[1];
                    *(u16 *)(reg_a5 + 0x20) = reg_tmp.h[0];
                }
                reg_d0.h[0] = 0x7FFF;
                *(u16 *)(reg_a6 + 0x78) = (u16) reg_d0.h[0];
            } else {
                *(u8 *)(reg_a6 + 0x7C) = 0x15U;
                reg_d2.w = 0x2B33;
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1E);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x20);
                if (((u32) reg_tmp.w <= (u32) reg_d2.w) && (D_0028E8B8 == 0)) {
                    *(u8 *)(reg_a6 + 0x7C) = 0x19U;
                }
            }
            if (*(u8 *)(reg_a6 + 0x3E) == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1E);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x20);
                if ((s32) reg_tmp.w < 0) {
                    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xEA);
                    reg_d0.w = 0x1000;
                    func_001A91A0();
                    reg_d0.w = 0xC;
                    if (!(reg_d1.w & 0x10)) {
                        reg_d0.w = 0x14;
                    }
                    reg_a6 += 0x60;
                    func_0016A9B0();
                    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
                    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
                    reg_a6 = (void *) reg_tmp.w;
                    func_002016D0();
                    *(s16 *)(reg_a5 + 0x24) = 0x6E;
                    if (*(u16 *)(reg_a6 + 0x114) != 0) {
                        reg_a6 += 0x20;
                        func_0016A9B0();
                        reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
                        reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
                        reg_a6 = (void *) reg_tmp.w;
                    }
                    goto next_4;
                }
                goto next_5;
            }
next_4:
            func_001BC2E0();
            return;
        }
next_5:
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
        reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
        if (reg_d0.b[0] == 2) {
            reg_d0.w = 5;
            func_00124BB0();
            if (D_0028E408 == 0) {
                reg_d0.w = 5;
                func_00124B20();
            }
        }
        if (*(u8 *)(reg_a6 + 0x3E) != 0) {
            reg_d0.w = 4;
            func_00124BB0();
            if (D_0028E408 == 0) {
                reg_d0.w = 4;
                func_00124B20();
            }
        }
        if (*(u8 *)(reg_a6 + 0x7E) != 0) {
            reg_d0.w = 4;
            func_00124BB0();
            if (D_0028E408 == 0) {
                reg_d0.w = 4;
                func_00124B20();
            }
        }
        func_001BC440();
    }
}

s32 func_00124D10();
s32 func_00124D90();
s32 func_00124F50();
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_00203460();
s32 func_0020ED10();
extern u8 D_0028E855;

void func_001BC160() {
    D_0028E855 |= 0x40;
    D_0028E855 |= 0x80;
    func_0020ED10();
    func_0013F3C0();
    func_00203460();
    func_001BC430();
    func_001BC230();
    func_001BC2E0();
    func_001253B0();
    func_00124D10();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x13;
    (*(s8 *)((u8 *)(reg_a6) + (0xBC))) = 0x16;
    reg_d0.w = 1;
    func_00124D90();
    reg_d0.w = 6;
    func_00124F50();
}

s32 func_00125120();

void func_001BC230(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        reg_tmp.w = -1U;
        (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) reg_tmp.h[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
        (*(s8 *)((u8 *)(reg_a6) + (0x3C))) = 0x15;
        reg_d0.w = 0;
        func_00125120();
        reg_d0.w = 2;
        func_00125120();
        reg_d0.w = 8;
        func_00125120();
        reg_d0.w = 0xA;
        func_00125120();
        reg_d0.w = 0xC;
        func_00125120();
        reg_d0.w = 4;
        func_00124F50();
        return;
    }
}

void func_001BC2E0(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) {
        reg_tmp.w = -1U;
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) reg_tmp.h[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x7E))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x60))) = 0x8000;
        (*(s8 *)((u8 *)(reg_a6) + (0x7C))) = 0x15;
        reg_d0.w = 1;
        func_00125120();
        reg_d0.w = 3;
        func_00125120();
        reg_d0.w = 9;
        func_00125120();
        reg_d0.w = 0xB;
        func_00125120();
        reg_d0.w = 0xD;
        func_00125120();
        reg_d0.w = 5;
        func_00124F50();
        return;
    }
}

void func_001BC390(void) {
    *(s16 *)((u8 *)reg_a6 + 0xE8) = 1;
}

void func_001BC3A0(void) {
    *(s16 *)(reg_a6 + 0xE8) = 0;
}

void func_001BC3B0(void) {
    reg_d0.h[0] = 0xA001;
    (*(u16 *)((u8 *)(reg_a6) + (0))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x60))) |= reg_d0.h[0];
}

extern u16 *reg_a6_as_u16_p;

void func_001BC400(void) {
    reg_d0.h[0] = 0x8000;
    reg_a6_as_u16_p[0x0 / 2] = (u16) reg_d0.h[0];
    reg_a6_as_u16_p[0x20 / 2] = (u16) reg_d0.h[0];
    reg_a6_as_u16_p[0x60 / 2] = (u16) reg_d0.h[0];
}

void func_001BC430(void) {
    *(s16 *)(reg_a6 + 0xE6) = 1;
}

extern u16 D_0028E8A0;

void func_001BC440(void) {
    void func_00203400(void);
#ifdef DEATH_LABEL
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x22))) == 0)) {
#else
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x22))) -= 1, (*(u16 *)((u8 *)(reg_a5) + (0x22))) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x22))) = 0x78U;
            return;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0xEA))) = 0;
        func_001BC160();
    }
}

#include "common.h"
#include "sdk/ps2sdk.h"

void func_0018CE60(s32 arg0);
void func_0018CF30(s32 arg0);
void func_0018D9F0(void);
void func_0018DA30(void);
void func_0018DA50(void);
void func_0018DEF0(s32 arg0, s32 arg1);

extern s32 D_0029CCE0_as_s32_a[];
extern s32 D_0029CD04[];

s32 func_0018C580(void) {
    s32 temp_v0;
    s32 var_v1;

    sceSifInitRpc(0);
loop_1:
    if (sceSifBindRpc((sceSifClientData *)D_0029CCE0_as_s32_a, 0x12345, 0) < 0) {
loop_2:
        goto loop_2;
    }
    var_v1 = 0x2710;
    do {
        temp_v0 = var_v1;
        var_v1 -= 1;
    } while (temp_v0 != 0);
    if (D_0029CD04[0] != 0) {
        return 1;
    }
    goto loop_1;
}

extern s32 D_0029CD40_as_s32_a[];
extern s32 D_0029CD44[];

s32 func_0018C600(s32 arg0, s32 arg1, s32 arg2) {
    s32 t = arg0 & 0xFFF0;

    if (t == 0x8020 || t == 0x550 || t == 0x560) {
        sceSifCallRpc((sceSifClientData *)D_0029CCE0_as_s32_a, arg0, 0, (void *)arg1, 0x40, D_0029CD40_as_s32_a, 0x40, 0, 0);
    } else {
        D_0029CD40_as_s32_a[0] = arg1;
        D_0029CD44[0] = arg2;
        sceSifCallRpc((sceSifClientData *)D_0029CCE0_as_s32_a, arg0, 0, D_0029CD40_as_s32_a, 0x10, D_0029CD40_as_s32_a, 0x40, 0, 0);
    }
    return D_0029CD40_as_s32_a[0];
}

extern s32 D_0029CD48[];


s32 func_0018C6C0(s32 command, s32 firstWord, s32 secondWord, s32 thirdWord)
{
    D_0029CD40_as_s32_a[0] = firstWord;
    D_0029CD44[0] = secondWord;
    D_0029CD48[0] = thirdWord;

    sceSifCallRpc((sceSifClientData *)D_0029CCE0_as_s32_a, command, 0, D_0029CD40_as_s32_a, 0x10,
                  D_0029CD40_as_s32_a, 0x40, 0, 0);

    return D_0029CD40_as_s32_a[0];
}

extern u8 D_0025BAC0[];
extern u8 D_0025BB00[];
extern u8 D_0025BB40[];
extern u8 D_0025BB80[];
extern u8 D_0025BBC0[];
extern u8 D_0025BC00[];
extern u8 D_0025BC40[];
extern s32 D_0028DF90;
extern s32 D_0029CA10_as_s32_a[];
extern s32 D_0029CA14_as_s32_a[];
extern s32 D_0029CA18_as_s32_a[];
extern s32 D_0029CA34[];
extern s32 D_0029CA38[];
extern s32 D_0029CA3C[];
extern s32 D_0029CA40[];
extern s32 D_0029CA5C[];

void func_0018C730(void) {
    func_0018C580();
    D_0029CA18_as_s32_a[0] = 0;
    D_0029CA10_as_s32_a[0] = 1;
    D_0028DF90 = 0;
    D_0029CA38[0] = 1;
    D_0029CA14_as_s32_a[0] = 1;
    D_0029CA3C[0] = 1;
    D_0029CA40[0] = 0;
    D_0029CA34[0] = 0;
    D_0029CA5C[0] = 0;
    func_0018C600(0xD0, 0, 0);
    func_0018C600(0x540, 0, 0);
    func_0018C600(0xA0, 0x3FFF3FFF, 0);
    func_0018C600(0xA1, 0x3FFF3FFF, 0);
    func_0018C600(0x80, 0x3FFF3FFF, 0);
    func_0018C600(0x81, 0x3FFF3FFF, 0);
    func_0018C600(0x550, (s32)((s32) D_0025BAC0), 0);
    func_0018C600(0x560, (s32)((s32) D_0025BB00), 0);
    func_0018C600(0x560, (s32)((s32) D_0025BB40), 0);
    func_0018C600(0x560, (s32)((s32) D_0025BB80), 0);
    func_0018C600(0x560, (s32)((s32) D_0025BBC0), 0);
    func_0018C600(0x560, (s32)((s32) D_0025BC00), 0);
    func_0018C600(0x560, (s32)((s32) D_0025BC40), 0);
}

s32 func_0018E300();                            /* extern */
s32 func_0018E390();                            /* extern */
s32 func_0018E420();                            /* extern */
s32 func_0018E4B0();                            /* extern */

void func_0018C890(void) {
    func_0018E300();
    func_0018E390();
    func_0018E420();
    func_0018E4B0();
}

extern u8 D_0029CA10[];
extern u8 D_0029CA14[];
extern u8 D_0029CA18[];

void func_0018C8D0(s32 arg0) {
    s32 off;
    s32 *p1;
    s32 *p2;

    off = arg0 * 0x28;
    p1 = (s32 *)(D_0029CA10 + off);
    if (*p1 == 0) {
        p2 = (s32 *)(D_0029CA14 + off);
        if (*p2 == 0) {
            func_0018C600(arg0 | 0x110, 0, 0);
        }
        func_0018C600(arg0 | 0x30, 0, 0);
        func_0018C600(arg0 | 0x10, 0, 0);
        *p1 = 1;
        *p2 = 1;
        *(s32 *)(D_0029CA18 + off) = 0;
    }
}

extern u8 D_00277F78[];

void func_0018C990(void) {
    s32 v[2];
    s32 i;
    s32 o4;
    s32 o28;
    u8 *p;
    s32 *f;
    s32 t;

    v[0] = func_0018C600(0x80B0, 0, 0) & ~0xFFF;
    v[1] = func_0018C600(0x80B1, 0, 0) & ~0xFFF;
    func_0018C600(0x520, 0, 0);
    i = 0;
    o4 = 0;
    o28 = 0;
    do {
        if (*(s32 *)((u8 *)v + o4) & 0x1000) {
            printf((const char *)D_00277F78);
            p = D_0029CA10 + o28;
            f = (s32 *)(p + 8);
            t = *f;
            if (t == 2) {
                func_0018C600(i | 0x60, 0, 0);
                *(s32 *)(p + 4) = 1;
                *f = 0;
                *(s32 *)(p + 0x24) = 0;
            } else {
                if (t == 3) {
                    *(s32 *)(p + 0xC) = *(s32 *)(p + 0x14);
                }
                *f = 4;
                *(s32 *)(p + 0x24) = 1;
                func_0018CE60(i);
            }
        }
        i += 1;
        o4 += 4;
        o28 += 0x28;
    } while (i < 2);
}

extern u8 D_00277F88[];

void func_0018CAD0(void) {
    s32 i;
    s32 off;
    s32 *f;
    u8 *p;

    off = 0;
    i = 0;
    do {
        p = D_0029CA10 + off;
        f = (s32 *)(p + 0x24);
        if (*f != 0) {
            printf((const char *)D_00277F88);
            *f = 0;
            f = (s32 *)(p + 8);
            if (*f == 4) {
                *f = 3;
                func_0018CF30(i);
            } else {
                func_0018C600(i | 0xE0, 0, 0);
                func_0018C600(i | 0x50, 0, 0);
                *(s32 *)(p + 4) = 0;
                *f = 3;
                func_0018CF30(i);
            }
        }
        i += 1;
        off += 0x28;
    } while (i < 2);
}

void func_0018CBB0(void) {
    s32 v[2];
    s32 i;

    v[0] = func_0018C600(0x80B0, 0, 0) & ~0xFFF;
    v[1] = func_0018C600(0x80B1, 0, 0) & ~0xFFF;
    func_0018C600(0x520, 0, 0);
    for (i = 0; i < 2; i++) {
        if (v[i] & 0x1000) {
            func_0018C600(i | 0x60, 0, 0);
            *(s32 *)(D_0029CA10 + i * 0x28 + 4) = 1;
            *(s32 *)(D_0029CA10 + i * 0x28 + 8) = 0;
        }
    }
    D_0029CA18_as_s32_a[0] = 0;
    D_0029CA14_as_s32_a[0] = 1;
    D_0029CA3C[0] = 1;
    D_0029CA40[0] = 0;
}

void func_0018CCA0(s32 arg0) {
    u32 v = func_0018C600(arg0 | 0x80B0, 0, 0) & ~0xFFF; if (v & 0x1000) {
        func_0018C600(arg0 | 0x60, 0, 0);
        *(s32 *)(D_0029CA14 + arg0 * 0x28) = 1;
        *(s32 *)(D_0029CA18 + arg0 * 0x28) = 0;
    }
}

#pragma push
#pragma divbyzerocheck on
extern u8 D_0029CA1C[];
extern u8 D_0029CA20[];
extern u8 D_0029CA24[];
extern u8 D_0029CA28[];
extern u8 D_0029CA2C[];
extern u8 D_0029CA30[];

void func_0018CD20(s32 arg0) {
    s32 off;
    s32 *p;
    s32 *q;
    s32 *r;
    s32 n;
    s32 v;

    off = arg0 * 0x28;
    if (*(s32 *)(D_0029CA10 + off) == 1) return;
    if (*(s32 *)(D_0029CA14 + off) == 1) return;
    v = func_0018C600(arg0 | 0x80B0, 0, 0) & ~0xFFF;
    if (!(v & 0x1000)) return;
    p = (s32 *)(D_0029CA1C + off);
    *(s32 *)(D_0029CA20 + off) = *p;
    *(s32 *)(D_0029CA24 + off) = 0;
    *(q = (s32 *)(D_0029CA30 + off)) = 0x78;
    n = *p;
    if (n == 0) {
        n = 1;
    }
    v = n * 100;
    *(s32 *)(D_0029CA28 + off) = v;
    *(s32 *)(D_0029CA2C + off) = v / *q;
    r = (s32 *)(D_0029CA18 + off);
    if (*r != 4) {
        *r = 2;
    }
}
#pragma pop

#pragma push
#pragma divbyzerocheck on
void func_0018CE60(s32 arg0) {
    s32 off;
    s32 *p;
    s32 *q;
    s32 n;
    s32 v;

    off = arg0 * 0x28;
    p = (s32 *)(D_0029CA1C + off);
    *(s32 *)(D_0029CA20 + off) = *p;
    if (*p == 0) {
        *(s32 *)(D_0029CA24 + off) = 0;
    } else {
        *(s32 *)(D_0029CA24 + off) = 0;
    }
    *(q = (s32 *)(D_0029CA30 + off)) = 0x1E;
    n = *p;
    if (n == 0) {
        n = 1;
    }
    v = n * 100;
    *(s32 *)(D_0029CA28 + off) = v;
    *(s32 *)(D_0029CA2C + off) = v / *q;
}
#pragma pop

#pragma push
#pragma divbyzerocheck on
void func_0018CF30(s32 arg0) {
    s32 off;
    s32 d;
    s32 *q;
    s32 base;

    off = arg0 * 0x28;
    *(s32 *)(D_0029CA24 + off) = *(s32 *)(D_0029CA20 + off);
    *(q = (s32 *)(D_0029CA30 + off)) = 0x1E;
    base = *(s32 *)(D_0029CA1C + off);
    d = *(s32 *)(D_0029CA24 + off) - base;
    if (d < 0) {
        d = -d;
    }
    if (d == 0) {
        d = 1;
    }
    *(s32 *)(D_0029CA28 + off) = base * 100;
    *(s32 *)(D_0029CA2C + off) = d * 100 / *q;
    *(s32 *)(D_0029CA18 + off) = 3;
}
#pragma pop

extern s32 D_0028DF8C;
extern u16 D_0028E3C0;

void func_0018D010(s32 arg0) {
    s32 var_a1;
    s32 var_a2;

    var_a1 = arg0;
    if (D_0028E3C0 == 0) {
        if (arg0 != 0) {
            var_a1 -= 1;
        }
        var_a2 = D_0028DF8C;
        var_a2 -= 0x1E;
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        if ((arg0 == 2) || (arg0 == 0xA) || (arg0 == 0x12) || (arg0 == 0x2D) || (arg0 == 0x32) || (arg0 == 0x25)) {
            var_a1 |= 0x80;
        }
        D_0028DF90 = func_0018C600(0x500, (s32)var_a1, (s32)((s32)var_a2));
    }
}

extern s32 D_0028DF88;

void func_0018D0A0(s32 arg0) {
    s32 a1;
    s32 a2;
    s32 a3;

    if (D_0028E3C0 == 0) {
        a1 = arg0;
        if (arg0 != 0) {
            a1 -= 1;
        }
        a2 = D_0028DF8C;
        a2 -= 0x1E;
        a3 = D_0028DF88;
        if (a2 < 0) {
            a2 = 0;
        }
        if ((arg0 == 2) || (arg0 == 0xA) || (arg0 == 0x12) || (arg0 == 0x2D) || (arg0 == 0x32) || (arg0 == 0x25)) {
            a1 |= 0x80;
        }
        D_0028DF90 = func_0018C6C0(0x580, a1, a2, a3);
    }
}


void func_0018D130(void) {
    func_0018C600(0x510, (s32)D_0028DF88, 0);
}


void func_0018D140(void) {
    func_0018C600(0x520, 0, 0);
}

extern u8 D_0028E2E0;

void func_0018D150(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(0, 1);
        return;
    }
    func_0018DEF0(0xD, 1);
}

void func_0018D190(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(1, 1);
        return;
    }
    func_0018DEF0(0xE, 1);
}

void func_0018D1D0(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(2, 1);
        return;
    }
    func_0018DEF0(0xF, 1);
}

void func_0018D210(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(3, 1);
        return;
    }
    func_0018DEF0(0x10, 1);
}

void func_0018D250(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(4, 1);
        return;
    }
    func_0018DEF0(0x11, 1);
}

void func_0018D290(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(5, 1);
        return;
    }
    func_0018DEF0(0x12, 1);
}

void func_0018D2D0(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(6, 1);
        return;
    }
    func_0018DEF0(0x13, 1);
}

void func_0018D310(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(7, 1);
        return;
    }
    func_0018DEF0(0x14, 1);
}

void func_0018D350(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(8, 1);
        return;
    }
    func_0018DEF0(0x15, 1);
}

void func_0018D390(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(9, 0);
        return;
    }
    func_0018DEF0(0x16, 0);
}

void func_0018D3D0(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(0xA, 1);
        return;
    }
    func_0018DEF0(0x17, 1);
}

void func_0018D410(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(0xB, 0);
        return;
    }
    func_0018DEF0(0x18, 0);
}

void func_0018D450(void) {
    if (D_0028E2E0 == 0) {
        func_0018DEF0(0xC, 1);
        return;
    }
    func_0018DEF0(0x19, 1);
}


void func_0018D490(void) {
    D_0028DF8C = 0x5D;
    D_0028DF88 = 0xA;
    func_0018D0A0(8);
}


void func_0018D4B0(void) {
    func_0018DA30();
}


void func_0018D4C0(void) {
    func_0018D9F0();
}


void func_0018D4D0(void) {
    func_0018DA50();
}


void func_0018D4E0(void) {
    D_0028DF8C = 0xB4;
    D_0028DF88 = 0;
    func_0018D0A0(6);
}

void func_0018D500(void) {
    D_0028DF8C = 0x9E;
    D_0028DF88 = 0;
    func_0018D0A0(4);
}


void func_0018D520(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D0A0(1);
}

void func_0018D540(void) {
    D_0028DF8C = 0x8A;
    D_0028DF88 = 0;
    func_0018D0A0(0xF);
}


void func_0018D560(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D0A0(0xC);
}


void func_0018D580(void) {
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(9);
}


void func_0018D5A0(void) {
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2A);
}

void func_0018D5C0(void) {
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2B);
}


void func_0018D5E0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D010(0x26);
}



void func_0018D600(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D010(0x27);
}

void func_0018D620(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D010(0x28);
}

void func_0018D640(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0;
    func_0018D010(0x29);
}

s32 vibration_start_pad1(s32, s32);            /* extern */
s32 vibration_start_pad2(s32, s32);            /* extern */
extern s8 D_0028E310_as_s8;

void func_0018D660(void) {
    D_0028E310_as_s8 = 0x3C;
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2A);
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2B);
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2A);
    vibration_start_pad1(0xC8, 0x50);
    vibration_start_pad2(0xC8, 0x50);
}


void func_0018D6D0(void) {
    D_0028DF8C = 0xB2;
    D_0028DF88 = 1;
    func_0018D010(0x17);
}

void func_0018D6F0(void) {
    D_0028DF8C = 0x5D;
    D_0028DF88 = 2;
    func_0018D010(8);
}

void func_0018D710(void) {
    D_0028DF8C = 0x5D;
    D_0028DF88 = 2;
    func_0018D010(0x11);
}

void func_0018D730(void) {
    D_0028DF8C = 0x5D;
    D_0028DF88 = 2;
    func_0018D010(0x16);
}

void func_0018D750(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 3;
    func_0018D0A0(2);
}

void func_0018D770(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 3;
    func_0018D0A0(0xA);
}


void func_0018D790(void) {
    D_0028DF8C = 0xE6;
    D_0028DF88 = 3;
    func_0018D0A0(0x12);
    vibration_start_pad1(0x8C, 0x4B0);
}

void func_0018D7D0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 4;
    func_0018D0A0(2);
}

void func_0018D7F0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 4;
    func_0018D0A0(0xA);
}

void func_0018D810(void) {
    D_0028DF8C = 0xFA;
    D_0028DF88 = 4;
    func_0018D0A0(0x12);
    vibration_start_pad2(0x8C, 0x4B0);
}


void func_0018D850(void) {
    D_0028DF8C = 0xE4;
    D_0028DF88 = 5;
    func_0018D010(3);
}


void func_0018D870(void) {
    D_0028DF8C = 0xE4;
    D_0028DF88 = 5;
    func_0018D010(0xB);
}

void func_0018D890(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 5;
    func_0018D010(5);
}

void func_0018D8B0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 5;
    func_0018D010(0xE);
    func_0018D010(0xE);
    func_0018D010(0xE);
}

void func_0018D8F0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 6;
    func_0018D010(0x13);
}

void func_0018D910(void) {
    D_0028DF8C = 0xE4;
    D_0028DF88 = 7;
    func_0018D010(0x10);
}


void func_0018D930(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 7;
    func_0018D0A0(7);
}

void func_0018D950(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 7;
    func_0018D010(7);
}

void func_0018D970(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 7;
    func_0018D010(0x22);
}

void func_0018D990(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 7;
    func_0018D010(0x30);
}

void func_0018D9B0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 7;
    func_0018D010(0x2F);
}


void func_0018D9D0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0x8;
    func_0018D010(0x38);
}

void func_0018D9F0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 6;
    func_0018D010(0x14);
}

void func_0018DA10(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0x6;
    func_0018D010(0x15);
}

void func_0018DA30(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 6;
    func_0018D010(0x23);
}

void func_0018DA50(void) {
    D_0028DF8C = 0x94;
    D_0028DF88 = 6;
    func_0018D010(0x37);
}

void func_0018DA70(void) {
}

void func_0018DA80(void) {
}

void func_0018DA90(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 9;
    func_0018D010(0x35);
}

void func_0018DAB0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 9;
    func_0018D010(0x36);
}

void func_0018DAD0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xA;
    func_0018D0A0(0x2D);
}

void func_0018DAF0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xA;
    func_0018D010(0x2E);
    func_0018D010(0x2E);
    func_0018D010(0x2E);
}


void func_0018DB30(void) {
    D_0028DF8C = 0xD2;
    D_0028DF88 = 0xA;
    func_0018D010(0x31);
}


void func_0018DB50(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0xA;
    func_0018D0A0(0x32);
}

void func_0018DB70(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xA;
    func_0018D010(0x24);
    vibration_start_pad1(0xA0, 0x12C);
    vibration_start_pad2(0xA0, 0x12C);
}

void func_0018DBC0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xA;
    func_0018D0A0(0x25);
}

void func_0018DBE0(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0xA;
    func_0018D010(0x2C);
}

void func_0018DC00(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 10;
    func_0018D010(0x34);
}

void func_0018DC20(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0xA;
    func_0018D010(0xD);
}

void func_0018DC40(void) {
    D_0028DF8C = 0x80;
    D_0028DF88 = 0xA;
    func_0018D010(0x33);
}

void func_0018DC60(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x1C);
}

void func_0018DC80(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x1D);
}

void func_0018DCA0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x1E);
}

void func_0018DCC0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0x0B;
    func_0018D010(0x1F);
}

void func_0018DCE0(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x18);
}


void func_0018DD00(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x19);
}

void func_0018DD20(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x1A);
}

void func_0018DD40(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x1B);
}

void func_0018DD60(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x20);
}

void func_0018DD80(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xB;
    func_0018D010(0x21);
}


void func_0018DDA0(void) {
    D_0028DF88 = 10;
    func_0018D130();
}

void func_0018DDB0(void) {
    D_0028DF88 = 10;
    func_0018D130();
}

void func_0018DDC0(void) {
    D_0028DF88 = 10;
    func_0018D130();
}

void func_0018DDD0(void) {
    D_0028DF88 = 3;
    func_0018D130();
}

void func_0018DDE0(void) {
    D_0028DF88 = 3;
    func_0018D130();
}

void func_0018DDF0(void) {
    D_0028DF88 = 4;
    func_0018D130();
}

void func_0018DE00(void) {
    D_0028DF88 = 4;
    func_0018D130();
}

s32 vibration_stop_pad1();                            /* extern */

void func_0018DE10(void) {
    D_0028DF88 = 3;
    func_0018D130();
    vibration_stop_pad1();
}

s32 vibration_stop_pad2();                            /* extern */

void func_0018DE40(void) {
    D_0028DF88 = 4;
    func_0018D130();
    vibration_stop_pad2();
}


void func_0018DE70(void) {
    func_0018C730();
}

void func_0018DE80(void) {
}


void func_0018DE90(void) {
    func_0018D140();
}


void func_0018DEA0(void) {
    func_0018DDA0();
    func_0018DDD0();
    func_0018DDF0();
}

extern u8 D_0028E364;

void func_0018DED0(void) {
    D_0028E364 = 0xFF;
    func_0018CD20(0);
}


void func_0018DEE0(void) {
    D_0028E364 = 0xFF;
    func_0018CCA0(0);
}

extern u8 D_00277F98[];
extern u8 D_0028DF98_as_u8;
extern s32 D_0029CA1C_as_s32_a[];
extern s32 D_0029CA20_as_s32_a[];
extern u8 D_0029CBF0[];
extern u8 D_0029CBF4[];

void func_0018DEF0(s32 arg0, s32 arg1) {
    if (D_0028E3C0 != 0) return;
    D_0028E364 = 0x46;
    D_0029CA18_as_s32_a[0] = 0;
    func_0018C600(0x100, 1, 0);
    func_0018C8D0(0);
    func_0018C600(0x200, 0, 0);
    printf((const char *)D_00277F98);
    func_0018C600(0x8000, 0x30000, 0);
    if (arg1 != 0) {
        func_0018C600(0x80C0, 2, 0);
    } else {
        func_0018C600(0x80C0, 0, 0);
    }
    func_0018C600(0x160, (s32)(*(s32 *)(D_0029CBF0 + arg0 * 8)), *(s32 *)(D_0029CBF4 + arg0 * 8));
    D_0029CA1C_as_s32_a[0] = 0x64;
    D_0029CA20_as_s32_a[0] = D_0029CA1C_as_s32_a[0];
    func_0018C600(0x80, 0x7FFF7FFF, 0);
    func_0018C600(0x140, 0, 0);
    D_0028DF98_as_u8 = 1;
}

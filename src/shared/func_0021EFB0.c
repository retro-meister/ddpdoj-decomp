#include "common.h"

s32 func_0018D4B0();
void func_0021F1C0(void);
void func_0021F2C0(void);
void func_0021F440(void);
s32 func_00221120();
s32 func_00222260();
s32 func_00222780();
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u16 D_0028E320_as_u16;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
extern s8 D_0028EB04;
extern s8 D_0028EB14;
extern s8 D_0028EB38;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB68;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
void func_0021EFB0(void) {
    s32 var_a1;

    if (func_00221120(0xF) == 0) {
        func_0021F1C0();
    }
    func_0021F2C0();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 0xD;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    D_0028EB14 = D_0028EB58;
    if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    if ((D_0028EB14 >= 9) && (D_0028EB14 < 0xC)) {
        if (D_0057CC78[0] != 0) {
            var_a1 = 1;
        }
    } else if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 0xD;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            break;
        case 7:
            func_0018D4B0();
            D_0028EB90 = 0x80;
            D_0028EAE4 = D_0028E254;
            D_0028EB84 = 0x10;
            D_0028EAE0 = D_0028E250;
            break;
        case 9:
            func_00222780();
            break;
        case 10:
            func_00222780();
            break;
        case 11:
            func_00222780();
            break;
        case 12:
            func_0018D4B0();
            func_0021F440();
            func_0021F2C0();
            break;
        case 13:
            func_0018D4B0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB38 = 2;
            D_0028EB04 = 1;
            D_0028EB68 += 1;
            break;
        }
    }
}

#pragma opt_propagation off


void func_0021F180(void)
{
    if (D_0028EB38 == 0) {
        s8 savedState = D_0028EB14;

        D_0028EB68 = 2;
        D_0028EB54 = 1;
        D_0028E320_as_u16 = 0xE10;
        D_0028EB58 = savedState;
        return;
    }
}

extern void func_0018D4C0(void);
extern s8 D_00271690[];
extern s8 D_002716A0[];
extern u8 D_0028E358;
extern s32 D_0057CC68[];
extern s8 D_0068DD00[];

void func_0021F1C0(void) {
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel != 7 && !(sel > 7)) {
        max = D_00271690[sel];
        if (sel == 2 && D_0028E358 != 0) {
            max = D_002716A0[sel];
        }
        cur = D_0068DD00[sel];
        pad = D_0057CC68[0];
        if (pad & 0x2000) {
            func_0018D4C0();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DD00[D_0028EB58] = cur;
        } else if (pad & 0x8000) {
            func_0018D4C0();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DD00[D_0028EB58] = cur;
        }
    }
}

extern void func_0021B840(s32, s32);
extern u8 D_00271C60[];
extern u8 D_00271C64[];
extern s8 D_0028E270_as_s8;
extern s8 D_0028E271_as_s8;
extern s8 D_0028E272_as_s8;
extern s8 D_0028E273_as_s8;
extern s8 D_0028E274_as_s8;
extern s8 D_0028E275_as_s8;
extern s8 D_0028E276_as_s8;
extern s8 D_0028E277_as_s8;
extern s8 D_0028E28C_as_s8;
extern u8 D_0028E2DC;
extern s8 D_0028E2E0_as_s8;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern s8 D_0028E9EC;
extern s8 D_0068DD01[];
extern s8 D_0068DD02[];
extern s8 D_0068DD03_as_s8_a[];
extern s8 D_0068DD04_as_s8_a[];
extern s8 D_0068DD05_as_s8_a[];
extern s8 D_0068DD06_as_s8_a[];
extern s8 D_0068DD09[];
extern s8 D_0068DD0A[];
extern s8 D_0068DD0B[];
extern s8 D_0068DD0C_as_s8_a[];
extern s8 D_0068DD0D[];
extern s8 D_0068DD0E[];
extern s8 D_0068DD0F[];
extern s8 D_0068DD10_as_s8_a[];
void func_0021F2C0(void) {
    s32 temp_a0;

    if (D_0028E358 != D_0068DD01[0]) {
        D_0028E354 = 0;
        D_0028E9EC = 1;
        D_0068DD02[0] = 0;
    }
    if (D_0028E354 != D_0068DD02[0]) {
        D_0028E354 = (u8) D_0068DD02[0];
        if (D_0028E358 == 0) {
            D_0028E354 &= 3;
        } else {
            D_0028E354 &= 1;
        }
        D_0068DD02[0] = D_0028E354;
        D_0028E9EC = 1;
    }
    if (D_0028E2DC != D_0068DD03_as_s8_a[0]) {
        D_0028E9EC = 1;
    }
    D_0028E2DC = (u8) D_0068DD03_as_s8_a[0];
    D_0028E2E0_as_s8 = D_0068DD06_as_s8_a[0];
    D_0028E28C_as_s8 = D_0068DD05_as_s8_a[0];
    if (D_0028E32C != D_0068DD04_as_s8_a[0]) {
        D_0028E32C = (u16) (s8)(D_0068DD04_as_s8_a[0]);
        if (D_0028E32C != 5) {
            temp_a0 = (D_0028E32C & 0xFFFF) * 8;
            func_0021B840(*(s32 *)(D_00271C60 + temp_a0), *(s32 *)(D_00271C64 + temp_a0));
        }
    }
    D_0028E270_as_s8 = D_0068DD09[0];
    D_0028E271_as_s8 = D_0068DD0A[0];
    D_0028E272_as_s8 = D_0068DD0B[0];
    D_0028E273_as_s8 = D_0068DD0C_as_s8_a[0];
    D_0028E274_as_s8 = D_0068DD0D[0];
    D_0028E275_as_s8 = D_0068DD0E[0];
    D_0028E276_as_s8 = D_0068DD0F[0];
    D_0028E277_as_s8 = D_0068DD10_as_s8_a[0];
}

#ifdef DEATH_LABEL
extern u8 death_D_00628F01[];
extern u8 death_D_00628F02[];
#endif

void func_0021F440(void) {
    if (D_0028E354 != 0) {
        D_0028E9EC = 1;
    }
    D_0068DD01[0] = 0;
    D_0068DD02[0] = 0;
    D_0028E354 = 0;
    D_0068DD03_as_s8_a[0] = 0;
    D_0068DD04_as_s8_a[0] = 5;
    D_0068DD05_as_s8_a[0] = 1;
    D_0068DD06_as_s8_a[0] = 0;
    D_0068DD09[0] = 7;
    D_0068DD0D[0] = 7;
    D_0068DD0A[0] = 6;
    D_0068DD0E[0] = 6;
    D_0068DD0B[0] = 5;
    D_0068DD0F[0] = 5;
    D_0068DD0C_as_s8_a[0] = 1;
    D_0068DD10_as_s8_a[0] = 1;
#ifdef DEATH_LABEL
    death_D_00628F01[0] = 0;
    death_D_00628F02[0] = 0;
#endif
}

s32 func_0021F560();
s32 func_0021F5B0();
s32 func_0021F600();
s32 func_0021F750();
s32 func_00212580();
s32 printf();
extern s8 D_0028EB60;

void func_0021F4E0(void) {
    switch (D_0028EB60) {                           /* irregular */
    case 0:
        func_0021F560(D_0028EB60);
        break;
    case 1:
        func_0021F5B0(D_0028EB60);
        break;
    case 2:
        func_0021F600(D_0028EB60);
        break;
    case 3:
#ifndef DEATH_LABEL
        func_0021F750(D_0028EB60);
#endif
        break;
    }
#ifdef DEATH_LABEL
    if (D_0028EB60 >= 0x40) {
        D_0028EB60++;
        if (D_0028EB60 >= 0x60) {
            func_00212580(2);
            printf("kidou\n");
        }
    }
#endif
}

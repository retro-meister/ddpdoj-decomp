#include "common.h"

s32 func_0018CBB0();
s32 func_0018D4B0();
void func_0018D4C0(void);
s32 func_00221120();
s32 func_00222260();
s32 func_00222340();
s32 func_00222530();
void death_func_001B74D0(void);
void death_func_001B7520(void);
void death_func_001B7570(void);
void death_func_001B76A0(void);
extern u16 D_0028E320_as_u16;
extern s8 D_0028EB04;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s8 death_D_00290048[3];
extern s8 death_D_00290C4C;
extern s8 death_D_00290C74;
extern s8 death_D_00290CA8;
extern s32 death_D_00290CE4;
extern s32 D_0057CC68[];
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
extern s8 death_D_00628F00[];

void death_func_001B7460(void) {
    switch (death_D_00290CA8) {
    case 0:
        death_func_001B74D0();
        break;
    case 1:
        death_func_001B7520();
        break;
    case 2:
        death_func_001B7570();
        break;
    case 3:
        break;
    }
}

void death_func_001B74D0(void) {
    death_D_00290CE4 = 0;
    death_D_00290CA8++;
    func_00222340(0x17);
    D_0028EB90 = 0x40;
    death_D_00290C4C = 0;
    death_D_00290C74 = 1;
    D_0028EB04 = 1;
    D_0028E320_as_u16 = 0xE10;
}

void death_func_001B7520(void) {
    if (func_00222530(0x17) != 0) {
        death_D_00290CA8++;
        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
    }
}

void death_func_001B7570(void) {
    s32 var_a1;

    if (func_00221120(0x17) == 0) {
        death_func_001B76A0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 3;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 3;
    } else if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    death_D_00290C4C = D_0028EB58;
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 1:
        case 2:
            break;
        case 3:
            func_0018CBB0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB4C = 1;
            D_0028EB90 = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            death_D_00290C74 = 2;
            D_0028EB84 = 0;
            death_D_00290CA8++;
            func_0018D4B0();
            break;
        }
    }
}

void death_func_001B76A0(void) {
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel < 3) {
        max = death_D_00290048[sel];
        cur = death_D_00628F00[sel];
        pad = D_0057CC68[0];
        if (pad & 0x2000) {
            func_0018D4C0();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            death_D_00628F00[D_0028EB58] = cur;
        } else if (pad & 0x8000) {
            func_0018D4C0();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            death_D_00628F00[D_0028EB58] = cur;
        }
    }
}

#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Pair;

extern void func_0018D4B0(void);
extern void func_0018D4C0(void);
extern void func_002035F0(void);
extern void func_00217BB0(s32 a, s32 b);
extern void func_00217C20(s32 a, s32 b);
extern void func_0021B840(s32 a, s32 b);
extern s32 func_00223BE0(void);
extern Pair D_00271C60[];
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u8 D_0028E27C;
extern u8 D_0028E28C;
extern u16 D_0028E31C;
extern u16 D_0028E324;
extern u16 D_0028E328;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern u8 D_0028E36C;
extern u8 D_0028E378;
extern u16 D_0028E910;
extern u8 D_0028E9EC;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
extern s32 D_0028EB90;
extern s8 D_0028EBBC;
extern u8 D_0028EBC4;
extern s8 D_0028EBD0;
extern u32 D_0057CC60[];
extern u32 D_0057CC70[];
extern s8 D_0068DD02[];

void func_00223550(void) {
    u32 pad;

    if (D_0028EBBC != 0) {
        D_0028EBBC--;
    }
    if (D_0028EBBC == 0 && (D_0057CC70[D_0028E31C] & 0x800)) {
        func_0018D4B0();
        D_0028E36C++;
        return;
    }
    if (func_00223BE0() != 0) {
        return;
    }
    switch (D_0028EBD0) {
    case 1:
        pad = D_0057CC60[D_0028E31C];
        if (pad & 0x8000) {
            func_0018D4C0();
            D_0068DD02[0]--;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            D_0028E9EC = 1;
        } else if (pad & 0x2000) {
            func_0018D4C0();
            D_0068DD02[0]++;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            D_0028E9EC = 1;
        }
        break;
    case 2:
        if (D_0057CC60[D_0028E31C] & 0xA000) {
            func_0018D4C0();
            D_0028E27C++;
            D_0028E27C &= 1;
            if (D_0028E27C != 0) {
                func_00217BB0(0x78, 0x14);
                func_00217C20(0x78, 0x14);
            }
        }
        break;
    case 3:
        pad = D_0057CC60[D_0028E31C];
        if (pad & 0x8000) {
            func_0018D4C0();
            D_0028E32C--;
            if ((s16)D_0028E32C < 0) {
                D_0028E32C = 5;
            }
            if (D_0028E32C != 5) {
                func_0021B840(D_00271C60[D_0028E32C].a, D_00271C60[D_0028E32C].b);
            }
        } else if (pad & 0x2000) {
            func_0018D4C0();
            D_0028E32C++;
            if (D_0028E32C > 5) {
                D_0028E32C = 0;
            }
            if (D_0028E32C != 5) {
                func_0021B840(D_00271C60[D_0028E32C].a, D_00271C60[D_0028E32C].b);
            }
        }
        break;
    case 4:
        if (D_0057CC60[D_0028E31C] & 0xA000) {
            func_0018D4C0();
            D_0028E28C++;
            D_0028E28C &= 1;
        }
        break;
    case 5:
        if (D_0057CC70[D_0028E31C] & 0x20) {
            func_0018D4B0();
            D_0028EB90 = 0x80;
            D_0028EAE4 = D_0028E254;
            D_0028E36C = 0xB;
            D_0028EAE0 = D_0028E250;
        }
        break;
    case 6:
    case 7:
        if (D_0057CC70[D_0028E31C] & 0x20) {
            func_0018D4B0();
            D_0028EBC4 = 1;
            D_0028E36C = 5;
        }
        break;
    case 8:
        if (D_0057CC60[D_0028E31C] & 0xA000) {
            func_0018D4C0();
            D_0028E324++;
            D_0028E324 &= 1;
        }
        break;
    case 9:
        pad = D_0057CC60[D_0028E31C];
        if (pad & 0x8000) {
            func_0018D4C0();
            D_0028E328--;
            if ((s32)D_0028E328 <= 0) {
                D_0028E328 = 5;
            }
        } else if (pad & 0x2000) {
            func_0018D4C0();
            D_0028E328++;
            if (D_0028E328 > 5) {
                D_0028E328 = 1;
            }
        }
        if (D_0028E378 != 0xFF && (D_0057CC70[D_0028E31C] & 0x20)) {
            reg_d6.h[0] = 1;
            reg_d7.h[0] = D_0028E328;
            if (reg_d7.h[0] == 5) {
                reg_d7.h[0] = 0;
            }
            func_002035F0();
            D_0028E36C = 0;
        }
        break;
    }
    D_0028E910 = D_0028E324;
}

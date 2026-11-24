#include "common.h"

void func_0012FAB0(void);
void func_0013B190(void);
void func_0015BA20(void);
void func_0015BD00(void);
void func_00168BA0(void);
void func_0020EAA0(void);
void fade_start_in(void);
void func_0021D570(void);
s32 func_0022BB80(u8 *);
void func_00235890(void);
void printf(const char *, ...);
s32 sceGsSyncV(s32);
extern const char D_00275840[];
extern s8 D_0028DF84;
extern s8 D_0028E25C;
extern s8 D_0028E284;
extern s8 D_0028E288;
extern s8 D_0028E298;
extern s8 D_0028E2A0;
extern s8 D_0028E2A4;
extern u8 D_0028E2B8;
extern u8 D_0028E2B9;
extern u8 D_0028E2BA;
extern u8 D_0028E2BB;
extern u8 D_0028E2BC;
extern s8 D_0028E2BD;
extern s8 D_0028E2BE;
extern s8 D_0028E2BF;
extern u16 D_0028E2FC;
extern u16 D_0028E300;
extern s8 D_0028E310;
extern s16 D_0028E314;
extern s16 D_0028E318;
extern s8 D_0028E368;
extern s8 D_0028E370;
extern s8 D_0028E3F8;
extern s8 D_0028EB00;
extern s32 D_0028EB94;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00169140(void) {
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1;
        func_0013B190();
        func_0015BA20();
        func_0020EAA0();
        D_0028E310 = 0;
        D_0028E288 = 0;
        D_0028E284 = 0;
        D_0028E298 = 0;
        D_0028E2A4 = 0;
        D_0028E2A0 = 0;
        D_0028E368 = 0;
        func_0012FAB0();
#ifdef DEATH_LABEL
        func_00235890();
#else
        if (D_0028DF84 != 0) {
            func_00235890();
        }
#endif
    }
    if (D_0028EB94 == 0) {
        func_0015BD00();
    }
    func_0021D570();
    if (D_0028EB00 >= 10) {
        if (D_0028EB00 == 10) {
            D_0028DF84 = 1;
            reg_d0.h[0] = 3;
            func_00168BA0();
        } else if (D_0028EB00 == 30) {
            D_0028DF84 = 0;
            reg_d0.h[0] = 0x10;
            D_0028E370 = 0;
            D_0028E3F8 = 0;
            func_00168BA0();
        } else if (D_0028EB00 == 40) {
#ifdef DEATH_LABEL
            D_0028E2B8 = 0;
            D_0028E2B9 = 0;
            D_0028E2BA = 0;
            D_0028E2BB = 0;
            D_0028E2BC = 0;
            D_0028E2BD = 0;
            D_0028E2BE = 0;
            D_0028E2BF = 0;
            reg_a0 = &D_0028E2B8;
            if (func_0022BB80(reg_a0) != 0) {
                sceGsSyncV(0);
                if (func_0022BB80(reg_a0) != 0) {
                    D_0028E2B8 = 0;
                    D_0028E2B9 = 0;
                    D_0028E2BA = 0;
                    D_0028E2BB = 0;
                    D_0028E2BC = 0;
                }
            }
            printf(D_00275840, D_0028E2B8, D_0028E2B9, D_0028E2BA, D_0028E2BB, D_0028E2BC);
#endif
            D_0028DF84 = 0;
            reg_d0.h[0] = 0x13;
            D_0028E370 = 0;
            D_0028E3F8 = 0;
            func_00168BA0();
        } else {
            D_0028E318 = 9;
            D_0028E314 = 9;
            D_0028E2FC = D_0028E300;
            D_0028E25C = 0;
            D_0028E2B8 = 0;
            D_0028E2B9 = 0;
            D_0028E2BA = 0;
            D_0028E2BB = 0;
            D_0028E2BC = 0;
            D_0028E2BD = 0;
            D_0028E2BE = 0;
            D_0028E2BF = 0;
            reg_a0 = &D_0028E2B8;
            if (func_0022BB80(reg_a0) != 0) {
                sceGsSyncV(0);
                if (func_0022BB80(reg_a0) != 0) {
                    D_0028E2B8 = 0;
                    D_0028E2B9 = 0;
                    D_0028E2BA = 0;
                    D_0028E2BB = 0;
                    D_0028E2BC = 0;
                }
            }
            printf(D_00275840, D_0028E2B8, D_0028E2B9, D_0028E2BA, D_0028E2BB, D_0028E2BC);
            reg_d0.h[0] = 0xE;
            func_00168BA0();
        }
        D_0028EB00 = 0;
        fade_start_in();
    }
}

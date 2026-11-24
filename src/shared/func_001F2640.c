#include "common.h"

s32 func_00124B20();
s32 func_00124D70();
s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F00();
s32 func_00124F50();
s32 func_0018D350();
s32 func_001F5630();
s32 func_001F5730();
s32 func_001F57C0();
s32 func_0020ED10();
extern void *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u16 D_0028E908;
extern u16 D_00299768[];
extern u16 D_0029976A[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

#ifdef DEATH_LABEL
extern u16 death_D_0068FFB2[];
extern u16 death_D_0068FFB4[];
extern u16 death_D_006901B2[];
extern u16 death_D_006901B4[];
#endif

void func_001F2640(void) {
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
            D_0028E620 = (void *)reg_a0;
            D_0028E855 |= 1;
            D_0028E855 |= 4;
            D_0028E854 |= 1;
            func_001F5630();
            func_001F5730();
            func_001F57C0();
            D_00299768[0] = 1;
            D_0029976A[0] = 1;
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

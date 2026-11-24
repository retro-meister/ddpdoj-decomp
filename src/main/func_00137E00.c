#include "common.h"

extern s8 D_0028E408;

s32 func_0011BEA0();
s32 func_0012FA50();
s32 func_0012FB00();
s32 func_00137CC0();
s32 func_001A2FA0();
s32 func_002071C0();
s32 func_0021D410();
s32 func_00224B50();
s32 func_0022BC60();
s32 func_0022BE60();
s32 func_0023DBF0();
s32 memcpy();
extern u8 D_00269320[];
extern u8 D_0028DEF4;
extern u8 D_0028DEF8;
extern u16 D_0028DEFC;
extern u16 D_0028DF00;
extern u8 D_0028DF04;
extern u8 D_0028DF08;
extern s16 D_0028E3C0_as_s16;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern s8 D_0028ED74_as_s8;
extern s8 D_0028ED7C_as_s8;
extern u8 D_006A4800[];
extern u8 D_006C58A0[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern u8 D_006C5CA0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00137E00(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 temp_a1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    temp_a1 = D_0028DF08;
    D_0028E408 = 1;
    D_0028DEF4 += 1;
    switch (temp_a1) {                              /* irregular */
    case 0:
        D_0028DF08 = temp_a1 + 1;
        func_0022BC60(4, temp_a1, 1);
        reg_a0 = (u8 *)D_00269320;
        reg_d0.h[0] = 0xC;
        func_001A2FA0();
        /* fallthrough */
    case 1:
        if (func_0022BE60(D_0028DF04) != 0) {
            D_0028DF08 += 1;
            memcpy(D_006C58A0, D_006A4800, 0x202E8);
            func_0021D410(D_006C5CA0);
            func_0023DBF0(D_006C58A0);
            D_0028ED7C_as_s8 = 2;
            D_0028ED30 = D_006C58D8[0];
            reg_d0.h[0] = 0x14;
            D_0028ED31 = D_006C58D9[0];
            D_0028ED32 = D_006C58DA[0];
            D_0028ED33 = D_006C58DB[0];
            D_0028ED34 = D_006C58DC[0];
            D_0028ED35 = D_006C58DD[0];
            D_0028ED36 = D_006C58DE[0];
            D_0028ED37 = D_006C58DF[0];
            func_002071C0();
            (*(s8 *)((u8 *)(reg_a0) + (5))) = 3;
        }
        break;
    case 2:
        if (D_0028DEF8 != 0) {
            D_0028DF08 = temp_a1 + 1;
        }
        break;
    case 3:
        D_0028DF08 = temp_a1 + 1;
        break;
    case 4:
        D_0028DF00 -= 1;
        if (D_0028DF00 == 0) {
            D_0028DF08 = 0;
            D_0028E408 = 0;
            D_0028E3C0_as_s16 = 0;
            D_0028ED7C_as_s8 = 0;
            D_0028ED74_as_s8 = 0;
            func_0012FA50();
            func_0012FB00();
            func_0011BEA0();
            func_00224B50();
            D_0028DF04 += 1;
            if ((s32) D_0028DF04 >= 3) {
                D_0028DF04 = 0;
            }
        }
        break;
    }
    if ((s32) D_0028DF08 > 0) {
        func_00137CC0();
        reg_d0.h[0] = (u16) D_0028DEF4;
        if ((reg_d0.h[0] &= 1) == 0) {
            D_0028DEFC += 4;
            D_0028DEFC &= 0xF;
        }
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}

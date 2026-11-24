#include "common.h"

typedef void (*Fn)();

s32 func_0018DA30();
s32 func_0018DA50();
s32 func_00203850();
s32 func_002039B0();
s32 func_002046F0();
s32 func_00204A20();
s32 func_002053F0();
s32 func_00205D20();
s32 func_00206080();
extern u8 D_00251AB0[];
extern u8 D_00251AC0[];
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 *jtbl_0028E3F4_as_u8_p;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00146470(void) {
    u8 *temp_s0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_a4 = (u8 *)D_00251AC0;
    if (reg_d7.h[0] != 0) {
        reg_a4 = (u8 *)D_00251AB0;
    }
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    if (reg_d0.w & 4) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) -= 1;
        if (0 > (s16) (*(u16 *)((u8 *)(reg_a6) + (2)))) {
            (*(u16 *)((u8 *)(reg_a6) + (2))) = 0U;
        }
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (2))) != reg_d6.h[0]) {
        func_0018DA50();
    }
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    if (reg_d0.w & 8) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) > 1) {
            (*(u16 *)((u8 *)(reg_a6) + (2))) = 1U;
        }
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (2))) != reg_d6.h[0]) {
        func_0018DA50();
    }
    if (((*(u8 *)((u8 *)(reg_a6) + (0x31))) != 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        func_0018DA30();
        (*(s8 *)((u8 *)(reg_a6) + (0))) = 2;
        if (reg_d7.h[0] != 0) {
            D_0028E99C = (s32) (*(u16 *)((u8 *)(reg_a6) + (2)));
        } else {
            D_0028E998 = (*(u16 *)((u8 *)(reg_a6) + (2))) + 2;
        }
    }
    temp_v1 = (*(u8 *)((u8 *)(reg_a5) + (2)));
    temp_s0 = (u8 *)(reg_a4);
    if (temp_v1 & 1) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = (u8) (temp_v1 | 1);
    } else {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = (u8) (temp_v1 | 1);
        func_00203850();
        func_002039B0();
    }
    temp_v1_2 = (*(u8 *)((u8 *)(reg_a5) + (2)));
    if (temp_v1_2 & 2) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = (u8) (temp_v1_2 | 2);
    } else {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = (u8) (temp_v1_2 | 2);
        func_002046F0();
    }
    func_00204A20();
    func_002053F0();
    func_00205D20();
    func_00206080();
    reg_a4 = temp_s0;
}

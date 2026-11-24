#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_00125EA0();
s32 func_0012FE10();
s32 func_00131610();
s32 func_00134170();
s32 func_00134260();
s32 func_00134A70();
s32 func_00134AC0();
s32 func_00134B70();
s32 func_00134BA0();
s32 func_00134BD0();
s32 func_00135100();
s32 func_001351F0();
s32 func_001353E0();
extern u8 D_0028E398;
extern u16 D_0028E910;
extern u8 D_0028ED80;
extern u8 D_002BF3EA[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00134C40(void) {
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0xA);
    reg_a4 = (u8 *) reg_tmp.w;
    if (reg_a5[3] == 0) {
        func_00134AC0();
        return;
    }
    if (reg_a5[3] == 2) {
        func_00134BA0();
        return;
    }
    if (reg_a5[3] == 3) {
        func_00134B70();
        return;
    }
    if (reg_a5[3] == 4) {
        func_00134BD0();
        return;
    }
    if (D_0028E910 != 0) {
        goto next_8;
    }
    if (D_0028E398 == 0) {
        goto next_8;
    }
    if (D_0028ED80 != 0) {
        goto next_8;
    }
    func_001351F0();
    if (D_0028E408 == 0) {
        goto next_2;
    }
    if (reg_a5[2] != 0) {
        goto next_1;
    }
    reg_a5[2] = 1;
    func_00125EA0();
    func_00134A70();
next_1:
    reg_d0.w = 3;
    reg_d1.w = 0;
    func_00134170();
    func_00135100();
    goto next_4;
next_2:
    if (reg_a5[2] == 0) {
        goto next_3;
    }
    reg_a5[2] = 0;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a5[6];
    func_00134260();
    func_00134A70();
next_3:
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a5[6];
    func_00134170();
next_4:
    func_00131610();
    if (D_0028E408 != 0) {
        return;
    }
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 0xE);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = reg_a0;
    ((Fn) jtbl_0028E3F4)();
    if (((reg_d0.h[0] &= 0x70) & 0xFFFF) == 0) {
        goto next_6;
    }
    func_001351F0();
    if (D_0028E408 == 0) {
        goto next_5;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    reg_d1.h[0] = 8;
    func_001353E0();
    goto next_6;
next_5:
    reg_a5[4] = 0;
next_6:
    reg_a5[4] -= 1;
    if ((s8) reg_a5[4] >= 0) {
        goto next_10;
    }
    reg_a5[4] = 60;
    reg_a5[5] -= 1;
    if ((s8) reg_a5[5] >= 0) {
        goto next_10;
    }
next_8:
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 6);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = reg_a0;
    ((Fn) jtbl_0028E3F4)();
    if (D_0028ED80 != 0) {
        goto next_9;
    }
    if (D_0028E910 != 0) {
        goto next_9;
    }
    func_001351F0();
    if (D_0028E408 == 0) {
        goto next_11;
    }
next_9:
    reg_a5[3] = 4;
    func_00134BD0();
    return;
next_11:
    reg_a5[3] = 3;
    func_00134B70();
    return;
next_10:
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    func_0012FE10();
    if (D_0028E408 == 0) {
        goto next_12;
    }
    func_00134A70();
next_12:
    func_001351F0();
    if (D_0028E408 == 0) {
        goto next_13;
    }
    reg_d0.b[0] = reg_a5[5];
    D_002BF3EA[0] = reg_d0.b[0];
    return;
next_13:
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 0x12);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.b[0] = reg_a5[5];
    *reg_a0 = reg_d0.b[0];
}

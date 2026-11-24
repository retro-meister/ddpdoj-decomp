#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_0018DA30();
s32 func_0018DA50();
s32 func_0019DA80();
s32 func_001AF2C0();
s32 func_001AF310();
s32 func_001AF460();
extern u16 D_00251B20[];
extern u16 D_00251B30[];
extern u16 D_0028C130[];
extern u16 D_0028E3F0;
extern u8 *jtbl_0028E3F4_as_u8_p;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AFCC0(void) {
    u16 var_a0;
    reg_d7.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
    func_001AF310();
    if (D_0028E408 != 0) {
        reg_d7.b[0] -= 1;
        if (0 > reg_d7.sb[0]) {
            reg_d7.b[0] = 2;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0xE))) = (u8) reg_d7.b[0];
    }
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_a0 = (u8 *)(reg_tmp.w);
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
    reg_d7.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
    reg_d6.h[0] = reg_d7.h[0];
    if (reg_d0.w & 4) {
        (*(s8 *)((u8 *)(reg_a5) + (0xC))) = 1;
        do {
            reg_d7.b[0] -= 1;
            if (0 > reg_d7.sb[0]) {
                reg_d7.b[0] = 2;
            }
            func_001AF310();
        } while (D_0028E408 != 0);
    }
    if (reg_d0.w & 8) {
        (*(s8 *)((u8 *)(reg_a5) + (0xC))) = 1;
        do {
            reg_d7.b[0] += 1;
            if ((s8) reg_d7.b[0] > 2) {
                reg_d7.b[0] = 0;
            }
            func_001AF310();
        } while (D_0028E408 != 0);
    }
    if (reg_d6.b[0] != reg_d7.b[0]) {
        func_0018DA50();
    }
    (*(u8 *)((u8 *)(reg_a5) + (0xE))) = (u8) reg_d7.b[0];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
    reg_a0 = (u8 *)(reg_tmp.w);
    *(u8 *)reg_a0 = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
    (*(u16 *)((u8 *)(reg_a5) + (0x12))) -= 1;
    if (((*(u16 *)((u8 *)(reg_a5) + (0x12))) == 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        func_0018DA30();
        func_001AF460();
        return;
    }
    reg_d1.w = 0x5BC00000;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_d1.w = 0x5BC02600;
    }
    reg_d2.w = 0x1551;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x648;
    reg_d7.w = reg_d1.w;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
    func_0019DA80();
    reg_d0.w = 0;
    reg_d1.w = reg_d7.w;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
    reg_a0 = (u8 *)((u32) D_0028C130);
    reg_d0.h[0] += reg_d0.h[0];
    if (reg_d0.h[0] != 0) {
        var_a0 = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1));
    } else {
        var_a0 = *(u16 *)reg_a0;
    }
    reg_d1.h[0] += var_a0;
    reg_a2 = (u8 *)(D_00251B20);
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_a2 = (u8 *)(D_00251B30);
    }
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d0.h[0] &= 3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x618;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
    func_0019DA80();
    func_001AF2C0();
    if (0 <= (s16)(reg_d0.h[0])) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_d1.w = reg_d7.w;
        reg_a2 = (u8 *)(D_0028C130);
        reg_a2 += reg_d0.h[0];
        reg_d1.h[0] += *(u16 *)reg_a2;
        reg_d2.w = 0x1557;
        reg_d3.h[0] = 0x618;
        reg_d4.w = 0;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
        func_0019DA80();
    }
}

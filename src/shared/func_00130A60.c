#include "common.h"

void func_00130110(void);
void func_001305E0(void);
void func_00130A00(void);
void func_0018D8F0(void);
extern u16 D_0028E1D8_as_u16_a[];
extern u16 D_0028E1E4_as_u16_a[];
extern u16 D_0028E1F0;
extern u16 D_0028E1F4;
extern u16 D_0028E1F8;
extern u8 D_0028E204;
extern u8 D_0028E208;
extern u8 D_0028E20C;
extern u8 D_0028E210;
extern u16 D_0028E224;
extern u16 D_0028E228_as_u16;
extern u8 D_0028E350;
extern u8 D_0028E390;
extern u8 D_0028E39C;
extern s8 D_0028E408;
extern u8 *reg_a0;

void func_00130A60(void) {
    if (D_0028E350 != 0) return;
    if (D_0028E39C == 0x12) return;
    reg_a0 = (u8 *)&D_0028E228_as_u16;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] = D_0028E1F4;
    D_0028E1F4 = reg_d0.h[0];
    reg_d0.h[0] = ~(s16)reg_d0.h[0];
    D_0028E1F8 = reg_d0.h[0];
    reg_d1.h[0] &= reg_d0.h[0];
    reg_d1.h[0] &= 0xE0;
    D_0028E1F0 = reg_d1.h[0];
    func_00130A00();
    reg_d1.h[0] |= D_0028E1F0;
    if (reg_d1.h[0] & 0x20) {
        func_0018D8F0();
        reg_a0 = (u8 *)D_0028E1E4_as_u16_a;
        func_001305E0();
        return;
    }
    if (reg_d1.w & 1) {
        func_0018D8F0();
        reg_a0 = (u8 *)D_0028E1E4_as_u16_a;
        func_001305E0();
        reg_d0.b[0] = D_0028E39C;
        if (reg_d0.b[0] != 0x12) {
            D_0028E208 += 1;
        }
    }
    if (reg_d1.w & 2) {
        func_0018D8F0();
        reg_a0 = (u8 *)D_0028E1D8_as_u16_a;
        reg_d0.b[0] = D_0028E390;
        if (reg_d0.b[0] != 1) {
            reg_a0 = (u8 *)D_0028E1E4_as_u16_a;
        }
        func_001305E0();
        reg_d0.b[0] = D_0028E39C;
        if (reg_d0.b[0] != 0x12) {
            D_0028E204 += 1;
        }
    }
    reg_a0 = (u8 *)&D_0028E224;
    if (D_0028E210 == 0) {
        func_00130110();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = D_0028E390;
            if (reg_d1.b[0] != 0) {
                *(u16 *)reg_a0 = reg_d0.h[0];
            } else {
                *(u16 *)reg_a0 = 0xF;
            }
            D_0028E20C = 6;
            D_0028E210 = 1;
        }
    } else if (D_0028E210 == 1) {
        D_0028E20C -= 1;
        if (D_0028E20C == 0) {
            *(u16 *)reg_a0 = 0;
            D_0028E20C = 6;
            D_0028E210 = 2;
        }
    } else if (D_0028E210 == 2) {
        D_0028E20C -= 1;
        if (D_0028E20C == 0) {
            D_0028E210 = 0;
        }
    }
}

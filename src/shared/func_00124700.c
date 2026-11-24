#include "common.h"

typedef void (*Fn)();

extern u8 D_00295E7C[];
extern u16 D_00295E50[];
extern u16 D_00295E52[];
extern u8 *D_00295E54[];
extern u16 D_00295E58[];
extern u16 D_00295E5A[];
extern u16 D_00295E5C[];
extern u8 *D_00295F40[];
extern u16 D_00295F44[];
extern s64 D_002960A8[];
extern u16 D_002960B0[];
extern u8 *D_00296210[];
extern u16 D_00296214[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_00124700(void) {
    u32 t1;
    u32 t2;
    u32 t3;

    if (D_00296210[0] != 0) {
        reg_a4 = (u8 *)(D_00296214);
        reg_d7.w = 4;
        do {
            reg_d0.h[0] = *(u16 *)reg_a4;
            if (reg_d0.h[0] != 0) {
                reg_d0.h[0] &= 0xFF;
                reg_d0.h[0] *= 8;
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
                *(u8 *)(reg_a4 + 1) |= 1;
                if (reg_tmp.b[0] & 1) {
                    reg_d0.h[0] += 4;
                }
                reg_a0 = D_00296210[0];
                reg_a0 += reg_d0.h[0];
                reg_a0 = *(u8 **)reg_a0;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                t1 = reg_d7.w;
                jtbl_0028E3F4();
                reg_d7.w = t1;
            }
            reg_a4 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (D_00295E54[0] != 0) {
        if (D_00295E50[0] != 0) {
            D_00295E50[0] = 0;
            reg_a0 = (u8 *)D_00295E7C;
            D_00295E58[0] = 0;
            reg_a1 = (u8 *)(D_00295E5C);
            reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xF, 0x1F);
            D_00295E5A[0] = D_00295E52[0];
            do {
                *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                reg_a1 += 2;
            } while ((s16)(--reg_d0.h[0]) >= 0);
        }
        reg_a0 = D_00295E54[0];
        reg_d0.h[0] = D_00295E5A[0];
        if ((s16)(reg_d0.h[0]) != -1) {
            reg_d0.h[0] *= 8;
            reg_d0.h[0] += D_00295E58[0];
            reg_a0 += reg_d0.h[0];
            reg_a0 = *(u8 **)reg_a0;
            reg_a4 = (u8 *)(D_00295E5C);
            jtbl_0028E3F4 = (Fn)(reg_a0);
            jtbl_0028E3F4();
            if (D_00295E58[0] == 0) {
                D_00295E58[0] += 4;
            }
        }
    }
    if (D_002960A8[0] != 0) {
        reg_a4 = (u8 *)(D_002960B0);
        reg_d7.w = 9;
        do {
            reg_d0.h[0] = *(u16 *)reg_a4;
            if (reg_d0.h[0] != 0) {
                reg_d0.h[0] &= 0xFF;
                reg_d0.h[0] *= 8;
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
                *(u8 *)(reg_a4 + 1) |= 1;
                if (reg_tmp.b[0] & 1) {
                    reg_d0.h[0] += 4;
                }
                if (!(*(u8 *)(reg_a4 + 1) & 2)) {
                    reg_a0 = (u8 *) D_002960A8[0];
                    reg_a0 += reg_d0.h[0];
                    reg_a0 = *(u8 **)reg_a0;
                    jtbl_0028E3F4 = (Fn)(reg_a0);
                    t2 = reg_d7.w;
                    jtbl_0028E3F4();
                    reg_d7.w = t2;
                }
            }
            reg_a4 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (D_00295F40[0] != 0) {
        reg_a4 = (u8 *)(D_00295F44);
        reg_d7.w = 9;
        do {
            reg_d0.h[0] = *(u16 *)reg_a4;
            if (reg_d0.h[0] != 0) {
                reg_d0.h[0] &= 0xFF;
                reg_d0.h[0] *= 8;
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
                *(u8 *)(reg_a4 + 1) |= 1;
                if (reg_tmp.b[0] & 1) {
                    reg_d0.h[0] += 4;
                }
                reg_a0 = D_00295F40[0];
                reg_a0 += reg_d0.h[0];
                reg_a0 = *(u8 **)reg_a0;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                t3 = reg_d7.w;
                jtbl_0028E3F4();
                reg_d7.w = t3;
            }
            reg_a4 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

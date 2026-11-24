#include "common.h"

extern void func_0018DD40(void);
extern s32 printf(const char *format, ...);
extern char D_0028BEB0[];
extern char D_0028BED0[];
extern u16 D_0028E3C0;
extern u16 D_0028E748;
extern u16 D_0028E750;
extern u16 D_0028E920;
extern s8 D_0028EC24;
extern u8 D_0028ED58;
extern u32 D_0028ED70_as_u32;
extern u8 D_0028ED74;
extern u8 D_0028ED78;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u16 D_006C58A4[];
extern u16 D_006C58A8[];
extern u8 D_006CB588[];
extern u8 D_006CB5A8[];

void func_00236F40(void) {
    u32 save_d6;
    u32 save_d7;
    u8 swap;
    u16 t0;
    u16 t6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    if (D_0028ED80 != 0) {
        return;
    }
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0xFF;
    reg_d1.h[0] &= 0xFF;
    reg_d6.h[0] &= 0xFF00;
    reg_d7.h[0] &= 0xFF00;
    switch (D_0028ED74) {
    case 0:
        D_0028ED70_as_u32 = 0;
        reg_d1.b[0] = 0x80;
        reg_d0.b[0] = 0x80;
        break;
    case 1:
        if (D_0028ED70_as_u32 == 0x1A5E0) {
            D_0028ED70_as_u32 = 0x1A5DF;
            printf(D_0028BEB0);
        }
        switch (D_0028ED7C) {
        case 0:
            break;
        case 2:
            if (D_0028ED70_as_u32 > 2 && D_0028ED58 == 0 && D_0028E3C0 == 0) {
                if (D_0028EC24 == 0) {
                    if (reg_d0.b[0] & 0x7F) {
                        D_0028ED58 = 1;
                    }
                } else if (reg_d1.b[0] & 0x7F) {
                    D_0028ED58 = 1;
                }
                if (D_0028ED58 != 0) {
                    func_0018DD40();
                    printf(D_0028BED0);
                }
            }
            if (D_0028ED58 != 0) {
                swap = 0;
                if (D_0028EC24 == 0) {
                    if (D_006C58A4[0] == 0xFF) {
                        swap = 1;
                    }
                } else if (D_006C58A8[0] == 0xFF) {
                    swap = 1;
                }
                if (swap) {
                    t0 = reg_d0.h[0];
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d1.h[0] = t0;
                    t6 = reg_d6.h[0];
                    reg_d6.h[0] = reg_d7.h[0];
                    reg_d7.h[0] = t6;
                }
            } else {
                if (D_0028ED78 != D_0028ED7C) {
                    D_0028ED7C = 0;
                }
                if (D_006C58A4[0] != 0xFF) {
                    reg_d0.b[0] = D_006CB5A8[D_0028ED70_as_u32] ^ D_006CB588[D_0028ED70_as_u32 & 0x1F];
                } else {
                    reg_d1.b[0] = D_006CB5A8[D_0028ED70_as_u32] ^ D_006CB588[D_0028ED70_as_u32 & 0x1F];
                }
                D_0028ED70_as_u32++;
            }
            break;
        case 1:
            if (D_0028ED78 != D_0028ED7C) {
                D_0028ED7C = 0;
            }
            if (D_006C58A4[0] != 0xFF) {
                D_006CB5A8[D_0028ED70_as_u32] = reg_d0.b[0];
            } else {
                D_006CB5A8[D_0028ED70_as_u32] = reg_d1.b[0];
            }
            D_006CB5A8[D_0028ED70_as_u32] ^= D_006CB588[D_0028ED70_as_u32 & 0x1F];
            D_0028ED70_as_u32++;
            if (D_0028E920 == 3 || D_0028E750 != 0 || D_0028E748 != 0) {
                D_0028ED7C = 0;
            }
            break;
        }
        break;
    case 3:
    case 2:
        break;
    }
    reg_d0.h[0] |= reg_d6.h[0];
    reg_d1.h[0] |= reg_d7.h[0];
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

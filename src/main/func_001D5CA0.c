#include "common.h"

typedef void (*Fn)();

extern u8 D_00263610[];
extern s8 D_0028E408;

s32 func_001D55B0();
s32 func_001D5670();
s32 func_00202140();
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D5CA0(void) {
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 *var_a0;
    u8 *var_a1;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0xAA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
        (*(u8 *)((u8 *)(reg_a6) + (0xB0))) -= 4;
        if ((s8) (*(u16 *)((u8 *)(reg_a6) + (0xB0))) < 0x11) {
            (*(u8 *)((u8 *)(reg_a6) + (0xB0))) = 0x10;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = 8U;
        var_a1 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(var_a1) + (0x4F)));
        if (reg_d0.b[0] != 0) {
            (*(s16 *)((u8 *)(var_a1) + (0x8A))) = 0x1008;
            (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = 0x10U;
            (*(u8 *)((u8 *)(reg_a6) + (0xB0))) = 8;
            (*(u16 *)((u8 *)(reg_a6) + (0xAA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
        }
        (*(u16 *)((u8 *)(reg_a6) + (0xAE))) = 0U;
        (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
    reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 1) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) += 4;
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) += 4;
                if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A))) >= 0x1C) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0x1CU;
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0x1CU;
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 2U;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xAB)));
            (*(u8 *)((u8 *)(reg_a6) + (0xAB))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0xAB))) = (*(u8 *)((u8 *)(reg_a6) + (0xAA)));
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
                if (reg_d0.b[0] != 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0xAA))) = 8;
                }
                reg_a4 = (u8 *)D_00263610;
                reg_a4 += (*(u16 *)((u8 *)(reg_a6) + (0xAE)));
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                reg_a4 = (u8 *) reg_tmp.w;
                (*(u16 *)((u8 *)(reg_a6) + (0xAE))) += 4;
                (*(u16 *)((u8 *)(reg_a6) + (0xAE))) &= 0x1F;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                    func_00202140();
                    if (D_0028E408 != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                    reg_d3.h[0] = temp_a0_2;
                    reg_a0 = reg_a6 + 0x20;
                    jtbl_0028E3F4 = (Fn)(reg_a4);
                    jtbl_0028E3F4();
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x46)));
                    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x48)));
                    func_00202140();
                    if (D_0028E408 != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
                    temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
                    reg_d3.h[0] = temp_a0_4;
                    reg_a0 = reg_a6 + 0x40;
                    jtbl_0028E3F4 = (Fn)(reg_a4);
                    jtbl_0028E3F4();
                }
                (*(u16 *)((u8 *)(reg_a6) + (0xAC))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0xAC))) == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 3U;
                    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x2000;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 3) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 4;
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)))) {
                    *(u16 *)var_a0 = 0;
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
                    goto block_29;
                }
            }
        }
    } else {
block_29:
        func_001D55B0();
    }
}

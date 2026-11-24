#include "common.h"

s32 func_00171490();
s32 func_00171520();
s32 func_00171770();
s32 func_00171820();
s32 func_001A3020();
s32 func_001ABB80();
s32 func_001ABD80();
s32 func_00201D10();
extern u8 D_002554B0[];
extern u8 D_0026B1C0[];
extern u8 D_0026B1D0[];
extern u8 D_0028DAC8[];
extern u8 D_0028E370;
extern s16 D_0028E5B0_as_s16;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern s16 D_0028E7A0;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern u8 D_0028ED5C;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_00171B90(void) {
    s32 temp_a1;
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 var_a0;
    u8 *var_a0_2;

    if ((*(s16 *)((u8 *)(reg_a6) + (0))) >= 0) {
        reg_a0 = (u8 *)D_0026B1D0;
        func_00171490();
        reg_a0 = (u8 *)D_0028DAC8;
        reg_d0.w = 1;
        func_00171520();
        reg_d0.h[0] = D_0028E918;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(D_0026B1C0 + temp_a1);
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)D_002554B0;
        func_001A3020();
    }
    var_a0 = 1;
    if ((*(u16 *)((u8 *)(reg_a4) + (0))) == 0) {
        (*(s16 *)((u8 *)(reg_a4) + (2))) = 1;
        D_0028E5B0_as_s16 = 0;
        if ((D_0028ED7C != 2) || (D_0028E91C != 0)) {
            if ((D_0029F260[0] < 0) && (D_0028E5FC == 0)) {
                func_001ABB80();
            }
            if ((D_0029F1F0[0] < 0) && (D_0028E5F8 == 0)) {
                func_001ABD80();
            }
        }
        D_0028E7A0 = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
        return;
    }
    if ((D_0028E370 != 0) && ((var_a0 = D_0028ED7C, (var_a0 != 2)) || (D_0028ED5C == 0)) && ((D_0028ED80 == 0) || (D_0028ED5C == 0))) {
        var_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if (var_a0 != 0) {
            temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
            if (temp_v1 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) (temp_v1 - 1);
                goto block_25;
            }
            if (var_a0 != 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                func_00201D10();
                (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    (*(s16 *)((u8 *)(reg_a6) + (0x10))) = 0;
                    (*(u16 *)((u8 *)(reg_a4) + (0))) -= 1;
                }
                goto block_25;
            }
        }
    } else {
block_25:
        func_00171770();
    }
    var_a0_2 = (u8 *)(reg_a6 + 0x20);
    reg_a6 = var_a0_2;
    if ((D_0028E370 != 0) && ((var_a0_2 = (void *) D_0028ED7C, (var_a0_2 != (void *)2)) || (D_0028ED5C == 0)) && ((D_0028ED80 == 0) || (D_0028ED5C == 0))) {
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if (temp_a0 != 0) {
            temp_v1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
            if (temp_v1_2 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) (temp_v1_2 - 1);
                goto block_35;
            }
            if (temp_a0 != 0) {
block_35:
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                func_00201D10();
                (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
                var_a0_2 = (u8 *)(reg_a6);
                reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (0x16)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (4)));
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    (*(u16 *)((u8 *)(var_a0_2) + (0x10))) = 0U;
                    (*(u16 *)((u8 *)(reg_a4) + (0))) -= 1;
                }
                goto block_39;
            }
        }
    } else {
block_39:
        func_00171820();
    }
}

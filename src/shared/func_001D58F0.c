#include "common.h"

s32 func_001D46A0();
s32 func_001D55B0();
s32 func_001D5670();
s32 func_001D5830();
extern u16 D_0028E8C8;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D58F0(void) {
    s32 var_a1;
    u16 temp_v1;
    u8 temp_a0;
    u8 *var_a0;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        var_a1 = 0x404;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
        (*(s16 *)((u8 *)(reg_a6) + (0x88))) = 0x404;
        (*(s16 *)((u8 *)(reg_a6) + (0x8A))) = 0x1020;
        (*(u16 *)((u8 *)(reg_a6) + (0x8C))) = 6U;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
        if (reg_d0.b[0] != 0) {
            (*(s16 *)((u8 *)(reg_a6) + (0x8A))) = 0x1008;
            (*(u16 *)((u8 *)(reg_a6) + (0x8C))) = 0x20U;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
    reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 1) {
            temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x8E)));
            if (temp_v1 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x8E))) = (u16) (temp_v1 - 1);
            } else {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) += 4;
                    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) += 4;
                    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A))) >= 0x1C) {
                        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0x1CU;
                        (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0x1CU;
                        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 2U;
                        func_001D5830();
                    }
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x89)));
            (*(u8 *)((u8 *)(reg_a6) + (0x89))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x89))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x88)));
                temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                if (temp_a0 != 8) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (temp_a0 + 1);
                }
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x8B)));
            (*(u8 *)((u8 *)(reg_a6) + (0x8B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                reg_d0.h[0] = 0x20;
                reg_d0.h[0] -= D_0028E8C8;
                (*(u8 *)((u8 *)(reg_a6) + (0x8B))) = (u8) reg_d0.b[0];
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
                if (reg_d0.b[0] != 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x8A))) = 8;
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x91)));
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d5.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                    reg_d4.w = 0;
                    func_001D46A0();
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x90)));
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    reg_d5.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
                    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
                    reg_d4.w = 0;
                    func_001D46A0();
                }
                (*(u16 *)((u8 *)(reg_a6) + (0x8C))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0x8C))) == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 3U;
                    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x2000;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 3) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 4;
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)))) {
                    *(u16 *)var_a0 = 0;
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
                    goto block_28;
                }
            }
        }
    } else {
block_28:
        func_001D55B0();
    }
}

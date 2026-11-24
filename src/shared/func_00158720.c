#include "common.h"

s32 func_0014D220();
s32 func_0014E290();
s32 func_00158B80();
s32 func_001594D0();
s32 func_0019C4B0();
s32 func_0019C530();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201710();
s32 func_00201C60();
extern u8 D_00258520[];
extern u16 D_0028E3A8_as_u16;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00158720(void) {
    s16 temp_v1_2;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u8 temp_v1;
    u8 var_a0_2;
    u8 *var_p;
    u8 *var_a0;

    func_00201C60();
    reg_d1.w = 0x5C;
    var_a0 = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        var_a0 = (u8 *)((void *) reg_d0.b[0]);
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] = (s32) var_a0 ^ reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 2) {
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x2400;
        }
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x36))) = 0x40U;
            (*(u16 *)((u8 *)(reg_a5) + (0x38))) = (u16) reg_d1.h[0];
            reg_d0.w = 0x234;
            func_001A91A0();
            var_a0 = (u8 *)((void *)0x8000);
            D_0028E3A8_as_u16 = 0;
            (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
            (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 1U;
            goto block_5;
        }
    } else {
block_5:
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    }
    func_001594D0();
    if ((*(u16 *)((u8 *)(reg_a5) + (0x36))) != 0) {
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x38)));
        func_00201710();
        (*(u16 *)((u8 *)(reg_a5) + (0x36))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a5) + (0x36))) == 0) {
            func_0014E290();
            return;
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) == 0) {
            return;
        }
        goto block_37;
    }
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) == 0)) {
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        if (((s16)(temp_a0) >= 0) && ((s32)(temp_a0 & 0xFFFF) < 0x6401)) {
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) = 1U;
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x23))) != 0) {
            temp_v1 = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
            if (temp_v1 != 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) (temp_v1 - 1);
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
            (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
                if ((s16)(temp_a0_2) < 0x80) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) (temp_a0_2 + 1);
                }
            }
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (temp_a1 + reg_d0.h[0]);
            temp_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (2)));
            if ((s32) temp_a0_3 >= 0x9800) {
                D_0028E3A8_as_u16 = 0;
                func_0014E290();
                return;
            }
            goto block_24;
        }
block_24:
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
            temp_v1_2 = (s16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            if ((temp_v1_2 >= 0) && (temp_v1_2 < 0x6601)) {
                (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
            (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 4;
                if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) >= 0x3C) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                }
            }
        }
        var_a0_2 = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
        if (var_a0_2 == 2) {
            if ((*(u16 *)((u8 *)(reg_a5) + (0x2C))) == 0) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
                (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    var_p = reg_a5;
                    (*(u8 *)((u8 *)(var_p) + (0x29))) = (u8) (*(u8 *)((u8 *)(var_p) + (0x28)));
                    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = 1U;
                    goto block_36;
                }
            } else {
block_36:
                func_00158B80();
            }
        }
        goto block_37;
    }
block_37:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1E))) == 0) {
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        reg_a0 = (u8 *)D_00258520;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xD800F200;
        reg_d3.h[0] = 0x2870;
        if ((*(u8 *)((u8 *)(reg_a5) + (0x22))) == 0) {
            func_0019C530();
        } else {
            func_0019C4B0();
        }
        reg_a0 = reg_a6;
        func_0014D220();
    }
}

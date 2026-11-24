#include "common.h"

extern s8 D_0028E408;

s32 func_00128AC0();
s32 func_0014EA50();
void func_00150510(u32);
void func_00150670(u8);
s32 func_00150730();
s32 func_00150F40();
s32 func_00171430();
s32 func_00201C60();
s32 func_00202180();
s32 func_00202490();
s32 func_00202D50();
extern u16 D_002578D0[];
extern u16 D_00257950[];
extern u16 D_0028E8A0;
extern u16 D_0028E8D8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001512D0(void) {
    u16 temp_a0_2;
    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        if (D_0028E8A0 != 0) {
            func_00150F40();
            return;
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) {
            func_00201C60();
            goto block_7;
        }
        func_0014EA50();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) >= 0x40) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1U;
            }
            if (((*(u16 *)((u8 *)(reg_a5) + (0x28))) != 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
                    func_00202490();
                    goto block_13;
                }
            } else {
block_13:
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                func_00150F40();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 != 0) {
                func_00150F40();
                return;
            }
            func_00202180();
            if (D_0028E408 != 0) {
                func_00150F40();
                return;
            }
            func_00150670(*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            func_00128AC0();
            func_00150F40();
        }
    }
}

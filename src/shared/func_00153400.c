#include "common.h"

extern s8 D_0028E408;

s32 func_00128AC0();
s32 func_0014EA50();
void func_00150510(u32);
void func_00150670(u8);
s32 func_00150730();
s32 func_00150F70();
s32 func_00171430();
s32 func_00201C60();
s32 func_00202180();
s32 func_00202490();
s32 func_00202500();
s32 func_00202D50();
extern u16 D_0028E8A0;
extern u16 D_0028E8D8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00153400(void) {
    u16 temp_a0_2;

    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E8A0 != 0) {
            func_00150F70();
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
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) -= 0x40;
            }
            if (((*(u16 *)((u8 *)(reg_a5) + (0x28))) != 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                    (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
                    func_00202490();
                    if (D_0028E408 != 0) {
                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    }
                }
            }
            func_00202180();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
            func_00202500();
            (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                func_00150F70();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 != 0) {
                func_00150F70();
                return;
            }
            func_00202180();
            if (D_0028E408 != 0) {
                func_00150F70();
                return;
            }
            func_00150670(reg_d1.b[0]);
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            func_00128AC0();
            func_00150F70();
        }
    }
}

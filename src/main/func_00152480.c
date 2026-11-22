#include "common.h"

extern s8 D_0028E408;

s32 func_00128AC0();
void func_00150510(u32);
void func_00150670(u8);
s32 func_00150730();
s32 func_00150F70();
s32 func_00171430();
s32 func_00201C60();
s32 func_00202180();
s32 func_00202500();
s32 func_00202D50();
extern u16 D_0028E3E4;
extern u16 D_0028E8A0;
extern u16 D_0028E8D8;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00152480(void) {
    u16 temp_a0;
    u8 temp_v0;
    u8 *var_a0;

    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E8A0 != 0) {
            func_00150F70();
            return;
        }
        func_00201C60();
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a5) + (0x19))) == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 == 0) {
                func_00202180();
                if (D_0028E408 == 0) {
                    func_00150670(reg_d1.b[0]);
                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    func_00128AC0();
                }
            }
        }
        var_a0 = (u8 *)(reg_a5);
        if ((*(u16 *)((u8 *)(var_a0) + (0x26))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
            (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 1U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 2;
                    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0x3008;
                    var_a0 = (u8 *)((void *) (*(u8 *)((u8 *)(reg_a5) + (0x23))));
                    (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = (s8) var_a0;
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x30U;
                }
            }
        } else {
            temp_v0 = (*(u8 *)((u8 *)(var_a0) + (0x1B)));
            if (temp_v0 != 0) {
                (*(u8 *)((u8 *)(var_a0) + (0x1B))) = (u8) (temp_v0 - 1);
            } else if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0x20) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
                (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 2;
                }
            }
        }
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E3E4 != 0) {
            func_00150F70();
            return;
        }
        func_00202180();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        func_00202500();
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        func_00150F70();
    }
}

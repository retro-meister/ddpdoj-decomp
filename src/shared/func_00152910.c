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

void func_00152910(void) {
    u16 temp_a0;

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
                    func_00150670(*(u8 *)((u8 *)(reg_a5) + (0x22)));
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

#include "common.h"

void func_001713F0(s32);

void func_00211FC0(void) {
    func_001713F0(0);
}

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
extern s32 D_0026F6A0[];
extern s32 D_0028DC94;
extern s32 *reg_a0_as_s32_p;

void func_00211FD0(void) {
    reg_a0_as_s32_p = D_0026F6A0;
    func_0014E370();
    reg_a0_as_s32_p = &D_0028DC94;
    reg_d0.w = 1;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    *(u16 *)(reg_a6 + 2) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = (u16) reg_tmp.h[0];
}

s32 func_00137C10();                            /* extern */
s32 func_0016A8E0();                            /* extern */
s32 func_0019BE80();                            /* extern */
s32 func_00203670();                            /* extern */
s32 func_002114C0();                            /* extern */

void func_00212030(void) {
    s64 temp_v0_2;
    u16 temp_v0;

    func_00203670();
    temp_v0 = *(u16 *)(reg_a5 + 0x18);
    if (temp_v0 != 0) {
        *(u16 *)(reg_a5 + 0x18) = (u16) (temp_v0 - 1);
    } else {
        func_0016A8E0();
        if (reg_d0.w & 0x40) {
            func_00137C10();
            temp_v0_2 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
            if ((temp_v0_2 < 4) && (temp_v0_2 >= 0)) {
                reg_d1.w = 0;
                reg_d0.h[0] *= 4;
                func_002114C0();
            }
        }
    }
    func_0019BE80();
}

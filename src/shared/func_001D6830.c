#include "common.h"

s32 func_00138A40();
s32 func_001D66A0();
s32 func_00201C60();
extern s16 D_0028E85C_as_s16;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D6830(s32 arg0) {
    s16 temp_v0;
    s32 var_a0;

    var_a0 = arg0;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        func_001D66A0();
        var_a0 = 0x600;
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x600;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 4;
            (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)))) {
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 2U;
            }
        }
    }
    if (((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 2) && ((*(s16 *)((u8 *)(reg_a6) + (2))) >= 0x6A00)) {
        func_00138A40();
        D_0028E85C_as_s16 = 0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 3U;
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 3) {
        temp_v0 = (*(s16 *)((u8 *)(reg_a6) + (2)));
        if ((temp_v0 < -0x63FF) && (temp_v0 > -0x6800)) {
            (*(s16 *)((u8 *)(reg_a5) + (0x30))) = 1;
        }
    }
    func_00201C60();
}

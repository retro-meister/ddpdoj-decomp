#include "common.h"

s32 func_0021BEA0(s32 *, s32, s32, s32 *); /* extern */
extern s32 D_00287040[];
extern s32 D_00287050[];
extern u8 D_0028E370;
extern u16 D_0028E3C0;
extern s8 D_0028E3F8;
extern u8 D_0028ED58;
extern u8 D_0028ED74;
extern u8 D_0028ED7C;
extern s32 D_00586FF0[];
extern u16 D_006C58A4[];

void func_002168B0(void) {
    s32 var_a2;
    s32 var_a2_2;

    if ((D_0028E370 != 0) && (D_0028E3F8 != 0) && (D_0028E3C0 == 0) && (D_0028ED74 == 1) && (D_0028ED7C == 2)) {
        if (D_0028ED58 != 0) {
            var_a2 = 0x88;
            if (D_006C58A4[0] == 0xFF) {
                var_a2 = 0x18;
            }
            func_0021BEA0(D_00586FF0, 2, var_a2, D_00287040);
            return;
        }
        var_a2_2 = 0x90;
        if (D_006C58A4[0] == 0xFF) {
            var_a2_2 = 0x20;
        }
        func_0021BEA0(D_00586FF0, 2, var_a2_2, D_00287050);
    }
}

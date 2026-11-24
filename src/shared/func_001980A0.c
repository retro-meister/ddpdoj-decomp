#include "common.h"

s32 func_0012FAB0();                            /* extern */
s32 func_00135ED0();                            /* extern */
s32 func_00137C20();                            /* extern */
s32 func_0013FD80();                            /* extern */
s32 func_0018DE90();                            /* extern */
s32 func_001981F0();                                /* extern */
s32 func_001984C0();                            /* extern */
s32 func_001A2FA0();                            /* extern */
s32 func_002071C0();                            /* extern */
s32 func_002075F0();                            /* extern */
extern s32 D_00269160_as_s32_a[];
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 D_0028E290;
extern s32 D_0028EAFC;
extern s32 *reg_a0_as_s32_p;

void func_001980A0(void) {
    func_0013FD80();
    func_00137C20();
    func_00135ED0();
    func_002075F0();
    func_0018DE90();
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0_as_s32_p = D_00269160_as_s32_a;
    func_001A2FA0();
    if ((s32) D_0028E258 < (s32) D_0028E25C) {
        D_0028E258 = D_0028E25C;
    }
    if (D_0028E290 == 2) {
        func_001984C0();
    } else if (func_001981F0() != 0) {
        func_001984C0();
    } else {
        D_0028EAFC = 0xFF;
    }
    reg_d0.h[0] = 8;
    func_002071C0();
    (*(s16 *)((u8 *)(reg_a0_as_s32_p) + (4))) = 0x12;
}

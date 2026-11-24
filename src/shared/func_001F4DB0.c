#include "common.h"

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001F4EB0();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s8 D_0028E408;
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001F4DB0(void) {
    func_001F4EB0();
    func_00124590();
    if (D_0028E408 != 0) {
        func_002035A0();
        func_0014E290();
        return;
    }
    reg_a0_as_s32 = reg_a6_as_s32;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x20;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x40;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x60;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x80;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xA0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xC0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x1A0;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x140;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x160;
    func_0014D220();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x180;
    func_0014D220();
#ifdef DEATH_LABEL
    reg_a0_as_s32 = reg_a6_as_s32 + 0x200;
    func_0014D220();
#endif
}

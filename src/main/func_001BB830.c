#include "common.h"

s32 func_0014E290();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001BB8E0();                            /* extern */
s32 func_002016D0();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s8 D_0028E408;
extern s32 reg_a0;
extern u8 *reg_a5;
extern s32 reg_a6;

void func_001BB830(void) {
    u16 temp_v0;

    func_001BB8E0();
    temp_v0 = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
    if (temp_v0 != 0) {
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) (temp_v0 - 1);
        func_002016D0();
    }
    func_00124590();
    if (D_0028E408 != 0) {
        func_002035A0();
        func_0014E290();
        return;
    }
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x60;
    func_0014D220();
}

#include "common.h"

s32 enemy_end_task();                           /* extern */
s32 func_00124590();                            /* extern */
s32 func_0014D220();                            /* extern */
s32 func_001CA730();                            /* extern */
s32 func_002035A0();                            /* extern */
extern s8 D_0028E408;
extern s32 reg_a0;
extern s32 reg_a6;

void func_001CA640(void) {
    func_001CA730();
    func_00124590();
    if (D_0028E408 != 0) {
        func_002035A0();
        enemy_end_task();
        return;
    }
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x40;
    func_0014D220();
    reg_a0 = reg_a6 + 0x60;
    func_0014D220();
    reg_a0 = reg_a6 + 0x80;
    func_0014D220();
    reg_a0 = reg_a6 + 0xA0;
    func_0014D220();
    reg_a0 = reg_a6 + 0xC0;
    func_0014D220();
    reg_a0 = reg_a6 + 0xE0;
    func_0014D220();
    reg_a0 = reg_a6 + 0x100;
    func_0014D220();
}

#include "common.h"

s32 func_00134660();                            /* extern */
s32 func_00134740();                            /* extern */
extern u8 *reg_a4;

void func_00134620(void) {
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) != 0) {
        func_00134740();
        return;
    }
    (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
    func_00134660();
}

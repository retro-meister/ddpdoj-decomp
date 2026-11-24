#include "common.h"

s32 func_00205DA0();                            /* extern */
s32 func_00205F30();                            /* extern */
extern u8 *reg_a1;

void func_00205EE0(void) {
    if ((*(u8 *)((u8 *)(reg_a1) + (1))) != 0) {
        func_00205F30();
        return;
    }
    func_00205DA0();
    func_00205F30();
}

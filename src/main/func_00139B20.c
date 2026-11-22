#include "common.h"

s32 func_00128660();                            /* extern */
s32 func_001368C0();                            /* extern */
s32 func_00139EB0();                            /* extern */
s32 func_0014D260();                            /* extern */
s32 func_0016AAB0();                            /* extern */
s32 func_001B82D0();                            /* extern */
s32 func_00209E60();                            /* extern */
s32 func_002114A0();                            /* extern */
extern u8 *reg_a5;

void func_00139B20(void) {
    func_0016AAB0();
    func_00128660();
    func_00139EB0();
    func_001B82D0();
    func_002114A0();
    func_001368C0();
    func_00209E60();
    func_0014D260();
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
}

#include "common.h"

s32 func_00217A20();                            /* extern */
s32 func_00217A30();                            /* extern */
s32 func_002184A0();                            /* extern */
extern s32 D_0028E98C;
extern s16 D_0028E990;
extern s16 D_0028E994;

void func_00122BE0(void) {
    D_0028E990 = 0xF0;
    D_0028E98C = 0;
    D_0028E994 = 0;
    func_002184A0();
    func_00217A20();
    func_00217A30();
}

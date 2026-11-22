#include "common.h"

s32 func_002071C0();                            /* extern */
s32 func_002075F0();                            /* extern */
extern s32 D_0028DE80;

void func_00200D30(void) {
    reg_d0.h[0] = 0xE;
    func_002071C0();
    (*(s16 *)((u8 *)(&D_0028DE80) + (8))) = 0;
    func_002075F0();
}

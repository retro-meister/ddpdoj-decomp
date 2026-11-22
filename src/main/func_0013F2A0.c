#include "common.h"

s32 func_0013EAF0();                            /* extern */
s32 func_0013F120();                            /* extern */
extern s8 D_0028E3F8;
extern u16 D_0028E5C0;
extern u16 D_0029CD90[];
extern u8 D_0029F261[];

void func_0013F2A0(void) {
    D_0028E3F8 = 1;
    if ((D_0028E5C0 != 0) || (!(D_0029F261[0] & 0x40) && (D_0029CD90[0] != 0))) {
        func_0013EAF0();
        func_0013F120();
        return;
    }
    func_0013EAF0();
}

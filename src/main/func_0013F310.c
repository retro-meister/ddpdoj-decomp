#include "common.h"

s32 func_0013EB60();                            /* extern */
s32 func_0013F190();                            /* extern */
extern s8 D_0028E3F8;
extern u16 D_0028E5BC;
extern u16 D_0029CD80[];
extern u8 D_0029F1F1[];

void func_0013F310(void) {
    D_0028E3F8 = 1;
    if ((D_0028E5BC != 0) || (!(D_0029F1F1[0] & 0x40) && (D_0029CD80[0] != 0))) {
        func_0013EB60();
        func_0013F190();
        return;
    }
    func_0013EB60();
}

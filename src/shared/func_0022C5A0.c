#include "common.h"

s32 overlay_flush();                            /* extern */
s32 func_0021D140(s32);                         /* extern */
extern u8 D_0028E268;
extern s32 D_0028ED10;

void func_0022C5A0(void) {
    if ((D_0028E268 != 0) && (D_0028ED10 != 0)) {
        func_0021D140(D_0028ED10 & 0xFFFF);
        overlay_flush();
    }
}

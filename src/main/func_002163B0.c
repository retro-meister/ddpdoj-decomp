#include "common.h"

s32 sceDevVif0Reset();                          /* extern */
s32 sceDevVu0Reset();                           /* extern */
s32 sceDmaReset(s32);                       /* extern */
s32 sceGsResetPath();                           /* extern */

void func_002163B0(void) {
    sceDevVif0Reset();
    sceDevVu0Reset();
    sceGsResetPath();
    sceDmaReset(1);
}

#include "common.h"

extern s8 D_0028E408;

s32 func_00130270();
s32 func_001303A0();
extern u8 D_0028E304;
extern u8 D_0028E7B4;
extern s32 D_0057CC70_as_s32_a[];
extern s32 D_0057CC74[];
void func_00169BC0(void) {
    D_0028E7B4 = 0;
    if (D_0057CC70_as_s32_a[0] & 0x20) {
        func_00130270();
        if (D_0028E408 == 0) {
            D_0028E7B4 |= 1;
        }
    }
    if (D_0057CC74[0] & 0x20) {
        func_001303A0();
        if ((D_0028E408 == 0) && ((D_0028E304 == 0) || (D_0028E7B4 == 0))) {
            D_0028E7B4 |= 2;
        }
    }    if (D_0028E7B4 != 0) { return; }
}

#include "common.h"

s32 func_0018D0A0(s32);                     /* extern */
s32 vibration_start_pad1(s32, s32);            /* extern */
extern s32 D_0028DF88;
extern s32 D_0028DF8C;

void func_0018D790(void) {
    D_0028DF8C = 0xE6;
    D_0028DF88 = 3;
    func_0018D0A0(0x12);
    vibration_start_pad1(0x8C, 0x4B0);
}

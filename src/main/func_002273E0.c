#include "common.h"

extern u16 D_0028E320;
extern s32 D_0057CC70[];
extern s32 D_0057CC74[];
extern s32 D_0057CC78[];

void func_002273E0(void) {
    D_0028E320 = 0xE10;
    if (D_0057CC78[0] == 0) {
        D_0028E320 -= 1;
        if (D_0028E320 == 0) {
            D_0057CC74[0] = 0x40;
            D_0057CC70[0] = 0x40;
            D_0057CC78[0] = 0x40;
        }
    } else {
        D_0028E320 = 0xE10;
    }
}

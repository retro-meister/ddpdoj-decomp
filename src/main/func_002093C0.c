#include "common.h"

extern s32 D_0028E498;
extern s32 D_0028E49C;
extern s32 bcd_result;
void func_0011C2B0(void);

void func_002093C0(void) {
    s32 value = 0x200002;

    D_0028E498 = value;
    value = 0;
    if ((s16)value <= (s16)bcd_result) {
        D_0028E498 = 0x3E0002;
    }
    D_0028E49C = value;
    bcd_result = 0;
    func_0011C2B0();
}

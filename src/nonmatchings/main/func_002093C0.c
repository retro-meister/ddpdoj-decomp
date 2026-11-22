#include "common.h"

extern s32 D_0028E498;
extern s32 D_0028E49C;
extern s32 bcd_result;

void func_0011C2B0(void);

void func_002093C0(void) {
    s32 status = 0x200002;
    D_0028E498 = status;
    if ((s16)0 <= bcd_result) {
        D_0028E498 = 0x3E0002;
    }
    D_0028E49C = 0;
    bcd_result = 0;
    func_0011C2B0();
}

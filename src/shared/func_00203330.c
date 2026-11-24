#include "common.h"

s32 func_002032F0();                            /* extern */
extern s32 *D_0028E448;
extern s32 D_0029F1F0[];
extern s32 D_0029F260[];
extern s32 *reg_a0;
extern s32 *reg_a1;
extern u8 *reg_a6;

void func_00203330(void) {
    reg_a0 = D_0029F260;
    reg_a1 = D_0029F1F0;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x2B))) != 0) {
        D_0028E448 = reg_a1;
        reg_a1 = reg_a0;
        reg_a0 = D_0028E448;
    }
    func_002032F0();
}

#include "common.h"

s32 func_0011C230();                            /* extern */
s32 func_0011C240();                            /* extern */
s32 func_0011C920();                            /* extern */
extern s32 D_0028E0D8[];
extern s32 D_0028E0DC[];
extern s16 D_0028E0E0[];
extern s16 D_0028E0E2[];
extern s32 D_0028E0E8[];
extern s32 D_0028E0EC[];
extern s32 D_0028E0F8[];
extern s32 D_0028E0FC[];
extern s16 D_0028E100[];
extern s16 D_0028E102[];
extern s32 D_0028E108[];
extern s32 D_0028E10C[];

void func_0011BEA0(void) {
    reg_d0.w = 0;
    func_0011C230();
    D_0028E108[0] = 0;
    reg_d0.w = 1;
    D_0028E10C[0] = 0;
    D_0028E0F8[0] = 0;
    D_0028E0FC[0] = 0;
    D_0028E100[0] = 0;
    D_0028E102[0] = 0;
    func_0011C240();
    D_0028E0E8[0] = 0;
    D_0028E0EC[0] = 0;
    D_0028E0D8[0] = 0;
    D_0028E0DC[0] = 0;
    D_0028E0E0[0] = 0;
    D_0028E0E2[0] = 0;
    func_0011C920();
}

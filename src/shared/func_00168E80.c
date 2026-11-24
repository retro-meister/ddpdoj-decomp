#include "common.h"

s32 func_0012FAB0();                            /* extern */
s32 func_0015BA20();                            /* extern */
s32 func_0015BBD0();                            /* extern */
s32 func_00168BA0();                            /* extern */
extern s8 D_0028DF84;
extern s16 D_0028E314_as_s16;
extern s16 D_0028E318_as_s16;
extern s8 D_0028E408;
extern u8 *reg_a5;

void func_00168E80(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        func_0012FAB0();
        func_0015BA20();
    }
    func_0015BBD0();
    if (D_0028E408 == 0) {
        D_0028E318_as_s16 = 1;
        D_0028E314_as_s16 = 1;
        reg_d0.h[0] = 5;
        D_0028DF84 = 0;
        func_00168BA0();
    }
}

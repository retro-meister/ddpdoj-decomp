#include "common.h"

s32 func_0016C260();
s32 func_00201BE0();
s32 func_00203060();
extern s8 D_0028E408;
extern u8 *reg_a6;

void func_0016C0C0() {
    func_00201BE0();
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    D_0028E408 = 0;
    func_00203060();
    if (D_0028E408 != 0) {
        func_0016C260();
    }
}

#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern s32 D_00271E00[];
extern s32 D_0028DDD4;
extern u16 D_0028ED10;
#pragma opt_propagation off
void func_00234250(s32 arg0, s32 arg1) {
    func_0022C5E0(0xB4, D_00271E00[arg1], 0, 0x14, 14, D_0028ED10, 100);
    if (arg0 == 1) {
        u16 t = D_0028ED10;
        func_0022C5E0(300, D_0028DDD4, 0, 0x14, 14, t, 100);
    }
}

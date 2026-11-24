#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern s32 D_00271F10[];
extern u16 D_0028ED10_as_u16;

void func_00234430(s32 index) {
    func_0022C5E0(0xC8, D_00271F10[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

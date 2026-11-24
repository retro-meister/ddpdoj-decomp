#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern u16 D_0028ED10_as_u16;
extern s32 D_00271F70[];

void func_00234370(s32 index) {
    func_0022C5E0(0xC8, D_00271F70[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

#include "common.h"

extern s32 D_00271EB0[];
extern u16 D_0028ED10_as_u16;
s32 func_0022C5E0(s32, s32, s32, s32, s32, s32, s32);

s32 func_00234580(s32 index) {
    return func_0022C5E0(0xC8, D_00271EB0[index], 0, 0x14, 0xE, D_0028ED10_as_u16, 0x64);
}

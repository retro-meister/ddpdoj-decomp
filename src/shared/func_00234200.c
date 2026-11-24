#include "common.h"

extern s32 D_0028DDC8;
extern u8 D_0028ECE8;
extern u16 D_0028ED10;

void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);

void func_00234200(void) {
    func_0022C5E0(0xC8, (&D_0028DDC8)[D_0028ECE8], 0, 0x14, 0xE, D_0028ED10, 0x64);
}

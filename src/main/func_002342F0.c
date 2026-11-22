#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern s32 D_00271E80[];
extern s32 D_0028DDE0[2];
extern u8 D_0028ECE8;
extern volatile u16 D_0028ED10;

void func_002342F0(s32 arg0) {
    func_0022C5E0(0xC8, D_0028DDE0[D_0028ECE8], 0, 0x14, 14, D_0028ED10, 100);
    func_0022C5E0(0xF0, D_00271E80[arg0], 0, 0x14, 14, D_0028ED10, 100);
}

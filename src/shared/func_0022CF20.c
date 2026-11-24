#include "common.h"

void func_0022C5E0(s32 x, char *text, s32 a, s32 b, s32 c, s32 d, s32 e);
extern char *D_00271E30[];
extern char *D_00271E50[];
extern char *D_0028DDC0[2];
extern s8 D_0028ECBC;
extern u8 D_0028ECE8;
extern u16 D_0028ED10;
extern s32 D_0028ED20;

void func_0022CF20(void) {
    if (D_0028ECBC != 0) {
        func_0022C5E0(0x64, D_00271E50[D_0028ED20], 0, 0x14, 0xE, D_0028ED10, 0x64);
    } else {
        func_0022C5E0(0x64, D_00271E30[D_0028ED20], 0, 0x14, 0xE, D_0028ED10, 0x64);
    }
    func_0022C5E0(0x78, D_0028DDC0[D_0028ECE8], 0, 0x14, 0xE, D_0028ED10, 0x64);
}

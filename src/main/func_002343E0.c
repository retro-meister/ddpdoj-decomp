#include "common.h"
extern s32 D_0028DE3C;
extern volatile u16 D_0028ED10;
void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
void func_002343E0(void) {
    u16 t = D_0028ED10;
    func_0022C5E0(0xC8, D_0028DE3C, 0, 0x14, 0xE, t, 0x64);
}

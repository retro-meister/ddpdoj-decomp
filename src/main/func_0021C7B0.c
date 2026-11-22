#include "common.h"
extern u8 *D_0028EA84;
extern u8 *D_0028EA88;
extern u8 *volatile D_0028EA8C;
extern s32 D_0028EA90;
extern s32 D_0028EA94;
extern u8 *D_0028EA9C;
void func_0021C7B0(s32 value) {
    u8 *base = D_0028EA9C;
    D_0028EA94 = value;
    D_0028EA90 = 0;
    D_0028EA88 = base;
    D_0028EA8C = base + 0x5DC800;
    D_0028EA84 = D_0028EA8C;
}

#include "common.h"

extern s8 D_0028E35C;
extern s8 D_0028E360;
extern u8 D_0028EA40;
extern s8 D_0028EA41;

extern s32 scePadSetActDirect(s64 port, s64 slot, u8 *mode);

void func_00217B30(void)
{
    s64 zero = 0;

    D_0028E360 = 0;
    D_0028E35C = 0;
    D_0028EA41 = 0;
    scePadSetActDirect(zero = 0, zero, &D_0028EA40);
    scePadSetActDirect(1, 0, &D_0028EA40);
}

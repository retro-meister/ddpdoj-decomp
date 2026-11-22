#include "common.h"

extern s16 D_0028EC18;
extern s8 D_0028EC1A;

extern s8 func_00227310(s16 *state);
extern void func_00222260(s32 command);

void func_002275C0(void)
{
    (void)*(volatile s8 *)&D_0028EC1A;
    D_0028EC1A = func_00227310(&D_0028EC18);
    func_00222260(7);
}

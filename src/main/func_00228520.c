#include "common.h"

extern s16 D_0028EC10;
extern s8 D_0028EC12;

extern s8 func_00227310(s16 *state);
extern void func_00222260(s32 mode);

void func_00228520(void)
{
    (void)*(volatile s8 *)&D_0028EC12;
    D_0028EC12 = func_00227310(&D_0028EC10);
    func_00222260(8);
}

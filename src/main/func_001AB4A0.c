#include "common.h"

extern u16 D_0028E610;
extern u16 D_0028E658;
extern s16 D_0028E65C;
extern s16 D_0028E660;
extern s32 D_0028E664;
extern s32 D_0028E668;
extern s32 D_0028E66C;
extern s16 D_0028E670;
extern s16 D_0028E674;
extern s16 D_0028E678;
extern s16 D_0028E67C;
extern s16 D_0028E680;
extern s16 D_0028E684;
extern s16 D_0028E688;
extern u32 D_0028E68C;
extern s32 D_0028E690;

void func_001AB4A0(void)
{
    u32 savedD0;
    u32 clearedHalfword;

    savedD0 = reg_d0.w;
    clearedHalfword = (D_0028E658 = 0);
    D_0028E664 = clearedHalfword;
    D_0028E668 = clearedHalfword;
    D_0028E66C = clearedHalfword;
    D_0028E690 = clearedHalfword;
    reg_d0.w = 0;
    D_0028E65C = 0;
    D_0028E660 = 0;
    D_0028E670 = 0;
    D_0028E674 = 0;
    D_0028E678 = 0;
    D_0028E67C = 0;
    D_0028E680 = 0;
    D_0028E684 = 0;
    D_0028E688 = 0;
    D_0028E610 = reg_d0.h[0];
    D_0028E68C = reg_d0.w;
    reg_d0.w = savedD0;
}

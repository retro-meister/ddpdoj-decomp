#include "common.h"

extern const char D_0012AE18[];
extern s32 D_0012B310;
extern u32 D_00132670[];
extern u32 D_00132674[];
extern u8 D_00135A80[];

extern s32 func_00118268(const char *format, ...);
extern void func_0011B5D0(void *buffer, u32 byteCount, u32 startSector);
extern void func_0011D510(s32 mode);

void func_0011D360(void)
{
    D_0012B310 = 0x1E40;
    func_0011B5D0(D_00135A80, D_00132670[0], D_00132674[0]);
    func_0011D510(2);
    func_00118268(D_0012AE18);
}

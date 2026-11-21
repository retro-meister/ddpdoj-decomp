#include "common.h"

extern u32 D_001A4F10[];
extern u32 D_001A4F14[];
extern u32 D_001A4F18[];
extern u32 D_001A4F30[];
extern u32 D_001A4F34[];
extern u32 D_001A4F38[];
extern u32 D_001A4F40[];
extern u32 D_001A4F44[];
extern u32 D_001A4F48[];
extern u32 D_001A4F60[];
extern u32 D_001A4F64[];
extern u32 D_001A4F68[];
extern u32 D_001A4F70[];
extern u32 D_001A4F74[];
extern u32 D_001A4F78[];
extern u32 D_001A4F80[];
extern u32 D_001A4F84[];
extern u32 D_001A4F88[];
extern u8 D_001A4F90[0xA8];
extern u8 D_001A5040[0x100];
extern u8 D_001A5140[0x100];

extern s32 func_0010C0E0(s32 mode);
extern s32 func_0010C340(s32 port, s32 slot, void *buffer);
extern void *func_00117060(void *destination, s32 value, u32 size);

void func_0011E120(void)
{
    func_00117060(D_001A4F90, 0, sizeof(D_001A4F90));

    D_001A4F88[0] = 0;
    D_001A4F78[0] = 0;
    D_001A4F68[0] = 0;
    D_001A4F48[0] = 0;
    D_001A4F38[0] = 0;
    D_001A4F18[0] = 0;

    D_001A4F84[0] = 0;
    D_001A4F74[0] = 0;
    D_001A4F64[0] = 0;
    D_001A4F44[0] = 0;
    D_001A4F34[0] = 0;
    D_001A4F14[0] = 0;

    D_001A4F80[0] = 0;
    D_001A4F70[0] = 0;
    D_001A4F60[0] = 0;
    D_001A4F40[0] = 0;
    D_001A4F30[0] = 0;
    D_001A4F10[0] = 0;

    func_0010C0E0(0);
    func_0010C340(0, 0, D_001A5040);
    func_0010C340(1, 0, D_001A5140);
}

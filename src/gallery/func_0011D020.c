#include "common.h"

extern char D_0012AE00[];
extern void *D_0012B300;
extern void *D_0012B30C;
extern u8 D_00132900[0x40];
extern u8 D_00132980[17][0x40];
extern u8 D_001A4A80[];

extern void *func_001160A8(u32 alignment, u32 size);
extern void func_00118268(const char *format, ...);
extern void func_0011C990(void);
extern void func_00101120(void *context, s16 resourceId, s32, s32, s32, s32, s32, s32);
extern void func_00103220(s32);
extern void func_00101308(void *context, void *destination);
extern void func_00100E08(s32, s32);
extern void func_0011E9E0(void);
extern void func_0011D170(void);

void func_0011D020(void)
{
    s32 resourceIndex;
    u8 (*resourceBuffer)[0x40];

    *(volatile u32 *)0x10000000 = 0;
    D_0012B300 = func_001160A8(0x40, 0x300000);
    func_00118268(D_0012AE00, D_0012B300, 0x2D9248);
    D_0012B30C = D_0012B300;
    func_0011C990();

    resourceBuffer = D_00132980;
    for (resourceIndex = 0; resourceIndex < 17; resourceIndex++, resourceBuffer++) {
        func_00101120(D_001A4A80, (s16)(0x37E8 + resourceIndex), 1, 0, 0, 0, 8, 2);
        func_00103220(0);
        func_00101308(D_001A4A80, *resourceBuffer);
        func_00100E08(0, 0);
    }

    func_00101120(D_001A4A80, 0x37FA, 1, 0, 0, 0, 8, 2);
    func_00103220(0);
    func_00101308(D_001A4A80, D_00132900);
    func_00100E08(0, 0);
    func_0011E9E0();
    func_0011D170();
}

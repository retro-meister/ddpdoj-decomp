#include "common.h"

s32 func_0018C580();
extern s32 func_0018C600(s32, s32, s32);
extern u8 D_0025BAC0[];
extern u8 D_0025BB00[];
extern u8 D_0025BB40[];
extern u8 D_0025BB80[];
extern u8 D_0025BBC0[];
extern u8 D_0025BC00[];
extern u8 D_0025BC40[];
extern s32 D_0028DF90;
extern s32 D_0029CA10_as_s32_a[];
extern s32 D_0029CA14_as_s32_a[];
extern s32 D_0029CA18_as_s32_a[];
extern s32 D_0029CA34[];
extern s32 D_0029CA38[];
extern s32 D_0029CA3C[];
extern s32 D_0029CA40[];
extern s32 D_0029CA5C[];

void func_0018C730(void) {
    func_0018C580();
    D_0029CA18_as_s32_a[0] = 0;
    D_0029CA10_as_s32_a[0] = 1;
    D_0028DF90 = 0;
    D_0029CA38[0] = 1;
    D_0029CA14_as_s32_a[0] = 1;
    D_0029CA3C[0] = 1;
    D_0029CA40[0] = 0;
    D_0029CA34[0] = 0;
    D_0029CA5C[0] = 0;
    func_0018C600(0xD0, 0, 0);
    func_0018C600(0x540, 0, 0);
    func_0018C600(0xA0, 0x3FFF3FFF, 0);
    func_0018C600(0xA1, 0x3FFF3FFF, 0);
    func_0018C600(0x80, 0x3FFF3FFF, 0);
    func_0018C600(0x81, 0x3FFF3FFF, 0);
    func_0018C600(0x550, (s32) D_0025BAC0, 0);
    func_0018C600(0x560, (s32) D_0025BB00, 0);
    func_0018C600(0x560, (s32) D_0025BB40, 0);
    func_0018C600(0x560, (s32) D_0025BB80, 0);
    func_0018C600(0x560, (s32) D_0025BBC0, 0);
    func_0018C600(0x560, (s32) D_0025BC00, 0);
    func_0018C600(0x560, (s32) D_0025BC40, 0);
}

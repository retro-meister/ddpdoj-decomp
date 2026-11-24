#include "common.h"

s32 func_0022C960(void);
s32 func_002345B0(void);
extern s8 D_0028E268_as_s8;
extern s32 D_0028ECC0;
extern s32 D_0028ECC4;
extern s32 D_0028ECCC;
extern s8 D_0028ECD8_as_s8;
extern s8 D_0028ECF0_as_s8;
extern s8 D_0028ECFC_as_s8;
extern s32 D_0028ED00;
extern s32 D_0028ED08;
extern s32 D_0028ED0C;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern u32 D_0028ED20_as_u32;
extern s32 D_006A0E40_as_s32_a4[4];

void func_0022C870(void) {
    D_0028E268_as_s8 = 1;
    D_0028ED10 = 0;
    D_0028ED08 = 0;
    D_006A0E40_as_s32_a4[0] = 0;
    D_006A0E40_as_s32_a4[1] = 0;
    D_006A0E40_as_s32_a4[2] = 0;
    D_006A0E40_as_s32_a4[3] = 0;
    D_0028ED0C = 0;
    D_0028ECC4 = 0;
    D_0028ECC0 = 0;
    D_0028ECD8_as_s8 = 0;
    D_0028ECF0_as_s8 = 0;
    D_0028ECCC = 0;
    D_0028ED00 = 0;
    D_0028ED18 += 1;
    switch (D_0028ED20_as_u32) {
    case 0:
        D_0028ECFC_as_s8 = 0xA;
        func_002345B0();
        func_0022C960();
        break;
    case 1:
    case 4:
    case 6:
    case 7:
        D_0028ECFC_as_s8 = 0x14;
        break;
    case 2:
        D_0028ECFC_as_s8 = 0x28;
        break;
    case 3:
        D_0028ECFC_as_s8 = 0;
        break;
    case 5:
        D_0028ECFC_as_s8 = 0x46;
        break;
    case 8:
        D_0028ECFC_as_s8 = 0x50;
        break;
    }
}

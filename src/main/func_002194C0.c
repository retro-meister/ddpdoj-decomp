#include "common.h"

void func_0021A170(void);
extern u8 D_0028E2F4;
extern s32 D_0028EA80;
extern s16 D_00592000[];
extern s16 D_00592002[];
extern s16 D_00592008[];
extern s16 D_0059200A[];
extern s16 D_00592010[];
extern s16 D_00592012[];
extern s16 D_00592018[];
extern s16 D_0059201A[];
extern s16 D_00592020[];
extern s32 D_00592024[];
extern s32 D_00592028[];
extern s16 D_0059202C[];
extern s16 D_0059202E[];
extern s16 D_00592030[];
void func_002194C0(void) {
    if (D_0028E2F4 != 0) {
        D_00592000[0] = 0;
        D_00592020[0] = 1;
        D_0059202E[0] = 0x80;
        D_0028EA80 = 1;
        D_00592024[0] = 0x2240;
        D_00592028[0] = 0x3836;
        D_00592030[0] = 0x80;
        D_0059202C[0] = 1;
        D_00592008[0] = 0;
        D_00592002[0] = 0x1C0;
        D_00592012[0] = 0x1C0;
        D_0059200A[0] = 0xE0;
        D_0059201A[0] = 0xE0;
        D_00592010[0] = 0;
        D_00592018[0] = 0;
        func_0021A170();
    }
}

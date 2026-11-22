#include "common.h"

s32 func_00131630();
s32 func_00134FB0();
s32 func_0013B190();
s32 func_00171910();
s32 func_00172060();
s32 func_001AD690();
s32 func_00217B30(s32, s32);
s32 func_002195D0();
extern s16 D_0028DFC0;
extern u8 D_0028E378;
extern s16 D_0028E958;
extern s16 D_0028E95C;
extern u8 D_0028E961;
extern u8 D_0028ED60;
extern u8 D_0028ED74;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C[];
extern s16 D_0029976E[];
extern u8 *reg_a5;

void func_00131700(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s8 *)((u8 *)(reg_a5) + (7))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (6))) = 4;
    D_0028E378 = 0xFF;
    func_00217B30(4, 1);
    func_002195D0();
    func_0013B190();
    func_00131630();
    func_001AD690();
    D_0028E961 |= 1;
    D_0028E961 |= 8;
    func_00171910();
    D_00299768[0] = 0;
    D_0028E95C = 1;
    D_0029976A[0] = 0;
    D_0028E958 = 1;
    D_0029976C[0] = 0;
    D_0029976E[0] = 0;
    func_00172060();
    func_00134FB0();
    D_0028ED60 = 0;
    D_0028DFC0 = 1;
    D_0028ED74 = 2;
}

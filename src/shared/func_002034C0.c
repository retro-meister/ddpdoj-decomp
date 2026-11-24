#include "common.h"

s32 func_0018D390();
s32 func_0020ECE0();
extern s16 D_0028DFBC;
extern u8 D_0028E855;
extern s16 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern s16 D_0029F260[];
extern u8 D_0029F261[];
void func_002034C0(void) {
    func_0020ECE0();
    func_0018D390();
    D_0028DFBC = 1;
    D_0028E855 |= 8;
    D_0028E855 &= 0xEF;
    if (*(s16 *)D_0029F260 < 0) goto block_1;
    if (!(D_0029F261[0] & 1)) goto next_1;
    if (*(u8 *)D_0029F260 & 0x80) goto next_1;
block_1:
    D_0029F261[0] |= 0x20;
next_1:
    if (*(s16 *)D_0029F1F0 < 0) goto block_2;
    if (!(D_0029F1F1[0] & 1)) goto next_2;
    if (*(u8 *)D_0029F1F0 & 0x80) goto next_2;
block_2:
    D_0029F1F1[0] |= 0x20;
next_2:
    return;
}

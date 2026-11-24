#include "common.h"

extern u8 D_0029CCE0[];
extern s32 D_0029CD40[];
extern s32 D_0029CD44[];
extern s32 D_0029CD48[];

extern s32 sceSifCallRpc(void *, s32, s32, void *, s32, void *, s32, s32, s64);

s32 func_0018C6C0(s32 command, s32 firstWord, s32 secondWord, s32 thirdWord)
{
    D_0029CD40[0] = firstWord;
    D_0029CD44[0] = secondWord;
    D_0029CD48[0] = thirdWord;

    sceSifCallRpc(D_0029CCE0, command, 0, D_0029CD40, 0x10,
                  D_0029CD40, 0x40, 0, 0);

    return D_0029CD40[0];
}

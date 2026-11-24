#include "common.h"

void sceSifInitRpc(s32);
s32 sceCdInit(s32);
void sceSifExitCmd(void);
s32 LoadExecPS2(void *, s32, s32);
extern u8 D_0026F6C0[];
extern u8 D_0026F700[];
extern u8 D_0026F740[];

void func_00212580(s32 mode) {
    sceSifInitRpc(0);
    sceCdInit(0);
    sceSifExitCmd();
    if (mode == 0) {
        LoadExecPS2(D_0026F6C0, 0, 0);
    } else if (mode == 1) {
        LoadExecPS2(D_0026F700, 0, 0);
    } else {
        LoadExecPS2(D_0026F740, 0, 0);
    }
}

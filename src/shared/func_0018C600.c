#include "common.h"

s32 sceSifCallRpc();
extern u8 D_0029CCE0[];
extern u8 *D_0029CD40[];
extern s32 D_0029CD44[];

u8 *func_0018C600(s32 arg0, u8 *arg1, s32 arg2) {
    s32 t = arg0 & 0xFFF0;

    if (t == 0x8020 || t == 0x550 || t == 0x560) {
        sceSifCallRpc(D_0029CCE0, arg0, 0, arg1, 0x40, D_0029CD40, 0x40, 0, 0);
    } else {
        D_0029CD40[0] = arg1;
        D_0029CD44[0] = arg2;
        sceSifCallRpc(D_0029CCE0, arg0, 0, D_0029CD40, 0x10, D_0029CD40, 0x40, 0, 0);
    }
    return D_0029CD40[0];
}

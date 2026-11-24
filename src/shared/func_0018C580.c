#include "common.h"

s32 sceSifInitRpc(s32);                     /* extern */
s32 sceSifBindRpc(s32 *, s32, s32);     /* extern */
extern s32 D_0029CCE0_as_s32_a[];
extern s32 D_0029CD04[];

s32 func_0018C580(void) {
    s32 temp_v0;
    s32 var_v1;

    sceSifInitRpc(0);
loop_1:
    if (sceSifBindRpc(D_0029CCE0_as_s32_a, 0x12345, 0) < 0) {
loop_2:
        goto loop_2;
    }
    var_v1 = 0x2710;
    do {
        temp_v0 = var_v1;
        var_v1 -= 1;
    } while (temp_v0 != 0);
    if (D_0029CD04[0] != 0) {
        return 1;
    }
    goto loop_1;
}

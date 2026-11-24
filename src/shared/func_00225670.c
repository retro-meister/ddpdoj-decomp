#include "common.h"

s32 sceCdBreak();                            /* extern */
extern s8 D_0028E374_as_s8;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 D_0028EC64;

void func_00225670(void) {
    D_0028EC64 = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    D_0028E374_as_s8 = 2;
    g_cd_async_busy = 1;
}

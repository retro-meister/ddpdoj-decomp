#include "common.h"
extern s32 func_0018C600(s32, s32, s32);
extern u8 D_0029CA14[];
extern u8 D_0029CA18[];
void func_0018CCA0(s32 arg0) {
    u32 v = func_0018C600(arg0 | 0x80B0, 0, 0) & ~0xFFF; if (v & 0x1000) {
        func_0018C600(arg0 | 0x60, 0, 0);
        *(s32 *)(D_0029CA14 + arg0 * 0x28) = 1;
        *(s32 *)(D_0029CA18 + arg0 * 0x28) = 0;
    }
}

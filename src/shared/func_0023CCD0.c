#include "common.h"

typedef union {
    u16 h[2];
    u32 w;
} HalfPair;

extern s32 D_0028ED88;

s32 func_0023CCD0(u16 *addr, u16 *starts, s32 *sizes, s32 count) {
    HalfPair target;
    HalfPair start;
    s32 i;
    s32 size;
    s32 j;
    u32 pos;

    u8 *hi = (u8 *)(addr + 1);

    target.h[1] = addr[0];
    target.h[0] = addr[1];
    if (target.w == 0) {
        return -1;
    }
    for (i = 0; i < count * 4; i += 4) {
        start.h[1] = starts[1];
        start.h[0] = starts[0];
        pos = start.w;
        size = *(s32 *)((u8 *)sizes + i);
        if (pos <= target.w && target.w < pos + size) {
            for (j = 0; j < size; j += 2) {
                if (pos == target.w) {
                    ((u8 *)addr)[1] = i;
                    ((u8 *)addr)[0] = j;
                    ((u8 *)addr)[3] = 0x81;
                    *hi = 0x99;
                    return 1;
                }
                pos += 2;
            }
        }
        starts += 2;
    }
    D_0028ED88 = 1;
    return 0;
}

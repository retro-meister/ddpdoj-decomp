#include "common.h"

s32 sceCdDiskReady(s32);                     /* extern */
s32 sceCdSearchFile(s32 *, s32);                /* extern */
extern s32 D_002C0100[];

void func_00216210(s32 arg0) {
    do {
        sceCdDiskReady(0);
    } while (sceCdSearchFile(D_002C0100, arg0) == 0);
}

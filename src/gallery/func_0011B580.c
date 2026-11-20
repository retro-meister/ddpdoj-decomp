#include "common.h"

extern u8 D_001328C0[];
extern s32 func_0010DCE0(void *, void *);
extern void func_0010E468(s32);

void func_0011B580(void *value) {
    s32 result;
    u32 retry;

    do {
        func_0010E468(0);
        result = func_0010DCE0(D_001328C0, value);
        retry = (u32)(result != 0);
        retry ^= 1;
    } while (retry != 0);
}

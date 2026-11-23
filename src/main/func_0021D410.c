#include "common.h"

void func_0021D410(u8 *buf) {
    u8 prev;
    u8 cur;
    s32 i;

    prev = buf[0];
    for (i = 1; i < 0x5533; i++) {
        cur = buf[i];
        buf[i] = (s8)cur - (s8)prev;
        prev = cur;
    }
}

#include "common.h"

void func_00218280(s8 *dst, s8 value, s32 count) {
    s32 current;
    s32 next;

    current = count;
    if (current != 0) {
        next = current - 1;
        do {
            *dst = value;
            current = next;
            dst += 1;
            next = current - 1;
        } while (current != 0);
    }
}

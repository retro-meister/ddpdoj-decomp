#include "common.h"

extern void *reg_a6_as_void_p;

void func_001D4620(void) {
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x86) = 1;
}

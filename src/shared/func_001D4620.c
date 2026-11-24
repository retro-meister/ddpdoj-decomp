#include "common.h"

extern void *reg_a6;

void func_001D4620(void) {
    *(s16 *)((u8 *)reg_a6 + 0x86) = 1;
}

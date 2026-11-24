#include "common.h"

extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;

void func_001CE540(void);

void func_001CE520(void) {
    *(s16 *)((u8 *)reg_a4_as_void_p + 2) = 0;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0xBE) = 0;
    func_001CE540();
}

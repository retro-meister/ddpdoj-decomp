#include "common.h"

extern void *reg_a4;
extern void *reg_a6;

void func_001CE540(void);

void func_001CE520(void) {
    *(s16 *)((u8 *)reg_a4 + 2) = 0;
    *(s16 *)((u8 *)reg_a6 + 0xBE) = 0;
    func_001CE540();
}

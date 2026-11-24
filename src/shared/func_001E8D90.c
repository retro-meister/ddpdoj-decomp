#include "common.h"

extern void *reg_a4;

void func_001E8DA0(void);

void func_001E8D90(void) {
    *(s16 *)((u8 *)reg_a4 + 2) = 1;
    func_001E8DA0();
}

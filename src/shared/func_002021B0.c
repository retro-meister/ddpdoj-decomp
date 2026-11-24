#include "common.h"

extern void *reg_a0_as_void_p;

void func_002021D0(void);

void func_002021B0(void) {
    u8 *base = (u8 *)reg_a0_as_void_p;
    reg_d2.h[0] = *(u16 *)(base + 0x2);
    reg_d3.h[0] = *(u16 *)(base + 0x4);
    func_002021D0();
}

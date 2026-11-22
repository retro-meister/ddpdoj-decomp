#include "common.h"

extern u16 reg_d2;
extern void *reg_a0;
extern u16 reg_d3;

void func_002021D0(void);

void func_002021B0(void) {
    u8 *base = (u8 *)reg_a0;
    reg_d2 = *(u16 *)(base + 0x2);
    reg_d3 = *(u16 *)(base + 0x4);
    func_002021D0();
}

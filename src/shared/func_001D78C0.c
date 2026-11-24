#include "common.h"

extern void *reg_a6;

void func_001D78C0(void)
{
    *(u16 *)((u8 *)reg_a6 + 0xC6) -= 1;
    if (0 > *(s16 *)((u8 *)reg_a6 + 0xC6)) {
        *(u16 *)((u8 *)reg_a6 + 0xC6) = 0x17;
    }
}

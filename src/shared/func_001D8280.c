#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D8280(s32 byteOffset)
{
    u8 *counter;

    *(u16 *)(reg_a4 + 4) = 0;
    *(u16 *)(reg_a4 + 6) = 1;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 10) = 0;
    counter = reg_a6 + byteOffset + (!(byteOffset & 1) ? 1 : -1);
    *counter += 1;
}

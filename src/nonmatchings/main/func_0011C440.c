#include "common.h"

extern u8 D_002B6D50[];
extern u8 *reg_a0;

void func_0011C440(void)
{
    u8 *table;
    u32 savedColumn;
    u32 savedRow;
    u8 *entry;

    reg_a0 = D_002B6D50;
    table = reg_a0;
    savedRow = reg_d0.w;
    savedColumn = ((volatile Reg32 *)&reg_d1)->w;

    reg_d0.h[0] <<= 6;
    reg_d0.h[0] += reg_d1.h[0];
    ((volatile Reg32 *)&reg_d1)->w = savedColumn;
    reg_d0.h[0] <<= 2;

    entry = table + reg_d0.h[0];
    reg_d0.w = savedRow;
    reg_a0 = entry;
}

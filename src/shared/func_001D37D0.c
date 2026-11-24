#include "common.h"

extern void func_001D3810(void);
extern s16 *reg_a4;
extern void *reg_a6;

void func_001D37D0(void)
{
    *reg_a4 = 0x1818;
    ((u8 *)reg_a6)[0x1B] = 0xC;
    ((u8 *)reg_a6)[0x1A] = 0xE;
    ((u16 *)reg_a6)[1] = 0x4400;
    ((u16 *)reg_a6)[2] = 0xEC00;
    func_001D3810();
}

#include "common.h"

extern s16 D_00296214[];
extern s16 *reg_a0;
void func_00124D10(void)
{
  s16 *savedAddressRegister;
  u32 savedDataRegister;
  s16 *firstEntry;
  savedDataRegister = reg_d0.w;
  firstEntry = D_00296214;
  savedAddressRegister = reg_a0;
  reg_d0.w = 4;
  if (reg_d0.w && reg_d0.w)
  {
  }
  reg_a0 = firstEntry;
  do
  {
    *reg_a0 = 0;
    reg_a0 += 0x10;
  }
  while (((s16) (--reg_d0.h[0])) >= 0);
  reg_a0 = savedAddressRegister;
  reg_d0.w = savedDataRegister;
}

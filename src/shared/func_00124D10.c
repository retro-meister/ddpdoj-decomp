#include "common.h"

extern s16 D_00296214_as_s16_a[];
extern s16 *reg_a0_as_s16_p;
void func_00124D10(void)
{
  s16 *savedAddressRegister;
  u32 savedDataRegister;
  s16 *firstEntry;
  savedDataRegister = reg_d0.w;
  firstEntry = D_00296214_as_s16_a;
  savedAddressRegister = reg_a0_as_s16_p;
  reg_d0.w = 4;
  if (reg_d0.w && reg_d0.w)
  {
  }
  reg_a0_as_s16_p = firstEntry;
  do
  {
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p += 0x10;
  }
  while (((s16) (--reg_d0.h[0])) >= 0);
  reg_a0_as_s16_p = savedAddressRegister;
  reg_d0.w = savedDataRegister;
}

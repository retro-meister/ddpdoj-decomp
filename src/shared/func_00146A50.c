#include "common.h"

extern u8 D_0029D710[];
extern u8 D_0029D750[];
extern u16 D_0029F1F4[];
extern u16 D_0029F220[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern char func_00146A90(u16 sourceValue);
inline int inline_fn(u16 arg0, u16 arg1, u16 arg2)
{
  return (arg0 && arg1) && arg2;
}

void func_00146A50(void)
{
  u16 sourceValue = D_0029F220[0];
  u16 new_var;
  u16 new_var3;
  int new_var2;
  reg_a0 = D_0029D750;
  new_var = sourceValue;
  new_var2 = 0;
  new_var3 = D_0029F1F4[0];
  reg_a1 = D_0029D710;
  if (!new_var)
  {
  }
  if (inline_fn(new_var, new_var, new_var))
  {
  }
  reg_d1.h[new_var2] = new_var;
  reg_d2.h[new_var2] = new_var3;
  func_00146A90(new_var);
}

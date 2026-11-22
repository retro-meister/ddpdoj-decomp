#include "common.h"

extern u8 D_0029D730[];
extern u8 D_0029D770[];
extern u16 D_0029F264[];
extern u16 D_0029F290[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern void func_00146A90(u16 value);
void func_001469E0(void)
{
  u16 value = D_0029F290[0];
  int new_var;
  reg_a0 = D_0029D770;
  if ((!new_var) && (!new_var))
  {
  }
  reg_d2.h[0] = (new_var = D_0029F264[0]);
  reg_a1 = D_0029D730;
  reg_d1.h[0] = value;
  func_00146A90(value);
}

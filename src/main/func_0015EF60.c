#include "common.h"

extern void func_001292C0(void);
void func_0015EF60(void)
{
  u32 saved_d0;
  reg_d6.h[0] = reg_d1.h[0];
  reg_d0.w = 0xFFFF000D;
  reg_d1.h[0] -= 2;
  func_001292C0();
  saved_d0 = reg_d0.w;
  reg_d0.w = saved_d0 + 0xFFFE0000;
  reg_d1.h[0] -= 5;
  func_001292C0();
  reg_d1.h[0] = reg_d6.h[0];
}

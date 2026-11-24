#include "common.h"

extern u8 *reg_a0;
extern u8 D_00295EA0[];
void func_00124F00(void)
{
  u8 *savedAddress;
  int new_var;
  u32 savedData;
  unsigned int new_var2;
  new_var2 = reg_d0.w;
  savedAddress = reg_a0;
  reg_a0 = D_00295EA0;
  reg_d0.h[0] *= 8;
  new_var = 0;
  reg_a0 += reg_d0.h[new_var];
  *((s16 *) reg_a0) &= ~1;
  reg_a0 = savedAddress;
  reg_d0.w = new_var2;
}

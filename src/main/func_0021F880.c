#include "common.h"

extern s32 func_00222530(s32);
extern volatile s8 D_0028EB04;
extern volatile s8 D_0028EB54;
extern volatile s8 D_0028EB58;
extern volatile s8 D_0028EB5C;
extern volatile s32 D_0028EB90;
void func_0021F880(void)
{
  s32 count;
  int new_var;
  if (func_00222530(0x18) != 0)
  {
    D_0028EB90 = 0x40;
    count = D_0028EB5C;
    D_0028EB58 = 0;
    D_0028EB54 = (new_var = 1);
    D_0028EB04 = 1;
    D_0028EB5C = count + 1;
  }
}

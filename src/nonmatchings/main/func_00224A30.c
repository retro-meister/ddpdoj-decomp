#include "common.h"

extern u16 D_0028E7BC;
extern u8 *reg_a0;
extern void func_0018D4B0(void);
extern void func_002071C0(void);
extern void func_00224A90(void);
void func_00224A30(void)
{
  u16 mode = D_0028E7BC;
  switch (mode)
  {
    case 1:
      break;

    default:
      if (mode == 0xF)
    {
      if (mode)
      {
        return;
      }
      else
      {
        return;
      }
    }
      func_00224A90();
      func_0018D4B0();
      reg_d0.h[0] = 8;
      func_002071C0();
      *((u16 *) (reg_a0 + 4)) = 0x12;
      break;

  }

}

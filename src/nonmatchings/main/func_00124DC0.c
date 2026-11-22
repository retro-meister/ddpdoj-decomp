#include "common.h"

extern u8 D_00295EA0[];
extern u8 *reg_a0;
void func_00124DC0(void)
{
  u8 *savedAddress;
  u32 tableAddress;
  u32 savedData;
  savedAddress = *((u8 * volatile *) (&reg_a0));
  tableAddress = *((volatile u16 *) (&reg_d0.h[0]));
  tableAddress = (u32) D_00295EA0;
  savedData = *((volatile u32 *) (&reg_d0.w));
  *((u8 * volatile *) (&reg_a0)) = (u8 *) tableAddress;
  tableAddress <<= 3;
  *((volatile u16 *) (&reg_d0.h[0])) = tableAddress;
  reg_a0 = (*((u8 * volatile *) (&reg_a0))) + reg_d0.h[0];
  *((s16 *) reg_a0) = (*((s16 *) reg_a0)) | 1;
  reg_a0 = savedAddress;
  reg_d0.w = savedData;
}

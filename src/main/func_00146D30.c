#include "common.h"

extern void func_00146DB0(u16 highWord);
extern void func_0018D7D0(void);
extern u16 D_0029F110[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];
extern u32 reg_a3;
extern u32 reg_a4;
void func_00146D30(void)
{
  u16 highWord = D_0029F112[0];
  reg_d0.h[1] = highWord;
  reg_a4 = (u32) D_0029F110;
  reg_d0.h[0] = D_0029F114[0];
  reg_a3 = (u32) func_0018D7D0;
  reg_d0.h[0] = D_0029F114[0];
  func_00146DB0(highWord);
}

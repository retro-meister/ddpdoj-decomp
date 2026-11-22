#include "common.h"

extern u32 D_0028EC18;
extern void *D_00270850[];
extern void func_00227440(void *state);
extern void func_002274C0(void *state, void **entries, s32 entryCount);
void func_002278D0(void)
{
  int new_var;
  func_00227440(&D_0028EC18);
  func_002274C0(&D_0028EC18, D_00270850, new_var = 7);
}

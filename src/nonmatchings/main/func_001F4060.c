#include "common.h"

extern void func_001F4090(u8);
extern void *work_reg_a4;
extern void *D_0028E450;

void func_001F4060(void) {
    u8 val;

    work_reg_0.w = 0;
    val = work_reg_0.b[0];
    *(u8 *)((u8 *)work_reg_a4 + 1) = val;
    *(u8 *)((u8 *)work_reg_a4 + 0) = val;
    *(u8 *)((u8 *)D_0028E450 + 0x1B) = 6;
    func_001F4090(val);
}

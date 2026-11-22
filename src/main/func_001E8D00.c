#include "common.h"

extern void *work_reg_a4;
extern void *D_0028E450;
void func_001E8D20(void);

void func_001E8D00(void) {
    ((u16 *)work_reg_a4)[1] = 1;
    *(u16 *)((u8 *)D_0028E450 + 0x12C) = 0;
    func_001E8D20();
}

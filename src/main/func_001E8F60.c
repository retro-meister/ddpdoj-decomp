#include "common.h"

extern void *work_reg_a4;
extern void *D_0028E450;
extern void func_001E8F80(void);

void func_001E8F60(void) {
    ((s16 *)work_reg_a4)[1] = 1;
    *(s16 *)((u8 *)D_0028E450 + 0x138) = 0;
    func_001E8F80();
}

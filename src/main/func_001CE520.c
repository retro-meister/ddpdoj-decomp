#include "common.h"

extern void *work_reg_a4;
extern void *D_0028E450;

void func_001CE540(void);

void func_001CE520(void) {
    *(s16 *)((u8 *)work_reg_a4 + 2) = 0;
    *(s16 *)((u8 *)D_0028E450 + 0xBE) = 0;
    func_001CE540();
}

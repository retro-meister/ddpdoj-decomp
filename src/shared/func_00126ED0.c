#include "common.h"

extern void *D_0028DE8C;
extern u32 D_0028DE90;
extern u32 D_0028DE94;
extern s8 D_0028E408;
extern u16 D_0028E988;
extern u8 *reg_a0;

void func_00126ED0(void) {
    reg_d1.w = D_0028DE94;
    D_0028E988 -= 1;
    (*(s16 *)((u8 *)(reg_a0) + (-6))) = 0;
    D_0028E408 = 0;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

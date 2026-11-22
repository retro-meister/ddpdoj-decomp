#include "common.h"

extern void func_0014E2C0(void);
extern s32 D_0028E450;
extern u8 *D_0028E454;
extern u16 D_0028E48A;

void func_0014E260(void) {
    u8 *src = D_0028E454;

    D_0028E48A = *(u16 *)(src + 6);
    *(u16 *)bcd_digits = *(u16 *)(src + 8);
    work_reg_0.w = 0;
    D_0028E450 = *(s32 *)bcd_digits;
    *(u16 *)&work_reg_1 = *(u16 *)(src + 4);
    func_0014E2C0();
}

#include "common.h"

extern s8 D_0028E408;
s32 func_00126F10();
extern u8 D_0028DE80;
extern u32 D_0028DE90;
extern u16 D_002BF4F0[];
extern u8 *reg_a0;

void func_00125F00(void) {
    u32 tmp;

    D_0028DE90 = reg_d7.w;
    *(u8 **) (&D_0028DE80 + 0xC) = reg_a0;
    reg_a0 = (u8 *) D_002BF4F0;
    reg_d7.h[0] = 0x45;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00126F10();
    D_0028E408 = 0;
    return;
next_1:
    reg_a0 += 0x2C;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    D_0028E408 = 1;
    reg_d7.w = D_0028DE90;
    reg_a0 = *(u8 **) (&D_0028DE80 + 0xC);
}

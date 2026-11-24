#include "common.h"

extern s8 D_0028E408;

s32 func_001AF310();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AF210(void) {
    reg_d7.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
loop_1:
    func_001AF310();
    if (D_0028E408 != 0) {
        reg_d7.b[0] += 1;
        if ((s8) reg_d7.b[0] > 2) {
            reg_d7.w = 0;
        }
        goto loop_1;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0xE))) = (u8) reg_d7.b[0];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
    reg_a4 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
    reg_a0 = (u8 *)(reg_tmp.w);
    *(u8 *)reg_a0 = *(u8 *)(reg_a5 + 0xE);
}

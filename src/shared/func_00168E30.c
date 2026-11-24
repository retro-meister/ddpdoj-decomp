#include "common.h"

s32 func_0012FBD0();                            /* extern */
s32 func_00168BA0();                            /* extern */
s32 func_0020ECE0();                            /* extern */
extern s8 D_0028E7B4_as_s8;
extern s16 D_0028E7B8_as_s16;
extern u8 *reg_a5;

void func_00168E30(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
    func_00168BA0();
    D_0028E7B4_as_s8 = 0;
    D_0028E7B8_as_s16 = 0;
    func_0012FBD0();
    func_0020ECE0();
}

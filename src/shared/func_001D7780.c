#include "common.h"

s32 func_00202140();                            /* extern */
s32 func_00202500();                            /* extern */
extern s8 D_0028E408;
extern u8 *reg_a6;

void func_001D7780(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
    func_00202140();
    if (D_0028E408 == 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x11A)));
        func_00202500();
        (*(u8 *)((u8 *)(reg_a6) + (0x11A))) = (u8) reg_d1.b[0];
    }
}

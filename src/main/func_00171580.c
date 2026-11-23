#include "common.h"

s32 func_00201D10();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_00171580(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) (*(u16 *)((u8 *)(reg_a6) + (0x10))) > (s32) reg_d0.h[0]) {
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) >>= 1;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) >>= 1;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if ((*(s16 *)((u8 *)(reg_a6) + (0x1E))) > (s16) reg_d0.h[0]) {
            (*(u16 *)((u8 *)(reg_a6) + (2))) = 0x3800U;
            (*(u16 *)((u8 *)(reg_a6) + (0x10))) = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

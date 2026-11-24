#include "common.h"

s32 func_002021D0();                            /* extern */
s32 func_002024F0();                            /* extern */
s32 func_00202B50();                            /* extern */
extern s8 D_0028E408;
extern u16 D_0029C068[];
extern u8 *reg_a6;

void func_001FF000(void) {
    reg_d0.h[0] = D_0029C068[0];
    reg_d3.h[0] -= reg_d0.h[0];
    func_00202B50();
    if (((s16) reg_d0.h[0] >= 0x200) || ((*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 8, (((s16) reg_d0.h[0] < 0x100) == 0)) || ((*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 6, (((s16) reg_d0.h[0] < 0x40) == 0))) {
        func_002021D0();
        func_002024F0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}

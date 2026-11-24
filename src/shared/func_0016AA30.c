#include "common.h"

extern void func_0016A8F0(void);
extern void func_0016CA20(void);
extern s8 D_0028E408;
extern u8 *reg_a0;

void func_0016AA30(void) {
    func_0016A8F0();
    do {
        if (*(u16 *)reg_a0 == 0) {
            func_0016CA20();
            D_0028E408 = 0;
            return;
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d2.h[0]) >= 0);
    reg_d2.w = 0;
    D_0028E408 = 1;
    reg_d2.h[0] -= 1;
}

#include "common.h"

s32 func_00236F40();
s32 func_0014A370();
extern u16 D_0028E1AC;
extern u16 D_0028E1B8;
extern u16 D_0028E248_as_u16_a[];
extern u8 D_0028E36C;
extern u8 *reg_a0;

void func_0016A710(void) {
    u32 t;
    u32 t2;

    if (D_0028E36C != 0) return;
    reg_a0 = (u8 *)D_0028E248_as_u16_a;
    reg_d0.h[0] = *(u16 *)reg_a0;
    t = reg_d0.h[0];
    reg_d1.h[0] = t;
    reg_d1.h[0] = (s32) reg_d1.h[0] >> 8;
    if (t & 1) {
        reg_d0.h[0] = (s32) t >> 1;
        reg_d0.h[0] |= 0x8000;
    } else {
        reg_d0.h[0] = (s32) t >> 1;
    }
    t2 = reg_d1.h[0];
    if (t2 & 1) {
        reg_d1.h[0] = (s32) (t2 & 0xFFFF) >> 1;
        reg_d1.h[0] |= 0x8000;
    } else {
        reg_d1.h[0] = (s32) (t2 & 0xFFFF) >> 1;
    }
    reg_d0.h[0] = ~reg_d0.sh[0];
    reg_d1.h[0] = ~reg_d1.sh[0];
    func_00236F40();
#ifdef DEATH_LABEL
    func_0014A370();
#endif
    D_0028E1B8 = reg_d0.h[0];
    D_0028E1AC = reg_d1.h[0];
}

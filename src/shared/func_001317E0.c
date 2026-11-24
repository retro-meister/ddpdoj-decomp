#include "common.h"

s32 func_00125E80();                            /* extern */
s32 func_00131630();                            /* extern */
s32 func_0013B190();                            /* extern */
s32 func_0013E7C0();                            /* extern */
s32 func_0013E850();                            /* extern */
s32 func_001AD720();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 D_0028E90C;
#endif
extern s16 D_0028E59C_as_s16;
extern s16 D_0028E854_as_s16;

void func_001317E0(void) {
    func_0013B190();
    func_00206D70();
    func_00131630();
    func_00125E80();
    func_001AD720();
    D_0028E854_as_s16 = 0;
    func_0013E7C0();
    func_0013E850();
    D_0028E59C_as_s16 = 0;
#ifdef DEATH_LABEL
    if (death_D_00290DC0 == 0) {
        reg_d0.h[0] = 7;
    } else {
        D_0028E90C = 1;
        reg_d0.h[0] = 0xE;
    }
#else
    reg_d0.h[0] = 7;
#endif
    func_002071C0();
}

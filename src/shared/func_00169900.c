#include "common.h"

s32 func_0012FAB0();                            /* extern */
s32 func_001A2FA0();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
extern s32 D_00269140_as_s32_a[];
extern s8 D_0028E290_as_s8;
extern s32 *reg_a0_as_s32_p;

#ifdef DEATH_LABEL
extern u8 D_0028E7B4;
extern u8 death_D_00290DC0;
#endif

void func_00169900(void) {
    D_0028E290_as_s8 = 2;
#ifdef DEATH_LABEL
    death_D_00290DC0 = 0;
#endif
    func_00206D70();
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0_as_s32_p = D_00269140_as_s32_a;
    func_001A2FA0();
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x15, 9);
    func_002071C0();
#ifdef DEATH_LABEL
    *((u8 *)reg_a0_as_s32_p + 5) = D_0028E7B4;
#endif
}

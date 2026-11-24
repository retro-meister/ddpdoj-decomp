#include "common.h"

s32 func_002071C0();                            /* extern */
#ifdef DEATH_LABEL
s32 func_00206D70();
extern u8 death_D_00290DC0;
#else
s32 func_002075F0();                            /* extern */
extern s32 D_0028DE80;
#endif

void func_00200D30(void) {
#ifdef DEATH_LABEL
    death_D_00290DC0 = 1;
    func_00206D70();
    reg_d0.h[0] = 0x15;
    func_002071C0();
#else
    reg_d0.h[0] = 0xE;
    func_002071C0();
    (*(s16 *)((u8 *)(&D_0028DE80) + (8))) = 0;
    func_002075F0();
#endif
}

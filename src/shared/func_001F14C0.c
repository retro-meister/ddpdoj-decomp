#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */
s32 func_001F1540(s32);                     /* extern */
s32 func_0020ED10();                            /* extern */
extern u16 D_0028E2E8;
extern u8 *reg_a4;

#ifdef DEATH_LABEL
extern s8 death_D_0029085C;
#endif

void func_001F14C0(void) {
#ifdef DEATH_LABEL
    death_D_0029085C = 0;
#endif
    reg_d0.w = 0;
    func_00124F50();
    reg_d0.w = 1;
    func_00124F50();
    reg_d0.w = 0;
    func_00124D90();
    func_0020ED10();
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x260;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x160;
    if (D_0028E2E8 == 0) {
        func_001F1540(0x260);
        return;
    }
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    func_001F1540(0x260);
}

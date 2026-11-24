#include "common.h"

s32 func_001F5BB0();
void func_00203400(void);
extern u16 D_0028E8A0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F5C90(void) {
#ifdef DEATH_LABEL
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0)) {
#else
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 1, (*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x78U;
            return;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x10A))) = 0;
        func_001F5BB0();
    }
}

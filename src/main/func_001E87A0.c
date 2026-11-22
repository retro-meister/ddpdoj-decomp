#include "common.h"

s32 func_001E8480();
void func_00203400(void);
extern u16 D_0028E8A0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E87A0(void) {
    if ((D_0028E8A0 == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x16D))) != 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 1, (*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0)) {
        func_00203400();
        if (reg_d0.h[0] == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0x78U;
            return;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x16A))) = 0;
        func_001E8480();
    }
}

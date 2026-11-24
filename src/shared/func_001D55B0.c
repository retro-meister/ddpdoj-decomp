#include "common.h"

extern s16 D_0028E884_as_s16;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D55B0(void) {
    (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = 0;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) != 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
        if (reg_d0.b[0] != 2) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            reg_d0.h[0] += 1;
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += 1;
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) &= 3;
            return;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if (reg_d0.h[0] == 5) {
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2U;
            return;
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 5U;
        return;
    }
    D_0028E884_as_s16 = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 6U;
}

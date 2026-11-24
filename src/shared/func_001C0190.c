#include "common.h"

s32 func_0014E030();
extern Reg32 D_0028E480;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C0190(void) {
    reg_d0.w = 0x32;
    func_0014E030();
    if (*(s16 *)(reg_a4 + 8) >= 0) {
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
        *(s8 *)(reg_a0 + 0x1B) = 0x30;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    } else {
        D_0028E480.h[1] = *(u16 *)(reg_a6 + 0xA2);
        D_0028E480.h[0] = *(u16 *)(reg_a6 + 0xA4);
        reg_d2.w = D_0028E480.w;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
        *(s8 *)(reg_a0 + 0x1B) = 0x30;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    }
    *(s16 *)reg_a4 = 0;
}

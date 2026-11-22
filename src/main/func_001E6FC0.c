#include "common.h"

s32 func_00202140();                            /* extern */
s32 func_00202500();                            /* extern */
extern u8 *reg_a6;

void func_001E6FC0(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    func_00202140();
    reg_d0.w = 0;
    reg_d1.b[0] += 0x14;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x9A))) = (u8) reg_d1.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    func_00202140();
    reg_d0.w = 0;
    reg_d1.b[0] += 0x2C;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0xBA))) = (u8) reg_d1.b[0];
}

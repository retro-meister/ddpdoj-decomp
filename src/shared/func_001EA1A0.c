#include "common.h"

s32 func_002010A0();
extern u16 D_002642E0[];
extern u32 D_0028D9D4;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EA1A0(void) {
    reg_a0_as_u16_p = D_002642E0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if ((*(u8 *)((u8 *)(reg_a6) + (0x13D))) != 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x13))) *= -1;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1D3)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1D4)));
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x15))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x14))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x17))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x16))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x19))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x18))) = (u8) reg_d0.b[0];
}

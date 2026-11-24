#include "common.h"

s32 func_002011A0();
extern u16 D_00264550[];
extern u32 D_0028D9F4;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001ECD10(void) {
    reg_a0_as_u16_p = D_00264550;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F0)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1F2)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1F4)));
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) += reg_d0.h[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x10))) = (u8) reg_d0.b[0];
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1F1))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x11))) *= -1;
    }
}

#include "common.h"

s32 func_001713C0();
s32 func_001D0E60();
extern u8 D_0026D1D0[];
extern u32 D_0028DBC0;
extern u16 D_0028DBC4[];
extern u32 D_0028DBC8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D0C80(void) {
    s32 temp_a1;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(D_0026D1D0 + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DBC0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DBC4);
    reg_d0.w = ((u32) D_0028DBC8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x118)));
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x117)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x116)));
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) += reg_d0.b[0];
    if ((s32) (*(u8 *)((u8 *)(reg_a4) + (5))) > 0xE) {
        reg_d0.b[0] = 0xE;
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) reg_d0.b[0];
    }
    func_001D0E60();
}

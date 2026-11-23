#include "common.h"

s32 func_001713C0();
s32 func_001CFF10();
extern u8 D_0026CF40[];
extern u32 D_0028DB94;
extern u16 D_0028DB98[];
extern u32 D_0028DB9C;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CFD70(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DB98);
    reg_d0.w = ((u32) D_0028DB9C >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026CF40 + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DB94 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12B)));
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x126)));
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12A)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= reg_d0.b[0];
    func_001CFF10();
}

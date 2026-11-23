#include "common.h"

s32 func_001713C0();
s32 func_001CF800();
extern u8 D_0026CE20[];
extern u32 D_0028DB7C;
extern u16 D_0028DB80[];
extern u32 D_0028DB84;
extern u16 D_0028DB88[];
extern u32 D_0028DB90;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CF5B0(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DB80);
    reg_d0.w = ((u32) D_0028DB84 >> 1) - 1;
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
    reg_a0 = *(u8 **)(D_0026CE20 + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DB7C >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DB88);
    reg_d0.w = ((u32) D_0028DB90 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x107)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x106)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) -= reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x108)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x10))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x14))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12A)));
    reg_d0.b[0] = (s8) reg_d0.b[0] * 8;
    (*(u8 *)((u8 *)(reg_a4) + (3))) += reg_d0.b[0];
    func_001CF800();
}

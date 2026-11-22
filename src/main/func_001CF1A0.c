#include "common.h"

s32 func_001713C0();
extern u8 D_0026CE00[];
extern u32 D_0028DB28;
extern u16 D_0028DB70[];
extern u32 D_0028DB78;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CF1A0(void) {
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026CE00 + (reg_d0.h[0] & ~3));
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB28 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DB70);
    reg_d0.w = ((u32) D_0028DB78 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x10B)));
    (*(u8 *)((u8 *)(reg_a4) + (2))) -= reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12A)));
    reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
    (*(u8 *)((u8 *)(reg_a4) + (3))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
}

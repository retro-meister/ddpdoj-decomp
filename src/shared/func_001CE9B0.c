#include "common.h"

s32 func_001713C0();
s32 func_002011A0();
extern u8 D_0026CC40[];
extern u32 D_0028DB20;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_001CE9B0(void) {
    s32 temp_a1;
    u16 *temp_a0;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(D_0026CC40 + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB20 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = 8;
    if (D_0028E910 != 0) {
        reg_d0.b[0] = 4;
    }
    (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x17))) = (u8) reg_d0.b[0];
    reg_d1.h[0] = 3;
    func_002011A0();
    if ((s8) reg_d0.b[0] < 0) {
        reg_d1.h[0] = 0xFFFD;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0x16))) = (u8) reg_d1.b[0];
    (*(s16 *)((u8 *)(reg_a4) + (0x18))) = 0x606;
}

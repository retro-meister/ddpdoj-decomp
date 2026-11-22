#include "common.h"


s32 func_0019C6D0();
extern u8 D_0026E350[];
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001B7D90(void) {
    u16 temp_a0;

    reg_a2 = D_0026E350;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
    reg_d2.h[0] += 7;
    reg_d2.h[0] = reg_d2.b[0] << 5;
    reg_a2 += reg_d2.h[0];
    reg_a2 += (*(u16 *)((u8 *)(reg_a6) + (0xAA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600F800;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBC)));
    func_0019C6D0();
}

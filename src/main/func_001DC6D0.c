#include "common.h"

s32 func_0019C4B0();
extern u8 D_0026EFD0[];
extern u8 D_0026EFF0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC6D0(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026EFD0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    func_0019C4B0();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x88)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF9400200;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    func_0019C4B0();
}

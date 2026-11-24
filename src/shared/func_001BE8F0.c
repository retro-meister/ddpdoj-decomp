#include "common.h"

s32 func_001BE270();
s32 func_002021F0(void *);
s32 func_00202500();
s32 func_00202B70(u16, void *);
extern u8 D_0026F480[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BE8F0(void) {
    u16 temp_a0;

    reg_a0 = D_0026F480;
    reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0(reg_a6);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_a0 = D_0026F480;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B70(temp_a0, reg_a6);
    if ((s16) reg_d0.h[0] < 0x201) {
        (*(u16 *)((u8 *)(reg_a4) + (6))) += 4;
        (*(u16 *)((u8 *)(reg_a4) + (6))) &= 0xF;
    }
    func_001BE270();
}

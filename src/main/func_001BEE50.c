#include "common.h"

s32 func_001BE270();
s32 func_00201D10();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202B70();
extern u8 D_0026F4A0[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BEE50(void) {
    u8 temp_v0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
    (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
        temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
        if (temp_v0 != 2) {
            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (u8) (temp_v0 - 1);
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x3B))) < 3) {
                (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = 2U;
            }
        }
    }
    reg_a0 = (u8 *)D_0026F4A0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x194)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x196)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x3A))) = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F4A0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x194)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x196)));
    reg_a0 += (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x201) {
        (*(u16 *)((u8 *)(reg_a4) + (6))) += 4;
        (*(u16 *)((u8 *)(reg_a4) + (6))) &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a6) + (0x194))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x196))) += reg_d3.h[0];
    func_001BE270();
}

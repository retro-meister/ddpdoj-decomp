#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
extern u8 D_00258400[];
extern u8 D_00258410[];
extern u16 D_0029C066[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00157E60(void) {
    reg_a0 = D_00258410;
    func_0014E370();
    reg_a0 = D_00258400;
    reg_d0.w = 6;
    func_0014E300();
    reg_tmp.w = 0x70000000;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_d1.w = 0;
    reg_d1.h[0] -= 0x800;
    reg_d1.h[0] -= D_0029C066[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
}

#include "common.h"

s32 func_00129410();
s32 func_001D7940();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DA070(s32 arg0, s32 arg1) {
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : *(u16 *)reg_a6;
    func_001D7940();
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d4.w = 0;
    func_00129410();
    reg_d1.b[0] += 3;
    func_00129410();
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : *(u16 *)reg_a6;
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d4.w = 0;
    func_00129410();
    reg_d1.b[0] += 3;
    func_00129410();
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : *(u16 *)reg_a6;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d4.w = 0;
    func_00129410();
    reg_d1.b[0] += 3;
    func_00129410();
}

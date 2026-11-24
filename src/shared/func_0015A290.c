#include "common.h"

extern s8 D_0028E408;

s32 func_00128970();
s32 func_00202140();
extern u8 D_00258740[];
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015A290(void) {
    u32 t1;

    reg_a4 = (u8 *)D_00258740;
    reg_d7.w = 5;
loop_1:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a4) + (0)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a4) + (2)));
    func_00202140();
    if (D_0028E408 == 0) {
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d4.w = 0;
        reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
        reg_d0.h[0] += 4;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = 5;
        reg_d0.h[1] = reg_tmp.h[0];
        func_00128970();
        reg_a4 += 4;
        t1 = reg_d7.h[0] - 1;
        reg_d7.h[0] = t1;
        if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
    }
}

#include "common.h"


s32 func_00124B20();
s32 func_00124D70();
s32 func_001BE270();
s32 func_002021F0();
s32 func_00202B70();
extern u8 D_0028DC84[];
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BEA80(void) {
    reg_a0 = D_0028DC84;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] -= D_0029C068[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_a0 = D_0028DC84;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] -= D_0029C068[0];
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x1401) {
        if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = 1U;
            (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
        }
        (*(s8 *)((u8 *)(reg_a4) + (3))) = 4;
        if ((s16) reg_d0.h[0] > 0x200) {
            func_001BE270();
            return;
        }
        (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
        reg_d0.w = 5;
        func_00124B20();
        func_00124D70();
        func_001BE270();
        return;
    }
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0x20;
    func_001BE270();
}

#include "common.h"

s32 func_0014E030();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CF320(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        reg_d0.h[0] = 0x9A;
        func_0014E030();
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[1] += 0x7FFF + 0x5C81;
        reg_d0.h[0] += 0x7FFF + 0x7801;
        (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
        reg_d0.b[0] = 0xD;
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x10A)));
        (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = 0x80;
        (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        (*(u16 *)((u8 *)(reg_a4) + (0xC))) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 8U;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if (reg_tmp.b[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        }
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        reg_d0.h[0] = 0x9A;
        func_0014E030();
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[1] += 0x7FFF + 0x5C81;
        reg_d0.h[0] += 0x800;
        (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
        reg_d0.b[0] = 0xD;
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x10A)));
        (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = 0x80;
        (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        (*(u16 *)((u8 *)(reg_a4) + (0xC))) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 8U;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if (reg_tmp.b[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
        }
    }
}

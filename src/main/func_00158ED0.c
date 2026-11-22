#include "common.h"

s32 func_00129280();
s32 func_001292C0();
s32 func_00158B40();
s32 func_00202590();
extern u8 *reg_a6;

void func_00158ED0(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x29)));
    (*(u8 *)((u8 *)(reg_a6) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x28)));
        reg_d7.w = 1;
        do {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2E)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x30)));
            func_00202590();
            (*(u8 *)((u8 *)(reg_a6) + (0x30))) = (u8) reg_d1.b[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x31)));
            func_00202590();
            (*(u8 *)((u8 *)(reg_a6) + (0x31))) = (u8) reg_d1.b[0];
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d4.w = 0;
        reg_d0.w = 0x160007;
        reg_d3.w = 0;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x30)));
        reg_d3.w = 0x078005C0;
        func_00129280();
        reg_d1.b[0] += 6;
        func_001292C0();
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x31)));
        reg_d3.w = 0x077FFA40;
        func_00129280();
        reg_d1.b[0] -= 6;
        func_001292C0();
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x2C))) == 0) {
            func_00158B40();
        }
    }
}

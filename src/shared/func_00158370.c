#include "common.h"

void func_0014E290(void);
void func_0014EA50(void);
void func_0019C610(void);
void func_0019C6D0(void);
extern Reg32 D_0028E484;
extern s8 enemy_move_end_requested;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00158370(void) {
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    if ((s16) reg_d2.h[0] >= 0x6000) {
        goto next_1;
    }
    if ((s16) reg_d2.h[0] <= -0x2800) {
        goto next_1;
    }
    if ((s16) reg_d1.h[0] <= -0x3C00) {
        goto next_1;
    }
    *(u8 *)(reg_a5 + 0x17) = 1;
    goto next_2;
next_1:
    if (*(u8 *)(reg_a5 + 0x17) == 0) {
        goto next_2;
    }
    func_0014E290();
    return;
next_2:
    func_0014EA50();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d2.w = 0x1CBB;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= 0x2800;
    reg_d7.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    if ((s16) reg_d7.h[0] <= -0x2800) {
        goto next_3;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_3;
    }
    if ((s16) reg_d6.h[0] <= -0x3C00) {
        goto next_3;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_3;
    }
    reg_d3.h[0] = 0x1EA0;
    func_0019C610();
next_3:
    reg_d2.w = 0x1CBC;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d7.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    if ((s16) reg_d7.h[0] <= -0x2800) {
        goto next_4;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_4;
    }
    if ((s16) reg_d6.h[0] <= -0x3C00) {
        goto next_4;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_4;
    }
    reg_d3.h[0] = 0x1EA0;
    func_0019C610();
next_4:
    reg_d2.w = 0x1CBD;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w -= 0x2C002000;
    reg_d7.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    if ((s16) reg_d7.h[0] <= -0x2400) {
        goto next_5;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_5;
    }
    if ((s16) reg_d6.h[0] <= -0x4000) {
        goto next_5;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_5;
    }
    reg_d3.h[0] = 0x2090;
    func_0019C6D0();
next_5:
    reg_d2.w = 0x1CBE;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w -= 0x2BFFFC00;
    reg_d7.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484.h[0];
    if ((s16) reg_d7.h[0] <= -0x2400) {
        return;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        return;
    }
    if ((s16) reg_d6.h[0] <= -0x4000) {
        return;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        return;
    }
    reg_d3.h[0] = 0x2090;
    func_0019C6D0();
}

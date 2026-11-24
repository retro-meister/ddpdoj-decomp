#include "common.h"

s32 func_0011C4A0();
s32 func_0011C610();
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u32 D_0028E428;
extern void *D_0028E42C;
extern u16 D_0028E474;
extern u8 *reg_a6;

void func_0013EC50(void) {
    u32 tmp;

    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 0;
    reg_d5.h[0] = 2;
    func_0011C610();
    reg_d1.h[0] += reg_d7.h[0];
    if ((s16) reg_d7.h[0] < 0) goto next_1;
    reg_d7.h[0] *= 2;
next_1:
    reg_d3.w = 1;
    reg_d6.w = 5;
    reg_d5.w = 0;
    reg_d5.b[0] = *(u8 *) (reg_a6 + 0x24);
    reg_d6.b[0] -= reg_d5.b[0];
    D_0028E474 = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = D_0028E474;
    reg_d5.b[0] = *(u8 *) (reg_a6 + 0x25);
    if (reg_d5.b[0] == 0) goto next_2;
    reg_d4.w = 0x02CC000A;
loop_1:
    func_0011C4A0();
    reg_d1.h[0] += reg_d7.h[0];
    reg_d5.w -= 0x10001;
    if (reg_d5.h[0] != 0) goto loop_1;
next_2:
    D_0028E474 = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = D_0028E474;
    D_0028E474 = reg_d5.h[0];
    reg_d5.h[0] -= 1;
    if (D_0028E474 == 0) goto next_3;
    reg_d4.w = 0x02C0000A;
loop_2:
    func_0011C4A0();
    reg_d1.h[0] += reg_d7.h[0];
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
next_3:
    if ((s8) reg_d6.b[0] < 0) goto next_4;
    reg_d4.w = 0x02C6000A;
loop_3:
    func_0011C4A0();
    reg_d1.h[0] += reg_d7.h[0];
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
next_4:
    reg_d4.w = 0x02D2000A;
    func_0011C4A0();
    reg_d0.w = D_0028E428;
    reg_d1.w = D_0028E424;
    reg_d2.w = D_0028E420;
    reg_d3.w = D_0028E41C;
    reg_d4.w = D_0028E418;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a6 = (u8 *)D_0028E42C;
}

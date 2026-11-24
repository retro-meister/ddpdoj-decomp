#include "common.h"

extern u8 D_0028E380;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u8 D_0028E390;
extern u8 D_0028E394;
extern u8 D_0028E398;
extern u8 D_0028E39C;

extern s8 D_0028E408;

void func_002095E0(void) {
    reg_d0.b[0] = D_0028E39C;
    if ((s8) reg_d0.b[0] > 0x12) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E398;
    if ((s8) reg_d0.b[0] > 0x1) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E394;
    if ((s8) reg_d0.b[0] > 0x1) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E390;
    if ((s8) reg_d0.b[0] > 0x2) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E38C;
    if ((s8) reg_d0.b[0] > 0x3) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E388;
    if ((s8) reg_d0.b[0] > 0x3) goto next_1;
    if (0 > (s16) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E384;
    if ((s8) reg_d0.b[0] > 0x4) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E380;
    if ((s8) reg_d0.b[0] > 0x1) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    D_0028E408 = 0;
    return;
next_1:
    D_0028E408 = 1;
}

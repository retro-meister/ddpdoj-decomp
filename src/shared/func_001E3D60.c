#include "common.h"

s32 func_00129370();
s32 func_002027A0();
extern u8 *D_0028E44C_as_u8_p;
extern Reg32 D_0028E474;
extern u16 D_0028E910;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E3D60(void) {
    u32 tmp;
    s32 tmp2;

    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x39);
    *(u8 *)(reg_a5 + 0x39) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    reg_d0.h[0] = 0x12;
    if (D_0028E910 == 0) goto next_1;
    reg_d0.h[0] += 4;
next_1:
    *(u8 *)(reg_a5 + 0x39) = reg_d0.b[0];
    reg_a0 = (u8 *)D_0029F260_as_u16_a;
    reg_a1 = (u8 *)D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_2;
    D_0028E44C_as_u8_p = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)D_0028E44C_as_u8_p;
next_2:
    if (*(s16 *)reg_a0 < 0) goto next_3;
    if (*(s16 *)reg_a1 >= 0) goto block_rts;
    D_0028E44C_as_u8_p = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)D_0028E44C_as_u8_p;
next_3:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d5.h[0] = 0;
    reg_d0.h[0] += reg_d5.h[0];
    D_0028E474.h[0] = reg_d5.h[0];
    reg_d5.h[0] = 0xFF00;
    reg_d5.h[1] = D_0028E474.h[0];
    reg_d5.h[0] += *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] += reg_d5.h[0];
    func_002027A0();
    reg_d0.w = 0xFFFD0013;
    reg_d7.w = 1;
    reg_d1.h[0] = 0x75;
    if (D_0028E910 == 0) goto loop_4;
    reg_d1.h[0] = 0x70;
loop_4:
    reg_d6.w = 3;
loop_5:
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d3.w = reg_d5.w;
    reg_d4.w = 0;
    func_00129370();
    reg_d1.h[0] += 2;
    tmp2 = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp2;
    if (((s64) ((s64) (u16) tmp2 << 0x30) >> 0x30) >= 0) goto loop_5;
    reg_d1.h[0] += 0xA;
    if (D_0028E910 == 0) goto next_6;
    reg_d1.h[0] += 0xA;
next_6:
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_4;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x3B);
    *(u8 *)(reg_a5 + 0x3B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a5 + 0x3B) = *(u8 *)(reg_a5 + 0x3A);
    *(u8 *)(reg_a5 + 0x39) = *(u8 *)(reg_a5 + 0x38);
block_rts:
    return;
}

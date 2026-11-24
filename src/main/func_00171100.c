#include "common.h"

s32 func_001A9130();
extern u16 D_00269430[];
extern u16 D_00269460[];
extern Reg32 D_0028E47C;
extern u16 D_0028E980;
extern u16 D_0028E984;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00171100(void) {
    u32 t;
    s32 t2;

    reg_d1.h[0] = D_0028E980;
    D_0028E984 += 1;
    if (D_0028E984 != 0xA) goto next_1;
    if ((s16) reg_d3.h[0] != 0) goto next_1;
    *(u8 *)(reg_a6 + 1) |= 0x20;
    D_0028E980 += 4;
next_1:
    reg_a0 = (u8 *)D_00269430;
    reg_d0.w = *(u32 *)((u8 *)D_00269430 + (reg_d1.h[0] & ~3));
    if (!(*(u8 *)(reg_a6 + 1) & 0x20)) goto next_2;
    reg_d0.w += reg_d0.w;
next_2:
    reg_a0 = (u8 *)D_00269460;
    *(u16 *)(reg_a6 + 0x10) = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x12) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((s16) reg_d4.h[0] == 0) goto next_5;
    if ((s16) reg_d5.h[0] == 0) goto next_5;
    if ((s16) reg_d5.h[0] < 0) goto next_5;
    *(u16 *)(reg_a6 + 0x1E) = reg_d5.h[0];
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    reg_d4.w = 3;
loop_3:
    D_0028E47C.w = 0;
    reg_d3.w = 0xF;
    reg_d3.h[0] &= reg_d5.h[0];
    D_0028E47C.h[0] = reg_d3.h[0];
    reg_d3.h[0] -= 1;
    D_0028E47C.w -= 1;
    if (D_0028E47C.h[1] != 0) goto next_4;
loop_4:
    func_001A9130();
    t2 = reg_d3.h[0] - 1;
    reg_d3.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_4;
next_4:
    reg_d5.h[0] >>= 4;
    reg_d0.w <<= 4;
    t = reg_d4.h[0] - 1;
    reg_d4.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
    return;
next_5:
    *(u16 *)(reg_a6 + 0x1E) = 1;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    func_001A9130();
}

#include "common.h"

typedef struct {
    s32 low;
    s32 high;
} Range;

s32 func_002010A0();
s32 func_00201C60();
s32 func_002024C0();
extern Range death_D_0028E4C0[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_00225360(u8 index) {
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < death_D_0028E4C0[index].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (death_D_0028E4C0[index].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5e00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
}

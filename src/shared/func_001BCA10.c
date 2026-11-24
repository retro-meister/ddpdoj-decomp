#include "common.h"

s32 func_001BC930();
s32 func_002011D0();
s32 func_00201E20();
extern u16 D_0028E470;
extern u32 D_0028E47C;
extern u32 D_0028E480;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a4 + (o)))
#define SW(o) (*(s16 *)(reg_a4 + (o)))
#define SW6(o) (*(s16 *)(reg_a6 + (o)))

void func_001BCA10(void) {
    if (reg_a5[0x1F] != 0) goto block_main;
    reg_d0.b[0] = reg_a5[0x1B];
    if (reg_d0.b[0] == 0) goto next_1;
    if (reg_a5[0x1A] == reg_d0.b[0]) goto next_1;
#ifdef DEATH_LABEL
    reg_a5[0x1D] -= 1;
    if ((s8) reg_a5[0x1D] >= 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_a5[0x1A] += 1;
    goto block_main;
next_1:
    if (reg_a5[0x19] != 0) goto next_3;
    reg_a5[0x1D] -= 1;
    if ((s8) reg_a5[0x1D] >= 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_a5[0x1A] -= 1;
    if ((s8) reg_a5[0x1A] > 0) goto block_main;
    if ((s8) reg_a5[0x20] >= 0) goto next_2;
#else
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if (reg_tmp.sb[0] > 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_a5[0x1A] += 1;
    goto block_main;
next_1:
    if (reg_a5[0x19] != 0) goto next_3;
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if (reg_tmp.sb[0] > 0) goto block_main;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_tmp.b[0] = reg_a5[0x1A];
    reg_a5[0x1A] -= 1;
    if (reg_tmp.sb[0] >= 2) goto block_main;
    if ((s8) reg_a5[0x20] <= 0) goto next_2;
#endif
    reg_a5[0x1F] = 1;
    func_002011D0();
    reg_d0.b[0] += 1;
    reg_d6.b[0] = reg_d0.b[0];
    reg_a4 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_a4[9] = 1;
        reg_a4[0x29] = reg_d6.b[0];
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
next_2:
    func_001BC930();
    goto block_main;
next_3:
    reg_a5[0x19] -= 1;
    if (reg_a5[0x19] != 0) goto block_main;
    reg_a5[0x1B] = 0;
    *(u16 *)(reg_a5 + 0x1C) = 0x404;
block_main:
    reg_d5.w = 0;
    reg_d5.b[0] = reg_a5[0x1A];
    if (reg_a5[0x18] == 0) goto next_4;
    reg_d5.h[0] *= 0xFFFF;
next_4:
    reg_a4 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_d0.h[0] = 0x70;
        reg_d1.w = 0;
        reg_d1.b[0] = reg_a4[0x1A];
        func_00201E20();
        reg_d6.h[1] = *(u16 *)(reg_a6 + 2);
        reg_d6.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d6.w += 0x02000000;
        W(2) = reg_d6.h[1];
        W(4) = reg_d6.h[0];
        reg_d1.h[0] = reg_d2.h[0];
        reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
        reg_d3.h[0] = reg_d3.sh[0] * 4;
        reg_d2.h[0] = reg_d2.sh[0] + reg_d1.sh[0];
        SW(2) += reg_d2.sh[0];
        SW(4) += reg_d3.sh[0];
        reg_d6.w = 0;
        reg_d6.b[0] = reg_a4[0x1B];
        D_0028E470 = (u16) reg_d6.sb[0];
        reg_d6.h[0] = D_0028E470;
        reg_d6.h[0] = reg_d6.sh[0] + reg_d5.sh[0];
        if ((s16) reg_d6.h[0] >= 0) {
            reg_d4.w = 1;
        } else {
            reg_d4.w = -1;
            reg_d6.h[0] *= 0xFFFF;
        }
loop_6:
        reg_d0.h[0] = 0x70;
        reg_d1.h[0] = reg_d4.h[0];
        reg_d1.b[0] += reg_a4[0x1A];
        reg_d1.h[0] = reg_d1.b[0];
        func_00201E20();
        reg_d1.h[0] = reg_d2.h[0];
        reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
        reg_d3.h[0] = reg_d3.sh[0] * 4;
        reg_d2.h[0] = reg_d2.sh[0] + reg_d1.sh[0];
        reg_d2.h[0] = reg_d2.sh[0] + SW6(2);
        reg_d2.h[0] = reg_d2.sh[0] + 0x200;
        reg_d3.h[0] = reg_d3.sh[0] + SW6(4);
        reg_d2.h[0] = reg_d2.sh[0] - SW(2);
        reg_d3.h[0] = reg_d3.sh[0] - SW(4);
        reg_d2.h[0] = reg_d2.sh[0] >> 4;
        reg_d3.h[0] = reg_d3.sh[0] >> 4;
        D_0028E480 = (s16) reg_d2.h[0];
        reg_d2.w = D_0028E480;
        D_0028E47C = (s16) reg_d3.h[0];
        reg_d3.w = D_0028E47C;
#ifdef DEATH_LABEL
        reg_d2.h[0] = reg_d2.sh[0] * reg_d6.sh[0];
        reg_d3.h[0] = reg_d3.sh[0] * reg_d6.sh[0];
#else
        reg_d2.h[0] = reg_d2.h[0] * reg_d6.h[0];
        reg_d3.h[0] = (s16) reg_d3.h[0] * reg_d6.h[0];
#endif
        SW(2) += reg_d2.sh[0];
        SW(4) += reg_d3.sh[0];
        if (reg_d6.sh[0] < 0x10) goto next_7;
#ifdef DEATH_LABEL
        reg_a4[0x1A] += reg_d4.b[0];
#else
        reg_a4[0x1A] = (s8) reg_a4[0x1A] + reg_d4.sb[0];
#endif
        reg_d6.h[0] -= 0x10;
        if (reg_d6.h[0] != 0) goto loop_6;
next_7:
        if (reg_d4.sh[0] >= 0) goto next_8;
        reg_d6.h[0] *= 0xFFFF;
next_8:
        reg_a4[0x1B] = reg_d6.b[0];
        reg_tmp.b[0] = reg_a4[0x2F];
        reg_a4[0x2F] -= 1;
        if ((s32) reg_tmp.b[0] > 0) goto next_9;
        reg_a4[0x2F] = reg_a4[0x2E];
        W(0x30) += 4;
        W(0x30) &= 0x7F;
next_9:
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

#include "common.h"

extern s8 D_0028E408;

s32 func_00128AC0();
void func_00150510(u32);
void func_00150670(u8);
s32 func_00150730();
s32 func_00150F70();
s32 func_00171430();
s32 func_00201C60();
s32 func_00202180();
s32 func_00202500();
s32 func_00202D50();
extern u16 D_0028E3E4;
extern u16 D_0028E8A0;
extern u16 D_0028E8D8;
extern u8 *reg_a5;
extern u8 *reg_a6;
#ifdef DEATH_LABEL
s32 func_00202490();
#endif

void func_00151EC0(void) {
    func_00150510(8);
    if (D_0028E408 != 0) return;
    func_00171430();
    if (D_0028E408 != 0) return;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    if (D_0028E8A0 != 0) {
        func_00150F70();
        return;
    }
    func_00201C60();
    if ((*(u16 *)((u8 *)(reg_a5) + (0x26))) != 0) goto next_4;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) goto next_1;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0) goto next_1;
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0x10;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    reg_d1.b[0] &= 0x3C;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x30;
next_1:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    if (D_0028E3E4 != 0) goto next_2;
    func_00202180();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a5) + (0x22))) = reg_d1.b[0];
next_2:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0) goto next_7;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 1;
    goto next_7;
next_4:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == MAIN_OR_DEATH_LABEL(0x1C, 0x20)) goto next_5;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += MAIN_OR_DEATH_LABEL(1, 2);
next_5:
#ifdef DEATH_LABEL
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) goto next_6;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
    func_00202490();
    func_00150F70();
    return;
#else
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) goto next_6;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d1.b[0] &= 0x3C;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    if ((*(u8 *)((u8 *)(reg_a5) + (0x23))) != reg_d1.b[0]) {
        func_00150F70();
        return;
    }
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1;
#endif
next_6:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00150F70();
    return;
next_7:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        func_00150F70();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= D_0028E8D8;
    reg_d0.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = reg_d0.b[0];
    func_00202D50();
    if (D_0028E408 != 0) {
        func_00150F70();
        return;
    }
    func_00202180();
    if (D_0028E408 != 0) {
        func_00150F70();
        return;
    }
    func_00150670(reg_d1.b[0]);
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    func_00128AC0();
    func_00150F70();
}

#include "common.h"

typedef void (*Fn)();

s32 func_001B82B0();
s32 func_00201F20();
s32 printf();
extern u8 D_00250780[];
extern u8 D_002507A0[];
extern u8 D_00262570[];
extern u8 D_0027F2F0[];
extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern Reg32 D_0028E484;
extern u16 D_0028E854_as_u16;
extern u16 D_0028E910;
extern u8 D_0029A530_as_u8_a[];
extern u16 D_0029AA30[];
extern u16 D_0029C06C[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B8440(void) {
    u32 cnt;
    s32 cnt2;
    u16 swp;
    u8 *save;
    u8 *p;
    s32 idx;

    reg_d7.h[0] = D_0029AA30[0];
    if (reg_d7.h[0] == 0) goto block_rts;
    reg_d7.h[0] -= 1;
    if (D_0028E910 != 0) {
        reg_a6 = (u8 *)D_0029A530_as_u8_a;
        goto next_clr;
    }
    reg_d5.w = 0;
    reg_d6.h[0] = D_0028E3E0;
    reg_d6.h[0] *= 0xFFFF;
    reg_tmp.w = reg_d6.w;
    reg_d6.h[0] = D_0028E3EC;
    reg_d6.h[1] = reg_tmp.h[0];
    if (D_0028E854_as_u16 == 0) goto next_1;
    reg_d5.h[0] = 0x8000;
next_1:
    reg_tmp.w = reg_d5.w;
    reg_d5.h[1] = reg_tmp.h[0];
    reg_d5.h[0] = D_0028E3F0;
    reg_a6 = (u8 *)D_0029A530_as_u8_a;
    goto loop_2;
next_2:
    reg_a6 += 0x40;
loop_2:
    reg_d0.b[0] = reg_a6[1];
    if (reg_d0.b[0] == 0) goto next_2;
    reg_a2 = reg_a6 + 2;
    reg_a4 = reg_a6 + 0x1A;
    if (0 <= (s64) *(s16 *)(reg_a6 + 0x1E)) goto next_3;
    if (0 <= (s64) (s32) reg_d5.w) goto next_dir;
    goto next_boss;
next_3:
    reg_d0.b[0] = reg_a4[1];
    if (reg_d0.b[0] == 0) goto next_4;
    reg_d1.w = 1;
    if (reg_d0.b[0] > 8) goto next_5;
    if (reg_d0.b[0] < 6) goto next_6;
    reg_d1.w = 3;
next_5:
    reg_d1.h[0] &= reg_d5.h[0];
    if (reg_d1.h[0] != 0) goto next_6;
    reg_a4[1] -= 1;
next_6:
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = reg_a4[1];
    reg_d1.b[0] = reg_a6[0x1A];
    goto next_speed;
next_ret:
    *(u16 *)(reg_a2 + 0) += reg_d2.h[0];
    reg_d0.h[0] = reg_d3.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d3.h[0] -= reg_d0.h[0];
    *(u16 *)(reg_a2 + 2) += reg_d3.h[0];
next_4:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a4[1];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] -= 0x58;
    *(u16 *)(reg_a2 + 0) += reg_d1.h[0];
next_7:
    reg_d1.h[0] = D_0029C06C[0];
    *(u16 *)(reg_a2 + 2) -= reg_d1.h[0];
    if (0 > (s64) (s32) reg_d6.w) goto next_anim;
    reg_d1.h[1] = *(u16 *)(reg_a2 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC000;
    reg_d1.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d1.h[0] += 0x7FFF + 0x4001;
    if (reg_tmp.h[1] != 0) goto next_clr;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x8400;
    reg_tmp.w = reg_d1.w;
    swp = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d1.h[1] = swp;
    reg_d1.h[0] += 0x600;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d1.h[0] += 0x7FFF + 0x401;
    if (reg_tmp.h[1] != 0) goto next_clr;
    goto next_anim;
next_set:
    if (*(u16 *)(reg_a6 + 0x22) == 0) goto next_8;
    *(u16 *)(reg_a6 + 0x22) -= 1;
    reg_a0 = (u8 *)D_00250780;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    jtbl_0028E3F4 = reg_a0;
    ((Fn) jtbl_0028E3F4)();
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_8:
    reg_a6[0x18] -= 1;
    if (reg_a6[0x18] == 0) goto next_clr;
    if (reg_d6.h[0] == 0) goto next_9;
    reg_a0 = (u8 *)D_00250780;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    jtbl_0028E3F4 = reg_a0;
    ((Fn) jtbl_0028E3F4)();
next_9:
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_clr:
    func_001B82B0();
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_dir:
    if (reg_a4[1] <= 2) goto next_10;
    reg_d1.w = 0;
    if (reg_a4[1] > 8) goto next_11;
    if (reg_a4[1] < 6) goto next_12;
    reg_d1.w = 3;
next_11:
    reg_d1.h[0] &= reg_d5.h[0];
    if (reg_d1.h[0] != 0) goto next_12;
    reg_a4[1] -= 1;
next_12:
    save = reg_a2;
    func_00201F20();
    reg_a2 = save;
next_10:
    *(u16 *)(reg_a2 + 0) -= 0x20;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    goto next_7;
next_boss:
    save = reg_a2;
    func_00201F20();
    reg_a2 = save;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d1.w = 0;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    reg_d1.b[0] = reg_a6[0x21];
    *(u16 *)(save + 0) -= reg_d1.h[0];
    if (0 > (s64) (s32) reg_d6.w) goto next_anim;
    reg_d1.h[1] = *(u16 *)(reg_a2 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC000;
    reg_d1.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d1.h[0] += 0x7FFF + 0x4001;
    if (reg_tmp.h[1] != 0) goto next_13;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x9000;
    reg_tmp.w = reg_d1.w;
    swp = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d1.h[1] = swp;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d1.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] != 0) goto next_13;
    goto next_anim;
next_13:
    func_001B82B0();
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_speed:
    idx = reg_d1.h[0] * 2;
    reg_d3.h[0] = *(u16 *)(D_002507A0 + idx);
    p = D_00262570 + reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(p + 0);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(p + 2);
    reg_d2.w = (s32) reg_d2.w >> 4;
    reg_d1.h[0] &= 0xC0;
    reg_d3.w = (s32) reg_d3.w >> 4;
    if (reg_d1.h[0] == 0) goto next_ret;
    if (reg_d1.h[0] != 0x40) goto next_14;
    reg_d2.h[0] *= 0xFFFF;
    goto next_ret;
next_14:
    if (reg_d1.h[0] != 0x80) goto next_15;
    reg_d2.h[0] *= 0xFFFF & 0xFFFF;
    reg_d3.h[0] *= 0xFFFF;
    goto next_ret;
next_15:
    if (reg_d1.h[0] != 0xC0) goto next_16;
    reg_d3.h[0] *= 0xFFFF;
    goto next_ret;
next_16:
    printf(D_0027F2F0);
    goto block_rts;
next_anim:
    reg_d2.w = 3;
    if (reg_a4[1] > 0xD) goto next_17;
    reg_d2.w = 1;
    if (reg_a4[1] > 9) goto next_17;
    reg_d2.w = 0;
next_17:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x10);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x14);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x16);
    reg_a0 = (u8 *) reg_tmp.w;
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    idx = reg_d0.h[0] + 2;
    *(u16 *)(reg_a6 + 0xC) = (idx) ? *(u16 *)(reg_a0 + ((s16) idx & ~1)) : *(u16 *)reg_a0;
loop_18:
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x10);
    *(u16 *)(reg_a6 + 0x10) -= 4;
    if (reg_tmp.h[0] > 3) goto next_19;
    *(u16 *)(reg_a6 + 0x10) = *(u16 *)(reg_a6 + 0x12);
next_19:
    cnt2 = reg_d2.h[0] - 1;
    reg_d2.h[0] = cnt2;
    if (((s64) ((s64) (u16) cnt2 << 0x30) >> 0x30) >= 0) goto loop_18;
    goto next_set;
block_rts:
    return;
}

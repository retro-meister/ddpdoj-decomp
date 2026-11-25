#include "common.h"
#include "entity.h"

void func_0019E980(void);


void func_0019DC20(void) {
    *(u16 *)(reg_a6 + 0x52) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x52) < 0) {
        *(u16 *)(reg_a6 + 0x52) = 8U;
    }
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x52);
}

void func_0019DC60(void) {
    *(u16 *)(reg_a6 + 0x52) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x52) < 0) {
        *(u16 *)(reg_a6 + 0x52) = 8U;
    }
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x52);
}

void func_0019DCA0(void) {
    *(u16 *)(reg_a6 + 0x52) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x52) < 0) {
        *(u16 *)(reg_a6 + 0x52) = 8U;
    }
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x52);
}

void func_0019DCE0(void) {
    *(u16 *)(reg_a6 + 0x54) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x54) < 0) {
        *(u16 *)(reg_a6 + 0x54) = 8U;
    }
    reg_d7.h[0] = *(u16 *)(reg_a6 + 0x54);
}


void func_0019DD20(void) {
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += *(u16 *) reg_a1;
    reg_a1 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[0] += *(u16 *) reg_a1;
    reg_a1 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a5 = (u8 *) reg_tmp.w;
    reg_d0.w = 0;
    *(u16 *) reg_a0 = (reg_d6.h[0]) ? *(u16 *) (reg_a5 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a5;
    reg_a0 += 2;
    *(u16 *) reg_a0 = ((u16) reg_d6.h[0] + 2) ? *(u16 *) (reg_a5 + ((s16) ((u16) reg_d6.h[0] + 2) & ~1)) : *(u16 *) reg_a5;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *) (reg_a0 - 2) = *(u8 *) (reg_a4 + 0x57);
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) (reg_a4 + 0x5A);
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) (reg_a4 + 0x20);
    reg_a0 += 2;
}

s32 entity_draw_keep();
extern u8 option_shot_lists_1[];
extern u8 option_shot_lists_2[];
extern u8 D_0028D960;
extern u16 g_p2_option_level_data[];
extern u16 g_p2_option_level_data_lo[];
extern u16 g_p1_option_level_data[];
extern u16 g_p1_option_level_data_lo[];
extern u16 g_two_player_game;
extern u8 D_0029E390[];
extern u8 D_0029EA50[];

void func_0019E130(void) {
    u8 *save_a3;
    u8 *save_a5;
    u8 *save_a6;
    u8 *push_a6;
    u32 save_d6;
    u32 save_d7;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = g_p1_option_level_data[0];
    reg_tmp.h[0] = g_p1_option_level_data_lo[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = g_p2_option_level_data[0];
    reg_tmp.h[0] = g_p2_option_level_data_lo[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x150;
    if (*(u16 *)(reg_a4 + 0x58) == 0) goto next_1;
    reg_d0.h[0] = 0x150;
next_1:
    reg_a3 = reg_a0;
    reg_a3 += reg_d0.h[0];
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!(*(u8 *)reg_a4 & 1)) goto next_2;
    reg_d0.h[0] += 4;
    reg_a1 = &D_0028D960;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
next_2:
    if (g_two_player_game != 0) goto next_3;
    if ((s32)reg_d4.h[0] <= 4) goto next_3;
    reg_d4.w = 4;
next_3:
    reg_d5.h[0] = reg_d4.h[0];
    reg_a1 = (u8 *)option_shot_lists_1;
    reg_a2 = (u8 *)option_shot_lists_2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x20);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    func_0019DC20();
    func_0019DCE0();
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto next_4;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
next_4:
    push_a6 = reg_a6;
    func_0019DD20();
    reg_a6 = reg_a0 - 0x2C;
    entity_draw_keep();
    reg_a6 = push_a6;
next_5:
    reg_a0 = reg_a3;
    reg_a6 += 0x20;
loop_1:
    if (*(s16 *)reg_a0 >= 0) goto next_6;
    reg_a0 += 0x30;
    if ((s16)(reg_d5.h[0] -= 1) >= 0) goto loop_1;
    goto next_7;
next_6:
    reg_a1 = reg_a2;
    func_0019DD20();
    reg_a6 = reg_a0 - 0x2C;
    entity_draw_keep();
next_7:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u8 option_shot_lists_3[];

void func_0019E5B0(void) {
    u8 *save_a3;
    u8 *save_a5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = g_p1_option_level_data[0];
    reg_tmp.h[0] = g_p1_option_level_data_lo[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = g_p2_option_level_data[0];
    reg_tmp.h[0] = g_p2_option_level_data_lo[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x450;
    if (*(u16 *)(reg_a4 + 0x58) == 0) goto next_1;
    reg_d0.h[0] = 0x450;
next_1:
    reg_a3 = reg_a0;
    reg_a3 += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
    reg_d0.b[0] += 0x10;
    reg_d0.b[0] &= 0x3F;
    if ((s32)reg_d0.b[0] >= 0x20) goto next_2;
    reg_atmp = reg_a0;
    reg_a0 = reg_a3;
    reg_a3 = (u8 *)reg_atmp;
next_2:
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d4.h[0] += 2;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!(*(u8 *)reg_a4 & 1)) goto next_3;
    reg_a1 = &D_0028D960;
    reg_d0.h[0] += 4;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d4.h[0] += 2;
next_3:
    if (g_two_player_game != 0) goto next_4;
    if ((s32)reg_d4.h[0] <= 4) goto next_4;
    reg_d4.w = 4;
next_4:
    reg_d5.h[0] = reg_d4.h[0];
    reg_a1 = (u8 *)option_shot_lists_3;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x20);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto loop_1;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
loop_1:
    if (*(s16 *)reg_a3 >= 0) goto next_6;
    reg_a3 += 0x30;
    if ((s16)(reg_d5.h[0] -= 1) >= 0) goto loop_1;
    goto next_5;
next_6:
    func_0019DC60();
    func_0019DCE0();
    func_0019E980();
    reg_a0 = reg_a3;
    func_0019DC60();
    func_0019DCE0();
    reg_a6 += 0x20;
    func_0019E980();
next_5:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

void func_0019E980(void) {
    u8 *save_a1;
    u8 *save_a6;

    save_a1 = reg_a1;
    save_a6 = reg_a6;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.w = 0;
    reg_d0.w = 0;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
    reg_d0.h[0] &= 0x3E;
    if ((reg_d0.h[0] != 0) && ((s32)reg_d0.b[0] > 0x20)) {
        reg_d0.b[0] *= -1;
        reg_d3.h[0] = 0xFFFF;
        reg_d0.h[0] &= 0x3E;
    }
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if ((s8)reg_d3.b[0] < 0) {
        reg_d1.h[0] *= 0xFFFF;
    }
    *(u16 *)reg_a0 = *(u16 *)(reg_a6 + 4);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.w = 0;
    reg_a5 = (u8 *)reg_tmp.w;
    *(u16 *)reg_a0 = (reg_d6.h[0] != 0) ? *(u16 *)(reg_a5 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a5;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)(reg_a5 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a5;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *)(reg_a0 - 2) = *(u8 *)(reg_a4 + 0x57);
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 0x5A);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 0x20);
    reg_a0 += 2;
    if ((s8)reg_d3.b[0] < 0) {
        *(u8 *)(reg_a0 - 0x12) *= -1;
        *(u8 *)(reg_a0 - 0xF) |= 0x40;
    }
    reg_a6 = reg_a0 - 0x2C;
    entity_draw_keep();
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_a1 = save_a1;
    reg_a6 = save_a6;
}

s32 func_0019F270();
extern u8 option_shot_lists_4[];

void func_0019EF20(void) {
    u32 save_d6;
    u32 save_d7;
    u8 *save_a3;
    u8 *save_a5;
    u8 *save_a6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = g_p1_option_level_data[0];
    reg_tmp.h[0] = g_p1_option_level_data_lo[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = g_p2_option_level_data[0];
    reg_tmp.h[0] = g_p2_option_level_data_lo[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x150;
    if (*(u16 *)(reg_a4 + 0x58) == 0) goto next_1;
    reg_d0.h[0] = 0x150;
next_1:
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!(*(u8 *)reg_a4 & 1)) goto next_2;
    reg_d0.h[0] += 4;
    reg_a1 = &D_0028D960;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
next_2:
    if (g_two_player_game != 0) goto next_3;
    if ((s32)reg_d4.h[0] <= 4) goto next_3;
    reg_d4.w = 4;
next_3:
    reg_d4.h[0] *= 2;
    reg_d4.h[0] += 1;
    reg_a1 = (u8 *)option_shot_lists_4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x20);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    func_0019DCA0();
    func_0019DCE0();
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto next_4;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
next_4:
    reg_a3 = reg_a0;
loop_1:
    reg_a0 += 0x30;
    if (*(s16 *)reg_a0 >= 0) goto next_6;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_1;
    goto next_5;
next_6:
    func_0019F270();
next_5:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

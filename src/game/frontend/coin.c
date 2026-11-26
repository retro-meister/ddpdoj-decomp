#include "common.h"
void credit_display_changed_check_coins(void);
void credit_display_changed_check_side(void);
void credit_display_changed_check_side_coins(u8 arg0);
void credit_display_changed();
void credit_display_unchanged();
void p1_continue_discount_reset(void);
void p2_continue_discount_reset(void);
void p1_credit_spend(void);
void p2_credit_spend(void);
void credit_spend_accept(void);
void credit_spend_refuse(void);
void coin_slots_clear(void);
void free_play_text_print_at(void);

extern u8 coin_init_table[];
extern u8 coin_init_table_2[];
extern u8 D_0028E1D0;
extern u8 D_0028E1D4;
extern u8 D_0028E1D8[];
extern u8 D_0028E1DA[];
extern u8 D_0028E1DC;
extern u8 D_0028E1E0;
extern u8 D_0028E1E4[];
extern u8 D_0028E1E6[];
extern u8 D_0028E1E8;
extern u8 D_0028E1EC;
extern u16 D_0028E1F0;
extern u16 D_0028E1F4;
extern u16 D_0028E1F8;
extern s8 D_0028E1FC;
extern s8 D_0028E200;
extern u8 D_0028E204;
extern u8 D_0028E208;
extern u8 D_0028E20C;
extern u8 D_0028E210;
extern s16 coin_init_state;
extern u8 g_setting_coin_mode;

void coin_init(void) {
    s8 temp_v1;

    reg_a0 = coin_init_table;
    reg_d0.w = 0;
    ((s8 *)D_0028E1E4)[0] = 0;
    ((s8 *)D_0028E1E6)[0] = 0;
    reg_d0.b[0] = g_setting_coin_mode;
    ((s8 *)D_0028E1D8)[0] = 0;
    coin_init_state = 0;
    D_0028E210 = 0;
    D_0028E20C = 0;
    D_0028E208 = 0;
    D_0028E204 = 0;
    D_0028E200 = 0;
    D_0028E1FC = 0;
    D_0028E1F8 = 0;
    D_0028E1F4 = 0;
    D_0028E1F0 = 0;
    D_0028E1E0 = 0;
    D_0028E1DC = 0;
    ((s8 *)D_0028E1DA)[0] = 0;
    D_0028E1D4 = 0;
    D_0028E1D0 = 0;
    temp_v1 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    reg_a0 = coin_init_table_2;
    D_0028E1EC = temp_v1;
    D_0028E1E8 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    p1_continue_discount_reset();
    p2_continue_discount_reset();
    coin_slots_clear();
}

extern u8 D_0028E1E0;
extern u8 D_0028E1E4[];

void credit_display_changed_check(void) {
    if (reg_d0.h[0] != 0) {
        credit_display_changed_check_side();
        return;
    }
    reg_d0.b[0] = D_0028E1E4[0];
    reg_d1.b[0] = D_0028E1E0;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        credit_display_changed_check_coins();
        return;
    }
    D_0028E1E0 = reg_d0.b[0];
    credit_display_changed();
}

extern u8 D_0028E1DC;
extern u8 D_0028E1E6[];

void credit_display_changed_check_coins(void) {
    reg_d0.b[0] = D_0028E1E6[0];
    reg_d1.b[0] = D_0028E1DC;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        credit_display_unchanged();
        return;
    }
    D_0028E1DC = reg_d0.b[0];
    credit_display_changed();
}

extern u8 D_0028E1D4;
extern u8 D_0028E1D8[];
extern u8 g_setting_chute_type;

void credit_display_changed_check_side(void) {
    extern void credit_display_changed(u8);
    reg_d0.b[0] = D_0028E1E4[0];
    if (g_setting_chute_type == 1) {
        reg_d0.b[0] = D_0028E1D8[0];
    }
    reg_d1.b[0] = D_0028E1D4;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        credit_display_changed_check_side_coins(D_0028E1E4[0]);
        return;
    }
    D_0028E1D4 = reg_d0.b[0];
    credit_display_changed(D_0028E1E4[0]);
}

extern u8 D_0028E1D0;
extern u8 D_0028E1DA[];

void credit_display_changed_check_side_coins(u8 arg0) {
    extern void credit_display_unchanged(u8);
    extern void credit_display_changed(u8);
    reg_d0.b[0] = D_0028E1E6[0];
    if (g_setting_chute_type == 1) {
        reg_d0.b[0] = D_0028E1DA[0];
    }
    reg_d1.b[0] = D_0028E1D0;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        credit_display_unchanged(D_0028E1E6[0]);
        return;
    }
    D_0028E1D0 = reg_d0.b[0];
    credit_display_changed(D_0028E1E6[0]);
}


void credit_display_changed() {
    (*(u8 *)&cond_flag) = 1;
}

void credit_display_unchanged() {
    (*(u8 *)&cond_flag) = 0;
}

extern u8 D_0028E1EC;

void credits_get(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
    } else if (reg_d0.b[0] == 0x11) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.b[0] = D_0028E1E4[1];
        reg_d1.b[0] = D_0028E1E4[0];
    } else {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.b[0] = D_0028E1EC;
        reg_d1.b[0] = D_0028E1E4[0];
    }
}

extern u8 D_0028E1D9[];

void coins_get(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        if (g_setting_chute_type != 1) {
            reg_d0.b[0] = D_0028E1D9[0];
            reg_d1.b[0] = D_0028E1E4[0];
            return;
        }
        reg_d0.b[0] = D_0028E1D9[0];
        reg_d1.b[0] = D_0028E1D8[0];
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    if (g_setting_chute_type != 1) {
        reg_d0.b[0] = D_0028E1EC;
        reg_d1.b[0] = D_0028E1E4[0];
        return;
    }
    reg_d0.b[0] = D_0028E1EC;
    reg_d1.b[0] = D_0028E1D8[0];
}

extern u8 D_0028E204;
extern u8 D_0028E208;

void coin_counter_pulses_take(void) {
    reg_d0.w = 0;
    if (D_0028E208 != 0) {
        D_0028E208 -= 1;
        reg_d0.h[0] |= 1;
    }
    if (D_0028E204 != 0) {
        D_0028E204 -= 1;
        reg_d0.h[0] |= 2;
    }
    if ((u8)D_0028E200 != 0) {
        (*(u8 *)&D_0028E200) -= 1;
        reg_d0.h[0] |= 4;
    }
    if ((u8)D_0028E1FC != 0) {
        (*(u8 *)&D_0028E1FC) -= 1;
        reg_d0.h[0] |= 8;
    }
    if (reg_d0.h[0] != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

void p1_credits_get(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = D_0028E1E6[0];
    reg_d1.b[0] = D_0028E1DA[0];
}

void p2_credits_get(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = D_0028E1E4[0];
    reg_d1.b[0] = D_0028E1D8[0];
}

extern u8 D_0028E1E5[];

void p1_continue_discount_reset(void) {
    D_0028E1E5[0] = 2;
}

void p2_continue_discount_reset(void) {
    D_0028E1D9[0] = 2;
}


void p1_credit_spend_one(void) {
    reg_d3.sw = 1;
    p1_credit_spend();
}

s32 p1_coins_decrement();
s32 p1_credits_subtract();

void p1_credit_spend(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        credit_spend_accept();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        p2_credits_get();
        reg_d2.w = 0;
        reg_d2.b[0] = D_0028E1E5[0];
        if ((s16)(reg_d2.h[0]) > (s16) reg_d0.h[0]) {
            credit_spend_refuse();
            return;
        }
        if (reg_d3.h[0] == 0) {
            credit_spend_accept();
            return;
        }
        reg_d0.h[0] = reg_d2.h[0];
        D_0028E1E5[0] = 1;
        p1_credits_subtract();
        credit_spend_accept();
        return;
    }
    p1_credits_get();
    if (reg_d0.h[0] == 0) {
        credit_spend_refuse();
        return;
    }
    if (reg_d3.h[0] == 0) {
        credit_spend_accept();
        return;
    }
    p1_coins_decrement();
    credit_spend_accept();
}


void p2_credit_spend_one(void) {
    reg_d3.sw = 1;
    p2_credit_spend();
}

s32 p2_coins_decrement();
s32 p2_credits_subtract();

void p2_credit_spend(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        credit_spend_accept();
        return;
    }
    reg_d1.b[0] = g_setting_chute_type;
    if (reg_d1.b[0] != 1) {
        if (reg_d0.b[0] == 0x11) {
            p2_credits_get();
            reg_d2.w = 0;
            reg_d2.b[0] = D_0028E1D9[0];
            if ((s16)(reg_d2.h[0]) > (s16) reg_d0.h[0]) {
                credit_spend_refuse();
                return;
            }
            if (reg_d3.h[0] == 0) {
                credit_spend_accept();
                return;
            }
            reg_d0.h[0] = reg_d2.h[0];
            D_0028E1D9[0] = 1;
            p1_credits_subtract();
            credit_spend_accept();
            return;
        }
        p1_credits_get();
        if (reg_d0.h[0] == 0) {
            credit_spend_refuse();
            return;
        }
        if (reg_d3.h[0] == 0) {
            credit_spend_accept();
            return;
        }
        p1_coins_decrement();
        credit_spend_accept();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        p2_credits_get();
        reg_d2.w = 0;
        reg_d2.b[0] = D_0028E1D9[0];
        if ((s16)(reg_d2.h[0]) > (s16) reg_d1.h[0]) {
            credit_spend_refuse();
            return;
        }
        if (reg_d3.h[0] == 0) {
            credit_spend_accept();
            return;
        }
        reg_d0.h[0] = reg_d2.h[0];
        D_0028E1D9[0] = 1;
        p2_credits_subtract();
        credit_spend_accept();
        return;
    }
    p1_credits_get();
    if (reg_d1.h[0] == 0) {
        credit_spend_refuse();
        return;
    }
    if (reg_d3.h[0] == 0) {
        credit_spend_accept();
        return;
    }
    p2_coins_decrement();
    credit_spend_accept();
}

void credit_spend_accept(void) {
    (*(u8 *)&cond_flag) = 0;
}

void credit_spend_refuse(void) {
    (*(u8 *)&cond_flag) = 1;
}

extern u8 D_0028E1E8;

void coin_to_credit(void) {
    u32 s0;
    u32 s1;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    reg_d0.b[0] = *(s8 *)(reg_a0 + 2);
    if (reg_d0.b[0] == 9) goto block_end;
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) goto block_end;
    if (reg_d0.b[0] == 0x11) {
        *(s8 *)(reg_a0 + 0) += 1;
        if (*(s8 *)(reg_a0 + 0) > 9) {
            *(s8 *)(reg_a0 + 0) = 9;
        }
    }
    if ((s8)reg_d0.b[0] >= 9 && (s8)reg_d0.b[0] < 0x11) {
        *(s8 *)(reg_a0 + 0) += 1;
        reg_d1.b[0] = D_0028E1EC;
        if (*(s8 *)(reg_a0 + 0) == reg_d1.b[0]) {
            *(s8 *)(reg_a0 + 0) = 0;
            *(s8 *)(reg_a0 + 2) += 1;
            if (*(s8 *)(reg_a0 + 2) > 9) {
                *(s8 *)(reg_a0 + 2) = 9;
            }
        }
    }
    if (0 <= (s8)reg_d0.b[0] && (s8)reg_d0.b[0] < 9) {
        reg_d1.b[0] = D_0028E1E8;
        *(s8 *)(reg_a0 + 2) += (s8)reg_d1.b[0];
        if (*(s8 *)(reg_a0 + 2) > 9) {
            *(s8 *)(reg_a0 + 2) = 9;
        }
    }
block_end:
    reg_d1.w = s1;
    reg_d0.w = s0;
}

extern u8 D_0028E1C0[];
extern u8 D_0028E1C8[];

void coin_slots_clear(void) {
    reg_a0 = D_0028E1C8;
    reg_d0.w = 1;
    do {
        *(s8 *)(reg_a0 + 1) = 0;
        *(s8 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 2) = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        reg_a0 = D_0028E1C0;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u8 g_arcade_coin_port;
extern u8 g_stage_load_state;

void coin_update(void) {
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 v;
    u16 c;
    u32 count;

    if (g_stage_load_state != 0) return;
    if (g_setting_coin_mode == 0x12) return;
    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028E1C8;
    reg_d7.w = 1;
    reg_d0.h[0] = ~(s16)reg_d0.h[0];
loop_1:
    v = *(u8 *)(reg_a0 + 1);
    if (v != 0) goto next_2;
    if ((reg_d0.w & 1) == 0) goto next_5;
    *(u8 *)(reg_a0 + 1) = 1;
    *(s16 *)(reg_a0 + 4) = 0;
    *(u16 *)(reg_a0 + 2) = 1;
    goto next_5;
next_2:
    if (v != 1) goto next_3;
    if ((reg_d0.w & 1) == 0) goto block_1;
    c = *(u16 *)(reg_a0 + 2);
    if (c == 0xFFFF) goto next_5;
    *(u16 *)(reg_a0 + 2) = c + 1;
    goto next_5;
block_1:
    *(u8 *)(reg_a0 + 1) = 2;
    goto next_5;
next_3:
    if (v != 2) goto next_5;
    if (reg_d0.w & 1) goto block_3;
    *(u8 *)(reg_a0 + 1) = 0;
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    *(u16 *)(reg_a0 + 2) = 0;
    if ((s16)reg_d1.h[0] < 3) goto block_2;
    if ((s16)reg_d1.h[0] >= 0x27) goto block_2;
    *(s16 *)(reg_a0 + 4) = 0x80;
    goto next_5;
block_2:
    *(s16 *)(reg_a0 + 4) = 1;
    goto next_5;
block_3:
    *(u8 *)(reg_a0 + 1) = 1;
next_5:
    if (reg_d0.h[0] & 1) {
        reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
        reg_d0.h[0] |= 0x8000;
    } else {
        reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
    }
    reg_a0 = (u8 *)D_0028E1C0;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
}

extern u16 coin_slots_take_buffer[];
extern u16 coin_slots_take_buffer_2[];

void coin_slots_take(void) {
    reg_d1.w = 0;
    if (coin_slots_take_buffer_2[0] == 0x80) {
        coin_slots_take_buffer_2[0] = 0;
        reg_d1.h[0] |= 1;
    }
    if (coin_slots_take_buffer[0] == 0x80) {
        coin_slots_take_buffer[0] = 0;
        reg_d1.h[0] |= 2;
    }
}

void sfx_coin(void);
extern u16 D_0028E1F0;
extern u16 D_0028E1F4;
extern u16 D_0028E1F8;
extern u8 D_0028E20C;
extern u8 D_0028E210;
extern u16 coin_inputs_update_state;

void coin_inputs_update(void) {
    if (g_stage_load_state != 0) return;
    if (g_setting_coin_mode == 0x12) return;
    reg_a0 = (u8 *)&(*(u16 *)&g_arcade_coin_port);
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] = D_0028E1F4;
    D_0028E1F4 = reg_d0.h[0];
    reg_d0.h[0] = ~(s16)reg_d0.h[0];
    D_0028E1F8 = reg_d0.h[0];
    reg_d1.h[0] &= reg_d0.h[0];
    reg_d1.h[0] &= 0xE0;
    D_0028E1F0 = reg_d1.h[0];
    coin_slots_take();
    reg_d1.h[0] |= D_0028E1F0;
    if (reg_d1.h[0] & 0x20) {
        sfx_coin();
        reg_a0 = (u8 *)((u16 *)D_0028E1E4);
        coin_to_credit();
        return;
    }
    if (reg_d1.w & 1) {
        sfx_coin();
        reg_a0 = (u8 *)((u16 *)D_0028E1E4);
        coin_to_credit();
        reg_d0.b[0] = g_setting_coin_mode;
        if (reg_d0.b[0] != 0x12) {
            D_0028E208 += 1;
        }
    }
    if (reg_d1.w & 2) {
        sfx_coin();
        reg_a0 = (u8 *)((u16 *)D_0028E1D8);
        reg_d0.b[0] = g_setting_chute_type;
        if (reg_d0.b[0] != 1) {
            reg_a0 = (u8 *)((u16 *)D_0028E1E4);
        }
        coin_to_credit();
        reg_d0.b[0] = g_setting_coin_mode;
        if (reg_d0.b[0] != 0x12) {
            D_0028E204 += 1;
        }
    }
    reg_a0 = (u8 *)&coin_inputs_update_state;
    if (D_0028E210 == 0) {
        coin_counter_pulses_take();
        if (cond_flag != 0) {
            reg_d1.b[0] = g_setting_chute_type;
            if (reg_d1.b[0] != 0) {
                *(u16 *)reg_a0 = reg_d0.h[0];
            } else {
                *(u16 *)reg_a0 = 0xF;
            }
            D_0028E20C = 6;
            D_0028E210 = 1;
        }
    } else if (D_0028E210 == 1) {
        D_0028E20C -= 1;
        if (D_0028E20C == 0) {
            *(u16 *)reg_a0 = 0;
            D_0028E20C = 6;
            D_0028E210 = 2;
        }
    } else if (D_0028E210 == 2) {
        D_0028E20C -= 1;
        if (D_0028E20C == 0) {
            D_0028E210 = 0;
        }
    }
}

s32 text_layer_put();

void text_layer_put_hex_digit(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_s4;

    temp_s0 = reg_d0.w;
    temp_s1 = reg_d1.w;
    temp_s2 = reg_d2.w;
    temp_s3 = reg_d3.w;
    temp_s4 = reg_d4.w;
    reg_d4.w &= 0xF;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d3.w = 0;
    reg_d2.w = 0;
    if ((s8) reg_d4.b[0] >= 0xA) {
        reg_d4.h[0] += 7;
    }
    reg_d4.h[0] += 0x30;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[1] = reg_tmp4.h[0];
    text_layer_put();
    reg_d0.w = temp_s0;
    reg_d1.w = temp_s1;
    reg_d2.w = temp_s2;
    reg_d3.w = temp_s3;
    reg_d4.w = temp_s4;
}

#ifndef DEATH_LABEL
extern char coin_text_free_play[];

void free_play_text_print(void) {
    extern void text_layer_print(void);
    reg_d0.h[0] = 10;
    reg_d1.h[0] = 3;
    reg_a0 = (u8 *)coin_text_free_play;
    reg_d2.sh[0] = 0;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL

void free_play_text_print_p1(void) {
    reg_d0.h[0] = 3;
    reg_d1.h[0] = 3;
    free_play_text_print_at();
}
#endif

#ifndef DEATH_LABEL
void free_play_text_print_p2(void) {
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 0x3;
    free_play_text_print_at();
}
#endif

#ifndef DEATH_LABEL
void free_play_text_print_at(void) {
    extern void text_layer_print(void);
    reg_d2.sh[0] = 0;
    reg_a0 = (u8 *)coin_text_free_play;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
extern s32 coin_text_coins;

void coins_text_print(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0xB;
    reg_d1.h[0] = 3;
    reg_a0 = &(*(u8 *)&coin_text_coins);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1E4[0];
    reg_d4.b[0] += D_0028E1D8[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern s32 coin_text_coins;

void coins_text_print_p1(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 4;
    reg_d1.h[0] = 3;
    reg_a0 = (u8 *)(&coin_text_coins);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1E4[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void coins_text_print_p2(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0x12;
    reg_d1.h[0] = 3;
    reg_a0 = (u8 *)(&coin_text_coins);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1D8[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern u8 coin_text_credits_with_coins[];

void credits_with_coins_text_print(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)coin_text_credits_with_coins;
    text_layer_print();
    reg_d0.h[0] += 0xC;
    reg_d4.b[0] = D_0028E1EC;
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E4[0];
    reg_d4.b[0] += D_0028E1D8[0];
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern s32 coin_text_credits_short;
extern s32 coin_text_coins_frame;

void credits_with_coins_text_print_p1(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 3;
    reg_d1.h[0] = 4;
    reg_a0 = (u8 *)(&coin_text_credits_short);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 = (u8 *)(&coin_text_coins_frame);
    reg_d1.h[0] = 3;
    text_layer_print();
    reg_d0.h[0] += 5;
    reg_d4.b[0] = D_0028E1EC;
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E4[0];
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void credits_with_coins_text_print_p2(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 4;
    reg_a0 = (u8 *)(&coin_text_credits_short);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 = (u8 *)(&coin_text_coins_frame);
    reg_d1.h[0] = 3;
    text_layer_print();
    reg_d0.h[0] += 5;
    reg_d4.b[0] = D_0028E1EC;
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1D8[0];
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1DA[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern s32 coin_text_credits[];

void credits_text_print(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0xA;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)coin_text_credits;
    text_layer_print();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void credits_text_print_p1(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 3;
    reg_a0 = (u8 *)coin_text_credits;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void credits_text_print_p2(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)coin_text_credits;
    text_layer_print();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1DA[0];
    text_layer_put_hex_digit();
}
#endif

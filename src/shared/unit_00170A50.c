#include "common.h"
#include "entity.h"

void func_00170A50(void) {
}

typedef void (*Fn)(void);
extern u8 *reg_call_target_as_u8_p;
extern u16 D_0025AE10[];

void func_00170A60(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)D_0025AE10;
    reg_d0.h[0] <<= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}

extern u16 D_0025AE50[];

void func_00170B20(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)D_0025AE50;
    reg_d0.h[0] <<= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}

extern u16 D_0025AE70[];

void func_00170BE0(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)D_0025AE70;
    reg_d0.h[0] <<= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}

extern u16 D_0025AEA8[];

void func_00170CA0(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)D_0025AEA8;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
}

extern u16 D_0025AEB8[];

void func_00170D00(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a1 = (u8 *)D_0025AEB8;
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1E) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a1) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
}

extern u16 D_0025AEC8[];

void func_00170D70(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a1 = (u8 *)D_0025AEC8;
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1E) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a1) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
}

void func_00170DE0(void) {
    reg_d2.h[0] = ENTITY(reg_a6)->misc.h;
}

s32 func_001ABF90();
s32 func_00200EE0();
s32 func_00201010();
extern u16 D_0028E024;
extern u16 g_p1_hyper_gauge;
extern s16 g_p1_hyper_active_as_s16;
extern u16 g_boss_hits;
extern u16 g_boss_hit_decay_timer;
extern u16 g_p1_hits;
extern u16 g_p1_combo_timer;
extern u8 D_0028E855;

void func_00170DF0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s64 t;

    reg_d3.h[0] = D_0028E024;
    reg_d4.h[0] = g_p1_combo_timer;
    reg_d5.h[0] = g_p1_hits;
    if (D_0028E855 & 2) {
        reg_d0.h[0] = g_boss_hits;
        if ((s16) reg_d0.h[0] >= 0) {
            func_00200EE0();
            reg_d5.w = reg_d2.w;
            reg_d4.h[0] = g_boss_hit_decay_timer;
        } else {
            reg_d4.w = 0;
        }
    }
    if ((g_p1_hyper_active_as_s16 == 0) && ((s16) reg_d4.h[0] != 0)) {
        t = (s64) ((s64) reg_d5.h[0] << 0x30) >> 0x30;
        if ((t != 0) && (t >= 0)) {
            save_d0 = reg_d0.w;
            save_d1 = reg_d1.w;
            save_d2 = reg_d2.w;
            save_d3 = reg_d3.w;
            save_d4 = reg_d4.w;
            save_d5 = reg_d5.w;
            if ((s32) (reg_d5.h[0] & 0xFFFF) > 0x200) {
                reg_d5.h[0] = 0x200;
            }
            reg_d0.h[0] = reg_d5.h[0];
            func_00201010();
            reg_d0.w = 0;
loop_11:
            reg_tmp2.w = 0;
            reg_tmp.w = 0;
            reg_tmp.h[0] = 0x14;
            reg_tmp2.h[0] = reg_d2.h[0];
            reg_tmp2.w -= reg_tmp.w;
            reg_d2.h[0] -= 0x14;
            if (reg_tmp2.h[1] == 0) {
                reg_d0.h[0] += 0x48;
                goto loop_11;
            }
            g_p1_hyper_gauge += reg_d0.h[0];
            func_001ABF90();
            reg_d0.w = save_d0;
            reg_d1.w = save_d1;
            reg_d2.w = save_d2;
            reg_d3.w = save_d3;
            reg_d4.w = save_d4;
            reg_d5.w = save_d5;
        }
    }
}

s32 func_001AC160();
extern u16 D_0028E020;
extern u16 g_p2_hyper_gauge;
extern s16 g_p2_hyper_active_as_s16;
extern u16 g_p2_hits;
extern u16 g_p2_combo_timer;

void func_00170F80(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s64 t;

    reg_d3.h[0] = D_0028E020;
    reg_d4.h[0] = g_p2_combo_timer;
    reg_d5.h[0] = g_p2_hits;
    if (D_0028E855 & 2) {
        reg_d0.h[0] = g_boss_hits;
        if ((s16) reg_d0.h[0] >= 0) {
            func_00200EE0();
            reg_d5.w = reg_d2.w;
            reg_d4.h[0] = g_boss_hit_decay_timer;
        } else {
            reg_d4.w = 0;
        }
    }
    if ((g_p2_hyper_active_as_s16 == 0) && ((s16) reg_d4.h[0] != 0)) {
        t = (s64) ((s64) reg_d5.h[0] << 0x30) >> 0x30;
        if ((t != 0) && (t >= 0)) {
            save_d0 = reg_d0.w;
            save_d1 = reg_d1.w;
            save_d2 = reg_d2.w;
            save_d3 = reg_d3.w;
            save_d4 = reg_d4.w;
            save_d5 = reg_d5.w;
            if ((s32) (reg_d5.h[0] & 0xFFFF) > 0x200) {
                reg_d5.h[0] = 0x200;
            }
            reg_d0.h[0] = reg_d5.h[0];
            func_00201010();
            reg_d0.w = 0;
loop_11:
            reg_tmp2.w = 0;
            reg_tmp2.h[0] = reg_d2.h[0];
            reg_tmp2.w -= 0x14;
            reg_d2.h[0] -= 0x14;
            if (reg_tmp2.h[1] == 0) {
                reg_d0.h[0] += 0x48;
                goto loop_11;
            }
            g_p2_hyper_gauge += reg_d0.h[0];
            func_001AC160();
            reg_d0.w = save_d0;
            reg_d1.w = save_d1;
            reg_d2.w = save_d2;
            reg_d3.w = save_d3;
            reg_d4.w = save_d4;
            reg_d5.w = save_d5;
        }
    }
}

s32 func_001A9130();
extern u16 D_00269430[];
extern u16 D_00269460[];
extern u16 D_0028E980;
extern u16 D_0028E984;

void func_00171100(void) {
    u32 t;
    s32 t2;

    reg_d1.h[0] = D_0028E980;
    D_0028E984 += 1;
    if (D_0028E984 != 0xA) goto next_1;
    if ((s16) reg_d3.h[0] != 0) goto next_1;
    ENTITY(reg_a6)->flags.b[1] |= 0x20;
    D_0028E980 += 4;
next_1:
    reg_a0 = (u8 *)D_00269430;
    reg_d0.w = *(u32 *)((u8 *)D_00269430 + (reg_d1.h[0] & ~3));
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto next_2;
    reg_d0.w += reg_d0.w;
next_2:
    reg_a0 = (u8 *)D_00269460;
    ENTITY(reg_a6)->hit_y_plus.h = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_y_minus.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((s16) reg_d4.h[0] == 0) goto next_5;
    if ((s16) reg_d5.h[0] == 0) goto next_5;
    if ((s16) reg_d5.h[0] < 0) goto next_5;
    ENTITY(reg_a6)->misc.h = reg_d5.h[0];
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d4.w = 3;
loop_3:
    reg_tmp3.w = 0;
    reg_d3.w = 0xF;
    reg_d3.h[0] &= reg_d5.h[0];
    reg_tmp3.h[0] = reg_d3.h[0];
    reg_d3.h[0] -= 1;
    reg_tmp3.w -= 1;
    if (reg_tmp3.h[1] != 0) goto next_4;
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
    ENTITY(reg_a6)->misc.h = 1;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    func_001A9130();
}

#pragma push
#pragma opt_propagation off
extern u8 g_ground_no_draw;
extern void (*reg_call_target_as_fn)(void);

void scenery_draw(void (*callback)(void))
{
    if (g_ground_no_draw == 0) {
        const u16 *state = (const u16 *)((void *)reg_a6);

        reg_d1.h[1] = state[1];
        reg_d1.h[0] = state[2];
        reg_d3.h[0] = state[10];
        reg_d2.h[1] = state[8];
        reg_d2.h[0] = state[9];
        reg_d4.w = 0;
        reg_d4.h[0] = state[6];
        reg_call_target_as_fn = callback;
        reg_call_target_as_fn();
    }
}
#pragma pop

void entity_release(void) {
    ENTITY(reg_a6)->flags.b[1] = 0;
}

void func_001713B0(void) {
    void boss_level_get(void);
    *(u16 *)&reg_d0 = 0x58;
    boss_level_get();
}

void func_001713C0(void) {
    s32 boss_level_get();
    reg_d0.h[0] = 0x78;
    boss_level_get();
    reg_d0.w = 4;
}


void enemy_set_entity_count(u16 val) {
    *(u16 *)(reg_a5 + 4) = val;
}


void enemy_switch_target_player(void) {
    u8 *flags_ptr;
    u8 flags;

    flags_ptr = reg_a5 + 2;
    flags = flags_ptr[0];
    if (flags & 1) {
        flags_ptr[0] = flags & 0xFE;
        return;
    }
    flags_ptr[0] = flags | 1;
}

s32 enemy_remove();                           /* extern */
s32 entity_check_bounds();                            /* extern */

void func_00171430(void) {
    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            cond_flag = 1;
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    cond_flag = 0;
}

#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32 mode);

void func_00168AA0(void) {
    enemy_set_entity_count(0);
}

extern s32 D_0025B0C0[];
extern s32 *reg_a0_as_s32_p;

void enemy_init_entities(void);

void func_00168AB0(void) {
    reg_a0_as_s32_p = D_0025B0C0;
    enemy_init_entities();
}

s32 enemy_remove();
extern u16 D_0028DFFC;
extern u16 g_enemy_signal_1;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line;

void func_00168AC0(void) {
    u8 t;

    if ((s32) g_scroll_line < 0x2E0) goto next_1;
    enemy_remove();
    return;
next_1:
    if (g_enemies_stopped != 0) goto block_rts;
    g_enemy_signal_1 = 0;
    ENTITY(reg_a6)->offset_y.h -= 1;
    if ((s16) ENTITY(reg_a6)->offset_y.h >= 0) goto block_rts;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = D_0028DFFC;
    if (reg_d1.h[0] == 0) goto next_2;
loop_1:
    reg_d0.h[0] -= 1;
    reg_d1.h[0] -= 7;
    if ((s16) reg_d1.h[0] >= 0) goto loop_1;
next_2:
    ENTITY(reg_a6)->offset_y.h = reg_d0.h[0];
    g_enemy_signal_1 = 1;
    t = ENTITY(reg_a6)->flags.b[0];
    if (t & 0x40) goto next_3;
    ENTITY(reg_a6)->flags.b[0] = t | 0x40;
    return;
next_3:
    ENTITY(reg_a6)->flags.b[0] = t & 0xBF;
    g_enemy_signal_1 = 0xFFFF;
block_rts:
    return;
}

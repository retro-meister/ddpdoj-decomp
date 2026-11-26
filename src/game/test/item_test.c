#include "common.h"
#include "entity.h"

extern void *D_0026B090[8];

void item_update_taken(void);

s32 item_release();
s32 sprite_draw_with_items();
s32 entity_velocity();

void item_update_one(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u32 temp_a1;

    if (*(u8 *)reg_a6 & 0x80) {
        item_update_taken();
        return;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    temp_a0 = *(u16 *)reg_a0;
    temp_a1 = reg_d1.w;
    reg_a0 += 2;
    reg_tmp1.h[1] = temp_a0;
    reg_tmp1.h[0] = *(u16 *)reg_a0;
    reg_d1.w = temp_a1 + (s32) reg_tmp1.w;
    reg_a0 += 2;
    temp_a0_2 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = temp_a0_2;
    reg_a0 += 2;
    reg_a0 += *(u16 *)(reg_a6 + 0xA);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d4.h[0] = 0x1D;
    sprite_draw_with_items();
    if (*(u8 *)(reg_a6 + 0xF) != 0) {
        *(u16 *)(reg_a6 + 2) += 0x20;
    } else {
        entity_velocity();
    }
    *(u8 *)(reg_a6 + 0xD) -= 1;
    if (*(u8 *)(reg_a6 + 0xD) == 0) {
        *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
        *(u8 *)(reg_a6 + 0xF) = 0U;
        *(u16 *)(reg_a6 + 0xA) += 4;
        if ((s16) *(u16 *)(reg_a6 + 0xA) >= 0x78) {
            item_release();
        }
    }
}

void item_update_taken(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u32 temp_a1;

    reg_tmp.h[1] = *(u16 *)(reg_a6 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    temp_a0 = *(u16 *)reg_a0;
    temp_a1 = reg_d1.w;
    reg_a0 += 2;
    reg_tmp1.h[1] = temp_a0;
    reg_tmp1.h[0] = *(u16 *)reg_a0;
    reg_d1.w = temp_a1 + (s32) reg_tmp1.w;
    reg_a0 += 2;
    temp_a0_2 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = temp_a0_2;
    reg_a0 += 2;
    reg_a0 += *(u16 *)(reg_a6 + 0xA);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d4.h[0] = 0x1D;
    sprite_draw_with_items();
    if (*(u8 *)(reg_a6 + 0xF) != 0) {
        *(u16 *)(reg_a6 + 2) += 0x20;
    } else {
        entity_velocity();
    }
    *(u8 *)(reg_a6 + 0xD) -= 1;
    if (*(u8 *)(reg_a6 + 0xD) == 0) {
        *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
        *(u8 *)(reg_a6 + 0xF) = 0U;
        *(u16 *)(reg_a6 + 0xA) += 4;
        if ((s16) *(u16 *)(reg_a6 + 0xA) >= 0x44) {
            item_release();
        }
    }
}

extern u16 g_item_count;


void item_init(void) {
    u32 save_d0;
    u32 save_d1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] |= 0x8000;
    reg_a2 = *(u8 **)(((u8 *)D_0026B090) + (reg_d0.h[0] & ~3));
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = ENTITY(reg_a6)->y.h;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ENTITY(reg_a6)->x.h;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    cond_flag = 0;
    reg_a2 += 2;
    reg_a0 += 2;
    g_item_count += 1;
}

extern u16 g_item_test_cursor;

void item_init_at_y(void) {
    reg_a2 = (u8 *)((u8 *)D_0026B090);
    reg_d1.h[0] = reg_d0.h[0];
    reg_a2 = *(u8 **)(((u8 *)D_0026B090) + (reg_d0.h[0] & ~3));
    reg_d1.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d6.h[0];
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xFFFF;
    reg_a0 += 2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) g_item_test_cursor;
    reg_a0 += 2;
    g_item_count += 1;
    g_item_test_cursor += 0xC;
    if (g_item_test_cursor == 0x9C) {
        g_item_test_cursor = 0;
    } else if (g_item_test_cursor == 0xA2) {
        g_item_test_cursor = 6;
    }
}

void enemy_set_entity_count(s32 mode);

void item_test_count_0(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */
extern s32 D_0025B0E0[];
extern s32 D_0028CA00;

void item_test_begin(void) {
    reg_a0 = (u8 *)D_0025B0E0;
    enemy_init_entities();
    reg_a0 = (u8 *)(&D_0028CA00);
    reg_d0.w = 1;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

s32 debug_number_get();                            /* extern */
s32 input_get_p2_pressed();                            /* extern */
s32 item_spawn();                            /* extern */
s32 entity_draw();                            /* extern */
s32 entity_move_by_p2_stick();                            /* extern */

void item_test_update(void) {
    s64 temp_v0_2;
    u16 temp_v0;

    entity_move_by_p2_stick();
    temp_v0 = *(u16 *)(reg_a5 + 0x18);
    if (temp_v0 != 0) {
        *(u16 *)(reg_a5 + 0x18) = (u16) (temp_v0 - 1);
    } else {
        input_get_p2_pressed();
        if (reg_d0.w & 0x40) {
            debug_number_get();
            temp_v0_2 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
            if ((temp_v0_2 < 5) && (temp_v0_2 >= 0)) {
                reg_d0.h[0] *= 4;
                item_spawn();
            }
        }
    }
    entity_draw();
}

extern u16 D_0026B0B0[16];
extern u16 D_0026B0D0[16];
extern u16 D_0026B0F0[16];
extern u16 D_0026B110[16];
extern u16 D_0026B150[16];
extern u16 D_0026B130[16];
extern u8 D_0028E7A8[];
extern u8 D_0028E7A4[];

void *D_0026B090[8] = {
    D_0026B0B0,
    D_0026B0D0,
    D_0026B0F0,
    D_0026B110,
    D_0026B150,
    D_0026B130,
    D_0028E7A8,
    D_0028E7A4,
};

u16 D_0026B0B0[16] = {
    0xFC00, 0xFD00, 0x0000, 0x0000, 0x0418, 0x0600, 0x0600, 0x0500,
    0x0500, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026B0D0[16] = {
    0xFC00, 0xFC00, 0x0000, 0x0000, 0x0420, 0x0600, 0x0600, 0x0700,
    0x0700, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026B0F0[16] = {
    0xFC00, 0xFD00, 0x0000, 0x0000, 0x0418, 0x0600, 0x0600, 0x0500,
    0x0500, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026B110[16] = {
    0xFC00, 0xFD00, 0x0000, 0x0000, 0x0000, 0x0600, 0x0600, 0x0500,
    0x0500, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026B130[16] = {
    0xFC00, 0xFD00, 0x0000, 0x0000, 0x0000, 0x0600, 0x0600, 0x0500,
    0x0500, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026B150[16] = {
    0xFC00, 0xFC00, 0x0000, 0x0000, 0x0420, 0x0600, 0x0600, 0x0500,
    0x0500, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

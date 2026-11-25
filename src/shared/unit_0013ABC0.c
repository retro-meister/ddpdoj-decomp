#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32);

void func_0013ABC0(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_work();                            /* extern */
s32 enemy_init_entities();                            /* extern */
extern s32 D_00253200[];
extern s32 D_0028C188;

void func_0013ABD0(void) {
    reg_a0 = (u8 *)D_00253200;
    enemy_init_entities();
    reg_a0 = (u8 *)(&D_0028C188);
    reg_d0.w = 1;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

s32 explosion_spawn();
s32 input_get_p2_held();
s32 input_get_p2_pressed();
s32 sprite_draw_layer5_keep();
extern u16 D_00253220[];
extern u16 D_0028C190_as_u16;

void func_0013AC30(void) {
    u32 temp_a0;
    u32 temp_a1;
    u32 temp_v1_2;

    input_get_p2_pressed();
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] != 0) {
        *(u8 *)(reg_a5 + 0x16) += 1;
        *(u8 *)(reg_a5 + 0x16) &= 1;
    }
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x19) < 0) {
        *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
        reg_d6.w = 0;
        reg_d6.b[0] = *(u8 *)(reg_a5 + 0x16);
        reg_d4.h[0] = reg_d6.h[0];
        reg_d4.h[0] *= 8;
        reg_d6.h[0] += reg_d4.h[0];
        input_get_p2_held();
        reg_d0.h[0] &= 0x20;
        if (reg_d0.h[0] != 0) {
            reg_d6.h[0] |= 0x80;
        }
        reg_a1 = (u8 *)(D_00253220);
        reg_d7.w = 8;
        do {
            reg_d0.h[0] = reg_d6.h[0];
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            reg_d6.h[0] += 1;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_d0.w = 0;
    reg_a0 = (u8 *)(&D_0028C190_as_u16);
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x16);
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_00253220);
    reg_d7.w = 8;
    reg_a1 = (u8 *) reg_tmp.w;
    do {
        reg_d1.h[0] = *(u16 *)reg_a0;
        reg_d1.h[0] += 0x7FFF + 0x7D01;
        temp_a1 = reg_d1.h[0];
        reg_tmp1.h[0] = temp_a1;
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        temp_a0 = *(u16 *)(reg_a0 + 2);
        reg_d1.h[0] = temp_a0;
        reg_d2.w = 0x2B;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = 0;
        reg_d1.h[0] += 0x7FFF + 0x7F01;
        sprite_draw_layer5_keep();
        reg_d1.w += 0xFC000400;
        temp_v1_2 = *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d2.h[1] = temp_v1_2;
        reg_d2.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        sprite_draw_layer5_keep();
        reg_a0 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

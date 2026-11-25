#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32);

void func_001A4FA0(void) {
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();
extern u8 D_0025F690[];

void func_001A4FB0(void) {
    s8 temp_a1;
    s8 temp_a3;
    u32 temp_a2;

    reg_a0 = (u8 *)((s8 *)D_0025F690);
    enemy_init_entities();
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x12);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x14);
    reg_a0 = (u8 *)((s8 *) reg_tmp.w);
    reg_tmp.b[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
    reg_tmp.b[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = 0xFF;
    temp_a2 = reg_d0.h[0];
    reg_d1.h[0] = temp_a2;
    reg_d2.h[0] = temp_a2;
    temp_a1 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[1] = temp_a1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] = temp_a2 & reg_tmp.h[0];
    if (reg_d0.h[0] == 2) {
        ENTITY(reg_a6)->offset_x.sh = 1;
        reg_d0.h[0] = 0xFF;
        reg_tmp.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_d0.h[0] = temp_a2 & reg_tmp.h[0];
    }
    reg_tmp.b[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= reg_tmp.h[0];
    temp_a3 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[1] = temp_a3;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= reg_tmp.h[0];
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x1A) = (u16) reg_d2.h[0];
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x14) = (u16) reg_tmp.h[0];
}

s32 func_0014E050();
s32 enemy_remove();
s32 entity_follow_scroll();
extern u16 g_enemies_stopped;
extern u16 D_0029C068[];

void func_001A51B0(void) {
    if (ENTITY(reg_a6)->offset_x.h != 0) goto next_0;
    entity_follow_scroll();
next_0:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_tmp1.w = (s16)reg_d1.h[0];
    reg_d1.w = reg_tmp1.w;
    reg_d1.w += 0x4000;
    if ((s32)reg_d1.w <= 0x3800) goto next_1;
    if ((s32)reg_d1.w < 0xB800) goto next_3;
next_1:
    if (ENTITY(reg_a6)->offset_y.h == 0) goto next_4;
next_2:
    enemy_remove();
    return;
next_3:
    ENTITY(reg_a6)->offset_y.h = 1;
next_4:
    if (g_enemies_stopped != 0) return;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a5 + 0x1B) = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x16);
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0xC);
    func_0014E050();
    *(u16 *)(reg_a0 + 0x12) = *(u16 *)(reg_a5 + 0x12);
    *(u16 *)(reg_a0 + 0x14) = *(u16 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a0 + 0x48) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x4A) = ENTITY(reg_a6)->x.h;
    *(u8 *)(reg_a0 + 3) |= 0x40;
    if (*(u16 *)(reg_a5 + 0x18) == 0) return;
    *(u8 *)(reg_a5 + 0x18) -= 1;
    if (*(u8 *)(reg_a5 + 0x18) == 0) goto next_2;
}

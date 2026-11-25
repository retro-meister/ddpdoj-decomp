#include "common.h"
#include "entity.h"

void func_001C7D10(void);
void func_001C7DA0();
void func_001C7F70();
void func_001C87E0();
void func_001C8CB0();
void func_001C91D0();
void func_001C9570(void);
void func_001C9640(void);
void func_001C9740(void);

s32 boss_movement_start();                            /* extern */
s32 boss_animation_start();                            /* extern */

void func_001C7CB0(void) {
    reg_d0.w = 0;
    boss_movement_start();
    reg_d0.w = 0;
    boss_animation_start();
    reg_d0.w = 2;
    boss_animation_start();
    reg_d0.w = 0xB;
    boss_animation_start();
    reg_d0.w = 0xC;
    boss_animation_start();
    reg_d0.w = 0xD;
    boss_animation_start();
    func_001C7D10();
}

extern u16 *reg_a4_as_u16_p;

void func_001C7D10(void) {
    *reg_a4_as_u16_p = 0;
}

s32 boss_movement_start();                            /* extern */
s32 func_001CBBD0();                            /* extern */
s32 func_001CBC70();                            /* extern */
s32 func_001CBCA0();                            /* extern */

void func_001C7D20(void) {
    reg_d0.w = 3;
    boss_movement_start();
    reg_d0.h[0] = 0x100;
    func_001CBCA0();
    reg_d0.h[0] = 0;
    func_001CBC70();
    reg_d0.h[0] = 0x20;
    func_001CBC70();
    func_001CBBD0();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x10;
    *(s16 *)(reg_a4 + 6) = 4;
    *(s16 *)(reg_a4 + 8) = 0;
    func_001C7DA0(0x10);
}

typedef void (*Fn)();

extern u8 D_0026C6C0[];
s32 boss_phase_start();
s32 boss_part_hide();
s32 func_001CBA00();
extern u8 D_0026C680[];
extern void (*reg_call_target)();

void func_001C7DA0() {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_a1 = D_0026C680;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        func_001CBA00();
        *(u8 *)(reg_a4 + 3) = 1U;
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_a0 = D_0026C6C0;
            reg_a0 += *(u16 *)(reg_a4 + 0x14);
            reg_a0 = *(u8 **)reg_a0;
            reg_call_target = (Fn)(reg_a0);
            reg_call_target();
            *(u16 *)(reg_a4 + 0x14) += 4;
            *(u16 *)(reg_a4 + 8) &= 0x1F;
        }
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 2;
            boss_part_hide();
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 4;
            boss_phase_start();
        }
    }
}

s32 boss_movement_start();                            /* extern */
s32 func_0013B8B0();                            /* extern */
extern s32 D_0026C7B0[];

void func_001C7EE0(void) {
    reg_d0.w = 1;
    boss_movement_start();
    reg_a0 = (u8 *)D_0026C7B0;
    func_0013B8B0();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 6) = 0x101;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 0xA) = 1;
    *(s8 *)(reg_a4 + 0xD) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x2020;
    *(s16 *)(reg_a4 + 0x12) = 4;
    *(s16 *)(reg_a4 + 0x14) = 0;
    func_001C7F70(0x2020, 1, 0x101);
}

extern u8 D_0026C790[];

s32 boss_slots_end();
s32 boss_part_hide_all();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_spawn();
s32 explosion_burst_medium();
s32 func_0013B2E0();
s32 sfx_explosion_ground_medium();
s32 sfx_explosion_boss();
s32 rng_next();
s32 rng_next_unsigned();
s32 rng_next_word();
extern u16 D_0026C6E0[];

void func_001C7F70() {
    u16 *t1;
    u16 *t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;
    u8 *v1;

    v1 = (u8 *)(reg_a4);
    t7 = (*(u8 *)((u8 *)(v1) + (3)));
    if (t7 == 4) {
        (*(u16 *)((u8 *)(v1) + (4))) -= 1;
        if (*(u16 *)(reg_a4 + 4) != 0) {
            goto block_rts;
        }
        boss_slots_end();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    } else {
        if (t7 == 3) {
            reg_d6.w = 0;
            reg_a1 = (u8 *)(D_0026C6E0);
loop_6:
            t3 = *(u16 *)reg_a1;
            reg_d0.h[0] = t3;
            reg_a1 += 2;
            if (reg_d0.h[0] != 0xFFFF) {
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                t1 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t1);
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                t4 = ENTITY(reg_a6)->x.h;
                *(u16 *)(reg_a0 + 4) = t4;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                rng_next();
                reg_d0.b[0] += 4;
                reg_d0.b[0] += *(u8 *)(reg_a4 + 0xD);
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                rng_next_unsigned();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x18) = (u16) reg_d6.h[0];
                reg_d6.h[0] += 1;
                reg_a1 += 2;
                goto loop_6;
            }
            reg_d0.h[0] = 0x1E;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            t6 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = t6;
            reg_tmp.w = 0xF4000000;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
            *(s16 *)(reg_a0 + 0x1E) = 4;
            sfx_explosion_boss();
            v1 = (u8 *)((void *)0x80);
            *(u16 *)(reg_a4 + 4) = 0x80U;
            *(u8 *)(reg_a4 + 3) = 4U;
        }
        t9 = *(u8 *)(reg_a4 + 3);
        if (t9 == 2) {
            boss_flash_running();
            if (cond_flag == 0) {
                reg_a0 = (u8 *)D_0026C790;
                func_0013B2E0();
                boss_part_hide_all();
                *(u8 *)(reg_a4 + 3) = 3U;
                *(u16 *)(reg_a4 + 0xA) = 1U;
            }
        }
        t10 = *(u8 *)(reg_a4 + 3);
        if (t10 == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
            *(u8 *)(reg_a4 + 0x11) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
                rng_next_unsigned();
                reg_d1.b[0] = reg_d0.b[0];
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                rng_next_word();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
                reg_d2.h[0] += reg_d0.h[0];
                reg_tmp2.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = reg_tmp2.h[1];
                rng_next_word();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
                reg_d2.h[0] += reg_d0.h[0];
                reg_d2.h[0] -= 0x1000;
                reg_tmp2.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = reg_tmp2.h[1];
                reg_d3.h[0] = 8;
                reg_d0.h[0] = 0;
                explosion_burst_medium();
                sfx_explosion_ground_medium();
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
            *(u8 *)(reg_a4 + 0xF) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xF) = (u8) *(u8 *)(reg_a4 + 0xE);
                t11 = *(u8 *)(reg_a4 + 6);
                if (t11 != 2) {
                    *(u8 *)(reg_a4 + 6) = (u8) (t11 - 1);
                    *(u8 *)(reg_a4 + 0xD) += 1;
                }
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
                *(u8 *)(reg_a4 + 0x13) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                    reg_a0 = (u8 *)D_0026C6C0;
                    reg_a0 += *(u16 *)(reg_a4 + 0x14);
                    reg_a0 = *(u8 **)reg_a0;
                    reg_call_target = (Fn)(reg_a0);
                    reg_call_target();
                    *(u16 *)(reg_a4 + 0x14) += 4;
                    *(u16 *)(reg_a4 + 0x14) &= 0x1F;
                }
                reg_a1 = (u8 *)(D_0026C6E0);
                reg_a1 += *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                t2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t2);
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                t5 = ENTITY(reg_a6)->x.h;
                *(u16 *)(reg_a0 + 4) = t5;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d0.b[0] += 2;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
                reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 1);
                reg_d0.b[0] += reg_d1.b[0];
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                rng_next_unsigned();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a4 + 8) += 0xA;
                if (*(u16 *)(reg_a4 + 8) == 0xA0) {
                    *(u16 *)(reg_a4 + 8) = 0U;
                    t8 = *(u8 *)(reg_a4 + 6);
                    if (t8 == 2) {
                        reg_d0.h[0] = 0x16;
                        boss_flash_start();
                        *(u8 *)(reg_a4 + 3) = 2U;
                    }
                }
            }
        }
        if (*(u8 *)(reg_a4 + 3) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
            *(u8 *)(reg_a4 + 0x13) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                reg_a0 = (u8 *)D_0026C6C0;
                reg_a0 += *(u16 *)(reg_a4 + 0x14);
                reg_a0 = *(u8 **)reg_a0;
                reg_call_target = (Fn)(reg_a0);
                reg_call_target();
                *(u16 *)(reg_a4 + 0x14) += 4;
                *(u16 *)(reg_a4 + 0x14) &= 0x1F;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_a1 = (u8 *)(D_0026C6E0);
                reg_a1 += *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                *(u16 *)(reg_a4 + 8) += 0xA;
                if ((s16) *(u16 *)(reg_a4 + 8) >= 0xA0) {
                    *(u16 *)(reg_a4 + 8) = 0U;
                    *(u16 *)(reg_a4 + 0xA) -= 1;
                    if (*(u16 *)(reg_a4 + 0xA) == 0) {
                        *(u16 *)(reg_a4 + 6) = 0x2010;
                        *(u16 *)(reg_a4 + 0xE) = 0x1111;
                        *(u8 *)(reg_a4 + 3) = 1U;
                        *(u16 *)(reg_a4 + 0x12) = 0x101;
                        *(u16 *)(reg_a4 + 0x14) = 0U;
                    }
                }
            }
        }
    }
}

s32 boss_movement_start();                            /* extern */
s32 boss_animation_start();                            /* extern */

void func_001C8780(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    reg_d0.w = 2;
    boss_movement_start();
    reg_d0.w = 3;
    boss_animation_start();
    *(s16 *)(reg_a4 + 4) = 0x40;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 0xA) = 2;
    func_001C87E0(0x40);
}

s32 boss_animation_stop();
s32 boss_attack_start();
s32 boss_attack_running();
s32 func_001CBBE0();
s32 rng_next_masked();
extern u16 D_0026C800[];
extern u16 g_loop;

void func_001C87E0() {
    u16 temp_v1;
    u16 temp_v1_2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1_3;
    u8 *temp_a1;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        temp_a1 = (u8 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
            if (*(u16 *)(reg_a4 + 4) == 0) {
                func_001CBBE0();
                if (g_loop != 0) {
                    reg_d0.w = 0xD;
                    boss_animation_stop();
                }
                reg_d0.w = 6;
                boss_attack_start();
                *(u16 *)(reg_a0 + 4) = 0xA0U;
            }
        } else {
            reg_d0.w = 6;
            boss_attack_running();
            if (cond_flag == 0) {
                *(u8 *)(reg_a4 + 3) = 2U;
            }
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        reg_d0.w = 6;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 7;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 8;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_d0.w = 9;
                    boss_attack_running();
                    if (cond_flag == 0) {
                        do {
                            rng_next_masked();
                            reg_d0.h[0] &= 3;
                        } while (*(u16 *)(reg_a4 + 6) == reg_d0.h[0]);
                        *(u16 *)(reg_a4 + 6) = (u16) reg_d0.h[0];
                        reg_a1 = (u8 *)(D_0026C800);
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_a1 += reg_d0.h[0];
                        reg_d0.h[0] = *(u16 *)reg_a1;
                        reg_a1 += 2;
                        boss_attack_start();
                        *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)reg_a1;
                        reg_a1 += 2;
                        *(u16 *)(reg_a4 + 8) += 1;
                        if (*(u16 *)(reg_a4 + 8) == 3) {
                            *(u16 *)(reg_a4 + 8) = 0U;
                            *(u8 *)(reg_a4 + 3) = 3U;
                            *(u16 *)(reg_a4 + 4) = 0x40U;
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 3) {
        reg_d0.w = 6;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 7;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 8;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_d0.w = 9;
                    boss_attack_running();
                    if (cond_flag == 0) {
                        temp_v1_2 = *(u16 *)(reg_a4 + 4);
                        if (temp_v1_2 != 0) {
                            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1_2 - 1);
                            if (*(u16 *)(reg_a4 + 4) == 0) {
                                *(s16 *)(reg_a4 + 0xC) = 0x20;
                                *(u16 *)(reg_a4 + 0xE) = 0x4040U;
                                *(u16 *)(reg_a4 + 0x10) = 4U;
                            }
                        } else {
                            reg_d0.w = 0xB;
                            boss_attack_running();
                            if (cond_flag == 0) {
                                reg_d0.w = 0xB;
                                boss_attack_start();
                                *(u16 *)(reg_a0 + 0xC) = (u16) *(u16 *)(reg_a4 + 0xE);
                                temp_v1_3 = *(u8 *)(reg_a4 + 0xF);
                                if (temp_v1_3 != 0x10) {
                                    *(u8 *)(reg_a4 + 0xF) = (u8) (temp_v1_3 - 8);
                                    if ((s8) *(u8 *)(reg_a4 + 0xF) < 0x11) {
                                        *(u8 *)(reg_a4 + 0xF) = 0x10U;
                                    }
                                }
                                *(u16 *)(reg_a4 + 0x10) -= 1;
                                if (*(u16 *)(reg_a4 + 0x10) == 0) {
                                    *(u8 *)(reg_a4 + 3) = 2U;
                                } else {
                                    goto block_31;
                                }
                            } else {
block_31:
                                reg_d0.w = 0xA;
                                boss_attack_running();
                                if (cond_flag == 0) {
                                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
                                    *(u8 *)(reg_a4 + 0xD) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a4 + 0xD) = *(u8 *)(reg_a4 + 0xC);
                                        reg_d0.w = 0xA;
                                        boss_attack_start();
                                        rng_next_masked();
                                        reg_d0.h[0] &= 3;
                                        reg_d0.h[0] += *(u16 *)(reg_a4 + 0xA);
                                        *(u16 *)(reg_a0 + 4) = (u16) reg_d0.h[0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 4) {
        reg_d0.w = 0xA;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            boss_attack_running();
            if (cond_flag == 0) {
                *(u8 *)(reg_a4 + 3) = 0U;
                *(u16 *)(reg_a4 + 4) = 0x40U;
            }
        }
    }
}


void func_001C8C10(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 0x60;
    *(s16 *)(reg_a4 + 6) = 0x6060;
    *(s16 *)(reg_a4 + 8) = 0x1E;
    *(s8 *)(reg_a4 + 0xB) = 1;
    *(s16 *)(reg_a4 + 0x10) = 0x3040;
    *(s16 *)(reg_a4 + 0x12) = 0x20;
    *(s16 *)(reg_a4 + 0xC) = 0x303;
    *(s16 *)(reg_a4 + 0x16) = 0x2024;
    *(s16 *)(reg_a4 + 0x1A) = 0x303;
    *(s8 *)(reg_a4 + 0x15) = 0;
    *(s8 *)(reg_a4 + 0x14) = 0;
    *(s8 *)(reg_a4 + 0x19) = 2;
    *(s8 *)(reg_a4 + 0x18) = 2;
    func_001C8CB0();
}

s32 boss_animation_start();
s32 boss_animation_running();

void func_001C8CB0(arg1)
    s32 arg1;
{
    s32 var_a1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_a0_8;

    var_a1 = arg1;
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 2;
            boss_animation_stop();
            reg_d0.w = 6;
            boss_animation_start();
            var_a1 = 2;
            *(u8 *)(reg_a4 + 3) = 2U;
            *(u8 *)(reg_a4 + 2) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 2);
    if (temp_a0 == 1) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xE;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x17);
                *(u8 *)(reg_a4 + 0x17) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x17) = (u8) *(u8 *)(reg_a4 + 0x16);
                    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
                    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
                    if ((s32) reg_tmp.w < 0x7700) {
                        *(u8 *)(reg_a4 + 0x17) = 8U;
                    }
                    reg_d0.w = 0xE;
                    boss_attack_start();
                    *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)(reg_a4 + 0x18);
                    *(u16 *)(reg_a0 + 8) = 0xFFFB;
                    *(s16 *)(reg_a0 + 0x16) = 4;
                    *(s16 *)(reg_a0 + 0x18) = 5;
                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x1B);
                    *(u8 *)(reg_a4 + 0x1B) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a4 + 0x1B) = (u8) *(u8 *)(reg_a4 + 0x1A);
                        *(u16 *)(reg_a0 + 8) = 0xFFFA;
                        *(s16 *)(reg_a0 + 0x16) = 0xB;
                        *(s16 *)(reg_a0 + 0x18) = 0xC;
                        *(s8 *)(reg_a0 + 7) = 4;
                        *(u8 *)(reg_a4 + 2) = 2U;
                    }
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 2);
    if (temp_a0_2 == 2) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_d0.w = 1;
                boss_attack_start();
                *(u8 *)(reg_a0 + 5) = (u8) *(u8 *)(reg_a4 + 0xB);
                *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)(reg_a4 + 8);
                *(u8 *)(reg_a4 + 0xB) = (u8) -(s8) *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a4 + 2) = 1U;
                *(u16 *)(reg_a4 + 8) += 1;
                if ((s16) *(u16 *)(reg_a4 + 8) >= 0x28) {
                    *(u16 *)(reg_a4 + 8) = 0x28U;
                }
            }
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 2) {
        reg_d0.w = 0xA;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
                *(u8 *)(reg_a4 + 0x11) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
                    *(u8 *)(reg_a4 + 3) = 3U;
                    *(u16 *)(reg_a4 + 4) = 0x20U;
                    temp_a0_4 = *(u8 *)(reg_a4 + 0x15);
                    if (temp_a0_4 != 4) {
                        *(u8 *)(reg_a4 + 0x15) = (u8) (temp_a0_4 + 1);
                    }
                }
            }
        }
    }
    temp_a0_5 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_5 == 3) {
        reg_d0.w = 0xC;
        boss_attack_running();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 9;
                boss_animation_start();
                *(u8 *)(reg_a4 + 3) = 4U;
            }
        }
    }
    temp_a0_6 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_6 == 4) {
        reg_d0.w = 9;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xD;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
                *(u8 *)(reg_a4 + 0x13) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                    reg_d0.w = 0xD;
                    boss_attack_start();
                    *(u16 *)(reg_a0 + 6) = 4U;
                    *(u8 *)(reg_a4 + 0xD) -= 1;
                    if (*(u8 *)(reg_a4 + 0xD) == 0) {
                        *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
                        *(u8 *)(reg_a4 + 0x12) -= 4;
                        if ((s8) *(u8 *)(reg_a4 + 0x12) < 0x11) {
                            *(u8 *)(reg_a4 + 0x12) = 0x10U;
                        }
                        *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                        *(u8 *)(reg_a4 + 3) = 5U;
                    }
                }
            }
        }
    }
    temp_a0_7 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_7 == 5) {
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xA;
            boss_animation_start();
            *(u8 *)(reg_a4 + 3) = 2U;
            temp_a0_8 = *(u8 *)(reg_a4 + 0x14);
            if (temp_a0_8 != 4) {
                *(u8 *)(reg_a4 + 0x14) = (u8) (temp_a0_8 + 1);
            }
        }
    }
}


void func_001C91A0(void) {
    reg_a4[3] = 0;
    *(s16 *)(reg_a4 + 4) = 0x60;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 8) = 8;
    func_001C91D0(0x60);
}

s32 aim_at_player();
s32 direction_turn_toward();
extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];

void func_001C91D0() {
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u8 temp_a0_3;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] = temp_a1;
            reg_d0.h[0] += D_0026C250[0];
            reg_d1.h[0] += D_0026C252[0];
            aim_at_player();
            *(u8 *)(reg_a4 + 0xB) = (u8) reg_d1.b[0];
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            temp_a1_2 = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] = temp_a1_2;
            reg_d0.h[0] += D_0026C260[0];
            reg_d1.h[0] += D_0026C262[0];
            aim_at_player();
            *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 1) {
        reg_d0.w = 8;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_d0.w = 8;
                boss_animation_start();
                reg_d7.w = 1;
                do {
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    temp_a1_3 = ENTITY(reg_a6)->x.h;
                    reg_d1.h[0] = temp_a1_3;
                    reg_d0.h[0] += D_0026C250[0];
                    reg_d1.h[0] += D_0026C252[0];
                    aim_at_player();
                    reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
                    direction_turn_toward();
                    *(u8 *)(reg_a4 + 0xB) = (u8) reg_d1.b[0];
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    temp_a1_4 = ENTITY(reg_a6)->x.h;
                    reg_d1.h[0] = temp_a1_4;
                    reg_d0.h[0] += D_0026C260[0];
                    reg_d1.h[0] += D_0026C262[0];
                    aim_at_player();
                    reg_d0.b[0] = *(u8 *)(reg_a4 + 0xA);
                    direction_turn_toward();
                    *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.w = 0xD;
                boss_attack_start();
                *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a4 + 0xA);
                *(u16 *)(reg_a4 + 8) -= 1;
                if (*(u16 *)(reg_a4 + 8) == 0) {
                    *(s16 *)reg_a4 = 0;
                    reg_d0.w = 4;
                    boss_phase_start();
                }
            }
        }
    }
}

s32 boss_movement_start();                            /* extern */

void func_001C9440(void) {
    reg_d0.w = 4;
    boss_movement_start();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x20;
}

s32 boss_movement_current();

void func_001C9480() {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 5) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 3;
            boss_phase_start();
        }
    }
}

extern u8 D_0026C810[];

void func_001C9510(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 4) = 0x20;
    reg_tmp.w = (u32) D_0026C810;
    *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a4 + 0xC) = 1;
    func_001C9570();
}


void func_001C9570(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if ((temp_a0 == 1) && (boss_movement_current(temp_a0), (reg_d0.h[0] == 5))) {
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 8);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
        reg_a1 = (u8 *)(reg_tmp.w);
        temp_a0_2 = *(u16 *)(reg_a4 + 6);
        reg_a1 += temp_a0_2;
        if (*(s16 *)reg_a1 != -1) {
            func_001C9640();
            return;
        }
        reg_d0.w = 4;
        boss_phase_start();
        *(s16 *)reg_a4 = 0;
    }
}

s32 boss_movement_start();
s32 enemy_switch_target_player();

void func_001C9640(void) {
    reg_d0.w = 6;
    boss_movement_start();
    *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)(reg_a1 + 2);
    *(u16 *)(reg_a4 + 6) += 4;
    enemy_switch_target_player();
    if (*(u8 *)(reg_a4 + 2) != 0) {
        reg_d0.w = 2;
        boss_attack_start();
        *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)(reg_a4 + 0xC);
        *(u16 *)(reg_a4 + 0xC) *= 0xFFFF;
    }
    *(u8 *)(reg_a4 + 2) = 1U;
}

s32 boss_animation_start(s32, s32, s32);   /* extern */
s32 boss_attack_start();                            /* extern */

void func_001C96E0(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x10;
    *(s16 *)(reg_a4 + 6) = 0x200A;
    *(s16 *)(reg_a4 + 0xC) = 0x101;
    reg_d0.w = 0xA;
    boss_animation_start(0x101, 0x200A, 0x10);
    reg_d0.w = 0xF;
    boss_attack_start();
    func_001C9740();
}

void func_001C9740(void) {
}

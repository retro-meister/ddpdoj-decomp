#include "common.h"
#include "entity.h"

void func_001D28B0(void);
void func_001D2930();
void func_001D30B0(void);
void func_001D3170(u8 arg0);
void func_001D31D0(void);
void func_001D3270(void);
void func_001D32E0(void);
void func_001D3340(void);
void func_001D3420(void);
void func_001D34C0();

s32 boss_movement_start();                            /* extern */
s32 boss_animation_start();                            /* extern */

void func_001D2880(void) {
    reg_d0.w = 0;
    boss_movement_start();
    reg_d0.w = 7;
    boss_animation_start();
    func_001D28B0();
}

extern s16 *reg_a4_as_s16_p;

void func_001D28B0(void) {
    *reg_a4_as_s16_p = 0;
}

s32 func_0013B8B0();                            /* extern */
extern s32 D_0026D990[];
extern s32 *reg_a0_as_s32_p;

void func_001D28C0(void) {
    reg_a0_as_s32_p = D_0026D990;
    func_0013B8B0();
    *(s16 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x101;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 0xA) = 1;
    *(s8 *)(reg_a4 + 0xD) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x2020;
    *(s16 *)(reg_a4 + 0x12) = 0;
    func_001D2930(1, 0x101);
}

typedef void (*Fn)();

s32 boss_slots_end();
s32 boss_part_hide_all();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_spawn();
s32 func_0013AAB0();
s32 func_0013B2E0();
s32 func_0018D500();
s32 func_0018D520();
s32 func_0018D560();
s32 func_0018D660();
s32 rng_next();
s32 rng_next_unsigned();
s32 rng_next_word();
extern u16 D_0026D810[];
extern u16 D_0026D8A0[];
extern void (*jtbl_0028E3F4)();

void func_001D2930() {
    u8 bits;

    if (*(u16 *)(reg_a4 + 2) != 4) goto next_s3;
    *(u16 *)(reg_a4 + 4) -= 1;
    if (*(u16 *)(reg_a4 + 4) != 0) goto next_s4rts;
    boss_slots_end();
    *(u16 *)reg_a4 = 0;
next_s4rts:
    return;
next_s3:
    if (*(u16 *)(reg_a4 + 2) != 3) goto next_s2;
    reg_d6.w = 0;
    reg_a1 = (u8 *) D_0026D810;
loop_10:
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if ((s16) reg_d0.h[0] == -1) goto next_20;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    rng_next();
    reg_d0.b[0] += 4;
    reg_d0.b[0] += reg_a4[0xD];
    reg_a0[0x1B] = reg_d0.b[0];
    rng_next_unsigned();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x18) = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_10;
next_20:
    *(u16 *)(reg_a4 + 4) = 0x80;
    *(u16 *)(reg_a4 + 2) = 4;
    func_0018D660();
    return;
next_s2:
    if (*(u16 *)(reg_a4 + 2) != 2) goto next_s1;
    boss_flash_running();
    if (cond_flag != 0) goto next_s1;
    reg_a0 = (u8 *) D_0026D8A0;
    func_0013B2E0();
    boss_part_hide_all();
    *(u16 *)(reg_a4 + 0xA) = 1;
    *(u16 *)(reg_a4 + 2) = 3;
    return;
next_s1:
    if (*(u16 *)(reg_a4 + 2) != 1) goto next_s0;
    reg_tmp.b[0] = reg_a4[0x11];
    reg_a4[0x11] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_reon;
    reg_a4[0x11] = reg_a4[0x10];
    rng_next_unsigned();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    rng_next_word();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] += reg_d0.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    rng_next_word();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d2.h[0] += reg_d0.h[0];
    reg_d2.h[0] -= 0x1000;
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    reg_d3.h[0] = 8;
    reg_d0.h[0] = 0;
    func_0013AAB0();
    if (reg_a4[6] == 2) goto next_reon;
    func_0018D560();
next_reon:
    reg_tmp.b[0] = reg_a4[0xF];
    reg_a4[0xF] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec;
    reg_a4[0xF] = reg_a4[0xE];
    if (reg_a4[6] == 2) goto next_intdec;
    reg_a4[6] -= 1;
    reg_a4[0xD] += 1;
next_intdec:
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_s0;
    reg_a4[7] = reg_a4[6];
    if (reg_a4[6] == 2) goto next_intdec20;
    reg_tmp.b[0] = reg_a4[0x12];
    reg_a4[0x12] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec20;
    reg_a4[0x12] = 4;
    func_0018D520();
next_intdec20:
    reg_a1 = (u8 *) D_0026D810;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    rng_next();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 2;
    reg_d0.b[0] += 2;
    reg_d1.b[0] = reg_a4[0xD];
    reg_d1.b[0] = (s8) reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    reg_a0[0x1B] = reg_d0.b[0];
    rng_next_unsigned();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a4 + 8) += 8;
    if (*(u16 *)(reg_a4 + 8) != 0x80) goto next_s0;
    *(u16 *)(reg_a4 + 8) = 0;
    if (reg_a4[6] != 2) goto next_s0;
    reg_d0.h[0] = 0xA;
    boss_flash_start();
    *(u16 *)(reg_a4 + 2) = 2;
    return;
next_s0:
    if (*(u16 *)(reg_a4 + 2) != 0) goto block_rts;
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    reg_a4[7] = reg_a4[6];
    bits = reg_a4[0x13];
    if (bits & 1) {
        reg_a4[0x13] = bits & 0xFE;
        goto next_40;
    }
    reg_a4[0x13] = bits | 1;
    reg_a0 = (u8 *) func_0018D500;
    rng_next_unsigned();
    if (reg_d0.sb[0] >= 0) goto next_30;
    reg_a0 = (u8 *) func_0018D520;
next_30:
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
next_40:
    reg_a1 = (u8 *) D_0026D810;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a4 + 8) += 8;
    if ((s32) *(u16 *)(reg_a4 + 8) < 0x80) goto block_rts;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) != 0) goto block_rts;
    *(u16 *)(reg_a4 + 6) = 0x2010;
    *(u16 *)(reg_a4 + 0xE) = 0x1111;
    *(u16 *)(reg_a4 + 2) = 1;
block_rts:
    return;
}

s32 boss_movement_start();                            /* extern */
s32 boss_attack_start();                            /* extern */

void func_001D3070(void) {
    reg_d0.w = 1;
    boss_movement_start();
    reg_d0.w = 6;
    boss_attack_start();
    reg_d0.w = 7;
    boss_attack_start();
    func_001D30B0();
}

s32 boss_phase_start();                            /* extern */
s32 boss_attack_running();                            /* extern */

void func_001D30B0(void) {
    reg_d0.w = 6;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 3;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}

s32 boss_movement_start();                            /* extern */
s32 boss_animation_start();                            /* extern */

void func_001D30F0(void) {
    u8 temp_a0;
    u8 temp_v0;

    reg_d0.w = 2;
    boss_movement_start();
    reg_d0.w = 4;
    boss_animation_start();
    temp_a0 = *(u8 *)(reg_a6 + 0x115);
    *(u8 *)(reg_a0 + 3) = temp_a0;
    *(s8 *)(reg_a0 + 2) = 1;
    temp_v0 = *(u8 *)(reg_a6 + 0x115);
    if ((s32) temp_v0 < 0x11) {
        func_001D3170(temp_a0);
        return;
    }
    *(u8 *)(reg_a6 + 0x115) = (u8) (temp_v0 - 0x30);
    func_001D3170(temp_a0);
}

s32 boss_phase_start();                            /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_start();                            /* extern */

void func_001D3170(u8 arg0) {
    reg_d0.w = 4;
    boss_animation_running();
    if (cond_flag == 0) {
        reg_d0.w = 5;
        boss_attack_start();
        reg_d0.w = 6;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}


void func_001D31C0(void) {
    func_001D31D0();
}

s32 boss_phase_start();                            /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_running();                            /* extern */

void func_001D31D0(void) {
    reg_d0.w = 5;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 5;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 4;
            boss_phase_start();
            *reg_a4_as_s16_p = 0;
        }
    }
}

s32 boss_movement_start();                            /* extern */
s32 boss_attack_start();                            /* extern */

void func_001D3230(void) {
    reg_d0.w = 3;
    boss_movement_start();
    reg_d0.w = 3;
    boss_attack_start();
    reg_d0.w = 4;
    boss_attack_start();
    func_001D3270();
}

s32 boss_phase_start();                            /* extern */
s32 boss_attack_running();                            /* extern */

void func_001D3270(void) {
    reg_d0.w = 4;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 5;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}

s32 boss_animation_start();                            /* extern */

void func_001D32B0(void) {
    reg_d0.w = 4;
    boss_animation_start();
    *(s16 *)(reg_a0 + 2) = 0x5001;
    func_001D32E0();
}

s32 boss_phase_start();                            /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_start();                            /* extern */

void func_001D32E0(void) {
    reg_d0.w = 4;
    boss_animation_running();
    if (cond_flag == 0) {
        reg_d0.w = 8;
        boss_attack_start();
        reg_d0.w = 7;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}


void func_001D3330(void) {
    reg_a4_as_s16_p[1] = 0;
    func_001D3340();
}

s32 boss_phase_start(void *);                      /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_running(void *);                      /* extern */

void func_001D3340(void) {
    u16 temp_v1;
    u8 *temp_a0;

    temp_a0 = reg_a4 + 2;
    temp_v1 = *(u16 *)(reg_a4 + 2);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 2;
            boss_phase_start(temp_a0);
            *(s16 *)reg_a4 = 0;
        }
    } else {
        reg_d0.w = 8;
        boss_attack_running(temp_a0);
        if (cond_flag == 0) {
            reg_d0.w = 5;
            boss_animation_running();
            if (cond_flag == 0) {
                *(u16 *)(reg_a4 + 2) = 1U;
            }
        }
    }
}

s32 boss_movement_start(s32);                     /* extern */

void func_001D33E0(void) {
    *(s16 *)(reg_a4 + 2) = 0x80;
    reg_d0.w = 1;
    boss_movement_start(0x80);
    func_001D3420();
}

s32 boss_animation_start();
s32 boss_attack_start();
s32 func_001D4550();

void func_001D3420() {
    *(u16 *)(reg_a4 + 2) -= 1;
    if ((s16) *(u16 *)(reg_a4 + 2) < 0) {
        reg_d0.w = 2;
        boss_animation_start();
        reg_d0.w = 1;
        boss_attack_start();
        reg_d0.w = 2;
        boss_attack_start();
        func_001D4550();
        *(s16 *)reg_a4 = 0;
    }
}

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u16 unk4;
    u16 unk6;
} WorkRegA4;

extern WorkRegA4 *reg_a4_as_WorkRegA4_p;

void func_001D3490(void) {
    reg_a4_as_WorkRegA4_p->unk2 = 0x40;
    reg_a4_as_WorkRegA4_p->unk4 = 0x404;
    reg_a4_as_WorkRegA4_p->unk6 = 0x17;
    func_001D34C0(0x404, 0x40);
}

s32 boss_phase_start();
s32 boss_part_hide();
s32 rng_next_masked();
s32 func_002013F0();
extern u8 D_0026D9C0[];

void func_001D34C0() {
    u16 temp_a2;
    u16 temp_v1;

    temp_v1 = *(u16 *)(reg_a4 + 2);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 8;
            boss_part_hide();
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_a0 = (u8 *)func_0018D500;
        rng_next_unsigned();
        if ((s8) reg_d0.b[0] >= 0) {
            reg_a0 = (u8 *)func_0018D520;
        }
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] = *(u16 *)(D_0026D9C0 + (reg_d0.h[0] * 2));
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a2;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x800;
        *(s8 *)(reg_a0 + 0x1B) = 2;
        rng_next_masked();
        reg_d0.b[0] += 0x60;
        *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
        *(s16 *)(reg_a0 + 0x20) = 0;
        *(u16 *)(reg_a0 + 0x22) = 0xFFF9;
        func_002013F0();
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += 0x7FFF + 0x6641;
        *(u16 *)(reg_a0 + 0x26) = (u16) reg_d1.h[0];
        func_002013F0();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d0.h[0];
        *(u16 *)(reg_a0 + 0x28) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a4 + 6) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 6) < 0) {
            reg_d0.w = 8;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}

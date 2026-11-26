#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void boss_slots_step(void);
void boss_flash_update(void);

extern u8 D_00295E50[];
extern u8 *D_00295E54[];
extern u16 D_00295E5A[];
extern u32 *D_00295E9C[];
extern u8 D_00295EA0[];
extern u8 *D_00295F40[];
extern s64 D_002960A8[];
extern u8 *D_00296210[];

void boss_slots_init(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    memset(D_00295E50, 0, MAIN_OR_DEATH_LABEL(0x490, 0x4D0));
    if (reg_a0 != 0) {
        ((s32 *)D_00295E54)[0] = (int)reg_a0;
        D_00295E5A[0] = 0xFFFF;
    }
    if (reg_a3 != 0) {
        ((s32 *)D_00295F40)[0] = (int)reg_a3;
    }
    if (reg_a1 != 0) {
        D_002960A8[0] = (s32)reg_a1;
    }
    if (reg_a2 != 0) {
        D_00295E9C[0] = (u32 *)reg_a2;
        reg_a6 = (u8 *)D_00295EA0;
loop_8:
        reg_d0.w = *(u32 *)reg_a2;
        reg_a2 += 4;
        if (reg_d0.w != -1U) {
            ENTITY(reg_a6)->flags.h = 0x8000;
            ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
            ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
            reg_a6 += 8;
            goto loop_8;
        }
    }
    if (reg_a4 != 0) {
        ((s32 *)D_00296210)[0] = (int)reg_a4;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u16 D_002962DE[];

void boss_slots_end(void) {
    ((s16 *)D_002962DE)[0] = 1;
}

#pragma push
#pragma opt_propagation off
#pragma divbyzerocheck on
extern u8 g_setting_difficulty;
extern u16 g_rank;

void boss_level_get(void) {
    u8 val = g_setting_difficulty;
    s32 quotient;

    reg_d1.w = 0;
    reg_d0.h[0] = (u16)((s16)reg_d0.h[0] >> 2);
    reg_d2.h[0] = g_rank;
    reg_d1.h[0] = reg_d0.h[0];
    reg_tmp2.w = (u32)(s16)reg_d2.h[0];
    reg_d2.w = reg_tmp2.w;
    quotient = (s16)reg_d2.h[0] / (s16)reg_d1.h[0];
    reg_d1.b[0] = val;
    reg_d1.b[0] -= 1;
    reg_d0.w = 4;
    reg_d2.h[0] = (u16)quotient;
}
#pragma pop

typedef void (*Fn)();


extern u16 g_frame_mod2;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u8 g_boss_present_b1;
extern u16 g_enemies_stopped;
extern u16 g_true_last_boss;
extern u16 D_002962DE[];
extern u8 *reg_call_target_as_u8_p;

void boss_slots_run(void) {
    u32 temp_s0;
    u8 *temp_s1;
    u32 temp_v0;

    cond_flag = 0;
    if (D_002962DE[0] != 0) {
        cond_flag = 1;
        return;
    }
    if (g_enemies_stopped == 0) {
        boss_slots_step();
        if (!(g_boss_present_b1 & 0x40) && (g_boss_present_b1 & 0x10)) {
            reg_d0.h[0] = g_p1_hyper_active;
            temp_v0 = reg_d0.h[0] | g_p2_hyper_active;
            reg_d0.h[0] = temp_v0;
            if ((temp_v0 & 0xFFFF) && (0 <= (s16)g_true_last_boss) && (g_frame_mod2 != 0)) {
                boss_slots_step();
            }
        }
    }
    if (((s32 *)D_00295E9C)[0] != 0) {
        reg_a4 = (u8 *)D_00295EA0;
        reg_d7.h[0] = 0x13;
        do {
            temp_s1 = (u8 *)(reg_a4);
            if ((0 > (s64)*(s16 *)((u8 *)(temp_s1) + (0))) && ((*(u8 *)((u8 *)(temp_s1) + (0))) & 1)) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(temp_s1) + (2)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(temp_s1) + (4)));
                reg_a3 = (u8 *)reg_tmp.w;
                reg_call_target_as_u8_p = reg_a3;
                temp_s0 = reg_d7.w;
                ((Fn)reg_call_target_as_u8_p)();
                reg_a4 = temp_s1;
                reg_d7.w = temp_s0;
            }
            reg_a4 += 8;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    boss_flash_update();
    cond_flag = 0;
}

extern u8 D_00295E7C[];
extern u16 D_00295E52[];
extern u8 *D_00295E54[];
extern u16 D_00295E58[];
extern u16 D_00295E5C[];
extern u8 *D_00295F40[];
extern u16 D_00295F44[];
extern u16 D_002960B0[];
extern u8 *D_00296210[];
extern u16 D_00296214[];

void boss_slots_step(void) {
    u32 t1;
    u32 t2;
    u32 t3;

    if (D_00296210[0] != 0) {
        reg_a4 = (u8 *)(D_00296214);
        reg_d7.w = 4;
        do {
            reg_d0.h[0] = *(u16 *)reg_a4;
            if (reg_d0.h[0] != 0) {
                reg_d0.h[0] &= 0xFF;
                reg_d0.h[0] *= 8;
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
                *(u8 *)(reg_a4 + 1) |= 1;
                if (reg_tmp.b[0] & 1) {
                    reg_d0.h[0] += 4;
                }
                reg_a0 = D_00296210[0];
                reg_a0 += reg_d0.h[0];
                reg_a0 = *(u8 **)reg_a0;
                reg_call_target = (Fn)(reg_a0);
                t1 = reg_d7.w;
                reg_call_target();
                reg_d7.w = t1;
            }
            reg_a4 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (D_00295E54[0] != 0) {
        if (((u16 *)D_00295E50)[0] != 0) {
            ((u16 *)D_00295E50)[0] = 0;
            reg_a0 = (u8 *)D_00295E7C;
            D_00295E58[0] = 0;
            reg_a1 = (u8 *)(D_00295E5C);
            reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xF, 0x1F);
            D_00295E5A[0] = D_00295E52[0];
            do {
                *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                reg_a1 += 2;
            } while ((s16)(--reg_d0.h[0]) >= 0);
        }
        reg_a0 = D_00295E54[0];
        reg_d0.h[0] = D_00295E5A[0];
        if ((s16)(reg_d0.h[0]) != -1) {
            reg_d0.h[0] *= 8;
            reg_d0.h[0] += D_00295E58[0];
            reg_a0 += reg_d0.h[0];
            reg_a0 = *(u8 **)reg_a0;
            reg_a4 = (u8 *)(D_00295E5C);
            reg_call_target = (Fn)(reg_a0);
            reg_call_target();
            if (D_00295E58[0] == 0) {
                D_00295E58[0] += 4;
            }
        }
    }
    if (D_002960A8[0] != 0) {
        reg_a4 = (u8 *)(D_002960B0);
        reg_d7.w = 9;
        do {
            reg_d0.h[0] = *(u16 *)reg_a4;
            if (reg_d0.h[0] != 0) {
                reg_d0.h[0] &= 0xFF;
                reg_d0.h[0] *= 8;
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
                *(u8 *)(reg_a4 + 1) |= 1;
                if (reg_tmp.b[0] & 1) {
                    reg_d0.h[0] += 4;
                }
                if (!(*(u8 *)(reg_a4 + 1) & 2)) {
                    reg_a0 = (u8 *) D_002960A8[0];
                    reg_a0 += reg_d0.h[0];
                    reg_a0 = *(u8 **)reg_a0;
                    reg_call_target = (Fn)(reg_a0);
                    t2 = reg_d7.w;
                    reg_call_target();
                    reg_d7.w = t2;
                }
            }
            reg_a4 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (D_00295F40[0] != 0) {
        reg_a4 = (u8 *)(D_00295F44);
        reg_d7.w = 9;
        do {
            reg_d0.h[0] = *(u16 *)reg_a4;
            if (reg_d0.h[0] != 0) {
                reg_d0.h[0] &= 0xFF;
                reg_d0.h[0] *= 8;
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
                *(u8 *)(reg_a4 + 1) |= 1;
                if (reg_tmp.b[0] & 1) {
                    reg_d0.h[0] += 4;
                }
                reg_a0 = D_00295F40[0];
                reg_a0 += reg_d0.h[0];
                reg_a0 = *(u8 **)reg_a0;
                reg_call_target = (Fn)(reg_a0);
                t3 = reg_d7.w;
                reg_call_target();
                reg_d7.w = t3;
            }
            reg_a4 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

extern s16 D_002962B4[];

void boss_phase_start(void) {
    s32 d0 = reg_d0.w;
    s32 d1 = reg_d1.w;
    u32 tmp;

    reg_a0 = (u8 *) ((s16 *)D_00296214);
    reg_d1.w = 4;
loop_1:
    if (*(s16 *) reg_a0 != 0) goto next_1;
    reg_d0.h[0] |= 0x8000;
    *(s16 *) reg_a0 = reg_d0.h[0];
    reg_d1.w = d1;
    reg_d0.w = d0;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *) D_002962B4;
    reg_d1.w = d1;
    reg_d0.w = d0;
}

void boss_phase_running(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_00296214;
    reg_d1.w = 5;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    cond_flag = 1;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    cond_flag = 0;
}

void boss_phase_stop(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_00296214;
    reg_d1.w = 4;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    *(u16 *) reg_a0 = 0;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
}

void boss_phase_stop_all(void)
{
  s16 *savedAddressRegister;
  u32 savedDataRegister;
  s16 *firstEntry;
  savedDataRegister = reg_d0.w;
  firstEntry = ((s16 *)D_00296214);
  savedAddressRegister = ((s16 *)reg_a0);
  reg_d0.w = 4;
  if (reg_d0.w && reg_d0.w)
  {
  }
  (*(s16 **)&reg_a0) = firstEntry;
  do
  {
    *(*(s16 **)&reg_a0) = 0;
    (*(s16 **)&reg_a0) += 0x10;
  }
  while (((s16) (--reg_d0.h[0])) >= 0);
  (*(s16 **)&reg_a0) = savedAddressRegister;
  reg_d0.w = savedDataRegister;
}

void boss_movement_stop(void) {
    D_00295E5A[0] = 0xFFFF;
}

void boss_movement_current(void) {
    *(u16 *)&reg_d0 = D_00295E5A[0];
}


void boss_movement_start(void) {
    ((s16 *)D_00295E50)[0] = 1;
    reg_a0 = (u8 *)D_00295E7C;
    D_00295E52[0] = reg_d0.h[0];
}

void boss_part_show(void) {
    u8 *savedAddress;
    u32 savedData;

    savedData = reg_d0.w;
    savedAddress = reg_a0;
    reg_a0 = D_00295EA0;
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    *(s16 *)reg_a0 |= 1;
    reg_a0 = savedAddress;
    reg_d0.w = savedData;
}


void boss_part_show_all(void)
{
    s16 *savedAddress;
    u32 savedData;
    s16 *table;

    savedData = reg_d0.w;
    table = ((s16 *)D_00295EA0);
    savedAddress = ((s16 *)reg_a0);
    (*(s16 **)&reg_a0) = table;
    reg_d0.h[0] = 0x13;

    do {
        s16 flags = *((s16 *)reg_a0);

        if (0 > (s64)flags) {
            *(*(s16 **)&reg_a0) = flags | 1;
        }
        (*(s16 **)&reg_a0) += 4;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    (*(s16 **)&reg_a0) = savedAddress;
    reg_d0.w = savedData;
}

void boss_part_hide_all(void)
{
    s16 *savedAddressRegister;
    u32 savedDataRegister;
    s32 entryFlags;

    savedDataRegister = reg_d0.w;
    savedAddressRegister = ((s16 *)reg_a0);
    (*(s16 **)&reg_a0) = ((s16 *)D_00295EA0);
    reg_d0.h[0] = 0x13;

    do {
        entryFlags = *((s16 *)reg_a0);
        if (0 <= entryFlags) {
            goto nextEntry;
        }
        *(*(s16 **)&reg_a0) = entryFlags & ~1;

    nextEntry:
        (*(s16 **)&reg_a0) += 4;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    (*(s16 **)&reg_a0) = savedAddressRegister;
    reg_d0.w = savedDataRegister;
}

void boss_part_hide(void)
{
  u8 *savedAddress;
  int new_var;
  u32 savedData;
  unsigned int new_var2;
  new_var2 = reg_d0.w;
  savedAddress = reg_a0;
  reg_a0 = D_00295EA0;
  reg_d0.h[0] *= 8;
  new_var = 0;
  reg_a0 += reg_d0.h[new_var];
  *((s16 *) reg_a0) &= ~1;
  reg_a0 = savedAddress;
  reg_d0.w = new_var2;
}

extern u16 D_00296084[];

void boss_animation_start(void) {
    u32 t1;
    u32 t2;
    u32 s0;
    u32 saved;
    u32 s2;

    s0 = reg_d0.w;
    saved = reg_d1.w;
    s2 = reg_d2.w;
    reg_a0 = (u8 *)(D_00295F44);
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *)reg_a0;
    if (reg_d2.h[0] == 0) {
        goto block_7;
    }
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] == reg_d2.h[0]) {
        goto block_8;
    }
    reg_a0 += 0x20;
    t1 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t1;
    if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    reg_a0 = (u8 *)(D_00295F44);
    reg_d1.w = 9;
block_5:
    if ((s16) *(u16 *)reg_a0 != 0) {
        goto block_7;
    }
    reg_d0.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_d0.w = s0;
    reg_d1.w = saved;
    reg_d2.w = s2;
    return;
block_7:
    reg_a0 += 0x20;
    t2 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t2;
    if (((s64) ((s64) (t2 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto block_5;
    }
block_8:
    reg_d0.w = s0;
    reg_d1.w = saved;
    reg_d2.w = s2;
    reg_a0 = (u8 *)(D_00296084);
    return;
}

void boss_animation_running(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_00295F44;
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    cond_flag = 1;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    cond_flag = 0;
}

void boss_animation_stop(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_00295F44;
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    *(u16 *) reg_a0 = 0;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
}

extern s16 boss_attack_start_buffer[];

void boss_attack_start(void) {
    s32 d0 = reg_d0.w;
    s32 d1 = reg_d1.w;
    u32 tmp;

    reg_a0 = (u8 *) ((s16 *)D_002960B0);
    reg_d1.w = 9;
loop_1:
    if (*(s16 *) reg_a0 != 0) goto next_1;
    reg_d0.h[0] |= 0x8000;
    *(s16 *) reg_a0 = reg_d0.h[0];
    reg_d1.w = d1;
    reg_d0.w = d0;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *) boss_attack_start_buffer;
    reg_d1.w = d1;
    reg_d0.w = d0;
}

void boss_attack_running(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_002960B0;
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    cond_flag = 1;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    cond_flag = 0;
}

void boss_attack_stop(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_002960B0;
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    *(u16 *) reg_a0 = 0;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
}

void boss_attack_stop_all(void)
{
    s16 *savedAddressRegister;
    u32 savedDataRegister;

    savedDataRegister = reg_d0.w;
    savedAddressRegister = ((s16 *)reg_a0);
    (*(s16 **)&reg_a0) = ((s16 *)D_002960B0);
    reg_d0.w = 9;

    do {
        *(*(s16 **)&reg_a0) = 0;
        (*(s16 **)&reg_a0) += 0x10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    (*(s16 **)&reg_a0) = savedAddressRegister;
    reg_d0.w = savedDataRegister;
}

extern u16 D_002962D4[];
extern u16 D_002962D6[];
extern u16 D_002962D8[];
extern u16 D_002962DA[];
void boss_flash_start(void) {
    D_002962D6[0] = reg_d0.h[0];
    ((s16 *)D_002962D4)[0] = 1;
    ((s16 *)D_002962D8)[0] = 0x1C00;
    ((s16 *)D_002962DA)[0] = 1;
}

extern u16 D_002962D4[];

void boss_flash_running(void) {
    if (D_002962D4[0] == 0) {
        cond_flag = 0;
        return;
    }
    cond_flag = 1;
}

s32 sprite_draw_with_warning_keep();
extern u16 D_002962D8[];
extern u16 D_002962DA[];
extern u16 D_002962DC[];
void boss_flash_update(void) {
    if (D_002962D4[0] == 0) return;
    if (D_002962D4[0] != 2) goto next_1;
    D_002962DC[0] -= 1;
    if (D_002962DC[0] != 0) goto next_1;
    D_002962D4[0] = 0;
next_1:
    if (D_002962D4[0] != 1) goto next_2;
    D_002962DA[0] += 0x20;
    D_002962D8[0] -= 0x400;
    if ((s16) D_002962D8[0] >= 0) goto next_2;
    D_002962D8[0] = 0;
    D_002962DA[0] = 0xE0;
    D_002962D4[0] = 2;
    D_002962DC[0] = 1;
next_2:
    reg_d1.w = 0;
    reg_d1.h[0] = D_002962D8[0];
    reg_d3.h[0] = 0x3800;
    reg_d3.h[0] |= D_002962DA[0];
    reg_d2.w = 0x10AA;
    reg_d4.h[0] = D_002962D6[0];
    sprite_draw_with_warning_keep();
}

/* .bss (the compiler lays these out in reverse) */
u8 *D_00296210[52];
s16 boss_attack_start_buffer[16];
u16 D_002960B0[160];
u8 *D_00295F40[92];
u8 D_00295EA0[160];
#ifdef DEATH_LABEL
u8 D_00295E50[144];
#else
u8 D_00295E50[80];
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_00295E52, D_00295E50, 0x2);
PC_DATA_ALIAS(D_00295E54, D_00295E50, 0x4);
PC_DATA_ALIAS(D_00295E58, D_00295E50, 0x8);
PC_DATA_ALIAS(D_00295E5A, D_00295E50, 0xa);
PC_DATA_ALIAS(D_00295E5C, D_00295E50, 0xc);
PC_DATA_ALIAS(D_00295E7C, D_00295E50, MAIN_OR_DEATH_LABEL(0x2c, 0x4c));

#ifndef DEATH_LABEL
PC_DATA_ALIAS(D_00295E9C, D_00295E50, 0x4c);
#endif
#endif

#include "common.h"

s32 func_001F5BB0();
extern u16 D_0028E8A0;

void func_001F5C90(void) {
    void func_00203400(void);
#ifdef DEATH_LABEL
    if ((D_0028E8A0 == 0) && (*(u16 *)(reg_a5 + 0x1A) == 0)) {
#else
    if ((D_0028E8A0 == 0) && (*(u16 *)(reg_a5 + 0x1A) -= 1, *(u16 *)(reg_a5 + 0x1A) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            *(u16 *)(reg_a5 + 0x1A) = 0x78U;
            return;
        }
        *(s16 *)(reg_a6 + 0x10A) = 0;
        func_001F5BB0();
    }
}

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_movement_start();
s32 boss_part_show();
s32 boss_part_hide();
s32 boss_attack_stop_all();
s32 func_001A9000();
s32 func_001F5620();
s32 func_001F6080();
s32 func_001F6140();
s32 func_002016D0();
extern s32 D_0028E638;
extern u16 D_0028E89C;
extern u16 D_0028E8B8;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];
extern u16 D_0029CEA0[];

void func_001F5D00(void) {
    s32 func_00203400();
#ifdef DEATH_LABEL
    u16 hp;

#endif
    reg_d1.b[0] = reg_a6[0x181];
#ifdef DEATH_LABEL
    reg_d1.b[0] |= reg_a6[0x201];
#endif
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        goto next_2;
    }
next_1:
    reg_a6[0xEC] = 0x17;
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0x18);
    if (reg_tmp.w >= 0x1ECCC) {
        goto next_7;
    }
    if (D_0028E8B8 != 0) {
        goto next_7;
    }
    reg_d0.w = 0x19;
    reg_a6[0xEC] = reg_d0.b[0];
    goto next_7;
next_2:
    reg_d0.b[0] = 0xA3;
    reg_a6[0x181] &= reg_d0.b[0];
#ifdef DEATH_LABEL
    reg_a6[0x201] &= reg_d0.b[0];
#endif
    *(u16 *) (reg_a6 + 0x10A) = reg_d1.h[0];
    if (D_0028E89C != 0) {
        goto next_3;
    }
    if (D_0029CEA0[0] == 0) {
        goto next_4;
    }
    *(u16 *) (reg_a6 + 0x13A) = 40;
next_3:
    reg_d0.w = 0x12;
    boss_part_show();
    reg_d5.h[0] = 0x7FFF;
    *(u16 *) (reg_a6 + 0x198) = reg_d5.h[0];
#ifdef DEATH_LABEL
    *(u16 *) (reg_a6 + 0x218) = reg_d5.h[0];
#endif
    *(u16 *) (reg_a5 + 0x16) = *(u16 *) (reg_a5 + 0x1C);
    *(u16 *) (reg_a5 + 0x18) = *(u16 *) (reg_a5 + 0x1E);
    goto next_1;
next_4:
    if (*(u16 *) (reg_a6 + 0x13A) != 0) {
        goto next_3;
    }
    func_001A9000();
    reg_d0.b[0] = reg_a6[0xEC];
    if (reg_d0.b[0] != 0x19) {
        goto next_5;
    }
    reg_d0.b[0] = 0x17;
next_5:
    reg_d0.b[0] ^= 8;
    reg_a6[0xEC] = reg_d0.b[0];
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x198);
#ifdef DEATH_LABEL
    hp = *(u16 *) (reg_a6 + 0x218);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
#endif
    reg_d5.w = 0x7FFF;
    *(u16 *) (reg_a6 + 0x198) = reg_d5.h[0];
#ifdef DEATH_LABEL
    *(u16 *) (reg_a6 + 0x218) = reg_d5.h[0];
#endif
    reg_d5.h[0] -= reg_d4.h[0];
    if (*(u16 *) (reg_a6 + 0x108) != 0) {
        goto next_7;
    }
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0x18);
    reg_tmp.w -= reg_d5.w;
    *(u16 *) (reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0x18) = reg_tmp.h[0];
    if (0 <= (s64) (s32) reg_tmp.w) {
        goto next_7;
    }
    func_00203400();
    if (reg_d0.b[0] != 0) {
        goto next_6;
    }
    reg_tmp.w = 0x200;
    *(u16 *) (reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0x18) = reg_tmp.h[0];
    goto next_7;
next_6:
    D_0028E638 = 0x100000;
    func_001F6080();
    return;
next_7:
    *(u16 *) (reg_a5 + 0x1C) = *(u16 *) (reg_a5 + 0x16);
    *(u16 *) (reg_a5 + 0x1E) = *(u16 *) (reg_a5 + 0x18);
    reg_d0.h[0] = 0x500;
    if (*(u16 *) (reg_a6 + 0x13A) == 0) {
        goto next_8;
    }
    *(u16 *) (reg_a6 + 0x13A) -= 1;
    reg_d0.h[0] = 0x800;
next_8:
    *(u16 *) (reg_a6 + 0x194) = reg_d0.h[0];
    *(u16 *) (reg_a6 + 0x196) = reg_d0.h[0];
#ifdef DEATH_LABEL
    *(u16 *) (reg_a6 + 0x214) = reg_d0.h[0];
    *(u16 *) (reg_a6 + 0x216) = reg_d0.h[0];
#endif
    reg_d0.w = 0x12;
    if (D_0028E89C != 0) {
        goto next_9;
    }
    if (D_0029CEA0[0] != 0) {
        goto next_9;
    }
    if (*(u16 *) (reg_a6 + 0x13A) != 0) {
        goto next_9;
    }
    boss_part_hide();
    goto next_10;
next_9:
    boss_part_show();
next_10:
#ifdef DEATH_LABEL
    if (reg_a6[0x111] == 0) {
        reg_d0.h[1] = *(u16 *) (reg_a5 + 0x16);
        reg_d0.h[0] = *(u16 *) (reg_a5 + 0x18);
        reg_d0.w -= 0x23000;
        if (0 <= (s64) (s32) reg_d0.w) {
            goto next_11;
        }
        boss_attack_stop_all();
        boss_phase_stop_all();
        reg_d0.w = 0x10;
        boss_movement_start();
        reg_d0.w = 0x1A;
        boss_phase_start();
        func_001F5620();
        reg_a6[0x111] = 1;
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
        func_002016D0();
    }
    if (reg_a6[0x111] < 2) {
        reg_d0.h[1] = *(u16 *) (reg_a5 + 0x16);
        reg_d0.h[0] = *(u16 *) (reg_a5 + 0x18);
        reg_d0.w -= 0x174C0;
        if (0 <= (s64) (s32) reg_d0.w) {
            goto next_11;
        }
        boss_attack_stop_all();
        boss_phase_stop_all();
        reg_d0.w = 0x10;
        boss_movement_start();
        reg_d0.w = 0x19;
        boss_phase_start();
        func_001F5620();
        reg_a6[0x111] = 2;
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
        func_002016D0();
    }
#else
    if (reg_a6[0x111] != 0) {
        goto next_11;
    }
    reg_d0.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *) (reg_a5 + 0x18);
    reg_d0.w -= 0x23000;
    if (0 <= (s64) (s32) reg_d0.w) {
        goto next_11;
    }
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 0xB;
    boss_movement_start();
    reg_d0.w = 0x13;
    boss_phase_start();
    func_001F5620();
    reg_a6[0x111] = 1;
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    D_0029976C_as_s16_a[0] = 1;
    D_0029976E_as_s16_a[0] = 1;
    func_002016D0();
#endif
next_11:
    func_001F6140();
}

#include "common.h"
#include "entity.h"

void func_001F5520(void);
void func_001F5620(void);
void func_001F5750(void);
void func_001F57D0(void);
void func_001F57E0(void);
void func_001F5850(void);
void func_001F5BB0(void);

s32 boss_phase_stop_all();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 score_add();
s32 func_002016D0();
extern u8 D_0028E290;
extern u16 D_0028E2E8;
extern s32 g_boss_score;
extern u16 D_0028E8B8;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define TW(o) (*(u16 *)(reg_a5 + (o)))

void func_001F4EB0(void) {
    s32 boss_phase_start();
    s32 func_00203400();
    s32 top;
    s32 p1;
    s32 p2;
    s32 p3;
    s32 p4;
    s32 p5;
#ifdef DEATH_LABEL
    s32 p6;
    s32 p7;
#endif
    u16 hp;

    if (W(0x106) != 0) return;
    if (reg_a6[0x10F] != 0) {
        func_001F5850();
        return;
    }
    reg_d1.b[0] = reg_a6[1];
    reg_d1.b[0] |= reg_a6[0x21];
    reg_d1.b[0] |= reg_a6[0x41];
    reg_d1.b[0] |= reg_a6[0x61];
    reg_d1.b[0] |= reg_a6[0x81];
    reg_d1.b[0] |= reg_a6[0xA1];
    reg_d1.b[0] |= reg_a6[0xC1];
    reg_d1.b[0] |= reg_a6[0x1A1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_1;
    reg_a6[0xE7] = 0x10;
    reg_a6[0xE6] = 0x11;
    reg_a6[0xE9] = 0x12;
    reg_a6[0xE8] = 0x16;
    reg_tmp.h[1] = TW(0x16);
    reg_tmp.h[0] = TW(0x18);
    if (reg_tmp.w >= 0x15000) goto block_chk;
    if (D_0028E8B8 != 0) goto block_chk;
    reg_d0.w = 0x19;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_a6[0xE6] = reg_d0.b[0];
    reg_a6[0xE9] = reg_d0.b[0];
    reg_a6[0xE8] = reg_d0.b[0];
    goto block_chk;
next_1:
    reg_d0.b[0] = 0xA3;
    reg_a6[1] &= reg_d0.b[0];
    reg_a6[0x21] &= reg_d0.b[0];
    reg_a6[0x41] &= reg_d0.b[0];
    reg_a6[0x61] &= reg_d0.b[0];
    reg_a6[0x81] &= reg_d0.b[0];
    reg_a6[0xA1] &= reg_d0.b[0];
    reg_a6[0xC1] &= reg_d0.b[0];
    reg_a6[0x1A1] &= reg_d0.b[0];
    W(0x10A) = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = reg_a6[0xE7];
    reg_d2.b[0] = reg_a6[0xE6];
    reg_d3.b[0] = reg_a6[0xE9];
    reg_d4.b[0] = reg_a6[0xE8];
    if (reg_d0.b[0] != 0x19) goto next_2;
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
    reg_d4.b[0] = 0x16;
next_2:
    reg_d0.b[0] ^= 0xF;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    reg_a6[0xE6] = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    reg_a6[0xE9] = reg_d3.b[0];
    reg_d4.b[0] ^= 9;
    reg_a6[0xE8] = reg_d4.b[0];
    if (D_0028E290 == 2) {
#ifdef DEATH_LABEL
        top = W(0x18);
        p1 = W(0x38);
        p2 = W(0x58);
        p3 = W(0x78);
        p4 = W(0x98);
        p5 = W(0xB8);
        p6 = W(0xD8);
        p7 = W(0x1B8);
        if (top > p1) goto skip_1;
        top = p1;
skip_1:
        if (p2 > p3) goto skip_2;
        p2 = p3;
skip_2:
        if (p4 > p5) goto skip_3;
        p4 = p5;
skip_3:
        if (p6 > p7) goto skip_4;
        p6 = p7;
skip_4:
        if (top > p2) goto skip_5;
        top = p2;
skip_5:
        if (p4 > p6) goto skip_6;
        p4 = p6;
skip_6:
        if (top > p4) goto skip_7;
        top = p4;
skip_7:;
#else
        top = W(0x18);
        p1 = W(0x38);
        p2 = W(0x58);
        p3 = W(0x78);
        p4 = W(0xD8);
        p5 = W(0x1B8);
        if (top > p1) goto skip_1;
        top = p1;
skip_1:
        if (p2 > p3) goto skip_2;
        p2 = p3;
skip_2:
        if (p4 > p5) goto skip_3;
        p4 = p5;
skip_3:
        if (top > p2) goto skip_4;
        top = p2;
skip_4:
        if (top > p4) goto skip_5;
        top = p4;
skip_5:;
#endif
    }
    reg_d4.h[0] = W(0x18);
    hp = W(0x38);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x58);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x78);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x98);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0xB8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0xD8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x1B8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    reg_d5.w = 0x7FFF;
    W(0x18) = reg_d5.h[0];
    W(0x38) = reg_d5.h[0];
    W(0x58) = reg_d5.h[0];
    W(0x78) = reg_d5.h[0];
    W(0x98) = reg_d5.h[0];
    W(0xB8) = reg_d5.h[0];
    W(0xD8) = reg_d5.h[0];
    W(0x1B8) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (W(0x108) != 0) goto block_chk;
    reg_tmp.h[1] = TW(0x16);
    reg_tmp.h[0] = TW(0x18);
    if (D_0028E290 == 2) {
        if (top > 0x7FFF) {
            reg_tmp.w += top - 0x7FFF;
            if (reg_tmp.w >= 0x3F000) reg_tmp.w = 0x3F000;
        } else {
            reg_tmp.w -= reg_d5.w;
        }
    } else {
        reg_tmp.w -= reg_d5.w;
    }
    TW(0x16) = reg_tmp.h[1];
    TW(0x18) = reg_tmp.h[0];
    if (0 > (s32) reg_tmp.w) goto next_9;
    goto block_chk;
next_9:
    func_00203400();
    if (reg_d0.h[0] != 0) goto next_6;
    reg_tmp.w = 0x200;
    TW(0x16) = reg_tmp.h[1];
    TW(0x18) = reg_tmp.h[0];
    goto block_chk;
next_6:
    if (D_0028E2E8 != 0) goto next_7;
    g_boss_score = 0x70000;
    func_001F5520();
    return;
next_7:
    reg_d1.h[0] = W(0x10A);
    reg_d0.w = 0x70000;
    score_add();
    func_001F5520();
    return;
block_chk:
    if (reg_a6[0x10D] != 0) goto next_8;
    if (D_0028E2E8 != 0) goto next_8;
    reg_d0.h[1] = TW(0x16);
    reg_d0.h[0] = TW(0x18);
    reg_d0.w += 0xFFFD6000;
    if (0 > (s32) reg_d0.w) goto next_10;
    goto next_8;
next_10:
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 0xE;
    boss_phase_start();
    func_001F5620();
    reg_a6[0x10D] = 1;
    func_002016D0();
next_8:
    func_001F57E0();
}

s32 boss_phase_stop_all();                            /* extern */
s32 boss_animation_stop();                            /* extern */
s32 boss_attack_stop_all();                            /* extern */
s32 func_0013F3C0();                            /* extern */
s32 func_0018DEE0();                            /* extern */
s32 func_002016D0();                            /* extern */
s32 func_00203460();                            /* extern */
s32 func_0020ED10();                            /* extern */
extern u8 D_0028E855;

void func_001F5520(void) {
    s32 boss_phase_start(s32, s32, s32, s32);
    func_0018DEE0();
    func_0020ED10();
    if (D_0028E2E8 == 0) {
        D_0028E855 |= 0x40;
        D_0028E855 |= 0x80;
        func_00203460();
        *(s8 *)(reg_a6 + 0x1E) = 1;
    } else {
        *(s16 *)(reg_a5 + 0x1A) = 0x6270;
    }
    func_0013F3C0();
    func_002016D0();
    boss_attack_stop_all();
    boss_phase_stop_all();
    func_001F57D0();
    func_001F5750();
    reg_d0.w = 2;
    boss_animation_stop();
    reg_tmp.w = -1U;
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xE7) = 0x10;
    *(s8 *)(reg_a6 + 0xE6) = 0x11;
    *(s8 *)(reg_a6 + 0xE9) = 0x12;
    *(s8 *)(reg_a6 + 0xE8) = 0x16;
    reg_d0.w = 1;
    boss_phase_start(0x16, 0x12, 0x11, 0x10);
}

void func_001F5620(void) {
    *(s16 *)(reg_a6 + 0x108) = 1;
}

void func_001F5630(void) {
    *(s16 *)(reg_a6 + 0x108) = 0;
}

void func_001F5640(void) {
    reg_d0.h[0] = 0xA001;
    ENTITY(reg_a6)->flags.h |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x20) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x40) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x60) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x80) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xA0) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xC0) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x1A0) |= reg_d0.h[0];
}

void func_001F56F0(void) {
    reg_d0.h[0] = 0xA001;
    *(u16 *)(reg_a6 + 0x140) |= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x160) |= reg_d0.h[0];
}

extern void *reg_a6_as_void_p;

void func_001F5730(void) {
    u16 *flags;
    u32 combined;

    reg_d0.h[0] = 0xA001;
    flags = (u16 *)reg_a6_as_void_p;
    combined = (u32)flags[0xC0] | (u32)reg_d0.h[0];
    flags[0xC0] = (u16)combined;
#ifdef DEATH_LABEL
    flags = (u16 *)reg_a6_as_void_p;
    combined = (u32)flags[0x100] | (u32)reg_d0.h[0];
    flags[0x100] = (u16)combined;
#endif
}

void func_001F5750(void) {
    reg_d0.h[0] = 0x8000;
    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x40) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x60) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x80) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xA0) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xC0) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x1A0) = (u16) reg_d0.h[0];
}


void func_001F57C0(void) {
    *(s16*)(reg_a6 + 0x106) = 0;
}

void func_001F57D0(void) {
    *(s16 *)(reg_a6 + 0x106) = 1;
}

extern u16 g_enemies_stopped;

void func_001F57E0(void) {
    void func_00203400(void);
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) == 0)) {
#else
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) -= 1, *(u16 *)(reg_a5 + 0x1A) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            *(u16 *)(reg_a5 + 0x1A) = 0x78U;
            return;
        }
        *(s16 *)(reg_a6 + 0x10A) = 0;
        func_001F5520();
    }
}

s32 func_001F5C90();
s32 func_001F5D00();

void func_001F5850(void) {
    s32 func_00203400();
    u32 big;
    u16 t;

    if (reg_a6[0x10F] != 1) {
        func_001F5D00();
        return;
    }
    reg_d1.b[0] = reg_a6[0x141];
    reg_d1.b[0] |= reg_a6[0x161];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        goto next_1;
    }
    reg_a6[0xE7] = 0x10;
    reg_a6[0xE6] = 0x11;
    reg_a6[0xE9] = 0x12;
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0x18);
    if (reg_tmp.w >= 0xE000) {
        goto next_9;
    }
    if (D_0028E8B8 != 0) {
        goto next_9;
    }
    reg_d0.w = 0x19;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_a6[0xE6] = reg_d0.b[0];
    reg_a6[0xE9] = reg_d0.b[0];
    goto next_9;
next_1:
    reg_d0.b[0] = 0xA3;
    reg_a6[0x141] &= reg_d0.b[0];
    reg_a6[0x161] &= reg_d0.b[0];
    *(u16 *) (reg_a6 + 0x10A) = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = reg_a6[0xE7];
    reg_d2.b[0] = reg_a6[0xE6];
    reg_d3.b[0] = reg_a6[0xE9];
    if (reg_d0.b[0] != 0x19) {
        goto next_2;
    }
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
next_2:
    reg_d0.b[0] ^= 0xF;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    reg_a6[0xE6] = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    reg_a6[0xE9] = reg_d3.b[0];
    if (D_0028E290 != 2) {
        goto next_3;
    }
    big = *(u16 *) (reg_a6 + 0x158);
    t = *(u16 *) (reg_a6 + 0x178);
    if ((s32) big <= (s32) t) {
        big = t;
    }
next_3:
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x158);
    t = *(u16 *) (reg_a6 + 0x178);
    if (!((s16) t < (s16) reg_d4.h[0])) {
        goto next_4;
    }
    reg_d4.h[0] = t;
next_4:
    reg_d5.w = 0x7FFF;
    *(u16 *) (reg_a6 + 0x158) = reg_d5.h[0];
    *(u16 *) (reg_a6 + 0x178) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (*(u16 *) (reg_a6 + 0x108) != 0) {
        goto next_9;
    }
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0x18);
    if (D_0028E290 != 2) {
        goto next_6;
    }
    if ((s32) big <= 0x7FFF) {
        goto next_5;
    }
    reg_tmp.w += big - 0x7FFF;
    if (reg_tmp.w < 0x2A000) {
        goto next_7;
    }
    reg_tmp.w = 0x2A000;
    goto next_7;
next_5:
    reg_tmp.w -= reg_d5.w;
    goto next_7;
next_6:
    reg_tmp.w -= reg_d5.w;
next_7:
    *(u16 *) (reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0x18) = reg_tmp.h[0];
    if (0 <= (s64) (s32) reg_tmp.w) {
        goto next_9;
    }
    func_00203400();
    if (reg_d0.h[0] != 0) {
        goto next_8;
    }
    reg_tmp.w = 0x200;
    *(u16 *) (reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0x18) = reg_tmp.h[0];
    goto next_9;
next_8:
    reg_d1.h[0] = *(u16 *) (reg_a6 + 0x10A);
    reg_d0.w = 0x80000;
    score_add();
    func_001F5BB0();
    return;
next_9:
    func_001F5C90();
}

s32 boss_part_hide();
s32 func_0013F3C0();
s32 func_0018DEE0();
s32 func_0020ED10();

void func_001F5BB0(void) {
    s32 boss_phase_start();
    func_0018DEE0();
    func_0020ED10();
    *(u16 *)(reg_a5 + 0x1A) = 0x6270;
    func_0013F3C0();
    func_002016D0();
    func_001F57D0();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x15F) = 1;
    *(u16 *)(reg_a6 + 0x140) = 0x8000;
    *(u16 *)(reg_a6 + 0x160) = 0x8000;
    *(s8 *)(reg_a6 + 0xE7) = 0x10;
    *(s8 *)(reg_a6 + 0xE6) = 0x11;
    *(s8 *)(reg_a6 + 0xE9) = 0x12;
    reg_d0.w = 0xE;
    boss_part_hide(0x12, 0x11, 0x10, 0x8000);
    reg_d0.w = 0xA;
    boss_part_hide();
    reg_d0.w = 3;
    boss_phase_start();
}

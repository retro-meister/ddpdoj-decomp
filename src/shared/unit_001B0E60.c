#include "common.h"
#include "entity.h"

s32 func_0013AFF0();
s32 sprite_palette_load();
s32 velocity_from_dir256();
extern u8 D_0028DF0C;
extern u8 D_0028DF10;
extern u16 D_0029BD80[];
extern u16 D_0029BDC0[];
extern u8 D_0029BE00[];

void func_001B0E60(void) {
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u32 t;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    s_a0 = reg_a0;
    s_a1 = reg_a1;
    s_a2 = reg_a2;
    s_a3 = reg_a3;
    s_a4 = reg_a4;
    s_a5 = reg_a5;
    s_a6 = reg_a6;
    if (D_0028DF0C != 0) goto block_exit;
    reg_a6 = (u8 *)D_0029BE00;
    if (ENTITY(reg_a6)->flags.sb[0] >= 6) goto block_set;
    if (*(s8 *)(reg_a6 + 0x70) < 6) goto next_1;
block_set:
    D_0028DF0C = 1;
    goto block_exit;
next_1:
    reg_a0 = (u8 *)D_0029BDC0;
    reg_d1.w = 0;
    reg_a1 = (u8 *)D_0029BD80;
    reg_d0.h[0] = 0x50;
    D_0028DF10 += 6;
    reg_d1.b[0] = D_0028DF10;
    velocity_from_dir256();
    reg_d6.h[0] = 0x800;
    reg_d6.h[0] -= reg_d2.h[0];
    reg_d7.w = 0x1F;
    reg_d6.h[0] >>= 6;
loop_2:
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = reg_d6.h[0];
    func_0013AFF0();
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a0 = (u8 *)D_0029BD80;
    reg_d0.h[0] = 0xB;
    sprite_palette_load();
block_exit:
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
    reg_a0 = s_a0;
    reg_a1 = s_a1;
    reg_a2 = s_a2;
    reg_a3 = s_a3;
    reg_a4 = s_a4;
    reg_a5 = s_a5;
    reg_a6 = s_a6;
}

s32 text_layer_clear();
s32 func_00137C50();
s32 func_0018D150();
s32 func_0018DD20();
s32 text_palette_load();
s32 func_001B04B0();
s32 task_start();
s32 func_0020ECE0();
s32 replay_header_clear();
extern u8 D_0025F770[];
extern u8 D_00260930[];
extern u8 D_00260970[];
extern u8 D_002609B0[];
extern u8 D_002609F0[];
extern u8 D_00260A30[];
extern u8 D_00260CB0[];
extern u8 D_00260CF0[];
extern u8 D_00260D30[];
extern u8 D_00260D70[];
extern u8 D_00260DB0[];
extern u8 D_00260DF0[];
extern u8 D_00260E30[];
extern u8 D_00260E70[];
extern u8 D_00269140[];
extern s16 D_0028DF14;
extern s16 D_0028DF18;
extern s16 D_0028E3C0_as_s16;
extern u8 D_0028ED74;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;

void func_001B1080(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    func_001B04B0();
    func_00137C50();
    D_0028E3C0_as_s16 = 0;
    D_0028ED80 = 0;
    replay_header_clear();
    D_0028ED7C = 1;
    D_0028ED74 = 2;
    func_0020ECE0();
    D_0028DF14 = 0;
    D_0028DF0C = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.h[0] = 0x6F;
    do {
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 1;
    do {
        *(s8 *)(reg_a0 + 1) = 0;
        *(u8 *)reg_a0 = 0;
        reg_tmp.w = -1U;
        *(u16 *)(reg_a0 + 0x56) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 0x58) = (u16) reg_tmp.h[0];
        *(s16 *)(reg_a0 + 0x60) = 0;
        *(s16 *)(reg_a0 + 0x62) = 0;
        *(s16 *)(reg_a0 + 0x64) = 1;
        *(s16 *)(reg_a0 + 0x66) = 0;
        *(s16 *)(reg_a0 + 0x68) = 0;
        *(s16 *)(reg_a0 + 0x6A) = 2;
        *(s16 *)(reg_a0 + 0x6C) = 0x140;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    D_0028DF18 = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 5);
    if (reg_d0.b[0] == 3) {
        *(s8 *)(reg_a0 + 1) = 1;
        *(s8 *)(reg_a0 + 0x71) = 1;
    }
    if (reg_d0.b[0] == 2) {
        *(s8 *)(reg_a0 + 0x71) = 1;
    }
    if (reg_d0.b[0] == 1) {
        *(s8 *)(reg_a0 + 1) = 1;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    *(u8 *)(reg_a5 + 5) = 0xFFU;
    *(u8 *)(reg_a5 + 4) = 0xFFU;
    *(u8 *)(reg_a5 + 7) = 0xFFU;
    *(u8 *)(reg_a5 + 6) = 0xFFU;
    *(u8 *)(reg_a5 + 9) = 0xFFU;
    *(u8 *)(reg_a5 + 8) = 0xFFU;
    *(s16 *)(reg_a5 + 0xA) = 0;
    text_layer_clear();
    reg_a0 = (u8 *)D_00269140;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)D_0025F770;
    reg_d0.w = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260930;
    reg_d0.w = 0x18;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260970;
    reg_d0.w = 0x19;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609B0;
    reg_d0.w = 0x1B;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CB0;
    reg_d0.w = 0x12;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D70;
    reg_d0.w = 0x13;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E70;
    reg_d0.w = 0x14;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DB0;
    reg_d0.w = 0x10;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CF0;
    reg_d0.w = 0x15;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E30;
    reg_d0.w = 0x16;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DF0;
    reg_d0.w = 0x17;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D30;
    reg_d0.w = 0x11;
    sprite_palette_load();
    reg_d0.h[0] = 0xA;
    task_start();
    *(s16 *)(reg_a0 + 4) = 0;
    func_0018D150();
    func_0018DD20();
    reg_a0 = (u8 *)D_00260CB0;
    reg_a1 = (u8 *)(D_0029BDC0);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
}

extern u8 D_0028E304;
extern u16 g_loop;

void func_001B1920(void) {
    s32 func_002075F0();
    func_002075F0();
    if ((D_0028E304 != 0) && (g_loop == 0)) {
        g_loop = 1;
    }
}


s32 func_00130270();
s32 func_001303A0();
s32 func_001384E0();
s32 func_00138650();
s32 func_00138750();
s32 func_001460A0();
s32 func_00146350();
s32 func_00146470();
s32 func_0016A8B0();
s32 func_0016A8C0();
s32 func_00204800();
s32 func_0020ED40();
s32 func_0020EE20();
#ifdef DEATH_LABEL
s32 text_layer_clear();
s32 func_0018DD40();
s32 func_0018DEE0();
s32 text_palette_load();
s32 death_func_001B1220();
s32 task_start();
s32 func_002075F0();
s32 fade_reset();
extern u8 D_00269140[];
extern u8 D_0028E290;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#endif

void func_001B1960(void) {
    u8 t1;

    t1 = *(u8 *)(reg_a5 + 3);
    if (t1 == 0) {
        func_001B1080();
        return;
    }
    if (t1 == 2) {
        func_001B1920();
        return;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    reg_a6 = (u8 *)D_0029BE00;
    reg_d7.w = 1;
    do {
        if (ENTITY(reg_a6)->flags.b[1] != 0) {
            if (ENTITY(reg_a6)->flags.b[0] == 3) {
                func_001384E0();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 4) {
                func_00138750();
            }
#ifdef DEATH_LABEL
            if (ENTITY(reg_a6)->flags.b[0] == 5) {
                func_00138650();
                fade_reset();
                death_func_001B1220();
                D_0028E290 = 2;
                text_layer_clear();
                reg_d0.w = 0;
                reg_a0 = (u8 *)D_00269140;
                text_palette_load();
                D_00684C80[0] = 0xFF;
                D_00684C80[1] = 0xFF;
                D_00684C80[2] = 0xFF;
                D_00684C80[3] = 0xFF;
                D_00684C80[9] = 0xFF;
                if (D_0028E7B4 & 1) {
                    D_00684C80[0] = *(u8 *)(reg_a5 + 9);
                    D_00684C80[1] = *(u8 *)(reg_a5 + 5);
                    D_00684C80[9] = D_00684C80[1];
                } else {
                    D_00684C80[2] = *(u8 *)(reg_a5 + 8);
                    D_00684C80[3] = *(u8 *)(reg_a5 + 4);
                    D_00684C80[9] = D_00684C80[3];
                }
                func_002075F0();
                func_0018DD40();
                func_0018DEE0();
                reg_d0.h[0] = 0x15;
                task_start();
                return;
            }
#else
            if (ENTITY(reg_a6)->flags.b[0] == 5) {
                func_00138650();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 6) {
                func_0020ED40();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 7) {
                func_0020EE20();
            }
#endif
            if (ENTITY(reg_a6)->flags.b[0] == 0) {
                func_001460A0();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 1) {
                func_00146470();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 2) {
                func_00146350();
            }
            if ((s32) ENTITY(reg_a6)->flags.b[0] < 7) {
                *(u8 *)(reg_a6 + 0x30) -= 1;
                if (*(u8 *)(reg_a6 + 0x30) == 0) {
                    *(u8 *)(reg_a6 + 0x30) = 2U;
                    if (*(u16 *)(reg_a6 + 0x2E) == 0) {
                        *(s8 *)(reg_a6 + 0x31) = 1;
                    } else {
                        reg_d0.w = 1;
                        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x2E);
                        if (reg_d1.b[0] == 0) {
                            reg_d1.b[0] = 0x99;
                        } else if (reg_d1.b[0] & 0xF) {
                            reg_d1.b[0] = reg_d1.b[0] - 1;
                        } else {
                            reg_d1.b[0] = (reg_d1.b[0] - 0x10) & 0xF0;
                            reg_d1.b[0] |= 9;
                        }
                        if (reg_d1.b[0] == 0x99) {
                            *(u8 *)(reg_a6 + 0x2F) -= 1;
                        }
                        *(u8 *)(reg_a6 + 0x2E) = (u8) reg_d1.b[0];
                    }
                }
            }
        } else if ((reg_d7.h[0] != 0) && (D_0028E304 == 0)) {
            func_0016A8B0();
            if ((reg_d0.w & 0x8000) && ((reg_a0 = (u8 *)D_0029BE00, (*(u8 *)(reg_a0 + 0x71) == 0)) || ((s32) *(u8 *)(reg_a0 + 0x70) < 6))) {
                func_00130270();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->flags.sb[1] = 1;
                }
            }
        } else if (D_0028E304 == 0) {
            func_0016A8C0();
            if ((reg_d0.w & 0x8000) && ((reg_a0 = (u8 *)D_0029BE00, (*(u8 *)(reg_a0 + 1) == 0)) || ((s32) *(u8 *)reg_a0 < 6))) {
                func_001303A0();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->flags.sb[1] = 1;
                }
            }
        }
        func_00204800();
        reg_a6 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = 3;
    reg_a6 = (u8 *)D_0029BE00;
    if (ENTITY(reg_a6)->flags.b[1] != 0) {
        reg_d0.h[0] &= 0xFFFE;
        if (ENTITY(reg_a6)->flags.b[0] == 8) {
            reg_d0.h[0] |= 1;
        }
    }
    if (*(u8 *)(reg_a6 + 0x71) != 0) {
        reg_d0.h[0] &= 0xFFFD;
        if (*(u8 *)(reg_a6 + 0x70) == 8) {
            reg_d0.h[0] |= 2;
        }
    }
    if (reg_d0.h[0] == 3) {
        *(u8 *)(reg_a5 + 3) = 2U;
    }
    func_001B0E60();
}

s32 func_001A33C0();
s32 func_001A35A0();
s32 func_0023C1E0();
extern s16 D_0028E3B4_as_s16;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern s16 g_player2[];
extern u16 D_0029F248[];
extern u16 D_0029F24A[];
extern s16 g_player1[];
extern u16 D_0029F2B8[];
extern u16 D_0029F2BA[];
extern u8 D_006CB1D4[];

void func_001B1D70(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    func_001B04B0();
    D_0028DF14 = 0;
    D_0028E3B4_as_s16 = 1;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.h[0] = 0x6F;
    do {
        *(s16 *)reg_a0 = 0;
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 1;
    do {
        *(s8 *)(reg_a0 + 1) = 0;
        *(u8 *)reg_a0 = 0;
        reg_tmp.w = -1U;
        *(u16 *)(reg_a0 + 0x56) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 0x58) = (u16) reg_tmp.h[0];
        *(s16 *)(reg_a0 + 0x60) = 0;
        *(s16 *)(reg_a0 + 0x62) = 0;
        *(s16 *)(reg_a0 + 0x64) = 1;
        *(s16 *)(reg_a0 + 0x66) = 0;
        *(s16 *)(reg_a0 + 0x68) = 0;
        *(s16 *)(reg_a0 + 0x6A) = 2;
        *(s16 *)(reg_a0 + 0x6C) = 0x140;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    D_0028DF18 = 0;
    *(s8 *)(reg_a5 + 2) = 0;
    *(u8 *)(reg_a5 + 5) = 0xFFU;
    *(u8 *)(reg_a5 + 4) = 0xFFU;
    *(u8 *)(reg_a5 + 7) = 0xFFU;
    *(u8 *)(reg_a5 + 6) = 0xFFU;
    *(u8 *)(reg_a5 + 9) = 0xFFU;
    *(u8 *)(reg_a5 + 8) = 0xFFU;
    *(s16 *)(reg_a5 + 0xA) = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 0;
    if (0 > g_player1[0]) {
        reg_d0.h[0] = 1;
    } else if (0 > g_player2[0]) {
        reg_d0.h[0] = 2;
    }
    reg_a6 = (u8 *)D_0029BE00;
    if (reg_d0.b[0] == 2) {
        *(s8 *)(reg_a0 + 0x71) = 1;
        reg_d1.h[0] = D_0029F248[0];
        *(u8 *)(reg_a5 + 8) = (u8) reg_d1.b[0];
        reg_d1.h[0] = D_0029F24A[0];
        *(u8 *)(reg_a5 + 4) = (u8) reg_d1.b[0];
        *(u8 *)(reg_a5 + 6) = (u8) reg_d1.b[0];
        *(s8 *)(reg_a6 + 0x70) = 3;
        reg_d1.w = 0;
        if (D_0028E934 != 0) {
            reg_d1.w = 1;
        }
        *(u16 *)(reg_a6 + 0x72) = (u16) reg_d1.h[0];
        reg_d0.w = 1;
        func_001A33C0();
        reg_d0.w = 1;
        func_001A35A0();
    } else if (reg_d0.b[0] == 1) {
        *(s8 *)(reg_a0 + 1) = 1;
        reg_d1.h[0] = D_0029F2B8[0];
        *(u8 *)(reg_a5 + 9) = (u8) reg_d1.b[0];
        reg_d1.h[0] = D_0029F2BA[0];
        *(u8 *)(reg_a5 + 5) = (u8) reg_d1.b[0];
        *(u8 *)(reg_a5 + 7) = (u8) reg_d1.b[0];
        ENTITY(reg_a6)->flags.sb[0] = 3;
        reg_d1.w = 0;
        if (D_0028E938 != 0) {
            reg_d1.w = 1;
        }
        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
        reg_d0.w = 0;
        func_001A33C0();
        reg_d0.w = 0;
        func_001A35A0();
    }
    text_layer_clear();
    reg_a0 = (u8 *)D_00269140;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)D_0025F770;
    reg_d0.w = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260930;
    reg_d0.w = 0x18;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260970;
    reg_d0.w = 0x19;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609B0;
    reg_d0.w = 0x1B;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CB0;
    reg_d0.w = 0x12;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D70;
    reg_d0.w = 0x13;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E70;
    reg_d0.w = 0x14;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DB0;
    reg_d0.w = 0x10;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CF0;
    reg_d0.w = 0x15;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E30;
    reg_d0.w = 0x16;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DF0;
    reg_d0.w = 0x17;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D30;
    reg_d0.w = 0x11;
    sprite_palette_load();
    if (D_0028ED7C == 1) {
        func_0023C1E0(D_006CB1D4);
    }
    reg_d0.h[0] = 0xA;
    task_start();
    *(s16 *)(reg_a0 + 4) = 0;
}

void func_001B21F0(void) {
    void func_002075F0(void);
    D_0028E3B4_as_s16 = 0;
    func_002075F0();
}


void func_001B2200(void) {
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    if (temp_a0 == 0) {
        func_001B1D70();
        return;
    }
    if (temp_a0 == 2) {
        func_001B21F0();
        return;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    reg_a6 = D_0029BE00;
    reg_d7.w = 1;
    do {
        if (ENTITY(reg_a6)->flags.b[1] != 0) {
            temp_a0_2 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_2 == 3) {
                func_001384E0();
                ENTITY(reg_a6)->flags.b[0] = 5U;
            }
            temp_a0_3 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_3 == 5) {
                func_00138650();
            }
            temp_a0_4 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_4 == 6) {
                func_0020ED40();
            }
            temp_a0_5 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_5 == 7) {
                func_0020EE20();
            }
        }
        reg_a6 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = 3;
    reg_a6 = D_0029BE00;
    if (ENTITY(reg_a6)->flags.b[1] != 0) {
        reg_d0.h[0] &= 0xFFFE;
        if (ENTITY(reg_a6)->flags.b[0] == 8) {
            reg_d0.h[0] |= 1;
        }
    }
    if (*(u8 *)(reg_a6 + 0x71) != 0) {
        reg_d0.h[0] &= 0xFFFD;
        if (*(u8 *)(reg_a6 + 0x70) == 8) {
            reg_d0.h[0] |= 2;
        }
    }
    if (reg_d0.h[0] == 3) {
        *(u8 *)(reg_a5 + 3) = 2U;
    }
}

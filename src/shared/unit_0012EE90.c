#include "common.h"
#include "entity.h"

s32 func_0012E3D0();
extern u16 g_game_frame;

void bullet_move_type_27(void) {
    func_0012E3D0();
    reg_tmp.w = 0x19D;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] &= 3;
    do {
        reg_tmp.w = 1;
        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
        reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_tmp.w);
        ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
        ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_tmp.w = 0x1B;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x30) = 0x20;
}

void bullet_move_type_28(void) {
    *(s16 *)(reg_a6 + 0x28) = 0x1410;
    reg_tmp.w = 0x1C;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}

void bullet_move_type_29(void) {
    *(s16 *)(reg_a6 + 0x2C) = 1;
    reg_tmp.w = 0x1D;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}

s32 func_0012DA30();
s32 func_0012E350();

void bullet_move_type_30() {
    func_0012E350();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x1E;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] -= *(u8 *)(reg_a6 + 0x36);
    func_0012DA30();
    reg_d2.w = (u32) ((s32) reg_d2.w >> 3);
    reg_d3.w = (u32) ((s32) reg_d3.w >> 3);
    *(u16 *)(reg_a6 + 0x30) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x32) = (u16) reg_d3.h[0];
}

void bullet_move_type_31() {
    func_0012E350();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x1F;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] -= *(u8 *)(reg_a6 + 0x36);
    func_0012DA30();
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 3);
    reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 3);
    *(u16 *)(reg_a6 + 0x30) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x32) = (u16) reg_d3.h[0];
}

s32 func_0012E350();                            /* extern */

void bullet_move_type_32(void) {
    func_0012E350();
    reg_tmp.w = 0x1E6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x20;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_33(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x1B4;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    *(s16 *)(reg_a6 + 0x2C) = 0x14;
    *(s16 *)(reg_a6 + 0x2E) = 0x101;
    reg_tmp.w = 0x21;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_34(void) {
    *(s16 *)(reg_a6 + 0x2C) = 1;
    reg_tmp.w = 0x22;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}

s32 func_0012E3D0();                            /* extern */

void bullet_move_type_35(void) {
    func_0012E3D0();
    reg_tmp.w = 0x23;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0x1A6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x28) = 0x404;
    ENTITY(reg_a6)->move.sb.speed = 0;
}

extern u16 D_0024EC80[];

void func_0012F4C0(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_a1 = (u8 *)(D_0024EC80);
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_x_minus.h -= 4;
}

#ifdef DEATH_LABEL
void death_func_0012E5B0(void) {
    *(u16 *)(reg_a6 + 0x28) = 0x1410;
    reg_tmp.w = 0x24;
    *(u16 *)(reg_a6 + 0x22) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = reg_tmp.h[0];
    ENTITY(reg_a6)->look.h = 0;
    ENTITY(reg_a6)->attr.b.palette = 0x1A;
}
#endif

s32 func_0013B350();
s32 func_0015B930();
extern u8 D_00269800[];
extern u32 D_0028E964;
extern s16 D_0028E968_as_s16;
extern s16 D_0028E96C_as_s16;

void func_0012F6A0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    D_0028E968_as_s16 = 0xF0;
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_00269800;
    save_d1 = reg_d1.w;
    D_0028E964 = 0;
    D_0028E96C_as_s16 = 0;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    func_0013B350();
    D_0028E964 = reg_d0.w;
    func_0015B930();
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

void func_0012F9F0(void);
void func_0013BE50(void);
void func_0013C300(void);
void func_0013C350(void);
void voice_logo(void);
extern u8 D_00269820[];
extern u16 D_0028E968;
extern u16 D_0028E96C;

void func_0012F7D0(void) {
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    if (D_0028E96C == 0) {
        reg_d0.w = D_0028E964;
        func_0013C350();
        if (cond_flag == 0) {
            func_0013C300();
            D_0028E96C = 1;
            voice_logo();
        }
    }
    if (D_0028E96C == 1) {
        D_0028E968 -= 1;
        if (D_0028E968 == 0) {
            reg_a0 = (u8 *)D_00269820;
            func_0013BE50();
            D_0028E964 = reg_d0.w;
            D_0028E96C = 2;
        }
    }
    if (D_0028E96C == 2) {
        reg_d0.w = D_0028E964;
        func_0013C350();
        if (cond_flag == 0) {
            func_0013C300();
            goto block_1;
        }
    }
    func_0012F9F0();
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    cond_flag = 1;
    return;
block_1:
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    cond_flag = 0;
}

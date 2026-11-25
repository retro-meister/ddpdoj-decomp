#include "common.h"
#include "entity.h"

void func_001A40A0(void);
void func_001A4320(void);
void func_001A4400(void);
void func_001A4410(void);
void func_001A44C0(void);
void func_001A4660(void);
void func_001A4740(void);
void func_001A47D0(void);
void func_001A4990(void);
void func_001A4A20(void);
void func_001A4B60(void);
void func_001A4CB0(void);
void func_001A4EA0(void);

extern s16 D_0028E774;

void func_001A3D20(void) {
    D_0028E774 = 0xF0;
}

s32 func_0013B350();
extern u8 D_0026B580[];
extern u16 D_0028E76C;
extern u32 D_0028E770;
extern s16 D_0028E778_as_s16;

void func_001A3D30(void) {
    s32 music_stop();
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
    music_stop();
    D_0028E770 = (u16)(D_0028E76C = 0);
    D_0028E778_as_s16 = 0;
    D_0028E774 = 0xF0;
    reg_a0 = (u8 *)D_0026B580;
    func_0013B350();
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
    D_0028E770 = reg_d0.w;
    reg_d0.w = save_d0;
}


s32 func_0013BE50();
s32 func_0013C300();
s32 func_0013C350();
extern u8 D_0026B5F0[];
extern u8 D_0028E294;
extern u8 *reg_save2_a6;
extern u8 *reg_save2_a5;
extern u8 *reg_save2_a4;
extern u8 *reg_save2_a3;
extern u8 *reg_save2_a2;
extern u8 *reg_save2_a1;
extern u8 *reg_save2_a0;
extern u32 reg_save2_d7;
extern u32 reg_save2_d6;
extern u32 reg_save2_d5;
extern u32 reg_save2_d4;
extern u32 reg_save2_d3;
extern u32 reg_save2_d2;
extern u32 reg_save2_d1;
extern u32 reg_save2_d0;
extern u16 D_0028E774_as_u16;
extern u16 D_0028E778;

void func_001A3E70(void) {
    reg_save2_d0 = reg_d0.w;
    reg_save2_d1 = reg_d1.w;
    reg_save2_d2 = reg_d2.w;
    reg_save2_d3 = reg_d3.w;
    reg_save2_d4 = reg_d4.w;
    reg_save2_d5 = reg_d5.w;
    reg_save2_d6 = reg_d6.w;
    reg_save2_d7 = reg_d7.w;
    reg_save2_a0 = (u8 *)(reg_a0);
    reg_save2_a1 = reg_a1;
    reg_save2_a2 = reg_a2;
    reg_save2_a3 = reg_a3;
    reg_save2_a4 = reg_a4;
    reg_save2_a5 = reg_a5;
    reg_save2_a6 = reg_a6;
    if (D_0028E778 == 0) {
        reg_d0.w = D_0028E770;
        func_0013C350();
        if (cond_flag == 0) {
            func_0013C300();
            D_0028E778 = 1;
        }
    }
    if (D_0028E294 == 0) {
        if (D_0028E778 == 1) {
            D_0028E774_as_u16 -= 1;
            if (D_0028E774_as_u16 == 0) {
                reg_a0 = (u8 *)D_0026B5F0;
                func_0013BE50();
                D_0028E770 = reg_d0.w;
                D_0028E778 = 2;
            }
        }
        if (D_0028E778 == 2) {
            reg_d0.w = D_0028E770;
            func_0013C350();
            if (cond_flag == 0) {
                func_0013C300();
                func_001A40A0();
                return;
            }
        }
        func_001A4320();
        func_001A4410();
        func_001A44C0();
        func_001A4660();
        func_001A4740();
        func_001A47D0();
        func_001A4990();
        func_001A4A20();
        func_001A4B60();
        func_001A4CB0();
        func_001A4EA0();
        goto block_11;
    }
block_11:
    cond_flag = 1;
    reg_d0.w = reg_save2_d0;
    reg_d1.w = reg_save2_d1;
    reg_d2.w = reg_save2_d2;
    reg_d3.w = reg_save2_d3;
    reg_d4.w = reg_save2_d4;
    reg_d5.w = reg_save2_d5;
    reg_d6.w = reg_save2_d6;
    reg_d7.w = reg_save2_d7;
    reg_a0 = (u8 *)reg_save2_a0;
    reg_a1 = (u8 *)reg_save2_a1;
    reg_a2 = (u8 *)reg_save2_a2;
    reg_a3 = (u8 *)reg_save2_a3;
    reg_a4 = (u8 *)reg_save2_a4;
    reg_a5 = (u8 *)reg_save2_a5;
    reg_a6 = (u8 *)reg_save2_a6;
}

extern s32 reg_save2_a6_as_s32;
extern s32 reg_save2_a5_as_s32;
extern s32 reg_save2_a4_as_s32;
extern s32 reg_save2_a3_as_s32;
extern s32 reg_save2_a2_as_s32;
extern s32 reg_save2_a1_as_s32;
extern s32 reg_save2_a0_as_s32;

void func_001A40A0(void) {
    void music_stop(void);
    music_stop();
    reg_d0.w = reg_save2_d0;
    reg_d1.w = reg_save2_d1;
    reg_d2.w = reg_save2_d2;
    reg_d3.w = reg_save2_d3;
    reg_d4.w = reg_save2_d4;
    reg_d5.w = reg_save2_d5;
    reg_d6.w = reg_save2_d6;
    reg_d7.w = reg_save2_d7;
    reg_a0 = (u8 *)reg_save2_a0_as_s32;
    reg_a1 = (u8 *)reg_save2_a1_as_s32;
    reg_a2 = (u8 *)reg_save2_a2_as_s32;
    reg_a3 = (u8 *)reg_save2_a3_as_s32;
    cond_flag = 0;
    reg_a4 = (u8 *)reg_save2_a4_as_s32;
    reg_a5 = (u8 *)reg_save2_a5_as_s32;
    reg_a6 = (u8 *)reg_save2_a6_as_s32;
}

void func_001A4140(void) {
    reg_save2_d0 = reg_d0.w;
    reg_save2_d1 = reg_d1.w;
    reg_save2_d2 = reg_d2.w;
    reg_save2_d3 = reg_d3.w;
    reg_save2_d4 = reg_d4.w;
    reg_save2_d5 = reg_d5.w;
    reg_save2_d6 = reg_d6.w;
    reg_save2_d7 = reg_d7.w;
    reg_save2_a0 = reg_a0;
    reg_save2_a1 = reg_a1;
    reg_save2_a2 = reg_a2;
    reg_save2_a3 = reg_a3;
    reg_save2_a4 = reg_a4;
    reg_save2_a5 = reg_a5;
    reg_save2_a6 = reg_a6;
    func_001A4320();
    func_001A4410();
    func_001A44C0();
    func_001A4660();
    func_001A4740();
    func_001A47D0();
    func_001A4990();
    func_001A4A20();
    func_001A4B60();
    func_001A4CB0();
    func_001A4EA0();
    reg_d0.w = reg_save2_d0;
    reg_d1.w = reg_save2_d1;
    reg_d2.w = reg_save2_d2;
    reg_d3.w = reg_save2_d3;
    reg_d4.w = reg_save2_d4;
    reg_d5.w = reg_save2_d5;
    reg_d6.w = reg_save2_d6;
    reg_d7.w = reg_save2_d7;
    reg_a0 = (u8 *)reg_save2_a0;
    reg_a1 = (u8 *)reg_save2_a1;
    reg_a2 = (u8 *)reg_save2_a2;
    reg_a3 = (u8 *)reg_save2_a3;
    reg_a4 = (u8 *)reg_save2_a4;
    reg_a5 = (u8 *)reg_save2_a5;
    reg_a6 = (u8 *)reg_save2_a6;
}

void func_001A42A0(void) {
    s32 sprite_draw(s32);
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;

    temp_s1 = reg_d2.w;
    temp_s2 = reg_d3.w;
    temp_s3 = reg_d4.w;
    temp_s0 = reg_d1.w;
    reg_d2.w = 0x1458;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 7;
    reg_d1.w = 0;
    sprite_draw(0x1458);
    reg_d1.w = temp_s0;
    reg_d2.w = temp_s1;
    reg_d3.w = temp_s2;
    reg_d4.w = temp_s3;
}

extern u16 g_frame_mod2;

void func_001A4320(void) {
    s32 sprite_draw();
    reg_d2.w = 0x1458;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 7;
    reg_d1.w = 0;
    sprite_draw();
    if (D_0028E294 == 0) {
        func_001A4400();
        reg_d1.w = 0x5F000400;
        reg_d2.w = 0x153A;
        reg_d3.h[0] = 0x8C0;
        reg_d4.h[0] = 6;
        sprite_draw();
        if (g_frame_mod2 != 0) {
            reg_d1.w = 0x63000800;
            reg_d2.w = 0x1547;
            reg_d3.h[0] = 0x4A0;
            reg_d4.h[0] = 5;
            sprite_draw();
        }
    }
    if (D_0028E294 != 0) {
        reg_d1.w = 0x14C00000;
    } else {
        reg_d1.w = 0x05C00000;
    }
    reg_d2.w = 0x153B;
    reg_d3.h[0] = 0x2EE0;
    reg_d4.h[0] = 6;
    sprite_draw();
}

void func_001A4400(void) {
}

extern u8 D_0026B370[];

void func_001A4410(void) {
    s32 sprite_draw_keep();
    if (D_0028E294 != 0) {
        reg_d1.w = 0x628004C0;
    } else {
        reg_d1.w = 0x538004C0;
    }
    reg_d6.w = 0;
    reg_d3.h[0] = 0x610;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        reg_d2.w = *(u32 *)(D_0026B370 + (reg_d6.h[0] & ~3));
        sprite_draw_keep();
        reg_d6.h[0] += 4;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_0026B390[];
extern u16 D_002BB378_as_u16_a[];

void func_001A44C0(void) {
    void sprite_draw_keep(void);
    u16 idx;

    reg_a6 = (u8 *)D_002BB378_as_u16_a;
    reg_a0 = (u8 *)D_0026B390;
    if (D_0028E294 != 0) {
        reg_d1.w = 0x62000A80;
    } else {
        reg_d1.w = 0x53000A80;
    }
    reg_d7.w = 4;
    do {
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        idx = reg_d0.h[0] & 0xFFFF;
        reg_d2.h[0] = ((idx + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(idx + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((idx + 4) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(idx + 4) & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((idx + 6) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(idx + 6) & ~1)) : *(u16 *)reg_a0;
        sprite_draw_keep();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u8 D_0026B3B0[];
extern u16 D_002BB368_as_u16_a[];

void func_001A4660(void) {
    s32 sprite_draw_keep();
    u16 temp_a0;

    reg_a6 = (u8 *)(D_002BB368_as_u16_a);
    reg_a0 = (u8 *)D_0026B3B0;
    if (D_0028E294 != 0) {
        reg_d1.w = 0x5E0009C0;
    } else {
        reg_d1.w = 0x4F0009C0;
    }
    reg_d3.h[0] = 0x220;
    reg_d4.h[0] = 8;
    reg_d7.w = 4;
    do {
        temp_a0 = ENTITY(reg_a6)->flags.h;
        reg_d0.h[0] = temp_a0;
        reg_a6 += 2;
        reg_d0.h[0] -= 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
        sprite_draw_keep();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001A4740(void) {
    s32 sprite_draw_keep();
    if (D_0028E294 != 0) {
        reg_d1.w = 0x5EC01800;
    } else {
        reg_d1.w = 0x4FC01800;
    }
    reg_d2.w = 0x1548;
    reg_d3.h[0] = 0x228;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        sprite_draw_keep();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u8 D_0026B3C0[];
extern s8 D_002BB388_as_s8_a[];
extern u16 D_002BB398_as_u16_a[];

void func_001A47D0(void) {
    void sprite_draw_keep(void);
    reg_a0 = (u8 *)D_0026B3C0;
    reg_a1 = (u8 *)D_002BB398_as_u16_a;
    reg_a2 = (u8 *)D_002BB388_as_s8_a;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x5EC0;
    } else {
        reg_d1.h[0] = 0x4FC0;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] = 0x2400;
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (reg_d0.h[0] != 0) {
            if ((reg_d0.b[0] == 1) && (*(s8 *)reg_a2 == 5)) {
                reg_d1.h[0] = 0x2400;
                reg_a2 += 2;
                reg_d2.w = 0x14BE;
                reg_d3.h[0] = 0x218;
                goto next_2;
            }
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_d2.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
            sprite_draw_keep();
            reg_d1.h[0] += 0x200;
            reg_d2.w = 0x1546;
            sprite_draw_keep();
            reg_d1.h[0] += 0x200;
            goto next_1;
        }
        reg_d1.h[0] = 0x2600;
next_1:
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
next_2:
        sprite_draw_keep();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001A4990(void) {
    s32 sprite_draw_keep();
    if (D_0028E294 != 0) {
        reg_d1.w = 0x66C02BC0;
    } else {
        reg_d1.w = 0x57C02BC0;
    }
    reg_d2.w = 0x14C9;
    reg_d3.h[0] = 0x220;
    reg_d4.h[0] = 8;
    reg_d7.w = 4;
    do {
        sprite_draw_keep();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u8 D_0026B3F0[];
extern u16 D_002BB358_as_u16_a[];

void func_001A4A20(void) {
    void sprite_draw_keep(void);
    u32 tmp;

    reg_a6 = (u8 *)D_002BB358_as_u16_a;
    reg_a0 = (u8 *)D_0026B3F0;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x6380;
    } else {
        reg_d1.h[0] = 0x5480;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 8;
    reg_d7.w = 4;
    do {
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        reg_d1.h[0] = 0x31C0;
        reg_d6.w = 3;
loop_1:
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] &= 0xF;
        reg_d2.w = *(u32 *)(D_0026B3F0 + (reg_d2.h[0] * 4));
        sprite_draw_keep();
        reg_d1.h[0] -= 0x200;
        reg_d0.h[0] >>= 4;
        if (reg_d0.h[0] != 0) {
            tmp = reg_d6.h[0] - 1;
            reg_d6.h[0] = tmp;
            if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                goto loop_1;
            }
        }
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u8 D_0026B420[];
extern u8 D_0026B4A0[];
extern u8 D_002BB3B0_as_u8_a[];

void func_001A4B60(void) {
    void sprite_draw_keep(void);
    s32 flag;
    u32 tmp;

    reg_a6 = (u8 *)D_002BB3B0_as_u8_a;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x66C0;
    } else {
        reg_d1.h[0] = 0x57C0;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    reg_a0 = (u8 *)D_0026B420;
    do {
        reg_d1.h[0] = 0x1680;
        reg_d5.w = 2;
        flag = 0;
loop_1:
        reg_d2.w = *(u32 *)reg_a6;
        reg_a6 += 4;
        if ((u32) reg_d2.w > 0x70U) {
            flag = 1;
        }
        if (flag != 0) {
            reg_d2.w = 0x68;
            *(u32 *)(reg_a6 - 4) = reg_d2.w;
        }
        reg_d2.w = *(u32 *)(reg_a0 + reg_d2.w);
        sprite_draw_keep();
        reg_d1.h[0] += 0x400;
        tmp = reg_d5.h[0] - 1;
        reg_d5.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_a0 = (u8 *)D_0026B4A0;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u8 D_0026B520[];
extern u8 D_0026B550[];
extern u16 D_002BB338_as_u16_a[];
extern u32 D_002BB3F0_as_u32_a[];

void func_001A4CB0(void) {
    void sprite_draw_keep(void);
    u32 tmp;

    reg_a1 = (u8 *)D_002BB3F0_as_u32_a;
    reg_a2 = (u8 *)D_002BB338_as_u16_a;
    reg_a0 = (u8 *)D_0026B520;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x62C0;
    } else {
        reg_d1.h[0] = 0x53C0;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        reg_d1.h[0] = 0x2580;
        reg_d6.w = 7;
        reg_d0.w = *(u32 *)reg_a1;
        reg_a1 += 4;
loop_1:
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] &= 0xF;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += reg_d2.h[0];
        reg_tmp2.w = reg_d2.w;
        reg_d2.w = *(u32 *)(reg_a0 + (u16) reg_tmp2.w);
        sprite_draw_keep();
        reg_d1.h[0] -= 0x200;
        reg_d0.w >>= 4;
        if (reg_d0.w != 0) {
            goto next_1;
        }
        if (*(u16 *)reg_a2 == 0) {
            goto next_2;
        }
next_1:
        tmp = reg_d6.h[0] - 1;
        reg_d6.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        if (reg_d0.h[0] != 0) {
            reg_d2.h[0] = reg_d0.h[0];
            reg_d2.h[0] &= 0xF;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_tmp2.w = reg_d2.w;
            reg_d2.w = *(u32 *)(reg_a0 + (u16) reg_tmp2.w);
            sprite_draw_keep();
        }
next_2:
        reg_a0 = (u8 *)D_0026B550;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_002BB348_as_u16_a[];

void func_001A4EA0(void) {
    s32 sprite_draw_keep();
    u16 temp_a0;

    reg_a6 = (u8 *)(D_002BB348_as_u16_a);
    if (D_0028E294 != 0) {
        reg_d1.w = 0x62C02780;
    } else {
        reg_d1.w = 0x53C02780;
    }
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    reg_a0 = (u8 *)D_0026B520;
    do {
        temp_a0 = ENTITY(reg_a6)->flags.h;
        reg_d2.h[0] = temp_a0;
        reg_a6 += 2;
        reg_d2.h[0] &= 0xF;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += reg_d2.h[0];
        reg_tmp2.w = reg_d2.w;
        reg_d2.w = *(u32 *)(reg_a0 + (u16) reg_tmp2.w);
        sprite_draw_keep();
        reg_a0 = (u8 *)D_0026B550;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

u8 D_0026B370[720] = {
    0x35, 0x15, 0x00, 0x00, 0x36, 0x15, 0x00, 0x00, 0x37, 0x15, 0x00, 0x00, 0x38, 0x15, 0x00, 0x00,
    0x39, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xBA, 0x14, 0x18, 0x04, 0x00, 0x00, 0x00, 0x00, 0xBC, 0x14, 0x18, 0x04, 0x01, 0x00,
    0x00, 0x00, 0xBB, 0x14, 0x18, 0x04, 0x00, 0x00, 0x00, 0x00, 0xBD, 0x14, 0x18, 0x04, 0x01, 0x00,
    0xCA, 0x14, 0x00, 0x00, 0xCB, 0x14, 0x00, 0x00, 0xCC, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3D, 0x15, 0x00, 0x00, 0x3E, 0x15, 0x00, 0x00, 0x3F, 0x15, 0x00, 0x00, 0x40, 0x15, 0x00, 0x00,
    0x41, 0x15, 0x00, 0x00, 0x42, 0x15, 0x00, 0x00, 0x43, 0x15, 0x00, 0x00, 0x44, 0x15, 0x00, 0x00,
    0x45, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xBF, 0x14, 0x00, 0x00, 0xC0, 0x14, 0x00, 0x00, 0xC1, 0x14, 0x00, 0x00, 0xC2, 0x14, 0x00, 0x00,
    0xC3, 0x14, 0x00, 0x00, 0xC4, 0x14, 0x00, 0x00, 0xC5, 0x14, 0x00, 0x00, 0xC6, 0x14, 0x00, 0x00,
    0xC7, 0x14, 0x00, 0x00, 0xC8, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x05, 0x15, 0x00, 0x00, 0x06, 0x15, 0x00, 0x00, 0x07, 0x15, 0x00, 0x00, 0x08, 0x15, 0x00, 0x00,
    0x09, 0x15, 0x00, 0x00, 0x0A, 0x15, 0x00, 0x00, 0x0B, 0x15, 0x00, 0x00, 0x0C, 0x15, 0x00, 0x00,
    0x0D, 0x15, 0x00, 0x00, 0x0E, 0x15, 0x00, 0x00, 0x0F, 0x15, 0x00, 0x00, 0x10, 0x15, 0x00, 0x00,
    0x11, 0x15, 0x00, 0x00, 0x12, 0x15, 0x00, 0x00, 0x13, 0x15, 0x00, 0x00, 0x14, 0x15, 0x00, 0x00,
    0x15, 0x15, 0x00, 0x00, 0x16, 0x15, 0x00, 0x00, 0x17, 0x15, 0x00, 0x00, 0x18, 0x15, 0x00, 0x00,
    0x19, 0x15, 0x00, 0x00, 0x1A, 0x15, 0x00, 0x00, 0x1B, 0x15, 0x00, 0x00, 0x1C, 0x15, 0x00, 0x00,
    0x1D, 0x15, 0x00, 0x00, 0x1E, 0x15, 0x00, 0x00, 0x1F, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xE9, 0x14, 0x00, 0x00, 0xEA, 0x14, 0x00, 0x00, 0xEB, 0x14, 0x00, 0x00, 0xEC, 0x14, 0x00, 0x00,
    0xED, 0x14, 0x00, 0x00, 0xEE, 0x14, 0x00, 0x00, 0xEF, 0x14, 0x00, 0x00, 0xF0, 0x14, 0x00, 0x00,
    0xF1, 0x14, 0x00, 0x00, 0xF2, 0x14, 0x00, 0x00, 0xF3, 0x14, 0x00, 0x00, 0xF4, 0x14, 0x00, 0x00,
    0xF5, 0x14, 0x00, 0x00, 0xF6, 0x14, 0x00, 0x00, 0xF7, 0x14, 0x00, 0x00, 0xF8, 0x14, 0x00, 0x00,
    0xF9, 0x14, 0x00, 0x00, 0xFA, 0x14, 0x00, 0x00, 0xFB, 0x14, 0x00, 0x00, 0xFC, 0x14, 0x00, 0x00,
    0xFD, 0x14, 0x00, 0x00, 0xFE, 0x14, 0x00, 0x00, 0xFF, 0x14, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00,
    0x01, 0x15, 0x00, 0x00, 0x02, 0x15, 0x00, 0x00, 0x03, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x2B, 0x15, 0x00, 0x00, 0x2C, 0x15, 0x00, 0x00, 0x2D, 0x15, 0x00, 0x00, 0x2E, 0x15, 0x00, 0x00,
    0x2F, 0x15, 0x00, 0x00, 0x30, 0x15, 0x00, 0x00, 0x31, 0x15, 0x00, 0x00, 0x32, 0x15, 0x00, 0x00,
    0x33, 0x15, 0x00, 0x00, 0x34, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x21, 0x15, 0x00, 0x00, 0x22, 0x15, 0x00, 0x00, 0x23, 0x15, 0x00, 0x00, 0x24, 0x15, 0x00, 0x00,
    0x25, 0x15, 0x00, 0x00, 0x26, 0x15, 0x00, 0x00, 0x27, 0x15, 0x00, 0x00, 0x28, 0x15, 0x00, 0x00,
    0x29, 0x15, 0x00, 0x00, 0x2A, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x05, 0x00, 0x1F, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x12, 0x00, 0x13, 0x00, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x01, 0x19, 0x00, 0x1A, 0x00, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
    0x20, 0x00, 0x21, 0x00, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x27, 0x00,
    0x28, 0x00, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x2E, 0x00, 0x2F, 0x00,
    0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40, 0x00, 0x1F, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40, 0x01, 0x1F, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x80, 0x01, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x1F, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1F, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1F, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

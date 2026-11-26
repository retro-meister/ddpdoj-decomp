#include "common.h"

s32 func_001A2F20();
extern s16 D_0028E0C0;
extern u8 D_0029FCB0[];

void func_001A30A0(void) {
    s32 d0 = reg_d0.w;
    u8 *a0 = reg_a0;
    u8 *a1 = reg_a1;

    reg_a1 = (u8 *)D_0029FCB0;
    reg_d0.h[0] <<= 6;
    reg_d0.h[0] += 0x20;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 7;
    func_001A2F20();
    reg_d0.w = d0;
    D_0028E0C0 = 1;
    reg_a0 = a0;
    reg_a1 = a1;
}


void func_001A3130(void) {
    s32 d0;
    s32 d1;
    u8 *a0;
    u8 *a1;
    u32 tmp;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    a0 = reg_a0;
    a1 = reg_a1;
    reg_a1 = (u8 *) ((u16 *)D_0029FCB0);
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
loop_1:
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    D_0028E0C0 = 1;
    reg_d1.w = d1;
    reg_a0 = a0;
    reg_a1 = a1;
}

extern s16 D_0028E0BC;
extern u8 D_0029F4B0[];

void func_001A31D0(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = (s32)reg_a0;
    u8 *temp_s2 = reg_a1;

    reg_a1 = D_0029F4B0;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 0xF;
    func_001A2F20();
    reg_d0.w = temp_s0;
    D_0028E0BC = 1;
    reg_a0 = (u8 *)temp_s1;
    reg_a1 = temp_s2;
}

void func_001A3250(void) {
    u32 save_d0;
    u32 save_d1;
    u8 *save_a0;
    u8 *save_a1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    reg_a1 = (u8 *)D_0029F4B0;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
    do {
        reg_d0.w = 0xF;
        func_001A2F20();
    } while ((s16)(--reg_d1.h[0]) >= 0);
    reg_d0.w = save_d0;
    D_0028E0BC = 1;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
}

s32 sprite_palette_load();
extern u32 D_0025F620[];
extern u16 g_stage_x4;

void func_001A3300(void) {
    s64 temp_a0;
    u16 temp_a1;

    reg_a2 = (u8 *)(D_0025F620);
    reg_d0.h[0] = g_stage_x4;
    reg_tmp.w = *(u32 *)(reg_a2 + reg_d0.h[0]);
    reg_a2 = (u8 *) reg_tmp.w;
loop_1:
    reg_d0.w = *(u32 *)reg_a2;
    reg_a2 += 4;
    if (reg_d0.w != -1U) {
        reg_a1 = (u8 *)reg_d0.w;
loop_3:
        temp_a1 = *(u16 *)reg_a1;
        temp_a0 = (s64) ((s64) temp_a1 << 0x30) >> 0x30;
        if (temp_a0 != -1) {
            reg_d0.h[0] = temp_a1;
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
            reg_a0 = (u8 *)reg_tmp.w;
            sprite_palette_load();
            reg_a1 += 8;
            goto loop_3;
        }
        goto loop_1;
    }
}

s32 text_palette_load();
extern u8 D_0025F640[];
extern u8 D_0025F650[];
extern s32 D_0028E998;
extern s32 D_0028E99C;

void func_001A33C0(void) {
    u8 *temp_s0;
    u8 *var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;

    temp_s0 = (u8 *)(D_0025F640 + (reg_d0.h[0] * 8));
    var_s1 = (u8 *)(D_0025F650 + (((reg_d1.h[0] != 0) + (reg_d0.h[0] * 2)) * 0x10));
    if (reg_d0.h[0] == 0) {
        if (D_0028E99C >= 0) {
            var_v0 = D_0028E99C * 0x10;
            var_s1 = (u8 *)(D_0025F650 + var_v0);
        }
    } else {
        if (D_0028E998 >= 0) {
            var_v0 = D_0028E998 * 0x10;
            var_s1 = (u8 *)(D_0025F650 + var_v0);
        }
    }
    var_s2 = 0;
    var_s3 = 0;
    var_s4 = 0;
    do {
        reg_a0 = *(u8 **)((u8 *)var_s1 + var_s3);
        reg_d0.h[0] = *(u16 *)(temp_s0 + var_s4);
        sprite_palette_load();
        var_s2 += 1;
        var_s3 += 4;
        var_s4 += 2;
    } while (var_s2 < 3);
    reg_a0 = *(u8 **)((u8 *)var_s1 + (var_s2 * 4));
    reg_d0.w = (u32) *(u16 *)(temp_s0 + (var_s2 * 2));
    text_palette_load();
}

extern s32 D_0028E77C;
extern s32 D_0028E780;

void func_001A34C0(void) {
    reg_a4 = (u8 *)(&D_0028E780);
    if (reg_d0.b[0] != 0) {
        reg_a4 = (u8 *)(&D_0028E77C);
    }
}

s32 deferred_text_clear();
void func_001A34E0(void) {
    reg_d1.h[0] = 0;
    reg_d0.h[0] = 0xDC;
    if (reg_d2.b[0] != 0) {
        reg_d0.h[0] = 0xDC;
        reg_d1.h[0] = 0xE00;
    }
    reg_d4.w = 0;
    reg_d2.w = 1;
    reg_d3.w = 0xD;
    deferred_text_clear();
}


void func_001A3520(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_a4 = temp_s0;
}

void func_001A3560(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    *(s16 *)reg_a4 = 1;
    *(s16 *)(reg_a4 + 2) = 0;
    reg_a4 = temp_s0;
}

void func_001A35A0(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    if (*(u16 *)(reg_a4 + 2) != 4) {
        *(s16 *)reg_a4 = 1;
        *(u16 *)(reg_a4 + 2) = 4U;
    }
    reg_a4 = temp_s0;
}

void func_001A35F0(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    *(s16 *)reg_a4 = 1;
    *(s16 *)(reg_a4 + 2) = 8;
    reg_a4 = temp_s0;
}

extern u8 g_setting_chute_type;
extern u8 g_setting_coin_mode;
extern u16 g_loop;

void func_001A3630(void) {
    u8 *temp_s0;

    if ((s8)g_setting_coin_mode >= 9) {
        func_001A3560();
        return;
    }
    if (g_setting_chute_type == 1) {
        func_001A3560();
        return;
    }
    if (g_loop != 0) {
        func_001A35A0();
        return;
    }
    temp_s0 = reg_a4;
    func_001A34C0();
    if (*(u16 *)(reg_a4 + 2) != 0xC) {
        *(s16 *)reg_a4 = 1;
        *(u16 *)(reg_a4 + 2) = 0xCU;
    }
    reg_a4 = temp_s0;
}


void func_001A36E0(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    *(s8 *)(reg_a5 + 2) = 0;
    *(s16 *)(reg_a5 + 4) = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A34C0();
    *(s16 *)reg_a4 = 0;
    *(s16 *)(reg_a4 + 2) = 0;
}

typedef void (*Fn)();

void func_001A37F0();
void func_001A3830();
void func_001A39B0();
void func_001A3BA0();

void (*player_panel_steps[4])() = {
    func_001A37F0,
    func_001A3830,
    func_001A39B0,
    func_001A3BA0,
};

/* Cells of the panel texts, one per frame: tile in the high word, palette in the low word. */
u32 player_panel_step1_frames[16] = {
    (0x06EF << 16) | 0x16, (0x0707 << 16) | 0x16, (0x071F << 16) | 0x16, (0x0737 << 16) | 0x16,
    (0x074F << 16) | 0x16, (0x0767 << 16) | 0x16, (0x077F << 16) | 0x16, (0x0797 << 16) | 0x16,
    (0x07AF << 16) | 0x16, (0x0797 << 16) | 0x16, (0x077F << 16) | 0x16, (0x0767 << 16) | 0x16,
    (0x074F << 16) | 0x16, (0x0737 << 16) | 0x16, (0x071F << 16) | 0x16, (0x0707 << 16) | 0x16,
};

u32 player_panel_step2_frames_p1[8] = {
    (0x067F << 16) | 0x0E, (0x0686 << 16) | 0x0E, (0x068D << 16) | 0x0E, (0x0694 << 16) | 0x0E,
    (0x069B << 16) | 0x0E, (0x06A2 << 16) | 0x0E, (0x06A9 << 16) | 0x0E, (0x06B0 << 16) | 0x0E,
};

u32 player_panel_step2_frames_p2[8] = {
    (0x06B7 << 16) | 0x10, (0x06BE << 16) | 0x10, (0x06C5 << 16) | 0x10, (0x06CC << 16) | 0x10,
    (0x06D3 << 16) | 0x10, (0x06DA << 16) | 0x10, (0x06E1 << 16) | 0x10, (0x06E8 << 16) | 0x10,
};

u32 player_panel_step3_frames[16] = {
    (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C,
    (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C,
    (0x066B << 16) | 0x0C, (0x066B << 16) | 0x0C, (0x0657 << 16) | 0x0C, (0x0657 << 16) | 0x0C,
    (0x0643 << 16) | 0x0C, (0x0643 << 16) | 0x0C, (0x062F << 16) | 0x0C, (0x062F << 16) | 0x0C,
};


void func_001A3730(void) {
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_001A36E0();
        return;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A34C0();
    if (*(u16 *)reg_a4 != 0) {
        *(u16 *)reg_a4 = 0U;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
        if (*(u16 *)(reg_a5 + 4) != reg_d0.h[0]) {
            *(s8 *)(reg_a5 + 2) = 0;
            *(u16 *)(reg_a5 + 4) = (u16) reg_d0.h[0];
        }
    }
    reg_a0 = (u8 *)player_panel_steps;
    reg_a0 += *(u16 *)(reg_a5 + 4);
    reg_call_target = *(Fn *)reg_a0;
    reg_call_target();
}


void func_001A37F0() {
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A34E0();
    }
}

s32 deferred_text_put();

void func_001A3830(s32 arg3) {
    s32 var_a3;
    u16 temp_a0;
    u16 temp_a1;

    var_a3 = arg3;
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A34E0();
        var_a3 = 1;
        *(u8 *)(reg_a5 + 7) = 1U;
        *(u16 *)(reg_a5 + 0xC) = 0U;
        *(s16 *)(reg_a5 + 0xE) = 0x202;
        reg_tmp.w = 0xDC0100;
        *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
        switch (*(u8 *)(reg_a5 + 6)) { case 0: break; default:
            reg_tmp.w = 0xDC0F00;
            *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
        }
    }
    *(u8 *)(reg_a5 + 0xF) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0xF) < 0) {
        *(u8 *)(reg_a5 + 0xF) = *(u8 *)(reg_a5 + 0xE);
        *(u8 *)(reg_a5 + 7) = 1U;
        *(u16 *)(reg_a5 + 0xC) += 4;
        if ((s16) *(u16 *)(reg_a5 + 0xC) >= 0x40) {
            *(u16 *)(reg_a5 + 0xC) = 0U;
        }
    }
    if (*(u8 *)(reg_a5 + 7) != 0) {
        *(u8 *)(reg_a5 + 7) = 0U;
        reg_a0 = (u8 *)(player_panel_step1_frames);
        temp_a1 = *(u16 *)(reg_a5 + 0xC);
        reg_a0 += temp_a1;
        reg_d4.w = *(u32 *)reg_a0;
        reg_d0.h[0] = *(u16 *)(reg_a5 + 8);
        temp_a0 = *(u16 *)(reg_a5 + 0xA);
        reg_d1.h[0] = temp_a0;
        reg_d2.w = 1;
        reg_d3.w = 0xB;
        deferred_text_put();
    }
}

s32 func_001AB7F0();
s32 func_001AB860();

void func_001A39B0(s32 arg2, s32 arg3) {
    s32 var_a2;
    s32 var_a3;
    u16 temp_a0_2;
    u8 *temp_a0;

    var_a2 = arg2;
    var_a3 = arg3;
    temp_a0 = (u8 *)(reg_a5 + 2);
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        if (*(u8 *)(reg_a5 + 6) == 0) {
            func_001AB7F0();
        } else {
            func_001AB860();
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A34E0();
        var_a2 = 0xDC0000;
        var_a3 = 0x101;
        *(u8 *)(reg_a5 + 7) = 1U;
        *(u16 *)(reg_a5 + 0xC) = 0U;
        *(s16 *)(reg_a5 + 0xE) = 0x101;
        reg_tmp.w = 0xDC0100;
        *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32) player_panel_step2_frames_p1;
        *(u16 *)(reg_a5 + 0x10) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[0];
        switch (*(u8 *)(reg_a5 + 6)) { case 0: break; default:
            reg_tmp.w = 0xDC1200;
            *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) player_panel_step2_frames_p2;
            *(u16 *)(reg_a5 + 0x10) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[0];
        }
    }
    *(u8 *)(reg_a5 + 0xF) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0xF) < 0) {
        *(u8 *)(reg_a5 + 0xF) = *(u8 *)(reg_a5 + 0xE);
        *(u8 *)(reg_a5 + 7) = 1U;
        *(u16 *)(reg_a5 + 0xC) += 4;
        if ((s16) *(u16 *)(reg_a5 + 0xC) >= 0x20) {
            *(u16 *)(reg_a5 + 0xC) = 0U;
        }
    }
    if (*(u8 *)(reg_a5 + 7) != 0) {
        *(u8 *)(reg_a5 + 7) = 0U;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x10);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x12);
        reg_a0 = (u8 *)(reg_tmp.w);
        temp_a0_2 = *(u16 *)(reg_a5 + 0xC);
        reg_a0 += temp_a0_2;
        reg_d4.w = *(u32 *)reg_a0;
        reg_d0.h[0] = *(u16 *)(reg_a5 + 8);
        reg_d1.h[0] = *(u16 *)(reg_a5 + 0xA);
        reg_d3.w = 6;
        reg_d2.w = 0;
        deferred_text_put();
    }
}


void func_001A3BA0(s32 arg3) {
    s32 var_a3;
    u16 temp_a0;
    u16 temp_a1;

    var_a3 = arg3;
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A34E0();
        var_a3 = 1;
        *(u8 *)(reg_a5 + 7) = 1U;
        *(u16 *)(reg_a5 + 0xC) = 0U;
        *(s16 *)(reg_a5 + 0xE) = 0x202;
        reg_tmp.w = 0xDC0200;
        *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
        switch (*(u8 *)(reg_a5 + 6)) { case 0: break; default:
            reg_tmp.w = 0xDC1000;
            *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
        }
    }
    *(u8 *)(reg_a5 + 0xF) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0xF) < 0) {
        *(u8 *)(reg_a5 + 0xF) = *(u8 *)(reg_a5 + 0xE);
        *(u8 *)(reg_a5 + 7) = 1U;
        *(u16 *)(reg_a5 + 0xC) += 4;
        if ((s16) *(u16 *)(reg_a5 + 0xC) >= 0x40) {
            *(u16 *)(reg_a5 + 0xC) = 0U;
        }
    }
    if (*(u8 *)(reg_a5 + 7) != 0) {
        *(u8 *)(reg_a5 + 7) = 0U;
        reg_a0 = (u8 *)(player_panel_step3_frames);
        temp_a1 = *(u16 *)(reg_a5 + 0xC);
        reg_a0 += temp_a1;
        reg_d4.w = *(u32 *)reg_a0;
        reg_d0.h[0] = *(u16 *)(reg_a5 + 8);
        temp_a0 = *(u16 *)(reg_a5 + 0xA);
        reg_d1.h[0] = temp_a0;
        reg_d2.w = 1;
        reg_d3.w = 9;
        deferred_text_put();
    }
}

/* .sbss (the compiler lays these out in reverse) */
s32 D_0028E780;
s32 D_0028E77C;

#include "common.h"
#include "sdk/ps2sdk.h"
#include "pad.h"
#include "gfx_types.h"

void func_0021D6C0(void);
void func_0021D850();
void func_0021D970(void);
void func_0021DA10(void);
void func_0021DA60(void);
void func_0021DAA0(void);
void func_0021DC60(void);
void func_0021DC80(void);
void func_0021DCD0(void);
void func_0021DD40();
void func_0021DD90();
void func_0021DDE0();
void func_0021E000(void);
void func_0021E160(void);
void func_0021E2D0(void);
void func_0021E300(void);
void func_0021E370();
void func_0021E3C0();
void func_0021E410();
void func_0021E5C0(void);
void func_0021E680(void);
void func_0021E6F0();
void func_0021E740();
void func_0021E790();
void func_0021E8D0(void);
void func_0021EA10(void);
void func_0021EA50(void);
void func_0021EAE0(void);
void func_0021EB30(void);
void func_0021EB80(void);
void func_0021ED50(void);
void func_0021ED70(void);
void func_0021EDC0(void);
void func_0021EE80(void);
void func_0021EF10();
void func_0021EF60();
void func_0021EFB0();
void func_0021F180();
void func_0021F1C0(void);
void func_0021F2C0(void);
void func_0021F440(void);
void func_0021F4E0(void);
void func_0021F560();
void func_0021F5B0();
void func_0021F600();
void func_0021F750();
void death_func_001B7460(void);
void death_func_001B74D0(void);
void death_func_001B7520(void);
void death_func_001B7570(void);
void death_func_001B76A0(void);
void func_0021F7B0(void);
void func_0021F820();
void func_0021F880();
void func_0021F8D0();
void func_0021FC70(void);
void func_0021FDB0(void);
void func_002201A0(void);
void func_00220390(void);
void func_002207C0(void);
void func_002209C0(void);
void func_00221000(void);
void death_func_001B9120(void);
void func_00221080(void);
s32 func_00221120(s32 page);
s32 func_002212C0();
void func_00221360(void);
void func_00221440(void);
void func_00221550(void);
void func_00221E20(void);
void func_00221FF0();
void func_00222170(void);
void func_00222260(s32 group);
void func_00222340(s32 group);
s32 func_00222530(s32 group);
void func_00222780(void);
void func_002228D0(s32 x, s32 y);
void func_00222C30(s32 x, s32 y, s32 attr);
void func_002234C0(void);
void func_00223550(void);
void func_00223A60(void);
void func_00223AA0(void);
s32 func_00223BE0(void);
void func_00224020(s32 x, s32 y);
void func_002242B0(s32 x, s32 y);
void func_00224A30(void);
void func_00224A90(void);
void func_00224B50(void);
void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
void func_00224CC0(void);
void func_00225000(void);
void func_00225450(void);
void func_00225A00(void);
void func_00225AB0(void);
void func_002260F0(void);

extern s32 D_00684CF0[10][4][5];

void func_0021D500(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_00684CF0[i][j][k] = 0;
            }
        }
    }
}

extern s8 D_0028EB88;

void func_0021D570(void) {
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
    switch (D_0028EB88) {                           /* irregular */
    case 0:
        func_00221FF0(2, D_0028EB88);
        /* fallthrough */
    case 1:
        func_0021D6C0();
        break;
    case 2:
        func_0021D850(2, D_0028EB88);
        break;
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

s32 func_00227830();
s32 func_00227AE0();
s32 func_00227D90();
s32 func_00227F00();
s32 func_00227F70();
s32 func_00228770();
s32 func_00228B50();
s32 func_002295F0();
s32 func_0022A040();
s32 func_0022A410();
extern s8 D_0028EB84;

#ifdef DEATH_LABEL
#endif

void func_0021D6C0(void) {
    switch (D_0028EB84) {
    case 0:
        func_0021D970();
        break;
    case 1:
        func_0021DCD0();
        break;
    case 2:
        func_0021E300();
        break;
    case 3:
        func_0021E680();
        break;
    case 5:
        func_00225A00();
        break;
    case 6:
        func_00225AB0();
        break;
    case 7:
        func_00227830();
        break;
    case 10:
        func_00227AE0();
        break;
    case 11:
        func_00227D90();
        break;
    case 8:
        func_00228770();
        break;
    case 13:
        func_0022A410();
        break;
    case 14:
        func_0021EA50();
        break;
    case 15:
        func_0021EE80();
        break;
    case 16:
        func_00225000();
        break;
    case 21:
        func_0021F4E0();
        break;
#ifdef DEATH_LABEL
    case 23:
        death_func_001B7460();
        break;
#endif
    case 24:
        func_0021F7B0();
        break;
    case 17:
        func_00228B50();
        break;
    case 18:
        func_002295F0();
        break;
    case 19:
        func_0022A040();
        break;
    case 20:
        func_00227F70();
        break;
    case 22:
        func_00227F00();
        break;
    }
}

extern s8 g_fade_state;
extern s8 D_0028EB00;

void func_0021D850() {
    if (g_fade_state == 0) {
        D_0028EB88 = 0;
        if (D_0028EB00 == 2) {
            D_0028EB00 = 0x14;
        } else if (D_0028EB00 == 3) {
            D_0028EB00 = 0x1E;
        } else if (D_0028EB00 == 4) {
            D_0028EB00 = 0x28;
        } else {
            D_0028EB00 = 0xA;
        }
    }
}

extern s32 D_00270810[];
extern s32 D_00270828[];
extern s32 D_00270838[];
extern s32 D_0068DE90[];
extern s32 D_0068DEA0[];
extern s32 D_0068DEB0[];
extern s32 D_0068DEC8_as_s32_a[];
extern s32 D_0068DED8_as_s32_a[];
extern s32 D_0068DEF0_as_s32_a[];

void func_0021D8C0(void) {
    memcpy(D_0068DEF0_as_s32_a, D_00270810, 0x16);
    memcpy(D_0068DED8_as_s32_a, D_00270828, 0xA);
    memcpy(D_0068DEC8_as_s32_a, D_00270838, 0xC);
    memcpy(D_0068DEB0, D_00270810, 0x16);
    memcpy(D_0068DE90, D_00270828, 0xA);
    memcpy(D_0068DEA0, D_00270838, 0xC);
}

extern s8 D_0028EB7C;

void func_0021D970(void) {
    switch (D_0028EB7C) {
    case 0:
        func_0021DA10();
        break;
    case 1:
        func_0021DA60();
        break;
    case 2:
        func_0021DAA0();
        break;
    case 3:
        func_0021DC60();
        break;
    case 4:
        func_0021DC80();
        break;
    }
}

extern s16 D_0028E320;
extern s8 D_0028E368_as_s8;
extern s8 D_0028EB4C;
extern s8 D_0028EB80;
extern s32 D_0028EBB4;

void func_0021DA10(void) {
    D_0028E368_as_s8 = 0;
    D_0028EBB4 = 0;
    D_0028EB80 = 0;
    D_0028EB7C += 1;
    func_00222340(0);
    D_0028EB4C = 1;
    D_0028E320 = 0xE10;
}

extern s8 D_0028EB04;
extern s8 D_0028EB28;
extern s8 D_0028EB54;
extern s8 D_0028EB58;

void func_0021DA60(void) {
    if (func_00222530(0) != 0) {
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB7C += 1;
        D_0028EB58 = D_0028EB28;
    }
}

extern u16 D_0028E320_as_u16;
extern s8 D_0028EAE8;
extern s8 D_0028EB08;
extern s8 D_0028EB0C;
extern s8 D_0028EB14;
extern s8 D_0028EB18;
extern s8 D_0028EB1C;
extern s8 D_0028EB20;
extern s8 D_0028EB50;
extern s8 D_0028EB5C;
extern s8 D_0028EB60;
extern s8 D_0028EB68;
extern s8 D_0028EB6C;
extern s8 D_0028EB70;
extern s8 D_0028EB74;
extern s8 D_0028EC18_as_s8;
extern s8 D_0028EC1A;
extern s8 D_0028EC24;
#ifdef DEATH_LABEL
extern s8 g_game_mode_as_s8;
extern s8 D_0028E2E4_as_s8;
extern s8 D_0028E304_as_s8;
extern s32 D_0028EAFC;
extern s8 D_0028EB00;
s32 func_00169BC0();
#endif

void func_0021DAA0(void) {
    s32 sfx_menu_confirm();
    s32 fade_start_out();
    s32 var_a1;

    func_00221120(0);
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = MAIN_OR_DEATH_LABEL(8, 5);
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = MAIN_OR_DEATH_LABEL(8, 5);
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB28 = D_0028EB58;
    if (var_a1 != 0) {
        D_0028EB4C = 2;
        D_0028EB54 = 2;
        sfx_menu_confirm();
        D_0028EB50 = 0;
        D_0028EB54 = 0;
#ifdef DEATH_LABEL
        switch (D_0028EB58) {
        case 0:
            break;
        case 1:
            D_0028E2E4_as_s8 = 0;
            g_game_mode_as_s8 = 2;
            D_0028E304_as_s8 = 1;
            D_0028EAFC = 0xFF;
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 4;
            break;
        case 2:
            D_0028EB5C = 0;
            D_0028EB84 = 0x18;
            D_0028EB08 = 0;
            break;
        case 3:
            D_0028EB68 = 0;
            D_0028EB84 = 0xF;
            D_0028EB14 = 0;
            break;
        case 4:
            D_0028EB74 = 0;
            D_0028EB84 = 2;
            D_0028EB20 = 0;
            break;
        case 6:
            D_0028EB70 = 0;
            D_0028EB84 = 3;
            D_0028EB1C = 0;
            break;
        case 5:
            D_0028EB60 = 0;
            D_0028EB84 = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 1;
            break;
        }
#else
        switch (D_0028EB58) {
        case 0:
            break;
        case 1:
            D_0028EB6C = 0;
            D_0028EB84 = 0xE;
            D_0028EB18 = 0;
            break;
        case 3:
            D_0028EB60 = 0;
            D_0028EB84 = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 2;
            break;
        case 4:
            D_0028EB60 = 0;
            D_0028EB84 = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 1;
            break;
        case 5:
            D_0028EB5C = 0;
            D_0028EB84 = 0x18;
            D_0028EB08 = 0;
            break;
        case 6:
            D_0028EB68 = 0;
            D_0028EB84 = 0xF;
            D_0028EB14 = 0;
            break;
        case 7:
            D_0028EB74 = 0;
            D_0028EB84 = 2;
            D_0028EB20 = 0;
            break;
        case 2:
            D_0028EB84 = 7;
            D_0028EC18_as_s8 = 0xA;
            D_0028EC1A = 0;
            if (g_pad_trigger[0] & 0x20) {
                D_0028EC24 = 0;
            } else {
                D_0028EC24 = 1;
            }
            break;
        case 9:
            D_0028EB70 = 0;
            D_0028EB84 = 3;
            D_0028EB1C = 0;
            break;
        case 8:
            fade_start_out();
            D_0028EB88 = 2;
            break;
        }
#endif
    }
}

void func_0021DC60(void) {
    if (D_0028EB4C == 0) {
        D_0028E368_as_s8 = 0;
        D_0028EB7C = 4;
    }
}

#pragma push
#pragma opt_propagation off
extern s32 func_002365A0(void);

void func_0021DC80(void) {
    if (func_002365A0() != 0) {
        s8 val = D_0028EB28;
        D_0028EB7C = 2;
        D_0028EB54 = 1;
        D_0028E320 = 0xE10;
        D_0028EB58 = val;
    }
}
#pragma pop

extern s8 D_0028EB78;

void func_0021DCD0(void) {
    switch (D_0028EB78) {                           /* irregular */
    case 0:
        func_0021DD40(D_0028EB78);
        break;
    case 1:
        func_0021DD90(D_0028EB78);
        break;
    case 2:
        func_0021DDE0(D_0028EB78);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 D_0028EB24;
extern s8 D_0028EB48;
extern s32 D_0028EB90;
extern s32 D_0028EBB0;

void func_0021DD40() {
    D_0028EBB0 = 0;
    D_0028EB78 += 1;
    func_00222340(1);
    D_0028EB90 = 0x40;
    D_0028EB24 = 0;
    D_0028EB48 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off

void func_0021DD90()
{
    if (func_00222530(1) != 0) {
        s32 previousCount = D_0028EB78;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB78 = previousCount + 1;
        return;
    }
}
#pragma pop

extern s8 D_0028EB3C;
void func_0021DDE0() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(1) == 0) {
        func_0021E000();
    }
    func_0021E160();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 6;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB24 = D_0028EB58;
    if ((D_0028EB24 >= 7) && (D_0028EB24 < 0xB)) {
        if (g_pad_trigger[2] != 0) {
            var_a1 = 1;
        }
    } else if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 6;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            sfx_menu_confirm();
            func_0021E2D0();
            func_0021E160();
            break;
        case 6:
            sfx_menu_confirm();
            func_00222260(0xE);
            D_0028EB6C = 3;
            D_0028EB84 = 0xE;
            D_0028EB90 = 0x40;
            D_0028EB3C = 1;
            D_0028EB54 = 2;
            D_0028EB48 = 2;
            D_0028EB04 = 1;
            D_0028EB78 += 1;
            break;
        }
    }
}

extern s32 g_screen_mode;
extern s8 D_0028DD9C[4];
extern s8 D_0028DDA0[2];
extern s8 g_pad_tate_rotate_as_s8;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern s8 D_0068DD01[];

void func_0021DF60(void) {
    s32 value;

    D_0028E358 = D_0068DD01[0];
    if (D_0028E358 == 0) {
        if (D_0028E354 > 3) {
            D_0028E354 = 0;
        }
        value = D_0028DD9C[D_0028E354];
    } else {
        if (D_0028E354 > 1) {
            D_0028E354 = 0;
        }
        value = D_0028DDA0[D_0028E354];
    }
    g_screen_mode = value;
    if (D_0028E358 == 0 && D_0028E354 >= 2) {
        g_pad_tate_rotate_as_s8 = 1;
    } else {
        g_pad_tate_rotate_as_s8 = 0;
    }
}

extern s8 D_0028DD10[8];
extern s16 g_pad_vib_power_p2_as_s16;
extern s16 g_pad_vib_power_p1_as_s16;
extern s16 g_pad_vib_timer_p2_as_s16;
extern s16 g_pad_vib_timer_p1_as_s16;
extern u8 g_pad_vib_state_p2;
extern u8 g_pad_vib_state_p1;
extern s8 D_0068DC20[];

void func_0021E000(void) {
    extern void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel < 5) {
        max = D_0028DD10[sel];
        cur = D_0068DC20[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DC20[D_0028EB58] = cur;
            if (D_0028EB58 == 4 && cur == 1) {
                if (g_pad_repeat[0] != 0) {
                    g_pad_vib_state_p1 = 1;
                    g_pad_vib_power_p1_as_s16 = 0x78;
                    g_pad_vib_timer_p1_as_s16 = 0x14;
                } else {
                    g_pad_vib_state_p2 = 1;
                    g_pad_vib_power_p2_as_s16 = 0x78;
                    g_pad_vib_timer_p2_as_s16 = 0x14;
                }
            }
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DC20[D_0028EB58] = cur;
            if (D_0028EB58 == 4 && cur == 1) {
                if (g_pad_repeat[0] != 0) {
                    g_pad_vib_state_p1 = 1;
                    g_pad_vib_power_p1_as_s16 = 0x78;
                    g_pad_vib_timer_p1_as_s16 = 0x14;
                } else {
                    g_pad_vib_state_p2 = 1;
                    g_pad_vib_power_p2_as_s16 = 0x78;
                    g_pad_vib_timer_p2_as_s16 = 0x14;
                }
            }
        }
    }
}

extern s8 g_pad_vib_enabled_as_s8;
extern s8 D_0028E384_as_s8;
extern s8 D_0028E388_as_s8;
extern s8 D_0028E38C_as_s8;
extern s8 D_0068DC21[];
extern s8 D_0068DC22[];
extern s8 D_0068DC23[];
extern s8 D_0068DC24[];

void func_0021E160(void) {
    D_0028E38C_as_s8 = D_0068DC21[0];
    D_0028E384_as_s8 = D_0068DC22[0];
    D_0028E388_as_s8 = D_0068DC23[0];
    g_pad_vib_enabled_as_s8 = D_0068DC24[0];
}

extern u8 g_p1_btn_map_a_as_u8;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 D_0028E273;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 D_0028E277;
extern u8 D_0028E278;
extern u8 g_pad_vib_enabled;
extern u8 g_stage_map_enabled;
extern u8 D_0028E2D8;
extern u8 g_screen_wide;
extern u8 g_bgm_alternate_set;
extern u8 D_0028E2E4;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 D_0028E308;
extern u8 D_0028E30C;
extern u8 D_0028E32C_as_u8;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u8 D_0068DC21_as_u8_a[];
extern u8 D_0068DC22_as_u8_a[];
extern u8 D_0068DC23_as_u8_a[];
extern u8 D_0068DC24_as_u8_a[];
extern u8 D_0068DC33[];
extern u8 D_0068DC41_as_u8_a[];
extern u8 D_0068DC42[];
extern u8 D_0068DC43[];
extern u8 D_0068DC44_as_u8_a[];
extern u8 D_0068DC45[];
extern u8 D_0068DCF4[];
extern u8 D_0068DD01_as_u8_a[];
extern u8 D_0068DD02_as_u8_a[];
extern u8 D_0068DD03[];
extern u8 D_0068DD04[];
extern u8 D_0068DD05[];
extern u8 D_0068DD06[];
extern u8 D_0068DD09_as_u8_a[];
extern u8 D_0068DD0A_as_u8_a[];
extern u8 D_0068DD0B_as_u8_a[];
extern u8 D_0068DD0C[];
extern u8 D_0068DD0D_as_u8_a[];
extern u8 D_0068DD0E_as_u8_a[];
extern u8 D_0068DD0F_as_u8_a[];
extern u8 D_0068DD10[];

#ifdef DEATH_LABEL
extern u8 death_D_00290854;
extern u8 death_D_00290858;
extern u8 death_D_00628DC6[];
#endif

void func_0021E1A0(void) {
    D_0068DC21_as_u8_a[0] = D_0028E38C;
    D_0068DC22_as_u8_a[0] = D_0028E384;
    D_0068DC23_as_u8_a[0] = D_0028E388;
    D_0068DC24_as_u8_a[0] = g_pad_vib_enabled;
    D_0068DC33[0] = D_0028E278;
    D_0068DCF4[0] = D_0028E2D8;
    D_0068DC41_as_u8_a[0] = D_0028E304;
    D_0068DC42[0] = D_0028E30C;
    D_0068DC43[0] = D_0028E308;
    D_0068DC44_as_u8_a[0] = D_0028E2EC;
#ifdef DEATH_LABEL
    D_0068DC45[0] = death_D_00290858;
    death_D_00628DC6[0] = death_D_00290854;
#else
    D_0068DC45[0] = D_0028E2E4;
#endif
    D_0068DD01_as_u8_a[0] = D_0028E358;
    D_0068DD02_as_u8_a[0] = D_0028E354;
    D_0068DD03[0] = g_screen_wide;
    D_0068DD04[0] = D_0028E32C_as_u8;
    D_0068DD05[0] = g_stage_map_enabled;
    D_0068DD06[0] = g_bgm_alternate_set;
    D_0068DD09_as_u8_a[0] = g_p1_btn_map_a_as_u8;
    D_0068DD0A_as_u8_a[0] = g_p1_btn_map_b;
    D_0068DD0B_as_u8_a[0] = g_p1_btn_map_c;
    D_0068DD0C[0] = D_0028E273;
    D_0068DD0D_as_u8_a[0] = g_p2_btn_map_a;
    D_0068DD0E_as_u8_a[0] = g_p2_btn_map_b;
    D_0068DD0F_as_u8_a[0] = g_p2_btn_map_c;
    D_0068DD10[0] = D_0028E277;
}

void func_0021E2D0(void) {
    D_0068DC22[0] = 0;
    D_0068DC23[0] = 0;
    D_0068DC21[0] = 1;
    D_0068DC24[0] = 0;
}


void func_0021E300(void) {
    switch (D_0028EB74) {                           /* irregular */
    case 0:
        func_0021E370(D_0028EB74);
        break;
    case 1:
        func_0021E3C0(D_0028EB74);
        break;
    case 2:
        func_0021E410(D_0028EB74);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 D_0028EB44;
extern s32 D_0028EBAC;

void func_0021E370() {
    D_0028EBAC = 0;
    D_0028EB74 += 1;
    func_00222340(2);
    D_0028EB90 = 0x40;
    D_0028EB20 = 0;
    D_0028EB44 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021E3C0()
{
    if (func_00222530(2) != 0) {
        s32 count = D_0028EB74;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB74 = count + 1;
    }
}
#pragma pop

s32 streams_stop();
s32 sfx_play_on_channel();
s32 music_play();
extern s32 g_se_priority;
extern s32 g_se_volume;
extern s32 g_se_last_result;
extern u8 D_0028EB04_as_u8;
extern u8 D_0028EB20_as_u8;
extern u8 D_0028EB44_as_u8;
extern u8 D_0028EB4C_as_u8;
extern u8 D_0028EB54_as_u8;
extern u8 D_0028EB7C_as_u8;
extern u8 D_0028EB84_as_u8;
extern s32 D_0028EC68;
extern s32 D_0028EC6C;
extern s8 D_0068DC35[];
extern s8 D_0068DC36[];
void func_0021E410() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(2) == 0) {
        func_0021E5C0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 4;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 4;
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB20_as_u8 = D_0028EB58;
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 3:
            break;
        case 1:
            sfx_menu_confirm();
            D_0028EC68 = 0;
            D_0028EB84_as_u8 = 6;
            break;
        case 2:
            sfx_menu_confirm();
            D_0028EC6C = 0;
            D_0028EB84_as_u8 = 5;
            break;
        case 4:
            streams_stop();
            func_00222260(0);
            D_0028EB7C_as_u8 = 3;
            D_0028EB4C_as_u8 = 1;
            D_0028EB90 = 0x40;
            D_0028EB04_as_u8 = 1;
            D_0028EB54_as_u8 = 2;
            D_0028EB44_as_u8 = 2;
            D_0028EB84_as_u8 = 0;
            D_0028EB74 += 1;
            sfx_menu_confirm();
            break;
        case 5:
            g_se_volume = 0xFF;
            g_se_priority = 0xA;
            g_se_last_result = D_0068DC35[0] + 1;
            sfx_play_on_channel(g_se_last_result);
            break;
        case 6:
            g_se_last_result = (s32) D_0068DC36[0];
            music_play(g_se_last_result, 1);
            break;
        }
    }
}

extern s8 D_0028E278_as_s8;
extern s8 D_0068DC30[];

void func_0021E5C0(void) {
    void sfx_menu_tick(void);
    s32 value;

    if (D_0028EB58 == 3) {
        value = D_0068DC30[D_0028EB58];
        if (g_pad_repeat[2] & 0x2000) {
            sfx_menu_tick();
            value++;
            if (value >= 2) {
                value = 0;
            }
            D_0068DC30[D_0028EB58] = value;
            D_0028E278_as_s8 = value;
        } else if (g_pad_repeat[2] & 0x8000) {
            sfx_menu_tick();
            value--;
            if (value < 0) {
                value = 1;
            }
            D_0068DC30[D_0028EB58] = value;
            D_0028E278_as_s8 = value;
        }
    }
}


void func_0021E680(void) {
    switch (D_0028EB70) {                           /* irregular */
    case 0:
        func_0021E6F0(D_0028EB70);
        break;
    case 1:
        func_0021E740(D_0028EB70);
        break;
    case 2:
        func_0021E790(D_0028EB70);
        /* fallthrough */
    case 3:
        break;
    }
}

extern s8 D_0028EB40;
extern s32 D_0028EBA8;

void func_0021E6F0() {
    D_0028EBA8 = 0;
    D_0028EB70 += 1;
    func_00222340(3);
    D_0028EB90 = 0x40;
    D_0028EB1C = 0;
    D_0028EB40 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021E740()
{
    if (func_00222530(3) != 0) {
        s32 previousCount = D_0028EB70;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB70 = previousCount + 1;
        return;
    }
}
#pragma pop

void func_0021E790() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(3) == 0) {
        func_0021E8D0();
    }
    func_0021EA10();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = MAIN_OR_DEATH_LABEL(5, 7);
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB1C = D_0028EB58;
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = MAIN_OR_DEATH_LABEL(5, 7);
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 1:
        case 2:
        case 3:
        case 4:
#ifdef DEATH_LABEL
        case 5:
        case 6:
#endif
            break;
        case MAIN_OR_DEATH_LABEL(5, 7):
            sfx_menu_confirm();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB40 = 2;
            D_0028EB04 = 1;
            D_0028EB70 += 1;
            break;
        }
    }
}

extern s8 D_0028DD20;
extern u16 D_0028E300;
extern s8 D_0068DC40[];

void func_0021E8D0(void) {
    extern void sfx_menu_tick(void);
    s32 count;
    s32 value;

    if (D_0028EB58 >= MAIN_OR_DEATH_LABEL(5, 7)) {
        return;
    }
    if (D_0028EB58 == 1 && !(D_0028E300 & 1)) {
        return;
    }
    if (D_0028EB58 == 2 && !(D_0028E300 & 2)) {
        return;
    }
    if (D_0028EB58 == 3 && !(D_0028E300 & 4)) {
        return;
    }
    if (D_0028EB58 == 4 && !(D_0028E300 & 8)) {
        return;
    }
    count = (&D_0028DD20)[D_0028EB58];
    value = D_0068DC40[D_0028EB58];
    if (g_pad_repeat[2] & 0x2000) {
        sfx_menu_tick();
        value++;
        if (value >= count) {
            value = 0;
        }
        D_0068DC40[D_0028EB58] = value;
    } else if (g_pad_repeat[2] & 0x8000) {
        sfx_menu_tick();
        value--;
        if (value < 0) {
            value = count - 1;
        }
        D_0068DC40[D_0028EB58] = value;
    }
}

extern s8 D_0028E2EC_as_s8;
extern s8 D_0028E304_as_s8;
extern s8 D_0028E308_as_s8;
extern s8 D_0028E30C_as_s8;
extern s8 D_0068DC41[];
extern s8 D_0068DC42_as_s8_a[];
extern s8 D_0068DC43_as_s8_a[];
extern s8 D_0068DC44[];

#ifdef DEATH_LABEL
extern s8 D_0068DC45_as_s8_a[];
extern s8 death_D_00290854_as_s8;
extern s8 death_D_00290858_as_s8;
extern s8 death_D_00628DC6_as_s8_a[];
#endif

void func_0021EA10(void) {
    D_0028E304_as_s8 = D_0068DC41[0];
    D_0028E30C_as_s8 = D_0068DC42_as_s8_a[0];
    D_0028E308_as_s8 = D_0068DC43_as_s8_a[0];
    D_0028E2EC_as_s8 = D_0068DC44[0];
#ifdef DEATH_LABEL
    death_D_00290858_as_s8 = D_0068DC45_as_s8_a[0];
    death_D_00290854_as_s8 = death_D_00628DC6_as_s8_a[0];
#endif
}


void func_0021EA50(void) {
    switch (D_0028EB6C) {
    case 0:
        func_0021EAE0();
        break;
    case 1:
        func_0021EB30();
        break;
    case 2:
        func_0021EB80();
        break;
    case 3:
        func_0021ED50();
        break;
    case 4:
        func_0021ED70();
        break;
    case 5:
        break;
    }
}

extern s32 D_0028EBA4;

void func_0021EAE0(void) {
    D_0028EBA4 = 0;
    D_0028EB6C += 1;
    func_00222340(0xE);
    D_0028EB90 = 0x40;
    D_0028EB18 = 0;
    D_0028EB3C = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021EB30(void)
{
    if (func_00222530(0xE) != 0) {
        s32 previousCount = D_0028EB6C;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB6C = previousCount + 1;
        return;
    }
}
#pragma pop

extern u8 g_game_mode;
extern s32 D_0028EAFC;

void func_0021EB80(void) {
    extern void sfx_menu_confirm(void);
    extern void func_00169BC0(void);
    extern void fade_start_out(void);
    s32 var_a1;

    if (func_00221120(0xE) == 0) {
        func_0021EDC0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 5;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB18 = D_0028EB58;
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 5;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 1:
            D_0028EB3C = 2;
#ifndef DEATH_LABEL
            D_0028EAFC = 0xFF;
#endif
            D_0028EB54 = 2;
            g_game_mode = 0;
            D_0028E2E4 = 0;
            sfx_menu_confirm();
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 2;
            break;
        case 2:
            g_game_mode = 1;
            D_0028E2E4 = 1;
#ifndef DEATH_LABEL
            D_0028EAFC = 0xFF;
#endif
            D_0028EB3C = 2;
            D_0028EB54 = 2;
            sfx_menu_confirm();
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 2;
            break;
        case 3:
            D_0028EB3C = 2;
            D_0028EB54 = 2;
            sfx_menu_confirm();
            D_0028EB78 = 0;
            D_0028EB84 = 1;
            D_0028EB24 = 0;
            break;
        case 4:
            break;
        case 5:
            sfx_menu_confirm();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB3C = 2;
            D_0028EB04 = 1;
            D_0028EB6C += 1;
            break;
        }
    }
}

void func_0021ED50(void) {
    if (D_0028EB3C == 0) {
        D_0028EB6C = 4;
    }
}

#pragma push
#pragma opt_propagation off
void func_0021ED70(void) {
    if (func_002365A0() != 0) {
        s8 val = D_0028EB18;
        D_0028EB6C = 2;
        D_0028EB54 = 1;
        D_0028E320 = 0xE10;
        D_0028EB58 = val;
    }
}
#pragma pop

extern s8 D_0028E2D8_as_s8;
extern s8 D_0068DCF0[];

void func_0021EDC0(void) {
    void sfx_menu_tick(void);
    s32 value;

    if (D_0028EB58 == 4) {
        value = D_0068DCF0[D_0028EB58];
        if (g_pad_repeat[2] & 0x2000) {
            sfx_menu_tick();
            value++;
            if (value >= 2) {
                value = 0;
            }
            D_0068DCF0[D_0028EB58] = value;
            D_0028E2D8_as_s8 = value;
        } else if (g_pad_repeat[2] & 0x8000) {
            sfx_menu_tick();
            value--;
            if (value < 0) {
                value = 1;
            }
            D_0068DCF0[D_0028EB58] = value;
            D_0028E2D8_as_s8 = value;
        }
    }
}


void func_0021EE80(void) {
    switch (D_0028EB68) {                           /* irregular */
    case 0:
        func_0021EF10(D_0028EB68);
        break;
    case 1:
        func_0021EF60(D_0028EB68);
        break;
    case 2:
        func_0021EFB0(D_0028EB68);
        break;
    case 3:
        func_0021F180(D_0028EB68);
        /* fallthrough */
    case 4:
        break;
    }
}

extern s8 D_0028EB38;
extern s32 D_0028EBA0;

void func_0021EF10() {
    D_0028EBA0 = 0;
    D_0028EB68 += 1;
    func_00222340(0xF);
    D_0028EB90 = 0x40;
    D_0028EB14 = 0;
    D_0028EB38 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

#pragma push
#pragma opt_propagation off
void func_0021EF60()
{
    if (func_00222530(0xF) != 0) {
        s32 count = D_0028EB68;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB68 = count + 1;
        return;
    }
}
#pragma pop

#pragma push
extern s8 g_display_offset_y;
extern s8 g_display_offset_x;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
void func_0021EFB0() {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(0xF) == 0) {
        func_0021F1C0();
    }
    func_0021F2C0();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 0xD;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    D_0028EB14 = D_0028EB58;
    if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    if ((D_0028EB14 >= 9) && (D_0028EB14 < 0xC)) {
        if (g_pad_trigger[2] != 0) {
            var_a1 = 1;
        }
    } else if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 0xD;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            break;
        case 7:
            sfx_menu_confirm();
            D_0028EB90 = 0x80;
            D_0028EAE4 = g_display_offset_x;
            D_0028EB84 = 0x10;
            D_0028EAE0 = g_display_offset_y;
            break;
        case 9:
            func_00222780();
            break;
        case 10:
            func_00222780();
            break;
        case 11:
            func_00222780();
            break;
        case 12:
            sfx_menu_confirm();
            func_0021F440();
            func_0021F2C0();
            break;
        case 13:
            sfx_menu_confirm();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB38 = 2;
            D_0028EB04 = 1;
            D_0028EB68 += 1;
            break;
        }
    }
}

#pragma opt_propagation off


void func_0021F180()
{
    if (D_0028EB38 == 0) {
        s8 savedState = D_0028EB14;

        D_0028EB68 = 2;
        D_0028EB54 = 1;
        D_0028E320_as_u16 = 0xE10;
        D_0028EB58 = savedState;
        return;
    }
}

extern s8 D_00271690[];
extern s8 D_002716A0[];
extern s8 D_0068DD00[];

void func_0021F1C0(void) {
    extern void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel != 7 && !(sel > 7)) {
        max = D_00271690[sel];
        if (sel == 2 && D_0028E358 != 0) {
            max = D_002716A0[sel];
        }
        cur = D_0068DD00[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            D_0068DD00[D_0028EB58] = cur;
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            D_0068DD00[D_0028EB58] = cur;
        }
    }
}

extern u8 D_00271C60[];
extern u8 D_00271C64[];
extern s8 g_p1_btn_map_a_as_s8;
extern s8 g_p1_btn_map_b_as_s8;
extern s8 g_p1_btn_map_c_as_s8;
extern s8 D_0028E273_as_s8;
extern s8 g_p2_btn_map_a_as_s8;
extern s8 g_p2_btn_map_b_as_s8;
extern s8 g_p2_btn_map_c_as_s8;
extern s8 D_0028E277_as_s8;
extern s8 g_stage_map_enabled_as_s8;
extern s8 g_bgm_alternate_set_as_s8;
extern u16 D_0028E32C;
extern s8 g_display_reset_pending;
extern s8 D_0068DD02[];
extern s8 D_0068DD03_as_s8_a[];
extern s8 D_0068DD04_as_s8_a[];
extern s8 D_0068DD05_as_s8_a[];
extern s8 D_0068DD06_as_s8_a[];
extern s8 D_0068DD09[];
extern s8 D_0068DD0A[];
extern s8 D_0068DD0B[];
extern s8 D_0068DD0C_as_s8_a[];
extern s8 D_0068DD0D[];
extern s8 D_0068DD0E[];
extern s8 D_0068DD0F[];
extern s8 D_0068DD10_as_s8_a[];
void func_0021F2C0(void) {
    extern void wallpaper_load(s32, s32);
    s32 temp_a0;

    if (D_0028E358 != D_0068DD01[0]) {
        D_0028E354 = 0;
        g_display_reset_pending = 1;
        D_0068DD02[0] = 0;
    }
    if (D_0028E354 != D_0068DD02[0]) {
        D_0028E354 = (u8) D_0068DD02[0];
        if (D_0028E358 == 0) {
            D_0028E354 &= 3;
        } else {
            D_0028E354 &= 1;
        }
        D_0068DD02[0] = D_0028E354;
        g_display_reset_pending = 1;
    }
    if (g_screen_wide != D_0068DD03_as_s8_a[0]) {
        g_display_reset_pending = 1;
    }
    g_screen_wide = (u8) D_0068DD03_as_s8_a[0];
    g_bgm_alternate_set_as_s8 = D_0068DD06_as_s8_a[0];
    g_stage_map_enabled_as_s8 = D_0068DD05_as_s8_a[0];
    if (D_0028E32C != D_0068DD04_as_s8_a[0]) {
        D_0028E32C = (u16) (s8)(D_0068DD04_as_s8_a[0]);
        if (D_0028E32C != 5) {
            temp_a0 = (D_0028E32C & 0xFFFF) * 8;
            wallpaper_load(*(s32 *)(D_00271C60 + temp_a0), *(s32 *)(D_00271C64 + temp_a0));
        }
    }
    g_p1_btn_map_a_as_s8 = D_0068DD09[0];
    g_p1_btn_map_b_as_s8 = D_0068DD0A[0];
    g_p1_btn_map_c_as_s8 = D_0068DD0B[0];
    D_0028E273_as_s8 = D_0068DD0C_as_s8_a[0];
    g_p2_btn_map_a_as_s8 = D_0068DD0D[0];
    g_p2_btn_map_b_as_s8 = D_0068DD0E[0];
    g_p2_btn_map_c_as_s8 = D_0068DD0F[0];
    D_0028E277_as_s8 = D_0068DD10_as_s8_a[0];
}

#ifdef DEATH_LABEL
extern u8 death_D_00628F01[];
extern u8 death_D_00628F02[];
#endif

void func_0021F440(void) {
    if (D_0028E354 != 0) {
        g_display_reset_pending = 1;
    }
    D_0068DD01[0] = 0;
    D_0068DD02[0] = 0;
    D_0028E354 = 0;
    D_0068DD03_as_s8_a[0] = 0;
    D_0068DD04_as_s8_a[0] = 5;
    D_0068DD05_as_s8_a[0] = 1;
    D_0068DD06_as_s8_a[0] = 0;
    D_0068DD09[0] = 7;
    D_0068DD0D[0] = 7;
    D_0068DD0A[0] = 6;
    D_0068DD0E[0] = 6;
    D_0068DD0B[0] = 5;
    D_0068DD0F[0] = 5;
    D_0068DD0C_as_s8_a[0] = 1;
    D_0068DD10_as_s8_a[0] = 1;
#ifdef DEATH_LABEL
    death_D_00628F01[0] = 0;
    death_D_00628F02[0] = 0;
#endif
}

s32 func_00212580();

void func_0021F4E0(void) {
    switch (D_0028EB60) {                           /* irregular */
    case 0:
        func_0021F560(D_0028EB60);
        break;
    case 1:
        func_0021F5B0(D_0028EB60);
        break;
    case 2:
        func_0021F600(D_0028EB60);
        break;
    case 3:
#ifndef DEATH_LABEL
        func_0021F750(D_0028EB60);
#endif
        break;
    }
#ifdef DEATH_LABEL
    if (D_0028EB60 >= 0x40) {
        D_0028EB60++;
        if (D_0028EB60 >= 0x60) {
            func_00212580(2);
            printf("kidou\n");
        }
    }
#endif
}
#pragma pop

extern s8 D_0028EB30;
extern s32 D_0028EB98;

void func_0021F560() {
    D_0028EB98 = 0;
    D_0028EB60 += 1;
    func_00222340(0x15);
    D_0028EB90 = 0x40;
    D_0028EB0C = 0;
    D_0028EB30 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}

void func_0021F5B0() {
    if (func_00222530(0x15) != 0) {
        D_0028EB58 = 0;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB90 = 0x40;
        D_0028EB60++;
    }
}

extern s8 D_0028EAA8;
extern s8 D_0028EBC0;
void func_0021F600() {
    s32 sfx_menu_confirm();
    s32 sfx_menu_move();
    s32 fade_start_out();
    s32 selected;
    s32 choice;
    u32 buttons;

    buttons = g_pad_trigger[2];
    choice = D_0028EAE8;
    selected = 0;
    if ((buttons & 0x8000) && D_0028EB0C == 0) {
        D_0028EBC0 = 0;
        D_0028EB0C = 1;
        sfx_menu_move();
    } else if ((buttons & 0x2000) && D_0028EB0C == 1) {
        D_0028EBC0 = 0;
        D_0028EB0C = 0;
        sfx_menu_move();
    } else if (buttons & 0x20) {
        selected = 1;
        if (D_0028EB0C == 0) {
            choice = 3;
        }
    }
    if (selected != 0) {
        switch (choice) {
#ifdef DEATH_LABEL
        case 1:
            streams_stop();
            sfx_menu_confirm();
            D_0028EB60 = 0x40;
            fade_start_out();
            break;
#else
        case 1:
        case 2:
            D_0028EAA8 = choice;
            fade_start_out();
            sfx_menu_confirm();
            D_0028EB60 += 1;
            break;
#endif
        case 3:
            streams_stop();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB4C = 1;
            D_0028EB90 = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EB30 = 2;
            D_0028EB84 = 0;
            D_0028EB60 += 1;
            sfx_menu_confirm();
            break;
        }
    }
}

#ifndef DEATH_LABEL
s32 func_00212580(s32);                     /* extern */

void func_0021F750() {
    if (g_fade_state == 0) {
        switch (D_0028EAA8) {                       /* irregular */
        case 1:
            func_00212580(0);
            return;
        case 2:
            func_00212580(1);
            break;
        }
    }
}
#endif

#ifdef DEATH_LABEL
extern s8 death_D_00290048[3];
extern s8 death_D_00290C4C;
extern s8 death_D_00290C74;
extern s8 death_D_00290CA8;
extern s32 death_D_00290CE4;
extern s8 death_D_00628F00[];

void death_func_001B7460(void) {
    switch (death_D_00290CA8) {
    case 0:
        death_func_001B74D0();
        break;
    case 1:
        death_func_001B7520();
        break;
    case 2:
        death_func_001B7570();
        break;
    case 3:
        break;
    }
}

void death_func_001B74D0(void) {
    death_D_00290CE4 = 0;
    death_D_00290CA8++;
    func_00222340(0x17);
    D_0028EB90 = 0x40;
    death_D_00290C4C = 0;
    death_D_00290C74 = 1;
    D_0028EB04 = 1;
    D_0028E320_as_u16 = 0xE10;
}

void death_func_001B7520(void) {
    if (func_00222530(0x17) != 0) {
        death_D_00290CA8++;
        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
    }
}

void death_func_001B7570(void) {
    s32 sfx_menu_confirm();
    s32 var_a1;

    if (func_00221120(0x17) == 0) {
        death_func_001B76A0();
    }
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 3;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 3;
    } else if (g_pad_trigger[2] & 0x20) {
        var_a1 = 1;
    }
    death_D_00290C4C = D_0028EB58;
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 1:
        case 2:
            break;
        case 3:
            streams_stop();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB4C = 1;
            D_0028EB90 = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            death_D_00290C74 = 2;
            D_0028EB84 = 0;
            death_D_00290CA8++;
            sfx_menu_confirm();
            break;
        }
    }
}

void death_func_001B76A0(void) {
    void sfx_menu_tick(void);
    s32 sel;
    s32 cur;
    s32 max;
    s32 pad;

    sel = D_0028EB58;
    if (sel < 3) {
        max = death_D_00290048[sel];
        cur = death_D_00628F00[sel];
        pad = g_pad_repeat[2];
        if (pad & 0x2000) {
            sfx_menu_tick();
            cur++;
            if (cur >= max) {
                cur = 0;
            }
            death_D_00628F00[D_0028EB58] = cur;
        } else if (pad & 0x8000) {
            sfx_menu_tick();
            cur--;
            if (cur < 0) {
                cur = max - 1;
            }
            death_D_00628F00[D_0028EB58] = cur;
        }
    }
}
#endif


void func_0021F7B0(void) {
    switch (D_0028EB5C) {                           /* irregular */
    case 0:
        func_0021F820(D_0028EB5C);
        break;
    case 1:
        func_0021F880(D_0028EB5C);
        break;
    case 2:
        func_0021F8D0(D_0028EB5C);
        /* fallthrough */
    case 3:
        break;
    }
}

s32 func_001A3D30();                            /* extern */
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s32 D_0028EAF4;
extern s8 D_0028EB2C;
extern s32 D_0028EB94;

void func_0021F820() {
    D_0028EB94 = 0;
    D_0028EB5C += 1;
    func_00222340(0x18);
    D_0028EB90 = 0x40;
    D_0028EB2C = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
    D_0028EB08 = 0;
    D_0028EAF0 = 0;
    D_0028EAEC = 0;
    D_0028EAF4 = 0;
    func_001A3D30();
}

void func_0021F880() {
    if (func_00222530(0x18) != 0) {
        D_0028EB58 = 0;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB90 = 0x40;
        D_0028EB5C++;
    }
}

s32 func_0015BDD0();
s32 func_001A3E70();
extern s8 D_0028E294_as_s8;
void func_0021F8D0() {
    s32 sfx_menu_confirm();
    s32 var_s0;

    if (D_0028EAF0 == 0) {
        func_002212C0(0x18);
    }
    var_s0 = 0;
    D_0028E294_as_s8 = 1;
    func_001A3E70();
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_held[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_s0 = 1;
            D_0028EB58 = 5;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (g_pad_trigger[2] & 0x40) {
        var_s0 = 1;
        D_0028EB58 = 5;
    } else if (g_pad_trigger[2] & 0x20) {
        var_s0 = 1;
    }
    D_0028EB08 = D_0028EB58;
    if (var_s0 != 0) {
        switch (D_0028EB58) {
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            sfx_menu_confirm();
            if (D_0028EAF4 == 0) {
                D_0028EAEC = 0;
                D_0028EAF0 = 1;
                D_0028EAF4 = 1;
                break;
            }
            D_0028EAF4 = 0;
            D_0028EAF0 = 2;
            break;
        case 5:
            streams_stop();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB4C = 1;
            D_0028EB90 = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EB84 = 0;
            D_0028EB2C = 0;
            D_0028EB94 = 0;
            D_0028EAF0 = 0;
            D_0028EAEC = 0;
            D_0028EAF4 = 0;
            D_0028EB5C += 1;
            func_0015BDD0();
            sfx_menu_confirm();
            break;
        }
    }
}

extern void func_002278D0(void);
extern void func_00227B70(void);
extern void func_00227E00(void);
extern void func_002287E0(void);
extern void func_00228BC0(void);
extern void func_00229660(void);
extern void func_0022A0B0(void);
extern void func_0022A480(void);
#ifdef DEATH_LABEL
#endif

void func_0021FA50(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_flush(void);
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

    if (D_0028EB00 != 0) {
        if (D_0028EB84 == 0x10) {
            func_00225450();
            return;
        }
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
        if (D_0028EB94 == 0) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
            func_00221440();
        } else {
            func_00221360();
        }
        glyph_queue_clear();
        func_0021FC70();
        func_0021FDB0();
        func_002201A0();
        func_00220390();
        func_002207C0();
        func_002209C0();
        func_00221000();
#ifdef DEATH_LABEL
        death_func_001B9120();
#endif
        func_00221080();
        func_002278D0();
        func_00227B70();
        func_002287E0();
        func_00228BC0();
        func_00229660();
        func_0022A0B0();
        func_0022A480();
        func_00221E20();
        glyph_queue_flush();
        func_00227E00();
        func_00221550();
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
}

typedef struct {
    s32 x;
    s32 y;
    u8 pad08[0x24];
    s32 alpha;
    s32 z;
    s32 active;
} Label;

extern s8 D_002714F0[];
extern u8 *D_00271510[];
extern Label D_00685010_as_Label_a[];

void func_0021FC70(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 wide);
    s32 i;
    s32 count;
    Label *label;
    s32 x;
    s32 y;
    s32 z;

    count = D_002714F0[0];
    switch (D_0028EB4C) {
    case 0:
        break;
    case 1:
        D_0028EBB4 += 4;
        if (D_0028EBB4 >= 0x80) {
            D_0028EB4C = 0;
            D_0028EBB4 = 0x80;
        }
        break;
    case 2:
        D_0028EBB4 -= 4;
        if (D_0028EBB4 <= 0) {
            D_0028EBB4 = 0;
            D_0028EB4C = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        label = &D_00685010_as_Label_a[i];
        if (label->active != 0) {
            label->alpha = D_0028EBB4;
            reg_a0 = D_00271510[i];
            x = label->x;
            y = label->y;
            z = label->z;
            if (label->alpha != 0) {
                glyph_queue_add(x, y, z, 0, 0x80, label->alpha, 1);
            }
        }
    }
}

extern void text_queue_clear(void);
extern void text_flush(void);
extern s8 D_002714F1[];
extern u8 *D_00271540[];
extern u8 *D_00271640[];
extern u8 *D_00271650[];
extern u8 *D_00271670[][2];
extern s16 D_00271800[];
extern u8 *D_0028DD18[2];
extern u8 D_00685010[];
extern s8 D_0068DC10[];

void func_0021FDB0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    u8 *item;
    u8 **pair;

    count = D_002714F1[0];
    switch (D_0028EB48) {
    case 0:
        break;
    case 1:
        D_0028EBB0 += 4;
        if (D_0028EBB0 >= 0x80) {
            D_0028EB48 = 0;
            D_0028EBB0 = 0x80;
        }
        break;
    case 2:
        D_0028EBB0 -= 4;
        if (D_0028EBB0 <= 0) {
            D_0028EBB0 = 0;
            D_0028EB48 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3AC) = D_0028EBB0;
        reg_a0 = D_00271540[i];
        x = *(s32 *)(item + 0x380);
        alpha = *(s32 *)(item + 0x3AC);
        top = *(s32 *)(item + 0x384);
        z = *(s32 *)(item + 0x3B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x10 + i];
        if (i == 1) {
            reg_a0 = D_00271640[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 1) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = D_00271650[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 2) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            if (index == 3) {
                reg_a0 = D_00271670[index][0];
                glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            } else {
                pair = D_00271670[index];
                reg_a0 = pair[0];
                glyph_queue_add(x, y, z, 0, 0x80, alpha, 0);
                reg_a0 = pair[1];
                glyph_queue_add(x - 8, y, z, 0, 0x80, alpha, 0);
            }
            if (D_0028EB24 == 3) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = D_0028DD18[index];
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 4) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    text_flush();
}

extern s8 D_002714F2[];
extern u8 *D_00271560[];

void func_002201A0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = D_002714F2[0];
    switch (D_0028EB44) {
    case 0:
        break;
    case 1:
        D_0028EBAC += 4;
        if (D_0028EBAC >= 0x80) {
            D_0028EB44 = 0;
            D_0028EBAC = 0x80;
        }
        break;
    case 2:
        D_0028EBAC -= 4;
        if (D_0028EBAC <= 0) {
            D_0028EBAC = 0;
            D_0028EB44 = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x734) == 0) {
            continue;
        }
        *(s32 *)(item + 0x72C) = D_0028EBAC;
        reg_a0 = D_00271560[i];
        x = *(s32 *)(item + 0x700);
        alpha = *(s32 *)(item + 0x72C);
        top = *(s32 *)(item + 0x704);
        z = *(s32 *)(item + 0x730);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x20 + i];
        if (i == 3) {
            reg_a0 = D_0028DD18[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB20 == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}

extern s8 D_002714F3[];
extern u8 *D_00271580[];
extern u8 *D_00271598[];
extern u8 *D_0028DD28[2];
extern u8 *D_0028DD30[2];
extern u8 *D_0028DD38[2];
extern u8 *D_0028DD40[2];
#ifdef DEATH_LABEL
extern u8 *D_00270AB0[];
extern u8 *D_0028DD60[2];
#endif

void func_00220390(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    u8 *item;

    count = D_002714F3[0];
    switch (D_0028EB40) {
    case 0:
        break;
    case 1:
        D_0028EBA8 += 4;
        if (D_0028EBA8 >= 0x80) {
            D_0028EB40 = 0;
            D_0028EBA8 = 0x80;
        }
        break;
    case 2:
        D_0028EBA8 -= 4;
        if (D_0028EBA8 <= 0) {
            D_0028EBA8 = 0;
            D_0028EB40 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0xAB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0xAAC) = D_0028EBA8;
        reg_a0 = D_00271580[i];
        x = *(s32 *)(item + 0xA80);
        alpha = *(s32 *)(item + 0xAAC);
        top = *(s32 *)(item + 0xA84);
        z = *(s32 *)(item + 0xAB0);
        if (alpha == 0) {
            continue;
        }
        if (i == 1 && !(D_0028E300 & 1)) {
            reg_a0 = D_00271598[0];
        }
        if (i == 2 && !(D_0028E300 & 2)) {
            reg_a0 = D_00271598[0];
        }
        if (i == 3 && !(D_0028E300 & 4)) {
            reg_a0 = D_00271598[0];
        }
        if (i == 4 && !(D_0028E300 & 8)) {
            reg_a0 = D_00271598[0];
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x30 + i];
        if (i == 1 && (D_0028E300 & 1)) {
            reg_a0 = D_0028DD28[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2 && (D_0028E300 & 2)) {
            reg_a0 = D_0028DD30[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3 && (D_0028E300 & 4)) {
            reg_a0 = D_0028DD38[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4 && (D_0028E300 & 8)) {
            reg_a0 = D_0028DD40[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 4) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
#ifdef DEATH_LABEL
        if (i == 5) {
            reg_a0 = D_00270AB0[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 5) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 6) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
#endif
    }
    text_flush();
}

extern s8 D_002714FE[];
extern u8 *D_002715B0[];

void func_002207C0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = D_002714FE[0];
    switch (D_0028EB3C) {
    case 0:
        break;
    case 1:
        D_0028EBA4 += 4;
        if (D_0028EBA4 >= 0x80) {
            D_0028EB3C = 0;
            D_0028EBA4 = 0x80;
        }
        break;
    case 2:
        D_0028EBA4 -= 4;
        if (D_0028EBA4 <= 0) {
            D_0028EBA4 = 0;
            D_0028EB3C = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3134) == 0) {
            continue;
        }
        *(s32 *)(item + 0x312C) = D_0028EBA4;
        reg_a0 = D_002715B0[i];
        x = *(s32 *)(item + 0x3100);
        alpha = *(s32 *)(item + 0x312C);
        top = *(s32 *)(item + 0x3104);
        z = *(s32 *)(item + 0x3130);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xE0 + i];
        if (i == 4) {
            reg_a0 = D_0028DD18[index];
            glyph_queue_add(x, y + 32, z, 0, 0x80, alpha, 1);
            if (D_0028EB18 == 4) {
                func_00224BA0(x, y + 32, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}

#pragma push
#pragma opt_dead_assignments off
void text_queue_clear(void);
void text_flush(void);
extern s8 D_002714FF[];
extern u8 *D_002715D0[];
extern u8 *D_002716B0[];
extern u8 *D_002716C0[];
extern u16 D_00271A10[];
extern u8 *D_0028DD48[2];
extern u8 *D_0028DD50[2];
extern u8 *D_0028DD58[2];
extern u8 *D_0028DD60[2];
extern u8 *D_0028DD68[2];

void func_002209C0(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    void text_queue_glyph(s16 x, s16 y, u16 glyph, s32 w, s32 a4, s32 h, u16 attr, u16 z);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;
    u16 glyph;

    count = D_002714FF[0];
    switch (D_0028EB38) {
    case 0:
        break;
    case 1:
        D_0028EBA0 += 4;
        if (D_0028EBA0 >= 0x80) {
            D_0028EB38 = 0;
            D_0028EBA0 = 0x80;
        }
        break;
    case 2:
        D_0028EBA0 -= 4;
        if (D_0028EBA0 <= 0) {
            D_0028EBA0 = 0;
            D_0028EB38 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x34B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x34AC) = D_0028EBA0;
        reg_a0 = D_002715D0[i];
        x = *(s32 *)(item + 0x3480);
        alpha = *(s32 *)(item + 0x34AC);
        top = *(s32 *)(item + 0x3484);
        z = *(s32 *)(item + 0x34B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xF0 + i];
        if (i == 1) {
            reg_a0 = D_0028DD50[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            if (D_0028E358 == 0) {
                reg_a0 = D_002716B0[index];
            } else {
                reg_a0 = D_0028DD48[index];
            }
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            reg_a0 = D_0028DD58[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = D_002716C0[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 4) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 5) {
            reg_a0 = D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 5) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = D_0028DD68[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 6) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 9) {
            glyph = D_00271A10[D_0068DD09[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0D[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 10) {
            glyph = D_00271A10[D_0068DD0A[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0E[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 11) {
            glyph = D_00271A10[D_0068DD0B[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0F[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
    }
    text_flush();
}
#pragma pop

void func_00221000(void) {
    switch (D_0028EB30) {
    case 0:
        break;
    case 1:
        D_0028EB98 += 4;
        if (D_0028EB98 >= 0x80) {
            D_0028EB30 = 0;
            D_0028EB98 = 0x80;
        }
        break;
    case 2:
        D_0028EB98 -= 4;
        if (D_0028EB98 <= 0) {
            D_0028EB98 = 0;
            D_0028EB30 = 0;
        }
        break;
    }
}

#ifdef DEATH_LABEL
extern s8 death_D_00262EC7[];
extern u8 *death_D_00262FF0[];
extern u8 *death_D_002630C8[];
extern u8 *death_D_00290050[2];

void death_func_001B9120(void) {
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = death_D_00262EC7[0];
    switch (death_D_00290C74) {
    case 0:
        break;
    case 1:
        death_D_00290CE4 += 4;
        if (death_D_00290CE4 >= 0x80) {
            death_D_00290C74 = 0;
            death_D_00290CE4 = 0x80;
        }
        break;
    case 2:
        death_D_00290CE4 -= 4;
        if (death_D_00290CE4 <= 0) {
            death_D_00290CE4 = 0;
            death_D_00290C74 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x50B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x50AC) = death_D_00290CE4;
        reg_a0 = death_D_00262FF0[i];
        x = *(s32 *)(item + 0x5080);
        alpha = *(s32 *)(item + 0x50AC);
        top = *(s32 *)(item + 0x5084);
        z = *(s32 *)(item + 0x50B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x170 + i];
        if (i == 1) {
            reg_a0 = death_D_00290050[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = death_D_002630C8[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (death_D_00290C4C == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    text_flush();
}
#endif

s32 func_001A4140();
extern u8 D_0028E294;

void func_00221080(void) {
    switch (D_0028EB2C) {                           /* irregular */
    case 0:
        break;
    case 1:
        D_0028EB94 += 4;
        if (D_0028EB94 >= 0x80) {
            D_0028EB2C = 0;
            D_0028EB94 = 0x80;
        }
        break;
    case 2:
        D_0028EB94 -= 4;
        if (D_0028EB94 <= 0) {
            D_0028EB94 = 0;
            D_0028EB2C = 0;
        }
        break;
    }
    if (D_0028EB94 != 0) {
        D_0028E294 = 1;
        func_001A4140();
    }
}

extern s16 D_0068DEFA[];

s32 func_00221120(s32 page) {
    extern void sfx_menu_move(void);
    s32 port;
    s32 count;
    u32 pad;

    port = 2;
    switch (page) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 17:
    case 18:
        port = D_0028EC24;
        break;
    }
    count = D_002714F0[page];
    pad = g_pad_repeat[port];
    if (pad & 0x1000) {
        sfx_menu_move();
        D_0028EB58--;
        if (D_0028EB84 == 15 && D_0028EB58 == 8) {
            D_0028EB58--;
        }
        if (page == 18 && D_0068DEFA[0] == 0 && D_0028EB58 == 7) {
            D_0028EB58 = 6;
        }
        if (D_0028EB58 <= 0) {
            D_0028EB58 = count - 1;
        }
        return 1;
    }
    if (pad & 0x4000) {
        sfx_menu_move();
        D_0028EB58++;
        if (D_0028EB84 == 15 && D_0028EB58 == 8) {
            D_0028EB58++;
        }
        if (page == 18 && D_0068DEFA[0] == 0 && D_0028EB58 == 7) {
            D_0028EB58 = 8;
        }
        if (D_0028EB58 >= count) {
            D_0028EB58 = 1;
        }
        return 1;
    }
    return 0;
}

s32 sfx_menu_move();                            /* extern */

s32 func_002212C0() {
    if (g_pad_repeat[2] & 0x1000) {
        sfx_menu_move();
        D_0028EB58 -= 1;
        if (D_0028EB58 < 0) {
            D_0028EB58 = 4;
        }
        return 1;
    }
    if (g_pad_repeat[2] & 0x4000) {
        sfx_menu_move();
        D_0028EB58 += 1;
        if (D_0028EB58 >= 5) {
            D_0028EB58 = 0;
        }
        return 1;
    }
    return 0;
}

extern s16 D_002717E0[];

void func_00221360(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        D_0028EB50 += 4;
        if (D_0028EB50 >= 0x20) {
            D_0028EB54 = 0;
            D_0028EB50 = 0x20;
        }
        break;
    case 2:
        D_0028EB50 -= 4;
        if (D_0028EB50 <= 0) {
            D_0028EB50 = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    if (D_0028EB58 != -1) {
        x = D_002717E0[D_0028EB58 * 2];
        if (D_0028EB50 != 0) {
            gfx_draw_color_box(x - 8, 0, 0x48, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
        }
    }
}

extern s16 D_00271760[];
extern s16 D_002717A0_as_s16_a[];

void func_00221440(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 sel;
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        D_0028EB50 += 4;
        if (D_0028EB50 >= 0x40) {
            D_0028EB54 = 0;
            D_0028EB50 = 0x40;
        }
        break;
    case 2:
        D_0028EB50 -= 4;
        if (D_0028EB50 <= 0) {
            D_0028EB50 = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    sel = D_0028EB58;
    if (sel != -1) {
        if (D_0028EB84 == 0xF) {
            x = D_002717A0_as_s16_a[sel * 2];
        } else {
            x = D_00271760[sel * 2];
        }
        if (D_0028EB50 != 0 && sel != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
        }
    }
}

extern void frame_draw_left_panel(s32 level);
extern u8 *D_00270870[];
extern u8 *D_002708B0[];
extern u8 *D_002708F0[];
extern u8 *D_00270A00[];
extern u8 *D_00271320[];
extern s8 D_002714F9[];
extern s8 D_002714FA[];
extern u8 *D_00271A20[];
extern u8 *D_00271A50[];
extern u8 *D_00271A70[];
extern u8 *D_00271A90[];
extern u8 *D_00271AB0[];
extern u8 *D_00271AD0[];
extern u8 *D_00271B08[];
extern u8 *D_00271B18[];
extern u8 *D_0028DCE8[2];
extern u8 *D_0028DCF0[2];
extern u8 *D_0028DCFC;
extern u8 *D_0028DD00;
extern u8 *D_0028DD04;
extern u8 *D_0028DD08;
extern u8 *D_0028DD78[2];
extern u8 *D_0028DD80;
extern u8 *D_0028DD8C;
extern s32 D_0028EB8C;
extern u8 D_0028EBE8;
extern s8 D_0028EBEA;
extern s8 D_0028EBF2;
extern s8 D_0028EBFA;
extern s8 D_0028EC02;
extern s8 D_0028EC0A;
extern s8 D_0028EC12;
extern u8 D_0028EC3C_as_u8;
extern s32 D_0028EC7C;
#ifdef DEATH_LABEL
extern u8 *death_D_0028FFDC;
extern u8 *death_D_00290078[2];
extern u8 *death_D_00290080[2];
extern u8 *death_D_002634D0[];
extern s8 death_D_00290C4C;
#endif

void func_00221550(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s64 alpha;
    s32 item;
    u8 state;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        D_0028EB90 += 4;
        D_0028EB8C += 4;
        if (D_0028EB90 >= 0x80) {
            D_0028EB04 = 0;
            D_0028EB90 = 0x80;
#ifndef DEATH_LABEL
            D_0028EB8C = 0x80;
#endif
        }
        if (D_0028EB8C >= 0x80) {
            D_0028EB8C = 0x80;
        }
        break;
    case 2:
        D_0028EB90 -= 4;
        if (D_0028EB90 <= 0) {
            D_0028EB90 = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (D_0028EB84 == 0xD) {
        return;
    }
    if (D_0028EB90 != 0) {
        text_queue_clear();
        alpha = D_0028EB90;
        if (alpha >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(D_0028EB8C);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (D_0028EB84 == 0) {
            reg_a0 = D_00271A20[D_0028EB28];
            if (D_0028EB00 != 3) {
                if (D_0028EB7C != 4 || D_0028EC7C == 0) {
                    func_002228D0(0x36, 8);
                }
            }
        }
        if (D_0028EB84 == 1) {
            reg_a0 = D_00271A50[D_0028EB24];
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 2) {
            reg_a0 = D_00271A70[D_0028EB20];
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 3) {
            item = D_0028EB1C;
            reg_a0 = D_00271A90[item];
            if (item == 1 && !(D_0028E300 & 1)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            if (item == 2 && !(D_0028E300 & 2)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            if (item == 4 && !(D_0028E300 & 8)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            if (item == 5 && !(D_0028E300 & 0x10)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 0xE) {
            reg_a0 = D_00271AB0[D_0028EB18];
            if (D_0028EB6C != 4 || D_0028EC7C == 0) {
                func_002228D0(0x36, 8);
            }
        }
        if (D_0028EB84 == 0x15) {
            if (D_0028EB50 != 0) {
                gfx_draw_color_box(0xE0, 0, 0x6E, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
            }
            reg_a0 = MAIN_OR_DEATH_LABEL(D_00271B08, death_D_00290078)[D_0028EAE8];
            func_002228D0(0x36, 8);
            reg_a0 = MAIN_OR_DEATH_LABEL(D_00271B18, death_D_00290080)[D_0028EAE8];
            func_002228D0(0x136, 8);
            func_002242B0(0xC, 4);
        }
#ifdef DEATH_LABEL
        if (D_0028EB84 == 0x17) {
            reg_a0 = death_D_002634D0[death_D_00290C4C];
            func_002228D0(0x36, 8);
        }
#endif
        if (D_0028EB84 == 0x18) {
            reg_a0 = (u8 *)D_0028DD8C;
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 0xF) {
            reg_a0 = D_00271AD0[D_0028EB14];
            func_002228D0(0x36, 8);
            if (D_0028EB14 == 1) {
                reg_a0 = D_0028DD78[D_0068DD01[0]];
                func_002228D0(0x22, 8);
            }
        }
    }
    if (D_0028EB84 == 7) {
        reg_a0 = D_00270870[D_0028EC1A];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 8) {
        reg_a0 = D_002708B0[D_0028EC12];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x11) {
        reg_a0 = D_002708F0[D_0028EC0A];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x12) {
        reg_a0 = D_00270A00[D_0028EC02];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x13) {
        reg_a0 = D_00271320[D_0028EBFA];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 9) {
        reg_a0 = D_0028DCE8[(D_0028EBF2 == D_002714F9[0] - 1) ? 1 : 0];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0xA) {
        reg_a0 = D_0028DCF0[(D_0028EBEA == D_002714FA[0] - 1) ? 1 : 0];
        if (D_0028EBE8 >= 3) {
            func_002228D0(0x36, 8);
        }
    }
    if (D_0028EB84 == 0xB) {
        state = D_0028EC3C_as_u8;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(D_0028DCFC, death_D_0028FFDC);
            func_002228D0(0x36, 8);
        }
    }
    if (D_0028EB84 == 0x16) {
        reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(D_0028DD00, death_D_0028FFDC);
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x14) {
        state = D_0028EC3C_as_u8;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)D_0028DD04;
            func_002228D0(0x36, 8);
        }
    }
    if (D_0028EB84 == 0xD) {
        reg_a0 = (u8 *)D_0028DD08;
        func_002228D0(0x36, 8);
    }
    text_flush();
}

s32 sfx_menu_confirm(s32);                         /* extern */
extern s32 D_0028EAF8;

s32 func_00221C20(void) {
    s32 var_s0;

    var_s0 = 0;
    if (D_0028EAFC == 0xFF) {
        return 1;
    }
    switch (D_0028EAF8) {                           /* irregular */
    case 0:
        D_0028EAF0 = 1;
        D_0028EB58 = (s8) D_0028EAFC;
        D_0028EAF8 += 1;
        D_0028EAEC = 0;
        break;
    case 1:
        if ((D_0028EAF0 == 3) && (g_pad_trigger[2] & 0x20)) {
            sfx_menu_confirm(D_0028EAFC);
            D_0028EAF0 = 2;
            D_0028EAF8 += 1;
        }
        break;
    case 2:
        if (D_0028EAF0 == 0) {
            D_0028EAF8 = 0;
            var_s0 = 1;
        }
        break;
    }
    return var_s0;
}


void func_00221CF0(void) {
    s32 glyph_queue_clear();
    s32 glyph_queue_flush();
    u8 * spA0;
    u8 * spB0;
    u8 * spC0;
    u8 * spD0;
    u8 * spE0;
    u8 * spF0;
    u8 * temp_fp;
    u32 temp_s7;
    u32 temp_s6;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_s4;
    u32 temp_s5;

    if (D_0028EAF8 != 0) {
        temp_s7 = reg_d0.w;
        temp_s6 = reg_d1.w;
        temp_s0 = reg_d2.w;
        temp_s1 = reg_d3.w;
        temp_s2 = reg_d4.w;
        temp_s3 = reg_d5.w;
        temp_s4 = reg_d6.w;
        temp_s5 = reg_d7.w;
        spA0 = reg_a0;
        spB0 = reg_a1;
        spC0 = reg_a2;
        spD0 = reg_a3;
        spE0 = reg_a4;
        spF0 = reg_a5;
        temp_fp = reg_a6;
        glyph_queue_clear();
        func_00221E20();
        glyph_queue_flush();
        reg_d0.w = temp_s7;
        reg_d1.w = temp_s6;
        reg_d2.w = temp_s0;
        reg_d3.w = temp_s1;
        reg_d4.w = temp_s2;
        reg_d5.w = temp_s3;
        reg_d6.w = temp_s4;
        reg_d7.w = temp_s5;
        reg_a0 = spA0;
        reg_a1 = spB0;
        reg_a2 = spC0;
        reg_a3 = spD0;
        reg_a4 = spE0;
        reg_a5 = spF0;
        reg_a6 = temp_fp;
    }
}

extern void frame_draw_right_panel(s32 level);
extern char *D_0028DD90;
extern char D_002BB060_as_char_a[];
extern char D_002BB100_as_char_a[];
extern char *reg_a0_as_char_p;

void func_00221E20(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern s32 glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
    char buf[2];
    s32 alpha;
    s32 i;
    char *p;
    s32 y;

    switch (D_0028EAF0) {
    case 0:
    case 3:
        break;
    case 1:
        D_0028EAEC += 4;
        if (D_0028EAEC >= 0x80) {
            D_0028EAEC = 0x80;
            D_0028EAF0 = 3;
        }
        break;
    case 2:
        D_0028EAEC -= 4;
        if (D_0028EAEC <= 0) {
            D_0028EAEC = 0;
            D_0028EAF0 = 0;
        }
        break;
    }
    if (D_0028EAEC != 0) {
        text_queue_clear();
        alpha = D_0028EAEC;
        if (D_0028EAEC >= 0x60) {
            alpha = 0x60;
        }
        if (alpha != 0) {
            frame_draw_right_panel(D_0028EAEC);
            gfx_draw_color_box(0xEC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        reg_a0_as_char_p = (char *)D_0028DD90;
        func_00222C30(0x116, 8, D_0028EAEC);
        buf[1] = 0;
        i = 0;
        y = 0;
        p = MAIN_OR_DEATH_LABEL(D_002BB100_as_char_a, D_002BB060_as_char_a) + D_0028EB58 * 0x1E;
        do {
            reg_a0_as_char_p = buf;
            *reg_a0_as_char_p = *p++;
            glyph_queue_add(0x106, y + 0xE + (i / 5) * 5, 0x136, 0, 0x80, D_0028EAEC, 1);
            i++;
            y += 9;
        } while (i < 0x14);
    }
    text_flush();
}

extern s8 D_0028EB10;
extern s8 D_0028EB34;
extern s8 D_0028EB64;
extern s32 D_0028EB9C;
extern s32 D_0028EBB8;
extern u8 D_0028EBD8;
extern u8 D_0028EBE0;
extern u8 D_0028EBF0;
extern u8 D_0028EC00;
extern u8 D_0028EC08;
extern u8 D_0028EC10;
extern u8 D_0028EC18;
extern s8 D_0028EC20;

#ifdef DEATH_LABEL
extern s32 death_D_00290CE4;
extern s8 death_D_00290CA8;
extern s8 death_D_00290C74;
extern s8 death_D_00290C4C;
#endif

void func_00221FF0() {
    s32 func_002263C0();
    D_0028EBB8 = 0;
    D_0028EBB4 = 0;
    D_0028EBB0 = 0;
    D_0028EBAC = 0;
    D_0028EBA8 = 0;
    D_0028EBA4 = 0;
    D_0028EBA0 = 0;
    D_0028EB9C = 0;
    D_0028EB98 = 0;
#ifdef DEATH_LABEL
    death_D_00290CE4 = 0;
#endif
    D_0028EB94 = 0;
    D_0028EB90 = 0;
    D_0028EB8C = 0;
    D_0028EB84 = 0;
    D_0028EB80 = 0;
    D_0028EB7C = 0;
    D_0028EB78 = 0;
    D_0028EB74 = 0;
    D_0028EB70 = 0;
    D_0028EB6C = 0;
    D_0028EB68 = 0;
    D_0028EB64 = 0;
    D_0028EB60 = 0;
#ifdef DEATH_LABEL
    death_D_00290CA8 = 0;
#endif
    D_0028EB5C = 0;
    D_0028EB04 = 0;
    D_0028EB58 = 0;
    D_0028EB54 = 0;
    D_0028EB50 = 0;
    D_0028EB4C = 0;
    D_0028EB48 = 0;
    D_0028EB44 = 0;
    D_0028EB40 = 0;
    D_0028EB3C = 0;
    D_0028EB38 = 0;
    D_0028EB34 = 0;
    D_0028EB30 = 0;
#ifdef DEATH_LABEL
    death_D_00290C74 = 0;
#endif
    D_0028EB2C = 0;
    D_0028EB24 = 0;
    D_0028EB20 = 0;
    D_0028EB1C = 0;
    D_0028EB18 = 0;
    D_0028EB14 = 0;
    D_0028EB10 = 0;
    D_0028EB0C = 0;
#ifdef DEATH_LABEL
    death_D_00290C4C = 0;
#endif
    D_0028EB08 = 0;
    D_0028EAF4 = 0;
    D_0028EAF0 = 0;
    D_0028EAEC = 0;
    D_0028EC20 = 0;
    D_0028EB88 = 1;
    D_0028EB28 = 1;
    memset(&D_0028EC18, 0, 6);
    memset(&D_0028EC10, 0, 6);
    memset(&D_0028EC08, 0, 6);
    memset(&D_0028EC00, 0, 6);
    memset(&D_0028EBF0, 0, 6);
    memset(&D_0028EBE8, 0, 6);
    memset(&D_0028EBE0, 0, 6);
    memset(&D_0028EBD8, 0, 6);
    func_002263C0();
    D_0028E368_as_s8 = 0;
    D_0028EB00 = 1;
    func_00222170();
    func_0021E1A0();
}

extern Obj38 D_00685010_as_Obj38_a_a16[][16];
extern u8 D_0068DC10_as_u8_a_a16[][16];

void func_00222170(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            D_00685010_as_Obj38_a_a16[i][j].active = 0;
            D_0068DC10_as_u8_a_a16[i][j] = 0;
        }
    }
    for (j = 0; j < 16; j++) {
        D_00685010_as_Obj38_a_a16[12][j].active = 0;
    }
}

extern s16 D_00271760_as_s16_a_a2[][2];
extern s16 D_002717A0[][2];

void func_00222260(s32 group) {
    s32 i;
    s32 count;
    s32 x;
    s32 y;
    s32 id;

    id = group + 100;
    count = D_002714F0[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            x = D_002717A0[i][0];
            D_00685010_as_Obj38_a_a16[group][i].x = x;
            y = D_002717A0[i][1];
            D_00685010_as_Obj38_a_a16[group][i].y = y;
            D_00685010_as_Obj38_a_a16[group][i].x2 = x;
            D_00685010_as_Obj38_a_a16[group][i].y2 = y;
        } else {
            x = D_00271760_as_s16_a_a2[i][0];
            D_00685010_as_Obj38_a_a16[group][i].x = x;
            y = D_00271760_as_s16_a_a2[i][1];
            D_00685010_as_Obj38_a_a16[group][i].y = y;
            D_00685010_as_Obj38_a_a16[group][i].x2 = x;
            D_00685010_as_Obj38_a_a16[group][i].y2 = y;
        }
        D_00685010_as_Obj38_a_a16[group][i].unk2C = 0;
        D_00685010_as_Obj38_a_a16[group][i].timer = 0x3C;
        D_00685010_as_Obj38_a_a16[group][i].id = id;
        D_00685010_as_Obj38_a_a16[group][i].active = 1;
    }
}

#pragma push
#pragma divbyzerocheck on
typedef struct {
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 fx;
    s32 fy;
    s32 vx;
    s32 vy;
    s32 dx;
    s32 dy;
    s32 timer;
    s32 step;
    s32 id;
    s32 active;
} MoveItem;

typedef struct {
    s16 x;
    s16 y;
} Point16;

extern Point16 D_00271760_as_Point16_a[];
extern Point16 D_002717A0_as_Point16_a[];
extern s32 D_00271910[];
extern MoveItem D_00685010_as_MoveItem_a_a16[][16];

void func_00222340(s32 group) {
    s32 i;
    s32 count;
    s32 dx;
    s32 dy;
    s32 tag;

    tag = group + 100;
    count = D_002714F0[group];
    for (i = 0; i < count; i++) {
        if (group == 15) {
            D_00685010_as_MoveItem_a_a16[group][i].x0 = -D_002717A0_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y0 = D_002717A0_as_Point16_a[i].y;
            D_00685010_as_MoveItem_a_a16[group][i].x1 = D_002717A0_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y1 = D_002717A0_as_Point16_a[i].y;
        } else {
            D_00685010_as_MoveItem_a_a16[group][i].x0 = -D_00271760_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y0 = D_00271760_as_Point16_a[i].y;
            D_00685010_as_MoveItem_a_a16[group][i].x1 = D_00271760_as_Point16_a[i].x;
            D_00685010_as_MoveItem_a_a16[group][i].y1 = D_00271760_as_Point16_a[i].y;
        }
        D_00685010_as_MoveItem_a_a16[group][i].step = 0;
        D_00685010_as_MoveItem_a_a16[group][i].timer = 60;
        D_00685010_as_MoveItem_a_a16[group][i].id = tag;
        D_00685010_as_MoveItem_a_a16[group][i].active = 1;
        dx = D_00685010_as_MoveItem_a_a16[group][i].x1 - D_00685010_as_MoveItem_a_a16[group][i].x0;
        dy = D_00685010_as_MoveItem_a_a16[group][i].y1 - D_00685010_as_MoveItem_a_a16[group][i].y0;
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        D_00685010_as_MoveItem_a_a16[group][i].dx = 0;
        D_00685010_as_MoveItem_a_a16[group][i].dy = 0;
        if (dx != 0) {
            D_00685010_as_MoveItem_a_a16[group][i].dx = dx * 10000 / D_00271910[0];
        }
        if (dy != 0) {
            D_00685010_as_MoveItem_a_a16[group][i].dy = dy * 10000 / D_00271910[0];
        }
        D_00685010_as_MoveItem_a_a16[group][i].vx = D_00685010_as_MoveItem_a_a16[group][i].dx * 60;
        D_00685010_as_MoveItem_a_a16[group][i].vy = D_00685010_as_MoveItem_a_a16[group][i].dy * 60;
        D_00685010_as_MoveItem_a_a16[group][i].fx = D_00685010_as_MoveItem_a_a16[group][i].x0 * 10000;
        D_00685010_as_MoveItem_a_a16[group][i].fy = D_00685010_as_MoveItem_a_a16[group][i].y0 * 10000;
    }
}
#pragma pop

typedef struct {
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
    s32 posX;
    s32 posY;
    s32 speedX;
    s32 speedY;
    s32 accelX;
    s32 accelY;
    s32 delay;
    u8 pad[0xC];
} Mover;


s32 func_00222530(s32 group) {
    s32 i;
    s32 count;
    s32 done;
    Mover *m;
    s32 *delay;
    s32 off;
    s32 *target;
    s32 *cur;

    done = 0;
    count = D_002714F0[group];
    i = 0;
    if (i < count) {
        off = 0;
        do {
            m = (Mover *)(D_00685010 + group * 0x380 + off);
            delay = &m->delay;
            if (*delay != 0) {
                (*delay)--;
            }
            if (*delay <= 0) {
                done++;
                m->x = m->targetX;
                m->y = m->targetY;
            }
            cur = &m->x;
            target = &m->targetX;
            if (m->x != m->targetX) {
                if (m->x < m->targetX) {
                    *cur = m->posX / 10000;
                    m->posX += m->speedX;
                    m->speedX -= m->accelX;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->posX / 10000;
                    m->posX -= m->speedX;
                    m->speedX -= m->accelX;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            cur = &m->y;
            target = &m->targetY;
            if (m->y != m->targetY) {
                if (m->y < m->targetY) {
                    *cur = m->posY / 10000;
                    m->posY += m->speedY;
                    m->speedY -= m->accelY;
                    if (*cur > *target) {
                        *cur = *target;
                    }
                } else {
                    *cur = m->posY / 10000;
                    m->posY -= m->speedY;
                    m->speedY -= m->accelY;
                    if (*cur < *target) {
                        *cur = *target;
                    }
                }
            }
            i++;
            off += 0x38;
        } while (i < count);
    }
    return done == count;
}


void func_00222780(void) {
    extern void sfx_menu_confirm(void);
    s32 button;
    s32 slot;
    s32 sel;

    if (g_pad_trigger[0] != 0) {
        for (button = 0; button < 8; button++) {
            if (g_pad_trigger[0] & (1 << button)) {
                goto found1;
            }
        }
        goto next;
found1:
        sfx_menu_confirm();
        sel = D_0028EB14;
        for (slot = 9; slot < MAIN_OR_DEATH_LABEL(12, 13); slot++) {
            if (sel != slot && button == D_0068DC10[slot + 0xF0]) {
                D_0068DC10[slot + 0xF0] = D_0068DC10[sel + 0xF0];
            }
        }
        D_0068DD00[sel] = button;
    }
next:
    if (g_pad_trigger[1] != 0) {
        for (button = 0; button < 8; button++) {
            if (g_pad_trigger[1] & (1 << button)) {
                goto found2;
            }
        }
        return;
found2:
        sfx_menu_confirm();
        sel = D_0028EB14 + 4;
        for (slot = 13; slot < MAIN_OR_DEATH_LABEL(16, 17); slot++) {
            if (sel != slot && button == D_0068DC10[slot + 0xF0]) {
                D_0068DC10[slot + 0xF0] = D_0068DC10[sel + 0xF0];
            }
        }
        D_0068DD00[sel] = button;
    }
}

void text_queue_sjis(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
void text_queue_ascii(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
extern u16 g_game_frame;

void func_002228D0(s32 x, s32 y) {
    void text_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *(s8 *)reg_a0;
            reg_a0 += 1;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0x8F81:
            return;
        case 0x6781:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, D_0028EB90, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, D_0028EB90, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (g_game_frame >> 5) & 3; n > 0; n--) {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                text_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
                cy += 8;
            } else {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}

void func_00222C30(s32 x, s32 y, s32 attr) {
    void text_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *(s8 *)reg_a0;
            reg_a0 += 1;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0x8F81:
            return;
        case 0x6781:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (g_game_frame >> 5) & 3; n > 0; n--) {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                text_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 8;
            } else {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}

void overlay_queue_sjis(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
void overlay_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
void overlay_queue_ascii(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);

void func_00222F90(s32 x, s32 y, s32 attr) {
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *(s8 *)reg_a0;
            reg_a0 += 1;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0:
        case 0x8F81:
            return;
        case 0x6781:
            overlay_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            overlay_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            overlay_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            overlay_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, attr, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (g_game_frame >> 5) & 3; n > 0; n--) {
                overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                overlay_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 8;
            } else {
                overlay_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, attr, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}

extern u8 g_paused;

void func_002232F0(void) {
    extern void sfx_menu_confirm(void);
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

    if (g_paused != 0 && g_paused != 0x63) {
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
        switch (g_paused) {
        case 0:
            break;
        case 1:
            func_002234C0();
            break;
        case 2:
            sfx_menu_confirm();
            g_paused++;
            break;
        case 3:
            func_00223550();
            break;
        case 4:
            func_00223A60();
            break;
        case 5:
            func_00223AA0();
            break;
        case 0xB:
            func_00224CC0();
            break;
        case 0x63:
            break;
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
}

extern void streams_pause(void);
extern void vibration_stop_all(void);
extern void vibration_suspend(void);
extern u16 D_0028E324;
extern u16 D_0028E328;
extern u16 g_loop;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern u16 g_stage;
extern u8 D_0028EBBC;
extern s16 D_0028EBC8;
extern u8 D_0028EBCC;
extern u8 D_0028EBD0_as_u8;
extern u8 D_0028ED74;

void func_002234C0(void) {
    g_paused++;
    D_0028EBC8 = 0;
    D_0028EB90 = 0;
    D_0028EBD0_as_u8 = 1;
    D_0028EBCC = 1;
    D_0028EB04 = 1;
    D_0028EB8C = 0;
    D_0028E324 = MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0);
    D_0028E328 = g_stage;
    if (D_0028E328 == 0) {
        D_0028E328 = 1;
    }
    D_0028EBBC = 0x28;
    vibration_suspend();
    vibration_stop_all();
    streams_pause();
    if (D_0028ED74 == 1) {
        D_0028ED74 = 3;
    }
}

extern s8 D_0028EBC4;

typedef struct {
    s32 a;
    s32 b;
} Pair;

extern void func_002035F0(void);
extern void vibration_start_pad1(s32 a, s32 b);
extern void vibration_start_pad2(s32 a, s32 b);
extern Pair D_00271C60_as_Pair_a[];
extern u16 g_pause_player;
extern u8 D_0028E378;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif
extern u8 g_display_reset_pending_as_u8;
extern s8 D_0028EBBC_as_s8;
extern s8 D_0028EBD0;
s32 streams_resume();
s32 vibration_resume();
extern s8 g_pause_lock_timer_as_s8;
s32 func_00237670();
s32 func_002376F0();
extern u8 D_0028ED7C;
extern u8 g_simulation_active;
extern s16 D_00271C8C[];
extern s16 D_00271C90[];
extern s8 D_0028EBCC_as_s8;
extern u8 *D_00271B30[];
extern u8 *D_00271B60[];
extern u8 *D_00271B90[];
extern s32 sprintf(char *buf, const char *format, ...);
extern void text_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
extern char *g_pad_dma_buf;
extern u8 *D_00271BC8[];
extern u8 *D_00271BCC[];
extern u8 *D_00271BD0[];
extern u8 *D_00271BD4[];

void func_00223550(void) {
    extern void sfx_menu_confirm(void);
    extern void sfx_menu_tick(void);
    extern void wallpaper_load(s32 a, s32 b);
    u32 pad;

    if (D_0028EBBC_as_s8 != 0) {
        D_0028EBBC_as_s8--;
    }
    if (D_0028EBBC_as_s8 == 0 && (g_pad_trigger[g_pause_player] & 0x800)) {
        sfx_menu_confirm();
        g_paused++;
        return;
    }
    if (func_00223BE0() != 0) {
        return;
    }
    switch (D_0028EBD0) {
    case 1:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            D_0068DD02[0]--;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            g_display_reset_pending_as_u8 = 1;
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            D_0068DD02[0]++;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            g_display_reset_pending_as_u8 = 1;
        }
        break;
    case 2:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            g_pad_vib_enabled++;
            g_pad_vib_enabled &= 1;
            if (g_pad_vib_enabled != 0) {
                vibration_start_pad1(0x78, 0x14);
                vibration_start_pad2(0x78, 0x14);
            }
        }
        break;
    case 3:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            D_0028E32C--;
            if ((s16)D_0028E32C < 0) {
                D_0028E32C = 5;
            }
            if (D_0028E32C != 5) {
                wallpaper_load(D_00271C60_as_Pair_a[D_0028E32C].a, D_00271C60_as_Pair_a[D_0028E32C].b);
            }
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            D_0028E32C++;
            if (D_0028E32C > 5) {
                D_0028E32C = 0;
            }
            if (D_0028E32C != 5) {
                wallpaper_load(D_00271C60_as_Pair_a[D_0028E32C].a, D_00271C60_as_Pair_a[D_0028E32C].b);
            }
        }
        break;
    case 4:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            g_stage_map_enabled++;
            g_stage_map_enabled &= 1;
        }
        break;
    case 5:
        if (g_pad_trigger[g_pause_player] & 0x20) {
            sfx_menu_confirm();
            D_0028EB90 = 0x80;
            D_0028EAE4 = g_display_offset_x;
            g_paused = 0xB;
            D_0028EAE0 = g_display_offset_y;
        }
        break;
    case 6:
    case 7:
        if (g_pad_trigger[g_pause_player] & 0x20) {
            sfx_menu_confirm();
            D_0028EBC4 = 1;
            g_paused = 5;
        }
        break;
    case 8:
        if (g_pad_repeat[g_pause_player] & 0xA000) {
            sfx_menu_tick();
            D_0028E324++;
            D_0028E324 &= 1;
        }
        break;
    case 9:
        pad = g_pad_repeat[g_pause_player];
        if (pad & 0x8000) {
            sfx_menu_tick();
            D_0028E328--;
            if ((s32)D_0028E328 <= 0) {
                D_0028E328 = 5;
            }
        } else if (pad & 0x2000) {
            sfx_menu_tick();
            D_0028E328++;
            if (D_0028E328 > 5) {
                D_0028E328 = 1;
            }
        }
        if (D_0028E378 != 0xFF && (g_pad_trigger[g_pause_player] & 0x20)) {
            reg_d6.h[0] = 1;
            reg_d7.h[0] = D_0028E328;
            if (reg_d7.h[0] == 5) {
                reg_d7.h[0] = 0;
            }
            func_002035F0();
            g_paused = 0;
        }
        break;
    }
    MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0) = D_0028E324;
}

void func_00223A60(void) {
    g_paused = 0;
    streams_resume();
    g_pause_lock_timer_as_s8 = 0x3C;
    vibration_resume();
    if (D_0028ED74 == 3) {
        D_0028ED74 = 1;
    }
}

void func_00223AA0(void) {
    extern void sfx_menu_confirm(void);
    extern void sfx_menu_tick(void);
    u32 buttons;

    buttons = g_pad_trigger[g_pause_player];
    if (buttons & 0x20) {
        if (D_0028EBC4 == 0) {
            if (g_simulation_active == 0 && D_0028ED7C != 2) {
                func_00224A30();
            } else {
                sfx_menu_confirm();
                if (D_0028EBD0 == 7) {
                    func_002376F0();
                } else {
                    func_00224A90();
                    func_00237670();
                }
            }
        } else {
            sfx_menu_confirm();
            g_paused = 3;
        }
        return;
    }
    if (buttons & 0x40) {
        sfx_menu_confirm();
        g_paused = 3;
        return;
    }
    if ((buttons & 0x8000) && D_0028EBC4 == 1) {
        sfx_menu_tick();
        D_0028EBC0 = 0;
        D_0028EBC4 = 0;
        return;
    }
    if ((buttons & 0x2000) && D_0028EBC4 == 0) {
        sfx_menu_tick();
        D_0028EBC0 = 0;
        D_0028EBC4 = 1;
    }
}

s32 func_00223BE0(void) {
    s32 sfx_menu_move();
    s32 temp_s0;
    s32 temp_v1;
    s32 temp_v1_2;

    if (g_simulation_active == 0) { temp_s0 = 8; } else { temp_s0 = 8; }
    if (g_simulation_active == 0) {
        temp_v1 = g_pad_repeat[g_pause_player];
        if (temp_v1 & 0x1000) {
            sfx_menu_move();
            D_0028EBD0 -= 1;
            if (D_0028EBD0 == 6) {
                D_0028EBD0 -= 1;
            }
            if (D_0028EBD0 <= 0) {
                D_0028EBD0 = temp_s0 - 1;
            }
            return 1;
        }
        if (temp_v1 & 0x4000) {
            sfx_menu_move();
            D_0028EBD0 += 1;
            if (D_0028EBD0 == 6) {
                D_0028EBD0 += 1;
            }
            if (D_0028EBD0 >= temp_s0) {
                D_0028EBD0 = 1;
            }
            return 1;
        }
        goto block_21;
    }
    temp_v1_2 = g_pad_repeat[g_pause_player];
    if (temp_v1_2 & 0x1000) {
        sfx_menu_move();
        D_0028EBD0 -= 1;
        if (D_0028EBD0 <= 0) {
            D_0028EBD0 = temp_s0 - 1;
        }
        return 1;
    }
    if (temp_v1_2 & 0x4000) {
        sfx_menu_move();
        D_0028EBD0 += 1;
        if (D_0028EBD0 >= temp_s0) {
            D_0028EBD0 = 1;
        }
        return 1;
    }
block_21:
    return 0;
}

void func_00223D70(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EBCC_as_s8) {
    case 0:
        break;
    case 1:
        D_0028EBC8 += 4;
        if (D_0028EBC8 >= 0x40) {
            D_0028EBCC_as_s8 = 0;
            D_0028EBC8 = 0x40;
        }
        break;
    case 2:
        D_0028EBC8 -= 4;
        if (D_0028EBC8 <= 0) {
            D_0028EBC8 = 0;
            D_0028EBCC_as_s8 = 0;
        }
        break;
    }
    if (g_simulation_active == 0 && D_0028EBD0 > 6) {
        x = D_00271C8C[D_0028EBD0 * 2];
    } else {
        x = D_00271C90[D_0028EBD0 * 2];
    }
    if (D_0028EBC8 != 0) {
        gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EBC8, 0xB4, 1, 1);
    }
}

void func_00223E80(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s64 alpha;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        D_0028EB90 += 4;
        if (D_0028EB90 >= 0x80) {
            D_0028EB04 = 0;
            D_0028EB90 = 0x80;
        }
        break;
    case 2:
        D_0028EB90 -= 4;
        if (D_0028EB90 <= 0) {
            D_0028EB90 = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (D_0028EB90 != 0) {
        text_queue_clear();
        alpha = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(D_0028EB90);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (g_paused != 5) {
            if (D_0028ED7C == 2) {
                reg_a0 = D_00271B90[D_0028EBD0];
#ifndef DEATH_LABEL
            } else if (g_simulation_active != 0) {
                reg_a0 = D_00271B60[D_0028EBD0];
#endif
            } else {
                reg_a0 = D_00271B30[D_0028EBD0];
            }
            func_002228D0(0x36, 8);
        } else {
            func_00224020(0xC, 8);
        }
        text_flush();
    }
}

void func_00224020(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
    if (D_0028EBD0 == 6) {
        reg_a0 = D_00271BD0[0];
    } else if (D_0028ED7C == 2) {
        reg_a0 = D_00271BCC[0];
#ifndef DEATH_LABEL
    } else if (g_simulation_active != 0) {
        reg_a0 = D_00271BD4[0];
#endif
    } else {
        reg_a0 = D_00271BC8[0];
    }
    func_002228D0(x + 42, y);
    if (D_0028EBC4 == 0) {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py - shrink, px - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py, px + 75, g_pad_dma_buf, 0, 20, 16, 128, 300);
    } else {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py, px, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py - shrink, px + 75 - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
    }
}

void func_002242B0(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
    if (D_0028EB0C == 1) {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py - shrink, px - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py, px + 75, g_pad_dma_buf, 0, 20, 16, 128, 300);
    } else {
        sprintf(g_pad_dma_buf, "\x82\xCD\x82\xA2");
        text_queue_sjis_vertical(py, px, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x81\x5E");
        text_queue_sjis_vertical(py, px + 50, g_pad_dma_buf, 0, 20, 16, 128, 300);
        sprintf(g_pad_dma_buf, "\x82\xA2\x82\xA2\x82\xA6");
        text_queue_sjis_vertical(py - shrink, px + 75 - shrink, g_pad_dma_buf, 4, w, h, 128, 300);
    }
}

typedef struct {
    s16 x;
    s16 y;
} Point;

extern u8 *D_00271710[];
extern u8 *D_00271740[];
extern Point D_00271C90_as_Point_a[];

void func_002244E0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
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
    s32 x;
    s32 y;
    s32 n;

    if (g_paused != 0 && g_paused != 0x63) {
        if (g_paused == 0xB) {
            func_00225450();
            return;
        }
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
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
        func_00223D70();
        func_00223E80();
        glyph_queue_clear();
        x = D_00271C90_as_Point_a[0].x;
        y = D_00271C90_as_Point_a[0].y;
        reg_a0 = D_00271710[0];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        x = D_00271C90_as_Point_a[1].x;
        y = D_00271C90_as_Point_a[1].y;
        reg_a0 = D_00271710[1];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        if (D_0028E358 == 0) {
            reg_a0 = D_002716B0[D_0028E354];
        } else {
            reg_a0 = D_0028DD48[D_0028E354];
        }
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 1) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90_as_Point_a[2].x;
        y = D_00271C90_as_Point_a[2].y;
        reg_a0 = D_00271710[2];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = D_0028DD18[g_pad_vib_enabled];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 2) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90_as_Point_a[3].x;
        y = D_00271C90_as_Point_a[3].y;
        reg_a0 = D_00271710[3];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = D_00271740[D_0028E32C];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 3) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        x = D_00271C90_as_Point_a[4].x;
        y = D_00271C90_as_Point_a[4].y;
        reg_a0 = D_00271710[4];
        glyph_queue_add(x, y, 300, 0, 0x80, 0x80, 1);
        reg_a0 = D_0028DD18[g_stage_map_enabled];
        glyph_queue_add(x, y + 120, 300, 0, 0x80, 0x80, 1);
        if (D_0028EBD0 == 4) {
            func_00224BA0(x, y + 120, 300, 0, 0x80, 0x80, 1, 3);
        }
        reg_a0 = D_00271710[5];
        glyph_queue_add(D_00271C90_as_Point_a[5].x, D_00271C90_as_Point_a[5].y, 300, 0, 0x80, 0x80, 1);
        n = 6;
        if (g_simulation_active != 0) {
            n++;
            reg_a0 = D_00271710[6];
            glyph_queue_add(D_00271C90_as_Point_a[6].x, D_00271C90_as_Point_a[6].y, 300, 0, 0x80, 0x80, 1);
        }
        x = D_00271C90_as_Point_a[n].x;
        reg_a0 = D_00271710[7];
        glyph_queue_add(x, D_00271C90_as_Point_a[n].y, 300, 0, 0x80, 0x80, 1);
        glyph_queue_flush();
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
}

extern u16 D_0028E7BC;
extern void task_start(void);

void func_00224A30(void) {
    extern void sfx_menu_confirm(void);
    if (D_0028E7BC == 1 || D_0028E7BC == 0xF) {
        return;
    }
    func_00224A90();
    sfx_menu_confirm();
    reg_d0.h[0] = 8;
    task_start();
    *(u16 *)(reg_a0 + 4) = 0x12;
}

s32 layers_reset();
s32 func_0012FA50();
s32 func_0012FB00();
s32 func_0012FD00();
s32 func_0013B190();
s32 sound_stop_effects();
s32 music_stop();
s32 task_reset_all();
s32 stage_map_reset();
s32 replay_header_clear();
extern u8 D_0028E1DA[];
extern u8 D_0028E1E6[];
extern u8 D_0028E2A0;
extern s16 D_0028E324_as_s16;
extern u8 D_0028E368;
extern s16 D_0028E3A0;
extern s16 D_0028E3B4_as_s16;
extern s16 g_attract_demo_as_s16;
extern s16 g_loop_as_s16;
extern u8 D_0028EC4C;
extern u8 D_0028ED64;
extern u8 D_0028ED6C;
extern s32 D_0028ED70;

void func_00224A90(void) {
    sound_stop_effects();
    music_stop();
    func_0012FA50();
    func_0012FB00();
    layers_reset();
    g_attract_demo_as_s16 = 0;
    D_0028EAFC = 0xFF;
    D_0028E378 = 0xFF;
    g_paused = 0;
    D_0028E2A0 = 0;
    D_0028E368 = 0;
    func_00224B50();
    g_simulation_active = 0;
    replay_header_clear();
    D_0028ED7C = 0;
    D_0028ED74 = 0;
    D_0028EC4C = 0;
    D_0028ED6C = 0;
    D_0028ED64 = 0;
    D_0028ED70 = 0;
#ifndef DEATH_LABEL
    D_0028E3B4_as_s16 = 0;
#endif
    func_0012FD00();
    task_reset_all();
    func_0013B190();
    stage_map_reset();
    g_loop_as_s16 = 0;
    D_0028E1DA[0] = 0;
    D_0028E324_as_s16 = 0;
    D_0028E1E6[0] = 0;
    D_0028E3A0 = 0;
}

void func_00224B50(void) {
    D_0028E38C_as_s8 = D_0068DC21[0];
    D_0028E384_as_s8 = D_0068DC22[0];
    D_0028E388_as_s8 = D_0068DC23[0];
    D_0028E2EC_as_s8 = D_0068DC44[0];
    D_0028E304_as_s8 = D_0068DC41[0];
#ifndef DEATH_LABEL
    printf("restore com setting\n", D_0068DC23[0], D_0068DC22[0], D_0068DC21[0]);
#endif
}

extern u8 D_0028DDA4;
extern u8 D_0028DDA6;
extern s32 g_frame_counter;

void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags) {
    extern s32 glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    u8 *text;
    s32 level;
    s32 alpha;

    text = reg_a0;
    level = (g_frame_counter & 0x3F) * 2;
    if (level < 0x3F) {
        level = 0x80 - level;
    }
    alpha = (arg5 * level) >> 7;
    if (flags & 1) {
        reg_a0 = &D_0028DDA4;
        glyph_queue_add(arg0, arg1 - 8, arg2, arg3, arg4, alpha, arg6);
    }
    if (flags & 2) {
        reg_a0 = &D_0028DDA6;
        glyph_queue_add(arg0, arg1 + strlen((const char *)text) * 8, arg2, arg3, arg4, alpha, arg6);
    }
    reg_a0 = text;
}

s32 display_set_offset();
extern s8 g_paused_as_s8;
void func_00224CC0(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_tick();
    s32 temp_v1;

    temp_v1 = g_pad_trigger[g_pause_player];
    if (temp_v1 & 0x20) {
        sfx_menu_confirm();
        g_display_offset_x = D_0028EAE4;
        g_display_offset_y = D_0028EAE0;
        display_set_offset(g_display_offset_x, g_display_offset_y);
        D_0028EB90 = 0;
        g_paused_as_s8 = 3;
        D_0028EB04 = 1;
        return;
    }
    if (temp_v1 & 0x40) {
        sfx_menu_confirm();
        display_set_offset(g_display_offset_x, g_display_offset_y);
        D_0028EB90 = 0;
        g_paused_as_s8 = 3;
        D_0028EB04 = 1;
        return;
    }
    if (temp_v1 & 0x100) {
        sfx_menu_confirm();
        D_0028EAE4 = D_0028EAE0 = 0;
        display_set_offset(D_0028EAE4, D_0028EAE0);
    }
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if ((g_pad_repeat[g_pause_player] & 0x4000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x1000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x2000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x8000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
    } else {
        if ((g_pad_repeat[g_pause_player] & 0x4000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x1000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x2000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[g_pause_player] & 0x8000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
    }
    display_set_offset(D_0028EAE4, D_0028EAE0);
}

void func_00225000(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_tick();
    if (g_pad_trigger[2] & 0x20) {
        sfx_menu_confirm();
        g_display_offset_x = D_0028EAE4;
        g_display_offset_y = D_0028EAE0;
        display_set_offset(g_display_offset_x, g_display_offset_y);
        D_0028EB04 = 1;
        D_0028EB90 = 0;
        func_00222260(0xF);
        D_0028EB84 = 0xF;
        D_0028EB68 = 3;
        D_0028EB38 = 1;
        return;
    }
    if (g_pad_trigger[2] & 0x40) {
        sfx_menu_confirm();
        display_set_offset(g_display_offset_x, g_display_offset_y);
        D_0028EB04 = 1;
        D_0028EB90 = 0;
        func_00222260(0xF);
        D_0028EB84 = 0xF;
        D_0028EB68 = 3;
        D_0028EB38 = 1;
        return;
    }
    if (g_pad_trigger[2] & 0x100) {
        sfx_menu_confirm();
        D_0028EAE4 = D_0028EAE0 = 0;
        display_set_offset(D_0028EAE4, D_0028EAE0);
    }
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if ((g_pad_repeat[2] & 0x4000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
        if ((g_pad_repeat[2] & 0x1000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[2] & 0x2000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[2] & 0x8000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
    } else {
        if ((g_pad_repeat[2] & 0x4000) && (D_0028EAE0 < 8)) {
            sfx_menu_tick();
            D_0028EAE0 += 1;
        }
        if ((g_pad_repeat[2] & 0x1000) && (D_0028EAE0 > -8)) {
            sfx_menu_tick();
            D_0028EAE0 -= 1;
        }
        if ((g_pad_repeat[2] & 0x2000) && (D_0028EAE4 < 8)) {
            sfx_menu_tick();
            D_0028EAE4 += 1;
        }
        if ((g_pad_repeat[2] & 0x8000) && (D_0028EAE4 > -8)) {
            sfx_menu_tick();
            D_0028EAE4 -= 1;
        }
    }
    display_set_offset(D_0028EAE4, D_0028EAE0);
}

extern void *g_dma_gif;

void func_002252E0(void *buffer) {
    sceGifPacket packet;
    s32 i;
    u64 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 0, 1, 0x101, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, 0x80808080ULL | ((u64)0x3F800000 << 32));
    sceGifPkAddGsData(&packet, 1);
    sceGifPkAddGsData(&packet, 0x801CULL | ((u64)0x24000000 << 32));
    sceGifPkAddGsData(&packet, 0x55);
    for (i = 0; i < 0x1C0; i += 0x20) {
        x = (i + 0x700) << 4;
        sceGifPkAddGsData(&packet, x | 0x79000000);
        sceGifPkAddGsData(&packet, x | 0x87000000ULL);
    }
    for (i = 0; i < 0xE0; i += 0x10) {
        x = (u64)((i + 0x790) << 4) << 16;
        sceGifPkAddGsData(&packet, x | 0x7000);
        sceGifPkAddGsData(&packet, x | 0x8C00);
    }
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern void frame_draw_wide_left_panel(s32 alpha);
extern u8 D_00271BE0[];
extern u8 g_gif_buf_as_u8_a2_a0x10000[2][0x10000];

void func_00225450(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
    char buf[16];

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
    gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x60, 1, 1, 1);
    func_002252E0(g_gif_buf_as_u8_a2_a0x10000[0]);
    text_queue_clear();
    frame_draw_wide_left_panel(0x80);
    gfx_draw_color_box(0xC, 8, 0x70, 0xD0, 0x12C, 0x40, 1, 1, 0x40);
    reg_a0 = (u8 *)D_00271BE0;
    func_002228D0(0x62, 8);
    text_flush();
    sprintf(buf, "%3d,%d", D_0028EAE4, D_0028EAE0);
    reg_a0 = (u8 *)buf;
    glyph_queue_clear();
    glyph_queue_add(0xD8, 0x54, 0x12C, 0, 0x80, 0x80, 1);
    glyph_queue_flush();
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

extern s8 D_0028E374_as_s8;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 D_0028EC64;

void func_00225630(void) {
    D_0028EC64 = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    D_0028E374_as_s8 = 1;
    g_cd_async_busy = 1;
}


void func_00225670(void) {
    D_0028EC64 = 0;
    if (g_cd_async_state != 0) {
        sceCdBreak();
    }
    g_cd_async_state = 0;
    D_0028E374_as_s8 = 2;
    g_cd_async_busy = 1;
}

extern u8 D_0028EC64_as_u8;

void func_002256B0(void) {
    D_0028EC64_as_u8 = 3;
}

extern u8 *D_0028DD70;
extern u8 *D_0028DD74;
extern u8 D_0028E374;
extern s16 D_0028EC5C;
extern s8 D_0028EC60;

void func_002256C0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
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
    s32 x;
    s32 y;
    s32 alpha;

    if (D_0028E374 != 0) {
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
        switch (D_0028EC64) {
        case 0:
            D_0028EC5C = 0;
            D_0028EC64++;
            D_0028EC60 = 0;
        case 1:
            D_0028EC5C += 8;
            if (D_0028EC5C >= 0x80) {
                D_0028EC5C = 0x80;
                D_0028EC64++;
            }
            break;
        case 2:
            D_0028EC60++;
            if (D_0028EC60 >= 120) {
                D_0028EC60 = 0;
            }
            break;
        case 3:
            D_0028EC5C -= 8;
            if (D_0028EC5C <= 0) {
                D_0028EC5C = 0;
                D_0028EC64++;
            }
            break;
        case 4:
            D_0028E374 = 0;
            break;
        }
        alpha = D_0028EC5C;
        if (D_0028EC64 < 3 && D_0028E374 == 1) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x18F, 0x60, 1, 1, 1);
        }
        glyph_queue_clear();
        if (D_0028E374 == 1) {
            x = 32;
            y = 104;
        } else {
            x = 96;
            y = 72;
        }
        reg_a0 = (u8 *)D_0028DD70;
        glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        if (D_0028EC60 >= 30) {
            reg_a0 = (u8 *)D_0028DD74;
            y += 88;
            glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (D_0028EC60 >= 60) {
            reg_a0 = (u8 *)D_0028DD74;
            y += 8;
            glyph_queue_add(x, y, 400, 0, 0x80, alpha, 1);
        }
        if (D_0028EC60 >= 90) {
            reg_a0 = (u8 *)D_0028DD74;
            glyph_queue_add(x, y + 8, 400, 0, 0x80, alpha, 1);
        }
        glyph_queue_flush();
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
}

s32 func_0022C6A0();
s32 func_00235890();
extern s32 D_0028EAD4;
extern s32 D_0028ED0C;

void func_00225A00(void) {
    switch (D_0028EC6C) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_0028EAD4 = 0;
        D_0028EC6C += 1;
        D_0028ED0C = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (D_0028EAD4) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_0022C6A0(0);
            if (D_0028ED0C != 0) {
                func_00235890();
                D_0028EAD4 += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            D_0028ED0C = 0;
            D_0028EC6C += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        D_0028EB84 = 2;
        break;
    }
}

s32 func_0022C6D0();
s32 func_00234EF0();
extern s32 D_0028EAD0;
extern s32 D_0028ECC4;

void func_00225AB0(void) {
    switch (D_0028EC68) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_0028EAD0 = 0;
        D_0028EC68 += 1;
        D_0028ED0C = 0;
        /* fallthrough */
    case 1:                                         /* switch 1 */
        switch (D_0028EAD0) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_0022C6D0(0);
            if (D_0028ED0C != 0) {
                D_0028EAD0 += 1;
                break;
            }
            break;
        case 1:                                     /* switch 2 */
            D_0028ED0C = 0;
            if (D_0028ECC4 != 0) {
                func_00234EF0(D_0028EAD0);
                func_00235890();
            }
            D_0028EC68 += 1;
            break;
        }
        break;
    default:                                        /* switch 1 */
        D_0028EB84 = 2;
        break;
    }
}

extern s32 D_0028EAC0;
extern s32 D_0028EAC4;
extern s8 D_0028EACC;


void func_00225B70(void) {
    extern void func_002263C0(void);
    D_0028EAC4 = 0;
    D_0028EACC = 1;
    D_0028EAC0 = 1;
    D_0028EB04 = 1;
    D_0028EB90 = 0;
    D_0028EB8C = 0;
    func_002263C0();
}

extern s8 D_0028EAC8;
void func_00225B90(void) {
    s32 sfx_menu_confirm();
    s32 sfx_menu_move();
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;

    temp_a1 = D_0028EC24 * 4;
    temp_a0 = *(u32 *)((u8 *)g_pad_trigger + temp_a1);
    if (temp_a0 & 0x40) {
        D_0028EAC0 = 2;
        D_0028EB04 = 2;
        D_0028EAC8 = 2;
        D_0028EACC += 1;
        sfx_menu_confirm();
        return;
    }
    if (temp_a0 & 0x20) {
        D_0028EAC0 = 2;
        sfx_menu_confirm();
        if (D_0028EAC8 == 3) {
            D_0028EACC = 0x40;
            return;
        }
        D_0028EB04 = 2;
        D_0028EACC += 1;
        return;
    }
    temp_a0_2 = *(u32 *)((u8 *)g_pad_repeat + temp_a1);
    if (temp_a0_2 & 0x1000) {
        sfx_menu_move();
        D_0028EAC8 -= 1;
        if (0 >= D_0028EAC8) {
            D_0028EAC8 = 2;
        }
    } else if (temp_a0_2 & 0x4000) {
        sfx_menu_move();
        D_0028EAC8 += 1;
        if (D_0028EAC8 >= 3) {
            D_0028EAC8 = 1;
        }
    }
}

void func_00225CB0(void) {
    if (D_0028EAC4 == 0) {
        D_0028EACC += 1;
    }
}

s32 func_00226260();
s32 func_002263D0();
s32 func_0022A870();

s8 func_00225CD0(void) {
    s32 func_002263C0();
    s8 var_s0;

    var_s0 = 0;
    switch (D_0028EACC) {
    default:
        if (D_0028EACC != 0) {
            D_0028EACC += 1;
        }
        break;
    case 0x1:
        func_00225B90();
        break;
    case 0x2:
        var_s0 = D_0028EAC8;
        D_0028EACC += 1;
        break;
    case 0x3:
        func_00225CB0();
        break;
    case 0x20:
        D_0028EACC = 0;
        break;
    case 0x40:
        func_002263D0(1, D_0028EC24, 0);
        D_0028EACC += 1;
        break;
    case 0x41:
        switch (func_00226260()) {
        case 0:
            D_0028EACC = 1;
            D_0028EAC0 = 1;
            break;
        }
        break;
    case 0x50:
        func_0022A870();
        break;
    case 0x51:
        D_0028EAC4 = 0;
        D_0028EACC = 1;
        D_0028EAC0 = 1;
        D_0028EB04 = 1;
        D_0028EB90 = 0;
        D_0028EB8C = 0;
        func_002263C0();
        break;
    }
    return var_s0;
}

extern s16 D_00271CE0[];

void func_00225E20(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EAC0) {
    case 0:
        break;
    case 1:
        D_0028EAC4 += 4;
        if (D_0028EAC4 >= 0x40) {
            D_0028EAC0 = 0;
            D_0028EAC4 = 0x3C;
        }
        break;
    case 2:
        D_0028EAC4 -= 4;
        if (0 >= D_0028EAC4) {
            D_0028EAC4 = 0;
            D_0028EAC0 = 0;
        }
        break;
    }
    x = D_00271CE0[D_0028EAC8 * 2];
    if (D_0028EAC4 != 0) {
        gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EAC4, 0xB4, 1, 1);
    }
}

extern void func_00227000(void);
extern void func_0022AA20(void);
extern u8 *D_00271CC0[];
extern Point D_00271CE0_as_Point_a[];

void func_00225EF0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_clear(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void glyph_queue_flush(void);
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
    s32 alpha;
    s32 i;

    if (D_0028EACC != 0) {
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
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x20, 1, 1, 1);
        if (D_0028EACC == 0x50 || D_0028EACC == 0x51) {
            func_0022AA20();
        } else {
            func_00225E20();
            func_002260F0();
            func_00227000();
            glyph_queue_clear();
            alpha = D_0028EAC4 * 2;
            for (i = 0; i < 3; i++) {
                reg_a0 = D_00271CC0[i];
                glyph_queue_add(D_00271CE0_as_Point_a[i].x, D_00271CE0_as_Point_a[i].y, 0x12C, 0, 0x80, alpha, 1);
            }
            glyph_queue_flush();
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
}

extern u8 *D_00271CD0[];
extern u8 *D_0028DDA8;

void func_002260F0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    s32 alpha;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        D_0028EB90 += 4;
        if (D_0028EB90 >= 0x80) {
            D_0028EB04 = 0;
            D_0028EB90 = 0x80;
        }
        break;
    case 2:
        D_0028EB90 -= 4;
        if (D_0028EB90 <= 0) {
            D_0028EB90 = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (D_0028EB90 != 0) {
        text_queue_clear();
        alpha = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(D_0028EB90);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (D_0028EACC >= 0x40) {
            if (D_0028EC3C_as_u8 != 0 && (u32)(D_0028EC3C_as_u8 - 1) > 1 && (u32)(D_0028EC3C_as_u8 - 5) > 1) {
                reg_a0 = (u8 *)D_0028DDA8;
                func_002228D0(0x36, 8);
            }
        } else {
            reg_a0 = D_00271CD0[D_0028EAC8];
            func_002228D0(0x36, 8);
        }
        text_flush();
    }
}

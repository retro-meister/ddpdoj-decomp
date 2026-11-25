#include "common.h"
void func_0012FE80(void);
void func_0012FEE0(void);
void func_0012FF50(u8 arg0);
void func_0012FFC0();
void func_0012FFD0();
void func_00130250(void);
void func_00130260(void);
void func_00130280(void);
void func_001303B0(void);
void func_001305C0(void);
void func_001305D0(void);
void func_00130720(void);
void func_00130DE0(void);

extern u8 D_0024F340[];
extern u8 D_0024F360[];
extern s8 D_0028E1D0_as_s8;
extern s8 D_0028E1D4_as_s8;
extern s8 D_0028E1D8_as_s8_a[];
extern s8 D_0028E1DA_as_s8_a[];
extern s8 D_0028E1DC_as_s8;
extern s8 D_0028E1E0_as_s8;
extern s8 D_0028E1E4_as_s8_a[];
extern s8 D_0028E1E6_as_s8_a[];
extern s8 D_0028E1E8_as_s8;
extern s8 D_0028E1EC_as_s8;
extern s16 D_0028E1F0_as_s16;
extern s16 D_0028E1F4_as_s16;
extern s16 D_0028E1F8_as_s16;
extern s8 D_0028E1FC;
extern s8 D_0028E200;
extern s8 D_0028E204_as_s8;
extern s8 D_0028E208_as_s8;
extern s8 D_0028E20C_as_s8;
extern s8 D_0028E210_as_s8;
extern s16 D_0028E214;
extern u8 g_setting_coin_mode;

void func_0012FD40(void) {
    s8 temp_v1;

    reg_a0 = D_0024F340;
    reg_d0.w = 0;
    D_0028E1E4_as_s8_a[0] = 0;
    D_0028E1E6_as_s8_a[0] = 0;
    reg_d0.b[0] = g_setting_coin_mode;
    D_0028E1D8_as_s8_a[0] = 0;
    D_0028E214 = 0;
    D_0028E210_as_s8 = 0;
    D_0028E20C_as_s8 = 0;
    D_0028E208_as_s8 = 0;
    D_0028E204_as_s8 = 0;
    D_0028E200 = 0;
    D_0028E1FC = 0;
    D_0028E1F8_as_s16 = 0;
    D_0028E1F4_as_s16 = 0;
    D_0028E1F0_as_s16 = 0;
    D_0028E1E0_as_s8 = 0;
    D_0028E1DC_as_s8 = 0;
    D_0028E1DA_as_s8_a[0] = 0;
    D_0028E1D4_as_s8 = 0;
    D_0028E1D0_as_s8 = 0;
    temp_v1 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    reg_a0 = D_0024F360;
    D_0028E1EC_as_s8 = temp_v1;
    D_0028E1E8_as_s8 = *(s8 *)(reg_a0 + reg_d0.h[0]);
    func_00130250();
    func_00130260();
    func_00130720();
}

extern u8 D_0028E1E0;
extern u8 D_0028E1E4[];

void func_0012FE10(void) {
    if (reg_d0.h[0] != 0) {
        func_0012FEE0();
        return;
    }
    reg_d0.b[0] = D_0028E1E4[0];
    reg_d1.b[0] = D_0028E1E0;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FE80();
        return;
    }
    D_0028E1E0 = reg_d0.b[0];
    func_0012FFC0();
}

extern u8 D_0028E1DC;
extern u8 D_0028E1E6[];

void func_0012FE80(void) {
    reg_d0.b[0] = D_0028E1E6[0];
    reg_d1.b[0] = D_0028E1DC;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FFD0();
        return;
    }
    D_0028E1DC = reg_d0.b[0];
    func_0012FFC0();
}

extern u8 D_0028E1D4;
extern u8 D_0028E1D8[];
extern u8 g_setting_chute_type;

void func_0012FEE0(void) {
    extern void func_0012FFC0(u8);
    reg_d0.b[0] = D_0028E1E4[0];
    if (g_setting_chute_type == 1) {
        reg_d0.b[0] = D_0028E1D8[0];
    }
    reg_d1.b[0] = D_0028E1D4;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FF50(D_0028E1E4[0]);
        return;
    }
    D_0028E1D4 = reg_d0.b[0];
    func_0012FFC0(D_0028E1E4[0]);
}

extern u8 D_0028E1D0;
extern u8 D_0028E1DA[];

void func_0012FF50(u8 arg0) {
    extern void func_0012FFD0(u8);
    extern void func_0012FFC0(u8);
    reg_d0.b[0] = D_0028E1E6[0];
    if (g_setting_chute_type == 1) {
        reg_d0.b[0] = D_0028E1DA[0];
    }
    reg_d1.b[0] = D_0028E1D0;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FFD0(D_0028E1E6[0]);
        return;
    }
    D_0028E1D0 = reg_d0.b[0];
    func_0012FFC0(D_0028E1E6[0]);
}


void func_0012FFC0() {
    (*(u8 *)&cond_flag) = 1;
}

void func_0012FFD0() {
    (*(u8 *)&cond_flag) = 0;
}

extern u8 D_0028E1EC;

void func_0012FFE0(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
    } else if (reg_d0.b[0] == 0x11) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.b[0] = D_0028E1E4[1];
        reg_d1.b[0] = D_0028E1E4[0];
    } else {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.b[0] = D_0028E1EC;
        reg_d1.b[0] = D_0028E1E4[0];
    }
}

extern u8 D_0028E1D9[];

void func_00130050(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        if (g_setting_chute_type != 1) {
            reg_d0.b[0] = D_0028E1D9[0];
            reg_d1.b[0] = D_0028E1E4[0];
            return;
        }
        reg_d0.b[0] = D_0028E1D9[0];
        reg_d1.b[0] = D_0028E1D8[0];
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    if (g_setting_chute_type != 1) {
        reg_d0.b[0] = D_0028E1EC;
        reg_d1.b[0] = D_0028E1E4[0];
        return;
    }
    reg_d0.b[0] = D_0028E1EC;
    reg_d1.b[0] = D_0028E1D8[0];
}

extern u8 D_0028E1FC_as_u8;
extern u8 D_0028E200_as_u8;
extern u8 D_0028E204;
extern u8 D_0028E208;

void func_00130110(void) {
    reg_d0.w = 0;
    if (D_0028E208 != 0) {
        D_0028E208 -= 1;
        reg_d0.h[0] |= 1;
    }
    if (D_0028E204 != 0) {
        D_0028E204 -= 1;
        reg_d0.h[0] |= 2;
    }
    if (D_0028E200_as_u8 != 0) {
        D_0028E200_as_u8 -= 1;
        reg_d0.h[0] |= 4;
    }
    if (D_0028E1FC_as_u8 != 0) {
        D_0028E1FC_as_u8 -= 1;
        reg_d0.h[0] |= 8;
    }
    if (reg_d0.h[0] != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

void func_001301B0(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = D_0028E1E6[0];
    reg_d1.b[0] = D_0028E1DA[0];
}

void func_00130200(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = D_0028E1E4[0];
    reg_d1.b[0] = D_0028E1D8[0];
}

extern u8 D_0028E1E5[];

void func_00130250(void) {
    D_0028E1E5[0] = 2;
}

void func_00130260(void) {
    D_0028E1D9[0] = 2;
}


void func_00130270(void) {
    reg_d3.sw = 1;
    func_00130280();
}

s32 func_00131340();
s32 func_001313A0();

void func_00130280(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        func_001305C0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_00130200();
        reg_d2.w = 0;
        reg_d2.b[0] = D_0028E1E5[0];
        if ((s16)(reg_d2.h[0]) > (s16) reg_d0.h[0]) {
            func_001305D0();
            return;
        }
        if (reg_d3.h[0] == 0) {
            func_001305C0();
            return;
        }
        reg_d0.h[0] = reg_d2.h[0];
        D_0028E1E5[0] = 1;
        func_001313A0();
        func_001305C0();
        return;
    }
    func_001301B0();
    if (reg_d0.h[0] == 0) {
        func_001305D0();
        return;
    }
    if (reg_d3.h[0] == 0) {
        func_001305C0();
        return;
    }
    func_00131340();
    func_001305C0();
}


void func_001303A0(void) {
    reg_d3.sw = 1;
    func_001303B0();
}

s32 func_00131370();
s32 func_001313E0();

void func_001303B0(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        func_001305C0();
        return;
    }
    reg_d1.b[0] = g_setting_chute_type;
    if (reg_d1.b[0] != 1) {
        if (reg_d0.b[0] == 0x11) {
            func_00130200();
            reg_d2.w = 0;
            reg_d2.b[0] = D_0028E1D9[0];
            if ((s16)(reg_d2.h[0]) > (s16) reg_d0.h[0]) {
                func_001305D0();
                return;
            }
            if (reg_d3.h[0] == 0) {
                func_001305C0();
                return;
            }
            reg_d0.h[0] = reg_d2.h[0];
            D_0028E1D9[0] = 1;
            func_001313A0();
            func_001305C0();
            return;
        }
        func_001301B0();
        if (reg_d0.h[0] == 0) {
            func_001305D0();
            return;
        }
        if (reg_d3.h[0] == 0) {
            func_001305C0();
            return;
        }
        func_00131340();
        func_001305C0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_00130200();
        reg_d2.w = 0;
        reg_d2.b[0] = D_0028E1D9[0];
        if ((s16)(reg_d2.h[0]) > (s16) reg_d1.h[0]) {
            func_001305D0();
            return;
        }
        if (reg_d3.h[0] == 0) {
            func_001305C0();
            return;
        }
        reg_d0.h[0] = reg_d2.h[0];
        D_0028E1D9[0] = 1;
        func_001313E0();
        func_001305C0();
        return;
    }
    func_001301B0();
    if (reg_d1.h[0] == 0) {
        func_001305D0();
        return;
    }
    if (reg_d3.h[0] == 0) {
        func_001305C0();
        return;
    }
    func_00131370();
    func_001305C0();
}

void func_001305C0(void) {
    (*(u8 *)&cond_flag) = 0;
}

void func_001305D0(void) {
    (*(u8 *)&cond_flag) = 1;
}

extern u8 D_0028E1E8;

void func_001305E0(void) {
    u32 s0;
    u32 s1;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    reg_d0.b[0] = *(s8 *)(reg_a0 + 2);
    if (reg_d0.b[0] == 9) goto block_end;
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) goto block_end;
    if (reg_d0.b[0] == 0x11) {
        *(s8 *)(reg_a0 + 0) += 1;
        if (*(s8 *)(reg_a0 + 0) > 9) {
            *(s8 *)(reg_a0 + 0) = 9;
        }
    }
    if ((s8)reg_d0.b[0] >= 9 && (s8)reg_d0.b[0] < 0x11) {
        *(s8 *)(reg_a0 + 0) += 1;
        reg_d1.b[0] = D_0028E1EC;
        if (*(s8 *)(reg_a0 + 0) == reg_d1.b[0]) {
            *(s8 *)(reg_a0 + 0) = 0;
            *(s8 *)(reg_a0 + 2) += 1;
            if (*(s8 *)(reg_a0 + 2) > 9) {
                *(s8 *)(reg_a0 + 2) = 9;
            }
        }
    }
    if (0 <= (s8)reg_d0.b[0] && (s8)reg_d0.b[0] < 9) {
        reg_d1.b[0] = D_0028E1E8;
        *(s8 *)(reg_a0 + 2) += (s8)reg_d1.b[0];
        if (*(s8 *)(reg_a0 + 2) > 9) {
            *(s8 *)(reg_a0 + 2) = 9;
        }
    }
block_end:
    reg_d1.w = s1;
    reg_d0.w = s0;
}

extern u8 D_0028E1C0[];
extern u8 D_0028E1C8[];

void func_00130720(void) {
    reg_a0 = D_0028E1C8;
    reg_d0.w = 1;
    do {
        *(s8 *)(reg_a0 + 1) = 0;
        *(s8 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 2) = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        reg_a0 = D_0028E1C0;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u8 g_arcade_coin_port;
extern u8 g_stage_load_state;

void func_00130790(void) {
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 v;
    u16 c;
    u32 count;

    if (g_stage_load_state != 0) return;
    if (g_setting_coin_mode == 0x12) return;
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
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028E1C8;
    reg_d7.w = 1;
    reg_d0.h[0] = ~(s16)reg_d0.h[0];
loop_1:
    v = *(u8 *)(reg_a0 + 1);
    if (v != 0) goto next_2;
    if ((reg_d0.w & 1) == 0) goto next_5;
    *(u8 *)(reg_a0 + 1) = 1;
    *(s16 *)(reg_a0 + 4) = 0;
    *(u16 *)(reg_a0 + 2) = 1;
    goto next_5;
next_2:
    if (v != 1) goto next_3;
    if ((reg_d0.w & 1) == 0) goto block_1;
    c = *(u16 *)(reg_a0 + 2);
    if (c == 0xFFFF) goto next_5;
    *(u16 *)(reg_a0 + 2) = c + 1;
    goto next_5;
block_1:
    *(u8 *)(reg_a0 + 1) = 2;
    goto next_5;
next_3:
    if (v != 2) goto next_5;
    if (reg_d0.w & 1) goto block_3;
    *(u8 *)(reg_a0 + 1) = 0;
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    *(u16 *)(reg_a0 + 2) = 0;
    if ((s16)reg_d1.h[0] < 3) goto block_2;
    if ((s16)reg_d1.h[0] >= 0x27) goto block_2;
    *(s16 *)(reg_a0 + 4) = 0x80;
    goto next_5;
block_2:
    *(s16 *)(reg_a0 + 4) = 1;
    goto next_5;
block_3:
    *(u8 *)(reg_a0 + 1) = 1;
next_5:
    if (reg_d0.h[0] & 1) {
        reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
        reg_d0.h[0] |= 0x8000;
    } else {
        reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
    }
    reg_a0 = (u8 *)D_0028E1C0;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
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
}

extern u16 D_0028E1C4[];
extern u16 D_0028E1CC[];

void func_00130A00(void) {
    reg_d1.w = 0;
    if (D_0028E1CC[0] == 0x80) {
        D_0028E1CC[0] = 0;
        reg_d1.h[0] |= 1;
    }
    if (D_0028E1C4[0] == 0x80) {
        D_0028E1C4[0] = 0;
        reg_d1.h[0] |= 2;
    }
}

void sfx_coin(void);
extern u16 D_0028E1D8_as_u16_a[];
extern u16 D_0028E1E4_as_u16_a[];
extern u16 D_0028E1F0;
extern u16 D_0028E1F4;
extern u16 D_0028E1F8;
extern u8 D_0028E20C;
extern u8 D_0028E210;
extern u16 D_0028E224;
extern u16 g_arcade_coin_port_as_u16;

void func_00130A60(void) {
    if (g_stage_load_state != 0) return;
    if (g_setting_coin_mode == 0x12) return;
    reg_a0 = (u8 *)&g_arcade_coin_port_as_u16;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] = D_0028E1F4;
    D_0028E1F4 = reg_d0.h[0];
    reg_d0.h[0] = ~(s16)reg_d0.h[0];
    D_0028E1F8 = reg_d0.h[0];
    reg_d1.h[0] &= reg_d0.h[0];
    reg_d1.h[0] &= 0xE0;
    D_0028E1F0 = reg_d1.h[0];
    func_00130A00();
    reg_d1.h[0] |= D_0028E1F0;
    if (reg_d1.h[0] & 0x20) {
        sfx_coin();
        reg_a0 = (u8 *)D_0028E1E4_as_u16_a;
        func_001305E0();
        return;
    }
    if (reg_d1.w & 1) {
        sfx_coin();
        reg_a0 = (u8 *)D_0028E1E4_as_u16_a;
        func_001305E0();
        reg_d0.b[0] = g_setting_coin_mode;
        if (reg_d0.b[0] != 0x12) {
            D_0028E208 += 1;
        }
    }
    if (reg_d1.w & 2) {
        sfx_coin();
        reg_a0 = (u8 *)D_0028E1D8_as_u16_a;
        reg_d0.b[0] = g_setting_chute_type;
        if (reg_d0.b[0] != 1) {
            reg_a0 = (u8 *)D_0028E1E4_as_u16_a;
        }
        func_001305E0();
        reg_d0.b[0] = g_setting_coin_mode;
        if (reg_d0.b[0] != 0x12) {
            D_0028E204 += 1;
        }
    }
    reg_a0 = (u8 *)&D_0028E224;
    if (D_0028E210 == 0) {
        func_00130110();
        if (cond_flag != 0) {
            reg_d1.b[0] = g_setting_chute_type;
            if (reg_d1.b[0] != 0) {
                *(u16 *)reg_a0 = reg_d0.h[0];
            } else {
                *(u16 *)reg_a0 = 0xF;
            }
            D_0028E20C = 6;
            D_0028E210 = 1;
        }
    } else if (D_0028E210 == 1) {
        D_0028E20C -= 1;
        if (D_0028E20C == 0) {
            *(u16 *)reg_a0 = 0;
            D_0028E20C = 6;
            D_0028E210 = 2;
        }
    } else if (D_0028E210 == 2) {
        D_0028E20C -= 1;
        if (D_0028E20C == 0) {
            D_0028E210 = 0;
        }
    }
}

s32 text_layer_put();

void text_layer_put_hex_digit(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_s4;

    temp_s0 = reg_d0.w;
    temp_s1 = reg_d1.w;
    temp_s2 = reg_d2.w;
    temp_s3 = reg_d3.w;
    temp_s4 = reg_d4.w;
    reg_d4.w &= 0xF;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d3.w = 0;
    reg_d2.w = 0;
    if ((s8) reg_d4.b[0] >= 0xA) {
        reg_d4.h[0] += 7;
    }
    reg_d4.h[0] += 0x30;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[1] = reg_tmp4.h[0];
    text_layer_put();
    reg_d0.w = temp_s0;
    reg_d1.w = temp_s1;
    reg_d2.w = temp_s2;
    reg_d3.w = temp_s3;
    reg_d4.w = temp_s4;
}

#ifndef DEATH_LABEL
extern char D_0024F378[];

void func_00130D80(void) {
    extern void text_layer_print(void);
    reg_d0.h[0] = 10;
    reg_d1.h[0] = 3;
    reg_a0 = (u8 *)D_0024F378;
    reg_d2.sh[0] = 0;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL

void func_00130DB0(void) {
    reg_d0.h[0] = 3;
    reg_d1.h[0] = 3;
    func_00130DE0();
}
#endif

#ifndef DEATH_LABEL
void func_00130DC0(void) {
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 0x3;
    func_00130DE0();
}
#endif

#ifndef DEATH_LABEL
void func_00130DE0(void) {
    extern void text_layer_print(void);
    reg_d2.sh[0] = 0;
    reg_a0 = (u8 *)D_0024F378;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
extern u8 D_0028C0A8_as_u8;

void func_00130E00(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0xB;
    reg_d1.h[0] = 3;
    reg_a0 = &D_0028C0A8_as_u8;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1E4[0];
    reg_d4.b[0] += D_0028E1D8[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern s32 D_0028C0A8;

void func_00130E70(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 4;
    reg_d1.h[0] = 3;
    reg_a0 = (u8 *)(&D_0028C0A8);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1E4[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void func_00130EC0(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0x12;
    reg_d1.h[0] = 3;
    reg_a0 = (u8 *)(&D_0028C0A8);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1D8[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern u8 D_0024F388[];

void func_00130F10(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)D_0024F388;
    text_layer_print();
    reg_d0.h[0] += 0xC;
    reg_d4.b[0] = D_0028E1EC;
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E4[0];
    reg_d4.b[0] += D_0028E1D8[0];
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern s32 D_0028C0B0;
extern s32 D_0028C0B8;

void func_00130FB0(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 3;
    reg_d1.h[0] = 4;
    reg_a0 = (u8 *)(&D_0028C0B0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 = (u8 *)(&D_0028C0B8);
    reg_d1.h[0] = 3;
    text_layer_print();
    reg_d0.h[0] += 5;
    reg_d4.b[0] = D_0028E1EC;
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E4[0];
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void func_00131050(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 4;
    reg_a0 = (u8 *)(&D_0028C0B0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 = (u8 *)(&D_0028C0B8);
    reg_d1.h[0] = 3;
    text_layer_print();
    reg_d0.h[0] += 5;
    reg_d4.b[0] = D_0028E1EC;
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1D8[0];
    text_layer_put_hex_digit();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1DA[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern s32 D_0024F398[];

void func_001310F0(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0xA;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)D_0024F398;
    text_layer_print();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void func_00131150(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 3;
    reg_a0 = (u8 *)D_0024F398;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1E6[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
void func_001311A0(void) {
    s32 text_layer_print();
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)D_0024F398;
    text_layer_print();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1DA[0];
    text_layer_put_hex_digit();
}
#endif

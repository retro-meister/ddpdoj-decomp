#include "common.h"

void func_001340E0(void);
void func_00134660(void);
void func_00134740(void);
void func_00134BA0(void);

void func_001340A0(void) {
    void func_001353E0(void);
    *(u16 *)&reg_d1 = 1;
    func_001353E0();
}

void func_001340B0(void) {
    void func_001353E0(void);
    *(u16 *)&reg_d1 = 9;
    func_001353E0();
}

extern u16 D_0025F9B0[];


void func_001340C0(void) {
    reg_a0 = (u8 *)D_0025F9B0;
    func_001340E0();
}

extern u16 D_0025F9F0[];


void func_001340D0(void) {
    reg_a0 = (u8 *)D_0025F9F0;
    func_001340E0();
}

void sprite_palette_load(void);

void func_001340E0(void) {
    *(u16 *)&reg_d0 = 6;
    sprite_palette_load();
}

s32 text_palette_load();
extern u8 D_00269340[];
extern u8 D_002BF3E0[];

void func_001340F0(void) {
    s32 var_a0;
    u8 *temp_a1;

    var_a0 = 0;
    do {
        temp_a1 = D_002BF3E0 + var_a0;
        (*(s8 *)((u8 *)(temp_a1) + (0))) = 0;
        var_a0 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (7))) = 0;
    } while (var_a0 < 0x24);
    if (var_a0 < 0x2C) {
        do {
            *(D_002BF3E0 + var_a0) = 0;
            var_a0 += 1;
        } while (var_a0 < 0x2C);
    }
    reg_a0 = D_00269340;
    reg_d0.h[0] = 0xD;
    text_palette_load();
}

extern u8 D_002BF3F6[];

void func_00134170(void) {
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;

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
    reg_a4 = (u8 *)D_002BF3E0;
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    reg_a4 = (u8 *)D_002BF3F6;
next_1:
    if (*(u16 *) reg_a4 == reg_d0.h[0]) {
        goto next_2;
    }
    *(u16 *) reg_a4 = reg_d0.h[0];
    *(u16 *) (reg_a4 + 2) = 0;
    *(u16 *) (reg_a4 + 4) = reg_d1.h[0];
next_2:
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

void func_00134260(void) {
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;

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
    reg_a4 = (u8 *)D_002BF3E0;
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    if (*(u16 *) D_002BF3E0 == 3) {
        goto next_2;
    }
    reg_a4 = (u8 *)D_002BF3F6;
next_1:
    if ((reg_d0.h[0] = *(u16 *) reg_a4) == 0) {
        goto next_4;
    }
    reg_d2.h[0] = 2;
    if (reg_d0.h[0] == 1) {
        goto next_3;
    }
next_2:
    reg_d2.h[0] = 4;
next_3:
    *(u16 *) reg_a4 = reg_d2.h[0];
    *(u16 *) (reg_a4 + 2) = 0;
    *(u16 *) (reg_a4 + 4) = reg_d1.h[0];
next_4:
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

typedef void (*Fn)();

extern u8 D_00269B70[];
extern u16 D_002BF3E0_as_u16_a[];

void func_00134380(u16 *arg0) {
    u16 *var_a0;
    u16 temp_v1_2;

    var_a0 = (u16 *)(arg0);
    reg_a4 = (u8 *)(D_002BF3E0_as_u16_a);
    reg_d7.w = 1;
    do {
        temp_v1_2 = *(u16 *)reg_a4;
        reg_d0.h[0] = temp_v1_2;
        if (temp_v1_2 != 0) {
            ((Fn)*(u32 *)((u8 *)D_00269B70 + (reg_d0.h[0] * 4)))();
        }
        var_a0 = (u16 *)(reg_a4 + 0x16);
        reg_a4 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


s32 deferred_text_clear();
s32 func_00130CC0();
s32 func_00131610();
s32 text_layer_print();
s32 func_0018D9F0();
extern u8 D_00269B90[];
extern u8 D_00269BA0[];
#ifdef DEATH_LABEL
extern u8 death_D_00251300[];
extern u8 death_D_00251310[];
extern u16 D_0028E314;
extern u16 D_0028E318;
#endif

void func_00134410(void) {
    u16 temp_a0;

    func_00131610();
    if (cond_flag != 0) {
        func_00134660();
        return;
    }
    if (*(u16 *)(reg_a4 + 2) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
        *(u16 *)(reg_a4 + 2) = 1U;
        *(u8 *)(reg_a4 + 0xD) = 0U;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        deferred_text_clear();
        reg_d0.h[0] = 0x74;
        reg_d1.h[0] = 0xC00;
        reg_d2.w = 7;
        reg_d3.w = 3;
        deferred_text_clear();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        if (*(u16 *)(reg_a4 + 4) != 0) {
            reg_d1.h[0] = 0x33;
            reg_d0.h[0] = 0xF;
        }
        *(u16 *)(reg_a4 + 6) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[0];
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 6);
    temp_a0 = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = temp_a0;
    reg_a0 = (u8 *)D_00269B90;
    reg_d2.h[0] = 2;
    text_layer_print();
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    if (*(u8 *)(reg_a4 + 0xD) != reg_d4.b[0]) {
        *(u8 *)(reg_a4 + 0xD) = (u8) reg_d4.b[0];
        func_0018D9F0();
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] += 0xA;
    reg_d1.h[0] = *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = 2;
    func_00130CC0();
#ifdef DEATH_LABEL
    if (*(u16 *)(reg_a4 + 4) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)death_D_00251300;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 1;
        reg_d4.w = 0;
        reg_d1.h[0] = 0x32;
        reg_d2.h[0] = 2;
        reg_d4.h[0] = D_0028E318;
        reg_d0.h[0] += 0xA;
        func_00130CC0();
    } else {
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)death_D_00251310;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d4.w = 0;
        reg_d1.h[0] = 0x32;
        reg_d2.h[0] = 2;
        reg_d4.h[0] = D_0028E314;
        reg_d0.h[0] += 0xA;
        func_00130CC0();
    }
#endif
}


void func_00134620(void) {
    if (*(u16 *)(reg_a4 + 2) != 0) {
        func_00134740();
        return;
    }
    *(u16 *)(reg_a4 + 2) = 1U;
    func_00134660();
}


void func_00134660() {
    reg_d0.h[0] = 1;
    reg_d1.h[0] = 0x33;
    if (*(u16 *)(reg_a4 + 4) != 0) {
        reg_d1.h[0] = 0x33;
        reg_d0.h[0] = 0xF;
    }
    *(u16 *)(reg_a4 + 6) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[0];
    reg_a0 = D_00269BA0;
    reg_d2.h[0] = 2;
    text_layer_print();
    func_00134740();
    if (*(u16 *)(reg_a4 + 4) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
        return;
    }
    reg_d0.h[0] = 0xF;
    reg_d1.h[0] = 0x32;
    reg_a0 = D_00269BA0;
    reg_d2.h[0] = 2;
    text_layer_print();
}

extern s16 *reg_a4_as_s16_p;

void func_00134740(void) {
    *reg_a4_as_s16_p = 0;
}

s32 deferred_text_put();
s32 deferred_text_put_sheet();
extern u32 D_00269BA0_as_u32_a[];
extern u8 D_00269BB0[];
extern u8 D_00269C00[];
extern s16 D_002BF3F6_as_s16_a[];
#ifdef DEATH_LABEL
s32 func_00130CC0();
extern u8 death_D_00251300[];
extern u8 death_D_00251310[];
extern u16 D_0028E314;
extern u16 D_0028E318;
#endif

void func_00134750(void) {
    s32 temp_a3;
    u32 temp_a2;
    u32 temp_a3_2;
    u8 temp_a0;

    if (*(u16 *)(reg_a4 + 2) == 0) {
        *(u16 *)(reg_a4 + 2) = 1U;
        *(u8 *)(reg_a4 + 0xD) = 0U;
        *(u16 *)(reg_a4 + 0x10) = 0U;
        *(s16 *)(reg_a4 + 0xE) = 3;
        *(u16 *)(reg_a4 + 0x14) = 0U;
        *(s16 *)(reg_a4 + 0x12) = 1;
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)(D_00269BA0_as_u32_a);
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)(D_00269BA0_as_u32_a);
        reg_d2.h[0] = 2;
        text_layer_print();
        D_002BF3F6_as_s16_a[0] = 0;
    }
#ifdef DEATH_LABEL
    reg_d0.h[0] = 1;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)death_D_00251300;
    reg_d2.h[0] = 2;
    text_layer_print();
    reg_d0.h[0] = 1;
    reg_d4.w = 0;
    reg_d1.h[0] = 0x32;
    reg_d2.h[0] = 2;
    reg_d4.h[0] = D_0028E318;
    reg_d0.h[0] += 0xA;
    func_00130CC0();
    reg_d0.h[0] = 0xF;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)death_D_00251310;
    reg_d2.h[0] = 2;
    text_layer_print();
    reg_d0.h[0] = 0xF;
    reg_d4.w = 0;
    reg_d1.h[0] = 0x32;
    reg_d2.h[0] = 2;
    reg_d4.h[0] = D_0028E314;
    reg_d0.h[0] += 0xA;
    func_00130CC0();
#endif
    *(u8 *)(reg_a4 + 0xF) -= 1;
    if ((s8) *(u8 *)(reg_a4 + 0xF) < 0) {
        *(u8 *)(reg_a4 + 0xF) = *(u8 *)(reg_a4 + 0xE);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
        temp_a3 = reg_tmp.h[0] & ~3;
        temp_a2 = *(u32 *)(D_00269BB0 + temp_a3);
        reg_d4.w = temp_a2;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        deferred_text_put();
        *(u16 *)(reg_a4 + 0x10) += 4;
        if (*(u16 *)(reg_a4 + 0x10) == 0x44) {
            *(u16 *)(reg_a4 + 0x10) = 0U;
        }
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    reg_a0 = *(u8 **)(D_00269C00 + (reg_d4.h[0] * 4));
    reg_a0 += *(u16 *)(reg_a4 + 0x14);
    temp_a3_2 = *(u32 *)reg_a0;
    reg_d4.w = temp_a3_2;
    reg_d0.h[0] = 0x74;
    reg_d1.h[0] = 0xC00;
    reg_d2.w = 7;
    reg_d3.w = 3;
    reg_d5.h[0] = 0xC;
    deferred_text_put_sheet();
    *(u8 *)(reg_a4 + 0x13) -= 1;
    if ((s8) *(u8 *)(reg_a4 + 0x13) < 0) {
        *(u8 *)(reg_a4 + 0x13) = *(u8 *)(reg_a4 + 0x12);
        *(u16 *)(reg_a4 + 0x14) += 4;
        if ((s16) *(u16 *)(reg_a4 + 0x14) >= 0xC) {
            *(u16 *)(reg_a4 + 0x14) = 0U;
        }
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    temp_a0 = *(u8 *)(reg_a4 + 0xD);
    if (temp_a0 != reg_d4.b[0]) {
        *(u8 *)(reg_a4 + 0xD) = (u8) reg_d4.b[0];
        func_0018D9F0();
    }
}

void func_001349A0() {
    if (*(u16 *)(reg_a4 + 2) == 0) {
        *(u16 *)(reg_a4 + 2) = 1U;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        deferred_text_clear();
        reg_d0.h[0] = 0x74;
        reg_d1.h[0] = 0xC00;
        reg_d2.w = 7;
        reg_d3.w = 3;
        deferred_text_clear();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = D_00269BA0;
        reg_d2.h[0] = 2;
        text_layer_print();
    }
    *(s16 *)reg_a4 = 0;
}

extern u32 reg_a0_as_u32;

void func_00134A70(void)
{
    *(u16 *)(reg_a5 + 4) = 0x93C;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0_as_u32 = reg_tmp.w;
    reg_d0.b[0] = reg_a5[5];
    *(u8 *)reg_a0_as_u32 = reg_d0.b[0];
}

s32 func_001A3560();
s32 func_001ACA00();
s32 func_001ACA80();
extern u8 D_00269CD0[];
extern u8 D_00269CF0[];

void func_00134AC0() {
    *(s8 *)(reg_a5 + 3) = 1;
    reg_a4 = D_00269CD0;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a4 = D_00269CF0;
    }
    reg_tmp.w = (u32) reg_a4;
    *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a5 + 0x14) = 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3560();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        func_001ACA00();
    } else {
        func_001ACA80();
    }
    func_00134A70();
}


void func_00134B70(void) {
    *(s8 *)(reg_a5 + 3) = 2;
    func_00134A70();
    func_00134BA0();
}

s32 func_002075F0();                            /* extern */

void func_00134BA0(void) {
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 6);
    func_00134260();
    func_002075F0();
}

s32 func_0013B190();                            /* extern */
s32 func_0018DE90();                            /* extern */
s32 func_0018DEE0();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 task_start();                            /* extern */
extern u16 g_loop;
extern u16 g_stage;
extern s8 D_0028ED64_as_s8;

void func_00134BD0(void) {
    func_0018DEE0();
    func_0018DE90();
    func_0013B190();
    func_00206D70();
    reg_d0.h[0] = 0xE;
    task_start();
    if (g_loop != 1) {
        if ((s32) 0 < g_stage) {
            goto block_3;
        }
    } else {
block_3:
        D_0028ED64_as_s8 = 1;
    }
}

s32 func_00125EA0();
s32 func_0012FE10();
s32 func_00135100();
s32 func_001351F0();
extern u8 D_0028E398;
extern u8 g_simulation_active;
extern u8 D_002BF3EA[];
extern u8 *jtbl_0028E3F4_as_u8_p;

void func_00134C40(void) {
    s32 func_001353E0();
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0xA);
    reg_a4 = (u8 *) reg_tmp.w;
    if (reg_a5[3] == 0) {
        func_00134AC0();
        return;
    }
    if (reg_a5[3] == 2) {
        func_00134BA0();
        return;
    }
    if (reg_a5[3] == 3) {
        func_00134B70();
        return;
    }
    if (reg_a5[3] == 4) {
        func_00134BD0();
        return;
    }
    if (g_loop != 0) {
        goto next_8;
    }
    if (D_0028E398 == 0) {
        goto next_8;
    }
    if (g_simulation_active != 0) {
        goto next_8;
    }
    func_001351F0();
    if (cond_flag == 0) {
        goto next_2;
    }
    if (reg_a5[2] != 0) {
        goto next_1;
    }
    reg_a5[2] = 1;
    func_00125EA0();
    func_00134A70();
next_1:
    reg_d0.w = 3;
    reg_d1.w = 0;
    func_00134170();
    func_00135100();
    goto next_4;
next_2:
    if (reg_a5[2] == 0) {
        goto next_3;
    }
    reg_a5[2] = 0;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a5[6];
    func_00134260();
    func_00134A70();
next_3:
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a5[6];
    func_00134170();
next_4:
    func_00131610();
    if (cond_flag != 0) {
        return;
    }
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 0xE);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn) jtbl_0028E3F4_as_u8_p)();
    if (((reg_d0.h[0] &= 0x70) & 0xFFFF) == 0) {
        goto next_6;
    }
    func_001351F0();
    if (cond_flag == 0) {
        goto next_5;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    reg_d1.h[0] = 8;
    func_001353E0();
    goto next_6;
next_5:
    reg_a5[4] = 0;
next_6:
    reg_a5[4] -= 1;
    if ((s8) reg_a5[4] >= 0) {
        goto next_10;
    }
    reg_a5[4] = 60;
    reg_a5[5] -= 1;
    if ((s8) reg_a5[5] >= 0) {
        goto next_10;
    }
next_8:
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 6);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn) jtbl_0028E3F4_as_u8_p)();
    if (g_simulation_active != 0) {
        goto next_9;
    }
    if (g_loop != 0) {
        goto next_9;
    }
    func_001351F0();
    if (cond_flag == 0) {
        goto next_11;
    }
next_9:
    reg_a5[3] = 4;
    func_00134BD0();
    return;
next_11:
    reg_a5[3] = 3;
    func_00134B70();
    return;
next_10:
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    func_0012FE10();
    if (cond_flag == 0) {
        goto next_12;
    }
    func_00134A70();
next_12:
    func_001351F0();
    if (cond_flag == 0) {
        goto next_13;
    }
    reg_d0.b[0] = reg_a5[5];
    D_002BF3EA[0] = reg_d0.b[0];
    return;
next_13:
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 0x12);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.b[0] = reg_a5[5];
    *reg_a0 = reg_d0.b[0];
}

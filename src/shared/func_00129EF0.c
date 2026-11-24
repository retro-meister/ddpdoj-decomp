#include "common.h"

extern u8 D_0024EB30[];
extern u8 D_0024EE90[];
void func_00125EE0();
#ifdef DEATH_LABEL
void death_func_00128A90();
#endif
void func_00128640();
void func_00129450();
void func_00129460();
void func_0012DA30();
void func_0012DB30();
void func_0012DCC0();
void func_0014E030();
void func_00202760();
void func_00203330();
extern u8 D_0024E7D0_as_u8_a[];
extern u8 D_0024F0F0[];
extern u8 D_00262570[];
extern u32 D_0028DEA4;
extern u16 D_0028E3EC;
extern s8 D_0028E408;
extern Reg32 D_0028E484;
extern u16 D_0028E854_as_u16;
extern u16 D_0028E88C;
extern u8 D_002962E0[];
#ifdef DEATH_LABEL
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif
extern u16 D_00299760[];
extern u16 D_00299762[];
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u8 *D_00299770[];
extern u16 D_0029C06C[];
extern u8 D_0029CEA0_as_u8_a[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u16 *reg_a4_as_u16_p;
extern u8 *reg_a6;

#define SLOT_PHASE MAIN_OR_DEATH_LABEL(D_00299762[0], *(u16 *)(D_002962E0 + 0x10682))
#define SLOT_CURSOR MAIN_OR_DEATH_LABEL(D_00299770[0], *(u8 **)(D_002962E0 + 0x10690))

void func_00129EF0(void) {
    u8 *var_a0;
    u8 *var_a0_4;
    u8 *var_a1;
    u8 *var_a2;
    s32 temp_a0_16;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a2_5;
    s64 temp_a1;
    s64 temp_v1_57;
    s8 var_v0;
    s8 var_v0_2;
    s8 var_v0_3;
    u16 temp_a0_11;
    u16 temp_a0_13;
    u16 temp_a0_14;
    u16 temp_a0_15;
    u16 temp_a0_18;
    u16 temp_a0_2;
    u16 temp_a1_4;
    u16 temp_a1_8;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a3;
    u16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_10;
    u16 temp_v1_11;
    u16 temp_v1_13;
    u16 temp_v1_14;
    u16 temp_v1_15;
    u16 temp_v1_16;
    u16 temp_v1_17;
    u16 temp_v1_18;
    u16 temp_v1_19;
    u16 temp_v1_20;
    u16 temp_v1_21;
    u16 temp_v1_22;
    u16 temp_v1_23;
    u16 temp_v1_24;
    u16 temp_v1_25;
    u16 temp_v1_26;
    u16 temp_v1_27;
    u16 temp_v1_28;
    u16 temp_v1_29;
    u16 temp_v1_2;
    u16 temp_v1_30;
    u16 temp_v1_31;
    u16 temp_v1_32;
    u16 temp_v1_33;
    u16 temp_v1_35;
    u16 temp_v1_36;
    u16 temp_v1_38;
    u16 temp_v1_39;
    u16 temp_v1_3;
    u16 temp_v1_40;
    u16 temp_v1_41;
    u16 temp_v1_44;
    u16 temp_v1_45;
    u16 temp_v1_47;
    u16 temp_v1_48;
    u16 temp_v1_49;
    u16 temp_v1_4;
    u16 temp_v1_50;
    u16 temp_v1_51;
    u16 temp_v1_52;
    u16 temp_v1_54;
    u16 temp_v1_55;
    u16 temp_v1_56;
    u16 temp_v1_58;
    u16 temp_v1_59;
    u16 temp_v1_5;
    u16 temp_v1_60;
    u16 temp_v1_61;
    u16 temp_v1_62;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u16 temp_v1_8;
    u16 temp_v1_9;
    u16 var_a0_3;
    u32 temp_a0;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u8 temp_a0_10;
    u8 temp_a0_12;
    u8 temp_a0_17;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_a0_8;
    u8 temp_a0_9;
    u8 temp_a1_7;
    u8 temp_a1_9;
    u8 temp_v1_12;
    u8 temp_v1_34;
    u8 temp_v1_37;
    u8 temp_v1_42;
    u8 temp_v1_43;
    u8 temp_v1_46;
    u8 temp_v1_53;
    u8 var_a0_2;
    u8 *temp_a3_2;
    u8 *var_a1_2;


    reg_a6 = D_002962E0;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    reg_d6.h[0] = D_0029C06C[0];
    if (D_00299768_as_u16_a[0] != 0) {
        reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
        if (D_0029976A_as_u16_a[0] != 0) {
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
            if (D_0029976C[0] != 0) {
                reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
                if (D_0029976E[0] != 0) {
                    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
                }
            }
        }
    }
    goto loop_10;

L_bom_bui:
    reg_d1.h[0] = *(u16 *)D_0029CEA0_as_u8_a;
    if ((reg_d1.h[0] != 0) && (reg_d1.w & 1) && (0 <= (s64)(s16)D_0028E854_as_u16)) {
        goto block_12;
    }
    reg_d0.w = 0;
    D_0028DEA4 = reg_d7.w;
    MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
    reg_d7.w = D_0028DEA4;
    func_00128640();

block_9:
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

loop_10:
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0);
    if ((s16)reg_d2.h[0] >= 0) {
        goto block_9;
    }
    D_00299760[0] += 1;
    reg_d1.h[0] = *(u16 *)D_0029CEA0_as_u8_a;
    if ((s16)(reg_d1.h[0] |= (s16)D_0028E854_as_u16) < 0) {
        goto L_bom_bui;
    }

block_12:
    reg_d0.h[0] = 0x5180;
    reg_d0.h[0] &= reg_d2.h[0];
    if (reg_d0.h[0] != 0) {
        goto L_not_plain;
    }
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d0.h[0] -= reg_d6.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 2) += reg_d0.h[1];
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0xC800;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x9000;
    reg_tmp.w = reg_d0.w;
    temp_v0 = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d0.h[1] = temp_v0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_a1 = (u8 *)((u32)reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_d0.w = (u32)((s32)reg_d0.w >> 6);
    temp_a1_2 = reg_d0.w;
    reg_d0.w = temp_a1_2 & 0x07FF03FF;
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 | 0x80008000;
    *reg_a4_as_u16_p = reg_d0.h[1];
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = reg_d0.h[0];
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a1 + 0);
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a6 + 0x1C);
    reg_a4_as_u16_p += 1;
    func_0012DCC0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    goto block_44;

block_16:
    func_00128640();
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_not_plain:
    if (reg_d2.w & 0x1000) {
        goto block_16;
    }
    *(u16 *)(reg_a6 + 4) -= reg_d6.h[0];
    if (0 > (s64)(s16)reg_d2.b[0]) {
        goto L_0012A4B0;
    }
    if (!(reg_d2.w & 0x100)) {
        goto L_0012A68C;
    }
    temp_a0 = reg_d6.h[0]; *(u16 *)(reg_a6 + 4) += temp_a0;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_0012DA30();
    *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
    reg_d0.w = 0x3F;
    reg_d0.h[0] &= *(u16 *)(reg_a6 + 0);
    reg_a0 = D_0024EB30;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = (void (*)())reg_a0;
    jtbl_0028E3F4();
    SLOT_PHASE += 1;
    if (SLOT_PHASE == 3) {
        SLOT_PHASE = 0;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_0012A4B0:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0xC800;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x9000;
    reg_tmp.w = reg_d0.w;
    temp_v0 = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d0.h[1] = temp_v0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    if (reg_d2.w & 0x100) {
        goto L_0012A5DC;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_0012DA30();
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d3.h[0];
    func_0012DB30();
    if ((*(u8 *)(reg_a6 + 1)) & 0x40) {
        goto block_33;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    goto block_44;

L_0012A5DC:
    reg_d0.w = 0x3F;
    reg_d0.h[0] &= *(u16 *)(reg_a6 + 0);
    reg_a0 = D_0024EB30;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = (void (*)())reg_a0;
    jtbl_0028E3F4();
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_0012A68C:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    func_0012DB30();

block_33:
    temp_a0_17 = *(u8 *)(reg_a6 + 1);
    var_a1_2 = reg_a6 + 1;
    if (temp_a0_17 & 0x20) {
        *(u8 *)(reg_a6 + 1) = (u8)(temp_a0_17 | 0x20);
    } else {
        *(u8 *)(reg_a6 + 1) = (u8)(temp_a0_17 | 0x20);
        reg_tmp.w = 0x24F;
        *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
        *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0);
        reg_a1 = D_0024E7D0_as_u8_a;
        reg_d0.h[0] &= 0x3F;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a1 += reg_d0.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a1 - 2) == 1) {
            reg_tmp.w = 0x23F;
            *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
        }
        *(s16 *)(reg_a6 + 0xE) = 0x410;
        reg_tmp.w = 0xFC00FE00;
        *(u16 *)(reg_a6 + 6) = reg_tmp.h[1];
        var_a1_2 = (void *)reg_tmp.h[0];
        *(u16 *)(reg_a6 + 8) = (u16)var_a1_2;
        *(u16 *)(reg_a6 + 0x16) = 0x10U;
        *(u16 *)(reg_a6 + 0x1E) = (u16)((s16)*(u16 *)(reg_a6 + 0x1E) >> 1);
        *(u16 *)(reg_a6 + 0x20) = (u16)((s16)*(u16 *)(reg_a6 + 0x20) >> 1);
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += 1;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x16) -= 1;
    if (*(u16 *)(reg_a6 + 0x16) == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x3C);
        if ((s16)reg_d0.h[0] >= 0) {
            D_0028DEA4 = reg_d7.w;
            MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
            reg_d7.w = D_0028DEA4;
        }
        func_00128640();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

block_44:
    switch (reg_tmp.w) {
    default:
        return;
                            case 0:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                if (reg_tmp.w == 0x146) {
                                    reg_tmp.w = 0x140;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 1:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                if (reg_tmp.w == 0x146) {
                                    reg_tmp.w = 0x146;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 3:                 /* switch 1 */
                                temp_a0_3 = *(u8 *)(reg_a6 + 1);
                                if (temp_a0_3 & 8) {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_3 & 0xF7;
                                } else {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_3 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = D_0028E484.h[0];
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w = 0x1A2;
                                    if (D_0028E484.w == reg_tmp.w) {
                                        reg_tmp.w = 0x19E;
                                        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 4:                 /* switch 1 */
                                temp_a0_4 = *(u8 *)(reg_a6 + 1);
                                if (temp_a0_4 & 8) {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_4 & 0xF7;
                                } else {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_4 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = D_0028E484.h[0];
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w = 0x1A6;
                                    if (D_0028E484.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1A2;
                                        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 5:                 /* switch 1 */
                                temp_a0_5 = *(u8 *)(reg_a6 + 1);
                                if (temp_a0_5 & 8) {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_5 & 0xF7;
                                } else {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_5 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = D_0028E484.h[0];
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w = 0x1AA;
                                    if (D_0028E484.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1A6;
                                        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 6:                 /* switch 1 */
                                temp_a0_6 = *(u8 *)(reg_a6 + 1);
                                if (temp_a0_6 & 8) {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_6 & 0xF7;
                                } else {
                                    *(u8 *)(reg_a6 + 1) = temp_a0_6 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = D_0028E484.h[0];
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                    D_0028E484.w = 0x1AE;
                                    if (D_0028E484.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1AA;
                                        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 7:                 /* switch 1 */
                                temp_v1_12 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_12 == 0) {
                                    reg_a6 += 0xA;
                                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_a0 = reg_a6 + 6;
                                    reg_d0.w += 1;
                                    temp_a1_4 = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_a0 += 2;
                                    reg_tmp.h[1] = temp_a1_4;
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_a0 += 2;
                                    if (reg_tmp.w == reg_d0.w) {
                                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                        reg_d0.w -= reg_tmp.w;
                                    }
                                    reg_a0 += 4;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d0.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[0];
                                    *(u8 *)(reg_a0 + 0) = *(u8 *)(reg_a0 + 1);
                                    reg_a0 += 2;
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_12 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 8:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                if (reg_tmp.w == 0x1EA) {
                                    reg_tmp.w = 0x1E6;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 9:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                if (reg_tmp.w == 0x1BD) {
                                    reg_tmp.w = 0x1B9;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 10:                /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                if (reg_tmp.w == 0x1C3) {
                                    reg_tmp.w = 0x1BF;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 11:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                if (reg_tmp.w == 0x224) {
                                    reg_tmp.w = 0x220;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 12:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                if (reg_tmp.w == 0x212) {
                                    reg_tmp.w = 0x20E;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 13:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                if (reg_tmp.w == 0x218) {
                                    reg_tmp.w = 0x214;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 16:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
                                (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 17:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
                                (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2B)));
                                (*(u8 *)((u8 *)(reg_a6) + (0x2B))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2A)));
                                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x35)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += reg_d0.b[0];
                                }
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 18:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
                                (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
                                (*(u16 *)((u8 *)(reg_a6) + (0x34))) -= 1;
                                if (0 > (s64)*(s16 *)(reg_a6 + 0x34)) {
                                    reg_d0.w = 0x35;
                                    func_0014E030();
                                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                                    goto block_16;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 19:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a0_3 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_3 = 1 << reg_d0.b[0];
                                if (temp_a2_3 & temp_a0_3) {
                                    temp_a0_7 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                                    if (temp_a0_7 & temp_a2_3) {
                                        (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_7 & (~temp_a2_3 & 0xFF));
                                        goto block_144;
                                    }
                                    (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_7 | (temp_a2_3 & 0xFF));
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_tmp.w += 1;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    reg_tmp.w = 0x297;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    if (reg_tmp.w == D_0028E484.w) {
                                        reg_tmp.w = 0x287;
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_d1.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                if (reg_d1.w != 0) {
                                    reg_a0 = (u8 *) reg_d1.w;
                                    if ((0 > (s64)*(s16 *)(reg_a0 + 0)) && (0 <= (s64)*(s8 *)(reg_a0 + 0))) {
                                        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                                        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
                                        reg_d1.w += reg_tmp.w;
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d1.h[0];
                                        temp_a0_8 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                                        temp_a1_5 = 1 << reg_d0.b[0];
                                        if (temp_a0_8 & temp_a1_5) {
                                            (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_8 & (~temp_a1_5 & 0xFF));
                                        } else {
                                            (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_8 | (temp_a1_5 & 0xFF));
                                            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                            reg_tmp.w += 1;
                                            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                            reg_tmp.w = 0x288;
                                            D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                            D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                            if (reg_tmp.w != D_0028E484.w) {
                                                goto block_144;
                                            }
                                            goto block_143;
                                        }
                                        goto block_144;
                                    }
                                    goto L_clr_block_143;
                                }
block_143:
                                (*(u8 *)((u8 *)(reg_a6) + (0x35))) |= 8;
                                (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x32)));
block_144:
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
L_clr_block_143:
                                func_00128640();
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 20:                /* switch 1 */
                                reg_a6 += 0xA;
                                if (D_0028E3EC != 0) {
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_tmp.w += 1;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    if (reg_tmp.w == 0x1B4) {
                                        reg_tmp.w = 0x1AE;
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 22:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a0_4 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_4 = 1 << reg_d0.b[0];
                                if (temp_a2_4 & temp_a0_4) {
                                    temp_a0_9 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                                    if (temp_a0_9 & temp_a2_4) {
                                        (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_9 & (~temp_a2_4 & 0xFF));
                                        goto block_167;
                                    }
                                    (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_9 | (temp_a2_4 & 0xFF));
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_tmp.w += 1;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    reg_tmp.w = 0x2AB;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    if (reg_tmp.w == D_0028E484.w) {
                                        reg_tmp.w = 0x29B;
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_d1.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                if (reg_d1.w != 0) {
                                    reg_a0 = (u8 *) reg_d1.w;
                                    if ((0 > (s64)*(s16 *)(reg_a0 + 0)) && (0 <= (s64)*(s8 *)(reg_a0 + 0))) {
                                        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                                        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                                        D_0028E484.h[0] = *(u16 *)(reg_a6 + 0x2A);
                                        reg_d1.w = (u32) (reg_d1.w + D_0028E484.w);
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d1.h[0];
                                        temp_a0_10 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                                        temp_a1_6 = 1 << reg_d0.b[0];
                                        if (temp_a0_10 & temp_a1_6) {
                                            (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_10 & (~temp_a1_6 & 0xFF));
                                        } else {
                                            (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_10 | (temp_a1_6 & 0xFF));
                                            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                            reg_tmp.w += 1;
                                            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                            reg_tmp.w = 0x29C;
                                            D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                            D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                            if (reg_tmp.w != D_0028E484.w) {
                                                goto block_167;
                                            }
                                            goto block_166;
                                        }
                                        goto block_167;
                                    }
                                    goto L_clr_block_166;
                                }
block_166:
                                (*(u8 *)((u8 *)(reg_a6) + (0x35))) |= 8;
                                (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x32)));
block_167:
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
L_clr_block_166:
                                func_00128640();
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 23:                /* switch 1 */
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                if (reg_tmp.w == 0x224) {
                                    reg_tmp.w = 0x220;
                                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                }
                                temp_a0_11 = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                                if (temp_a0_11 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_11) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0x36))) = (u16) (temp_a0_11 - 1);
                                    }
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                        (*(u16 *)((u8 *)(reg_a6) + (0x1E))) -= reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 24:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a1_7 = (*(u8 *)((u8 *)(reg_a6) + (0x35)));
                                temp_a2_5 = 1 << reg_d0.b[0];
                                if (temp_a2_5 & temp_a1_7) {
                                    temp_a0_12 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                                    if (temp_a0_12 & temp_a2_5) {
                                        (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_12 & (~temp_a2_5 & 0xFF));
                                    } else {
                                        (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_12 | (temp_a2_5 & 0xFF));
                                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                        reg_tmp.w += 1;
                                        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                        reg_tmp.w = 0x2AB;
                                        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                        D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                        if (reg_tmp.w == D_0028E484.w) {
                                            reg_tmp.w = 0x29B;
                                            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                        }
                                    }
                                    temp_a0_13 = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                                    if (temp_a0_13 != 0) {
                                        if (0 <= (s64)(s16)temp_a0_13) {
                                            (*(u16 *)((u8 *)(reg_a6) + (0x36))) = (u16) (temp_a0_13 - 1);
                                        }
                                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                        if ((s32) reg_tmp.b[0] <= 0) {
                                            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                            (*(u16 *)((u8 *)(reg_a6) + (0x1E))) -= reg_d0.h[0];
                                        }
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x35))) = (u8) (temp_a1_7 | 8);
                                (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x32)));
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 25:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] *= -1;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_202;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] *= -1;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_202;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if (((s32) reg_d0.h[0] >= 0x600) && ((s32) reg_d0.h[0] > 0x6E00)) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] *= -1;
                                        reg_d1.b[0] += 0x80;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
block_202:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                        func_0012DA30();
                                        (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) reg_d2.h[0];
                                        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d3.h[0];
                                        reg_tmp.w = 0x14;
                                        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                        D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                        reg_tmp.w = (u32) (reg_tmp.w + D_0028E484.w);
                                        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_34 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_34 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = D_0028E484.h[0];
                                    if (D_0028E484.w == reg_d0.w) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_34 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 26:                /* switch 1 */
                                temp_v1_37 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_37 == 0) {
                                    reg_a6 += 0xA;
                                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_a0 = reg_a6 + 6;
                                    reg_d0.w += 1;
                                    temp_a1_8 = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_a0 += 2;
                                    reg_tmp.h[1] = temp_a1_8;
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_a0 += 2;
                                    if (reg_d0.w == reg_tmp.w) {
                                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                        reg_d0.w -= reg_tmp.w;
                                    }
                                    reg_a0 += 4;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d0.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[0];
                                    *(u8 *)(reg_a0 + 0) = *(u8 *)(reg_a0 + 1);
                                    reg_a0 += 2;
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_37 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 27:                /* switch 1 */
                                reg_a4_as_u16_p -= 6;
                                reg_a0 = SLOT_CURSOR;
                                reg_a2 = (u8 *)reg_a4_as_u16_p;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                reg_a1 -= 4;
                                SLOT_CURSOR = reg_a0;
                                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                reg_tmp.w += 1;
                                (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0x1A2;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                                if (reg_tmp.w == D_0028E484.w) {
                                    reg_tmp.w = 0x19E;
                                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                                }
                                temp_v1_40 = (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                                if (temp_v1_40 != 0) {
                                    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) (temp_v1_40 - 1);
                                    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                                    reg_d1.w = *(u16 *)(reg_a6 + 0x2A);
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
                                    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d1.h[0];
                                    reg_d1.w = 0;
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += reg_d0.b[0];
                                        reg_d1.w = 1;
                                    }
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x37)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x37))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a6) + (0x37))) = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x38)));
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += reg_d0.b[0];
#ifdef DEATH_LABEL
                                        if ((death_D_0029085C == 2) && (*(u8 *)(reg_a6 + 0x1B) > death_D_00290858)) {
                                            *(u8 *)(reg_a6 + 0x1B) = death_D_00290858;
                                        }
#endif
                                        reg_d1.w = 1;
                                    }
                                    if (reg_d1.h[0] != 0) {
                                        reg_d0.w = 0;
                                        reg_d1.w = 0;
                                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d3.h[0] = *(u16 *)(D_0024F0F0 + (reg_d1.h[0] * 2));
                                        temp_a3_2 = D_00262570 + (reg_d3.h[0] * 2);
                                        reg_d2.w = reg_d0.h[0] * (*(u16 *)(temp_a3_2 + 0));
                                        reg_d3.w = reg_d0.h[0] * (*(u16 *)(temp_a3_2 + 2));
                                        reg_d2.w = (u32) ((s32) reg_d2.w >> 4);
                                        reg_d3.w = (u32) ((s32) reg_d3.w >> 4);
                                        reg_d1.h[0] &= 0xC0;
                                        switch (reg_d1.h[0]) { /* switch 2; irregular */
                                        case 0x0:   /* switch 2 */
                                            break;
                                        case 0x40:  /* switch 2 */
                                            reg_d2.h[0] *= 0xFFFF;
                                            break;
                                        case 0x80:  /* switch 2 */
                                            reg_d2.h[0] *= -1;
                                            reg_d3.h[0] *= 0xFFFF;
                                            break;
                                        case 0xC0:  /* switch 2 */
                                            reg_d3.h[0] *= 0xFFFF;
                                            break;
                                        }
                                        (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) reg_d2.h[0];
                                        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d3.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 28:                /* switch 1 */
                                temp_v1_42 = (*(u8 *)((u8 *)(reg_a6) + (0x29)));
                                if (temp_v1_42 != 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x29))) = (u8) (temp_v1_42 - 1);
                                    if ((*(u8 *)((u8 *)(reg_a6) + (0x29))) == 0) {
                                        func_00203330();
                                        if (D_0028E408 == 0) {
                                            func_00202760();
                                            if (D_0028E88C == 0) {
                                                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                                reg_d1.b[0] += 0xB0;
                                            }
                                            reg_d0.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                            reg_d3.w = 0;
                                            reg_d4.w = 0;
                                            MAIN_OR_DEATH_LABEL(func_00129450, func_00129460)();
                                        }
                                    }
                                }
                                temp_v1_43 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_43 == 0) {
                                    reg_d0.w = 0x297;
                                    reg_d1.w = 0x287;
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_tmp.w += 1;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    if (reg_tmp.w == reg_d0.w) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_43 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 29:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.h[0] = 0x40;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_261;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.h[0] = 0xC0;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_261;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if ((s32) reg_d0.h[0] < 0x600) {
                                        reg_d1.h[0] = 0;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1D))) ^= 0x20;
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                        func_0012DA30();
                                        reg_d2.w = (u32) ((s32) reg_d2.w >> 1);
                                        reg_d3.w = (u32) ((s32) reg_d3.w >> 1);
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
                                        goto block_262;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x6E00) {
                                        reg_d1.h[0] = 0x80;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
block_261:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                        func_0012DA30();
                                        reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
                                        reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 1);
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
block_262:
                                        reg_tmp.w = 0x14;
                                        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                        D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                        reg_tmp.w = (u32) (reg_tmp.w + D_0028E484.w);
                                        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_46 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_46 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = D_0028E484.h[0];
                                    if (D_0028E484.w == reg_d0.w) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_46 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 30:                /* switch 1 */
                                reg_tmp.w = 1;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                D_0028E484.w += reg_tmp.w;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) D_0028E484.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = D_0028E484.h[0];
                                reg_tmp.w = 0x224;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                if (reg_tmp.w == D_0028E484.w) {
                                    reg_tmp.w = 0x220;
                                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                }
                                temp_a0_14 = (*(u16 *)((u8 *)(reg_a6) + (0x34)));
                                if (temp_a0_14 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_14) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0x34))) = (u16) (temp_a0_14 - 1);
                                    }
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                                        (*(u16 *)((u8 *)(reg_a6) + (0x1E))) += reg_d0.h[0];
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x32)));
                                        (*(u16 *)((u8 *)(reg_a6) + (0x20))) += reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 31:                /* switch 1 */
                                reg_tmp.w = 1;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                D_0028E484.w += reg_tmp.w;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) D_0028E484.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = D_0028E484.h[0];
                                reg_tmp.w = 0x224;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                if (reg_tmp.w == D_0028E484.w) {
                                    reg_tmp.w = 0x220;
                                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                }
                                temp_a0_15 = (*(u16 *)((u8 *)(reg_a6) + (0x34)));
                                if (temp_a0_15 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_15) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0x34))) = (u16) (temp_a0_15 - 1);
                                    }
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                                        (*(u16 *)((u8 *)(reg_a6) + (0x1E))) += reg_d0.h[0];
                                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x32)));
                                        (*(u16 *)((u8 *)(reg_a6) + (0x20))) += reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 32:                /* switch 1 */
                                reg_tmp.w = 1;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                D_0028E484.w += reg_tmp.w;
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) D_0028E484.h[1];
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = D_0028E484.h[0];
                                reg_tmp.w = 0x1EA;
                                D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                var_a2 = reg_a6 + 0xA;
                                if (reg_tmp.w == D_0028E484.w) {
                                    reg_tmp.w = 0x1E6;
                                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                }
                                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                                reg_d1.w = *(u16 *)(reg_a6 + 0x2A);
                                (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
                                var_a1 = reg_a6;
                                (*(u16 *)((u8 *)(var_a1) + (4))) += reg_d1.h[0];
                                reg_d1.w = 0;
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                                    var_a2 = reg_a6;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(var_a2) + (0x2E)));
                                    var_a1 = (u8 *) (*(u8 *)((u8 *)(var_a2) + (0x1A)));
                                    (*(u8 *)((u8 *)(var_a2) + (0x1A))) = (u8) (var_a1 + reg_d0.b[0]);
                                    reg_d1.w = 1;
                                }
                                var_a0_4 = reg_a6;
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0_4) + (0x37)));
                                (*(u8 *)((u8 *)(var_a0_4) + (0x37))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x37))) = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                                    var_a2 = reg_a6;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(var_a2) + (0x38)));
                                    var_a1 = (u8 *) (*(u8 *)((u8 *)(var_a2) + (0x1B)));
                                    var_a0_4 = var_a1 + reg_d0.b[0];
                                    (*(u8 *)((u8 *)(var_a2) + (0x1B))) = (u8) var_a0_4;
                                    reg_d1.w = 1;
                                }
                                if (reg_d1.h[0] != 0) {
                                    reg_d0.w = 0;
                                    reg_d1.w = 0;
                                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                    func_0012DA30();
                                    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) reg_d2.h[0];
                                    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d3.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 33:                /* switch 1 */
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
                                (*(u8 *)((u8 *)(reg_a6) + (0x2F))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x2F))) = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
                                    reg_a0 = D_0024EE90;
                                    reg_a0 += reg_d0.h[0];
                                    *(u16 *)(reg_a6 + 0xA) = *(u16 *)(reg_a0 + 0);
                                    *(u16 *)(reg_a6 + 0xC) = *(u16 *)(reg_a0 + 2);
                                    *(u16 *)(reg_a6 + 0x2C) -= 4;
                                    if (0 > (s64)*(s16 *)(reg_a6 + 0x2C)) {
                                        *(u16 *)(reg_a6 + 0x2C) = 0xC;
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 34:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] += 0x80;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_314;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] += 0x80;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_314;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if ((s32) reg_d0.h[0] < 0x600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] += 0x80;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1D))) ^= 0x20;
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                        func_0012DA30();
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
                                        goto block_315;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x6E00) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                        reg_d1.b[0] += 0x80;
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
block_314:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                                        func_0012DA30();
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
block_315:
                                        reg_tmp.w = 0x14;
                                        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                        D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                        reg_tmp.w = (u32) (reg_tmp.w + D_0028E484.w);
                                        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_53 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_53 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = D_0028E484.h[0];
                                    if (D_0028E484.w == reg_d0.w) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_53 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 35:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a1_9 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                                temp_a0_16 = 1 << reg_d0.b[0];
                                if (temp_a1_9 & temp_a0_16) {
                                    (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a1_9 & (~temp_a0_16 & 0xFF));
                                } else {
                                    (*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a1_9 | (temp_a0_16 & 0xFF));
                                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x29)));
                                    (*(u8 *)((u8 *)(reg_a6) + (0x29))) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        (*(u8 *)((u8 *)(reg_a6) + (0x29))) = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                                        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
                                    }
                                    reg_tmp.w = 1;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                    D_0028E484.w += reg_tmp.w;
                                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) D_0028E484.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = D_0028E484.h[0];
                                    reg_tmp.w = 0x1AA;
                                    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                                    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
                                    if (reg_tmp.w == D_0028E484.w) {
                                        reg_tmp.w = 0x1A6;
                                        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
#ifdef DEATH_LABEL
                            case 36:                /* switch 1 */
                                temp_v1_42 = (*(u8 *)((u8 *)(reg_a6) + (0x29)));
                                if (temp_v1_42 != 0) {
                                    (*(u8 *)((u8 *)(reg_a6) + (0x29))) = (u8) (temp_v1_42 - 1);
                                    if ((*(u8 *)((u8 *)(reg_a6) + (0x29))) == 0) {
                                        func_00203330();
                                        if (D_0028E408 == 0) {
                                            func_00202760();
                                            if (D_0028E88C == 0) {
                                                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                                                reg_d1.b[0] += 0xB0;
                                            }
                                            reg_d0.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                            reg_d3.w = 0;
                                            reg_d4.w = 0;
                                            func_00129450();
                                        }
                                    }
                                }
                                temp_v1_43 = (*(u8 *)((u8 *)(reg_a6) + (0x18)));
                                if (temp_v1_43 == 0) {
                                    reg_d0.w = 0x297;
                                    reg_d1.w = 0x287;
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
                                    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
                                    if (reg_tmp.w == reg_d0.w) {
                                        (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d1.h[1];
                                        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x18))) = (u8) (temp_v1_43 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
#endif
                            case 2:                 /* switch 1 */
                            case 21:                /* switch 1 */
                                if (D_0028E3EC != 0) {
                                    reg_a0 = reg_a6 + 0x12;
                                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_a0 += 2;
                                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_a0 += 2;
                                    reg_a1 = (u8 *) reg_tmp.w;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)(reg_a0 + 0);
                                    reg_d0.h[0] -= 4;
                                    reg_d0.h[0] &= 0xC;
                                    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d0.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
    }
}

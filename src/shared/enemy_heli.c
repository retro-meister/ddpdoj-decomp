#include "common.h"

void func_00150F40(void);

extern s8 D_0028E408;

s32 func_0013A780();
s32 func_0018D540();
s32 func_001A9000();
s32 func_001A91A0();
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00150510(u32 arg0) {
    s32 func_0014E290();
    u8 temp_a0;
    u8 temp_a1;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2A)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = arg0;
            func_001A91A0();
            reg_d0.w = 2;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            reg_d0.b[0] += 8;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] *= 4;
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            func_0018D540();
            func_0014E290();
            D_0028E408 = 1;
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
block_4:
    D_0028E408 = 0;
}

extern u16 D_002579D0[];

void func_00150670(u8 arg0) {
    reg_d2.w = 0;
    reg_d2.b[0] = arg0;
    reg_a0 = (u8 *)(D_002579D0);
    reg_d2.h[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
}

void func_00150730(void) {
}

extern u16 D_0028E894;
extern u16 g_stage;

void func_00150740(void) {
    s32 func_0014E290(u16);
    if ((g_stage == 1) && (D_0028E894 != 0)) {
        func_0014E290(g_stage);
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}

extern u16 D_0028E858;

void func_00150790(void) {
    s32 func_0014E290(u16);
    if ((g_stage == 2) && (D_0028E858 != 0)) {
        func_0014E290(g_stage);
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}

s32 func_0014D220(void);
s32 func_0019C530(void);
s32 func_0019C570(void);
extern u8 D_00257880[];
extern u16 D_0028E3EC;
extern u16 D_0028E910;

void func_001507E0(void) {
    u32 offset;

    reg_a0 = reg_a6;
    func_0014D220();
    if (D_0028E3EC != 0) {
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0x7FFF + 0x7901;
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d3.h[0] = 0x828;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
        reg_d2.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(D_00257880 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_00257880;
        offset = reg_d2.h[0] + 2;
        reg_d2.h[0] = (offset != 0) ? *(u16 *)(D_00257880 + ((s16)offset & ~1)) : *(u16 *)D_00257880;
        func_0019C570();
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 0xF;
    block_rts:
        return;
    }
    if (D_0028E910 != 0) {
        goto block_rts;
    }
    switch (g_stage) {
    case 2:
        return;
    }
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += 0x7FFF + 0x6C01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2C);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2E);
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d4.b[0] = 0x18;
    func_0019C530();
}


extern void func_001713F0(s32);

void func_001509C0(void) {
    func_001713F0(0);
}


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_002036F0();
extern u16 D_00257890[];
extern u16 D_002578B0[];
extern u16 D_002578D0[];
extern u16 D_00257950[];
extern u16 D_0028E880;
extern u16 D_0028E884;
extern u16 D_0028E888;
extern u16 D_0028E88C;
extern u16 D_0028E890;
extern u16 D_0028E8CC;
extern s8 enemy_move_end_requested;

void func_001509D0(void) {
    s32 func_0014E290();
    func_00150740();
    if ((D_0028E408 == 0) && (reg_a0 = (u8 *)D_002578B0, func_0014E370(), reg_a0 = (u8 *)D_00257890, reg_d0.h[0] = 0xC, func_0014E300(), (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B))), func_0014E7E0(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
            func_002036F0();
        }
        reg_d0.h[0] = D_0028E8CC;
        reg_d0.b[0] -= 8;
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (D_0028E890 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E88C != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E888 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E884 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E880 != 0) {
                func_0014E290();
            }
        }
    }
}

s32 func_00128AC0();
s32 func_00171430();
s32 func_00201C60();
s32 func_00202180();
s32 func_00202490();
s32 func_00202D50();
extern u16 D_0028E8A0;
extern u16 D_0028E8D8;

void func_00150C50(void) {
    u16 temp_a0_2;
    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        if (D_0028E8A0 != 0) {
#ifndef DEATH_LABEL
            func_00150F40();
#endif
            return;
        }
        func_00201C60();
        if ((*(u16 *)((u8 *)(reg_a5) + (0x28))) != 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
                func_00202490();
                if (D_0028E408 != 0) {
                    func_00150F40();
                    return;
                }
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                goto block_21;
            }
        }
block_21:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((s32) reg_tmp.b[0] > 0) {
            func_00150F40();
            return;
        }
        reg_d0.w = 0x58;
        reg_d0.h[0] -= D_0028E8D8;
        reg_d0.h[0] += 2;
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
        func_00202D50();
        if (D_0028E408 != 0) {
            func_00150F40();
            return;
        }
        func_00202180();
        if (D_0028E408 != 0) {
            func_00150F40();
            return;
        }
        func_00150670(*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_tmp.h[0] = temp_a0_2;
        reg_d0.w = 0x3000D;
        reg_d2.w += reg_tmp.w;
        func_00150730();
        reg_d3.w = 0;
        func_00128AC0();
        func_00150F40();
    }
}

s32 func_0019BFC0();                            /* extern */

void func_00150F40(void) {
    func_0019BFC0();
    func_001507E0();
}

s32 func_0019BFC0();

void func_00150F70(void) {
    reg_a0 = (u8 *)(D_002578D0);
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_00257950);
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_0019BFC0();
    func_001507E0();
}

void func_001510C0(void) {
    func_001713F0(0);
}

extern u16 D_00257A50[];
extern u16 D_00257A70[];

void func_001510D0(void) {
    func_00150740();
    if (D_0028E408 == 0) {
        func_00150790();
        if (D_0028E408 == 0) {
            reg_a0 = (u8 *)(D_00257A70);
            func_0014E370();
            reg_a0 = (u8 *)(D_00257A50);
            reg_d0.h[0] = 0xA;
            func_0014E300();
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
            func_0014E7E0();
            if (enemy_move_end_requested == 0) {
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
                    func_002036F0();
                }
                reg_d0.h[0] = D_0028E8CC;
                reg_d0.b[0] -= 8;
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
            }
        }
    }
}

s32 func_0014EA50();

void func_001512D0(void) {
    u16 temp_a0_2;
    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        if (D_0028E8A0 != 0) {
            func_00150F40();
            return;
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) {
            func_00201C60();
            goto block_7;
        }
        func_0014EA50();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) >= 0x40) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1U;
            }
            if (((*(u16 *)((u8 *)(reg_a5) + (0x28))) != 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
                    func_00202490();
                    goto block_13;
                }
            } else {
block_13:
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                func_00150F40();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 != 0) {
                func_00150F40();
                return;
            }
            func_00202180();
            if (D_0028E408 != 0) {
                func_00150F40();
                return;
            }
            func_00150670(*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            func_00128AC0();
            func_00150F40();
        }
    }
}

void func_00151600(void) {
    func_001713F0(0);
}

extern u16 D_00257A90[];
extern u16 D_00257AB0[];

void func_00151610(void) {
    func_00150740();
    if (D_0028E408 == 0) {
        func_00150790();
        if (D_0028E408 == 0) {
            reg_a0 = (u8 *)(D_00257AB0);
            func_0014E370();
            reg_a0 = (u8 *)(D_00257A90);
            reg_d0.h[0] = 0xA;
            func_0014E300();
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
            func_0014E7E0();
            if (enemy_move_end_requested == 0) {
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
                    func_002036F0();
                }
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d0.b[0] += 0x20;
                reg_d0.b[0] &= 0x3C;
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d0.b[0];
                func_00202180();
                if (D_0028E408 != 0) {
                    reg_d1.w = 0x20;
                }
                (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
                reg_d0.h[0] = D_0028E8CC;
                reg_d0.b[0] -= 8;
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
                if (g_stage == 2) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0xAU;
                }
            }
        }
    }
}

s32 func_00202500();
extern u16 D_0028E3E4;

void func_00151880(void) {
    func_00150510(8);
    if (D_0028E408 != 0) return;
    func_00171430();
    if (D_0028E408 != 0) return;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    if (D_0028E8A0 != 0) {
        func_00150F70();
        return;
    }
    func_00201C60();
    if ((*(u16 *)((u8 *)(reg_a5) + (0x26))) != 0) goto next_4;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) goto next_1;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0) goto next_1;
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 3;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0x10;
    reg_d1.h[0] = 0x3000;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    reg_d1.b[0] &= 0x3C;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x30;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x23))) == reg_d1.b[0]) goto next_1;
    if ((s32)(*(u8 *)((u8 *)(reg_a5) + (0x23))) < (s32)reg_d1.b[0]) goto next_0;
    (*(u8 *)((u8 *)(reg_a5) + (0x1E))) = 0xFC;
    goto next_1;
next_0:
    (*(u8 *)((u8 *)(reg_a5) + (0x1E))) = 4;
next_1:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    if (D_0028E3E4 != 0) goto next_2;
    func_00202180();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a5) + (0x22))) = reg_d1.b[0];
next_2:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0) goto next_7;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 1;
    goto next_7;
next_4:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0x1C) goto next_5;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
next_5:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) goto next_6;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d1.b[0] &= 0x3C;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    if ((*(u8 *)((u8 *)(reg_a5) + (0x23))) != reg_d1.b[0]) {
        func_00150F70();
        return;
    }
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1;
next_6:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00150F70();
    return;
next_7:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        func_00150F70();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= D_0028E8D8;
    reg_d0.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = reg_d0.b[0];
    func_00202D50();
    if (D_0028E408 != 0) {
        func_00150F70();
        return;
    }
    func_00202180();
    if (D_0028E408 != 0) {
        func_00150F70();
        return;
    }
    func_00150670(reg_d1.b[0]);
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    func_00128AC0();
    func_00150F70();
}

void func_00151C20(void) {
    func_001713F0(0);
}

extern u16 D_00257AD0[];
extern u16 D_00257AF0[];
extern u16 D_0028E878;
extern u16 D_0028E87C;

void func_00151C30(void) {
    s32 func_0014E290();
    func_00150740();
    if ((D_0028E408 == 0) && (func_00150790(), (D_0028E408 == 0)) && (reg_a0 = (u8 *)D_00257AF0, func_0014E370(), reg_a0 = (u8 *)D_00257AD0, reg_d0.h[0] = 0xA, func_0014E300(), (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B))), func_0014E7E0(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
            func_002036F0();
        }
        reg_d1.w = 0x20;
        func_00202180();
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = D_0028E8CC;
        reg_d0.b[0] -= 8;
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (D_0028E884 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E880 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E87C != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E878 != 0) {
                func_0014E290();
            }
        }
    }
}

#ifdef DEATH_LABEL
s32 func_00202490();
#endif

void func_00151EC0(void) {
    func_00150510(8);
    if (D_0028E408 != 0) return;
    func_00171430();
    if (D_0028E408 != 0) return;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    if (D_0028E8A0 != 0) {
        func_00150F70();
        return;
    }
    func_00201C60();
    if ((*(u16 *)((u8 *)(reg_a5) + (0x26))) != 0) goto next_4;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) goto next_1;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0) goto next_1;
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 0x10;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    reg_d1.b[0] &= 0x3C;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x30;
next_1:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    if (D_0028E3E4 != 0) goto next_2;
    func_00202180();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a5) + (0x22))) = reg_d1.b[0];
next_2:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0) goto next_7;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 1;
    goto next_7;
next_4:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == MAIN_OR_DEATH_LABEL(0x1C, 0x20)) goto next_5;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += MAIN_OR_DEATH_LABEL(1, 2);
next_5:
#ifdef DEATH_LABEL
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) goto next_6;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
    func_00202490();
    func_00150F70();
    return;
#else
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) goto next_6;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d1.b[0] &= 0x3C;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    if ((*(u8 *)((u8 *)(reg_a5) + (0x23))) != reg_d1.b[0]) {
        func_00150F70();
        return;
    }
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1;
#endif
next_6:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00150F70();
    return;
next_7:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        func_00150F70();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= D_0028E8D8;
    reg_d0.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = reg_d0.b[0];
    func_00202D50();
    if (D_0028E408 != 0) {
        func_00150F70();
        return;
    }
    func_00202180();
    if (D_0028E408 != 0) {
        func_00150F70();
        return;
    }
    func_00150670(reg_d1.b[0]);
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    func_00128AC0();
    func_00150F70();
}

void func_00152230(void) {
    func_001713F0(0);
}

extern u16 D_00257B10[];
extern u16 D_00257B30[];

void func_00152240(void) {
    func_00150740();
    if (D_0028E408 == 0) {
        reg_a0 = (u8 *)(D_00257B30);
        func_0014E370();
        reg_a0 = (u8 *)(D_00257B10);
        reg_d0.h[0] = 0xA;
        func_0014E300();
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
        func_0014E7E0();
        if (enemy_move_end_requested == 0) {
            reg_a0 = (u8 *)(D_002578D0);
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.h[0] &= 0x3E;
            reg_d1.h[0] += reg_d1.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_00257950);
            (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
                func_002036F0();
            }
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.b[0] += 0x20;
            reg_d0.b[0] &= 0x3C;
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d0.b[0];
            func_00202180();
            if (D_0028E408 != 0) {
                reg_d1.w = 0x20;
            }
            (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
            reg_d0.h[0] = D_0028E8CC;
            reg_d0.b[0] -= 8;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        }
    }
}

void func_00152480(void) {
    u16 temp_a0;
    u8 temp_v0;
    u8 *var_a0;

    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E8A0 != 0) {
            func_00150F70();
            return;
        }
        func_00201C60();
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a5) + (0x19))) == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 == 0) {
                func_00202180();
                if (D_0028E408 == 0) {
                    func_00150670(reg_d1.b[0]);
                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    func_00128AC0();
                }
            }
        }
        var_a0 = (u8 *)(reg_a5);
        if ((*(u16 *)((u8 *)(var_a0) + (0x26))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
            (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 1U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 2;
                    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0x3008;
                    var_a0 = (u8 *)((void *) (*(u8 *)((u8 *)(reg_a5) + (0x23))));
                    (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = (s8) var_a0;
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x30U;
                }
            }
        } else {
            temp_v0 = (*(u8 *)((u8 *)(var_a0) + (0x1B)));
            if (temp_v0 != 0) {
                (*(u8 *)((u8 *)(var_a0) + (0x1B))) = (u8) (temp_v0 - 1);
            } else if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0x20) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
                (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 2;
                }
            }
        }
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E3E4 != 0) {
            func_00150F70();
            return;
        }
        func_00202180();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        func_00202500();
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        func_00150F70();
    }
}

void func_001526F0(void) {
    func_001713F0(0);
}

extern u16 D_00257B50[];
extern u16 D_00257B70[];

void func_00152700(void) {
    func_00150740();
    if (D_0028E408 == 0) {
        reg_a0 = (u8 *)(D_00257B70);
        func_0014E370();
        reg_a0 = (u8 *)(D_00257B50);
        reg_d0.h[0] = 0xA;
        func_0014E300();
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
        func_0014E7E0();
        if (enemy_move_end_requested == 0) {
            reg_a0 = (u8 *)(D_002578D0);
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.h[0] &= 0x3E;
            reg_d1.h[0] += reg_d1.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_00257950);
            (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            func_00202180();
            if (D_0028E408 != 0) {
                reg_d1.w = 0x20;
            }
            (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
            if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
                func_002036F0();
            }
            reg_d0.h[0] = D_0028E8CC;
            reg_d0.b[0] -= 8;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        }
    }
}

void func_00152910(void) {
    u16 temp_a0;

    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E8A0 != 0) {
            func_00150F70();
            return;
        }
        func_00201C60();
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a5) + (0x19))) == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 == 0) {
                func_00202180();
                if (D_0028E408 == 0) {
                    func_00150670(*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    func_00128AC0();
                }
            }
        }
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E3E4 != 0) {
            func_00150F70();
            return;
        }
        func_00202180();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        func_00202500();
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        func_00150F70();
    }
}

void func_001713F0(s32);

void func_00152A80(void) {
    func_001713F0(0);
}

extern u16 D_00257B90[];
extern u16 D_00257BB0[];
extern s16 D_0028E8A8_as_s16;

void func_00152A90(void) {
    s32 func_0014E290();
    func_00150740();
    if ((D_0028E408 == 0) && (func_00150790(), (D_0028E408 == 0)) && (reg_a0 = (u8 *)D_00257BB0, func_0014E370(), reg_a0 = (u8 *)D_00257B90, reg_d0.h[0] = 0xA, func_0014E300(), (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B))), func_0014E7E0(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
            func_002036F0();
        }
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3C;
        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d0.b[0];
        func_00202180();
        if (D_0028E408 != 0) {
            reg_d1.w = 0x20;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = D_0028E8CC;
        reg_d0.b[0] -= 8;
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (D_0028E8A8_as_s16 >= 0x290) {
                if (D_0028E878 != 0) {
                    func_0014E290();
                }
            } else if (D_0028E8A8_as_s16 > 0x1FC) {
                if (((D_0028E8A8_as_s16 < 0x240) || (D_0028E8A8_as_s16 > 0x274)) && (D_0028E884 != 0)) {
                    func_0014E290();
                    return;
                }
                if ((D_0028E880 != 0) && (D_0028E8A8_as_s16 > 0x228)) {
                    func_0014E290();
                    return;
                }
                if (D_0028E87C != 0) {
                    func_0014E290();
                    return;
                }
                if (D_0028E878 != 0) {
                    func_0014E290();
                }
            }
        }
    }
}

void func_00152DA0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u8 temp_v1;

    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E8A0 != 0) {
            func_00150F70();
            return;
        }
        func_00201C60();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x29))) == 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x28)));
                func_00202D50();
                if (D_0028E408 == 0) {
                    func_00202180();
                    if (D_0028E408 == 0) {
                        func_00150670(*(u8 *)((u8 *)(reg_a5) + (0x22)));
                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_tmp.h[0] = temp_a0;
                        reg_d0.w = 0xD;
                        reg_d2.w += reg_tmp.w;
                        func_00150730();
                        reg_d3.w = 0;
                        func_00128AC0();
                    }
                }
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
            (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = 1U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 2;
                    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = 1U;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    reg_d1.b[0] &= 0x3C;
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x30U;
                    temp_v1 = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                    if (temp_v1 != reg_d1.b[0]) {
                        if ((s32) temp_v1 >= (s32) reg_d1.b[0]) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1E))) = 0xFC;
                        } else {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1E))) = 4;
                        }
                    }
                }
            }
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
            if (D_0028E3E4 != 0) {
                func_00150F70();
                return;
            }
            func_00202180();
            if (D_0028E408 != 0) {
                func_00150F70();
                return;
            }
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
            func_00202500();
            (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
            func_00150F70();
            return;
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x26))) != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x19))) == 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
                (*(u8 *)((u8 *)(reg_a5) + (0x26))) -= 1;
                func_00202D50();
                if (D_0028E408 == 0) {
                    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    reg_d1.b[0] = reg_d2.b[0];
                    func_00150670(reg_d1.b[0]);
                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_tmp.h[0] = temp_a0_2;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    func_00128AC0();
                }
            }
            goto block_33;
        }
        if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != 0x1C) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
            (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
            }
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                reg_d1.b[0] &= 0x3C;
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                if ((*(u8 *)((u8 *)(reg_a5) + (0x23))) != reg_d1.b[0]) {
                    func_00150F70();
                    return;
                }
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1U;
                goto block_33;
            }
        }
block_33:
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        func_00150F70();
    }
}

void func_00153190(void) {
    func_001713F0(0);
}

extern u16 D_00257BD0[];
extern u16 D_00257BF0[];
extern u16 D_0028E8D4;

void func_001531A0(void) {
    s32 func_0014E290();
    func_00150740();
    if ((D_0028E408 == 0) && (func_00150790(), (D_0028E408 == 0)) && (reg_a0 = (u8 *)D_00257BF0, func_0014E370(), reg_a0 = (u8 *)D_00257BD0, reg_d0.h[0] = 0xA, func_0014E300(), (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B))), func_0014E7E0(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        func_00202180();
        if (D_0028E408 != 0) {
            reg_d1.w = 0x20;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
            func_002036F0();
        }
        reg_d0.h[0] = D_0028E8D4;
        reg_d0.b[0] -= 8;
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (D_0028E884 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E880 != 0) {
                func_0014E290();
            }
        }
    }
}

void func_00153400(void) {
    u16 temp_a0_2;

    func_00150510(8);
    if ((D_0028E408 == 0) && (func_00171430(), (D_0028E408 == 0))) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        if (D_0028E8A0 != 0) {
            func_00150F70();
            return;
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) {
            func_00201C60();
            goto block_7;
        }
        func_0014EA50();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) >= 0x40) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 1U;
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) -= 0x40;
            }
            if (((*(u16 *)((u8 *)(reg_a5) + (0x28))) != 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                    (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
                    func_00202490();
                    if (D_0028E408 != 0) {
                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    }
                }
            }
            func_00202180();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
            func_00202500();
            (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                func_00150F70();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= D_0028E8D8;
            reg_d0.h[0] += 2;
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
            func_00202D50();
            if (D_0028E408 != 0) {
                func_00150F70();
                return;
            }
            func_00202180();
            if (D_0028E408 != 0) {
                func_00150F70();
                return;
            }
            func_00150670(reg_d1.b[0]);
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            func_00128AC0();
            func_00150F70();
        }
    }
}

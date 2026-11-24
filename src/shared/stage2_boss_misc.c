#include "common.h"

void func_001C45A0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_0014E370();                            /* extern */
extern s32 D_0026C570[];
extern s32 *reg_a0_as_s32_p;

void func_001C45B0(void) {
    reg_a0_as_s32_p = D_0026C570;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x23))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x22))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0x505;
    (*(s8 *)((u8 *)(reg_a5) + (0x2B))) = 0;
}


s32 func_0014E290();
s32 func_0019C570();
s32 func_00201C60();
s32 func_00203060();
extern u16 D_0028E574[];

void func_001C4650(void) {
    u16 temp_a2;

    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)))) != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFF;
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            func_0014E290();
        }
    }
    func_00203060();
    if (cond_flag != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_7;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_7:
    func_00201C60();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xF800FC00;
    reg_d3.h[0] = 0x820;
    reg_d4.h[0] = 0x1A;
    reg_a0 = (u8 *)(D_0028E574);
    reg_d2.w = 0;
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    if ((s16)(reg_d2.h[0]) > 0x20) {
        reg_d4.h[0] |= 0x40;
    }
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_0019C570();
}

void func_001C4820(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_0014E370();
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u16 D_0026C590[];

void func_001C4830(void) {
    reg_a0 = (u8 *)(D_0026C590);
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a0 = (u8 *)(D_0024EEF0);
    reg_d1.b[0] += 2;
    reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 2);
    reg_d1.h[0] &= 0x3E;
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = (u8) reg_d0.b[0];
    reg_a0 = (u8 *)(D_0024EC80);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0024EBC0_as_u16_a);
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
}

s32 func_0019D620();
s32 func_00201F20();

void func_001C4A10(void) {
    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= *(u8 *)(reg_a6 + 1)) != 0) {
        reg_d0.b[0] = 0xA3;
        *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
        *(s16 *)(reg_a6 + 0x18) = 0x7FFF;
    }
    func_00201F20();
    if (0 > *(s16 *)(reg_a6 + 2)) goto block_e1;
    if (*(s16 *)(reg_a6 + 2) > 0x7000) goto block_e1;
    if (0 > *(s16 *)(reg_a6 + 4)) goto block_e1;
    if (*(s16 *)(reg_a6 + 4) > 0x3800) goto block_e1;
    goto block_l1;
block_e1:
    func_0014E290();
block_l1:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
        *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 0xF;
    }
    func_0019D620();
}

void func_001C4BB0(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

extern u8 D_0026C5B0[];

void func_001C4BC0(void) {
    reg_a0 = D_0026C5B0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 2U;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0x20;
    (*(s16 *)((u8 *)(reg_a5) + (0x28))) = 4;
    (*(s16 *)((u8 *)(reg_a5) + (0x2C))) = 0x10;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) &= 0x3F;
    (*(u8 *)((u8 *)(reg_a5) + (0x31))) = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
}

s32 func_0013A780();
s32 func_0019BFC0();
extern u8 D_0028DB10[];

void func_001C4C90(void) {
    func_00203060();
    if (cond_flag != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201C60();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x28)));
        reg_d0.h[0] = 6;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2E)));
        reg_d0.w = 0xFFFA0007;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w = 1;
        reg_d3.w = 0;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.b[0] += 0x10;
        reg_d1.b[0] &= 0x3F;
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
        reg_a0 = D_0028DB10;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) &= 7;
    }
    func_0019BFC0();
}

void func_001C4EE0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_00202180();
extern u8 D_0026C5D0[];

void func_001C4EF0(void) {
    reg_a0 = D_0026C5D0;
    func_0014E370();
    *(u16 *)(reg_a6 + 2) = *(u16 *)(reg_a5 + 0x16);
    *(u16 *)(reg_a6 + 4) = *(u16 *)(reg_a5 + 0x18);
    *(u16 *)(reg_a6 + 0x1A) = *(u16 *)(reg_a5 + 0x1A);
    func_00202180();
    *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(s16 *)(reg_a5 + 0x1E) = 2;
    *(s16 *)(reg_a5 + 0x20) = 0;
}

s32 func_0013A780();                            /* extern */

void func_001C4F70(void) {
    extern s32 func_0014E290(u16);
    u16 temp_a0;

    reg_d0.h[0] = 3;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a0;
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    func_0014E290(temp_a0);
}

void func_001C4FC0(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

s32 func_0014E370();                            /* extern */
extern s32 D_0026C5F0[];

void func_001C4FD0(void) {
    reg_a0_as_s32_p = D_0026C5F0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0x202;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
}

s32 func_0019C470();
s32 func_00201B80();
extern u32 D_0026C610[];

void func_001C5030(void) {
    u16 temp_a1;
    u16 temp_a2;

    func_00203060();
    if (cond_flag != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201C60();
    func_00201B80();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
        if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0x20) {
            func_0014E290();
            return;
        }
    }
    reg_a0 = (u8 *)(D_0026C610);
    temp_a2 = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
    reg_a0 += temp_a2;
    reg_d2.w = *(u32 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0x17;
    func_0019C470();
}

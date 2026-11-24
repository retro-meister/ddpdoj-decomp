#include "common.h"

s32 func_001340B0();
s32 func_0013E6C0();
s32 func_0013E710();
s32 func_00141300();
s32 func_00141710();
s32 func_001417D0();
s32 func_00141B50();
s32 func_00145E70(u8 *);
s32 func_001ABCA0();
s32 func_001ABEA0();
extern u16 D_002555C0[];
extern u16 D_002555D0[];
extern u16 D_002555E0_as_u16_a[];
extern u16 D_002556E0[];
extern u16 D_002560C0[];
extern u16 D_0028C5F8[];
extern u16 D_0028C600[];
extern u16 D_0028C608_as_u16_a[];
extern u16 D_0028DFB4;
extern u16 D_0028DFB8;
extern u16 D_0028DFBC;
extern u16 D_0028DFC0;
extern u16 D_0028DFC4;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u8 D_0028E280;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E290;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u16 D_0028E5B4;
extern u16 D_0028E5B8;
extern u16 D_0028E5BC;
extern u16 D_0028E5C0;
extern u16 D_0028E5C4;
extern u16 D_0028E5C8;
extern u16 D_0028E5CC;
extern u16 D_0028E5D0;
extern u16 D_0028E5D8;
extern u16 D_0028E5DC;
extern u16 D_0028E5E0;
extern u16 D_0028E5E4;
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F0;
extern u16 D_0028E5F4;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E91C;
extern u8 D_0028ED80;
extern u8 D_0029F260_as_u8_a[];
extern u16 D_006E5BF0[];
extern u16 D_006E5BF2[];
extern u16 D_006E5BFC[];
extern u16 D_006E5C12[];
extern u16 D_006E5C14[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
extern u16 D_0028E810;
#endif

void func_001406F0(void) {
    s32 i;
    s32 val;
    s32 rem;
    s32 n;

    *(u16 *)reg_a2 = 0x8000;
    reg_a0 = (u8 *)D_002560C0;
    D_0028DFC0 = 0;
    D_0028DFC4 = 0;
    D_0028DFBC = 0;
    reg_a1 = reg_a6;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] |= *(u16 *)reg_a6;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x58);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x5A);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x20);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    reg_d2.b[0] = reg_a6[0x24];
    if (reg_a5[7] != 0) goto skip_1;
    reg_d5.w = 0x2F;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d5.h[0]) >= 0);
skip_1:
    *(u16 *)(reg_a6 + 0x58) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x5A) = reg_d0.h[0];
    reg_a6[0x56] = reg_a5[6];
    if (reg_a5[7] != 0) goto next_30;
    reg_d0.w = 0;
    *(u16 *)(reg_a3 + 0) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 4) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 6) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 8) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 0xA) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 0xC) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 0xE) = reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x5A);
    reg_a0 = (u8 *)D_0028C608_as_u16_a;
    reg_d0.h[0] -= 2;
    reg_a0 += reg_d0.h[0];
    reg_d0.b[0] = reg_a0[1];
    reg_a6[0x25] = reg_d0.b[0];
    reg_a6[0x24] = reg_a0[0];
    reg_a0 += 2;
    if (reg_d6.h[0] == 0) goto next_25;
    *(u16 *)(reg_a6 + 0x20) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 0x22) = reg_d1.h[0];
    reg_a6[0x25] = reg_d2.b[0];
    reg_a6[0x24] = reg_d2.b[0];
    if (reg_d4.h[0] != 0) goto next_30;
next_25:
    reg_a6[0x25] = reg_d0.b[0];
    reg_a6[0x24] = reg_d0.b[0];
    reg_d0.w = 0;
    *(u16 *)(reg_a6 + 0x20) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x58);
    reg_a2 = (u8 *)D_002555E0_as_u16_a;
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 2) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 4) = ((reg_d0.h[0] + 4) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 6) = ((reg_d0.h[0] + 6) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
next_30:
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    if (D_0028ED80 != 0) {
        func_00141300();
    }
    func_001340B0();
#ifdef DEATH_LABEL
    if (D_0028E3C0 != 0) {
        reg_d1.w = 0;
        reg_d1.h[0] = D_0028E810;
        *(u16 *)(reg_a6 + 0x20) = reg_d1.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d1.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += *(u16 *)(reg_a6 + 0x58);
        reg_a2 = (u8 *)D_002555E0_as_u16_a;
        reg_d0.h[0] <<= 2;
        *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 2) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 4) = ((reg_d0.h[0] + 4) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 6) = ((reg_d0.h[0] + 6) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
        reg_tmp.w += reg_d1.w;
        *(u16 *)(reg_a4 + 0) = reg_tmp.h[1];
        *(u16 *)(reg_a4 + 2) = reg_tmp.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
        reg_tmp.w += reg_d1.w;
        *(u16 *)(reg_a4 + 4) = reg_tmp.h[1];
        *(u16 *)(reg_a4 + 6) = reg_tmp.h[0];
    }
#endif
    if (D_0028E290 != 2) goto next_40;
    if (reg_d6.h[0] != 0) goto next_35;
    func_001417D0();
    goto next_36;
next_35:
    func_00141710();
next_36:
    func_00145E70(reg_a6);
next_40:
    if (D_0028ED80 == 0) goto next_76;
    if (reg_d6.h[0] == 0) goto next_41;
    if (D_0028E2C4 == 0) goto next_76;
next_41:
#ifndef DEATH_LABEL
    if (reg_a6 == D_0029F260_as_u8_a) {
        D_0028E02C = D_006E5C14[0];
    } else {
        D_0028E028 = D_006E5C14[0];
    }
#endif
    reg_d1.w = 0;
    reg_d1.h[0] = D_006E5BF2[0];
    *(u16 *)(reg_a6 + 0x20) = reg_d1.h[0];
    reg_d1.h[0] = D_006E5BF0[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d1.h[0];
    func_00145E70(reg_a6);
    D_0028E5C0 = 0;
    D_0028E5BC = 0;
    if (D_0028E2B0 != 0) goto next_60;
    for (i = 0; i < D_006E5BFC[0]; i++) {
        if (reg_a6 == D_0029F260_as_u8_a) {
            func_0013E6C0();
        } else {
            func_0013E710();
        }
    }
#ifdef DEATH_LABEL
    if (reg_a6 == D_0029F260_as_u8_a) {
        if (D_0028E2AC == 0) goto next_50;
        if (reg_d6.h[0] == 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            D_0028E5E4 = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                D_0028E5B8 = 4;
                D_0028E5E4 = 0x95F;
            } else {
                D_0028E5B8 = val / 100;
            }
        } else {
            val = D_0028E2AC & 0xFFFF;
            if (val >= 100) {
                D_0028E5B8 = 0;
                D_0028E5E4 = 0x95F;
            } else {
                D_0028E5B8 = 0;
                D_0028E5E4 = ((val % 100) * 0x960) / 100;
            }
        }
    } else {
        if (D_0028E2AC == 0) goto next_50;
        if (reg_d6.h[0] == 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            D_0028E5E0 = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                D_0028E5B4 = 4;
                D_0028E5E0 = 0x95F;
            } else {
                D_0028E5B4 = val / 100;
            }
        } else {
            val = D_0028E2AC & 0xFFFF;
            if (val >= 100) {
                D_0028E5B4 = 0;
                D_0028E5E0 = 0x95F;
            } else {
                D_0028E5B4 = 0;
                D_0028E5E0 = ((val % 100) * 0x960) / 100;
            }
        }
    }
#else
    if (reg_d6.h[0] != 0) goto next_45;
    if (D_0028E280 != 5) goto next_45;
    if (reg_a6 == D_0029F260_as_u8_a) {
        if (D_0028E5C0 != 0) {
            D_0028E5F4 = 0;
            D_0028E288 = 0x78;
        }
    } else if (D_0028E5BC != 0) {
        D_0028E5F0 = 0;
        D_0028E284 = 0x78;
    }
next_45:
    if (reg_a6 == D_0029F260_as_u8_a) {
        if (D_0028E2AC == 0) goto next_50;
        val = D_0028E2AC & 0xFFFF;
        rem = val % 100;
        D_0028E5E4 = (rem * 0x960) / 100;
        if (val == 0x1F4) {
            D_0028E5B8 = 4;
            D_0028E5E4 = 0x95F;
        } else {
            D_0028E5B8 = val / 100;
        }
        if (reg_d6.h[0] == 0) goto next_50;
        func_001ABCA0();
    } else {
        if (D_0028E2AC == 0) goto next_50;
        val = D_0028E2AC & 0xFFFF;
        rem = val % 100;
        D_0028E5E0 = (rem * 0x960) / 100;
        if (val == 0x1F4) {
            D_0028E5B4 = 4;
            D_0028E5E0 = 0x95F;
        } else {
            D_0028E5B4 = val / 100;
        }
        if (reg_d6.h[0] == 0) goto next_50;
        func_001ABEA0();
    }
#endif
next_50:
    if (reg_a6 == D_0029F260_as_u8_a) {
        D_0028E5EC = D_006E5C12[0];
    } else {
        D_0028E5E8 = D_006E5C12[0];
    }
    goto next_76;
next_60:
    if (reg_a6 == D_0029F260_as_u8_a) {
        D_0028E5EC = D_006E5C12[0];
    } else {
        D_0028E5E8 = D_006E5C12[0];
    }
    n = D_006E5BFC[0];
    if (n == 0) {
        n = 1;
    }
    if (reg_a6 == D_0029F260_as_u8_a) {
        D_0028E5C8 = 1;
        D_0028E5FC = 1;
        D_0028DFB8 = 1;
        reg_a6[0] |= 1;
        D_0028E5D0 = n;
        D_0028E5C0 = 0;
        if (D_0028E2AC != 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            D_0028E5E4 = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                D_0028E5B8 = 4;
                D_0028E5E4 = 0x95F;
            } else {
                D_0028E5B8 = val / 100;
            }
        }
        if (D_0028E2A8 != 0) {
            val = D_0028E2A8 & 0xFF;
            D_0028E5F4 = (val * 0x960) / 100;
        }
        D_0028E5DC = 0;
    } else {
        D_0028E5C4 = 1;
        D_0028E5F8 = 1;
        D_0028DFB4 = 1;
        reg_a6[0] |= 1;
        D_0028E5CC = n;
        D_0028E5BC = 0;
        if (D_0028E2AC != 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            D_0028E5E0 = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                D_0028E5B4 = 4;
                D_0028E5E0 = 0x95F;
            } else {
                D_0028E5B4 = val / 100;
            }
        }
        if (D_0028E2A8 != 0) {
            val = D_0028E2A8 & 0xFF;
            D_0028E5F0 = (val * 0x960) / 100;
        }
        D_0028E5D8 = 0;
    }
next_76:
    reg_a6[0x3F] = 0xF0;
    if (D_0028E290 == 2) goto next_85;
    if (reg_d6.h[0] != 0) goto next_85;
    if (D_0028E91C == 0) goto next_85;
    if (D_0028ED80 == 0) goto next_85;
    reg_a6[0x3F] = 0;
next_85:
    reg_a0 = (u8 *)D_0028C5F8;
    if (reg_a5[6] != 0) {
        reg_a0 = (u8 *)D_0028C600;
    }
    *(u16 *)(reg_a6 + 2) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x1C) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a6[0x55] = reg_a0[1];
    reg_a6[0x54] = reg_a0[0];
    reg_a0 += 2;
    reg_a6[0x3A] = reg_a6[0x1C];
    reg_a6[0x57] = reg_a6[0x55];
    *(u16 *)(reg_a6 + 2) = *(u16 *)(reg_a5 + 8);
    *(u16 *)(reg_a6 + 4) = *(u16 *)(reg_a5 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x58);
    reg_a0 = (u8 *)D_002555C0;
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x10) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x12) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] <<= 1;
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x58);
    reg_d0.h[0] += reg_d2.h[0];
    reg_d2.h[0] <<= 1;
    reg_d1.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_002555D0;
    reg_a0 += reg_d0.h[0];
    reg_a6[0x1B] = reg_a0[1];
    reg_a6[0x38] = reg_a0[1];
    reg_a6[0x39] = reg_a0[0];
    reg_a0 = (u8 *)D_002556E0;
    reg_a0 += reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x2C) = *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x36) = *(u16 *)(reg_a0 + 2);
    reg_a0 += 4;
    func_00141B50();
}

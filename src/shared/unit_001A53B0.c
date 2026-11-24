#include "common.h"

void func_001A5AD0(void);
void func_001A5B50(void);
void func_001A5DD0(void);
void func_001A6050(void);
void func_001A6510(void);
void func_001A6650(void);
void func_001A68B0(void);
void func_001A6B70(void);
void func_001A6BE0(void);
void func_001A6C60(void);
void func_001A6E70(void);
void func_001A7080(void);
void func_001A7410(void);
void func_001A7520(void);
void func_001A77A0(void);
void func_001A7840(void);
void func_001A7B30(void);
void func_001A7C60(void);
void func_001A7D00(void);
void func_001A7E90(void);
void func_001A7EE0(void);
void func_001A8070(void);
void func_001A80C0(void);
void func_001A80D0(void);
void func_001A8510(void);
void func_001A8520(void);
void func_001A8970(void);
void func_001A89E0(void);
void func_001A8A40(void);
void func_001A8A60(void);
void func_001A8E00(void);

void func_001A53B0(void) {
}


void func_001A53C0(void) {
    func_001A53B0();
}

void func_0019D810(void);

void func_001A53D0() {
    func_0019D810();
}

void func_001A53E0(void) {
    func_0019D810();
}

void func_0019D840(void);

void func_001A53F0(void) {
    func_0019D840();
}

void func_001A5400(void) {
    extern void func_0011C4A0(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x54F000A;
    func_0011C4A0();
}

void func_001A5430(void) {
    extern void func_0011C4A0(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x54F000A;
    func_0011C4A0();
}

void func_001A5460(void) {
    extern void func_0011C4A0(void);
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    func_0011C4A0();
}

void func_001A5490(void) {
    void func_0011C4A0(void);
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    func_0011C4A0();
}

extern u8 D_0026BFD0[];
extern u8 D_0028DAE8[];
extern u16 D_0028E5C0;
extern u16 D_0028E5FC;
extern u16 D_0029F2B8[];

void func_001A54C0(void) {
    u32 save_d1;

    save_d1 = reg_d1.w;
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = D_0029F2B8[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0028DAE8;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d4.h[0] = 0;
loop_0:
    func_001A53F0();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.w = reg_d5.w;
next_0:
    if (D_0028E5FC != 0) goto next_1;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0x100;
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    reg_d2.h[0] = D_0028E5C0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BFD0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53D0();
next_1:
    reg_d1.w = save_d1;
}

extern u8 D_0028DAF0[];
extern u16 D_0028E5BC;
extern u16 D_0028E5F8;
extern u16 D_0029F248[];

void func_001A5600(void) {
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = D_0029F248[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0028DAF0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d4.h[0] = 1;
loop_0:
    func_001A53F0();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.w = reg_d5.w;
next_0:
    if (D_0028E5F8 != 0) goto next_1;
    reg_d1.h[0] += 0xF500;
    reg_d1.h[1] += 0x100;
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    reg_d2.h[0] = D_0028E5BC;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BFD0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53D0();
next_1:
    return;
}

extern u16 D_0028DAF8[];

void func_001A5740(arg0)
    u16 arg0;
{
    s32 func_0011C4A0();
    u16 var_a0;
    var_a0 = arg0;
    if ((s16) reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)(D_0028DAF8);
        reg_d4.h[0] = D_0029F2B8[0];
        reg_d4.h[0] += reg_d4.h[0];
        reg_d3.h[0] = 0;
        reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d5.h[0] = reg_d1.h[0];
        do {
            func_0011C4A0();
            var_a0 = (u32)reg_d1.h[0] + 0x100;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.h[0] = reg_d5.h[0];
    }
}

extern u16 D_0028DB00[];

void func_001A5850(void) {
    extern void func_0011C4A0(void);
    if ((s16)reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)D_0028DB00;
        reg_d4.h[0] = D_0029F248[0];
        reg_d4.h[0] += reg_d4.h[0];
        reg_d3.h[0] = 0;
        reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d5.h[0] = reg_d1.h[0];
        do {
            func_0011C4A0();
            reg_d1.h[0] -= 0x100;
        } while ((s16)--reg_d7.h[0] >= 0);
        reg_d1.h[0] = reg_d5.h[0];
    }
}

extern s16 D_0028E8C4_as_s16;

void func_001A5960(void) {
    if (D_0028E8C4_as_s16 >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        func_001A80D0();
    }
}

extern s16 D_0028E8C0_as_s16;

void func_001A59B0(void) {
    if (D_0028E8C0_as_s16 >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        func_001A8520();
    }
}

extern u16 D_0028E648;
extern u16 D_0028E6D8;

void func_001A5A00(void) {
    if (D_0028E6D8 != 0) {
        D_0028E6D8 -= 1;
        D_0028E648 += 1;
        if (D_0028E6D8 != 0) {
            D_0028E6D8 -= 1;
            D_0028E648 += 1;
            if (D_0028E6D8 != 0) {
                D_0028E6D8 -= 1;
                D_0028E648 += 1;
                if (D_0028E6D8 != 0) {
                    D_0028E648 += 1;
                    D_0028E6D8 -= 1;
                }
            }
        }
    }
}

extern u16 D_0028E59C;

void func_001A5A80(void) {
    func_001A89E0();
    func_001A8970();
    if (D_0028E59C != 0) {
        func_001A68B0();
        return;
    }
    func_001A5AD0();
}

extern u8 D_0028E854;
extern u8 D_0028E961;

void func_001A5AD0(void) {
    func_001A7D00();
    func_001A7EE0();
    func_001A5A00();
    if (D_0028E854 & 1) {
        func_001A6050();
        return;
    }
    if (D_0028E961 & 8) {
        func_001A6050();
        return;
    }
    func_001A5B50();
}

extern u16 D_0028E074;
extern u16 D_0028E3F0;
extern u8 D_0028E5DC_as_u8;
extern u8 D_0028E5DD;
extern u16 D_0028E614;
extern s8 D_0028E634;
extern u16 D_0028E69C;
extern u32 D_0028E6AC_as_u32;
extern u16 D_0028E6B0;
extern u16 D_0028E6B4;
extern u16 D_0028E6B8_as_u16;
extern u16 D_0028E6C8;
extern u32 D_0028E6D0_as_u32;
extern u32 D_0028E6F0_as_u32;
extern u32 D_0028E6FC_as_u32;
extern u8 D_0028E70C;
extern u16 D_0029CD9E[];
extern u8 D_0029F261[];
void func_001A5B50(void) {
    if (D_0028E8C4_as_s16 < 0) {
        func_001A5DD0();
        return;
    }
    func_001A80C0();
    if (!(D_0028E854 & 1) || (D_0028E634 < 0)) {
        if (D_0028E5FC != 0) {
            if (!(D_0028E70C & 1)) {
                D_0028E70C |= 1;
                func_001A5400();
                func_001A5460();
            }
            reg_d1.w = 0x64C00400;
            reg_d2.w = D_0028E6FC_as_u32;
            func_001A8A40();
        } else {
            D_0028E70C &= 0xFE;
            if (D_0028E3F0 & 0x40) {
                if (!(D_0029F261[0] & 0x40) && (reg_d6.h[0] = D_0029CD9E[0], (D_0029CD9E[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= D_0028E3F0;
                    if ((s32) reg_d0.h[0] < 0x14) {
                        func_001A5400();
                        reg_d1.w = 0x64C00400;
                        reg_d2.w = D_0028E6F0_as_u32;
                        func_001A8A40();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x200;
                        reg_d5.h[0] = D_0028E074;
                        func_001A8A60();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x200;
                reg_d6.h[0] = D_0028E614;
                func_001A8E00();
            }
        }
    }
    if (D_0028E6B8_as_u16 != 0) {
        D_0028E6B8_as_u16 -= 1;
        reg_d1.h[0] = 0x40;
        reg_d6.w = 0;
        reg_d0.h[0] = D_0028E69C;
        reg_d6.h[0] = D_0028E6B0;
        D_0028E6B0 += 1;
        reg_d3.h[0] = D_0028E6B8_as_u16;
        if ((s32) reg_d3.h[0] < 0x2A) {
            reg_d3.h[0] -= 0x2A;
            reg_d3.h[0] <<= 7;
            reg_d1.h[0] += reg_d3.h[0];
        }
        reg_d2.h[0] = D_0028E6B4;
        if (D_0028E6B4 != 0) {
            D_0028E6B4 -= 1;
        }
        reg_d4.h[0] = 7;
        func_001A7520();
    }
    reg_d6.h[0] = D_0028E6C8;
    if (D_0028E6C8 != 0) {
        if (D_0028E5FC != 0) {
            D_0028E5DD -= 1;
            if ((s8) D_0028E5DD < 0) {
                D_0028E5DD = D_0028E5DC_as_u8;
                goto block_26;
            }
            goto block_29;
        }
block_26:
        D_0028E6C8 -= 1;
        if (D_0028E6C8 == 0) {
            reg_d0.w = 0;
            D_0028E6D0_as_u32 = reg_d0.w;
            D_0028E6AC_as_u32 = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC00000;
            reg_d4.h[0] = 9;
            func_001A7C60();
        }
    }
    func_001A5DD0();
}

extern u16 D_0028E070;
extern u8 D_0028E5D8_as_u8;
extern u8 D_0028E5D9;
extern u16 D_0028E610;
extern u16 D_0028E65C;
extern u32 D_0028E66C_as_u32;
extern u16 D_0028E670;
extern u16 D_0028E674;
extern u16 D_0028E678_as_u16;
extern u16 D_0028E688;
extern u32 D_0028E690_as_u32;
extern u8 D_0028E708;
extern u16 D_0029CD8E[];
extern u8 D_0029F1F1[];
void func_001A5DD0(void) {
    if (D_0028E8C0_as_s16 < 0) {
        func_001A6510();
        return;
    }
    func_001A8510();
    if (!(D_0028E854 & 1) || (D_0028E634 < 0)) {
        if (D_0028E5F8 != 0) {
            if (!(D_0028E708 & 1)) {
                D_0028E708 |= 1;
                func_001A5430();
                func_001A5490();
            }
            reg_d1.w = 0x64C02800;
            reg_d2.w = D_0028E6FC_as_u32;
            func_001A8A40();
        } else {
            D_0028E708 &= 0xFE;
            if (D_0028E3F0 & 0x40) {
                if (!(D_0029F1F1[0] & 0x40) && (reg_d6.h[0] = D_0029CD8E[0], (D_0029CD8E[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= D_0028E3F0;
                    if ((s32) reg_d0.h[0] < 0x2C) {
                        func_001A5430();
                        reg_d1.w = 0x64C02800;
                        reg_d2.w = D_0028E6F0_as_u32;
                        func_001A8A40();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x1400;
                        reg_d5.h[0] = D_0028E070;
                        func_001A8A60();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x1400;
                reg_d6.h[0] = D_0028E610;
                func_001A8E00();
            }
        }
    }
    if (D_0028E678_as_u16 != 0) {
        D_0028E678_as_u16 -= 1;
        reg_d1.h[0] = 0x1FC0;
        reg_d6.w = 0;
        reg_d0.h[0] = D_0028E65C;
        reg_d6.h[0] = D_0028E670;
        D_0028E670 += 1;
        reg_d3.h[0] = D_0028E678_as_u16;
        if ((s32) reg_d3.h[0] < 0x2A) {
            reg_d3.h[0] -= 0x2A;
            reg_d3.h[0] <<= 7;
            reg_d1.h[0] -= reg_d3.h[0];
        }
        reg_d2.h[0] = D_0028E674;
        if (D_0028E674 != 0) {
            D_0028E674 -= 1;
        }
        reg_d4.h[0] = 8;
        func_001A7520();
    }
    reg_d6.h[0] = D_0028E688;
    if (D_0028E688 != 0) {
        if (D_0028E5F8 != 0) {
            D_0028E5D9 -= 1;
            if ((s8) D_0028E5D9 < 0) {
                D_0028E5D9 = D_0028E5D8_as_u8;
                goto block_26;
            }
            goto block_29;
        }
block_26:
        D_0028E688 -= 1;
        if (D_0028E688 == 0) {
            reg_d0.w = 0;
            D_0028E690_as_u32 = reg_d0.w;
            D_0028E66C_as_u32 = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC03400;
            reg_d4.h[0] = 0x4009;
            func_001A7C60();
        }
    }
    func_001A6510();
}

s32 func_0018DD00();
s32 sprite_palette_load();
s32 func_001AC8C0();
s32 func_001AC8E0();
extern u8 D_00261C30[];
extern u8 D_00261C70[];
extern u8 D_0028E61D;
extern u8 *D_0028E620;
extern u32 D_0028E624_as_u32;
extern u16 D_0028E628;
extern u16 D_0028E62C;
extern u16 D_0028E630;
extern u8 D_0028E635;
extern u8 D_0028E855;
extern u16 g_loop;
extern u16 g_stage;
extern u16 D_0029CEA0[];

void func_001A6050(void) {
    s32 func_0011C4A0();
    s32 flag;
    s32 bits;

    if (D_0028E855 & 8) {
        func_001A6650();
        return;
    }
    flag = D_0028E635;
    if ((s8) flag < 0) goto next_160;
    bits = flag & 0xFF;
    if (bits & 0x10) goto next_120;
    if (bits & 8) goto next_80;
    if (bits & 1) goto next_40;
    D_0028E635 = flag | 1;
    D_0028E630 = 0x32;
    D_0028E628 = 8;
    D_0028E62C = 8;
    if (!(D_0028E635 & 2)) {
        D_0028E635 |= 2;
        goto next_20;
    }
    if (!(D_0028E635 & 4)) {
        D_0028E635 |= 4;
        goto next_20;
    }
    func_001AC8C0();
    func_001AC8E0();
    reg_a0 = (u8 *)D_00261C30;
    reg_d0.h[0] = 7;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261C70;
    reg_d0.h[0] = 8;
    sprite_palette_load();
    goto next_40;
next_20:
    D_0028E635 &= 0xFE;
next_40:
    reg_d1.h[0] = 0x5BC0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d3.h[0] = 0x840;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] -= 0x32;
    reg_d6.h[0] <<= 7;
    func_001A6B70();
    func_001A6BE0();
    func_001A6C60();
    D_0028E630 -= 1;
    if (D_0028E630 != 0x11) {
        func_001A6510();
        return;
    }
    D_0028E635 |= 8;
    D_0028E630 = 0x38;
    func_001A6510();
    return;
next_80:
    reg_d1.h[0] = 0x67C0;
    reg_d2.w = 0xCA2;
    reg_d3.h[0] = 0x2E0;
    reg_d4.h[0] = 9;
    reg_tmp.h[0] = D_0028E630;
    D_0028E630 -= 1;
    if (reg_tmp.h[0] == 0) goto next_100;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d1.h[0] += reg_d6.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    func_001A53D0();
    reg_d7.h[0] = 0xE00;
    reg_d7.h[0] -= reg_d6.h[0];
    func_001A5960();
    func_001A59B0();
    func_001A6C60();
    func_001A6510();
    return;
next_100:
    D_0028E635 = flag | 0x10;
    func_001A6C60();
    D_0028E630 = 0xFFE2;
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 1;
    reg_d3.w = 0x1B;
    reg_d4.w = 0x03B6000A;
    func_0011C4A0();
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
    func_001A6510();
    return;
next_120:
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
    D_0028E630 += 1;
    if ((s16) D_0028E630 < 0) {
        func_001A6510();
        return;
    }
    reg_d1.w = 0x67C00000;
    reg_d2.w = 0xCA1;
    reg_d3.h[0] = 0x200;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = D_0028E630;
loop_140:
    reg_d3.h[0] += 2;
    if ((s16) --reg_d6.h[0] >= 0) goto loop_140;
    if (D_0028E630 != 0x6F) goto next_280;
    D_0028E635 |= 0x80;
    goto next_180;
next_160:
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
next_180:
    reg_a0 = (u8 *)D_0028E620;
    reg_d7.h[1] = *(u16 *) (reg_a0 + 0);
    reg_d7.h[0] = *(u16 *) (reg_a0 + 2);
    if ((s32) reg_d7.w < 0) {
        func_001A6510();
        return;
    }
    reg_d4.h[0] = 9;
    if ((u32) reg_d7.w > 0x6FB8U) goto next_240;
    if (g_loop == 0) goto next_200;
    if (g_stage == 4) goto next_240;
next_200:
    reg_d4.h[0] = 0x19;
    reg_d2.h[0] = D_0029CEA0[0];
    if ((s16) reg_d2.h[0] >= 0) goto next_220;
    if (reg_d2.w & 1) goto next_240;
next_220:
    if (D_0028E61D & 1) goto next_240;
    D_0028E61D |= 1;
    func_0018DD00();
next_240:
    reg_d1.w = 0x67C001C0;
    reg_d2.w = 0xCA1;
    reg_d3.h[0] = 0x200;
    reg_d0.w = D_0028E624_as_u32;
loop_260:
    reg_tmp7.w = reg_d7.w;
    reg_d7.w -= reg_d0.w;
    if ((u32) reg_d0.w <= (u32) reg_tmp7.w) {
        reg_d3.h[0] += 1;
        goto loop_260;
    }
next_280:
    if (reg_d3.h[0] == 0x200) {
        func_001A6510();
        return;
    }
    func_001A53D0();
    func_001A6510();
}

s32 func_001AC320();
extern s16 D_0028E644;
extern u16 D_0028E64C;
extern u16 D_0028E650;
extern s16 D_0028E924_as_s16;
extern u16 D_0028E928;

void func_001A6510(void) {
    u32 flags;
    u32 hit;

    flags = D_0028E855;
    if (!(flags & 4)) goto next_7;
    hit = D_0028E648;
    if ((s16)hit >= 0) goto next_0;
    D_0028E64C -= 1;
    goto next_1;
next_0:
    D_0028E64C += 1;
next_1:
    if (flags & 0x40) goto next_4;
    if (D_0028E924_as_s16 < 0) goto next_6;
    if (D_0028E650 == 0) goto next_7;
    D_0028E650 -= 1;
    if (D_0028E650 != 0) goto next_5;
    D_0028E644 = 8;
    D_0028E650 = 0xA;
    if (D_0028E928 != 0) goto next_3;
    D_0028E650 = 0x12;
next_3:
    D_0028E648 -= 1;
    if ((s16)D_0028E648 < 0) goto next_6;
    if (D_0028E648 != 0) goto next_5;
    func_001AC320();
    goto next_7;
next_4:
    switch (hit & 0xFFFF) {
    case 0:
        goto next_7;
    }
    if ((s16)D_0028E64C < 0) goto next_7;
    D_0028E644 = 7;
    D_0028E650 = 0;
next_5:
    func_001A7840();
    goto next_7;
next_6:
    D_0028E648 = 0;
    D_0028E650 = 0;
next_7:
    if (D_0028E855 & 8) {
        func_001A7080();
    }
}

s32 func_0011C7C0();
s32 func_001AC950();
s32 func_001AC9D0();
extern s16 D_0028E628_as_s16;
extern s16 D_0028E62C_as_s16;
extern u8 D_0028E634_as_u8;
extern s16 D_0028E684;
extern s16 D_0028E6B8;
extern s16 D_0028E6C4;

void func_001A6650(void) {
    u8 flags;

    flags = D_0028E634_as_u8;
    if ((s8)flags >= 0) goto next_0;
    func_001A5B50();
    return;
next_0:
    if (flags & 8) goto next_5;
    if (flags & 1) goto next_2;
    D_0028E634_as_u8 |= 1;
    D_0028E630 = 0x38;
    D_0028E628_as_s16 = 0x10;
    D_0028E62C_as_s16 = 8;
    if (!(D_0028E634_as_u8 & 2)) {
        D_0028E634_as_u8 |= 2;
        goto next_1;
    }
    if (!(D_0028E634_as_u8 & 4)) {
        D_0028E634_as_u8 |= 4;
        goto next_1;
    }
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 6;
    reg_d3.w = 0x1B;
    func_0011C7C0();
    goto next_2;
next_1:
    D_0028E634_as_u8 &= 0xFE;
next_2:
    func_001A6E70();
    reg_d1.h[0] = 0x75C0;
    reg_d2.w = 0xCA2;
    reg_d3.h[0] = 0x2E0;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    func_001A53D0();
    reg_d7.h[0] = reg_d6.h[0];
    func_001A5960();
    func_001A59B0();
    D_0028E630 -= 1;
    if (D_0028E630 != 0) {
        func_001A6510();
        return;
    }
    D_0028E634_as_u8 |= 8;
    D_0028E630 = 0x41;
    func_001A6510();
    return;
next_5:
    if (D_0028E648 == 0) goto next_7;
    reg_d6.h[0] = D_0028E630;
    if (D_0028E630 == 0) goto next_6;
    D_0028E630 -= 1;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d6.h[0] *= 0xFFFF;
next_6:
    func_001A6B70();
    func_001A6BE0();
    func_001A6E70();
    func_001A6510();
    return;
next_7:
    D_0028E634_as_u8 |= 0x80;
    D_0028E6C4 = 0;
    D_0028E684 = 0;
    D_0028E6B8 = 0;
    func_001A6E70();
    if (D_0028E8C4_as_s16 < 0) goto next_8;
    func_001AC950();
    func_001A5400();
next_8:
    if (D_0028E8C0_as_s16 < 0) {
        func_001A6510();
        return;
    }
    func_001AC9D0();
    func_001A5430();
    func_001A6510();
}

s32 func_001AA8F0();
s32 func_001AAA20();
s32 func_001AC3A0();
s32 func_001AC5F0();
extern s16 D_0028E59C_as_s16;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;

void func_001A68B0(void) {
    if (!(D_0028E854 & 1)) goto next_2;
    if ((s16)D_0028E8C4 < 0) goto next_0;
    func_001AA8F0();
    func_001AC3A0();
next_0:
    if ((s16)D_0028E8C0 < 0) goto next_1;
    func_001AAA20();
    func_001AC5F0();
next_1:
    D_0028E59C_as_s16 = 0;
    func_001A5AD0();
    return;
next_2:
    if (D_0028E630 == 0) goto next_7;
    D_0028E630 -= 1;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d6.h[0] *= 0xFFFF;
    reg_d0.h[0] = D_0028E8C4;
    if ((s16)D_0028E8C4 < 0) goto next_4;
    reg_tmp.w = reg_d0.h[0];
    reg_tmp.w -= 1;
    reg_d0.h[0] = reg_tmp.h[0];
    if (reg_tmp.h[1] != 0) goto next_3;
    if (reg_d0.h[0] <= 5) goto next_3;
    reg_d0.w = 5;
next_3:
    reg_d1.w = 0x5DC00500;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d3.h[0] = 0x208;
    func_001A54C0();
    func_001A6B70();
next_4:
    reg_d0.h[0] = D_0028E8C0;
    if ((s16)D_0028E8C0 < 0) goto next_6;
    reg_tmp.w = reg_d0.h[0];
    reg_tmp.w -= 1;
    reg_d0.h[0] = reg_tmp.h[0];
    if (reg_tmp.h[1] != 0) goto next_5;
    if (reg_d0.h[0] <= 5) goto next_5;
    reg_d0.w = 5;
next_5:
    reg_d1.w = 0x5DC03300;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d3.h[0] = 0x208;
    func_001A5600();
    func_001A6BE0();
next_6:
    return;
next_7:
    reg_d7.h[0] = D_0028E8C4;
    if ((s16)D_0028E8C4 < 0) goto next_10;
    reg_tmp7.w = reg_d7.h[0];
    reg_tmp7.w -= 1;
    reg_d7.h[0] = reg_tmp7.h[0];
    if (reg_tmp7.h[1] != 0) goto next_9;
    if (reg_d7.h[0] <= 5) goto next_8;
    reg_d7.w = 5;
next_8:
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x200;
    func_001A5740();
next_9:
    func_001AA8F0();
    func_001AC950();
    func_001A5400();
next_10:
    reg_d7.h[0] = D_0028E8C0;
    if ((s16)D_0028E8C0 < 0) goto next_13;
    reg_tmp7.w = reg_d7.h[0];
    reg_tmp7.w -= 1;
    reg_d7.h[0] = reg_tmp7.h[0];
    if (reg_tmp7.h[1] != 0) goto next_12;
    if (reg_d7.h[0] <= 5) goto next_11;
    reg_d7.w = 5;
next_11:
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x1900;
    func_001A5850();
next_12:
    func_001AAA20();
    func_001AC9D0();
    func_001A5430();
next_13:
    D_0028E59C_as_s16 = 0;
}

#pragma push
#pragma opt_propagation off


void func_001A6B70(void)
{
    if (D_0028E8C4_as_s16 >= 0) {
        u16 offset = reg_d6.h[0];
        u32 savedRegister;

        reg_d1.h[0] = 0x5BC0;
        reg_d2.w = 0xE65;
        reg_d3.h[0] = 0x840;
        reg_d4.h[0] = 9;
        savedRegister = reg_d1.w;
        reg_tmp1.w = savedRegister;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = 0;
        reg_d1.h[0] += offset;
        func_001A53D0(savedRegister);
        reg_d7.w = 0;
        func_001A80D0();
    }
}
#pragma pop


void func_001A6BE0(void) {
    if (D_0028E8C0_as_s16 >= 0) {
        u32 savedRegister;
        u16 savedLow;

        reg_d1.h[0] = 0x5BC0;
        savedRegister = reg_d1.w;
        savedLow = reg_d1.h[0];
        reg_d1.h[0] = 0x2800;
        reg_d2.w = 0xE63;
        reg_d3.h[0] = 0x840;
        reg_d4.h[0] = 9;
        reg_tmp1.w = savedRegister;
        reg_d1.h[1] = savedLow;
        reg_d1.h[0] -= reg_d6.h[0];
        func_001A53D0();
        reg_d7.w = 0;
        func_001A8520();
    }
}

void func_001A6C60(void) {
    reg_d1.h[0] = 0x5F80;
    reg_d6.h[0] = D_0028E628;
    reg_d6.h[0] <<= 7;
    if ((D_0028E635 & 8) && ((s32) D_0028E630 < 0xD)) {
        D_0028E62C -= 1;
        if ((s16) D_0028E62C < 0) {
            D_0028E62C = 0;
        }
    }
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d0.h[0] = D_0028E8C4;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s16)(D_0028E8C4) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x100;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] += reg_d6.h[0];
        func_001A54C0();
        if (D_0028E635 & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xC0;
            func_001A5740();
            func_001AA8F0();
        }
    }
    reg_d0.h[0] = D_0028E8C0;
    if ((s16)(D_0028E8C0) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x3700;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] -= reg_d6.h[0];
        func_001A5600();
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xC0;
            reg_d1.h[0] = 0x1B00;
            func_001A5850();
            func_001AAA20();
        }
    }
    D_0028E628 -= 1;
    if ((s16) D_0028E628 < 0) {
        D_0028E628 = 0;
    }
}

void func_001A6E70(void) {
    reg_d1.h[0] = 0x5DC0;
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] += reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((D_0028E634_as_u8 & 8) && ((s32) D_0028E630 < 0x11)) {
        D_0028E628 -= 1;
        if ((s16) D_0028E628 < 0) {
            D_0028E628 = 0;
        }
    }
    reg_d6.h[0] = D_0028E628;
    reg_d0.h[0] = D_0028E8C4;
    reg_d6.h[0] <<= 6;
    if ((s16)(D_0028E8C4) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x500;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] -= reg_d6.h[0];
        func_001A54C0();
        if ((s8) D_0028E634_as_u8 < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x200;
            func_001A5740();
            func_001AA8F0();
        }
    }
    reg_d0.h[0] = D_0028E8C0;
    if ((s16)(D_0028E8C0) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x3300;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] += reg_d6.h[0];
        func_001A5600();
        if ((s8) D_0028E634_as_u8 < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x1900;
            func_001A5850();
            func_001AAA20();
        }
    }
    D_0028E62C -= 1;
    if ((s16) D_0028E62C < 0) {
        D_0028E62C = 0;
    }
}

s32 func_0018DA10();
s32 func_0018DED0();
s32 func_001A9180();
s32 func_001A9190();
s32 func_001A97F0();
extern s8 D_0028E2A0_as_s8;
extern s8 D_0028E2A4_as_s8;
extern u32 D_0028E638_as_u32;
extern u32 D_0028E63C_as_u32;
extern u16 D_0028E640;
extern u8 D_0028ED80;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001A7080(void) {
    u8 flags;
    u8 *p;

    flags = D_0028E854;
    switch (flags & 8) {
    case 0:
        return;
    }
    if (flags & 0x10) goto next_0;
    D_0028E854 = flags | 0x10;
    D_0028E640 = 7;
    reg_a0 = (u8 *)&D_0028E640;
    reg_d0.w = D_0028E638_as_u32;
    reg_d0.w <<= 4;
    func_001A97F0();
next_0:
    if (!(D_0028E854 & 4)) {
        func_001A7B30();
        return;
    }
    if (D_0028E854 & 2) {
        func_001A7B30();
        return;
    }
    func_001A7410();
    if (cond_flag != 0) goto next_6;
    D_0028E640 -= 1;
    if ((s16)D_0028E640 >= 0) goto next_9;
    if (D_0028E63C_as_u32 == 0) goto next_1;
    func_0018DA10();
next_1:
    reg_d0.w = 0x10;
    reg_d0.h[0] -= D_0028E648;
    if ((s16)reg_d0.h[0] < 0) goto next_2;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] += 1;
    goto next_3;
next_2:
    reg_d0.w = 0;
next_3:
    D_0028E640 = reg_d0.h[0];
    reg_d7.w = 0;
    if (D_0028E648 < 0x32) goto next_4;
    D_0028E648 -= 1;
    reg_d7.w = 1;
next_4:
    if (D_0028E648 < 0x64) goto next_5;
    D_0028E648 -= 1;
    reg_d7.w = 2;
next_5:
    if (D_0028E648 < 0x96) goto next_7;
    D_0028E648 -= 1;
    reg_d7.w = 3;
next_7:
    reg_tmp.w = 0;
    reg_tmp.h[0] = D_0028E648;
    D_0028E648 -= 1;
    reg_tmp.w -= 1;
    if (D_0028E648 == 0) goto next_6;
    if ((s16)D_0028E648 >= 0) goto next_8;
    if (reg_tmp.h[1] != 0) goto next_10;
    D_0028E2A0_as_s8 = 0;
    D_0028E2A4_as_s8 = 0;
    D_0028E854 |= 2;
    if (D_0028ED80 == 0) goto next_11;
    D_0028E2A4_as_s8 = 0x78;
    func_0018DED0();
    goto next_12;
next_11:
    if (g_stage == 4) goto next_12;
    D_0028E2A4_as_s8 = 0x78;
    func_0018DED0();
next_12:
    reg_d0.w = 0;
    D_0028E648 = reg_d0.h[0];
    D_0028E640 = reg_d0.h[0];
    D_0028E63C_as_u32 = reg_d0.w;
    func_001A7B30();
    return;
next_10:
    D_0028E640 = 8;
    D_0028E64C = 0xFFFF;
    goto next_9;
next_6:
    D_0028E648 = 0xFFFF;
    D_0028E64C = 0x17;
    D_0028E640 = 0x12;
next_8:
    reg_d0.w = D_0028E638_as_u32;
    reg_d0.w >>= 8;
loop_0:
    p = (u8 *)&D_0028E640;
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
next_9:
    if (D_0028E648 == 0) goto next_13;
    if ((s16)D_0028E648 < 0) goto next_13;
    func_001A7B30();
    return;
next_13:
    if (D_0028E640 == 8) goto next_14;
    func_001A7B30();
next_14:
    reg_d1.w = D_0028E63C_as_u32;
    if (reg_d1.w == 0) goto next_15;
    func_0018DA10();
    reg_d0.w = reg_d1.w;
    reg_d0.w >>= 4;
    if (D_0029F260[0] >= 0) goto next_16;
    func_001A9180();
next_16:
    if (D_0029F1F0[0] >= 0) goto next_17;
    func_001A9190();
next_17:
    reg_d0.w = 0;
    D_0028E63C_as_u32 = reg_d0.w;
next_15:
    func_001A7B30();
}

s32 func_0016A8B0();
s32 func_0016A8C0();
extern s8 D_0028EC24;
extern u8 D_0028ED7C;
void func_001A7410(void) {
    u32 temp_s0;
    u32 temp_v1;

    reg_d0.h[0] = D_0028E648;
    reg_d0.h[0] -= 1;
    if ((s16) reg_d0.h[0] < 0) {
        cond_flag = 0;
        return;
    }
    reg_d0.w = 0;
    if (D_0029F260[0] < 0) {
        func_0016A8B0();
        if ((D_0028ED7C == 2) && (D_0028EC24 == 1)) {
            func_0016A8C0();
        }
    }
    if (D_0029F1F0[0] < 0) {
        temp_s0 = reg_d0.h[0];
        func_0016A8C0();
        if ((D_0028ED7C == 2) && (D_0028EC24 == 0)) {
            func_0016A8B0();
        }
        reg_d0.h[0] |= temp_s0 & 0xFFFF;
    }
    temp_v1 = reg_d0.b[0] & 0x70;
    reg_d0.b[0] = temp_v1;
    if (!(temp_v1 & 0xFF)) {
        cond_flag = 0;
        return;
    }
    reg_d7.h[0] = D_0028E648;
    cond_flag = 1;
    D_0028E648 = 0;
    reg_d7.w -= 1;
}

s32 func_001A30A0();
extern u8 D_00261C50[];
extern u8 D_00261C90[];
extern u8 D_00261CD0[];
extern u8 D_0026B640[];
extern u8 D_0026B660[];
extern u16 D_0028E3EC;

void func_001A7520(void) {
    u32 save_d0;
    u32 save_d6;

    reg_d1.h[1] = 0x4FC0;
    reg_d3.h[0] = 0x610;
    reg_d5.w = 0xCCB;
    if (D_0028E3EC != 0) goto next_0;
    reg_d5.w = 0xCD5;
next_0:
    if (reg_d2.h[0] == 0) goto next_1;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261C50;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
    goto next_2;
next_1:
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261C90;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
    if (reg_d0.h[0] < 0x100) goto next_2;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261CD0;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
next_2:
    reg_d7.w = 3;
loop_0:
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] <<= 4;
    reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 12);
    reg_d2.w = 0xF;
    if ((reg_d2.h[0] &= reg_d0.h[0]) != 0) goto next_3;
    if ((s32)reg_d6.w < 0) goto next_3;
    if ((s16)reg_d1.h[0] > 0x1C00) goto next_7;
    goto next_8;
next_3:
    reg_d6.w |= 0x80000000;
    if (reg_d6.h[0] >= 0xC) goto next_5;
    reg_d5.w = 0;
    save_d6 = reg_d6.w;
loop_1:
    reg_tmp6.w = reg_d6.h[0];
    reg_tmp6.w -= 3;
    reg_d6.h[0] = reg_tmp6.h[0];
    if (reg_tmp6.h[1] != 0) goto next_4;
    reg_d5.h[0] += 4;
    goto loop_1;
next_4:
    reg_d6.w = save_d6;
    reg_a0 = (u8 *)D_0026B660;
    reg_a0 = *(u8 **)(reg_a0 + reg_d5.h[0]);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.w = *(u32 *)(reg_a0 + reg_tmp2.h[0]);
    goto next_6;
next_5:
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = *(u16 *)(D_0026B640 + (reg_d2.h[0] & ~1));
    reg_d2.w += reg_d5.w;
next_6:
    func_001A53F0();
next_7:
    reg_d1.h[0] += 0x480;
next_8:
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    func_001A77A0();
}

extern u8 D_0026B730[];

void func_001A77A0(void) {
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] = 0x4EC0;
    reg_d6.h[0] -= 0x17;
    if ((s16) reg_d6.h[0] >= 0) goto next_1;
    reg_d6.h[0] *= 0xFFFF;
    reg_a0 = (u8 *)D_0026B730;
    reg_d6.h[0] &= 0xFFFE;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *) (reg_a0 + reg_d6.h[0]);
    goto next_2;
next_1:
    reg_d2.w = 0xD78;
    if (D_0028E3EC != 0) goto next_2;
    reg_d2.w = 0xD78;
next_2:
    reg_d3.h[0] = 0x420;
    func_001A53E0();
}

s32 func_00200EE0();
extern u8 D_0026B760[];
extern u8 D_0026B800[];
extern u8 D_0026B870[];
extern u8 D_0028DAD0[];
extern u16 D_0028E644_as_u16;

void func_001A7840(void) {
    u32 save_d6;

    reg_d0.h[0] = D_0028E648;
    if ((s16)reg_d0.h[0] >= 0) goto next_0;
    reg_d0.w = 0;
next_0:
    func_00200EE0();
    reg_d0.w = reg_d2.w;
    reg_d1.w = 0x5BBFFE00;
    reg_d1.h[0] += 0x440;
    reg_d4.h[0] = D_0028E644_as_u16;
    reg_d6.w = 0;
    reg_d6.h[0] = D_0028E64C;
    reg_d7.w = 7;
loop_0:
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 28;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    if (reg_d2.h[0] != 0) goto next_1;
    if ((s32)reg_d6.w >= 0) goto next_5;
next_1:
    reg_d6.w |= 0x80000000;
    if (reg_d6.h[0] >= 0xC) goto next_3;
    reg_d5.w = 0;
    save_d6 = reg_d6.w;
loop_1:
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] -= 3;
    if ((s32)reg_tmp6.h[0] < 3) goto next_2;
    reg_d5.h[0] += 4;
    goto loop_1;
next_2:
    reg_d6.w = save_d6;
    reg_a0 = (u8 *)D_0026B760;
    reg_a0 = *(u8 **)(D_0026B760 + (reg_d5.h[0] & ~3));
    reg_d2.h[0] *= 4;
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    goto next_4;
next_3:
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 6;
    reg_d2.h[0] &= D_0028E3F0;
    reg_a0 = (u8 *)D_0028DAD0;
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0026B870;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 += reg_d5.h[0];
    reg_d2.w += *(u32 *)reg_a0;
next_4:
    reg_d3.h[0] = 0x610;
    func_001A53F0();
next_5:
    reg_d1.h[0] += 0x440;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.h[0] += 0xFE00;
    reg_d1.w -= 0x2000000;
    reg_d2.w = 0xE37;
    reg_d6.h[0] -= 0x1B;
    if ((s16)reg_d6.h[0] >= 0) goto next_6;
    reg_d6.h[0] *= 0xFFFF;
    reg_d6.h[0] &= 0xFFFE;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *)(D_0026B800 + (reg_d6.h[0] & ~3));
next_6:
    reg_d3.h[0] = 0x420;
    func_001A53E0();
}

s32 func_0019C670();
extern u8 D_0026BFA0[];

void func_001A7B30(void) {
    reg_d0.w = D_0028E63C_as_u32;
    reg_d1.w = 0x0E000C00;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x10;
    reg_a0 = (u8 *)D_0026BFA0;
    reg_d6.w = 0;
    reg_d7.w = 7;
loop_0:
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 28;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    if (reg_d2.h[0] != 0) goto next_0;
    if (reg_d7.h[0] == 0) goto next_0;
    if (reg_d6.h[0] == 0) goto next_1;
next_0:
    reg_d6.w = 1;
    reg_a0 = (u8 *)D_0026BFA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    func_0019C670();
next_1:
    reg_d1.h[0] += 0x400;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
}

extern u16 D_0028DAE0[];

void func_001A7C60(void) {
    reg_d2.h[0] = g_loop;
    reg_a0 = (u8 *) D_0028DAE0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = *(u8 **) (reg_a0 + reg_d2.h[0]);
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = 0;
    reg_d2.h[0] = (reg_d6.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_d3.h[0] = 0x810;
    reg_d2.w += 0xD7D;
    func_001A53E0();
}

s32 func_0013EA00();
s32 func_001AB920();
s32 func_001AB940();
s32 func_001AB9D0();
extern u8 D_0028E288;
extern u8 D_0028E370;
extern u16 D_0028E3B4;
extern u16 D_0028E5C8;
extern u16 D_0028E5D0;
extern s8 D_0028E5DC_as_s8;
extern s8 D_0028E5DD_as_s8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F4;
extern u16 D_0028E6A0;
extern u16 D_0028E6DC;
extern u8 D_0028EC4C;
void func_001A7D00(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (D_0028E5FC == 0) {
        if (D_0028E5C8 == 0) {
            func_001AB9D0();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F261[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            D_0028E5FC = 1;
            func_001AB920();
            func_001AA8F0();
            if (D_0028E6C8 != 0) {
                D_0028E6C8 = D_0028E6DC;
            }
            reg_d0.h[0] = D_0028E5C0;
            D_0028E5EC += reg_d0.h[0];
            D_0028E5D0 = reg_d0.h[0];
            if (D_0028E5EC > 0xF) {
                D_0028E5EC = 0xF;
            }
            D_0028E5DD_as_s8 = 0;
            D_0028E5DC_as_s8 = 0;
            D_0028E5C0 = 0;
            func_0013EA00();
            goto block_9;
        }
    } else {
block_9:
        func_001AB940();
        if (D_0029F261[0] & 1) {
            func_001A7E90();
            return;
        }
        if (((s32) D_0028E6A0 >= 0x10) && (D_0028E6C8 != 0)) {
            D_0028E6B4 = D_0028E6C8;
            D_0028E6B8 = 0x78;
            D_0028E6C4 = 0x78;
        }
        if (!(D_0028E855 & 0x40) && (D_0028E3B4 == 0) && (D_0028EC4C == 0) && (D_0028E370 != 0)) {
            D_0028E5F4 -= 2;
            if ((s16) D_0028E5F4 < 0) {
                func_001A7E90();
                if (D_0028E288 == 0x78) {
                    D_0028E288 = 0xA;
                }
            }
        }
    }
}

s32 func_0013EA70();                            /* extern */
s32 func_001AA8F0();                            /* extern */
s32 func_001ABB80();                            /* extern */
extern s16 D_0028E58C_as_s16;

void func_001A7E90(void) {
    if (D_0028E5FC != 0) {
        D_0028E58C_as_s16 = 0x48;
    }
    func_0013EA70();
    reg_d0.w = 0;
    D_0028E5FC = reg_d0.h[0];
    D_0028E5F4 = reg_d0.h[0];
    D_0028E5D0 = reg_d0.h[0];
    D_0028E5C8 = reg_d0.h[0];
    func_001AA8F0();
    func_001ABB80();
}

s32 func_0013EA30();
s32 func_001ABA50();
s32 func_001ABA70();
s32 func_001ABB00();
extern u8 D_0028E284;
extern u16 D_0028E5C4;
extern u16 D_0028E5CC;
extern s8 D_0028E5D8_as_s8;
extern s8 D_0028E5D9_as_s8;
extern u16 D_0028E5E8;
extern u16 D_0028E5F0;
extern u16 D_0028E660;
extern s16 D_0028E678;
void func_001A7EE0(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (D_0028E5F8 == 0) {
        if (D_0028E5C4 == 0) {
            func_001ABB00();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F1F1[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            D_0028E5F8 = 1;
            func_001ABA50();
            func_001AAA20();
            if (D_0028E688 != 0) {
                D_0028E688 = D_0028E6DC;
            }
            reg_d0.h[0] = D_0028E5BC;
            D_0028E5E8 += reg_d0.h[0];
            D_0028E5CC = reg_d0.h[0];
            if (D_0028E5E8 > 0xF) {
                D_0028E5E8 = 0xF;
            }
            D_0028E5D9_as_s8 = 0;
            D_0028E5D8_as_s8 = 0;
            D_0028E5BC = 0;
            func_0013EA30();
            goto block_9;
        }
    } else {
block_9:
        func_001ABA70();
        if (D_0029F1F1[0] & 1) {
            func_001A8070();
            return;
        }
        if (((s32) D_0028E660 >= 0x10) && (D_0028E688 != 0)) {
            D_0028E674 = D_0028E688;
            D_0028E678 = 0x78;
            D_0028E684 = 0x78;
        }
        if (!(D_0028E855 & 0x40) && (D_0028E3B4 == 0) && (D_0028EC4C == 0) && (D_0028E370 != 0)) {
            D_0028E5F0 -= 2;
            if ((s16) D_0028E5F0 < 0) {
                func_001A8070();
                if (D_0028E284 == 0x78) {
                    D_0028E284 = 0xA;
                }
            }
        }
    }
}

s32 func_0013EA90();                            /* extern */
s32 func_001AAA20();                            /* extern */
s32 func_001ABD80();                            /* extern */
extern s16 D_0028E588_as_s16;

void func_001A8070(void) {
    if (D_0028E5F8 != 0) {
        D_0028E588_as_s16 = 0x48;
    }
    func_0013EA90();
    reg_d0.w = 0;
    D_0028E5F8 = reg_d0.h[0];
    D_0028E5F0 = reg_d0.h[0];
    D_0028E5CC = reg_d0.h[0];
    D_0028E5C4 = reg_d0.h[0];
    func_001AAA20();
    func_001ABD80();
}


void func_001A80C0(void) {
    reg_d6.sw = 0;
    reg_d7.sw = 0;
    func_001A80D0();
}

extern u8 D_0026BDE0[];
extern u8 D_0026BEA0[];
extern u16 D_0028E5B0;
extern u16 D_0028E5B8;
extern u16 D_0028E5E4;

void func_001A80D0(void) {
    u32 t1;

    switch (D_0028E5FC) {
    case 0:
        goto next_0;
    }
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5F4;
    reg_d2.h[0] *= 0x16;
    reg_d2.h[1] = 0;
    reg_d2.h[0] /= 0x4B0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BDE0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    reg_tmp1.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x400;
    if (!(D_0028E854 & 1)) goto next_1;
    if (D_0028E634 < 0) goto next_1;
    if (D_0028E635 & 0x10) goto next_2;
    reg_d1.h[0] = 0x60C0;
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    reg_d0.h[0] = D_0028E628;
    reg_d0.h[0] <<= 7;
    reg_d1.h[0] += reg_d0.h[0];
    goto next_1;
next_2:
    if (D_0028E855 & 8) goto next_3;
    reg_d1.h[0] = 0x60C0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    goto next_1;
next_3:
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] = t1 + reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x400;
    reg_d0.h[0] = D_0028E628;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
next_1:
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    func_001A53D0();
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x1000;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d2.w = 0xCFF;
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    reg_d0.h[0] = D_0028E5B8;
    if (D_0028E5B8 == 0) goto next_4;
    reg_d0.h[0] -= 1;
loop_0:
    func_001A53F0();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
next_4:
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5E4;
    if (D_0028E5E4 == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)D_0026BEA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53E0();
    return;
next_0:
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x1000;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    if (D_0028E5B0 == 0) goto next_5;
    reg_d0.h[0] = D_0028E5B8;
    if (D_0028E5B8 == 0) goto next_5;
    reg_d0.h[0] -= 1;
    reg_d2.w = 0xCFF;
loop_1:
    func_001A53F0();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_1;
next_5:
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5E4;
    if (D_0028E5E4 == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)D_0026BEA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53E0();
}


void func_001A8510(void) {
    reg_d6.sw = 0;
    reg_d7.sw = 0;
    func_001A8520();
}

extern u8 D_0026BF20[];
extern u16 D_0028E5B4;
extern u16 D_0028E5E0;

void func_001A8520(void) {
    u32 t1;

    switch (D_0028E5F8) {
    case 0:
        goto next_0;
    }
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5F0;
    reg_d2.h[0] *= 0x16;
    reg_d2.h[1] = 0;
    reg_d2.h[0] /= 0x4B0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BDE0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    reg_tmp1.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x2800;
    if (!(D_0028E854 & 1)) goto next_1;
    if (D_0028E634 < 0) goto next_1;
    if (D_0028E635 & 0x10) goto next_2;
    reg_d1.h[0] = 0x60C0;
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2C00;
    reg_d0.h[0] = D_0028E628;
    reg_d0.h[0] <<= 7;
    reg_d1.h[0] -= reg_d0.h[0];
    goto next_1;
next_2:
    if (D_0028E855 & 8) goto next_3;
    reg_d1.h[0] = 0x60C0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2C00;
    goto next_1;
next_3:
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] = t1 + reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2800;
    reg_d0.h[0] = D_0028E628;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] += reg_d0.h[0];
next_1:
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    func_001A53D0();
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2600;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d2.w = 0xE3A;
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    reg_d0.h[0] = D_0028E5B4;
    if (D_0028E5B4 == 0) goto next_4;
    reg_d0.h[0] -= 1;
loop_0:
    func_001A53F0();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
next_4:
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5E0;
    if (D_0028E5E0 == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)D_0026BF20;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53E0();
    return;
next_0:
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2600;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    if (D_0028E5B0 == 0) goto next_5;
    reg_d0.h[0] = D_0028E5B4;
    if (D_0028E5B4 == 0) goto next_5;
    reg_d0.h[0] -= 1;
    reg_d2.w = 0xE3A;
loop_1:
    func_001A53F0();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_1;
next_5:
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5E0;
    if (D_0028E5E0 == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)D_0026BF20;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53E0();
}

extern s32 D_0026BA70[];
extern s32 D_0028E6FC;
extern u16 D_0028E700;
extern u8 D_0028E704_as_u8;
extern u8 D_0028E705;

void func_001A8970(void)
{
    s32 tableEntry;

    D_0028E705 -= 1;
    if ((s8)D_0028E705 < 0) {
        reg_a0 = (u8 *)D_0026BA70;
        D_0028E705 = D_0028E704_as_u8;
        reg_d0.h[0] = D_0028E700;
        tableEntry = *(s32 *)(reg_a0 + reg_d0.h[0]);
        D_0028E700 -= 4;
        D_0028E6FC = tableEntry;
        if ((s16)D_0028E700 < 0) {
            D_0028E700 = 0x38;
        }
    }
}

extern s32 D_0026BAB0[];
extern s32 D_0028E6F0;

void func_001A89E0(void) {
    reg_d0.w = 0x3F;
    reg_a0 = (u8 *)D_0026BAB0;
    reg_d0.h[0] &= D_0028E3F0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    D_0028E6F0 = *(s32 *)(reg_a0 + reg_d0.h[0]);
}


void func_001A8A40(void) {
    reg_d3.sh[0] = 0x430;
    reg_d4.sh[0] = 0x9;
    func_001A53E0();
}

s32 func_0011C610();
extern u8 D_0026BB60[];
extern u8 D_0026BB70[];
extern u8 D_0026BBA0[];
extern u8 D_0026BBD0[];

void func_001A8A60(void) {
    s32 func_0011C4A0();
    u32 save_d5;

    if (reg_d6.h[0] >= 0x10) goto next_1;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d6.h[0] += reg_d6.h[0];
    reg_a0 = (u8 *)D_0026BB70;
    reg_d4.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    func_0011C4A0();
    reg_d1.h[0] += 0x300;
next_0:
    reg_d4.h[0] = reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BB60;
    reg_tmp4.w = reg_d4.w;
    reg_d4.h[1] = (reg_tmp4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_tmp4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_tmp4.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_tmp4.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    reg_d5.w = 9;
    func_0011C610();
    return;
next_1:
    save_d5 = reg_d5.h[0];
    reg_d5.w = 0xC;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] <<= reg_d5.h[0];
    reg_d6.h[0] |= (u16)((s32)reg_tmp6.h[0] >> (0x10 - reg_d5.h[0]));
    reg_d5.w = 0xF;
    reg_d5.h[0] &= reg_d6.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BBA0;
    reg_d4.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((u16)reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 1;
    func_0011C4A0();
    reg_d1.h[0] += 0x200;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] <<= 4;
    reg_d6.h[0] |= (u16)((s32)reg_tmp6.h[0] >> 12);
    reg_d5.w = 0xF;
    reg_d5.h[0] &= reg_d6.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BBD0;
    reg_d4.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 0;
    reg_d5.w = 3;
    func_0011C610();
    reg_d1.h[0] += 0x100;
    reg_d5.h[0] = save_d5;
    goto next_0;
}

extern u16 D_0026BC00[];

void func_001A8E00(void) {
    s32 func_0011C4A0();
    u32 temp_a1;
    u32 temp_v1_2;
    u16 var_v0_2;
    u32 temp_s0;
    u32 temp_s1;

    reg_d2.w = 2;
    reg_d3.w = 5;
    reg_d4.w = 0x053D000A;
    func_0011C4A0();
    reg_d5.w = 0;
    reg_a1 = (u8 *)(D_0026BC00);
    reg_d7.w = 3;
    reg_d1.h[0] += 0x200;
    do {
        reg_tmp6.h[0] = reg_d6.h[0];
        reg_d2.w = 0xF;
        reg_d6.h[0] *= 0x10;
        temp_a1 = ((s32) reg_tmp6.h[0] >> 0xC) & 0xFFFF;
        reg_d6.h[0] |= temp_a1;
        temp_v1_2 = reg_d2.h[0] & reg_d6.h[0];
        reg_d2.h[0] = temp_v1_2;
        if ((temp_v1_2 & 0xFFFF) || (reg_d5.h[0] != 0)) {
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d4.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
            var_v0_2 = (((u16)reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            temp_s0 = reg_d2.w;
            temp_s1 = reg_d3.w;
            reg_d4.h[0] = var_v0_2;
            reg_d2.w = 2;
            reg_d5.w = 0xA;
            reg_d3.w = 0;
            func_0011C610();
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            reg_d5.w = 1;
        }
        reg_d1.h[0] += 0x100;
        reg_a1 += 0x28;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

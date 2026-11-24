#include "common.h"

void func_00171A30(void);
void func_00171B90(void);

extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a6_as_u16_p;

void func_00171490(void) {
    reg_a1_as_u16_p = reg_a6_as_u16_p;
    reg_d0.h[0] = 0xF;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u16 *reg_a4_as_u16_p;

void func_00171520(void) {
    reg_a1_as_u16_p = reg_a4_as_u16_p;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 func_00201D10();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_00171580(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) (*(u16 *)((u8 *)(reg_a6) + (0x10))) > (s32) reg_d0.h[0]) {
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) >>= 1;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) >>= 1;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if ((*(s16 *)((u8 *)(reg_a6) + (0x1E))) > (s16) reg_d0.h[0]) {
            (*(u16 *)((u8 *)(reg_a6) + (2))) = 0x3800U;
            (*(u16 *)((u8 *)(reg_a6) + (0x10))) = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

void func_00171670(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) (*(u16 *)((u8 *)(reg_a6) + (0x10))) > (s32) reg_d0.h[0]) {
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) >>= 1;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) >>= 1;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if ((*(s16 *)((u8 *)(reg_a6) + (0x1E))) > (s16) reg_d0.h[0]) {
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x16)));
            (*(u16 *)((u8 *)(reg_a6) + (0x10))) = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

s32 func_0019D650();
s32 func_0019D6D0();

void func_00171770(void) {
    func_0019D650();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (8)));
    reg_d1.h[1] += (*(u16 *)((u8 *)(reg_a6) + (6)));
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d2.w = 0x11C6;
    func_0019D6D0();
}

void func_00171820(void) {
    func_0019D650();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= *(u16 *)(reg_a6 + 2);
    reg_d0.h[1] = 0x1C00;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[1] -= *(u16 *)(reg_a6 + 4);
    reg_d0.h[1] += reg_d0.h[1];
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 8);
    reg_d1.h[0] += reg_d0.h[1];
    reg_d1.h[1] += *(u16 *)(reg_a6 + 6);
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0xE);
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d2.w = 0x11C4;
    func_0019D6D0();
}

extern s16 D_0028E798;
extern s16 D_0028E79C;
extern s16 D_0028E7A0;
extern s16 D_002BB458_as_s16_a[];
extern s16 D_002BB45A[];
extern s16 D_002BB45C[];
extern s16 D_002BB45E[];
extern s16 D_002BB460[];
extern u8 D_002BB470[];
void func_00171910(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BB470 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x40);
    D_0028E798 = 0;
    D_002BB458_as_s16_a[0] = 0;
    D_0028E79C = 0;
    D_002BB45A[0] = 0;
    D_0028E7A0 = 0;
    D_002BB45C[0] = 0;
    D_002BB45E[0] = 0;
    D_002BB460[0] = 0;
}

void func_00171990(void) {
    D_0028E798 = 1;
}

void func_001719A0(void) {
    D_0028E7A0 = 1;
}

extern s8 D_0028E408;
extern u16 D_0028E7A0_as_u16;

void func_001719B0(void) {
    if (D_0028E7A0_as_u16 != 0) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}

extern u16 D_0028E79C_as_u16;
extern s32 D_002BB458[];
extern s32 D_002BB470_as_s32_a[];
extern s32 *reg_a4_as_s32_p;
extern s32 *reg_a6_as_s32_p;

void func_001719D0(void) {
    reg_a6_as_s32_p = D_002BB470_as_s32_a;
    reg_a4_as_s32_p = D_002BB458;
    if (D_0028E79C_as_u16 != 0) {
        func_00171A30();
        return;
    }
    if (D_0028E7A0_as_u16 != 0) {
        func_00171B90();
    }
}

s32 func_001A3020();
extern u8 D_002554B0[];
extern u8 D_0026B170[];
extern u8 D_0026B180[];
extern u8 D_0028DAC0[];
extern s32 D_0028DC20;
extern u16 D_0028E798_as_u16;
extern u16 D_0028E918;
extern u8 *reg_a0;

void func_00171A30(void) {
    s32 temp_a1;
    s32 var_v0;
    u16 temp_a2;

    if ((*(s16 *)((u8 *)(reg_a6) + (0))) >= 0) {
        reg_a0 = (u8 *)D_0026B180;
        func_00171490();
        reg_a0 = (u8 *)D_0028DAC0;
        var_v0 = (s32) D_0028DC20 >> 1;
        if (D_0028DC20 < 0) {
            var_v0 = (s32) (D_0028DC20 + 1) >> 1;
        }
        reg_d0.w = var_v0 - 1;
        func_00171520();
        reg_d0.h[0] = D_0028E918;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(D_0026B170 + temp_a1);
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)D_002554B0;
        func_001A3020();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (0))) == 0) {
        if (D_0028E798_as_u16 != 0) {
            (*(s16 *)((u8 *)(reg_a4) + (2))) = 1;
            D_0028E79C = 0;
            (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
            return;
        }
        reg_d1.w = 0;
        reg_d2.w = 0x10AA;
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019D6D0();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != 0) {
        func_00171580();
    }
    func_00171770();
    reg_a6 += 0x20;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != 0) {
        func_00171670();
    }
    func_00171820();
}

s32 func_001ABB80();
s32 func_001ABD80();
extern u8 D_0026B1C0[];
extern u8 D_0026B1D0[];
extern u8 D_0028DAC8[];
extern u8 D_0028E370;
extern s16 D_0028E5B0_as_s16;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E91C;
extern u8 D_0028ED5C;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_00171B90(void) {
    s32 temp_a1;
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 var_a0;
    u8 *var_a0_2;

    if ((*(s16 *)((u8 *)(reg_a6) + (0))) >= 0) {
        reg_a0 = (u8 *)D_0026B1D0;
        func_00171490();
        reg_a0 = (u8 *)D_0028DAC8;
        reg_d0.w = 1;
        func_00171520();
        reg_d0.h[0] = D_0028E918;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(D_0026B1C0 + temp_a1);
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)D_002554B0;
        func_001A3020();
    }
    var_a0 = 1;
    if ((*(u16 *)((u8 *)(reg_a4) + (0))) == 0) {
        (*(s16 *)((u8 *)(reg_a4) + (2))) = 1;
        D_0028E5B0_as_s16 = 0;
        if ((D_0028ED7C != 2) || (D_0028E91C != 0)) {
            if ((D_0029F260[0] < 0) && (D_0028E5FC == 0)) {
                func_001ABB80();
            }
            if ((D_0029F1F0[0] < 0) && (D_0028E5F8 == 0)) {
                func_001ABD80();
            }
        }
        D_0028E7A0 = 0;
        (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
        return;
    }
    if ((D_0028E370 != 0) && ((var_a0 = D_0028ED7C, (var_a0 != 2)) || (D_0028ED5C == 0)) && ((D_0028ED80 == 0) || (D_0028ED5C == 0))) {
        var_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if (var_a0 != 0) {
            temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
            if (temp_v1 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) (temp_v1 - 1);
                goto block_25;
            }
            if (var_a0 != 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                func_00201D10();
                (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    (*(s16 *)((u8 *)(reg_a6) + (0x10))) = 0;
                    (*(u16 *)((u8 *)(reg_a4) + (0))) -= 1;
                }
                goto block_25;
            }
        }
    } else {
block_25:
        func_00171770();
    }
    var_a0_2 = (u8 *)(reg_a6 + 0x20);
    reg_a6 = var_a0_2;
    if ((D_0028E370 != 0) && ((var_a0_2 = (void *) D_0028ED7C, (var_a0_2 != (void *)2)) || (D_0028ED5C == 0)) && ((D_0028ED80 == 0) || (D_0028ED5C == 0))) {
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
        if (temp_a0 != 0) {
            temp_v1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
            if (temp_v1_2 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) (temp_v1_2 - 1);
                goto block_35;
            }
            if (temp_a0 != 0) {
block_35:
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                func_00201D10();
                (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
                var_a0_2 = (u8 *)(reg_a6);
                reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (0x16)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (4)));
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    (*(u16 *)((u8 *)(var_a0_2) + (0x10))) = 0U;
                    (*(u16 *)((u8 *)(reg_a4) + (0))) -= 1;
                }
                goto block_39;
            }
        }
    } else {
block_39:
        func_00171820();
    }
}

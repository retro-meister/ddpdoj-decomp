#include "common.h"
#include "sdk/ps2sdk.h"

void func_00125EC0(void);
void func_00125EF0(void);
void func_00125F00(void);
void func_00125FF0(void);
void func_00126F10(void);
void func_001273D0(void);
void func_00127400(void);
void func_001278A0(void);
void func_001278D0(void);
void func_00127CA0(void);
void func_00127FA0(void);
void func_00128130(void);
void func_00128320(void);
void func_001285A0(void);
void func_00128710();
void func_00128830();
void func_00128B00(void);
void func_00128B10(void);
void func_00128F70(void);
void func_001290B0();
void func_001291D0();
void func_00129450(void);
void func_00129460(void);
void func_00129A90(void);
void func_00129B70(void);

extern u16 D_0028E3EC;
extern u16 D_0028E988;

void func_00125590(u16 arg0) {
    extern void func_0019D290(u16);
    if (D_0028E988 >= 0x34) {
        reg_d0.w = 1;
        reg_d0.h[0] &= reg_d7.h[0];
        arg0 = D_0028E3EC;
        if (arg0 == reg_d0.h[0]) {
            return;
        }
    }
    func_0019D290(arg0);
}


void func_001255F0(void) {
    s32 func_0019D290();
    u16 t;

    if (D_0028E988 < 35) goto call;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] -= reg_d2.h[0];
    t = reg_d0.h[0];
    if (((s64) ((s64) t << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] = (t << 16) - t;
    }
    if (reg_d0.h[0] < 0x600) goto call;
    reg_d0.w = 1;
    reg_d0.h[0] &= reg_d7.h[0];
    if (D_0028E3EC != reg_d0.h[0]) {
call:
        func_0019D290();
        return;
    }
}

extern u16 D_0029C068[];

void func_001256C0(void) {
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] == 0) {
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.sw;
        reg_d0.h[0] += 0x7800;
    }
    cond_flag = 0;
    switch (reg_tmp.h[1]) {
    case 0:
        break;
    default:
        cond_flag = 1;
    }
}

extern u16 D_0028E8A0;
extern u16 *reg_a6_as_u16_p;
extern u16 D_0028E0E4[];
void func_001257B0(void) {
    if (D_0028E8A0 == 0) {
        reg_d0.h[0] = D_0028E0E4[0];
        reg_a6_as_u16_p[1] += reg_d0.h[0];
    }
}

void func_001257E0(void) {
    reg_d0.w = 0;
    reg_a6_as_u16_p[0] = (u16) reg_d0.h[0];
    reg_a6_as_u16_p[1] = (u16) reg_d0.h[0];
    D_0028E988 -= 1;
}

extern u16 D_0028E970;
extern u16 D_0028E978;
extern u16 *reg_a0_as_u16_p;

void func_00125810(void) {
    reg_a0_as_u16_p = &D_0028E978;
    if (!(reg_d1.w & 0x1000)) {
        reg_a0_as_u16_p = &D_0028E970;
    }
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

extern u16 D_0028E974;
extern u16 D_0028E97C;

void func_00125860(void) {
    reg_a0_as_u16_p = &D_0028E97C;
    if (!(reg_d1.w & 0x1000)) {
        reg_a0_as_u16_p = &D_0028E974;
    }
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

void func_001258B0(void) {
    reg_a0_as_u16_p = &D_0028E978;
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

void func_001258F0(void) {
    reg_a0_as_u16_p = &D_0028E970;
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

extern u16 D_0028E3E0;

void func_00125930(void) {
    s32 func_00201D10();
    if (D_0028E3E0 == 0) {
        if (D_0028E8A0 == 0) {
            *(u8 *)(reg_a6 + 0x1B) += 1;
        }
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
        reg_d1.w = 0x3F;
        reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x1A);
        func_00201D10();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
    }
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x20);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 4) += reg_d2.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
}

void func_00125A00(void) {
    (*(u8 *)((u8 *)(reg_a6) + (0x19))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x19))) < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x18)));
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_tmp.w += 1;
        (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBCF) {
            reg_tmp.w = 0xBBF;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00125AA0(void) {
    (*(u8 *)((u8 *)(reg_a6) + (0x19))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x19))) < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x18)));
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_tmp.w += 1;
        (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBDF) {
            reg_tmp.w = 0xBCF;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00125B40(void) {
    (*(u8 *)((u8 *)(reg_a6) + (0x19))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x19))) < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x18)));
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_tmp.w += 1;
        (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBEF) {
            reg_tmp.w = 0xBDF;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00125BE0(void) {
    (*(u8 *)((u8 *)(reg_a6) + (0x19))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x19))) < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x18)));
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_tmp.w += 1;
        (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBFF) {
            reg_tmp.w = 0xBEF;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00201E20(void);
void func_00202760(void);

void func_00125C80(void) {
    if (*(u8 *)(reg_a6 + 0x1F) == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        func_00202760();
        *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
        reg_d0.w = 0x40;
        func_00201E20();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        *(u8 *)(reg_a6 + 0x1F) = 1;
    }
    reg_d0.h[0] = D_0028E3E0;
    if ((reg_d0.b[0] &= *(u8 *)(reg_a6 + 0x1B)) == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(s16 *)reg_a0 >= 0) {
            func_001257E0();
            return;
        }
        func_00202760();
        if (*(u8 *)(reg_a6 + 0x1A) != reg_d1.b[0]) {
            *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
            reg_d0.w = 0x40;
            func_00201E20();
            *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
            *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        }
    }
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d3.h[0];
}

extern s16 D_0028E970_as_s16;
extern s16 D_0028E974_as_s16;
extern s16 D_0028E978_as_s16;
extern s16 D_0028E97C_as_s16;
extern s16 D_0028E980_as_s16;
extern s16 D_0028E984_as_s16;
extern s16 D_0028E988_as_s16;
extern u8 D_002BF4F0[];
void func_00125DE0(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BF4F0 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0xC08);
    D_0028E970_as_s16 = 0;
    D_0028E974_as_s16 = 0;
    D_0028E978_as_s16 = 0;
    D_0028E97C_as_s16 = 0;
    D_0028E980_as_s16 = 0;
    D_0028E984_as_s16 = 0;
    D_0028E988_as_s16 = 0;
}

extern u16 D_0028E984;

void func_00125E40(void) {
    reg_d0.w = 0;
    D_0028E984 = reg_d0.h[0];
    D_0028E97C = reg_d0.h[0];
    D_0028E978 = reg_d0.h[0];
}

void func_00125E60(void) {
    reg_d0.w = 0;
    D_0028E984 = reg_d0.h[0];
    D_0028E974 = reg_d0.h[0];
    D_0028E970 = reg_d0.h[0];
}

void func_00125E80(void) {
    reg_d0.w = 0;
    D_0028E984 = reg_d0.h[0];
    D_0028E97C = reg_d0.h[0];
    D_0028E978 = reg_d0.h[0];
    D_0028E974 = reg_d0.h[0];
    D_0028E970 = reg_d0.h[0];
}


void func_00125EA0(void) {
    D_0028E980_as_s16 = 0;
    func_00125E80();
}


void func_00125EB0(void) {
    reg_d1.w = 0;
    func_00125EC0();
}

void func_00125EC0(void) {
    reg_d2.h[0] = (u8)reg_d2.h[0];
    reg_d2.h[0] <<= 2;
    func_00125F00();
}


void func_00125EE0(void) {
    reg_d1.w = 0;
    func_00125EF0();
}


void func_00125EF0(void) {
    reg_d2.sw = 0;
    func_00125F00();
}

extern u8 *D_0028DE8C;
extern u32 D_0028DE90;
extern u16 D_002BF4F0_as_u16_a[];

void func_00125F00(void) {
    u32 tmp;

    D_0028DE90 = reg_d7.w;
    D_0028DE8C = reg_a0;
    reg_a0 = (u8 *) D_002BF4F0_as_u16_a;
    reg_d7.h[0] = 0x45;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00126F10();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x2C;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    cond_flag = 1;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

extern u16 D_0029C06C[];
extern s32 D_002BF4F0_as_s32_a[];
extern s32 *reg_a6_as_s32_p;

void func_00125FA0(void) {
    reg_d7.h[0] = D_0028E988;
    if (reg_d7.h[0] != 0) {
        reg_a6_as_s32_p = D_002BF4F0_as_s32_a;
        reg_d7.w -= 1;
        reg_d6.h[0] = D_0029C06C[0];
        func_00125FF0();
    }
}

typedef void (*Fn)();

extern u8 D_002693E0[];

void func_00125FF0(void) {
    u32 t1;

loop_1:
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
    if (reg_d1.h[0] == 0) {
        reg_a6 += 0x2C;
        goto loop_1;
    }
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d6.h[0];
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d1.h[0];
    if ((s8) reg_d1.b[0] < 0) {
        func_00127FA0();
        return;
    }
    ((Fn)*(u32 *)((u8 *)D_002693E0 + (reg_d0.h[0] & ~3)))();
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

s32 func_0018D930();
s32 func_001A9130();

void func_001260B0() {
    reg_d0.w = 1;
    func_00125810();
    reg_tmp.w = 0x50000;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    func_001A9130();
    func_0018D930();
    (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
    func_00127CA0();
}


void func_00126120(void) {
    void func_00125590(void);
    void func_001257E0(void);
    void func_00125930(void);
    void func_00125A00(void);
    if ((u16)(reg_d1.h[0] &= 0x1800) != 0) {
        func_001260B0();
        return;
    }
    func_00125A00();
    func_00125930();
    if (0 <= (s64)*(s16 *)(reg_a6 + 2)) {
        func_00125590();
    } else {
        func_001257E0();
    }
}



s32 func_00170DF0();
s32 func_00170F80();
s32 func_00171100();
s32 func_0018D970();
extern u8 D_00269490[];
extern u8 *jtbl_0028E3F4_as_u8_p;

void func_001261A0(void) {
    s32 func_0019D290();
    s32 func_001257E0();
    u32 t;

    if (reg_d1.w & 1) {
        func_00128130();
        return;
    }
    reg_d0.w = 0;
    if (reg_d1.w & 0x1000) goto next_1;
    if (!(reg_d1.w & 0x800)) goto next_3;
    func_00170F80();
    goto next_2;
next_1:
    func_00170DF0();
next_2:
    func_00171100();
    func_0018D970();
    *(u8 *)(reg_a6 + 0) |= 1;
    func_00127CA0();
    return;
block_1:
    func_001257E0();
    return;
next_3:
    reg_tmp.w = 0xBBD;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x18) -= 1;
    if ((s16) *(u16 *)(reg_a6 + 0x18) >= 0) goto next_4;
    *(u16 *)(reg_a6 + 0x18) = 2;
    reg_tmp.w = 0xBBE;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
next_4:
    func_001256C0();
    if (cond_flag != 0) goto block_1;
    reg_d0.w = 4;
    reg_d1.h[0] &= reg_d0.h[0];
    t = reg_d1.h[0] ^ reg_d0.h[0];
    reg_d1.h[0] = t;
    if (t & 0xFFFF) goto next_5;
    func_001257B0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *)(reg_tmp.w);
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
    return;
next_5:
    *(u16 *)(reg_a6 + 2) -= 0x60;
    *(u8 *)(reg_a6 + 0x1E) -= 1;
    if (*(u8 *)(reg_a6 + 0x1E) != 0) goto next_6;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1F);
    reg_a0 = (u8 *)(D_00269490);
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    func_0019D290();
}

extern u8 D_0028E855;
extern void (*jtbl_0028E3F4)();

void func_00126410(void) {
    s32 func_001257E0();
    u32 t;

    if ((s16)(D_0028E855) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 1;
    func_00125860();
    reg_tmp.w = 0x50000;
    *(u16 *)(reg_a6 + 0x10) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    func_001A9130();
    func_0018D930();
    *(u8 *)reg_a6 = 0x84;
    func_00127CA0();
    return;
next_2:
    func_001257E0();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (cond_flag != 0) goto next_2;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0x19) < 0) {
        *(u8 *)(reg_a6 + 0x19) = *(u8 *)(reg_a6 + 0x18);
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC0F) {
            reg_tmp.w = 0xBFF;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            *(u8 *)(reg_a6 + 0x19) = 1;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
}

s32 func_0018D950();

void func_001265B0(void) {
    s32 func_001257E0();
    u32 t;

    if ((s16)(D_0028E855) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 2;
    func_00125860();
    reg_tmp.w = 0x10008;
    *(u16 *)(reg_a6 + 0x10) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = reg_tmp.h[0];
    reg_d0.w = 0x1000;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    func_001A9130();
    func_0018D950();
    *(u8 *)reg_a6 = 0x84;
    func_00127CA0();
    return;
next_2:
    func_001257E0();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (cond_flag != 0) goto next_2;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0x19) < 0) {
        *(u8 *)(reg_a6 + 0x19) = *(u8 *)(reg_a6 + 0x18);
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC2F) {
            reg_tmp.w = 0xC1F;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            *(u8 *)(reg_a6 + 0x19) = 2;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
}


void func_00126760(void) {
    s32 func_00125590();
    s32 func_001257E0();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 2;
        func_00125810();
        reg_tmp.w = 0x10004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125AA0();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x200) {
        func_00125590();
        return;
    }
    func_001257E0();
}


void func_00126830(void) {
    s32 func_00125590();
    s32 func_001257E0();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 4;
        func_00125810();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125B40();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x400) {
        func_00125590();
        return;
    }
    func_001257E0();
}


void func_00126900(void) {
    s32 func_00125590();
    s32 func_001257E0();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 8;
        func_00125810();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D950();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125BE0();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x600) {
        func_00125590();
        return;
    }
    func_001257E0();
}


void func_001269D0() {
    s32 func_001257E0();
    s32 func_00125A00();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 1;
        func_001258B0();
        reg_tmp.w = 0x50000;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125A00();
    func_001255F0();
}

void func_00126A70() {
    s32 func_001257E0();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 2;
        func_001258B0();
        reg_tmp.w = 0x10004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125AA0();
    func_001255F0();
}

void func_00126B10() {
    s32 func_001257E0();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 4;
        func_001258B0();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125B40();
    func_001255F0();
}

void func_00126BB0() {
    s32 func_001257E0();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 8;
        func_001258B0();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}


void func_00126C50() {
    s32 func_001257E0();
    s32 func_00125A00();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 1;
        func_001258F0();
        reg_tmp.w = 0x50000;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125A00();
    func_001255F0();
}

void func_00126CF0() {
    s32 func_001257E0();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 2;
        func_001258F0();
        reg_tmp.w = 0x10004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125AA0();
    func_001255F0();
}

void func_00126D90() {
    s32 func_001257E0();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 4;
        func_001258F0();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125B40();
    func_001255F0();
}

void func_00126E30() {
    s32 func_001257E0();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 8;
        func_001258F0();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}

extern void *D_0028DE8C_as_void_p;
extern u32 D_0028DE94;

void func_00126ED0(void) {
    reg_d1.w = D_0028DE94;
    D_0028E988 -= 1;
    (*(s16 *)((u8 *)(reg_a0) + (-6))) = 0;
    cond_flag = 0;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C_as_void_p;
}

extern u8 D_00269530_as_u8_a[];
extern u8 D_00269550[];
extern u8 D_002695E0[];

void func_00126F10(void) {
    u8 *save_a1;

    reg_a3 = (u8 *)D_002695E0;
    D_0028E988 += 1;
    reg_a3 = *(u8 **) (D_002695E0 + (reg_d0.h[0] & ~3));
    *(u16 *) reg_a0 = reg_d0.h[0];
    *(u16 *) reg_a0 |= 0x8000;
    reg_a0 += 2;
    D_0028DE94 = reg_d1.w;
    reg_tmp1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_tmp1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += reg_tmp1.w;
    reg_d1.h[0] += (s32) D_0029C06C[0];
    *(u16 *) reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xAC00;
    reg_d1.h[0] += 0xE00;
    reg_d1.h[0] += (s32) D_0029C068[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += 0xAC00;
    if (reg_tmp1.h[1] != 0) {
        func_00126ED0();
        return;
    }
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x6000;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp1.w = 0;
    reg_d1.h[0] += 0x800;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x6000;
    reg_tmp1.w += (s32) reg_tmp.w;
    if (reg_tmp1.h[1] != 0) {
        func_00126ED0();
        return;
    }
    reg_d1.w = D_0028DE94;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a0 += 2;
    reg_a0 -= 0x1E;
    save_a1 = reg_a1;
    reg_a1 = (u8 *)D_00269530_as_u8_a;
    reg_a1 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 0x28) = *(u16 *) (reg_a1 + 2);
    *(u16 *) (reg_a0 + 0x2A) = *(u16 *) (reg_a1 + 0);
    ((Fn) *(u32 *) (D_00269550 + (reg_d0.h[0] & ~3)))();
    reg_a1 = save_a1;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

s32 func_002011A0();
extern u16 D_002695D0[];

void func_00127310(void) {
    u8 *sa1;

    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x1A) = 0x420;
    func_002011A0();
    reg_d0.h[0] &= 0xE;
    sa1 = reg_a1;
    reg_d1.w = 0;
    reg_a1 = (u8 *)D_002695D0;
    reg_a1 += reg_d0.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 = sa1;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w += reg_d1.w;
    *(u16 *)(reg_a0 + 0xA) = reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    func_001273D0();
}

s32 func_00201270();
void func_001273D0(void) {
    func_00201270();
    reg_d0.h[0] >>= 1;
    func_00127400();
}

s32 func_002011D0();

void func_00127400(void) {
    s32 func_00201D10();
    u32 save_d0;
    u32 save_d2;
    u32 save_d3;
    u8 *temp_a1;

    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += reg_d0.b[0];
    save_d0 = reg_d0.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    func_002011D0();
    reg_d0.h[0] += 1;
    reg_d1.h[0] = reg_d0.h[0];
    func_00201270();
    reg_d0.b[0] -= reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) += reg_d0.b[0];
    temp_a1 = (u8 *)(reg_a0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1) + (0x1B)));
    reg_d1.w = 0x3F;
    reg_d0.h[0] = (u16) reg_d0.b[0];
    reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a1) + (0x1A)));
    reg_a0 = reg_a6;
    reg_atmp = temp_a1;
    reg_a6 = temp_a1;
    func_00201D10();
    reg_atmp = (u8 *)reg_a0;
    reg_a0 = reg_a6;
    reg_a6 = (u8 *)reg_atmp;
    (*(u16 *)((u8 *)(reg_a0) + (0x20))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x22))) = (u16) reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    cond_flag = 0;
    reg_d1.w = reg_d7.w;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
}

extern void *reg_a0_as_void_p;
extern void func_002010A0(void);

void func_00127530(void) {
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)((u8 *)reg_a0_as_void_p + 0x1A) = 0x420;
    func_002010A0();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] = (s8)reg_d0.b[0];
    reg_d0.h[0] >>= 1;
    func_00127400();
}

void func_001275B0(void) {
    *(u16 *)((u8 *)reg_a0_as_void_p + 0x1E) = 0x9601;
    cond_flag = 0;
}

s32 func_00201160();

void func_001275D0(void) {
    reg_d7.w = reg_d0.w;
    func_00201160();
    reg_d0.h[0] &= 0x1F;
    (*(u8 *)((u8 *)(reg_a0) + (0x19))) += reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x20))) = 0;
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}

void func_00127630(void) {
    reg_d7.w = reg_d0.w;
    func_00201160();
    reg_d0.h[0] &= 0x1F;
    (*(u8 *)((u8 *)(reg_a0) + (0x19))) += reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x20))) = 0;
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}


void func_00127690(void) {
    func_00127530();
    (*(s8 *)((u8 *)(reg_a0) + (0))) = 0;
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += 5;
    cond_flag = 0;
}

void func_001276D0(void) {
    func_00127530();
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += 5;
    cond_flag = 0;
}

void func_00127700(void) {
    func_00127530();
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += 5;
    cond_flag = 0;
}

void func_00127730(void) {
    func_00127530();
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += 5;
    cond_flag = 0;
}

extern u8 D_002695D0_as_u8_a[];
extern u8 D_0029F1F0_as_u8_a[];

void func_00127760(void) {
    reg_a3 = D_002695D0_as_u8_a;
    reg_tmp.w = (u32) D_0029F1F0_as_u8_a;
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern u8 D_002695A0_as_u8_a[];

void func_001277A0(void) {
    reg_a3 = D_002695A0_as_u8_a;
    reg_tmp.w = (u32) D_0029F1F0_as_u8_a;
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern u8 D_002695B0_as_u8_a[];

void func_001277E0(void) {
    reg_a3 = D_002695B0_as_u8_a;
    reg_tmp.w = (u32) D_0029F1F0_as_u8_a;
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern u8 D_002695C0_as_u8_a[];

void func_00127820(void) {
    reg_a3 = D_002695C0_as_u8_a;
    reg_tmp.w = (u32) D_0029F1F0_as_u8_a;
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern void *reg_a3_as_void_p;


void func_00127860(void) {
    reg_a3_as_void_p = D_002695D0;
    func_001278A0();
}

extern u16 D_002695A0[];
extern u16 *reg_a3_as_u16_p;


void func_00127870(void) {
    reg_a3_as_u16_p = D_002695A0;
    func_001278A0();
}

extern u16 D_002695B0[];


void func_00127880(void) {
    reg_a3_as_u16_p = D_002695B0;
    func_001278A0();
}

extern u16 D_002695C0[];

void func_00127890(void)
{
    reg_a3_as_u16_p = D_002695C0;
    func_001278A0();
}

extern u8 D_0029F260_as_u8_a[];
void func_001278A0(void) {
    reg_tmp.w = (u32)D_0029F260_as_u8_a;
    reg_a0_as_u16_p[18] = reg_tmp.h[1];
    reg_a0_as_u16_p[19] = reg_tmp.h[0];
    func_001278D0();
}

void func_001278D0(void) {
    reg_d7.h[0] &= 0xF;
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d7.b[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1F))) = 0;
    reg_d7.w = reg_d0.w;
    func_002011A0();
    reg_d0.w &= 0xE;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3_as_u16_p + ((s16)reg_d0.h[0] & ~1)) : *reg_a3_as_u16_p;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp.w += reg_d0.w;
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = (u16) reg_tmp.h[0];
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}

void func_001279A0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x420;
    func_002011A0();
    reg_a3 = (u8 *)(D_002695A0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    reg_tmp1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) reg_tmp1.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = reg_tmp1.h[0];
    func_001273D0();
    (*(u16 *)((u8 *)(reg_a0) + (0))) &= 0xFF83;
    (*(u16 *)((u8 *)(reg_a0) + (0))) |= 0x14;
}

void func_00127AA0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x420;
    func_002011A0();
    reg_a3 = (u8 *)(D_002695B0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    reg_tmp1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) reg_tmp1.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = reg_tmp1.h[0];
    func_001273D0();
    (*(u16 *)((u8 *)(reg_a0) + (0))) &= 0xFF83;
    (*(u16 *)((u8 *)(reg_a0) + (0))) |= 0x18;
}

void func_00127BA0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x420;
    func_002011A0();
    reg_a3 = (u8 *)(D_002695C0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    reg_tmp1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) reg_tmp1.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = reg_tmp1.h[0];
    func_001273D0();
    (*(u16 *)((u8 *)(reg_a0) + (0))) &= 0xFF83;
    (*(u16 *)((u8 *)(reg_a0) + (0))) |= 0x1C;
}

void func_002010A0(void);
extern u8 D_00269708[];

void func_00127CA0(void) {
    void func_00201D10(void);
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x10);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    reg_a0 = (u8 *)D_00269708;
    reg_a0 = *(u8 **)(D_00269708 + (reg_d0.h[0] & ~3));
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 = reg_a6;
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0) &= 0xF8DF;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 0x06000000;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[0];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a6 + 0x12) = 0x10;
    *(s16 *)(reg_a6 + 0x14) = 0x202;
    *(u16 *)(reg_a6 + 0x16) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(s8 *)(reg_a6 + 0x19) = 7;
    *(s8 *)(reg_a6 + 0x18) = 0xF;
    *(s16 *)(reg_a6 + 0x1C) = 0x1D;
    reg_d0.h[0] = D_0029C06C[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] + *(s16 *)(reg_a6 + 4);
    reg_d1.w = 0x30;
    if ((s32)reg_d0.h[0] < 0x1C00) {
        reg_d1.w = 0x10;
    }
    func_002010A0();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] &= 6;
    reg_d0.h[0] += 6;
    func_00201D10();
    *(u16 *)(reg_a6 + 0x1A) = reg_d3.h[0];
}

void func_0019C3E0(void);

void func_00127FA0(void) {
    u32 sd6;
    u8 t;
    u32 t1;

    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    switch (*(u8 *)(reg_a6 + 0x18)) {
        case 0:
            goto block_3;
    }
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    func_0019C3E0();
    reg_d6.w = sd6;
    goto block_4;
block_3:
    func_001257E0();
block_4:
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) {
        func_00125FF0();
    }
}


void func_00128130(void) {
    u32 sd6;
    u8 t;

    if ((reg_d1.w & 0x2000) && (D_0028E3EC != 0)) {
        *(u8 *)(reg_a6 + 0x1C) ^= 0x10;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    if (*(u8 *)(reg_a6 + 0x18) == 0) goto block_3;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    func_0019C3E0();
    reg_d6.w = sd6;
    if ((s32)*(u8 *)(reg_a6 + 0x15) < 3) return;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 8);
    reg_d1.h[1] += *(u16 *)(reg_a6 + 6);
    func_00128320();
    if (*(u8 *)(reg_a6 + 1) & 0x20) {
        func_001285A0();
    }
    return;
block_3:
    func_001257E0();
}

void func_0019D2F0(void);
extern u16 D_0028E910;
extern u16 g_stage;

void func_00128320(void) {
    void func_0019D2C0(void);
    u32 sd6;
    u32 sd7;

    reg_d1.h[0] += 0x7FFF + 0x7DC1;
    reg_d1.h[1] += 0x200;
    reg_d2.w = 0x11E0;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    func_0019D2C0();
    reg_d3.h[0] = 0x410;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x7FFF + 0x7F41;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d7.w = 1;
    reg_d6.w = 0;
    do {
        reg_d5.w = 0x1046;
        reg_d2.w = 0xF;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        reg_d4.w = 0;
        if (reg_d2.h[0] == 0 && reg_d6.h[0] == 0) {
            reg_d5.w = 0x103C;
        } else {
            reg_d4.h[0] = reg_d2.h[0] * 0xA;
        }
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d2.w = 0xF;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        if (reg_d2.h[0] != 0 || reg_d4.h[0] != 0 || reg_d6.h[0] != 0) {
            reg_d6.w = 1;
            reg_d2.w += reg_d4.w;
            if (reg_d5.w == 0x103C) {
                reg_d1.h[0] += 0x7FFF + 0x7E01;
            }
            reg_d2.w += reg_d5.w;
            reg_d4.h[0] = 0x1D;
            func_0019D2F0();
            reg_d1.h[0] += 0x400;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    if (g_stage != 0 || D_0028E910 != 0) {
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        return;
    }
    reg_d2.w = 0x11E1;
    reg_d1.h[0] += 0x400;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    reg_d1.h[1] += 0xC0;
    func_0019D2F0();
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_d1.w += 0xFF400000;
}

extern u32 D_002697E0[];

void func_001285A0(void) {
    s32 func_0019D2C0();
    u16 temp_a2;
    u16 temp_a3;
    u32 temp_a0;

    temp_a3 = (u32)reg_d1.h[0] + 0x400;
    reg_d1.h[0] = temp_a3;
    temp_a2 = (u32)reg_d1.h[1] + 0x40;
    reg_d1.h[1] = temp_a2;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
    reg_a0 = (u8 *)(D_002697E0);
    reg_a0 += reg_d0.h[0];
    temp_a0 = *(u32 *)reg_a0;
    reg_d2.w = temp_a0;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x1D;
    func_0019D2C0();
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) -= 4;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x12))) < 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = 0x10U;
    }
}

#ifdef DEATH_LABEL
s32 death_func_001271E0(void) {
    return (*reg_a6_as_u16_p & 0x3F) == 0x24;
}
#endif

void func_00128640(void) {
    reg_a6_as_u16_p[0] = 0;
    reg_a6_as_u16_p[1] = 0xFFFF;
}

extern u8 D_002962E0[];

void func_00128660(void) {
    memset(D_002962E0, 0, MAIN_OR_DEATH_LABEL(0x3494, 0x10694));
    reg_a0 = D_002962E0 + 2;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
    do {
        *(u16 *)reg_a0 = 0xFFFF;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u32 reg_a0_as_u32;

void func_001286D0(void) {
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a0_as_u32 = reg_tmp.w;
    func_00128710();
}

extern s32 D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;
extern s32 reg_a0_as_s32;

void func_00128710() {
    func_00128B00();
    reg_d0.w += 0x60000;
    func_00128B00();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0_as_s32 = D_0028DE98;
}

extern u8 *D_0028DE98_as_u8_p;

void func_00128760(void) {
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98_as_u8_p = reg_a0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        func_001286D0();
        return;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        func_00128710();
        return;
    }
    func_00128830();
}


void func_00128830() {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d0.w += 0x20000;
    reg_d1.b[0] += reg_d1.b[0];
    func_00129450();
    reg_d0.w -= 0x20000;
    reg_d1.b[0] -= 8;
    func_00129450();
    reg_d1.b[0] += 0x10;
    func_00129450();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}

void func_001288C0() {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] -= 8;
    func_00129450();
    reg_d1.b[0] += 0x10;
    func_00129450();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0_as_s32 = D_0028DE98;
}


void func_00128930(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    func_00128B00();
}

void func_00128970(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    reg_d0.w += 0x40000;
    func_00128B00();
    reg_d0.w += 0xFFFC0000;
}


void func_001289D0(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_00128710(reg_d0.w);
}


void func_00128A20(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_001288C0(reg_d0.w);
}


void func_00128A70(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_00128830(reg_d0.w);
}


void func_00128AC0(void) {
    if (D_0028E910 != 0) {
        func_00128760();
        return;
    }
    func_00128B10();
}


void func_00128B00(void) {
    func_00128B10();
}

extern u16 D_0024E7D0[];
extern u32 D_0028DEA4;
extern u32 D_0028DEA8;
extern u16 *D_0028DEB0_as_u16_p;
extern u8 *D_0028DEB4_as_u8_p;
extern u16 D_0028DFFC;
extern u8 D_0028E2E4;
extern u16 D_0028E7F0;
extern u16 D_0028E89C;
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u16 D_0029CEA0[];
#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif

void func_00128B10(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((D_0028E3C0 == 0) && (D_0028E2E4 != 0)) {
        return;
    }
#else
    if (D_0028E2E4 != 0) {
        return;
    }
#endif
    D_0028DEA4 = reg_d7.w;
    D_0028DEB4_as_u8_p = reg_a0;
    D_0028DEB0_as_u16_p = (u16 *) reg_a1;
    reg_d7.h[0] = D_0028E89C;
    reg_d7.h[0] += D_0028E8A0;
    reg_d7.h[0] += D_0029CEA0[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)D_002962E0;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (D_0029976C[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (D_0029976E[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 1;
    return;
next_3:
    if (0 <= (s64) (s16) D_0029CEA0[0]) {
        goto next_4;
    }
    if (*(u8 *) D_0029CEA0 & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 0;
    return;
next_5:
    D_0028DEA8 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) D_0024E7D0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += D_0028E7F0;
    reg_d7.h[0] += D_0028DFFC;
#ifdef DEATH_LABEL
    if ((death_D_0029085C == 2) && (reg_d7.h[0] > death_D_00290858)) {
        reg_d7.h[0] = death_D_00290858;
    }
#endif
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    reg_d1.b[0] >>= 2;
    func_00128F70();
}

extern u8 D_0024E740[];
extern u8 *D_0028DEB0_as_u8_p;

void func_00128F70(void) {
    if (reg_d3.w == 0) {
        goto next_1;
    }
    *(u16 *) (reg_a0 - 0xC) += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    *(u16 *) (reg_a0 - 0xE) += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
next_1:
    if (*(s16 *) reg_a1 == 0) {
        goto next_2;
    }
    reg_a1 = (u8 *)D_0024E740;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_tmp.h[0] = *(u16 *) (reg_a1 + 2);
    reg_a1 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn) reg_a1;
    jtbl_0028E3F4();
    return;
next_2:
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *)D_0028DEB0_as_u8_p;
    cond_flag = 0;
}


void func_00129070(void) {
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a0_as_u32 = reg_tmp.w;
    func_001290B0();
}


void func_001290B0() {
    func_00129450();
    reg_d0.w += 0x60000;
    func_00129450();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0_as_s32 = D_0028DE98;
}


void func_00129100(void) {
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98_as_u8_p = reg_a0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        func_00129070();
        return;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        func_001290B0();
        return;
    }
    func_001291D0();
}

void func_001291D0() {
    func_00129450();
    reg_d1.b[0] -= 8;
    func_00129450();
    reg_d1.b[0] += 0x10;
    func_00129450();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0_as_s32 = D_0028DE98;
}

void func_00129230() {
    reg_d1.b[0] -= 8;
    func_00129450();
    reg_d1.b[0] += 0x10;
    func_00129450();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0_as_s32 = D_0028DE98;
}


void func_00129280(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    func_00129450();
}

void func_001292C0(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    reg_d0.w += 0x40000;
    func_00129450();
    reg_d0.w += 0xFFFC0000;
}


void func_00129320(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_001290B0(reg_d0.w);
}


void func_00129370(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_00129230(reg_d0.w);
}


void func_001293C0(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_001291D0(reg_d0.w);
}


void func_00129410(void) {
    if (D_0028E910 != 0) {
        func_00129100();
        return;
    }
    func_00129460();
}

#ifdef DEATH_LABEL
extern u8 death_D_00290854;
extern u8 death_D_0029085C;
extern s32 death_D_0029040C;
extern s32 death_D_00290410;
extern u8 death_D_006901D0[];
#endif

void func_00129450(void) {
#ifdef DEATH_LABEL
    if (death_D_0029085C == 2) {
        if (death_D_00290854 != 0) {
            if (reg_a6 == death_D_006901D0) {
                death_D_0029040C += 1;
                if (death_D_0029040C & 1) {
                    return;
                }
            } else {
                death_D_00290410 += 1;
                if (!(death_D_00290410 & 1)) {
                    return;
                }
            }
        }
    } else {
        death_D_00290410 = 0;
        death_D_0029040C = 0;
    }
#endif
    func_00129460();
}

#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif

void func_00129460(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((D_0028E3C0 == 0) && (D_0028E2E4 != 0)) {
        return;
    }
#else
    if (D_0028E2E4 != 0) {
        return;
    }
#endif
    D_0028DEA4 = reg_d7.w;
    D_0028DEB4_as_u8_p = reg_a0;
    D_0028DEB0_as_u16_p = (u16 *) reg_a1;
    reg_d7.h[0] = D_0028E89C;
    reg_d7.h[0] += D_0028E8A0;
    reg_d7.h[0] += D_0029CEA0[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)D_002962E0;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (D_0029976C[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (D_0029976E[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 1;
    return;
next_3:
    if (0 <= (s64) (s16) D_0029CEA0[0]) {
        goto next_4;
    }
    if (*(u8 *) D_0029CEA0 & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 0;
    return;
next_5:
    D_0028DEA8 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) D_0024E7D0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.w |= 0x200;
    *(u16 *) reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += D_0028E7F0;
    reg_d7.h[0] += D_0028DFFC;
#ifdef DEATH_LABEL
    if ((death_D_0029085C == 2) && (reg_d7.h[0] > death_D_00290858)) {
        reg_d7.h[0] = death_D_00290858;
    }
#endif
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    func_00128F70();
}

extern s32 D_0028DEA4_as_s32;
extern s32 D_0028DEB0;
extern s32 D_0028DEB4_as_s32;
extern s32 reg_a1_as_s32;

void func_001298A0(void) {
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.sw = D_0028DEA4_as_s32;
    reg_a0_as_s32 = D_0028DEB4_as_s32;
    reg_a1_as_s32 = D_0028DEB0;
}

extern void *D_0028DEB4;

void func_001298D0(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d3.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_d4.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x25))) = 0;
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}

void func_00129930(void) {
    (*(u8 *)((u8 *)(reg_a0) + (0x25))) = (u8) reg_d4.b[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}

void func_00129970(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_d4.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}

void func_001299B0(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d3.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_d4.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x25))) = 0;
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}

void func_00129A10(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d3.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_d4.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x25))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}


void func_00129A80(void) {
    func_00129A90();
}

extern u16 D_0028E890;
extern u16 D_0028E894;

void func_00129A90(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) D_0028E894;
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) D_0028E890;
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_d4.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x25))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d5.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}

void func_00129B10(void) {
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_d4.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}


void func_00129B60(void) {
    func_00129B70();
}

void func_00129B70(void) {
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d3.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_d4.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d4.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_d5.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1_as_s32 = D_0028DEB0;
}

extern u16 D_00299764[];

#ifdef DEATH_LABEL
s32 death_func_00128A90();
#endif

void func_00129BE0(void) {
    u32 t;

    if (D_00299764[0] == 0) {
        return;
    }
    reg_d0.h[0] = *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
    if ((s16) reg_d0.h[0] < 0) {
        goto next_3;
    }
    reg_a6 = (u8 *)D_002962E0;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (D_0029976C[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (D_0029976E[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_1:
    if (0 > (s64) *(s8 *) (reg_a6 + 1)) {
        D_0028DEA4 = reg_d7.w;
        reg_d0.h[0] = *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
        MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
        reg_d7.w = D_0028DEA4;
        func_00128640();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    return;
next_3:
    reg_a6 = (u8 *)D_002962E0;
    reg_d2.w = 0x40;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (D_0029976C[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (D_0029976E[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_4:
    t = *(u8 *) (reg_a6 + 1);
    if (0 > (s8) t) {
        *(u8 *) (reg_a6 + 1) = t | reg_d2.b[0];
        *(u16 *) (reg_a6 + 0x3C) = 0xFFFF;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_4;
    }
}

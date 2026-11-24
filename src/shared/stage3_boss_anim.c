#include "common.h"

void func_001CDE10(void);
void func_001CDEA0(void);
void func_001CE070();
void func_001CE260();
void func_001CE440(void);
void func_001CE4C0(void);
void func_001CE540(void);
void func_001CE5F0();



void func_001CDDF0(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    *(u16 *)(reg_a6 + 0xA6) = 0;
    func_001CDE10();
}

void func_001CDE10(void) {
    if (*(u8 *)(reg_a6 + 0x8D) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            goto block_3;
        }
    } else {
block_3:
        *(u16 *)(reg_a6 + 0xA6) += 4;
        if (*(u16 *)(reg_a6 + 0xA6) == 0x40) {
            *(u16 *)(reg_a6 + 0xA6) = 0U;
        }
    }
}


void func_001CDE90(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001CDEA0();
}

s32 func_002021F0();
s32 func_00202500();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001CDEA0(void) {
    s16 *temp_a0;
    u32 temp_s0;
    u32 temp_s1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
            if (*(s16 *)reg_a1 < 0) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            temp_s1 = reg_d3.w;
            temp_s0 = reg_d2.w;
            if (*(u16 *)(reg_a6 + 0xB6) == 0) {
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x22);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x24);
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x80;
                func_002021F0();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0xB0);
                func_00202500();
                *(u16 *)(reg_a6 + 0xB0) = (u16) reg_d1.h[0];
            }
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            if (*(u16 *)(reg_a6 + 0xB8) == 0) {
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x42);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x44);
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x7FFF + 0x7F81;
                func_002021F0();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0xB2);
                func_00202500();
                *(u16 *)(reg_a6 + 0xB2) = (u16) reg_d1.h[0];
            }
        }
    }
}

extern u16 *reg_a4_as_u16_p;
extern u16 *reg_a6_as_u16_p;

void func_001CE040(void) {
    u16 flag = 0x8001;
    reg_a4_as_u16_p[1] = flag;
    reg_d0.w = 4;
    reg_a6_as_u16_p[21] = (u16) reg_d0.h[0];
    reg_a6_as_u16_p[37] = (u16) reg_d0.h[0];
    func_001CE070(flag);
}

s32 func_00124F50();
s32 func_001251C0();
extern u16 D_0026CB20[];

void func_001CE070() {
    u16 temp_a0;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0026CB20);
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2A);
        *(u16 *)(reg_a6 + 0x26) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x28) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x4A);
        *(u16 *)(reg_a6 + 0x46) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x48) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x48) = (u16) -(s16) *(u16 *)(reg_a6 + 0x48);
        *(u16 *)(reg_a6 + 0x2A) += 4;
        temp_a0 = *(u16 *)(reg_a6 + 0x2A);
        if (temp_a0 == 0x94) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 0;
            func_001251C0();
            reg_d0.w = 3;
            func_00124F50();
        }
        *(u16 *)(reg_a6 + 0x4A) = (u16) *(u16 *)(reg_a6 + 0x2A);
    }
}


void func_001CE230(void) {
    *(u16 *)(reg_a4 + 2) = 0x6001;
    reg_d0.h[0] = 0x84;
    *(u16 *)(reg_a6 + 0x2A) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x4A) = reg_d0.h[0];
    func_001CE260(0x6001);
}

s32 func_00124DC0();

void func_001CE260() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0026CB20);
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2A);
        *(u16 *)(reg_a6 + 0x26) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x28) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x4A);
        *(u16 *)(reg_a6 + 0x46) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x48) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x48) = (u16) -(s16) *(u16 *)(reg_a6 + 0x48);
        *(u16 *)(reg_a6 + 0x2A) -= 4;
        if ((s16) *(u16 *)(reg_a6 + 0x2A) < 0) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 2;
            func_00124F50();
            reg_d0.w = 2;
            func_00124DC0();
            reg_d0.w = 3;
            func_00124DC0();
        }
        *(u16 *)(reg_a6 + 0x4A) = (u16) *(u16 *)(reg_a6 + 0x2A);
    }
}


void func_001CE430(void) {
    func_001CE440();
}

void func_001CE440(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0xA8) += 4;
        if (*(u16 *)(reg_a6 + 0xA8) == 0x18) {
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001CE4B0(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    func_001CE4C0();
}

void func_001CE4C0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0xA8) -= 4;
        if (*(u16 *)(reg_a6 + 0xA8) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;


void func_001CE520(void) {
    *(s16 *)((u8 *)reg_a4_as_void_p + 2) = 0;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0xBE) = 0;
    func_001CE540();
}

void func_001CE540(void) {
    if (*(u8 *)(reg_a6 + 0x8D) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            goto block_3;
        }
    } else {
block_3:
        *(u16 *)(reg_a6 + 0xBE) += 4;
        if (*(u16 *)(reg_a6 + 0xBE) == 0x20) {
            *(u16 *)(reg_a6 + 0xBE) = 0U;
        }
    }
}

typedef struct WorkReg {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    s16 unk6;
} WorkReg;

typedef struct WorkRegBC {
    u8 pad0[0xBC];
    s16 unkBC;
} WorkRegBC;

extern WorkReg *reg_a4_as_WorkReg_p;
extern WorkRegBC *reg_a6_as_WorkRegBC_p;


void func_001CE5C0(void) {
    reg_a4_as_WorkReg_p->unk2 = 1;
    reg_a4_as_WorkReg_p->unk4 = 0x202;
    reg_a4_as_WorkReg_p->unk6 = 0xC0;
    reg_a6_as_WorkRegBC_p->unkBC = 0;
    func_001CE5F0(0x202, 1);
}

s32 func_00124F00();
s32 func_0013B2E0();
s32 func_001D4550();
s32 func_001D4560();
extern u8 D_0026CBC0[];
extern u8 D_0028E855;

void func_001CE5F0() {
    u16 t1;

    if (*(u16 *)(reg_a4 + 6) == 0) goto next_40;
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) == 0) {
        *(u16 *)(reg_a6 + 0xBC) = 0xC0;
        goto next_40;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
    *(u16 *)(reg_a6 + 0xBC) += 0xC;
    if (*(u16 *)(reg_a6 + 0xBC) != 0xC0) return;
    *(u16 *)(reg_a6 + 0xBC) = 0U;
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) != 0) return;
    *(u16 *)(reg_a6 + 0xBC) = 0x60;
next_40:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0xBC) += 0xC;
        t1 = *(u16 *)(reg_a6 + 0xBC);
        if (t1 == 0x1E0) {
            *(s16 *)reg_a4 = 0;
            D_0028E855 |= 2;
            D_0028E855 |= 0x10;
            func_001D4550();
            func_001D4560();
            reg_d0.w = 9;
            func_00124F00();
            reg_d0.w = 0;
            func_00124DC0();
            reg_d0.w = 1;
            func_00124DC0();
            reg_d0.w = 2;
            func_00124DC0();
            reg_d0.w = 3;
            func_00124DC0();
            reg_d0.w = 4;
            func_00124DC0();
            reg_d0.w = 5;
            func_00124DC0();
            reg_d0.w = 6;
            func_00124DC0();
            reg_d0.w = 7;
            func_00124DC0();
            reg_d0.w = 8;
            func_00124DC0();
            reg_d0.w = 0;
            func_00124F50();
            reg_d0.w = 1;
            func_00124F50();
            reg_d0.w = 6;
            func_00124F50();
            reg_a0 = (u8 *)D_0026CBC0;
            func_0013B2E0();
        }
    }
    }

#include "common.h"

extern void *reg_a6_as_void_p;

void func_001B78E0(void)
{
    extern void func_0019C6D0(void);
    u16 *work;

    reg_d2.w = 0x195E;
    work = (u16 *)reg_a6_as_void_p;
    reg_d1.h[1] = work[1];
    reg_d1.h[0] = work[2];
    reg_d1.w += 0xE600F400U;
    reg_d3.h[0] = 0x1A60;
    reg_d4.h[0] = work[0xE];
    func_0019C6D0();
}

typedef void (*Fn)();

s32 func_0019C940();
extern u8 D_0026E1B0[];
extern u16 D_0026E1D0[];
extern u16 D_0026E250[];
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001B7930(void) {
    u16 temp_a1;
    reg_a2 = (u8 *)(D_0026E250);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xEC00F400;
    reg_d3.h[0] = 0x1460;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x4A)));
        reg_a0 = (u8 *)(D_0026E1D0);
        reg_d0.b[0] = (u8) ((s32) reg_d0.b[0] >> 3);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x46))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x48))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    }
    reg_d6.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x4A)));
    if (reg_d0.b[0] != 0xC0) {
        reg_d0.b[0] = (u8) ((s32) (reg_d0.b[0] & 0xFF) >> 5);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ((Fn)*(u32 *)((u8 *)D_0026E1B0 + (reg_d0.h[0] & ~3)))();
        return;
    }
    func_0019C940();
}

extern u16 D_0026E1B0_as_u16_a[];
extern u16 D_0026E2D0[];

void func_001B7B60(void) {
    u16 temp_a1;
    reg_a2 = (u8 *)(D_0026E2D0);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6A)));
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xEC00F400;
    reg_d3.h[0] = 0x1460;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7C)));
    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x8A)));
        reg_a0 = (u8 *)(D_0026E1D0);
        reg_d0.b[0] = (u8) ((s32) reg_d0.b[0] >> 3);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x86))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x88))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    }
    reg_d6.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x88)));
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x8A)));
    if (reg_d0.b[0] != 0xC0) {
        reg_d0.b[0] = (u8) ((s32) (reg_d0.b[0] & 0xFF) >> 5);
        reg_a0 = (u8 *)(D_0026E1B0_as_u16_a);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ((Fn)*(u32 *)((u8 *)D_0026E1B0_as_u16_a + (reg_d0.h[0] & ~3)))();
    }
    func_0019C940();
}

extern u8 D_0026E350[];

void func_001B7D90(void) {
    s32 func_0019C6D0();
    u16 temp_a0;

    reg_a2 = D_0026E350;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
    reg_d2.h[0] += 7;
    reg_d2.h[0] = reg_d2.b[0] << 5;
    reg_a2 += reg_d2.h[0];
    reg_a2 += (*(u16 *)((u8 *)(reg_a6) + (0xAA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600F800;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBC)));
    func_0019C6D0();
}

extern u32 D_0026E530[];
extern u16 *reg_a2_as_u16_p;
extern u16 *reg_a6_as_u16_p;

void func_001B7E30(void) {
    extern void func_0019C6D0(void);
    reg_a2_as_u16_p = (u16 *)D_0026E530;
    reg_d2.h[1] = reg_a2_as_u16_p[0];
    reg_d2.h[0] = reg_a2_as_u16_p[1];
    reg_d1.h[1] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    reg_d1.w += 0xFC00FC00U;
    reg_d1.w += 0xF2000000U;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x15;
    func_0019C6D0();
}

extern u16 D_0026E540[];

void func_001B7EA0(void) {
    s32 func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC7);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 0x17;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFC00FD00;
    reg_d0.w = reg_d1.w;
    reg_d1.w += 0x09C00400;
    func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC6);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x09BFFC40;
    func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC9);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x0F400600;
    func_0019C6D0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xC8);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_0026E540;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)D_0026E540 + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)D_0026E540;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x0F3FF9C0;
    func_0019C6D0();
}

s32 func_0019C790();
extern u8 D_0026E5C0[];

void func_001B8200(void) {
    u32 temp_a0;

    reg_a2 = D_0026E5C0;
    reg_a2 += (*(u16 *)((u8 *)(reg_a6) + (0x11A)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w += 0xF8000080;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x11A))) < 0xB1) {
        reg_d1.w += 0xFE000100;
    }
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a2) + (4)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a2) + (6)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (8)));
    reg_d4.h[0] = 0x13;
    func_0019C790();
}

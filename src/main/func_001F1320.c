#include "common.h"

s32 func_0019C670();
extern u16 MAIN_OR_DEATH_LABEL(D_00264A70, death_D_0026A2E0)[];
extern u8 *reg_a0;
extern u8 *reg_a6;

#ifdef DEATH_LABEL
#define BOSS_X x
#define BOSS_Y y
#else
#define BOSS_X (*(u16 *)(reg_a6 + 2))
#define BOSS_Y (*(u16 *)(reg_a6 + 4))
#endif

void func_001F1320(void) {
#ifdef DEATH_LABEL
    s32 i;
    u16 y;
    u16 x;

    x = *(u16 *)(reg_a6 + 2);
    y = *(u16 *)(reg_a6 + 4);
    for (i = 0; i < 2; i++) {
#endif
    reg_a0 = (u8 *) MAIN_OR_DEATH_LABEL(D_00264A70, death_D_0026A2E0);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x12E);
    reg_d2.h[0] -= 0x18;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = BOSS_X;
    reg_d1.h[0] = BOSS_Y;
    reg_d1.w += 0xFE00FF00;
    reg_d4.w = 0;
    reg_d1.w += 0xF7C00000;
    reg_d3.h[0] = 0x208;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0xEC);
    func_0019C670();
#ifdef DEATH_LABEL
        x = *(u16 *)(reg_a6 + 0x202);
        y = *(u16 *)(reg_a6 + 0x204);
    }
#endif
}

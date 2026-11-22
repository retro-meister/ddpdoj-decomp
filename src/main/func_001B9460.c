#include "common.h"

s32 func_00124D90();
s32 func_001713B0();
extern u16 D_0026E8A0[];
extern u16 D_0026E8B0[];
extern u8 D_0028DC40[];
extern u8 D_0028DC48[];
extern u8 D_0028DC50[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B9460(void) {
    reg_d0.w = 5;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x1000;
    func_001713B0();
    reg_d1.b[0] = *(D_0028DC48 + reg_d0.b[0]);
    reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x10D)));
    if ((s32) reg_d1.b[0] >= 0x80) {
        reg_d1.b[0] = 0x80;
    }
    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(D_0028DC40 + reg_d0.b[0]);
    reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a6) + (0x10A)));
    if ((s8) reg_d1.b[0] < 3) {
        reg_d1.b[0] = 3;
    }
    (*(s8 *)((u8 *)(reg_a4) + (7))) = 0;
    (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x10D))) += 2;
    if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x10D))) >= 0x80) {
        (*(u8 *)((u8 *)(reg_a6) + (0x10D))) = 0x80U;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x10A))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x10A))) < 3) {
        (*(u8 *)((u8 *)(reg_a6) + (0x10A))) = 3U;
    }
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0x6000;
    (*(s8 *)((u8 *)(reg_a4) + (0xD))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0xC))) = 4;
    func_001713B0();
    reg_d1.b[0] = *(D_0028DC50 + reg_d0.b[0]);
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = reg_d1.b[0];
    reg_a0 = (u8 *)(D_0026E8A0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x10E)));
    if ((s16) reg_d1.h[0] > 4) {
        reg_d1.h[0] = 4;
    }
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x10E))) += 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x10E))) > 4) {
        (*(u16 *)((u8 *)(reg_a6) + (0x10E))) = 4U;
    }
    reg_a0 = (u8 *)(D_0026E8B0);
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x110)));
    if ((s16) reg_d1.h[0] > 0x20) {
        reg_d1.h[0] = 0x20;
    }
    (*(u16 *)((u8 *)(reg_a4) + (0x10))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x110))) += 2;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x110))) > 0x20) {
        (*(u16 *)((u8 *)(reg_a6) + (0x110))) = 0x20U;
    }
    (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 0x2020;
}

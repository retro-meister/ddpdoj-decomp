#include "common.h"

s32 func_001251C0();
s32 func_001713B0();
s32 func_002011D0();
extern u8 D_0026DFE0[];
extern u8 D_0028DC28[];
extern u8 D_0028DC30[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B3E30(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x114))) = 0;
    (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
    func_002011D0();
    if (reg_d0.h[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 0xFFU;
    }
    (*(u8 *)((u8 *)(reg_a4) + (2))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x4040;
    (*(s8 *)((u8 *)(reg_a4) + (7))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0x60;
    reg_tmp.w = 0;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0;
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0x10))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 0;
    func_001713B0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(D_0028DC28 + reg_d0.h[0]);
    reg_d2.b[0] -= (*(u8 *)((u8 *)(reg_a6) + (0x113)));
    if ((s8) reg_d2.b[0] < 5) {
        reg_d2.b[0] = 4;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x113))) += 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x113))) > 4) {
        (*(u8 *)((u8 *)(reg_a6) + (0x113))) = 4U;
    }
    reg_d3.w = 0;
    reg_d3.b[0] = *(D_0028DC30 + reg_d0.h[0]);
    reg_d3.b[0] -= (*(u8 *)((u8 *)(reg_a6) + (0x112)));
    if ((s8) reg_d3.b[0] < 0x10) {
        reg_d3.b[0] = 0xF;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x112))) += 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x112))) > 0x10) {
        (*(u8 *)((u8 *)(reg_a6) + (0x112))) = 0x10U;
    }
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026DFE0;
    reg_d4.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d0.w = 5;
    func_001251C0();
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d2.h[0];
    (*(u8 *)((u8 *)(reg_a0) + (0xA))) = (u8) reg_d3.b[0];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = (u16) reg_d4.h[0];
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = (u16) reg_tmp.h[0];
    reg_d0.w = 6;
    func_001251C0();
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d2.h[0];
    (*(u8 *)((u8 *)(reg_a0) + (0xA))) = (u8) reg_d3.b[0];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = (u16) reg_d4.h[0];
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0x10))) = (u16) reg_tmp.h[0];
    reg_d0.w = 0xE;
    func_001251C0();
}

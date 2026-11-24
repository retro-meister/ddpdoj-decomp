#include "common.h"

s32 func_0013A780();
s32 func_002010A0();
extern u8 *reg_a0;

void func_0013A930(u32 arg0, u32 arg1, s16 arg2) {
    u32 temp_a0;

    reg_d0.w = arg0;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d2.h[0];
    reg_d0.w = arg1;
    temp_a0 = reg_d0.h[0];
    reg_d0.h[0] = (u16) (temp_a0 >> reg_d6.h[0]);
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
    func_002010A0();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) += reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = arg2;
}


void func_0013A9E0(void) {
    reg_d6.h[0] = reg_d0.h[0];
    func_0013A930(7, 5, 0);
    func_0013A930(4, 7, 1);
    func_0013A930(7, 0xA, 2);
    func_0013A930(4, 0xE, 3);
    func_0013A930(7, 0x12, 6);
    func_0013A930(4, 0x16, 8);
    func_0013A930(7, 0x1C, 0xA);
    func_0013A930(5, 0x22, 0xC);
    func_0013A930(4, 0x28, 0xE);
    func_0013A930(5, 0x2E, 0x10);
    func_0013A930(5, 0x34, 0x12);
}

void func_0013AAB0(void) {
    reg_d6.h[0] = reg_d0.h[0];
    func_0013A930(7, 5, 0);
    func_0013A930(4, 7, 1);
    func_0013A930(7, 0xA, 2);
    func_0013A930(4, 0xE, 3);
    func_0013A930(5, 0x12, 6);
    func_0013A930(4, 0x16, 8);
    func_0013A930(5, 0x1C, 0xA);
    func_0013A930(5, 0x22, 0xC);
}

void func_0013AB50(void) {
    reg_d6.h[0] = reg_d0.h[0];
    func_0013A930(4, 5, 0);
    func_0013A930(7, 7, 1);
    func_0013A930(4, 0xA, 2);
    func_0013A930(5, 0xE, 3);
    func_0013A930(5, 0x12, 6);
}

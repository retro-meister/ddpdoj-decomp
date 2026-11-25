#include "common.h"

void func_00206910(void) {
}

extern u16 D_0028E220;

void func_00206920(void) {
    reg_d1.w = 0;
    D_0028E220 &= 1;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206960(void) {
    D_0028E220 &= 2;
    reg_d1.w = 1;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_002069A0(void) {
    D_0028E220 &= 4;
    reg_d1.w = 2;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_002069E0(void) {
    D_0028E220 &= 8;
    reg_d1.w = 3;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206A20(void) {
    D_0028E220 &= 0x70;
    reg_d1.w = 4;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206A60(void) {
    D_0028E220 &= 0x80;
    reg_d1.w = 7;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206AA0(void) {
    D_0028E220 &= 0x100;
    reg_d1.w = 8;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206AE0(void) {
    D_0028E220 &= 0x200;
    reg_d1.w = 9;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206B20(void) {
    D_0028E220 &= 0x400;
    reg_d1.w = 0xA;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206B60(void) {
    D_0028E220 &= 0x800;
    reg_d1.w = 0xB;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206BA0(void) {
    D_0028E220 &= 0x1000;
    reg_d1.w = 0xC;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

void func_00206BE0(void) {
    D_0028E220 &= 0x2000;
    reg_d1.w = 0xD;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}

extern s16 D_0028E220_as_s16;

void func_00206C20(void) {
    D_0028E220_as_s16 = 0;
    reg_d0.w = 0;
    func_00206920();
    reg_d0.w = 1;
    func_00206960();
    reg_d0.w = 1;
    func_002069A0();
    reg_d0.w = 1;
    func_002069E0();
    reg_d0.w = 1;
    func_00206A20();
    reg_d0.w = 0;
    func_00206A60();
    reg_d0.w = 0;
    func_00206AA0();
    reg_d0.w = 0;
    func_00206AE0();
    reg_d0.w = 0;
    func_00206B20();
    reg_d0.w = 0;
    func_00206B60();
    reg_d0.w = 0;
    func_00206BA0();
    reg_d0.w = 0;
    func_00206BE0();
    func_00206910();
}

void func_00206CB0(void) {
    reg_d0.h[0] = 8;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    D_0028E220 &= reg_d0.h[0];
    func_00206910();
    reg_d0.h[0] = 8;
    D_0028E220 |= reg_d0.h[0];
    func_00206910();
}

extern Reg32 reg_d0;

void func_00206D10(void) {
    u32 flags;

    reg_d0.h[0] = 1;
    flags = (u32)D_0028E220;
    flags |= (u32)(u16)reg_d0.h[0];
    D_0028E220 = (u16)flags;
    func_00206910();
}


void func_00206D30(void) {
    u32 previous_value = D_0028E220;

    reg_d0.h[0] = 1;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    D_0028E220 = (u16) (previous_value & (u16) reg_d0.h[0]);
    func_00206910();
}

void func_00206D60(void) {
}

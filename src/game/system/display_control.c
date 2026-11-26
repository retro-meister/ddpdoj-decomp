#include "common.h"

void display_control_write(void) {
}

extern u16 g_display_control;

void display_control_set_bit_0(void) {
    reg_d1.w = 0;
    g_display_control &= 1;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_1(void) {
    g_display_control &= 2;
    reg_d1.w = 1;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_2(void) {
    g_display_control &= 4;
    reg_d1.w = 2;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_3(void) {
    g_display_control &= 8;
    reg_d1.w = 3;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bits_4_to_6(void) {
    g_display_control &= 0x70;
    reg_d1.w = 4;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_7(void) {
    g_display_control &= 0x80;
    reg_d1.w = 7;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_8(void) {
    g_display_control &= 0x100;
    reg_d1.w = 8;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_9(void) {
    g_display_control &= 0x200;
    reg_d1.w = 9;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_10(void) {
    g_display_control &= 0x400;
    reg_d1.w = 0xA;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_11(void) {
    g_display_control &= 0x800;
    reg_d1.w = 0xB;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_12(void) {
    g_display_control &= 0x1000;
    reg_d1.w = 0xC;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}

void display_control_set_bit_13(void) {
    g_display_control &= 0x2000;
    reg_d1.w = 0xD;
    reg_d0.h[0] <<= reg_d1.h[0];
    g_display_control |= reg_d0.h[0];
}


void display_control_init(void) {
    g_display_control = 0;
    reg_d0.w = 0;
    display_control_set_bit_0();
    reg_d0.w = 1;
    display_control_set_bit_1();
    reg_d0.w = 1;
    display_control_set_bit_2();
    reg_d0.w = 1;
    display_control_set_bit_3();
    reg_d0.w = 1;
    display_control_set_bits_4_to_6();
    reg_d0.w = 0;
    display_control_set_bit_7();
    reg_d0.w = 0;
    display_control_set_bit_8();
    reg_d0.w = 0;
    display_control_set_bit_9();
    reg_d0.w = 0;
    display_control_set_bit_10();
    reg_d0.w = 0;
    display_control_set_bit_11();
    reg_d0.w = 0;
    display_control_set_bit_12();
    reg_d0.w = 0;
    display_control_set_bit_13();
    display_control_write();
}

void display_control_pulse_bit_3(void) {
    reg_d0.h[0] = 8;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    g_display_control &= reg_d0.h[0];
    display_control_write();
    reg_d0.h[0] = 8;
    g_display_control |= reg_d0.h[0];
    display_control_write();
}

extern Reg32 reg_d0;

void display_control_bit_0_on(void) {
    u32 flags;

    reg_d0.h[0] = 1;
    flags = (u32)g_display_control;
    flags |= (u32)(u16)reg_d0.h[0];
    g_display_control = (u16)flags;
    display_control_write();
}


void display_control_bit_0_off(void) {
    u32 previous_value = g_display_control;

    reg_d0.h[0] = 1;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    g_display_control = (u16) (previous_value & (u16) reg_d0.h[0]);
    display_control_write();
}

void display_control_unused(void) {
}

#include "common.h"

extern s32 reg_d4;
extern s32 reg_d3;
extern s32 reg_d2;
void func_0011C2B0(void);

void func_002093C0(void) {
    s32 value = 0x200002;

    reg_d4 = value;
    value = 0;
    if ((s16)value <= (s16)reg_d2) {
        reg_d4 = 0x3E0002;
    }
    reg_d3 = value;
    reg_d2 = 0;
    func_0011C2B0();
}

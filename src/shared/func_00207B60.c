#include "common.h"
#pragma opt_propagation off

typedef void (*Fn)(void);

void func_002079F0(void);
void func_00207A40(void);
void func_00207AC0(void);
void func_00207B10(void);
extern u8 *D_00267D20[];
extern s8 D_0028DFA0;
extern Fn jtbl_0028E3F4_as_Fn;
extern u8 *reg_a0;

void func_00207B60(void) {
    u8 **table;
    u8 *entry;

    reg_d7.h[0] = 0;
    func_002079F0();
    reg_d7.h[0] = 0;
    func_00207A40();
    reg_d7.h[0] = 0;
    func_00207AC0();
    reg_d7.h[0] = 0;
    func_00207B10();
    table = D_00267D20;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028DFA0;
    table += reg_d0.h[0];
    entry = *table;
    if (entry == (u8 *)-1) {
        return;
    }
    reg_a0 = entry;
    reg_d7.h[0] = 2;
    jtbl_0028E3F4_as_Fn = (Fn)reg_a0;
    jtbl_0028E3F4_as_Fn();
}

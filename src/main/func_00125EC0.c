#include "common.h"

extern u16 reg_d2;
void func_00125F00(void);
void func_00125EC0(void) {
    reg_d2 = (u8)reg_d2;
    reg_d2 <<= 2;
    func_00125F00();
}

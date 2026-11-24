#include "common.h"

void func_00125F00(void);
void func_00125EC0(void) {
    reg_d2.h[0] = (u8)reg_d2.h[0];
    reg_d2.h[0] <<= 2;
    func_00125F00();
}

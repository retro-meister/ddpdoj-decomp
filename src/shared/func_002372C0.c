#include "common.h"

extern void func_00236DA0(void);
extern void (*D_00272110[])(void);
extern u8 *reg_a5;

void func_002372C0(void) {
    s32 index = reg_a5[5];

    switch (reg_a5[3]) {
    case 0:
    case 1:
        D_00272110[index]();
        break;
    case 2:
        func_00236DA0();
        break;
    }
}

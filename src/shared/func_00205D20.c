#include "common.h"

extern u8 *reg_a1;
extern u8 *reg_a6;
void func_00205DA0(void);
void func_00205EE0(void);
void func_00205F30(void);

void func_00205D20(void) {
    reg_a1 = reg_a6 - 0x70;
    if (reg_d7.h[0] != 0) {
        reg_a1 = reg_a6 + 0x70;
    }
    if (reg_d7.h[0] == 0) {
        func_00205EE0();
        return;
    }
    if (reg_a1[1] != 0) {
        func_00205DA0();
    } else {
        func_00205F30();
        func_00205DA0();
    }
}

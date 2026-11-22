#include "common.h"

extern s16 *reg_a4;
extern u8 *reg_a6;

void func_001CA370(void);

void func_001CA350(void) {
    *reg_a4 = 0;
    reg_a6[0x1B] = 8;
    func_001CA370();
}

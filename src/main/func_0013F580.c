#include "common.h"

extern u8 D_0029CE20[];
extern u8 D_0029CDA0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_0013F5C0(void);

void func_0013F580(void) {
    reg_a0 = D_0029CE20;
    reg_a1 = D_0029CDA0;
    func_0013F5C0();
}

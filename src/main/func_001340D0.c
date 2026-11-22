#include "common.h"

extern u16 D_0025F9F0[];
extern u16 *reg_a0;

void func_001340E0(void);

void func_001340D0(void) {
    reg_a0 = D_0025F9F0;
    func_001340E0();
}

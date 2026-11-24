#include "common.h"

extern u16 D_002695B0[];
extern u16 *reg_a3;

void func_001278A0(void);

void func_00127880(void) {
    reg_a3 = D_002695B0;
    func_001278A0();
}

#include "common.h"

extern u16 D_002695A0[];
extern u16 *reg_a3;

void func_001278A0(void);

void func_00127870(void) {
    reg_a3 = D_002695A0;
    func_001278A0();
}

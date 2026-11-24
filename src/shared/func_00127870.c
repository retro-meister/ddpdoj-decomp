#include "common.h"

extern u16 D_002695A0[];
extern u16 *reg_a3_as_u16_p;

void func_001278A0(void);

void func_00127870(void) {
    reg_a3_as_u16_p = D_002695A0;
    func_001278A0();
}

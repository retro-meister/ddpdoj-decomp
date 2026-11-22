#include "common.h"

void func_001A3020(void);

void func_001340E0(void) {
    *(u16 *)&reg_d0 = 6;
    func_001A3020();
}

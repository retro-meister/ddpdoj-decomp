#include "common.h"

extern s16 *reg_a4;
extern s16 *reg_a6;
extern void func_001E88D0(void);

void func_001E88B0(void) {
    reg_a4[1] = 2;
    reg_a6[0x94] = 0;
    func_001E88D0();
}

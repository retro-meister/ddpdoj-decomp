#include "common.h"

extern s16 *reg_a4_as_s16_p;
extern s16 *reg_a6_as_s16_p;
extern void func_001E88D0(void);

void func_001E88B0(void) {
    reg_a4_as_s16_p[1] = 2;
    reg_a6_as_s16_p[0x94] = 0;
    func_001E88D0();
}

#include "common.h"

extern u16 *reg_a2_as_u16_p;
extern void func_0018DED0(void);

void func_0014D150(void) {
    reg_d1.h[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p++;
    func_0018DED0();
}

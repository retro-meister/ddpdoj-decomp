#include "common.h"

extern u16 *reg_a2;
extern void func_0018DED0(void);

void func_0014D150(void) {
    reg_d1.h[0] = *reg_a2;
    reg_a2++;
    func_0018DED0();
}

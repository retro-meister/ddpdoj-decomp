#include "common.h"

extern u16 *reg_a4_as_u16_p;
extern void func_001D73A0(void);

void func_001D7390(void) {
    reg_a4_as_u16_p[1] = 0x202;
    func_001D73A0();
}

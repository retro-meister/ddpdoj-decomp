#include "common.h"

extern u16 *reg_a4;
extern void func_001D73A0(void);

void func_001D7390(void) {
    reg_a4[1] = 0x202;
    func_001D73A0();
}

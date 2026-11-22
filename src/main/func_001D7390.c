#include "common.h"

extern u16 *work_reg_a4;
extern void func_001D73A0(void);

void func_001D7390(void) {
    work_reg_a4[1] = 0x202;
    func_001D73A0();
}

#include "common.h"

extern Reg32 reg_d1;
extern void func_0013EEA0(void);

void func_0013EE70(void) {
    u16 saved = reg_d6.h[0];
    reg_d1.h[0] = 0x1900;
    reg_d4.sw = 0x02CC000A;
    reg_d6.h[0] = (saved << 16) - saved;
    func_0013EEA0();
}

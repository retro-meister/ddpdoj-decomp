#include "common.h"

extern Reg32 work_reg_1;
extern u16 D_0028E490;
extern s32 D_0028E498;
extern void func_0013EEA0(void);

void func_0013EE70(void) {
    u16 saved = D_0028E490;
    work_reg_1.h[0] = 0x1900;
    D_0028E498 = 0x02CC000A;
    D_0028E490 = (saved << 16) - saved;
    func_0013EEA0();
}

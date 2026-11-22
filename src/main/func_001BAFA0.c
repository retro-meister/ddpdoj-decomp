#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;
extern void func_001BAEC0(void);

void func_001BAFA0(void) {
    *(u16 *)work_reg_a4 = 0;
    *(u16 *)(D_0028E450 + 0x1A) = 0x20;
    work_reg_a4[3] = D_0028E450[0x1B];
    func_001BAEC0();
}

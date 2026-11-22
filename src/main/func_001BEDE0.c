#include "common.h"

extern u8 *D_0028E450;
extern u8 *work_reg_a4;
void func_001BEE10(void);

void func_001BEDE0(void) {
    D_0028E450[0x1B] = 0;
    D_0028E450[0x1A] = 0x20;
    work_reg_a4[3] = 0;
    *(u16 *)&work_reg_a4[4] = 0;
    func_001BEE10();
}

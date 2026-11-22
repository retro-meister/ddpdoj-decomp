#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;

void func_001CDE10(void);

void func_001CDDF0(void) {
    *(u16 *)(work_reg_a4 + 2) = 1;
    *(u16 *)(D_0028E450 + 0xA6) = 0;
    func_001CDE10();
}

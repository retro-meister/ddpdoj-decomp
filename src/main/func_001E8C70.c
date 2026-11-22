#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;

void func_001E8C90(void);

void func_001E8C70(void) {
    *(u16 *)(work_reg_a4 + 2) = 0;
    *(u16 *)(D_0028E450 + 0x12A) = 0;
    func_001E8C90();
}

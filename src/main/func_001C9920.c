#include "common.h"

extern u8 *reg_a4;
void func_001C9950(void);

void func_001C9920(void) {
    reg_a4[3] = 0;
    *(u16 *)(reg_a4 + 4) = 0x1C0;
    *(u16 *)(reg_a4 + 6) = 0;
    *(u16 *)(reg_a4 + 8) = 0;
    func_001C9950();
}

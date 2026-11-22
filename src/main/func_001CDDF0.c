#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CDE10(void);

void func_001CDDF0(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    *(u16 *)(reg_a6 + 0xA6) = 0;
    func_001CDE10();
}

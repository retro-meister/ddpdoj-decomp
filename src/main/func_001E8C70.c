#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E8C90(void);

void func_001E8C70(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a6 + 0x12A) = 0;
    func_001E8C90();
}

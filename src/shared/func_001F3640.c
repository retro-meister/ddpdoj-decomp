#include "common.h"

extern u8 *reg_a4;

void func_001F3650(void);

void func_001F3640(void) {
    *(s16 *)(reg_a4 + 2) = 0x60;
    func_001F3650();
}

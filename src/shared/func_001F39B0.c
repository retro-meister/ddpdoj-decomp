#include "common.h"

extern void func_001F39C0(void);
extern s16 *reg_a4;

void func_001F39B0(void) {
    reg_a4[1] = 0x80;
    func_001F39C0();
}

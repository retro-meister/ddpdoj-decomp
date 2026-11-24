#include "common.h"

extern s16 *reg_a4_as_s16_p;
extern void func_001F30F0(void);

void func_001F30E0(void) {
    reg_a4_as_s16_p[1] = 0x60;
    func_001F30F0();
}

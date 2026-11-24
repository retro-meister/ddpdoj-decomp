#include "common.h"

extern s16 *reg_a4;
extern void func_001D75D0(void);

void func_001D75C0(void) {
    reg_a4[1] = 1;
    func_001D75D0();
}

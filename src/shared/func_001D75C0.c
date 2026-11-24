#include "common.h"

extern s16 *reg_a4_as_s16_p;
extern void func_001D75D0(void);

void func_001D75C0(void) {
    reg_a4_as_s16_p[1] = 1;
    func_001D75D0();
}

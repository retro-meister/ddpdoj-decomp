#include "common.h"

extern s16 *reg_a4_as_s16_p;
void func_001D7320(void);

void func_001D7310(void) {
    reg_a4_as_s16_p[1] = 0x202;
    func_001D7320();
}

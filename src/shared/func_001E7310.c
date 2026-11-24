#include "common.h"

extern s16 *reg_a4_as_s16_p;
void func_001E7320(void);

void func_001E7310(void) {
    reg_a4_as_s16_p[1] = 1;
    func_001E7320();
}

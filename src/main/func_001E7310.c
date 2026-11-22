#include "common.h"

extern s16 *reg_a4;
void func_001E7320(void);

void func_001E7310(void) {
    reg_a4[1] = 1;
    func_001E7320();
}

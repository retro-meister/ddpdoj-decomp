#include "common.h"

extern s16 *work_reg_a4;
void func_001D7320(void);

void func_001D7310(void) {
    work_reg_a4[1] = 0x202;
    func_001D7320();
}

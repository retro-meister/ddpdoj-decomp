#include "common.h"

extern s16 *reg_a4;
void func_001D3340(void);

void func_001D3330(void) {
    reg_a4[1] = 0;
    func_001D3340();
}

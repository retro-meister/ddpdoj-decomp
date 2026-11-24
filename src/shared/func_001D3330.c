#include "common.h"

extern s16 *reg_a4_as_s16_p;
void func_001D3340(void);

void func_001D3330(void) {
    reg_a4_as_s16_p[1] = 0;
    func_001D3340();
}

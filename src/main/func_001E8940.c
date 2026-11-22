#include "common.h"

extern s16 *reg_a4;
extern void func_001E8950(void);

void func_001E8940(void) {
    reg_a4[1] = 1;
    func_001E8950();
}

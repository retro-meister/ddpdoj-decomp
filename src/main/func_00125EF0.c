#include "common.h"

extern s32 reg_d2;
extern void func_00125F00(void);

void func_00125EF0(void) {
    reg_d2 = 0;
    func_00125F00();
}

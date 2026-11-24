#include "common.h"

extern void *reg_a0_as_void_p;
extern u8 D_002BAEB0_as_u8_a16[16];
void func_0013CD00(void);

void func_0013CCE0(void) {
    reg_a0_as_void_p = D_002BAEB0_as_u8_a16;
    func_0013CD00();
}

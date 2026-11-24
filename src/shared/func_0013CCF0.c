#include "common.h"

extern void *reg_a0_as_void_p;
extern u8 D_002BAEF0_as_u8_a[];
void func_0013CD00(void);

void func_0013CCF0(void) {
    reg_a0_as_void_p = D_002BAEF0_as_u8_a;
    func_0013CD00();
}

#include "common.h"

extern void *reg_a0;
extern u8 D_002BAEF0[];
void func_0013CD00(void);

void func_0013CCF0(void) {
    reg_a0 = D_002BAEF0;
    func_0013CD00();
}

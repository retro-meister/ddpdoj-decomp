#include "common.h"

extern char *reg_a0;
extern char D_0024F378[];
extern void func_00137AD0(void);

void func_00130DE0(void) {
    reg_d2.sh[0] = 0;
    reg_a0 = D_0024F378;
    func_00137AD0();
}

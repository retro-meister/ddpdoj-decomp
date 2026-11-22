#include "common.h"

extern s16 reg_d2;
extern char D_0024F378[];
extern char *reg_a0;
extern void func_00137AD0(void);

void func_00130D80(void) {
    reg_d0.h[0] = 10;
    reg_d1.h[0] = 3;
    reg_a0 = D_0024F378;
    reg_d2 = 0;
    func_00137AD0();
}

#include "common.h"

extern s16 bcd_result;
extern char D_0024F378[];
extern char *D_0028E468;
extern void func_00137AD0(void);

void func_00130D80(void) {
    work_reg_0.h[0] = 10;
    work_reg_1.h[0] = 3;
    D_0028E468 = D_0024F378;
    bcd_result = 0;
    func_00137AD0();
}

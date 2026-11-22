#include "common.h"

extern s16 bcd_result;
extern char *D_0028E468;
extern char D_0024F378[];
extern void func_00137AD0(void);

void func_00130DE0(void) {
    bcd_result = 0;
    D_0028E468 = D_0024F378;
    func_00137AD0();
}

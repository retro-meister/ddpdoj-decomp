#include "common.h"

extern u16 D_002695D0[];
extern void *reg_a3_as_void_p;

void func_001278A0(void);

void func_00127860(void) {
    reg_a3_as_void_p = D_002695D0;
    func_001278A0();
}

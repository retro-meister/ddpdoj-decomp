#include "common.h"

extern u16 D_002695D0[];
extern void *D_0028E45C;

void func_001278A0(void);

void func_00127860(void) {
    D_0028E45C = D_002695D0;
    func_001278A0();
}

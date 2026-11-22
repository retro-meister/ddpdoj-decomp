#include "common.h"

extern u16 D_002695B0[];
extern u16 *D_0028E45C;

void func_001278A0(void);

void func_00127880(void) {
    D_0028E45C = D_002695B0;
    func_001278A0();
}

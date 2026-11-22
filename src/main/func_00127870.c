#include "common.h"

extern u16 D_002695A0[];
extern u16 *D_0028E45C;

void func_001278A0(void);

void func_00127870(void) {
    D_0028E45C = D_002695A0;
    func_001278A0();
}

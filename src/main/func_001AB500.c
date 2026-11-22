#include "common.h"

extern u8 *D_0028E468;

void func_001AB500(void) {
    *(u16 *)(D_0028E468 + 6) += 1;
    *(u16 *)D_0028E468 = 1;
}

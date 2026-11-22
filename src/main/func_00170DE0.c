#include "common.h"

extern u8 *D_0028E450;
extern u16 bcd_result;

void func_00170DE0(void) {
    bcd_result = *(u16 *)(D_0028E450 + 0x1E);
}

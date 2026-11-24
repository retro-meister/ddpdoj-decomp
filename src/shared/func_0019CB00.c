#include "common.h"

extern Reg32 reg_d1;

void func_0019CB00(void) {
    u32 value = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = value << 2;
}

#include "common.h"

extern Reg32 work_reg_1;

void func_0019CB00(void) {
    u32 value = *(u16 *)&work_reg_1;
    *(u16 *)&work_reg_1 = value << 2;
}

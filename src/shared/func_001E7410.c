#include "common.h"

extern u8 *reg_a4;

void func_001E7420(void);

void func_001E7410(void) {
    ((u16 *)reg_a4)[1] = 0x202;
    func_001E7420();
}

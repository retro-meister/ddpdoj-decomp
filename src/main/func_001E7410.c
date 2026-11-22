#include "common.h"

extern u8 *work_reg_a4;

void func_001E7420(void);

void func_001E7410(void) {
    ((u16 *)work_reg_a4)[1] = 0x202;
    func_001E7420();
}

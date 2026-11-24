#include "common.h"

extern u16 *reg_a4;
extern void func_001D7420(void);

void func_001D7410(void) {
    reg_a4[1] = 1;
    func_001D7420();
}

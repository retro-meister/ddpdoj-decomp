#include "common.h"

extern u16 *reg_a4_as_u16_p;
extern void func_001D7420(void);

void func_001D7410(void) {
    reg_a4_as_u16_p[1] = 1;
    func_001D7420();
}

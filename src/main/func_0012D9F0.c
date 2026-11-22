#include "common.h"

extern u16 bcd_result;
void func_0012DA10(void);

void func_0012D9F0(void) {
    bcd_result = (u16)((bcd_result << 16) - bcd_result);
    func_0012DA10();
}

#include "common.h"

extern u16 bcd_result;
extern void func_0012D960(void);

void func_0012D940(void) {
    u16 value = bcd_result;
    s32 diff = (value << 16) - value;
    bcd_result = diff;
    func_0012D960();
}

#include "common.h"

extern u8 *D_0028E450;

extern void func_001C9750(void);

void func_001C9AF0(void) {
    *(u16 *)(D_0028E450 + 2) -= 0x10;
    func_001C9750();
}

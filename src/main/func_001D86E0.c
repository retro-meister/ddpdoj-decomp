#include "common.h"

extern void func_001D7880(void);
void func_001D82E0(s32 p0, s32 p1, void (*p2)(void), s32 p3);

void func_001D86E0(void) {
    func_001D82E0(0xC6, 0xC2, &func_001D7880, 0x186);
}

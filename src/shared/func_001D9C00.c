#include "common.h"

extern void func_001D7900(void);
void func_001D7C90(s32, s32, void (*)(void), s32);

void func_001D9C00(void) {
    func_001D7C90(0xE6, 0xE2, &func_001D7900, 0x187);
}

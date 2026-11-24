#include "common.h"

extern void func_001D8740(s32 arg0, s32 arg1, void *arg2);
extern s32 func_001D7900[];

void func_001D9C60(void) {
    func_001D8740(0xE6, 0xE2, &func_001D7900[0]);
}

#include "common.h"

extern void func_001D7900(void);
extern s32 D_0028DC64[];
void func_001D90E0(s32 arg0, s32 arg1, void (*arg2)(void), s32 *arg3);

void func_001D9C90(void) {
    func_001D90E0(0xE6, 0xE2, func_001D7900, D_0028DC64);
}

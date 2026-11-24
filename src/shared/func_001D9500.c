#include "common.h"

extern s32 D_0028DC60[];
extern void func_001D7880(void);
void func_001D90E0(s32 first, s32 second, void (*callback)(void), void *data);

void func_001D9500(void) {
    func_001D90E0(0xC6, 0xC2, func_001D7880, D_0028DC60);
}

#include "common.h"

extern s32 D_0028E464;
extern s32 D_0028E468;
extern s32 D_0029CDE0[];
extern s32 D_0029CE60[];

void func_0013F5C0(void);

void func_0013F5A0(void) {
    D_0028E468 = (s32)&D_0029CE60[0];
    D_0028E464 = (s32)&D_0029CDE0[0];
    func_0013F5C0();
}

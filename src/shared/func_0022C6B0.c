#include "common.h"

extern s8 D_0028ECBC;
extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern void func_0022C7B0();

void func_0022C6B0(s32 arg0) {
    D_0028ED1C = arg0;
    D_0028ECBC = 1;
    D_0028ED20 = 0;
    func_0022C7B0();
}

#include "common.h"

extern u8 D_0028ECBC;
extern s32 D_0028ED1C;
extern s32 D_0028ED20;

void func_0022C7B0(void);

void func_0022C760(s32 arg0) {
    D_0028ED1C = arg0;
    D_0028ED20 = 1;
    D_0028ECBC = 1;
    func_0022C7B0();
}

#include "common.h"

extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern u8 D_0028ECBC_as_u8;

void func_0022C7B0(void);

void func_0022C750(s32 arg0) {
    D_0028ED1C = arg0;
    D_0028ED20 = 0;
    D_0028ECBC_as_u8 = 0;
    func_0022C7B0();
}

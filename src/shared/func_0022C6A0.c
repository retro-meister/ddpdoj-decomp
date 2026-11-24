#include "common.h"

extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern u8 D_0028ECBC_as_u8;

void func_0022C7B0(void);

void func_0022C6A0(s32 value) {
    D_0028ED1C = value;
    D_0028ED20 = 0;
    D_0028ECBC_as_u8 = 0;
    func_0022C7B0();
}

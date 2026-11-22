#include "common.h"

extern s8 D_0028ECBC;
extern s8 D_0028ECD4;
extern s32 D_0028ED00;
extern s32 D_0028ED1C;
extern s32 D_0028ED20;

extern void func_0022C7B0(void);

void func_0022C780(void) {
    if (D_0028ED00 == 0) {
        D_0028ED1C = 0;
        D_0028ECD4 = 1;
        D_0028ED20 = 7;
        D_0028ECBC = 1;
    }
    func_0022C7B0();
}

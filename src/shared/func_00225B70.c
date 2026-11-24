#include "common.h"

extern s32 D_0028EAC0;
extern s32 D_0028EAC4;
extern s8 D_0028EACC;
extern s8 D_0028EB04;
extern s32 D_0028EB8C;
extern s32 D_0028EB90;

extern void func_002263C0(void);

void func_00225B70(void) {
    D_0028EAC4 = 0;
    D_0028EACC = 1;
    D_0028EAC0 = 1;
    D_0028EB04 = 1;
    D_0028EB90 = 0;
    D_0028EB8C = 0;
    func_002263C0();
}

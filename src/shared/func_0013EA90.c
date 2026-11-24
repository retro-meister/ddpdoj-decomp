#include "common.h"

extern void func_0013CA90(void);
extern u8 D_0029F1F0[];

void func_0013EA90(void) {
    D_0029F1F0[0] &= 0xFE;
    func_0013CA90();
}

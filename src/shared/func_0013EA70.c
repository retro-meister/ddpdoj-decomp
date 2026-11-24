#include "common.h"

extern u8 D_0029F260[];

void func_0013C980(void);

void func_0013EA70(void) {
    D_0029F260[0] &= 0xFE;
    func_0013C980();
}

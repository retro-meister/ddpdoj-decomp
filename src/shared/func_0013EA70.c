#include "common.h"

extern u8 D_0029F260_as_u8_a[];

void func_0013C980(void);

void func_0013EA70(void) {
    D_0029F260_as_u8_a[0] &= 0xFE;
    func_0013C980();
}

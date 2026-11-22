#include "common.h"

extern void *D_0028E468;
extern u16 D_0028E4A6;
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
extern u8 D_002BAEB0[];
void func_0013D030(u16);

void func_0013CFD0(void) {
    u16 src = D_0029F1F2[0];
    D_0028E4A6 = src;
    work_reg_1.h[0] = D_0029F1F4[0];
    D_0028E468 = D_002BAEB0;
    func_0013D030(src);
}

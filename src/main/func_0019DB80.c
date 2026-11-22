#include "common.h"

extern u16 D_0028E12C;
extern u8 *D_0028E468;
extern u8 D_002A3D30[];

void func_0019DB80(void) {
    u32 temp;

    D_0028E468 = D_002A3D30;
    temp = D_0028E12C;
    D_0028E468 += temp;
    D_0028E12C = temp + 0xC;
}

#include "common.h"

s32 func_0019D7A0();
extern u16 D_002962D4[];
extern u16 D_002962D6[];
extern u16 D_002962D8[];
extern u16 D_002962DA[];
extern u16 D_002962DC[];
void func_00125470(void) {
    if (D_002962D4[0] == 0) return;
    if (D_002962D4[0] != 2) goto next_1;
    D_002962DC[0] -= 1;
    if (D_002962DC[0] != 0) goto next_1;
    D_002962D4[0] = 0;
next_1:
    if (D_002962D4[0] != 1) goto next_2;
    D_002962DA[0] += 0x20;
    D_002962D8[0] -= 0x400;
    if ((s16) D_002962D8[0] >= 0) goto next_2;
    D_002962D8[0] = 0;
    D_002962DA[0] = 0xE0;
    D_002962D4[0] = 2;
    D_002962DC[0] = 1;
next_2:
    reg_d1.w = 0;
    reg_d1.h[0] = D_002962D8[0];
    reg_d3.h[0] = 0x3800;
    reg_d3.h[0] |= D_002962DA[0];
    reg_d2.w = 0x10AA;
    reg_d4.h[0] = D_002962D6[0];
    func_0019D7A0();
}

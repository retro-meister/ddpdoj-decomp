#include "common.h"

extern void *reg_a0_as_void_p;
extern u16 D_0028E4A6;
extern u16 D_0029F262[];
extern u16 D_0029F264[];
extern u8 D_002BAEF0_as_u8_a[];
void func_0013D030(u16);

void func_0013D000(void) {
    u16 src = D_0029F262[0];
    D_0028E4A6 = src;
    reg_d1.h[0] = D_0029F264[0];
    reg_a0_as_void_p = D_002BAEF0_as_u8_a;
    func_0013D030(src);
}

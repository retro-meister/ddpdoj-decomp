#include "common.h"

typedef void (*Fn)(void);
extern u8 *jtbl_0028E3F4_as_u8_p;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u16 D_0028E48A;

void func_0016CFB0(void) {
    reg_d2.w = 0;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[0] += 1;
    if (reg_d2.h[0] == 4) {
        reg_d2.w = 0;
    }
    *(u16 *)(reg_a5 + 0x1E) = reg_d2.h[0];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    reg_d2.w += 0x13D8;
    D_0028E48A = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
}

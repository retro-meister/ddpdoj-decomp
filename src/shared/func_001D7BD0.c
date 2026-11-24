#include "common.h"

typedef void (*Fn)(void);
extern Fn jtbl_0026EC80[];
extern u8 *reg_a4;

void func_001D7BD0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += 1;
    (*(Fn *)((u8 *)jtbl_0026EC80 + (reg_d0.h[0] << 2)))();
}

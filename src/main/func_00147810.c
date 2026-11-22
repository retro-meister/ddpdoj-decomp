#include "common.h"

extern u16 D_0029F220[];
extern u16 D_0029F1F4[];
extern void func_00147830(void);

void func_00147810(void) {
    reg_d0.h[0] = D_0029F220[0];
    reg_d1.h[0] = D_0029F1F4[0];
    func_00147830();
}

#include "common.h"

extern u8 D_0028E38C;
extern u8 *D_0026A690[];
extern u8 *reg_a0;

extern void func_00137AD0(void);

void func_0015C340(void)
{
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_0026A690;
    reg_d0.b[0] = D_0028E38C;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    reg_a0 = *(u8 **)(reg_a0 + reg_d0.h[0]);
    reg_d1.h[0] = 0xD;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    func_00137AD0();
}

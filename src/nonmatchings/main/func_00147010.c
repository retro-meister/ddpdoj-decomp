#include "common.h"

extern u8 *reg_a3;
extern u8 *reg_a4;
extern u16 D_0029F110[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];

extern void func_00147050(u16 highHalf);
extern void func_0018D810(void);

void func_00147010(void)
{
    u16 highHalf = D_0029F112[0];

    reg_a4 = (u8 *)D_0029F110;
    reg_a3 = (u8 *)func_0018D810;
    reg_d0.h[1] = highHalf;
    reg_d0.h[0] = D_0029F114[0];
    func_00147050(highHalf);
}

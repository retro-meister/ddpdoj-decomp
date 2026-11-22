#include "common.h"

extern void func_00146DB0(u16);
extern void func_0018D770(void);
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 D_0029F180[];
extern u16 D_0029F182[];
extern u16 D_0029F184[];

void func_00146CF0(void)
{
    u16 highHalfword;

    reg_a4 = D_0029F180;
    reg_a3 = (u8 *)func_0018D770;
    highHalfword = D_0029F182[0];
    reg_d0.h[1] = highHalfword;
    reg_d0.h[0] = D_0029F184[0];
    func_00146DB0(highHalfword);
}

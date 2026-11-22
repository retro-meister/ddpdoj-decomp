#include "common.h"

extern u16 D_0029F110[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];
extern u8 *reg_a3;
extern u8 *reg_a4;

extern void func_0018D7F0(void);
extern void func_00146DB0(u16 highWord);

void func_00146D70(void)
{
    u16 highWord = D_0029F112[0];

    reg_a4 = (u8 *)D_0029F110;
    reg_a3 = (u8 *)func_0018D7F0;
    reg_d0.h[1] = highWord;
    reg_d0.h[0] = D_0029F114[0];
    func_00146DB0(highWord);
}

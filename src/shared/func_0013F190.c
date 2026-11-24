#include "common.h"

extern void func_0013F200(void);

extern u32 D_0028E428;
extern u32 D_0028E424;
extern u32 D_0028E420;
extern u32 D_0028E41C;
extern u32 D_0028E418;
extern u32 D_0028E414;
extern u32 D_0028E410;
extern u32 D_0028E40C;
extern s32 D_0028E444;
extern s32 reg_a0;
extern u8 D_0029F214[];

void func_0013F190(void)
{
    D_0028E428 = reg_d0.w;
    D_0028E424 = reg_d1.w;
    D_0028E420 = reg_d2.w;
    D_0028E41C = reg_d3.w;
    D_0028E418 = reg_d4.w;
    D_0028E414 = reg_d5.w;
    D_0028E410 = reg_d6.w;
    D_0028E40C = reg_d7.w;
    D_0028E444 = reg_a0;

    reg_d1.h[0] = 0xF00;
    reg_d4.w = 0;
    *(u8 *)&reg_d4.w = D_0029F214[0];
    func_0013F200();
}

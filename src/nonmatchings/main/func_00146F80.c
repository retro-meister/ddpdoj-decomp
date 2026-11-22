#include "common.h"

extern void func_00147050(u16);
extern void func_0018D790(void);
extern u16 D_0029F180[];
extern u16 D_0029F182[];
extern u16 D_0029F184[];
extern u32 reg_a3;
extern u32 reg_a4;

void func_00146F80(void) {
    u16 highWord = D_0029F182[0];

    reg_a4 = (u32)D_0029F180;
    reg_a3 = (u32)func_0018D790;
    reg_d0.h[1] = highWord;
    reg_d0.h[0] = D_0029F184[0];
    func_00147050(highWord);
}

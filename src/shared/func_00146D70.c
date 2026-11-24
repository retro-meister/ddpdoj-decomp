#include "common.h"

extern u32 reg_a3;
extern u32 reg_a4;
extern u16 D_0029F110[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];
extern void func_0018D7F0(void);
extern void func_00146DB0(u16);

void func_00146D70(void) {
    unsigned int highWord = D_0029F112[0];
    reg_a4 = (u32)D_0029F110;
    reg_d0.h[0] = D_0029F114[0];
    reg_a3 = (u32)(&func_0018D7F0);
    reg_d0.h[1] = highWord;
    func_00146DB0(highWord);
}

#include "common.h"

extern u32 reg_a3_as_u32;
extern u32 reg_a4_as_u32;
extern u16 D_0029F180_as_u16_a[];
extern u16 D_0029F182[];
extern u16 D_0029F184[];
extern void func_0018D770(void);
extern void func_00146DB0(u16);

void func_00146CF0(void) {
    unsigned int highWord = D_0029F182[0];
    reg_a4_as_u32 = (u32)D_0029F180_as_u16_a;
    reg_d0.h[0] = D_0029F184[0];
    reg_a3_as_u32 = (u32)(&func_0018D770);
    reg_d0.h[1] = highWord;
    func_00146DB0(highWord);
}

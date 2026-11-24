#include "common.h"

typedef void (*Fn)();

s32 func_00209920();
s32 func_00209A00();
s32 func_00209A50();
s32 func_00209AA0();
extern u8 D_00268790[];
extern s8 D_0028DFA0;
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;

void func_00209AF0(void) {
    s32 temp_a1;

    reg_d7.h[0] = 0;
    func_00209920();
    reg_d7.h[0] = 0;
    func_00209A00();
    reg_d7.h[0] = 0;
    func_00209A50();
    reg_d7.h[0] = 0;
    func_00209AA0();
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) D_0028DFA0;
    temp_a1 = reg_d0.h[0] * 4;
    reg_d0.w = *(u32 *)(D_00268790 + temp_a1);
    if (reg_d0.w != -1U) {
        reg_a0 = (u8 *)reg_d0.w;
        reg_d7.h[0] = 2;
        jtbl_0028E3F4 = reg_a0;
        ((Fn)jtbl_0028E3F4)();
    }
}

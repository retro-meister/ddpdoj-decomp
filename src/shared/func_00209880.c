#include "common.h"


s32 func_00209200();
extern u8 D_00268380[];
extern u8 D_00268390[];
extern u8 D_002683A0[];
extern u8 D_002683C0[];
extern u8 D_002683D8[];
extern u8 D_00268430[];
extern s8 D_0028DFA0;
extern u8 *reg_a0;

void func_00209880(void) {
    s32 temp_a0;

    reg_a0 = D_00268380;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = D_00268390;
    func_00209200();
    reg_a0 = D_002683A0;
    func_00209200();
    reg_a0 = D_002683C0;
    func_00209200();
    reg_a0 = D_002683D8;
    func_00209200();
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) D_0028DFA0;
    temp_a0 = reg_d0.h[0] * 4;
    reg_a0 = *(u8 **)((u8 *)D_00268430 + temp_a0);
    reg_d0.h[0] = 2;
    func_00209200();
}

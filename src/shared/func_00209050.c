#include "common.h"

typedef void (*Fn)();

s32 func_0016A8B0();
s32 func_0016A8D0();
s32 func_0018DE90();
s32 func_0018DEA0();
s32 func_0018DEE0();
s32 func_00208E20();
s32 func_00208EB0();
s32 func_002093F0();
extern u8 D_00268230[];
extern s8 D_0028DFA0;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;

void func_00209050(void) {
    u32 t;

    func_00208E20();
    func_0016A8D0();
    if (!(reg_d0.w & 1)) goto next_1;
    D_0028DFA0 += 1;
    if (D_0028DFA0 < 0x2F) goto next_1;
    D_0028DFA0 = 0x2E;
next_1:
    if (!(reg_d0.w & 2)) goto next_2;
    D_0028DFA0 -= 1;
    if (0 <= D_0028DFA0) goto next_2;
    D_0028DFA0 = 0;
next_2:
    if (!(reg_d0.w & 8)) goto next_3;
    D_0028DFA0 += 0x10;
    if (D_0028DFA0 < 0x2F) goto next_3;
    D_0028DFA0 = 0x2E;
next_3:
    if (!(reg_d0.w & 4)) goto next_4;
    D_0028DFA0 -= 0x10;
    if (0 <= D_0028DFA0) goto next_4;
    D_0028DFA0 = 0;
next_4:
    if (!(reg_d0.w & 0x10)) goto next_5;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) D_0028DFA0;
    reg_a0 = *(u8 **)((u8 *)D_00268230 + (reg_d1.h[0] * 4));
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
next_5:
    if (!(reg_d0.w & 0x20)) goto next_6;
    func_0018DEE0();
    func_0018DE90();
    func_0018DEA0();
next_6:
    reg_d3.w = 0;
    reg_d0.h[0] = 0x13;
    reg_d2.h[0] = 0;
    reg_d1.h[0] = 0x2A;
    reg_d3.b[0] = (u8) D_0028DFA0;
    func_00208EB0();
    func_0016A8B0();
    t = reg_d0.w;
    if ((t & 0x8000) && (t & 0x10)) {
        reg_d0.w = 0;
        func_002093F0();
        func_0018DEE0();
        func_0018DE90();
        func_0018DEA0();
    }
    reg_d0.w = 0;
}

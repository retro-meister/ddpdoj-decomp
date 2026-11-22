#include "common.h"


typedef void (*Fn)();

s32 func_00137C50();
s32 func_0018DE90();
s32 func_0018DEA0();
s32 func_0018DEE0();
s32 func_00208AD0();
extern u8 D_00268080[];
extern s8 D_0028DFA8;
extern s8 D_0028DFAC;
extern s8 D_0028DFB0;
extern s16 D_0028E3B8;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00208BA0(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (3))) != 0) {
        if (D_0028DFAC == 1) {
            reg_d0.w = 0;
            D_0028DFAC = 2;
            reg_d0.b[0] = (u8) D_0028DFA8;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 = *(u8 **)((u8 *)D_00268080 + (reg_d0.h[0] * 4));
            jtbl_0028E3F4 = (Fn)(reg_a0);
            jtbl_0028E3F4();
        }
        reg_d0.w = 0;
        reg_d0.b[0] = (u8) D_0028DFA8;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += 1;
        reg_a0 = *(u8 **)((u8 *)D_00268080 + (reg_d0.h[0] * 4));
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        return;
    }
    D_0028DFA8 = 0;
    D_0028DFB0 = 0x3C;
    D_0028DFAC = 1;
    func_00208AD0();
    (*(u8 *)((u8 *)(reg_a5) + (3))) = 1U;
    func_0018DEE0();
    func_0018DE90();
    func_0018DEA0();
    func_00137C50();
    D_0028E3B8 = 1;
}

#include "common.h"

s32 func_0018DE90();
s32 func_0018DEE0();
s32 func_002071C0();
s32 func_00207490();
extern u8 D_0028E83C;
extern u8 D_0028E840;
extern u8 D_0028E844;
extern u8 D_0028E848;
extern u8 D_0028E84C;
extern u8 D_002BF390[];
extern u8 D_002BF3B4[];
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a6;

void func_00135C90(void) {
    reg_a2 = D_002BF390;
    reg_a3 = D_002BF3B4;
    reg_a0 = reg_a2 + 0x1C;
    func_00207490();
    reg_a0 = reg_a3 + 0x1C;
    func_00207490();
    reg_a0 = reg_a2 + 0x20;
    func_00207490();
    reg_a0 = reg_a3 + 0x20;
    func_00207490();
    reg_a0 = &D_0028E848;
    func_00207490();
    reg_a0 = &D_0028E84C;
    func_00207490();
    reg_a0 = &D_0028E844;
    func_00207490();
    reg_a0 = &D_0028E840;
    func_00207490();
    reg_a0 = &D_0028E83C;
    func_00207490();
    func_0018DEE0();
    func_0018DE90();
    reg_d0.h[0] = 0xE;
    func_002071C0();
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}

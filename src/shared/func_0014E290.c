#include "common.h"

extern void func_0014E2C0(void *);
extern void *reg_a5_as_void_p;
extern s32 reg_a6_as_s32;

void func_0014E290(void) {
    void *task = reg_a5_as_void_p;

    reg_tmp.h[1] = *(u16 *)((u8 *)task + 0x6);
    reg_tmp.h[0] = *(u16 *)((u8 *)task + 0x8);
    reg_d0.w = 1;
    reg_a6_as_s32 = reg_tmp.sw;
    *(u16 *)&reg_d1 = *(u16 *)((u8 *)task + 0x4);
    func_0014E2C0(task);
}

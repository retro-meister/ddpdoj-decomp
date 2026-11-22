#include "common.h"

extern void func_0014E2C0(void *);
extern void *D_0028E454;
extern s32 D_0028E450;

void enemy_end_task(void) {
    void *task = D_0028E454;

    work_reg_tmp.h[1] = *(u16 *)((u8 *)task + 0x6);
    work_reg_tmp.h[0] = *(u16 *)((u8 *)task + 0x8);
    work_reg_0.w = 1;
    D_0028E450 = work_reg_tmp.sw;
    *(u16 *)&work_reg_1 = *(u16 *)((u8 *)task + 0x4);
    func_0014E2C0(task);
}

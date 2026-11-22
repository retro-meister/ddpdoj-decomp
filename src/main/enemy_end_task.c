#include "common.h"

extern Reg32 work_reg_0;
extern Reg32 work_reg_1;
extern u8 bcd_digits[4];

extern void func_0014E2C0(void *);
extern void *D_0028E454;
extern s32 D_0028E450;
extern u16 D_0028E48A;

void enemy_end_task(void) {
    void *task = D_0028E454;

    D_0028E48A = *(u16 *)((u8 *)task + 0x6);
    *(u16 *)bcd_digits = *(u16 *)((u8 *)task + 0x8);
    work_reg_0.w = 1;
    D_0028E450 = *(s32 *)bcd_digits;
    *(u16 *)&work_reg_1 = *(u16 *)((u8 *)task + 0x4);
    func_0014E2C0(task);
}

#include "common.h"

s32 func_00124D90();
s32 func_001251C0();
s32 func_00171400();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_001C9640(void) {
    reg_d0.w = 6;
    func_00124D90();
    (*(u16 *)((u8 *)(reg_a0) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (2)));
    (*(u16 *)((u8 *)(reg_a4) + (6))) += 4;
    func_00171400();
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) != 0) {
        reg_d0.w = 2;
        func_001251C0();
        (*(u16 *)((u8 *)(reg_a0) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        (*(u16 *)((u8 *)(reg_a4) + (0xC))) *= 0xFFFF;
    }
    (*(u8 *)((u8 *)(reg_a4) + (2))) = 1U;
}

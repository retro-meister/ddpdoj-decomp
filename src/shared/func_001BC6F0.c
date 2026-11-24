#include "common.h"

s32 func_0013A780();
s32 func_0018D5C0();
extern u8 D_00262680[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BC6F0(u16 arg1) {
    s16 var_a0;
    u16 temp_a1;
    u16 var_a1;

    var_a1 = arg1;
    var_a0 = 0x70;
    (*(s8 *)((u8 *)(reg_a5) + (0x16))) = 0x70;
    reg_d7.w = 7;
    reg_a4 = reg_a6 + 0x20;
    do {
        if ((*(u16 *)((u8 *)(reg_a4) + (0))) == 0x8000) {
            reg_d0.w = 0xC;
            func_0013A780();
            var_a0 = 2;
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (2)));
            var_a1 = (*(u16 *)((u8 *)(reg_a4) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = var_a1;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        }
        (*(s8 *)((u8 *)(reg_a4) + (8))) = 1;
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    func_0018D5C0();
    reg_a4 = (u8 *)D_00262680;
loop_5:
    temp_a1 = (*(u16 *)((u8 *)(reg_a4) + (0)));
    reg_d1.h[0] = temp_a1;
    reg_a4 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_a4 += 2;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_a4 += 2;
        (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0)));
        reg_a4 += 2;
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
        goto loop_5;
    }
}

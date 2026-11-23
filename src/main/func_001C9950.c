#include "common.h"

s32 func_00124B20();
s32 func_00124D70();
s32 func_0013B2E0();
s32 func_001A3020();
s32 func_001C9750();
s32 func_001CBBF0();
s32 func_00201B80();
extern u8 D_0025FCB0[];
extern u8 D_0026C8C0[];
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C9950(void) {
    func_00201B80();
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0x10) {
            reg_d0.h[0] = 0xD;
            reg_a0 = (u8 *)D_0025FCB0;
            func_001A3020();
        }
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) != 0) {
            func_001C9750();
            return;
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        D_0028E854 |= 1;
        func_001C9750();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (6))) != 0x100) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u16 *)((u8 *)(reg_a4) + (6))) += 3;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (6))) >= 0x100) {
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 0x100U;
            }
        }
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) < 0x6200) {
        func_001C9750();
        return;
    }
    D_0028E855 |= 0x10;
    D_0028E855 |= 2;
    reg_d0.w = 3;
    func_00124B20();
    func_001CBBF0();
    func_00124D70();
    reg_a0 = (u8 *)D_0026C8C0;
    func_0013B2E0();
    func_001C9750();
}

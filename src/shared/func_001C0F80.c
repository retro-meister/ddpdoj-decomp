#include "common.h"

s32 func_001C1030();
s32 func_00201160();
s32 func_002011D0();
extern u8 *reg_a4;

void func_001C0F80(void) {
    (*(u8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x1002;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x2018;
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 1;
    func_002011D0(0x2018, 0x1002);
    if (reg_d0.h[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 0xFF;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 1;
    func_002011D0();
    if (reg_d0.h[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 0xFF;
    }
    func_00201160();
    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) reg_d0.b[0];
    func_00201160();
    (*(u8 *)((u8 *)(reg_a4) + (8))) = (u8) reg_d0.b[0];
    func_001C1030();
}

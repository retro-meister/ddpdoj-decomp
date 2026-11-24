#include "common.h"

s32 func_001C0720();
s32 func_002010A0();
s32 func_002011D0();
extern u8 *reg_a4;

void func_001C0650() {
    (*(u8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 1;
    func_002011D0();
    if (reg_d0.h[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 0xFF;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 1;
    func_002011D0();
    if (reg_d0.h[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 0xFF;
    }
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x1000;
    (*(u8 *)((u8 *)(reg_a4) + (9))) = 0x20U;
    do {
        func_002010A0();
    } while (reg_d0.b[0] == 0);
    reg_d0.b[0] += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (9))) += reg_d0.b[0];
    func_001C0720();
}

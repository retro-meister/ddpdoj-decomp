#include "common.h"

s32 func_002011D0();
s32 func_00201270();
extern u8 *reg_a5;

void func_001BC930(void) {
    func_00201270();
    reg_tmp.h[0] = (u16) (s8) reg_d0.b[0];
    reg_d0.h[0] = reg_tmp.h[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.h[0] += 0x14;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = 0;
    func_00201270();
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a5) + (0x1C))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a5) + (0x18))) = 0;
    func_002011D0();
    if (reg_d0.h[0] != 0) {
        (*(s8 *)((u8 *)(reg_a5) + (0x18))) = 1;
    }
    func_00201270();
    reg_d0.b[0] *= 4;
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
}

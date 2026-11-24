#include "common.h"

s32 func_002010A0();                            /* extern */
extern u8 *reg_a4;

void func_001E9420(void) {
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1B))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1A))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1D))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1C))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1F))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1E))) = (u8) reg_d0.b[0];
}

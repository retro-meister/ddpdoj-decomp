#include "common.h"

s32 func_0013B8B0();                            /* extern */
s32 func_001D2930(s32, s32);            /* extern */
extern s32 D_0026D990[];
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a4;

void func_001D28C0(void) {
    reg_a0_as_s32_p = D_0026D990;
    func_0013B8B0();
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x101;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0xD))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x2020;
    (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 0;
    func_001D2930(1, 0x101);
}
